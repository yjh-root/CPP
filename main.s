	.file	"main.cpp"
	.intel_syntax noprefix
 # GNU C++14 (MinGW.org GCC-6.3.0-1) version 6.3.0 (mingw32)
 #	compiled by GNU C version 6.3.0, GMP version 6.1.2, MPFR version 3.1.5, MPC version 1.0.2, isl version 0.15
 # warning: MPC header version 1.0.2 differs from library version 1.0.3.
 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -iprefix c:\mingw\bin\../lib/gcc/mingw32/6.3.0/
 # main.cpp -m32 -masm=intel -mtune=generic -march=i586 -fverbose-asm
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
	.text
	.globl	__Z3addii
	.def	__Z3addii;	.scl	2;	.type	32;	.endef
__Z3addii:
LFB936:
	.cfi_startproc
	push	ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp	 #,
	.cfi_def_cfa_register 5
	sub	esp, 16	 #,
	mov	edx, DWORD PTR [ebp+8]	 # tmp93, a
	mov	eax, DWORD PTR [ebp+12]	 # tmp94, b
	add	eax, edx	 # tmp92, tmp93
	mov	DWORD PTR [ebp-4], eax	 # ret, tmp92
	mov	eax, DWORD PTR [ebp-4]	 # _4, ret
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE936:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "add result=%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB937:
	.cfi_startproc
	push	ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp	 #,
	.cfi_def_cfa_register 5
	and	esp, -16	 #,
	sub	esp, 32	 #,
	call	___main	 #
	mov	DWORD PTR [esp+16], 5	 # a,
	lea	eax, [esp+16]	 # tmp91,
	mov	DWORD PTR [esp+28], eax	 # p, tmp91
	mov	eax, DWORD PTR [esp+28]	 # tmp92, p
	mov	eax, DWORD PTR [eax]	 # _4, *p_3
	add	eax, 2	 # tmp93,
	mov	DWORD PTR [esp+24], eax	 # b, tmp93
	mov	eax, DWORD PTR [esp+16]	 # a.0_6, a
	mov	edx, DWORD PTR [esp+24]	 # tmp94, b
	mov	DWORD PTR [esp+4], edx	 #, tmp94
	mov	DWORD PTR [esp], eax	 #, a.0_6
	call	__Z3addii	 #
	mov	DWORD PTR [esp+20], eax	 # ret, tmp95
	mov	eax, DWORD PTR [esp+20]	 # tmp96, ret
	mov	DWORD PTR [esp+4], eax	 #, tmp96
	mov	DWORD PTR [esp], OFFSET FLAT:LC0	 #,
	call	_printf	 #
	mov	eax, 0	 # _10,
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE937:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
