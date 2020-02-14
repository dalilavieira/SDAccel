#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
struct TYPE_19__ {scalar_t__ size; TYPE_2__* detail; scalar_t__* op_str; int /*<<< orphan*/  mnemonic; } ;
typedef  TYPE_3__ cs_insn ;
struct TYPE_21__ {scalar_t__ syntax; int bits; char* features; int /*<<< orphan*/  pc; TYPE_1__* cur; } ;
struct TYPE_20__ {int size; int /*<<< orphan*/  buf_asm; } ;
struct TYPE_18__ {int groups_count; int* groups; } ;
struct TYPE_17__ {int /*<<< orphan*/  (* disassemble ) (TYPE_5__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;} ;
typedef  int /*<<< orphan*/  RStrBuf ;
typedef  TYPE_4__ RAsmOp ;
typedef  TYPE_5__ RAsm ;

/* Variables and functions */
 int /*<<< orphan*/  CS_ARCH_X86 ; 
 int CS_MODE_16 ; 
 int CS_MODE_32 ; 
 int CS_MODE_64 ; 
 int /*<<< orphan*/  CS_OPT_DETAIL ; 
 int /*<<< orphan*/  CS_OPT_OFF ; 
 int /*<<< orphan*/  CS_OPT_ON ; 
 int /*<<< orphan*/  CS_OPT_SYNTAX ; 
 int /*<<< orphan*/  CS_OPT_SYNTAX_ATT ; 
 int /*<<< orphan*/  CS_OPT_SYNTAX_INTEL ; 
 scalar_t__ R_ASM_SYNTAX_ATT ; 
 scalar_t__ R_ASM_SYNTAX_JZ ; 
 scalar_t__ R_ASM_SYNTAX_MASM ; 
 scalar_t__ VPCEXT2 (int const*,int) ; 
 int X86_GRP_MODE32 ; 
 int X86_GRP_MODE64 ; 
 scalar_t__ cd ; 
static  int check_features (TYPE_5__*,TYPE_3__*) ; 
 int /*<<< orphan*/  cs_close (scalar_t__*) ; 
 scalar_t__ cs_disasm (scalar_t__,int const*,int,int /*<<< orphan*/ ,int,TYPE_3__**) ; 
 int /*<<< orphan*/  cs_free (TYPE_3__*,scalar_t__) ; 
 char* cs_group_name (scalar_t__,int) ; 
 char* cs_insn_name (scalar_t__,int) ; 
 int cs_open (int /*<<< orphan*/ ,int,scalar_t__*) ; 
 int /*<<< orphan*/  cs_option (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  memmove (char*,char*,scalar_t__) ; 
 scalar_t__ n ; 
 int /*<<< orphan*/  r_asm_op_set_asm (TYPE_4__*,char const*) ; 
 char* r_str_newf (char*,char const*) ; 
 int /*<<< orphan*/  r_strbuf_append (int /*<<< orphan*/ *,char const*) ; 
 char* r_strbuf_drain (int /*<<< orphan*/ *) ; 
 char* r_strbuf_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_strbuf_new (char*) ; 
 void* sdb_fmt (char*,int const,...) ; 
 char* strdup (char const*) ; 
 scalar_t__ strlen (char*) ; 
 int /*<<< orphan*/  strncmp (char*,char*,int) ; 
 char* strstr (char*,char const*) ; 
 int /*<<< orphan*/  stub1 (TYPE_5__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static bool the_end(void *p) {
#if 0
#if !USE_ITER_API
	if (insn) {
		cs_free (insn, n);
		insn = NULL;
	}
#endif
#endif
	if (cd) {
		cs_close (&cd);
		cd = 0;
	}
	return true;
}

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

void decompile_vm(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	const char *buf_asm = "invalid";
	if (len > 3 && buf[0] == 0x0F && buf[1] == 0x3F && (VPCEXT2 (buf, 0x01) || VPCEXT2 (buf, 0x05) || VPCEXT2 (buf, 0x07) || VPCEXT2 (buf, 0x0D) || VPCEXT2 (buf, 0x10))) {
		if (a->syntax == R_ASM_SYNTAX_ATT) {
			buf_asm = sdb_fmt ("vpcext $0x%x, $0x%x", buf[3], buf[2]);
		} else {
			buf_asm = sdb_fmt ("vpcext %xh, %xh", buf[2], buf[3]);
		}
		op->size = 4;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x00 && buf[4] == 0x00) {
		/* 0F C6 28 00 00 vmgetinfo */
		buf_asm ="vmgetinfo";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x00 && buf[4] == 0x01) {
		/* 0F C6 28 00 01 vmsetinfo */
		buf_asm ="vmsetinfo";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x00 && buf[4] == 0x02) {
		/* 0F C6 28 00 02 vmdxdsbl */
		buf_asm ="vmdxdsbl";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x00 && buf[4] == 0x03) {
		/* 0F C6 28 00 03 vmdxenbl */
		buf_asm ="vmdxenbl";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x01 && buf[4] == 0x00) {
		/* 0F C6 28 01 00 vmcpuid */
		buf_asm ="vmcpuid";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x01 && buf[4] == 0x01) {
		/* 0F C6 28 01 01 vmhlt */
		buf_asm ="vmhlt";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x01 && buf[4] == 0x02) {
		/* 0F C6 28 01 02 vmsplaf */
		buf_asm ="vmsplaf";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x02 && buf[4] == 0x00) {
		/* 0F C6 28 02 00 vmpushfd */
		buf_asm ="vmpushfd";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x02 && buf[4] == 0x01) {
		/* 0F C6 28 02 01 vmpopfd */
		buf_asm ="vmpopfd";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x02 && buf[4] == 0x02) {
		/* 0F C6 28 02 02 vmcli */
		buf_asm ="vmcli";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x02 && buf[4] == 0x03) {
		/* 0F C6 28 02 03 vmsti */
		buf_asm ="vmsti";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x02 && buf[4] == 0x04) {
		/* 0F C6 28 02 04 vmiretd */
		buf_asm ="vmiretd";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x03 && buf[4] == 0x00) {
		/* 0F C6 28 03 00 vmsgdt */
		buf_asm ="vmsgdt";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x03 && buf[4] == 0x01) {
		/* 0F C6 28 03 01 vmsidt */
		buf_asm ="vmsidt";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x03 && buf[4] == 0x02) {
		/* 0F C6 28 03 02 vmsldt */
		buf_asm ="vmsldt";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x03 && buf[4] == 0x03) {
		/* 0F C6 28 03 03 vmstr */
		buf_asm ="vmstr";
		op->size = 5;
	} else if (len > 4 && buf[0] == 0x0F && buf[1] == 0xC6 && buf[2] == 0x28 && buf[3] == 0x04 && buf[4] == 0x00) {
		/* 0F C6 28 04 00 vmsdte */
		buf_asm ="vmsdte";
		op->size = 5;
	}
	r_asm_op_set_asm (op, buf_asm);
}

__attribute__((used)) static int disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	static int omode = 0;
	int mode, ret;
	ut64 off = a->pc;

	mode =  (a->bits == 64)? CS_MODE_64:
		(a->bits == 32)? CS_MODE_32:
		(a->bits == 16)? CS_MODE_16: 0;
	if (cd && mode != omode) {
		cs_close (&cd);
		cd = 0;
	}
	if (op) {
		op->size = 0;
	}
	omode = mode;
	if (cd == 0) {
		ret = cs_open (CS_ARCH_X86, mode, &cd);
		if (ret) {
			return 0;
		}
	}
	if (a->features && *a->features) {
		cs_option (cd, CS_OPT_DETAIL, CS_OPT_ON);
	} else {
		cs_option (cd, CS_OPT_DETAIL, CS_OPT_OFF);
	}
	// always unsigned immediates (kernel addresses)
	// maybe r2 should have an option for this too?
#if CS_API_MAJOR >= 4
	cs_option (cd, CS_OPT_UNSIGNED, CS_OPT_ON);
#endif
	if (a->syntax == R_ASM_SYNTAX_MASM) {
#if CS_API_MAJOR >= 4
		cs_option (cd, CS_OPT_SYNTAX, CS_OPT_SYNTAX_MASM);
#endif
	} else if (a->syntax == R_ASM_SYNTAX_ATT) {
		cs_option (cd, CS_OPT_SYNTAX, CS_OPT_SYNTAX_ATT);
	} else {
		cs_option (cd, CS_OPT_SYNTAX, CS_OPT_SYNTAX_INTEL);
	}
	if (!op) {
		return true;
	}
	op->size = 1;
	cs_insn *insn = NULL;
#if USE_ITER_API
	{
		size_t size = len;
		if (!insn || cd < 1) {
			insn = cs_malloc (cd);
		}
		if (!insn) {
			cs_free (insn, n);
			return 0;
		}
		memset (insn, 0, insn->size);
		insn->size = 1;
		n = cs_disasm_iter (cd, (const uint8_t**)&buf, &size, (uint64_t*)&off, insn);
	}
#else
	n = cs_disasm (cd, (const ut8*)buf, len, off, 1, &insn);
#endif
	if (op) {
		op->size = 0;
	}
	if (a->features && *a->features) {
		if (!check_features (a, insn)) {
			op->size = insn->size;
			r_asm_op_set_asm (op, "illegal");
		}
	}
	if (op->size == 0 && n > 0 && insn->size > 0) {
		char *ptrstr;
		op->size = insn->size;
		char *buf_asm = sdb_fmt ("%s%s%s",
				insn->mnemonic, insn->op_str[0]?" ":"",
				insn->op_str);
		ptrstr = strstr (buf_asm, "ptr ");
		if (ptrstr) {
			memmove (ptrstr, ptrstr + 4, strlen (ptrstr + 4) + 1);
		}
		r_asm_op_set_asm (op, buf_asm);
	} else {
		decompile_vm (a, op, buf, len);
	}
	if (a->syntax == R_ASM_SYNTAX_JZ) {
		char *buf_asm = r_strbuf_get (&op->buf_asm);
		if (!strncmp (buf_asm, "je ", 3)) {
			memcpy (buf_asm, "jz", 2);
		} else if (!strncmp (buf_asm, "jne ", 4)) {
			memcpy (buf_asm, "jnz", 3);
		}
	}
#if 0
	// [eax + ebx*4]  =>  [eax + ebx * 4]
	char *ast = strchr (op->buf_asm, '*');
	if (ast && ast > op->buf_asm) {
		ast--;
		if (ast[0] != ' ') {
			char *tmp = strdup (ast + 1);
			if (tmp) {
				ast[0] = ' ';
				if (tmp[0] && tmp[1] && tmp[1] != ' ') {
					strcpy (ast, " * ");
					strcpy (ast + 3, tmp + 1);
				} else {
					strcpy (ast + 1, tmp);
				}
				free (tmp);
			}
		}
	}
#endif
#if USE_ITER_API
	/* do nothing because it should be allocated once and freed in the_end */
#else
	if (insn) {
		cs_free (insn, n);
	}
#endif
	return op->size;
}

__attribute__((used)) static int check_features(RAsm *a, cs_insn *insn) {
	const char *name;
	int i;
	if (!insn || !insn->detail) {
		return 1;
	}
	for (i = 0; i < insn->detail->groups_count; i++) {
		int id = insn->detail->groups[i];
		if (id < 128) {
			continue;
		}
		if (id == X86_GRP_MODE32) {
			continue;
		}
		if (id == X86_GRP_MODE64) {
			continue;
		}
		name = cs_group_name (cd, id);
		if (!name) {
			return 1;
		}
		if (!strstr (a->features, name)) {
			return 0;
		}
	}
	return 1;
}

