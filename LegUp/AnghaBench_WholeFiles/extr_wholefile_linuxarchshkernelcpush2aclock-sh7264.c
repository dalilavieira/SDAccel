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
struct clk {TYPE_1__* parent; } ;
struct TYPE_2__ {unsigned long rate; } ;

/* Variables and functions */
 int /*<<< orphan*/  FRQCR ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 unsigned long pll1_div ; 
 unsigned long* pll1rate ; 

__attribute__((used)) static unsigned long pll_recalc(struct clk *clk)
{
	unsigned long rate = clk->parent->rate / pll1_div;
	return rate * pll1rate[(__raw_readw(FRQCR) >> 8) & 1];
}

