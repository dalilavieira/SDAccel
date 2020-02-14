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
struct of_phandle_args {int args_count; size_t* args; } ;
struct clk_sp810_timerclken {int /*<<< orphan*/  channel; struct clk_sp810* sp810; } ;
struct clk_sp810 {TYPE_1__* timerclken; int /*<<< orphan*/  lock; scalar_t__ base; } ;
struct clk_hw {int dummy; } ;
struct clk {int dummy; } ;
struct TYPE_2__ {struct clk* clk; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 scalar_t__ SCCTRL ; 
 int SCCTRL_TIMERENnSEL_SHIFT (int /*<<< orphan*/ ) ; 
 scalar_t__ WARN_ON (int) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct clk_sp810_timerclken* to_clk_sp810_timerclken (struct clk_hw*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static u8 clk_sp810_timerclken_get_parent(struct clk_hw *hw)
{
	struct clk_sp810_timerclken *timerclken = to_clk_sp810_timerclken(hw);
	u32 val = readl(timerclken->sp810->base + SCCTRL);

	return !!(val & (1 << SCCTRL_TIMERENnSEL_SHIFT(timerclken->channel)));
}

__attribute__((used)) static int clk_sp810_timerclken_set_parent(struct clk_hw *hw, u8 index)
{
	struct clk_sp810_timerclken *timerclken = to_clk_sp810_timerclken(hw);
	struct clk_sp810 *sp810 = timerclken->sp810;
	u32 val, shift = SCCTRL_TIMERENnSEL_SHIFT(timerclken->channel);
	unsigned long flags = 0;

	if (WARN_ON(index > 1))
		return -EINVAL;

	spin_lock_irqsave(&sp810->lock, flags);

	val = readl(sp810->base + SCCTRL);
	val &= ~(1 << shift);
	val |= index << shift;
	writel(val, sp810->base + SCCTRL);

	spin_unlock_irqrestore(&sp810->lock, flags);

	return 0;
}

__attribute__((used)) static struct clk *clk_sp810_timerclken_of_get(struct of_phandle_args *clkspec,
		void *data)
{
	struct clk_sp810 *sp810 = data;

	if (WARN_ON(clkspec->args_count != 1 ||
		    clkspec->args[0] >=	ARRAY_SIZE(sp810->timerclken)))
		return NULL;

	return sp810->timerclken[clkspec->args[0]].clk;
}

