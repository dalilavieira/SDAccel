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
typedef  int u8 ;
struct irq_data {int irq; } ;

/* Variables and functions */
 int RBTX4927_IRQ_IOC ; 
 int __fls8 (int) ; 
 int /*<<< orphan*/  mmiowb () ; 
 int /*<<< orphan*/  rbtx4927_imask_addr ; 
 int /*<<< orphan*/  rbtx4927_imstat_addr ; 
 int readb (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writeb (unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int toshiba_rbtx4927_irq_nested(int sw_irq)
{
	u8 level3;

	level3 = readb(rbtx4927_imstat_addr) & 0x1f;
	if (unlikely(!level3))
		return -1;
	return RBTX4927_IRQ_IOC + __fls8(level3);
}

__attribute__((used)) static void toshiba_rbtx4927_irq_ioc_enable(struct irq_data *d)
{
	unsigned char v;

	v = readb(rbtx4927_imask_addr);
	v |= (1 << (d->irq - RBTX4927_IRQ_IOC));
	writeb(v, rbtx4927_imask_addr);
}

__attribute__((used)) static void toshiba_rbtx4927_irq_ioc_disable(struct irq_data *d)
{
	unsigned char v;

	v = readb(rbtx4927_imask_addr);
	v &= ~(1 << (d->irq - RBTX4927_IRQ_IOC));
	writeb(v, rbtx4927_imask_addr);
	mmiowb();
}

