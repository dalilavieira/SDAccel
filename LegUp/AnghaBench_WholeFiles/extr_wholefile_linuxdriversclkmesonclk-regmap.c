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
struct clk_regmap_mux_data {unsigned int shift; unsigned int mask; int /*<<< orphan*/  flags; int /*<<< orphan*/  offset; int /*<<< orphan*/  table; } ;
struct clk_regmap_gate_data {int flags; int /*<<< orphan*/  bit_idx; int /*<<< orphan*/  offset; } ;
struct clk_regmap_div_data {unsigned int shift; int flags; int /*<<< orphan*/  width; int /*<<< orphan*/  offset; int /*<<< orphan*/  table; } ;
struct clk_regmap {int /*<<< orphan*/  map; scalar_t__ data; } ;
struct clk_rate_request {int dummy; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int CLK_DIVIDER_READ_ONLY ; 
 int CLK_GATE_SET_TO_DISABLE ; 
 unsigned int clk_div_mask (int /*<<< orphan*/ ) ; 
 int clk_mux_determine_rate_flags (struct clk_hw*,struct clk_rate_request*,int /*<<< orphan*/ ) ; 
 unsigned int clk_mux_index_to_val (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int clk_mux_val_to_index (struct clk_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int divider_get_val (unsigned long,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 unsigned long divider_recalc_rate (struct clk_hw*,unsigned long,unsigned int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 long divider_ro_round_rate (struct clk_hw*,unsigned long,unsigned long*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned int) ; 
 long divider_round_rate (struct clk_hw*,unsigned long,unsigned long*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct clk_regmap* to_clk_regmap (struct clk_hw*) ; 

__attribute__((used)) static inline struct clk_regmap_gate_data *
clk_get_regmap_gate_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_gate_data *)clk->data;
}

__attribute__((used)) static inline struct clk_regmap_div_data *
clk_get_regmap_div_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_div_data *)clk->data;
}

__attribute__((used)) static inline struct clk_regmap_mux_data *
clk_get_regmap_mux_data(struct clk_regmap *clk)
{
	return (struct clk_regmap_mux_data *)clk->data;
}

__attribute__((used)) static int clk_regmap_gate_endisable(struct clk_hw *hw, int enable)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct clk_regmap_gate_data *gate = clk_get_regmap_gate_data(clk);
	int set = gate->flags & CLK_GATE_SET_TO_DISABLE ? 1 : 0;

	set ^= enable;

	return regmap_update_bits(clk->map, gate->offset, BIT(gate->bit_idx),
				  set ? BIT(gate->bit_idx) : 0);
}

__attribute__((used)) static int clk_regmap_gate_enable(struct clk_hw *hw)
{
	return clk_regmap_gate_endisable(hw, 1);
}

__attribute__((used)) static void clk_regmap_gate_disable(struct clk_hw *hw)
{
	clk_regmap_gate_endisable(hw, 0);
}

__attribute__((used)) static int clk_regmap_gate_is_enabled(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct clk_regmap_gate_data *gate = clk_get_regmap_gate_data(clk);
	unsigned int val;

	regmap_read(clk->map, gate->offset, &val);
	if (gate->flags & CLK_GATE_SET_TO_DISABLE)
		val ^= BIT(gate->bit_idx);

	val &= BIT(gate->bit_idx);

	return val ? 1 : 0;
}

__attribute__((used)) static unsigned long clk_regmap_div_recalc_rate(struct clk_hw *hw,
						unsigned long prate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct clk_regmap_div_data *div = clk_get_regmap_div_data(clk);
	unsigned int val;
	int ret;

	ret = regmap_read(clk->map, div->offset, &val);
	if (ret)
		/* Gives a hint that something is wrong */
		return 0;

	val >>= div->shift;
	val &= clk_div_mask(div->width);
	return divider_recalc_rate(hw, prate, val, div->table, div->flags,
				   div->width);
}

__attribute__((used)) static long clk_regmap_div_round_rate(struct clk_hw *hw, unsigned long rate,
				      unsigned long *prate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct clk_regmap_div_data *div = clk_get_regmap_div_data(clk);
	unsigned int val;
	int ret;

	/* if read only, just return current value */
	if (div->flags & CLK_DIVIDER_READ_ONLY) {
		ret = regmap_read(clk->map, div->offset, &val);
		if (ret)
			/* Gives a hint that something is wrong */
			return 0;

		val >>= div->shift;
		val &= clk_div_mask(div->width);

		return divider_ro_round_rate(hw, rate, prate, div->table,
					     div->width, div->flags, val);
	}

	return divider_round_rate(hw, rate, prate, div->table, div->width,
				  div->flags);
}

__attribute__((used)) static int clk_regmap_div_set_rate(struct clk_hw *hw, unsigned long rate,
				   unsigned long parent_rate)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct clk_regmap_div_data *div = clk_get_regmap_div_data(clk);
	unsigned int val;
	int ret;

	ret = divider_get_val(rate, parent_rate, div->table, div->width,
			      div->flags);
	if (ret < 0)
		return ret;

	val = (unsigned int)ret << div->shift;
	return regmap_update_bits(clk->map, div->offset,
				  clk_div_mask(div->width) << div->shift, val);
}

__attribute__((used)) static u8 clk_regmap_mux_get_parent(struct clk_hw *hw)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct clk_regmap_mux_data *mux = clk_get_regmap_mux_data(clk);
	unsigned int val;
	int ret;

	ret = regmap_read(clk->map, mux->offset, &val);
	if (ret)
		return ret;

	val >>= mux->shift;
	val &= mux->mask;
	return clk_mux_val_to_index(hw, mux->table, mux->flags, val);
}

__attribute__((used)) static int clk_regmap_mux_set_parent(struct clk_hw *hw, u8 index)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct clk_regmap_mux_data *mux = clk_get_regmap_mux_data(clk);
	unsigned int val = clk_mux_index_to_val(mux->table, mux->flags, index);

	return regmap_update_bits(clk->map, mux->offset,
				  mux->mask << mux->shift,
				  val << mux->shift);
}

__attribute__((used)) static int clk_regmap_mux_determine_rate(struct clk_hw *hw,
					 struct clk_rate_request *req)
{
	struct clk_regmap *clk = to_clk_regmap(hw);
	struct clk_regmap_mux_data *mux = clk_get_regmap_mux_data(clk);

	return clk_mux_determine_rate_flags(hw, req, mux->flags);
}

