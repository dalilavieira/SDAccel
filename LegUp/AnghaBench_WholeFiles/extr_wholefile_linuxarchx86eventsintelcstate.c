#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u64 ;
struct pt_regs {int flags; unsigned long ip; int /*<<< orphan*/  cs; } ;
struct pmu {scalar_t__ type; } ;
struct TYPE_7__ {size_t config; scalar_t__ reg; } ;
struct hw_perf_event {size_t config; int idx; int /*<<< orphan*/  prev_count; int /*<<< orphan*/  event_base; scalar_t__ config_base; TYPE_1__ extra_reg; } ;
struct TYPE_8__ {size_t config; scalar_t__ type; scalar_t__ sample_period; scalar_t__ exclude_guest; scalar_t__ exclude_host; scalar_t__ exclude_idle; scalar_t__ exclude_hv; scalar_t__ exclude_kernel; scalar_t__ exclude_user; } ;
struct perf_event {unsigned int cpu; struct hw_perf_event hw; int /*<<< orphan*/  count; struct pmu* pmu; TYPE_2__ attr; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct cpu_hw_events {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_12__ {int /*<<< orphan*/  msr; int /*<<< orphan*/  attr; } ;
struct TYPE_11__ {int /*<<< orphan*/  perf_ctr_virt_mask; } ;
struct TYPE_10__ {int /*<<< orphan*/  msr; int /*<<< orphan*/  attr; } ;
struct TYPE_9__ {scalar_t__* lbr_sel_map; unsigned int eventsel; int (* addr_offset ) (int,int) ;unsigned int perfctr; int (* rdpmc_index ) (int) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 size_t PERF_CSTATE_CORE_EVENT_MAX ; 
 size_t PERF_CSTATE_PKG_EVENT_MAX ; 
 int PERF_EFLAGS_VM ; 
 int PERF_EF_START ; 
 int PERF_EF_UPDATE ; 
 size_t PERF_SAMPLE_BRANCH_CALL_STACK_SHIFT ; 
 int X86_VM_MASK ; 
 int /*<<< orphan*/  __KERNEL_CS ; 
 int /*<<< orphan*/  __USER_CS ; 
 size_t __this_cpu_read (int /*<<< orphan*/ ) ; 
 size_t array_index_nospec (unsigned long,size_t) ; 
 TYPE_6__* core_msr ; 
 TYPE_5__ cpu_hw_events ; 
 int /*<<< orphan*/  cpumap_print_to_pagebuf (int,char*,int /*<<< orphan*/ *) ; 
 void* cpumask_any_and (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 unsigned int cpumask_any_but (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  cpumask_set_cpu (unsigned int,int /*<<< orphan*/ *) ; 
 scalar_t__ cpumask_test_and_clear_cpu (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cstate_core_cpu_mask ; 
 struct pmu cstate_core_pmu ; 
 int /*<<< orphan*/  cstate_pkg_cpu_mask ; 
 struct pmu cstate_pkg_pmu ; 
 struct pmu* dev_get_drvdata (struct device*) ; 
 scalar_t__ has_cstate_core ; 
 scalar_t__ has_cstate_pkg ; 
 int /*<<< orphan*/  local64_add (size_t,int /*<<< orphan*/ *) ; 
 size_t local64_cmpxchg (int /*<<< orphan*/ *,size_t,size_t) ; 
 size_t local64_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  local64_set (int /*<<< orphan*/ *,size_t) ; 
 int nr_cpu_ids ; 
 int /*<<< orphan*/  perf_pmu_migrate_context (struct pmu*,unsigned int,unsigned int) ; 
 TYPE_4__* pkg_msr ; 
 int /*<<< orphan*/  rdmsrl (int /*<<< orphan*/ ,size_t) ; 
 int stub1 (int,int) ; 
 int stub2 (int,int) ; 
 int stub3 (int) ; 
 int /*<<< orphan*/  topology_core_cpumask (unsigned int) ; 
 int /*<<< orphan*/  topology_sibling_cpumask (unsigned int) ; 
 int /*<<< orphan*/  wrmsrl (scalar_t__,size_t) ; 
 TYPE_3__ x86_pmu ; 

__attribute__((used)) static inline bool x86_pmu_has_lbr_callstack(void)
{
	return  x86_pmu.lbr_sel_map &&
		x86_pmu.lbr_sel_map[PERF_SAMPLE_BRANCH_CALL_STACK_SHIFT] > 0;
}

__attribute__((used)) static inline unsigned int x86_pmu_config_addr(int index)
{
	return x86_pmu.eventsel + (x86_pmu.addr_offset ?
				   x86_pmu.addr_offset(index, true) : index);
}

__attribute__((used)) static inline unsigned int x86_pmu_event_addr(int index)
{
	return x86_pmu.perfctr + (x86_pmu.addr_offset ?
				  x86_pmu.addr_offset(index, false) : index);
}

__attribute__((used)) static inline int x86_pmu_rdpmc_index(int index)
{
	return x86_pmu.rdpmc_index ? x86_pmu.rdpmc_index(index) : index;
}

__attribute__((used)) static inline void __x86_pmu_enable_event(struct hw_perf_event *hwc,
					  u64 enable_mask)
{
	u64 disable_mask = __this_cpu_read(cpu_hw_events.perf_ctr_virt_mask);

	if (hwc->extra_reg.reg)
		wrmsrl(hwc->extra_reg.reg, hwc->extra_reg.config);
	wrmsrl(hwc->config_base, (hwc->config | enable_mask) & ~disable_mask);
}

__attribute__((used)) static inline void x86_pmu_disable_event(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;

	wrmsrl(hwc->config_base, hwc->config);
}

__attribute__((used)) static inline bool kernel_ip(unsigned long ip)
{
#ifdef CONFIG_X86_32
	return ip > PAGE_OFFSET;
#else
	return (long)ip < 0;
#endif
}

__attribute__((used)) static inline void set_linear_ip(struct pt_regs *regs, unsigned long ip)
{
	regs->cs = kernel_ip(ip) ? __KERNEL_CS : __USER_CS;
	if (regs->flags & X86_VM_MASK)
		regs->flags ^= (PERF_EFLAGS_VM | X86_VM_MASK);
	regs->ip = ip;
}

__attribute__((used)) static inline int amd_pmu_init(void)
{
	return 0;
}

__attribute__((used)) static inline void reserve_ds_buffers(void)
{
}

__attribute__((used)) static inline void release_ds_buffers(void)
{
}

__attribute__((used)) static inline int intel_pmu_init(void)
{
	return 0;
}

__attribute__((used)) static inline int intel_cpuc_prepare(struct cpu_hw_events *cpuc, int cpu)
{
	return 0;
}

__attribute__((used)) static inline void intel_cpuc_finish(struct cpu_hw_events *cpuc)
{
}

__attribute__((used)) static inline int is_ht_workaround_enabled(void)
{
	return 0;
}

__attribute__((used)) static ssize_t cstate_get_attr_cpumask(struct device *dev,
				       struct device_attribute *attr,
				       char *buf)
{
	struct pmu *pmu = dev_get_drvdata(dev);

	if (pmu == &cstate_core_pmu)
		return cpumap_print_to_pagebuf(true, buf, &cstate_core_cpu_mask);
	else if (pmu == &cstate_pkg_pmu)
		return cpumap_print_to_pagebuf(true, buf, &cstate_pkg_cpu_mask);
	else
		return 0;
}

__attribute__((used)) static int cstate_pmu_event_init(struct perf_event *event)
{
	u64 cfg = event->attr.config;
	int cpu;

	if (event->attr.type != event->pmu->type)
		return -ENOENT;

	/* unsupported modes and filters */
	if (event->attr.exclude_user   ||
	    event->attr.exclude_kernel ||
	    event->attr.exclude_hv     ||
	    event->attr.exclude_idle   ||
	    event->attr.exclude_host   ||
	    event->attr.exclude_guest  ||
	    event->attr.sample_period) /* no sampling */
		return -EINVAL;

	if (event->cpu < 0)
		return -EINVAL;

	if (event->pmu == &cstate_core_pmu) {
		if (cfg >= PERF_CSTATE_CORE_EVENT_MAX)
			return -EINVAL;
		if (!core_msr[cfg].attr)
			return -EINVAL;
		event->hw.event_base = core_msr[cfg].msr;
		cpu = cpumask_any_and(&cstate_core_cpu_mask,
				      topology_sibling_cpumask(event->cpu));
	} else if (event->pmu == &cstate_pkg_pmu) {
		if (cfg >= PERF_CSTATE_PKG_EVENT_MAX)
			return -EINVAL;
		cfg = array_index_nospec((unsigned long)cfg, PERF_CSTATE_PKG_EVENT_MAX);
		if (!pkg_msr[cfg].attr)
			return -EINVAL;
		event->hw.event_base = pkg_msr[cfg].msr;
		cpu = cpumask_any_and(&cstate_pkg_cpu_mask,
				      topology_core_cpumask(event->cpu));
	} else {
		return -ENOENT;
	}

	if (cpu >= nr_cpu_ids)
		return -ENODEV;

	event->cpu = cpu;
	event->hw.config = cfg;
	event->hw.idx = -1;
	return 0;
}

__attribute__((used)) static inline u64 cstate_pmu_read_counter(struct perf_event *event)
{
	u64 val;

	rdmsrl(event->hw.event_base, val);
	return val;
}

__attribute__((used)) static void cstate_pmu_event_update(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;
	u64 prev_raw_count, new_raw_count;

again:
	prev_raw_count = local64_read(&hwc->prev_count);
	new_raw_count = cstate_pmu_read_counter(event);

	if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
			    new_raw_count) != prev_raw_count)
		goto again;

	local64_add(new_raw_count - prev_raw_count, &event->count);
}

__attribute__((used)) static void cstate_pmu_event_start(struct perf_event *event, int mode)
{
	local64_set(&event->hw.prev_count, cstate_pmu_read_counter(event));
}

__attribute__((used)) static void cstate_pmu_event_stop(struct perf_event *event, int mode)
{
	cstate_pmu_event_update(event);
}

__attribute__((used)) static void cstate_pmu_event_del(struct perf_event *event, int mode)
{
	cstate_pmu_event_stop(event, PERF_EF_UPDATE);
}

__attribute__((used)) static int cstate_pmu_event_add(struct perf_event *event, int mode)
{
	if (mode & PERF_EF_START)
		cstate_pmu_event_start(event, mode);

	return 0;
}

__attribute__((used)) static int cstate_cpu_exit(unsigned int cpu)
{
	unsigned int target;

	if (has_cstate_core &&
	    cpumask_test_and_clear_cpu(cpu, &cstate_core_cpu_mask)) {

		target = cpumask_any_but(topology_sibling_cpumask(cpu), cpu);
		/* Migrate events if there is a valid target */
		if (target < nr_cpu_ids) {
			cpumask_set_cpu(target, &cstate_core_cpu_mask);
			perf_pmu_migrate_context(&cstate_core_pmu, cpu, target);
		}
	}

	if (has_cstate_pkg &&
	    cpumask_test_and_clear_cpu(cpu, &cstate_pkg_cpu_mask)) {

		target = cpumask_any_but(topology_core_cpumask(cpu), cpu);
		/* Migrate events if there is a valid target */
		if (target < nr_cpu_ids) {
			cpumask_set_cpu(target, &cstate_pkg_cpu_mask);
			perf_pmu_migrate_context(&cstate_pkg_pmu, cpu, target);
		}
	}
	return 0;
}

__attribute__((used)) static int cstate_cpu_init(unsigned int cpu)
{
	unsigned int target;

	/*
	 * If this is the first online thread of that core, set it in
	 * the core cpu mask as the designated reader.
	 */
	target = cpumask_any_and(&cstate_core_cpu_mask,
				 topology_sibling_cpumask(cpu));

	if (has_cstate_core && target >= nr_cpu_ids)
		cpumask_set_cpu(cpu, &cstate_core_cpu_mask);

	/*
	 * If this is the first online thread of that package, set it
	 * in the package cpu mask as the designated reader.
	 */
	target = cpumask_any_and(&cstate_pkg_cpu_mask,
				 topology_core_cpumask(cpu));
	if (has_cstate_pkg && target >= nr_cpu_ids)
		cpumask_set_cpu(cpu, &cstate_pkg_cpu_mask);

	return 0;
}

