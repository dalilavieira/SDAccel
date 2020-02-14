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
struct pt_regs {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VERIFY_READ ; 
 scalar_t__ __copy_from_user_inatomic (unsigned long*,unsigned long*,int) ; 
 int /*<<< orphan*/  access_ok (int /*<<< orphan*/ ,unsigned long*,int) ; 
 unsigned int backtrace_limit ; 
 int /*<<< orphan*/  backtrace_ops ; 
 scalar_t__ kernel_stack_pointer (struct pt_regs* const) ; 
 int /*<<< orphan*/  oprofile_add_trace (unsigned long) ; 
 int /*<<< orphan*/  unwind_stack (int /*<<< orphan*/ *,struct pt_regs* const,unsigned long*,int /*<<< orphan*/ *,unsigned int*) ; 
 int /*<<< orphan*/  user_mode (struct pt_regs* const) ; 

__attribute__((used)) static int backtrace_stack(void *data, char *name)
{
	/* Yes, we want all stacks */
	return 0;
}

__attribute__((used)) static void backtrace_address(void *data, unsigned long addr, int reliable)
{
	unsigned int *depth = data;

	if ((*depth)--)
		oprofile_add_trace(addr);
}

__attribute__((used)) static unsigned long *
user_backtrace(unsigned long *stackaddr, struct pt_regs *regs)
{
	unsigned long buf_stack;

	/* Also check accessibility of address */
	if (!access_ok(VERIFY_READ, stackaddr, sizeof(unsigned long)))
		return NULL;

	if (__copy_from_user_inatomic(&buf_stack, stackaddr, sizeof(unsigned long)))
		return NULL;

	/* Quick paranoia check */
	if (buf_stack & 3)
		return NULL;

	oprofile_add_trace(buf_stack);

	stackaddr++;

	return stackaddr;
}

void sh_backtrace(struct pt_regs * const regs, unsigned int depth)
{
	unsigned long *stackaddr;

	/*
	 * Paranoia - clip max depth as we could get lost in the weeds.
	 */
	if (depth > backtrace_limit)
		depth = backtrace_limit;

	stackaddr = (unsigned long *)kernel_stack_pointer(regs);
	if (!user_mode(regs)) {
		if (depth)
			unwind_stack(NULL, regs, stackaddr,
				     &backtrace_ops, &depth);
		return;
	}

	while (depth-- && (stackaddr != NULL))
		stackaddr = user_backtrace(stackaddr, regs);
}

