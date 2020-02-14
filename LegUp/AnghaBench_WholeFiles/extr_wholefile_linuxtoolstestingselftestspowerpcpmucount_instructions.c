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
typedef  int u64 ;
struct TYPE_4__ {int value; } ;
struct TYPE_3__ {int disabled; int exclude_kernel; int exclude_hv; int exclude_idle; } ;
struct event {int /*<<< orphan*/  fd; TYPE_2__ result; TYPE_1__ attr; } ;
typedef  int s64 ;

/* Variables and functions */
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int PERF_COUNT_HW_CPU_CYCLES ; 
 int PERF_COUNT_HW_INSTRUCTIONS ; 
 int /*<<< orphan*/  PERF_TYPE_HARDWARE ; 
 int /*<<< orphan*/  PR_TASK_PERF_EVENTS_DISABLE ; 
 int /*<<< orphan*/  PR_TASK_PERF_EVENTS_ENABLE ; 
 int eat_cpu (int (*) ()) ; 
 int /*<<< orphan*/  event_close (struct event*) ; 
 int /*<<< orphan*/  event_init_opts (struct event*,int,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ event_open (struct event*) ; 
 scalar_t__ event_open_with_group (struct event*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  event_read (struct event*) ; 
 int /*<<< orphan*/  event_report (struct event*) ; 
 int /*<<< orphan*/  event_reset (struct event*) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  prctl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,int,...) ; 
 int test_harness (int (*) (),char*) ; 
 int /*<<< orphan*/  thirty_two_instruction_loop (int) ; 

__attribute__((used)) static void setup_event(struct event *e, u64 config, char *name)
{
	event_init_opts(e, config, PERF_TYPE_HARDWARE, name);

	e->attr.disabled = 1;
	e->attr.exclude_kernel = 1;
	e->attr.exclude_hv = 1;
	e->attr.exclude_idle = 1;
}

__attribute__((used)) static int do_count_loop(struct event *events, u64 instructions,
			 u64 overhead, bool report)
{
	s64 difference, expected;
	double percentage;

	prctl(PR_TASK_PERF_EVENTS_ENABLE);

	/* Run for 1M instructions */
	thirty_two_instruction_loop(instructions >> 5);

	prctl(PR_TASK_PERF_EVENTS_DISABLE);

	event_read(&events[0]);
	event_read(&events[1]);

	expected = instructions + overhead;
	difference = events[0].result.value - expected;
	percentage = (double)difference / events[0].result.value * 100;

	if (report) {
		event_report(&events[0]);
		event_report(&events[1]);

		printf("Looped for %llu instructions, overhead %llu\n", instructions, overhead);
		printf("Expected %llu\n", expected);
		printf("Actual   %llu\n", events[0].result.value);
		printf("Delta    %lld, %f%%\n", difference, percentage);
	}

	event_reset(&events[0]);
	event_reset(&events[1]);

	if (difference < 0)
		difference = -difference;

	/* Tolerate a difference below 0.0001 % */
	difference *= 10000 * 100;
	if (difference / events[0].result.value)
		return -1;

	return 0;
}

__attribute__((used)) static u64 determine_overhead(struct event *events)
{
	u64 current, overhead;
	int i;

	do_count_loop(events, 0, 0, false);
	overhead = events[0].result.value;

	for (i = 0; i < 100; i++) {
		do_count_loop(events, 0, 0, false);
		current = events[0].result.value;
		if (current < overhead) {
			printf("Replacing overhead %llu with %llu\n", overhead, current);
			overhead = current;
		}
	}

	return overhead;
}

__attribute__((used)) static int test_body(void)
{
	struct event events[2];
	u64 overhead;

	setup_event(&events[0], PERF_COUNT_HW_INSTRUCTIONS, "instructions");
	setup_event(&events[1], PERF_COUNT_HW_CPU_CYCLES, "cycles");

	if (event_open(&events[0])) {
		perror("perf_event_open");
		return -1;
	}

	if (event_open_with_group(&events[1], events[0].fd)) {
		perror("perf_event_open");
		return -1;
	}

	overhead = determine_overhead(events);
	printf("Overhead of null loop: %llu instructions\n", overhead);

	/* Run for 1Mi instructions */
	FAIL_IF(do_count_loop(events, 1000000, overhead, true));

	/* Run for 10Mi instructions */
	FAIL_IF(do_count_loop(events, 10000000, overhead, true));

	/* Run for 100Mi instructions */
	FAIL_IF(do_count_loop(events, 100000000, overhead, true));

	/* Run for 1Bi instructions */
	FAIL_IF(do_count_loop(events, 1000000000, overhead, true));

	/* Run for 16Bi instructions */
	FAIL_IF(do_count_loop(events, 16000000000, overhead, true));

	/* Run for 64Bi instructions */
	FAIL_IF(do_count_loop(events, 64000000000, overhead, true));

	event_close(&events[0]);
	event_close(&events[1]);

	return 0;
}

__attribute__((used)) static int count_instructions(void)
{
	return eat_cpu(test_body);
}

int main(void)
{
	return test_harness(count_instructions, "count_instructions");
}

