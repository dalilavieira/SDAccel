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
struct stack_info {scalar_t__ end; unsigned long* next_sp; } ;
struct unwind_state {unsigned long* sp; struct stack_info stack_info; int /*<<< orphan*/  stack_mask; struct task_struct* task; int /*<<< orphan*/  graph_idx; } ;
struct task_struct {int dummy; } ;
struct pt_regs {int dummy; } ;

/* Variables and functions */
 void* PTR_ALIGN (unsigned long*,int) ; 
 unsigned long READ_ONCE_NOCHECK (unsigned long) ; 
 scalar_t__ __kernel_text_address (unsigned long) ; 
 unsigned long ftrace_graph_ret_addr (struct task_struct*,int /*<<< orphan*/ *,unsigned long,unsigned long*) ; 
 int /*<<< orphan*/  get_stack_info (unsigned long*,struct task_struct*,struct stack_info*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct unwind_state*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  on_stack (struct stack_info*,unsigned long*,int) ; 
 scalar_t__ unwind_done (struct unwind_state*) ; 

unsigned long unwind_get_return_address(struct unwind_state *state)
{
	unsigned long addr;

	if (unwind_done(state))
		return 0;

	addr = READ_ONCE_NOCHECK(*state->sp);

	return ftrace_graph_ret_addr(state->task, &state->graph_idx,
				     addr, state->sp);
}

unsigned long *unwind_get_return_address_ptr(struct unwind_state *state)
{
	return NULL;
}

bool unwind_next_frame(struct unwind_state *state)
{
	struct stack_info *info = &state->stack_info;

	if (unwind_done(state))
		return false;

	do {
		for (state->sp++; state->sp < info->end; state->sp++) {
			unsigned long addr = READ_ONCE_NOCHECK(*state->sp);

			if (__kernel_text_address(addr))
				return true;
		}

		state->sp = PTR_ALIGN(info->next_sp, sizeof(long));

	} while (!get_stack_info(state->sp, state->task, info,
				 &state->stack_mask));

	return false;
}

void __unwind_start(struct unwind_state *state, struct task_struct *task,
		    struct pt_regs *regs, unsigned long *first_frame)
{
	memset(state, 0, sizeof(*state));

	state->task = task;
	state->sp   = PTR_ALIGN(first_frame, sizeof(long));

	get_stack_info(first_frame, state->task, &state->stack_info,
		       &state->stack_mask);

	/*
	 * The caller can provide the address of the first frame directly
	 * (first_frame) or indirectly (regs->sp) to indicate which stack frame
	 * to start unwinding at.  Skip ahead until we reach it.
	 */
	if (!unwind_done(state) &&
	    (!on_stack(&state->stack_info, first_frame, sizeof(long)) ||
	    !__kernel_text_address(*first_frame)))
		unwind_next_frame(state);
}

