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
typedef  int u64 ;
typedef  int u32 ;
struct icst_vco {unsigned int v; int r; size_t s; } ;
struct icst_params {int ref; int* s2div; unsigned int vd_max; unsigned int rd_max; size_t* idx2s; unsigned long vco_min; unsigned long vco_max; unsigned int rd_min; unsigned int vd_min; } ;

/* Variables and functions */
 int /*<<< orphan*/  do_div (int,int) ; 

unsigned long icst_hz(const struct icst_params *p, struct icst_vco vco)
{
	u64 dividend = p->ref * 2 * (u64)(vco.v + 8);
	u32 divisor = (vco.r + 2) * p->s2div[vco.s];

	do_div(dividend, divisor);
	return (unsigned long)dividend;
}

struct icst_vco
icst_hz_to_vco(const struct icst_params *p, unsigned long freq)
{
	struct icst_vco vco = { .s = 1, .v = p->vd_max, .r = p->rd_max };
	unsigned long f;
	unsigned int i = 0, rd, best = (unsigned int)-1;

	/*
	 * First, find the PLL output divisor such
	 * that the PLL output is within spec.
	 */
	do {
		f = freq * p->s2div[p->idx2s[i]];

		if (f > p->vco_min && f <= p->vco_max)
			break;
		i++;
	} while (i < 8);

	if (i >= 8)
		return vco;

	vco.s = p->idx2s[i];

	/*
	 * Now find the closest divisor combination
	 * which gives a PLL output of 'f'.
	 */
	for (rd = p->rd_min; rd <= p->rd_max; rd++) {
		unsigned long fref_div, f_pll;
		unsigned int vd;
		int f_diff;

		fref_div = (2 * p->ref) / rd;

		vd = (f + fref_div / 2) / fref_div;
		if (vd < p->vd_min || vd > p->vd_max)
			continue;

		f_pll = fref_div * vd;
		f_diff = f_pll - f;
		if (f_diff < 0)
			f_diff = -f_diff;

		if ((unsigned)f_diff < best) {
			vco.v = vd - 8;
			vco.r = rd - 2;
			if (f_diff == 0)
				break;
			best = f_diff;
		}
	}

	return vco;
}

