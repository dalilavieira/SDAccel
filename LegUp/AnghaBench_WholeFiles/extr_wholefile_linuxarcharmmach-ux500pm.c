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

/* Variables and functions */
 scalar_t__ GIC_DIST_ENABLE_SET ; 
 scalar_t__ GIC_DIST_PENDING_SET ; 
 int PRCMU_GIC_NUMBER_REGS ; 
 scalar_t__ PRCM_A9_MASK_REQ ; 
 int PRCM_A9_MASK_REQ_PRCM_A9_MASK_REQ ; 
 scalar_t__ PRCM_ARMITMSK31TO0 ; 
 scalar_t__ PRCM_ARMITVAL31TO0 ; 
 scalar_t__ PRCM_ARM_WFI_STANDBY ; 
 int PRCM_ARM_WFI_STANDBY_WFI0 ; 
 int PRCM_ARM_WFI_STANDBY_WFI1 ; 
 scalar_t__ dist_base ; 
 int readl (scalar_t__) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

int prcmu_gic_decouple(void)
{
	u32 val = readl(PRCM_A9_MASK_REQ);

	/* Set bit 0 register value to 1 */
	writel(val | PRCM_A9_MASK_REQ_PRCM_A9_MASK_REQ,
	       PRCM_A9_MASK_REQ);

	/* Make sure the register is updated */
	readl(PRCM_A9_MASK_REQ);

	/* Wait a few cycles for the gic mask completion */
	udelay(1);

	return 0;
}

int prcmu_gic_recouple(void)
{
	u32 val = readl(PRCM_A9_MASK_REQ);

	/* Set bit 0 register value to 0 */
	writel(val & ~PRCM_A9_MASK_REQ_PRCM_A9_MASK_REQ, PRCM_A9_MASK_REQ);

	return 0;
}

bool prcmu_gic_pending_irq(void)
{
	u32 pr; /* Pending register */
	u32 er; /* Enable register */
	int i;

	/* 5 registers. STI & PPI not skipped */
	for (i = 0; i < PRCMU_GIC_NUMBER_REGS; i++) {

		pr = readl_relaxed(dist_base + GIC_DIST_PENDING_SET + i * 4);
		er = readl_relaxed(dist_base + GIC_DIST_ENABLE_SET + i * 4);

		if (pr & er)
			return true; /* There is a pending interrupt */
	}

	return false;
}

bool prcmu_pending_irq(void)
{
	u32 it, im;
	int i;

	for (i = 0; i < PRCMU_GIC_NUMBER_REGS - 1; i++) {
		it = readl(PRCM_ARMITVAL31TO0 + i * 4);
		im = readl(PRCM_ARMITMSK31TO0 + i * 4);
		if (it & im)
			return true; /* There is a pending interrupt */
	}

	return false;
}

bool prcmu_is_cpu_in_wfi(int cpu)
{
	return readl(PRCM_ARM_WFI_STANDBY) &
		(cpu ? PRCM_ARM_WFI_STANDBY_WFI1 : PRCM_ARM_WFI_STANDBY_WFI0);
}

int prcmu_copy_gic_settings(void)
{
	u32 er; /* Enable register */
	int i;

	/* We skip the STI and PPI */
	for (i = 0; i < PRCMU_GIC_NUMBER_REGS - 1; i++) {
		er = readl_relaxed(dist_base +
				   GIC_DIST_ENABLE_SET + (i + 1) * 4);
		writel(er, PRCM_ARMITMSK31TO0 + i * 4);
	}

	return 0;
}

