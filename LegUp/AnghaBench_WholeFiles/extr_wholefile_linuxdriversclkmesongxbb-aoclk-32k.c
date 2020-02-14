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
struct clk_hw {int dummy; } ;
struct cec_32k_freq_table {unsigned long parent_rate; unsigned long target_rate; int n1; int n2; int m1; int m2; scalar_t__ dualdiv; } ;
struct aoclk_cec_32k {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  AO_CRT_CLK_CNTL1 ; 
 int /*<<< orphan*/  AO_RTC_ALT_CLK_CNTL0 ; 
 int /*<<< orphan*/  AO_RTC_ALT_CLK_CNTL1 ; 
 int /*<<< orphan*/  AO_RTI_PWR_CNTL_REG0 ; 
 int ARRAY_SIZE (struct cec_32k_freq_table const*) ; 
 int CLK_CNTL0_DUALDIV_EN ; 
 int CLK_CNTL0_IN_GATE_EN ; 
 int CLK_CNTL0_N1_MASK ; 
 int CLK_CNTL0_N2_MASK ; 
 int CLK_CNTL0_OUT_GATE_EN ; 
 int CLK_CNTL1_BYPASS_EN ; 
 int CLK_CNTL1_M1_MASK ; 
 int CLK_CNTL1_M2_MASK ; 
 int CLK_CNTL1_SELECT_OSC ; 
 unsigned long DIV_ROUND_CLOSEST (unsigned long,unsigned long) ; 
 unsigned long DIV_ROUND_UP (int,unsigned long) ; 
 int EINVAL ; 
 int FIELD_GET (int,int) ; 
 int FIELD_PREP (int,int) ; 
 int PWR_CNTL_ALT_32K_SEL ; 
 struct cec_32k_freq_table const* aoclk_cec_32k_table ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct aoclk_cec_32k* to_aoclk_cec_32k (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static unsigned long aoclk_cec_32k_recalc_rate(struct clk_hw *hw,
					       unsigned long parent_rate)
{
	struct aoclk_cec_32k *cec_32k = to_aoclk_cec_32k(hw);
	unsigned long n1;
	u32 reg0, reg1;

	regmap_read(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0, &reg0);
	regmap_read(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL1, &reg1);

	if (reg1 & CLK_CNTL1_BYPASS_EN)
		return parent_rate;

	if (reg0 & CLK_CNTL0_DUALDIV_EN) {
		unsigned long n2, m1, m2, f1, f2, p1, p2;

		n1 = FIELD_GET(CLK_CNTL0_N1_MASK, reg0) + 1;
		n2 = FIELD_GET(CLK_CNTL0_N2_MASK, reg0) + 1;

		m1 = FIELD_GET(CLK_CNTL1_M1_MASK, reg1) + 1;
		m2 = FIELD_GET(CLK_CNTL1_M2_MASK, reg1) + 1;

		f1 = DIV_ROUND_CLOSEST(parent_rate, n1);
		f2 = DIV_ROUND_CLOSEST(parent_rate, n2);

		p1 = DIV_ROUND_CLOSEST(100000000 * m1, f1 * (m1 + m2));
		p2 = DIV_ROUND_CLOSEST(100000000 * m2, f2 * (m1 + m2));

		return DIV_ROUND_UP(100000000, p1 + p2);
	}

	n1 = FIELD_GET(CLK_CNTL0_N1_MASK, reg0) + 1;

	return DIV_ROUND_CLOSEST(parent_rate, n1);
}

__attribute__((used)) static const struct cec_32k_freq_table *find_cec_32k_freq(unsigned long rate,
							  unsigned long prate)
{
	int i;

	for (i = 0 ; i < ARRAY_SIZE(aoclk_cec_32k_table) ; ++i)
		if (aoclk_cec_32k_table[i].parent_rate == prate &&
		    aoclk_cec_32k_table[i].target_rate == rate)
			return &aoclk_cec_32k_table[i];

	return NULL;
}

__attribute__((used)) static long aoclk_cec_32k_round_rate(struct clk_hw *hw, unsigned long rate,
				     unsigned long *prate)
{
	const struct cec_32k_freq_table *freq = find_cec_32k_freq(rate,
								  *prate);

	/* If invalid return first one */
	if (!freq)
		return aoclk_cec_32k_table[0].target_rate;

	return freq->target_rate;
}

__attribute__((used)) static int aoclk_cec_32k_set_rate(struct clk_hw *hw, unsigned long rate,
				  unsigned long parent_rate)
{
	const struct cec_32k_freq_table *freq = find_cec_32k_freq(rate,
								  parent_rate);
	struct aoclk_cec_32k *cec_32k = to_aoclk_cec_32k(hw);
	u32 reg = 0;

	if (!freq)
		return -EINVAL;

	/* Disable clock */
	regmap_update_bits(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0,
			   CLK_CNTL0_IN_GATE_EN | CLK_CNTL0_OUT_GATE_EN, 0);

	reg = FIELD_PREP(CLK_CNTL0_N1_MASK, freq->n1 - 1);
	if (freq->dualdiv)
		reg |= CLK_CNTL0_DUALDIV_EN |
		       FIELD_PREP(CLK_CNTL0_N2_MASK, freq->n2 - 1);

	regmap_write(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0, reg);

	reg = FIELD_PREP(CLK_CNTL1_M1_MASK, freq->m1 - 1);
	if (freq->dualdiv)
		reg |= FIELD_PREP(CLK_CNTL1_M2_MASK, freq->m2 - 1);

	regmap_write(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL1, reg);

	/* Enable clock */
	regmap_update_bits(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0,
			   CLK_CNTL0_IN_GATE_EN, CLK_CNTL0_IN_GATE_EN);

	udelay(200);

	regmap_update_bits(cec_32k->regmap, AO_RTC_ALT_CLK_CNTL0,
			   CLK_CNTL0_OUT_GATE_EN, CLK_CNTL0_OUT_GATE_EN);

	regmap_update_bits(cec_32k->regmap, AO_CRT_CLK_CNTL1,
			   CLK_CNTL1_SELECT_OSC, CLK_CNTL1_SELECT_OSC);

	/* Select 32k from XTAL */
	regmap_update_bits(cec_32k->regmap,
			  AO_RTI_PWR_CNTL_REG0,
			  PWR_CNTL_ALT_32K_SEL,
			  FIELD_PREP(PWR_CNTL_ALT_32K_SEL, 4));

	return 0;
}

