#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u_long ;
struct unw_frame_info {int dummy; } ;
struct switch_stack {int dummy; } ;
struct pt_regs {int /*<<< orphan*/  ar_pfs; } ;
struct TYPE_10__ {unsigned long ip; int /*<<< orphan*/ * pfs_loc; } ;
struct TYPE_9__ {unsigned int depth; int /*<<< orphan*/ * prev_pfs_loc; struct pt_regs* regs; TYPE_2__ frame; } ;
typedef  TYPE_1__ ia64_backtrace_t ;

/* Variables and functions */
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  oprofile_add_trace (unsigned long) ; 
 int /*<<< orphan*/  unw_get_ip (TYPE_2__*,unsigned long*) ; 
 int /*<<< orphan*/  unw_get_sp (TYPE_2__*,unsigned long*) ; 
 int /*<<< orphan*/  unw_init_frame_info (TYPE_2__*,int /*<<< orphan*/ ,struct switch_stack*) ; 
 int /*<<< orphan*/  unw_init_running (void (*) (struct unw_frame_info*,void*),TYPE_1__*) ; 
 scalar_t__ unw_is_intr_frame (TYPE_2__*) ; 
 scalar_t__ unw_unwind (TYPE_2__*) ; 
 scalar_t__ user_mode (struct pt_regs* const) ; 

__attribute__((used)) static __inline__ int in_ivt_code(unsigned long pc)
{
	extern char ia64_ivt[];
	return (pc >= (u_long)ia64_ivt && pc < (u_long)ia64_ivt+32768);
}

__attribute__((used)) static __inline__ int next_frame(ia64_backtrace_t *bt)
{
	/*
	 * Avoid unsightly console message from unw_unwind() when attempting
	 * to unwind through the Interrupt Vector Table which has no unwind
	 * information.
	 */
	if (in_ivt_code(bt->frame.ip))
		return 0;

	/*
	 * WAR for spinlock contention from leaf functions.  ia64_spinlock_contention_pre3_4
	 * has ar.pfs == r0.  Leaf functions do not modify ar.pfs so ar.pfs remains
	 * as 0, stopping the backtrace.  Record the previous ar.pfs when the current
	 * IP is in ia64_spinlock_contention_pre3_4 then unwind, if pfs_loc has not changed
	 * after unwind then use pt_regs.ar_pfs which is where the real ar.pfs is for
	 * leaf functions.
	 */
	if (bt->prev_pfs_loc && bt->regs && bt->frame.pfs_loc == bt->prev_pfs_loc)
		bt->frame.pfs_loc = &bt->regs->ar_pfs;
	bt->prev_pfs_loc = NULL;

	return unw_unwind(&bt->frame) == 0;
}

__attribute__((used)) static void do_ia64_backtrace(struct unw_frame_info *info, void *vdata)
{
	ia64_backtrace_t *bt = vdata;
	struct switch_stack *sw;
	int count = 0;
	u_long pc, sp;

	sw = (struct switch_stack *)(info+1);
	/* padding from unw_init_running */
	sw = (struct switch_stack *)(((unsigned long)sw + 15) & ~15);

	unw_init_frame_info(&bt->frame, current, sw);

	/* skip over interrupt frame and oprofile calls */
	do {
		unw_get_sp(&bt->frame, &sp);
		if (sp >= (u_long)bt->regs)
			break;
		if (!next_frame(bt))
			return;
	} while (count++ < 200);

	/* finally, grab the actual sample */
	while (bt->depth-- && next_frame(bt)) {
		unw_get_ip(&bt->frame, &pc);
		oprofile_add_trace(pc);
		if (unw_is_intr_frame(&bt->frame)) {
			/*
			 * Interrupt received on kernel stack; this can
			 * happen when timer interrupt fires while processing
			 * a softirq from the tail end of a hardware interrupt
			 * which interrupted a system call.  Don't laugh, it
			 * happens!  Splice the backtrace into two parts to
			 * avoid spurious cycles in the gprof output.
			 */
			/* TODO: split rather than drop the 2nd half */
			break;
		}
	}
}

void
ia64_backtrace(struct pt_regs * const regs, unsigned int depth)
{
	ia64_backtrace_t bt;
	unsigned long flags;

	/*
	 * On IA64 there is little hope of getting backtraces from
	 * user space programs -- the problems of getting the unwind
	 * information from arbitrary user programs are extreme.
	 */
	if (user_mode(regs))
		return;

	bt.depth = depth;
	bt.regs = regs;
	bt.prev_pfs_loc = NULL;
	local_irq_save(flags);
	unw_init_running(do_ia64_backtrace, &bt);
	local_irq_restore(flags);
}

