const char * lj_class2_long = 
"	.version 2.3\n"
"	.target sm_20\n"
"	.address_size 64\n"
"	.global .texref pos_tex;\n"
"	.global .texref q_tex;\n"
"	.entry kernel_pair (\n"
"		.param .u64 __cudaparm_kernel_pair_x_,\n"
"		.param .u64 __cudaparm_kernel_pair_lj1,\n"
"		.param .u64 __cudaparm_kernel_pair_lj3,\n"
"		.param .s32 __cudaparm_kernel_pair_lj_types,\n"
"		.param .u64 __cudaparm_kernel_pair_sp_lj_in,\n"
"		.param .u64 __cudaparm_kernel_pair_dev_nbor,\n"
"		.param .u64 __cudaparm_kernel_pair_dev_packed,\n"
"		.param .u64 __cudaparm_kernel_pair_ans,\n"
"		.param .u64 __cudaparm_kernel_pair___val_paramengv,\n"
"		.param .s32 __cudaparm_kernel_pair_eflag,\n"
"		.param .s32 __cudaparm_kernel_pair_vflag,\n"
"		.param .s32 __cudaparm_kernel_pair_inum,\n"
"		.param .s32 __cudaparm_kernel_pair_nbor_pitch,\n"
"		.param .u64 __cudaparm_kernel_pair_q_,\n"
"		.param .f32 __cudaparm_kernel_pair_cut_coulsq,\n"
"		.param .f32 __cudaparm_kernel_pair_qqrd2e,\n"
"		.param .f32 __cudaparm_kernel_pair_g_ewald,\n"
"		.param .s32 __cudaparm_kernel_pair_t_per_atom)\n"
"	{\n"
"	.reg .u32 %r<86>;\n"
"	.reg .u64 %rd<64>;\n"
"	.reg .f32 %f<167>;\n"
"	.reg .pred %p<21>;\n"
"	.shared .align 16 .b8 __cuda___cuda_local_var_32541_33_non_const_sp_lj112[32];\n"
"	.shared .align 4 .b8 __cuda___cuda_local_var_32635_55_non_const_red_acc144[3072];\n"
"	.loc	16	36	0\n"
"$LDWbegin_kernel_pair:\n"
"	.loc	16	41	0\n"
"	ld.param.u64 	%rd1, [__cudaparm_kernel_pair_sp_lj_in];\n"
"	ldu.global.f32 	%f1, [%rd1+0];\n"
"	.loc	16	42	0\n"
"	ld.global.f32 	%f2, [%rd1+4];\n"
"	.loc	16	43	0\n"
"	ld.global.f32 	%f3, [%rd1+8];\n"
"	.loc	16	44	0\n"
"	ld.global.f32 	%f4, [%rd1+12];\n"
"	st.shared.v4.f32 	[__cuda___cuda_local_var_32541_33_non_const_sp_lj112+0], {%f1,%f2,%f3,%f4};\n"
"	.loc	16	45	0\n"
"	ld.global.f32 	%f5, [%rd1+16];\n"
"	.loc	16	46	0\n"
"	ld.global.f32 	%f6, [%rd1+20];\n"
"	.loc	16	47	0\n"
"	ld.global.f32 	%f7, [%rd1+24];\n"
"	.loc	16	48	0\n"
"	ld.global.f32 	%f8, [%rd1+28];\n"
"	st.shared.v4.f32 	[__cuda___cuda_local_var_32541_33_non_const_sp_lj112+16], {%f5,%f6,%f7,%f8};\n"
"	.loc	16	56	0\n"
"	mov.f32 	%f9, 0f00000000;     	\n"
"	mov.f32 	%f10, %f9;\n"
"	mov.f32 	%f11, 0f00000000;    	\n"
"	mov.f32 	%f12, %f11;\n"
"	mov.f32 	%f13, 0f00000000;    	\n"
"	mov.f32 	%f14, %f13;\n"
"	mov.f32 	%f15, 0f00000000;    	\n"
"	mov.f32 	%f16, %f15;\n"
"	mov.f32 	%f17, 0f00000000;    	\n"
"	mov.f32 	%f18, %f17;\n"
"	mov.f32 	%f19, 0f00000000;    	\n"
"	mov.f32 	%f20, %f19;\n"
"	ld.param.s32 	%r1, [__cudaparm_kernel_pair_t_per_atom];\n"
"	cvt.s32.u32 	%r2, %tid.x;\n"
"	div.s32 	%r3, %r2, %r1;\n"
"	cvt.s32.u32 	%r4, %ntid.x;\n"
"	div.s32 	%r5, %r4, %r1;\n"
"	cvt.s32.u32 	%r6, %ctaid.x;\n"
"	mul.lo.s32 	%r7, %r6, %r5;\n"
"	add.s32 	%r8, %r3, %r7;\n"
"	ld.param.s32 	%r9, [__cudaparm_kernel_pair_inum];\n"
"	setp.ge.s32 	%p1, %r8, %r9;\n"
"	@%p1 bra 	$Lt_0_30978;\n"
"	.loc	16	61	0\n"
"	cvt.s64.s32 	%rd2, %r8;\n"
"	mul.wide.s32 	%rd3, %r8, 4;\n"
"	ld.param.u64 	%rd4, [__cudaparm_kernel_pair_dev_nbor];\n"
"	add.u64 	%rd5, %rd3, %rd4;\n"
"	ld.global.s32 	%r10, [%rd5+0];\n"
"	ld.param.s32 	%r11, [__cudaparm_kernel_pair_nbor_pitch];\n"
"	cvt.s64.s32 	%rd6, %r11;\n"
"	mul.wide.s32 	%rd7, %r11, 4;\n"
"	add.u64 	%rd8, %rd7, %rd5;\n"
"	ld.global.s32 	%r12, [%rd8+0];\n"
"	sub.s32 	%r13, %r1, 1;\n"
"	and.b32 	%r14, %r13, %r2;\n"
"	cvt.s64.s32 	%rd9, %r14;\n"
"	mul.wide.s32 	%rd10, %r14, 4;\n"
"	ld.param.u64 	%rd11, [__cudaparm_kernel_pair_dev_packed];\n"
"	setp.ne.u64 	%p2, %rd11, %rd4;\n"
"	@%p2 bra 	$Lt_0_22530;\n"
"	cvt.s32.s64 	%r15, %rd6;\n"
"	mul.lo.s32 	%r16, %r15, %r1;\n"
"	mov.s32 	%r17, %r16;\n"
"	mul.lo.s32 	%r18, %r13, %r8;\n"
"	add.s32 	%r19, %r15, %r18;\n"
"	cvt.s64.s32 	%rd12, %r19;\n"
"	mul.wide.s32 	%rd13, %r19, 4;\n"
"	add.u64 	%rd14, %rd8, %rd13;\n"
"	and.b32 	%r20, %r13, %r12;\n"
"	cvt.s64.s32 	%rd15, %r20;\n"
"	div.s32 	%r21, %r12, %r1;\n"
"	mul.lo.s32 	%r22, %r16, %r21;\n"
"	cvt.s64.s32 	%rd16, %r22;\n"
"	add.u64 	%rd17, %rd15, %rd16;\n"
"	mul.lo.u64 	%rd18, %rd17, 4;\n"
"	add.u64 	%rd19, %rd14, %rd18;\n"
"	add.u64 	%rd20, %rd10, %rd14;\n"
"	bra.uni 	$Lt_0_22274;\n"
"$Lt_0_22530:\n"
"	add.u64 	%rd21, %rd7, %rd8;\n"
"	ld.global.s32 	%r23, [%rd21+0];\n"
"	cvt.s64.s32 	%rd22, %r23;\n"
"	mul.wide.s32 	%rd23, %r23, 4;\n"
"	add.u64 	%rd24, %rd11, %rd23;\n"
"	cvt.s64.s32 	%rd25, %r12;\n"
"	mul.wide.s32 	%rd26, %r12, 4;\n"
"	add.u64 	%rd19, %rd24, %rd26;\n"
"	mov.s32 	%r17, %r1;\n"
"	add.u64 	%rd20, %rd10, %rd24;\n"
"$Lt_0_22274:\n"
"	.loc	16	64	0\n"
"	mov.u32 	%r24, %r10;\n"
"	mov.s32 	%r25, 0;\n"
"	mov.u32 	%r26, %r25;\n"
"	mov.s32 	%r27, 0;\n"
"	mov.u32 	%r28, %r27;\n"
"	mov.s32 	%r29, 0;\n"
"	mov.u32 	%r30, %r29;\n"
"	tex.1d.v4.f32.s32 {%f21,%f22,%f23,%f24},[pos_tex,{%r24,%r26,%r28,%r30}];\n"
"	mov.f32 	%f25, %f21;\n"
"	mov.f32 	%f26, %f22;\n"
"	mov.f32 	%f27, %f23;\n"
"	mov.f32 	%f28, %f24;\n"
"	.loc	16	65	0\n"
"	mov.u32 	%r31, %r10;\n"
"	mov.s32 	%r32, 0;\n"
"	mov.u32 	%r33, %r32;\n"
"	mov.s32 	%r34, 0;\n"
"	mov.u32 	%r35, %r34;\n"
"	mov.s32 	%r36, 0;\n"
"	mov.u32 	%r37, %r36;\n"
"	tex.1d.v4.f32.s32 {%f29,%f30,%f31,%f32},[q_tex,{%r31,%r33,%r35,%r37}];\n"
"	mov.f32 	%f33, %f29;\n"
"	setp.ge.u64 	%p3, %rd20, %rd19;\n"
"	@%p3 bra 	$Lt_0_32514;\n"
"	cvt.rzi.ftz.s32.f32 	%r38, %f28;\n"
"	cvt.s64.s32 	%rd27, %r17;\n"
"	ld.param.s32 	%r39, [__cudaparm_kernel_pair_lj_types];\n"
"	mul.lo.s32 	%r40, %r39, %r38;\n"
"	ld.param.u64 	%rd28, [__cudaparm_kernel_pair_lj1];\n"
"	mov.f32 	%f34, 0f00000000;    	\n"
"	mov.f32 	%f35, 0f00000000;    	\n"
"	mov.f32 	%f36, 0f00000000;    	\n"
"	mov.f32 	%f37, 0f00000000;    	\n"
"	mov.f32 	%f38, 0f00000000;    	\n"
"	mov.u64 	%rd29, __cuda___cuda_local_var_32541_33_non_const_sp_lj112;\n"
"$Lt_0_23298:\n"
"	.loc	16	69	0\n"
"	ld.global.s32 	%r41, [%rd20+0];\n"
"	.loc	16	72	0\n"
"	shr.s32 	%r42, %r41, 30;\n"
"	and.b32 	%r43, %r42, 3;\n"
"	cvt.s64.s32 	%rd30, %r43;\n"
"	mul.wide.s32 	%rd31, %r43, 4;\n"
"	add.u64 	%rd32, %rd29, %rd31;\n"
"	ld.shared.f32 	%f39, [%rd32+0];\n"
"	.loc	16	73	0\n"
"	mov.f32 	%f40, 0f3f800000;    	\n"
"	ld.shared.f32 	%f41, [%rd32+16];\n"
"	sub.ftz.f32 	%f42, %f40, %f41;\n"
"	.loc	16	76	0\n"
"	and.b32 	%r44, %r41, 1073741823;\n"
"	mov.u32 	%r45, %r44;\n"
"	mov.s32 	%r46, 0;\n"
"	mov.u32 	%r47, %r46;\n"
"	mov.s32 	%r48, 0;\n"
"	mov.u32 	%r49, %r48;\n"
"	mov.s32 	%r50, 0;\n"
"	mov.u32 	%r51, %r50;\n"
"	tex.1d.v4.f32.s32 {%f43,%f44,%f45,%f46},[pos_tex,{%r45,%r47,%r49,%r51}];\n"
"	mov.f32 	%f47, %f43;\n"
"	mov.f32 	%f48, %f44;\n"
"	mov.f32 	%f49, %f45;\n"
"	mov.f32 	%f50, %f46;\n"
"	cvt.rzi.ftz.s32.f32 	%r52, %f50;\n"
"	sub.ftz.f32 	%f51, %f26, %f48;\n"
"	sub.ftz.f32 	%f52, %f25, %f47;\n"
"	sub.ftz.f32 	%f53, %f27, %f49;\n"
"	mul.ftz.f32 	%f54, %f51, %f51;\n"
"	fma.rn.ftz.f32 	%f55, %f52, %f52, %f54;\n"
"	fma.rn.ftz.f32 	%f56, %f53, %f53, %f55;\n"
"	add.s32 	%r53, %r52, %r40;\n"
"	cvt.s64.s32 	%rd33, %r53;\n"
"	mul.wide.s32 	%rd34, %r53, 16;\n"
"	add.u64 	%rd35, %rd34, %rd28;\n"
"	ld.global.f32 	%f57, [%rd35+8];\n"
"	setp.gt.ftz.f32 	%p4, %f57, %f56;\n"
"	@!%p4 bra 	$Lt_0_26114;\n"
"	rcp.approx.ftz.f32 	%f58, %f56;\n"
"	ld.global.f32 	%f59, [%rd35+12];\n"
"	setp.lt.ftz.f32 	%p5, %f56, %f59;\n"
"	@!%p5 bra 	$Lt_0_24322;\n"
"	.loc	16	92	0\n"
"	rsqrt.approx.ftz.f32 	%f60, %f56;\n"
"	mul.ftz.f32 	%f61, %f58, %f60;\n"
"	mov.f32 	%f62, %f61;\n"
"	.loc	16	93	0\n"
"	mul.ftz.f32 	%f63, %f61, %f61;\n"
"	mov.f32 	%f64, %f63;\n"
"	.loc	16	94	0\n"
"	mul.ftz.f32 	%f65, %f63, %f39;\n"
"	ld.global.v2.f32 	{%f66,%f67}, [%rd35+0];\n"
"	mul.ftz.f32 	%f68, %f66, %f61;\n"
"	sub.ftz.f32 	%f69, %f68, %f67;\n"
"	mul.ftz.f32 	%f70, %f65, %f69;\n"
"	bra.uni 	$Lt_0_24066;\n"
"$Lt_0_24322:\n"
"	.loc	16	96	0\n"
"	mov.f32 	%f70, 0f00000000;    	\n"
"$Lt_0_24066:\n"
"	ld.param.f32 	%f71, [__cudaparm_kernel_pair_cut_coulsq];\n"
"	setp.gt.ftz.f32 	%p6, %f71, %f56;\n"
"	@!%p6 bra 	$Lt_0_24834;\n"
"	.loc	20	518	0\n"
"	rsqrt.approx.ftz.f32 	%f72, %f58;\n"
"	ld.param.f32 	%f73, [__cudaparm_kernel_pair_g_ewald];\n"
"	mul.ftz.f32 	%f74, %f73, %f72;\n"
"	mul.ftz.f32 	%f75, %f74, %f74;\n"
"	neg.ftz.f32 	%f76, %f75;\n"
"	mov.f32 	%f77, 0f3fb8aa3b;    	\n"
"	mul.ftz.f32 	%f78, %f76, %f77;\n"
"	ex2.approx.ftz.f32 	%f79, %f78;\n"
"	.loc	16	103	0\n"
"	mov.f32 	%f80, 0f3f800000;    	\n"
"	mov.f32 	%f81, 0f3ea7ba05;    	\n"
"	fma.rn.ftz.f32 	%f82, %f81, %f74, %f80;\n"
"	rcp.approx.ftz.f32 	%f83, %f82;\n"
"	mov.f32 	%f84, 0f3e827906;    	\n"
"	mov.f32 	%f85, 0fbe91a98e;    	\n"
"	mov.f32 	%f86, 0f3fb5f0e3;    	\n"
"	mov.f32 	%f87, 0fbfba00e3;    	\n"
"	mov.f32 	%f88, 0f3f87dc22;    	\n"
"	fma.rn.ftz.f32 	%f89, %f88, %f83, %f87;\n"
"	fma.rn.ftz.f32 	%f90, %f83, %f89, %f86;\n"
"	fma.rn.ftz.f32 	%f91, %f83, %f90, %f85;\n"
"	fma.rn.ftz.f32 	%f92, %f83, %f91, %f84;\n"
"	mul.ftz.f32 	%f93, %f83, %f92;\n"
"	mul.ftz.f32 	%f94, %f79, %f93;\n"
"	mov.f32 	%f95, %f94;\n"
"	.loc	16	104	0\n"
"	mov.u32 	%r54, %r44;\n"
"	mov.s32 	%r55, 0;\n"
"	mov.u32 	%r56, %r55;\n"
"	mov.s32 	%r57, 0;\n"
"	mov.u32 	%r58, %r57;\n"
"	mov.s32 	%r59, 0;\n"
"	mov.u32 	%r60, %r59;\n"
"	tex.1d.v4.f32.s32 {%f96,%f97,%f98,%f99},[q_tex,{%r54,%r56,%r58,%r60}];\n"
"	mov.f32 	%f100, %f96;\n"
"	ld.param.f32 	%f101, [__cudaparm_kernel_pair_qqrd2e];\n"
"	mul.ftz.f32 	%f102, %f101, %f33;\n"
"	mul.ftz.f32 	%f103, %f102, %f100;\n"
"	div.approx.ftz.f32 	%f104, %f103, %f72;\n"
"	mov.f32 	%f105, %f104;\n"
"	.loc	16	105	0\n"
"	mov.f32 	%f106, 0f3f906ebb;   	\n"
"	mul.ftz.f32 	%f107, %f74, %f106;\n"
"	fma.rn.ftz.f32 	%f108, %f79, %f107, %f94;\n"
"	sub.ftz.f32 	%f109, %f108, %f42;\n"
"	mul.ftz.f32 	%f110, %f104, %f109;\n"
"	bra.uni 	$Lt_0_24578;\n"
"$Lt_0_24834:\n"
"	.loc	16	107	0\n"
"	mov.f32 	%f110, 0f00000000;   	\n"
"$Lt_0_24578:\n"
"	.loc	16	111	0\n"
"	add.ftz.f32 	%f111, %f110, %f70;\n"
"	mul.ftz.f32 	%f112, %f111, %f58;\n"
"	fma.rn.ftz.f32 	%f36, %f52, %f112, %f36;\n"
"	.loc	16	112	0\n"
"	fma.rn.ftz.f32 	%f35, %f51, %f112, %f35;\n"
"	.loc	16	113	0\n"
"	fma.rn.ftz.f32 	%f34, %f53, %f112, %f34;\n"
"	ld.param.s32 	%r61, [__cudaparm_kernel_pair_eflag];\n"
"	mov.u32 	%r62, 0;\n"
"	setp.le.s32 	%p7, %r61, %r62;\n"
"	@%p7 bra 	$Lt_0_25602;\n"
"	.loc	16	116	0\n"
"	mov.f32 	%f113, %f105;\n"
"	mov.f32 	%f114, %f95;\n"
"	sub.ftz.f32 	%f115, %f114, %f42;\n"
"	fma.rn.ftz.f32 	%f116, %f113, %f115, %f37;\n"
"	selp.f32 	%f37, %f116, %f37, %p6;\n"
"	@!%p5 bra 	$Lt_0_25602;\n"
"	.loc	16	120	0\n"
"	ld.param.u64 	%rd36, [__cudaparm_kernel_pair_lj3];\n"
"	add.u64 	%rd37, %rd36, %rd34;\n"
"	ld.global.v4.f32 	{%f117,%f118,%f119,_}, [%rd37+0];\n"
"	mov.f32 	%f120, %f64;\n"
"	mov.f32 	%f121, %f62;\n"
"	mul.ftz.f32 	%f122, %f117, %f121;\n"
"	sub.ftz.f32 	%f123, %f122, %f118;\n"
"	mul.ftz.f32 	%f124, %f120, %f123;\n"
"	sub.ftz.f32 	%f125, %f124, %f119;\n"
"	fma.rn.ftz.f32 	%f38, %f39, %f125, %f38;\n"
"$Lt_0_25602:\n"
"$Lt_0_25090:\n"
"	ld.param.s32 	%r63, [__cudaparm_kernel_pair_vflag];\n"
"	mov.u32 	%r64, 0;\n"
"	setp.le.s32 	%p8, %r63, %r64;\n"
"	@%p8 bra 	$Lt_0_26114;\n"
"	.loc	16	124	0\n"
"	mov.f32 	%f126, %f10;\n"
"	mul.ftz.f32 	%f127, %f52, %f52;\n"
"	fma.rn.ftz.f32 	%f128, %f112, %f127, %f126;\n"
"	mov.f32 	%f10, %f128;\n"
"	.loc	16	125	0\n"
"	mov.f32 	%f129, %f12;\n"
"	fma.rn.ftz.f32 	%f130, %f112, %f54, %f129;\n"
"	mov.f32 	%f12, %f130;\n"
"	.loc	16	126	0\n"
"	mov.f32 	%f131, %f14;\n"
"	mul.ftz.f32 	%f132, %f53, %f53;\n"
"	fma.rn.ftz.f32 	%f133, %f112, %f132, %f131;\n"
"	mov.f32 	%f14, %f133;\n"
"	.loc	16	127	0\n"
"	mov.f32 	%f134, %f16;\n"
"	mul.ftz.f32 	%f135, %f51, %f52;\n"
"	fma.rn.ftz.f32 	%f136, %f112, %f135, %f134;\n"
"	mov.f32 	%f16, %f136;\n"
"	.loc	16	128	0\n"
"	mov.f32 	%f137, %f18;\n"
"	mul.ftz.f32 	%f138, %f52, %f53;\n"
"	fma.rn.ftz.f32 	%f139, %f112, %f138, %f137;\n"
"	mov.f32 	%f18, %f139;\n"
"	.loc	16	129	0\n"
"	mul.ftz.f32 	%f140, %f51, %f53;\n"
"	fma.rn.ftz.f32 	%f19, %f112, %f140, %f19;\n"
"	mov.f32 	%f20, %f19;\n"
"$Lt_0_26114:\n"
"$Lt_0_23554:\n"
"	.loc	16	68	0\n"
"	mul.lo.u64 	%rd38, %rd27, 4;\n"
"	add.u64 	%rd20, %rd20, %rd38;\n"
"	setp.lt.u64 	%p9, %rd20, %rd19;\n"
"	@%p9 bra 	$Lt_0_23298;\n"
"	bra.uni 	$Lt_0_22786;\n"
"$Lt_0_32514:\n"
"	mov.f32 	%f34, 0f00000000;    	\n"
"	mov.f32 	%f35, 0f00000000;    	\n"
"	mov.f32 	%f36, 0f00000000;    	\n"
"	mov.f32 	%f37, 0f00000000;    	\n"
"	mov.f32 	%f38, 0f00000000;    	\n"
"$Lt_0_22786:\n"
"	mov.u32 	%r65, 1;\n"
"	setp.le.s32 	%p10, %r1, %r65;\n"
"	@%p10 bra 	$Lt_0_28930;\n"
"	.loc	16	134	0\n"
"	mov.u64 	%rd39, __cuda___cuda_local_var_32635_55_non_const_red_acc144;\n"
"	cvt.s64.s32 	%rd40, %r2;\n"
"	mul.wide.s32 	%rd41, %r2, 4;\n"
"	add.u64 	%rd42, %rd39, %rd41;\n"
"	mov.f32 	%f141, %f36;\n"
"	st.shared.f32 	[%rd42+0], %f141;\n"
"	mov.f32 	%f142, %f35;\n"
"	st.shared.f32 	[%rd42+512], %f142;\n"
"	mov.f32 	%f143, %f34;\n"
"	st.shared.f32 	[%rd42+1024], %f143;\n"
"	mov.f32 	%f144, %f38;\n"
"	st.shared.f32 	[%rd42+1536], %f144;\n"
"	mov.f32 	%f145, %f37;\n"
"	st.shared.f32 	[%rd42+2048], %f145;\n"
"	shr.s32 	%r66, %r1, 31;\n"
"	mov.s32 	%r67, 1;\n"
"	and.b32 	%r68, %r66, %r67;\n"
"	add.s32 	%r69, %r68, %r1;\n"
"	shr.s32 	%r70, %r69, 1;\n"
"	mov.s32 	%r71, %r70;\n"
"	mov.u32 	%r72, 0;\n"
"	setp.ne.u32 	%p11, %r70, %r72;\n"
"	@!%p11 bra 	$Lt_0_27394;\n"
"$Lt_0_27906:\n"
"	setp.ge.u32 	%p12, %r14, %r71;\n"
"	@%p12 bra 	$Lt_0_28162;\n"
"	add.u32 	%r73, %r2, %r71;\n"
"	cvt.u64.u32 	%rd43, %r73;\n"
"	mul.wide.u32 	%rd44, %r73, 4;\n"
"	add.u64 	%rd45, %rd39, %rd44;\n"
"	ld.shared.f32 	%f146, [%rd45+0];\n"
"	add.ftz.f32 	%f141, %f146, %f141;\n"
"	st.shared.f32 	[%rd42+0], %f141;\n"
"	ld.shared.f32 	%f147, [%rd45+512];\n"
"	add.ftz.f32 	%f142, %f147, %f142;\n"
"	st.shared.f32 	[%rd42+512], %f142;\n"
"	ld.shared.f32 	%f148, [%rd45+1024];\n"
"	add.ftz.f32 	%f143, %f148, %f143;\n"
"	st.shared.f32 	[%rd42+1024], %f143;\n"
"	ld.shared.f32 	%f149, [%rd45+1536];\n"
"	add.ftz.f32 	%f144, %f149, %f144;\n"
"	st.shared.f32 	[%rd42+1536], %f144;\n"
"	ld.shared.f32 	%f150, [%rd45+2048];\n"
"	add.ftz.f32 	%f145, %f150, %f145;\n"
"	st.shared.f32 	[%rd42+2048], %f145;\n"
"$Lt_0_28162:\n"
"	shr.u32 	%r71, %r71, 1;\n"
"	mov.u32 	%r74, 0;\n"
"	setp.ne.u32 	%p13, %r71, %r74;\n"
"	@%p13 bra 	$Lt_0_27906;\n"
"$Lt_0_27394:\n"
"	mov.f32 	%f36, %f141;\n"
"	mov.f32 	%f35, %f142;\n"
"	mov.f32 	%f34, %f143;\n"
"	mov.f32 	%f38, %f144;\n"
"	mov.f32 	%f37, %f145;\n"
"	ld.param.s32 	%r75, [__cudaparm_kernel_pair_vflag];\n"
"	mov.u32 	%r76, 0;\n"
"	setp.le.s32 	%p14, %r75, %r76;\n"
"	@%p14 bra 	$Lt_0_28930;\n"
"	mov.f32 	%f141, %f10;\n"
"	st.shared.f32 	[%rd42+0], %f141;\n"
"	mov.f32 	%f142, %f12;\n"
"	st.shared.f32 	[%rd42+512], %f142;\n"
"	mov.f32 	%f143, %f14;\n"
"	st.shared.f32 	[%rd42+1024], %f143;\n"
"	mov.f32 	%f144, %f16;\n"
"	st.shared.f32 	[%rd42+1536], %f144;\n"
"	mov.f32 	%f145, %f18;\n"
"	st.shared.f32 	[%rd42+2048], %f145;\n"
"	mov.f32 	%f151, %f19;\n"
"	st.shared.f32 	[%rd42+2560], %f151;\n"
"	mov.s32 	%r77, %r70;\n"
"	@!%p11 bra 	$Lt_0_29442;\n"
"$Lt_0_29954:\n"
"	setp.ge.u32 	%p15, %r14, %r77;\n"
"	@%p15 bra 	$Lt_0_30210;\n"
"	add.u32 	%r78, %r2, %r77;\n"
"	cvt.u64.u32 	%rd46, %r78;\n"
"	mul.wide.u32 	%rd47, %r78, 4;\n"
"	add.u64 	%rd48, %rd39, %rd47;\n"
"	ld.shared.f32 	%f152, [%rd48+0];\n"
"	add.ftz.f32 	%f141, %f152, %f141;\n"
"	st.shared.f32 	[%rd42+0], %f141;\n"
"	ld.shared.f32 	%f153, [%rd48+512];\n"
"	add.ftz.f32 	%f142, %f153, %f142;\n"
"	st.shared.f32 	[%rd42+512], %f142;\n"
"	ld.shared.f32 	%f154, [%rd48+1024];\n"
"	add.ftz.f32 	%f143, %f154, %f143;\n"
"	st.shared.f32 	[%rd42+1024], %f143;\n"
"	ld.shared.f32 	%f155, [%rd48+1536];\n"
"	add.ftz.f32 	%f144, %f155, %f144;\n"
"	st.shared.f32 	[%rd42+1536], %f144;\n"
"	ld.shared.f32 	%f156, [%rd48+2048];\n"
"	add.ftz.f32 	%f145, %f156, %f145;\n"
"	st.shared.f32 	[%rd42+2048], %f145;\n"
"	ld.shared.f32 	%f157, [%rd48+2560];\n"
"	add.ftz.f32 	%f151, %f157, %f151;\n"
"	st.shared.f32 	[%rd42+2560], %f151;\n"
"$Lt_0_30210:\n"
"	shr.u32 	%r77, %r77, 1;\n"
"	mov.u32 	%r79, 0;\n"
"	setp.ne.u32 	%p16, %r77, %r79;\n"
"	@%p16 bra 	$Lt_0_29954;\n"
"$Lt_0_29442:\n"
"	mov.f32 	%f10, %f141;\n"
"	mov.f32 	%f12, %f142;\n"
"	mov.f32 	%f14, %f143;\n"
"	mov.f32 	%f16, %f144;\n"
"	mov.f32 	%f18, %f145;\n"
"	mov.f32 	%f20, %f151;\n"
"$Lt_0_28930:\n"
"$Lt_0_26882:\n"
"	mov.u32 	%r80, 0;\n"
"	setp.ne.s32 	%p17, %r14, %r80;\n"
"	@%p17 bra 	$Lt_0_30978;\n"
"	ld.param.u64 	%rd49, [__cudaparm_kernel_pair___val_paramengv];\n"
"	add.u64 	%rd50, %rd49, %rd3;\n"
"	ld.param.s32 	%r81, [__cudaparm_kernel_pair_eflag];\n"
"	mov.u32 	%r82, 0;\n"
"	setp.le.s32 	%p18, %r81, %r82;\n"
"	@%p18 bra 	$Lt_0_31490;\n"
"	st.global.f32 	[%rd50+0], %f38;\n"
"	cvt.s64.s32 	%rd51, %r9;\n"
"	mul.wide.s32 	%rd52, %r9, 4;\n"
"	add.u64 	%rd53, %rd52, %rd50;\n"
"	st.global.f32 	[%rd53+0], %f37;\n"
"	add.u64 	%rd50, %rd52, %rd53;\n"
"$Lt_0_31490:\n"
"	ld.param.s32 	%r83, [__cudaparm_kernel_pair_vflag];\n"
"	mov.u32 	%r84, 0;\n"
"	setp.le.s32 	%p19, %r83, %r84;\n"
"	@%p19 bra 	$Lt_0_32002;\n"
"	mov.f32 	%f158, %f10;\n"
"	st.global.f32 	[%rd50+0], %f158;\n"
"	cvt.s64.s32 	%rd54, %r9;\n"
"	mul.wide.s32 	%rd55, %r9, 4;\n"
"	add.u64 	%rd56, %rd55, %rd50;\n"
"	mov.f32 	%f159, %f12;\n"
"	st.global.f32 	[%rd56+0], %f159;\n"
"	add.u64 	%rd57, %rd55, %rd56;\n"
"	mov.f32 	%f160, %f14;\n"
"	st.global.f32 	[%rd57+0], %f160;\n"
"	add.u64 	%rd58, %rd55, %rd57;\n"
"	mov.f32 	%f161, %f16;\n"
"	st.global.f32 	[%rd58+0], %f161;\n"
"	add.u64 	%rd50, %rd55, %rd58;\n"
"	mov.f32 	%f162, %f18;\n"
"	st.global.f32 	[%rd50+0], %f162;\n"
"	mov.f32 	%f163, %f20;\n"
"	add.u64 	%rd59, %rd55, %rd50;\n"
"	st.global.f32 	[%rd59+0], %f163;\n"
"$Lt_0_32002:\n"
"	ld.param.u64 	%rd60, [__cudaparm_kernel_pair_ans];\n"
"	mul.lo.u64 	%rd61, %rd2, 16;\n"
"	add.u64 	%rd62, %rd60, %rd61;\n"
"	mov.f32 	%f164, %f165;\n"
"	st.global.v4.f32 	[%rd62+0], {%f36,%f35,%f34,%f164};\n"
"$Lt_0_30978:\n"
"$Lt_0_21762:\n"
"	.loc	16	137	0\n"
"	exit;\n"
"$LDWend_kernel_pair:\n"
"	}\n"
"	.entry kernel_pair_fast (\n"
"		.param .u64 __cudaparm_kernel_pair_fast_x_,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_lj1_in,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_lj3_in,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_sp_lj_in,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_dev_nbor,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_dev_packed,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_ans,\n"
"		.param .u64 __cudaparm_kernel_pair_fast___val_paramengv,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_eflag,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_vflag,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_inum,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_nbor_pitch,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_q_,\n"
"		.param .f32 __cudaparm_kernel_pair_fast_cut_coulsq,\n"
"		.param .f32 __cudaparm_kernel_pair_fast_qqrd2e,\n"
"		.param .f32 __cudaparm_kernel_pair_fast_g_ewald,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_t_per_atom)\n"
"	{\n"
"	.reg .u32 %r<88>;\n"
"	.reg .u64 %rd<76>;\n"
"	.reg .f32 %f<170>;\n"
"	.reg .pred %p<24>;\n"
"	.shared .align 4 .b8 __cuda___cuda_local_var_32654_33_non_const_sp_lj3320[32];\n"
"	.shared .align 16 .b8 __cuda___cuda_local_var_32652_34_non_const_lj13360[1936];\n"
"	.shared .align 16 .b8 __cuda___cuda_local_var_32653_34_non_const_lj35296[1936];\n"
"	.shared .align 4 .b8 __cuda___cuda_local_var_32749_55_non_const_red_acc7232[3072];\n"
"	.loc	16	147	0\n"
"$LDWbegin_kernel_pair_fast:\n"
"	cvt.s32.u32 	%r1, %tid.x;\n"
"	mov.u32 	%r2, 7;\n"
"	setp.gt.s32 	%p1, %r1, %r2;\n"
"	@%p1 bra 	$Lt_1_24066;\n"
"	.loc	16	155	0\n"
"	mov.u64 	%rd1, __cuda___cuda_local_var_32654_33_non_const_sp_lj3320;\n"
"	cvt.s64.s32 	%rd2, %r1;\n"
"	mul.wide.s32 	%rd3, %r1, 4;\n"
"	ld.param.u64 	%rd4, [__cudaparm_kernel_pair_fast_sp_lj_in];\n"
"	add.u64 	%rd5, %rd4, %rd3;\n"
"	ld.global.f32 	%f1, [%rd5+0];\n"
"	add.u64 	%rd6, %rd3, %rd1;\n"
"	st.shared.f32 	[%rd6+0], %f1;\n"
"$Lt_1_24066:\n"
"	mov.u64 	%rd1, __cuda___cuda_local_var_32654_33_non_const_sp_lj3320;\n"
"	mov.u32 	%r3, 120;\n"
"	setp.gt.s32 	%p2, %r1, %r3;\n"
"	@%p2 bra 	$Lt_1_24578;\n"
"	.loc	16	157	0\n"
"	mov.u64 	%rd7, __cuda___cuda_local_var_32652_34_non_const_lj13360;\n"
"	cvt.s64.s32 	%rd8, %r1;\n"
"	mul.wide.s32 	%rd9, %r1, 16;\n"
"	ld.param.u64 	%rd10, [__cudaparm_kernel_pair_fast_lj1_in];\n"
"	add.u64 	%rd11, %rd10, %rd9;\n"
"	add.u64 	%rd12, %rd9, %rd7;\n"
"	ld.global.v4.f32 	{%f2,%f3,%f4,%f5}, [%rd11+0];\n"
"	st.shared.v4.f32 	[%rd12+0], {%f2,%f3,%f4,%f5};\n"
"	ld.param.s32 	%r4, [__cudaparm_kernel_pair_fast_eflag];\n"
"	mov.u32 	%r5, 0;\n"
"	setp.le.s32 	%p3, %r4, %r5;\n"
"	@%p3 bra 	$Lt_1_25090;\n"
"	.loc	16	159	0\n"
"	mov.u64 	%rd13, __cuda___cuda_local_var_32653_34_non_const_lj35296;\n"
"	ld.param.u64 	%rd14, [__cudaparm_kernel_pair_fast_lj3_in];\n"
"	add.u64 	%rd15, %rd14, %rd9;\n"
"	add.u64 	%rd16, %rd9, %rd13;\n"
"	ld.global.v4.f32 	{%f6,%f7,%f8,%f9}, [%rd15+0];\n"
"	st.shared.v4.f32 	[%rd16+0], {%f6,%f7,%f8,%f9};\n"
"$Lt_1_25090:\n"
"	mov.u64 	%rd13, __cuda___cuda_local_var_32653_34_non_const_lj35296;\n"
"$Lt_1_24578:\n"
"	mov.u64 	%rd13, __cuda___cuda_local_var_32653_34_non_const_lj35296;\n"
"	mov.u64 	%rd7, __cuda___cuda_local_var_32652_34_non_const_lj13360;\n"
"	.loc	16	168	0\n"
"	mov.f32 	%f10, 0f00000000;    	\n"
"	mov.f32 	%f11, %f10;\n"
"	mov.f32 	%f12, 0f00000000;    	\n"
"	mov.f32 	%f13, %f12;\n"
"	mov.f32 	%f14, 0f00000000;    	\n"
"	mov.f32 	%f15, %f14;\n"
"	mov.f32 	%f16, 0f00000000;    	\n"
"	mov.f32 	%f17, %f16;\n"
"	mov.f32 	%f18, 0f00000000;    	\n"
"	mov.f32 	%f19, %f18;\n"
"	mov.f32 	%f20, 0f00000000;    	\n"
"	mov.f32 	%f21, %f20;\n"
"	.loc	16	170	0\n"
"	bar.sync 	0;\n"
"	ld.param.s32 	%r6, [__cudaparm_kernel_pair_fast_t_per_atom];\n"
"	div.s32 	%r7, %r1, %r6;\n"
"	cvt.s32.u32 	%r8, %ntid.x;\n"
"	div.s32 	%r9, %r8, %r6;\n"
"	cvt.s32.u32 	%r10, %ctaid.x;\n"
"	mul.lo.s32 	%r11, %r10, %r9;\n"
"	add.s32 	%r12, %r7, %r11;\n"
"	ld.param.s32 	%r13, [__cudaparm_kernel_pair_fast_inum];\n"
"	setp.ge.s32 	%p4, %r12, %r13;\n"
"	@%p4 bra 	$Lt_1_34818;\n"
"	.loc	16	175	0\n"
"	cvt.s64.s32 	%rd17, %r12;\n"
"	mul.wide.s32 	%rd18, %r12, 4;\n"
"	ld.param.u64 	%rd19, [__cudaparm_kernel_pair_fast_dev_nbor];\n"
"	add.u64 	%rd20, %rd18, %rd19;\n"
"	ld.global.s32 	%r14, [%rd20+0];\n"
"	ld.param.s32 	%r15, [__cudaparm_kernel_pair_fast_nbor_pitch];\n"
"	cvt.s64.s32 	%rd21, %r15;\n"
"	mul.wide.s32 	%rd22, %r15, 4;\n"
"	add.u64 	%rd23, %rd22, %rd20;\n"
"	ld.global.s32 	%r16, [%rd23+0];\n"
"	sub.s32 	%r17, %r6, 1;\n"
"	and.b32 	%r18, %r17, %r1;\n"
"	cvt.s64.s32 	%rd24, %r18;\n"
"	mul.wide.s32 	%rd25, %r18, 4;\n"
"	ld.param.u64 	%rd26, [__cudaparm_kernel_pair_fast_dev_packed];\n"
"	setp.ne.u64 	%p5, %rd26, %rd19;\n"
"	@%p5 bra 	$Lt_1_26370;\n"
"	cvt.s32.s64 	%r19, %rd21;\n"
"	mul.lo.s32 	%r20, %r19, %r6;\n"
"	mov.s32 	%r21, %r20;\n"
"	mul.lo.s32 	%r22, %r17, %r12;\n"
"	add.s32 	%r23, %r19, %r22;\n"
"	cvt.s64.s32 	%rd27, %r23;\n"
"	mul.wide.s32 	%rd28, %r23, 4;\n"
"	add.u64 	%rd29, %rd23, %rd28;\n"
"	and.b32 	%r24, %r17, %r16;\n"
"	cvt.s64.s32 	%rd30, %r24;\n"
"	div.s32 	%r25, %r16, %r6;\n"
"	mul.lo.s32 	%r26, %r20, %r25;\n"
"	cvt.s64.s32 	%rd31, %r26;\n"
"	add.u64 	%rd32, %rd30, %rd31;\n"
"	mul.lo.u64 	%rd33, %rd32, 4;\n"
"	add.u64 	%rd34, %rd29, %rd33;\n"
"	add.u64 	%rd35, %rd25, %rd29;\n"
"	bra.uni 	$Lt_1_26114;\n"
"$Lt_1_26370:\n"
"	add.u64 	%rd36, %rd22, %rd23;\n"
"	ld.global.s32 	%r27, [%rd36+0];\n"
"	cvt.s64.s32 	%rd37, %r27;\n"
"	mul.wide.s32 	%rd38, %r27, 4;\n"
"	add.u64 	%rd39, %rd26, %rd38;\n"
"	cvt.s64.s32 	%rd40, %r16;\n"
"	mul.wide.s32 	%rd41, %r16, 4;\n"
"	add.u64 	%rd34, %rd39, %rd41;\n"
"	mov.s32 	%r21, %r6;\n"
"	add.u64 	%rd35, %rd25, %rd39;\n"
"$Lt_1_26114:\n"
"	.loc	16	178	0\n"
"	mov.u32 	%r28, %r14;\n"
"	mov.s32 	%r29, 0;\n"
"	mov.u32 	%r30, %r29;\n"
"	mov.s32 	%r31, 0;\n"
"	mov.u32 	%r32, %r31;\n"
"	mov.s32 	%r33, 0;\n"
"	mov.u32 	%r34, %r33;\n"
"	tex.1d.v4.f32.s32 {%f22,%f23,%f24,%f25},[pos_tex,{%r28,%r30,%r32,%r34}];\n"
"	mov.f32 	%f26, %f22;\n"
"	mov.f32 	%f27, %f23;\n"
"	mov.f32 	%f28, %f24;\n"
"	mov.f32 	%f29, %f25;\n"
"	.loc	16	179	0\n"
"	mov.u32 	%r35, %r14;\n"
"	mov.s32 	%r36, 0;\n"
"	mov.u32 	%r37, %r36;\n"
"	mov.s32 	%r38, 0;\n"
"	mov.u32 	%r39, %r38;\n"
"	mov.s32 	%r40, 0;\n"
"	mov.u32 	%r41, %r40;\n"
"	tex.1d.v4.f32.s32 {%f30,%f31,%f32,%f33},[q_tex,{%r35,%r37,%r39,%r41}];\n"
"	mov.f32 	%f34, %f30;\n"
"	setp.ge.u64 	%p6, %rd35, %rd34;\n"
"	@%p6 bra 	$Lt_1_36354;\n"
"	cvt.rzi.ftz.s32.f32 	%r42, %f29;\n"
"	cvt.s64.s32 	%rd42, %r21;\n"
"	mul.lo.s32 	%r43, %r42, 11;\n"
"	cvt.rn.f32.s32 	%f35, %r43;\n"
"	mov.f32 	%f36, 0f00000000;    	\n"
"	mov.f32 	%f37, 0f00000000;    	\n"
"	mov.f32 	%f38, 0f00000000;    	\n"
"	mov.f32 	%f39, 0f00000000;    	\n"
"	mov.f32 	%f40, 0f00000000;    	\n"
"$Lt_1_27138:\n"
"	.loc	16	184	0\n"
"	ld.global.s32 	%r44, [%rd35+0];\n"
"	.loc	16	187	0\n"
"	shr.s32 	%r45, %r44, 30;\n"
"	and.b32 	%r46, %r45, 3;\n"
"	cvt.s64.s32 	%rd43, %r46;\n"
"	mul.wide.s32 	%rd44, %r46, 4;\n"
"	add.u64 	%rd45, %rd1, %rd44;\n"
"	ld.shared.f32 	%f41, [%rd45+0];\n"
"	.loc	16	188	0\n"
"	mov.f32 	%f42, 0f3f800000;    	\n"
"	ld.shared.f32 	%f43, [%rd45+16];\n"
"	sub.ftz.f32 	%f44, %f42, %f43;\n"
"	.loc	16	191	0\n"
"	and.b32 	%r47, %r44, 1073741823;\n"
"	mov.u32 	%r48, %r47;\n"
"	mov.s32 	%r49, 0;\n"
"	mov.u32 	%r50, %r49;\n"
"	mov.s32 	%r51, 0;\n"
"	mov.u32 	%r52, %r51;\n"
"	mov.s32 	%r53, 0;\n"
"	mov.u32 	%r54, %r53;\n"
"	tex.1d.v4.f32.s32 {%f45,%f46,%f47,%f48},[pos_tex,{%r48,%r50,%r52,%r54}];\n"
"	mov.f32 	%f49, %f45;\n"
"	mov.f32 	%f50, %f46;\n"
"	mov.f32 	%f51, %f47;\n"
"	mov.f32 	%f52, %f48;\n"
"	sub.ftz.f32 	%f53, %f27, %f50;\n"
"	sub.ftz.f32 	%f54, %f26, %f49;\n"
"	sub.ftz.f32 	%f55, %f28, %f51;\n"
"	mul.ftz.f32 	%f56, %f53, %f53;\n"
"	fma.rn.ftz.f32 	%f57, %f54, %f54, %f56;\n"
"	fma.rn.ftz.f32 	%f58, %f55, %f55, %f57;\n"
"	add.ftz.f32 	%f59, %f35, %f52;\n"
"	cvt.rzi.ftz.s32.f32 	%r55, %f59;\n"
"	cvt.s64.s32 	%rd46, %r55;\n"
"	mul.wide.s32 	%rd47, %r55, 16;\n"
"	add.u64 	%rd48, %rd47, %rd7;\n"
"	ld.shared.f32 	%f60, [%rd48+8];\n"
"	setp.gt.ftz.f32 	%p7, %f60, %f58;\n"
"	@!%p7 bra 	$Lt_1_29954;\n"
"	rcp.approx.ftz.f32 	%f61, %f58;\n"
"	ld.shared.f32 	%f62, [%rd48+12];\n"
"	setp.lt.ftz.f32 	%p8, %f58, %f62;\n"
"	@!%p8 bra 	$Lt_1_28162;\n"
"	.loc	16	206	0\n"
"	rsqrt.approx.ftz.f32 	%f63, %f58;\n"
"	mul.ftz.f32 	%f64, %f61, %f63;\n"
"	mov.f32 	%f65, %f64;\n"
"	.loc	16	207	0\n"
"	mul.ftz.f32 	%f66, %f64, %f64;\n"
"	mov.f32 	%f67, %f66;\n"
"	.loc	16	208	0\n"
"	mul.ftz.f32 	%f68, %f66, %f41;\n"
"	ld.shared.v2.f32 	{%f69,%f70}, [%rd48+0];\n"
"	mul.ftz.f32 	%f71, %f69, %f64;\n"
"	sub.ftz.f32 	%f72, %f71, %f70;\n"
"	mul.ftz.f32 	%f73, %f68, %f72;\n"
"	bra.uni 	$Lt_1_27906;\n"
"$Lt_1_28162:\n"
"	.loc	16	210	0\n"
"	mov.f32 	%f73, 0f00000000;    	\n"
"$Lt_1_27906:\n"
"	ld.param.f32 	%f74, [__cudaparm_kernel_pair_fast_cut_coulsq];\n"
"	setp.gt.ftz.f32 	%p9, %f74, %f58;\n"
"	@!%p9 bra 	$Lt_1_28674;\n"
"	.loc	20	518	0\n"
"	rsqrt.approx.ftz.f32 	%f75, %f61;\n"
"	ld.param.f32 	%f76, [__cudaparm_kernel_pair_fast_g_ewald];\n"
"	mul.ftz.f32 	%f77, %f76, %f75;\n"
"	mul.ftz.f32 	%f78, %f77, %f77;\n"
"	neg.ftz.f32 	%f79, %f78;\n"
"	mov.f32 	%f80, 0f3fb8aa3b;    	\n"
"	mul.ftz.f32 	%f81, %f79, %f80;\n"
"	ex2.approx.ftz.f32 	%f82, %f81;\n"
"	.loc	16	217	0\n"
"	mov.f32 	%f83, 0f3f800000;    	\n"
"	mov.f32 	%f84, 0f3ea7ba05;    	\n"
"	fma.rn.ftz.f32 	%f85, %f84, %f77, %f83;\n"
"	rcp.approx.ftz.f32 	%f86, %f85;\n"
"	mov.f32 	%f87, 0f3e827906;    	\n"
"	mov.f32 	%f88, 0fbe91a98e;    	\n"
"	mov.f32 	%f89, 0f3fb5f0e3;    	\n"
"	mov.f32 	%f90, 0fbfba00e3;    	\n"
"	mov.f32 	%f91, 0f3f87dc22;    	\n"
"	fma.rn.ftz.f32 	%f92, %f91, %f86, %f90;\n"
"	fma.rn.ftz.f32 	%f93, %f86, %f92, %f89;\n"
"	fma.rn.ftz.f32 	%f94, %f86, %f93, %f88;\n"
"	fma.rn.ftz.f32 	%f95, %f86, %f94, %f87;\n"
"	mul.ftz.f32 	%f96, %f86, %f95;\n"
"	mul.ftz.f32 	%f97, %f82, %f96;\n"
"	mov.f32 	%f98, %f97;\n"
"	.loc	16	218	0\n"
"	mov.u32 	%r56, %r47;\n"
"	mov.s32 	%r57, 0;\n"
"	mov.u32 	%r58, %r57;\n"
"	mov.s32 	%r59, 0;\n"
"	mov.u32 	%r60, %r59;\n"
"	mov.s32 	%r61, 0;\n"
"	mov.u32 	%r62, %r61;\n"
"	tex.1d.v4.f32.s32 {%f99,%f100,%f101,%f102},[q_tex,{%r56,%r58,%r60,%r62}];\n"
"	mov.f32 	%f103, %f99;\n"
"	ld.param.f32 	%f104, [__cudaparm_kernel_pair_fast_qqrd2e];\n"
"	mul.ftz.f32 	%f105, %f104, %f34;\n"
"	mul.ftz.f32 	%f106, %f105, %f103;\n"
"	div.approx.ftz.f32 	%f107, %f106, %f75;\n"
"	mov.f32 	%f108, %f107;\n"
"	.loc	16	219	0\n"
"	mov.f32 	%f109, 0f3f906ebb;   	\n"
"	mul.ftz.f32 	%f110, %f77, %f109;\n"
"	fma.rn.ftz.f32 	%f111, %f82, %f110, %f97;\n"
"	sub.ftz.f32 	%f112, %f111, %f44;\n"
"	mul.ftz.f32 	%f113, %f107, %f112;\n"
"	bra.uni 	$Lt_1_28418;\n"
"$Lt_1_28674:\n"
"	.loc	16	221	0\n"
"	mov.f32 	%f113, 0f00000000;   	\n"
"$Lt_1_28418:\n"
"	.loc	16	225	0\n"
"	add.ftz.f32 	%f114, %f113, %f73;\n"
"	mul.ftz.f32 	%f115, %f114, %f61;\n"
"	fma.rn.ftz.f32 	%f38, %f54, %f115, %f38;\n"
"	.loc	16	226	0\n"
"	fma.rn.ftz.f32 	%f37, %f53, %f115, %f37;\n"
"	.loc	16	227	0\n"
"	fma.rn.ftz.f32 	%f36, %f55, %f115, %f36;\n"
"	ld.param.s32 	%r63, [__cudaparm_kernel_pair_fast_eflag];\n"
"	mov.u32 	%r64, 0;\n"
"	setp.le.s32 	%p10, %r63, %r64;\n"
"	@%p10 bra 	$Lt_1_29442;\n"
"	.loc	16	230	0\n"
"	mov.f32 	%f116, %f108;\n"
"	mov.f32 	%f117, %f98;\n"
"	sub.ftz.f32 	%f118, %f117, %f44;\n"
"	fma.rn.ftz.f32 	%f119, %f116, %f118, %f39;\n"
"	selp.f32 	%f39, %f119, %f39, %p9;\n"
"	@!%p8 bra 	$Lt_1_29442;\n"
"	.loc	16	233	0\n"
"	add.u64 	%rd49, %rd47, %rd13;\n"
"	mov.f32 	%f120, %f67;\n"
"	ld.shared.v4.f32 	{%f121,%f122,%f123,_}, [%rd49+0];\n"
"	mov.f32 	%f124, %f65;\n"
"	mul.ftz.f32 	%f125, %f121, %f124;\n"
"	sub.ftz.f32 	%f126, %f125, %f122;\n"
"	mul.ftz.f32 	%f127, %f120, %f126;\n"
"	.loc	16	234	0\n"
"	sub.ftz.f32 	%f128, %f127, %f123;\n"
"	fma.rn.ftz.f32 	%f40, %f41, %f128, %f40;\n"
"$Lt_1_29442:\n"
"$Lt_1_28930:\n"
"	ld.param.s32 	%r65, [__cudaparm_kernel_pair_fast_vflag];\n"
"	mov.u32 	%r66, 0;\n"
"	setp.le.s32 	%p11, %r65, %r66;\n"
"	@%p11 bra 	$Lt_1_29954;\n"
"	.loc	16	238	0\n"
"	mov.f32 	%f129, %f11;\n"
"	mul.ftz.f32 	%f130, %f54, %f54;\n"
"	fma.rn.ftz.f32 	%f131, %f115, %f130, %f129;\n"
"	mov.f32 	%f11, %f131;\n"
"	.loc	16	239	0\n"
"	mov.f32 	%f132, %f13;\n"
"	fma.rn.ftz.f32 	%f133, %f115, %f56, %f132;\n"
"	mov.f32 	%f13, %f133;\n"
"	.loc	16	240	0\n"
"	mov.f32 	%f134, %f15;\n"
"	mul.ftz.f32 	%f135, %f55, %f55;\n"
"	fma.rn.ftz.f32 	%f136, %f115, %f135, %f134;\n"
"	mov.f32 	%f15, %f136;\n"
"	.loc	16	241	0\n"
"	mov.f32 	%f137, %f17;\n"
"	mul.ftz.f32 	%f138, %f53, %f54;\n"
"	fma.rn.ftz.f32 	%f139, %f115, %f138, %f137;\n"
"	mov.f32 	%f17, %f139;\n"
"	.loc	16	242	0\n"
"	mov.f32 	%f140, %f19;\n"
"	mul.ftz.f32 	%f141, %f54, %f55;\n"
"	fma.rn.ftz.f32 	%f142, %f115, %f141, %f140;\n"
"	mov.f32 	%f19, %f142;\n"
"	.loc	16	243	0\n"
"	mul.ftz.f32 	%f143, %f53, %f55;\n"
"	fma.rn.ftz.f32 	%f20, %f115, %f143, %f20;\n"
"	mov.f32 	%f21, %f20;\n"
"$Lt_1_29954:\n"
"$Lt_1_27394:\n"
"	.loc	16	183	0\n"
"	mul.lo.u64 	%rd50, %rd42, 4;\n"
"	add.u64 	%rd35, %rd35, %rd50;\n"
"	setp.lt.u64 	%p12, %rd35, %rd34;\n"
"	@%p12 bra 	$Lt_1_27138;\n"
"	bra.uni 	$Lt_1_26626;\n"
"$Lt_1_36354:\n"
"	mov.f32 	%f36, 0f00000000;    	\n"
"	mov.f32 	%f37, 0f00000000;    	\n"
"	mov.f32 	%f38, 0f00000000;    	\n"
"	mov.f32 	%f39, 0f00000000;    	\n"
"	mov.f32 	%f40, 0f00000000;    	\n"
"$Lt_1_26626:\n"
"	mov.u32 	%r67, 1;\n"
"	setp.le.s32 	%p13, %r6, %r67;\n"
"	@%p13 bra 	$Lt_1_32770;\n"
"	.loc	16	248	0\n"
"	mov.u64 	%rd51, __cuda___cuda_local_var_32749_55_non_const_red_acc7232;\n"
"	cvt.s64.s32 	%rd52, %r1;\n"
"	mul.wide.s32 	%rd53, %r1, 4;\n"
"	add.u64 	%rd54, %rd51, %rd53;\n"
"	mov.f32 	%f144, %f38;\n"
"	st.shared.f32 	[%rd54+0], %f144;\n"
"	mov.f32 	%f145, %f37;\n"
"	st.shared.f32 	[%rd54+512], %f145;\n"
"	mov.f32 	%f146, %f36;\n"
"	st.shared.f32 	[%rd54+1024], %f146;\n"
"	mov.f32 	%f147, %f40;\n"
"	st.shared.f32 	[%rd54+1536], %f147;\n"
"	mov.f32 	%f148, %f39;\n"
"	st.shared.f32 	[%rd54+2048], %f148;\n"
"	shr.s32 	%r68, %r6, 31;\n"
"	mov.s32 	%r69, 1;\n"
"	and.b32 	%r70, %r68, %r69;\n"
"	add.s32 	%r71, %r70, %r6;\n"
"	shr.s32 	%r72, %r71, 1;\n"
"	mov.s32 	%r73, %r72;\n"
"	mov.u32 	%r74, 0;\n"
"	setp.ne.u32 	%p14, %r72, %r74;\n"
"	@!%p14 bra 	$Lt_1_31234;\n"
"$Lt_1_31746:\n"
"	setp.ge.u32 	%p15, %r18, %r73;\n"
"	@%p15 bra 	$Lt_1_32002;\n"
"	add.u32 	%r75, %r1, %r73;\n"
"	cvt.u64.u32 	%rd55, %r75;\n"
"	mul.wide.u32 	%rd56, %r75, 4;\n"
"	add.u64 	%rd57, %rd51, %rd56;\n"
"	ld.shared.f32 	%f149, [%rd57+0];\n"
"	add.ftz.f32 	%f144, %f149, %f144;\n"
"	st.shared.f32 	[%rd54+0], %f144;\n"
"	ld.shared.f32 	%f150, [%rd57+512];\n"
"	add.ftz.f32 	%f145, %f150, %f145;\n"
"	st.shared.f32 	[%rd54+512], %f145;\n"
"	ld.shared.f32 	%f151, [%rd57+1024];\n"
"	add.ftz.f32 	%f146, %f151, %f146;\n"
"	st.shared.f32 	[%rd54+1024], %f146;\n"
"	ld.shared.f32 	%f152, [%rd57+1536];\n"
"	add.ftz.f32 	%f147, %f152, %f147;\n"
"	st.shared.f32 	[%rd54+1536], %f147;\n"
"	ld.shared.f32 	%f153, [%rd57+2048];\n"
"	add.ftz.f32 	%f148, %f153, %f148;\n"
"	st.shared.f32 	[%rd54+2048], %f148;\n"
"$Lt_1_32002:\n"
"	shr.u32 	%r73, %r73, 1;\n"
"	mov.u32 	%r76, 0;\n"
"	setp.ne.u32 	%p16, %r73, %r76;\n"
"	@%p16 bra 	$Lt_1_31746;\n"
"$Lt_1_31234:\n"
"	mov.f32 	%f38, %f144;\n"
"	mov.f32 	%f37, %f145;\n"
"	mov.f32 	%f36, %f146;\n"
"	mov.f32 	%f40, %f147;\n"
"	mov.f32 	%f39, %f148;\n"
"	ld.param.s32 	%r77, [__cudaparm_kernel_pair_fast_vflag];\n"
"	mov.u32 	%r78, 0;\n"
"	setp.le.s32 	%p17, %r77, %r78;\n"
"	@%p17 bra 	$Lt_1_32770;\n"
"	mov.f32 	%f144, %f11;\n"
"	st.shared.f32 	[%rd54+0], %f144;\n"
"	mov.f32 	%f145, %f13;\n"
"	st.shared.f32 	[%rd54+512], %f145;\n"
"	mov.f32 	%f146, %f15;\n"
"	st.shared.f32 	[%rd54+1024], %f146;\n"
"	mov.f32 	%f147, %f17;\n"
"	st.shared.f32 	[%rd54+1536], %f147;\n"
"	mov.f32 	%f148, %f19;\n"
"	st.shared.f32 	[%rd54+2048], %f148;\n"
"	mov.f32 	%f154, %f20;\n"
"	st.shared.f32 	[%rd54+2560], %f154;\n"
"	mov.s32 	%r79, %r72;\n"
"	@!%p14 bra 	$Lt_1_33282;\n"
"$Lt_1_33794:\n"
"	setp.ge.u32 	%p18, %r18, %r79;\n"
"	@%p18 bra 	$Lt_1_34050;\n"
"	add.u32 	%r80, %r1, %r79;\n"
"	cvt.u64.u32 	%rd58, %r80;\n"
"	mul.wide.u32 	%rd59, %r80, 4;\n"
"	add.u64 	%rd60, %rd51, %rd59;\n"
"	ld.shared.f32 	%f155, [%rd60+0];\n"
"	add.ftz.f32 	%f144, %f155, %f144;\n"
"	st.shared.f32 	[%rd54+0], %f144;\n"
"	ld.shared.f32 	%f156, [%rd60+512];\n"
"	add.ftz.f32 	%f145, %f156, %f145;\n"
"	st.shared.f32 	[%rd54+512], %f145;\n"
"	ld.shared.f32 	%f157, [%rd60+1024];\n"
"	add.ftz.f32 	%f146, %f157, %f146;\n"
"	st.shared.f32 	[%rd54+1024], %f146;\n"
"	ld.shared.f32 	%f158, [%rd60+1536];\n"
"	add.ftz.f32 	%f147, %f158, %f147;\n"
"	st.shared.f32 	[%rd54+1536], %f147;\n"
"	ld.shared.f32 	%f159, [%rd60+2048];\n"
"	add.ftz.f32 	%f148, %f159, %f148;\n"
"	st.shared.f32 	[%rd54+2048], %f148;\n"
"	ld.shared.f32 	%f160, [%rd60+2560];\n"
"	add.ftz.f32 	%f154, %f160, %f154;\n"
"	st.shared.f32 	[%rd54+2560], %f154;\n"
"$Lt_1_34050:\n"
"	shr.u32 	%r79, %r79, 1;\n"
"	mov.u32 	%r81, 0;\n"
"	setp.ne.u32 	%p19, %r79, %r81;\n"
"	@%p19 bra 	$Lt_1_33794;\n"
"$Lt_1_33282:\n"
"	mov.f32 	%f11, %f144;\n"
"	mov.f32 	%f13, %f145;\n"
"	mov.f32 	%f15, %f146;\n"
"	mov.f32 	%f17, %f147;\n"
"	mov.f32 	%f19, %f148;\n"
"	mov.f32 	%f21, %f154;\n"
"$Lt_1_32770:\n"
"$Lt_1_30722:\n"
"	mov.u32 	%r82, 0;\n"
"	setp.ne.s32 	%p20, %r18, %r82;\n"
"	@%p20 bra 	$Lt_1_34818;\n"
"	ld.param.u64 	%rd61, [__cudaparm_kernel_pair_fast___val_paramengv];\n"
"	add.u64 	%rd62, %rd61, %rd18;\n"
"	ld.param.s32 	%r83, [__cudaparm_kernel_pair_fast_eflag];\n"
"	mov.u32 	%r84, 0;\n"
"	setp.le.s32 	%p21, %r83, %r84;\n"
"	@%p21 bra 	$Lt_1_35330;\n"
"	st.global.f32 	[%rd62+0], %f40;\n"
"	cvt.s64.s32 	%rd63, %r13;\n"
"	mul.wide.s32 	%rd64, %r13, 4;\n"
"	add.u64 	%rd65, %rd64, %rd62;\n"
"	st.global.f32 	[%rd65+0], %f39;\n"
"	add.u64 	%rd62, %rd64, %rd65;\n"
"$Lt_1_35330:\n"
"	ld.param.s32 	%r85, [__cudaparm_kernel_pair_fast_vflag];\n"
"	mov.u32 	%r86, 0;\n"
"	setp.le.s32 	%p22, %r85, %r86;\n"
"	@%p22 bra 	$Lt_1_35842;\n"
"	mov.f32 	%f161, %f11;\n"
"	st.global.f32 	[%rd62+0], %f161;\n"
"	cvt.s64.s32 	%rd66, %r13;\n"
"	mul.wide.s32 	%rd67, %r13, 4;\n"
"	add.u64 	%rd68, %rd67, %rd62;\n"
"	mov.f32 	%f162, %f13;\n"
"	st.global.f32 	[%rd68+0], %f162;\n"
"	add.u64 	%rd69, %rd67, %rd68;\n"
"	mov.f32 	%f163, %f15;\n"
"	st.global.f32 	[%rd69+0], %f163;\n"
"	add.u64 	%rd70, %rd67, %rd69;\n"
"	mov.f32 	%f164, %f17;\n"
"	st.global.f32 	[%rd70+0], %f164;\n"
"	add.u64 	%rd62, %rd67, %rd70;\n"
"	mov.f32 	%f165, %f19;\n"
"	st.global.f32 	[%rd62+0], %f165;\n"
"	mov.f32 	%f166, %f21;\n"
"	add.u64 	%rd71, %rd67, %rd62;\n"
"	st.global.f32 	[%rd71+0], %f166;\n"
"$Lt_1_35842:\n"
"	ld.param.u64 	%rd72, [__cudaparm_kernel_pair_fast_ans];\n"
"	mul.lo.u64 	%rd73, %rd17, 16;\n"
"	add.u64 	%rd74, %rd72, %rd73;\n"
"	mov.f32 	%f167, %f168;\n"
"	st.global.v4.f32 	[%rd74+0], {%f38,%f37,%f36,%f167};\n"
"$Lt_1_34818:\n"
"$Lt_1_25602:\n"
"	.loc	16	251	0\n"
"	exit;\n"
"$LDWend_kernel_pair_fast:\n"
"	}\n"
;
