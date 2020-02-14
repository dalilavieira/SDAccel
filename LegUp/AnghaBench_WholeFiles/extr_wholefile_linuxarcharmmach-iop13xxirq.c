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

__attribute__((used)) static inline void iop13xx_msi_init(void)
{
	return;
}

__attribute__((used)) static u32 read_intctl_0(void)
{
	u32 val;
	asm volatile("mrc p6, 0, %0, c0, c4, 0":"=r" (val));
	return val;
}

__attribute__((used)) static void write_intctl_0(u32 val)
{
	asm volatile("mcr p6, 0, %0, c0, c4, 0"::"r" (val));
}

__attribute__((used)) static u32 read_intctl_1(void)
{
	u32 val;
	asm volatile("mrc p6, 0, %0, c1, c4, 0":"=r" (val));
	return val;
}

__attribute__((used)) static void write_intctl_1(u32 val)
{
	asm volatile("mcr p6, 0, %0, c1, c4, 0"::"r" (val));
}

__attribute__((used)) static u32 read_intctl_2(void)
{
	u32 val;
	asm volatile("mrc p6, 0, %0, c2, c4, 0":"=r" (val));
	return val;
}

__attribute__((used)) static void write_intctl_2(u32 val)
{
	asm volatile("mcr p6, 0, %0, c2, c4, 0"::"r" (val));
}

__attribute__((used)) static u32 read_intctl_3(void)
{
	u32 val;
	asm volatile("mrc p6, 0, %0, c3, c4, 0":"=r" (val));
	return val;
}

__attribute__((used)) static void write_intctl_3(u32 val)
{
	asm volatile("mcr p6, 0, %0, c3, c4, 0"::"r" (val));
}

__attribute__((used)) static void write_intstr_0(u32 val)
{
	asm volatile("mcr p6, 0, %0, c0, c5, 0"::"r" (val));
}

__attribute__((used)) static void write_intstr_1(u32 val)
{
	asm volatile("mcr p6, 0, %0, c1, c5, 0"::"r" (val));
}

__attribute__((used)) static void write_intstr_2(u32 val)
{
	asm volatile("mcr p6, 0, %0, c2, c5, 0"::"r" (val));
}

__attribute__((used)) static void write_intstr_3(u32 val)
{
	asm volatile("mcr p6, 0, %0, c3, c5, 0"::"r" (val));
}

__attribute__((used)) static void write_intbase(u32 val)
{
	asm volatile("mcr p6, 0, %0, c0, c2, 0"::"r" (val));
}

__attribute__((used)) static void write_intsize(u32 val)
{
	asm volatile("mcr p6, 0, %0, c2, c2, 0"::"r" (val));
}

__attribute__((used)) static void
iop13xx_irq_mask0 (struct irq_data *d)
{
	write_intctl_0(read_intctl_0() & ~(1 << (d->irq - 0)));
}

__attribute__((used)) static void
iop13xx_irq_mask1 (struct irq_data *d)
{
	write_intctl_1(read_intctl_1() & ~(1 << (d->irq - 32)));
}

__attribute__((used)) static void
iop13xx_irq_mask2 (struct irq_data *d)
{
	write_intctl_2(read_intctl_2() & ~(1 << (d->irq - 64)));
}

__attribute__((used)) static void
iop13xx_irq_mask3 (struct irq_data *d)
{
	write_intctl_3(read_intctl_3() & ~(1 << (d->irq - 96)));
}

__attribute__((used)) static void
iop13xx_irq_unmask0(struct irq_data *d)
{
	write_intctl_0(read_intctl_0() | (1 << (d->irq - 0)));
}

__attribute__((used)) static void
iop13xx_irq_unmask1(struct irq_data *d)
{
	write_intctl_1(read_intctl_1() | (1 << (d->irq - 32)));
}

__attribute__((used)) static void
iop13xx_irq_unmask2(struct irq_data *d)
{
	write_intctl_2(read_intctl_2() | (1 << (d->irq - 64)));
}

__attribute__((used)) static void
iop13xx_irq_unmask3(struct irq_data *d)
{
	write_intctl_3(read_intctl_3() | (1 << (d->irq - 96)));
}

