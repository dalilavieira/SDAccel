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
 int /*<<< orphan*/  IOMD_DMAMASK ; 
 int /*<<< orphan*/  IOMD_FIQMASK ; 
 int /*<<< orphan*/  IOMD_IRQCLRA ; 
 int /*<<< orphan*/  IOMD_IRQMASKA ; 
 int /*<<< orphan*/  IOMD_IRQMASKB ; 
 unsigned int iomd_readb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iomd_writeb (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void iomd_ack_irq_a(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << d->irq;
	val = iomd_readb(IOMD_IRQMASKA);
	iomd_writeb(val & ~mask, IOMD_IRQMASKA);
	iomd_writeb(mask, IOMD_IRQCLRA);
}

__attribute__((used)) static void iomd_mask_irq_a(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << d->irq;
	val = iomd_readb(IOMD_IRQMASKA);
	iomd_writeb(val & ~mask, IOMD_IRQMASKA);
}

__attribute__((used)) static void iomd_unmask_irq_a(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << d->irq;
	val = iomd_readb(IOMD_IRQMASKA);
	iomd_writeb(val | mask, IOMD_IRQMASKA);
}

__attribute__((used)) static void iomd_mask_irq_b(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << (d->irq & 7);
	val = iomd_readb(IOMD_IRQMASKB);
	iomd_writeb(val & ~mask, IOMD_IRQMASKB);
}

__attribute__((used)) static void iomd_unmask_irq_b(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << (d->irq & 7);
	val = iomd_readb(IOMD_IRQMASKB);
	iomd_writeb(val | mask, IOMD_IRQMASKB);
}

__attribute__((used)) static void iomd_mask_irq_dma(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << (d->irq & 7);
	val = iomd_readb(IOMD_DMAMASK);
	iomd_writeb(val & ~mask, IOMD_DMAMASK);
}

__attribute__((used)) static void iomd_unmask_irq_dma(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << (d->irq & 7);
	val = iomd_readb(IOMD_DMAMASK);
	iomd_writeb(val | mask, IOMD_DMAMASK);
}

__attribute__((used)) static void iomd_mask_irq_fiq(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << (d->irq & 7);
	val = iomd_readb(IOMD_FIQMASK);
	iomd_writeb(val & ~mask, IOMD_FIQMASK);
}

__attribute__((used)) static void iomd_unmask_irq_fiq(struct irq_data *d)
{
	unsigned int val, mask;

	mask = 1 << (d->irq & 7);
	val = iomd_readb(IOMD_FIQMASK);
	iomd_writeb(val | mask, IOMD_FIQMASK);
}

