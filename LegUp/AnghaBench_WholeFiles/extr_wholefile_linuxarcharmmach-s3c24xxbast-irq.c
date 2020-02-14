#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* chip; } ;
struct irq_desc {TYPE_2__ irq_data; } ;
struct irq_data {size_t irq; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* irq_ack ) (TYPE_2__*) ;} ;

/* Variables and functions */
 int BAST_IRQ_ISA ; 
 int /*<<< orphan*/  BAST_VA_PC104_IRQMASK ; 
 int /*<<< orphan*/  BAST_VA_PC104_IRQREQ ; 
 int __raw_readb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writeb (unsigned long,int /*<<< orphan*/ ) ; 
 unsigned long* bast_pc104_irqmasks ; 
 unsigned int* bast_pc104_irqs ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 struct irq_desc* irq_desc ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_2__*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void
bast_pc104_mask(struct irq_data *data)
{
	unsigned long temp;

	temp = __raw_readb(BAST_VA_PC104_IRQMASK);
	temp &= ~bast_pc104_irqmasks[data->irq];
	__raw_writeb(temp, BAST_VA_PC104_IRQMASK);
}

__attribute__((used)) static void
bast_pc104_maskack(struct irq_data *data)
{
	struct irq_desc *desc = irq_desc + BAST_IRQ_ISA;

	bast_pc104_mask(data);
	desc->irq_data.chip->irq_ack(&desc->irq_data);
}

__attribute__((used)) static void
bast_pc104_unmask(struct irq_data *data)
{
	unsigned long temp;

	temp = __raw_readb(BAST_VA_PC104_IRQMASK);
	temp |= bast_pc104_irqmasks[data->irq];
	__raw_writeb(temp, BAST_VA_PC104_IRQMASK);
}

__attribute__((used)) static void bast_irq_pc104_demux(struct irq_desc *desc)
{
	unsigned int stat;
	unsigned int irqno;
	int i;

	stat = __raw_readb(BAST_VA_PC104_IRQREQ) & 0xf;

	if (unlikely(stat == 0)) {
		/* ack if we get an irq with nothing (ie, startup) */

		desc = irq_desc + BAST_IRQ_ISA;
		desc->irq_data.chip->irq_ack(&desc->irq_data);
	} else {
		/* handle the IRQ */

		for (i = 0; stat != 0; i++, stat >>= 1) {
			if (stat & 1) {
				irqno = bast_pc104_irqs[i];
				generic_handle_irq(irqno);
			}
		}
	}
}

