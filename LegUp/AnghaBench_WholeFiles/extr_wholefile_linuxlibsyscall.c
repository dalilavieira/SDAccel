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
struct task_struct {long state; } ;
struct pt_regs {int dummy; } ;

/* Variables and functions */
 int EAGAIN ; 
 int EINVAL ; 
 struct task_struct* current ; 
 unsigned long instruction_pointer (struct pt_regs*) ; 
 int /*<<< orphan*/  put_task_stack (struct task_struct*) ; 
 int /*<<< orphan*/  syscall_get_arguments (struct task_struct*,struct pt_regs*,int /*<<< orphan*/ ,unsigned int,unsigned long*) ; 
 long syscall_get_nr (struct task_struct*,struct pt_regs*) ; 
 struct pt_regs* task_pt_regs (struct task_struct*) ; 
 int /*<<< orphan*/  try_get_task_stack (struct task_struct*) ; 
 scalar_t__ unlikely (int) ; 
 unsigned long user_stack_pointer (struct pt_regs*) ; 
 unsigned long wait_task_inactive (struct task_struct*,long) ; 

__attribute__((used)) static int collect_syscall(struct task_struct *target, long *callno,
			   unsigned long args[6], unsigned int maxargs,
			   unsigned long *sp, unsigned long *pc)
{
	struct pt_regs *regs;

	if (!try_get_task_stack(target)) {
		/* Task has no stack, so the task isn't in a syscall. */
		*sp = *pc = 0;
		*callno = -1;
		return 0;
	}

	regs = task_pt_regs(target);
	if (unlikely(!regs)) {
		put_task_stack(target);
		return -EAGAIN;
	}

	*sp = user_stack_pointer(regs);
	*pc = instruction_pointer(regs);

	*callno = syscall_get_nr(target, regs);
	if (*callno != -1L && maxargs > 0)
		syscall_get_arguments(target, regs, 0, maxargs, args);

	put_task_stack(target);
	return 0;
}

int task_current_syscall(struct task_struct *target, long *callno,
			 unsigned long args[6], unsigned int maxargs,
			 unsigned long *sp, unsigned long *pc)
{
	long state;
	unsigned long ncsw;

	if (unlikely(maxargs > 6))
		return -EINVAL;

	if (target == current)
		return collect_syscall(target, callno, args, maxargs, sp, pc);

	state = target->state;
	if (unlikely(!state))
		return -EAGAIN;

	ncsw = wait_task_inactive(target, state);
	if (unlikely(!ncsw) ||
	    unlikely(collect_syscall(target, callno, args, maxargs, sp, pc)) ||
	    unlikely(wait_task_inactive(target, state) != ncsw))
		return -EAGAIN;

	return 0;
}

