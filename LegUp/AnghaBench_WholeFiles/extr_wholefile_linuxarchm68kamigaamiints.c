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
struct TYPE_2__ {int intena; unsigned short intreqr; unsigned short intenar; unsigned short intreq; } ;

/* Variables and functions */
 unsigned short IF_AUD0 ; 
 unsigned short IF_AUD1 ; 
 unsigned short IF_AUD2 ; 
 unsigned short IF_AUD3 ; 
 unsigned short IF_BLIT ; 
 unsigned short IF_COPER ; 
 unsigned short IF_DSKBLK ; 
 unsigned short IF_DSKSYN ; 
 unsigned short IF_RBF ; 
 int IF_SETCLR ; 
 unsigned short IF_SOFT ; 
 unsigned short IF_TBE ; 
 unsigned short IF_VERTB ; 
 int /*<<< orphan*/  IRQ_AMIGA_AUD0 ; 
 int /*<<< orphan*/  IRQ_AMIGA_AUD1 ; 
 int /*<<< orphan*/  IRQ_AMIGA_AUD2 ; 
 int /*<<< orphan*/  IRQ_AMIGA_AUD3 ; 
 int /*<<< orphan*/  IRQ_AMIGA_BLIT ; 
 int /*<<< orphan*/  IRQ_AMIGA_COPPER ; 
 int /*<<< orphan*/  IRQ_AMIGA_DSKBLK ; 
 int /*<<< orphan*/  IRQ_AMIGA_DSKSYN ; 
 int /*<<< orphan*/  IRQ_AMIGA_RBF ; 
 int /*<<< orphan*/  IRQ_AMIGA_SOFT ; 
 int /*<<< orphan*/  IRQ_AMIGA_TBE ; 
 int /*<<< orphan*/  IRQ_AMIGA_VERTB ; 
 int IRQ_USER ; 
 TYPE_1__ amiga_custom ; 
 int /*<<< orphan*/  generic_handle_irq (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void amiga_irq_enable(struct irq_data *data)
{
	amiga_custom.intena = IF_SETCLR | (1 << (data->irq - IRQ_USER));
}

__attribute__((used)) static void amiga_irq_disable(struct irq_data *data)
{
	amiga_custom.intena = 1 << (data->irq - IRQ_USER);
}

__attribute__((used)) static void ami_int1(struct irq_desc *desc)
{
	unsigned short ints = amiga_custom.intreqr & amiga_custom.intenar;

	/* if serial transmit buffer empty, interrupt */
	if (ints & IF_TBE) {
		amiga_custom.intreq = IF_TBE;
		generic_handle_irq(IRQ_AMIGA_TBE);
	}

	/* if floppy disk transfer complete, interrupt */
	if (ints & IF_DSKBLK) {
		amiga_custom.intreq = IF_DSKBLK;
		generic_handle_irq(IRQ_AMIGA_DSKBLK);
	}

	/* if software interrupt set, interrupt */
	if (ints & IF_SOFT) {
		amiga_custom.intreq = IF_SOFT;
		generic_handle_irq(IRQ_AMIGA_SOFT);
	}
}

__attribute__((used)) static void ami_int3(struct irq_desc *desc)
{
	unsigned short ints = amiga_custom.intreqr & amiga_custom.intenar;

	/* if a blitter interrupt */
	if (ints & IF_BLIT) {
		amiga_custom.intreq = IF_BLIT;
		generic_handle_irq(IRQ_AMIGA_BLIT);
	}

	/* if a copper interrupt */
	if (ints & IF_COPER) {
		amiga_custom.intreq = IF_COPER;
		generic_handle_irq(IRQ_AMIGA_COPPER);
	}

	/* if a vertical blank interrupt */
	if (ints & IF_VERTB) {
		amiga_custom.intreq = IF_VERTB;
		generic_handle_irq(IRQ_AMIGA_VERTB);
	}
}

__attribute__((used)) static void ami_int4(struct irq_desc *desc)
{
	unsigned short ints = amiga_custom.intreqr & amiga_custom.intenar;

	/* if audio 0 interrupt */
	if (ints & IF_AUD0) {
		amiga_custom.intreq = IF_AUD0;
		generic_handle_irq(IRQ_AMIGA_AUD0);
	}

	/* if audio 1 interrupt */
	if (ints & IF_AUD1) {
		amiga_custom.intreq = IF_AUD1;
		generic_handle_irq(IRQ_AMIGA_AUD1);
	}

	/* if audio 2 interrupt */
	if (ints & IF_AUD2) {
		amiga_custom.intreq = IF_AUD2;
		generic_handle_irq(IRQ_AMIGA_AUD2);
	}

	/* if audio 3 interrupt */
	if (ints & IF_AUD3) {
		amiga_custom.intreq = IF_AUD3;
		generic_handle_irq(IRQ_AMIGA_AUD3);
	}
}

__attribute__((used)) static void ami_int5(struct irq_desc *desc)
{
	unsigned short ints = amiga_custom.intreqr & amiga_custom.intenar;

	/* if serial receive buffer full interrupt */
	if (ints & IF_RBF) {
		/* acknowledge of IF_RBF must be done by the serial interrupt */
		generic_handle_irq(IRQ_AMIGA_RBF);
	}

	/* if a disk sync interrupt */
	if (ints & IF_DSKSYN) {
		amiga_custom.intreq = IF_DSKSYN;
		generic_handle_irq(IRQ_AMIGA_DSKSYN);
	}
}

