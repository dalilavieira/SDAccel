#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {unsigned long* gregs; unsigned long version; } ;
struct ucontext {unsigned long uc_flags; unsigned long uc_link; int /*<<< orphan*/  uc_sigmask; int /*<<< orphan*/  uc_stack; TYPE_2__ uc_mcontext; } ;
struct switch_stack {int r16; int r17; int r18; int r19; int r20; int r21; int r22; int r23; int fp; int gp; } ;
struct rt_sigframe {struct ucontext uc; int /*<<< orphan*/  info; } ;
struct pt_regs {int r1; int r2; int r3; int r4; int r5; int r6; int r7; int r8; int r9; int r10; int r11; int r12; int r13; int r14; int r15; int ea; int ra; int sp; int orig_r2; int orig_r7; } ;
struct TYPE_11__ {int sa_flags; scalar_t__ sa_handler; } ;
struct TYPE_12__ {TYPE_4__ sa; } ;
struct ksignal {TYPE_5__ ka; scalar_t__ sig; int /*<<< orphan*/  info; } ;
typedef  int /*<<< orphan*/  sigset_t ;
struct TYPE_10__ {struct pt_regs* kregs; } ;
struct TYPE_8__ {int /*<<< orphan*/  fn; } ;
struct TYPE_13__ {TYPE_3__ thread; TYPE_1__ restart_block; } ;

/* Variables and functions */
 int EFAULT ; 
 scalar_t__ EINTR ; 
#define  ERESTARTNOHAND 131 
#define  ERESTARTNOINTR 130 
#define  ERESTARTSYS 129 
#define  ERESTART_RESTARTBLOCK 128 
 int MCONTEXT_VERSION ; 
 int SA_RESTART ; 
 int SA_SIGINFO ; 
 scalar_t__ __NR_restart_syscall ; 
 int __get_user (int,unsigned long*) ; 
 int __put_user (int,unsigned long*) ; 
 int __save_altstack (int /*<<< orphan*/ *,unsigned long) ; 
 int copy_siginfo_to_user (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int copy_to_user (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 TYPE_6__* current ; 
 int /*<<< orphan*/  do_no_restart_syscall ; 
 int /*<<< orphan*/  force_sigsegv (scalar_t__,TYPE_6__*) ; 
 scalar_t__ get_signal (struct ksignal*) ; 
 int restore_altstack (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  restore_saved_sigmask () ; 
 int /*<<< orphan*/ * sigmask_to_save () ; 
 int /*<<< orphan*/  signal_setup_done (int,struct ksignal*,int /*<<< orphan*/ ) ; 
 unsigned long sigsp (unsigned long,struct ksignal*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline int rt_restore_ucontext(struct pt_regs *regs,
					struct switch_stack *sw,
					struct ucontext *uc, int *pr2)
{
	int temp;
	unsigned long *gregs = uc->uc_mcontext.gregs;
	int err;

	/* Always make any pending restarted system calls return -EINTR */
	current->restart_block.fn = do_no_restart_syscall;

	err = __get_user(temp, &uc->uc_mcontext.version);
	if (temp != MCONTEXT_VERSION)
		goto badframe;
	/* restore passed registers */
	err |= __get_user(regs->r1, &gregs[0]);
	err |= __get_user(regs->r2, &gregs[1]);
	err |= __get_user(regs->r3, &gregs[2]);
	err |= __get_user(regs->r4, &gregs[3]);
	err |= __get_user(regs->r5, &gregs[4]);
	err |= __get_user(regs->r6, &gregs[5]);
	err |= __get_user(regs->r7, &gregs[6]);
	err |= __get_user(regs->r8, &gregs[7]);
	err |= __get_user(regs->r9, &gregs[8]);
	err |= __get_user(regs->r10, &gregs[9]);
	err |= __get_user(regs->r11, &gregs[10]);
	err |= __get_user(regs->r12, &gregs[11]);
	err |= __get_user(regs->r13, &gregs[12]);
	err |= __get_user(regs->r14, &gregs[13]);
	err |= __get_user(regs->r15, &gregs[14]);
	err |= __get_user(sw->r16, &gregs[15]);
	err |= __get_user(sw->r17, &gregs[16]);
	err |= __get_user(sw->r18, &gregs[17]);
	err |= __get_user(sw->r19, &gregs[18]);
	err |= __get_user(sw->r20, &gregs[19]);
	err |= __get_user(sw->r21, &gregs[20]);
	err |= __get_user(sw->r22, &gregs[21]);
	err |= __get_user(sw->r23, &gregs[22]);
	/* gregs[23] is handled below */
	err |= __get_user(sw->fp, &gregs[24]);  /* Verify, should this be
							settable */
	err |= __get_user(sw->gp, &gregs[25]);  /* Verify, should this be
							settable */

	err |= __get_user(temp, &gregs[26]);  /* Not really necessary no user
							settable bits */
	err |= __get_user(regs->ea, &gregs[27]);

	err |= __get_user(regs->ra, &gregs[23]);
	err |= __get_user(regs->sp, &gregs[28]);

	regs->orig_r2 = -1;		/* disable syscall checks */

	err |= restore_altstack(&uc->uc_stack);
	if (err)
		goto badframe;

	*pr2 = regs->r2;
	return err;

badframe:
	return 1;
}

__attribute__((used)) static inline int rt_setup_ucontext(struct ucontext *uc, struct pt_regs *regs)
{
	struct switch_stack *sw = (struct switch_stack *)regs - 1;
	unsigned long *gregs = uc->uc_mcontext.gregs;
	int err = 0;

	err |= __put_user(MCONTEXT_VERSION, &uc->uc_mcontext.version);
	err |= __put_user(regs->r1, &gregs[0]);
	err |= __put_user(regs->r2, &gregs[1]);
	err |= __put_user(regs->r3, &gregs[2]);
	err |= __put_user(regs->r4, &gregs[3]);
	err |= __put_user(regs->r5, &gregs[4]);
	err |= __put_user(regs->r6, &gregs[5]);
	err |= __put_user(regs->r7, &gregs[6]);
	err |= __put_user(regs->r8, &gregs[7]);
	err |= __put_user(regs->r9, &gregs[8]);
	err |= __put_user(regs->r10, &gregs[9]);
	err |= __put_user(regs->r11, &gregs[10]);
	err |= __put_user(regs->r12, &gregs[11]);
	err |= __put_user(regs->r13, &gregs[12]);
	err |= __put_user(regs->r14, &gregs[13]);
	err |= __put_user(regs->r15, &gregs[14]);
	err |= __put_user(sw->r16, &gregs[15]);
	err |= __put_user(sw->r17, &gregs[16]);
	err |= __put_user(sw->r18, &gregs[17]);
	err |= __put_user(sw->r19, &gregs[18]);
	err |= __put_user(sw->r20, &gregs[19]);
	err |= __put_user(sw->r21, &gregs[20]);
	err |= __put_user(sw->r22, &gregs[21]);
	err |= __put_user(sw->r23, &gregs[22]);
	err |= __put_user(regs->ra, &gregs[23]);
	err |= __put_user(sw->fp, &gregs[24]);
	err |= __put_user(sw->gp, &gregs[25]);
	err |= __put_user(regs->ea, &gregs[27]);
	err |= __put_user(regs->sp, &gregs[28]);
	return err;
}

__attribute__((used)) static inline void *get_sigframe(struct ksignal *ksig, struct pt_regs *regs,
				 size_t frame_size)
{
	unsigned long usp;

	/* Default to using normal stack.  */
	usp = regs->sp;

	/* This is the X/Open sanctioned signal stack switching.  */
	usp = sigsp(usp, ksig);

	/* Verify, is it 32 or 64 bit aligned */
	return (void *)((usp - frame_size) & -8UL);
}

__attribute__((used)) static int setup_rt_frame(struct ksignal *ksig, sigset_t *set,
			  struct pt_regs *regs)
{
	struct rt_sigframe *frame;
	int err = 0;

	frame = get_sigframe(ksig, regs, sizeof(*frame));

	if (ksig->ka.sa.sa_flags & SA_SIGINFO)
		err |= copy_siginfo_to_user(&frame->info, &ksig->info);

	/* Create the ucontext.  */
	err |= __put_user(0, &frame->uc.uc_flags);
	err |= __put_user(0, &frame->uc.uc_link);
	err |= __save_altstack(&frame->uc.uc_stack, regs->sp);
	err |= rt_setup_ucontext(&frame->uc, regs);
	err |= copy_to_user(&frame->uc.uc_sigmask, set, sizeof(*set));

	if (err)
		goto give_sigsegv;

	/* Set up to return from userspace; jump to fixed address sigreturn
	   trampoline on kuser page.  */
	regs->ra = (unsigned long) (0x1044);

	/* Set up registers for signal handler */
	regs->sp = (unsigned long) frame;
	regs->r4 = (unsigned long) ksig->sig;
	regs->r5 = (unsigned long) &frame->info;
	regs->r6 = (unsigned long) &frame->uc;
	regs->ea = (unsigned long) ksig->ka.sa.sa_handler;
	return 0;

give_sigsegv:
	force_sigsegv(ksig->sig, current);
	return -EFAULT;
}

__attribute__((used)) static void handle_signal(struct ksignal *ksig, struct pt_regs *regs)
{
	int ret;
	sigset_t *oldset = sigmask_to_save();

	/* set up the stack frame */
	ret = setup_rt_frame(ksig, oldset, regs);

	signal_setup_done(ret, ksig, 0);
}

__attribute__((used)) static int do_signal(struct pt_regs *regs)
{
	unsigned int retval = 0, continue_addr = 0, restart_addr = 0;
	int restart = 0;
	struct ksignal ksig;

	current->thread.kregs = regs;

	/*
	 * If we were from a system call, check for system call restarting...
	 */
	if (regs->orig_r2 >= 0) {
		continue_addr = regs->ea;
		restart_addr = continue_addr - 4;
		retval = regs->r2;

		/*
		 * Prepare for system call restart. We do this here so that a
		 * debugger will see the already changed PC.
		 */
		switch (retval) {
		case ERESTART_RESTARTBLOCK:
			restart = -2;
		case ERESTARTNOHAND:
		case ERESTARTSYS:
		case ERESTARTNOINTR:
			restart++;
			regs->r2 = regs->orig_r2;
			regs->r7 = regs->orig_r7;
			regs->ea = restart_addr;
			break;
		}
	}

	if (get_signal(&ksig)) {
		/* handler */
		if (unlikely(restart && regs->ea == restart_addr)) {
			if (retval == ERESTARTNOHAND ||
			    retval == ERESTART_RESTARTBLOCK ||
			     (retval == ERESTARTSYS
				&& !(ksig.ka.sa.sa_flags & SA_RESTART))) {
				regs->r2 = EINTR;
				regs->r7 = 1;
				regs->ea = continue_addr;
			}
		}
		handle_signal(&ksig, regs);
		return 0;
	}

	/*
	 * No handler present
	 */
	if (unlikely(restart) && regs->ea == restart_addr) {
		regs->ea = continue_addr;
		regs->r2 = __NR_restart_syscall;
	}

	/*
	* If there's no signal to deliver, we just put the saved sigmask back.
	*/
	restore_saved_sigmask();

	return restart;
}

