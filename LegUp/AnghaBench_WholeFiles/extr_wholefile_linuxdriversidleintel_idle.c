#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct cpuidle_driver {TYPE_1__* states; } ;
struct cpuidle_device {int dummy; } ;
struct TYPE_10__ {int x86_model; } ;
struct TYPE_9__ {unsigned int exit_latency; unsigned int target_residency; } ;
struct TYPE_8__ {unsigned long long auto_demotion_disable_flags; } ;
struct TYPE_7__ {int disabled; } ;
struct TYPE_6__ {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
#define  INTEL_FAM6_ATOM_GEMINI_LAKE 131 
#define  INTEL_FAM6_ATOM_GOLDMONT 130 
#define  INTEL_FAM6_IVYBRIDGE_X 129 
#define  INTEL_FAM6_SKYLAKE_DESKTOP 128 
 int /*<<< orphan*/  MSR_IA32_FEATURE_CONTROL ; 
 int /*<<< orphan*/  MSR_IA32_POWER_CTL ; 
 int /*<<< orphan*/  MSR_PKGC10_IRTL ; 
 int /*<<< orphan*/  MSR_PKGC6_IRTL ; 
 int /*<<< orphan*/  MSR_PKGC7_IRTL ; 
 int /*<<< orphan*/  MSR_PKGC8_IRTL ; 
 int /*<<< orphan*/  MSR_PKGC9_IRTL ; 
 int /*<<< orphan*/  MSR_PKG_CST_CONFIG_CONTROL ; 
 TYPE_5__ boot_cpu_data ; 
 TYPE_4__* bxt_cstates ; 
 int /*<<< orphan*/  cpuid (int,unsigned int*,unsigned int*,unsigned int*,unsigned int*) ; 
 unsigned long long div64_u64 (unsigned long long,int) ; 
 unsigned long flg2MWAIT (int /*<<< orphan*/ ) ; 
 TYPE_3__* icpu ; 
 unsigned long long* irtl_ns_units ; 
 int /*<<< orphan*/  ivt_idle_state_table_update () ; 
 int max_cstate ; 
 int /*<<< orphan*/  mwait_idle_with_hints (unsigned long,unsigned long) ; 
 int mwait_substates ; 
 int /*<<< orphan*/  rdmsrl (int /*<<< orphan*/ ,unsigned long long) ; 
 TYPE_2__* skl_cstates ; 
 int /*<<< orphan*/  tick_broadcast_disable () ; 
 int /*<<< orphan*/  tick_broadcast_enable () ; 
 int /*<<< orphan*/  wrmsrl (int /*<<< orphan*/ ,unsigned long long) ; 

__attribute__((used)) static void intel_idle_s2idle(struct cpuidle_device *dev,
			     struct cpuidle_driver *drv, int index)
{
	unsigned long ecx = 1; /* break on interrupt flag */
	unsigned long eax = flg2MWAIT(drv->states[index].flags);

	mwait_idle_with_hints(eax, ecx);
}

__attribute__((used)) static void __setup_broadcast_timer(bool on)
{
	if (on)
		tick_broadcast_enable();
	else
		tick_broadcast_disable();
}

__attribute__((used)) static void auto_demotion_disable(void)
{
	unsigned long long msr_bits;

	rdmsrl(MSR_PKG_CST_CONFIG_CONTROL, msr_bits);
	msr_bits &= ~(icpu->auto_demotion_disable_flags);
	wrmsrl(MSR_PKG_CST_CONFIG_CONTROL, msr_bits);
}

__attribute__((used)) static void c1e_promotion_disable(void)
{
	unsigned long long msr_bits;

	rdmsrl(MSR_IA32_POWER_CTL, msr_bits);
	msr_bits &= ~0x2;
	wrmsrl(MSR_IA32_POWER_CTL, msr_bits);
}

__attribute__((used)) static unsigned long long irtl_2_usec(unsigned long long irtl)
{
	unsigned long long ns;

	if (!irtl)
		return 0;

	ns = irtl_ns_units[(irtl >> 10) & 0x7];

	return div64_u64((irtl & 0x3FF) * ns, 1000);
}

__attribute__((used)) static void bxt_idle_state_table_update(void)
{
	unsigned long long msr;
	unsigned int usec;

	rdmsrl(MSR_PKGC6_IRTL, msr);
	usec = irtl_2_usec(msr);
	if (usec) {
		bxt_cstates[2].exit_latency = usec;
		bxt_cstates[2].target_residency = usec;
	}

	rdmsrl(MSR_PKGC7_IRTL, msr);
	usec = irtl_2_usec(msr);
	if (usec) {
		bxt_cstates[3].exit_latency = usec;
		bxt_cstates[3].target_residency = usec;
	}

	rdmsrl(MSR_PKGC8_IRTL, msr);
	usec = irtl_2_usec(msr);
	if (usec) {
		bxt_cstates[4].exit_latency = usec;
		bxt_cstates[4].target_residency = usec;
	}

	rdmsrl(MSR_PKGC9_IRTL, msr);
	usec = irtl_2_usec(msr);
	if (usec) {
		bxt_cstates[5].exit_latency = usec;
		bxt_cstates[5].target_residency = usec;
	}

	rdmsrl(MSR_PKGC10_IRTL, msr);
	usec = irtl_2_usec(msr);
	if (usec) {
		bxt_cstates[6].exit_latency = usec;
		bxt_cstates[6].target_residency = usec;
	}

}

__attribute__((used)) static void sklh_idle_state_table_update(void)
{
	unsigned long long msr;
	unsigned int eax, ebx, ecx, edx;


	/* if PC10 disabled via cmdline intel_idle.max_cstate=7 or shallower */
	if (max_cstate <= 7)
		return;

	/* if PC10 not present in CPUID.MWAIT.EDX */
	if ((mwait_substates & (0xF << 28)) == 0)
		return;

	rdmsrl(MSR_PKG_CST_CONFIG_CONTROL, msr);

	/* PC10 is not enabled in PKG C-state limit */
	if ((msr & 0xF) != 8)
		return;

	ecx = 0;
	cpuid(7, &eax, &ebx, &ecx, &edx);

	/* if SGX is present */
	if (ebx & (1 << 2)) {

		rdmsrl(MSR_IA32_FEATURE_CONTROL, msr);

		/* if SGX is enabled */
		if (msr & (1 << 18))
			return;
	}

	skl_cstates[5].disabled = 1;	/* C8-SKL */
	skl_cstates[6].disabled = 1;	/* C9-SKL */
}

__attribute__((used)) static void intel_idle_state_table_update(void)
{
	switch (boot_cpu_data.x86_model) {

	case INTEL_FAM6_IVYBRIDGE_X:
		ivt_idle_state_table_update();
		break;
	case INTEL_FAM6_ATOM_GOLDMONT:
	case INTEL_FAM6_ATOM_GEMINI_LAKE:
		bxt_idle_state_table_update();
		break;
	case INTEL_FAM6_SKYLAKE_DESKTOP:
		sklh_idle_state_table_update();
		break;
	}
}

