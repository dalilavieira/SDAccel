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
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  JAZZ_IO_IRQ_ENABLE ; 
 int JAZZ_IRQ_START ; 
 int /*<<< orphan*/  r4030_lock ; 
 unsigned int r4030_read_reg16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r4030_write_reg16 (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 

__attribute__((used)) static void enable_r4030_irq(struct irq_data *d)
{
	unsigned int mask = 1 << (d->irq - JAZZ_IRQ_START);
	unsigned long flags;

	raw_spin_lock_irqsave(&r4030_lock, flags);
	mask |= r4030_read_reg16(JAZZ_IO_IRQ_ENABLE);
	r4030_write_reg16(JAZZ_IO_IRQ_ENABLE, mask);
	raw_spin_unlock_irqrestore(&r4030_lock, flags);
}

void disable_r4030_irq(struct irq_data *d)
{
	unsigned int mask = ~(1 << (d->irq - JAZZ_IRQ_START));
	unsigned long flags;

	raw_spin_lock_irqsave(&r4030_lock, flags);
	mask &= r4030_read_reg16(JAZZ_IO_IRQ_ENABLE);
	r4030_write_reg16(JAZZ_IO_IRQ_ENABLE, mask);
	raw_spin_unlock_irqrestore(&r4030_lock, flags);
}

__attribute__((used)) static irqreturn_t r4030_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *cd = dev_id;

	cd->event_handler(cd);
	return IRQ_HANDLED;
}

