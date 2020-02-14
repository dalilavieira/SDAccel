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
typedef  int u16 ;
struct irq_data {unsigned int irq; } ;

/* Variables and functions */
 unsigned int EINT0 ; 
 unsigned int EINT1 ; 
 unsigned int EINT7 ; 
#define  IRQ_TYPE_EDGE_BOTH 130 
#define  IRQ_TYPE_EDGE_FALLING 129 
#define  IRQ_TYPE_EDGE_RISING 128 
 scalar_t__ MCFEPORT_EPFR ; 
 scalar_t__ MCFEPORT_EPIER ; 
 int /*<<< orphan*/  MCFEPORT_EPPAR ; 
 scalar_t__ MCFINTC0_CIMR ; 
 scalar_t__ MCFINTC0_ICR0 ; 
 scalar_t__ MCFINTC0_SIMR ; 
 scalar_t__ MCFINTC1_CIMR ; 
 scalar_t__ MCFINTC1_ICR0 ; 
 scalar_t__ MCFINTC1_SIMR ; 
 scalar_t__ MCFINTC2_CIMR ; 
 scalar_t__ MCFINTC2_ICR0 ; 
 scalar_t__ MCFINTC2_SIMR ; 
 unsigned int MCFINT_VECBASE ; 
 int __raw_readb (scalar_t__) ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  __raw_writew (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  irq_set_handler (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned int irq2ebit(unsigned int irq)
{
	return irq - EINT0;
}

__attribute__((used)) static void intc_irq_mask(struct irq_data *d)
{
	unsigned int irq = d->irq - MCFINT_VECBASE;

	if (MCFINTC2_SIMR && (irq > 128))
		__raw_writeb(irq - 128, MCFINTC2_SIMR);
	else if (MCFINTC1_SIMR && (irq > 64))
		__raw_writeb(irq - 64, MCFINTC1_SIMR);
	else
		__raw_writeb(irq, MCFINTC0_SIMR);
}

__attribute__((used)) static void intc_irq_unmask(struct irq_data *d)
{
	unsigned int irq = d->irq - MCFINT_VECBASE;

	if (MCFINTC2_CIMR && (irq > 128))
		__raw_writeb(irq - 128, MCFINTC2_CIMR);
	else if (MCFINTC1_CIMR && (irq > 64))
		__raw_writeb(irq - 64, MCFINTC1_CIMR);
	else
		__raw_writeb(irq, MCFINTC0_CIMR);
}

__attribute__((used)) static void intc_irq_ack(struct irq_data *d)
{
	unsigned int ebit = irq2ebit(d->irq);

	__raw_writeb(0x1 << ebit, MCFEPORT_EPFR);
}

__attribute__((used)) static unsigned int intc_irq_startup(struct irq_data *d)
{
	unsigned int irq = d->irq;

	if ((irq >= EINT1) && (irq <= EINT7)) {
		unsigned int ebit = irq2ebit(irq);
		u8 v;

#if defined(MCFEPORT_EPDDR)
		/* Set EPORT line as input */
		v = __raw_readb(MCFEPORT_EPDDR);
		__raw_writeb(v & ~(0x1 << ebit), MCFEPORT_EPDDR);
#endif

		/* Set EPORT line as interrupt source */
		v = __raw_readb(MCFEPORT_EPIER);
		__raw_writeb(v | (0x1 << ebit), MCFEPORT_EPIER);
	}

	irq -= MCFINT_VECBASE;
	if (MCFINTC2_ICR0 && (irq > 128))
		__raw_writeb(5, MCFINTC2_ICR0 + irq - 128);
	else if (MCFINTC1_ICR0 && (irq > 64))
		__raw_writeb(5, MCFINTC1_ICR0 + irq - 64);
	else
		__raw_writeb(5, MCFINTC0_ICR0 + irq);

	intc_irq_unmask(d);
	return 0;
}

__attribute__((used)) static int intc_irq_set_type(struct irq_data *d, unsigned int type)
{
	unsigned int ebit, irq = d->irq;
	u16 pa, tb;

	switch (type) {
	case IRQ_TYPE_EDGE_RISING:
		tb = 0x1;
		break;
	case IRQ_TYPE_EDGE_FALLING:
		tb = 0x2;
		break;
	case IRQ_TYPE_EDGE_BOTH:
		tb = 0x3;
		break;
	default:
		/* Level triggered */
		tb = 0;
		break;
	}

	if (tb)
		irq_set_handler(irq, handle_edge_irq);

	ebit = irq2ebit(irq) * 2;
	pa = __raw_readw(MCFEPORT_EPPAR);
	pa = (pa & ~(0x3 << ebit)) | (tb << ebit);
	__raw_writew(pa, MCFEPORT_EPPAR);
	
	return 0;
}

