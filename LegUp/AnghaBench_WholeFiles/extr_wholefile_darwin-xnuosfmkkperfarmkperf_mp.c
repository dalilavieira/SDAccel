#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
struct kperf_timer {int /*<<< orphan*/  pending_cpus; } ;
typedef  TYPE_1__* processor_t ;
struct TYPE_6__ {int logical_cpu_max; } ;
struct TYPE_5__ {scalar_t__ state; scalar_t__ active_thread; } ;

/* Variables and functions */
 TYPE_1__* PROCESSOR_NULL ; 
 scalar_t__ PROCESSOR_RUNNING ; 
 int /*<<< orphan*/  SIGPkptimer ; 
 scalar_t__ THREAD_NULL ; 
 int UINT64_C (int) ; 
 int atomic_fetch_and_explicit (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int atomic_fetch_or_explicit (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_datap (int) ; 
 int cpu_number () ; 
 int /*<<< orphan*/  cpu_signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_1__* cpu_to_processor (int) ; 
 int /*<<< orphan*/  kperf_ipi_handler (struct kperf_timer*) ; 
 scalar_t__ kperf_timerc ; 
 struct kperf_timer* kperf_timerv ; 
 TYPE_2__ machine_info ; 
 int /*<<< orphan*/  memory_order_relaxed ; 

void
kperf_signal_handler(unsigned int cpu_number)
{
	uint64_t cpu_mask = UINT64_C(1) << cpu_number;

	/* find all the timers that caused a signal */
	for(int i = 0; i < (int)kperf_timerc; i++) {
		uint64_t pending_cpus;
		struct kperf_timer *timer = &kperf_timerv[i];

		pending_cpus = atomic_fetch_and_explicit(&timer->pending_cpus,
				~cpu_mask, memory_order_relaxed);
		if (pending_cpus & cpu_mask) {
			kperf_ipi_handler(timer);
		}
	}
}

bool
kperf_mp_broadcast_other_running(struct kperf_timer *timer)
{
	int current_cpu = cpu_number();
	bool system_only_self = true;
	int n_cpus = machine_info.logical_cpu_max;

	/* signal all running processors */
	for (int i = 0; i < n_cpus; i++) {
		uint64_t i_bit = UINT64_C(1) << i;
		processor_t processor = cpu_to_processor(i);

		/* do not IPI processors that are not scheduling threads */
		if (processor == PROCESSOR_NULL ||
				processor->state != PROCESSOR_RUNNING ||
				processor->active_thread == THREAD_NULL)
		{
			continue;
		}

		if (i == current_cpu) {
			system_only_self = false;
			continue;
		}

		/* nor processors that have not responded to the last broadcast */
		uint64_t already_pending = atomic_fetch_or_explicit(
				&timer->pending_cpus, i_bit, memory_order_relaxed);
		if (already_pending & i_bit)
		{
#if DEVELOPMENT || DEBUG
			atomic_fetch_add_explicit(&kperf_pending_ipis, 1,
					memory_order_relaxed);
#endif /* DEVELOPMENT || DEBUG */
			continue;
		}

		cpu_signal(cpu_datap(i), SIGPkptimer, NULL, NULL);
	}

	return system_only_self;
}

