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
struct device {int dummy; } ;
struct cpumask {int dummy; } ;

/* Variables and functions */
 int bL_cpufreq_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bL_cpufreq_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpumask_first (struct cpumask const*) ; 
 scalar_t__ dev_pm_opp_get_opp_count (struct device*) ; 
 struct device* get_cpu_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ve_spc_cpufreq_ops ; 

__attribute__((used)) static int ve_spc_init_opp_table(const struct cpumask *cpumask)
{
	struct device *cpu_dev = get_cpu_device(cpumask_first(cpumask));
	/*
	 * platform specific SPC code must initialise the opp table
	 * so just check if the OPP count is non-zero
	 */
	return dev_pm_opp_get_opp_count(cpu_dev) <= 0;
}

__attribute__((used)) static int ve_spc_get_transition_latency(struct device *cpu_dev)
{
	return 1000000; /* 1 ms */
}

__attribute__((used)) static int ve_spc_cpufreq_probe(struct platform_device *pdev)
{
	return bL_cpufreq_register(&ve_spc_cpufreq_ops);
}

__attribute__((used)) static int ve_spc_cpufreq_remove(struct platform_device *pdev)
{
	bL_cpufreq_unregister(&ve_spc_cpufreq_ops);
	return 0;
}

