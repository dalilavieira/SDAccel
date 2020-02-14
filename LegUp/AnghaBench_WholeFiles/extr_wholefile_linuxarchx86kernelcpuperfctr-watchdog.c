#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int x86_vendor; int /*<<< orphan*/  x86; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  MSR_ARCH_PERFMON_EVENTSEL0 ; 
 int /*<<< orphan*/  MSR_ARCH_PERFMON_PERFCTR0 ; 
 unsigned int MSR_F15H_PERF_CTL ; 
 unsigned int MSR_F15H_PERF_CTR ; 
 int /*<<< orphan*/  MSR_K7_EVNTSEL0 ; 
 int /*<<< orphan*/  MSR_K7_PERFCTR0 ; 
 int /*<<< orphan*/  MSR_KNC_EVNTSEL0 ; 
 int /*<<< orphan*/  MSR_KNC_PERFCTR0 ; 
 int /*<<< orphan*/  MSR_P4_BPU_PERFCTR0 ; 
 int /*<<< orphan*/  MSR_P4_BSU_ESCR0 ; 
 int /*<<< orphan*/  MSR_P6_EVNTSEL0 ; 
 int /*<<< orphan*/  MSR_P6_PERFCTR0 ; 
 unsigned int NMI_MAX_COUNTER_BITS ; 
 int /*<<< orphan*/  X86_FEATURE_ARCH_PERFMON ; 
#define  X86_VENDOR_AMD 129 
#define  X86_VENDOR_INTEL 128 
 TYPE_1__ boot_cpu_data ; 
 int /*<<< orphan*/  clear_bit (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_has (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evntsel_nmi_owner ; 
 int /*<<< orphan*/  perfctr_nmi_owner ; 
 int /*<<< orphan*/  test_and_set_bit (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_bit (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned int nmi_perfctr_msr_to_bit(unsigned int msr)
{
	/* returns the bit offset of the performance counter register */
	switch (boot_cpu_data.x86_vendor) {
	case X86_VENDOR_AMD:
		if (msr >= MSR_F15H_PERF_CTR)
			return (msr - MSR_F15H_PERF_CTR) >> 1;
		return msr - MSR_K7_PERFCTR0;
	case X86_VENDOR_INTEL:
		if (cpu_has(&boot_cpu_data, X86_FEATURE_ARCH_PERFMON))
			return msr - MSR_ARCH_PERFMON_PERFCTR0;

		switch (boot_cpu_data.x86) {
		case 6:
			return msr - MSR_P6_PERFCTR0;
		case 11:
			return msr - MSR_KNC_PERFCTR0;
		case 15:
			return msr - MSR_P4_BPU_PERFCTR0;
		}
	}
	return 0;
}

__attribute__((used)) static inline unsigned int nmi_evntsel_msr_to_bit(unsigned int msr)
{
	/* returns the bit offset of the event selection register */
	switch (boot_cpu_data.x86_vendor) {
	case X86_VENDOR_AMD:
		if (msr >= MSR_F15H_PERF_CTL)
			return (msr - MSR_F15H_PERF_CTL) >> 1;
		return msr - MSR_K7_EVNTSEL0;
	case X86_VENDOR_INTEL:
		if (cpu_has(&boot_cpu_data, X86_FEATURE_ARCH_PERFMON))
			return msr - MSR_ARCH_PERFMON_EVENTSEL0;

		switch (boot_cpu_data.x86) {
		case 6:
			return msr - MSR_P6_EVNTSEL0;
		case 11:
			return msr - MSR_KNC_EVNTSEL0;
		case 15:
			return msr - MSR_P4_BSU_ESCR0;
		}
	}
	return 0;

}

int avail_to_resrv_perfctr_nmi_bit(unsigned int counter)
{
	BUG_ON(counter > NMI_MAX_COUNTER_BITS);

	return !test_bit(counter, perfctr_nmi_owner);
}

int reserve_perfctr_nmi(unsigned int msr)
{
	unsigned int counter;

	counter = nmi_perfctr_msr_to_bit(msr);
	/* register not managed by the allocator? */
	if (counter > NMI_MAX_COUNTER_BITS)
		return 1;

	if (!test_and_set_bit(counter, perfctr_nmi_owner))
		return 1;
	return 0;
}

void release_perfctr_nmi(unsigned int msr)
{
	unsigned int counter;

	counter = nmi_perfctr_msr_to_bit(msr);
	/* register not managed by the allocator? */
	if (counter > NMI_MAX_COUNTER_BITS)
		return;

	clear_bit(counter, perfctr_nmi_owner);
}

int reserve_evntsel_nmi(unsigned int msr)
{
	unsigned int counter;

	counter = nmi_evntsel_msr_to_bit(msr);
	/* register not managed by the allocator? */
	if (counter > NMI_MAX_COUNTER_BITS)
		return 1;

	if (!test_and_set_bit(counter, evntsel_nmi_owner))
		return 1;
	return 0;
}

void release_evntsel_nmi(unsigned int msr)
{
	unsigned int counter;

	counter = nmi_evntsel_msr_to_bit(msr);
	/* register not managed by the allocator? */
	if (counter > NMI_MAX_COUNTER_BITS)
		return;

	clear_bit(counter, evntsel_nmi_owner);
}

