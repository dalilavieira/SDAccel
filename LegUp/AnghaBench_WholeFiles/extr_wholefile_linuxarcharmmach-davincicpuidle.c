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
struct cpuidle_driver {int dummy; } ;
struct cpuidle_device {int dummy; } ;

/* Variables and functions */
 int DDR2_LPMODEN_BIT ; 
 scalar_t__ DDR2_SDRCR_OFFSET ; 
 int DDR2_SRPD_BIT ; 
 int __raw_readl (scalar_t__) ; 
 int /*<<< orphan*/  __raw_writel (int,scalar_t__) ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int ddr2_pdown ; 
 scalar_t__ ddr2_reg_base ; 

__attribute__((used)) static void davinci_save_ddr_power(int enter, bool pdown)
{
	u32 val;

	val = __raw_readl(ddr2_reg_base + DDR2_SDRCR_OFFSET);

	if (enter) {
		if (pdown)
			val |= DDR2_SRPD_BIT;
		else
			val &= ~DDR2_SRPD_BIT;
		val |= DDR2_LPMODEN_BIT;
	} else {
		val &= ~(DDR2_SRPD_BIT | DDR2_LPMODEN_BIT);
	}

	__raw_writel(val, ddr2_reg_base + DDR2_SDRCR_OFFSET);
}

__attribute__((used)) static int davinci_enter_idle(struct cpuidle_device *dev,
			      struct cpuidle_driver *drv, int index)
{
	davinci_save_ddr_power(1, ddr2_pdown);
	cpu_do_idle();
	davinci_save_ddr_power(0, ddr2_pdown);

	return index;
}

