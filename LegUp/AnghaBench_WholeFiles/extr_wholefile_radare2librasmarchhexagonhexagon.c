#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_5__ {int imm; } ;
struct TYPE_6__ {scalar_t__ type; TYPE_1__ op; } ;
typedef  TYPE_2__ HexOp ;

/* Variables and functions */
 scalar_t__ HEX_OP_TYPE_IMM ; 
#define  HEX_REG_BADVA 213 
#define  HEX_REG_BADVA0 212 
#define  HEX_REG_BADVA1 211 
#define  HEX_REG_BRKPTCFG0 210 
#define  HEX_REG_BRKPTCFG1 209 
#define  HEX_REG_BRKPTPC0 208 
#define  HEX_REG_BRKPTPC1 207 
#define  HEX_REG_CCR 206 
#define  HEX_REG_CFGBASE 205 
#define  HEX_REG_CS0 204 
#define  HEX_REG_CS1 203 
#define  HEX_REG_DIAG 202 
#define  HEX_REG_ELR 201 
#define  HEX_REG_EVB 200 
#define  HEX_REG_FRAMEKEY 199 
#define  HEX_REG_FRAMELIMIT 198 
#define  HEX_REG_GP 197 
#define  HEX_REG_HTID 196 
#define  HEX_REG_IAD 195 
#define  HEX_REG_IAHL 194 
#define  HEX_REG_IEL 193 
#define  HEX_REG_IMASK 192 
#define  HEX_REG_IPEND 191 
#define  HEX_REG_ISDBCFG0 190 
#define  HEX_REG_ISDBCFG1 189 
#define  HEX_REG_ISDBEN 188 
#define  HEX_REG_ISDBGPR 187 
#define  HEX_REG_ISDBMBXIN 186 
#define  HEX_REG_ISDBMBXOUT 185 
#define  HEX_REG_ISDBST 184 
#define  HEX_REG_LC0 183 
#define  HEX_REG_LC1 182 
#define  HEX_REG_M0 181 
#define  HEX_REG_M1 180 
#define  HEX_REG_MODECTL 179 
#define  HEX_REG_P 178 
#define  HEX_REG_PC 177 
#define  HEX_REG_PCYCLEHI 176 
#define  HEX_REG_PCYCLELO 175 
#define  HEX_REG_PKTCOUNTHI 174 
#define  HEX_REG_PKTCOUNTLO 173 
#define  HEX_REG_PMUCFG 172 
#define  HEX_REG_PMUCNT0 171 
#define  HEX_REG_PMUCNT1 170 
#define  HEX_REG_PMUCNT2 169 
#define  HEX_REG_PMUCNT3 168 
#define  HEX_REG_PMUEVTCFG 167 
#define  HEX_REG_REV 166 
#define  HEX_REG_SA0 165 
#define  HEX_REG_SA1 164 
#define  HEX_REG_SGP0 163 
#define  HEX_REG_SGP1 162 
#define  HEX_REG_SSR 161 
#define  HEX_REG_STID 160 
#define  HEX_REG_SYSCFG 159 
#define  HEX_REG_UGP 158 
#define  HEX_REG_UPCYCLEHI 157 
#define  HEX_REG_UPCYCLELO 156 
#define  HEX_REG_USR 155 
#define  HEX_REG_UTIMERHI 154 
#define  HEX_REG_UTIMERLO 153 
#define  HEX_REG_VID 152 
#define  HEX_SUB_REGPAIR_R17_R16 151 
#define  HEX_SUB_REGPAIR_R19_R18 150 
#define  HEX_SUB_REGPAIR_R1_R0 149 
#define  HEX_SUB_REGPAIR_R21_R20 148 
#define  HEX_SUB_REGPAIR_R23_R22 147 
#define  HEX_SUB_REGPAIR_R3_R2 146 
#define  HEX_SUB_REGPAIR_R5_R4 145 
#define  HEX_SUB_REGPAIR_R7_R6 144 
#define  HEX_SUB_REG_R0 143 
#define  HEX_SUB_REG_R1 142 
#define  HEX_SUB_REG_R16 141 
#define  HEX_SUB_REG_R17 140 
#define  HEX_SUB_REG_R18 139 
#define  HEX_SUB_REG_R19 138 
#define  HEX_SUB_REG_R2 137 
#define  HEX_SUB_REG_R20 136 
#define  HEX_SUB_REG_R21 135 
#define  HEX_SUB_REG_R22 134 
#define  HEX_SUB_REG_R23 133 
#define  HEX_SUB_REG_R3 132 
#define  HEX_SUB_REG_R4 131 
#define  HEX_SUB_REG_R5 130 
#define  HEX_SUB_REG_R6 129 
#define  HEX_SUB_REG_R7 128 
 int constant_extender ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

char* hex_get_cntl_reg(int opreg){
	switch (opreg) {
		case HEX_REG_SA0:
			return "SA0";
		case HEX_REG_LC0:
			return "LC0";
		case HEX_REG_SA1:
			return "SA1";
		case HEX_REG_LC1:
			return "LC1";
		case HEX_REG_P:
			return "P";
		case HEX_REG_M0:
			return "M0";
		case HEX_REG_M1:
			return "M1";
		case HEX_REG_USR:
			return "USR";
		case HEX_REG_PC:
			return "PC";
		case HEX_REG_UGP:
			return "UGP";
		case HEX_REG_GP:
			return "GP";
		case HEX_REG_CS0:
			return "CS0";
		case HEX_REG_CS1:
			return "CS1";
		case HEX_REG_UPCYCLELO:
			return "UPCYCLELO";
		case HEX_REG_UPCYCLEHI:
			return "UPCYCLEHI";
		case HEX_REG_FRAMELIMIT:
			return "FRAMELIMIT";
		case HEX_REG_FRAMEKEY:
			return "FRAMEKEY";
		case HEX_REG_PKTCOUNTLO:
			return "PKTCOUNTLO";
		case HEX_REG_PKTCOUNTHI:
			return "PKTCOUNTHI";
		case HEX_REG_UTIMERLO:
			return "UTIMERLO";
		case HEX_REG_UTIMERHI:
			return "UTIMERHI";
		default:
			return "<CRerr>";
	}
}

char* hex_get_sys_reg(int opreg)
{
	static char tmp[5];
	switch (opreg) {
		case HEX_REG_SGP0:
			return "SGP0";
		case HEX_REG_SGP1:
			return "SGP1";
		case HEX_REG_STID:
			return "STID";
		case HEX_REG_ELR:
			return "ELR";
		case HEX_REG_BADVA0:
			return "BADVA0";
		case HEX_REG_BADVA1:
			return "BADVA1";
		case HEX_REG_SSR:
			return "SSR";
		case HEX_REG_CCR:
			return "CCR";
		case HEX_REG_HTID:
			return "HTID";
		case HEX_REG_BADVA:
			return "BADVA";
		case HEX_REG_IMASK:
			return "IMASK";
		case HEX_REG_EVB:
			return "EVB";
		case HEX_REG_MODECTL:
			return "MODECTL";
		case HEX_REG_SYSCFG:
			return "SYSCFG";
		case HEX_REG_IPEND:
			return "IPEND";
		case HEX_REG_VID:
			return "VID";
		case HEX_REG_IAD:
			return "IAD";
		case HEX_REG_IEL:
			return "IEL";
		case HEX_REG_IAHL:
			return "IAHL";
		case HEX_REG_CFGBASE:
			return "CFGBASE";
		case HEX_REG_DIAG:
			return "DIAG";
		case HEX_REG_REV:
			return "REV";
		case HEX_REG_PCYCLELO:
			return "PCYCLELO";
		case HEX_REG_PCYCLEHI:
			return "PCYCLEHI";
		case HEX_REG_ISDBST:
			return "ISDBST";
		case HEX_REG_ISDBCFG0:
			return "ISDBCFG0";
		case HEX_REG_ISDBCFG1:
			return "ISDBCFG1";
		case HEX_REG_BRKPTPC0:
			return "BRKPTPC0";
		case HEX_REG_BRKPTCFG0:
			return "BRKPTCFG0";
		case HEX_REG_BRKPTPC1:
			return "BRKPTPC1";
		case HEX_REG_BRKPTCFG1:
			return "BRKPTCFG1";
		case HEX_REG_ISDBMBXIN:
			return "ISDBMBXIN";
		case HEX_REG_ISDBMBXOUT:
			return "ISDBMBXOUT";
		case HEX_REG_ISDBEN:
			return "ISDBEN";
		case HEX_REG_ISDBGPR:
			return "ISDBGPR";
		case HEX_REG_PMUCNT0:
			return "PMUCNT0";
		case HEX_REG_PMUCNT1:
			return "PMUCNT1";
		case HEX_REG_PMUCNT2:
			return "PMUCNT2";
		case HEX_REG_PMUCNT3:
			return "PMUCNT3";
		case HEX_REG_PMUEVTCFG:
			return "PMUEVTCFG";
		case HEX_REG_PMUCFG:
			return "PMUCFG";
		default:
			sprintf(tmp, "S%d", opreg);
			return tmp;
	}
}

char* hex_get_sub_reg(int opreg)
{
	switch (opreg) {
		case HEX_SUB_REG_R0:
			return "R0";
		case HEX_SUB_REG_R1:
			return "R1";
		case HEX_SUB_REG_R2:
			return "R2";
		case HEX_SUB_REG_R3:
			return "R3";
		case HEX_SUB_REG_R4:
			return "R4";
		case HEX_SUB_REG_R5:
			return "R5";
		case HEX_SUB_REG_R6:
			return "R6";
		case HEX_SUB_REG_R7:
			return "R7";
		case HEX_SUB_REG_R16:
			return "R16";
		case HEX_SUB_REG_R17:
			return "R17";
		case HEX_SUB_REG_R18:
			return "R18";
		case HEX_SUB_REG_R19:
			return "R19";
		case HEX_SUB_REG_R20:
			return "R20";
		case HEX_SUB_REG_R21:
			return "R21";
		case HEX_SUB_REG_R22:
			return "R22";
		case HEX_SUB_REG_R23:
			return "R23";
		default:
			return "<err>";
	}
}

char* hex_get_sub_regpair(int opreg)
{
	switch (opreg) {
		case HEX_SUB_REGPAIR_R1_R0:
			return "R1:R0";
		case HEX_SUB_REGPAIR_R3_R2:
			return "R3:R2";
		case HEX_SUB_REGPAIR_R5_R4:
			return "R5:R4";
		case HEX_SUB_REGPAIR_R7_R6:
			return "R7:R6";
		case HEX_SUB_REGPAIR_R17_R16:
			return "R17:R16";
		case HEX_SUB_REGPAIR_R19_R18:
			return "R19:R18";
		case HEX_SUB_REGPAIR_R21_R20:
			return "R21:R20";
		case HEX_SUB_REGPAIR_R23_R22:
			return "R23:R22";
		default:
			return "<err>";
	}
}

inline bool hex_if_duplex(uint32_t insn_word)
{
	if ((insn_word & (3 << 14)) == 0) {
		return true;
	}
	return false;
}

void hex_op_extend(HexOp *op)
{
	if ((constant_extender != 1) && (op->type == HEX_OP_TYPE_IMM)) {
		op->op.imm = ((op->op.imm) & 0x3F) | (constant_extender);
	}
	constant_extender = 1;
}

void hex_op_extend_off(HexOp *op, int offset)
{
	if ((constant_extender != 1) && (op->type == HEX_OP_TYPE_IMM)) {
		op->op.imm = (op->op.imm) >> offset;
		hex_op_extend(op);
	}
}

