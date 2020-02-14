#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int ulong ;
typedef  int u64 ;

/* Variables and functions */
 int delay ; 
 scalar_t__ kthread_should_stop () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  test_mode ; 
 int trace_clock_local () ; 

__attribute__((used)) static void busy_wait(ulong time)
{
	u64 start, end;
	start = trace_clock_local();
	do {
		end = trace_clock_local();
		if (kthread_should_stop())
			break;
	} while ((end - start) < (time * 1000));
}

__attribute__((used)) static int preemptirq_delay_run(void *data)
{
	unsigned long flags;

	if (!strcmp(test_mode, "irq")) {
		local_irq_save(flags);
		busy_wait(delay);
		local_irq_restore(flags);
	} else if (!strcmp(test_mode, "preempt")) {
		preempt_disable();
		busy_wait(delay);
		preempt_enable();
	}

	return 0;
}

