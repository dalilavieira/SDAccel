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
typedef  int u32 ;
struct clk_hw {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  hw; int /*<<< orphan*/  regmap; } ;
struct clk_branch {int halt_check; TYPE_1__ clkr; int /*<<< orphan*/  halt_reg; int /*<<< orphan*/  halt_bit; int /*<<< orphan*/  hwcg_bit; int /*<<< orphan*/  hwcg_reg; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int BRANCH_CLK_OFF ; 
 int BRANCH_HALT ; 
 int BRANCH_HALT_DELAY ; 
 int BRANCH_HALT_ENABLE ; 
 int BRANCH_HALT_SKIP ; 
 int BRANCH_NOC_FSM_STATUS_MASK ; 
 int BRANCH_NOC_FSM_STATUS_ON ; 
 int BRANCH_NOC_FSM_STATUS_SHIFT ; 
 int BRANCH_VOTED ; 
 int EBUSY ; 
 int /*<<< orphan*/  WARN (int,char*,char const*,char*) ; 
 int /*<<< orphan*/  clk_disable_regmap (struct clk_hw*) ; 
 int clk_enable_regmap (struct clk_hw*) ; 
 char* clk_hw_get_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 struct clk_branch* to_clk_branch (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static bool clk_branch_in_hwcg_mode(const struct clk_branch *br)
{
	u32 val;

	if (!br->hwcg_reg)
		return 0;

	regmap_read(br->clkr.regmap, br->hwcg_reg, &val);

	return !!(val & BIT(br->hwcg_bit));
}

__attribute__((used)) static bool clk_branch_check_halt(const struct clk_branch *br, bool enabling)
{
	bool invert = (br->halt_check == BRANCH_HALT_ENABLE);
	u32 val;

	regmap_read(br->clkr.regmap, br->halt_reg, &val);

	val &= BIT(br->halt_bit);
	if (invert)
		val = !val;

	return !!val == !enabling;
}

__attribute__((used)) static bool clk_branch2_check_halt(const struct clk_branch *br, bool enabling)
{
	u32 val;
	u32 mask;

	mask = BRANCH_NOC_FSM_STATUS_MASK << BRANCH_NOC_FSM_STATUS_SHIFT;
	mask |= BRANCH_CLK_OFF;

	regmap_read(br->clkr.regmap, br->halt_reg, &val);

	if (enabling) {
		val &= mask;
		return (val & BRANCH_CLK_OFF) == 0 ||
			val == BRANCH_NOC_FSM_STATUS_ON;
	} else {
		return val & BRANCH_CLK_OFF;
	}
}

__attribute__((used)) static int clk_branch_wait(const struct clk_branch *br, bool enabling,
		bool (check_halt)(const struct clk_branch *, bool))
{
	bool voted = br->halt_check & BRANCH_VOTED;
	const char *name = clk_hw_get_name(&br->clkr.hw);

	/*
	 * Skip checking halt bit if we're explicitly ignoring the bit or the
	 * clock is in hardware gated mode
	 */
	if (br->halt_check == BRANCH_HALT_SKIP || clk_branch_in_hwcg_mode(br))
		return 0;

	if (br->halt_check == BRANCH_HALT_DELAY || (!enabling && voted)) {
		udelay(10);
	} else if (br->halt_check == BRANCH_HALT_ENABLE ||
		   br->halt_check == BRANCH_HALT ||
		   (enabling && voted)) {
		int count = 200;

		while (count-- > 0) {
			if (check_halt(br, enabling))
				return 0;
			udelay(1);
		}
		WARN(1, "%s status stuck at 'o%s'", name,
				enabling ? "ff" : "n");
		return -EBUSY;
	}
	return 0;
}

__attribute__((used)) static int clk_branch_toggle(struct clk_hw *hw, bool en,
		bool (check_halt)(const struct clk_branch *, bool))
{
	struct clk_branch *br = to_clk_branch(hw);
	int ret;

	if (en) {
		ret = clk_enable_regmap(hw);
		if (ret)
			return ret;
	} else {
		clk_disable_regmap(hw);
	}

	return clk_branch_wait(br, en, check_halt);
}

__attribute__((used)) static int clk_branch_enable(struct clk_hw *hw)
{
	return clk_branch_toggle(hw, true, clk_branch_check_halt);
}

__attribute__((used)) static void clk_branch_disable(struct clk_hw *hw)
{
	clk_branch_toggle(hw, false, clk_branch_check_halt);
}

__attribute__((used)) static int clk_branch2_enable(struct clk_hw *hw)
{
	return clk_branch_toggle(hw, true, clk_branch2_check_halt);
}

__attribute__((used)) static void clk_branch2_disable(struct clk_hw *hw)
{
	clk_branch_toggle(hw, false, clk_branch2_check_halt);
}

