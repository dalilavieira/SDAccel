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
typedef  scalar_t__ uint32_t ;
typedef  scalar_t__ pid_t ;
struct TYPE_2__ {int* pmc_enable; } ;

/* Variables and functions */
 scalar_t__ COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 scalar_t__ MMCR0_FC ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  SPRN_BESCR ; 
 int /*<<< orphan*/  SPRN_EBBHR ; 
 int /*<<< orphan*/  SPRN_EBBRR ; 
 int /*<<< orphan*/  SPRN_MMCR0 ; 
 int /*<<< orphan*/  SPRN_PMC1 ; 
 int catch_sigill (int /*<<< orphan*/ ) ; 
 int ebb_event_enable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ebb_global_enable () ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_1__ ebb_state ; 
 int /*<<< orphan*/  event ; 
 int /*<<< orphan*/  event_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  event_init_named (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  event_leader_ebb_init (int /*<<< orphan*/ *) ; 
 int event_open (int /*<<< orphan*/ *) ; 
 int event_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fork () ; 
 scalar_t__ mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ sample_period ; 
 int /*<<< orphan*/  setup_ebb_handler (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  standard_ebb_callee ; 
 int test_harness (int (*) (),char*) ; 
 int wait_for_child (scalar_t__) ; 
 int /*<<< orphan*/  write_pmc1 ; 

__attribute__((used)) static inline uint32_t pmc_sample_period(uint32_t value)
{
	return COUNTER_OVERFLOW - value;
}

__attribute__((used)) static inline void ebb_enable_pmc_counting(int pmc)
{
	ebb_state.pmc_enable[PMC_INDEX(pmc)] = true;
}

__attribute__((used)) static int child(void)
{
	/* Even though we have EBE=0 we can still see the EBB regs */
	FAIL_IF(mfspr(SPRN_BESCR) != 0);
	FAIL_IF(mfspr(SPRN_EBBHR) != 0);
	FAIL_IF(mfspr(SPRN_EBBRR) != 0);

	FAIL_IF(catch_sigill(write_pmc1));

	/* We can still read from the event, though it is on our parent */
	FAIL_IF(event_read(&event));

	return 0;
}

int fork_cleanup(void)
{
	pid_t pid;

	SKIP_IF(!ebb_is_supported());

	event_init_named(&event, 0x1001e, "cycles");
	event_leader_ebb_init(&event);

	FAIL_IF(event_open(&event));

	ebb_enable_pmc_counting(1);
	setup_ebb_handler(standard_ebb_callee);
	ebb_global_enable();

	FAIL_IF(ebb_event_enable(&event));

	mtspr(SPRN_MMCR0, MMCR0_FC);
	mtspr(SPRN_PMC1, pmc_sample_period(sample_period));

	/* Don't need to actually take any EBBs */

	pid = fork();
	if (pid == 0)
		exit(child());

	/* Child does the actual testing */
	FAIL_IF(wait_for_child(pid));

	/* After fork */
	event_close(&event);

	return 0;
}

int main(void)
{
	return test_harness(fork_cleanup, "fork_cleanup");
}

