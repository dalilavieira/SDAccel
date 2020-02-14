#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  TYPE_1__* thread_t ;
typedef  scalar_t__ thread_continue_t ;
typedef  int /*<<< orphan*/  task_t ;
struct kperf_sample {int dummy; } ;
struct kperf_context {uintptr_t* starting_fp; int /*<<< orphan*/  trigger_type; int /*<<< orphan*/  cur_pid; int /*<<< orphan*/  cur_task; TYPE_1__* cur_thread; } ;
typedef  TYPE_2__* processor_t ;
struct TYPE_12__ {scalar_t__ kperf_last_sample_time; } ;
struct TYPE_11__ {int reason; scalar_t__ last_made_runnable_time; scalar_t__ last_run_time; int /*<<< orphan*/  sched_pri; int /*<<< orphan*/  system_timer; int /*<<< orphan*/  user_timer; int /*<<< orphan*/  runnable_timer; } ;

/* Variables and functions */
 int AST_SCHEDULING ; 
 int /*<<< orphan*/  BUF_DATA (int /*<<< orphan*/ ,scalar_t__,scalar_t__,int,...) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  PERF_LZ_CPUSAMPLE ; 
 int /*<<< orphan*/  PERF_LZ_MKRUNNABLE ; 
 int /*<<< orphan*/  PERF_LZ_WAITSAMPLE ; 
 unsigned int SAMPLE_FLAG_CONTINUATION ; 
 unsigned int SAMPLE_FLAG_NON_INTERRUPT ; 
 unsigned int SAMPLE_FLAG_PEND_USER ; 
 scalar_t__ THREAD_NOT_RUNNABLE ; 
 int /*<<< orphan*/  TRIGGER_TYPE_LAZY_CPU ; 
 int /*<<< orphan*/  TRIGGER_TYPE_LAZY_WAIT ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_2__* current_processor () ; 
 int /*<<< orphan*/  get_threadtask (TYPE_1__*) ; 
 unsigned int kperf_action_get_count () ; 
 struct kperf_sample* kperf_intr_sample_buffer () ; 
 int kperf_lazy_cpu_action ; 
 void kperf_lazy_cpu_sample (TYPE_1__*,unsigned int,int) ; 
 scalar_t__ kperf_lazy_cpu_time_threshold ; 
 int kperf_lazy_wait_action ; 
 scalar_t__ kperf_lazy_wait_time_threshold ; 
 int /*<<< orphan*/  kperf_on_cpu_update () ; 
 int /*<<< orphan*/  kperf_sample (struct kperf_sample*,struct kperf_context*,int,unsigned int) ; 
 scalar_t__ mach_absolute_time () ; 
 int /*<<< orphan*/  ml_at_interrupt_context () ; 
 scalar_t__ ml_get_interrupts_enabled () ; 
 int /*<<< orphan*/  task_pid (int /*<<< orphan*/ ) ; 
 scalar_t__ thread_get_last_wait_duration (TYPE_1__*) ; 
 scalar_t__ thread_tid (TYPE_1__*) ; 
 scalar_t__ timer_grab (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timer_update (int /*<<< orphan*/ *,scalar_t__) ; 

void
kperf_lazy_reset(void)
{
	kperf_lazy_wait_action = 0;
	kperf_lazy_wait_time_threshold = 0;
	kperf_lazy_cpu_action = 0;
	kperf_lazy_cpu_time_threshold = 0;
	kperf_on_cpu_update();
}

void
kperf_lazy_off_cpu(thread_t thread)
{
	/* try to lazily sample the CPU if the thread was pre-empted */
	if ((thread->reason & AST_SCHEDULING) != 0) {
		kperf_lazy_cpu_sample(thread, 0, 0);
    }
}

void
kperf_lazy_make_runnable(thread_t thread, bool in_interrupt)
{
	assert(thread->last_made_runnable_time != THREAD_NOT_RUNNABLE);
	/* ignore threads that race to wait and in waking up */
	if (thread->last_run_time > thread->last_made_runnable_time) {
		return;
	}

	uint64_t wait_time = thread_get_last_wait_duration(thread);
	if (wait_time > kperf_lazy_wait_time_threshold) {
		BUF_DATA(PERF_LZ_MKRUNNABLE, (uintptr_t)thread_tid(thread),
				thread->sched_pri, in_interrupt ? 1 : 0);
	}
}

void
kperf_lazy_wait_sample(thread_t thread, thread_continue_t continuation,
		uintptr_t *starting_fp)
{
	/* ignore idle threads */
	if (thread->last_made_runnable_time == THREAD_NOT_RUNNABLE) {
		return;
	}
	/* ignore invalid made runnable times */
	if (thread->last_made_runnable_time < thread->last_run_time) {
		return;
	}

	/* take a sample if thread was waiting for longer than threshold */
	uint64_t wait_time = thread_get_last_wait_duration(thread);
	if (wait_time > kperf_lazy_wait_time_threshold) {
		uint64_t time_now = mach_absolute_time();
		timer_update(&thread->runnable_timer, time_now);
		timer_update(&thread->system_timer, time_now);

		uint64_t runnable_time = timer_grab(&thread->runnable_timer);
		uint64_t running_time = timer_grab(&thread->user_timer) +
				timer_grab(&thread->system_timer);

		BUF_DATA(PERF_LZ_WAITSAMPLE, wait_time, runnable_time, running_time);

		task_t task = get_threadtask(thread);
		struct kperf_context ctx = {
			.cur_thread = thread,
			.cur_task = task,
			.cur_pid = task_pid(task),
			.trigger_type = TRIGGER_TYPE_LAZY_WAIT,
			.starting_fp = starting_fp,
		};

		struct kperf_sample *sample = kperf_intr_sample_buffer();
		if (!sample) {
			return;
		}

		unsigned int flags = SAMPLE_FLAG_PEND_USER;
		flags |= continuation ? SAMPLE_FLAG_CONTINUATION : 0;
		flags |= !ml_at_interrupt_context() ? SAMPLE_FLAG_NON_INTERRUPT : 0;

		kperf_sample(sample, &ctx, kperf_lazy_wait_action, flags);
	}
}

void
kperf_lazy_cpu_sample(thread_t thread, unsigned int flags, bool interrupt)
{
	assert(ml_get_interrupts_enabled() == FALSE);

	/* take a sample if this CPU's last sample time is beyond the threshold */
	processor_t processor = current_processor();
	uint64_t time_now = mach_absolute_time();
	uint64_t since_last_sample = time_now - processor->kperf_last_sample_time;
	if (since_last_sample > kperf_lazy_cpu_time_threshold) {
		processor->kperf_last_sample_time = time_now;
		timer_update(&thread->runnable_timer, time_now);
		timer_update(&thread->system_timer, time_now);

		uint64_t runnable_time = timer_grab(&thread->runnable_timer);
		uint64_t running_time = timer_grab(&thread->user_timer) +
				timer_grab(&thread->system_timer);

		BUF_DATA(PERF_LZ_CPUSAMPLE, running_time, runnable_time,
				thread->sched_pri, interrupt ? 1 : 0);

		task_t task = get_threadtask(thread);
		struct kperf_context ctx = {
			.cur_thread = thread,
			.cur_task = task,
			.cur_pid = task_pid(task),
			.trigger_type = TRIGGER_TYPE_LAZY_CPU,
			.starting_fp = 0,
		};

		struct kperf_sample *sample = kperf_intr_sample_buffer();
		if (!sample) {
			return;
		}

		kperf_sample(sample, &ctx, kperf_lazy_cpu_action,
				SAMPLE_FLAG_PEND_USER | flags);
	}
}

int kperf_lazy_get_wait_action(void) { return kperf_lazy_wait_action; }

int
kperf_lazy_set_wait_action(int action_id)
{
	if (action_id < 0 || (unsigned int)action_id > kperf_action_get_count()) {
		return 1;
	}

	kperf_lazy_wait_action = action_id;
	kperf_on_cpu_update();
	return 0;
}

uint64_t
kperf_lazy_get_wait_time_threshold(void)
{
	return kperf_lazy_wait_time_threshold;
}

int
kperf_lazy_set_wait_time_threshold(uint64_t threshold)
{
	kperf_lazy_wait_time_threshold = threshold;
	return 0;
}

int kperf_lazy_get_cpu_action(void) { return kperf_lazy_cpu_action; }

int
kperf_lazy_set_cpu_action(int action_id)
{
	if (action_id < 0 || (unsigned int)action_id > kperf_action_get_count()) {
		return 1;
	}

	kperf_lazy_cpu_action = action_id;
	return 0;
}

uint64_t
kperf_lazy_get_cpu_time_threshold(void)
{
	return kperf_lazy_cpu_time_threshold;
}

int
kperf_lazy_set_cpu_time_threshold(uint64_t threshold)
{
	kperf_lazy_cpu_time_threshold = threshold;
	return 0;
}

