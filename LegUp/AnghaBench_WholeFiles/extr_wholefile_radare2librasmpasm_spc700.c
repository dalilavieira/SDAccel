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
typedef  size_t ut8 ;
struct TYPE_7__ {int type; char* name; } ;
struct TYPE_6__ {int size; } ;
typedef  TYPE_1__ RAsmOp ;
typedef  int /*<<< orphan*/  RAsm ;

/* Variables and functions */
#define  SPC_ARG16 131 
#define  SPC_ARG8_1 130 
#define  SPC_ARG8_2 129 
#define  SPC_OP 128 
 int /*<<< orphan*/  r_asm_op_set_asm (TYPE_1__*,char const*) ; 
 char* sdb_fmt (char*,size_t const,...) ; 
 TYPE_2__* spc_op_table ; 

__attribute__((used)) static int spc700OpLength(int spcoptype){
	switch(spcoptype) {
	case SPC_OP:
		return 1;
	case SPC_ARG8_1:
		return 2;
	case SPC_ARG8_2:
	case SPC_ARG16:
		return 3;
	}
	return 0;
}

__attribute__((used)) static int spc700Disass(RAsmOp *op, const ut8 *buf, int len) {
	int foo = spc700OpLength (spc_op_table[buf[0]].type);
	if (len < foo) {
		return 0;
	}
	const char *buf_asm = "invalid";
	switch (spc_op_table[buf[0]].type) {
	case SPC_OP:
		buf_asm = spc_op_table[buf[0]].name;
		break;
	case SPC_ARG8_1:
		buf_asm = sdb_fmt (spc_op_table[buf[0]].name, buf[1]);
		break;
	case SPC_ARG8_2:
		buf_asm = sdb_fmt (spc_op_table[buf[0]].name, buf[1], buf[2]);
		break;
	case SPC_ARG16:
		buf_asm = sdb_fmt (spc_op_table[buf[0]].name, buf[1]+0x100*buf[2]);
		break;
	}
	r_asm_op_set_asm (op, buf_asm);
	return foo;
}

__attribute__((used)) static int disassemble(RAsm *a, RAsmOp *r_op, const ut8 *buf, int len) {
	int dlen = spc700Disass(r_op, buf, len);
	if (dlen < 0) {
		dlen = 0;
	}
	r_op->size = dlen;
	return dlen;
}

