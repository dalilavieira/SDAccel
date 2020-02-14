#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  scalar_t__ ut64 ;
struct TYPE_15__ {int type; TYPE_1__* args; } ;
typedef  TYPE_2__ mcore_t ;
struct TYPE_16__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_3__ mcore_handle ;
struct TYPE_18__ {int /*<<< orphan*/  reg; } ;
struct TYPE_17__ {int type; int size; int eob; void* jump; void* fail; void* val; void* ptr; scalar_t__ delay; } ;
struct TYPE_14__ {scalar_t__ value; } ;
typedef  int /*<<< orphan*/  RAnalOpMask ;
typedef  TYPE_4__ RAnalOp ;
typedef  TYPE_5__ RAnal ;

/* Variables and functions */
#define  R_ANAL_OP_TYPE_CALL 133 
#define  R_ANAL_OP_TYPE_CJMP 132 
#define  R_ANAL_OP_TYPE_ICALL 131 
#define  R_ANAL_OP_TYPE_ILL 130 
#define  R_ANAL_OP_TYPE_JMP 129 
 int R_ANAL_OP_TYPE_NULL ; 
#define  R_ANAL_OP_TYPE_RET 128 
 void* UT64_MAX ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 int /*<<< orphan*/  mcore_free (TYPE_2__*) ; 
 scalar_t__ mcore_init (TYPE_3__*,int /*<<< orphan*/  const*,int) ; 
 TYPE_2__* mcore_next (TYPE_3__*) ; 
 int r_reg_set_profile_string (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static int mcore_anal(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf, int len, RAnalOpMask mask) {
	mcore_handle handle = {0};
	mcore_t* instr = NULL;

	if (mcore_init (&handle, buf, len)) {
		eprintf ("[!] mcore: bad or invalid data.\n");
		return -1;
	}

	op->delay = 0;
	op->type = R_ANAL_OP_TYPE_NULL;
	op->jump = UT64_MAX;
	op->fail = UT64_MAX;
	op->ptr = op->val = UT64_MAX;
	op->size = 2;
	if ((instr = mcore_next (&handle))) {
		op->type = instr->type;
		switch (instr->type) {
		case R_ANAL_OP_TYPE_CALL:
		case R_ANAL_OP_TYPE_CJMP:
			op->fail = addr + 2;
			op->jump = addr + instr->args[0].value + 1;
			break;
		case R_ANAL_OP_TYPE_JMP:
			op->jump = addr + instr->args[0].value + 1;
			break;
		case R_ANAL_OP_TYPE_ICALL:
			// the loading address depends on the word
			// that this pointer points to.
			// op->jump = addr + ((instr->args[i].value << 2) & 0xfffffffc);
			break;
		case R_ANAL_OP_TYPE_RET:
		case R_ANAL_OP_TYPE_ILL:
			op->eob = true;
			break;
		default:
			break;
		}
		mcore_free (instr);
	}
	return op->size;
}

__attribute__((used)) static int set_reg_profile(RAnal *anal) {
	const char *p;
	p = "=PC	pc\n"
		"=SP	r1\n"
		"=SR	sr\n"
		"=A0	r3\n"
		"=A1	r4\n"
		"=A2	r5\n"
		"=A3	r6\n"
		"=A4	r7\n"
		"=A5	r8\n"
		"=A6	r6\n"
		"gpr	r0	.32 0   0\n"
		"gpr	r1	.32 4   0\n"
		"gpr	r2	.32 8   0\n"
		"gpr	r3	.32 12  0\n"
		"gpr	r4	.32 16  0\n"
		"gpr	r5	.32 20  0\n"
		"gpr	r6	.32 24  0\n"
		"gpr	r7	.32 28  0\n"
		"gpr	r8	.32 32  0\n"
		"gpr	r9	.32 36  0\n"
		"gpr	r10   .32 40  0\n"
		"gpr	r11   .32 44  0\n"
		"gpr	r12   .32 48  0\n"
		"gpr	r13   .32 52  0\n"
		"gpr	r14   .32 56  0\n"
		"gpr	r15   .32 60  0\n"

		"gpr	psr   .32 64  0\n"
		"gpr	vbr   .32 68  0\n"
		"gpr	epsr  .32 72  0\n"
		"gpr	fpsr  .32 76  0\n"
		"gpr	epc   .32 80  0\n"
		"gpr	fpc   .32 84  0\n"
		"gpr	ss0   .32 88  0\n"
		"gpr	ss1   .32 92  0\n"
		"gpr	ss2   .32 96  0\n"
		"gpr	ss3   .32 100 0\n"
		"gpr	ss4   .32 104 0\n"
		"gpr	gcr   .32 108 0\n"
		"gpr	gsr   .32 112 0\n"
		"gpr	cpidr .32 116 0\n"
		"gpr	dcsr  .32 120 0\n"
		"gpr	cwr   .32 124 0\n"
		"gpr	cr16  .32 128 0\n"
		"gpr	cfr   .32 132 0\n"
		"gpr	ccr   .32 136 0\n"
		"gpr	capr  .32 140 0\n"
		"gpr	pacr  .32 144 0\n"
		"gpr	prsr  .32 148 0\n"

		"gpr	cr22  .32 152 0\n"
		"gpr	cr23  .32 156 0\n"
		"gpr	cr24  .32 160 0\n"
		"gpr	cr25  .32 164 0\n"
		"gpr	cr26  .32 168 0\n"
		"gpr	cr27  .32 172 0\n"
		"gpr	cr28  .32 176 0\n"
		"gpr	cr29  .32 180 0\n"
		"gpr	cr30  .32 184 0\n"
		"gpr	cr31  .32 188 0\n"
		"gpr	pc	.32 192 0\n";
	return r_reg_set_profile_string (anal->reg, p);
}

__attribute__((used)) static int archinfo(RAnal *anal, int q) {
	return 2;
}

