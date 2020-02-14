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
 int CAUSEF_IP0 ; 
 int CAUSEF_IP1 ; 
 int CAUSEF_IP7 ; 
 int MIPS_CPU_IRQ_BASE ; 
 int RBTX4939_IRQ_IOC ; 
#define  RBTX4939_IRQ_IOCINT 128 
 int __fls8 (unsigned char) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  mmiowb () ; 
 int /*<<< orphan*/  rbtx4939_ien_addr ; 
 int /*<<< orphan*/  rbtx4939_ifac2_addr ; 
 int readb (int /*<<< orphan*/ ) ; 
 int tx4939_irq () ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writeb (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rbtx4939_ioc_irq_unmask(struct irq_data *d)
{
	int ioc_nr = d->irq - RBTX4939_IRQ_IOC;

	writeb(readb(rbtx4939_ien_addr) | (1 << ioc_nr), rbtx4939_ien_addr);
}

__attribute__((used)) static void rbtx4939_ioc_irq_mask(struct irq_data *d)
{
	int ioc_nr = d->irq - RBTX4939_IRQ_IOC;

	writeb(readb(rbtx4939_ien_addr) & ~(1 << ioc_nr), rbtx4939_ien_addr);
	mmiowb();
}

__attribute__((used)) static inline int rbtx4939_ioc_irqroute(void)
{
	unsigned char istat = readb(rbtx4939_ifac2_addr);

	if (unlikely(istat == 0))
		return -1;
	return RBTX4939_IRQ_IOC + __fls8(istat);
}

__attribute__((used)) static int rbtx4939_irq_dispatch(int pending)
{
	int irq;

	if (pending & CAUSEF_IP7)
		return MIPS_CPU_IRQ_BASE + 7;
	irq = tx4939_irq();
	if (likely(irq >= 0)) {
		/* redirect IOC interrupts */
		switch (irq) {
		case RBTX4939_IRQ_IOCINT:
			irq = rbtx4939_ioc_irqroute();
			break;
		}
	} else if (pending & CAUSEF_IP0)
		irq = MIPS_CPU_IRQ_BASE + 0;
	else if (pending & CAUSEF_IP1)
		irq = MIPS_CPU_IRQ_BASE + 1;
	else
		irq = -1;
	return irq;
}

