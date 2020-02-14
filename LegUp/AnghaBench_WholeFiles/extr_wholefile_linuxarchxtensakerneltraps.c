#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct task_struct {int dummy; } ;
struct pt_regs {scalar_t__* areg; int /*<<< orphan*/  pc; } ;
struct TYPE_4__ {int /*<<< orphan*/  comm; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_PREEMPT ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOCKDEP_NOW_UNRELIABLE ; 
 unsigned int LOCKLEVEL ; 
 int /*<<< orphan*/  SIGILL ; 
 long SIGKILL ; 
 int /*<<< orphan*/  SIGTRAP ; 
 int /*<<< orphan*/  TAINT_DIE ; 
#define  XCHAL_INTLEVEL1_MASK 134 
#define  XCHAL_INTLEVEL2_MASK 133 
#define  XCHAL_INTLEVEL3_MASK 132 
#define  XCHAL_INTLEVEL4_MASK 131 
#define  XCHAL_INTLEVEL5_MASK 130 
#define  XCHAL_INTLEVEL6_MASK 129 
#define  XCHAL_INTLEVEL7_MASK 128 
 int /*<<< orphan*/  __ffs (unsigned int) ; 
 int /*<<< orphan*/  add_taint (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  console_verbose () ; 
 TYPE_1__* current ; 
 void die (char const*,struct pt_regs*,long) ; 
 int /*<<< orphan*/  die_lock ; 
 int /*<<< orphan*/  do_IRQ (int /*<<< orphan*/ ,struct pt_regs*) ; 
 int /*<<< orphan*/  do_exit (long) ; 
 int /*<<< orphan*/  force_sig (int /*<<< orphan*/ ,TYPE_1__*) ; 
 unsigned int get_sr (int /*<<< orphan*/ ) ; 
 scalar_t__ in_interrupt () ; 
 unsigned int intenable ; 
 int /*<<< orphan*/  interrupt ; 
 int /*<<< orphan*/  irq_enter () ; 
 int /*<<< orphan*/  irq_exit () ; 
 int kstack_depth_to_print ; 
 scalar_t__ kstack_end (unsigned long*) ; 
 int /*<<< orphan*/  panic (char*) ; 
 scalar_t__ panic_on_oops ; 
 int /*<<< orphan*/  pr_cont (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 struct pt_regs* set_irq_regs (struct pt_regs*) ; 
 int /*<<< orphan*/  show_regs (struct pt_regs*) ; 
 int /*<<< orphan*/  show_trace (struct task_struct*,unsigned long*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 unsigned long* stack_pointer (struct task_struct*) ; 
 int /*<<< orphan*/  task_pid_nr (TYPE_1__*) ; 
 int /*<<< orphan*/  trace_hardirqs_off () ; 
 int /*<<< orphan*/  user_mode (struct pt_regs*) ; 

__attribute__((used)) static inline void
__die_if_kernel(const char *str, struct pt_regs *regs, long err)
{
	if (!user_mode(regs))
		die(str, regs, err);
}

void do_unhandled(struct pt_regs *regs, unsigned long exccause)
{
	__die_if_kernel("Caught unhandled exception - should not happen",
			regs, SIGKILL);

	/* If in user mode, send SIGILL signal to current process */
	pr_info_ratelimited("Caught unhandled exception in '%s' "
			    "(pid = %d, pc = %#010lx) - should not happen\n"
			    "\tEXCCAUSE is %ld\n",
			    current->comm, task_pid_nr(current), regs->pc,
			    exccause);
	force_sig(SIGILL, current);
}

void do_multihit(struct pt_regs *regs, unsigned long exccause)
{
	die("Caught multihit exception", regs, SIGKILL);
}

void do_interrupt(struct pt_regs *regs)
{
	static const unsigned int_level_mask[] = {
		0,
		XCHAL_INTLEVEL1_MASK,
		XCHAL_INTLEVEL2_MASK,
		XCHAL_INTLEVEL3_MASK,
		XCHAL_INTLEVEL4_MASK,
		XCHAL_INTLEVEL5_MASK,
		XCHAL_INTLEVEL6_MASK,
		XCHAL_INTLEVEL7_MASK,
	};
	struct pt_regs *old_regs;

	trace_hardirqs_off();

	old_regs = set_irq_regs(regs);
	irq_enter();

	for (;;) {
		unsigned intread = get_sr(interrupt);
		unsigned intenable = get_sr(intenable);
		unsigned int_at_level = intread & intenable;
		unsigned level;

		for (level = LOCKLEVEL; level > 0; --level) {
			if (int_at_level & int_level_mask[level]) {
				int_at_level &= int_level_mask[level];
				break;
			}
		}

		if (level == 0)
			break;

		do_IRQ(__ffs(int_at_level), regs);
	}

	irq_exit();
	set_irq_regs(old_regs);
}

void
do_illegal_instruction(struct pt_regs *regs)
{
	__die_if_kernel("Illegal instruction in kernel", regs, SIGKILL);

	/* If in user mode, send SIGILL signal to current process. */

	pr_info_ratelimited("Illegal Instruction in '%s' (pid = %d, pc = %#010lx)\n",
			    current->comm, task_pid_nr(current), regs->pc);
	force_sig(SIGILL, current);
}

void
do_debug(struct pt_regs *regs)
{
#ifdef CONFIG_HAVE_HW_BREAKPOINT
	int ret = check_hw_breakpoint(regs);

	preempt_enable();
	if (ret == 0)
		return;
#endif
	__die_if_kernel("Breakpoint in kernel", regs, SIGKILL);

	/* If in user mode, send SIGTRAP signal to current process */

	force_sig(SIGTRAP, current);
}

void show_stack(struct task_struct *task, unsigned long *sp)
{
	int i = 0;
	unsigned long *stack;

	if (!sp)
		sp = stack_pointer(task);
	stack = sp;

	pr_info("Stack:\n");

	for (i = 0; i < kstack_depth_to_print; i++) {
		if (kstack_end(sp))
			break;
		pr_cont(" %08lx", *sp++);
		if (i % 8 == 7)
			pr_cont("\n");
	}
	show_trace(task, stack);
}

void die(const char * str, struct pt_regs * regs, long err)
{
	static int die_counter;

	console_verbose();
	spin_lock_irq(&die_lock);

	pr_info("%s: sig: %ld [#%d]%s\n", str, err, ++die_counter,
		IS_ENABLED(CONFIG_PREEMPT) ? " PREEMPT" : "");
	show_regs(regs);
	if (!user_mode(regs))
		show_stack(NULL, (unsigned long*)regs->areg[1]);

	add_taint(TAINT_DIE, LOCKDEP_NOW_UNRELIABLE);
	spin_unlock_irq(&die_lock);

	if (in_interrupt())
		panic("Fatal exception in interrupt");

	if (panic_on_oops)
		panic("Fatal exception");

	do_exit(err);
}

