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
typedef  int volatile u32 ;
struct irq_data {int irq; } ;

/* Variables and functions */
 int volatile C_IRQ0 ; 
 int volatile C_IRQ1 ; 
 int volatile C_IRQ2 ; 
 int volatile C_IRQ3 ; 
 int volatile C_IRQ5 ; 
 int /*<<< orphan*/  IE_IRQ0 ; 
 int /*<<< orphan*/  IE_IRQ1 ; 
 int MIPS_CPU_IRQ_BASE ; 
 scalar_t__ SNI_PCIT_INT_REG ; 
 int SNI_PCIT_INT_START ; 
 int /*<<< orphan*/  clear_c0_status (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_IRQ (int) ; 
 int ffs (int volatile) ; 
 scalar_t__ likely (int) ; 
 int read_c0_cause () ; 
 int read_c0_status () ; 
 int /*<<< orphan*/  set_c0_status (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void enable_pcit_irq(struct irq_data *d)
{
	u32 mask = 1 << (d->irq - SNI_PCIT_INT_START + 24);

	*(volatile u32 *)SNI_PCIT_INT_REG |= mask;
}

void disable_pcit_irq(struct irq_data *d)
{
	u32 mask = 1 << (d->irq - SNI_PCIT_INT_START + 24);

	*(volatile u32 *)SNI_PCIT_INT_REG &= ~mask;
}

__attribute__((used)) static void pcit_hwint1(void)
{
	u32 pending = *(volatile u32 *)SNI_PCIT_INT_REG;
	int irq;

	clear_c0_status(IE_IRQ1);
	irq = ffs((pending >> 16) & 0x7f);

	if (likely(irq > 0))
		do_IRQ(irq + SNI_PCIT_INT_START - 1);
	set_c0_status(IE_IRQ1);
}

__attribute__((used)) static void pcit_hwint0(void)
{
	u32 pending = *(volatile u32 *)SNI_PCIT_INT_REG;
	int irq;

	clear_c0_status(IE_IRQ0);
	irq = ffs((pending >> 16) & 0x3f);

	if (likely(irq > 0))
		do_IRQ(irq + SNI_PCIT_INT_START - 1);
	set_c0_status(IE_IRQ0);
}

__attribute__((used)) static void sni_pcit_hwint(void)
{
	u32 pending = read_c0_cause() & read_c0_status();

	if (pending & C_IRQ1)
		pcit_hwint1();
	else if (pending & C_IRQ2)
		do_IRQ(MIPS_CPU_IRQ_BASE + 4);
	else if (pending & C_IRQ3)
		do_IRQ(MIPS_CPU_IRQ_BASE + 5);
	else if (pending & C_IRQ5)
		do_IRQ(MIPS_CPU_IRQ_BASE + 7);
}

__attribute__((used)) static void sni_pcit_hwint_cplus(void)
{
	u32 pending = read_c0_cause() & read_c0_status();

	if (pending & C_IRQ0)
		pcit_hwint0();
	else if (pending & C_IRQ1)
		do_IRQ(MIPS_CPU_IRQ_BASE + 3);
	else if (pending & C_IRQ2)
		do_IRQ(MIPS_CPU_IRQ_BASE + 4);
	else if (pending & C_IRQ3)
		do_IRQ(MIPS_CPU_IRQ_BASE + 5);
	else if (pending & C_IRQ5)
		do_IRQ(MIPS_CPU_IRQ_BASE + 7);
}

