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
typedef  void* u8 ;
struct irq_data {int irq; } ;

/* Variables and functions */
 int MIPS_CPU_IRQ_BASE ; 
 int RBTX4938_IRQ_IOC ; 
 int RBTX4938_IRQ_IOCINT ; 
 int STATUSF_IP0 ; 
 int STATUSF_IP1 ; 
 int STATUSF_IP2 ; 
 int STATUSF_IP7 ; 
 int __fls8 (void*) ; 
 int /*<<< orphan*/  mmiowb () ; 
 int /*<<< orphan*/  rbtx4938_imask_addr ; 
 int /*<<< orphan*/  rbtx4938_imstat_addr ; 
 void* readb (int /*<<< orphan*/ ) ; 
 int txx9_irq () ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writeb (unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int toshiba_rbtx4938_irq_nested(int sw_irq)
{
	u8 level3;

	level3 = readb(rbtx4938_imstat_addr);
	if (unlikely(!level3))
		return -1;
	/* must use fls so onboard ATA has priority */
	return RBTX4938_IRQ_IOC + __fls8(level3);
}

__attribute__((used)) static void toshiba_rbtx4938_irq_ioc_enable(struct irq_data *d)
{
	unsigned char v;

	v = readb(rbtx4938_imask_addr);
	v |= (1 << (d->irq - RBTX4938_IRQ_IOC));
	writeb(v, rbtx4938_imask_addr);
	mmiowb();
}

__attribute__((used)) static void toshiba_rbtx4938_irq_ioc_disable(struct irq_data *d)
{
	unsigned char v;

	v = readb(rbtx4938_imask_addr);
	v &= ~(1 << (d->irq - RBTX4938_IRQ_IOC));
	writeb(v, rbtx4938_imask_addr);
	mmiowb();
}

__attribute__((used)) static int rbtx4938_irq_dispatch(int pending)
{
	int irq;

	if (pending & STATUSF_IP7)
		irq = MIPS_CPU_IRQ_BASE + 7;
	else if (pending & STATUSF_IP2) {
		irq = txx9_irq();
		if (irq == RBTX4938_IRQ_IOCINT)
			irq = toshiba_rbtx4938_irq_nested(irq);
	} else if (pending & STATUSF_IP1)
		irq = MIPS_CPU_IRQ_BASE + 0;
	else if (pending & STATUSF_IP0)
		irq = MIPS_CPU_IRQ_BASE + 1;
	else
		irq = -1;
	return irq;
}

