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
 int iop33x_mask0 ; 
 int iop33x_mask1 ; 

__attribute__((used)) static void intctl0_write(u32 val)
{
	asm volatile("mcr p6, 0, %0, c0, c0, 0" : : "r" (val));
}

__attribute__((used)) static void intctl1_write(u32 val)
{
	asm volatile("mcr p6, 0, %0, c1, c0, 0" : : "r" (val));
}

__attribute__((used)) static void intstr0_write(u32 val)
{
	asm volatile("mcr p6, 0, %0, c2, c0, 0" : : "r" (val));
}

__attribute__((used)) static void intstr1_write(u32 val)
{
	asm volatile("mcr p6, 0, %0, c3, c0, 0" : : "r" (val));
}

__attribute__((used)) static void intbase_write(u32 val)
{
	asm volatile("mcr p6, 0, %0, c12, c0, 0" : : "r" (val));
}

__attribute__((used)) static void intsize_write(u32 val)
{
	asm volatile("mcr p6, 0, %0, c13, c0, 0" : : "r" (val));
}

__attribute__((used)) static void
iop33x_irq_mask1 (struct irq_data *d)
{
	iop33x_mask0 &= ~(1 << d->irq);
	intctl0_write(iop33x_mask0);
}

__attribute__((used)) static void
iop33x_irq_mask2 (struct irq_data *d)
{
	iop33x_mask1 &= ~(1 << (d->irq - 32));
	intctl1_write(iop33x_mask1);
}

__attribute__((used)) static void
iop33x_irq_unmask1(struct irq_data *d)
{
	iop33x_mask0 |= 1 << d->irq;
	intctl0_write(iop33x_mask0);
}

__attribute__((used)) static void
iop33x_irq_unmask2(struct irq_data *d)
{
	iop33x_mask1 |= (1 << (d->irq - 32));
	intctl1_write(iop33x_mask1);
}

