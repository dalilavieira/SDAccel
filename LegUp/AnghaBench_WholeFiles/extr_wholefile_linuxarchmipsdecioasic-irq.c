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
struct irq_data {int irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  IO_REG_SIMR ; 
 int /*<<< orphan*/  IO_REG_SIR ; 
 int /*<<< orphan*/  fast_iob () ; 
 int ioasic_irq_base ; 
 int ioasic_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioasic_write (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void unmask_ioasic_irq(struct irq_data *d)
{
	u32 simr;

	simr = ioasic_read(IO_REG_SIMR);
	simr |= (1 << (d->irq - ioasic_irq_base));
	ioasic_write(IO_REG_SIMR, simr);
}

__attribute__((used)) static void mask_ioasic_irq(struct irq_data *d)
{
	u32 simr;

	simr = ioasic_read(IO_REG_SIMR);
	simr &= ~(1 << (d->irq - ioasic_irq_base));
	ioasic_write(IO_REG_SIMR, simr);
}

__attribute__((used)) static void ack_ioasic_irq(struct irq_data *d)
{
	mask_ioasic_irq(d);
	fast_iob();
}

__attribute__((used)) static void clear_ioasic_dma_irq(struct irq_data *d)
{
	u32 sir;

	sir = ~(1 << (d->irq - ioasic_irq_base));
	ioasic_write(IO_REG_SIR, sir);
	fast_iob();
}

