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
 int /*<<< orphan*/  OST_OSCR ; 
 int /*<<< orphan*/  PS2_CNT ; 
 struct clk* clk_get (int /*<<< orphan*/ *,char*) ; 
 int clk_get_rate (struct clk*) ; 
 unsigned long long cnt32_to_63 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

unsigned long long sched_clock(void)
{
	unsigned long long v = cnt32_to_63(readl(OST_OSCR));

	/* original conservative method, but overflow frequently
	 * v *= NSEC_PER_SEC >> 12;
	 * do_div(v, CLOCK_TICK_RATE >> 12);
	 */
	v = ((v & 0x7fffffffffffffffULL) * 2235) >> 5;

	return v;
}

__attribute__((used)) static inline void puv3_init_pm(void) {}

void puv3_ps2_init(void)
{
	struct clk *bclk32;

	bclk32 = clk_get(NULL, "BUS32_CLK");
	writel(clk_get_rate(bclk32) / 200000, PS2_CNT); /* should > 5us */
}

