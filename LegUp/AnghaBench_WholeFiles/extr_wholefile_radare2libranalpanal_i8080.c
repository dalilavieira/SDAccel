#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
struct arg_t {int type; char** fmt; int const shift; int const mask; } ;
struct opcode_t {int size; int const cmd; struct arg_t arg2; struct arg_t arg1; int /*<<< orphan*/  name; } ;
struct TYPE_4__ {int jump; int size; void* type; int /*<<< orphan*/  fail; int /*<<< orphan*/  addr; } ;
typedef  int /*<<< orphan*/  RAnalOpMask ;
typedef  TYPE_1__ RAnalOp ;
typedef  int /*<<< orphan*/  RAnal ;

/* Variables and functions */
 void* R_ANAL_OP_TYPE_ADD ; 
 void* R_ANAL_OP_TYPE_CALL ; 
 void* R_ANAL_OP_TYPE_CRET ; 
 void* R_ANAL_OP_TYPE_JMP ; 
 void* R_ANAL_OP_TYPE_NOP ; 
 void* R_ANAL_OP_TYPE_POP ; 
 void* R_ANAL_OP_TYPE_PUSH ; 
 void* R_ANAL_OP_TYPE_RET ; 
 void* R_ANAL_OP_TYPE_SUB ; 
 void* R_ANAL_OP_TYPE_TRAP ; 
 void* R_ANAL_OP_TYPE_UNK ; 
 int /*<<< orphan*/  memset (TYPE_1__*,char,int) ; 
 struct opcode_t* opcodes ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int const) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,int /*<<< orphan*/ ) ; 
 int strlen (char*) ; 

__attribute__((used)) static void arg(char* s, int const cmd, struct arg_t const* arg, int val) {
  if (arg->type == 3) {
    strcat(s, arg->fmt[(cmd >> arg->shift) & arg->mask]);
  } else {
    if (arg->type == 1)
      sprintf(s, "%02X", val & 0xff);
    else if (arg->type == 2)
      sprintf(s, "%04X", val);
  }
}

__attribute__((used)) static int i8080_disasm(unsigned char const* const code, char* text, int text_sz) {
  int const cmd = code[0];
  int const p = code[1] | (code[2] << 8);

  struct opcode_t const *op;
  for (op = &opcodes[0]; op->size; ++op) {
    int const grp = cmd &
      ~((op->arg1.mask << op->arg1.shift) | 
       (op->arg2.mask << op->arg2.shift));
    int const branch = (grp == 0xc0 || grp == 0xc2 || grp == 0xc4);
    if (grp == op->cmd) {
      strcpy(text, op->name);
      if (!branch) strcat(text, " ");
      arg(text + strlen(text), cmd, &op->arg1, p);
      if (op->arg2.type != 0) strcat(text, (branch ? " " : ", "));
      arg(text + strlen(text), cmd, &op->arg2, p);
      return op->size;
    }
  }
  snprintf(text, text_sz, "db 0x%02x", cmd);
  return 1;
}

__attribute__((used)) static int i8080_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *data, int len, RAnalOpMask mask) {
	char out[32];
	int ilen = i8080_disasm (data, out, len);
	memset (op, '\0', sizeof (RAnalOp));
	op->addr = addr;
	op->type = R_ANAL_OP_TYPE_UNK;
	switch (data[0]) {
	case 0x00:
		op->type = R_ANAL_OP_TYPE_NOP;
		break;
	case 0x03:
	case 0x04:
	case 0x0c:
	case 0x13:
	case 0x14:
	case 0x1c:
	case 0x23:
	case 0x24:
	case 0x2c:
	case 0x33:
	case 0x34:
	case 0x3c:
		op->type = R_ANAL_OP_TYPE_ADD; // INC
		break;
	case 0x09:
	case 0x19:
	case 0x29:
	case 0x39:
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
	case 0x86:
	case 0x87:
	case 0xc6:
		op->type = R_ANAL_OP_TYPE_ADD;
		break;
	case 0x90:
	case 0x91:
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:
	case 0x96:
	case 0x97:
	case 0xd6:
		op->type = R_ANAL_OP_TYPE_SUB;
		break;
	case 0xc0:
	case 0xc8:
	case 0xd0:
	case 0xd8:
	case 0xe0:
	case 0xe8:
	case 0xf0:
	case 0xf8:
		op->type = R_ANAL_OP_TYPE_CRET;
		break;
	case 0xc9:
		op->type = R_ANAL_OP_TYPE_RET;
		break;
	case 0x05:
	case 0x0b:
	case 0x0d:
	case 0x15:
	case 0x1b:
	case 0x1d:
	case 0x25:
	case 0x2b:
	case 0x2d:
	case 0x35:
	case 0x3b:
	case 0x3d:
		// XXXX: DEC
		op->type = R_ANAL_OP_TYPE_SUB;
		break;
	case 0xc5:
	case 0xd5:
	case 0xe5:
	case 0xf5:
		op->type = R_ANAL_OP_TYPE_PUSH;
		break;
	case 0xc1:
	case 0xd1:
	case 0xe1:
	case 0xf1:
		op->type = R_ANAL_OP_TYPE_POP;
		break;
	case 0x40:
	case 0x49:
	case 0x52:
	case 0x5b:
	case 0x64:
	case 0x6d:
	case 0x76:
	case 0x7f:
		op->type = R_ANAL_OP_TYPE_TRAP; // HALT
		break;
	case 0x10:
	case 0x18:
	case 0x20:
	case 0x28:
	case 0x30:
	case 0x38:
	case 0xc2:
	case 0xc3:
	case 0xca:
	case 0xd2:
	case 0xda:
	case 0xe2:
	case 0xe9:
	case 0xea:
	case 0xf2:
	case 0xfa:
		op->type = R_ANAL_OP_TYPE_JMP; // jmpz
		break;

	case 0xc4:
	case 0xcc:
	case 0xcd:
	case 0xd4:
	case 0xdc:
	case 0xdd:
	case 0xe4:
	case 0xec:
	case 0xed:
	case 0xf4:
	case 0xfc:
	case 0xfd:
		op->type = R_ANAL_OP_TYPE_CALL;
		break;
	case 0xc7:				//rst 0
		op->jump = 0x00;
		op->fail = addr + ilen;
		op->type = R_ANAL_OP_TYPE_JMP;
		break;
	case 0xcf:				//rst 8
		op->jump = 0x08;
		op->fail = addr + ilen;
		op->type = R_ANAL_OP_TYPE_JMP;
		break;
	case 0xd7:				//rst 16
		op->jump = 0x10;
		op->fail = addr + ilen;
		op->type = R_ANAL_OP_TYPE_JMP;
		break;
	case 0xdf:				 //rst 24
		op->jump = 0x18;
		op->fail = addr + ilen;
		op->type = R_ANAL_OP_TYPE_JMP;
		break;
	case 0xe7:				//rst 32
		op->jump = 0x20;
		op->fail = addr + ilen;
		op->type = R_ANAL_OP_TYPE_JMP;
		break;
	case 0xef:				//rst 40
		op->jump = 0x28;
		op->fail = addr + ilen;
		op->type = R_ANAL_OP_TYPE_JMP;
		break;
	case 0xf7:				//rst 48
		op->jump = 0x30;
		op->fail = addr + ilen;
		op->type = R_ANAL_OP_TYPE_JMP;
		break;
	case 0xff:				//rst 56
		op->jump = 0x38;
		op->fail = addr + ilen;
		op->type = R_ANAL_OP_TYPE_JMP;
	break;					// copypasta from gb and z80
	}
	return op->size = ilen;
}

