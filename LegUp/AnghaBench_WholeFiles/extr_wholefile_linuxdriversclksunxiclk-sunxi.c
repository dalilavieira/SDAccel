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
typedef  int u8 ;
typedef  scalar_t__ u32 ;
struct factors_request {int rate; int m; int k; int p; int n; int parent_rate; scalar_t__ parent_index; } ;

/* Variables and functions */
 void* DIV_ROUND_UP (int,int) ; 
 scalar_t__ SUN6I_AHB1_PARENT_PLL6 ; 
 int __roundup_pow_of_two (int) ; 
 scalar_t__ order_base_2 (void*) ; 
 scalar_t__ round_down (scalar_t__,int) ; 

__attribute__((used)) static void sun4i_get_pll1_factors(struct factors_request *req)
{
	u8 div;

	/* Normalize value to a 6M multiple */
	div = req->rate / 6000000;
	req->rate = 6000000 * div;

	/* m is always zero for pll1 */
	req->m = 0;

	/* k is 1 only on these cases */
	if (req->rate >= 768000000 || req->rate == 42000000 ||
			req->rate == 54000000)
		req->k = 1;
	else
		req->k = 0;

	/* p will be 3 for divs under 10 */
	if (div < 10)
		req->p = 3;

	/* p will be 2 for divs between 10 - 20 and odd divs under 32 */
	else if (div < 20 || (div < 32 && (div & 1)))
		req->p = 2;

	/* p will be 1 for even divs under 32, divs under 40 and odd pairs
	 * of divs between 40-62 */
	else if (div < 40 || (div < 64 && (div & 2)))
		req->p = 1;

	/* any other entries have p = 0 */
	else
		req->p = 0;

	/* calculate a suitable n based on k and p */
	div <<= req->p;
	div /= (req->k + 1);
	req->n = div / 4;
}

__attribute__((used)) static void sun6i_a31_get_pll1_factors(struct factors_request *req)
{
	/*
	 * We can operate only on MHz, this will make our life easier
	 * later.
	 */
	u32 freq_mhz = req->rate / 1000000;
	u32 parent_freq_mhz = req->parent_rate / 1000000;

	/*
	 * Round down the frequency to the closest multiple of either
	 * 6 or 16
	 */
	u32 round_freq_6 = round_down(freq_mhz, 6);
	u32 round_freq_16 = round_down(freq_mhz, 16);

	if (round_freq_6 > round_freq_16)
		freq_mhz = round_freq_6;
	else
		freq_mhz = round_freq_16;

	req->rate = freq_mhz * 1000000;

	/* If the frequency is a multiple of 32 MHz, k is always 3 */
	if (!(freq_mhz % 32))
		req->k = 3;
	/* If the frequency is a multiple of 9 MHz, k is always 2 */
	else if (!(freq_mhz % 9))
		req->k = 2;
	/* If the frequency is a multiple of 8 MHz, k is always 1 */
	else if (!(freq_mhz % 8))
		req->k = 1;
	/* Otherwise, we don't use the k factor */
	else
		req->k = 0;

	/*
	 * If the frequency is a multiple of 2 but not a multiple of
	 * 3, m is 3. This is the first time we use 6 here, yet we
	 * will use it on several other places.
	 * We use this number because it's the lowest frequency we can
	 * generate (with n = 0, k = 0, m = 3), so every other frequency
	 * somehow relates to this frequency.
	 */
	if ((freq_mhz % 6) == 2 || (freq_mhz % 6) == 4)
		req->m = 2;
	/*
	 * If the frequency is a multiple of 6MHz, but the factor is
	 * odd, m will be 3
	 */
	else if ((freq_mhz / 6) & 1)
		req->m = 3;
	/* Otherwise, we end up with m = 1 */
	else
		req->m = 1;

	/* Calculate n thanks to the above factors we already got */
	req->n = freq_mhz * (req->m + 1) / ((req->k + 1) * parent_freq_mhz)
		 - 1;

	/*
	 * If n end up being outbound, and that we can still decrease
	 * m, do it.
	 */
	if ((req->n + 1) > 31 && (req->m + 1) > 1) {
		req->n = (req->n + 1) / 2 - 1;
		req->m = (req->m + 1) / 2 - 1;
	}
}

__attribute__((used)) static void sun8i_a23_get_pll1_factors(struct factors_request *req)
{
	u8 div;

	/* Normalize value to a 6M multiple */
	div = req->rate / 6000000;
	req->rate = 6000000 * div;

	/* m is always zero for pll1 */
	req->m = 0;

	/* k is 1 only on these cases */
	if (req->rate >= 768000000 || req->rate == 42000000 ||
			req->rate == 54000000)
		req->k = 1;
	else
		req->k = 0;

	/* p will be 2 for divs under 20 and odd divs under 32 */
	if (div < 20 || (div < 32 && (div & 1)))
		req->p = 2;

	/* p will be 1 for even divs under 32, divs under 40 and odd pairs
	 * of divs between 40-62 */
	else if (div < 40 || (div < 64 && (div & 2)))
		req->p = 1;

	/* any other entries have p = 0 */
	else
		req->p = 0;

	/* calculate a suitable n based on k and p */
	div <<= req->p;
	div /= (req->k + 1);
	req->n = div / 4 - 1;
}

__attribute__((used)) static void sun4i_get_pll5_factors(struct factors_request *req)
{
	u8 div;

	/* Normalize value to a parent_rate multiple (24M) */
	div = req->rate / req->parent_rate;
	req->rate = req->parent_rate * div;

	if (div < 31)
		req->k = 0;
	else if (div / 2 < 31)
		req->k = 1;
	else if (div / 3 < 31)
		req->k = 2;
	else
		req->k = 3;

	req->n = DIV_ROUND_UP(div, (req->k + 1));
}

__attribute__((used)) static void sun6i_a31_get_pll6_factors(struct factors_request *req)
{
	u8 div;

	/* Normalize value to a parent_rate multiple (24M) */
	div = req->rate / req->parent_rate;
	req->rate = req->parent_rate * div;

	req->k = div / 32;
	if (req->k > 3)
		req->k = 3;

	req->n = DIV_ROUND_UP(div, (req->k + 1)) - 1;
}

__attribute__((used)) static void sun5i_a13_get_ahb_factors(struct factors_request *req)
{
	u32 div;

	/* divide only */
	if (req->parent_rate < req->rate)
		req->rate = req->parent_rate;

	/*
	 * user manual says valid speed is 8k ~ 276M, but tests show it
	 * can work at speeds up to 300M, just after reparenting to pll6
	 */
	if (req->rate < 8000)
		req->rate = 8000;
	if (req->rate > 300000000)
		req->rate = 300000000;

	div = order_base_2(DIV_ROUND_UP(req->parent_rate, req->rate));

	/* p = 0 ~ 3 */
	if (div > 3)
		div = 3;

	req->rate = req->parent_rate >> div;

	req->p = div;
}

__attribute__((used)) static void sun6i_get_ahb1_factors(struct factors_request *req)
{
	u8 div, calcp, calcm = 1;

	/*
	 * clock can only divide, so we will never be able to achieve
	 * frequencies higher than the parent frequency
	 */
	if (req->parent_rate && req->rate > req->parent_rate)
		req->rate = req->parent_rate;

	div = DIV_ROUND_UP(req->parent_rate, req->rate);

	/* calculate pre-divider if parent is pll6 */
	if (req->parent_index == SUN6I_AHB1_PARENT_PLL6) {
		if (div < 4)
			calcp = 0;
		else if (div / 2 < 4)
			calcp = 1;
		else if (div / 4 < 4)
			calcp = 2;
		else
			calcp = 3;

		calcm = DIV_ROUND_UP(div, 1 << calcp);
	} else {
		calcp = __roundup_pow_of_two(div);
		calcp = calcp > 3 ? 3 : calcp;
	}

	req->rate = (req->parent_rate / calcm) >> calcp;
	req->p = calcp;
	req->m = calcm - 1;
}

__attribute__((used)) static void sun6i_ahb1_recalc(struct factors_request *req)
{
	req->rate = req->parent_rate;

	/* apply pre-divider first if parent is pll6 */
	if (req->parent_index == SUN6I_AHB1_PARENT_PLL6)
		req->rate /= req->m + 1;

	/* clk divider */
	req->rate >>= req->p;
}

__attribute__((used)) static void sun4i_get_apb1_factors(struct factors_request *req)
{
	u8 calcm, calcp;
	int div;

	if (req->parent_rate < req->rate)
		req->rate = req->parent_rate;

	div = DIV_ROUND_UP(req->parent_rate, req->rate);

	/* Invalid rate! */
	if (div > 32)
		return;

	if (div <= 4)
		calcp = 0;
	else if (div <= 8)
		calcp = 1;
	else if (div <= 16)
		calcp = 2;
	else
		calcp = 3;

	calcm = (div >> calcp) - 1;

	req->rate = (req->parent_rate >> calcp) / (calcm + 1);
	req->m = calcm;
	req->p = calcp;
}

__attribute__((used)) static void sun7i_a20_get_out_factors(struct factors_request *req)
{
	u8 div, calcm, calcp;

	/* These clocks can only divide, so we will never be able to achieve
	 * frequencies higher than the parent frequency */
	if (req->rate > req->parent_rate)
		req->rate = req->parent_rate;

	div = DIV_ROUND_UP(req->parent_rate, req->rate);

	if (div < 32)
		calcp = 0;
	else if (div / 2 < 32)
		calcp = 1;
	else if (div / 4 < 32)
		calcp = 2;
	else
		calcp = 3;

	calcm = DIV_ROUND_UP(div, 1 << calcp);

	req->rate = (req->parent_rate >> calcp) / calcm;
	req->m = calcm - 1;
	req->p = calcp;
}

__attribute__((used)) static void sun6i_display_factors(struct factors_request *req)
{
	u8 m;

	if (req->rate > req->parent_rate)
		req->rate = req->parent_rate;

	m = DIV_ROUND_UP(req->parent_rate, req->rate);

	req->rate = req->parent_rate / m;
	req->m = m - 1;
}

