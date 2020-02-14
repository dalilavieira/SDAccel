#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct sljit_compiler {int /*<<< orphan*/  size; } ;
typedef  int sljit_sw ;
typedef  size_t sljit_s32 ;
typedef  int sljit_ins ;

/* Variables and functions */
 int A (size_t) ; 
 int ADDIS ; 
 size_t ALT_FORM1 ; 
 size_t ALT_FORM2 ; 
 size_t ALT_FORM3 ; 
 size_t ALT_FORM4 ; 
 size_t ALT_FORM5 ; 
 size_t ALT_SET_FLAGS ; 
 size_t ALT_SIGN_EXT ; 
 int B (size_t) ; 
 int D (size_t) ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 scalar_t__ FAST_IS_REG (size_t) ; 
 int IMM (int) ; 
 size_t INDEXED ; 
 int INST_CODE_AND_DST (int,size_t,size_t) ; 
 size_t LOAD_DATA ; 
 size_t MEM_MASK ; 
 size_t OFFS_REG (size_t) ; 
 size_t OFFS_REG_MASK ; 
 size_t REG1_SOURCE ; 
 size_t REG2_SOURCE ; 
 size_t REG_DEST ; 
 size_t REG_MASK ; 
 int RLDI (size_t,size_t,int,int,int) ; 
 int SIMM_MAX ; 
 int SIMM_MIN ; 
 int /*<<< orphan*/  SLJIT_ASSERT (int) ; 
 size_t SLJIT_IMM ; 
 size_t SLJIT_MEM ; 
 size_t SLJIT_MOV ; 
 size_t SLJIT_MOV_P ; 
 size_t SLJIT_SUCCESS ; 
 scalar_t__ SLJIT_UNLIKELY (size_t) ; 
 scalar_t__ SLOW_IS_REG (size_t) ; 
 size_t TMP_REG1 ; 
 size_t TMP_REG2 ; 
 int* data_transfer_insts ; 
 int emit_single_op (struct sljit_compiler*,size_t,size_t,size_t,size_t,size_t) ; 
 scalar_t__ ensure_buf (struct sljit_compiler*,int) ; 
 int load_immediate (struct sljit_compiler*,size_t,int) ; 

__attribute__((used)) static sljit_s32 push_inst(struct sljit_compiler *compiler, sljit_ins ins)
{
	sljit_ins *ptr = (sljit_ins*)ensure_buf(compiler, sizeof(sljit_ins));
	FAIL_IF(!ptr);
	*ptr = ins;
	compiler->size++;
	return SLJIT_SUCCESS;
}

__attribute__((used)) static sljit_s32 emit_op_mem(struct sljit_compiler *compiler, sljit_s32 inp_flags, sljit_s32 reg,
	sljit_s32 arg, sljit_sw argw, sljit_s32 tmp_reg)
{
	sljit_ins inst;
	sljit_s32 offs_reg;
	sljit_sw high_short;

	/* Should work when (arg & REG_MASK) == 0. */
	SLJIT_ASSERT(A(0) == 0);
	SLJIT_ASSERT(arg & SLJIT_MEM);

	if (SLJIT_UNLIKELY(arg & OFFS_REG_MASK)) {
		argw &= 0x3;
		offs_reg = OFFS_REG(arg);

		if (argw != 0) {
#if (defined SLJIT_CONFIG_PPC_32 && SLJIT_CONFIG_PPC_32)
			FAIL_IF(push_inst(compiler, RLWINM | S(OFFS_REG(arg)) | A(tmp_reg) | (argw << 11) | ((31 - argw) << 1)));
#else
			FAIL_IF(push_inst(compiler, RLDI(tmp_reg, OFFS_REG(arg), argw, 63 - argw, 1)));
#endif
			offs_reg = tmp_reg;
		}

		inst = data_transfer_insts[(inp_flags | INDEXED) & MEM_MASK];

#if (defined SLJIT_CONFIG_PPC_64 && SLJIT_CONFIG_PPC_64)
		SLJIT_ASSERT(!(inst & INT_ALIGNED));
#endif

		return push_inst(compiler, INST_CODE_AND_DST(inst, inp_flags, reg) | A(arg & REG_MASK) | B(offs_reg));
	}

	inst = data_transfer_insts[inp_flags & MEM_MASK];
	arg &= REG_MASK;

#if (defined SLJIT_CONFIG_PPC_64 && SLJIT_CONFIG_PPC_64)
	if ((inst & INT_ALIGNED) && (argw & 0x3) != 0) {
		FAIL_IF(load_immediate(compiler, tmp_reg, argw));

		inst = data_transfer_insts[(inp_flags | INDEXED) & MEM_MASK];
		return push_inst(compiler, INST_CODE_AND_DST(inst, inp_flags, reg) | A(arg) | B(tmp_reg));
	}
#endif

	if (argw <= SIMM_MAX && argw >= SIMM_MIN)
		return push_inst(compiler, INST_CODE_AND_DST(inst, inp_flags, reg) | A(arg) | IMM(argw));

#if (defined SLJIT_CONFIG_PPC_64 && SLJIT_CONFIG_PPC_64)
	if (argw <= 0x7fff7fffl && argw >= -0x80000000l) {
#endif

		high_short = (sljit_s32)(argw + ((argw & 0x8000) << 1)) & ~0xffff;

#if (defined SLJIT_CONFIG_PPC_64 && SLJIT_CONFIG_PPC_64)
		SLJIT_ASSERT(high_short && high_short <= 0x7fffffffl && high_short >= -0x80000000l);
#else
		SLJIT_ASSERT(high_short);
#endif

		FAIL_IF(push_inst(compiler, ADDIS | D(tmp_reg) | A(arg) | IMM(high_short >> 16)));
		return push_inst(compiler, INST_CODE_AND_DST(inst, inp_flags, reg) | A(tmp_reg) | IMM(argw));

#if (defined SLJIT_CONFIG_PPC_64 && SLJIT_CONFIG_PPC_64)
	}

	/* The rest is PPC-64 only. */

	FAIL_IF(load_immediate(compiler, tmp_reg, argw));

	inst = data_transfer_insts[(inp_flags | INDEXED) & MEM_MASK];
	return push_inst(compiler, INST_CODE_AND_DST(inst, inp_flags, reg) | A(arg) | B(tmp_reg));
#endif
}

__attribute__((used)) static sljit_s32 emit_op(struct sljit_compiler *compiler, sljit_s32 op, sljit_s32 input_flags,
	sljit_s32 dst, sljit_sw dstw,
	sljit_s32 src1, sljit_sw src1w,
	sljit_s32 src2, sljit_sw src2w)
{
	/* arg1 goes to TMP_REG1 or src reg
	   arg2 goes to TMP_REG2, imm or src reg
	   result goes to TMP_REG2, so put result can use TMP_REG1. */
	sljit_s32 dst_r = TMP_REG2;
	sljit_s32 src1_r;
	sljit_s32 src2_r;
	sljit_s32 sugg_src2_r = TMP_REG2;
	sljit_s32 flags = input_flags & (ALT_FORM1 | ALT_FORM2 | ALT_FORM3 | ALT_FORM4 | ALT_FORM5 | ALT_SIGN_EXT | ALT_SET_FLAGS);

	/* Destination check. */
	if (SLOW_IS_REG(dst)) {
		dst_r = dst;
		flags |= REG_DEST;

		if (op >= SLJIT_MOV && op <= SLJIT_MOV_P)
			sugg_src2_r = dst_r;
	}

	/* Source 1. */
	if (FAST_IS_REG(src1)) {
		src1_r = src1;
		flags |= REG1_SOURCE;
	}
	else if (src1 & SLJIT_IMM) {
		FAIL_IF(load_immediate(compiler, TMP_REG1, src1w));
		src1_r = TMP_REG1;
	}
	else {
		FAIL_IF(emit_op_mem(compiler, input_flags | LOAD_DATA, TMP_REG1, src1, src1w, TMP_REG1));
		src1_r = TMP_REG1;
	}

	/* Source 2. */
	if (FAST_IS_REG(src2)) {
		src2_r = src2;
		flags |= REG2_SOURCE;

		if (!(flags & REG_DEST) && op >= SLJIT_MOV && op <= SLJIT_MOV_P)
			dst_r = src2_r;
	}
	else if (src2 & SLJIT_IMM) {
		FAIL_IF(load_immediate(compiler, sugg_src2_r, src2w));
		src2_r = sugg_src2_r;
	}
	else {
		FAIL_IF(emit_op_mem(compiler, input_flags | LOAD_DATA, sugg_src2_r, src2, src2w, TMP_REG2));
		src2_r = sugg_src2_r;
	}

	FAIL_IF(emit_single_op(compiler, op, flags, dst_r, src1_r, src2_r));

	if (!(dst & SLJIT_MEM))
		return SLJIT_SUCCESS;

	return emit_op_mem(compiler, input_flags, dst_r, dst, dstw, TMP_REG1);
}

