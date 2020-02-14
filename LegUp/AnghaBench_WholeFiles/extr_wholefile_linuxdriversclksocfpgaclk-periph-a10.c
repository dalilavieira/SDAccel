#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_3__ {scalar_t__ reg; } ;
struct socfpga_periph_clk {int fixed_div; int shift; TYPE_1__ hw; scalar_t__ width; scalar_t__ div_reg; } ;
struct clk_hw {TYPE_2__* init; } ;
struct TYPE_4__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int CLK_MGR_FREE_MASK ; 
 int CLK_MGR_FREE_SHIFT ; 
 int GENMASK (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SOCFPGA_MPU_FREE_CLK ; 
 int /*<<< orphan*/  SOCFPGA_NOC_FREE_CLK ; 
 int /*<<< orphan*/  SOCFPGA_SDMMC_FREE_CLK ; 
 int readl (scalar_t__) ; 
 scalar_t__ streq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct socfpga_periph_clk* to_socfpga_periph_clk (struct clk_hw*) ; 

__attribute__((used)) static unsigned long clk_periclk_recalc_rate(struct clk_hw *hwclk,
					     unsigned long parent_rate)
{
	struct socfpga_periph_clk *socfpgaclk = to_socfpga_periph_clk(hwclk);
	u32 div;

	if (socfpgaclk->fixed_div) {
		div = socfpgaclk->fixed_div;
	} else if (socfpgaclk->div_reg) {
		div = readl(socfpgaclk->div_reg) >> socfpgaclk->shift;
		div &= GENMASK(socfpgaclk->width - 1, 0);
		div += 1;
	} else {
		div = ((readl(socfpgaclk->hw.reg) & 0x7ff) + 1);
	}

	return parent_rate / div;
}

__attribute__((used)) static u8 clk_periclk_get_parent(struct clk_hw *hwclk)
{
	struct socfpga_periph_clk *socfpgaclk = to_socfpga_periph_clk(hwclk);
	u32 clk_src;

	clk_src = readl(socfpgaclk->hw.reg);
	if (streq(hwclk->init->name, SOCFPGA_MPU_FREE_CLK) ||
	    streq(hwclk->init->name, SOCFPGA_NOC_FREE_CLK) ||
	    streq(hwclk->init->name, SOCFPGA_SDMMC_FREE_CLK))
		return (clk_src >> CLK_MGR_FREE_SHIFT) &
			CLK_MGR_FREE_MASK;
	else
		return 0;
}

