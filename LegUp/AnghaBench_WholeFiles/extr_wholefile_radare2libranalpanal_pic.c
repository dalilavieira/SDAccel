#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_34__   TYPE_5__ ;
typedef  struct TYPE_33__   TYPE_4__ ;
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;
typedef  struct TYPE_29__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  void* ut64 ;
typedef  int ut32 ;
typedef  int ut16 ;
struct TYPE_34__ {int f; int d; int n; int k; int b; int m; } ;
struct TYPE_31__ {int /*<<< orphan*/  io; TYPE_1__* (* open_at ) (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* fd_remap ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ;scalar_t__ (* fd_get_name ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
struct TYPE_33__ {scalar_t__ cpu; int /*<<< orphan*/ * reg; TYPE_2__ iob; } ;
struct TYPE_32__ {int size; int cycles; int jump; void* type; int /*<<< orphan*/  esil; void* fail; } ;
struct TYPE_30__ {int /*<<< orphan*/  fd; } ;
struct TYPE_29__ {scalar_t__ opcode; int args; int /*<<< orphan*/  (* handler ) (TYPE_4__*,TYPE_3__*,void*,TYPE_5__*) ;} ;
typedef  int /*<<< orphan*/  RRegItem ;
typedef  int /*<<< orphan*/  RReg ;
typedef  TYPE_1__ RIODesc ;
typedef  TYPE_2__ RIOBind ;
typedef  int /*<<< orphan*/  RAnalOpMask ;
typedef  TYPE_3__ RAnalOp ;
typedef  TYPE_4__ RAnal ;
typedef  scalar_t__ PicMidrangeOpcode ;
typedef  TYPE_5__ PicMidrangeOpArgsVal ;
typedef  int PicMidrangeOpArgs ;

/* Variables and functions */
 int PIC_MIDRANGE_ESIL_CSTACK_TOP ; 
 int PIC_MIDRANGE_ESIL_SRAM_START ; 
 int PIC_MIDRANGE_OPINFO_LEN ; 
#define  PIC_MIDRANGE_OP_ARGS_11K 138 
 int PIC_MIDRANGE_OP_ARGS_11K_MASK_K ; 
#define  PIC_MIDRANGE_OP_ARGS_1D_7F 137 
 int PIC_MIDRANGE_OP_ARGS_1D_7F_MASK_D ; 
 int PIC_MIDRANGE_OP_ARGS_1D_7F_MASK_F ; 
#define  PIC_MIDRANGE_OP_ARGS_1N_2M 136 
 int PIC_MIDRANGE_OP_ARGS_1N_2M_MASK_M ; 
 int PIC_MIDRANGE_OP_ARGS_1N_2M_MASK_N ; 
#define  PIC_MIDRANGE_OP_ARGS_1N_6K 135 
 int PIC_MIDRANGE_OP_ARGS_1N_6K_MASK_K ; 
 int PIC_MIDRANGE_OP_ARGS_1N_6K_MASK_N ; 
#define  PIC_MIDRANGE_OP_ARGS_2F 134 
 int PIC_MIDRANGE_OP_ARGS_2F_MASK_F ; 
#define  PIC_MIDRANGE_OP_ARGS_3B_7F 133 
 int PIC_MIDRANGE_OP_ARGS_3B_7F_MASK_B ; 
 int PIC_MIDRANGE_OP_ARGS_3B_7F_MASK_F ; 
#define  PIC_MIDRANGE_OP_ARGS_4K 132 
 int PIC_MIDRANGE_OP_ARGS_4K_MASK_K ; 
#define  PIC_MIDRANGE_OP_ARGS_7F 131 
 int PIC_MIDRANGE_OP_ARGS_7F_MASK_F ; 
#define  PIC_MIDRANGE_OP_ARGS_8K 130 
 int PIC_MIDRANGE_OP_ARGS_8K_MASK_K ; 
#define  PIC_MIDRANGE_OP_ARGS_9K 129 
 int PIC_MIDRANGE_OP_ARGS_9K_MASK_K ; 
#define  PIC_MIDRANGE_OP_ARGS_NONE 128 
 void* R_ANAL_OP_TYPE_ADD ; 
 void* R_ANAL_OP_TYPE_AND ; 
 void* R_ANAL_OP_TYPE_CALL ; 
 void* R_ANAL_OP_TYPE_CJMP ; 
 void* R_ANAL_OP_TYPE_CMP ; 
 void* R_ANAL_OP_TYPE_CPL ; 
 void* R_ANAL_OP_TYPE_ILL ; 
 void* R_ANAL_OP_TYPE_JMP ; 
 void* R_ANAL_OP_TYPE_LOAD ; 
 void* R_ANAL_OP_TYPE_MOV ; 
 void* R_ANAL_OP_TYPE_MUL ; 
 void* R_ANAL_OP_TYPE_NOP ; 
 void* R_ANAL_OP_TYPE_OR ; 
 void* R_ANAL_OP_TYPE_POP ; 
 void* R_ANAL_OP_TYPE_PUSH ; 
 void* R_ANAL_OP_TYPE_RET ; 
 void* R_ANAL_OP_TYPE_ROL ; 
 void* R_ANAL_OP_TYPE_ROR ; 
 void* R_ANAL_OP_TYPE_STORE ; 
 void* R_ANAL_OP_TYPE_SUB ; 
 void* R_ANAL_OP_TYPE_UNK ; 
 void* R_ANAL_OP_TYPE_XOR ; 
 int /*<<< orphan*/  R_PERM_RW ; 
 int /*<<< orphan*/  R_REG_TYPE_GPR ; 
 int /*<<< orphan*/  free (char*) ; 
 TYPE_1__* mem_sram ; 
 TYPE_1__* mem_stack ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  memset (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ pic_midrange_get_opcode (int) ; 
 TYPE_10__* pic_midrange_op_anal_info ; 
 int r_read_le16 (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * r_reg_get (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int r_reg_set_profile_string (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  r_reg_set_value (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 char* r_str_newf (char*,int) ; 
 int /*<<< orphan*/  r_strbuf_setf (int /*<<< orphan*/ *,char*,...) ; 
 scalar_t__ strcasecmp (scalar_t__,char*) ; 
 scalar_t__ stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* stub3 (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub4 (TYPE_4__*,TYPE_3__*,void*,TYPE_5__*) ; 

__attribute__((used)) static void anal_pic_midrange_extract_args (ut16 instr,
					    PicMidrangeOpArgs args,
					    PicMidrangeOpArgsVal *args_val) {

	memset (args_val, 0, sizeof (PicMidrangeOpArgsVal));

	switch (args) {
	case PIC_MIDRANGE_OP_ARGS_NONE: return;
	case PIC_MIDRANGE_OP_ARGS_2F:
		args_val->f = instr & PIC_MIDRANGE_OP_ARGS_2F_MASK_F;
		return;
	case PIC_MIDRANGE_OP_ARGS_7F:
		args_val->f = instr & PIC_MIDRANGE_OP_ARGS_7F_MASK_F;
		return;
	case PIC_MIDRANGE_OP_ARGS_1D_7F:
		args_val->f = instr & PIC_MIDRANGE_OP_ARGS_1D_7F_MASK_F;
		args_val->d =
			(instr & PIC_MIDRANGE_OP_ARGS_1D_7F_MASK_D) >> 7;
		return;
	case PIC_MIDRANGE_OP_ARGS_1N_6K:
		args_val->n =
			(instr & PIC_MIDRANGE_OP_ARGS_1N_6K_MASK_N) >> 6;
		args_val->k = instr & PIC_MIDRANGE_OP_ARGS_1N_6K_MASK_K;
		return;
	case PIC_MIDRANGE_OP_ARGS_3B_7F:
		args_val->b =
			(instr & PIC_MIDRANGE_OP_ARGS_3B_7F_MASK_B) >> 7;
		args_val->f = instr & PIC_MIDRANGE_OP_ARGS_3B_7F_MASK_F;
		return;
	case PIC_MIDRANGE_OP_ARGS_4K:
		args_val->k = instr & PIC_MIDRANGE_OP_ARGS_4K_MASK_K;
		return;
	case PIC_MIDRANGE_OP_ARGS_8K:
		args_val->k = instr & PIC_MIDRANGE_OP_ARGS_8K_MASK_K;
		return;
	case PIC_MIDRANGE_OP_ARGS_9K:
		args_val->k = instr & PIC_MIDRANGE_OP_ARGS_9K_MASK_K;
		return;
	case PIC_MIDRANGE_OP_ARGS_11K:
		args_val->k = instr & PIC_MIDRANGE_OP_ARGS_11K_MASK_K;
		return;
	case PIC_MIDRANGE_OP_ARGS_1N_2M:
		args_val->n =
			(instr & PIC_MIDRANGE_OP_ARGS_1N_2M_MASK_N) >> 2;
		args_val->m = instr & PIC_MIDRANGE_OP_ARGS_1N_2M_MASK_M;
		return;
	}
}

__attribute__((used)) static RIODesc *cpu_memory_map (RIOBind *iob, RIODesc *desc, ut32 addr,
				ut32 size) {
	char *mstr = r_str_newf ("malloc://%d", size);
	if (desc && iob->fd_get_name (iob->io, desc->fd)) {
		iob->fd_remap (iob->io, desc->fd, addr);
	} else {
		desc = iob->open_at (iob->io, mstr, R_PERM_RW, 0, addr);
	}
	free (mstr);
	return desc;
}

__attribute__((used)) static bool pic_midrange_reg_write (RReg *reg, const char *regname, ut32 num) {
	if (reg) {
		RRegItem *item = r_reg_get (reg, regname, R_REG_TYPE_GPR);
		if (item) {
			r_reg_set_value (reg, item, num);
			return true;
		}
	}
	return false;
}

__attribute__((used)) static void anal_pic_midrange_malloc (RAnal *anal, bool force) {
	static bool init_done = false;

	if (!init_done || force) {
		// Allocate memory as needed.
		// We assume that code is already allocated with firmware
		// image
		mem_sram =
			cpu_memory_map (&anal->iob, mem_sram,
					PIC_MIDRANGE_ESIL_SRAM_START, 0x1000);
		mem_stack =
			cpu_memory_map (&anal->iob, mem_stack,
					PIC_MIDRANGE_ESIL_CSTACK_TOP, 0x20);

		pic_midrange_reg_write (anal->reg, "_sram",
					PIC_MIDRANGE_ESIL_SRAM_START);
		pic_midrange_reg_write (anal->reg, "_stack",
					PIC_MIDRANGE_ESIL_CSTACK_TOP);
		pic_midrange_reg_write (anal->reg, "stkptr", 0x1f);

		init_done = true;
	}
}

__attribute__((used)) static int anal_pic_midrange_op (RAnal *anal, RAnalOp *op, ut64 addr,
				 const ut8 *buf, int len) {

	ut16 instr;
	int i;

	anal_pic_midrange_malloc (anal, false);

	if (!buf || len < 2) {
		op->type = R_ANAL_OP_TYPE_ILL;
		return op->size;
	}

	instr = r_read_le16 (buf);

	// Default op params
	op->size = 2;
	op->cycles = 1;
	op->type = R_ANAL_OP_TYPE_NOP;

	PicMidrangeOpcode opcode = pic_midrange_get_opcode (instr);
	PicMidrangeOpArgsVal args_val;

	for (i = 0; i < PIC_MIDRANGE_OPINFO_LEN; i++) {
		if (pic_midrange_op_anal_info[i].opcode == opcode) {
			anal_pic_midrange_extract_args (
				instr, pic_midrange_op_anal_info[i].args,
				&args_val);
			pic_midrange_op_anal_info[i].handler (anal, op, addr,
							      &args_val);
			break;
		}
	}

	return op->size;
}

__attribute__((used)) static void pic18_cond_branch (RAnalOp *op, ut64 addr, const ut8 *buf, char *flag) {
	op->type = R_ANAL_OP_TYPE_CJMP;
	op->jump = addr + 2 + 2 * (*(ut16 *)buf & 0xff);
	op->fail = addr + op->size;
	op->cycles = 2;
	r_strbuf_setf (&op->esil, "%s,?,{,0x%x,pc,=,}", flag, op->jump);
}

__attribute__((used)) static int anal_pic_pic18_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf, int len) {
	//TODO code should be refactored and brocken into smaller chuncks!!
	//TODO complete the esil emitter
	if (len < 2) {
		op->size = len;
		goto beach; //pancake style :P
	}
	op->size = 2;
	ut16 b = *(ut16 *)buf;
	ut32 dword_instr = 0;
	memcpy (&dword_instr, buf, len);
	switch (b >> 9) {
	case 0x76: //call
		if (len < 4) {
			goto beach;
		}
		if (dword_instr >> 28 != 0xf) {
			goto beach;
		}
		op->size = 4;
		op->type = R_ANAL_OP_TYPE_CALL;
		return op->size;
	};
	switch (b >> 11) { //NEX_T
	case 0x1b:	//rcall
		op->type = R_ANAL_OP_TYPE_CALL;
		return op->size;
	case 0x1a: //bra
		op->type = R_ANAL_OP_TYPE_JMP;
		op->cycles = 2;
		op->jump = addr + 2 + 2 * (*(ut16 *)buf & 0x7ff);
		r_strbuf_setf (&op->esil, "0x%x,pc,=", op->jump);
		return op->size;
	}
	switch (b >> 12) { //NOP,movff,BAF_T
	case 0xf:	//nop
		op->type = R_ANAL_OP_TYPE_NOP;
		op->cycles = 1;
		r_strbuf_setf (&op->esil, ",");
		return op->size;
	case 0xc: //movff
		if (len < 4) {
			goto beach;
		}
		if (dword_instr >> 28 != 0xf) {
			goto beach;
		}
		op->size = 4;
		op->type = R_ANAL_OP_TYPE_MOV;
		return op->size;
	case 0xb: //btfsc
	case 0xa: //btfss
		op->type = R_ANAL_OP_TYPE_CJMP;
		return op->size;
	case 0x9: //bcf
	case 0x8: //bsf
	case 0x7: //btg
		op->type = R_ANAL_OP_TYPE_UNK;
		return op->size;
	};

	switch (b >> 8) { //GOTO_T,N_T,K_T
	case 0xe0:	//bz
		pic18_cond_branch (op, addr, buf, "z");
		return op->size;
	case 0xe1: //bnz
		pic18_cond_branch (op, addr, buf, "z,!");
		return op->size;
	case 0xe3: //bnc
		pic18_cond_branch (op, addr, buf, "c,!");
		return op->size;
	case 0xe4: //bov
		pic18_cond_branch (op, addr, buf, "ov");
		return op->size;
	case 0xe5: //bnov
		pic18_cond_branch (op, addr, buf, "ov,!");
		return op->size;
	case 0xe6: //bn
		pic18_cond_branch (op, addr, buf, "n");
		return op->size;
	case 0xe7: //bnn
		pic18_cond_branch (op, addr, buf, "n,!");
		return op->size;
	case 0xe2: //bc
		pic18_cond_branch (op, addr, buf, "c");
		return op->size;
	case 0xef: //goto
		if (len < 4) {
			goto beach;
		}
		if (dword_instr >> 28 != 0xf) {
			goto beach;
		}
		op->size = 4;
		op->cycles = 2;
		op->jump = ((dword_instr & 0xff) | ((dword_instr & 0xfff0000) >> 8)) * 2;
		r_strbuf_setf (&op->esil, "0x%x,pc,=", op->jump);
		op->type = R_ANAL_OP_TYPE_JMP;
		return op->size;
	case 0xf: //addlw
		op->type = R_ANAL_OP_TYPE_ADD;
		op->cycles = 1;
		//TODO add support for dc flag
		r_strbuf_setf (&op->esil, "0x%x,wreg,+=,$z,z,:=,$s,n,:=,7,$c,c,:=,$o,ov,:=,", *(ut16 *)buf & 0xff);
		return op->size;
	case 0xe: //movlw
		op->type = R_ANAL_OP_TYPE_LOAD;
		op->cycles = 1;
		r_strbuf_setf (&op->esil, "0x%x,wreg,=,");
		return op->size;
	case 0xd: //mullw
		op->type = R_ANAL_OP_TYPE_MUL;
		op->cycles = 1;
		r_strbuf_setf (&op->esil, "0x%x,wreg,*,prod,=", *(ut16 *)buf & 0xff);
		return op->size;
	case 0xc: //retlw
		op->type = R_ANAL_OP_TYPE_RET;
		op->cycles = 2;
		r_strbuf_setf (&op->esil, "0x%x,wreg,=,tos,pc,=,", *(ut16 *)buf & 0xff);
		return op->size;
	case 0xb: //andlw
		op->type = R_ANAL_OP_TYPE_AND;
		op->cycles = 1;
		r_strbuf_setf (&op->esil, "0x%x,wreg,&=,$z,z,:=,$s,n,:=,", *(ut16 *)buf & 0xff);
		return op->size;
	case 0xa: //xorlw
		op->type = R_ANAL_OP_TYPE_XOR;
		op->cycles = 1;
		r_strbuf_setf (&op->esil, "0x%x,wreg,^=,$z,z,:=,$s,n,:=,", *(ut16 *)buf & 0xff);
		return op->size;
	case 0x9: //iorlw
		op->type = R_ANAL_OP_TYPE_OR;
		op->cycles = 1;
		r_strbuf_setf (&op->esil, "0x%x,wreg,^=,$z,z,:=,$s,n,:=,", *(ut16 *)buf & 0xff);
		return op->size;
	case 0x8: //sublw
		op->type = R_ANAL_OP_TYPE_SUB;
		op->cycles = 1;
		//TODO add support for dc flag
		r_strbuf_setf (&op->esil, "wreg,0x%x,-,wreg,=,$z,z,:=,$s,n,:=,7,$c,c,:=,$o,ov,:=,", *(ut16 *)buf & 0xff);
		return op->size;
	};

	switch (b >> 6) { //LFSR
	case 0x3b8:       //lfsr
		if (len < 4) {
			goto beach;
		}
		if (dword_instr >> 28 != 0xf) {
			goto beach;
		}
		op->size = 4;
		op->type = R_ANAL_OP_TYPE_LOAD;
		return op->size;
	};
	switch (b >> 10) { //DAF_T
	case 0x17:	//subwf
	case 0x16:	//subwfb
	case 0x15:	//subfwb
	case 0x13:	//dcfsnz
	case 0xb:	//decfsz
	case 0x1:	//decf
		op->type = R_ANAL_OP_TYPE_SUB;
		return op->size;
	case 0x14: //movf
		op->type = R_ANAL_OP_TYPE_MOV;
		return op->size;
	case 0x12: //infsnz
	case 0xf:  //incfsz
	case 0xa:  //incf
	case 0x8:  //addwfc
		op->type = R_ANAL_OP_TYPE_ADD;
		return op->size;
	case 0x9: //addwf
		op->cycles = 1;
		op->type = R_ANAL_OP_TYPE_ADD;
		return op->size;
	case 0x11: //rlncf
	case 0xd:  //rlcf
		op->type = R_ANAL_OP_TYPE_ROL;
		return op->size;
	case 0x10: //rrncf
	case 0xc:  //rrcf
		op->type = R_ANAL_OP_TYPE_ROR;
		return op->size;
	case 0xe: //swapf
		op->type = R_ANAL_OP_TYPE_UNK;
		return op->size;
	case 0x7: //comf
		op->type = R_ANAL_OP_TYPE_CPL;
		return op->size;
	case 0x6: //xorwf
		op->type = R_ANAL_OP_TYPE_XOR;
		return op->size;
	case 0x5: //andwf
		op->type = R_ANAL_OP_TYPE_AND;
		return op->size;
	case 0x4: //iorwf
		op->type = R_ANAL_OP_TYPE_OR;
		return op->size;
	};
	switch (b >> 9) { //AF_T
	case 0x37:	//movwf
		op->type = R_ANAL_OP_TYPE_STORE;
		return op->size;
	case 0x36: //negf
	case 0x35: //clrf
	case 0x34: //setf
		op->type = R_ANAL_OP_TYPE_UNK;
		return op->size;
	case 0x33: //tstfsz
		op->type = R_ANAL_OP_TYPE_CJMP;
		return op->size;
	case 0x32: //cpfsgt
	case 0x31: //cpfseq
	case 0x30: //cpfslt
		op->type = R_ANAL_OP_TYPE_CMP;
		return op->size;
	case 0x1: //mulwf
		op->type = R_ANAL_OP_TYPE_MUL;
		return op->size;
	};
	switch (b >> 4) {
	case 0x10: //movlb
		op->type = R_ANAL_OP_TYPE_LOAD;
		op->cycles = 1;
		r_strbuf_setf (&op->esil, "0x%x,bsr,=,", *(ut16 *)buf & 0xf);
		return op->size;
	};
	switch (b) {
	case 0xff: //reset
	case 0x7:  //daw
	case 0x4:  //clwdt
	case 0x3:  //sleep
		op->type = R_ANAL_OP_TYPE_UNK;
		return op->size;
	case 0x13: //return
		op->type = R_ANAL_OP_TYPE_RET;
		op->cycles = 2;
		r_strbuf_setf (&op->esil, "tos,pc,=,");
		return op->size;
	case 0x12: //return
		op->type = R_ANAL_OP_TYPE_RET;
		op->cycles = 2;
		r_strbuf_setf (&op->esil, "tos,pc,=");
		return op->size;
	case 0x11: //retfie
	case 0x10: //retfie
		op->type = R_ANAL_OP_TYPE_RET;
		return op->size;
	case 0xf: //tblwt
	case 0xe: //tblwt
	case 0xd: //tblwt
	case 0xc: //tblwt
		op->type = R_ANAL_OP_TYPE_LOAD;
		return op->size;
	case 0xb: //tblrd
	case 0xa: //tblrd
	case 0x9: //tblrd
	case 0x8: //tblrd
		op->type = R_ANAL_OP_TYPE_STORE;
		return op->size;
	case 0x6: //pop
		op->type = R_ANAL_OP_TYPE_POP;
		return op->size;
	case 0x5: //push
		op->type = R_ANAL_OP_TYPE_PUSH;
		return op->size;
	case 0x0: //nop
		op->type = R_ANAL_OP_TYPE_NOP;
		op->cycles = 1;
		r_strbuf_setf (&op->esil, ",");
		return op->size;
	};
beach:
	op->type = R_ANAL_OP_TYPE_ILL;
	return op->size;
}

__attribute__((used)) static int anal_pic_midrange_set_reg_profile (RAnal *esil) {
	const char *p;
	p = "=PC	pc\n"
	    "=SP	stkptr\n"
	    "gpr	indf0	.8	0	0\n"
	    "gpr	indf1	.8	1	0\n"
	    "gpr	pcl		.8	2	0\n"
	    "gpr	status	.8	3	0\n"
	    "flg	c		.1	3.0	0\n"
	    "flg	dc		.1	3.1	0\n"
	    "flg	z		.1	3.2	0\n"
	    "flg	pd		.1	3.3	0\n"
	    "flg	to		.1	3.4	0\n"
	    "gpr	fsr0l	.8	4	0\n"
	    "gpr	fsr0h	.8	5	0\n"
	    "gpr	fsr1l	.8	6	0\n"
	    "gpr	fsr1h	.8	7	0\n"
	    "gpr	bsr		.8	8	0\n"
	    "gpr	wreg	.8	9	0\n"
	    "gpr	pclath	.8	10	0\n"
	    "gpr	intcon	.8	11	0\n"
	    "gpr	pc		.16	12	0\n"
	    "gpr	stkptr	.8	14	0\n"
	    "gpr	_sram	.32 15	0\n"
	    "gpr	_stack	.32 19	0\n";

	return r_reg_set_profile_string (esil->reg, p);
}

__attribute__((used)) static int anal_pic_pic18_set_reg_profile(RAnal *esil) {
	const char *p;
	p =
		"#pc lives in nowhere actually"
		"=PC	pc\n"
		"=SP	tos\n"
		"gpr	pc	.32	0	0\n"
		"gpr	pcl	.8	0	0\n"
		"gpr	pclath	.8	1	0\n"
		"gpr	pclatu	.8	2	0\n"
		"#bsr max is 0b111\n"
		"gpr	bsr	.8	4	0\n"
		"#tos doesn't exist\n"
		"#general rule of thumb any register of size >8 bits has no existance\n"
		"gpr	tos	.32	5	0\n"
		"gpr	tosl	.8	5	0\n"
		"gpr	tosh	.8	6	0\n"
		"gpr	tosu	.8	7	0\n"

		"gpr	indf0	.16	9	0\n"
		"gpr	fsr0	.12	9	0\n"
		"gpr	fsr0l	.8	9	0\n"
		"gpr	fsr0h	.8	10	0\n"
		"gpr	indf1	.16	11	0\n"
		"gpr	fsr1	.12	11	0\n"
		"gpr	fsr1l	.8	11	0\n"
		"gpr	fsr1h	.8	12	0\n"
		"gpr	indf2	.16	13	0\n"
		"gpr	fsr2	.12	13	0\n"
		"gpr	frs2l	.8	13	0\n"
		"gpr	fsr2h	.8	14	0\n"
		"gpr	tblptr	.22	15	0\n"
		"gpr	tblptrl	.8	15	0\n"
		"gpr	tblptrh	.8	16	0\n"
		"gpr	tblptru	.8	17	0\n"
		"gpr	rcon	.8	18	0\n"
		"gpr	memcon	.8	19	0\n"
		"gpr	intcon	.8	20	0\n"
		"gpr	intcon2	.8	21	0\n"
		"gpr	intcon3	.8	22	0\n"
		"gpr	pie1	.8	23	0\n"
		"gpr	porta	.7	29	0\n"
		"gpr	trisa	.8	30	0\n"
		"gpr	portb	.8	33	0\n"
		"gpr	tisb	.8	34	0\n"
		"gpr	latb	.8	35	0\n"
		"gpr	portc	.8	36	0\n"
		"gpr	trisc	.8	37	0\n"
		"gpr	latc	.8	38	0\n"
		"gpr	portd	.8	39	0\n"
		"gpr	trisd	.8	40	0\n"
		"gpr	latd	.8	41	0\n"
		"gpr	pspcon	.8	42	0\n"
		"gpr	porte	.8	43	0\n"
		"gpr	trise	.8	44	0\n"
		"gpr	late	.8	45	0\n"
		"gpr	t0con	.8	46	0\n"
		"gpr	t1con	.8	47	0\n"
		"gpr	t2con	.8	48	0\n"
		"gpr	tmr1h	.8	50	0\n"
		"gpr	tmr0h	.8	51	0\n"
		"gpr	tmr1l	.8	52	0\n"
		"gpr	tmr2	.8	53	0\n"
		"gpr	pr2	.8	54	0\n"
		"gpr	ccpr1h	.8	55	0\n"
		"gpr	postinc2 .8	56	0\n"
		"gpr	ccpr1l	.8	57	0\n"
		"gpr	postdec2 .8	58	0\n"
		"gpr	ccp1con	.8	59	0\n"
		"gpr	preinc2	.8	60	0\n"
		"gpr	ccpr2h	.8	61	0\n"
		"gpr	plusw2	.8	62	0\n"
		"gpr	ccpr2l	.8	63	0\n"
		"gpr	ccp2con	.8	64	0\n"
		"gpr	status	.8	65	0\n"
		"flg	c	.1	.520	0\n"
		"flg	dc	.1	.521	0\n"
		"flg	z	.1	.522	0\n"
		"flg	ov	.1	.523	0\n"
		"flg	n	.1	.524	0\n"
		"gpr	prod	.16	66	0\n"
		"gpr	prodl	.8	66	0\n"
		"gpr	prodh	.8	67	0\n"
		"gpr	osccon	.8	68	0\n"
		"gpr	tmr3h	.8	69	0\n"
		"gpr	lvdcon	.8	70	0\n"
		"gpr	tmr3l	.8	71	0\n"
		"gpr	wdtcon	.8	72	0\n"
		"gpr	t3con	.8	73	0\n"
		"gpr	spbrg	.8	74	0\n"
		"gpr	postinc0 .8	75	0\n"
		"gpr	rcreg	.8	76	0\n"
		"gpr	postdec0 .8	77	0\n"
		"gpr	txreg	.8	78	0\n"
		"gpr	preinc0	.8	79	0\n"
		"gpr	txsta	.8	80	0\n"
		"gpr	plusw0	.8	81	0\n"
		"gpr	rcsta	.8	82	0\n"
		"gpr	sspbuf	.8	83	0\n"
		"gpr	wreg	.8	84	0\n"
		"gpr	sspadd	.8	85	0\n"
		"gpr	sspstat	.8	86	0\n"
		"gpr	postinc1 .8	87	0\n"
		"gpr	sspcon1	.8	88	0\n"
		"gpr	postdec1 .8	89	0\n"
		"gpr	sspcon2	.8	90	0\n"
		"gpr	preinc1	.8	91	0\n"
		"gpr	adresh	.8	92	0\n"
		"gpr	plusw1	.8	93	0\n"
		"gpr	adresl	.8	94	0\n"
		"gpr	adcon0	.8	95	0\n"
		"#stkprt max is 0b11111\n"
		"gpr	stkptr	.8	96	0\n"
		"gpr	tablat	.8	14	0\n";

	return r_reg_set_profile_string (esil->reg, p);
}

__attribute__((used)) static int anal_pic_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf, int len, RAnalOpMask mask) {
	if (anal->cpu && strcasecmp (anal->cpu, "baseline") == 0) {
		// TODO: implement
		return -1;
	}
	if (anal->cpu && strcasecmp (anal->cpu, "midrange") == 0) {
		return anal_pic_midrange_op (anal, op, addr, buf, len);
	}
	if (anal->cpu && strcasecmp (anal->cpu, "pic18") == 0) {
		return anal_pic_pic18_op (anal, op, addr, buf, len);
	}
	return -1;
}

__attribute__((used)) static int anal_pic_set_reg_profile(RAnal *anal) {
	if (anal->cpu && strcasecmp (anal->cpu, "baseline") == 0) {
		// TODO: We are using the midrange profile as the baseline
		return anal_pic_midrange_set_reg_profile (anal);
	}
	if (anal->cpu && strcasecmp (anal->cpu, "midrange") == 0) {
		return anal_pic_midrange_set_reg_profile (anal);
	}
	if (anal->cpu && strcasecmp (anal->cpu, "pic18") == 0) {
		return anal_pic_pic18_set_reg_profile (anal);
	}
	return -1;
}

