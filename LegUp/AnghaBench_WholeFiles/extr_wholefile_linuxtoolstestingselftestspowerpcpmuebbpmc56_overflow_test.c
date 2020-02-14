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
struct TYPE_6__ {int* pmc_enable; TYPE_2__ stats; } ;

/* Variables and functions */
 int BESCR_PMEO ; 
 int COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  SPRN_BESCR ; 
 int /*<<< orphan*/  SPRN_PMC2 ; 
 int /*<<< orphan*/  SPRN_PMC5 ; 
 int /*<<< orphan*/  SPRN_PMC6 ; 
 int core_busy_loop () ; 
 int /*<<< orphan*/  count_pmc (int,int) ; 
 int /*<<< orphan*/  dump_ebb_state () ; 
 int ebb_event_enable (struct event*) ; 
 int /*<<< orphan*/  ebb_freeze_pmcs () ; 
 int /*<<< orphan*/  ebb_global_disable () ; 
 int /*<<< orphan*/  ebb_global_enable () ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_3__ ebb_state ; 
 int /*<<< orphan*/  event_close (struct event*) ; 
 int /*<<< orphan*/  event_init (struct event*,int) ; 
 int /*<<< orphan*/  event_leader_ebb_init (struct event*) ; 
 int event_open (struct event*) ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int pmc56_overflowed ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  reset_ebb () ; 
 int sample_period ; 
 int /*<<< orphan*/  setup_ebb_handler (void (*) ()) ; 
 int test_harness (int (*) (),char*) ; 

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
	uint64_t val;

	val = mfspr(SPRN_BESCR);
	if (!(val & BESCR_PMEO)) {
		ebb_state.stats.spurious++;
		goto out;
	}

	ebb_state.stats.ebb_count++;
	count_pmc(2, sample_period);

	val = mfspr(SPRN_PMC5);
	if (val >= COUNTER_OVERFLOW)
		pmc56_overflowed++;

	count_pmc(5, COUNTER_OVERFLOW);

	val = mfspr(SPRN_PMC6);
	if (val >= COUNTER_OVERFLOW)
		pmc56_overflowed++;

	count_pmc(6, COUNTER_OVERFLOW);

out:
	reset_ebb();
}

int pmc56_overflow(void)
{
	struct event event;

	SKIP_IF(!ebb_is_supported());

	/* Use PMC2 so we set PMCjCE, which enables PMC5/6 */
	event_init(&event, 0x2001e);
	event_leader_ebb_init(&event);

	event.attr.exclude_kernel = 1;
	event.attr.exclude_hv = 1;
	event.attr.exclude_idle = 1;

	FAIL_IF(event_open(&event));

	setup_ebb_handler(ebb_callee);
	ebb_global_enable();

	FAIL_IF(ebb_event_enable(&event));

	mtspr(SPRN_PMC2, pmc_sample_period(sample_period));
	mtspr(SPRN_PMC5, 0);
	mtspr(SPRN_PMC6, 0);

	while (ebb_state.stats.ebb_count < 10)
		FAIL_IF(core_busy_loop());

	ebb_global_disable();
	ebb_freeze_pmcs();

	count_pmc(2, sample_period);

	dump_ebb_state();

	printf("PMC5/6 overflow %d\n", pmc56_overflowed);

	event_close(&event);

	FAIL_IF(ebb_state.stats.ebb_count == 0 || pmc56_overflowed != 0);

	return 0;
}

int main(void)
{
	return test_harness(pmc56_overflow, "pmc56_overflow");
}

