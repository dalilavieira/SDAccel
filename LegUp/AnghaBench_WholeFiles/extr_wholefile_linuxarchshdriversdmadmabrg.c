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
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {void (* handler ) (void*) ;void* data; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMABRGCR ; 
 unsigned int DMABRGIRQ_A0TXF ; 
 int DMABRGIRQ_USBDMA ; 
 int DMABRGIRQ_USBDMAERR ; 
 int EBUSY ; 
 int ENOENT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int __ffs (unsigned long) ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,int /*<<< orphan*/ ) ; 
 TYPE_1__* dmabrg_handlers ; 
 scalar_t__ likely (int) ; 
 void stub1 (void*) ; 

__attribute__((used)) static inline void dmabrg_call_handler(int i)
{
	dmabrg_handlers[i].handler(dmabrg_handlers[i].data);
}

__attribute__((used)) static irqreturn_t dmabrg_irq(int irq, void *data)
{
	unsigned long dcr;
	unsigned int i;

	dcr = __raw_readl(DMABRGCR);
	__raw_writel(dcr & ~0x00ff0003, DMABRGCR);	/* ack all */
	dcr &= dcr >> 8;	/* ignore masked */

	/* USB stuff, get it out of the way first */
	if (dcr & 1)
		dmabrg_call_handler(DMABRGIRQ_USBDMA);
	if (dcr & 2)
		dmabrg_call_handler(DMABRGIRQ_USBDMAERR);

	/* Audio */
	dcr >>= 16;
	while (dcr) {
		i = __ffs(dcr);
		dcr &= dcr - 1;
		dmabrg_call_handler(i + DMABRGIRQ_A0TXF);
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static void dmabrg_disable_irq(unsigned int dmairq)
{
	unsigned long dcr;
	dcr = __raw_readl(DMABRGCR);
	dcr &= ~(1 << ((dmairq > 1) ? dmairq + 22 : dmairq + 8));
	__raw_writel(dcr, DMABRGCR);
}

__attribute__((used)) static void dmabrg_enable_irq(unsigned int dmairq)
{
	unsigned long dcr;
	dcr = __raw_readl(DMABRGCR);
	dcr |= (1 << ((dmairq > 1) ? dmairq + 22 : dmairq + 8));
	__raw_writel(dcr, DMABRGCR);
}

int dmabrg_request_irq(unsigned int dmairq, void(*handler)(void*),
		       void *data)
{
	if ((dmairq > 9) || !handler)
		return -ENOENT;
	if (dmabrg_handlers[dmairq].handler)
		return -EBUSY;

	dmabrg_handlers[dmairq].handler = handler;
	dmabrg_handlers[dmairq].data = data;
	
	dmabrg_enable_irq(dmairq);
	return 0;
}

void dmabrg_free_irq(unsigned int dmairq)
{
	if (likely(dmairq < 10)) {
		dmabrg_disable_irq(dmairq);
		dmabrg_handlers[dmairq].handler = NULL;
		dmabrg_handlers[dmairq].data = NULL;
	}
}

