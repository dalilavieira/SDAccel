#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int ut8 ;
typedef  int ut32 ;
typedef  int ut16 ;
struct propeller_cmd {char* instr; char* operands; char* prefix; int dst; int src; int immed; int opcode; } ;

/* Variables and functions */
#define  PROP_ABS 194 
#define  PROP_ABSNEG 193 
#define  PROP_ADD 192 
#define  PROP_ADDABS 191 
#define  PROP_ADDS 190 
#define  PROP_ADDSX 189 
#define  PROP_ADDX 188 
#define  PROP_AND 187 
#define  PROP_ANDN 186 
#define  PROP_CLKSET 185 
#define  PROP_CMP 184 
#define  PROP_CMPS 183 
#define  PROP_CMPSUB 182 
#define  PROP_CMPSX 181 
#define  PROP_CMPX 180 
#define  PROP_COGID 179 
#define  PROP_COGINIT 178 
#define  PROP_COGSTOP 177 
#define  PROP_DJNZ 176 
#define  PROP_HUBOP 175 
 int PROP_INSTR_MAXLEN ; 
#define  PROP_JMP 174 
#define  PROP_LOCKCLR 173 
#define  PROP_LOCKNEW 172 
#define  PROP_LOCKRET 171 
#define  PROP_LOCKSET 170 
#define  PROP_MAX 169 
#define  PROP_MAXS 168 
#define  PROP_MIN 167 
#define  PROP_MINS 166 
#define  PROP_MOV 165 
#define  PROP_MOVD 164 
#define  PROP_MOVI 163 
#define  PROP_MOVS 162 
#define  PROP_MUXC 161 
#define  PROP_MUXNC 160 
#define  PROP_MUXNZ 159 
#define  PROP_MUXZ 158 
#define  PROP_NEG 157 
#define  PROP_NEGC 156 
#define  PROP_NEGNC 155 
#define  PROP_NEGNZ 154 
#define  PROP_NEGZ 153 
#define  PROP_OR 152 
#define  PROP_RCL 151 
#define  PROP_RCR 150 
#define  PROP_RDBYTE 149 
#define  PROP_RDLONG 148 
#define  PROP_RDWORD 147 
#define  PROP_REV 146 
#define  PROP_ROL 145 
#define  PROP_ROR 144 
#define  PROP_SAR 143 
#define  PROP_SHL 142 
#define  PROP_SHR 141 
 int PROP_SUB ; 
#define  PROP_SUBABS 140 
#define  PROP_SUBS 139 
#define  PROP_SUBSX 138 
 int PROP_SUBX ; 
#define  PROP_SUMC 137 
#define  PROP_SUMNC 136 
#define  PROP_SUMNZ 135 
#define  PROP_SUMZ 134 
#define  PROP_TJZ 133 
#define  PROP_WAITCNT 132 
#define  PROP_WAITPEQ 131 
#define  PROP_WAITPNE 130 
#define  PROP_WAITVID 129 
#define  PROP_XOR 128 
 char** conditions ; 
 char** ext_instrs ; 
 char** instrs ; 
 int r_read_be32 (int const*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,...) ; 

__attribute__((used)) static ut16 get_opcode (ut32 instr) {
	return instr >> 26;
}

__attribute__((used)) static ut16 get_opcode_ext (ut32 instr) {
	return (instr & 0x7) | (instr >> 23);
}

__attribute__((used)) static ut16 get_src (ut32 instr) {
	return instr & 0x1FF;
}

__attribute__((used)) static ut16 get_dst (ut32 instr) {
	return ((instr >> 9) & 0x1FF) << 2;
}

__attribute__((used)) static int is_immediate (ut32 instr) {
	return instr & 0x00400000;
}

__attribute__((used)) static int decode_ext_cmd (struct propeller_cmd *cmd, ut32 instr) {
	ut16 opcode;

	opcode = get_opcode_ext (instr);

	switch (opcode) {
		case PROP_CLKSET:
		case PROP_COGID:
		case PROP_COGINIT:
		case PROP_COGSTOP:
		case PROP_LOCKCLR:
		case PROP_LOCKNEW:
		case PROP_LOCKRET:
		case PROP_LOCKSET:
			snprintf (cmd->instr, PROP_INSTR_MAXLEN - 1,
					"%s", ext_instrs[PROP_CLKSET]);
			snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1,
					"%d", get_dst (instr));
			return 4;
			break;
	}

	return -1;
}

__attribute__((used)) static ut8 get_zcri (ut32 instr) {
	return (instr >> 22) & 0xf;
}

__attribute__((used)) static ut8 get_con (ut32 instr) {
	return (instr >> 18) & 0xf;
}

__attribute__((used)) static void decode_prefix (struct propeller_cmd *cmd, ut32 instr) {
	ut8 prefix = (instr >> 18) & 0xF;

	snprintf (cmd->prefix, 15, "%s", conditions[prefix]);
	cmd->prefix[15] = '\0';
}

__attribute__((used)) static int decode_jmp (struct propeller_cmd *cmd, ut32 instr) {
	ut16 opcode;
	ut8 zcri;
	int ret = 1;
	opcode = get_opcode (instr);
	switch (opcode) {
		case PROP_JMP:
			zcri = get_zcri (instr);
			if (zcri & 0x2) {
				snprintf (cmd->instr, PROP_INSTR_MAXLEN - 1,
						"%s", "jmpret");
				if (zcri & 1) {
					cmd->dst = get_dst (instr) << 2;
					cmd->src = get_src (instr) << 2;

					snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1,
							"0x%x, #0x%x", get_dst (instr), get_src (instr) << 2);
				} else {
					cmd->src = get_src (instr) << 2;
					cmd->dst = get_dst (instr) << 2;
					snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1,
							"0x%x, 0x%x", get_dst (instr), get_src (instr) << 2);
				}
			} else {
				snprintf (cmd->instr, PROP_INSTR_MAXLEN - 1,
						"%s", "jmp");
				if (zcri & 1) {
					cmd->src = get_src (instr) << 2;
					cmd->immed = 1;
					snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1,
							"#0x%x", get_src (instr) << 2);
				} else {
					cmd->immed = 0;
					cmd->src = get_src (instr) << 2; 
					snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1,
							"0x%x", get_src (instr) << 2);
				}
			}

			ret = 4;
			break;
	}


	return ret;
}

int propeller_decode_command(const ut8 *instr, struct propeller_cmd *cmd)
{
	int ret = -1;
	ut32 in;
	ut16 opcode;

	in = r_read_be32 (instr);

	opcode = get_opcode (in);

	if (!get_con (in)) {
		snprintf (cmd->instr, PROP_INSTR_MAXLEN, "nop");
		cmd->operands[0] = '\0';
		return 4;
	}

	switch (opcode) {
		case PROP_ABS:
		case PROP_ABSNEG:
		case PROP_ADD:
		case PROP_ADDABS:
		case PROP_ADDS:
		case PROP_ADDSX:
		case PROP_ADDX:
		case PROP_AND:
		case PROP_ANDN:
		case PROP_CMP:
		case PROP_CMPS:
		case PROP_CMPSUB:
		case PROP_CMPSX:
		case PROP_CMPX:
		case PROP_DJNZ:
		case PROP_MAX:
		case PROP_MAXS:
		case PROP_MIN:
		case PROP_MINS:
		case PROP_MOV:
		case PROP_MOVD:
		case PROP_MOVI:
		case PROP_MOVS:
		case PROP_MUXC:
		case PROP_MUXNC:
		case PROP_MUXNZ:
		case PROP_MUXZ:
		case PROP_NEG:
		case PROP_NEGC:
		case PROP_NEGNC:
		case PROP_NEGNZ:
		case PROP_NEGZ:
		case PROP_OR:
		case PROP_RCL:
		case PROP_RCR:
		case PROP_RDBYTE:
		case PROP_RDLONG:
		case PROP_RDWORD:
			//case PROP_RET:
		case PROP_REV:
		case PROP_ROL:
		case PROP_ROR:
		case PROP_SAR:
		case PROP_SHL:
		case PROP_SHR:
		case PROP_SUBABS:
		case PROP_SUBS:
		case PROP_SUBSX:
			//case PROP_SUBX:
		case PROP_SUMC:
		case PROP_SUMNC:
		case PROP_SUMNZ:
		case PROP_SUMZ:
			//case PROP_TEST:
		case PROP_TJZ:
		case PROP_WAITCNT:
		case PROP_WAITPEQ:
		case PROP_WAITPNE:
		case PROP_WAITVID:
		case PROP_XOR:
			snprintf (cmd->instr, sizeof cmd->instr, "%s", instrs[opcode]);

			if ((opcode == PROP_RDBYTE || opcode == PROP_RDLONG ||
						opcode == PROP_RDWORD) && (!(get_zcri (in) & 0x2))) {
				cmd->instr[0] = 'w';
				cmd->instr[1] = 'r';
			}

			if (opcode == PROP_SUB && in & 0x08000000) {
				snprintf (cmd->instr, PROP_INSTR_MAXLEN - 1, "sub");
			} else if (opcode == PROP_SUBX && in & 0x08000000) {
				snprintf (cmd->instr, PROP_INSTR_MAXLEN - 1, "subx");
			}

			if (is_immediate (in)) {
				cmd->src = get_src (in);
				cmd->dst = get_dst (in);
				snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1, "0x%x, #%d",
						get_dst (in), get_src (in));
			} else {
				cmd->src = get_src (in) << 2;
				cmd->dst = get_dst (in);
				snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1, "0x%x, 0x%x",
						get_dst (in), get_src (in) << 2);
			}

			ret = 4;
			break;
		case PROP_HUBOP:
			ret = decode_ext_cmd (cmd, in);
			if (ret == -1) {
				snprintf (cmd->instr, PROP_INSTR_MAXLEN - 1, "%s",
						instrs[opcode]);

				if (is_immediate (in)) {
					cmd->src = get_src (in);
					cmd->dst = get_dst (in);

					snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1, "0x%x, #%d",
							get_dst (in) << 2, get_src (in));
				} else {
					cmd->src = get_src (in);
					cmd->dst = get_dst (in);

					snprintf (cmd->operands, PROP_INSTR_MAXLEN - 1, "0x%x, 0x%x",
							get_dst (in), get_src (in));
				}

				ret = 4;
			}
			break;
		case PROP_JMP:
			ret = decode_jmp (cmd, in);
			break;
	}

	cmd->opcode = opcode;

	if (ret > 0) {
		decode_prefix (cmd, in);
	}

	return ret;
}

