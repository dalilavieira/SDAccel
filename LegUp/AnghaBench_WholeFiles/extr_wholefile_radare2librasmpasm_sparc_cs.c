#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
struct TYPE_14__ {int size; scalar_t__* op_str; int /*<<< orphan*/  mnemonic; } ;
typedef  TYPE_2__ cs_insn ;
struct TYPE_16__ {int /*<<< orphan*/  pc; scalar_t__ big_endian; scalar_t__* cpu; TYPE_1__* cur; } ;
struct TYPE_15__ {int size; } ;
struct TYPE_13__ {int /*<<< orphan*/  (* disassemble ) (TYPE_4__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;} ;
typedef  int /*<<< orphan*/  RStrBuf ;
typedef  TYPE_3__ RAsmOp ;
typedef  TYPE_4__ RAsm ;

/* Variables and functions */
 int /*<<< orphan*/  CS_ARCH_SPARC ; 
 int CS_MODE_BIG_ENDIAN ; 
 int CS_MODE_V9 ; 
 int /*<<< orphan*/  CS_OPT_DETAIL ; 
 int /*<<< orphan*/  CS_OPT_OFF ; 
 scalar_t__ cd ; 
 int /*<<< orphan*/  cs_close (scalar_t__*) ; 
 int cs_disasm (scalar_t__,int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ,int,TYPE_2__**) ; 
 int /*<<< orphan*/  cs_free (TYPE_2__*,int) ; 
 char* cs_insn_name (scalar_t__,int) ; 
 int cs_open (int /*<<< orphan*/ ,int,scalar_t__*) ; 
 int /*<<< orphan*/  cs_option (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  r_asm_op_set_asm (TYPE_3__*,char*) ; 
 char* r_str_newf (char*,char const*) ; 
 int /*<<< orphan*/  r_str_replace_char (char*,char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_strbuf_append (int /*<<< orphan*/ *,char const*) ; 
 char* r_strbuf_drain (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_strbuf_new (char*) ; 
 char* sdb_fmt (char*,int /*<<< orphan*/ ,char*,scalar_t__*) ; 
 int /*<<< orphan*/  strcmp (scalar_t__*,char*) ; 
 char* strdup (char const*) ; 
 int /*<<< orphan*/  stub1 (TYPE_4__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static char *mnemonics(RAsm *a, int id, bool json) {
	int i;
	a->cur->disassemble (a, NULL, NULL, -1);
	if (id != -1) {
		const char *name = cs_insn_name (cd, id);
		if (json) {
			return name? r_str_newf ("[\"%s\"]\n", name): NULL;
		}
		return name? strdup (name): NULL;
	}
	RStrBuf *buf = r_strbuf_new ("");
	if (json) {
		r_strbuf_append (buf, "[");
	}
	for (i = 1; ; i++) {
		const char *op = cs_insn_name (cd, i);
		if (!op) {
			break;
		}
		if (json) {
			r_strbuf_append (buf, "\"");
		}
		r_strbuf_append (buf, op);
		if (json) {
			if (cs_insn_name (cd, i + 1)) {
				r_strbuf_append (buf, "\",");
			} else {
				r_strbuf_append (buf, "\"]\n");
			}
		} else {
			r_strbuf_append (buf, "\n");
		}
	}
	return r_strbuf_drain (buf);
}

__attribute__((used)) static int disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	cs_insn* insn;
	int n = -1, ret = -1;
	int mode = CS_MODE_BIG_ENDIAN;
	if (a->cpu && *a->cpu) {
		if (!strcmp (a->cpu, "v9")) {
			mode |= CS_MODE_V9;
		}
	}
	if (op) {
		memset (op, 0, sizeof (RAsmOp));
		op->size = 4;
	}
	if (cd != 0) {
		cs_close (&cd);
	}
	ret = cs_open (CS_ARCH_SPARC, mode, &cd);
	if (ret) {
		goto fin;
	}
	cs_option (cd, CS_OPT_DETAIL, CS_OPT_OFF);
	if (!op) {
		return 0;
	}
	if (a->big_endian) {
		n = cs_disasm (cd, buf, len, a->pc, 1, &insn);
	}
	if (n < 1) {
		r_asm_op_set_asm (op, "invalid");
		op->size = 4;
		ret = -1;
		goto beach;
	} else {
		ret = 4;
	}
	if (insn->size < 1) {
		goto beach;
	}
	op->size = insn->size;
	char *buf_asm = sdb_fmt ("%s%s%s",
		insn->mnemonic, insn->op_str[0]? " ": "",
		insn->op_str);
	r_str_replace_char (buf_asm, '%', 0);
	r_asm_op_set_asm (op, buf_asm);
	// TODO: remove the '$'<registername> in the string
	cs_free (insn, n);
	beach:
	// cs_close (&cd);
	fin:
	return ret;
}

