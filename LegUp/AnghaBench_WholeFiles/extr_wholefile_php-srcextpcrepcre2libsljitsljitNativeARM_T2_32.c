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
struct sljit_compiler {int size; } ;
typedef  int sljit_u16 ;
typedef  int sljit_sw ;
typedef  int /*<<< orphan*/  sljit_s32 ;
typedef  int sljit_ins ;

/* Variables and functions */
 int ADDWI ; 
 int ADD_WI ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int IMM12 (int) ; 
 int INVALID_IMM ; 
 int RD4 (int /*<<< orphan*/ ) ; 
 int RN4 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SLJIT_ASSERT (int) ; 
 int /*<<< orphan*/  SLJIT_ERR_UNSUPPORTED ; 
 int /*<<< orphan*/  SLJIT_SUCCESS ; 
 int SUBWI ; 
 int SUB_WI ; 
 scalar_t__ ensure_buf (struct sljit_compiler*,int) ; 
 int get_imm (int) ; 

__attribute__((used)) static sljit_s32 push_inst16(struct sljit_compiler *compiler, sljit_ins inst)
{
	sljit_u16 *ptr;
	SLJIT_ASSERT(!(inst & 0xffff0000));

	ptr = (sljit_u16*)ensure_buf(compiler, sizeof(sljit_u16));
	FAIL_IF(!ptr);
	*ptr = inst;
	compiler->size++;
	return SLJIT_SUCCESS;
}

__attribute__((used)) static sljit_s32 push_inst32(struct sljit_compiler *compiler, sljit_ins inst)
{
	sljit_u16 *ptr = (sljit_u16*)ensure_buf(compiler, sizeof(sljit_ins));
	FAIL_IF(!ptr);
	*ptr++ = inst >> 16;
	*ptr = inst;
	compiler->size += 2;
	return SLJIT_SUCCESS;
}

__attribute__((used)) static sljit_s32 emit_set_delta(struct sljit_compiler *compiler, sljit_s32 dst, sljit_s32 reg, sljit_sw value)
{
	if (value >= 0) {
		if (value <= 0xfff)
			return push_inst32(compiler, ADDWI | RD4(dst) | RN4(reg) | IMM12(value));
		value = get_imm(value);
		if (value != INVALID_IMM)
			return push_inst32(compiler, ADD_WI | RD4(dst) | RN4(reg) | value);
	}
	else {
		value = -value;
		if (value <= 0xfff)
			return push_inst32(compiler, SUBWI | RD4(dst) | RN4(reg) | IMM12(value));
		value = get_imm(value);
		if (value != INVALID_IMM)
			return push_inst32(compiler, SUB_WI | RD4(dst) | RN4(reg) | value);
	}
	return SLJIT_ERR_UNSUPPORTED;
}

