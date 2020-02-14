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
typedef  int u32 ;
typedef  int u16 ;
struct irq_data {unsigned int irq; } ;

/* Variables and functions */
 unsigned int EINT0 ; 
 unsigned int EINT1 ; 
 unsigned int EINT7 ; 
#define  IRQ_TYPE_EDGE_BOTH 130 
#define  IRQ_TYPE_EDGE_FALLING 129 
#define  IRQ_TYPE_EDGE_RISING 128 
 unsigned long MCFEPORT_EPDDR ; 
 unsigned long MCFEPORT_EPFR ; 
 unsigned long MCFEPORT_EPIER ; 
 int /*<<< orphan*/  MCFEPORT_EPPAR ; 
 unsigned long MCFICM_INTC0 ; 
 scalar_t__ MCFINTC_ICR0 ; 
 scalar_t__ MCFINTC_IMRH ; 
 scalar_t__ MCFINTC_IMRL ; 
 unsigned int MCFINT_VECBASE ; 
 scalar_t__ __raw_readb (unsigned long) ; 
 int __raw_readl (unsigned long) ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writeb (int,unsigned long) ; 
 int /*<<< orphan*/  __raw_writel (int,unsigned long) ; 
 int /*<<< orphan*/  __raw_writew (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  intc_intpri ; 
 int /*<<< orphan*/  irq_set_handler (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void intc_irq_mask(struct irq_data *d)
{
	unsigned int irq = d->irq - MCFINT_VECBASE;
	unsigned long imraddr;
	u32 val, imrbit;

#ifdef MCFICM_INTC1
	imraddr = (irq & 0x40) ? MCFICM_INTC1 : MCFICM_INTC0;
#else
	imraddr = MCFICM_INTC0;
#endif
	imraddr += (irq & 0x20) ? MCFINTC_IMRH : MCFINTC_IMRL;
	imrbit = 0x1 << (irq & 0x1f);

	val = __raw_readl(imraddr);
	__raw_writel(val | imrbit, imraddr);
}

__attribute__((used)) static void intc_irq_unmask(struct irq_data *d)
{
	unsigned int irq = d->irq - MCFINT_VECBASE;
	unsigned long imraddr;
	u32 val, imrbit;

#ifdef MCFICM_INTC1
	imraddr = (irq & 0x40) ? MCFICM_INTC1 : MCFICM_INTC0;
#else
	imraddr = MCFICM_INTC0;
#endif
	imraddr += ((irq & 0x20) ? MCFINTC_IMRH : MCFINTC_IMRL);
	imrbit = 0x1 << (irq & 0x1f);

	/* Don't set the "maskall" bit! */
	if ((irq & 0x20) == 0)
		imrbit |= 0x1;

	val = __raw_readl(imraddr);
	__raw_writel(val & ~imrbit, imraddr);
}

__attribute__((used)) static void intc_irq_ack(struct irq_data *d)
{
	unsigned int irq = d->irq;

	__raw_writeb(0x1 << (irq - EINT0), MCFEPORT_EPFR);
}

__attribute__((used)) static unsigned int intc_irq_startup(struct irq_data *d)
{
	unsigned int irq = d->irq - MCFINT_VECBASE;
	unsigned long icraddr;

#ifdef MCFICM_INTC1
	icraddr = (irq & 0x40) ? MCFICM_INTC1 : MCFICM_INTC0;
#else
	icraddr = MCFICM_INTC0;
#endif
	icraddr += MCFINTC_ICR0 + (irq & 0x3f);
	if (__raw_readb(icraddr) == 0)
		__raw_writeb(intc_intpri--, icraddr);

	irq = d->irq;
	if ((irq >= EINT1) && (irq <= EINT7)) {
		u8 v;

		irq -= EINT0;

		/* Set EPORT line as input */
		v = __raw_readb(MCFEPORT_EPDDR);
		__raw_writeb(v & ~(0x1 << irq), MCFEPORT_EPDDR);

		/* Set EPORT line as interrupt source */
		v = __raw_readb(MCFEPORT_EPIER);
		__raw_writeb(v | (0x1 << irq), MCFEPORT_EPIER);
	}

	intc_irq_unmask(d);
	return 0;
}

__attribute__((used)) static int intc_irq_set_type(struct irq_data *d, unsigned int type)
{
	unsigned int irq = d->irq;
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

	irq -= EINT0;
	pa = __raw_readw(MCFEPORT_EPPAR);
	pa = (pa & ~(0x3 << (irq * 2))) | (tb << (irq * 2));
	__raw_writew(pa, MCFEPORT_EPPAR);
	
	return 0;
}

