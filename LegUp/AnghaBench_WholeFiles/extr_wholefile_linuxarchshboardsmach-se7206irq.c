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
struct irq_data {unsigned int irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTC_IPR01 ; 
 int /*<<< orphan*/  INTMSK0 ; 
 int /*<<< orphan*/  INTMSK1 ; 
 int /*<<< orphan*/  INTSTS0 ; 
 int /*<<< orphan*/  INTSTS1 ; 
#define  IRQ0_IRQ 130 
#define  IRQ1_IRQ 129 
#define  IRQ3_IRQ 128 
 unsigned short __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writew (unsigned short,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disable_irq_nosync (unsigned int) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 struct irq_data* irq_get_irq_data (unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler_name (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  irqd_irq_disabled (struct irq_data*) ; 
 int /*<<< orphan*/  irqd_irq_inprogress (struct irq_data*) ; 
 int /*<<< orphan*/  se7206_irq_chip ; 

__attribute__((used)) static void disable_se7206_irq(struct irq_data *data)
{
	unsigned int irq = data->irq;
	unsigned short val;
	unsigned short mask = 0xffff ^ (0x0f << 4 * (3 - (IRQ0_IRQ - irq)));
	unsigned short msk0,msk1;

	/* Set the priority in IPR to 0 */
	val = __raw_readw(INTC_IPR01);
	val &= mask;
	__raw_writew(val, INTC_IPR01);
	/* FPGA mask set */
	msk0 = __raw_readw(INTMSK0);
	msk1 = __raw_readw(INTMSK1);

	switch (irq) {
	case IRQ0_IRQ:
		msk0 |= 0x0010;
		break;
	case IRQ1_IRQ:
		msk0 |= 0x000f;
		break;
	case IRQ3_IRQ:
		msk0 |= 0x0f00;
		msk1 |= 0x00ff;
		break;
	}
	__raw_writew(msk0, INTMSK0);
	__raw_writew(msk1, INTMSK1);
}

__attribute__((used)) static void enable_se7206_irq(struct irq_data *data)
{
	unsigned int irq = data->irq;
	unsigned short val;
	unsigned short value = (0x0001 << 4 * (3 - (IRQ0_IRQ - irq)));
	unsigned short msk0,msk1;

	/* Set priority in IPR back to original value */
	val = __raw_readw(INTC_IPR01);
	val |= value;
	__raw_writew(val, INTC_IPR01);

	/* FPGA mask reset */
	msk0 = __raw_readw(INTMSK0);
	msk1 = __raw_readw(INTMSK1);

	switch (irq) {
	case IRQ0_IRQ:
		msk0 &= ~0x0010;
		break;
	case IRQ1_IRQ:
		msk0 &= ~0x000f;
		break;
	case IRQ3_IRQ:
		msk0 &= ~0x0f00;
		msk1 &= ~0x00ff;
		break;
	}
	__raw_writew(msk0, INTMSK0);
	__raw_writew(msk1, INTMSK1);
}

__attribute__((used)) static void eoi_se7206_irq(struct irq_data *data)
{
	unsigned short sts0,sts1;
	unsigned int irq = data->irq;

	if (!irqd_irq_disabled(data) && !irqd_irq_inprogress(data))
		enable_se7206_irq(data);
	/* FPGA isr clear */
	sts0 = __raw_readw(INTSTS0);
	sts1 = __raw_readw(INTSTS1);

	switch (irq) {
	case IRQ0_IRQ:
		sts0 &= ~0x0010;
		break;
	case IRQ1_IRQ:
		sts0 &= ~0x000f;
		break;
	case IRQ3_IRQ:
		sts0 &= ~0x0f00;
		sts1 &= ~0x00ff;
		break;
	}
	__raw_writew(sts0, INTSTS0);
	__raw_writew(sts1, INTSTS1);
}

__attribute__((used)) static void make_se7206_irq(unsigned int irq)
{
	disable_irq_nosync(irq);
	irq_set_chip_and_handler_name(irq, &se7206_irq_chip,
				      handle_level_irq, "level");
	disable_se7206_irq(irq_get_irq_data(irq));
}

