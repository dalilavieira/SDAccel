#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
struct cpuidle_driver {size_t state_count; TYPE_1__* states; } ;
struct cpuidle_device {int dummy; } ;
struct TYPE_9__ {int idle; int donate_dedicated_cpu; int /*<<< orphan*/  wait_state_cycles; } ;
struct TYPE_8__ {int /*<<< orphan*/  lppaca_ptr; } ;
struct TYPE_7__ {int target_residency; int /*<<< orphan*/ * enter; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int ENODEV ; 
 int /*<<< orphan*/  FW_FEATURE_SPLPAR ; 
 int /*<<< orphan*/  HMT_low () ; 
 int /*<<< orphan*/  HMT_medium () ; 
 int /*<<< orphan*/  HMT_very_low () ; 
 scalar_t__ IDLE_NO_OVERRIDE ; 
 int /*<<< orphan*/  SPRN_PURR ; 
 int /*<<< orphan*/  TIF_POLLING_NRFLAG ; 
 scalar_t__ be64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cede_processor () ; 
 int /*<<< orphan*/  clear_thread_flag (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be64 (scalar_t__) ; 
 int /*<<< orphan*/  cpuidle_devices ; 
 scalar_t__ cpuidle_disable ; 
 int /*<<< orphan*/  cpuidle_disable_device (struct cpuidle_device*) ; 
 int /*<<< orphan*/  cpuidle_enable_device (struct cpuidle_device*) ; 
 scalar_t__ cpuidle_get_driver () ; 
 int /*<<< orphan*/  cpuidle_pause_and_lock () ; 
 int /*<<< orphan*/  cpuidle_resume_and_unlock () ; 
 TYPE_1__* cpuidle_state_table ; 
 TYPE_1__* dedicated_states ; 
 scalar_t__ firmware_has_feature (int /*<<< orphan*/ ) ; 
 TYPE_3__* get_lppaca () ; 
 scalar_t__ get_tb () ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 TYPE_2__* local_paca ; 
 scalar_t__ lppaca_shared_proc (int /*<<< orphan*/ ) ; 
 int max_idle_state ; 
 unsigned long mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  need_resched () ; 
 struct cpuidle_device* per_cpu (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  ppc64_runlatch_off () ; 
 int /*<<< orphan*/  ppc64_runlatch_on () ; 
 scalar_t__ prep_irq_for_idle () ; 
 struct cpuidle_driver pseries_idle_driver ; 
 int /*<<< orphan*/  set_thread_flag (int /*<<< orphan*/ ) ; 
 TYPE_1__* shared_states ; 
 int /*<<< orphan*/  smp_mb () ; 
 int snooze_timeout ; 
 int snooze_timeout_en ; 
 int tb_ticks_per_usec ; 

__attribute__((used)) static inline void idle_loop_prolog(unsigned long *in_purr)
{
	ppc64_runlatch_off();
	*in_purr = mfspr(SPRN_PURR);
	/*
	 * Indicate to the HV that we are idle. Now would be
	 * a good time to find other work to dispatch.
	 */
	get_lppaca()->idle = 1;
}

__attribute__((used)) static inline void idle_loop_epilog(unsigned long in_purr)
{
	u64 wait_cycles;

	wait_cycles = be64_to_cpu(get_lppaca()->wait_state_cycles);
	wait_cycles += mfspr(SPRN_PURR) - in_purr;
	get_lppaca()->wait_state_cycles = cpu_to_be64(wait_cycles);
	get_lppaca()->idle = 0;

	ppc64_runlatch_on();
}

__attribute__((used)) static int snooze_loop(struct cpuidle_device *dev,
			struct cpuidle_driver *drv,
			int index)
{
	unsigned long in_purr;
	u64 snooze_exit_time;

	set_thread_flag(TIF_POLLING_NRFLAG);

	idle_loop_prolog(&in_purr);
	local_irq_enable();
	snooze_exit_time = get_tb() + snooze_timeout;

	while (!need_resched()) {
		HMT_low();
		HMT_very_low();
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
	clear_thread_flag(TIF_POLLING_NRFLAG);

	local_irq_disable();

	idle_loop_epilog(in_purr);

	return index;
}

__attribute__((used)) static void check_and_cede_processor(void)
{
	/*
	 * Ensure our interrupt state is properly tracked,
	 * also checks if no interrupt has occurred while we
	 * were soft-disabled
	 */
	if (prep_irq_for_idle()) {
		cede_processor();
#ifdef CONFIG_TRACE_IRQFLAGS
		/* Ensure that H_CEDE returns with IRQs on */
		if (WARN_ON(!(mfmsr() & MSR_EE)))
			__hard_irq_enable();
#endif
	}
}

__attribute__((used)) static int dedicated_cede_loop(struct cpuidle_device *dev,
				struct cpuidle_driver *drv,
				int index)
{
	unsigned long in_purr;

	idle_loop_prolog(&in_purr);
	get_lppaca()->donate_dedicated_cpu = 1;

	HMT_medium();
	check_and_cede_processor();

	local_irq_disable();
	get_lppaca()->donate_dedicated_cpu = 0;

	idle_loop_epilog(in_purr);

	return index;
}

__attribute__((used)) static int shared_cede_loop(struct cpuidle_device *dev,
			struct cpuidle_driver *drv,
			int index)
{
	unsigned long in_purr;

	idle_loop_prolog(&in_purr);

	/*
	 * Yield the processor to the hypervisor.  We return if
	 * an external interrupt occurs (which are driven prior
	 * to returning here) or if a prod occurs from another
	 * processor. When returning here, external interrupts
	 * are enabled.
	 */
	check_and_cede_processor();

	local_irq_disable();
	idle_loop_epilog(in_purr);

	return index;
}

__attribute__((used)) static int pseries_cpuidle_cpu_online(unsigned int cpu)
{
	struct cpuidle_device *dev = per_cpu(cpuidle_devices, cpu);

	if (dev && cpuidle_get_driver()) {
		cpuidle_pause_and_lock();
		cpuidle_enable_device(dev);
		cpuidle_resume_and_unlock();
	}
	return 0;
}

__attribute__((used)) static int pseries_cpuidle_cpu_dead(unsigned int cpu)
{
	struct cpuidle_device *dev = per_cpu(cpuidle_devices, cpu);

	if (dev && cpuidle_get_driver()) {
		cpuidle_pause_and_lock();
		cpuidle_disable_device(dev);
		cpuidle_resume_and_unlock();
	}
	return 0;
}

__attribute__((used)) static int pseries_cpuidle_driver_init(void)
{
	int idle_state;
	struct cpuidle_driver *drv = &pseries_idle_driver;

	drv->state_count = 0;

	for (idle_state = 0; idle_state < max_idle_state; ++idle_state) {
		/* Is the state not enabled? */
		if (cpuidle_state_table[idle_state].enter == NULL)
			continue;

		drv->states[drv->state_count] =	/* structure copy */
			cpuidle_state_table[idle_state];

		drv->state_count += 1;
	}

	return 0;
}

__attribute__((used)) static int pseries_idle_probe(void)
{

	if (cpuidle_disable != IDLE_NO_OVERRIDE)
		return -ENODEV;

	if (firmware_has_feature(FW_FEATURE_SPLPAR)) {
		/*
		 * Use local_paca instead of get_lppaca() since
		 * preemption is not disabled, and it is not required in
		 * fact, since lppaca_ptr does not need to be the value
		 * associated to the current CPU, it can be from any CPU.
		 */
		if (lppaca_shared_proc(local_paca->lppaca_ptr)) {
			cpuidle_state_table = shared_states;
			max_idle_state = ARRAY_SIZE(shared_states);
		} else {
			cpuidle_state_table = dedicated_states;
			max_idle_state = ARRAY_SIZE(dedicated_states);
		}
	} else
		return -ENODEV;

	if (max_idle_state > 1) {
		snooze_timeout_en = true;
		snooze_timeout = cpuidle_state_table[1].target_residency *
				 tb_ticks_per_usec;
	}
	return 0;
}

