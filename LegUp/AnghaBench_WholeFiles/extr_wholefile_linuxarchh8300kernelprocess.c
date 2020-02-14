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
struct thread_info {int dummy; } ;
struct TYPE_2__ {unsigned long ksp; int /*<<< orphan*/  usp; } ;
struct task_struct {int flags; scalar_t__ state; TYPE_1__ thread; } ;
struct pt_regs {unsigned long er4; unsigned long er5; unsigned long er6; unsigned long retpc; scalar_t__ er0; int /*<<< orphan*/  er3; int /*<<< orphan*/  er2; int /*<<< orphan*/  er1; int /*<<< orphan*/  orig_er0; int /*<<< orphan*/  ccr; int /*<<< orphan*/  pc; } ;

/* Variables and functions */
 int /*<<< orphan*/  KERN_DEFAULT ; 
 int PF_KTHREAD ; 
 scalar_t__ TASK_RUNNING ; 
 scalar_t__ THREAD_SIZE ; 
 struct task_struct* current ; 
 struct pt_regs* current_pt_regs () ; 
 int /*<<< orphan*/  in_sched_functions (unsigned long) ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  memset (struct pt_regs*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_notice (char*,...) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int /*<<< orphan*/  rdusp () ; 
 scalar_t__ ret_from_fork ; 
 scalar_t__ ret_from_kernel_thread ; 
 int /*<<< orphan*/  show_regs_print_info (int /*<<< orphan*/ ) ; 
 scalar_t__ task_stack_page (struct task_struct*) ; 
 scalar_t__ unlikely (int) ; 
 scalar_t__ user_mode (struct pt_regs*) ; 

void arch_cpu_idle(void)
{
	local_irq_enable();
	__asm__("sleep");
}

void machine_restart(char *__unused)
{
	local_irq_disable();
	__asm__("jmp @@0");
}

void machine_halt(void)
{
	local_irq_disable();
	__asm__("sleep");
	for (;;)
		;
}

void machine_power_off(void)
{
	local_irq_disable();
	__asm__("sleep");
	for (;;)
		;
}

void show_regs(struct pt_regs *regs)
{
	show_regs_print_info(KERN_DEFAULT);

	pr_notice("\n");
	pr_notice("PC: %08lx  Status: %02x\n",
	       regs->pc, regs->ccr);
	pr_notice("ORIG_ER0: %08lx ER0: %08lx ER1: %08lx\n",
	       regs->orig_er0, regs->er0, regs->er1);
	pr_notice("ER2: %08lx ER3: %08lx ER4: %08lx ER5: %08lx\n",
	       regs->er2, regs->er3, regs->er4, regs->er5);
	pr_notice("ER6' %08lx ", regs->er6);
	if (user_mode(regs))
		printk("USP: %08lx\n", rdusp());
	else
		printk("\n");
}

void flush_thread(void)
{
}

int copy_thread(unsigned long clone_flags,
		unsigned long usp, unsigned long topstk,
		struct task_struct *p)
{
	struct pt_regs *childregs;

	childregs = (struct pt_regs *) (THREAD_SIZE + task_stack_page(p)) - 1;

	if (unlikely(p->flags & PF_KTHREAD)) {
		memset(childregs, 0, sizeof(struct pt_regs));
		childregs->retpc = (unsigned long) ret_from_kernel_thread;
		childregs->er4 = topstk; /* arg */
		childregs->er5 = usp; /* fn */
	}  else {
		*childregs = *current_pt_regs();
		childregs->er0 = 0;
		childregs->retpc = (unsigned long) ret_from_fork;
		p->thread.usp = usp ?: rdusp();
	}
	p->thread.ksp = (unsigned long)childregs;

	return 0;
}

unsigned long get_wchan(struct task_struct *p)
{
	unsigned long fp, pc;
	unsigned long stack_page;
	int count = 0;

	if (!p || p == current || p->state == TASK_RUNNING)
		return 0;

	stack_page = (unsigned long)p;
	fp = ((struct pt_regs *)p->thread.ksp)->er6;
	do {
		if (fp < stack_page+sizeof(struct thread_info) ||
		    fp >= 8184+stack_page)
			return 0;
		pc = ((unsigned long *)fp)[1];
		if (!in_sched_functions(pc))
			return pc;
		fp = *(unsigned long *) fp;
	} while (count++ < 16);
	return 0;
}

