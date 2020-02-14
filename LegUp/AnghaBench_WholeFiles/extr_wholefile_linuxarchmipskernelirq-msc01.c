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
struct irq_data {unsigned int irq; } ;

/* Variables and functions */
 scalar_t__ MSC01_IC_DISH ; 
 scalar_t__ MSC01_IC_DISL ; 
 scalar_t__ MSC01_IC_ENAH ; 
 scalar_t__ MSC01_IC_ENAL ; 
 scalar_t__ MSC01_IC_EOI ; 
 scalar_t__ MSC01_IC_RAMW ; 
 int MSC01_IC_RAMW_ADDR_SHF ; 
 int MSC01_IC_RAMW_DATA_SHF ; 
 scalar_t__ MSC01_IC_SUP ; 
 int MSC01_IC_SUP_EDGE_BIT ; 
 scalar_t__ MSC01_IC_VEC ; 
 int /*<<< orphan*/  MSCIC_READ (scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  MSCIC_WRITE (scalar_t__,int) ; 
 int /*<<< orphan*/  cpu_has_veic ; 
 int /*<<< orphan*/  do_IRQ (unsigned int) ; 
 int irq_base ; 

__attribute__((used)) static inline void mask_msc_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	if (irq < (irq_base + 32))
		MSCIC_WRITE(MSC01_IC_DISL, 1<<(irq - irq_base));
	else
		MSCIC_WRITE(MSC01_IC_DISH, 1<<(irq - irq_base - 32));
}

__attribute__((used)) static inline void unmask_msc_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	if (irq < (irq_base + 32))
		MSCIC_WRITE(MSC01_IC_ENAL, 1<<(irq - irq_base));
	else
		MSCIC_WRITE(MSC01_IC_ENAH, 1<<(irq - irq_base - 32));
}

__attribute__((used)) static void level_mask_and_ack_msc_irq(struct irq_data *d)
{
	mask_msc_irq(d);
	if (!cpu_has_veic)
		MSCIC_WRITE(MSC01_IC_EOI, 0);
}

__attribute__((used)) static void edge_mask_and_ack_msc_irq(struct irq_data *d)
{
	unsigned int irq = d->irq;

	mask_msc_irq(d);
	if (!cpu_has_veic)
		MSCIC_WRITE(MSC01_IC_EOI, 0);
	else {
		u32 r;
		MSCIC_READ(MSC01_IC_SUP+irq*8, r);
		MSCIC_WRITE(MSC01_IC_SUP+irq*8, r | ~MSC01_IC_SUP_EDGE_BIT);
		MSCIC_WRITE(MSC01_IC_SUP+irq*8, r);
	}
}

void ll_msc_irq(void)
{
	unsigned int irq;

	/* read the interrupt vector register */
	MSCIC_READ(MSC01_IC_VEC, irq);
	if (irq < 64)
		do_IRQ(irq + irq_base);
	else {
		/* Ignore spurious interrupt */
	}
}

__attribute__((used)) static void msc_bind_eic_interrupt(int irq, int set)
{
	MSCIC_WRITE(MSC01_IC_RAMW,
		    (irq<<MSC01_IC_RAMW_ADDR_SHF) | (set<<MSC01_IC_RAMW_DATA_SHF));
}

