#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
struct mmp_clk_unit {int dummy; } ;
struct mmp_clk_reset_cell {int bits; int /*<<< orphan*/  lock; scalar_t__ flags; scalar_t__ reg; int /*<<< orphan*/  clk_id; } ;
struct mmp2_clk_unit {scalar_t__ apbc_base; scalar_t__ apmu_base; struct mmp_clk_unit unit; scalar_t__ mpmu_base; } ;
struct device_node {int dummy; } ;
struct clk {int dummy; } ;
struct TYPE_24__ {scalar_t__ reg_clk_ctrl; } ;
struct TYPE_26__ {TYPE_1__ reg_info; } ;
struct TYPE_25__ {int /*<<< orphan*/  lock; scalar_t__ offset; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 scalar_t__ APMU_CCIC0 ; 
 scalar_t__ APMU_CCIC1 ; 
 scalar_t__ APMU_SDH0 ; 
 int ARRAY_SIZE (TYPE_2__*) ; 
 int /*<<< orphan*/  CLK_SET_RATE_PARENT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MMP2_CLK_CCIC0_MIX ; 
 int /*<<< orphan*/  MMP2_CLK_CCIC1_MIX ; 
 int /*<<< orphan*/  MMP2_CLK_UART_PLL ; 
 scalar_t__ MPMU_UART_PLL ; 
 TYPE_2__* apbc_gate_clks ; 
 TYPE_2__* apbc_mux_clks ; 
 TYPE_2__* apmu_div_clks ; 
 TYPE_2__* apmu_gate_clks ; 
 TYPE_2__* apmu_mux_clks ; 
 int /*<<< orphan*/  ccic0_lock ; 
 TYPE_4__ ccic0_mix_config ; 
 int /*<<< orphan*/  ccic1_lock ; 
 TYPE_4__ ccic1_mix_config ; 
 TYPE_2__* ccic_parent_names ; 
 TYPE_2__* fixed_factor_clks ; 
 TYPE_2__* fixed_rate_clks ; 
 struct mmp_clk_reset_cell* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmp_clk_add (struct mmp_clk_unit*,int /*<<< orphan*/ ,struct clk*) ; 
 struct clk* mmp_clk_register_factor (char*,char*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,TYPE_2__*,int,int /*<<< orphan*/ *) ; 
 struct clk* mmp_clk_register_mix (int /*<<< orphan*/ *,char*,TYPE_2__*,int,int /*<<< orphan*/ ,TYPE_4__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mmp_register_div_clks (struct mmp_clk_unit*,TYPE_2__*,scalar_t__,int) ; 
 int /*<<< orphan*/  mmp_register_fixed_factor_clks (struct mmp_clk_unit*,TYPE_2__*,int) ; 
 int /*<<< orphan*/  mmp_register_fixed_rate_clks (struct mmp_clk_unit*,TYPE_2__*,int) ; 
 int /*<<< orphan*/  mmp_register_gate_clks (struct mmp_clk_unit*,TYPE_2__*,scalar_t__,int) ; 
 int /*<<< orphan*/  mmp_register_mux_clks (struct mmp_clk_unit*,TYPE_2__*,scalar_t__,int) ; 
 int /*<<< orphan*/  sdh_lock ; 
 TYPE_4__ sdh_mix_config ; 
 TYPE_2__* sdh_parent_names ; 
 int /*<<< orphan*/  uart_factor_masks ; 
 TYPE_2__* uart_factor_tbl ; 

__attribute__((used)) static inline void mmp_clk_reset_register(struct device_node *np,
			struct mmp_clk_reset_cell *cells, int nr_resets)
{
}

__attribute__((used)) static void mmp2_pll_init(struct mmp2_clk_unit *pxa_unit)
{
	struct clk *clk;
	struct mmp_clk_unit *unit = &pxa_unit->unit;

	mmp_register_fixed_rate_clks(unit, fixed_rate_clks,
					ARRAY_SIZE(fixed_rate_clks));

	mmp_register_fixed_factor_clks(unit, fixed_factor_clks,
					ARRAY_SIZE(fixed_factor_clks));

	clk = mmp_clk_register_factor("uart_pll", "pll1_4",
				CLK_SET_RATE_PARENT,
				pxa_unit->mpmu_base + MPMU_UART_PLL,
				&uart_factor_masks, uart_factor_tbl,
				ARRAY_SIZE(uart_factor_tbl), NULL);
	mmp_clk_add(unit, MMP2_CLK_UART_PLL, clk);
}

__attribute__((used)) static void mmp2_apb_periph_clk_init(struct mmp2_clk_unit *pxa_unit)
{
	struct mmp_clk_unit *unit = &pxa_unit->unit;

	mmp_register_mux_clks(unit, apbc_mux_clks, pxa_unit->apbc_base,
				ARRAY_SIZE(apbc_mux_clks));

	mmp_register_gate_clks(unit, apbc_gate_clks, pxa_unit->apbc_base,
				ARRAY_SIZE(apbc_gate_clks));
}

__attribute__((used)) static void mmp2_axi_periph_clk_init(struct mmp2_clk_unit *pxa_unit)
{
	struct clk *clk;
	struct mmp_clk_unit *unit = &pxa_unit->unit;

	sdh_mix_config.reg_info.reg_clk_ctrl = pxa_unit->apmu_base + APMU_SDH0;
	clk = mmp_clk_register_mix(NULL, "sdh_mix_clk", sdh_parent_names,
					ARRAY_SIZE(sdh_parent_names),
					CLK_SET_RATE_PARENT,
					&sdh_mix_config, &sdh_lock);

	ccic0_mix_config.reg_info.reg_clk_ctrl = pxa_unit->apmu_base + APMU_CCIC0;
	clk = mmp_clk_register_mix(NULL, "ccic0_mix_clk", ccic_parent_names,
					ARRAY_SIZE(ccic_parent_names),
					CLK_SET_RATE_PARENT,
					&ccic0_mix_config, &ccic0_lock);
	mmp_clk_add(unit, MMP2_CLK_CCIC0_MIX, clk);

	ccic1_mix_config.reg_info.reg_clk_ctrl = pxa_unit->apmu_base + APMU_CCIC1;
	clk = mmp_clk_register_mix(NULL, "ccic1_mix_clk", ccic_parent_names,
					ARRAY_SIZE(ccic_parent_names),
					CLK_SET_RATE_PARENT,
					&ccic1_mix_config, &ccic1_lock);
	mmp_clk_add(unit, MMP2_CLK_CCIC1_MIX, clk);

	mmp_register_mux_clks(unit, apmu_mux_clks, pxa_unit->apmu_base,
				ARRAY_SIZE(apmu_mux_clks));

	mmp_register_div_clks(unit, apmu_div_clks, pxa_unit->apmu_base,
				ARRAY_SIZE(apmu_div_clks));

	mmp_register_gate_clks(unit, apmu_gate_clks, pxa_unit->apmu_base,
				ARRAY_SIZE(apmu_gate_clks));
}

__attribute__((used)) static void mmp2_clk_reset_init(struct device_node *np,
				struct mmp2_clk_unit *pxa_unit)
{
	struct mmp_clk_reset_cell *cells;
	int i, nr_resets;

	nr_resets = ARRAY_SIZE(apbc_gate_clks);
	cells = kcalloc(nr_resets, sizeof(*cells), GFP_KERNEL);
	if (!cells)
		return;

	for (i = 0; i < nr_resets; i++) {
		cells[i].clk_id = apbc_gate_clks[i].id;
		cells[i].reg = pxa_unit->apbc_base + apbc_gate_clks[i].offset;
		cells[i].flags = 0;
		cells[i].lock = apbc_gate_clks[i].lock;
		cells[i].bits = 0x4;
	}

	mmp_clk_reset_register(np, cells, nr_resets);
}

