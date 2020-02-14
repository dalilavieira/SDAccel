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
typedef  int u64 ;
struct op_system_config {unsigned int mmcr0; unsigned int mmcr1; unsigned long mmcra; scalar_t__ enable_user; scalar_t__ enable_kernel; } ;
struct op_counter_config {scalar_t__ enabled; scalar_t__ count; } ;
struct TYPE_2__ {int num_pmcs; } ;

/* Variables and functions */
 unsigned int MMCR0_FC ; 
 unsigned int MMCR0_FCECE ; 
 unsigned int MMCR0_FCM1 ; 
 unsigned int MMCR0_KERNEL_DISABLE ; 
 unsigned int MMCR0_PMAO ; 
 unsigned int MMCR0_PMC1CE ; 
 unsigned int MMCR0_PMCjCE ; 
 unsigned int MMCR0_PMXE ; 
 unsigned int MMCR0_PROBLEM_DISABLE ; 
 unsigned long MMCRA_SAMPLE_ENABLE ; 
 int MSR_PMM ; 
 int OPROFILE_MAX_PMC_NUM ; 
 int OPROFILE_PMSEL_FIELD_WIDTH ; 
 int OPROFILE_PM_PMCSEL_MSK ; 
 int OPROFILE_PM_UNIT_MSK ; 
 int OPROFILE_PM_UNIT_SHIFT ; 
 int /*<<< orphan*/  PVR_970 ; 
 int /*<<< orphan*/  PVR_970FX ; 
 int /*<<< orphan*/  PVR_970GX ; 
 int /*<<< orphan*/  PVR_970MP ; 
 int /*<<< orphan*/  PVR_POWER4 ; 
 int /*<<< orphan*/  PVR_POWER4p ; 
 int /*<<< orphan*/  PVR_POWER5 ; 
 int /*<<< orphan*/  PVR_POWER5p ; 
 int /*<<< orphan*/  PVR_POWER7p ; 
 int /*<<< orphan*/  SPRN_MMCR0 ; 
 int /*<<< orphan*/  SPRN_MMCR1 ; 
 int /*<<< orphan*/  SPRN_MMCRA ; 
 int /*<<< orphan*/  classic_ctr_write (int,scalar_t__) ; 
 int cntr_marked_events ; 
 TYPE_1__* cur_cpu_spec ; 
 int /*<<< orphan*/  dbg (char*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  mb () ; 
 int mfmsr () ; 
 unsigned int mfspr (int /*<<< orphan*/ ) ; 
 unsigned int mmcr0_val ; 
 unsigned int mmcr1_val ; 
 unsigned long mmcra_val ; 
 int /*<<< orphan*/  mtmsr (int) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,unsigned int) ; 
 int oprofile_running ; 
 int /*<<< orphan*/  ppc_enable_pmcs () ; 
 scalar_t__ pvr_version_is (int /*<<< orphan*/ ) ; 
 scalar_t__* reset_value ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int use_slot_nums ; 

__attribute__((used)) static int power7_marked_instr_event(u64 mmcr1)
{
	u64 psel, unit;
	int pmc, cntr_marked_events = 0;

	/* Given the MMCR1 value, look at the field for each counter to
	 * determine if it is a marked event.  Code based on the function
	 * power7_marked_instr_event() in file arch/powerpc/perf/power7-pmu.c.
	 */
	for (pmc = 0; pmc < 4; pmc++) {
		psel = mmcr1 & (OPROFILE_PM_PMCSEL_MSK
				<< (OPROFILE_MAX_PMC_NUM - pmc)
				* OPROFILE_PMSEL_FIELD_WIDTH);
		psel = (psel >> ((OPROFILE_MAX_PMC_NUM - pmc)
				 * OPROFILE_PMSEL_FIELD_WIDTH)) & ~1ULL;
		unit = mmcr1 & (OPROFILE_PM_UNIT_MSK
				<< (OPROFILE_PM_UNIT_SHIFT
				    - (pmc * OPROFILE_PMSEL_FIELD_WIDTH )));
		unit = unit >> (OPROFILE_PM_UNIT_SHIFT
				- (pmc * OPROFILE_PMSEL_FIELD_WIDTH));

		switch (psel >> 4) {
		case 2:
			cntr_marked_events |= (pmc == 1 || pmc == 3) << pmc;
			break;
		case 3:
			if (psel == 0x3c) {
				cntr_marked_events |= (pmc == 0) << pmc;
				break;
			}

			if (psel == 0x3e) {
				cntr_marked_events |= (pmc != 1) << pmc;
				break;
			}

			cntr_marked_events |= 1 << pmc;
			break;
		case 4:
		case 5:
			cntr_marked_events |= (unit == 0xd) << pmc;
			break;
		case 6:
			if (psel == 0x64)
				cntr_marked_events |= (pmc >= 2) << pmc;
			break;
		case 8:
			cntr_marked_events |= (unit == 0xd) << pmc;
			break;
		}
	}
	return cntr_marked_events;
}

__attribute__((used)) static int power4_reg_setup(struct op_counter_config *ctr,
			     struct op_system_config *sys,
			     int num_ctrs)
{
	int i;

	/*
	 * The performance counter event settings are given in the mmcr0,
	 * mmcr1 and mmcra values passed from the user in the
	 * op_system_config structure (sys variable).
	 */
	mmcr0_val = sys->mmcr0;
	mmcr1_val = sys->mmcr1;
	mmcra_val = sys->mmcra;

	/* Power 7+ and newer architectures:
	 * Determine which counter events in the group (the group of events is
	 * specified by the bit settings in the MMCR1 register) are marked
	 * events for use in the interrupt handler.  Do the calculation once
	 * before OProfile starts.  Information is used in the interrupt
	 * handler.  Starting with Power 7+ we only record the sample for
	 * marked events if the SIAR valid bit is set.  For non marked events
	 * the sample is always recorded.
	 */
	if (pvr_version_is(PVR_POWER7p))
		cntr_marked_events = power7_marked_instr_event(mmcr1_val);
	else
		cntr_marked_events = 0; /* For older processors, set the bit map
					 * to zero so the sample will always be
					 * be recorded.
					 */

	for (i = 0; i < cur_cpu_spec->num_pmcs; ++i)
		reset_value[i] = 0x80000000UL - ctr[i].count;

	/* setup user and kernel profiling */
	if (sys->enable_kernel)
		mmcr0_val &= ~MMCR0_KERNEL_DISABLE;
	else
		mmcr0_val |= MMCR0_KERNEL_DISABLE;

	if (sys->enable_user)
		mmcr0_val &= ~MMCR0_PROBLEM_DISABLE;
	else
		mmcr0_val |= MMCR0_PROBLEM_DISABLE;

	if (pvr_version_is(PVR_POWER4) || pvr_version_is(PVR_POWER4p) ||
	    pvr_version_is(PVR_970) || pvr_version_is(PVR_970FX) ||
	    pvr_version_is(PVR_970MP) || pvr_version_is(PVR_970GX) ||
	    pvr_version_is(PVR_POWER5) || pvr_version_is(PVR_POWER5p))
		use_slot_nums = 1;

	return 0;
}

__attribute__((used)) static inline int mmcra_must_set_sample(void)
{
	if (pvr_version_is(PVR_POWER4) || pvr_version_is(PVR_POWER4p) ||
	    pvr_version_is(PVR_970) || pvr_version_is(PVR_970FX) ||
	    pvr_version_is(PVR_970MP) || pvr_version_is(PVR_970GX))
		return 1;

	return 0;
}

__attribute__((used)) static int power4_cpu_setup(struct op_counter_config *ctr)
{
	unsigned int mmcr0 = mmcr0_val;
	unsigned long mmcra = mmcra_val;

	ppc_enable_pmcs();

	/* set the freeze bit */
	mmcr0 |= MMCR0_FC;
	mtspr(SPRN_MMCR0, mmcr0);

	mmcr0 |= MMCR0_FCM1|MMCR0_PMXE|MMCR0_FCECE;
	mmcr0 |= MMCR0_PMC1CE|MMCR0_PMCjCE;
	mtspr(SPRN_MMCR0, mmcr0);

	mtspr(SPRN_MMCR1, mmcr1_val);

	if (mmcra_must_set_sample())
		mmcra |= MMCRA_SAMPLE_ENABLE;
	mtspr(SPRN_MMCRA, mmcra);

	dbg("setup on cpu %d, mmcr0 %lx\n", smp_processor_id(),
	    mfspr(SPRN_MMCR0));
	dbg("setup on cpu %d, mmcr1 %lx\n", smp_processor_id(),
	    mfspr(SPRN_MMCR1));
	dbg("setup on cpu %d, mmcra %lx\n", smp_processor_id(),
	    mfspr(SPRN_MMCRA));

	return 0;
}

__attribute__((used)) static int power4_start(struct op_counter_config *ctr)
{
	int i;
	unsigned int mmcr0;

	/* set the PMM bit (see comment below) */
	mtmsr(mfmsr() | MSR_PMM);

	for (i = 0; i < cur_cpu_spec->num_pmcs; ++i) {
		if (ctr[i].enabled) {
			classic_ctr_write(i, reset_value[i]);
		} else {
			classic_ctr_write(i, 0);
		}
	}

	mmcr0 = mfspr(SPRN_MMCR0);

	/*
	 * We must clear the PMAO bit on some (GQ) chips. Just do it
	 * all the time
	 */
	mmcr0 &= ~MMCR0_PMAO;

	/*
	 * now clear the freeze bit, counting will not start until we
	 * rfid from this excetion, because only at that point will
	 * the PMM bit be cleared
	 */
	mmcr0 &= ~MMCR0_FC;
	mtspr(SPRN_MMCR0, mmcr0);

	oprofile_running = 1;

	dbg("start on cpu %d, mmcr0 %x\n", smp_processor_id(), mmcr0);
	return 0;
}

__attribute__((used)) static void power4_stop(void)
{
	unsigned int mmcr0;

	/* freeze counters */
	mmcr0 = mfspr(SPRN_MMCR0);
	mmcr0 |= MMCR0_FC;
	mtspr(SPRN_MMCR0, mmcr0);

	oprofile_running = 0;

	dbg("stop on cpu %d, mmcr0 %x\n", smp_processor_id(), mmcr0);

	mb();
}

