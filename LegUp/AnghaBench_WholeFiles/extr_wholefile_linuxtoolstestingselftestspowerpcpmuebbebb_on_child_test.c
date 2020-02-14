#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
union pipe {int /*<<< orphan*/  fds; } ;
typedef  scalar_t__ uint32_t ;
struct TYPE_3__ {int exclude_kernel; int exclude_hv; int exclude_idle; } ;
struct event {TYPE_1__ attr; } ;
typedef  scalar_t__ pid_t ;
struct TYPE_4__ {int* pmc_enable; } ;

/* Variables and functions */
 scalar_t__ COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int ebb_event_enable (struct event*) ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_2__ ebb_state ; 
 int /*<<< orphan*/  event_close (struct event*) ; 
 int /*<<< orphan*/  event_init_named (struct event*,int,char*) ; 
 int /*<<< orphan*/  event_leader_ebb_init (struct event*) ; 
 int event_open_with_pid (struct event*,scalar_t__) ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fork () ; 
 int notify_parent (union pipe) ; 
 int pipe (int /*<<< orphan*/ ) ; 
 int sync_with_child (union pipe,union pipe) ; 
 int test_harness (int (*) (),char*) ; 
 int wait_for_child (scalar_t__) ; 
 int wait_for_parent (union pipe) ; 
 int /*<<< orphan*/  write_pmc1 () ; 

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
	int i;

	FAIL_IF(wait_for_parent(read_pipe));
	FAIL_IF(notify_parent(write_pipe));

	/* Parent creates EBB event */

	FAIL_IF(wait_for_parent(read_pipe));
	FAIL_IF(notify_parent(write_pipe));

	/* Check the EBB is enabled by writing PMC1 */
	write_pmc1();

	/* EBB event is enabled here */
	for (i = 0; i < 1000000; i++) ;

	return 0;
}

int ebb_on_child(void)
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

	FAIL_IF(sync_with_child(read_pipe, write_pipe));

	/* Child is running now */

	event_init_named(&event, 0x1001e, "cycles");
	event_leader_ebb_init(&event);

	event.attr.exclude_kernel = 1;
	event.attr.exclude_hv = 1;
	event.attr.exclude_idle = 1;

	FAIL_IF(event_open_with_pid(&event, pid));
	FAIL_IF(ebb_event_enable(&event));

	FAIL_IF(sync_with_child(read_pipe, write_pipe));

	/* Child should just exit happily */
	FAIL_IF(wait_for_child(pid));

	event_close(&event);

	return 0;
}

int main(void)
{
	return test_harness(ebb_on_child, "ebb_on_child");
}

