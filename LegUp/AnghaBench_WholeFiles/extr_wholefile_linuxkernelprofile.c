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
typedef  void task_struct ;
struct pt_regs {int dummy; } ;
struct notifier_block {int dummy; } ;
typedef  enum profile_type { ____Placeholder_profile_type } profile_type ;

/* Variables and functions */
 int CPU_PROFILING ; 
 int EINVAL ; 
 int KVM_PROFILING ; 
 int NOTIFY_OK ; 
#define  PROFILE_MUNMAP 129 
#define  PROFILE_TASK_EXIT 128 
 int SCHED_PROFILING ; 
 scalar_t__ _stext ; 
 int /*<<< orphan*/  atomic_add (unsigned int,int /*<<< orphan*/ *) ; 
 int atomic_notifier_call_chain (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*) ; 
 int atomic_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int atomic_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 scalar_t__ cpumask_test_cpu (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct pt_regs* get_irq_regs () ; 
 scalar_t__ get_option (char**,int*) ; 
 size_t min (unsigned long,scalar_t__) ; 
 int /*<<< orphan*/  munmap_notifier ; 
 int /*<<< orphan*/  pr_info (char*,unsigned long) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/ * prof_buffer ; 
 int /*<<< orphan*/ * prof_cpu_mask ; 
 scalar_t__ prof_len ; 
 int prof_on ; 
 unsigned long prof_shift ; 
 int /*<<< orphan*/  profile_hit (int,void*) ; 
 scalar_t__ profile_pc (struct pt_regs*) ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  strncmp (char*,char const*,int) ; 
 int /*<<< orphan*/  task_exit_notifier ; 
 int /*<<< orphan*/  task_free_notifier ; 
 int /*<<< orphan*/  user_mode (struct pt_regs*) ; 

int profile_setup(char *str)
{
	static const char schedstr[] = "schedule";
	static const char sleepstr[] = "sleep";
	static const char kvmstr[] = "kvm";
	int par;

	if (!strncmp(str, sleepstr, strlen(sleepstr))) {
#ifdef CONFIG_SCHEDSTATS
		force_schedstat_enabled();
		prof_on = SLEEP_PROFILING;
		if (str[strlen(sleepstr)] == ',')
			str += strlen(sleepstr) + 1;
		if (get_option(&str, &par))
			prof_shift = par;
		pr_info("kernel sleep profiling enabled (shift: %ld)\n",
			prof_shift);
#else
		pr_warn("kernel sleep profiling requires CONFIG_SCHEDSTATS\n");
#endif /* CONFIG_SCHEDSTATS */
	} else if (!strncmp(str, schedstr, strlen(schedstr))) {
		prof_on = SCHED_PROFILING;
		if (str[strlen(schedstr)] == ',')
			str += strlen(schedstr) + 1;
		if (get_option(&str, &par))
			prof_shift = par;
		pr_info("kernel schedule profiling enabled (shift: %ld)\n",
			prof_shift);
	} else if (!strncmp(str, kvmstr, strlen(kvmstr))) {
		prof_on = KVM_PROFILING;
		if (str[strlen(kvmstr)] == ',')
			str += strlen(kvmstr) + 1;
		if (get_option(&str, &par))
			prof_shift = par;
		pr_info("kernel KVM profiling enabled (shift: %ld)\n",
			prof_shift);
	} else if (get_option(&str, &par)) {
		prof_shift = par;
		prof_on = CPU_PROFILING;
		pr_info("kernel profiling enabled (shift: %ld)\n",
			prof_shift);
	}
	return 1;
}

void profile_task_exit(struct task_struct *task)
{
	blocking_notifier_call_chain(&task_exit_notifier, 0, task);
}

int profile_handoff_task(struct task_struct *task)
{
	int ret;
	ret = atomic_notifier_call_chain(&task_free_notifier, 0, task);
	return (ret == NOTIFY_OK) ? 1 : 0;
}

void profile_munmap(unsigned long addr)
{
	blocking_notifier_call_chain(&munmap_notifier, 0, (void *)addr);
}

int task_handoff_register(struct notifier_block *n)
{
	return atomic_notifier_chain_register(&task_free_notifier, n);
}

int task_handoff_unregister(struct notifier_block *n)
{
	return atomic_notifier_chain_unregister(&task_free_notifier, n);
}

int profile_event_register(enum profile_type type, struct notifier_block *n)
{
	int err = -EINVAL;

	switch (type) {
	case PROFILE_TASK_EXIT:
		err = blocking_notifier_chain_register(
				&task_exit_notifier, n);
		break;
	case PROFILE_MUNMAP:
		err = blocking_notifier_chain_register(
				&munmap_notifier, n);
		break;
	}

	return err;
}

int profile_event_unregister(enum profile_type type, struct notifier_block *n)
{
	int err = -EINVAL;

	switch (type) {
	case PROFILE_TASK_EXIT:
		err = blocking_notifier_chain_unregister(
				&task_exit_notifier, n);
		break;
	case PROFILE_MUNMAP:
		err = blocking_notifier_chain_unregister(
				&munmap_notifier, n);
		break;
	}

	return err;
}

__attribute__((used)) static void do_profile_hits(int type, void *__pc, unsigned int nr_hits)
{
	unsigned long pc;
	pc = ((unsigned long)__pc - (unsigned long)_stext) >> prof_shift;
	atomic_add(nr_hits, &prof_buffer[min(pc, prof_len - 1)]);
}

void profile_hits(int type, void *__pc, unsigned int nr_hits)
{
	if (prof_on != type || !prof_buffer)
		return;
	do_profile_hits(type, __pc, nr_hits);
}

void profile_tick(int type)
{
	struct pt_regs *regs = get_irq_regs();

	if (!user_mode(regs) && prof_cpu_mask != NULL &&
	    cpumask_test_cpu(smp_processor_id(), prof_cpu_mask))
		profile_hit(type, (void *)profile_pc(regs));
}

