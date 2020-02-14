#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_7__ {int exclude_kernel; int exclude_hv; int exclude_idle; } ;
struct TYPE_5__ {int value; } ;
struct event {TYPE_3__ attr; TYPE_1__ result; } ;
typedef  int int64_t ;
struct TYPE_6__ {int* pmc_count; int ebb_count; int /*<<< orphan*/  spurious; } ;
struct TYPE_8__ {int* pmc_enable; TYPE_2__ stats; } ;

/* Variables and functions */
 int BESCR_PMEO ; 
 scalar_t__ COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int MMCR0_FC ; 
 int /*<<< orphan*/  MMCR0_PMAO ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  SPRN_BESCR ; 
 int /*<<< orphan*/  SPRN_MMCR0 ; 
 int /*<<< orphan*/  clear_ebb_stats () ; 
 int /*<<< orphan*/  count_pmc (int,scalar_t__) ; 
 int counters_frozen ; 
 int ebb_event_enable (struct event*) ; 
 int /*<<< orphan*/  ebb_global_disable () ; 
 int /*<<< orphan*/  ebb_global_enable () ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_4__ ebb_state ; 
 int /*<<< orphan*/  event_close (struct event*) ; 
 int /*<<< orphan*/  event_init_named (struct event*,int,char*) ; 
 int /*<<< orphan*/  event_leader_ebb_init (struct event*) ; 
 int event_open (struct event*) ; 
 int /*<<< orphan*/  mb () ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  reset_ebb () ; 
 int /*<<< orphan*/  reset_ebb_with_clear_mask (int /*<<< orphan*/ ) ; 
 scalar_t__ sample_period ; 
 int /*<<< orphan*/  setup_ebb_handler (void (*) ()) ; 
 int test_harness (int (*) (),char*) ; 
 int /*<<< orphan*/  test_harness_set_timeout (int) ; 
 int /*<<< orphan*/  thirty_two_instruction_loop (int) ; 

__attribute__((used)) static inline uint32_t pmc_sample_period(uint32_t value)
{
	return COUNTER_OVERFLOW - value;
}

__attribute__((used)) static inline void ebb_enable_pmc_counting(int pmc)
{
	ebb_state.pmc_enable[PMC_INDEX(pmc)] = true;
}

__attribute__((used)) static int do_count_loop(struct event *event, uint64_t instructions,
			 uint64_t overhead, bool report)
{
	int64_t difference, expected;
	double percentage;

	clear_ebb_stats();

	counters_frozen = false;
	mb();
	mtspr(SPRN_MMCR0, mfspr(SPRN_MMCR0) & ~MMCR0_FC);

	thirty_two_instruction_loop(instructions >> 5);

	counters_frozen = true;
	mb();
	mtspr(SPRN_MMCR0, mfspr(SPRN_MMCR0) | MMCR0_FC);

	count_pmc(4, sample_period);

	event->result.value = ebb_state.stats.pmc_count[4-1];
	expected = instructions + overhead;
	difference = event->result.value - expected;
	percentage = (double)difference / event->result.value * 100;

	if (report) {
		printf("Looped for %lu instructions, overhead %lu\n", instructions, overhead);
		printf("Expected %lu\n", expected);
		printf("Actual   %llu\n", event->result.value);
		printf("Delta    %ld, %f%%\n", difference, percentage);
		printf("Took %d EBBs\n", ebb_state.stats.ebb_count);
	}

	if (difference < 0)
		difference = -difference;

	/* Tolerate a difference of up to 0.0001 % */
	difference *= 10000 * 100;
	if (difference / event->result.value)
		return -1;

	return 0;
}

__attribute__((used)) static uint64_t determine_overhead(struct event *event)
{
	uint64_t current, overhead;
	int i;

	do_count_loop(event, 0, 0, false);
	overhead = event->result.value;

	for (i = 0; i < 100; i++) {
		do_count_loop(event, 0, 0, false);
		current = event->result.value;
		if (current < overhead) {
			printf("Replacing overhead %lu with %lu\n", overhead, current);
			overhead = current;
		}
	}

	return overhead;
}

__attribute__((used)) static void pmc4_ebb_callee(void)
{
	uint64_t val;

	val = mfspr(SPRN_BESCR);
	if (!(val & BESCR_PMEO)) {
		ebb_state.stats.spurious++;
		goto out;
	}

	ebb_state.stats.ebb_count++;
	count_pmc(4, sample_period);
out:
	if (counters_frozen)
		reset_ebb_with_clear_mask(MMCR0_PMAO);
	else
		reset_ebb();
}

int instruction_count(void)
{
	struct event event;
	uint64_t overhead;

	SKIP_IF(!ebb_is_supported());

	event_init_named(&event, 0x400FA, "PM_RUN_INST_CMPL");
	event_leader_ebb_init(&event);
	event.attr.exclude_kernel = 1;
	event.attr.exclude_hv = 1;
	event.attr.exclude_idle = 1;

	FAIL_IF(event_open(&event));
	FAIL_IF(ebb_event_enable(&event));

	sample_period = COUNTER_OVERFLOW;

	setup_ebb_handler(pmc4_ebb_callee);
	mtspr(SPRN_MMCR0, mfspr(SPRN_MMCR0) & ~MMCR0_FC);
	ebb_global_enable();

	overhead = determine_overhead(&event);
	printf("Overhead of null loop: %lu instructions\n", overhead);

	/* Run for 1M instructions */
	FAIL_IF(do_count_loop(&event, 0x100000, overhead, true));

	/* Run for 10M instructions */
	FAIL_IF(do_count_loop(&event, 0xa00000, overhead, true));

	/* Run for 100M instructions */
	FAIL_IF(do_count_loop(&event, 0x6400000, overhead, true));

	/* Run for 1G instructions */
	FAIL_IF(do_count_loop(&event, 0x40000000, overhead, true));

	/* Run for 16G instructions */
	FAIL_IF(do_count_loop(&event, 0x400000000, overhead, true));

	/* Run for 64G instructions */
	FAIL_IF(do_count_loop(&event, 0x1000000000, overhead, true));

	/* Run for 128G instructions */
	FAIL_IF(do_count_loop(&event, 0x2000000000, overhead, true));

	ebb_global_disable();
	event_close(&event);

	printf("Finished OK\n");

	return 0;
}

int main(void)
{
	test_harness_set_timeout(300);
	return test_harness(instruction_count, "instruction_count");
}

