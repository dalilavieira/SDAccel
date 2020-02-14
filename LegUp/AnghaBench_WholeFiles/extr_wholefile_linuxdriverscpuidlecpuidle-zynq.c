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
struct platform_device {int dummy; } ;
struct cpuidle_driver {int dummy; } ;
struct cpuidle_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_do_idle () ; 
 int cpuidle_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  zynq_idle_driver ; 

__attribute__((used)) static int zynq_enter_idle(struct cpuidle_device *dev,
			   struct cpuidle_driver *drv, int index)
{
	/* Add code for DDR self refresh start */
	cpu_do_idle();

	return index;
}

__attribute__((used)) static int zynq_cpuidle_probe(struct platform_device *pdev)
{
	pr_info("Xilinx Zynq CpuIdle Driver started\n");

	return cpuidle_register(&zynq_idle_driver, NULL);
}

