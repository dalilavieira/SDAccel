#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_6__ ;
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
struct TYPE_23__ {int size; } ;
typedef  TYPE_1__ vle_t ;
struct TYPE_24__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ vle_handle ;
typedef  int ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
typedef  int ut32 ;
struct TYPE_25__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_3__ ppcps_t ;
struct TYPE_26__ {scalar_t__ size; scalar_t__* op_str; int /*<<< orphan*/  mnemonic; } ;
typedef  TYPE_4__ cs_insn ;
typedef  int /*<<< orphan*/  buf_asm ;
struct TYPE_28__ {int bits; scalar_t__ big_endian; scalar_t__ cpu; int /*<<< orphan*/  pc; } ;
struct TYPE_27__ {int size; } ;
typedef  TYPE_5__ RAsmOp ;
typedef  TYPE_6__ RAsm ;

/* Variables and functions */
 int /*<<< orphan*/  CS_ARCH_PPC ; 
 int CS_ERR_OK ; 
 int CS_MODE_32 ; 
 int CS_MODE_64 ; 
 int CS_MODE_BIG_ENDIAN ; 
 int CS_MODE_LITTLE_ENDIAN ; 
 int /*<<< orphan*/  CS_OPT_DETAIL ; 
 int /*<<< orphan*/  CS_OPT_OFF ; 
 int /*<<< orphan*/  cs_close (scalar_t__*) ; 
 int cs_disasm (scalar_t__,int const*,int,int /*<<< orphan*/ ,int,TYPE_4__**) ; 
 int /*<<< orphan*/  cs_free (TYPE_4__*,int) ; 
 int cs_open (int /*<<< orphan*/ ,int,scalar_t__*) ; 
 int /*<<< orphan*/  cs_option (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ handle ; 
 int libps_decode (int const,TYPE_3__*) ; 
 int /*<<< orphan*/  libps_snprint (char*,int,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  r_asm_op_set_asm (TYPE_5__*,char const*) ; 
 char* sdb_fmt (char*,int /*<<< orphan*/ ,char*,scalar_t__*) ; 
 scalar_t__ strncmp (scalar_t__,char*,int) ; 
 int /*<<< orphan*/  vle_free (TYPE_1__*) ; 
 int /*<<< orphan*/  vle_init (TYPE_2__*,int const*,int) ; 
 TYPE_1__* vle_next (TYPE_2__*) ; 
 int /*<<< orphan*/  vle_snprint (char*,int,int /*<<< orphan*/ ,TYPE_1__*) ; 

__attribute__((used)) static bool the_end(void *p) {
	if (handle) {
		cs_close (&handle);
		handle = 0;
	}
	return true;
}

__attribute__((used)) static int decompile_vle(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	vle_t* instr = 0;
	vle_handle handle = {0};
	if (len < 2) {
		return -1;
	}
	if (!vle_init (&handle, buf, len) && (instr = vle_next (&handle))) {
		op->size = instr->size;
		char buf_asm[64];
		vle_snprint (buf_asm, sizeof (buf_asm), a->pc, instr);
		r_asm_op_set_asm (op, buf_asm);
		vle_free (instr);
	} else {
		r_asm_op_set_asm (op, "invalid");
		op->size = 2;
		return -1;
	}
	return op->size;
}

__attribute__((used)) static int decompile_ps(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	ppcps_t instr = {0};
	if (len < 4) {
		return -1;
	}
	op->size = 4;
	const ut32 data = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
	if (libps_decode (data, &instr) < 1) {
		r_asm_op_set_asm (op, "invalid");
		return -1;
	}
	char buf_asm[64];
	libps_snprint (buf_asm, sizeof (buf_asm), a->pc, &instr);
	r_asm_op_set_asm (op, buf_asm);
	return op->size;
}

__attribute__((used)) static int disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	static int omode = -1, obits = -1;
	int n, ret;
	ut64 off = a->pc;
	cs_insn* insn;
	int mode = (a->bits == 64) ? CS_MODE_64 : (a->bits == 32) ? CS_MODE_32 : 0;
	mode |= a->big_endian ? CS_MODE_BIG_ENDIAN : CS_MODE_LITTLE_ENDIAN;

	if (a->cpu && strncmp (a->cpu, "vle", 3) == 0) {
		// vle is big-endian only
		if (!a->big_endian) {
			return -1;
		}
		ret = decompile_vle (a, op, buf, len);
		if (ret >= 0) {
			return op->size;
		}
	} else if (a->cpu && strncmp (a->cpu, "ps", 2) == 0) {
		// libps is big-endian only
		if (!a->big_endian) {
			return -1;
		}
		ret = decompile_ps (a, op, buf, len);
		if (ret >= 0) {
			return op->size;
		}
	}
	if (mode != omode || a->bits != obits) {
		cs_close (&handle);
		handle = 0;
		omode = mode;
		obits = a->bits;
	}
	if (handle == 0) {
		ret = cs_open (CS_ARCH_PPC, mode, &handle);
		if (ret != CS_ERR_OK) {
			return -1;
		}
	}
	op->size = 4;
	cs_option (handle, CS_OPT_DETAIL, CS_OPT_OFF);
	n = cs_disasm (handle, (const ut8*) buf, len, off, 1, &insn);
	op->size = 4;
	if (n > 0 && insn->size > 0) {
		const char *opstr = sdb_fmt ("%s%s%s", insn->mnemonic,
			insn->op_str[0] ? " " : "", insn->op_str);
		r_asm_op_set_asm (op, opstr);
		cs_free (insn, n);
		return op->size;
	}
	r_asm_op_set_asm (op, "invalid");
	op->size = 4;
	cs_free (insn, n);
	return op->size;
}

