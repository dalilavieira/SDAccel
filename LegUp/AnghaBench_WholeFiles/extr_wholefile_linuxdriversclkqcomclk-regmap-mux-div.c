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
typedef  int u8 ;
typedef  int u32 ;
struct clk_hw {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  regmap; struct clk_hw hw; } ;
struct clk_regmap_mux_div {int hid_shift; int src_shift; int* parent_map; int div; int src; int /*<<< orphan*/  hid_width; int /*<<< orphan*/  src_width; scalar_t__ reg_offset; TYPE_1__ clkr; } ;
struct clk_rate_request {unsigned long rate; unsigned long best_parent_rate; struct clk_hw* best_parent_hw; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 scalar_t__ CFG_RCGR ; 
 scalar_t__ CMD_RCGR ; 
 int CMD_RCGR_DIRTY_CFG ; 
 int CMD_RCGR_UPDATE ; 
 int EBUSY ; 
 int EINVAL ; 
 char* clk_hw_get_name (struct clk_hw*) ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 struct clk_hw* clk_hw_get_parent_by_index (struct clk_hw*,int) ; 
 unsigned long clk_hw_get_rate (struct clk_hw*) ; 
 unsigned long clk_hw_round_rate (struct clk_hw*,unsigned long) ; 
 unsigned long mult_frac (unsigned long,int,int) ; 
 int /*<<< orphan*/  pr_err (char*,char const*,...) ; 
 int regmap_read (int /*<<< orphan*/ ,scalar_t__,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,scalar_t__,int,int) ; 
 struct clk_regmap_mux_div* to_clk_regmap_mux_div (struct clk_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 

int mux_div_set_src_div(struct clk_regmap_mux_div *md, u32 src, u32 div)
{
	int ret, count;
	u32 val, mask;
	const char *name = clk_hw_get_name(&md->clkr.hw);

	val = (div << md->hid_shift) | (src << md->src_shift);
	mask = ((BIT(md->hid_width) - 1) << md->hid_shift) |
	       ((BIT(md->src_width) - 1) << md->src_shift);

	ret = regmap_update_bits(md->clkr.regmap, CFG_RCGR + md->reg_offset,
				 mask, val);
	if (ret)
		return ret;

	ret = regmap_update_bits(md->clkr.regmap, CMD_RCGR + md->reg_offset,
				 CMD_RCGR_UPDATE, CMD_RCGR_UPDATE);
	if (ret)
		return ret;

	/* Wait for update to take effect */
	for (count = 500; count > 0; count--) {
		ret = regmap_read(md->clkr.regmap, CMD_RCGR + md->reg_offset,
				  &val);
		if (ret)
			return ret;
		if (!(val & CMD_RCGR_UPDATE))
			return 0;
		udelay(1);
	}

	pr_err("%s: RCG did not update its configuration", name);
	return -EBUSY;
}

__attribute__((used)) static void mux_div_get_src_div(struct clk_regmap_mux_div *md, u32 *src,
				u32 *div)
{
	u32 val, d, s;
	const char *name = clk_hw_get_name(&md->clkr.hw);

	regmap_read(md->clkr.regmap, CMD_RCGR + md->reg_offset, &val);

	if (val & CMD_RCGR_DIRTY_CFG) {
		pr_err("%s: RCG configuration is pending\n", name);
		return;
	}

	regmap_read(md->clkr.regmap, CFG_RCGR + md->reg_offset, &val);
	s = (val >> md->src_shift);
	s &= BIT(md->src_width) - 1;
	*src = s;

	d = (val >> md->hid_shift);
	d &= BIT(md->hid_width) - 1;
	*div = d;
}

__attribute__((used)) static inline bool is_better_rate(unsigned long req, unsigned long best,
				  unsigned long new)
{
	return (req <= new && new < best) || (best < req && best < new);
}

__attribute__((used)) static int mux_div_determine_rate(struct clk_hw *hw,
				  struct clk_rate_request *req)
{
	struct clk_regmap_mux_div *md = to_clk_regmap_mux_div(hw);
	unsigned int i, div, max_div;
	unsigned long actual_rate, best_rate = 0;
	unsigned long req_rate = req->rate;

	for (i = 0; i < clk_hw_get_num_parents(hw); i++) {
		struct clk_hw *parent = clk_hw_get_parent_by_index(hw, i);
		unsigned long parent_rate = clk_hw_get_rate(parent);

		max_div = BIT(md->hid_width) - 1;
		for (div = 1; div < max_div; div++) {
			parent_rate = mult_frac(req_rate, div, 2);
			parent_rate = clk_hw_round_rate(parent, parent_rate);
			actual_rate = mult_frac(parent_rate, 2, div);

			if (is_better_rate(req_rate, best_rate, actual_rate)) {
				best_rate = actual_rate;
				req->rate = best_rate;
				req->best_parent_rate = parent_rate;
				req->best_parent_hw = parent;
			}

			if (actual_rate < req_rate || best_rate <= req_rate)
				break;
		}
	}

	if (!best_rate)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int __mux_div_set_rate_and_parent(struct clk_hw *hw, unsigned long rate,
					 unsigned long prate, u32 src)
{
	struct clk_regmap_mux_div *md = to_clk_regmap_mux_div(hw);
	int ret;
	u32 div, max_div, best_src = 0, best_div = 0;
	unsigned int i;
	unsigned long actual_rate, best_rate = 0;

	for (i = 0; i < clk_hw_get_num_parents(hw); i++) {
		struct clk_hw *parent = clk_hw_get_parent_by_index(hw, i);
		unsigned long parent_rate = clk_hw_get_rate(parent);

		max_div = BIT(md->hid_width) - 1;
		for (div = 1; div < max_div; div++) {
			parent_rate = mult_frac(rate, div, 2);
			parent_rate = clk_hw_round_rate(parent, parent_rate);
			actual_rate = mult_frac(parent_rate, 2, div);

			if (is_better_rate(rate, best_rate, actual_rate)) {
				best_rate = actual_rate;
				best_src = md->parent_map[i];
				best_div = div - 1;
			}

			if (actual_rate < rate || best_rate <= rate)
				break;
		}
	}

	ret = mux_div_set_src_div(md, best_src, best_div);
	if (!ret) {
		md->div = best_div;
		md->src = best_src;
	}

	return ret;
}

__attribute__((used)) static u8 mux_div_get_parent(struct clk_hw *hw)
{
	struct clk_regmap_mux_div *md = to_clk_regmap_mux_div(hw);
	const char *name = clk_hw_get_name(hw);
	u32 i, div, src = 0;

	mux_div_get_src_div(md, &src, &div);

	for (i = 0; i < clk_hw_get_num_parents(hw); i++)
		if (src == md->parent_map[i])
			return i;

	pr_err("%s: Can't find parent with src %d\n", name, src);
	return 0;
}

__attribute__((used)) static int mux_div_set_parent(struct clk_hw *hw, u8 index)
{
	struct clk_regmap_mux_div *md = to_clk_regmap_mux_div(hw);

	return mux_div_set_src_div(md, md->parent_map[index], md->div);
}

__attribute__((used)) static int mux_div_set_rate(struct clk_hw *hw,
			    unsigned long rate, unsigned long prate)
{
	struct clk_regmap_mux_div *md = to_clk_regmap_mux_div(hw);

	return __mux_div_set_rate_and_parent(hw, rate, prate, md->src);
}

__attribute__((used)) static int mux_div_set_rate_and_parent(struct clk_hw *hw,  unsigned long rate,
				       unsigned long prate, u8 index)
{
	struct clk_regmap_mux_div *md = to_clk_regmap_mux_div(hw);

	return __mux_div_set_rate_and_parent(hw, rate, prate,
					     md->parent_map[index]);
}

__attribute__((used)) static unsigned long mux_div_recalc_rate(struct clk_hw *hw, unsigned long prate)
{
	struct clk_regmap_mux_div *md = to_clk_regmap_mux_div(hw);
	u32 div, src;
	int i, num_parents = clk_hw_get_num_parents(hw);
	const char *name = clk_hw_get_name(hw);

	mux_div_get_src_div(md, &src, &div);
	for (i = 0; i < num_parents; i++)
		if (src == md->parent_map[i]) {
			struct clk_hw *p = clk_hw_get_parent_by_index(hw, i);
			unsigned long parent_rate = clk_hw_get_rate(p);

			return mult_frac(parent_rate, 2, div + 1);
		}

	pr_err("%s: Can't find parent %d\n", name, src);
	return 0;
}

