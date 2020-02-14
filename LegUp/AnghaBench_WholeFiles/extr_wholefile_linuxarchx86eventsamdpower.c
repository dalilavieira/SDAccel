#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
struct pt_regs {int flags; unsigned long ip; int /*<<< orphan*/  cs; } ;
struct TYPE_8__ {scalar_t__ config; scalar_t__ type; scalar_t__ sample_period; scalar_t__ exclude_guest; scalar_t__ exclude_host; scalar_t__ exclude_idle; scalar_t__ exclude_hv; scalar_t__ exclude_kernel; scalar_t__ exclude_user; } ;
struct TYPE_7__ {scalar_t__ config; scalar_t__ reg; } ;
struct hw_perf_event {scalar_t__ config; scalar_t__ pwr_acc; scalar_t__ ptsc; int state; scalar_t__ config_base; TYPE_1__ extra_reg; } ;
struct perf_event {TYPE_2__ attr; struct hw_perf_event hw; int /*<<< orphan*/  count; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct cpu_hw_events {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_11__ {int /*<<< orphan*/  perf_ctr_virt_mask; } ;
struct TYPE_10__ {scalar_t__ type; } ;
struct TYPE_9__ {scalar_t__* lbr_sel_map; unsigned int eventsel; int (* addr_offset ) (int,int) ;unsigned int perfctr; int (* rdpmc_index ) (int) ;} ;

/* Variables and functions */
 scalar_t__ AMD_POWER_EVENTSEL_PKG ; 
 scalar_t__ AMD_POWER_EVENT_MASK ; 
 int EINVAL ; 
 int ENOENT ; 
 int /*<<< orphan*/  MSR_F15H_CU_PWR_ACCUMULATOR ; 
 int /*<<< orphan*/  MSR_F15H_PTSC ; 
 int PERF_EFLAGS_VM ; 
 int PERF_EF_START ; 
 int PERF_EF_UPDATE ; 
 int PERF_HES_STOPPED ; 
 int PERF_HES_UPTODATE ; 
 size_t PERF_SAMPLE_BRANCH_CALL_STACK_SHIFT ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int X86_VM_MASK ; 
 int /*<<< orphan*/  __KERNEL_CS ; 
 int /*<<< orphan*/  __USER_CS ; 
 scalar_t__ __this_cpu_read (int /*<<< orphan*/ ) ; 
 TYPE_6__ cpu_hw_events ; 
 int /*<<< orphan*/  cpu_mask ; 
 int cpu_pwr_sample_ratio ; 
 int /*<<< orphan*/  cpumap_print_to_pagebuf (int,char*,int /*<<< orphan*/ *) ; 
 int cpumask_any_but (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  cpumask_set_cpu (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpumask_test_and_clear_cpu (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  do_div (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  local64_add (scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ max_cu_acc_power ; 
 int nr_cpumask_bits ; 
 int /*<<< orphan*/  perf_pmu_migrate_context (TYPE_4__*,unsigned int,int) ; 
 TYPE_4__ pmu_class ; 
 int /*<<< orphan*/  rdmsrl (int /*<<< orphan*/ ,scalar_t__) ; 
 int stub1 (int,int) ; 
 int stub2 (int,int) ; 
 int stub3 (int) ; 
 int /*<<< orphan*/  topology_sibling_cpumask (unsigned int) ; 
 int /*<<< orphan*/  wrmsrl (scalar_t__,scalar_t__) ; 
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

__attribute__((used)) static void event_update(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;
	u64 prev_pwr_acc, new_pwr_acc, prev_ptsc, new_ptsc;
	u64 delta, tdelta;

	prev_pwr_acc = hwc->pwr_acc;
	prev_ptsc = hwc->ptsc;
	rdmsrl(MSR_F15H_CU_PWR_ACCUMULATOR, new_pwr_acc);
	rdmsrl(MSR_F15H_PTSC, new_ptsc);

	/*
	 * Calculate the CU power consumption over a time period, the unit of
	 * final value (delta) is micro-Watts. Then add it to the event count.
	 */
	if (new_pwr_acc < prev_pwr_acc) {
		delta = max_cu_acc_power + new_pwr_acc;
		delta -= prev_pwr_acc;
	} else
		delta = new_pwr_acc - prev_pwr_acc;

	delta *= cpu_pwr_sample_ratio * 1000;
	tdelta = new_ptsc - prev_ptsc;

	do_div(delta, tdelta);
	local64_add(delta, &event->count);
}

__attribute__((used)) static void __pmu_event_start(struct perf_event *event)
{
	if (WARN_ON_ONCE(!(event->hw.state & PERF_HES_STOPPED)))
		return;

	event->hw.state = 0;

	rdmsrl(MSR_F15H_PTSC, event->hw.ptsc);
	rdmsrl(MSR_F15H_CU_PWR_ACCUMULATOR, event->hw.pwr_acc);
}

__attribute__((used)) static void pmu_event_start(struct perf_event *event, int mode)
{
	__pmu_event_start(event);
}

__attribute__((used)) static void pmu_event_stop(struct perf_event *event, int mode)
{
	struct hw_perf_event *hwc = &event->hw;

	/* Mark event as deactivated and stopped. */
	if (!(hwc->state & PERF_HES_STOPPED))
		hwc->state |= PERF_HES_STOPPED;

	/* Check if software counter update is necessary. */
	if ((mode & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
		/*
		 * Drain the remaining delta count out of an event
		 * that we are disabling:
		 */
		event_update(event);
		hwc->state |= PERF_HES_UPTODATE;
	}
}

__attribute__((used)) static int pmu_event_add(struct perf_event *event, int mode)
{
	struct hw_perf_event *hwc = &event->hw;

	hwc->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;

	if (mode & PERF_EF_START)
		__pmu_event_start(event);

	return 0;
}

__attribute__((used)) static void pmu_event_del(struct perf_event *event, int flags)
{
	pmu_event_stop(event, PERF_EF_UPDATE);
}

__attribute__((used)) static int pmu_event_init(struct perf_event *event)
{
	u64 cfg = event->attr.config & AMD_POWER_EVENT_MASK;

	/* Only look at AMD power events. */
	if (event->attr.type != pmu_class.type)
		return -ENOENT;

	/* Unsupported modes and filters. */
	if (event->attr.exclude_user   ||
	    event->attr.exclude_kernel ||
	    event->attr.exclude_hv     ||
	    event->attr.exclude_idle   ||
	    event->attr.exclude_host   ||
	    event->attr.exclude_guest  ||
	    /* no sampling */
	    event->attr.sample_period)
		return -EINVAL;

	if (cfg != AMD_POWER_EVENTSEL_PKG)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static void pmu_event_read(struct perf_event *event)
{
	event_update(event);
}

__attribute__((used)) static ssize_t
get_attr_cpumask(struct device *dev, struct device_attribute *attr, char *buf)
{
	return cpumap_print_to_pagebuf(true, buf, &cpu_mask);
}

__attribute__((used)) static int power_cpu_exit(unsigned int cpu)
{
	int target;

	if (!cpumask_test_and_clear_cpu(cpu, &cpu_mask))
		return 0;

	/*
	 * Find a new CPU on the same compute unit, if was set in cpumask
	 * and still some CPUs on compute unit. Then migrate event and
	 * context to new CPU.
	 */
	target = cpumask_any_but(topology_sibling_cpumask(cpu), cpu);
	if (target < nr_cpumask_bits) {
		cpumask_set_cpu(target, &cpu_mask);
		perf_pmu_migrate_context(&pmu_class, cpu, target);
	}
	return 0;
}

__attribute__((used)) static int power_cpu_init(unsigned int cpu)
{
	int target;

	/*
	 * 1) If any CPU is set at cpu_mask in the same compute unit, do
	 * nothing.
	 * 2) If no CPU is set at cpu_mask in the same compute unit,
	 * set current ONLINE CPU.
	 *
	 * Note: if there is a CPU aside of the new one already in the
	 * sibling mask, then it is also in cpu_mask.
	 */
	target = cpumask_any_but(topology_sibling_cpumask(cpu), cpu);
	if (target >= nr_cpumask_bits)
		cpumask_set_cpu(cpu, &cpu_mask);
	return 0;
}

