#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
typedef  int const ut16 ;
typedef  int /*<<< orphan*/  basm ;
struct TYPE_7__ {int /*<<< orphan*/  reg; } ;
struct TYPE_6__ {int size; int jump; void* type; int /*<<< orphan*/  fail; int /*<<< orphan*/  esil; } ;
typedef  int /*<<< orphan*/  RAnalOpMask ;
typedef  TYPE_1__ RAnalOp ;
typedef  TYPE_2__ RAnal ;

/* Variables and functions */
 void* R_ANAL_OP_TYPE_ADD ; 
 void* R_ANAL_OP_TYPE_CALL ; 
 void* R_ANAL_OP_TYPE_CJMP ; 
 void* R_ANAL_OP_TYPE_ILL ; 
 void* R_ANAL_OP_TYPE_LOAD ; 
 void* R_ANAL_OP_TYPE_MOV ; 
 void* R_ANAL_OP_TYPE_NOP ; 
 void* R_ANAL_OP_TYPE_RET ; 
 void* R_ANAL_OP_TYPE_SHL ; 
 void* R_ANAL_OP_TYPE_SHR ; 
 void* R_ANAL_OP_TYPE_SUB ; 
 void* R_ANAL_OP_TYPE_XCHG ; 
 int /*<<< orphan*/ * i4004_e ; 
 int /*<<< orphan*/ * i4004_f ; 
 int* i4004_ins_len ; 
 int r_reg_set_profile_string (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  r_strbuf_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,size_t const,char*,int,...) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/  strncpy (char*,int /*<<< orphan*/ ,size_t const) ; 

__attribute__((used)) static int set_reg_profile(RAnal *anal) {
	const char *p =
		"=PC	PC\n"
		/* syntax not yet supported */
		// "=SP	&PC1\n"
		"=A0	r0\n"
		"=A1	r1\n"
		"=A2	r2\n"
		"=A3	r3\n"
		"=R0	r0\n"
		"gpr	r0	.4	0	0\n"
		"gpr	r1	.4	1	0\n"
		"gpr	r2	.4	2	0\n"
		"gpr	r3	.4	3	0\n"
		"gpr	r4	.4	4	0\n"
		"gpr	r5	.4	5	0\n"
		"gpr	r6	.4	6	0\n"
		"gpr	r7	.4	7	0\n"
		"gpr	r8	.4	8	0\n"
		"gpr	r9	.4	9	0\n"
		"gpr	r10	.4	10	0\n"
		"gpr	r11	.4	11	0\n"
		"gpr	r12	.4	12	0\n"
		"gpr	r13	.4	13	0\n"
		"gpr	r14	.4	14	0\n"
		"gpr	r15	.4	15	0\n"
		"gpr	PC	.64	32	0\n"
		/* stack */
		"gpr	PC1	.64	34	0\n"
		"gpr	PC2	.64	34	0\n"
		"gpr	PC3	.64	34	0\n"
		;

	return r_reg_set_profile_string (anal->reg, p);
}

__attribute__((used)) static int i4004_get_ins_len (ut8 hex) {
	ut8 high = (hex & 0xf0)>>4;
	int ret = i4004_ins_len[high];
	if (ret == 3) {
		ret = (hex & 1) ? 1 : 2;
	}
	return ret;
}

__attribute__((used)) static int i4004_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf, int len, RAnalOpMask mask) {
	char basm[128];
	const size_t basz = sizeof (basm)-1;
	int rlen = i4004_get_ins_len (*buf);
	if (!op) {
		return 2;
	}
	r_strbuf_init (&op->esil);
	ut8 high = (*buf & 0xf0)>>4;
	ut8 low = (*buf & 0xf);
	basm[0] = 0;

	if (rlen > len) {
		return op->size = 0;
	}
	switch (high) {
	case 0:
		if (low) {
			op->type = R_ANAL_OP_TYPE_ILL;
		} else {
			op->type = R_ANAL_OP_TYPE_NOP;
		}
		break;
	case 1: //snprintf (basm, basz, "jcn %d 0x%02x", low, buf[1]); break;
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->jump = buf[1];
		op->fail = addr + rlen;
		break;
	case 2:
		if (rlen == 1) {
			snprintf (basm, basz, "scr r%d", (low & 0xe));
		} else {
			snprintf (basm, basz, "fim r%d, 0x%02x", (low & 0xe), buf[1]);
		}
		break;
	case 3:
		op->type = R_ANAL_OP_TYPE_MOV;
		snprintf (basm, basz, "fin r%d", (low & 0xe));
		break;
	case 4:
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->jump = (ut16) (low<<8) | buf[1];
		op->fail = addr + rlen;
		break;
	case 5: //snprintf (basm, basz, "jms 0x%03x", ((ut16)(low<<8) | buf[1])); break;
		op->type = R_ANAL_OP_TYPE_CALL;
		op->jump = (ut16) (low<<8) | buf[1];
		op->fail = addr + rlen;
		break;
	case 6: //snprintf (basm, basz, "inc r%d", low); break;
		op->type = R_ANAL_OP_TYPE_ADD;
		break;
	case 7: snprintf (basm, basz, "isz r%d, 0x%02x", low, buf[1]); break;
	case 8:
		op->type = R_ANAL_OP_TYPE_ADD;
		//snprintf (basm, basz, "add r%d", low); break;
		break;
	case 9:
		op->type = R_ANAL_OP_TYPE_SUB;
		//snprintf (basm, basz, "sub r%d", low); break;
		break;
	case 10: //snprintf (basm, basz, "ld r%d", low); break;
		op->type = R_ANAL_OP_TYPE_MOV;
		break;
	case 11: //snprintf (basm, basz, "xch r%d", low); break;
		op->type = R_ANAL_OP_TYPE_XCHG;
		break;
	case 12: //snprintf (basm, basz, "bbl %d", low); break;
		op->type = R_ANAL_OP_TYPE_RET;
		break;
	case 13:
		op->type = R_ANAL_OP_TYPE_LOAD;
		//snprintf (basm, basz, "ldm %d", low); break;
		break;
	case 14:
		strncpy (basm, i4004_e[low], basz);
		basm[basz] = '\0';
		break;
	case 15:
		strncpy (basm, i4004_f[low], basz);
		basm[basz] = '\0';
		if (!strcmp (basm, "dac")) {
			op->type = R_ANAL_OP_TYPE_SUB;
		}
		break;
	}
	if (!strcmp (basm, "invalid")) {
		op->type = R_ANAL_OP_TYPE_ILL;
	} else if (!strcmp (basm, "ral")) {
		op->type = R_ANAL_OP_TYPE_SHL;
	} else if (!strcmp (basm, "rar")) {
		op->type = R_ANAL_OP_TYPE_SHR;
	}
	return op->size = rlen;
}

