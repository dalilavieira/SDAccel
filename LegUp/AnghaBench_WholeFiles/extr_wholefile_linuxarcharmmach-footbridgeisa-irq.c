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
struct irq_desc {int dummy; } ;
struct irq_data {int irq; } ;

/* Variables and functions */
 scalar_t__ PCIIACK_BASE ; 
 int /*<<< orphan*/  PIC_HI ; 
 int /*<<< orphan*/  PIC_LO ; 
 int /*<<< orphan*/  PIC_MASK_HI ; 
 int /*<<< orphan*/  PIC_MASK_LO ; 
 unsigned int _ISA_IRQ (int) ; 
 int /*<<< orphan*/  do_bad_IRQ (struct irq_desc*) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 unsigned int inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void isa_mask_pic_lo_irq(struct irq_data *d)
{
	unsigned int mask = 1 << (d->irq & 7);

	outb(inb(PIC_MASK_LO) | mask, PIC_MASK_LO);
}

__attribute__((used)) static void isa_ack_pic_lo_irq(struct irq_data *d)
{
	unsigned int mask = 1 << (d->irq & 7);

	outb(inb(PIC_MASK_LO) | mask, PIC_MASK_LO);
	outb(0x20, PIC_LO);
}

__attribute__((used)) static void isa_unmask_pic_lo_irq(struct irq_data *d)
{
	unsigned int mask = 1 << (d->irq & 7);

	outb(inb(PIC_MASK_LO) & ~mask, PIC_MASK_LO);
}

__attribute__((used)) static void isa_mask_pic_hi_irq(struct irq_data *d)
{
	unsigned int mask = 1 << (d->irq & 7);

	outb(inb(PIC_MASK_HI) | mask, PIC_MASK_HI);
}

__attribute__((used)) static void isa_ack_pic_hi_irq(struct irq_data *d)
{
	unsigned int mask = 1 << (d->irq & 7);

	outb(inb(PIC_MASK_HI) | mask, PIC_MASK_HI);
	outb(0x62, PIC_LO);
	outb(0x20, PIC_HI);
}

__attribute__((used)) static void isa_unmask_pic_hi_irq(struct irq_data *d)
{
	unsigned int mask = 1 << (d->irq & 7);

	outb(inb(PIC_MASK_HI) & ~mask, PIC_MASK_HI);
}

__attribute__((used)) static void isa_irq_handler(struct irq_desc *desc)
{
	unsigned int isa_irq = *(unsigned char *)PCIIACK_BASE;

	if (isa_irq < _ISA_IRQ(0) || isa_irq >= _ISA_IRQ(16)) {
		do_bad_IRQ(desc);
		return;
	}

	generic_handle_irq(isa_irq);
}

