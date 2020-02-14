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
typedef  unsigned long u8 ;
struct regmap {int dummy; } ;
struct clk_master_layout {unsigned int mask; unsigned int pres_shift; } ;
struct TYPE_2__ {unsigned long min; unsigned long max; } ;
struct clk_master_characteristics {unsigned long* divisors; TYPE_1__ output; scalar_t__ have_div3_pres; } ;
struct clk_master {struct regmap* regmap; struct clk_master_characteristics* characteristics; struct clk_master_layout* layout; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 unsigned int AT91_PMC_CSS ; 
 int /*<<< orphan*/  AT91_PMC_MCKR ; 
 unsigned int AT91_PMC_MCKRDY ; 
 int /*<<< orphan*/  AT91_PMC_SR ; 
 unsigned int MASTER_DIV_MASK ; 
 unsigned int MASTER_DIV_SHIFT ; 
 unsigned int MASTER_PRES_MASK ; 
 unsigned long MASTER_PRES_MAX ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/  regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 struct clk_master* to_clk_master (struct clk_hw*) ; 

__attribute__((used)) static inline void pmc_register_id(u8 id) {}

__attribute__((used)) static inline void pmc_register_pck(u8 pck) {}

__attribute__((used)) static inline bool clk_master_ready(struct regmap *regmap)
{
	unsigned int status;

	regmap_read(regmap, AT91_PMC_SR, &status);

	return status & AT91_PMC_MCKRDY ? 1 : 0;
}

__attribute__((used)) static int clk_master_prepare(struct clk_hw *hw)
{
	struct clk_master *master = to_clk_master(hw);

	while (!clk_master_ready(master->regmap))
		cpu_relax();

	return 0;
}

__attribute__((used)) static int clk_master_is_prepared(struct clk_hw *hw)
{
	struct clk_master *master = to_clk_master(hw);

	return clk_master_ready(master->regmap);
}

__attribute__((used)) static unsigned long clk_master_recalc_rate(struct clk_hw *hw,
					    unsigned long parent_rate)
{
	u8 pres;
	u8 div;
	unsigned long rate = parent_rate;
	struct clk_master *master = to_clk_master(hw);
	const struct clk_master_layout *layout = master->layout;
	const struct clk_master_characteristics *characteristics =
						master->characteristics;
	unsigned int mckr;

	regmap_read(master->regmap, AT91_PMC_MCKR, &mckr);
	mckr &= layout->mask;

	pres = (mckr >> layout->pres_shift) & MASTER_PRES_MASK;
	div = (mckr >> MASTER_DIV_SHIFT) & MASTER_DIV_MASK;

	if (characteristics->have_div3_pres && pres == MASTER_PRES_MAX)
		rate /= 3;
	else
		rate >>= pres;

	rate /= characteristics->divisors[div];

	if (rate < characteristics->output.min)
		pr_warn("master clk is underclocked");
	else if (rate > characteristics->output.max)
		pr_warn("master clk is overclocked");

	return rate;
}

__attribute__((used)) static u8 clk_master_get_parent(struct clk_hw *hw)
{
	struct clk_master *master = to_clk_master(hw);
	unsigned int mckr;

	regmap_read(master->regmap, AT91_PMC_MCKR, &mckr);

	return mckr & AT91_PMC_CSS;
}

