#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut64 ;
typedef  int ut32 ;
typedef  int ut16 ;
struct winedbg_arm_insn {int jmp; int fail; } ;
typedef  int st32 ;
struct TYPE_17__ {int bits; int /*<<< orphan*/  reg; scalar_t__ big_endian; } ;
struct TYPE_16__ {int jump; int fail; int ptr; int val; int size; int addr; int cond; int refptr; void* type; void* stackop; scalar_t__ delay; } ;
typedef  int /*<<< orphan*/  RAnalOpMask ;
typedef  TYPE_1__ RAnalOp ;
typedef  TYPE_2__ RAnal ;

/* Variables and functions */
 int ARM_DTX_LOAD ; 
 int B0010 ; 
 int B0011 ; 
 int B0100 ; 
 int B0101 ; 
 int B0111 ; 
 int B1000 ; 
 int B1011 ; 
 int B1100 ; 
 int B1101 ; 
 int B1110 ; 
 int B1111 ; 
 int B4 (int,int,int,int) ; 
 scalar_t__ IS_BRANCH (int) ; 
 scalar_t__ IS_BRANCHL (int) ; 
 scalar_t__ IS_CONDAL (int) ; 
 scalar_t__ IS_EXITPOINT (int) ; 
 scalar_t__ IS_LOAD (int) ; 
 int R_ANAL_ARCHINFO_ALIGN ; 
 int R_ANAL_ARCHINFO_MAX_OP_SIZE ; 
 int R_ANAL_ARCHINFO_MIN_OP_SIZE ; 
 void* R_ANAL_OP_TYPE_ADD ; 
 void* R_ANAL_OP_TYPE_CALL ; 
 void* R_ANAL_OP_TYPE_CJMP ; 
 void* R_ANAL_OP_TYPE_CMP ; 
 void* R_ANAL_OP_TYPE_JMP ; 
 void* R_ANAL_OP_TYPE_LOAD ; 
 void* R_ANAL_OP_TYPE_MOV ; 
 void* R_ANAL_OP_TYPE_NOP ; 
 void* R_ANAL_OP_TYPE_NULL ; 
 void* R_ANAL_OP_TYPE_RET ; 
 void* R_ANAL_OP_TYPE_STORE ; 
 void* R_ANAL_OP_TYPE_SUB ; 
 void* R_ANAL_OP_TYPE_SWI ; 
 void* R_ANAL_OP_TYPE_TRAP ; 
 void* R_ANAL_OP_TYPE_UCALL ; 
 void* R_ANAL_OP_TYPE_UJMP ; 
 void* R_ANAL_OP_TYPE_UNK ; 
 void* R_ANAL_STACK_GET ; 
 void* R_ANAL_STACK_INC ; 
 int UT64_MAX ; 
 int arm_disasm_one_insn (struct winedbg_arm_insn*) ; 
 int /*<<< orphan*/  arm_free (struct winedbg_arm_insn*) ; 
 struct winedbg_arm_insn* arm_new () ; 
 int /*<<< orphan*/  arm_set_input_buffer (struct winedbg_arm_insn*,int const*) ; 
 int /*<<< orphan*/  arm_set_pc (struct winedbg_arm_insn*,int) ; 
 int /*<<< orphan*/  arm_set_thumb (struct winedbg_arm_insn*,int) ; 
 int hackyArmAnal (TYPE_2__*,TYPE_1__*,int const*,int) ; 
 int* iconds ; 
 int /*<<< orphan*/  memset (TYPE_1__*,char,int) ; 
 int r_reg_set_profile_string (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static unsigned int disarm_branch_offset(unsigned int pc, unsigned int insoff) {
	unsigned int add = insoff << 2;
	/* zero extend if higher is 1 (0x02000000) */
	if ((add & 0x02000000) == 0x02000000) {
		add |= 0xFC000000;
	}
	return add + pc + 8;
}

__attribute__((used)) static int op_thumb(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *data, int len) {
	int op_code;
	ut16 *_ins = (ut16 *) data;
	ut16 ins = *_ins;
	ut32 *_ins32 = (ut32 *) data;
	ut32 ins32 = *_ins32;

	struct winedbg_arm_insn *arminsn = arm_new ();
	arm_set_thumb (arminsn, true);
	arm_set_input_buffer (arminsn, data);
	arm_set_pc (arminsn, addr);
	op->jump = op->fail = -1;
	op->ptr = op->val = -1;
	op->delay = 0;
	op->size = arm_disasm_one_insn (arminsn);
	op->jump = arminsn->jmp;
	op->fail = arminsn->fail;
	arm_free (arminsn);

	// TODO: handle 32bit instructions (branches are not correctly decoded //

	/* CMP */
	if (((ins & B4 (B1110, 0, 0, 0)) == B4 (B0010, 0, 0, 0))
	    && (1 == (ins & B4 (1, B1000, 0, 0)) >> 11)) { // dp3
		op->type = R_ANAL_OP_TYPE_CMP;
		return op->size;
	}
	if ((ins & B4 (B1111, B1100, 0, 0)) == B4 (B0100, 0, 0, 0)) {
		op_code = (ins & B4 (0, B0011, B1100, 0)) >> 6;
		if (op_code == 8 || op_code == 10) {  // dp5
			op->type = R_ANAL_OP_TYPE_CMP;
			return op->size;
		}
	}
	if ((ins & B4 (B1111, B1100, 0, 0)) == B4 (B0100, B0100, 0, 0)) {
		op_code = (ins & B4 (0, B0011, 0, 0)) >> 8;  // dp8
		if (op_code == 1) {
			op->type = R_ANAL_OP_TYPE_CMP;
			return op->size;
		}
	}
	if (ins == 0xbf) {
		// TODO: add support for more NOP instructions
		op->type = R_ANAL_OP_TYPE_NOP;
	} else if (((op_code = ((ins & B4 (B1111, B1000, 0, 0)) >> 11)) >= 12 &&
	            op_code <= 17)) {
		if (op_code % 2) {
			op->type = R_ANAL_OP_TYPE_LOAD;
		} else {
			op->type = R_ANAL_OP_TYPE_STORE;
		}
	} else if ((ins & B4 (B1111, 0, 0, 0)) == B4 (B0101, 0, 0, 0)) {
		op_code = (ins & B4 (0, B1110, 0, 0)) >> 9;
		if (op_code % 2) {
			op->type = R_ANAL_OP_TYPE_LOAD;
		} else {
			op->type = R_ANAL_OP_TYPE_STORE;
		}
	} else if ((ins & B4 (B1111, 0, 0, 0)) == B4 (B1101, 0, 0, 0)) {
		// BNE..
		int delta = (ins & B4 (0, 0, B1111, B1111));
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->jump = addr + 4 + (delta << 1);
		op->fail = addr + 4;
	} else if ((ins & B4 (B1111, B1000, 0, 0)) == B4 (B1110, 0, 0, 0)) {
		// B
		int delta = (ins & B4 (0, 0, B1111, B1111));
		op->type = R_ANAL_OP_TYPE_JMP;
		op->jump = addr + 4 + (delta << 1);
		op->fail = addr + 4;
	} else if ((ins & B4 (B1111, B1111, B1000, 0)) ==
	           B4 (B0100, B0111, B1000, 0)) {
		// BLX
		op->type = R_ANAL_OP_TYPE_UCALL;
		op->fail = addr + 4;
	} else if ((ins & B4 (B1111, B1111, B1000, 0)) ==
	           B4 (B0100, B0111, 0, 0)) {
		// BX
		op->type = R_ANAL_OP_TYPE_UJMP;
		op->fail = addr + 4;
	} else if ((ins & B4 (B1111, B1000, 0, 0)) == B4 (B1111, 0, 0, 0)) {
		// BL The long branch with link, it's in 2 instructions:
		// prefix: 11110[offset]
		// suffix: 11111[offset] (11101[offset] for blx)
		ut16 nextins = (ins32 & 0xFFFF0000) >> 16;
		ut32 high = (ins & B4 (0, B0111, B1111, B1111)) << 12;
		if (ins & B4 (0, B0100, 0, 0)) {
			high |= B4 (B1111, B1000, 0, 0) << 16;
		}
		int delta = high + ((nextins & B4 (0, B0111, B1111, B1111)) * 2);
		op->jump = (int) (addr + 4 + (delta));
		op->type = R_ANAL_OP_TYPE_CALL;
		op->fail = addr + 4;
	} else if ((ins & B4 (B1111, B1111, 0, 0)) == B4 (B1011, B1110, 0, 0)) {
		op->type = R_ANAL_OP_TYPE_TRAP;
		op->val = (ut64) (ins >> 8);
	} else if ((ins & B4 (B1111, B1111, 0, 0)) == B4 (B1101, B1111, 0, 0)) {
		op->type = R_ANAL_OP_TYPE_SWI;
		op->val = (ut64) (ins >> 8);
	}
	return op->size;
}

__attribute__((used)) static int op_cond(const ut8 *data) {
	ut8 b = data[3] >> 4;
	if (b == 0xf) {
		return 0;
	}
	return iconds[b];
}

__attribute__((used)) static int arm_op32(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *data, int len) {
	const ut8 *b = (ut8 *) data;
	ut8 ndata[4];
	ut32 branch_dst_addr, i = 0;
	ut32 *code = (ut32 *) data;
	struct winedbg_arm_insn *arminsn;

	if (!data) {
		return 0;
	}
	memset (op, '\0', sizeof (RAnalOp));
	arminsn = arm_new ();
	arm_set_thumb (arminsn, false);
	arm_set_input_buffer (arminsn, data);
	arm_set_pc (arminsn, addr);
	op->jump = op->fail = -1;
	op->ptr = op->val = -1;
	op->addr = addr;
	op->type = R_ANAL_OP_TYPE_UNK;

	if (anal->big_endian) {
		b = data = ndata;
		ndata[0] = data[3];
		ndata[1] = data[2];
		ndata[2] = data[1];
		ndata[3] = data[0];
	}
	if (anal->bits == 16) {
		arm_free (arminsn);
		return op_thumb (anal, op, addr, data, len);
	}
	op->size = 4;
	op->cond = op_cond (data);
	if (b[2] == 0x8f && b[3] == 0xe2) {
		op->type = R_ANAL_OP_TYPE_ADD;
#define ROR(x, y) ((int) ((x) >> (y)) | (((x) << (32 - (y)))))
		op->ptr = addr + ROR (b[0], (b[1] & 0xf) << 1) + 8;
	} else if (b[2] >= 0x9c && b[2] <= 0x9f) {  // load instruction
		char ch = b[3] & 0xf;
		switch (ch) {
		case 5:
			if ((b[3] & 0xf) == 5) {
				op->ptr = 8 + addr + b[0] + ((b[1] & 0xf) << 8);
				// XXX: if set it breaks the visual disasm wtf
				// op->refptr = true;
			}
		case 4:
		case 6:
		case 7:
		case 8:
		case 9: op->type = R_ANAL_OP_TYPE_LOAD; break;
		}
	} else // 0x000037b8  00:0000   0             800000ef  svc 0x00000080
	if (b[2] == 0xa0 && b[3] == 0xe1) {
		int n = (b[0] << 16) + b[1];
		op->type = R_ANAL_OP_TYPE_MOV;
		switch (n) {
		case 0:
		case 0x0110: case 0x0220: case 0x0330: case 0x0440:
		case 0x0550: case 0x0660: case 0x0770: case 0x0880:
		case 0x0990: case 0x0aa0: case 0x0bb0: case 0x0cc0:
			op->type = R_ANAL_OP_TYPE_NOP;
			break;
		}
	} else if (b[3] == 0xef) {
		op->type = R_ANAL_OP_TYPE_SWI;
		op->val = (b[0] | (b[1] << 8) | (b[2] << 2));
	} else if ((b[3] & 0xf) == 5) {  // [reg,0xa4]
#if 0
		0x00000000      a4a09fa4 ldrge sl, [pc], 0xa4
		0x00000000      a4a09fa5 ldrge sl, [pc, 0xa4]
		0x00000000      a4a09fa6 ldrge sl, [pc], r4, lsr 1
		0x00000000      a4a09fa7 ldrge sl, [pc, r4, lsr 1]
		0x00000000      a4a09fe8 ldm pc, {
			r2, r5, r7, sp, pc
		}; < UNPREDICT
#endif
		if ((b[1] & 0xf0) == 0xf0) {
			// ldr pc, [pc, #1] ;
			// op->type = R_ANAL_OP_TYPE_UJMP;
			op->type = R_ANAL_OP_TYPE_RET; // FAKE FOR FUN
			// op->stackop = R_ANAL_STACK_SET;
			op->jump = 1234;
			// op->ptr = 4+addr+b[0]; // sure? :)
			// op->ptrptr = true;
		}
		// eprintf("0x%08x\n", code[i] & ARM_DTX_LOAD);
		// 0x0001B4D8,           1eff2fe1        bx    lr
	} else if (b[3] == 0xe2 && b[2] == 0x8d && b[1] == 0xd0) {
		// ADD SP, SP, ...
		op->type = R_ANAL_OP_TYPE_ADD;
		op->stackop = R_ANAL_STACK_INC;
		op->val = -b[0];
	} else if (b[3] == 0xe2 && b[2] == 0x4d && b[1] == 0xd0) {
		// SUB SP, SP, ..
		op->type = R_ANAL_OP_TYPE_SUB;
		op->stackop = R_ANAL_STACK_INC;
		op->val = b[0];
	} else if (b[3] == 0xe2 && b[2] == 0x4c && b[1] == 0xb0) {
		// SUB SP, FP, ..
		op->type = R_ANAL_OP_TYPE_SUB;
		op->stackop = R_ANAL_STACK_INC;
		op->val = -b[0];
	} else if (b[3] == 0xe2 && b[2] == 0x4b && b[1] == 0xd0) {
		// SUB SP, IP, ..
		op->type = R_ANAL_OP_TYPE_SUB;
		op->stackop = R_ANAL_STACK_INC;
		op->val = -b[0];
	} else if ((code[i] == 0x1eff2fe1) ||
	           (code[i] == 0xe12fff1e)) {  // bx lr
		op->type = R_ANAL_OP_TYPE_RET;
	} else if ((code[i] & ARM_DTX_LOAD)) {  // IS_LOAD(code[i])) {
		ut32 ptr = 0;
		op->type = R_ANAL_OP_TYPE_MOV;
		if (b[2] == 0x1b) {
			/* XXX pretty incomplete */
			op->stackop = R_ANAL_STACK_GET;
			op->ptr = b[0];
			// var_add_access(addr, -b[0], 1, 0); // TODO: set/get (the last 0)
		} else {
			// ut32 oaddr = addr+8+b[0];
			// XXX TODO ret = radare_read_at(oaddr, (ut8*)&ptr, 4);
			if (anal->bits == 32) {
				b = (ut8 *) &ptr;
				op->ptr = b[0] + (b[1] << 8) + (b[2] << 16) + (b[3] << 24);
				// XXX data_xrefs_add(oaddr, op->ptr, 1);
				// TODO change data type to pointer
			} else {
				op->ptr = 0;
			}
		}
	}

	if (IS_LOAD (code[i])) {
		op->type = R_ANAL_OP_TYPE_LOAD;
		op->refptr = 4;
	}
	if (((((code[i] & 0xff) >= 0x10 && (code[i] & 0xff) < 0x20)) &&
	     ((code[i] & 0xffffff00) == 0xe12fff00)) ||
	    IS_EXITPOINT (code[i])) {
		// if (IS_EXITPOINT (code[i])) {
		b = data;
		branch_dst_addr = disarm_branch_offset (
			addr, b[0] | (b[1] << 8) |
			(b[2] << 16));                // code[i]&0x00FFFFFF);
		op->ptr = 0;
		if ((((code[i] & 0xff) >= 0x10 && (code[i] & 0xff) < 0x20)) &&
		    ((code[i] & 0xffffff00) == 0xe12fff00)) {
			op->type = R_ANAL_OP_TYPE_UJMP;
		} else if (IS_BRANCHL (code[i])) {
			if (IS_BRANCH (code[i])) {
				op->type = R_ANAL_OP_TYPE_CALL;
				op->jump = branch_dst_addr;
				op->fail = addr + 4;
			} else {
				op->type = R_ANAL_OP_TYPE_RET;
			}
		} else if (IS_BRANCH (code[i])) {
			if (IS_CONDAL (code[i])) {
				op->type = R_ANAL_OP_TYPE_JMP;
				op->jump = branch_dst_addr;
				op->fail = UT64_MAX;
			} else {
				op->type = R_ANAL_OP_TYPE_CJMP;
				op->jump = branch_dst_addr;
				op->fail = addr + 4;
			}
		} else {
			// unknown jump o return
			// op->type = R_ANAL_OP_TYPE_UJMP;
			// op->type = R_ANAL_OP_TYPE_NOP;
		}
	}
	// op->jump = arminsn->jmp;
	// op->fail = arminsn->fail;
	arm_free (arminsn);
	return op->size;
}

__attribute__((used)) static ut64 getaddr(ut64 addr, const ut8 *d) {
	if (d[2] >> 7) {
		/// st32 n = (d[0] + (d[1] << 8) + (d[2] << 16) + (0xff << 24));
		st32 n = (d[0] + (d[1] << 8) + (d[2] << 16) + ((ut64)(0xff) << 24)); // * 16777216));
		n = -n;
		return addr - (n * 4);
	}
	return addr + (4 * (d[0] + (d[1] << 8) + (d[2] << 16)));
}

__attribute__((used)) static int arm_op64(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *d, int len) {
	memset (op, 0, sizeof (RAnalOp));
	if (d[3] == 0) {
		return -1;      // invalid
	}
	int haa = hackyArmAnal (anal, op, d, len);
	if (haa > 0) {
		return haa;
	}
	op->size = 4;
	op->type = R_ANAL_OP_TYPE_NULL;
	if (d[0] == 0xc0 && d[3] == 0xd6) {
		// defaults to x30 reg. but can be different
		op->type = R_ANAL_OP_TYPE_RET;
	}
	switch (d[3]) {
	case 0x71:
	case 0xeb:
		op->type = R_ANAL_OP_TYPE_CMP;
		break;
	case 0xb8:
	case 0xb9:
	case 0xf8:
	case 0xa9: // ldp/stp
	case 0xf9: // ldr/str
		op->type = R_ANAL_OP_TYPE_LOAD;
		break;
	case 0x91: // mov
	case 0x52: // mov
	case 0x94: // bl A
	case 0x97: // bl A
		op->type = R_ANAL_OP_TYPE_CALL;
		op->jump = getaddr (addr, d);
		op->fail = addr + 4;
		break;
	case 0x54: // beq A
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->jump = addr + (4 * ((d[0] >> 4) | (d[1] << 8) | (d[2] << 16)));
		op->fail = addr + 4;
		break;
	case 0x17: // b A
	case 0x14: // b A
		op->type = R_ANAL_OP_TYPE_JMP;
		op->jump = getaddr (addr, d);
		op->fail = addr + 4;
		break;
	}
	return op->size;
}

__attribute__((used)) static int arm_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *data, int len, RAnalOpMask mask) {
	if (anal->bits == 64) {
		return arm_op64 (anal, op, addr, data, len);
	}
	return arm_op32 (anal, op, addr, data, len);
}

__attribute__((used)) static int set_reg_profile(RAnal *anal) {
	// TODO: support 64bit profile
	const char *p32 =
		"=PC	r15\n"
		"=SP	r13\n"
		"=BP	r14\n" // XXX
		"=A0	r0\n"
		"=A1	r1\n"
		"=A2	r2\n"
		"=A3	r3\n"
		"gpr	lr	.32	56	0\n" // r14
		"gpr	pc	.32	60	0\n" // r15

		"gpr	r0	.32	0	0\n"
		"gpr	r1	.32	4	0\n"
		"gpr	r2	.32	8	0\n"
		"gpr	r3	.32	12	0\n"
		"gpr	r4	.32	16	0\n"
		"gpr	r5	.32	20	0\n"
		"gpr	r6	.32	24	0\n"
		"gpr	r7	.32	28	0\n"
		"gpr	r8	.32	32	0\n"
		"gpr	r9	.32	36	0\n"
		"gpr	r10	.32	40	0\n"
		"gpr	r11	.32	44	0\n"
		"gpr	r12	.32	48	0\n"
		"gpr	r13	.32	52	0\n"
		"gpr	r14	.32	56	0\n"
		"gpr	r15	.32	60	0\n"
		"gpr	r16	.32	64	0\n"
		"gpr	r17	.32	68	0\n"
		"gpr	cpsr	.32	72	0\n";
	return r_reg_set_profile_string (anal->reg, p32);
}

__attribute__((used)) static int archinfo(RAnal *anal, int q) {
	if (q == R_ANAL_ARCHINFO_ALIGN) {
		if (anal && anal->bits == 16) {
			return 2;
		}
		return 4;
	}
	if (q == R_ANAL_ARCHINFO_MAX_OP_SIZE) {
		return 4;
	}
	if (q == R_ANAL_ARCHINFO_MIN_OP_SIZE) {
		if (anal && anal->bits == 16) {
			return 2;
		}
		return 4;
	}
	return 4; // XXX
}

