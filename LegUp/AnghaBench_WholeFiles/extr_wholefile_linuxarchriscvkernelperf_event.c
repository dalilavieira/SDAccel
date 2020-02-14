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
typedef  size_t u64 ;
struct perf_event_attr {int type; int /*<<< orphan*/  config; } ;
struct hw_perf_event {int idx; int state; int config; int /*<<< orphan*/  prev_count; } ;
struct perf_event {void (* destroy ) (struct perf_event*) ;struct perf_event_attr attr; struct hw_perf_event hw; int /*<<< orphan*/  count; } ;
struct cpu_hw_events {scalar_t__ n_events; struct perf_event** events; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_4__ {size_t max_events; int* hw_events; int**** cache_events; unsigned long long counter_width; scalar_t__ num_counters; scalar_t__ irq; int (* map_hw_event ) (int /*<<< orphan*/ ) ;int (* map_cache_event ) (int /*<<< orphan*/ ) ;scalar_t__ handle_irq; TYPE_1__* pmu; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* stop ) (struct perf_event*,int) ;int /*<<< orphan*/  (* start ) (struct perf_event*,int) ;int /*<<< orphan*/  (* read ) (struct perf_event*) ;} ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOSPC ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  IRQF_PERCPU ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 unsigned int PERF_COUNT_HW_CACHE_MAX ; 
 unsigned int PERF_COUNT_HW_CACHE_OP_MAX ; 
 unsigned int PERF_COUNT_HW_CACHE_RESULT_MAX ; 
 int PERF_EF_RELOAD ; 
 int PERF_EF_START ; 
 int PERF_EF_UPDATE ; 
 int PERF_HES_STOPPED ; 
 int PERF_HES_UPTODATE ; 
#define  PERF_TYPE_HARDWARE 132 
#define  PERF_TYPE_HW_CACHE 131 
#define  PERF_TYPE_RAW 130 
 int RISCV_MAX_COUNTERS ; 
 int RISCV_OP_UNSUPP ; 
#define  RISCV_PMU_CYCLE 129 
#define  RISCV_PMU_INSTRET 128 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_dec_return (int /*<<< orphan*/ *) ; 
 int atomic_inc_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_hw_events ; 
 size_t csr_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cycle ; 
 int /*<<< orphan*/  free_irq (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  instret ; 
 int /*<<< orphan*/  local64_add (size_t,int /*<<< orphan*/ *) ; 
 size_t local64_cmpxchg (int /*<<< orphan*/ *,size_t,size_t) ; 
 size_t local64_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  local64_set (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  perf_event_update_userpage (struct perf_event*) ; 
 int /*<<< orphan*/  pmc_reserve_mutex ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int request_irq (scalar_t__,scalar_t__,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  riscv_active_events ; 
 TYPE_2__* riscv_pmu ; 
 int /*<<< orphan*/  stub1 (struct perf_event*) ; 
 int /*<<< orphan*/  stub2 (struct perf_event*,int) ; 
 int /*<<< orphan*/  stub3 (struct perf_event*,int) ; 
 int stub4 (int /*<<< orphan*/ ) ; 
 int stub5 (int /*<<< orphan*/ ) ; 
 void stub6 (struct perf_event*) ; 
 struct cpu_hw_events* this_cpu_ptr (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int riscv_map_hw_event(u64 config)
{
	if (config >= riscv_pmu->max_events)
		return -EINVAL;

	return riscv_pmu->hw_events[config];
}

int riscv_map_cache_decode(u64 config, unsigned int *type,
			   unsigned int *op, unsigned int *result)
{
	return -ENOENT;
}

__attribute__((used)) static int riscv_map_cache_event(u64 config)
{
	unsigned int type, op, result;
	int err = -ENOENT;
		int code;

	err = riscv_map_cache_decode(config, &type, &op, &result);
	if (!riscv_pmu->cache_events || err)
		return err;

	if (type >= PERF_COUNT_HW_CACHE_MAX ||
	    op >= PERF_COUNT_HW_CACHE_OP_MAX ||
	    result >= PERF_COUNT_HW_CACHE_RESULT_MAX)
		return -EINVAL;

	code = (*riscv_pmu->cache_events)[type][op][result];
	if (code == RISCV_OP_UNSUPP)
		return -EINVAL;

	return code;
}

__attribute__((used)) static inline u64 read_counter(int idx)
{
	u64 val = 0;

	switch (idx) {
	case RISCV_PMU_CYCLE:
		val = csr_read(cycle);
		break;
	case RISCV_PMU_INSTRET:
		val = csr_read(instret);
		break;
	default:
		WARN_ON_ONCE(idx < 0 ||	idx > RISCV_MAX_COUNTERS);
		return -EINVAL;
	}

	return val;
}

__attribute__((used)) static inline void write_counter(int idx, u64 value)
{
	/* currently not supported */
	WARN_ON_ONCE(1);
}

__attribute__((used)) static void riscv_pmu_read(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;
	u64 prev_raw_count, new_raw_count;
	u64 oldval;
	int idx = hwc->idx;
	u64 delta;

	do {
		prev_raw_count = local64_read(&hwc->prev_count);
		new_raw_count = read_counter(idx);

		oldval = local64_cmpxchg(&hwc->prev_count, prev_raw_count,
					 new_raw_count);
	} while (oldval != prev_raw_count);

	/*
	 * delta is the value to update the counter we maintain in the kernel.
	 */
	delta = (new_raw_count - prev_raw_count) &
		((1ULL << riscv_pmu->counter_width) - 1);
	local64_add(delta, &event->count);
	/*
	 * Something like local64_sub(delta, &hwc->period_left) here is
	 * needed if there is an interrupt for perf.
	 */
}

__attribute__((used)) static void riscv_pmu_stop(struct perf_event *event, int flags)
{
	struct hw_perf_event *hwc = &event->hw;

	WARN_ON_ONCE(hwc->state & PERF_HES_STOPPED);
	hwc->state |= PERF_HES_STOPPED;

	if ((flags & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
		riscv_pmu->pmu->read(event);
		hwc->state |= PERF_HES_UPTODATE;
	}
}

__attribute__((used)) static void riscv_pmu_start(struct perf_event *event, int flags)
{
	struct hw_perf_event *hwc = &event->hw;

	if (WARN_ON_ONCE(!(event->hw.state & PERF_HES_STOPPED)))
		return;

	if (flags & PERF_EF_RELOAD) {
		WARN_ON_ONCE(!(event->hw.state & PERF_HES_UPTODATE));

		/*
		 * Set the counter to the period to the next interrupt here,
		 * if you have any.
		 */
	}

	hwc->state = 0;
	perf_event_update_userpage(event);

	/*
	 * Since we cannot write to counters, this serves as an initialization
	 * to the delta-mechanism in pmu->read(); otherwise, the delta would be
	 * wrong when pmu->read is called for the first time.
	 */
	local64_set(&hwc->prev_count, read_counter(hwc->idx));
}

__attribute__((used)) static int riscv_pmu_add(struct perf_event *event, int flags)
{
	struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
	struct hw_perf_event *hwc = &event->hw;

	if (cpuc->n_events == riscv_pmu->num_counters)
		return -ENOSPC;

	/*
	 * We don't have general conunters, so no binding-event-to-counter
	 * process here.
	 *
	 * Indexing using hwc->config generally not works, since config may
	 * contain extra information, but here the only info we have in
	 * hwc->config is the event index.
	 */
	hwc->idx = hwc->config;
	cpuc->events[hwc->idx] = event;
	cpuc->n_events++;

	hwc->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;

	if (flags & PERF_EF_START)
		riscv_pmu->pmu->start(event, PERF_EF_RELOAD);

	return 0;
}

__attribute__((used)) static void riscv_pmu_del(struct perf_event *event, int flags)
{
	struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
	struct hw_perf_event *hwc = &event->hw;

	cpuc->events[hwc->idx] = NULL;
	cpuc->n_events--;
	riscv_pmu->pmu->stop(event, PERF_EF_UPDATE);
	perf_event_update_userpage(event);
}

irqreturn_t riscv_base_pmu_handle_irq(int irq_num, void *dev)
{
	return IRQ_NONE;
}

__attribute__((used)) static int reserve_pmc_hardware(void)
{
	int err = 0;

	mutex_lock(&pmc_reserve_mutex);
	if (riscv_pmu->irq >= 0 && riscv_pmu->handle_irq) {
		err = request_irq(riscv_pmu->irq, riscv_pmu->handle_irq,
				  IRQF_PERCPU, "riscv-base-perf", NULL);
	}
	mutex_unlock(&pmc_reserve_mutex);

	return err;
}

void release_pmc_hardware(void)
{
	mutex_lock(&pmc_reserve_mutex);
	if (riscv_pmu->irq >= 0)
		free_irq(riscv_pmu->irq, NULL);
	mutex_unlock(&pmc_reserve_mutex);
}

__attribute__((used)) static void riscv_event_destroy(struct perf_event *event)
{
	if (atomic_dec_return(&riscv_active_events) == 0)
		release_pmc_hardware();
}

__attribute__((used)) static int riscv_event_init(struct perf_event *event)
{
	struct perf_event_attr *attr = &event->attr;
	struct hw_perf_event *hwc = &event->hw;
	int err;
	int code;

	if (atomic_inc_return(&riscv_active_events) == 1) {
		err = reserve_pmc_hardware();

		if (err) {
			pr_warn("PMC hardware not available\n");
			atomic_dec(&riscv_active_events);
			return -EBUSY;
		}
	}

	switch (event->attr.type) {
	case PERF_TYPE_HARDWARE:
		code = riscv_pmu->map_hw_event(attr->config);
		break;
	case PERF_TYPE_HW_CACHE:
		code = riscv_pmu->map_cache_event(attr->config);
		break;
	case PERF_TYPE_RAW:
		return -EOPNOTSUPP;
	default:
		return -ENOENT;
	}

	event->destroy = riscv_event_destroy;
	if (code < 0) {
		event->destroy(event);
		return code;
	}

	/*
	 * idx is set to -1 because the index of a general event should not be
	 * decided until binding to some counter in pmu->add().
	 *
	 * But since we don't have such support, later in pmu->add(), we just
	 * use hwc->config as the index instead.
	 */
	hwc->config = code;
	hwc->idx = -1;

	return 0;
}

