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

/* Variables and functions */
 int /*<<< orphan*/  CR_OFFSET (int) ; 
 int /*<<< orphan*/  ECR_OFFSET (int) ; 
 int /*<<< orphan*/  ESR_OFFSET (int) ; 
 int /*<<< orphan*/  REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SEC_CR_OFFSET ; 
 int /*<<< orphan*/  SEC_ECR_OFFSET ; 
 int /*<<< orphan*/  SEC_ESR_OFFSET ; 
 int ar7_irq_base ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ar7_unmask_irq(struct irq_data *d)
{
	writel(1 << ((d->irq - ar7_irq_base) % 32),
	       REG(ESR_OFFSET(d->irq - ar7_irq_base)));
}

__attribute__((used)) static void ar7_mask_irq(struct irq_data *d)
{
	writel(1 << ((d->irq - ar7_irq_base) % 32),
	       REG(ECR_OFFSET(d->irq - ar7_irq_base)));
}

__attribute__((used)) static void ar7_ack_irq(struct irq_data *d)
{
	writel(1 << ((d->irq - ar7_irq_base) % 32),
	       REG(CR_OFFSET(d->irq - ar7_irq_base)));
}

__attribute__((used)) static void ar7_unmask_sec_irq(struct irq_data *d)
{
	writel(1 << (d->irq - ar7_irq_base - 40), REG(SEC_ESR_OFFSET));
}

__attribute__((used)) static void ar7_mask_sec_irq(struct irq_data *d)
{
	writel(1 << (d->irq - ar7_irq_base - 40), REG(SEC_ECR_OFFSET));
}

__attribute__((used)) static void ar7_ack_sec_irq(struct irq_data *d)
{
	writel(1 << (d->irq - ar7_irq_base - 40), REG(SEC_CR_OFFSET));
}

