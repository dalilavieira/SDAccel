#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  int ut32 ;
typedef  int cs_mode ;
struct TYPE_18__ {int size; scalar_t__* op_str; int /*<<< orphan*/  mnemonic; TYPE_2__* detail; } ;
typedef  TYPE_3__ cs_insn ;
struct TYPE_20__ {int immdisp; int bits; scalar_t__ syntax; scalar_t__ big_endian; int /*<<< orphan*/  pc; scalar_t__* features; scalar_t__* cpu; TYPE_1__* cur; } ;
struct TYPE_19__ {int size; int /*<<< orphan*/  buf; int /*<<< orphan*/  buf_asm; } ;
struct TYPE_17__ {int groups_count; int* groups; } ;
struct TYPE_16__ {int /*<<< orphan*/  (* disassemble ) (TYPE_5__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;} ;
typedef  int /*<<< orphan*/  RStrBuf ;
typedef  TYPE_4__ RAsmOp ;
typedef  TYPE_5__ RAsm ;

/* Variables and functions */
#define  ARM_GRP_ARM 131 
#define  ARM_GRP_THUMB 130 
#define  ARM_GRP_THUMB1ONLY 129 
#define  ARM_GRP_THUMB2 128 
 int /*<<< orphan*/  CS_ARCH_ARM ; 
 int /*<<< orphan*/  CS_ARCH_ARM64 ; 
 int CS_MODE_ARM ; 
 int CS_MODE_BIG_ENDIAN ; 
 int CS_MODE_LITTLE_ENDIAN ; 
 int CS_MODE_MCLASS ; 
 int CS_MODE_THUMB ; 
 int CS_MODE_V8 ; 
 int /*<<< orphan*/  CS_OPT_DETAIL ; 
 int /*<<< orphan*/  CS_OPT_OFF ; 
 int /*<<< orphan*/  CS_OPT_ON ; 
 int /*<<< orphan*/  CS_OPT_SYNTAX ; 
 int /*<<< orphan*/  CS_OPT_SYNTAX_DEFAULT ; 
 int /*<<< orphan*/  CS_OPT_SYNTAX_NOREGNAME ; 
 scalar_t__ R_ASM_SYNTAX_REGNUM ; 
 int /*<<< orphan*/  R_MIN (int,int) ; 
 int UT16_MAX ; 
 int UT32_MAX ; 
 int /*<<< orphan*/  arm64ass (char const*,int /*<<< orphan*/ ,int*) ; 
 int armass_assemble (char const*,int /*<<< orphan*/ ,int const) ; 
 scalar_t__ cd ; 
 int /*<<< orphan*/  cs_close (scalar_t__*) ; 
 int cs_disasm (scalar_t__,int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,TYPE_3__**) ; 
 int /*<<< orphan*/  cs_free (TYPE_3__*,int) ; 
 char* cs_group_name (scalar_t__,int) ; 
 char* cs_insn_name (scalar_t__,int) ; 
 int cs_open (int /*<<< orphan*/ ,int,scalar_t__*) ; 
 int /*<<< orphan*/  cs_option (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 char* r_str_newf (char*,char const*) ; 
 int /*<<< orphan*/  r_str_rmch (char*,char) ; 
 int /*<<< orphan*/  r_strbuf_append (int /*<<< orphan*/ *,char const*) ; 
 char* r_strbuf_drain (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_strbuf_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_strbuf_new (char*) ; 
 int /*<<< orphan*/  r_strbuf_set (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  r_strbuf_setbin (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_write_be16 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_write_be32 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_write_le16 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_write_le32 (int /*<<< orphan*/ *,int) ; 
 char* sdb_fmt (char*,int /*<<< orphan*/ ,char*,scalar_t__*) ; 
 char* strdup (char const*) ; 
 scalar_t__ strstr (scalar_t__*,char const*) ; 
 int /*<<< orphan*/  stub1 (TYPE_5__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

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

__attribute__((used)) static bool check_features(RAsm *a, cs_insn *insn) {
	int i;
	if (!insn || !insn->detail) {
		return true;
	}
	for (i = 0; i < insn->detail->groups_count; i++) {
		int id = insn->detail->groups[i];
		switch (id) {
		case ARM_GRP_ARM:
		case ARM_GRP_THUMB:
		case ARM_GRP_THUMB1ONLY:
		case ARM_GRP_THUMB2:
			continue;
		default:
			if (id < 128) {
				continue;
			}
		}
		const char *name = cs_group_name (cd, id);
		if (!name) {
			return true;
		}
		if (!strstr (a->features, name)) {
			return false;
		}
	}
	return true;
}

__attribute__((used)) static int disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	static int omode = -1;
	static int obits = 32;
	bool disp_hash = a->immdisp;
	cs_insn* insn = NULL;
	cs_mode mode = 0;
	int ret, n = 0;
	mode |= (a->bits == 16)? CS_MODE_THUMB: CS_MODE_ARM;
	mode |= (a->big_endian)? CS_MODE_BIG_ENDIAN: CS_MODE_LITTLE_ENDIAN;
	if (mode != omode || a->bits != obits) {
		cs_close (&cd);
		cd = 0; // unnecessary
		omode = mode;
		obits = a->bits;
	}

	if (a->cpu) {
		if (strstr (a->cpu, "cortex")) {
			mode |= CS_MODE_MCLASS;
		}
		if (a->bits != 64) {
			if (strstr (a->cpu, "v8")) {
				mode |= CS_MODE_V8;
			}
		}
	}
	if (a->features && a->bits != 64) {
		if (strstr (a->features, "v8")) {
			mode |= CS_MODE_V8;
		}
	}
	if (op) {
		op->size = 4;
		r_strbuf_set (&op->buf_asm, "");
	}
	if (!cd || mode != omode) {
		ret = (a->bits == 64)?
			cs_open (CS_ARCH_ARM64, mode, &cd):
			cs_open (CS_ARCH_ARM, mode, &cd);
		if (ret) {
			ret = -1;
			goto beach;
		}
	}
	cs_option (cd, CS_OPT_SYNTAX, (a->syntax == R_ASM_SYNTAX_REGNUM)
			? CS_OPT_SYNTAX_NOREGNAME
			: CS_OPT_SYNTAX_DEFAULT);
	cs_option (cd, CS_OPT_DETAIL, (a->features && *a->features)
		? CS_OPT_ON: CS_OPT_OFF);
	if (!buf) {
		goto beach;
	}
	n = cs_disasm (cd, buf, R_MIN (4, len), a->pc, 1, &insn);
	if (n < 1 || insn->size < 1) {
		ret = -1;
		goto beach;
	}
	if (op) {
		op->size = 0;
	}
	if (a->features && *a->features) {
		if (!check_features (a, insn) && op) {
			op->size = insn->size;
			r_strbuf_set (&op->buf_asm, "illegal");
		}
	}
	if (op && !op->size) {
		op->size = insn->size;
		char *buf_asm = sdb_fmt ("%s%s%s",
			insn->mnemonic,
			insn->op_str[0]?" ":"",
			insn->op_str);
		if (!disp_hash) {
			r_str_rmch (buf_asm, '#');
		}
		r_strbuf_set (&op->buf_asm, buf_asm);
	}
	cs_free (insn, n);
	beach:
	cs_close (&cd);
	if (op) {
		if (!*r_strbuf_get (&op->buf_asm)) {
			r_strbuf_set (&op->buf_asm, "invalid");
		}
		return op->size;
	}
	return ret;
}

__attribute__((used)) static int assemble(RAsm *a, RAsmOp *op, const char *buf) {
	const bool is_thumb = (a->bits == 16);
	int opsize;
	ut32 opcode;
	if (a->bits == 64) {
		if (!arm64ass (buf, a->pc, &opcode)) {
			return -1;
		}
	} else {
		opcode = armass_assemble (buf, a->pc, is_thumb);
		if (a->bits != 32 && a->bits != 16) {
			eprintf ("Error: ARM assembler only supports 16 or 32 bits\n");
			return -1;
		}
	}
	if (opcode == UT32_MAX) {
		return -1;
	}
	ut8 opbuf[4];
	if (is_thumb) {
		const int o = opcode >> 16;
		opsize = o > 0? 4: 2;
		if (opsize == 4) {
			if (a->big_endian) {
				r_write_le16 (opbuf, opcode >> 16);
				r_write_le16 (opbuf + 2, opcode & UT16_MAX);
			} else {
				r_write_be32 (opbuf, opcode);
			}
		} else if (opsize == 2) {
			if (a->big_endian) {
				r_write_le16 (opbuf, opcode & UT16_MAX);
			} else {
				r_write_be16 (opbuf, opcode & UT16_MAX);
			}
		}
	} else {
		opsize = 4;
		if (a->big_endian) {
			r_write_le32 (opbuf, opcode);
		} else {
			r_write_be32 (opbuf, opcode);
		}
	}
	r_strbuf_setbin (&op->buf, opbuf, opsize);
// XXX. thumb endian assembler needs no swap
	return opsize;
}

