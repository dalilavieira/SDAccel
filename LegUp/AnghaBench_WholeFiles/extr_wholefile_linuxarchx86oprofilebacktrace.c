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
struct unwind_state {int dummy; } ;
struct stack_frame {unsigned long return_address; struct stack_frame* next_frame; } ;
struct pt_regs {unsigned long ip; } ;
typedef  int /*<<< orphan*/  bufhead ;

/* Variables and functions */
 unsigned long copy_from_user_nmi (struct stack_frame*,struct stack_frame*,int) ; 
 int /*<<< orphan*/  current ; 
 scalar_t__ frame_pointer (struct pt_regs* const) ; 
 int /*<<< orphan*/  oprofile_add_trace (unsigned long) ; 
 int /*<<< orphan*/  unwind_done (struct unwind_state*) ; 
 unsigned long unwind_get_return_address (struct unwind_state*) ; 
 int /*<<< orphan*/  unwind_next_frame (struct unwind_state*) ; 
 int /*<<< orphan*/  unwind_start (struct unwind_state*,int /*<<< orphan*/ ,struct pt_regs* const,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  user_mode (struct pt_regs* const) ; 

__attribute__((used)) static inline int
x86_backtrace_32(struct pt_regs * const regs, unsigned int depth)
{
	return 0;
}

__attribute__((used)) static struct stack_frame *dump_user_backtrace(struct stack_frame *head)
{
	/* Also check accessibility of one struct frame_head beyond: */
	struct stack_frame bufhead[2];
	unsigned long bytes;

	bytes = copy_from_user_nmi(bufhead, head, sizeof(bufhead));
	if (bytes != 0)
		return NULL;

	oprofile_add_trace(bufhead[0].return_address);

	/* frame pointers should strictly progress back up the stack
	 * (towards higher addresses) */
	if (head >= bufhead[0].next_frame)
		return NULL;

	return bufhead[0].next_frame;
}

void
x86_backtrace(struct pt_regs * const regs, unsigned int depth)
{
	struct stack_frame *head = (struct stack_frame *)frame_pointer(regs);

	if (!user_mode(regs)) {
		struct unwind_state state;
		unsigned long addr;

		if (!depth)
			return;

		oprofile_add_trace(regs->ip);

		if (!--depth)
			return;

		for (unwind_start(&state, current, regs, NULL);
		     !unwind_done(&state); unwind_next_frame(&state)) {
			addr = unwind_get_return_address(&state);
			if (!addr)
				break;

			oprofile_add_trace(addr);

			if (!--depth)
				break;
		}

		return;
	}

	if (x86_backtrace_32(regs, depth))
		return;

	while (depth-- && head)
		head = dump_user_backtrace(head);
}

