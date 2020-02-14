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
struct TYPE_5__ {scalar_t__ ebb_count; int /*<<< orphan*/  spurious; } ;
struct TYPE_6__ {int* pmc_enable; TYPE_2__ stats; int /*<<< orphan*/  trace; } ;

/* Variables and functions */
 int BESCR_PMEO ; 
 int COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int /*<<< orphan*/  MMCR0_PMAO ; 
 scalar_t__ NUMBER_OF_EBBS ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  SPRN_BESCR ; 
 int /*<<< orphan*/  SPRN_MMCR0 ; 
 int /*<<< orphan*/  SPRN_PMC1 ; 
 int /*<<< orphan*/  SPRN_SIAR ; 
 int core_busy_loop () ; 
 int /*<<< orphan*/  count_pmc (int,int) ; 
 int /*<<< orphan*/  dump_ebb_state () ; 
 int ebb_event_enable (struct event*) ; 
 int /*<<< orphan*/  ebb_freeze_pmcs () ; 
 int /*<<< orphan*/  ebb_global_disable () ; 
 int /*<<< orphan*/  ebb_global_enable () ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_3__ ebb_state ; 
 int /*<<< orphan*/  ebb_unfreeze_pmcs () ; 
 int /*<<< orphan*/  event_close (struct event*) ; 
 int /*<<< orphan*/  event_init_named (struct event*,int,char*) ; 
 int /*<<< orphan*/  event_leader_ebb_init (struct event*) ; 
 int event_open (struct event*) ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  reset_ebb () ; 
 int /*<<< orphan*/  reset_ebb_with_clear_mask (int /*<<< orphan*/ ) ; 
 int sample_period ; 
 int /*<<< orphan*/  setup_ebb_handler (void (*) ()) ; 
 int test_harness (int (*) (),char*) ; 
 int /*<<< orphan*/  trace_log_counter (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  trace_log_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

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
	uint64_t siar, val;

	val = mfspr(SPRN_BESCR);
	if (!(val & BESCR_PMEO)) {
		ebb_state.stats.spurious++;
		goto out;
	}

	ebb_state.stats.ebb_count++;
	trace_log_counter(ebb_state.trace, ebb_state.stats.ebb_count);

	/* Resets the PMC */
	count_pmc(1, sample_period);

out:
	if (ebb_state.stats.ebb_count == NUMBER_OF_EBBS)
		/* Reset but leave counters frozen */
		reset_ebb_with_clear_mask(MMCR0_PMAO);
	else
		/* Unfreezes */
		reset_ebb();

	/* Do some stuff to chew some cycles and pop the counter */
	siar = mfspr(SPRN_SIAR);
	trace_log_reg(ebb_state.trace, SPRN_SIAR, siar);

	val = mfspr(SPRN_PMC1);
	trace_log_reg(ebb_state.trace, SPRN_PMC1, val);

	val = mfspr(SPRN_MMCR0);
	trace_log_reg(ebb_state.trace, SPRN_MMCR0, val);
}

int back_to_back_ebbs(void)
{
	struct event event;

	SKIP_IF(!ebb_is_supported());

	event_init_named(&event, 0x1001e, "cycles");
	event_leader_ebb_init(&event);

	event.attr.exclude_kernel = 1;
	event.attr.exclude_hv = 1;
	event.attr.exclude_idle = 1;

	FAIL_IF(event_open(&event));

	setup_ebb_handler(ebb_callee);

	FAIL_IF(ebb_event_enable(&event));

	sample_period = 5;

	ebb_freeze_pmcs();
	mtspr(SPRN_PMC1, pmc_sample_period(sample_period));
	ebb_global_enable();
	ebb_unfreeze_pmcs();

	while (ebb_state.stats.ebb_count < NUMBER_OF_EBBS)
		FAIL_IF(core_busy_loop());

	ebb_global_disable();
	ebb_freeze_pmcs();

	count_pmc(1, sample_period);

	dump_ebb_state();

	event_close(&event);

	FAIL_IF(ebb_state.stats.ebb_count != NUMBER_OF_EBBS);

	return 0;
}

int main(void)
{
	return test_harness(back_to_back_ebbs, "back_to_back_ebbs");
}

