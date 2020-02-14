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
typedef  scalar_t__ u64 ;
typedef  int u32 ;
struct pnv_idle_states_t {int flags; scalar_t__ latency_ns; scalar_t__ residency_ns; char* name; scalar_t__ psscr_val; scalar_t__ psscr_mask; int /*<<< orphan*/  valid; } ;
struct cpumask {int dummy; } ;
struct cpuidle_state_usage {scalar_t__ disable; } ;
struct cpuidle_state {scalar_t__ target_residency; int (* enter ) (struct cpuidle_device*,struct cpuidle_driver*,int) ;unsigned int flags; unsigned int exit_latency; int /*<<< orphan*/  desc; int /*<<< orphan*/  name; scalar_t__ disabled; } ;
struct cpuidle_driver {int state_count; struct cpumask* cpumask; struct cpuidle_state* states; } ;
struct cpuidle_device {struct cpuidle_state_usage* states_usage; } ;
struct TYPE_2__ {scalar_t__ mask; scalar_t__ val; } ;

/* Variables and functions */
 unsigned int CPUIDLE_FLAG_NONE ; 
 int /*<<< orphan*/  CPUIDLE_NAME_LEN ; 
 int CPUIDLE_STATE_MAX ; 
 unsigned int DIV_ROUND_UP (scalar_t__,int) ; 
 int ENODEV ; 
 int /*<<< orphan*/  FW_FEATURE_OPAL ; 
 int /*<<< orphan*/  HMT_medium () ; 
 int /*<<< orphan*/  HMT_very_low () ; 
 scalar_t__ IDLE_NO_OVERRIDE ; 
 int OPAL_PM_NAP_ENABLED ; 
 int OPAL_PM_STOP_INST_DEEP ; 
 int OPAL_PM_STOP_INST_FAST ; 
 int OPAL_PM_TIMEBASE_STOP ; 
 int /*<<< orphan*/  PNV_THREAD_NAP ; 
 scalar_t__ POWERNV_THRESHOLD_LATENCY_NS ; 
 scalar_t__ TICK_USEC ; 
 int /*<<< orphan*/  TIF_POLLING_NRFLAG ; 
 int /*<<< orphan*/  clear_thread_flag (int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_present_mask ; 
 int /*<<< orphan*/  cpuidle_devices ; 
 scalar_t__ cpuidle_disable ; 
 int /*<<< orphan*/  cpuidle_disable_device (struct cpuidle_device*) ; 
 int /*<<< orphan*/  cpuidle_enable_device (struct cpuidle_device*) ; 
 scalar_t__ cpuidle_get_driver () ; 
 int /*<<< orphan*/  cpuidle_pause_and_lock () ; 
 int /*<<< orphan*/  cpuidle_resume_and_unlock () ; 
 struct cpuidle_state* cpuidle_state_table ; 
 scalar_t__ default_snooze_timeout ; 
 scalar_t__ firmware_has_feature (int /*<<< orphan*/ ) ; 
 scalar_t__ get_tb () ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int max_idle_state ; 
 int /*<<< orphan*/  need_resched () ; 
 int nr_pnv_idle_states ; 
 struct cpuidle_device* per_cpu (int /*<<< orphan*/ ,unsigned int) ; 
 int pnv_get_supported_cpuidle_states () ; 
 struct pnv_idle_states_t* pnv_idle_states ; 
 int /*<<< orphan*/  power7_idle_type (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  power9_idle_type (scalar_t__,scalar_t__) ; 
 struct cpuidle_driver powernv_idle_driver ; 
 struct cpuidle_state* powernv_states ; 
 int /*<<< orphan*/  ppc64_runlatch_off () ; 
 int /*<<< orphan*/  ppc64_runlatch_on () ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  set_thread_flag (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_mb () ; 
 int snooze_timeout_en ; 
 TYPE_1__* stop_psscr_table ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ tb_ticks_per_usec ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static u64 get_snooze_timeout(struct cpuidle_device *dev,
			      struct cpuidle_driver *drv,
			      int index)
{
	int i;

	if (unlikely(!snooze_timeout_en))
		return default_snooze_timeout;

	for (i = index + 1; i < drv->state_count; i++) {
		struct cpuidle_state *s = &drv->states[i];
		struct cpuidle_state_usage *su = &dev->states_usage[i];

		if (s->disabled || su->disable)
			continue;

		return s->target_residency * tb_ticks_per_usec;
	}

	return default_snooze_timeout;
}

__attribute__((used)) static int snooze_loop(struct cpuidle_device *dev,
			struct cpuidle_driver *drv,
			int index)
{
	u64 snooze_exit_time;

	set_thread_flag(TIF_POLLING_NRFLAG);

	local_irq_enable();

	snooze_exit_time = get_tb() + get_snooze_timeout(dev, drv, index);
	ppc64_runlatch_off();
	HMT_very_low();
	while (!need_resched()) {
		if (likely(snooze_timeout_en) && get_tb() > snooze_exit_time) {
			/*
			 * Task has not woken up but we are exiting the polling
			 * loop anyway. Require a barrier after polling is
			 * cleared to order subsequent test of need_resched().
			 */
			clear_thread_flag(TIF_POLLING_NRFLAG);
			smp_mb();
			break;
		}
	}

	HMT_medium();
	ppc64_runlatch_on();
	clear_thread_flag(TIF_POLLING_NRFLAG);

	local_irq_disable();

	return index;
}

__attribute__((used)) static int nap_loop(struct cpuidle_device *dev,
			struct cpuidle_driver *drv,
			int index)
{
	power7_idle_type(PNV_THREAD_NAP);

	return index;
}

__attribute__((used)) static int stop_loop(struct cpuidle_device *dev,
		     struct cpuidle_driver *drv,
		     int index)
{
	power9_idle_type(stop_psscr_table[index].val,
			 stop_psscr_table[index].mask);
	return index;
}

__attribute__((used)) static int powernv_cpuidle_cpu_online(unsigned int cpu)
{
	struct cpuidle_device *dev = per_cpu(cpuidle_devices, cpu);

	if (dev && cpuidle_get_driver()) {
		cpuidle_pause_and_lock();
		cpuidle_enable_device(dev);
		cpuidle_resume_and_unlock();
	}
	return 0;
}

__attribute__((used)) static int powernv_cpuidle_cpu_dead(unsigned int cpu)
{
	struct cpuidle_device *dev = per_cpu(cpuidle_devices, cpu);

	if (dev && cpuidle_get_driver()) {
		cpuidle_pause_and_lock();
		cpuidle_disable_device(dev);
		cpuidle_resume_and_unlock();
	}
	return 0;
}

__attribute__((used)) static int powernv_cpuidle_driver_init(void)
{
	int idle_state;
	struct cpuidle_driver *drv = &powernv_idle_driver;

	drv->state_count = 0;

	for (idle_state = 0; idle_state < max_idle_state; ++idle_state) {
		/* Is the state not enabled? */
		if (cpuidle_state_table[idle_state].enter == NULL)
			continue;

		drv->states[drv->state_count] =	/* structure copy */
			cpuidle_state_table[idle_state];

		drv->state_count += 1;
	}

	/*
	 * On the PowerNV platform cpu_present may be less than cpu_possible in
	 * cases when firmware detects the CPU, but it is not available to the
	 * OS.  If CONFIG_HOTPLUG_CPU=n, then such CPUs are not hotplugable at
	 * run time and hence cpu_devices are not created for those CPUs by the
	 * generic topology_init().
	 *
	 * drv->cpumask defaults to cpu_possible_mask in
	 * __cpuidle_driver_init().  This breaks cpuidle on PowerNV where
	 * cpu_devices are not created for CPUs in cpu_possible_mask that
	 * cannot be hot-added later at run time.
	 *
	 * Trying cpuidle_register_device() on a CPU without a cpu_device is
	 * incorrect, so pass a correct CPU mask to the generic cpuidle driver.
	 */

	drv->cpumask = (struct cpumask *)cpu_present_mask;

	return 0;
}

__attribute__((used)) static inline void add_powernv_state(int index, const char *name,
				     unsigned int flags,
				     int (*idle_fn)(struct cpuidle_device *,
						    struct cpuidle_driver *,
						    int),
				     unsigned int target_residency,
				     unsigned int exit_latency,
				     u64 psscr_val, u64 psscr_mask)
{
	strlcpy(powernv_states[index].name, name, CPUIDLE_NAME_LEN);
	strlcpy(powernv_states[index].desc, name, CPUIDLE_NAME_LEN);
	powernv_states[index].flags = flags;
	powernv_states[index].target_residency = target_residency;
	powernv_states[index].exit_latency = exit_latency;
	powernv_states[index].enter = idle_fn;
	/* For power8 and below psscr_* will be 0 */
	stop_psscr_table[index].val = psscr_val;
	stop_psscr_table[index].mask = psscr_mask;
}

__attribute__((used)) static inline int validate_dt_prop_sizes(const char *prop1, int prop1_len,
					 const char *prop2, int prop2_len)
{
	if (prop1_len == prop2_len)
		return 0;

	pr_warn("cpuidle-powernv: array sizes don't match for %s and %s\n",
		prop1, prop2);
	return -1;
}

__attribute__((used)) static int powernv_add_idle_states(void)
{
	int nr_idle_states = 1; /* Snooze */
	int dt_idle_states;
	u32 has_stop_states = 0;
	int i;
	u32 supported_flags = pnv_get_supported_cpuidle_states();


	/* Currently we have snooze statically defined */
	if (nr_pnv_idle_states <= 0) {
		pr_warn("cpuidle-powernv : Only Snooze is available\n");
		goto out;
	}

	/* TODO: Count only states which are eligible for cpuidle */
	dt_idle_states = nr_pnv_idle_states;

	/*
	 * Since snooze is used as first idle state, max idle states allowed is
	 * CPUIDLE_STATE_MAX -1
	 */
	if (nr_pnv_idle_states > CPUIDLE_STATE_MAX - 1) {
		pr_warn("cpuidle-powernv: discovered idle states more than allowed");
		dt_idle_states = CPUIDLE_STATE_MAX - 1;
	}

	/*
	 * If the idle states use stop instruction, probe for psscr values
	 * and psscr mask which are necessary to specify required stop level.
	 */
	has_stop_states = (pnv_idle_states[0].flags &
			   (OPAL_PM_STOP_INST_FAST | OPAL_PM_STOP_INST_DEEP));

	for (i = 0; i < dt_idle_states; i++) {
		unsigned int exit_latency, target_residency;
		bool stops_timebase = false;
		struct pnv_idle_states_t *state = &pnv_idle_states[i];

		/*
		 * Skip the platform idle state whose flag isn't in
		 * the supported_cpuidle_states flag mask.
		 */
		if ((state->flags & supported_flags) != state->flags)
			continue;
		/*
		 * If an idle state has exit latency beyond
		 * POWERNV_THRESHOLD_LATENCY_NS then don't use it
		 * in cpu-idle.
		 */
		if (state->latency_ns > POWERNV_THRESHOLD_LATENCY_NS)
			continue;
		/*
		 * Firmware passes residency and latency values in ns.
		 * cpuidle expects it in us.
		 */
		exit_latency = DIV_ROUND_UP(state->latency_ns, 1000);
		target_residency = DIV_ROUND_UP(state->residency_ns, 1000);

		if (has_stop_states && !(state->valid))
				continue;

		if (state->flags & OPAL_PM_TIMEBASE_STOP)
			stops_timebase = true;

		if (state->flags & OPAL_PM_NAP_ENABLED) {
			/* Add NAP state */
			add_powernv_state(nr_idle_states, "Nap",
					  CPUIDLE_FLAG_NONE, nap_loop,
					  target_residency, exit_latency, 0, 0);
		} else if (has_stop_states && !stops_timebase) {
			add_powernv_state(nr_idle_states, state->name,
					  CPUIDLE_FLAG_NONE, stop_loop,
					  target_residency, exit_latency,
					  state->psscr_val,
					  state->psscr_mask);
		}

		/*
		 * All cpuidle states with CPUIDLE_FLAG_TIMER_STOP set must come
		 * within this config dependency check.
		 */
#ifdef CONFIG_TICK_ONESHOT
		else if (state->flags & OPAL_PM_SLEEP_ENABLED ||
			 state->flags & OPAL_PM_SLEEP_ENABLED_ER1) {
			/* Add FASTSLEEP state */
			add_powernv_state(nr_idle_states, "FastSleep",
					  CPUIDLE_FLAG_TIMER_STOP,
					  fastsleep_loop,
					  target_residency, exit_latency, 0, 0);
		} else if (has_stop_states && stops_timebase) {
			add_powernv_state(nr_idle_states, state->name,
					  CPUIDLE_FLAG_TIMER_STOP, stop_loop,
					  target_residency, exit_latency,
					  state->psscr_val,
					  state->psscr_mask);
		}
#endif
		else
			continue;
		nr_idle_states++;
	}
out:
	return nr_idle_states;
}

__attribute__((used)) static int powernv_idle_probe(void)
{
	if (cpuidle_disable != IDLE_NO_OVERRIDE)
		return -ENODEV;

	if (firmware_has_feature(FW_FEATURE_OPAL)) {
		cpuidle_state_table = powernv_states;
		/* Device tree can indicate more idle states */
		max_idle_state = powernv_add_idle_states();
		default_snooze_timeout = TICK_USEC * tb_ticks_per_usec;
		if (max_idle_state > 1)
			snooze_timeout_en = true;
 	} else
 		return -ENODEV;

	return 0;
}

