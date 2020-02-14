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

/* Variables and functions */
 int /*<<< orphan*/  disable_kernel_altivec () ; 
 int /*<<< orphan*/  enable_kernel_altivec () ; 
 scalar_t__ in_interrupt () ; 
 int /*<<< orphan*/  pagefault_disable () ; 
 int /*<<< orphan*/  pagefault_enable () ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 

int enter_vmx_usercopy(void)
{
	if (in_interrupt())
		return 0;

	preempt_disable();
	/*
	 * We need to disable page faults as they can call schedule and
	 * thus make us lose the VMX context. So on page faults, we just
	 * fail which will cause a fallback to the normal non-vmx copy.
	 */
	pagefault_disable();

	enable_kernel_altivec();

	return 1;
}

int exit_vmx_usercopy(void)
{
	disable_kernel_altivec();
	pagefault_enable();
	preempt_enable();
	return 0;
}

int enter_vmx_ops(void)
{
	if (in_interrupt())
		return 0;

	preempt_disable();

	enable_kernel_altivec();

	return 1;
}

void *exit_vmx_ops(void *dest)
{
	disable_kernel_altivec();
	preempt_enable();
	return dest;
}

