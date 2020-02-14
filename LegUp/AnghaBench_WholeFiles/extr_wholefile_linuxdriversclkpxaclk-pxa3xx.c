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
typedef  int /*<<< orphan*/  u8 ;
struct clk_hw {int dummy; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 unsigned long AC97_DIV ; 
 unsigned long ACCR_D0CS ; 
 unsigned long ACCR_XL_MASK ; 
 unsigned long ACCR_XN_MASK ; 
 unsigned long ACSR ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 unsigned int KHz ; 
 int /*<<< orphan*/  MEMCLKCFG ; 
 int /*<<< orphan*/  PXA_BUS_60Mhz ; 
 int /*<<< orphan*/  PXA_BUS_HSS ; 
 int /*<<< orphan*/  PXA_CORE_60Mhz ; 
 int /*<<< orphan*/  PXA_CORE_RUN ; 
 int /*<<< orphan*/  PXA_CORE_TURBO ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 struct clk* clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 unsigned long clk_get_rate (struct clk*) ; 
 int /*<<< orphan*/  clk_put (struct clk*) ; 
 unsigned long* df_clkdiv ; 
 int /*<<< orphan*/ * get_freq_khz ; 
 unsigned long* hss_mult ; 
 int /*<<< orphan*/  pr_info (char*,unsigned long,unsigned int,...) ; 
 unsigned long* smcfs_mult ; 

__attribute__((used)) static inline int dummy_clk_set_parent(struct clk_hw *hw, u8 index)
{
	return 0;
}

unsigned int pxa3xx_get_clk_frequency_khz(int info)
{
	struct clk *clk;
	unsigned long clks[5];
	int i;

	for (i = 0; i < 5; i++) {
		clk = clk_get(NULL, get_freq_khz[i]);
		if (IS_ERR(clk)) {
			clks[i] = 0;
		} else {
			clks[i] = clk_get_rate(clk);
			clk_put(clk);
		}
	}
	if (info) {
		pr_info("RO Mode clock: %ld.%02ldMHz\n",
			clks[1] / 1000000, (clks[0] % 1000000) / 10000);
		pr_info("Run Mode clock: %ld.%02ldMHz\n",
			clks[2] / 1000000, (clks[1] % 1000000) / 10000);
		pr_info("Turbo Mode clock: %ld.%02ldMHz\n",
			clks[3] / 1000000, (clks[2] % 1000000) / 10000);
		pr_info("System bus clock: %ld.%02ldMHz\n",
			clks[4] / 1000000, (clks[4] % 1000000) / 10000);
	}
	return (unsigned int)clks[0] / KHz;
}

__attribute__((used)) static unsigned long clk_pxa3xx_ac97_get_rate(struct clk_hw *hw,
					     unsigned long parent_rate)
{
	unsigned long ac97_div, rate;

	ac97_div = AC97_DIV;

	/* This may loose precision for some rates but won't for the
	 * standard 24.576MHz.
	 */
	rate = parent_rate / 2;
	rate /= ((ac97_div >> 12) & 0x7fff);
	rate *= (ac97_div & 0xfff);

	return rate;
}

__attribute__((used)) static unsigned long clk_pxa3xx_smemc_get_rate(struct clk_hw *hw,
					      unsigned long parent_rate)
{
	unsigned long acsr = ACSR;
	unsigned long memclkcfg = __raw_readl(MEMCLKCFG);

	return (parent_rate / 48)  * smcfs_mult[(acsr >> 23) & 0x7] /
		df_clkdiv[(memclkcfg >> 16) & 0x3];
}

__attribute__((used)) static bool pxa3xx_is_ring_osc_forced(void)
{
	unsigned long acsr = ACSR;

	return acsr & ACCR_D0CS;
}

__attribute__((used)) static unsigned long clk_pxa3xx_system_bus_get_rate(struct clk_hw *hw,
					    unsigned long parent_rate)
{
	unsigned long acsr = ACSR;
	unsigned int hss = (acsr >> 14) & 0x3;

	if (pxa3xx_is_ring_osc_forced())
		return parent_rate;
	return parent_rate / 48 * hss_mult[hss];
}

__attribute__((used)) static u8 clk_pxa3xx_system_bus_get_parent(struct clk_hw *hw)
{
	if (pxa3xx_is_ring_osc_forced())
		return PXA_BUS_60Mhz;
	else
		return PXA_BUS_HSS;
}

__attribute__((used)) static unsigned long clk_pxa3xx_core_get_rate(struct clk_hw *hw,
					      unsigned long parent_rate)
{
	return parent_rate;
}

__attribute__((used)) static u8 clk_pxa3xx_core_get_parent(struct clk_hw *hw)
{
	unsigned long xclkcfg;
	unsigned int t;

	if (pxa3xx_is_ring_osc_forced())
		return PXA_CORE_60Mhz;

	/* Read XCLKCFG register turbo bit */
	__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
	t = xclkcfg & 0x1;

	if (t)
		return PXA_CORE_TURBO;
	return PXA_CORE_RUN;
}

__attribute__((used)) static unsigned long clk_pxa3xx_run_get_rate(struct clk_hw *hw,
					     unsigned long parent_rate)
{
	unsigned long acsr = ACSR;
	unsigned int xn = (acsr & ACCR_XN_MASK) >> 8;
	unsigned int t, xclkcfg;

	/* Read XCLKCFG register turbo bit */
	__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
	t = xclkcfg & 0x1;

	return t ? (parent_rate / xn) * 2 : parent_rate;
}

__attribute__((used)) static unsigned long clk_pxa3xx_cpll_get_rate(struct clk_hw *hw,
	unsigned long parent_rate)
{
	unsigned long acsr = ACSR;
	unsigned int xn = (acsr & ACCR_XN_MASK) >> 8;
	unsigned int xl = acsr & ACCR_XL_MASK;
	unsigned int t, xclkcfg;

	/* Read XCLKCFG register turbo bit */
	__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
	t = xclkcfg & 0x1;

	pr_info("RJK: parent_rate=%lu, xl=%u, xn=%u\n", parent_rate, xl, xn);
	return t ? parent_rate * xl * xn : parent_rate * xl;
}

