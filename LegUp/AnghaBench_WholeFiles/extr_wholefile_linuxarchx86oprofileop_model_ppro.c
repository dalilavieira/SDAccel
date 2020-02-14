#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_8__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {scalar_t__ version_id; int bit_width; int num_counters; } ;
union cpuid10_eax {TYPE_3__ split; void* full; } ;
typedef  int u64 ;
struct pt_regs {int dummy; } ;
struct oprofile_operations {int dummy; } ;
struct op_x86_model_spec {int reserved; } ;
struct op_msrs {TYPE_2__* controls; TYPE_1__* counters; } ;
struct TYPE_15__ {int x86; int x86_model; } ;
struct TYPE_14__ {int /*<<< orphan*/  x86_model; int /*<<< orphan*/  x86; } ;
struct TYPE_13__ {int num_counters; int num_controls; } ;
struct TYPE_12__ {int count; scalar_t__ enabled; } ;
struct TYPE_10__ {scalar_t__ addr; } ;
struct TYPE_9__ {scalar_t__ addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  APIC_LVTPC ; 
 int APIC_LVT_MASKED ; 
 int ARCH_PERFMON_EVENTSEL_ENABLE ; 
 int EBUSY ; 
 scalar_t__ MSR_P6_EVNTSEL0 ; 
 scalar_t__ MSR_P6_PERFCTR0 ; 
 int /*<<< orphan*/  OP_MAX_COUNTER ; 
 int /*<<< orphan*/  X86_FEATURE_ARCH_PERFMON ; 
 int __this_cpu_read (int /*<<< orphan*/ ) ; 
 int apic_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  apic_write (int /*<<< orphan*/ ,int) ; 
 TYPE_8__ boot_cpu_data ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 
 TYPE_4__* counter_config ; 
 int counter_width ; 
 TYPE_6__ cpu_info ; 
 void* cpuid_eax (int) ; 
 int min (int,int /*<<< orphan*/ ) ; 
 int num_counters ; 
 TYPE_5__ op_arch_perfmon_spec ; 
 int op_x86_get_ctrl (struct op_x86_model_spec const*,TYPE_4__*) ; 
 int /*<<< orphan*/  oprofile_add_sample (struct pt_regs* const,int) ; 
 int /*<<< orphan*/  pr_warning (char*,int,...) ; 
 int /*<<< orphan*/  rdmsrl (scalar_t__,int) ; 
 int /*<<< orphan*/  release_evntsel_nmi (scalar_t__) ; 
 int /*<<< orphan*/  release_perfctr_nmi (scalar_t__) ; 
 int /*<<< orphan*/  reserve_evntsel_nmi (scalar_t__) ; 
 int /*<<< orphan*/  reserve_perfctr_nmi (scalar_t__) ; 
 int* reset_value ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int /*<<< orphan*/  wrmsrl (scalar_t__,int) ; 

__attribute__((used)) static inline void op_x86_warn_in_use(int counter)
{
	/*
	 * The warning indicates an already running counter. If
	 * oprofile doesn't collect data, then try using a different
	 * performance counter on your platform to monitor the desired
	 * event. Delete counter #%d from the desired event by editing
	 * the /usr/share/oprofile/%s/<cpu>/events file. If the event
	 * cannot be monitored by any other counter, contact your
	 * hardware or BIOS vendor.
	 */
	pr_warning("oprofile: counter #%d on cpu #%d may already be used\n",
		   counter, smp_processor_id());
}

__attribute__((used)) static inline void op_x86_warn_reserved(int counter)
{
	pr_warning("oprofile: counter #%d is already reserved\n", counter);
}

__attribute__((used)) static void ppro_shutdown(struct op_msrs const * const msrs)
{
	int i;

	for (i = 0; i < num_counters; ++i) {
		if (!msrs->counters[i].addr)
			continue;
		release_perfctr_nmi(MSR_P6_PERFCTR0 + i);
		release_evntsel_nmi(MSR_P6_EVNTSEL0 + i);
	}
}

__attribute__((used)) static int ppro_fill_in_addresses(struct op_msrs * const msrs)
{
	int i;

	for (i = 0; i < num_counters; i++) {
		if (!reserve_perfctr_nmi(MSR_P6_PERFCTR0 + i))
			goto fail;
		if (!reserve_evntsel_nmi(MSR_P6_EVNTSEL0 + i)) {
			release_perfctr_nmi(MSR_P6_PERFCTR0 + i);
			goto fail;
		}
		/* both registers must be reserved */
		msrs->counters[i].addr = MSR_P6_PERFCTR0 + i;
		msrs->controls[i].addr = MSR_P6_EVNTSEL0 + i;
		continue;
	fail:
		if (!counter_config[i].enabled)
			continue;
		op_x86_warn_reserved(i);
		ppro_shutdown(msrs);
		return -EBUSY;
	}

	return 0;
}

__attribute__((used)) static void ppro_setup_ctrs(struct op_x86_model_spec const *model,
			    struct op_msrs const * const msrs)
{
	u64 val;
	int i;

	if (boot_cpu_has(X86_FEATURE_ARCH_PERFMON)) {
		union cpuid10_eax eax;
		eax.full = cpuid_eax(0xa);

		/*
		 * For Core2 (family 6, model 15), don't reset the
		 * counter width:
		 */
		if (!(eax.split.version_id == 0 &&
			__this_cpu_read(cpu_info.x86) == 6 &&
				__this_cpu_read(cpu_info.x86_model) == 15)) {

			if (counter_width < eax.split.bit_width)
				counter_width = eax.split.bit_width;
		}
	}

	/* clear all counters */
	for (i = 0; i < num_counters; ++i) {
		if (!msrs->controls[i].addr)
			continue;
		rdmsrl(msrs->controls[i].addr, val);
		if (val & ARCH_PERFMON_EVENTSEL_ENABLE)
			op_x86_warn_in_use(i);
		val &= model->reserved;
		wrmsrl(msrs->controls[i].addr, val);
		/*
		 * avoid a false detection of ctr overflows in NMI *
		 * handler
		 */
		wrmsrl(msrs->counters[i].addr, -1LL);
	}

	/* enable active counters */
	for (i = 0; i < num_counters; ++i) {
		if (counter_config[i].enabled && msrs->counters[i].addr) {
			reset_value[i] = counter_config[i].count;
			wrmsrl(msrs->counters[i].addr, -reset_value[i]);
			rdmsrl(msrs->controls[i].addr, val);
			val &= model->reserved;
			val |= op_x86_get_ctrl(model, &counter_config[i]);
			wrmsrl(msrs->controls[i].addr, val);
		} else {
			reset_value[i] = 0;
		}
	}
}

__attribute__((used)) static int ppro_check_ctrs(struct pt_regs * const regs,
			   struct op_msrs const * const msrs)
{
	u64 val;
	int i;

	for (i = 0; i < num_counters; ++i) {
		if (!reset_value[i])
			continue;
		rdmsrl(msrs->counters[i].addr, val);
		if (val & (1ULL << (counter_width - 1)))
			continue;
		oprofile_add_sample(regs, i);
		wrmsrl(msrs->counters[i].addr, -reset_value[i]);
	}

	/* Only P6 based Pentium M need to re-unmask the apic vector but it
	 * doesn't hurt other P6 variant */
	apic_write(APIC_LVTPC, apic_read(APIC_LVTPC) & ~APIC_LVT_MASKED);

	/* We can't work out if we really handled an interrupt. We
	 * might have caught a *second* counter just after overflowing
	 * the interrupt for this counter then arrives
	 * and we don't find a counter that's overflowed, so we
	 * would return 0 and get dazed + confused. Instead we always
	 * assume we found an overflow. This sucks.
	 */
	return 1;
}

__attribute__((used)) static void ppro_start(struct op_msrs const * const msrs)
{
	u64 val;
	int i;

	for (i = 0; i < num_counters; ++i) {
		if (reset_value[i]) {
			rdmsrl(msrs->controls[i].addr, val);
			val |= ARCH_PERFMON_EVENTSEL_ENABLE;
			wrmsrl(msrs->controls[i].addr, val);
		}
	}
}

__attribute__((used)) static void ppro_stop(struct op_msrs const * const msrs)
{
	u64 val;
	int i;

	for (i = 0; i < num_counters; ++i) {
		if (!reset_value[i])
			continue;
		rdmsrl(msrs->controls[i].addr, val);
		val &= ~ARCH_PERFMON_EVENTSEL_ENABLE;
		wrmsrl(msrs->controls[i].addr, val);
	}
}

__attribute__((used)) static void arch_perfmon_setup_counters(void)
{
	union cpuid10_eax eax;

	eax.full = cpuid_eax(0xa);

	/* Workaround for BIOS bugs in 6/15. Taken from perfmon2 */
	if (eax.split.version_id == 0 && boot_cpu_data.x86 == 6 &&
	    boot_cpu_data.x86_model == 15) {
		eax.split.version_id = 2;
		eax.split.num_counters = 2;
		eax.split.bit_width = 40;
	}

	num_counters = min((int)eax.split.num_counters, OP_MAX_COUNTER);

	op_arch_perfmon_spec.num_counters = num_counters;
	op_arch_perfmon_spec.num_controls = num_counters;
}

__attribute__((used)) static int arch_perfmon_init(struct oprofile_operations *ignore)
{
	arch_perfmon_setup_counters();
	return 0;
}

