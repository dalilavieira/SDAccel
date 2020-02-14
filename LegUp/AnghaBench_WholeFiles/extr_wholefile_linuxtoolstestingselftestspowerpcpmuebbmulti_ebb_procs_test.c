#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_4__ {int exclude_kernel; int exclude_hv; int exclude_idle; } ;
struct event {TYPE_1__ attr; } ;
typedef  scalar_t__ pid_t ;
struct TYPE_5__ {scalar_t__ ebb_count; } ;
struct TYPE_6__ {int* pmc_enable; TYPE_2__ stats; } ;

/* Variables and functions */
 scalar_t__ COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int NR_CHILDREN ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  SPRN_PMC1 ; 
 int bind_to_cpu (int) ; 
 int child_should_exit ; 
 int core_busy_loop () ; 
 int /*<<< orphan*/  count_pmc (int,scalar_t__) ; 
 int /*<<< orphan*/  dump_summary_ebb_state () ; 
 int ebb_check_mmcr0 () ; 
 int ebb_event_enable (struct event*) ; 
 int /*<<< orphan*/  ebb_freeze_pmcs () ; 
 int /*<<< orphan*/  ebb_global_disable () ; 
 int /*<<< orphan*/  ebb_global_enable () ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_3__ ebb_state ; 
 int /*<<< orphan*/  event_close (struct event*) ; 
 int /*<<< orphan*/  event_init_named (struct event*,int,char*) ; 
 int /*<<< orphan*/  event_leader_ebb_init (struct event*) ; 
 int event_open (struct event*) ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fork () ; 
 int /*<<< orphan*/  kill (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int pick_online_cpu () ; 
 scalar_t__ sample_period ; 
 int /*<<< orphan*/  setup_ebb_handler (int /*<<< orphan*/ ) ; 
 scalar_t__ sigaction (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sigint_action ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  standard_ebb_callee ; 
 int test_harness (int (*) (),char*) ; 
 int wait_for_child (scalar_t__) ; 

__attribute__((used)) static inline uint32_t pmc_sample_period(uint32_t value)
{
	return COUNTER_OVERFLOW - value;
}

__attribute__((used)) static inline void ebb_enable_pmc_counting(int pmc)
{
	ebb_state.pmc_enable[PMC_INDEX(pmc)] = true;
}

__attribute__((used)) static void sigint_handler(int signal)
{
	child_should_exit = true;
}

__attribute__((used)) static int cycles_child(void)
{
	struct event event;

	if (sigaction(SIGINT, &sigint_action, NULL)) {
		perror("sigaction");
		return 1;
	}

	event_init_named(&event, 0x1001e, "cycles");
	event_leader_ebb_init(&event);

	event.attr.exclude_kernel = 1;
	event.attr.exclude_hv = 1;
	event.attr.exclude_idle = 1;

	FAIL_IF(event_open(&event));

	ebb_enable_pmc_counting(1);
	setup_ebb_handler(standard_ebb_callee);
	ebb_global_enable();

	FAIL_IF(ebb_event_enable(&event));

	mtspr(SPRN_PMC1, pmc_sample_period(sample_period));

	while (!child_should_exit) {
		FAIL_IF(core_busy_loop());
		FAIL_IF(ebb_check_mmcr0());
	}

	ebb_global_disable();
	ebb_freeze_pmcs();

	count_pmc(1, sample_period);

	dump_summary_ebb_state();

	event_close(&event);

	FAIL_IF(ebb_state.stats.ebb_count == 0);

	return 0;
}

int multi_ebb_procs(void)
{
	pid_t pids[NR_CHILDREN];
	int cpu, rc, i;

	SKIP_IF(!ebb_is_supported());

	cpu = pick_online_cpu();
	FAIL_IF(cpu < 0);
	FAIL_IF(bind_to_cpu(cpu));

	for (i = 0; i < NR_CHILDREN; i++) {
		pids[i] = fork();
		if (pids[i] == 0)
			exit(cycles_child());
	}

	/* Have them all run for "a while" */
	sleep(10);

	rc = 0;
	for (i = 0; i < NR_CHILDREN; i++) {
		/* Tell them to stop */
		kill(pids[i], SIGINT);
		/* And wait */
		rc |= wait_for_child(pids[i]);
	}

	return rc;
}

int main(void)
{
	return test_harness(multi_ebb_procs, "multi_ebb_procs");
}

