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
struct irq_data {int hwirq; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int ENOENT ; 
 scalar_t__ S3C24XX_EINFLT0 ; 
 scalar_t__ S3C24XX_EINTMASK ; 
 scalar_t__ S3C24XX_EXTINT0 ; 
 int /*<<< orphan*/  __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/ * irq_save ; 
 int /*<<< orphan*/  pr_info (char*,char*,int) ; 
 unsigned long s3c_irqwake_intallow ; 
 unsigned long s3c_irqwake_intmask ; 
 int /*<<< orphan*/  s3c_pm_do_restore (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  s3c_pm_do_save (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/ * save_eintflt ; 
 int /*<<< orphan*/  save_eintmask ; 
 int /*<<< orphan*/ * save_extint ; 

int s3c_irq_wake(struct irq_data *data, unsigned int state)
{
	unsigned long irqbit = 1 << data->hwirq;

	if (!(s3c_irqwake_intallow & irqbit))
		return -ENOENT;

	pr_info("wake %s for hwirq %lu\n",
		state ? "enabled" : "disabled", data->hwirq);

	if (!state)
		s3c_irqwake_intmask |= irqbit;
	else
		s3c_irqwake_intmask &= ~irqbit;

	return 0;
}

__attribute__((used)) static int s3c24xx_irq_suspend(void)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(save_extint); i++)
		save_extint[i] = __raw_readl(S3C24XX_EXTINT0 + (i*4));

	for (i = 0; i < ARRAY_SIZE(save_eintflt); i++)
		save_eintflt[i] = __raw_readl(S3C24XX_EINFLT0 + (i*4));

	s3c_pm_do_save(irq_save, ARRAY_SIZE(irq_save));
	save_eintmask = __raw_readl(S3C24XX_EINTMASK);

	return 0;
}

__attribute__((used)) static void s3c24xx_irq_resume(void)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(save_extint); i++)
		__raw_writel(save_extint[i], S3C24XX_EXTINT0 + (i*4));

	for (i = 0; i < ARRAY_SIZE(save_eintflt); i++)
		__raw_writel(save_eintflt[i], S3C24XX_EINFLT0 + (i*4));

	s3c_pm_do_restore(irq_save, ARRAY_SIZE(irq_save));
	__raw_writel(save_eintmask, S3C24XX_EINTMASK);
}

