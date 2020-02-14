#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ut64 ;
struct TYPE_30__ {int bits; int /*<<< orphan*/  reg; int /*<<< orphan*/ * esil; } ;
struct TYPE_29__ {int /*<<< orphan*/  addr; } ;
struct TYPE_28__ {int /*<<< orphan*/  esil; } ;
struct TYPE_27__ {char* name; char* type; int /*<<< orphan*/  delta; int /*<<< orphan*/  kind; int /*<<< orphan*/  addr; int /*<<< orphan*/  isarg; int /*<<< orphan*/  size; } ;
struct TYPE_26__ {TYPE_6__* anal; int /*<<< orphan*/  config; } ;
struct TYPE_25__ {int size; } ;
typedef  int /*<<< orphan*/  Sdb ;
typedef  int /*<<< orphan*/  RStrBuf ;
typedef  TYPE_1__ RRegItem ;
typedef  TYPE_2__ RCore ;
typedef  int /*<<< orphan*/  RConfigHold ;
typedef  TYPE_3__ RAnalVar ;
typedef  TYPE_4__ RAnalOp ;
typedef  TYPE_5__ RAnalFunction ;
typedef  TYPE_6__ RAnal ;

/* Variables and functions */
 int /*<<< orphan*/  ADB ; 
 char* ARGPREFIX ; 
 char* RKEY (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  R_ANAL_COND_GE 131 
#define  R_ANAL_COND_GT 130 
#define  R_ANAL_COND_LE 129 
#define  R_ANAL_COND_LT 128 
 int R_ANAL_OP_MASK_ESIL ; 
 int R_ANAL_OP_MASK_VAL ; 
 int /*<<< orphan*/  R_REG_NAME_BP ; 
 int /*<<< orphan*/  R_REG_NAME_SP ; 
 int SDB_CONTAINS (int,char const*) ; 
 scalar_t__ UT64_MAX ; 
 char* VARPREFIX ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 TYPE_5__* r_anal_get_fcn_in (TYPE_6__*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_anal_op_free (TYPE_4__*) ; 
 int /*<<< orphan*/  r_anal_var_rename (TYPE_6__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,char const*,char const*,int) ; 
 int /*<<< orphan*/  r_anal_var_retype (TYPE_6__*,scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  r_config_hold_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_config_hold_i (int /*<<< orphan*/ *,char*,char*,char*,char*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_config_hold_restore (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_config_set (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  r_config_set_i (int /*<<< orphan*/ ,char*,int) ; 
 TYPE_4__* r_core_anal_op (TYPE_2__*,scalar_t__,int) ; 
 scalar_t__ r_num_math (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 char* r_reg_32_to_64 (int /*<<< orphan*/ ,char*) ; 
 TYPE_1__* r_reg_get (int /*<<< orphan*/ ,char*,int) ; 
 char* r_reg_get_name (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ r_reg_getv (int /*<<< orphan*/ ,char const*) ; 
 scalar_t__ r_str_endswith (char const*,char*) ; 
 scalar_t__ r_str_startswith (char*,char*) ; 
 char* r_str_trim (char*) ; 
 int /*<<< orphan*/  r_strbuf_append (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  r_strbuf_free (int /*<<< orphan*/ *) ; 
 char const* r_strbuf_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_strbuf_new (char*) ; 
 int /*<<< orphan*/  r_strbuf_set (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  r_strbuf_setf (int /*<<< orphan*/ *,char*,char*,...) ; 
 int /*<<< orphan*/  sdb_array_append_num (int /*<<< orphan*/ ,char const*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdb_const_get (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 char* sdb_fmt (char*,int,...) ; 
 scalar_t__ sdb_num_get (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 char* strchr (char*,char) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 char* strdup (char const*) ; 
 scalar_t__ strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 
 int /*<<< orphan*/  strncpy (char*,char*,int) ; 
 char* strstr (char const*,char*) ; 

__attribute__((used)) static bool r_anal_emul_init(RCore *core, RConfigHold *hc) {
	r_config_hold_i (hc, "esil.romem", "asm.trace", "dbg.trace",
			"esil.nonull", "dbg.follow", NULL);
	r_config_set (core->config, "esil.romem", "true");
	r_config_set (core->config, "asm.trace", "true");
	r_config_set (core->config, "dbg.trace", "true");
	r_config_set (core->config, "esil.nonull", "true");
	r_config_set_i (core->config, "dbg.follow", false);
	const char *bp = r_reg_get_name (core->anal->reg, R_REG_NAME_BP);
	const char *sp = r_reg_get_name (core->anal->reg, R_REG_NAME_SP);
	if ((bp && !r_reg_getv (core->anal->reg, bp)) && (sp && !r_reg_getv (core->anal->reg, sp))) {
		eprintf ("Stack isn't initialized.\n");
		eprintf ("Try running aei and aeim commands before aft for default stack initialization\n");
		return false;
	}
	return (core->anal->esil != NULL);
}

__attribute__((used)) static void r_anal_emul_restore(RCore *core, RConfigHold *hc) {
	r_config_hold_restore (hc);
	r_config_hold_free (hc);
}

__attribute__((used)) static bool type_pos_hit(RAnal *anal, Sdb *trace, bool in_stack, int idx, int size, const char *place) {
	if (in_stack) {
		const char *sp_name = r_reg_get_name (anal->reg, R_REG_NAME_SP);
		ut64 sp = r_reg_getv (anal->reg, sp_name);
		ut64 write_addr = sdb_num_get (trace, sdb_fmt ("%d.mem.write", idx), 0);
		return (write_addr == sp + size);
	}
	return SDB_CONTAINS (idx, place);
}

__attribute__((used)) static void var_rename(RAnal *anal, RAnalVar *v, const char *name, ut64 addr) {
	if (!name || !v) {
		return;
	}
	if (!*name || !strcmp (name , "...")) {
		return;
	}
	bool is_default = (r_str_startswith (v->name, VARPREFIX)
			|| r_str_startswith (v->name, ARGPREFIX))? true: false;
	if (*name == '*') {
		name++;
	}
	// longer name tends to be meaningful like "src" instead of "s1"
	if (!is_default && (strlen (v->name) > strlen (name))) {
		return;
	}
	RAnalFunction *fcn = r_anal_get_fcn_in (anal, addr, 0);
	if (!fcn) {
		return;
	}
	r_anal_var_rename (anal, fcn->addr, 1, v->kind, v->name, name, false);
}

__attribute__((used)) static void var_retype(RAnal *anal, RAnalVar *var, const char *vname, char *type, ut64 addr, bool ref, bool pfx) {
	if (!type || !var) {
		return;
	}
	char *trim = r_str_trim (type);
	if (!*trim) {
		return;
	}
	bool is_ptr = (vname && *vname == '*')? true: false;
	if (!strncmp (trim, "int", 3) || (!is_ptr && !strcmp (trim, "void"))) {
		// default or void type
		return;
	}
	const char *expand = var->type;
	if (!strcmp(var->type, "int32_t")) {
		expand = "int";
	} else if (!strcmp(var->type, "uint32_t")) {
		expand = "unsigned int";
	} else if (!strcmp(var->type, "uint64_t")) {
		expand = "unsigned long long";
	}
	const char *tmp = strstr (expand, "int");
	bool is_default = tmp? true: false;
	if (!is_default && strncmp (var->type, "void", 4)) {
		// return since type is already propgated
		// except for "void *", since "void *" => "char *" is possible
		return;
	}
	RStrBuf *sb = r_strbuf_new ("");
	if (pfx) {
		if (is_default && strncmp (var->type, "signed", 6)) {
			r_strbuf_setf (sb, "%s %s", type, tmp);
		} else {
			r_strbuf_free (sb);
			return;
		}
	} else {
		r_strbuf_set (sb, trim);
	}
	if (!strncmp (r_strbuf_get (sb), "const ", 6)) {
		// Droping const from type
		//TODO: Infering const type
		r_strbuf_setf (sb, "%s", type + 6);
	}
	if (is_ptr) {
		//type *ptr => type *
		r_strbuf_append (sb, " *");
	}
	if (ref) {
		if (r_str_endswith (r_strbuf_get (sb), "*")) { // type * => type **
			r_strbuf_append (sb, "*");
		} else {   //  type => type *
			r_strbuf_append (sb, " *");
		}
	}

	char* tmp1 = r_strbuf_get (sb);
	if (r_str_startswith (tmp1, "unsigned long long")) {
		r_strbuf_set (sb, "uint64_t");
	} else if (r_str_startswith (tmp1, "unsigned")) {
		r_strbuf_set (sb, "uint32_t");
	} else if (r_str_startswith (tmp1, "int")) {
		r_strbuf_set (sb, "int32_t");
	}
	r_anal_var_retype (anal, addr, 1, var->delta, var->kind, r_strbuf_get (sb), var->size, var->isarg, var->name);
	r_strbuf_free (sb);
}

__attribute__((used)) static void get_src_regname(RCore *core, ut64 addr, char *regname, int size) {
	RAnal *anal = core->anal;
	RAnalOp *op = r_core_anal_op (core, addr, R_ANAL_OP_MASK_VAL | R_ANAL_OP_MASK_ESIL);
	if (!op) {
		return;
	}
	char *op_esil = strdup (r_strbuf_get (&op->esil));
	char *tmp = strchr (op_esil, ',');
	if (tmp) {
		*tmp = '\0';
	}
	memset (regname, 0, size);
	RRegItem *ri = r_reg_get (anal->reg, op_esil, -1);
	if (ri) {
		if ((anal->bits == 64) && (ri->size == 32)) {
			const char *reg = r_reg_32_to_64 (anal->reg, op_esil);
			if (reg) {
				free (op_esil);
				op_esil = strdup (reg);
			}
		}
		strncpy (regname, op_esil, size - 1);
	}
	free (op_esil);
	r_anal_op_free (op);
}

__attribute__((used)) static ut64 get_addr(Sdb *trace, const char *regname, int idx) {
	if (!regname || !*regname) {
		return UT64_MAX;
	}
	const char *query = sdb_fmt ("%d.reg.read.%s", idx, regname);
	return r_num_math (NULL, sdb_const_get (trace, query, 0));
}

__attribute__((used)) static int cond_invert (int cond) {
	int res = 0;
	switch (cond) {
	case R_ANAL_COND_LE:
		res = R_ANAL_COND_GT;
		break;
	case R_ANAL_COND_LT:
		res = R_ANAL_COND_GE;
		break;
	case R_ANAL_COND_GE:
		res = R_ANAL_COND_LT;
		break;
	case R_ANAL_COND_GT:
		res = R_ANAL_COND_LE;
		break;
	}
	return res;
}

__attribute__((used)) static void var_add_range (RAnal *a, RAnalVar *var, int cond, ut64 val) {
	const char *key = RKEY (var->addr, var->kind, var->delta);
	sdb_array_append_num (ADB, key, cond, 0);
	sdb_array_append_num (ADB, key, val, 0);
}

