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
struct notifier_block {int dummy; } ;
typedef  enum cpu_pm_event { ____Placeholder_cpu_pm_event } cpu_pm_event ;

/* Variables and functions */
 int CPU_CLUSTER_PM_ENTER ; 
 int CPU_CLUSTER_PM_ENTER_FAILED ; 
 int CPU_CLUSTER_PM_EXIT ; 
 int CPU_PM_ENTER ; 
 int CPU_PM_ENTER_FAILED ; 
 int CPU_PM_EXIT ; 
 int __atomic_notifier_call_chain (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int*) ; 
 int atomic_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int atomic_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  cpu_pm_notifier_chain ; 
 int notifier_to_errno (int) ; 
 int /*<<< orphan*/  rcu_irq_enter_irqson () ; 
 int /*<<< orphan*/  rcu_irq_exit_irqson () ; 

__attribute__((used)) static int cpu_pm_notify(enum cpu_pm_event event, int nr_to_call, int *nr_calls)
{
	int ret;

	/*
	 * __atomic_notifier_call_chain has a RCU read critical section, which
	 * could be disfunctional in cpu idle. Copy RCU_NONIDLE code to let
	 * RCU know this.
	 */
	rcu_irq_enter_irqson();
	ret = __atomic_notifier_call_chain(&cpu_pm_notifier_chain, event, NULL,
		nr_to_call, nr_calls);
	rcu_irq_exit_irqson();

	return notifier_to_errno(ret);
}

int cpu_pm_register_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&cpu_pm_notifier_chain, nb);
}

int cpu_pm_unregister_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_unregister(&cpu_pm_notifier_chain, nb);
}

int cpu_pm_enter(void)
{
	int nr_calls;
	int ret = 0;

	ret = cpu_pm_notify(CPU_PM_ENTER, -1, &nr_calls);
	if (ret)
		/*
		 * Inform listeners (nr_calls - 1) about failure of CPU PM
		 * PM entry who are notified earlier to prepare for it.
		 */
		cpu_pm_notify(CPU_PM_ENTER_FAILED, nr_calls - 1, NULL);

	return ret;
}

int cpu_pm_exit(void)
{
	return cpu_pm_notify(CPU_PM_EXIT, -1, NULL);
}

int cpu_cluster_pm_enter(void)
{
	int nr_calls;
	int ret = 0;

	ret = cpu_pm_notify(CPU_CLUSTER_PM_ENTER, -1, &nr_calls);
	if (ret)
		/*
		 * Inform listeners (nr_calls - 1) about failure of CPU cluster
		 * PM entry who are notified earlier to prepare for it.
		 */
		cpu_pm_notify(CPU_CLUSTER_PM_ENTER_FAILED, nr_calls - 1, NULL);

	return ret;
}

int cpu_cluster_pm_exit(void)
{
	return cpu_pm_notify(CPU_CLUSTER_PM_EXIT, -1, NULL);
}

