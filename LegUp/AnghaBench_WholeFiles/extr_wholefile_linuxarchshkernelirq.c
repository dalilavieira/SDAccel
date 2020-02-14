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
struct pt_regs {int dummy; } ;

/* Variables and functions */
 int IRQ_HANDLED ; 
 unsigned int NO_IRQ_IGNORE ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 unsigned int irq_demux (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_enter () ; 
 int /*<<< orphan*/  irq_err_count ; 
 int /*<<< orphan*/  irq_exit () ; 
 int /*<<< orphan*/  irq_finish (unsigned int) ; 
 int /*<<< orphan*/  irq_lookup (unsigned int) ; 
 int /*<<< orphan*/  printk (char*,unsigned int) ; 
 struct pt_regs* set_irq_regs (struct pt_regs*) ; 

void ack_bad_irq(unsigned int irq)
{
	atomic_inc(&irq_err_count);
	printk("unexpected IRQ trap at vector %02x\n", irq);
}

__attribute__((used)) static inline void handle_one_irq(unsigned int irq)
{
	generic_handle_irq(irq);
}

int do_IRQ(unsigned int irq, struct pt_regs *regs)
{
	struct pt_regs *old_regs = set_irq_regs(regs);

	irq_enter();

	irq = irq_demux(irq_lookup(irq));

	if (irq != NO_IRQ_IGNORE) {
		handle_one_irq(irq);
		irq_finish(irq);
	}

	irq_exit();

	set_irq_regs(old_regs);

	return IRQ_HANDLED;
}

