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

/* Variables and functions */
 int /*<<< orphan*/  backtrace_tasklet ; 
 int /*<<< orphan*/  backtrace_work ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dump_stack () ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void backtrace_test_normal(void)
{
	pr_info("Testing a backtrace from process context.\n");
	pr_info("The following trace is a kernel self test and not a bug!\n");

	dump_stack();
}

__attribute__((used)) static void backtrace_test_irq_callback(unsigned long data)
{
	dump_stack();
	complete(&backtrace_work);
}

__attribute__((used)) static void backtrace_test_irq(void)
{
	pr_info("Testing a backtrace from irq context.\n");
	pr_info("The following trace is a kernel self test and not a bug!\n");

	init_completion(&backtrace_work);
	tasklet_schedule(&backtrace_tasklet);
	wait_for_completion(&backtrace_work);
}

__attribute__((used)) static void backtrace_test_saved(void)
{
	pr_info("Saved backtrace test skipped.\n");
}

__attribute__((used)) static int backtrace_regression_test(void)
{
	pr_info("====[ backtrace testing ]===========\n");

	backtrace_test_normal();
	backtrace_test_irq();
	backtrace_test_saved();

	pr_info("====[ end of backtrace testing ]====\n");
	return 0;
}

__attribute__((used)) static void exitf(void)
{
}

