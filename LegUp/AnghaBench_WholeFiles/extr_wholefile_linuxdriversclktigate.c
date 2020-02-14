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
typedef  void* u8 ;
typedef  int u32 ;
struct ti_clk_gate {int flags; void* bit_shift; int /*<<< orphan*/  reg; int /*<<< orphan*/  module; } ;
struct device {int dummy; } ;
struct clk_ops {int dummy; } ;
struct clk_omap_reg {int /*<<< orphan*/  offset; int /*<<< orphan*/  index; } ;
struct clk_omap_divider {int shift; int /*<<< orphan*/  reg; } ;
struct clk_init_data {char const* name; char const** parent_names; int num_parents; unsigned long flags; struct clk_ops const* ops; int /*<<< orphan*/ * member_0; } ;
struct clk_hw_omap_ops {int dummy; } ;
struct clk_hw {struct clk_init_data* init; } ;
struct clk_hw_omap {struct clk_hw hw; struct clk_hw_omap_ops const* ops; void* enable_bit; int /*<<< orphan*/  enable_reg; void* flags; } ;
struct clk {struct clk_init_data* init; } ;
struct TYPE_2__ {int (* clk_readl ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* clk_writel ) (int,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int CLKF_INTERFACE ; 
 int CLKF_NO_WAIT ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct clk_hw* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct clk_hw*) ; 
 struct clk_hw* clk_hw_get_parent (struct clk_hw*) ; 
 struct clk_hw_omap_ops clkhwops_iclk_wait ; 
 struct clk_hw_omap_ops clkhwops_wait ; 
 int /*<<< orphan*/  kfree (struct clk_hw_omap*) ; 
 struct clk_hw_omap* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct clk_omap_reg*,int) ; 
 int omap2_dflt_clk_enable (struct clk_hw*) ; 
 int stub1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub3 (int,int /*<<< orphan*/ *) ; 
 TYPE_1__* ti_clk_ll_ops ; 
 struct clk_hw* ti_clk_register (int /*<<< orphan*/ *,struct clk_hw*,char const*) ; 
 struct clk_omap_divider* to_clk_omap_divider (struct clk_hw*) ; 

__attribute__((used)) static int omap36xx_gate_clk_enable_with_hsdiv_restore(struct clk_hw *hw)
{
	struct clk_omap_divider *parent;
	struct clk_hw *parent_hw;
	u32 dummy_v, orig_v;
	int ret;

	/* Clear PWRDN bit of HSDIVIDER */
	ret = omap2_dflt_clk_enable(hw);

	/* Parent is the x2 node, get parent of parent for the m2 div */
	parent_hw = clk_hw_get_parent(clk_hw_get_parent(hw));
	parent = to_clk_omap_divider(parent_hw);

	/* Restore the dividers */
	if (!ret) {
		orig_v = ti_clk_ll_ops->clk_readl(&parent->reg);
		dummy_v = orig_v;

		/* Write any other value different from the Read value */
		dummy_v ^= (1 << parent->shift);
		ti_clk_ll_ops->clk_writel(dummy_v, &parent->reg);

		/* Write the original divider */
		ti_clk_ll_ops->clk_writel(orig_v, &parent->reg);
	}

	return ret;
}

__attribute__((used)) static struct clk *_register_gate(struct device *dev, const char *name,
				  const char *parent_name, unsigned long flags,
				  struct clk_omap_reg *reg, u8 bit_idx,
				  u8 clk_gate_flags, const struct clk_ops *ops,
				  const struct clk_hw_omap_ops *hw_ops)
{
	struct clk_init_data init = { NULL };
	struct clk_hw_omap *clk_hw;
	struct clk *clk;

	clk_hw = kzalloc(sizeof(*clk_hw), GFP_KERNEL);
	if (!clk_hw)
		return ERR_PTR(-ENOMEM);

	clk_hw->hw.init = &init;

	init.name = name;
	init.ops = ops;

	memcpy(&clk_hw->enable_reg, reg, sizeof(*reg));
	clk_hw->enable_bit = bit_idx;
	clk_hw->ops = hw_ops;

	clk_hw->flags = clk_gate_flags;

	init.parent_names = &parent_name;
	init.num_parents = 1;

	init.flags = flags;

	clk = ti_clk_register(NULL, &clk_hw->hw, name);

	if (IS_ERR(clk))
		kfree(clk_hw);

	return clk;
}

struct clk_hw *ti_clk_build_component_gate(struct ti_clk_gate *setup)
{
	struct clk_hw_omap *gate;
	struct clk_omap_reg *reg;
	const struct clk_hw_omap_ops *ops = &clkhwops_wait;

	if (!setup)
		return NULL;

	gate = kzalloc(sizeof(*gate), GFP_KERNEL);
	if (!gate)
		return ERR_PTR(-ENOMEM);

	reg = (struct clk_omap_reg *)&gate->enable_reg;
	reg->index = setup->module;
	reg->offset = setup->reg;

	gate->enable_bit = setup->bit_shift;

	if (setup->flags & CLKF_NO_WAIT)
		ops = NULL;

	if (setup->flags & CLKF_INTERFACE)
		ops = &clkhwops_iclk_wait;

	gate->ops = ops;

	return &gate->hw;
}

