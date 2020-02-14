#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct cpuidle_driver {int dummy; } ;
struct cpuidle_device {int dummy; } ;
struct TYPE_2__ {int (* suspend ) (int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_do_idle () ; 
 TYPE_1__* cpuidle_ops ; 
 int smp_processor_id () ; 
 int stub1 (int) ; 

int arm_cpuidle_simple_enter(struct cpuidle_device *dev,
		struct cpuidle_driver *drv, int index)
{
	cpu_do_idle();

	return index;
}

int arm_cpuidle_suspend(int index)
{
	int cpu = smp_processor_id();

	return cpuidle_ops[cpu].suspend(index);
}

