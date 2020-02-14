#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct pt_regs {int flags; unsigned long ip; int /*<<< orphan*/  cs; } ;
struct perf_sample_data {int dummy; } ;
struct TYPE_8__ {int reg; int config; } ;
struct hw_perf_event {int config_base; int config; int event_base; int idx; int /*<<< orphan*/  last_period; TYPE_1__ extra_reg; } ;
struct TYPE_9__ {int config; scalar_t__ type; int /*<<< orphan*/  exclude_user; int /*<<< orphan*/  exclude_kernel; } ;
struct perf_event {struct hw_perf_event hw; TYPE_2__ attr; } ;
struct p4_pebs_bind {int original; int alternative; unsigned int escr_emask; int* escr_msr; int** cntr; int /*<<< orphan*/  opcode; scalar_t__ metric_vert; scalar_t__ metric_pebs; scalar_t__ shared; } ;
struct p4_event_bind {int original; int alternative; unsigned int escr_emask; int* escr_msr; int** cntr; int /*<<< orphan*/  opcode; scalar_t__ metric_vert; scalar_t__ metric_pebs; scalar_t__ shared; } ;
struct cpu_hw_events {unsigned long* active_mask; TYPE_3__** event_list; struct perf_event** events; int /*<<< orphan*/  running; } ;
struct TYPE_13__ {int x86_model; } ;
struct TYPE_12__ {int /*<<< orphan*/  perf_ctr_virt_mask; } ;
struct TYPE_11__ {scalar_t__* lbr_sel_map; unsigned int eventsel; int (* addr_offset ) (int,int) ;unsigned int perfctr; int (* rdpmc_index ) (int) ;int num_counters; int cntval_bits; } ;
struct TYPE_10__ {struct hw_perf_event hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  APIC_DM_NMI ; 
 int /*<<< orphan*/  APIC_LVTPC ; 
 int ARCH_P4_UNFLAGGED_BIT ; 
 unsigned int ARRAY_SIZE (struct p4_pebs_bind*) ; 
 int BITS_TO_LONGS (unsigned int) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int EACCES ; 
 int EINVAL ; 
 int MSR_IA32_PEBS_ENABLE ; 
 int MSR_P4_PEBS_MATRIX_VERT ; 
 int P4_CCCR_ENABLE ; 
 int P4_CCCR_ESEL (unsigned int) ; 
 int P4_CCCR_OVF ; 
 int P4_CCCR_OVF_PMI_T0 ; 
 int P4_CCCR_OVF_PMI_T1 ; 
 int P4_CCCR_RESERVED ; 
 int P4_CNTR_LIMIT ; 
 int P4_CONFIG_ALIASABLE ; 
 int P4_CONFIG_EVENT_ALIAS_IMMUTABLE_BITS ; 
 int P4_CONFIG_EVENT_ALIAS_MASK ; 
 int P4_CONFIG_HT ; 
 int P4_CONFIG_MASK ; 
 int P4_ESCR_EVENT (int /*<<< orphan*/ ) ; 
 int P4_ESCR_EVENTMASK_MASK ; 
 int P4_ESCR_EVENT_MASK ; 
 unsigned int P4_ESCR_MSR_IDX (unsigned int) ; 
 unsigned int P4_ESCR_MSR_TABLE_SIZE ; 
 int P4_ESCR_T0_OS ; 
 int P4_ESCR_T0_USR ; 
 int P4_ESCR_T1_OS ; 
 int P4_ESCR_T1_USR ; 
 unsigned int P4_EVENT_INSTR_COMPLETED ; 
 unsigned int P4_OPCODE_ESEL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  P4_OPCODE_EVNT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  P4_PEBS_CONFIG_ENABLE ; 
 scalar_t__ P4_PEBS_CONFIG_METRIC_MASK ; 
 scalar_t__ P4_PEBS_METRIC__max ; 
 unsigned int P4_PEBS_METRIC__none ; 
 int PERF_EFLAGS_VM ; 
 size_t PERF_SAMPLE_BRANCH_CALL_STACK_SHIFT ; 
 scalar_t__ PERF_TYPE_RAW ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*,unsigned int) ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 unsigned int X86_PMC_IDX_MAX ; 
 int X86_VM_MASK ; 
 int /*<<< orphan*/  __KERNEL_CS ; 
 int /*<<< orphan*/  __USER_CS ; 
 scalar_t__ __test_and_clear_bit (int,int /*<<< orphan*/ ) ; 
 int __this_cpu_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  apic_perf_irqs ; 
 int /*<<< orphan*/  apic_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bitmap_zero (unsigned long*,unsigned int) ; 
 TYPE_7__ boot_cpu_data ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 TYPE_5__ cpu_hw_events ; 
 int get_cpu () ; 
 int /*<<< orphan*/  inc_irq_stat (int /*<<< orphan*/ ) ; 
 int p4_clear_ht_bit (int) ; 
 int p4_config_pack_cccr (int) ; 
 int p4_config_pack_escr (int) ; 
 scalar_t__ p4_config_pebs_has (int,int /*<<< orphan*/ ) ; 
 int p4_config_unpack_cccr (int) ; 
 int p4_config_unpack_escr (int) ; 
 unsigned int p4_config_unpack_event (int) ; 
 unsigned int p4_config_unpack_metric (int) ; 
 int p4_default_cccr_conf (int) ; 
 int p4_default_escr_conf (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int* p4_escr_table ; 
 struct p4_pebs_bind* p4_event_aliases ; 
 struct p4_pebs_bind* p4_event_bind_map ; 
 int* p4_general_events ; 
 scalar_t__ p4_ht_active () ; 
 int p4_ht_config_thread (int) ; 
 unsigned int p4_ht_thread (int) ; 
 int p4_is_event_cascaded (int) ; 
 struct p4_pebs_bind* p4_pebs_bind_map ; 
 int p4_set_ht_bit (int) ; 
 scalar_t__ p4_should_swap_ts (int,int) ; 
 scalar_t__ perf_event_overflow (struct perf_event*,struct perf_sample_data*,struct pt_regs*) ; 
 scalar_t__ perf_paranoid_cpu () ; 
 int /*<<< orphan*/  perf_sample_data_init (struct perf_sample_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_cpu () ; 
 int /*<<< orphan*/  rdmsrl (int,int) ; 
 int /*<<< orphan*/  set_bit (int,unsigned long*) ; 
 int smp_processor_id () ; 
 int stub1 (int,int) ; 
 int stub2 (int,int) ; 
 int stub3 (int) ; 
 scalar_t__ test_bit (int,unsigned long*) ; 
 struct cpu_hw_events* this_cpu_ptr (TYPE_5__*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  wrmsrl (int,int) ; 
 int /*<<< orphan*/  wrmsrl_safe (int,int) ; 
 int /*<<< orphan*/  x86_perf_event_set_period (struct perf_event*) ; 
 int x86_perf_event_update (struct perf_event*) ; 
 TYPE_4__ x86_pmu ; 
 int /*<<< orphan*/  x86_pmu_stop (struct perf_event*,int /*<<< orphan*/ ) ; 
 int x86_setup_perfctr (struct perf_event*) ; 

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

__attribute__((used)) static u64 p4_get_alias_event(u64 config)
{
	u64 config_match;
	int i;

	/*
	 * Only event with special mark is allowed,
	 * we're to be sure it didn't come as malformed
	 * RAW event.
	 */
	if (!(config & P4_CONFIG_ALIASABLE))
		return 0;

	config_match = config & P4_CONFIG_EVENT_ALIAS_MASK;

	for (i = 0; i < ARRAY_SIZE(p4_event_aliases); i++) {
		if (config_match == p4_event_aliases[i].original) {
			config_match = p4_event_aliases[i].alternative;
			break;
		} else if (config_match == p4_event_aliases[i].alternative) {
			config_match = p4_event_aliases[i].original;
			break;
		}
	}

	if (i >= ARRAY_SIZE(p4_event_aliases))
		return 0;

	return config_match | (config & P4_CONFIG_EVENT_ALIAS_IMMUTABLE_BITS);
}

__attribute__((used)) static struct p4_event_bind *p4_config_get_bind(u64 config)
{
	unsigned int evnt = p4_config_unpack_event(config);
	struct p4_event_bind *bind = NULL;

	if (evnt < ARRAY_SIZE(p4_event_bind_map))
		bind = &p4_event_bind_map[evnt];

	return bind;
}

__attribute__((used)) static u64 p4_pmu_event_map(int hw_event)
{
	struct p4_event_bind *bind;
	unsigned int esel;
	u64 config;

	config = p4_general_events[hw_event];
	bind = p4_config_get_bind(config);
	esel = P4_OPCODE_ESEL(bind->opcode);
	config |= p4_config_pack_cccr(P4_CCCR_ESEL(esel));

	return config;
}

__attribute__((used)) static bool p4_event_match_cpu_model(unsigned int event_idx)
{
	/* INSTR_COMPLETED event only exist for model 3, 4, 6 (Prescott) */
	if (event_idx == P4_EVENT_INSTR_COMPLETED) {
		if (boot_cpu_data.x86_model != 3 &&
			boot_cpu_data.x86_model != 4 &&
			boot_cpu_data.x86_model != 6)
			return false;
	}

	/*
	 * For info
	 * - IQ_ESCR0, IQ_ESCR1 only for models 1 and 2
	 */

	return true;
}

__attribute__((used)) static int p4_validate_raw_event(struct perf_event *event)
{
	unsigned int v, emask;

	/* User data may have out-of-bound event index */
	v = p4_config_unpack_event(event->attr.config);
	if (v >= ARRAY_SIZE(p4_event_bind_map))
		return -EINVAL;

	/* It may be unsupported: */
	if (!p4_event_match_cpu_model(v))
		return -EINVAL;

	/*
	 * NOTE: P4_CCCR_THREAD_ANY has not the same meaning as
	 * in Architectural Performance Monitoring, it means not
	 * on _which_ logical cpu to count but rather _when_, ie it
	 * depends on logical cpu state -- count event if one cpu active,
	 * none, both or any, so we just allow user to pass any value
	 * desired.
	 *
	 * In turn we always set Tx_OS/Tx_USR bits bound to logical
	 * cpu without their propagation to another cpu
	 */

	/*
	 * if an event is shared across the logical threads
	 * the user needs special permissions to be able to use it
	 */
	if (p4_ht_active() && p4_event_bind_map[v].shared) {
		if (perf_paranoid_cpu() && !capable(CAP_SYS_ADMIN))
			return -EACCES;
	}

	/* ESCR EventMask bits may be invalid */
	emask = p4_config_unpack_escr(event->attr.config) & P4_ESCR_EVENTMASK_MASK;
	if (emask & ~p4_event_bind_map[v].escr_emask)
		return -EINVAL;

	/*
	 * it may have some invalid PEBS bits
	 */
	if (p4_config_pebs_has(event->attr.config, P4_PEBS_CONFIG_ENABLE))
		return -EINVAL;

	v = p4_config_unpack_metric(event->attr.config);
	if (v >= ARRAY_SIZE(p4_pebs_bind_map))
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int p4_hw_config(struct perf_event *event)
{
	int cpu = get_cpu();
	int rc = 0;
	u32 escr, cccr;

	/*
	 * the reason we use cpu that early is that: if we get scheduled
	 * first time on the same cpu -- we will not need swap thread
	 * specific flags in config (and will save some cpu cycles)
	 */

	cccr = p4_default_cccr_conf(cpu);
	escr = p4_default_escr_conf(cpu, event->attr.exclude_kernel,
					 event->attr.exclude_user);
	event->hw.config = p4_config_pack_escr(escr) |
			   p4_config_pack_cccr(cccr);

	if (p4_ht_active() && p4_ht_thread(cpu))
		event->hw.config = p4_set_ht_bit(event->hw.config);

	if (event->attr.type == PERF_TYPE_RAW) {
		struct p4_event_bind *bind;
		unsigned int esel;
		/*
		 * Clear bits we reserve to be managed by kernel itself
		 * and never allowed from a user space
		 */
		event->attr.config &= P4_CONFIG_MASK;

		rc = p4_validate_raw_event(event);
		if (rc)
			goto out;

		/*
		 * Note that for RAW events we allow user to use P4_CCCR_RESERVED
		 * bits since we keep additional info here (for cache events and etc)
		 */
		event->hw.config |= event->attr.config;
		bind = p4_config_get_bind(event->attr.config);
		if (!bind) {
			rc = -EINVAL;
			goto out;
		}
		esel = P4_OPCODE_ESEL(bind->opcode);
		event->hw.config |= p4_config_pack_cccr(P4_CCCR_ESEL(esel));
	}

	rc = x86_setup_perfctr(event);
out:
	put_cpu();
	return rc;
}

__attribute__((used)) static inline int p4_pmu_clear_cccr_ovf(struct hw_perf_event *hwc)
{
	u64 v;

	/* an official way for overflow indication */
	rdmsrl(hwc->config_base, v);
	if (v & P4_CCCR_OVF) {
		wrmsrl(hwc->config_base, v & ~P4_CCCR_OVF);
		return 1;
	}

	/*
	 * In some circumstances the overflow might issue an NMI but did
	 * not set P4_CCCR_OVF bit. Because a counter holds a negative value
	 * we simply check for high bit being set, if it's cleared it means
	 * the counter has reached zero value and continued counting before
	 * real NMI signal was received:
	 */
	rdmsrl(hwc->event_base, v);
	if (!(v & ARCH_P4_UNFLAGGED_BIT))
		return 1;

	return 0;
}

__attribute__((used)) static void p4_pmu_disable_pebs(void)
{
	/*
	 * FIXME
	 *
	 * It's still allowed that two threads setup same cache
	 * events so we can't simply clear metrics until we knew
	 * no one is depending on us, so we need kind of counter
	 * for "ReplayEvent" users.
	 *
	 * What is more complex -- RAW events, if user (for some
	 * reason) will pass some cache event metric with improper
	 * event opcode -- it's fine from hardware point of view
	 * but completely nonsense from "meaning" of such action.
	 *
	 * So at moment let leave metrics turned on forever -- it's
	 * ok for now but need to be revisited!
	 *
	 * (void)wrmsrl_safe(MSR_IA32_PEBS_ENABLE, 0);
	 * (void)wrmsrl_safe(MSR_P4_PEBS_MATRIX_VERT, 0);
	 */
}

__attribute__((used)) static inline void p4_pmu_disable_event(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;

	/*
	 * If event gets disabled while counter is in overflowed
	 * state we need to clear P4_CCCR_OVF, otherwise interrupt get
	 * asserted again and again
	 */
	(void)wrmsrl_safe(hwc->config_base,
		p4_config_unpack_cccr(hwc->config) & ~P4_CCCR_ENABLE & ~P4_CCCR_OVF & ~P4_CCCR_RESERVED);
}

__attribute__((used)) static void p4_pmu_disable_all(void)
{
	struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
	int idx;

	for (idx = 0; idx < x86_pmu.num_counters; idx++) {
		struct perf_event *event = cpuc->events[idx];
		if (!test_bit(idx, cpuc->active_mask))
			continue;
		p4_pmu_disable_event(event);
	}

	p4_pmu_disable_pebs();
}

__attribute__((used)) static void p4_pmu_enable_pebs(u64 config)
{
	struct p4_pebs_bind *bind;
	unsigned int idx;

	BUILD_BUG_ON(P4_PEBS_METRIC__max > P4_PEBS_CONFIG_METRIC_MASK);

	idx = p4_config_unpack_metric(config);
	if (idx == P4_PEBS_METRIC__none)
		return;

	bind = &p4_pebs_bind_map[idx];

	(void)wrmsrl_safe(MSR_IA32_PEBS_ENABLE,	(u64)bind->metric_pebs);
	(void)wrmsrl_safe(MSR_P4_PEBS_MATRIX_VERT,	(u64)bind->metric_vert);
}

__attribute__((used)) static void p4_pmu_enable_event(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;
	int thread = p4_ht_config_thread(hwc->config);
	u64 escr_conf = p4_config_unpack_escr(p4_clear_ht_bit(hwc->config));
	unsigned int idx = p4_config_unpack_event(hwc->config);
	struct p4_event_bind *bind;
	u64 escr_addr, cccr;

	bind = &p4_event_bind_map[idx];
	escr_addr = bind->escr_msr[thread];

	/*
	 * - we dont support cascaded counters yet
	 * - and counter 1 is broken (erratum)
	 */
	WARN_ON_ONCE(p4_is_event_cascaded(hwc->config));
	WARN_ON_ONCE(hwc->idx == 1);

	/* we need a real Event value */
	escr_conf &= ~P4_ESCR_EVENT_MASK;
	escr_conf |= P4_ESCR_EVENT(P4_OPCODE_EVNT(bind->opcode));

	cccr = p4_config_unpack_cccr(hwc->config);

	/*
	 * it could be Cache event so we need to write metrics
	 * into additional MSRs
	 */
	p4_pmu_enable_pebs(hwc->config);

	(void)wrmsrl_safe(escr_addr, escr_conf);
	(void)wrmsrl_safe(hwc->config_base,
				(cccr & ~P4_CCCR_RESERVED) | P4_CCCR_ENABLE);
}

__attribute__((used)) static void p4_pmu_enable_all(int added)
{
	struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
	int idx;

	for (idx = 0; idx < x86_pmu.num_counters; idx++) {
		struct perf_event *event = cpuc->events[idx];
		if (!test_bit(idx, cpuc->active_mask))
			continue;
		p4_pmu_enable_event(event);
	}
}

__attribute__((used)) static int p4_pmu_handle_irq(struct pt_regs *regs)
{
	struct perf_sample_data data;
	struct cpu_hw_events *cpuc;
	struct perf_event *event;
	struct hw_perf_event *hwc;
	int idx, handled = 0;
	u64 val;

	cpuc = this_cpu_ptr(&cpu_hw_events);

	for (idx = 0; idx < x86_pmu.num_counters; idx++) {
		int overflow;

		if (!test_bit(idx, cpuc->active_mask)) {
			/* catch in-flight IRQs */
			if (__test_and_clear_bit(idx, cpuc->running))
				handled++;
			continue;
		}

		event = cpuc->events[idx];
		hwc = &event->hw;

		WARN_ON_ONCE(hwc->idx != idx);

		/* it might be unflagged overflow */
		overflow = p4_pmu_clear_cccr_ovf(hwc);

		val = x86_perf_event_update(event);
		if (!overflow && (val & (1ULL << (x86_pmu.cntval_bits - 1))))
			continue;

		handled += overflow;

		/* event overflow for sure */
		perf_sample_data_init(&data, 0, hwc->last_period);

		if (!x86_perf_event_set_period(event))
			continue;


		if (perf_event_overflow(event, &data, regs))
			x86_pmu_stop(event, 0);
	}

	if (handled)
		inc_irq_stat(apic_perf_irqs);

	/*
	 * When dealing with the unmasking of the LVTPC on P4 perf hw, it has
	 * been observed that the OVF bit flag has to be cleared first _before_
	 * the LVTPC can be unmasked.
	 *
	 * The reason is the NMI line will continue to be asserted while the OVF
	 * bit is set.  This causes a second NMI to generate if the LVTPC is
	 * unmasked before the OVF bit is cleared, leading to unknown NMI
	 * messages.
	 */
	apic_write(APIC_LVTPC, APIC_DM_NMI);

	return handled;
}

__attribute__((used)) static void p4_pmu_swap_config_ts(struct hw_perf_event *hwc, int cpu)
{
	u32 escr, cccr;

	/*
	 * we either lucky and continue on same cpu or no HT support
	 */
	if (!p4_should_swap_ts(hwc->config, cpu))
		return;

	/*
	 * the event is migrated from an another logical
	 * cpu, so we need to swap thread specific flags
	 */

	escr = p4_config_unpack_escr(hwc->config);
	cccr = p4_config_unpack_cccr(hwc->config);

	if (p4_ht_thread(cpu)) {
		cccr &= ~P4_CCCR_OVF_PMI_T0;
		cccr |= P4_CCCR_OVF_PMI_T1;
		if (escr & P4_ESCR_T0_OS) {
			escr &= ~P4_ESCR_T0_OS;
			escr |= P4_ESCR_T1_OS;
		}
		if (escr & P4_ESCR_T0_USR) {
			escr &= ~P4_ESCR_T0_USR;
			escr |= P4_ESCR_T1_USR;
		}
		hwc->config  = p4_config_pack_escr(escr);
		hwc->config |= p4_config_pack_cccr(cccr);
		hwc->config |= P4_CONFIG_HT;
	} else {
		cccr &= ~P4_CCCR_OVF_PMI_T1;
		cccr |= P4_CCCR_OVF_PMI_T0;
		if (escr & P4_ESCR_T1_OS) {
			escr &= ~P4_ESCR_T1_OS;
			escr |= P4_ESCR_T0_OS;
		}
		if (escr & P4_ESCR_T1_USR) {
			escr &= ~P4_ESCR_T1_USR;
			escr |= P4_ESCR_T0_USR;
		}
		hwc->config  = p4_config_pack_escr(escr);
		hwc->config |= p4_config_pack_cccr(cccr);
		hwc->config &= ~P4_CONFIG_HT;
	}
}

__attribute__((used)) static int p4_get_escr_idx(unsigned int addr)
{
	unsigned int idx = P4_ESCR_MSR_IDX(addr);

	if (unlikely(idx >= P4_ESCR_MSR_TABLE_SIZE	||
			!p4_escr_table[idx]		||
			p4_escr_table[idx] != addr)) {
		WARN_ONCE(1, "P4 PMU: Wrong address passed: %x\n", addr);
		return -1;
	}

	return idx;
}

__attribute__((used)) static int p4_next_cntr(int thread, unsigned long *used_mask,
			struct p4_event_bind *bind)
{
	int i, j;

	for (i = 0; i < P4_CNTR_LIMIT; i++) {
		j = bind->cntr[thread][i];
		if (j != -1 && !test_bit(j, used_mask))
			return j;
	}

	return -1;
}

__attribute__((used)) static int p4_pmu_schedule_events(struct cpu_hw_events *cpuc, int n, int *assign)
{
	unsigned long used_mask[BITS_TO_LONGS(X86_PMC_IDX_MAX)];
	unsigned long escr_mask[BITS_TO_LONGS(P4_ESCR_MSR_TABLE_SIZE)];
	int cpu = smp_processor_id();
	struct hw_perf_event *hwc;
	struct p4_event_bind *bind;
	unsigned int i, thread, num;
	int cntr_idx, escr_idx;
	u64 config_alias;
	int pass;

	bitmap_zero(used_mask, X86_PMC_IDX_MAX);
	bitmap_zero(escr_mask, P4_ESCR_MSR_TABLE_SIZE);

	for (i = 0, num = n; i < n; i++, num--) {

		hwc = &cpuc->event_list[i]->hw;
		thread = p4_ht_thread(cpu);
		pass = 0;

again:
		/*
		 * It's possible to hit a circular lock
		 * between original and alternative events
		 * if both are scheduled already.
		 */
		if (pass > 2)
			goto done;

		bind = p4_config_get_bind(hwc->config);
		escr_idx = p4_get_escr_idx(bind->escr_msr[thread]);
		if (unlikely(escr_idx == -1))
			goto done;

		if (hwc->idx != -1 && !p4_should_swap_ts(hwc->config, cpu)) {
			cntr_idx = hwc->idx;
			if (assign)
				assign[i] = hwc->idx;
			goto reserve;
		}

		cntr_idx = p4_next_cntr(thread, used_mask, bind);
		if (cntr_idx == -1 || test_bit(escr_idx, escr_mask)) {
			/*
			 * Check whether an event alias is still available.
			 */
			config_alias = p4_get_alias_event(hwc->config);
			if (!config_alias)
				goto done;
			hwc->config = config_alias;
			pass++;
			goto again;
		}
		/*
		 * Perf does test runs to see if a whole group can be assigned
		 * together succesfully.  There can be multiple rounds of this.
		 * Unfortunately, p4_pmu_swap_config_ts touches the hwc->config
		 * bits, such that the next round of group assignments will
		 * cause the above p4_should_swap_ts to pass instead of fail.
		 * This leads to counters exclusive to thread0 being used by
		 * thread1.
		 *
		 * Solve this with a cheap hack, reset the idx back to -1 to
		 * force a new lookup (p4_next_cntr) to get the right counter
		 * for the right thread.
		 *
		 * This probably doesn't comply with the general spirit of how
		 * perf wants to work, but P4 is special. :-(
		 */
		if (p4_should_swap_ts(hwc->config, cpu))
			hwc->idx = -1;
		p4_pmu_swap_config_ts(hwc, cpu);
		if (assign)
			assign[i] = cntr_idx;
reserve:
		set_bit(cntr_idx, used_mask);
		set_bit(escr_idx, escr_mask);
	}

done:
	return num ? -EINVAL : 0;
}

