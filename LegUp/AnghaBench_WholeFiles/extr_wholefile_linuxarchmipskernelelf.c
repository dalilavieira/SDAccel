#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_4__ {int fcr31; } ;
struct TYPE_5__ {TYPE_1__ fpu; } ;
struct task_struct {TYPE_2__ thread; } ;
struct mode_req {int single; int soft; int fr1; int frdefault; int fre; } ;
struct mips_elf_abiflags_v0 {int fp_abi; } ;
struct file {int dummy; } ;
struct elf64_phdr {scalar_t__ p_type; int p_filesz; int /*<<< orphan*/  p_offset; } ;
struct elf64_hdr {int e_flags; } ;
struct elf32_phdr {scalar_t__ p_type; int p_filesz; int /*<<< orphan*/  p_offset; } ;
struct elf32_hdr {scalar_t__* e_ident; int e_flags; } ;
struct cpuinfo_mips {int fpu_csr31; int fpu_msk31; } ;
struct arch_elf_state {int interp_fp_abi; int fp_abi; int nan_2008; int overall_fp_mode; } ;
typedef  int /*<<< orphan*/  loff_t ;
typedef  int /*<<< orphan*/  abiflags ;
struct TYPE_6__ {int fpu_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  CONFIG_MIPS_O32_FP64_SUPPORT ; 
 int EF_MIPS_ABI2 ; 
 int EF_MIPS_FP64 ; 
 int EF_MIPS_NAN2008 ; 
 int EINVAL ; 
 int EIO ; 
 size_t EI_CLASS ; 
 scalar_t__ ELFCLASS32 ; 
 int ELIBBAD ; 
 int ENOEXEC ; 
 int EXSTACK_DISABLE_X ; 
 int FPU_CSR_ABS2008 ; 
 int FPU_CSR_NAN2008 ; 
#define  FP_FR0 130 
#define  FP_FR1 129 
#define  FP_FRE 128 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 int MIPS_ABI_FP_64A ; 
 void* MIPS_ABI_FP_OLD_64 ; 
 int MIPS_ABI_FP_SOFT ; 
 int MIPS_ABI_FP_UNKNOWN ; 
 int MIPS_FPIR_F64 ; 
 scalar_t__ PT_MIPS_ABIFLAGS ; 
 int /*<<< orphan*/  TIF_32BIT_FPREGS ; 
 int /*<<< orphan*/  TIF_HYBRID_FPREGS ; 
 struct cpuinfo_mips boot_cpu_data ; 
 int /*<<< orphan*/  clear_thread_flag (int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_has_mips_r2_r6 ; 
 scalar_t__ cpu_has_mips_r6 ; 
 int /*<<< orphan*/  cpu_has_rixi ; 
 struct task_struct* current ; 
 struct mode_req* fpu_reqs ; 
 int kernel_read (struct file*,struct mips_elf_abiflags_v0*,int,int /*<<< orphan*/ *) ; 
 int max (int,int) ; 
 int min (int,int) ; 
 scalar_t__ mips_use_nan_2008 ; 
 scalar_t__ mips_use_nan_legacy ; 
 struct mode_req none_req ; 
 TYPE_3__ raw_current_cpu_data ; 
 int /*<<< orphan*/  set_thread_flag (int /*<<< orphan*/ ) ; 

int arch_elf_pt_proc(void *_ehdr, void *_phdr, struct file *elf,
		     bool is_interp, struct arch_elf_state *state)
{
	union {
		struct elf32_hdr e32;
		struct elf64_hdr e64;
	} *ehdr = _ehdr;
	struct elf32_phdr *phdr32 = _phdr;
	struct elf64_phdr *phdr64 = _phdr;
	struct mips_elf_abiflags_v0 abiflags;
	bool elf32;
	u32 flags;
	int ret;
	loff_t pos;

	elf32 = ehdr->e32.e_ident[EI_CLASS] == ELFCLASS32;
	flags = elf32 ? ehdr->e32.e_flags : ehdr->e64.e_flags;

	/* Let's see if this is an O32 ELF */
	if (elf32) {
		if (flags & EF_MIPS_FP64) {
			/*
			 * Set MIPS_ABI_FP_OLD_64 for EF_MIPS_FP64. We will override it
			 * later if needed
			 */
			if (is_interp)
				state->interp_fp_abi = MIPS_ABI_FP_OLD_64;
			else
				state->fp_abi = MIPS_ABI_FP_OLD_64;
		}
		if (phdr32->p_type != PT_MIPS_ABIFLAGS)
			return 0;

		if (phdr32->p_filesz < sizeof(abiflags))
			return -EINVAL;
		pos = phdr32->p_offset;
	} else {
		if (phdr64->p_type != PT_MIPS_ABIFLAGS)
			return 0;
		if (phdr64->p_filesz < sizeof(abiflags))
			return -EINVAL;
		pos = phdr64->p_offset;
	}

	ret = kernel_read(elf, &abiflags, sizeof(abiflags), &pos);
	if (ret < 0)
		return ret;
	if (ret != sizeof(abiflags))
		return -EIO;

	/* Record the required FP ABIs for use by mips_check_elf */
	if (is_interp)
		state->interp_fp_abi = abiflags.fp_abi;
	else
		state->fp_abi = abiflags.fp_abi;

	return 0;
}

int arch_check_elf(void *_ehdr, bool has_interpreter, void *_interp_ehdr,
		   struct arch_elf_state *state)
{
	union {
		struct elf32_hdr e32;
		struct elf64_hdr e64;
	} *ehdr = _ehdr;
	union {
		struct elf32_hdr e32;
		struct elf64_hdr e64;
	} *iehdr = _interp_ehdr;
	struct mode_req prog_req, interp_req;
	int fp_abi, interp_fp_abi, abi0, abi1, max_abi;
	bool elf32;
	u32 flags;

	elf32 = ehdr->e32.e_ident[EI_CLASS] == ELFCLASS32;
	flags = elf32 ? ehdr->e32.e_flags : ehdr->e64.e_flags;

	/*
	 * Determine the NaN personality, reject the binary if not allowed.
	 * Also ensure that any interpreter matches the executable.
	 */
	if (flags & EF_MIPS_NAN2008) {
		if (mips_use_nan_2008)
			state->nan_2008 = 1;
		else
			return -ENOEXEC;
	} else {
		if (mips_use_nan_legacy)
			state->nan_2008 = 0;
		else
			return -ENOEXEC;
	}
	if (has_interpreter) {
		bool ielf32;
		u32 iflags;

		ielf32 = iehdr->e32.e_ident[EI_CLASS] == ELFCLASS32;
		iflags = ielf32 ? iehdr->e32.e_flags : iehdr->e64.e_flags;

		if ((flags ^ iflags) & EF_MIPS_NAN2008)
			return -ELIBBAD;
	}

	if (!IS_ENABLED(CONFIG_MIPS_O32_FP64_SUPPORT))
		return 0;

	fp_abi = state->fp_abi;

	if (has_interpreter) {
		interp_fp_abi = state->interp_fp_abi;

		abi0 = min(fp_abi, interp_fp_abi);
		abi1 = max(fp_abi, interp_fp_abi);
	} else {
		abi0 = abi1 = fp_abi;
	}

	if (elf32 && !(flags & EF_MIPS_ABI2)) {
		/* Default to a mode capable of running code expecting FR=0 */
		state->overall_fp_mode = cpu_has_mips_r6 ? FP_FRE : FP_FR0;

		/* Allow all ABIs we know about */
		max_abi = MIPS_ABI_FP_64A;
	} else {
		/* MIPS64 code always uses FR=1, thus the default is easy */
		state->overall_fp_mode = FP_FR1;

		/* Disallow access to the various FPXX & FP64 ABIs */
		max_abi = MIPS_ABI_FP_SOFT;
	}

	if ((abi0 > max_abi && abi0 != MIPS_ABI_FP_UNKNOWN) ||
	    (abi1 > max_abi && abi1 != MIPS_ABI_FP_UNKNOWN))
		return -ELIBBAD;

	/* It's time to determine the FPU mode requirements */
	prog_req = (abi0 == MIPS_ABI_FP_UNKNOWN) ? none_req : fpu_reqs[abi0];
	interp_req = (abi1 == MIPS_ABI_FP_UNKNOWN) ? none_req : fpu_reqs[abi1];

	/*
	 * Check whether the program's and interp's ABIs have a matching FPU
	 * mode requirement.
	 */
	prog_req.single = interp_req.single && prog_req.single;
	prog_req.soft = interp_req.soft && prog_req.soft;
	prog_req.fr1 = interp_req.fr1 && prog_req.fr1;
	prog_req.frdefault = interp_req.frdefault && prog_req.frdefault;
	prog_req.fre = interp_req.fre && prog_req.fre;

	/*
	 * Determine the desired FPU mode
	 *
	 * Decision making:
	 *
	 * - We want FR_FRE if FRE=1 and both FR=1 and FR=0 are false. This
	 *   means that we have a combination of program and interpreter
	 *   that inherently require the hybrid FP mode.
	 * - If FR1 and FRDEFAULT is true, that means we hit the any-abi or
	 *   fpxx case. This is because, in any-ABI (or no-ABI) we have no FPU
	 *   instructions so we don't care about the mode. We will simply use
	 *   the one preferred by the hardware. In fpxx case, that ABI can
	 *   handle both FR=1 and FR=0, so, again, we simply choose the one
	 *   preferred by the hardware. Next, if we only use single-precision
	 *   FPU instructions, and the default ABI FPU mode is not good
	 *   (ie single + any ABI combination), we set again the FPU mode to the
	 *   one is preferred by the hardware. Next, if we know that the code
	 *   will only use single-precision instructions, shown by single being
	 *   true but frdefault being false, then we again set the FPU mode to
	 *   the one that is preferred by the hardware.
	 * - We want FP_FR1 if that's the only matching mode and the default one
	 *   is not good.
	 * - Return with -ELIBADD if we can't find a matching FPU mode.
	 */
	if (prog_req.fre && !prog_req.frdefault && !prog_req.fr1)
		state->overall_fp_mode = FP_FRE;
	else if ((prog_req.fr1 && prog_req.frdefault) ||
		 (prog_req.single && !prog_req.frdefault))
		/* Make sure 64-bit MIPS III/IV/64R1 will not pick FR1 */
		state->overall_fp_mode = ((raw_current_cpu_data.fpu_id & MIPS_FPIR_F64) &&
					  cpu_has_mips_r2_r6) ?
					  FP_FR1 : FP_FR0;
	else if (prog_req.fr1)
		state->overall_fp_mode = FP_FR1;
	else  if (!prog_req.fre && !prog_req.frdefault &&
		  !prog_req.fr1 && !prog_req.single && !prog_req.soft)
		return -ELIBBAD;

	return 0;
}

__attribute__((used)) static inline void set_thread_fp_mode(int hybrid, int regs32)
{
	if (hybrid)
		set_thread_flag(TIF_HYBRID_FPREGS);
	else
		clear_thread_flag(TIF_HYBRID_FPREGS);
	if (regs32)
		set_thread_flag(TIF_32BIT_FPREGS);
	else
		clear_thread_flag(TIF_32BIT_FPREGS);
}

void mips_set_personality_fp(struct arch_elf_state *state)
{
	/*
	 * This function is only ever called for O32 ELFs so we should
	 * not be worried about N32/N64 binaries.
	 */

	if (!IS_ENABLED(CONFIG_MIPS_O32_FP64_SUPPORT))
		return;

	switch (state->overall_fp_mode) {
	case FP_FRE:
		set_thread_fp_mode(1, 0);
		break;
	case FP_FR0:
		set_thread_fp_mode(0, 1);
		break;
	case FP_FR1:
		set_thread_fp_mode(0, 0);
		break;
	default:
		BUG();
	}
}

void mips_set_personality_nan(struct arch_elf_state *state)
{
	struct cpuinfo_mips *c = &boot_cpu_data;
	struct task_struct *t = current;

	t->thread.fpu.fcr31 = c->fpu_csr31;
	switch (state->nan_2008) {
	case 0:
		break;
	case 1:
		if (!(c->fpu_msk31 & FPU_CSR_NAN2008))
			t->thread.fpu.fcr31 |= FPU_CSR_NAN2008;
		if (!(c->fpu_msk31 & FPU_CSR_ABS2008))
			t->thread.fpu.fcr31 |= FPU_CSR_ABS2008;
		break;
	default:
		BUG();
	}
}

int mips_elf_read_implies_exec(void *elf_ex, int exstack)
{
	if (exstack != EXSTACK_DISABLE_X) {
		/* The binary doesn't request a non-executable stack */
		return 1;
	}

	if (!cpu_has_rixi) {
		/* The CPU doesn't support non-executable memory */
		return 1;
	}

	return 0;
}

