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
 int __raw_readl (scalar_t__) ; 
 int __raw_readw (scalar_t__) ; 
 scalar_t__ cprc_base ; 
 unsigned long* ifc_table ; 

__attribute__((used)) static void master_clk_init(struct clk *clk)
{
	int idx = (__raw_readl(cprc_base + 0x00) >> 6) & 0x0007;
	clk->rate *= ifc_table[idx];
}

__attribute__((used)) static unsigned long module_clk_recalc(struct clk *clk)
{
	int idx = (__raw_readw(cprc_base) >> 12) & 0x0007;
	return clk->parent->rate / ifc_table[idx];
}

__attribute__((used)) static unsigned long bus_clk_recalc(struct clk *clk)
{
	int idx = (__raw_readw(cprc_base) >> 3) & 0x0007;
	return clk->parent->rate / ifc_table[idx];
}

__attribute__((used)) static unsigned long cpu_clk_recalc(struct clk *clk)
{
	int idx = (__raw_readw(cprc_base) & 0x0007);
	return clk->parent->rate / ifc_table[idx];
}

