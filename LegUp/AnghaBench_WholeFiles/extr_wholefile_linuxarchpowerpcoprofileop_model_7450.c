#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u32 ;
struct pt_regs {int dummy; } ;
struct op_system_config {scalar_t__ enable_user; scalar_t__ enable_kernel; } ;
struct op_counter_config {scalar_t__ enabled; int /*<<< orphan*/  event; scalar_t__ count; } ;

/* Variables and functions */
 int MMCR0_FC ; 
 int MMCR0_FCECE ; 
 int MMCR0_FCM0 ; 
 int MMCR0_FCP ; 
 int MMCR0_FCS ; 
 int MMCR0_INIT ; 
 int MMCR0_PMC1CE ; 
 int MMCR0_PMCnCE ; 
 int MMCR0_PMXE ; 
 int MSR_PMM ; 
 int /*<<< orphan*/  SPRN_MMCR0 ; 
 int /*<<< orphan*/  SPRN_MMCR1 ; 
 int /*<<< orphan*/  SPRN_MMCR2 ; 
 int /*<<< orphan*/  SPRN_SIAR ; 
 int classic_ctr_read (int) ; 
 int /*<<< orphan*/  classic_ctr_write (int,scalar_t__) ; 
 int is_kernel_addr (unsigned long) ; 
 int /*<<< orphan*/  mb () ; 
 int mfmsr () ; 
 void* mfspr (int /*<<< orphan*/ ) ; 
 int mmcr0_event1 (int /*<<< orphan*/ ) ; 
 int mmcr0_event2 (int /*<<< orphan*/ ) ; 
 int mmcr0_val ; 
 int mmcr1_event3 (int /*<<< orphan*/ ) ; 
 int mmcr1_event4 (int /*<<< orphan*/ ) ; 
 int mmcr1_event5 (int /*<<< orphan*/ ) ; 
 int mmcr1_event6 (int /*<<< orphan*/ ) ; 
 int mmcr1_val ; 
 int mmcr2_val ; 
 int /*<<< orphan*/  mtmsr (int) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int num_pmcs ; 
 int /*<<< orphan*/  oprofile_add_ext_sample (unsigned long,struct pt_regs*,int,int) ; 
 int oprofile_running ; 
 scalar_t__* reset_value ; 

__attribute__((used)) static void pmc_start_ctrs(void)
{
	u32 mmcr0 = mfspr(SPRN_MMCR0);

	mmcr0 &= ~(MMCR0_FC | MMCR0_FCM0);
	mmcr0 |= (MMCR0_FCECE | MMCR0_PMC1CE | MMCR0_PMCnCE | MMCR0_PMXE);

	mtspr(SPRN_MMCR0, mmcr0);
}

__attribute__((used)) static void pmc_stop_ctrs(void)
{
	u32 mmcr0 = mfspr(SPRN_MMCR0);

	mmcr0 |= MMCR0_FC;
	mmcr0 &= ~(MMCR0_FCECE | MMCR0_PMC1CE | MMCR0_PMCnCE | MMCR0_PMXE);

	mtspr(SPRN_MMCR0, mmcr0);
}

__attribute__((used)) static int fsl7450_cpu_setup(struct op_counter_config *ctr)
{
	/* freeze all counters */
	pmc_stop_ctrs();

	mtspr(SPRN_MMCR0, mmcr0_val);
	mtspr(SPRN_MMCR1, mmcr1_val);
	if (num_pmcs > 4)
		mtspr(SPRN_MMCR2, mmcr2_val);

	return 0;
}

__attribute__((used)) static int fsl7450_reg_setup(struct op_counter_config *ctr,
			     struct op_system_config *sys,
			     int num_ctrs)
{
	int i;

	num_pmcs = num_ctrs;
	/* Our counters count up, and "count" refers to
	 * how much before the next interrupt, and we interrupt
	 * on overflow.  So we calculate the starting value
	 * which will give us "count" until overflow.
	 * Then we set the events on the enabled counters */
	for (i = 0; i < num_ctrs; ++i)
		reset_value[i] = 0x80000000UL - ctr[i].count;

	/* Set events for Counters 1 & 2 */
	mmcr0_val = MMCR0_INIT | mmcr0_event1(ctr[0].event)
		| mmcr0_event2(ctr[1].event);

	/* Setup user/kernel bits */
	if (sys->enable_kernel)
		mmcr0_val &= ~(MMCR0_FCS);

	if (sys->enable_user)
		mmcr0_val &= ~(MMCR0_FCP);

	/* Set events for Counters 3-6 */
	mmcr1_val = mmcr1_event3(ctr[2].event)
		| mmcr1_event4(ctr[3].event);
	if (num_ctrs > 4)
		mmcr1_val |= mmcr1_event5(ctr[4].event)
			| mmcr1_event6(ctr[5].event);

	mmcr2_val = 0;

	return 0;
}

__attribute__((used)) static int fsl7450_start(struct op_counter_config *ctr)
{
	int i;

	mtmsr(mfmsr() | MSR_PMM);

	for (i = 0; i < num_pmcs; ++i) {
		if (ctr[i].enabled)
			classic_ctr_write(i, reset_value[i]);
		else
			classic_ctr_write(i, 0);
	}

	/* Clear the freeze bit, and enable the interrupt.
	 * The counters won't actually start until the rfi clears
	 * the PMM bit */
	pmc_start_ctrs();

	oprofile_running = 1;

	return 0;
}

__attribute__((used)) static void fsl7450_stop(void)
{
	/* freeze counters */
	pmc_stop_ctrs();

	oprofile_running = 0;

	mb();
}

__attribute__((used)) static void fsl7450_handle_interrupt(struct pt_regs *regs,
				    struct op_counter_config *ctr)
{
	unsigned long pc;
	int is_kernel;
	int val;
	int i;

	/* set the PMM bit (see comment below) */
	mtmsr(mfmsr() | MSR_PMM);

	pc = mfspr(SPRN_SIAR);
	is_kernel = is_kernel_addr(pc);

	for (i = 0; i < num_pmcs; ++i) {
		val = classic_ctr_read(i);
		if (val < 0) {
			if (oprofile_running && ctr[i].enabled) {
				oprofile_add_ext_sample(pc, regs, i, is_kernel);
				classic_ctr_write(i, reset_value[i]);
			} else {
				classic_ctr_write(i, 0);
			}
		}
	}

	/* The freeze bit was set by the interrupt. */
	/* Clear the freeze bit, and reenable the interrupt.
	 * The counters won't actually start until the rfi clears
	 * the PM/M bit */
	pmc_start_ctrs();
}

