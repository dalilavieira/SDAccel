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
struct TYPE_2__ {int /*<<< orphan*/  cpus_allowed; } ;

/* Variables and functions */
 int /*<<< orphan*/  HZ ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 TYPE_1__* current ; 
 int /*<<< orphan*/ * kthread_run (int (*) (void*),int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  kthread_should_stop () ; 
 int /*<<< orphan*/  kthread_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/ * random_strings ; 
 int /*<<< orphan*/  schedule_timeout (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_current_state (int /*<<< orphan*/ ) ; 
 scalar_t__ simple_thread_cnt ; 
 int /*<<< orphan*/ * simple_tsk_fn ; 
 int /*<<< orphan*/  thread_mutex ; 
 int /*<<< orphan*/  trace_foo_bar (char*,int,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_foo_bar_with_cond (char*,int) ; 
 int /*<<< orphan*/  trace_foo_bar_with_fn (char*,int) ; 
 int /*<<< orphan*/  trace_foo_with_template_cond (char*,int) ; 
 int /*<<< orphan*/  trace_foo_with_template_fn (char*,int) ; 
 int /*<<< orphan*/  trace_foo_with_template_print (char*,int) ; 
 int /*<<< orphan*/  trace_foo_with_template_simple (char*,int) ; 

__attribute__((used)) static inline int __length_of(const int *list)
{
	int i;

	if (!list)
		return 0;

	for (i = 0; list[i]; i++)
		;
	return i;
}

__attribute__((used)) static void simple_thread_func(int cnt)
{
	int array[6];
	int len = cnt % 5;
	int i;

	set_current_state(TASK_INTERRUPTIBLE);
	schedule_timeout(HZ);

	for (i = 0; i < len; i++)
		array[i] = i + 1;
	array[i] = 0;

	/* Silly tracepoints */
	trace_foo_bar("hello", cnt, array, random_strings[len],
		      &current->cpus_allowed);

	trace_foo_with_template_simple("HELLO", cnt);

	trace_foo_bar_with_cond("Some times print", cnt);

	trace_foo_with_template_cond("prints other times", cnt);

	trace_foo_with_template_print("I have to be different", cnt);
}

__attribute__((used)) static int simple_thread(void *arg)
{
	int cnt = 0;

	while (!kthread_should_stop())
		simple_thread_func(cnt++);

	return 0;
}

__attribute__((used)) static void simple_thread_func_fn(int cnt)
{
	set_current_state(TASK_INTERRUPTIBLE);
	schedule_timeout(HZ);

	/* More silly tracepoints */
	trace_foo_bar_with_fn("Look at me", cnt);
	trace_foo_with_template_fn("Look at me too", cnt);
}

__attribute__((used)) static int simple_thread_fn(void *arg)
{
	int cnt = 0;

	while (!kthread_should_stop())
		simple_thread_func_fn(cnt++);

	return 0;
}

int foo_bar_reg(void)
{
	mutex_lock(&thread_mutex);
	if (simple_thread_cnt++)
		goto out;

	pr_info("Starting thread for foo_bar_fn\n");
	/*
	 * We shouldn't be able to start a trace when the module is
	 * unloading (there's other locks to prevent that). But
	 * for consistency sake, we still take the thread_mutex.
	 */
	simple_tsk_fn = kthread_run(simple_thread_fn, NULL, "event-sample-fn");
 out:
	mutex_unlock(&thread_mutex);
	return 0;
}

void foo_bar_unreg(void)
{
	mutex_lock(&thread_mutex);
	if (--simple_thread_cnt)
		goto out;

	pr_info("Killing thread for foo_bar_fn\n");
	if (simple_tsk_fn)
		kthread_stop(simple_tsk_fn);
	simple_tsk_fn = NULL;
 out:
	mutex_unlock(&thread_mutex);
}

