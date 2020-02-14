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
 int /*<<< orphan*/  ebb_child (union pipe,union pipe) ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_2__ ebb_state ; 
 int event_disable (struct event*) ; 
 int event_enable (struct event*) ; 
 int /*<<< orphan*/  event_init_named (struct event*,int,char*) ; 
 int event_open_with_pid (struct event*,scalar_t__) ; 
 int event_read (struct event*) ; 
 int /*<<< orphan*/  event_report (struct event*) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 scalar_t__ fork () ; 
 int /*<<< orphan*/  kill_child_and_wait (scalar_t__) ; 
 int pipe (int /*<<< orphan*/ ) ; 
 int sync_with_child (union pipe,union pipe) ; 
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

__attribute__((used)) static int setup_child_event(struct event *event, pid_t child_pid)
{
	event_init_named(event, 0x400FA, "PM_RUN_INST_CMPL");

	event->attr.exclude_kernel = 1;
	event->attr.exclude_hv = 1;
	event->attr.exclude_idle = 1;

	FAIL_IF(event_open_with_pid(event, child_pid));
	FAIL_IF(event_enable(event));

	return 0;
}

int task_event_vs_ebb(void)
{
	union pipe read_pipe, write_pipe;
	struct event event;
	pid_t pid;
	int rc;

	SKIP_IF(!ebb_is_supported());

	FAIL_IF(pipe(read_pipe.fds) == -1);
	FAIL_IF(pipe(write_pipe.fds) == -1);

	pid = fork();
	if (pid == 0) {
		/* NB order of pipes looks reversed */
		exit(ebb_child(write_pipe, read_pipe));
	}

	/* We setup the task event first */
	rc = setup_child_event(&event, pid);
	if (rc) {
		kill_child_and_wait(pid);
		return rc;
	}

	/* Signal the child to install its EBB event and wait */
	if (sync_with_child(read_pipe, write_pipe))
		/* If it fails, wait for it to exit */
		goto wait;

	/* Signal the child to run */
	FAIL_IF(sync_with_child(read_pipe, write_pipe));

wait:
	/* The EBB event should push the task event off so the child should succeed */
	FAIL_IF(wait_for_child(pid));
	FAIL_IF(event_disable(&event));
	FAIL_IF(event_read(&event));

	event_report(&event);

	/* The task event may have run, or not so we can't assert anything about it */

	return 0;
}

int main(void)
{
	return test_harness(task_event_vs_ebb, "task_event_vs_ebb");
}

