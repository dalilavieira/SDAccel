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
 int iop32x_mask ; 

__attribute__((used)) static void intctl_write(u32 val)
{
	asm volatile("mcr p6, 0, %0, c0, c0, 0" : : "r" (val));
}

__attribute__((used)) static void intstr_write(u32 val)
{
	asm volatile("mcr p6, 0, %0, c4, c0, 0" : : "r" (val));
}

__attribute__((used)) static void
iop32x_irq_mask(struct irq_data *d)
{
	iop32x_mask &= ~(1 << d->irq);
	intctl_write(iop32x_mask);
}

__attribute__((used)) static void
iop32x_irq_unmask(struct irq_data *d)
{
	iop32x_mask |= 1 << d->irq;
	intctl_write(iop32x_mask);
}

