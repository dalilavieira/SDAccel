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
typedef  int u32 ;
struct irq_data {size_t irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  MCFSIM_IMR ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ ) ; 
 int* mcf_irq2imr ; 

void mcf_setimr(int index)
{
	u32 imr;
	imr = __raw_readl(MCFSIM_IMR);
	__raw_writel(imr | (0x1 << index), MCFSIM_IMR);
}

void mcf_clrimr(int index)
{
	u32 imr;
	imr = __raw_readl(MCFSIM_IMR);
	__raw_writel(imr & ~(0x1 << index), MCFSIM_IMR);
}

void mcf_maskimr(unsigned int mask)
{
	u32 imr;
	imr = __raw_readl(MCFSIM_IMR);
	imr |= mask;
	__raw_writel(imr, MCFSIM_IMR);
}

void mcf_autovector(int irq)
{
#ifdef MCFSIM_AVR
	if ((irq >= EIRQ1) && (irq <= EIRQ7)) {
		u8 avec;
		avec = __raw_readb(MCFSIM_AVR);
		avec |= (0x1 << (irq - EIRQ1 + 1));
		__raw_writeb(avec, MCFSIM_AVR);
	}
#endif
}

__attribute__((used)) static void intc_irq_mask(struct irq_data *d)
{
	if (mcf_irq2imr[d->irq])
		mcf_setimr(mcf_irq2imr[d->irq]);
}

__attribute__((used)) static void intc_irq_unmask(struct irq_data *d)
{
	if (mcf_irq2imr[d->irq])
		mcf_clrimr(mcf_irq2imr[d->irq]);
}

__attribute__((used)) static int intc_irq_set_type(struct irq_data *d, unsigned int type)
{
	return 0;
}

