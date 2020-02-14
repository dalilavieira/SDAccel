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
struct irq_desc {int dummy; } ;
struct irq_data {int irq; } ;
struct irq_chip {int dummy; } ;
typedef  enum bcsr_id { ____Placeholder_bcsr_id } bcsr_id ;
struct TYPE_2__ {int /*<<< orphan*/  lock; scalar_t__ raddr; } ;

/* Variables and functions */
 scalar_t__ BCSR_REG_INTSTAT ; 
 scalar_t__ BCSR_REG_MASKCLR ; 
 scalar_t__ BCSR_REG_MASKSET ; 
 int __ffs (unsigned short) ; 
 unsigned short __raw_readw (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writew (unsigned short,scalar_t__) ; 
 int bcsr_csc_base ; 
 TYPE_1__* bcsr_regs ; 
 scalar_t__ bcsr_virt ; 
 int /*<<< orphan*/  chained_irq_enter (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  chained_irq_exit (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  generic_handle_irq (int) ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  wmb () ; 

void bcsr_write(enum bcsr_id reg, unsigned short val)
{
	unsigned long flags;

	spin_lock_irqsave(&bcsr_regs[reg].lock, flags);
	__raw_writew(val, bcsr_regs[reg].raddr);
	wmb();
	spin_unlock_irqrestore(&bcsr_regs[reg].lock, flags);
}

void bcsr_mod(enum bcsr_id reg, unsigned short clr, unsigned short set)
{
	unsigned short r;
	unsigned long flags;

	spin_lock_irqsave(&bcsr_regs[reg].lock, flags);
	r = __raw_readw(bcsr_regs[reg].raddr);
	r &= ~clr;
	r |= set;
	__raw_writew(r, bcsr_regs[reg].raddr);
	wmb();
	spin_unlock_irqrestore(&bcsr_regs[reg].lock, flags);
}

__attribute__((used)) static void bcsr_csc_handler(struct irq_desc *d)
{
	unsigned short bisr = __raw_readw(bcsr_virt + BCSR_REG_INTSTAT);
	struct irq_chip *chip = irq_desc_get_chip(d);

	chained_irq_enter(chip, d);
	generic_handle_irq(bcsr_csc_base + __ffs(bisr));
	chained_irq_exit(chip, d);
}

__attribute__((used)) static void bcsr_irq_mask(struct irq_data *d)
{
	unsigned short v = 1 << (d->irq - bcsr_csc_base);
	__raw_writew(v, bcsr_virt + BCSR_REG_MASKCLR);
	wmb();
}

__attribute__((used)) static void bcsr_irq_maskack(struct irq_data *d)
{
	unsigned short v = 1 << (d->irq - bcsr_csc_base);
	__raw_writew(v, bcsr_virt + BCSR_REG_MASKCLR);
	__raw_writew(v, bcsr_virt + BCSR_REG_INTSTAT);	/* ack */
	wmb();
}

__attribute__((used)) static void bcsr_irq_unmask(struct irq_data *d)
{
	unsigned short v = 1 << (d->irq - bcsr_csc_base);
	__raw_writew(v, bcsr_virt + BCSR_REG_MASKSET);
	wmb();
}

