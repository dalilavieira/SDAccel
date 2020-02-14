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
struct irq_data {int irq; } ;
struct group_irq {scalar_t__ enabled; unsigned int gpen; int /*<<< orphan*/  (* enable ) (struct group_irq*,int) ;} ;

/* Variables and functions */
#define  IRQ_GDMAGROUP 135 
#define  IRQ_GROUP0 134 
#define  IRQ_GROUP1 133 
#define  IRQ_I2CGROUP 132 
#define  IRQ_P2SGROUP 131 
#define  IRQ_SCGROUP 130 
#define  IRQ_T_INT_GROUP 129 
#define  IRQ_USBH 128 
 int /*<<< orphan*/  REG_AIC_EOSCR ; 
 int /*<<< orphan*/  REG_AIC_GEN ; 
 int /*<<< orphan*/  REG_AIC_MDCR ; 
 int /*<<< orphan*/  REG_AIC_MECR ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ ) ; 
 struct group_irq group_gdma ; 
 struct group_irq group_i2c ; 
 struct group_irq group_nirq0 ; 
 struct group_irq group_nirq1 ; 
 struct group_irq group_ottimer ; 
 struct group_irq group_ps2 ; 
 struct group_irq group_sc ; 
 struct group_irq group_usbh ; 
 int /*<<< orphan*/  groupirq_lock ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct group_irq*,int) ; 
 int /*<<< orphan*/  stub2 (struct group_irq*,int) ; 

__attribute__((used)) static int group_irq_enable(struct group_irq *group_irq)
{
	unsigned long flags;

	spin_lock_irqsave(&groupirq_lock, flags);
	if (group_irq->enabled++ == 0)
		(group_irq->enable)(group_irq, 1);
	spin_unlock_irqrestore(&groupirq_lock, flags);

	return 0;
}

__attribute__((used)) static void group_irq_disable(struct group_irq *group_irq)
{
	unsigned long flags;

	WARN_ON(group_irq->enabled == 0);

	spin_lock_irqsave(&groupirq_lock, flags);
	if (--group_irq->enabled == 0)
		(group_irq->enable)(group_irq, 0);
	spin_unlock_irqrestore(&groupirq_lock, flags);
}

__attribute__((used)) static void nuc900_group_enable(struct group_irq *gpirq, int enable)
{
	unsigned int groupen = gpirq->gpen;
	unsigned long regval;

	regval = __raw_readl(REG_AIC_GEN);

	if (enable)
		regval |= groupen;
	else
		regval &= ~groupen;

	__raw_writel(regval, REG_AIC_GEN);
}

__attribute__((used)) static void nuc900_irq_mask(struct irq_data *d)
{
	struct group_irq *group_irq;

	group_irq = NULL;

	__raw_writel(1 << d->irq, REG_AIC_MDCR);

	switch (d->irq) {
	case IRQ_GROUP0:
		group_irq = &group_nirq0;
		break;

	case IRQ_GROUP1:
		group_irq = &group_nirq1;
		break;

	case IRQ_USBH:
		group_irq = &group_usbh;
		break;

	case IRQ_T_INT_GROUP:
		group_irq = &group_ottimer;
		break;

	case IRQ_GDMAGROUP:
		group_irq = &group_gdma;
		break;

	case IRQ_SCGROUP:
		group_irq = &group_sc;
		break;

	case IRQ_I2CGROUP:
		group_irq = &group_i2c;
		break;

	case IRQ_P2SGROUP:
		group_irq = &group_ps2;
		break;
	}

	if (group_irq)
		group_irq_disable(group_irq);
}

__attribute__((used)) static void nuc900_irq_ack(struct irq_data *d)
{
	__raw_writel(0x01, REG_AIC_EOSCR);
}

__attribute__((used)) static void nuc900_irq_unmask(struct irq_data *d)
{
	struct group_irq *group_irq;

	group_irq = NULL;

	__raw_writel(1 << d->irq, REG_AIC_MECR);

	switch (d->irq) {
	case IRQ_GROUP0:
		group_irq = &group_nirq0;
		break;

	case IRQ_GROUP1:
		group_irq = &group_nirq1;
		break;

	case IRQ_USBH:
		group_irq = &group_usbh;
		break;

	case IRQ_T_INT_GROUP:
		group_irq = &group_ottimer;
		break;

	case IRQ_GDMAGROUP:
		group_irq = &group_gdma;
		break;

	case IRQ_SCGROUP:
		group_irq = &group_sc;
		break;

	case IRQ_I2CGROUP:
		group_irq = &group_i2c;
		break;

	case IRQ_P2SGROUP:
		group_irq = &group_ps2;
		break;
	}

	if (group_irq)
		group_irq_enable(group_irq);
}

