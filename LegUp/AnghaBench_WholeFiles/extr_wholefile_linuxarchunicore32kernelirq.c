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
struct puv3_irq_state {int saved; unsigned int icmr; unsigned int iclr; unsigned int iccr; } ;
struct irq_desc {int dummy; } ;
struct irq_data {int irq; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  GPIO_GEDR ; 
 int /*<<< orphan*/  GPIO_GFER ; 
 int /*<<< orphan*/  GPIO_GRER ; 
 unsigned int GPIO_IRQ_falling_edge ; 
 unsigned int GPIO_IRQ_mask ; 
 unsigned int GPIO_IRQ_rising_edge ; 
 unsigned int GPIO_MASK (int) ; 
 int /*<<< orphan*/  INTC_ICCR ; 
 int /*<<< orphan*/  INTC_ICLR ; 
 int /*<<< orphan*/  INTC_ICMR ; 
 unsigned int IRQ_GPIO0 ; 
 int IRQ_GPIOHIGH ; 
 scalar_t__ IRQ_RTCAlarm ; 
 unsigned int IRQ_TYPE_EDGE_FALLING ; 
 unsigned int IRQ_TYPE_EDGE_RISING ; 
 unsigned int IRQ_TYPE_PROBE ; 
 int /*<<< orphan*/  PM_PWER ; 
 unsigned int PM_PWER_GPIOHIGH ; 
 unsigned int PM_PWER_RTC ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 struct puv3_irq_state puv3_irq_state ; 
 unsigned int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int puv3_gpio_type(struct irq_data *d, unsigned int type)
{
	unsigned int mask;

	if (d->irq < IRQ_GPIOHIGH)
		mask = 1 << d->irq;
	else
		mask = GPIO_MASK(d->irq);

	if (type == IRQ_TYPE_PROBE) {
		if ((GPIO_IRQ_rising_edge | GPIO_IRQ_falling_edge) & mask)
			return 0;
		type = IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING;
	}

	if (type & IRQ_TYPE_EDGE_RISING)
		GPIO_IRQ_rising_edge |= mask;
	else
		GPIO_IRQ_rising_edge &= ~mask;
	if (type & IRQ_TYPE_EDGE_FALLING)
		GPIO_IRQ_falling_edge |= mask;
	else
		GPIO_IRQ_falling_edge &= ~mask;

	writel(GPIO_IRQ_rising_edge & GPIO_IRQ_mask, GPIO_GRER);
	writel(GPIO_IRQ_falling_edge & GPIO_IRQ_mask, GPIO_GFER);

	return 0;
}

__attribute__((used)) static void puv3_low_gpio_ack(struct irq_data *d)
{
	writel((1 << d->irq), GPIO_GEDR);
}

__attribute__((used)) static void puv3_low_gpio_mask(struct irq_data *d)
{
	writel(readl(INTC_ICMR) & ~(1 << d->irq), INTC_ICMR);
}

__attribute__((used)) static void puv3_low_gpio_unmask(struct irq_data *d)
{
	writel(readl(INTC_ICMR) | (1 << d->irq), INTC_ICMR);
}

__attribute__((used)) static int puv3_low_gpio_wake(struct irq_data *d, unsigned int on)
{
	if (on)
		writel(readl(PM_PWER) | (1 << d->irq), PM_PWER);
	else
		writel(readl(PM_PWER) & ~(1 << d->irq), PM_PWER);
	return 0;
}

__attribute__((used)) static void puv3_gpio_handler(struct irq_desc *desc)
{
	unsigned int mask, irq;

	mask = readl(GPIO_GEDR);
	do {
		/*
		 * clear down all currently active IRQ sources.
		 * We will be processing them all.
		 */
		writel(mask, GPIO_GEDR);

		irq = IRQ_GPIO0;
		do {
			if (mask & 1)
				generic_handle_irq(irq);
			mask >>= 1;
			irq++;
		} while (mask);
		mask = readl(GPIO_GEDR);
	} while (mask);
}

__attribute__((used)) static void puv3_high_gpio_ack(struct irq_data *d)
{
	unsigned int mask = GPIO_MASK(d->irq);

	writel(mask, GPIO_GEDR);
}

__attribute__((used)) static void puv3_high_gpio_mask(struct irq_data *d)
{
	unsigned int mask = GPIO_MASK(d->irq);

	GPIO_IRQ_mask &= ~mask;

	writel(readl(GPIO_GRER) & ~mask, GPIO_GRER);
	writel(readl(GPIO_GFER) & ~mask, GPIO_GFER);
}

__attribute__((used)) static void puv3_high_gpio_unmask(struct irq_data *d)
{
	unsigned int mask = GPIO_MASK(d->irq);

	GPIO_IRQ_mask |= mask;

	writel(GPIO_IRQ_rising_edge & GPIO_IRQ_mask, GPIO_GRER);
	writel(GPIO_IRQ_falling_edge & GPIO_IRQ_mask, GPIO_GFER);
}

__attribute__((used)) static int puv3_high_gpio_wake(struct irq_data *d, unsigned int on)
{
	if (on)
		writel(readl(PM_PWER) | PM_PWER_GPIOHIGH, PM_PWER);
	else
		writel(readl(PM_PWER) & ~PM_PWER_GPIOHIGH, PM_PWER);
	return 0;
}

__attribute__((used)) static void puv3_mask_irq(struct irq_data *d)
{
	writel(readl(INTC_ICMR) & ~(1 << d->irq), INTC_ICMR);
}

__attribute__((used)) static void puv3_unmask_irq(struct irq_data *d)
{
	writel(readl(INTC_ICMR) | (1 << d->irq), INTC_ICMR);
}

__attribute__((used)) static int puv3_set_wake(struct irq_data *d, unsigned int on)
{
	if (d->irq == IRQ_RTCAlarm) {
		if (on)
			writel(readl(PM_PWER) | PM_PWER_RTC, PM_PWER);
		else
			writel(readl(PM_PWER) & ~PM_PWER_RTC, PM_PWER);
		return 0;
	}
	return -EINVAL;
}

__attribute__((used)) static int puv3_irq_suspend(void)
{
	struct puv3_irq_state *st = &puv3_irq_state;

	st->saved = 1;
	st->icmr = readl(INTC_ICMR);
	st->iclr = readl(INTC_ICLR);
	st->iccr = readl(INTC_ICCR);

	/*
	 * Disable all GPIO-based interrupts.
	 */
	writel(readl(INTC_ICMR) & ~(0x1ff), INTC_ICMR);

	/*
	 * Set the appropriate edges for wakeup.
	 */
	writel(readl(PM_PWER) & GPIO_IRQ_rising_edge, GPIO_GRER);
	writel(readl(PM_PWER) & GPIO_IRQ_falling_edge, GPIO_GFER);

	/*
	 * Clear any pending GPIO interrupts.
	 */
	writel(readl(GPIO_GEDR), GPIO_GEDR);

	return 0;
}

__attribute__((used)) static void puv3_irq_resume(void)
{
	struct puv3_irq_state *st = &puv3_irq_state;

	if (st->saved) {
		writel(st->iccr, INTC_ICCR);
		writel(st->iclr, INTC_ICLR);

		writel(GPIO_IRQ_rising_edge & GPIO_IRQ_mask, GPIO_GRER);
		writel(GPIO_IRQ_falling_edge & GPIO_IRQ_mask, GPIO_GFER);

		writel(st->icmr, INTC_ICMR);
	}
}

