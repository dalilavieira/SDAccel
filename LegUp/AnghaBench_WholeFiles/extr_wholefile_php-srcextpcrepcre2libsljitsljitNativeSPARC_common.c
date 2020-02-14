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
struct sljit_compiler {int delay_slot; int cache_arg; int cache_argw; int /*<<< orphan*/  size; } ;
typedef  int sljit_sw ;
typedef  int sljit_s32 ;
typedef  int sljit_ins ;

/* Variables and functions */
 int ADD ; 
 int ARG_TEST ; 
 int D (int) ; 
 int DR (int) ; 
 int DST_INS_MASK ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int FD (int) ; 
 int GPR_REG ; 
 int IMM (int) ; 
 int IMM_ARG ; 
 int LOAD_DATA ; 
 int MEM_MASK ; 
 int MOVABLE_INS ; 
 int OFFS_REG (int) ; 
 int OFFS_REG_MASK ; 
 int REG_MASK ; 
 int S1 (int) ; 
 int S2 (int) ; 
 int SIMM_MAX ; 
 int SIMM_MIN ; 
 int /*<<< orphan*/  SLJIT_ASSERT (int) ; 
 int SLJIT_MEM ; 
 int SLJIT_SUCCESS ; 
 scalar_t__ SLJIT_UNLIKELY (int) ; 
 int SLL_W ; 
 int TMP_REG1 ; 
 int TMP_REG3 ; 
 int UNMOVABLE_INS ; 
 int* data_transfer_insts ; 
 scalar_t__ ensure_buf (struct sljit_compiler*,int) ; 
 int load_immediate (struct sljit_compiler*,int,int) ; 

__attribute__((used)) static sljit_s32 push_inst(struct sljit_compiler *compiler, sljit_ins ins, sljit_s32 delay_slot)
{
	sljit_ins *ptr;
	SLJIT_ASSERT((delay_slot & DST_INS_MASK) == UNMOVABLE_INS
		|| (delay_slot & DST_INS_MASK) == MOVABLE_INS
		|| (delay_slot & DST_INS_MASK) == ((ins >> 25) & 0x1f));
	ptr = (sljit_ins*)ensure_buf(compiler, sizeof(sljit_ins));
	FAIL_IF(!ptr);
	*ptr = ins;
	compiler->size++;
	compiler->delay_slot = delay_slot;
	return SLJIT_SUCCESS;
}

__attribute__((used)) static sljit_s32 getput_arg_fast(struct sljit_compiler *compiler, sljit_s32 flags, sljit_s32 reg, sljit_s32 arg, sljit_sw argw)
{
	SLJIT_ASSERT(arg & SLJIT_MEM);

	if ((!(arg & OFFS_REG_MASK) && argw <= SIMM_MAX && argw >= SIMM_MIN)
			|| ((arg & OFFS_REG_MASK) && (argw & 0x3) == 0)) {
		/* Works for both absoulte and relative addresses (immediate case). */
		if (SLJIT_UNLIKELY(flags & ARG_TEST))
			return 1;
		FAIL_IF(push_inst(compiler, data_transfer_insts[flags & MEM_MASK]
			| ((flags & MEM_MASK) <= GPR_REG ? D(reg) : FD(reg))
			| S1(arg & REG_MASK) | ((arg & OFFS_REG_MASK) ? S2(OFFS_REG(arg)) : IMM(argw)),
			((flags & MEM_MASK) <= GPR_REG && (flags & LOAD_DATA)) ? DR(reg) : MOVABLE_INS));
		return -1;
	}
	return 0;
}

__attribute__((used)) static sljit_s32 can_cache(sljit_s32 arg, sljit_sw argw, sljit_s32 next_arg, sljit_sw next_argw)
{
	SLJIT_ASSERT((arg & SLJIT_MEM) && (next_arg & SLJIT_MEM));

	/* Simple operation except for updates. */
	if (arg & OFFS_REG_MASK) {
		argw &= 0x3;
		SLJIT_ASSERT(argw);
		next_argw &= 0x3;
		if ((arg & OFFS_REG_MASK) == (next_arg & OFFS_REG_MASK) && argw == next_argw)
			return 1;
		return 0;
	}

	if (((next_argw - argw) <= SIMM_MAX && (next_argw - argw) >= SIMM_MIN))
		return 1;
	return 0;
}

__attribute__((used)) static sljit_s32 getput_arg(struct sljit_compiler *compiler, sljit_s32 flags, sljit_s32 reg, sljit_s32 arg, sljit_sw argw, sljit_s32 next_arg, sljit_sw next_argw)
{
	sljit_s32 base, arg2, delay_slot;
	sljit_ins dest;

	SLJIT_ASSERT(arg & SLJIT_MEM);
	if (!(next_arg & SLJIT_MEM)) {
		next_arg = 0;
		next_argw = 0;
	}

	base = arg & REG_MASK;
	if (SLJIT_UNLIKELY(arg & OFFS_REG_MASK)) {
		argw &= 0x3;

		/* Using the cache. */
		if (((SLJIT_MEM | (arg & OFFS_REG_MASK)) == compiler->cache_arg) && (argw == compiler->cache_argw))
			arg2 = TMP_REG3;
		else {
			if ((arg & OFFS_REG_MASK) == (next_arg & OFFS_REG_MASK) && argw == (next_argw & 0x3)) {
				compiler->cache_arg = SLJIT_MEM | (arg & OFFS_REG_MASK);
				compiler->cache_argw = argw;
				arg2 = TMP_REG3;
			}
			else if ((flags & LOAD_DATA) && ((flags & MEM_MASK) <= GPR_REG) && reg != base && reg != OFFS_REG(arg))
				arg2 = reg;
			else /* It must be a mov operation, so tmp1 must be free to use. */
				arg2 = TMP_REG1;
			FAIL_IF(push_inst(compiler, SLL_W | D(arg2) | S1(OFFS_REG(arg)) | IMM_ARG | argw, DR(arg2)));
		}
	}
	else {
		/* Using the cache. */
		if ((compiler->cache_arg == SLJIT_MEM) && (argw - compiler->cache_argw) <= SIMM_MAX && (argw - compiler->cache_argw) >= SIMM_MIN) {
			if (argw != compiler->cache_argw) {
				FAIL_IF(push_inst(compiler, ADD | D(TMP_REG3) | S1(TMP_REG3) | IMM(argw - compiler->cache_argw), DR(TMP_REG3)));
				compiler->cache_argw = argw;
			}
			arg2 = TMP_REG3;
		} else {
			if ((next_argw - argw) <= SIMM_MAX && (next_argw - argw) >= SIMM_MIN) {
				compiler->cache_arg = SLJIT_MEM;
				compiler->cache_argw = argw;
				arg2 = TMP_REG3;
			}
			else if ((flags & LOAD_DATA) && ((flags & MEM_MASK) <= GPR_REG) && reg != base)
				arg2 = reg;
			else /* It must be a mov operation, so tmp1 must be free to use. */
				arg2 = TMP_REG1;
			FAIL_IF(load_immediate(compiler, arg2, argw));
		}
	}

	dest = ((flags & MEM_MASK) <= GPR_REG ? D(reg) : FD(reg));
	delay_slot = ((flags & MEM_MASK) <= GPR_REG && (flags & LOAD_DATA)) ? DR(reg) : MOVABLE_INS;
	if (!base)
		return push_inst(compiler, data_transfer_insts[flags & MEM_MASK] | dest | S1(arg2) | IMM(0), delay_slot);
	return push_inst(compiler, data_transfer_insts[flags & MEM_MASK] | dest | S1(base) | S2(arg2), delay_slot);
}

