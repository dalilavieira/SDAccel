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
typedef  unsigned int u8 ;
typedef  int u32 ;
struct irq_data {int irq; } ;

/* Variables and functions */
 int C_IRQ0 ; 
 int C_IRQ1 ; 
 int C_IRQ3 ; 
 int C_IRQ4 ; 
 int C_IRQ5 ; 
 int /*<<< orphan*/  IE_IRQ3 ; 
 unsigned int IT_EISA ; 
 unsigned int IT_INTA ; 
 unsigned int IT_INTB ; 
 unsigned int IT_INTC ; 
 unsigned int IT_INTD ; 
 unsigned int IT_SCSI ; 
 int MIPS_CPU_IRQ_BASE ; 
 scalar_t__ PCIMT_CSITPEND ; 
 scalar_t__ PCIMT_IRQSEL ; 
 int PCIMT_IRQ_INT2 ; 
 int PCIMT_IRQ_SCSI ; 
 int /*<<< orphan*/  ST0_IM ; 
 int /*<<< orphan*/  clear_c0_status (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_IRQ (int) ; 
 int ffs (unsigned int) ; 
 int i8259_irq () ; 
 int /*<<< orphan*/  panic (char*) ; 
 int read_c0_cause () ; 
 int read_c0_status () ; 
 int /*<<< orphan*/  set_c0_status (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  write_c0_status (unsigned long) ; 

__attribute__((used)) static void enable_pcimt_irq(struct irq_data *d)
{
	unsigned int mask = 1 << (d->irq - PCIMT_IRQ_INT2);

	*(volatile u8 *) PCIMT_IRQSEL |= mask;
}

void disable_pcimt_irq(struct irq_data *d)
{
	unsigned int mask = ~(1 << (d->irq - PCIMT_IRQ_INT2));

	*(volatile u8 *) PCIMT_IRQSEL &= mask;
}

__attribute__((used)) static void pcimt_hwint0(void)
{
	panic("Received int0 but no handler yet ...");
}

__attribute__((used)) static void pcimt_hwint1(void)
{
	u8 pend = *(volatile char *)PCIMT_CSITPEND;
	unsigned long flags;

	if (pend & IT_EISA) {
		int irq;
		/*
		 * Note: ASIC PCI's builtin interrupt acknowledge feature is
		 * broken.  Using it may result in loss of some or all i8259
		 * interrupts, so don't use PCIMT_INT_ACKNOWLEDGE ...
		 */
		irq = i8259_irq();
		if (unlikely(irq < 0))
			return;

		do_IRQ(irq);
	}

	if (!(pend & IT_SCSI)) {
		flags = read_c0_status();
		clear_c0_status(ST0_IM);
		do_IRQ(PCIMT_IRQ_SCSI);
		write_c0_status(flags);
	}
}

__attribute__((used)) static void pcimt_hwint3(void)
{
	u8 pend = *(volatile char *)PCIMT_CSITPEND;
	int irq;

	pend &= (IT_INTA | IT_INTB | IT_INTC | IT_INTD);
	pend ^= (IT_INTA | IT_INTB | IT_INTC | IT_INTD);
	clear_c0_status(IE_IRQ3);
	irq = PCIMT_IRQ_INT2 + ffs(pend) - 1;
	do_IRQ(irq);
	set_c0_status(IE_IRQ3);
}

__attribute__((used)) static void sni_pcimt_hwint(void)
{
	u32 pending = read_c0_cause() & read_c0_status();

	if (pending & C_IRQ5)
		do_IRQ(MIPS_CPU_IRQ_BASE + 7);
	else if (pending & C_IRQ4)
		do_IRQ(MIPS_CPU_IRQ_BASE + 6);
	else if (pending & C_IRQ3)
		pcimt_hwint3();
	else if (pending & C_IRQ1)
		pcimt_hwint1();
	else if (pending & C_IRQ0) {
		pcimt_hwint0();
	}
}

