#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int const ut64 ;
typedef  int const ut32 ;
typedef  int st64 ;
struct TYPE_21__ {int /*<<< orphan*/  reg; int /*<<< orphan*/  big_endian; } ;
struct TYPE_20__ {int jump; int fail; int eob; int addr; int size; int ptr; int val; void* type; int /*<<< orphan*/  family; TYPE_1__* dst; } ;
struct TYPE_19__ {int base; int delta; void* reg; } ;
typedef  TYPE_1__ RAnalValue ;
typedef  int /*<<< orphan*/  RAnalOpMask ;
typedef  TYPE_2__ RAnalOp ;
typedef  TYPE_3__ RAnal ;

/* Variables and functions */
#define  FCC_A 191 
#define  FCC_E 190 
#define  FCC_G 189 
#define  FCC_GE 188 
#define  FCC_L 187 
#define  FCC_LE 186 
#define  FCC_LG 185 
#define  FCC_N 184 
#define  FCC_NE 183 
#define  FCC_O 182 
#define  FCC_U 181 
#define  FCC_UE 180 
#define  FCC_UG 179 
#define  FCC_UGE 178 
#define  FCC_UL 177 
#define  FCC_ULE 176 
 scalar_t__ GPR_G0 ; 
 int GPR_I7 ; 
 scalar_t__ GPR_O7 ; 
#define  ICC_A 175 
#define  ICC_CC 174 
#define  ICC_CS 173 
#define  ICC_E 172 
#define  ICC_G 171 
#define  ICC_GE 170 
#define  ICC_GU 169 
#define  ICC_L 168 
#define  ICC_LE 167 
#define  ICC_LEU 166 
#define  ICC_N 165 
#define  ICC_NE 164 
#define  ICC_NEG 163 
#define  ICC_POS 162 
#define  ICC_VC 161 
#define  ICC_VS 160 
#define  OP2_BPcc 159 
#define  OP2_BPr 158 
#define  OP2_Bicc 157 
#define  OP2_FBPfcc 156 
#define  OP2_FBfcc 155 
#define  OP2_ILLTRAP 154 
#define  OP2_INV 153 
#define  OP32_CONDINV1 152 
#define  OP32_CONDINV2 151 
#define  OP32_CONDINV3 150 
#define  OP32_INV1 149 
#define  OP32_INV2 148 
#define  OP32_INV3 147 
#define  OP32_INV4 146 
#define  OP32_INV5 145 
#define  OP32_JMPL 144 
#define  OP33_INV1 143 
#define  OP33_INV10 142 
#define  OP33_INV11 141 
#define  OP33_INV12 140 
#define  OP33_INV13 139 
#define  OP33_INV14 138 
#define  OP33_INV15 137 
#define  OP33_INV16 136 
#define  OP33_INV2 135 
#define  OP33_INV3 134 
#define  OP33_INV4 133 
#define  OP33_INV5 132 
#define  OP33_INV6 131 
#define  OP33_INV7 130 
#define  OP33_INV8 129 
#define  OP33_INV9 128 
 scalar_t__ OP_0 ; 
 scalar_t__ OP_1 ; 
 scalar_t__ OP_2 ; 
 scalar_t__ OP_3 ; 
 int R_ANAL_COND_ALWAYS ; 
 int R_ANAL_COND_EQ ; 
 int R_ANAL_COND_GE ; 
 int R_ANAL_COND_GT ; 
 int R_ANAL_COND_LE ; 
 int R_ANAL_COND_LT ; 
 int R_ANAL_COND_NE ; 
 int R_ANAL_COND_NEVER ; 
 int R_ANAL_COND_UNKNOWN ; 
 int /*<<< orphan*/  R_ANAL_OP_FAMILY_CPU ; 
 void* R_ANAL_OP_TYPE_CALL ; 
 void* R_ANAL_OP_TYPE_CJMP ; 
 void* R_ANAL_OP_TYPE_ILL ; 
 void* R_ANAL_OP_TYPE_JMP ; 
 void* R_ANAL_OP_TYPE_NOP ; 
 void* R_ANAL_OP_TYPE_RET ; 
 void* R_ANAL_OP_TYPE_UCALL ; 
 void* R_ANAL_OP_TYPE_UJMP ; 
 int /*<<< orphan*/  R_REG_TYPE_GPR ; 
 int X_COND (int const) ; 
 int X_DISP16 (int const) ; 
 int X_LDST_I (int const) ; 
 scalar_t__ X_OP (int const) ; 
 int X_OP2 (int const) ; 
 int X_OP3 (int const) ; 
 int X_RD (int const) ; 
 int X_RS1 (int const) ; 
 int X_RS2 (int const) ; 
 int /*<<< orphan*/ * gpr_regs ; 
 int /*<<< orphan*/  memcpy (int const*,int const*,int) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* r_anal_value_new () ; 
 void* r_reg_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int r_reg_set_profile_string (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static int icc_to_r_cond(const int cond) {
	/* we treat signed and unsigned the same here */
	switch(cond) {
	case ICC_A: return R_ANAL_COND_ALWAYS;
	case ICC_CC: return R_ANAL_COND_GE;
	case ICC_CS: return R_ANAL_COND_LT;
	case ICC_E: return R_ANAL_COND_EQ;
	case ICC_G: return R_ANAL_COND_GT;
	case ICC_GE: return R_ANAL_COND_GE;
	case ICC_GU: return R_ANAL_COND_GT;
	case ICC_L: return R_ANAL_COND_LT;
	case ICC_LE: return R_ANAL_COND_LE;
	case ICC_LEU: return R_ANAL_COND_LE;
	case ICC_N: return R_ANAL_COND_NEVER;
	case ICC_NE: return R_ANAL_COND_NE;
	case ICC_NEG:
	case ICC_POS:
	case ICC_VC:
	case ICC_VS:
	default: return R_ANAL_COND_UNKNOWN;
	}
}

__attribute__((used)) static int fcc_to_r_cond(const int cond) {
	switch (cond) {
	case FCC_A: return R_ANAL_COND_ALWAYS;
	case FCC_E: return R_ANAL_COND_EQ;
	case FCC_G: return R_ANAL_COND_GT;
	case FCC_GE: return R_ANAL_COND_GE;
	case FCC_L: return R_ANAL_COND_LT;
	case FCC_LE: return R_ANAL_COND_LE;
	case FCC_LG: return R_ANAL_COND_NE;
	case FCC_N: return R_ANAL_COND_NEVER;
	case FCC_NE: return R_ANAL_COND_NE;
	case FCC_O:
	case FCC_U:
	case FCC_UE:
	case FCC_UG:
	case FCC_UGE:
	case FCC_UL:
	case FCC_ULE:
	default:
		return R_ANAL_COND_UNKNOWN;
	}
}

__attribute__((used)) static st64 get_immed_sgnext(const ut64 insn, const ut8 nbit) {
	const ut64 mask = ~(((ut64)1 << (nbit + 1)) - 1);
	return (st64) ((insn & ~mask)
		| (((insn & ((ut64)1 << nbit)) >> nbit) * mask));
}

__attribute__((used)) static RAnalValue * value_fill_addr_pc_disp(const ut64 addr, const st64 disp) {
	RAnalValue *val = r_anal_value_new();
	val->base = addr + disp;
	return val;
}

__attribute__((used)) static RAnalValue * value_fill_addr_reg_regdelta(RAnal const * const anal, const int ireg, const int iregdelta) {
	RAnalValue *val = r_anal_value_new();
	val->reg = r_reg_get(anal->reg, gpr_regs[ireg], R_REG_TYPE_GPR);
	val->reg = r_reg_get(anal->reg, gpr_regs[iregdelta], R_REG_TYPE_GPR);
	return val;
}

__attribute__((used)) static RAnalValue * value_fill_addr_reg_disp(RAnal const * const anal, const int ireg, const st64 disp) {
	RAnalValue *val = r_anal_value_new();
	val->reg = r_reg_get(anal->reg, gpr_regs[ireg], R_REG_TYPE_GPR);
	val->delta = disp;
	return val;
}

__attribute__((used)) static void anal_call(RAnalOp *op, const ut32 insn, const ut64 addr) {
	const st64 disp = (get_immed_sgnext(insn, 29) * 4);
	op->type = R_ANAL_OP_TYPE_CALL;
	op->dst = value_fill_addr_pc_disp(addr, disp);
	op->jump = addr + disp;
	op->fail = addr + 4;
}

__attribute__((used)) static void anal_jmpl(RAnal const * const anal, RAnalOp *op, const ut32 insn, const ut64 addr) {
	st64 disp = 0;
	if (X_LDST_I (insn)) {
		disp = get_immed_sgnext (insn, 12);
	}

	if (X_RD(insn) == GPR_O7) {
		op->type = R_ANAL_OP_TYPE_UCALL;
		op->fail = addr + 4;
	} else if (X_RD(insn) == GPR_G0
		&& X_LDST_I(insn) == 1
		&& (X_RS1(insn) == GPR_I7 || X_RS1(insn) == GPR_O7)
		&& disp == 8) {
			op->type = R_ANAL_OP_TYPE_RET;
			op->eob = true;
			return;
		 }
	else {
		op->type = R_ANAL_OP_TYPE_UJMP;
		op->eob = true;
	}

	if(X_LDST_I(insn)) {
		op->dst = value_fill_addr_reg_disp(anal, X_RS1(insn), disp);
	} else {
		op->dst = value_fill_addr_reg_regdelta(anal, X_RS1(insn), X_RS2(insn));
	}
}

__attribute__((used)) static void anal_branch(RAnalOp *op, const ut32 insn, const ut64 addr) {
	st64 disp = 0;
	int r_cond = 0;
	op->eob = true;

	/* handle the conditions */
	if(X_OP2(insn) == OP2_Bicc || X_OP2(insn) == OP2_BPcc) {
		r_cond = icc_to_r_cond (X_COND(insn));
	} else if(X_OP2(insn) == OP2_FBfcc || X_OP2(insn) == OP2_FBPfcc) {
		r_cond = fcc_to_r_cond (X_COND(insn));
	} else if(X_OP2(insn) == OP2_BPr) {
		r_cond = R_ANAL_COND_UNKNOWN;
	}

	if (r_cond == R_ANAL_COND_ALWAYS) {
		op->type = R_ANAL_OP_TYPE_JMP;
	} else if (r_cond == R_ANAL_COND_NEVER) {
		op->type = R_ANAL_OP_TYPE_NOP;
		return;
	} else {
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->fail = addr + 4;
	}


	/* handle displacement */
	if (X_OP2 (insn) == OP2_Bicc || X_OP2 (insn) == OP2_FBfcc) {
		disp = get_immed_sgnext(insn, 21) * 4;
	} else if (X_OP2(insn) == OP2_BPcc || X_OP2 (insn) == OP2_FBPfcc) {
		disp = get_immed_sgnext (insn, 18) * 4;
	} else if (X_OP2(insn) == OP2_BPr) {
		disp = get_immed_sgnext (X_DISP16 (insn), 15) * 4;
	}
	op->dst = value_fill_addr_pc_disp (addr, disp);
	op->jump = addr + disp;
}

__attribute__((used)) static int sparc_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *data, int len, RAnalOpMask mask) {
	int sz = 4;
	ut32 insn;

	memset (op, 0, sizeof (RAnalOp));
	op->family = R_ANAL_OP_FAMILY_CPU;
	op->addr = addr;
	op->size = sz;
	op->jump = op->fail = -1;
	op->ptr = op->val = -1;

	if(!anal->big_endian) {
		((char*)&insn)[0] = data[3];
		((char*)&insn)[1] = data[2];
		((char*)&insn)[2] = data[1];
		((char*)&insn)[3] = data[0];
	} else {
		memcpy(&insn, data, sz);
	}

	if (X_OP(insn) == OP_0) {
		switch(X_OP2(insn)) {
		case OP2_ILLTRAP:
		case OP2_INV:
			op->type = R_ANAL_OP_TYPE_ILL;
			sz = 0; /* make r_core_anal_bb stop */
			break;
		case OP2_BPcc:
		case OP2_Bicc:
		case OP2_BPr:
		case OP2_FBPfcc:
		case OP2_FBfcc:
			anal_branch(op, insn, addr);
			break;
		}
	} else if(X_OP(insn) == OP_1) {
		anal_call(op, insn, addr);
	} else if(X_OP(insn) == OP_2) {
		switch(X_OP3(insn))
		 {
		case OP32_INV1:
		case OP32_INV2:
		case OP32_INV3:
		case OP32_INV4:
		case OP32_INV5:
			op->type = R_ANAL_OP_TYPE_ILL;
			sz = 0; /* make r_core_anal_bb stop */
			break;
		case OP32_CONDINV1:
			if(X_RD(insn) == 1) {
				op->type = R_ANAL_OP_TYPE_ILL;
				sz = 0; /* make r_core_anal_bb stop */
			}
			break;
		case OP32_CONDINV2:
			if(X_RS1(insn) == 1) {
				op->type = R_ANAL_OP_TYPE_ILL;
				sz = 0; /* make r_core_anal_bb stop */
			}
			break;
		case OP32_CONDINV3:
			if(X_RS1(insn) != 0) {
				op->type = R_ANAL_OP_TYPE_ILL;
				sz = 0; /* make r_core_anal_bb stop */
			}
			break;

		case OP32_JMPL:
			anal_jmpl(anal, op, insn, addr);
			break;
		 }
	} else if (X_OP(insn) == OP_3) {
		switch(X_OP3(insn)) {
		case OP33_INV1:
		case OP33_INV2:
		case OP33_INV3:
		case OP33_INV4:
		case OP33_INV5:
		case OP33_INV6:
		case OP33_INV7:
		case OP33_INV8:
		case OP33_INV9:
		case OP33_INV10:
		case OP33_INV11:
		case OP33_INV12:
		case OP33_INV13:
		case OP33_INV14:
		case OP33_INV15:
		case OP33_INV16:
			op->type = R_ANAL_OP_TYPE_ILL;
			sz = 0; /* make r_core_anal_bb stop */
			break;
		 }
	}

	return sz;
}

__attribute__((used)) static int set_reg_profile(RAnal *anal) {
	/* As far as I can see, sparc v9 register and instruction set
	   don't depened  on bits of the running application.
	   But: They depend on the bits of the consuming application,
	   that is the bits radare had been compiled with.
	   See sys/procfs_isa.h on a Solaris10 Sparc machine and
	   'man 4 core' for reference.
	 */
	const char *p =
	"=PC	pc\n"
	"=SP	o6\n"
	"=BP	i6\n"
	/* prgregset_t for _LP64 */
	"gpr	g0	.64	0	0\n"
	"gpr	g1	.64	8	0\n"
	"gpr	g2	.64	16	0\n"
	"gpr	g3	.64	24	0\n"
	"gpr	g4	.64	32	0\n"
	"gpr	g5	.64	40	0\n"
	"gpr	g6	.64	48	0\n"
	"gpr	g7	.64	56	0\n"
	"gpr	o0	.64	64	0\n"
	"gpr	o1	.64	72	0\n"
	"gpr	o2	.64	80	0\n"
	"gpr	o3	.64	88	0\n"
	"gpr	o4	.64	96	0\n"
	"gpr	o5	.64	104	0\n"
	"gpr	o6	.64	112	0\n"
	"gpr	o7	.64	120	0\n"
	"gpr	l0	.64	128	0\n"
	"gpr	l1	.64	136	0\n"
	"gpr	l2	.64	144	0\n"
	"gpr	l3	.64	152	0\n"
	"gpr	l4	.64	160	0\n"
	"gpr	l5	.64	168	0\n"
	"gpr	l6	.64	176	0\n"
	"gpr	l7	.64	184	0\n"
	"gpr	i0	.64	192	0\n"
	"gpr	i1	.64	200	0\n"
	"gpr	i2	.64	208	0\n"
	"gpr	i3	.64	216	0\n"
	"gpr	i4	.64	224	0\n"
	"gpr	i5	.64	232	0\n"
	"gpr	i6	.64	240	0\n"
	"gpr	i7	.64	248	0\n"
	"gpr	ccr	.64	256	0\n"
	"gpr	pc	.64	264	0\n"
	"gpr	ncp	.64	272	0\n"
	"gpr	y	.64	280	0\n"
	"gpr	asi	.64	288	0\n"
	"gpr	fprs	.64	296	0\n"
	/* beginning of prfpregset_t for __sparcv9 */
	"fpu	sf0	.32	304	0\n"
	"fpu	sf1	.32	308	0\n"
	"fpu	sf2	.32	312	0\n"
	"fpu	sf3	.32	316	0\n"
	"fpu	sf4	.32	320	0\n"
	"fpu	sf5	.32	324	0\n"
	"fpu	sf6	.32	328	0\n"
	"fpu	sf7	.32	332	0\n"
	"fpu	sf8	.32	336	0\n"
	"fpu	sf9	.32	340	0\n"
	"fpu	sf10	.32	344	0\n"
	"fpu	sf11	.32	348	0\n"
	"fpu	sf12	.32	352	0\n"
	"fpu	sf13	.32	356	0\n"
	"fpu	sf14	.32	360	0\n"
	"fpu	sf15	.32	364	0\n"
	"fpu	sf16	.32	368	0\n"
	"fpu	sf17	.32	372	0\n"
	"fpu	sf18	.32	376	0\n"
	"fpu	sf19	.32	380	0\n"
	"fpu	sf20	.32	384	0\n"
	"fpu	sf21	.32	388	0\n"
	"fpu	sf22	.32	392	0\n"
	"fpu	sf23	.32	396	0\n"
	"fpu	sf24	.32	400	0\n"
	"fpu	sf25	.32	404	0\n"
	"fpu	sf26	.32	408	0\n"
	"fpu	sf27	.32	412	0\n"
	"fpu	sf28	.32	416	0\n"
	"fpu	sf29	.32	420	0\n"
	"fpu	sf30	.32	424	0\n"
	"fpu	sf31	.32	428	0\n"
	"fpu	df0	.64	304	0\n"	/* sf0 sf1 */
	"fpu	df2	.64	312	0\n"	/* sf2 sf3 */
	"fpu	df4	.64	320	0\n"	/* sf4 sf5 */
	"fpu	df6	.64	328	0\n"	/* sf6 sf7 */
	"fpu	df8	.64	336	0\n"	/* sf8 sf9 */
	"fpu	df10	.64	344	0\n"	/* sf10 sf11 */
	"fpu	df12	.64	352	0\n"	/* sf12 sf13 */
	"fpu	df14	.64	360	0\n"	/* sf14 sf15 */
	"fpu	df16	.64	368	0\n"	/* sf16 sf17 */
	"fpu	df18	.64	376	0\n"	/* sf18 sf19 */
	"fpu	df20	.64	384	0\n"	/* sf20 sf21 */
	"fpu	df22	.64	392	0\n"	/* sf22 sf23 */
	"fpu	df24	.64	400	0\n"	/* sf24 sf25 */
	"fpu	df26	.64	408	0\n"	/* sf26 sf27 */
	"fpu	df28	.64	416	0\n"	/* sf28 sf29 */
	"fpu	df30	.64	424	0\n"	/* sf30 sf31 */
	"fpu	df32	.64	432	0\n"
	"fpu	df34	.64	440	0\n"
	"fpu	df36	.64	448	0\n"
	"fpu	df38	.64	456	0\n"
	"fpu	df40	.64	464	0\n"
	"fpu	df42	.64	472	0\n"
	"fpu	df44	.64	480	0\n"
	"fpu	df46	.64	488	0\n"
	"fpu	df48	.64	496	0\n"
	"fpu	df50	.64	504	0\n"
	"fpu	df52	.64	512	0\n"
	"fpu	df54	.64	520	0\n"
	"fpu	df56	.64	528	0\n"
	"fpu	df58	.64	536	0\n"
	"fpu	df60	.64	544	0\n"
	"fpu	df62	.64	552	0\n"
	"fpu	qf0	.128	304	0\n"	/* sf0 sf1 sf2 sf3 */
	"fpu	qf4	.128	320	0\n"	/* sf4 sf5 sf6 sf7 */
	"fpu	qf8	.128	336	0\n"	/* sf8 sf9 sf10 sf11 */
	"fpu	qf12	.128	352	0\n"	/* sf12 sf13 sf14 sf15 */
	"fpu	qf16	.128	368	0\n"	/* sf16 sf17 sf18 sf19 */
	"fpu	qf20	.128	384	0\n"	/* sf20 sf21 sf22 sf23 */
	"fpu	qf24	.128	400	0\n"	/* sf24 sf25 sf26 sf27 */
	"fpu	qf28	.128	416	0\n"	/* sf28 sf29 sf30 sf31 */
	"fpu	qf32	.128	432	0\n"	/* df32 df34 */
	"fpu	qf36	.128	448	0\n"	/* df36 df38 */
	"fpu	qf40	.128	464	0\n"	/* df40 df42 */
	"fpu	qf44	.128	480	0\n"	/* df44 df46 */
	"fpu	qf48	.128	496	0\n"	/* df48 df50 */
	"fpu	qf52	.128	512	0\n"	/* df52 df54 */
	"fpu	qf56	.128	528	0\n"	/* df56 df68 */
	"fpu	qf60	.128	544	0\n"	/* df60 df62 */
	"gpr	fsr	.64	560	0\n";	/* note that
						   we've left out the filler */
	return r_reg_set_profile_string (anal->reg, p);
}

__attribute__((used)) static int archinfo(RAnal *anal, int q) {
	return 4; /* :D */
}

