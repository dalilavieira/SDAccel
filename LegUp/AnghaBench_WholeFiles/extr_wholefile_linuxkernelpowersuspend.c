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
typedef  size_t suspend_state_t ;
struct platform_suspend_ops {int (* prepare ) () ;int (* prepare_late ) () ;int (* begin ) (size_t) ;int (* suspend_again ) () ;int /*<<< orphan*/  (* recover ) () ;int /*<<< orphan*/  (* end ) () ;int /*<<< orphan*/  (* finish ) () ;int /*<<< orphan*/  (* wake ) () ;scalar_t__ enter; scalar_t__ (* valid ) (size_t) ;} ;
struct platform_s2idle_ops {int (* prepare ) () ;int (* begin ) () ;int /*<<< orphan*/  (* end ) () ;int /*<<< orphan*/  (* restore ) () ;int /*<<< orphan*/  (* sync ) () ;int /*<<< orphan*/  (* wake ) () ;} ;
struct TYPE_2__ {int /*<<< orphan*/  failed_freeze; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENOSYS ; 
 int EPERM ; 
 int /*<<< orphan*/  PMSG_RESUME ; 
 int /*<<< orphan*/  PMSG_SUSPEND ; 
 int /*<<< orphan*/  PM_POST_SUSPEND ; 
 size_t PM_SUSPEND_MEM ; 
 size_t PM_SUSPEND_ON ; 
 int /*<<< orphan*/  PM_SUSPEND_PREPARE ; 
 size_t PM_SUSPEND_STANDBY ; 
 size_t PM_SUSPEND_TO_IDLE ; 
 scalar_t__ S2IDLE_STATE_ENTER ; 
 scalar_t__ S2IDLE_STATE_NONE ; 
 scalar_t__ S2IDLE_STATE_WAKE ; 
 int /*<<< orphan*/  SUSPEND_FREEZE ; 
 int /*<<< orphan*/  TPS (char*) ; 
 int __pm_notifier_call_chain (int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  cpuidle_pause () ; 
 int /*<<< orphan*/  cpuidle_resume () ; 
 int /*<<< orphan*/  dpm_noirq_begin () ; 
 int /*<<< orphan*/  dpm_noirq_end () ; 
 int /*<<< orphan*/  dpm_noirq_resume_devices (int /*<<< orphan*/ ) ; 
 int dpm_noirq_suspend_devices (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpm_save_failed_step (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_online_cpus () ; 
 int /*<<< orphan*/  lock_system_sleep () ; 
 size_t mem_sleep_current ; 
 size_t mem_sleep_default ; 
 int /*<<< orphan*/ * mem_sleep_labels ; 
 int /*<<< orphan*/ * mem_sleep_states ; 
 int /*<<< orphan*/ * pm_labels ; 
 int /*<<< orphan*/  pm_pr_dbg (char*) ; 
 int /*<<< orphan*/  pm_prepare_console () ; 
 int /*<<< orphan*/  pm_restore_console () ; 
 int /*<<< orphan*/ * pm_states ; 
 int /*<<< orphan*/  pm_wakeup_clear (int) ; 
 scalar_t__ pm_wakeup_pending () ; 
 int /*<<< orphan*/  put_online_cpus () ; 
 int /*<<< orphan*/  raw_spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  s2idle_lock ; 
 struct platform_s2idle_ops const* s2idle_ops ; 
 scalar_t__ s2idle_state ; 
 int /*<<< orphan*/  s2idle_wait_head ; 
 int /*<<< orphan*/  stub1 () ; 
 int stub10 () ; 
 int stub11 (size_t) ; 
 int /*<<< orphan*/  stub12 () ; 
 int /*<<< orphan*/  stub13 () ; 
 int /*<<< orphan*/  stub14 () ; 
 int stub15 () ; 
 int /*<<< orphan*/  stub2 () ; 
 scalar_t__ stub3 (size_t) ; 
 int stub4 () ; 
 int stub5 () ; 
 int stub6 () ; 
 int /*<<< orphan*/  stub7 () ; 
 int /*<<< orphan*/  stub8 () ; 
 int /*<<< orphan*/  stub9 () ; 
 struct platform_suspend_ops const* suspend_ops ; 
 TYPE_1__ suspend_stats ; 
 int /*<<< orphan*/  swait_event_exclusive (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  swake_up_one (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_suspend_resume (int /*<<< orphan*/ ,size_t,int) ; 
 int /*<<< orphan*/  unlock_system_sleep () ; 
 int /*<<< orphan*/  wake_up_all_idle_cpus () ; 

__attribute__((used)) static inline void hibernate_reserved_size_init(void) {}

__attribute__((used)) static inline void hibernate_image_size_init(void) {}

__attribute__((used)) static inline int suspend_devices_and_enter(suspend_state_t state)
{
	return -ENOSYS;
}

__attribute__((used)) static inline void suspend_test_start(void) {}

__attribute__((used)) static inline void suspend_test_finish(const char *label) {}

__attribute__((used)) static inline unsigned int count_highmem_pages(void) { return 0; }

__attribute__((used)) static inline int restore_highmem(void) { return 0; }

__attribute__((used)) static inline int suspend_freeze_processes(void)
{
	return 0;
}

__attribute__((used)) static inline void suspend_thaw_processes(void)
{
}

__attribute__((used)) static inline int pm_autosleep_init(void) { return 0; }

__attribute__((used)) static inline int pm_autosleep_lock(void) { return 0; }

__attribute__((used)) static inline void pm_autosleep_unlock(void) {}

__attribute__((used)) static inline suspend_state_t pm_autosleep_state(void) { return PM_SUSPEND_ON; }

bool pm_suspend_via_s2idle(void)
{
	return mem_sleep_current == PM_SUSPEND_TO_IDLE;
}

void s2idle_set_ops(const struct platform_s2idle_ops *ops)
{
	lock_system_sleep();
	s2idle_ops = ops;
	unlock_system_sleep();
}

__attribute__((used)) static void s2idle_begin(void)
{
	s2idle_state = S2IDLE_STATE_NONE;
}

__attribute__((used)) static void s2idle_enter(void)
{
	trace_suspend_resume(TPS("machine_suspend"), PM_SUSPEND_TO_IDLE, true);

	raw_spin_lock_irq(&s2idle_lock);
	if (pm_wakeup_pending())
		goto out;

	s2idle_state = S2IDLE_STATE_ENTER;
	raw_spin_unlock_irq(&s2idle_lock);

	get_online_cpus();
	cpuidle_resume();

	/* Push all the CPUs into the idle loop. */
	wake_up_all_idle_cpus();
	/* Make the current CPU wait so it can enter the idle loop too. */
	swait_event_exclusive(s2idle_wait_head,
		    s2idle_state == S2IDLE_STATE_WAKE);

	cpuidle_pause();
	put_online_cpus();

	raw_spin_lock_irq(&s2idle_lock);

 out:
	s2idle_state = S2IDLE_STATE_NONE;
	raw_spin_unlock_irq(&s2idle_lock);

	trace_suspend_resume(TPS("machine_suspend"), PM_SUSPEND_TO_IDLE, false);
}

__attribute__((used)) static void s2idle_loop(void)
{
	pm_pr_dbg("suspend-to-idle\n");

	for (;;) {
		int error;

		dpm_noirq_begin();

		/*
		 * Suspend-to-idle equals
		 * frozen processes + suspended devices + idle processors.
		 * Thus s2idle_enter() should be called right after
		 * all devices have been suspended.
		 *
		 * Wakeups during the noirq suspend of devices may be spurious,
		 * so prevent them from terminating the loop right away.
		 */
		error = dpm_noirq_suspend_devices(PMSG_SUSPEND);
		if (!error)
			s2idle_enter();
		else if (error == -EBUSY && pm_wakeup_pending())
			error = 0;

		if (!error && s2idle_ops && s2idle_ops->wake)
			s2idle_ops->wake();

		dpm_noirq_resume_devices(PMSG_RESUME);

		dpm_noirq_end();

		if (error)
			break;

		if (s2idle_ops && s2idle_ops->sync)
			s2idle_ops->sync();

		if (pm_wakeup_pending())
			break;

		pm_wakeup_clear(false);
	}

	pm_pr_dbg("resume from suspend-to-idle\n");
}

void s2idle_wake(void)
{
	unsigned long flags;

	raw_spin_lock_irqsave(&s2idle_lock, flags);
	if (s2idle_state > S2IDLE_STATE_NONE) {
		s2idle_state = S2IDLE_STATE_WAKE;
		swake_up_one(&s2idle_wait_head);
	}
	raw_spin_unlock_irqrestore(&s2idle_lock, flags);
}

__attribute__((used)) static bool valid_state(suspend_state_t state)
{
	/*
	 * PM_SUSPEND_STANDBY and PM_SUSPEND_MEM states need low level
	 * support and need to be valid to the low level
	 * implementation, no valid callback implies that none are valid.
	 */
	return suspend_ops && suspend_ops->valid && suspend_ops->valid(state);
}

void suspend_set_ops(const struct platform_suspend_ops *ops)
{
	lock_system_sleep();

	suspend_ops = ops;

	if (valid_state(PM_SUSPEND_STANDBY)) {
		mem_sleep_states[PM_SUSPEND_STANDBY] = mem_sleep_labels[PM_SUSPEND_STANDBY];
		pm_states[PM_SUSPEND_STANDBY] = pm_labels[PM_SUSPEND_STANDBY];
		if (mem_sleep_default == PM_SUSPEND_STANDBY)
			mem_sleep_current = PM_SUSPEND_STANDBY;
	}
	if (valid_state(PM_SUSPEND_MEM)) {
		mem_sleep_states[PM_SUSPEND_MEM] = mem_sleep_labels[PM_SUSPEND_MEM];
		if (mem_sleep_default >= PM_SUSPEND_MEM)
			mem_sleep_current = PM_SUSPEND_MEM;
	}

	unlock_system_sleep();
}

int suspend_valid_only_mem(suspend_state_t state)
{
	return state == PM_SUSPEND_MEM;
}

__attribute__((used)) static bool sleep_state_supported(suspend_state_t state)
{
	return state == PM_SUSPEND_TO_IDLE || (suspend_ops && suspend_ops->enter);
}

__attribute__((used)) static int platform_suspend_prepare(suspend_state_t state)
{
	return state != PM_SUSPEND_TO_IDLE && suspend_ops->prepare ?
		suspend_ops->prepare() : 0;
}

__attribute__((used)) static int platform_suspend_prepare_late(suspend_state_t state)
{
	return state == PM_SUSPEND_TO_IDLE && s2idle_ops && s2idle_ops->prepare ?
		s2idle_ops->prepare() : 0;
}

__attribute__((used)) static int platform_suspend_prepare_noirq(suspend_state_t state)
{
	return state != PM_SUSPEND_TO_IDLE && suspend_ops->prepare_late ?
		suspend_ops->prepare_late() : 0;
}

__attribute__((used)) static void platform_resume_noirq(suspend_state_t state)
{
	if (state != PM_SUSPEND_TO_IDLE && suspend_ops->wake)
		suspend_ops->wake();
}

__attribute__((used)) static void platform_resume_early(suspend_state_t state)
{
	if (state == PM_SUSPEND_TO_IDLE && s2idle_ops && s2idle_ops->restore)
		s2idle_ops->restore();
}

__attribute__((used)) static void platform_resume_finish(suspend_state_t state)
{
	if (state != PM_SUSPEND_TO_IDLE && suspend_ops->finish)
		suspend_ops->finish();
}

__attribute__((used)) static int platform_suspend_begin(suspend_state_t state)
{
	if (state == PM_SUSPEND_TO_IDLE && s2idle_ops && s2idle_ops->begin)
		return s2idle_ops->begin();
	else if (suspend_ops && suspend_ops->begin)
		return suspend_ops->begin(state);
	else
		return 0;
}

__attribute__((used)) static void platform_resume_end(suspend_state_t state)
{
	if (state == PM_SUSPEND_TO_IDLE && s2idle_ops && s2idle_ops->end)
		s2idle_ops->end();
	else if (suspend_ops && suspend_ops->end)
		suspend_ops->end();
}

__attribute__((used)) static void platform_recover(suspend_state_t state)
{
	if (state != PM_SUSPEND_TO_IDLE && suspend_ops->recover)
		suspend_ops->recover();
}

__attribute__((used)) static bool platform_suspend_again(suspend_state_t state)
{
	return state != PM_SUSPEND_TO_IDLE && suspend_ops->suspend_again ?
		suspend_ops->suspend_again() : false;
}

__attribute__((used)) static int suspend_test(int level)
{
#ifdef CONFIG_PM_DEBUG
	if (pm_test_level == level) {
		pr_info("suspend debug: Waiting for %d second(s).\n",
				pm_test_delay);
		mdelay(pm_test_delay * 1000);
		return 1;
	}
#endif /* !CONFIG_PM_DEBUG */
	return 0;
}

__attribute__((used)) static int suspend_prepare(suspend_state_t state)
{
	int error, nr_calls = 0;

	if (!sleep_state_supported(state))
		return -EPERM;

	pm_prepare_console();

	error = __pm_notifier_call_chain(PM_SUSPEND_PREPARE, -1, &nr_calls);
	if (error) {
		nr_calls--;
		goto Finish;
	}

	trace_suspend_resume(TPS("freeze_processes"), 0, true);
	error = suspend_freeze_processes();
	trace_suspend_resume(TPS("freeze_processes"), 0, false);
	if (!error)
		return 0;

	suspend_stats.failed_freeze++;
	dpm_save_failed_step(SUSPEND_FREEZE);
 Finish:
	__pm_notifier_call_chain(PM_POST_SUSPEND, nr_calls, NULL);
	pm_restore_console();
	return error;
}

