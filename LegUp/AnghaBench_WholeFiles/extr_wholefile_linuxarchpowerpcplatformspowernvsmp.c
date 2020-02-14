#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
struct TYPE_2__ {scalar_t__ cpu_start; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_FTR_ARCH_207S ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  FW_FEATURE_OPAL ; 
 long OPAL_SUCCESS ; 
 scalar_t__ OPAL_THREAD_INACTIVE ; 
 scalar_t__ OPAL_THREAD_STARTED ; 
 int PPC_BIT (int) ; 
 int /*<<< orphan*/  PVR_POWER9 ; 
 int /*<<< orphan*/  SPRN_HMEER ; 
 unsigned long __pa (int /*<<< orphan*/ ) ; 
 int boot_cpuid ; 
 scalar_t__ cpu_has_feature (int /*<<< orphan*/ ) ; 
 scalar_t__ doorbell_try_core_ipi (int) ; 
 int /*<<< orphan*/  firmware_has_feature (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  generic_secondary_smp_init ; 
 unsigned int get_hard_smp_processor_id (int) ; 
 int /*<<< orphan*/  ic_cause_ipi (int) ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int nr_cpu_ids ; 
 long opal_query_cpu_status (unsigned int,scalar_t__*) ; 
 long opal_start_cpu (unsigned int,unsigned long) ; 
 TYPE_1__** paca_ptrs ; 
 int /*<<< orphan*/  ppc_function_entry (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_devel (char*,int,unsigned int,...) ; 
 int /*<<< orphan*/  pr_warn (char*,long,int) ; 
 scalar_t__ pvr_version_is (int /*<<< orphan*/ ) ; 
 int smp_generic_cpu_bootable (unsigned int) ; 
 int smp_generic_kick_cpu (int) ; 
 int /*<<< orphan*/  xics_setup_cpu () ; 
 scalar_t__ xive_enabled () ; 
 int xive_smp_prepare_cpu (int) ; 
 int /*<<< orphan*/  xive_smp_setup_cpu () ; 

__attribute__((used)) static inline void pnv_smp_init(void) { }

__attribute__((used)) static inline void pnv_pci_init(void) { }

__attribute__((used)) static inline void pnv_pci_shutdown(void) { }

__attribute__((used)) static void pnv_smp_setup_cpu(int cpu)
{
	/*
	 * P9 workaround for CI vector load (see traps.c),
	 * enable the corresponding HMI interrupt
	 */
	if (pvr_version_is(PVR_POWER9))
		mtspr(SPRN_HMEER, mfspr(SPRN_HMEER) | PPC_BIT(17));

	if (xive_enabled())
		xive_smp_setup_cpu();
	else if (cpu != boot_cpuid)
		xics_setup_cpu();
}

__attribute__((used)) static int pnv_smp_kick_cpu(int nr)
{
	unsigned int pcpu;
	unsigned long start_here =
			__pa(ppc_function_entry(generic_secondary_smp_init));
	long rc;
	uint8_t status;

	if (nr < 0 || nr >= nr_cpu_ids)
		return -EINVAL;

	pcpu = get_hard_smp_processor_id(nr);
	/*
	 * If we already started or OPAL is not supported, we just
	 * kick the CPU via the PACA
	 */
	if (paca_ptrs[nr]->cpu_start || !firmware_has_feature(FW_FEATURE_OPAL))
		goto kick;

	/*
	 * At this point, the CPU can either be spinning on the way in
	 * from kexec or be inside OPAL waiting to be started for the
	 * first time. OPAL v3 allows us to query OPAL to know if it
	 * has the CPUs, so we do that
	 */
	rc = opal_query_cpu_status(pcpu, &status);
	if (rc != OPAL_SUCCESS) {
		pr_warn("OPAL Error %ld querying CPU %d state\n", rc, nr);
		return -ENODEV;
	}

	/*
	 * Already started, just kick it, probably coming from
	 * kexec and spinning
	 */
	if (status == OPAL_THREAD_STARTED)
		goto kick;

	/*
	 * Available/inactive, let's kick it
	 */
	if (status == OPAL_THREAD_INACTIVE) {
		pr_devel("OPAL: Starting CPU %d (HW 0x%x)...\n", nr, pcpu);
		rc = opal_start_cpu(pcpu, start_here);
		if (rc != OPAL_SUCCESS) {
			pr_warn("OPAL Error %ld starting CPU %d\n", rc, nr);
			return -ENODEV;
		}
	} else {
		/*
		 * An unavailable CPU (or any other unknown status)
		 * shouldn't be started. It should also
		 * not be in the possible map but currently it can
		 * happen
		 */
		pr_devel("OPAL: CPU %d (HW 0x%x) is unavailable"
			 " (status %d)...\n", nr, pcpu, status);
		return -ENODEV;
	}

kick:
	return smp_generic_kick_cpu(nr);
}

__attribute__((used)) static int pnv_cpu_bootable(unsigned int nr)
{
	/*
	 * Starting with POWER8, the subcore logic relies on all threads of a
	 * core being booted so that they can participate in split mode
	 * switches. So on those machines we ignore the smt_enabled_at_boot
	 * setting (smt-enabled on the kernel command line).
	 */
	if (cpu_has_feature(CPU_FTR_ARCH_207S))
		return 1;

	return smp_generic_cpu_bootable(nr);
}

__attribute__((used)) static int pnv_smp_prepare_cpu(int cpu)
{
	if (xive_enabled())
		return xive_smp_prepare_cpu(cpu);
	return 0;
}

__attribute__((used)) static void pnv_cause_ipi(int cpu)
{
	if (doorbell_try_core_ipi(cpu))
		return;

	ic_cause_ipi(cpu);
}

