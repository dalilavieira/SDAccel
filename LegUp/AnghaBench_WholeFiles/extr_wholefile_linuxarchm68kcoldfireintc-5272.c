#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct irq_desc {int /*<<< orphan*/  irq_data; } ;
struct irq_data {unsigned int irq; } ;
struct TYPE_4__ {int index; scalar_t__ ack; int /*<<< orphan*/  icr; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* irq_ack ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 unsigned int IRQ_TYPE_EDGE_FALLING ; 
 unsigned int MCFINT_VECBASE ; 
 unsigned int MCFINT_VECMAX ; 
 int /*<<< orphan*/  MCFSIM_PITR ; 
 int /*<<< orphan*/  handle_simple_irq (struct irq_desc*) ; 
 TYPE_2__* intc_irqmap ; 
 TYPE_1__* irq_desc_get_chip (struct irq_desc*) ; 
 int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void intc_irq_mask(struct irq_data *d)
{
	unsigned int irq = d->irq;

	if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX)) {
		u32 v;
		irq -= MCFINT_VECBASE;
		v = 0x8 << intc_irqmap[irq].index;
		writel(v, intc_irqmap[irq].icr);
	}
}

__attribute__((used)) static void intc_irq_unmask(struct irq_data *d)
{
	unsigned int irq = d->irq;

	if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX)) {
		u32 v;
		irq -= MCFINT_VECBASE;
		v = 0xd << intc_irqmap[irq].index;
		writel(v, intc_irqmap[irq].icr);
	}
}

__attribute__((used)) static void intc_irq_ack(struct irq_data *d)
{
	unsigned int irq = d->irq;

	/* Only external interrupts are acked */
	if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX)) {
		irq -= MCFINT_VECBASE;
		if (intc_irqmap[irq].ack) {
			u32 v;
			v = readl(intc_irqmap[irq].icr);
			v &= (0x7 << intc_irqmap[irq].index);
			v |= (0x8 << intc_irqmap[irq].index);
			writel(v, intc_irqmap[irq].icr);
		}
	}
}

__attribute__((used)) static int intc_irq_set_type(struct irq_data *d, unsigned int type)
{
	unsigned int irq = d->irq;

	if ((irq >= MCFINT_VECBASE) && (irq <= MCFINT_VECMAX)) {
		irq -= MCFINT_VECBASE;
		if (intc_irqmap[irq].ack) {
			u32 v;
			v = readl(MCFSIM_PITR);
			if (type == IRQ_TYPE_EDGE_FALLING)
				v &= ~(0x1 << (32 - irq));
			else
				v |= (0x1 << (32 - irq));
			writel(v, MCFSIM_PITR);
		}
	}
	return 0;
}

__attribute__((used)) static void intc_external_irq(struct irq_desc *desc)
{
	irq_desc_get_chip(desc)->irq_ack(&desc->irq_data);
	handle_simple_irq(desc);
}

