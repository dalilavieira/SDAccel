#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u64 ;
struct pt_regs {int flags; unsigned long ip; int /*<<< orphan*/  cs; } ;
struct TYPE_4__ {unsigned long config; scalar_t__ reg; } ;
struct hw_perf_event {unsigned long config; scalar_t__ config_base; TYPE_1__ extra_reg; } ;
struct perf_event {struct hw_perf_event hw; } ;
struct cpu_hw_events {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  perf_ctr_virt_mask; } ;
struct TYPE_5__ {scalar_t__* lbr_sel_map; unsigned int eventsel; int (* addr_offset ) (int,int) ;unsigned int perfctr; int (* rdpmc_index ) (int) ;} ;

/* Variables and functions */
 unsigned long ARCH_PERFMON_EVENTSEL_ENABLE ; 
 scalar_t__ MSR_P6_EVNTSEL0 ; 
 unsigned long P6_NOP_EVENT ; 
 int PERF_EFLAGS_VM ; 
 size_t PERF_SAMPLE_BRANCH_CALL_STACK_SHIFT ; 
 int X86_VM_MASK ; 
 int /*<<< orphan*/  __KERNEL_CS ; 
 int /*<<< orphan*/  __USER_CS ; 
 unsigned long __this_cpu_read (int /*<<< orphan*/ ) ; 
 TYPE_3__ cpu_hw_events ; 
 unsigned long* p6_perfmon_event_map ; 
 int /*<<< orphan*/  rdmsrl (scalar_t__,unsigned long) ; 
 int stub1 (int,int) ; 
 int stub2 (int,int) ; 
 int stub3 (int) ; 
 int /*<<< orphan*/  wrmsrl (scalar_t__,unsigned long) ; 
 int /*<<< orphan*/  wrmsrl_safe (scalar_t__,unsigned long) ; 
 TYPE_2__ x86_pmu ; 

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

__attribute__((used)) static u64 p6_pmu_event_map(int hw_event)
{
	return p6_perfmon_event_map[hw_event];
}

__attribute__((used)) static void p6_pmu_disable_all(void)
{
	u64 val;

	/* p6 only has one enable register */
	rdmsrl(MSR_P6_EVNTSEL0, val);
	val &= ~ARCH_PERFMON_EVENTSEL_ENABLE;
	wrmsrl(MSR_P6_EVNTSEL0, val);
}

__attribute__((used)) static void p6_pmu_enable_all(int added)
{
	unsigned long val;

	/* p6 only has one enable register */
	rdmsrl(MSR_P6_EVNTSEL0, val);
	val |= ARCH_PERFMON_EVENTSEL_ENABLE;
	wrmsrl(MSR_P6_EVNTSEL0, val);
}

__attribute__((used)) static inline void
p6_pmu_disable_event(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;
	u64 val = P6_NOP_EVENT;

	(void)wrmsrl_safe(hwc->config_base, val);
}

__attribute__((used)) static void p6_pmu_enable_event(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;
	u64 val;

	val = hwc->config;

	/*
	 * p6 only has a global event enable, set on PerfEvtSel0
	 * We "disable" events by programming P6_NOP_EVENT
	 * and we rely on p6_pmu_enable_all() being called
	 * to actually enable the events.
	 */

	(void)wrmsrl_safe(hwc->config_base, val);
}

