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
struct clk {unsigned long rate; TYPE_1__* parent; } ;
struct TYPE_2__ {unsigned long rate; } ;

/* Variables and functions */
 int /*<<< orphan*/  FRQCR ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 unsigned long* bfc_divisors ; 
 unsigned long* ifc_divisors ; 
 unsigned long* pfc_divisors ; 

__attribute__((used)) static void master_clk_init(struct clk *clk)
{
	clk->rate *= pfc_divisors[__raw_readl(FRQCR) & 0x0003];
}

__attribute__((used)) static unsigned long module_clk_recalc(struct clk *clk)
{
	int idx = (__raw_readl(FRQCR) & 0x0003);
	return clk->parent->rate / pfc_divisors[idx];
}

__attribute__((used)) static unsigned long bus_clk_recalc(struct clk *clk)
{
	int idx = ((__raw_readl(FRQCR) >> 16) & 0x0007);
	return clk->parent->rate / bfc_divisors[idx];
}

__attribute__((used)) static unsigned long cpu_clk_recalc(struct clk *clk)
{
	int idx = ((__raw_readl(FRQCR) >> 24) & 0x0001);
	return clk->parent->rate / ifc_divisors[idx];
}

