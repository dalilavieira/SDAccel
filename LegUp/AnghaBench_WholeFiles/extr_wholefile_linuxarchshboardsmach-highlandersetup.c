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
struct clk {int dummy; } ;

/* Variables and functions */
 int HL_NR_IRL ; 
 int IVDR_CK_ON ; 
 int /*<<< orphan*/  PA_IVDRCTL ; 
 int /*<<< orphan*/  PA_POFF ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writew (int,int /*<<< orphan*/ ) ; 
 int* irl2irq ; 
 scalar_t__ mach_is_r7780mp () ; 
 scalar_t__ mach_is_r7785rp () ; 

__attribute__((used)) static int ivdr_clk_enable(struct clk *clk)
{
	__raw_writew(__raw_readw(PA_IVDRCTL) | (1 << IVDR_CK_ON), PA_IVDRCTL);
	return 0;
}

__attribute__((used)) static void ivdr_clk_disable(struct clk *clk)
{
	__raw_writew(__raw_readw(PA_IVDRCTL) & ~(1 << IVDR_CK_ON), PA_IVDRCTL);
}

__attribute__((used)) static void r7780rp_power_off(void)
{
	if (mach_is_r7780mp() || mach_is_r7785rp())
		__raw_writew(0x0001, PA_POFF);
}

__attribute__((used)) static int highlander_irq_demux(int irq)
{
	if (irq >= HL_NR_IRL || irq < 0 || !irl2irq[irq])
		return irq;

	return irl2irq[irq];
}

