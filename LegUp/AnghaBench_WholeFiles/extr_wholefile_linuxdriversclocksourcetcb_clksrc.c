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
typedef  int u64 ;
typedef  int u32 ;
struct clocksource {int dummy; } ;
struct TYPE_3__ {int cmr; int imr; int rc; int clken; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 scalar_t__ ATMEL_TC_BCR ; 
 scalar_t__ ATMEL_TC_BMR ; 
 int ATMEL_TC_CLKEN ; 
 int ATMEL_TC_CLKSTA ; 
 scalar_t__ ATMEL_TC_REG (int,int /*<<< orphan*/ ) ; 
 int ATMEL_TC_SYNC ; 
 int /*<<< orphan*/  CCR ; 
 int /*<<< orphan*/  CMR ; 
 int /*<<< orphan*/  CV ; 
 int /*<<< orphan*/  IDR ; 
 int /*<<< orphan*/  IER ; 
 int /*<<< orphan*/  IMR ; 
 int /*<<< orphan*/  RA ; 
 int /*<<< orphan*/  RB ; 
 int /*<<< orphan*/  RC ; 
 int /*<<< orphan*/  SR ; 
 int bmr_cache ; 
 int /*<<< orphan*/  raw_local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  raw_local_irq_save (unsigned long) ; 
 int readl (scalar_t__) ; 
 int readl_relaxed (scalar_t__) ; 
 scalar_t__ tcaddr ; 
 TYPE_1__* tcb_cache ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static u64 tc_get_cycles(struct clocksource *cs)
{
	unsigned long	flags;
	u32		lower, upper;

	raw_local_irq_save(flags);
	do {
		upper = readl_relaxed(tcaddr + ATMEL_TC_REG(1, CV));
		lower = readl_relaxed(tcaddr + ATMEL_TC_REG(0, CV));
	} while (upper != readl_relaxed(tcaddr + ATMEL_TC_REG(1, CV)));

	raw_local_irq_restore(flags);
	return (upper << 16) | lower;
}

__attribute__((used)) static u64 tc_get_cycles32(struct clocksource *cs)
{
	return readl_relaxed(tcaddr + ATMEL_TC_REG(0, CV));
}

void tc_clksrc_suspend(struct clocksource *cs)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(tcb_cache); i++) {
		tcb_cache[i].cmr = readl(tcaddr + ATMEL_TC_REG(i, CMR));
		tcb_cache[i].imr = readl(tcaddr + ATMEL_TC_REG(i, IMR));
		tcb_cache[i].rc = readl(tcaddr + ATMEL_TC_REG(i, RC));
		tcb_cache[i].clken = !!(readl(tcaddr + ATMEL_TC_REG(i, SR)) &
					ATMEL_TC_CLKSTA);
	}

	bmr_cache = readl(tcaddr + ATMEL_TC_BMR);
}

void tc_clksrc_resume(struct clocksource *cs)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(tcb_cache); i++) {
		/* Restore registers for the channel, RA and RB are not used  */
		writel(tcb_cache[i].cmr, tcaddr + ATMEL_TC_REG(i, CMR));
		writel(tcb_cache[i].rc, tcaddr + ATMEL_TC_REG(i, RC));
		writel(0, tcaddr + ATMEL_TC_REG(i, RA));
		writel(0, tcaddr + ATMEL_TC_REG(i, RB));
		/* Disable all the interrupts */
		writel(0xff, tcaddr + ATMEL_TC_REG(i, IDR));
		/* Reenable interrupts that were enabled before suspending */
		writel(tcb_cache[i].imr, tcaddr + ATMEL_TC_REG(i, IER));
		/* Start the clock if it was used */
		if (tcb_cache[i].clken)
			writel(ATMEL_TC_CLKEN, tcaddr + ATMEL_TC_REG(i, CCR));
	}

	/* Dual channel, chain channels */
	writel(bmr_cache, tcaddr + ATMEL_TC_BMR);
	/* Finally, trigger all the channels*/
	writel(ATMEL_TC_SYNC, tcaddr + ATMEL_TC_BCR);
}

