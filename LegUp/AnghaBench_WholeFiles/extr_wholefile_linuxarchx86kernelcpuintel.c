#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  unsigned int u32 ;
struct cpuinfo_x86 {int x86; int x86_model; scalar_t__ x86_stepping; scalar_t__ microcode; int cpuid_level; int x86_cache_alignment; int x86_phys_bits; int x86_power; unsigned int x86_cache_size; int /*<<< orphan*/  x86_model_id; int /*<<< orphan*/  x86_coreid_bits; } ;
struct TYPE_5__ {unsigned char const descriptor; int tlb_type; int /*<<< orphan*/  entries; } ;
struct TYPE_4__ {scalar_t__ model; scalar_t__ stepping; scalar_t__ microcode; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  ELF_HWCAP2 ; 
 scalar_t__ ENERGY_PERF_BIAS_NORMAL ; 
 scalar_t__ ENERGY_PERF_BIAS_PERFORMANCE ; 
 size_t ENTRIES ; 
 int /*<<< orphan*/  HWCAP2_RING3MWAIT ; 
 int INTEL_FAM6_ATOM_GOLDMONT ; 
#define  INTEL_FAM6_XEON_PHI_KNL 143 
#define  INTEL_FAM6_XEON_PHI_KNM 142 
 scalar_t__ MKTME_DISABLED ; 
 scalar_t__ MKTME_ENABLED ; 
 scalar_t__ MKTME_UNINITIALIZED ; 
 int /*<<< orphan*/  MSR_IA32_ENERGY_PERF_BIAS ; 
 int /*<<< orphan*/  MSR_IA32_MISC_ENABLE ; 
 scalar_t__ MSR_IA32_MISC_ENABLE_FAST_STRING ; 
 int /*<<< orphan*/  MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT ; 
 int /*<<< orphan*/  MSR_IA32_TME_ACTIVATE ; 
 int /*<<< orphan*/  MSR_IA32_VMX_EPT_VPID_CAP ; 
 int /*<<< orphan*/  MSR_IA32_VMX_PROCBASED_CTLS ; 
 int /*<<< orphan*/  MSR_IA32_VMX_PROCBASED_CTLS2 ; 
 int /*<<< orphan*/  MSR_MISC_FEATURES_ENABLES ; 
 unsigned long MSR_MISC_FEATURES_ENABLES_RING3MWAIT_BIT ; 
 int /*<<< orphan*/  MSR_PLATFORM_INFO ; 
 scalar_t__ MSR_PLATFORM_INFO_CPUID_FAULT ; 
#define  STLB_4K 141 
#define  STLB_4K_2M 140 
#define  TLB_DATA0_2M_4M 139 
#define  TLB_DATA0_4K 138 
#define  TLB_DATA0_4M 137 
#define  TLB_DATA_1G 136 
#define  TLB_DATA_2M_4M 135 
#define  TLB_DATA_4K 134 
#define  TLB_DATA_4K_4M 133 
#define  TLB_DATA_4M 132 
#define  TLB_INST_2M_4M 131 
#define  TLB_INST_4K 130 
#define  TLB_INST_4M 129 
#define  TLB_INST_ALL 128 
 scalar_t__ TME_ACTIVATE_CRYPTO_AES_XTS_128 ; 
 scalar_t__ TME_ACTIVATE_CRYPTO_ALGS (scalar_t__) ; 
 int /*<<< orphan*/  TME_ACTIVATE_ENABLED (scalar_t__) ; 
 int TME_ACTIVATE_KEYID_BITS (scalar_t__) ; 
 int /*<<< orphan*/  TME_ACTIVATE_LOCKED (scalar_t__) ; 
 scalar_t__ TME_ACTIVATE_POLICY (scalar_t__) ; 
 scalar_t__ TME_ACTIVATE_POLICY_AES_XTS_128 ; 
 int /*<<< orphan*/  X86_BUG_CLFLUSH_MONITOR ; 
 int /*<<< orphan*/  X86_BUG_MONITOR ; 
 int /*<<< orphan*/  X86_FEATURE_ARCH_PERFMON ; 
 int /*<<< orphan*/  X86_FEATURE_BTS ; 
 int /*<<< orphan*/  X86_FEATURE_CLFLUSH ; 
 int /*<<< orphan*/  X86_FEATURE_CONSTANT_TSC ; 
 int /*<<< orphan*/  X86_FEATURE_CPUID_FAULT ; 
 int /*<<< orphan*/  X86_FEATURE_DS ; 
 int /*<<< orphan*/  X86_FEATURE_EPB ; 
 int /*<<< orphan*/  X86_FEATURE_EPT ; 
 int /*<<< orphan*/  X86_FEATURE_EPT_AD ; 
 int /*<<< orphan*/  X86_FEATURE_ERMS ; 
 int /*<<< orphan*/  X86_FEATURE_FLEXPRIORITY ; 
 int /*<<< orphan*/  X86_FEATURE_HYPERVISOR ; 
 int /*<<< orphan*/  X86_FEATURE_IA64 ; 
 int /*<<< orphan*/  X86_FEATURE_IBPB ; 
 int /*<<< orphan*/  X86_FEATURE_IBRS ; 
 int /*<<< orphan*/  X86_FEATURE_INTEL_STIBP ; 
 int /*<<< orphan*/  X86_FEATURE_LFENCE_RDTSC ; 
 int /*<<< orphan*/  X86_FEATURE_MPX ; 
 int /*<<< orphan*/  X86_FEATURE_MSR_SPEC_CTRL ; 
 int /*<<< orphan*/  X86_FEATURE_MWAIT ; 
 int /*<<< orphan*/  X86_FEATURE_NONSTOP_TSC ; 
 int /*<<< orphan*/  X86_FEATURE_NONSTOP_TSC_S3 ; 
 int /*<<< orphan*/  X86_FEATURE_P3 ; 
 int /*<<< orphan*/  X86_FEATURE_P4 ; 
 int /*<<< orphan*/  X86_FEATURE_PAT ; 
 int /*<<< orphan*/  X86_FEATURE_PEBS ; 
 int /*<<< orphan*/  X86_FEATURE_PGE ; 
 int /*<<< orphan*/  X86_FEATURE_PSE ; 
 int /*<<< orphan*/  X86_FEATURE_REP_GOOD ; 
 int /*<<< orphan*/  X86_FEATURE_RING3MWAIT ; 
 int /*<<< orphan*/  X86_FEATURE_SMEP ; 
 int /*<<< orphan*/  X86_FEATURE_SPEC_CTRL ; 
 int /*<<< orphan*/  X86_FEATURE_SPEC_CTRL_SSBD ; 
 int /*<<< orphan*/  X86_FEATURE_SSBD ; 
 int /*<<< orphan*/  X86_FEATURE_STIBP ; 
 int /*<<< orphan*/  X86_FEATURE_TME ; 
 int /*<<< orphan*/  X86_FEATURE_TPR_SHADOW ; 
 int /*<<< orphan*/  X86_FEATURE_VMX ; 
 int /*<<< orphan*/  X86_FEATURE_VNMI ; 
 int /*<<< orphan*/  X86_FEATURE_VPID ; 
 int /*<<< orphan*/  X86_FEATURE_XMM2 ; 
 int /*<<< orphan*/  X86_FEATURE_XTOPOLOGY ; 
 struct cpuinfo_x86 boot_cpu_data ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_cpu_cap (struct cpuinfo_x86*,int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_has (struct cpuinfo_x86*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpuid (int,unsigned int*,unsigned int*,unsigned int*,unsigned int*) ; 
 int cpuid_eax (int) ; 
 int /*<<< orphan*/  detect_extended_topology (struct cpuinfo_x86*) ; 
 scalar_t__ detect_extended_topology_early (struct cpuinfo_x86*) ; 
 int /*<<< orphan*/  detect_ht_early (struct cpuinfo_x86*) ; 
 int /*<<< orphan*/  detect_num_cpu_cores (struct cpuinfo_x86*) ; 
 scalar_t__ forcempx ; 
 int /*<<< orphan*/  get_count_order (unsigned int) ; 
 int /*<<< orphan*/  get_cpu_cap (struct cpuinfo_x86*) ; 
 int /*<<< orphan*/  init_intel_cacheinfo (struct cpuinfo_x86*) ; 
 scalar_t__ intel_get_microcode_revision () ; 
 TYPE_2__* intel_tlb_table ; 
 scalar_t__ mktme_status ; 
 scalar_t__ msr_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msr_misc_features_shadow ; 
 int /*<<< orphan*/  pr_err (char*,scalar_t__) ; 
 int /*<<< orphan*/  pr_err_once (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  pr_info_once (char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  pr_warn_once (char*) ; 
 int /*<<< orphan*/  rdmsr (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  rdmsrl (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ rdmsrl_safe (int /*<<< orphan*/ ,scalar_t__*) ; 
 scalar_t__ ring3mwait_disabled ; 
 int /*<<< orphan*/  set_cpu_bug (struct cpuinfo_x86*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_cpu_cap (struct cpuinfo_x86*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setup_clear_cpu_cap (int /*<<< orphan*/ ) ; 
 TYPE_1__* spectre_bad_microcodes ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  this_cpu_or (int /*<<< orphan*/ ,unsigned long) ; 
 scalar_t__ this_cpu_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  this_cpu_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * tlb_lld_1g ; 
 int /*<<< orphan*/ * tlb_lld_2m ; 
 int /*<<< orphan*/ * tlb_lld_4k ; 
 int /*<<< orphan*/ * tlb_lld_4m ; 
 int /*<<< orphan*/ * tlb_lli_2m ; 
 int /*<<< orphan*/ * tlb_lli_4k ; 
 int /*<<< orphan*/ * tlb_lli_4m ; 
 int /*<<< orphan*/  wrmsrl (int /*<<< orphan*/ ,scalar_t__) ; 

void check_mpx_erratum(struct cpuinfo_x86 *c)
{
	if (forcempx)
		return;
	/*
	 * Turn off the MPX feature on CPUs where SMEP is not
	 * available or disabled.
	 *
	 * Works around Intel Erratum SKD046: "Branch Instructions
	 * May Initialize MPX Bound Registers Incorrectly".
	 *
	 * This might falsely disable MPX on systems without
	 * SMEP, like Atom processors without SMEP.  But there
	 * is no such hardware known at the moment.
	 */
	if (cpu_has(c, X86_FEATURE_MPX) && !cpu_has(c, X86_FEATURE_SMEP)) {
		setup_clear_cpu_cap(X86_FEATURE_MPX);
		pr_warn("x86/mpx: Disabling MPX since SMEP not present\n");
	}
}

__attribute__((used)) static void probe_xeon_phi_r3mwait(struct cpuinfo_x86 *c)
{
	/*
	 * Ring 3 MONITOR/MWAIT feature cannot be detected without
	 * cpu model and family comparison.
	 */
	if (c->x86 != 6)
		return;
	switch (c->x86_model) {
	case INTEL_FAM6_XEON_PHI_KNL:
	case INTEL_FAM6_XEON_PHI_KNM:
		break;
	default:
		return;
	}

	if (ring3mwait_disabled)
		return;

	set_cpu_cap(c, X86_FEATURE_RING3MWAIT);
	this_cpu_or(msr_misc_features_shadow,
		    1UL << MSR_MISC_FEATURES_ENABLES_RING3MWAIT_BIT);

	if (c == &boot_cpu_data)
		ELF_HWCAP2 |= HWCAP2_RING3MWAIT;
}

__attribute__((used)) static bool bad_spectre_microcode(struct cpuinfo_x86 *c)
{
	int i;

	/*
	 * We know that the hypervisor lie to us on the microcode version so
	 * we may as well hope that it is running the correct version.
	 */
	if (cpu_has(c, X86_FEATURE_HYPERVISOR))
		return false;

	if (c->x86 != 6)
		return false;

	for (i = 0; i < ARRAY_SIZE(spectre_bad_microcodes); i++) {
		if (c->x86_model == spectre_bad_microcodes[i].model &&
		    c->x86_stepping == spectre_bad_microcodes[i].stepping)
			return (c->microcode <= spectre_bad_microcodes[i].microcode);
	}
	return false;
}

__attribute__((used)) static void early_init_intel(struct cpuinfo_x86 *c)
{
	u64 misc_enable;

	/* Unmask CPUID levels if masked: */
	if (c->x86 > 6 || (c->x86 == 6 && c->x86_model >= 0xd)) {
		if (msr_clear_bit(MSR_IA32_MISC_ENABLE,
				  MSR_IA32_MISC_ENABLE_LIMIT_CPUID_BIT) > 0) {
			c->cpuid_level = cpuid_eax(0);
			get_cpu_cap(c);
		}
	}

	if ((c->x86 == 0xf && c->x86_model >= 0x03) ||
		(c->x86 == 0x6 && c->x86_model >= 0x0e))
		set_cpu_cap(c, X86_FEATURE_CONSTANT_TSC);

	if (c->x86 >= 6 && !cpu_has(c, X86_FEATURE_IA64))
		c->microcode = intel_get_microcode_revision();

	/* Now if any of them are set, check the blacklist and clear the lot */
	if ((cpu_has(c, X86_FEATURE_SPEC_CTRL) ||
	     cpu_has(c, X86_FEATURE_INTEL_STIBP) ||
	     cpu_has(c, X86_FEATURE_IBRS) || cpu_has(c, X86_FEATURE_IBPB) ||
	     cpu_has(c, X86_FEATURE_STIBP)) && bad_spectre_microcode(c)) {
		pr_warn("Intel Spectre v2 broken microcode detected; disabling Speculation Control\n");
		setup_clear_cpu_cap(X86_FEATURE_IBRS);
		setup_clear_cpu_cap(X86_FEATURE_IBPB);
		setup_clear_cpu_cap(X86_FEATURE_STIBP);
		setup_clear_cpu_cap(X86_FEATURE_SPEC_CTRL);
		setup_clear_cpu_cap(X86_FEATURE_MSR_SPEC_CTRL);
		setup_clear_cpu_cap(X86_FEATURE_INTEL_STIBP);
		setup_clear_cpu_cap(X86_FEATURE_SSBD);
		setup_clear_cpu_cap(X86_FEATURE_SPEC_CTRL_SSBD);
	}

	/*
	 * Atom erratum AAE44/AAF40/AAG38/AAH41:
	 *
	 * A race condition between speculative fetches and invalidating
	 * a large page.  This is worked around in microcode, but we
	 * need the microcode to have already been loaded... so if it is
	 * not, recommend a BIOS update and disable large pages.
	 */
	if (c->x86 == 6 && c->x86_model == 0x1c && c->x86_stepping <= 2 &&
	    c->microcode < 0x20e) {
		pr_warn("Atom PSE erratum detected, BIOS microcode update recommended\n");
		clear_cpu_cap(c, X86_FEATURE_PSE);
	}

#ifdef CONFIG_X86_64
	set_cpu_cap(c, X86_FEATURE_SYSENTER32);
#else
	/* Netburst reports 64 bytes clflush size, but does IO in 128 bytes */
	if (c->x86 == 15 && c->x86_cache_alignment == 64)
		c->x86_cache_alignment = 128;
#endif

	/* CPUID workaround for 0F33/0F34 CPU */
	if (c->x86 == 0xF && c->x86_model == 0x3
	    && (c->x86_stepping == 0x3 || c->x86_stepping == 0x4))
		c->x86_phys_bits = 36;

	/*
	 * c->x86_power is 8000_0007 edx. Bit 8 is TSC runs at constant rate
	 * with P/T states and does not stop in deep C-states.
	 *
	 * It is also reliable across cores and sockets. (but not across
	 * cabinets - we turn it off in that case explicitly.)
	 */
	if (c->x86_power & (1 << 8)) {
		set_cpu_cap(c, X86_FEATURE_CONSTANT_TSC);
		set_cpu_cap(c, X86_FEATURE_NONSTOP_TSC);
	}

	/* Penwell and Cloverview have the TSC which doesn't sleep on S3 */
	if (c->x86 == 6) {
		switch (c->x86_model) {
		case 0x27:	/* Penwell */
		case 0x35:	/* Cloverview */
		case 0x4a:	/* Merrifield */
			set_cpu_cap(c, X86_FEATURE_NONSTOP_TSC_S3);
			break;
		default:
			break;
		}
	}

	/*
	 * There is a known erratum on Pentium III and Core Solo
	 * and Core Duo CPUs.
	 * " Page with PAT set to WC while associated MTRR is UC
	 *   may consolidate to UC "
	 * Because of this erratum, it is better to stick with
	 * setting WC in MTRR rather than using PAT on these CPUs.
	 *
	 * Enable PAT WC only on P4, Core 2 or later CPUs.
	 */
	if (c->x86 == 6 && c->x86_model < 15)
		clear_cpu_cap(c, X86_FEATURE_PAT);

	/*
	 * If fast string is not enabled in IA32_MISC_ENABLE for any reason,
	 * clear the fast string and enhanced fast string CPU capabilities.
	 */
	if (c->x86 > 6 || (c->x86 == 6 && c->x86_model >= 0xd)) {
		rdmsrl(MSR_IA32_MISC_ENABLE, misc_enable);
		if (!(misc_enable & MSR_IA32_MISC_ENABLE_FAST_STRING)) {
			pr_info("Disabled fast string operations\n");
			setup_clear_cpu_cap(X86_FEATURE_REP_GOOD);
			setup_clear_cpu_cap(X86_FEATURE_ERMS);
		}
	}

	/*
	 * Intel Quark Core DevMan_001.pdf section 6.4.11
	 * "The operating system also is required to invalidate (i.e., flush)
	 *  the TLB when any changes are made to any of the page table entries.
	 *  The operating system must reload CR3 to cause the TLB to be flushed"
	 *
	 * As a result, boot_cpu_has(X86_FEATURE_PGE) in arch/x86/include/asm/tlbflush.h
	 * should be false so that __flush_tlb_all() causes CR3 insted of CR4.PGE
	 * to be modified.
	 */
	if (c->x86 == 5 && c->x86_model == 9) {
		pr_info("Disabling PGE capability bit\n");
		setup_clear_cpu_cap(X86_FEATURE_PGE);
	}

	if (c->cpuid_level >= 0x00000001) {
		u32 eax, ebx, ecx, edx;

		cpuid(0x00000001, &eax, &ebx, &ecx, &edx);
		/*
		 * If HTT (EDX[28]) is set EBX[16:23] contain the number of
		 * apicids which are reserved per package. Store the resulting
		 * shift value for the package management code.
		 */
		if (edx & (1U << 28))
			c->x86_coreid_bits = get_count_order((ebx >> 16) & 0xff);
	}

	check_mpx_erratum(c);

	/*
	 * Get the number of SMT siblings early from the extended topology
	 * leaf, if available. Otherwise try the legacy SMT detection.
	 */
	if (detect_extended_topology_early(c) < 0)
		detect_ht_early(c);
}

__attribute__((used)) static void intel_workarounds(struct cpuinfo_x86 *c)
{
}

__attribute__((used)) static void srat_detect_node(struct cpuinfo_x86 *c)
{
#ifdef CONFIG_NUMA
	unsigned node;
	int cpu = smp_processor_id();

	/* Don't do the funky fallback heuristics the AMD version employs
	   for now. */
	node = numa_cpu_node(cpu);
	if (node == NUMA_NO_NODE || !node_online(node)) {
		/* reuse the value from init_cpu_to_node() */
		node = cpu_to_node(cpu);
	}
	numa_set_node(cpu, node);
#endif
}

__attribute__((used)) static void detect_vmx_virtcap(struct cpuinfo_x86 *c)
{
	/* Intel VMX MSR indicated features */
#define X86_VMX_FEATURE_PROC_CTLS_TPR_SHADOW	0x00200000
#define X86_VMX_FEATURE_PROC_CTLS_VNMI		0x00400000
#define X86_VMX_FEATURE_PROC_CTLS_2ND_CTLS	0x80000000
#define X86_VMX_FEATURE_PROC_CTLS2_VIRT_APIC	0x00000001
#define X86_VMX_FEATURE_PROC_CTLS2_EPT		0x00000002
#define X86_VMX_FEATURE_PROC_CTLS2_VPID		0x00000020
#define x86_VMX_FEATURE_EPT_CAP_AD		0x00200000

	u32 vmx_msr_low, vmx_msr_high, msr_ctl, msr_ctl2;
	u32 msr_vpid_cap, msr_ept_cap;

	clear_cpu_cap(c, X86_FEATURE_TPR_SHADOW);
	clear_cpu_cap(c, X86_FEATURE_VNMI);
	clear_cpu_cap(c, X86_FEATURE_FLEXPRIORITY);
	clear_cpu_cap(c, X86_FEATURE_EPT);
	clear_cpu_cap(c, X86_FEATURE_VPID);
	clear_cpu_cap(c, X86_FEATURE_EPT_AD);

	rdmsr(MSR_IA32_VMX_PROCBASED_CTLS, vmx_msr_low, vmx_msr_high);
	msr_ctl = vmx_msr_high | vmx_msr_low;
	if (msr_ctl & X86_VMX_FEATURE_PROC_CTLS_TPR_SHADOW)
		set_cpu_cap(c, X86_FEATURE_TPR_SHADOW);
	if (msr_ctl & X86_VMX_FEATURE_PROC_CTLS_VNMI)
		set_cpu_cap(c, X86_FEATURE_VNMI);
	if (msr_ctl & X86_VMX_FEATURE_PROC_CTLS_2ND_CTLS) {
		rdmsr(MSR_IA32_VMX_PROCBASED_CTLS2,
		      vmx_msr_low, vmx_msr_high);
		msr_ctl2 = vmx_msr_high | vmx_msr_low;
		if ((msr_ctl2 & X86_VMX_FEATURE_PROC_CTLS2_VIRT_APIC) &&
		    (msr_ctl & X86_VMX_FEATURE_PROC_CTLS_TPR_SHADOW))
			set_cpu_cap(c, X86_FEATURE_FLEXPRIORITY);
		if (msr_ctl2 & X86_VMX_FEATURE_PROC_CTLS2_EPT) {
			set_cpu_cap(c, X86_FEATURE_EPT);
			rdmsr(MSR_IA32_VMX_EPT_VPID_CAP,
			      msr_ept_cap, msr_vpid_cap);
			if (msr_ept_cap & x86_VMX_FEATURE_EPT_CAP_AD)
				set_cpu_cap(c, X86_FEATURE_EPT_AD);
		}
		if (msr_ctl2 & X86_VMX_FEATURE_PROC_CTLS2_VPID)
			set_cpu_cap(c, X86_FEATURE_VPID);
	}
}

__attribute__((used)) static void detect_tme(struct cpuinfo_x86 *c)
{
	u64 tme_activate, tme_policy, tme_crypto_algs;
	int keyid_bits = 0, nr_keyids = 0;
	static u64 tme_activate_cpu0 = 0;

	rdmsrl(MSR_IA32_TME_ACTIVATE, tme_activate);

	if (mktme_status != MKTME_UNINITIALIZED) {
		if (tme_activate != tme_activate_cpu0) {
			/* Broken BIOS? */
			pr_err_once("x86/tme: configuration is inconsistent between CPUs\n");
			pr_err_once("x86/tme: MKTME is not usable\n");
			mktme_status = MKTME_DISABLED;

			/* Proceed. We may need to exclude bits from x86_phys_bits. */
		}
	} else {
		tme_activate_cpu0 = tme_activate;
	}

	if (!TME_ACTIVATE_LOCKED(tme_activate) || !TME_ACTIVATE_ENABLED(tme_activate)) {
		pr_info_once("x86/tme: not enabled by BIOS\n");
		mktme_status = MKTME_DISABLED;
		return;
	}

	if (mktme_status != MKTME_UNINITIALIZED)
		goto detect_keyid_bits;

	pr_info("x86/tme: enabled by BIOS\n");

	tme_policy = TME_ACTIVATE_POLICY(tme_activate);
	if (tme_policy != TME_ACTIVATE_POLICY_AES_XTS_128)
		pr_warn("x86/tme: Unknown policy is active: %#llx\n", tme_policy);

	tme_crypto_algs = TME_ACTIVATE_CRYPTO_ALGS(tme_activate);
	if (!(tme_crypto_algs & TME_ACTIVATE_CRYPTO_AES_XTS_128)) {
		pr_err("x86/mktme: No known encryption algorithm is supported: %#llx\n",
				tme_crypto_algs);
		mktme_status = MKTME_DISABLED;
	}
detect_keyid_bits:
	keyid_bits = TME_ACTIVATE_KEYID_BITS(tme_activate);
	nr_keyids = (1UL << keyid_bits) - 1;
	if (nr_keyids) {
		pr_info_once("x86/mktme: enabled by BIOS\n");
		pr_info_once("x86/mktme: %d KeyIDs available\n", nr_keyids);
	} else {
		pr_info_once("x86/mktme: disabled by BIOS\n");
	}

	if (mktme_status == MKTME_UNINITIALIZED) {
		/* MKTME is usable */
		mktme_status = MKTME_ENABLED;
	}

	/*
	 * KeyID bits effectively lower the number of physical address
	 * bits.  Update cpuinfo_x86::x86_phys_bits accordingly.
	 */
	c->x86_phys_bits -= keyid_bits;
}

__attribute__((used)) static void init_intel_energy_perf(struct cpuinfo_x86 *c)
{
	u64 epb;

	/*
	 * Initialize MSR_IA32_ENERGY_PERF_BIAS if not already initialized.
	 * (x86_energy_perf_policy(8) is available to change it at run-time.)
	 */
	if (!cpu_has(c, X86_FEATURE_EPB))
		return;

	rdmsrl(MSR_IA32_ENERGY_PERF_BIAS, epb);
	if ((epb & 0xF) != ENERGY_PERF_BIAS_PERFORMANCE)
		return;

	pr_warn_once("ENERGY_PERF_BIAS: Set to 'normal', was 'performance'\n");
	pr_warn_once("ENERGY_PERF_BIAS: View and update with x86_energy_perf_policy(8)\n");
	epb = (epb & ~0xF) | ENERGY_PERF_BIAS_NORMAL;
	wrmsrl(MSR_IA32_ENERGY_PERF_BIAS, epb);
}

__attribute__((used)) static void intel_bsp_resume(struct cpuinfo_x86 *c)
{
	/*
	 * MSR_IA32_ENERGY_PERF_BIAS is lost across suspend/resume,
	 * so reinitialize it properly like during bootup:
	 */
	init_intel_energy_perf(c);
}

__attribute__((used)) static void init_cpuid_fault(struct cpuinfo_x86 *c)
{
	u64 msr;

	if (!rdmsrl_safe(MSR_PLATFORM_INFO, &msr)) {
		if (msr & MSR_PLATFORM_INFO_CPUID_FAULT)
			set_cpu_cap(c, X86_FEATURE_CPUID_FAULT);
	}
}

__attribute__((used)) static void init_intel_misc_features(struct cpuinfo_x86 *c)
{
	u64 msr;

	if (rdmsrl_safe(MSR_MISC_FEATURES_ENABLES, &msr))
		return;

	/* Clear all MISC features */
	this_cpu_write(msr_misc_features_shadow, 0);

	/* Check features and update capabilities and shadow control bits */
	init_cpuid_fault(c);
	probe_xeon_phi_r3mwait(c);

	msr = this_cpu_read(msr_misc_features_shadow);
	wrmsrl(MSR_MISC_FEATURES_ENABLES, msr);
}

__attribute__((used)) static void init_intel(struct cpuinfo_x86 *c)
{
	early_init_intel(c);

	intel_workarounds(c);

	/*
	 * Detect the extended topology information if available. This
	 * will reinitialise the initial_apicid which will be used
	 * in init_intel_cacheinfo()
	 */
	detect_extended_topology(c);

	if (!cpu_has(c, X86_FEATURE_XTOPOLOGY)) {
		/*
		 * let's use the legacy cpuid vector 0x1 and 0x4 for topology
		 * detection.
		 */
		detect_num_cpu_cores(c);
#ifdef CONFIG_X86_32
		detect_ht(c);
#endif
	}

	init_intel_cacheinfo(c);

	if (c->cpuid_level > 9) {
		unsigned eax = cpuid_eax(10);
		/* Check for version and the number of counters */
		if ((eax & 0xff) && (((eax>>8) & 0xff) > 1))
			set_cpu_cap(c, X86_FEATURE_ARCH_PERFMON);
	}

	if (cpu_has(c, X86_FEATURE_XMM2))
		set_cpu_cap(c, X86_FEATURE_LFENCE_RDTSC);

	if (boot_cpu_has(X86_FEATURE_DS)) {
		unsigned int l1, l2;

		rdmsr(MSR_IA32_MISC_ENABLE, l1, l2);
		if (!(l1 & (1<<11)))
			set_cpu_cap(c, X86_FEATURE_BTS);
		if (!(l1 & (1<<12)))
			set_cpu_cap(c, X86_FEATURE_PEBS);
	}

	if (c->x86 == 6 && boot_cpu_has(X86_FEATURE_CLFLUSH) &&
	    (c->x86_model == 29 || c->x86_model == 46 || c->x86_model == 47))
		set_cpu_bug(c, X86_BUG_CLFLUSH_MONITOR);

	if (c->x86 == 6 && boot_cpu_has(X86_FEATURE_MWAIT) &&
		((c->x86_model == INTEL_FAM6_ATOM_GOLDMONT)))
		set_cpu_bug(c, X86_BUG_MONITOR);

#ifdef CONFIG_X86_64
	if (c->x86 == 15)
		c->x86_cache_alignment = c->x86_clflush_size * 2;
	if (c->x86 == 6)
		set_cpu_cap(c, X86_FEATURE_REP_GOOD);
#else
	/*
	 * Names for the Pentium II/Celeron processors
	 * detectable only by also checking the cache size.
	 * Dixon is NOT a Celeron.
	 */
	if (c->x86 == 6) {
		unsigned int l2 = c->x86_cache_size;
		char *p = NULL;

		switch (c->x86_model) {
		case 5:
			if (l2 == 0)
				p = "Celeron (Covington)";
			else if (l2 == 256)
				p = "Mobile Pentium II (Dixon)";
			break;

		case 6:
			if (l2 == 128)
				p = "Celeron (Mendocino)";
			else if (c->x86_stepping == 0 || c->x86_stepping == 5)
				p = "Celeron-A";
			break;

		case 8:
			if (l2 == 128)
				p = "Celeron (Coppermine)";
			break;
		}

		if (p)
			strcpy(c->x86_model_id, p);
	}

	if (c->x86 == 15)
		set_cpu_cap(c, X86_FEATURE_P4);
	if (c->x86 == 6)
		set_cpu_cap(c, X86_FEATURE_P3);
#endif

	/* Work around errata */
	srat_detect_node(c);

	if (cpu_has(c, X86_FEATURE_VMX))
		detect_vmx_virtcap(c);

	if (cpu_has(c, X86_FEATURE_TME))
		detect_tme(c);

	init_intel_energy_perf(c);

	init_intel_misc_features(c);
}

__attribute__((used)) static void intel_tlb_lookup(const unsigned char desc)
{
	unsigned char k;
	if (desc == 0)
		return;

	/* look up this descriptor in the table */
	for (k = 0; intel_tlb_table[k].descriptor != desc && \
			intel_tlb_table[k].descriptor != 0; k++)
		;

	if (intel_tlb_table[k].tlb_type == 0)
		return;

	switch (intel_tlb_table[k].tlb_type) {
	case STLB_4K:
		if (tlb_lli_4k[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_4k[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lld_4k[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_4k[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case STLB_4K_2M:
		if (tlb_lli_4k[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_4k[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lld_4k[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_4k[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lli_2m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_2m[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lld_2m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_2m[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lli_4m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_4m[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lld_4m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_4m[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_INST_ALL:
		if (tlb_lli_4k[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_4k[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lli_2m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_2m[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lli_4m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_4m[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_INST_4K:
		if (tlb_lli_4k[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_4k[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_INST_4M:
		if (tlb_lli_4m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_4m[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_INST_2M_4M:
		if (tlb_lli_2m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_2m[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lli_4m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lli_4m[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_DATA_4K:
	case TLB_DATA0_4K:
		if (tlb_lld_4k[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_4k[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_DATA_4M:
	case TLB_DATA0_4M:
		if (tlb_lld_4m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_4m[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_DATA_2M_4M:
	case TLB_DATA0_2M_4M:
		if (tlb_lld_2m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_2m[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lld_4m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_4m[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_DATA_4K_4M:
		if (tlb_lld_4k[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_4k[ENTRIES] = intel_tlb_table[k].entries;
		if (tlb_lld_4m[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_4m[ENTRIES] = intel_tlb_table[k].entries;
		break;
	case TLB_DATA_1G:
		if (tlb_lld_1g[ENTRIES] < intel_tlb_table[k].entries)
			tlb_lld_1g[ENTRIES] = intel_tlb_table[k].entries;
		break;
	}
}

__attribute__((used)) static void intel_detect_tlb(struct cpuinfo_x86 *c)
{
	int i, j, n;
	unsigned int regs[4];
	unsigned char *desc = (unsigned char *)regs;

	if (c->cpuid_level < 2)
		return;

	/* Number of times to iterate */
	n = cpuid_eax(2) & 0xFF;

	for (i = 0 ; i < n ; i++) {
		cpuid(2, &regs[0], &regs[1], &regs[2], &regs[3]);

		/* If bit 31 is set, this is an unknown format */
		for (j = 0 ; j < 3 ; j++)
			if (regs[j] & (1 << 31))
				regs[j] = 0;

		/* Byte 0 is level count, not a descriptor */
		for (j = 1 ; j < 16 ; j++)
			intel_tlb_lookup(desc[j]);
	}
}

