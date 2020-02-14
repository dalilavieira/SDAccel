#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u_int ;
struct TYPE_2__ {scalar_t__ cpu_type; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int COPR_INST ; 
 int EMULATION_VERSION ; 
 scalar_t__ FPUDEBUG ; 
 size_t FPU_TYPE_FLAG_POS ; 
#define  MAJOR_06_EXCP 133 
#define  MAJOR_0C_EXCP 132 
#define  MAJOR_0E_EXCP 131 
#define  MAJOR_26_EXCP 130 
#define  MAJOR_2E_EXCP 129 
 int NOEXCEPTION ; 
 int PA2_0_FPU_FLAG ; 
#define  PA83_UNIMP_EXCP 128 
 int ROLEX_EXTEN_FLAG ; 
 int TIMEX_EXTEN_FLAG ; 
 int UNIMPLEMENTEDEXCEPTION ; 
 int /*<<< orphan*/  VASSERT (int) ; 
 TYPE_1__ boot_cpu_data ; 
 int dbl_fadd (int*,int*,int*,int*) ; 
 int dbl_fcmp (int*,int*,int,int*) ; 
 int dbl_fdiv (int*,int*,int*,int*) ; 
 int dbl_fmpy (int*,int*,int*,int*) ; 
 int dbl_frem (int*,int*,int*,int*) ; 
 int dbl_frnd (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_fsqrt (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_fsub (int*,int*,int*,int*) ; 
 int dbl_to_dbl_fcnvfu (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_dbl_fcnvfut (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_dbl_fcnvfx (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_dbl_fcnvfxt (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_dbl_fcnvuf (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_dbl_fcnvxf (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_sgl_fcnvff (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_sgl_fcnvfu (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_sgl_fcnvfut (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_sgl_fcnvfx (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_sgl_fcnvfxt (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_sgl_fcnvuf (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int dbl_to_sgl_fcnvxf (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int decode_06 (int,int*) ; 
static  int decode_0c (int,int,int,int*) ; 
 int decode_0e (int,int,int,int*) ; 
 int decode_26 (int,int*) ; 
 int decode_2e (int,int*) ; 
 int extru (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  fpdfpos ; 
 int /*<<< orphan*/  fpfmtpos ; 
 int /*<<< orphan*/  fpnulpos ; 
 int /*<<< orphan*/  fpr1pos ; 
 int /*<<< orphan*/  fpr2pos ; 
 int /*<<< orphan*/  fptpos ; 
 int fpzeroreg ; 
 int get_class (int) ; 
 int get_major (int) ; 
 int get_subop (int) ; 
 int get_subop1_PA1_1 (int) ; 
 int get_subop1_PA2_0 (int) ; 
 scalar_t__ pcxs ; 
 scalar_t__ pcxt ; 
 scalar_t__ pcxt_ ; 
 scalar_t__ pcxu ; 
 int /*<<< orphan*/  printk (char*,int,int) ; 
 int sgl_fadd (int*,int*,int*,int*) ; 
 int sgl_fcmp (int*,int*,int,int*) ; 
 int sgl_fdiv (int*,int*,int*,int*) ; 
 int sgl_fmpy (int*,int*,int*,int*) ; 
 int sgl_frem (int*,int*,int*,int*) ; 
 int sgl_frnd (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_fsqrt (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_fsub (int*,int*,int*,int*) ; 
 int sgl_to_dbl_fcnvff (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_dbl_fcnvfu (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_dbl_fcnvfut (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_dbl_fcnvfx (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_dbl_fcnvfxt (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_dbl_fcnvuf (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_dbl_fcnvxf (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_sgl_fcnvfu (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_sgl_fcnvfut (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_sgl_fcnvfx (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_sgl_fcnvfxt (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_sgl_fcnvuf (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int sgl_to_sgl_fcnvxf (int*,int /*<<< orphan*/ ,int*,int*) ; 
 int /*<<< orphan*/  update_status_cbit (int*,int,int,int) ; 

__attribute__((used)) static void parisc_linux_get_fpu_type(u_int fpregs[])
{
	/* on pa-linux the fpu type is not filled in by the
	 * caller; it is constructed here  
	 */ 
	if (boot_cpu_data.cpu_type == pcxs)
		fpregs[FPU_TYPE_FLAG_POS] = TIMEX_EXTEN_FLAG;
	else if (boot_cpu_data.cpu_type == pcxt ||
	         boot_cpu_data.cpu_type == pcxt_)
		fpregs[FPU_TYPE_FLAG_POS] = ROLEX_EXTEN_FLAG;
	else if (boot_cpu_data.cpu_type >= pcxu)
		fpregs[FPU_TYPE_FLAG_POS] = PA2_0_FPU_FLAG;
}

u_int
fpudispatch(u_int ir, u_int excp_code, u_int holder, u_int fpregs[])
{
	u_int class, subop;
	u_int fpu_type_flags;

	/* All FP emulation code assumes that ints are 4-bytes in length */
	VASSERT(sizeof(int) == 4);

	parisc_linux_get_fpu_type(fpregs);

	fpu_type_flags=fpregs[FPU_TYPE_FLAG_POS];  /* get fpu type flags */

	class = get_class(ir);
	if (class == 1) {
		if  (fpu_type_flags & PA2_0_FPU_FLAG)
			subop = get_subop1_PA2_0(ir);
		else
			subop = get_subop1_PA1_1(ir);
	}
	else
		subop = get_subop(ir);

	if (FPUDEBUG) printk("class %d subop %d\n", class, subop);

	switch (excp_code) {
		case MAJOR_0C_EXCP:
		case PA83_UNIMP_EXCP:
			return(decode_0c(ir,class,subop,fpregs));
		case MAJOR_0E_EXCP:
			return(decode_0e(ir,class,subop,fpregs));
		case MAJOR_06_EXCP:
			return(decode_06(ir,fpregs));
		case MAJOR_26_EXCP:
			return(decode_26(ir,fpregs));
		case MAJOR_2E_EXCP:
			return(decode_2e(ir,fpregs));
		default:
			/* "crashme Night Gallery painting nr 2. (asm_crash.s).
			 * This was fixed for multi-user kernels, but
			 * workstation kernels had a panic here.  This allowed
			 * any arbitrary user to panic the kernel by executing
			 * setting the FP exception registers to strange values
			 * and generating an emulation trap.  The emulation and
			 * exception code must never be able to panic the
			 * kernel.
			 */
			return(UNIMPLEMENTEDEXCEPTION);
	}
}

u_int
emfpudispatch(u_int ir, u_int dummy1, u_int dummy2, u_int fpregs[])
{
	u_int class, subop, major;
	u_int fpu_type_flags;

	/* All FP emulation code assumes that ints are 4-bytes in length */
	VASSERT(sizeof(int) == 4);

	fpu_type_flags=fpregs[FPU_TYPE_FLAG_POS];  /* get fpu type flags */

	major = get_major(ir);
	class = get_class(ir);
	if (class == 1) {
		if  (fpu_type_flags & PA2_0_FPU_FLAG)
			subop = get_subop1_PA2_0(ir);
		else
			subop = get_subop1_PA1_1(ir);
	}
	else
		subop = get_subop(ir);
	switch (major) {
		case 0x0C:
			return(decode_0c(ir,class,subop,fpregs));
		case 0x0E:
			return(decode_0e(ir,class,subop,fpregs));
		case 0x06:
			return(decode_06(ir,fpregs));
		case 0x26:
			return(decode_26(ir,fpregs));
		case 0x2E:
			return(decode_2e(ir,fpregs));
		default:
			return(PA83_UNIMP_EXCP);
	}
}

__attribute__((used)) static u_int
decode_0c(u_int ir, u_int class, u_int subop, u_int fpregs[])
{
	u_int r1,r2,t;		/* operand register offsets */ 
	u_int fmt;		/* also sf for class 1 conversions */
	u_int  df;		/* for class 1 conversions */
	u_int *status;
	u_int retval, local_status;
	u_int fpu_type_flags;

	if (ir == COPR_INST) {
		fpregs[0] = EMULATION_VERSION << 11;
		return(NOEXCEPTION);
	}
	status = &fpregs[0];	/* fp status register */
	local_status = fpregs[0]; /* and local copy */
	r1 = extru(ir,fpr1pos,5) * sizeof(double)/sizeof(u_int);
	if (r1 == 0)		/* map fr0 source to constant zero */
		r1 = fpzeroreg;
	t = extru(ir,fptpos,5) * sizeof(double)/sizeof(u_int);
	if (t == 0 && class != 2)	/* don't allow fr0 as a dest */
		return(MAJOR_0C_EXCP);
	fmt = extru(ir,fpfmtpos,2);	/* get fmt completer */

	switch (class) {
	    case 0:
		switch (subop) {
			case 0:	/* COPR 0,0 emulated above*/
			case 1:
				return(MAJOR_0C_EXCP);
			case 2:	/* FCPY */
				switch (fmt) {
				    case 2: /* illegal */
					return(MAJOR_0C_EXCP);
				    case 3: /* quad */
					t &= ~3;  /* force to even reg #s */
					r1 &= ~3;
					fpregs[t+3] = fpregs[r1+3];
					fpregs[t+2] = fpregs[r1+2];
				    case 1: /* double */
					fpregs[t+1] = fpregs[r1+1];
				    case 0: /* single */
					fpregs[t] = fpregs[r1];
					return(NOEXCEPTION);
				}
			case 3: /* FABS */
				switch (fmt) {
				    case 2: /* illegal */
					return(MAJOR_0C_EXCP);
				    case 3: /* quad */
					t &= ~3;  /* force to even reg #s */
					r1 &= ~3;
					fpregs[t+3] = fpregs[r1+3];
					fpregs[t+2] = fpregs[r1+2];
				    case 1: /* double */
					fpregs[t+1] = fpregs[r1+1];
				    case 0: /* single */
					/* copy and clear sign bit */
					fpregs[t] = fpregs[r1] & 0x7fffffff;
					return(NOEXCEPTION);
				}
			case 6: /* FNEG */
				switch (fmt) {
				    case 2: /* illegal */
					return(MAJOR_0C_EXCP);
				    case 3: /* quad */
					t &= ~3;  /* force to even reg #s */
					r1 &= ~3;
					fpregs[t+3] = fpregs[r1+3];
					fpregs[t+2] = fpregs[r1+2];
				    case 1: /* double */
					fpregs[t+1] = fpregs[r1+1];
				    case 0: /* single */
					/* copy and invert sign bit */
					fpregs[t] = fpregs[r1] ^ 0x80000000;
					return(NOEXCEPTION);
				}
			case 7: /* FNEGABS */
				switch (fmt) {
				    case 2: /* illegal */
					return(MAJOR_0C_EXCP);
				    case 3: /* quad */
					t &= ~3;  /* force to even reg #s */
					r1 &= ~3;
					fpregs[t+3] = fpregs[r1+3];
					fpregs[t+2] = fpregs[r1+2];
				    case 1: /* double */
					fpregs[t+1] = fpregs[r1+1];
				    case 0: /* single */
					/* copy and set sign bit */
					fpregs[t] = fpregs[r1] | 0x80000000;
					return(NOEXCEPTION);
				}
			case 4: /* FSQRT */
				switch (fmt) {
				    case 0:
					return(sgl_fsqrt(&fpregs[r1],0,
						&fpregs[t],status));
				    case 1:
					return(dbl_fsqrt(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2:
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
			case 5: /* FRND */
				switch (fmt) {
				    case 0:
					return(sgl_frnd(&fpregs[r1],0,
						&fpregs[t],status));
				    case 1:
					return(dbl_frnd(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2:
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
		} /* end of switch (subop) */

	case 1: /* class 1 */
		df = extru(ir,fpdfpos,2); /* get dest format */
		if ((df & 2) || (fmt & 2)) {
			/*
			 * fmt's 2 and 3 are illegal of not implemented
			 * quad conversions
			 */
			return(MAJOR_0C_EXCP);
		}
		/*
		 * encode source and dest formats into 2 bits.
		 * high bit is source, low bit is dest.
		 * bit = 1 --> double precision
		 */
		fmt = (fmt << 1) | df;
		switch (subop) {
			case 0: /* FCNVFF */
				switch(fmt) {
				    case 0: /* sgl/sgl */
					return(MAJOR_0C_EXCP);
				    case 1: /* sgl/dbl */
					return(sgl_to_dbl_fcnvff(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2: /* dbl/sgl */
					return(dbl_to_sgl_fcnvff(&fpregs[r1],0,
						&fpregs[t],status));
				    case 3: /* dbl/dbl */
					return(MAJOR_0C_EXCP);
				}
			case 1: /* FCNVXF */
				switch(fmt) {
				    case 0: /* sgl/sgl */
					return(sgl_to_sgl_fcnvxf(&fpregs[r1],0,
						&fpregs[t],status));
				    case 1: /* sgl/dbl */
					return(sgl_to_dbl_fcnvxf(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2: /* dbl/sgl */
					return(dbl_to_sgl_fcnvxf(&fpregs[r1],0,
						&fpregs[t],status));
				    case 3: /* dbl/dbl */
					return(dbl_to_dbl_fcnvxf(&fpregs[r1],0,
						&fpregs[t],status));
				}
			case 2: /* FCNVFX */
				switch(fmt) {
				    case 0: /* sgl/sgl */
					return(sgl_to_sgl_fcnvfx(&fpregs[r1],0,
						&fpregs[t],status));
				    case 1: /* sgl/dbl */
					return(sgl_to_dbl_fcnvfx(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2: /* dbl/sgl */
					return(dbl_to_sgl_fcnvfx(&fpregs[r1],0,
						&fpregs[t],status));
				    case 3: /* dbl/dbl */
					return(dbl_to_dbl_fcnvfx(&fpregs[r1],0,
						&fpregs[t],status));
				}
			case 3: /* FCNVFXT */
				switch(fmt) {
				    case 0: /* sgl/sgl */
					return(sgl_to_sgl_fcnvfxt(&fpregs[r1],0,
						&fpregs[t],status));
				    case 1: /* sgl/dbl */
					return(sgl_to_dbl_fcnvfxt(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2: /* dbl/sgl */
					return(dbl_to_sgl_fcnvfxt(&fpregs[r1],0,
						&fpregs[t],status));
				    case 3: /* dbl/dbl */
					return(dbl_to_dbl_fcnvfxt(&fpregs[r1],0,
						&fpregs[t],status));
				}
			case 5: /* FCNVUF (PA2.0 only) */
				switch(fmt) {
				    case 0: /* sgl/sgl */
					return(sgl_to_sgl_fcnvuf(&fpregs[r1],0,
						&fpregs[t],status));
				    case 1: /* sgl/dbl */
					return(sgl_to_dbl_fcnvuf(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2: /* dbl/sgl */
					return(dbl_to_sgl_fcnvuf(&fpregs[r1],0,
						&fpregs[t],status));
				    case 3: /* dbl/dbl */
					return(dbl_to_dbl_fcnvuf(&fpregs[r1],0,
						&fpregs[t],status));
				}
			case 6: /* FCNVFU (PA2.0 only) */
				switch(fmt) {
				    case 0: /* sgl/sgl */
					return(sgl_to_sgl_fcnvfu(&fpregs[r1],0,
						&fpregs[t],status));
				    case 1: /* sgl/dbl */
					return(sgl_to_dbl_fcnvfu(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2: /* dbl/sgl */
					return(dbl_to_sgl_fcnvfu(&fpregs[r1],0,
						&fpregs[t],status));
				    case 3: /* dbl/dbl */
					return(dbl_to_dbl_fcnvfu(&fpregs[r1],0,
						&fpregs[t],status));
				}
			case 7: /* FCNVFUT (PA2.0 only) */
				switch(fmt) {
				    case 0: /* sgl/sgl */
					return(sgl_to_sgl_fcnvfut(&fpregs[r1],0,
						&fpregs[t],status));
				    case 1: /* sgl/dbl */
					return(sgl_to_dbl_fcnvfut(&fpregs[r1],0,
						&fpregs[t],status));
				    case 2: /* dbl/sgl */
					return(dbl_to_sgl_fcnvfut(&fpregs[r1],0,
						&fpregs[t],status));
				    case 3: /* dbl/dbl */
					return(dbl_to_dbl_fcnvfut(&fpregs[r1],0,
						&fpregs[t],status));
				}
			case 4: /* undefined */
				return(MAJOR_0C_EXCP);
		} /* end of switch subop */

	case 2: /* class 2 */
		fpu_type_flags=fpregs[FPU_TYPE_FLAG_POS];
		r2 = extru(ir, fpr2pos, 5) * sizeof(double)/sizeof(u_int);
		if (r2 == 0)
			r2 = fpzeroreg;
		if  (fpu_type_flags & PA2_0_FPU_FLAG) {
			/* FTEST if nullify bit set, otherwise FCMP */
			if (extru(ir, fpnulpos, 1)) {  /* FTEST */
				switch (fmt) {
				    case 0:
					/*
					 * arg0 is not used
					 * second param is the t field used for
					 * ftest,acc and ftest,rej
					 * third param is the subop (y-field)
					 */
					BUG();
					/* Unsupported
					 * return(ftest(0L,extru(ir,fptpos,5),
					 *	 &fpregs[0],subop));
					 */
				    case 1:
				    case 2:
				    case 3:
					return(MAJOR_0C_EXCP);
				}
			} else {  /* FCMP */
				switch (fmt) {
				    case 0:
					retval = sgl_fcmp(&fpregs[r1],
						&fpregs[r2],extru(ir,fptpos,5),
						&local_status);
					update_status_cbit(status,local_status,
						fpu_type_flags, subop);
					return(retval);
				    case 1:
					retval = dbl_fcmp(&fpregs[r1],
						&fpregs[r2],extru(ir,fptpos,5),
						&local_status);
					update_status_cbit(status,local_status,
						fpu_type_flags, subop);
					return(retval);
				    case 2: /* illegal */
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
			}
		}  /* end of if for PA2.0 */
		else {	/* PA1.0 & PA1.1 */
		    switch (subop) {
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				return(MAJOR_0C_EXCP);
			case 0: /* FCMP */
				switch (fmt) {
				    case 0:
					retval = sgl_fcmp(&fpregs[r1],
						&fpregs[r2],extru(ir,fptpos,5),
						&local_status);
					update_status_cbit(status,local_status,
						fpu_type_flags, subop);
					return(retval);
				    case 1:
					retval = dbl_fcmp(&fpregs[r1],
						&fpregs[r2],extru(ir,fptpos,5),
						&local_status);
					update_status_cbit(status,local_status,
						fpu_type_flags, subop);
					return(retval);
				    case 2: /* illegal */
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
			case 1: /* FTEST */
				switch (fmt) {
				    case 0:
					/*
					 * arg0 is not used
					 * second param is the t field used for
					 * ftest,acc and ftest,rej
					 * third param is the subop (y-field)
					 */
					BUG();
					/* unsupported
					 * return(ftest(0L,extru(ir,fptpos,5),
					 *     &fpregs[0],subop));
					 */
				    case 1:
				    case 2:
				    case 3:
					return(MAJOR_0C_EXCP);
				}
		    } /* end of switch subop */
		} /* end of else for PA1.0 & PA1.1 */
	case 3: /* class 3 */
		r2 = extru(ir,fpr2pos,5) * sizeof(double)/sizeof(u_int);
		if (r2 == 0)
			r2 = fpzeroreg;
		switch (subop) {
			case 5:
			case 6:
			case 7:
				return(MAJOR_0C_EXCP);
			
			case 0: /* FADD */
				switch (fmt) {
				    case 0:
					return(sgl_fadd(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 1:
					return(dbl_fadd(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 2: /* illegal */
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
			case 1: /* FSUB */
				switch (fmt) {
				    case 0:
					return(sgl_fsub(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 1:
					return(dbl_fsub(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 2: /* illegal */
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
			case 2: /* FMPY */
				switch (fmt) {
				    case 0:
					return(sgl_fmpy(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 1:
					return(dbl_fmpy(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 2: /* illegal */
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
			case 3: /* FDIV */
				switch (fmt) {
				    case 0:
					return(sgl_fdiv(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 1:
					return(dbl_fdiv(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 2: /* illegal */
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
			case 4: /* FREM */
				switch (fmt) {
				    case 0:
					return(sgl_frem(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 1:
					return(dbl_frem(&fpregs[r1],&fpregs[r2],
						&fpregs[t],status));
				    case 2: /* illegal */
				    case 3: /* quad not implemented */
					return(MAJOR_0C_EXCP);
				}
		} /* end of class 3 switch */
	} /* end of switch(class) */

	/* If we get here, something is really wrong! */
	return(MAJOR_0C_EXCP);
}

