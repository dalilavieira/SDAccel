#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  uintptr_t vm_address_t ;
typedef  int /*<<< orphan*/  kern_return_t ;
struct TYPE_4__ {uintptr_t cthread_self; } ;
struct TYPE_5__ {TYPE_1__ machine; } ;

/* Variables and functions */
 uintptr_t MACHDEP_CTHREAD_MASK ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_2__* current_thread () ; 
 int /*<<< orphan*/  machine_thread_set_tsd_base (TYPE_2__*,uintptr_t) ; 

uintptr_t
get_tpidrro(void)
{
	uintptr_t	uthread;
#if __arm__
	uthread = __builtin_arm_mrc(15, 0, 13, 0, 3);	// TPIDRURO
#else
	__asm__ volatile("mrs %0, TPIDRRO_EL0" : "=r" (uthread));
#endif
	return uthread;
}

void
set_tpidrro(uintptr_t uthread)
{
#if __arm__
	 __builtin_arm_mcr(15, 0, uthread, 13, 0, 3);	// TPIDRURO
#else
	__asm__ volatile("msr TPIDRRO_EL0, %0" : : "r" (uthread));
#endif
}

kern_return_t
thread_set_cthread_self(vm_address_t self)
{
	return machine_thread_set_tsd_base(current_thread(), self);
}

vm_address_t
thread_get_cthread_self(void)
{
	uintptr_t	self;

	self = get_tpidrro();
#if __arm__
	self &= ~3;
	assert( self == current_thread()->machine.cthread_self);
	return ((kern_return_t) current_thread()->machine.cthread_self);
#else
	self &= MACHDEP_CTHREAD_MASK;
	assert( self == current_thread()->machine.cthread_self);
	return self;
#endif
}

