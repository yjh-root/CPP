	.file	"main.cpp"
 # GNU C++14 (MinGW.org GCC-6.3.0-1) version 6.3.0 (mingw32)
 #	compiled by GNU C version 6.3.0, GMP version 6.1.2, MPFR version 3.1.5, MPC version 1.0.2, isl version 0.15
 # warning: MPC header version 1.0.2 differs from library version 1.0.3.
 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -iprefix c:\mingw\bin\../lib/gcc/mingw32/6.3.0/
 # main.cpp -mtune=generic -march=i586 -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations
 # -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
 # -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
 # -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
 # -fchkp-use-static-bounds -fchkp-use-static-const-bounds
 # -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -fexceptions -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
 # -finline-atomics -fira-hoist-pressure -fira-share-save-slots
 # -fira-share-spill-slots -fivopts -fkeep-inline-dllexport
 # -fkeep-static-consts -fleading-underscore -flifetime-dse
 # -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
 # -fplt -fprefetch-loop-arrays -freg-struct-return
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
 # -fset-stack-executable -fshow-column -fsigned-zeros
 # -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
 # -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
 # -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
 # -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
 # -funwind-tables -fverbose-asm -fzero-initialized-in-bss -m32 -m80387
 # -m96bit-long-double -maccumulate-outgoing-args -malign-double
 # -malign-stringops -mavx256-split-unaligned-load
 # -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387
 # -mieee-fp -mlong-double-80 -mms-bitfields -mno-red-zone -mno-sse4
 # -mpush-args -msahf -mstack-arg-probe -mstv -mvzeroupper

	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.def	___main;	.scl	2;	.type	32;	.endef
LC4:
	.ascii "b=%f\12\0"
LC5:
	.ascii "d=%f\12\0"
LC6:
	.ascii "f=%f\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB936:
	.cfi_startproc
	pushl	%ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	 #,
	.cfi_def_cfa_register 5
	andl	$-16, %esp	 #,
	subl	$64, %esp	 #,
	call	___main	 #
	flds	LC0	 #
	fstps	60(%esp)	 # a
	fldl	LC1	 #
	fstpl	48(%esp)	 # c
	flds	60(%esp)	 # a
	flds	LC2	 #
	faddp	%st, %st(1)	 #,
	fstps	44(%esp)	 # b
	fldl	48(%esp)	 # c
	fldl	LC3	 #
	faddp	%st, %st(1)	 #,
	fstpl	32(%esp)	 # d
	flds	60(%esp)	 # a
	flds	LC2	 #
	faddp	%st, %st(1)	 #,
	fstpl	24(%esp)	 # f
	flds	44(%esp)	 # b
	fstpl	4(%esp)	 #
	movl	$LC4, (%esp)	 #,
	call	_printf	 #
	fldl	32(%esp)	 # d
	fstpl	4(%esp)	 #
	movl	$LC5, (%esp)	 #,
	call	_printf	 #
	fldl	24(%esp)	 # f
	fstpl	4(%esp)	 #
	movl	$LC6, (%esp)	 #,
	call	_printf	 #
	movl	$0, %eax	 #, _12
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE936:
	.section .rdata,"dr"
	.align 4
LC0:
	.long	1345844999
	.align 8
LC1:
	.long	-509607936
	.long	1107754720
	.align 4
LC2:
	.long	1101004800
	.align 8
LC3:
	.long	0
	.long	1077149696
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
