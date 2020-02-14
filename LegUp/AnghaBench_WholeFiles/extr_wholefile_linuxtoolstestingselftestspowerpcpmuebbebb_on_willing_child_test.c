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
union pipe {int /*<<< orphan*/  fds; } ;
typedef  scalar_t__ uint32_t ;
struct TYPE_5__ {int exclude_kernel; int exclude_hv; int exclude_idle; } ;
struct event {TYPE_2__ attr; } ;
typedef  scalar_t__ pid_t ;
struct TYPE_4__ {int ebb_count; } ;
struct TYPE_6__ {int* pmc_enable; TYPE_1__ stats; } ;

/* Variables and functions */
 scalar_t__ COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int core_busy_loop () ; 
 int /*<<< orphan*/  count_pmc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dump_ebb_state () ; 
 int ebb_event_enable (struct event*) ; 
 int /*<<< orphan*/  ebb_freeze_pmcs () ; 
 int /*<<< orphan*/  ebb_global_disable () ; 
 int /*<<< orphan*/  ebb_global_enable () ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_3__ ebb_state ; 
 int /*<<< orphan*/  event_close (struct event*) ; 
 int /*<<< orphan*/  event_init_named (struct event*,int,char*) ; 
 int /*<<< orphan*/  event_leader_ebb_init (struct event*) ; 
 int event_open_with_pid (struct event*,scalar_t__) ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fork () ; 
 int notify_parent (union pipe) ; 
 int pipe (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sample_period ; 
 int /*<<< orphan*/  setup_ebb_handler (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  standard_ebb_callee ; 
 int sync_with_child (union pipe,union pipe) ; 
 int test_harness (int (*) (),char*) ; 
 int wait_for_child (scalar_t__) ; 
 int wait_for_parent (union pipe) ; 

__attribute__((used)) static inline uint32_t pmc_sample_period(uint32_t value)
{
	return COUNTER_OVERFLOW - value;
}

__attribute__((used)) static inline void ebb_enable_pmc_counting(int pmc)
{
	ebb_state.pmc_enable[PMC_INDEX(pmc)] = true;
}

__attribute__((used)) static int victim_child(union pipe read_pipe, union pipe write_pipe)
{
	FAIL_IF(wait_for_parent(read_pipe));

	/* Setup our EBB handler, before the EBB event is created */
	ebb_enable_pmc_counting(1);
	setup_ebb_handler(standard_ebb_callee);
	ebb_global_enable();

	FAIL_IF(notify_parent(write_pipe));

	while (ebb_state.stats.ebb_count < 20) {
		FAIL_IF(core_busy_loop());
	}

	ebb_global_disable();
	ebb_freeze_pmcs();

	count_pmc(1, sample_period);

	dump_ebb_state();

	FAIL_IF(ebb_state.stats.ebb_count == 0);

	return 0;
}

int ebb_on_willing_child(void)
{
	union pipe read_pipe, write_pipe;
	struct event event;
	pid_t pid;

	SKIP_IF(!ebb_is_supported());

	FAIL_IF(pipe(read_pipe.fds) == -1);
	FAIL_IF(pipe(write_pipe.fds) == -1);

	pid = fork();
	if (pid == 0) {
		/* NB order of pipes looks reversed */
		exit(victim_child(write_pipe, read_pipe));
	}

	/* Signal the child to setup its EBB handler */
	FAIL_IF(sync_with_child(read_pipe, write_pipe));

	/* Child is running now */

	event_init_named(&event, 0x1001e, "cycles");
	event_leader_ebb_init(&event);

	event.attr.exclude_kernel = 1;
	event.attr.exclude_hv = 1;
	event.attr.exclude_idle = 1;

	FAIL_IF(event_open_with_pid(&event, pid));
	FAIL_IF(ebb_event_enable(&event));

	/* Child show now take EBBs and then exit */
	FAIL_IF(wait_for_child(pid));

	event_close(&event);

	return 0;
}

int main(void)
{
	return test_harness(ebb_on_willing_child, "ebb_on_willing_child");
}

