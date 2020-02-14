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
struct thread_info {int /*<<< orphan*/  addr_limit; int /*<<< orphan*/  status; } ;
struct TYPE_2__ {unsigned long sp; unsigned long pc; scalar_t__ fpu_counter; struct pt_regs* ptrace_bps; } ;
struct task_struct {int flags; scalar_t__ state; TYPE_1__ thread; } ;
struct pt_regs {unsigned long pr; unsigned long pc; unsigned long* regs; unsigned long mach; unsigned long macl; unsigned long gbr; int /*<<< orphan*/  sr; } ;
typedef  int /*<<< orphan*/  elf_fpregset_t ;

/* Variables and functions */
 unsigned long CLONE_SETTLS ; 
 int /*<<< orphan*/  KERNEL_DS ; 
 int /*<<< orphan*/  KERN_DEFAULT ; 
 int PF_KTHREAD ; 
 int /*<<< orphan*/  SR_FD ; 
 int /*<<< orphan*/  SR_MD ; 
 scalar_t__ TASK_RUNNING ; 
 int /*<<< orphan*/  TS_USEDFPU ; 
 int /*<<< orphan*/  USER_DS ; 
 struct task_struct* current ; 
 struct pt_regs* current_pt_regs () ; 
 int /*<<< orphan*/  flush_ptrace_hw_breakpoint (struct task_struct*) ; 
 int /*<<< orphan*/  free_thread_xstate (struct task_struct*) ; 
 scalar_t__ instruction_pointer (struct pt_regs*) ; 
 int /*<<< orphan*/  memset (struct pt_regs*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 scalar_t__ ret_from_fork ; 
 scalar_t__ ret_from_kernel_thread ; 
 int /*<<< orphan*/  show_code (struct pt_regs*) ; 
 int /*<<< orphan*/  show_regs_print_info (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  show_trace (int /*<<< orphan*/ *,unsigned long*,struct pt_regs*) ; 
 struct pt_regs* task_pt_regs (struct task_struct*) ; 
 struct thread_info* task_thread_info (struct task_struct*) ; 
 unsigned long thread_saved_pc (struct task_struct*) ; 
 scalar_t__ unlikely (int) ; 

void show_regs(struct pt_regs * regs)
{
	printk("\n");
	show_regs_print_info(KERN_DEFAULT);

	printk("PC is at %pS\n", (void *)instruction_pointer(regs));
	printk("PR is at %pS\n", (void *)regs->pr);

	printk("PC  : %08lx SP  : %08lx SR  : %08lx ",
	       regs->pc, regs->regs[15], regs->sr);
#ifdef CONFIG_MMU
	printk("TEA : %08x\n", __raw_readl(MMU_TEA));
#else
	printk("\n");
#endif

	printk("R0  : %08lx R1  : %08lx R2  : %08lx R3  : %08lx\n",
	       regs->regs[0],regs->regs[1],
	       regs->regs[2],regs->regs[3]);
	printk("R4  : %08lx R5  : %08lx R6  : %08lx R7  : %08lx\n",
	       regs->regs[4],regs->regs[5],
	       regs->regs[6],regs->regs[7]);
	printk("R8  : %08lx R9  : %08lx R10 : %08lx R11 : %08lx\n",
	       regs->regs[8],regs->regs[9],
	       regs->regs[10],regs->regs[11]);
	printk("R12 : %08lx R13 : %08lx R14 : %08lx\n",
	       regs->regs[12],regs->regs[13],
	       regs->regs[14]);
	printk("MACH: %08lx MACL: %08lx GBR : %08lx PR  : %08lx\n",
	       regs->mach, regs->macl, regs->gbr, regs->pr);

	show_trace(NULL, (unsigned long *)regs->regs[15], regs);
	show_code(regs);
}

void start_thread(struct pt_regs *regs, unsigned long new_pc,
		  unsigned long new_sp)
{
	regs->pr = 0;
	regs->sr = SR_FD;
	regs->pc = new_pc;
	regs->regs[15] = new_sp;

	free_thread_xstate(current);
}

void flush_thread(void)
{
	struct task_struct *tsk = current;

	flush_ptrace_hw_breakpoint(tsk);

#if defined(CONFIG_SH_FPU)
	/* Forget lazy FPU state */
	clear_fpu(tsk, task_pt_regs(tsk));
	clear_used_math();
#endif
}

void release_thread(struct task_struct *dead_task)
{
	/* do nothing */
}

int dump_fpu(struct pt_regs *regs, elf_fpregset_t *fpu)
{
	int fpvalid = 0;

#if defined(CONFIG_SH_FPU)
	struct task_struct *tsk = current;

	fpvalid = !!tsk_used_math(tsk);
	if (fpvalid)
		fpvalid = !fpregs_get(tsk, NULL, 0,
				      sizeof(struct user_fpu_struct),
				      fpu, NULL);
#endif

	return fpvalid;
}

int copy_thread(unsigned long clone_flags, unsigned long usp,
		unsigned long arg, struct task_struct *p)
{
	struct thread_info *ti = task_thread_info(p);
	struct pt_regs *childregs;

#if defined(CONFIG_SH_DSP)
	struct task_struct *tsk = current;

	if (is_dsp_enabled(tsk)) {
		/* We can use the __save_dsp or just copy the struct:
		 * __save_dsp(p);
		 * p->thread.dsp_status.status |= SR_DSP
		 */
		p->thread.dsp_status = tsk->thread.dsp_status;
	}
#endif

	memset(p->thread.ptrace_bps, 0, sizeof(p->thread.ptrace_bps));

	childregs = task_pt_regs(p);
	p->thread.sp = (unsigned long) childregs;
	if (unlikely(p->flags & PF_KTHREAD)) {
		memset(childregs, 0, sizeof(struct pt_regs));
		p->thread.pc = (unsigned long) ret_from_kernel_thread;
		childregs->regs[4] = arg;
		childregs->regs[5] = usp;
		childregs->sr = SR_MD;
#if defined(CONFIG_SH_FPU)
		childregs->sr |= SR_FD;
#endif
		ti->addr_limit = KERNEL_DS;
		ti->status &= ~TS_USEDFPU;
		p->thread.fpu_counter = 0;
		return 0;
	}
	*childregs = *current_pt_regs();

	if (usp)
		childregs->regs[15] = usp;
	ti->addr_limit = USER_DS;

	if (clone_flags & CLONE_SETTLS)
		childregs->gbr = childregs->regs[0];

	childregs->regs[0] = 0; /* Set return value for child */
	p->thread.pc = (unsigned long) ret_from_fork;
	return 0;
}

unsigned long get_wchan(struct task_struct *p)
{
	unsigned long pc;

	if (!p || p == current || p->state == TASK_RUNNING)
		return 0;

	/*
	 * The same comment as on the Alpha applies here, too ...
	 */
	pc = thread_saved_pc(p);

#ifdef CONFIG_FRAME_POINTER
	if (in_sched_functions(pc)) {
		unsigned long schedule_frame = (unsigned long)p->thread.sp;
		return ((unsigned long *)schedule_frame)[21];
	}
#endif

	return pc;
}

