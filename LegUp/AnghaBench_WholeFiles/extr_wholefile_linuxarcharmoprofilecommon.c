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
struct stackframe {int /*<<< orphan*/  pc; } ;
struct pt_regs {scalar_t__ ARM_fp; } ;
struct frame_tail {struct frame_tail* fp; int /*<<< orphan*/  lr; } ;
typedef  int /*<<< orphan*/  buftail ;

/* Variables and functions */
 int /*<<< orphan*/  VERIFY_READ ; 
 scalar_t__ __copy_from_user_inatomic (struct frame_tail*,struct frame_tail*,int) ; 
 int /*<<< orphan*/  access_ok (int /*<<< orphan*/ ,struct frame_tail*,int) ; 
 int /*<<< orphan*/  arm_get_current_stackframe (struct pt_regs* const,struct stackframe*) ; 
 int /*<<< orphan*/  oprofile_add_trace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  user_mode (struct pt_regs* const) ; 
 int /*<<< orphan*/  walk_stackframe (struct stackframe*,int (*) (struct stackframe*,void*),unsigned int*) ; 

__attribute__((used)) static int report_trace(struct stackframe *frame, void *d)
{
	unsigned int *depth = d;

	if (*depth) {
		oprofile_add_trace(frame->pc);
		(*depth)--;
	}

	return *depth == 0;
}

__attribute__((used)) static struct frame_tail* user_backtrace(struct frame_tail *tail)
{
	struct frame_tail buftail[2];

	/* Also check accessibility of one struct frame_tail beyond */
	if (!access_ok(VERIFY_READ, tail, sizeof(buftail)))
		return NULL;
	if (__copy_from_user_inatomic(buftail, tail, sizeof(buftail)))
		return NULL;

	oprofile_add_trace(buftail[0].lr);

	/* frame pointers should strictly progress back up the stack
	 * (towards higher addresses) */
	if (tail + 1 >= buftail[0].fp)
		return NULL;

	return buftail[0].fp-1;
}

__attribute__((used)) static void arm_backtrace(struct pt_regs * const regs, unsigned int depth)
{
	struct frame_tail *tail = ((struct frame_tail *) regs->ARM_fp) - 1;

	if (!user_mode(regs)) {
		struct stackframe frame;
		arm_get_current_stackframe(regs, &frame);
		walk_stackframe(&frame, report_trace, &depth);
		return;
	}

	while (depth-- && tail && !((unsigned long) tail & 3))
		tail = user_backtrace(tail);
}

