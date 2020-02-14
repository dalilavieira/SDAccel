#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct clk {unsigned long rate; TYPE_2__* parent; TYPE_1__* ops; } ;
struct TYPE_4__ {unsigned long rate; } ;
struct TYPE_3__ {scalar_t__ (* set_rate ) (struct clk*,int) ;} ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned long*) ; 
 int /*<<< orphan*/  CPG2_FRQCR3 ; 
 int EINVAL ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,int /*<<< orphan*/ ) ; 
 struct clk* clk_get (int /*<<< orphan*/ *,char*) ; 
 unsigned long clk_get_rate (struct clk*) ; 
 int /*<<< orphan*/  clk_put (struct clk*) ; 
 unsigned long* frqcr3_divisors ; 
 int* frqcr3_values ; 
 scalar_t__ stub1 (struct clk*,int) ; 

__attribute__((used)) static unsigned long emi_clk_recalc(struct clk *clk)
{
	int idx = __raw_readl(CPG2_FRQCR3) & 0x0007;
	return clk->parent->rate / frqcr3_divisors[idx];
}

__attribute__((used)) static inline int frqcr3_lookup(struct clk *clk, unsigned long rate)
{
	int divisor = clk->parent->rate / rate;
	int i;

	for (i = 0; i < ARRAY_SIZE(frqcr3_divisors); i++)
		if (frqcr3_divisors[i] == divisor)
			return frqcr3_values[i];

	/* Safe fallback */
	return 5;
}

__attribute__((used)) static unsigned long femi_clk_recalc(struct clk *clk)
{
	int idx = (__raw_readl(CPG2_FRQCR3) >> 3) & 0x0007;
	return clk->parent->rate / frqcr3_divisors[idx];
}

__attribute__((used)) static void shoc_clk_init(struct clk *clk)
{
	int i;

	/*
	 * For some reason, the shoc_clk seems to be set to some really
	 * insane value at boot (values outside of the allowable frequency
	 * range for instance). We deal with this by scaling it back down
	 * to something sensible just in case.
	 *
	 * Start scaling from the high end down until we find something
	 * that passes rate verification..
	 */
	for (i = 0; i < ARRAY_SIZE(frqcr3_divisors); i++) {
		int divisor = frqcr3_divisors[i];

		if (clk->ops->set_rate(clk, clk->parent->rate / divisor) == 0)
			break;
	}

	WARN_ON(i == ARRAY_SIZE(frqcr3_divisors));	/* Undefined clock */
}

__attribute__((used)) static unsigned long shoc_clk_recalc(struct clk *clk)
{
	int idx = (__raw_readl(CPG2_FRQCR3) >> 6) & 0x0007;
	return clk->parent->rate / frqcr3_divisors[idx];
}

__attribute__((used)) static int shoc_clk_verify_rate(struct clk *clk, unsigned long rate)
{
	struct clk *bclk = clk_get(NULL, "bus_clk");
	unsigned long bclk_rate = clk_get_rate(bclk);

	clk_put(bclk);

	if (rate > bclk_rate)
		return 1;
	if (rate > 66000000)
		return 1;

	return 0;
}

__attribute__((used)) static int shoc_clk_set_rate(struct clk *clk, unsigned long rate)
{
	unsigned long frqcr3;
	unsigned int tmp;

	/* Make sure we have something sensible to switch to */
	if (shoc_clk_verify_rate(clk, rate) != 0)
		return -EINVAL;

	tmp = frqcr3_lookup(clk, rate);

	frqcr3 = __raw_readl(CPG2_FRQCR3);
	frqcr3 &= ~(0x0007 << 6);
	frqcr3 |= tmp << 6;
	__raw_writel(frqcr3, CPG2_FRQCR3);

	clk->rate = clk->parent->rate / frqcr3_divisors[tmp];

	return 0;
}

