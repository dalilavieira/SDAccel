#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
struct TYPE_19__ {char* syntax; } ;
struct TYPE_18__ {int size; int /*<<< orphan*/  type; scalar_t__ delay; } ;
struct TYPE_17__ {scalar_t__ cpu; } ;
typedef  int (* TMS_ANAL_OP_FN ) (TYPE_1__*,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int) ;
typedef  int /*<<< orphan*/  RAnalOpMask ;
typedef  TYPE_2__ RAnalOp ;
typedef  TYPE_1__ RAnal ;

/* Variables and functions */
 int /*<<< orphan*/  R_ANAL_OP_TYPE_ACMP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_CALL ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_CCALL ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_CJMP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_CMP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_CRET ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_JMP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_MOV ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_NOP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_NULL ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_POP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_PUSH ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_RET ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_SWI ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_TRAP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_UCALL ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_UJMP ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_UNK ; 
 int /*<<< orphan*/  R_ANAL_OP_TYPE_UPUSH ; 
 TYPE_7__ engine ; 
 scalar_t__ r_str_casecmp (scalar_t__,char*) ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 int /*<<< orphan*/  strncasecmp (char const*,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ strstr (char const*,char*) ; 
 int tms320_c55x_plus_op (TYPE_1__*,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int) ; 
 int tms320_dasm (TYPE_7__*,int /*<<< orphan*/  const*,int) ; 
 int tms320_dasm_fini (TYPE_7__*) ; 
 int tms320_dasm_init (TYPE_7__*) ; 

__attribute__((used)) static bool match(const char * str, const char * token) {
	return !strncasecmp(str, token, strlen(token));
}

int tms320_c54x_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf, int len) {
	// TODO: add the implementation
	return 0;
}

int tms320_c55x_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf, int len) {
	const char * str = engine.syntax;

	op->delay = 0;
	op->size = tms320_dasm(&engine, buf, len);
	op->type = R_ANAL_OP_TYPE_NULL;

	str = strstr(str, "||") ? str + 3 : str;

	if (match(str, "B ")) {
		op->type = R_ANAL_OP_TYPE_JMP;
		if (match (str, "B AC")) {
			op->type = R_ANAL_OP_TYPE_UJMP;
		}
	} else if (match(str, "BCC ") || match(str, "BCCU ")) {
		op->type = R_ANAL_OP_TYPE_CJMP;
	} else if (match(str, "CALL ")) {
		op->type = R_ANAL_OP_TYPE_CALL;
		if (match (str, "CALL AC")) {
			op->type = R_ANAL_OP_TYPE_UCALL;
		}
	} else if (match(str, "CALLCC ")) {
		op->type = R_ANAL_OP_TYPE_CCALL;
	} else if (match(str, "RET")) {
		op->type = R_ANAL_OP_TYPE_RET;
		if (match (str, "RETCC")) {
			op->type = R_ANAL_OP_TYPE_CRET;
		}
	} else if (match(str, "MOV ")) {
		op->type = R_ANAL_OP_TYPE_MOV;
	} else if (match(str, "PSHBOTH ")) {
		op->type = R_ANAL_OP_TYPE_UPUSH;
	} else if (match(str, "PSH ")) {
		op->type = R_ANAL_OP_TYPE_PUSH;
	} else if (match(str, "POPBOTH ") || match(str, "POP ")) {
		op->type = R_ANAL_OP_TYPE_POP;
	} else if (match(str, "CMP ")) {
		op->type = R_ANAL_OP_TYPE_CMP;
	} else if (match(str, "CMPAND ")) {
		op->type = R_ANAL_OP_TYPE_ACMP;
	} else if (match(str, "NOP")) {
		op->type = R_ANAL_OP_TYPE_NOP;
	} else if (match(str, "INTR ")) {
		op->type = R_ANAL_OP_TYPE_SWI;
	} else if (match(str, "TRAP ")) {
		op->type = R_ANAL_OP_TYPE_TRAP;
	} else if (match(str, "INVALID")) {
		op->type = R_ANAL_OP_TYPE_UNK;
	}

	return op->size;
}

int tms320_op(RAnal * anal, RAnalOp * op, ut64 addr, const ut8 * buf, int len, RAnalOpMask mask) {
	TMS_ANAL_OP_FN aop = tms320_c55x_op;

	if (anal->cpu && r_str_casecmp(anal->cpu, "c64x") == 0) {
#ifdef CAPSTONE_TMS320C64X_H
		return tms320c64x_analop (anal, op, addr, buf, len, mask);
#else
		return -1;
#endif
	}
	if (anal->cpu && r_str_casecmp(anal->cpu, "c54x") == 0) {
		aop = tms320_c54x_op;
	} else if (anal->cpu && r_str_casecmp(anal->cpu, "c55x") == 0) {
		aop = tms320_c55x_op;
	} else if (anal->cpu && r_str_casecmp(anal->cpu, "c55x+") == 0) {
		aop = tms320_c55x_plus_op;
	}
	return aop (anal, op, addr, buf, len);
}

__attribute__((used)) static int tms320_init(void * unused) {
	return tms320_dasm_init (&engine);
}

__attribute__((used)) static int tms320_fini(void * unused) {
	return tms320_dasm_fini (&engine);
}

