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
struct clk_omap_reg {int offset; } ;
struct clk_hw_omap {int enable_bit; int /*<<< orphan*/  enable_reg; } ;
typedef  int /*<<< orphan*/  r ;
struct TYPE_2__ {int (* clk_readl ) (struct clk_omap_reg*) ;int /*<<< orphan*/  (* clk_writel ) (int,struct clk_omap_reg*) ;} ;

/* Variables and functions */
 int CM_AUTOIDLE ; 
 int CM_ICLKEN ; 
 int CM_IDLEST ; 
 int OMAP24XX_CM_FCLKEN2 ; 
 int OMAP24XX_CM_IDLEST_VAL ; 
 int /*<<< orphan*/  memcpy (struct clk_omap_reg*,int /*<<< orphan*/ *,int) ; 
 int stub1 (struct clk_omap_reg*) ; 
 int /*<<< orphan*/  stub2 (int,struct clk_omap_reg*) ; 
 int stub3 (struct clk_omap_reg*) ; 
 int /*<<< orphan*/  stub4 (int,struct clk_omap_reg*) ; 
 TYPE_1__* ti_clk_ll_ops ; 

void omap2_clkt_iclk_allow_idle(struct clk_hw_omap *clk)
{
	u32 v;
	struct clk_omap_reg r;

	memcpy(&r, &clk->enable_reg, sizeof(r));
	r.offset ^= (CM_AUTOIDLE ^ CM_ICLKEN);

	v = ti_clk_ll_ops->clk_readl(&r);
	v |= (1 << clk->enable_bit);
	ti_clk_ll_ops->clk_writel(v, &r);
}

void omap2_clkt_iclk_deny_idle(struct clk_hw_omap *clk)
{
	u32 v;
	struct clk_omap_reg r;

	memcpy(&r, &clk->enable_reg, sizeof(r));

	r.offset ^= (CM_AUTOIDLE ^ CM_ICLKEN);

	v = ti_clk_ll_ops->clk_readl(&r);
	v &= ~(1 << clk->enable_bit);
	ti_clk_ll_ops->clk_writel(v, &r);
}

__attribute__((used)) static void omap2430_clk_i2chs_find_idlest(struct clk_hw_omap *clk,
					   struct clk_omap_reg *idlest_reg,
					   u8 *idlest_bit,
					   u8 *idlest_val)
{
	memcpy(idlest_reg, &clk->enable_reg, sizeof(*idlest_reg));
	idlest_reg->offset ^= (OMAP24XX_CM_FCLKEN2 ^ CM_IDLEST);
	*idlest_bit = clk->enable_bit;
	*idlest_val = OMAP24XX_CM_IDLEST_VAL;
}

