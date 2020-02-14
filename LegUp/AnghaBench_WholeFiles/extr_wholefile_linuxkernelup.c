#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct cpumask {int dummy; } ;
typedef  int /*<<< orphan*/  (* smp_call_func_t ) (void*) ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_3__ {int /*<<< orphan*/  info; int /*<<< orphan*/  (* func ) (int /*<<< orphan*/ ) ;} ;
typedef  TYPE_1__ call_single_data_t ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 scalar_t__ cpumask_test_cpu (int /*<<< orphan*/ ,struct cpumask const*) ; 
 int /*<<< orphan*/  hypervisor_pin_vcpu (int) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

int smp_call_function_single(int cpu, void (*func) (void *info), void *info,
				int wait)
{
	unsigned long flags;

	WARN_ON(cpu != 0);

	local_irq_save(flags);
	func(info);
	local_irq_restore(flags);

	return 0;
}

int smp_call_function_single_async(int cpu, call_single_data_t *csd)
{
	unsigned long flags;

	local_irq_save(flags);
	csd->func(csd->info);
	local_irq_restore(flags);
	return 0;
}

int on_each_cpu(smp_call_func_t func, void *info, int wait)
{
	unsigned long flags;

	local_irq_save(flags);
	func(info);
	local_irq_restore(flags);
	return 0;
}

void on_each_cpu_mask(const struct cpumask *mask,
		      smp_call_func_t func, void *info, bool wait)
{
	unsigned long flags;

	if (cpumask_test_cpu(0, mask)) {
		local_irq_save(flags);
		func(info);
		local_irq_restore(flags);
	}
}

void on_each_cpu_cond(bool (*cond_func)(int cpu, void *info),
		      smp_call_func_t func, void *info, bool wait,
		      gfp_t gfp_flags)
{
	unsigned long flags;

	preempt_disable();
	if (cond_func(0, info)) {
		local_irq_save(flags);
		func(info);
		local_irq_restore(flags);
	}
	preempt_enable();
}

int smp_call_on_cpu(unsigned int cpu, int (*func)(void *), void *par, bool phys)
{
	int ret;

	if (cpu != 0)
		return -ENXIO;

	if (phys)
		hypervisor_pin_vcpu(0);
	ret = func(par);
	if (phys)
		hypervisor_pin_vcpu(-1);

	return ret;
}

