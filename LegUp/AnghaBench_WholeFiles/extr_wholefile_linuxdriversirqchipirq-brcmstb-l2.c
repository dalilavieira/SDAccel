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
struct irq_desc {int /*<<< orphan*/  lock; } ;
struct irq_data {int mask; } ;
struct TYPE_4__ {int /*<<< orphan*/  enable; int /*<<< orphan*/  disable; int /*<<< orphan*/  ack; int /*<<< orphan*/  mask; } ;
struct TYPE_3__ {scalar_t__ irq_ack; } ;
struct irq_chip_type {int* mask_cache; TYPE_2__ regs; TYPE_1__ chip; } ;
struct irq_chip_generic {int wake_active; struct brcmstb_l2_intc_data* private; } ;
struct irq_chip {int dummy; } ;
struct brcmstb_l2_intc_data {int saved_mask; scalar_t__ can_wake; int /*<<< orphan*/  domain; int /*<<< orphan*/  mask_offset; struct irq_chip_generic* gc; int /*<<< orphan*/  status_offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  chained_irq_enter (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  chained_irq_exit (struct irq_chip*,struct irq_desc*) ; 
 int ffs (int) ; 
 int /*<<< orphan*/  generic_handle_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_bad_irq (struct irq_desc*) ; 
 struct irq_chip_type* irq_data_get_chip_type (struct irq_data*) ; 
 struct irq_chip_generic* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 struct brcmstb_l2_intc_data* irq_desc_get_handler_data (struct irq_desc*) ; 
 int /*<<< orphan*/  irq_gc_lock (struct irq_chip_generic*) ; 
 int /*<<< orphan*/  irq_gc_lock_irqsave (struct irq_chip_generic*,unsigned long) ; 
 int /*<<< orphan*/  irq_gc_unlock (struct irq_chip_generic*) ; 
 int /*<<< orphan*/  irq_gc_unlock_irqrestore (struct irq_chip_generic*,unsigned long) ; 
 int /*<<< orphan*/  irq_linear_revmap (int /*<<< orphan*/ ,unsigned int) ; 
 int irq_reg_readl (struct irq_chip_generic*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_reg_writel (struct irq_chip_generic*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  raw_spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void brcmstb_l2_mask_and_ack(struct irq_data *d)
{
	struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
	struct irq_chip_type *ct = irq_data_get_chip_type(d);
	u32 mask = d->mask;

	irq_gc_lock(gc);
	irq_reg_writel(gc, mask, ct->regs.disable);
	*ct->mask_cache &= ~mask;
	irq_reg_writel(gc, mask, ct->regs.ack);
	irq_gc_unlock(gc);
}

__attribute__((used)) static void brcmstb_l2_intc_irq_handle(struct irq_desc *desc)
{
	struct brcmstb_l2_intc_data *b = irq_desc_get_handler_data(desc);
	struct irq_chip *chip = irq_desc_get_chip(desc);
	unsigned int irq;
	u32 status;

	chained_irq_enter(chip, desc);

	status = irq_reg_readl(b->gc, b->status_offset) &
		~(irq_reg_readl(b->gc, b->mask_offset));

	if (status == 0) {
		raw_spin_lock(&desc->lock);
		handle_bad_irq(desc);
		raw_spin_unlock(&desc->lock);
		goto out;
	}

	do {
		irq = ffs(status) - 1;
		status &= ~(1 << irq);
		generic_handle_irq(irq_linear_revmap(b->domain, irq));
	} while (status);
out:
	chained_irq_exit(chip, desc);
}

__attribute__((used)) static void brcmstb_l2_intc_suspend(struct irq_data *d)
{
	struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
	struct irq_chip_type *ct = irq_data_get_chip_type(d);
	struct brcmstb_l2_intc_data *b = gc->private;
	unsigned long flags;

	irq_gc_lock_irqsave(gc, flags);
	/* Save the current mask */
	b->saved_mask = irq_reg_readl(gc, ct->regs.mask);

	if (b->can_wake) {
		/* Program the wakeup mask */
		irq_reg_writel(gc, ~gc->wake_active, ct->regs.disable);
		irq_reg_writel(gc, gc->wake_active, ct->regs.enable);
	}
	irq_gc_unlock_irqrestore(gc, flags);
}

__attribute__((used)) static void brcmstb_l2_intc_resume(struct irq_data *d)
{
	struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
	struct irq_chip_type *ct = irq_data_get_chip_type(d);
	struct brcmstb_l2_intc_data *b = gc->private;
	unsigned long flags;

	irq_gc_lock_irqsave(gc, flags);
	if (ct->chip.irq_ack) {
		/* Clear unmasked non-wakeup interrupts */
		irq_reg_writel(gc, ~b->saved_mask & ~gc->wake_active,
				ct->regs.ack);
	}

	/* Restore the saved mask */
	irq_reg_writel(gc, b->saved_mask, ct->regs.disable);
	irq_reg_writel(gc, ~b->saved_mask, ct->regs.enable);
	irq_gc_unlock_irqrestore(gc, flags);
}

