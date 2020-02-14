#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int ut64 ;
typedef  int ut32 ;
typedef  int st32 ;
struct TYPE_12__ {int type; int u_shift; int u_mask; int u_lshift; int s_shift; int s_mask; int s_smask; int s_lshift; } ;
typedef  TYPE_1__ rsp_operand_decoder ;
struct TYPE_13__ {int type; int u; int s; } ;
typedef  TYPE_2__ rsp_operand ;
struct TYPE_14__ {int offset; int shift; int mask; } ;
typedef  TYPE_3__ rsp_op_escape ;
struct TYPE_15__ {int noperands; TYPE_1__* odecs; int /*<<< orphan*/  opcode; int /*<<< orphan*/  mnemonic; } ;
typedef  TYPE_4__ rsp_instruction_priv ;
struct TYPE_16__ {int noperands; TYPE_2__* operands; int /*<<< orphan*/  opcode; int /*<<< orphan*/  mnemonic; } ;
typedef  TYPE_5__ rsp_instruction ;

/* Variables and functions */
 int RSP_IMEM_OFFSET ; 
#define  RSP_OPND_OFFSET 129 
#define  RSP_OPND_TARGET 128 
 TYPE_3__* rsp_escapes_table ; 
 TYPE_4__ const* rsp_op_table ; 

__attribute__((used)) static inline ut64 rsp_mem_addr(ut64 addr, ut64 base) { addr &= 0xfff; addr |= base; return addr; }

__attribute__((used)) static const rsp_instruction_priv* rsp_decode_priv(ut32 iw) {
	const rsp_op_escape* escape;

	/* handle NOP pseudo instruction */
	if (iw == 0) {
		return &rsp_op_table[352];
	}

	escape = &rsp_escapes_table[(iw >> 25)];
	return &rsp_op_table[escape->offset + ((iw >> escape->shift) & escape->mask)];
}

__attribute__((used)) static inline st32 rsp_sign_extend(st32 x, st32 m)
{
	/* assume that bits of x above the m are already zeros
	* which is the case when called from rsp_operand_decode
	*/
	return (x ^ m) - m;
}

__attribute__((used)) static rsp_operand rsp_operand_decode(ut64 pc, ut32 iw, const rsp_operand_decoder* odec) {
	rsp_operand opnd;

	opnd.type = odec->type;
	opnd.u = ((iw >> odec->u_shift) & odec->u_mask) << odec->u_lshift;
	opnd.s = rsp_sign_extend ((iw >> odec->s_shift) & odec->s_mask, odec->s_smask) << odec->s_lshift;

	/* handle targets/offsets IMEM addresses */
	switch (opnd.type) {
	case RSP_OPND_TARGET:
		opnd.u = rsp_mem_addr (opnd.u, RSP_IMEM_OFFSET);
		break;
	case RSP_OPND_OFFSET:
		/* +4 for delay slot */
		opnd.u = rsp_mem_addr (pc + 4 + opnd.s, RSP_IMEM_OFFSET);
		break;
	default: /* do nothing */ break;
	}

	return opnd;
}

rsp_instruction rsp_instruction_decode(ut64 pc, ut32 iw) {
	int opnd;
	const rsp_instruction_priv* priv = rsp_decode_priv (iw);

	rsp_instruction r_instr;

	r_instr.mnemonic = priv->mnemonic;
	r_instr.opcode = priv->opcode;
	r_instr.noperands = priv->noperands;
	for (opnd = 0; opnd < r_instr.noperands; ++opnd) {
		r_instr.operands[opnd] = rsp_operand_decode (pc, iw, &priv->odecs[opnd]);
	}

	return r_instr;
}

