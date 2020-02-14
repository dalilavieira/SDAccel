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
typedef  int uint64_t ;
typedef  int uint32_t ;
struct TYPE_4__ {int exclude_kernel; int exclude_hv; int exclude_idle; } ;
struct event {TYPE_1__ attr; } ;
struct TYPE_5__ {int ebb_count; int /*<<< orphan*/  spurious; } ;
struct TYPE_6__ {int* pmc_enable; TYPE_2__ stats; int /*<<< orphan*/  trace; } ;

/* Variables and functions */
 int BESCR_PMEO ; 
 int COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int MMCR0_FC ; 
 int MMCR0_PMAO ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  SPRN_BESCR ; 
 int /*<<< orphan*/  SPRN_MMCR0 ; 
 int /*<<< orphan*/  SPRN_PMC1 ; 
 int core_busy_loop () ; 
 int /*<<< orphan*/  count_pmc (int,int) ; 
 int counters_frozen ; 
 int /*<<< orphan*/  dump_ebb_state () ; 
 int ebb_event_enable (struct event*) ; 
 int /*<<< orphan*/  ebb_freeze_pmcs () ; 
 int /*<<< orphan*/  ebb_global_disable () ; 
 int /*<<< orphan*/  ebb_global_enable () ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_3__ ebb_state ; 
 int ebbs_while_frozen ; 
 int /*<<< orphan*/  event_close (struct event*) ; 
 int /*<<< orphan*/  event_init_named (struct event*,int,char*) ; 
 int /*<<< orphan*/  event_leader_ebb_init (struct event*) ; 
 int event_open (struct event*) ; 
 int /*<<< orphan*/  mb () ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  reset_ebb_with_clear_mask (int) ; 
 int sample_period ; 
 int /*<<< orphan*/  setup_ebb_handler (void (*) ()) ; 
 int test_harness (int (*) (),char*) ; 
 int /*<<< orphan*/  trace_log_counter (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  trace_log_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  trace_log_string (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static inline uint32_t pmc_sample_period(uint32_t value)
{
	return COUNTER_OVERFLOW - value;
}

__attribute__((used)) static inline void ebb_enable_pmc_counting(int pmc)
{
	ebb_state.pmc_enable[PMC_INDEX(pmc)] = true;
}

__attribute__((used)) static void ebb_callee(void)
{
	uint64_t mask, val;

	mask = MMCR0_PMAO | MMCR0_FC;

	val = mfspr(SPRN_BESCR);
	if (!(val & BESCR_PMEO)) {
		ebb_state.stats.spurious++;
		goto out;
	}

	ebb_state.stats.ebb_count++;
	trace_log_counter(ebb_state.trace, ebb_state.stats.ebb_count);

	val = mfspr(SPRN_MMCR0);
	trace_log_reg(ebb_state.trace, SPRN_MMCR0, val);

	if (counters_frozen) {
		trace_log_string(ebb_state.trace, "frozen");
		ebbs_while_frozen++;
		mask &= ~MMCR0_FC;
	}

	count_pmc(1, sample_period);
out:
	reset_ebb_with_clear_mask(mask);
}

int cycles_with_freeze(void)
{
	struct event event;
	uint64_t val;
	bool fc_cleared;

	SKIP_IF(!ebb_is_supported());

	event_init_named(&event, 0x1001e, "cycles");
	event_leader_ebb_init(&event);

	event.attr.exclude_kernel = 1;
	event.attr.exclude_hv = 1;
	event.attr.exclude_idle = 1;

	FAIL_IF(event_open(&event));

	setup_ebb_handler(ebb_callee);
	ebb_global_enable();
	FAIL_IF(ebb_event_enable(&event));

	mtspr(SPRN_PMC1, pmc_sample_period(sample_period));

	fc_cleared = false;

	/* Make sure we loop until we take at least one EBB */
	while ((ebb_state.stats.ebb_count < 20 && !fc_cleared) ||
		ebb_state.stats.ebb_count < 1)
	{
		counters_frozen = false;
		mb();
		mtspr(SPRN_MMCR0, mfspr(SPRN_MMCR0) & ~MMCR0_FC);

		FAIL_IF(core_busy_loop());

		counters_frozen = true;
		mb();
		mtspr(SPRN_MMCR0, mfspr(SPRN_MMCR0) |  MMCR0_FC);

		val = mfspr(SPRN_MMCR0);
		if (! (val & MMCR0_FC)) {
			printf("Outside of loop, FC NOT set MMCR0 0x%lx\n", val);
			fc_cleared = true;
		}
	}

	ebb_global_disable();
	ebb_freeze_pmcs();

	count_pmc(1, sample_period);

	dump_ebb_state();

	printf("EBBs while frozen %d\n", ebbs_while_frozen);

	event_close(&event);

	FAIL_IF(ebb_state.stats.ebb_count == 0);
	FAIL_IF(fc_cleared);

	return 0;
}

int main(void)
{
	return test_harness(cycles_with_freeze, "cycles_with_freeze");
}

