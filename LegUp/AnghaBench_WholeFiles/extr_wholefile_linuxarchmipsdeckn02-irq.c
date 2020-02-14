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
struct irq_data {int irq; } ;

/* Variables and functions */
 scalar_t__ CKSEG1ADDR (scalar_t__) ; 
 scalar_t__ KN02_CSR ; 
 scalar_t__ KN02_SLOT_BASE ; 
 int cached_kn02_csr ; 
 int /*<<< orphan*/  iob () ; 
 int kn02_irq_base ; 

__attribute__((used)) static void unmask_kn02_irq(struct irq_data *d)
{
	volatile u32 *csr = (volatile u32 *)CKSEG1ADDR(KN02_SLOT_BASE +
						       KN02_CSR);

	cached_kn02_csr |= (1 << (d->irq - kn02_irq_base + 16));
	*csr = cached_kn02_csr;
}

__attribute__((used)) static void mask_kn02_irq(struct irq_data *d)
{
	volatile u32 *csr = (volatile u32 *)CKSEG1ADDR(KN02_SLOT_BASE +
						       KN02_CSR);

	cached_kn02_csr &= ~(1 << (d->irq - kn02_irq_base + 16));
	*csr = cached_kn02_csr;
}

__attribute__((used)) static void ack_kn02_irq(struct irq_data *d)
{
	mask_kn02_irq(d);
	iob();
}

