/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "fix_npt_sphere.h"
#include "atom.h"
#include "atom_vec.h"
#include "force.h"
#include "compute.h"
#include "kspace.h"
#include "update.h"
#include "domain.h"
#include "error.h"

using namespace LAMMPS_NS;

#define INERTIA 0.4          // moment of inertia for sphere

enum{NOBIAS,BIAS};

/* ---------------------------------------------------------------------- */

FixNPTSphere::FixNPTSphere(LAMMPS *lmp, int narg, char **arg) :
  FixNPT(lmp, narg, arg)
{
  if (!atom->omega_flag || !atom->torque_flag)
    error->all("Fix nvt/sphere requires atom attributes omega, torque");

  dttype = new double[atom->ntypes+1];
}

/* ---------------------------------------------------------------------- */

FixNPTSphere::~FixNPTSphere()
{
  delete [] dttype;
}

/* ---------------------------------------------------------------------- */

void FixNPTSphere::init()
{
  FixNPT::init();

  if (!atom->shape)
    error->all("Fix npt/sphere requires atom attribute shape");

  double **shape = atom->shape;
  for (int i = 1; i <= atom->ntypes; i++)
    if (shape[i][0] != shape[i][1] || shape[i][0] != shape[i][2])
      error->all("Fix npt/sphere requires spherical particle shapes");
}

/* ----------------------------------------------------------------------
   1st half of Verlet update 
------------------------------------------------------------------------- */

void FixNPTSphere::initial_integrate(int vflag)
{
  int i;
  double dtfm,dtirotate;

  double delta = update->ntimestep - update->beginstep;
  delta /= update->endstep - update->beginstep;

  // update eta_dot

  t_target = t_start + delta * (t_stop-t_start);
  f_eta = t_freq*t_freq * (t_current/t_target - 1.0);
  eta_dot += f_eta*dthalf;
  eta_dot *= drag_factor;
  eta += dtv*eta_dot;

  // update omega_dot
  // for non-varying dims, p_freq is 0.0, so omega_dot doesn't change

  double f_omega,volume;
  if (dimension == 3) volume = domain->xprd*domain->yprd*domain->zprd;
  else volume = domain->xprd*domain->yprd;
  double denskt = atom->natoms*boltz*t_target / volume * nktv2p;

  for (i = 0; i < 3; i++) {
    p_target[i] = p_start[i] + delta * (p_stop[i]-p_start[i]);
    f_omega = p_freq[i]*p_freq[i] * (p_current[i]-p_target[i])/denskt;
    omega_dot[i] += f_omega*dthalf;
    omega_dot[i] *= drag_factor;
    omega[i] += dtv*omega_dot[i];
    factor[i] = exp(-dthalf*(eta_dot+omega_dot[i]));
    dilation[i] = exp(dthalf*omega_dot[i]);
  }
  factor_rotate = exp(-dthalf*eta_dot);

  // v update only for atoms in group

  double **x = atom->x;
  double **v = atom->v;
  double **f = atom->f;
  double **omega = atom->omega;
  double **torque = atom->torque;
  double *mass = atom->mass;
  int *type = atom->type;
  int *mask = atom->mask;
  int nlocal = atom->nlocal;
  if (igroup == atom->firstgroup) nlocal = atom->nfirst;

  if (which == NOBIAS) {
    for (i = 0; i < nlocal; i++) {
      if (mask[i] & groupbit) {
	dtfm = dtf / mass[type[i]];
	v[i][0] = v[i][0]*factor[0] + dtfm*f[i][0];
	v[i][1] = v[i][1]*factor[1] + dtfm*f[i][1];
	v[i][2] = v[i][2]*factor[2] + dtfm*f[i][2];
      }
    }
  } else if (which == BIAS) {
    for (i = 0; i < nlocal; i++) {
      if (mask[i] & groupbit) {
	temperature->remove_bias(i,v[i]);
	dtfm = dtf / mass[type[i]];
	v[i][0] = v[i][0]*factor[0] + dtfm*f[i][0];
	v[i][1] = v[i][1]*factor[1] + dtfm*f[i][1];
	v[i][2] = v[i][2]*factor[2] + dtfm*f[i][2];
	temperature->restore_bias(i,v[i]);
      }
    }
  }

  // remap simulation box and all owned atoms by 1/2 step

  remap(0);

  // x update by full step only for atoms in group

  for (i = 0; i < nlocal; i++) {
    if (mask[i] & groupbit) {
      x[i][0] += dtv * v[i][0];
      x[i][1] += dtv * v[i][1];
      x[i][2] += dtv * v[i][2];
    }
  }

  // recompute timesteps since dt may have changed or come via rRESPA

  double dtfrotate = dtf / INERTIA;
  int ntypes = atom->ntypes;
  double **shape = atom->shape;
  for (int i = 1; i <= ntypes; i++)
    dttype[i] = dtfrotate / (0.25*shape[i][0]*shape[i][0]*mass[i]);

  // update angular momentum by 1/2 step
  // update quaternion a full step via Richardson iteration
  // returns new normalized quaternion

  for (i = 0; i < nlocal; i++) {    
    if (mask[i] & groupbit) {
      dtirotate = dttype[type[i]];
      omega[i][0] = omega[i][0]*factor_rotate + dtirotate*torque[i][0];
      omega[i][1] = omega[i][1]*factor_rotate + dtirotate*torque[i][1];
      omega[i][2] = omega[i][2]*factor_rotate + dtirotate*torque[i][2];
    }
  }

  // remap simulation box and all owned atoms by 1/2 step
  // redo KSpace coeffs since volume has changed

  remap(0);
  if (kspace_flag) force->kspace->setup();
}

/* ----------------------------------------------------------------------
   2nd half of Verlet update 
------------------------------------------------------------------------- */

void FixNPTSphere::final_integrate()
{
  int i,itype;
  double dtfm,dtirotate;

  // v update only for atoms in group

  double **v = atom->v;
  double **f = atom->f;
  double **omega = atom->omega;
  double **torque = atom->torque;
  double *mass = atom->mass;
  int *type = atom->type;
  int *mask = atom->mask;
  int nlocal = atom->nlocal;
  if (igroup == atom->firstgroup) nlocal = atom->nfirst;

  // recompute timesteps since dt may have changed or come via rRESPA

  double dtfrotate = dtf / INERTIA;
  int ntypes = atom->ntypes;
  double **shape = atom->shape;
  for (int i = 1; i <= ntypes; i++)
    dttype[i] = dtfrotate / (0.25*shape[i][0]*shape[i][0]*mass[i]);

  if (which == NOBIAS) {
    for (i = 0; i < nlocal; i++) {
      if (mask[i] & groupbit) {
	itype = type[i];
	
	dtfm = dtf / mass[itype];
	v[i][0] = (v[i][0] + dtfm*f[i][0]) * factor[0];
	v[i][1] = (v[i][1] + dtfm*f[i][1]) * factor[1];
	v[i][2] = (v[i][2] + dtfm*f[i][2]) * factor[2];
	
	dtirotate = dttype[itype];
	omega[i][0] = (omega[i][0] + dtirotate*torque[i][0]) * factor_rotate;
	omega[i][1] = (omega[i][1] + dtirotate*torque[i][1]) * factor_rotate;
	omega[i][2] = (omega[i][2] + dtirotate*torque[i][2]) * factor_rotate;
      }
    }

  } else if (which == BIAS) {
    for (i = 0; i < nlocal; i++) {
      if (mask[i] & groupbit) {
	itype = type[i];
	
	temperature->remove_bias(i,v[i]);
	dtfm = dtf / mass[itype];
	v[i][0] = (v[i][0] + dtfm*f[i][0]) * factor[0];
	v[i][1] = (v[i][1] + dtfm*f[i][1]) * factor[1];
	v[i][2] = (v[i][2] + dtfm*f[i][2]) * factor[2];
	temperature->restore_bias(i,v[i]);

	dtirotate = dttype[itype];
	omega[i][0] = (omega[i][0] + dtirotate*torque[i][0]) * factor_rotate;
	omega[i][1] = (omega[i][1] + dtirotate*torque[i][1]) * factor_rotate;
	omega[i][2] = (omega[i][2] + dtirotate*torque[i][2]) * factor_rotate;
      }
    }
  }

  // compute new T,P

  t_current = temperature->compute_scalar();
  if (press_couple == 0) {
    double tmp = pressure->compute_scalar();
  } else {
    temperature->compute_vector();
    pressure->compute_vector();
  }
  couple();

  // trigger virial computation on next timestep

  pressure->addstep(update->ntimestep+1);

  // update eta_dot

  f_eta = t_freq*t_freq * (t_current/t_target - 1.0);
  eta_dot += f_eta*dthalf;
  eta_dot *= drag_factor;

  // update omega_dot
  // for non-varying dims, p_freq is 0.0, so omega_dot doesn't change

  double f_omega,volume;
  if (dimension == 3) volume = domain->xprd*domain->yprd*domain->zprd;
  else volume = domain->xprd*domain->yprd;
  double denskt = atom->natoms*boltz*t_target / volume * nktv2p;

  for (i = 0; i < 3; i++) {
    f_omega = p_freq[i]*p_freq[i] * (p_current[i]-p_target[i])/denskt;
    omega_dot[i] += f_omega*dthalf;
    omega_dot[i] *= drag_factor;
  }
}
