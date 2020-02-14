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
struct decode_header {int dummy; } ;
struct arch_probes_insn {int stack_space; } ;
typedef  int probes_opcode_t ;
typedef  enum probes_insn { ____Placeholder_probes_insn } probes_insn ;

/* Variables and functions */
 int INSN_GOOD_NO_SLOT ; 
 unsigned long PSR_IT_MASK ; 
 int hweight32 (unsigned int) ; 

__attribute__((used)) static inline unsigned long it_advance(unsigned long cpsr)
	{
	if ((cpsr & 0x06000400) == 0) {
		/* ITSTATE<2:0> == 0 means end of IT block, so clear IT state */
		cpsr &= ~PSR_IT_MASK;
	} else {
		/* We need to shift left ITSTATE<4:0> */
		const unsigned long mask = 0x06001c00;  /* Mask ITSTATE<4:0> */
		unsigned long it = cpsr & mask;
		it <<= 1;
		it |= it >> (27 - 10);  /* Carry ITSTATE<2> to correct place */
		it &= mask;
		cpsr &= ~mask;
		cpsr |= it;
	}
	return cpsr;
}

enum probes_insn checker_stack_use_none(probes_opcode_t insn,
		struct arch_probes_insn *asi,
		const struct decode_header *h)
{
	asi->stack_space = 0;
	return INSN_GOOD_NO_SLOT;
}

enum probes_insn checker_stack_use_unknown(probes_opcode_t insn,
		struct arch_probes_insn *asi,
		const struct decode_header *h)
{
	asi->stack_space = -1;
	return INSN_GOOD_NO_SLOT;
}

enum probes_insn checker_stack_use_imm_x0x(probes_opcode_t insn,
		struct arch_probes_insn *asi,
		const struct decode_header *h)
{
	int imm = ((insn & 0xf00) >> 4) + (insn & 0xf);
	asi->stack_space = imm;
	return INSN_GOOD_NO_SLOT;
}

enum probes_insn checker_stack_use_imm_xxx(probes_opcode_t insn,
		struct arch_probes_insn *asi,
		const struct decode_header *h)
{
	int imm = insn & 0xfff;
	asi->stack_space = imm;
	return INSN_GOOD_NO_SLOT;
}

enum probes_insn checker_stack_use_stmdx(probes_opcode_t insn,
		struct arch_probes_insn *asi,
		const struct decode_header *h)
{
	unsigned int reglist = insn & 0xffff;
	int pbit = insn & (1 << 24);
	asi->stack_space = (hweight32(reglist) - (!pbit ? 1 : 0)) * 4;

	return INSN_GOOD_NO_SLOT;
}

