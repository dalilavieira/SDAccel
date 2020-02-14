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
typedef  int u8 ;
struct irq_data {scalar_t__ irq; } ;
struct TYPE_2__ {int imask0; int imask1; int cmeimask0; int cmeimask1; int istat0; int vmeistat; int istat1; } ;

/* Variables and functions */
 int SGINT_ISTAT0_LIO2 ; 
 int SGINT_ISTAT1_LIO3 ; 
 int SGINT_LOCAL0 ; 
 int SGINT_LOCAL1 ; 
 int SGINT_LOCAL2 ; 
 int SGINT_LOCAL3 ; 
 scalar_t__ SGI_MAP_0_IRQ ; 
 scalar_t__ SGI_MAP_1_IRQ ; 
 int /*<<< orphan*/  do_IRQ (int) ; 
 int* lc0msk_to_irqnr ; 
 int* lc1msk_to_irqnr ; 
 int* lc2msk_to_irqnr ; 
 int* lc3msk_to_irqnr ; 
 TYPE_1__* sgint ; 

__attribute__((used)) static void enable_local0_irq(struct irq_data *d)
{
	/* don't allow mappable interrupt to be enabled from setup_irq,
	 * we have our own way to do so */
	if (d->irq != SGI_MAP_0_IRQ)
		sgint->imask0 |= (1 << (d->irq - SGINT_LOCAL0));
}

__attribute__((used)) static void disable_local0_irq(struct irq_data *d)
{
	sgint->imask0 &= ~(1 << (d->irq - SGINT_LOCAL0));
}

__attribute__((used)) static void enable_local1_irq(struct irq_data *d)
{
	/* don't allow mappable interrupt to be enabled from setup_irq,
	 * we have our own way to do so */
	if (d->irq != SGI_MAP_1_IRQ)
		sgint->imask1 |= (1 << (d->irq - SGINT_LOCAL1));
}

__attribute__((used)) static void disable_local1_irq(struct irq_data *d)
{
	sgint->imask1 &= ~(1 << (d->irq - SGINT_LOCAL1));
}

__attribute__((used)) static void enable_local2_irq(struct irq_data *d)
{
	sgint->imask0 |= (1 << (SGI_MAP_0_IRQ - SGINT_LOCAL0));
	sgint->cmeimask0 |= (1 << (d->irq - SGINT_LOCAL2));
}

__attribute__((used)) static void disable_local2_irq(struct irq_data *d)
{
	sgint->cmeimask0 &= ~(1 << (d->irq - SGINT_LOCAL2));
	if (!sgint->cmeimask0)
		sgint->imask0 &= ~(1 << (SGI_MAP_0_IRQ - SGINT_LOCAL0));
}

__attribute__((used)) static void enable_local3_irq(struct irq_data *d)
{
	sgint->imask1 |= (1 << (SGI_MAP_1_IRQ - SGINT_LOCAL1));
	sgint->cmeimask1 |= (1 << (d->irq - SGINT_LOCAL3));
}

__attribute__((used)) static void disable_local3_irq(struct irq_data *d)
{
	sgint->cmeimask1 &= ~(1 << (d->irq - SGINT_LOCAL3));
	if (!sgint->cmeimask1)
		sgint->imask1 &= ~(1 << (SGI_MAP_1_IRQ - SGINT_LOCAL1));
}

__attribute__((used)) static void indy_local0_irqdispatch(void)
{
	u8 mask = sgint->istat0 & sgint->imask0;
	u8 mask2;
	int irq;

	if (mask & SGINT_ISTAT0_LIO2) {
		mask2 = sgint->vmeistat & sgint->cmeimask0;
		irq = lc2msk_to_irqnr[mask2];
	} else
		irq = lc0msk_to_irqnr[mask];

	/*
	 * workaround for INT2 bug; if irq == 0, INT2 has seen a fifo full
	 * irq, but failed to latch it into status register
	 */
	if (irq)
		do_IRQ(irq);
	else
		do_IRQ(SGINT_LOCAL0 + 0);
}

__attribute__((used)) static void indy_local1_irqdispatch(void)
{
	u8 mask = sgint->istat1 & sgint->imask1;
	u8 mask2;
	int irq;

	if (mask & SGINT_ISTAT1_LIO3) {
		mask2 = sgint->vmeistat & sgint->cmeimask1;
		irq = lc3msk_to_irqnr[mask2];
	} else
		irq = lc1msk_to_irqnr[mask];

	/* if irq == 0, then the interrupt has already been cleared */
	if (irq)
		do_IRQ(irq);
}

