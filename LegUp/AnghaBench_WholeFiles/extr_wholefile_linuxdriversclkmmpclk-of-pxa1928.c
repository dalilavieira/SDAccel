#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct mmp_clk_unit {int dummy; } ;
struct pxa1928_clk_unit {scalar_t__ apbc_base; scalar_t__ apmu_base; struct mmp_clk_unit unit; scalar_t__ mpmu_base; } ;
struct mmp_clk_reset_cell {int bits; int /*<<< orphan*/  lock; scalar_t__ flags; scalar_t__ reg; int /*<<< orphan*/  clk_id; } ;
struct device_node {int dummy; } ;
struct clk {int dummy; } ;
struct TYPE_16__ {int /*<<< orphan*/  lock; scalar_t__ offset; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  CLK_SET_RATE_PARENT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ MPMU_UART_PLL ; 
 TYPE_1__* apbc_gate_clks ; 
 TYPE_1__* apbc_mux_clks ; 
 TYPE_1__* apmu_div_clks ; 
 TYPE_1__* apmu_gate_clks ; 
 TYPE_1__* apmu_mux_clks ; 
 TYPE_1__* fixed_factor_clks ; 
 TYPE_1__* fixed_rate_clks ; 
 struct mmp_clk_reset_cell* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 struct clk* mmp_clk_register_factor (char*,char*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,TYPE_1__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mmp_register_div_clks (struct mmp_clk_unit*,TYPE_1__*,scalar_t__,int) ; 
 int /*<<< orphan*/  mmp_register_fixed_factor_clks (struct mmp_clk_unit*,TYPE_1__*,int) ; 
 int /*<<< orphan*/  mmp_register_fixed_rate_clks (struct mmp_clk_unit*,TYPE_1__*,int) ; 
 int /*<<< orphan*/  mmp_register_gate_clks (struct mmp_clk_unit*,TYPE_1__*,scalar_t__,int) ; 
 int /*<<< orphan*/  mmp_register_mux_clks (struct mmp_clk_unit*,TYPE_1__*,scalar_t__,int) ; 
 int /*<<< orphan*/  uart_factor_masks ; 
 TYPE_1__* uart_factor_tbl ; 

__attribute__((used)) static inline void mmp_clk_reset_register(struct device_node *np,
			struct mmp_clk_reset_cell *cells, int nr_resets)
{
}

__attribute__((used)) static void pxa1928_pll_init(struct pxa1928_clk_unit *pxa_unit)
{
	struct clk *clk;
	struct mmp_clk_unit *unit = &pxa_unit->unit;

	mmp_register_fixed_rate_clks(unit, fixed_rate_clks,
					ARRAY_SIZE(fixed_rate_clks));

	mmp_register_fixed_factor_clks(unit, fixed_factor_clks,
					ARRAY_SIZE(fixed_factor_clks));

	clk = mmp_clk_register_factor("uart_pll", "pll1_416",
				CLK_SET_RATE_PARENT,
				pxa_unit->mpmu_base + MPMU_UART_PLL,
				&uart_factor_masks, uart_factor_tbl,
				ARRAY_SIZE(uart_factor_tbl), NULL);
}

__attribute__((used)) static void pxa1928_apb_periph_clk_init(struct pxa1928_clk_unit *pxa_unit)
{
	struct mmp_clk_unit *unit = &pxa_unit->unit;

	mmp_register_mux_clks(unit, apbc_mux_clks, pxa_unit->apbc_base,
				ARRAY_SIZE(apbc_mux_clks));

	mmp_register_gate_clks(unit, apbc_gate_clks, pxa_unit->apbc_base,
				ARRAY_SIZE(apbc_gate_clks));
}

__attribute__((used)) static void pxa1928_axi_periph_clk_init(struct pxa1928_clk_unit *pxa_unit)
{
	struct mmp_clk_unit *unit = &pxa_unit->unit;

	mmp_register_mux_clks(unit, apmu_mux_clks, pxa_unit->apmu_base,
				ARRAY_SIZE(apmu_mux_clks));

	mmp_register_div_clks(unit, apmu_div_clks, pxa_unit->apmu_base,
				ARRAY_SIZE(apmu_div_clks));

	mmp_register_gate_clks(unit, apmu_gate_clks, pxa_unit->apmu_base,
				ARRAY_SIZE(apmu_gate_clks));
}

__attribute__((used)) static void pxa1928_clk_reset_init(struct device_node *np,
				struct pxa1928_clk_unit *pxa_unit)
{
	struct mmp_clk_reset_cell *cells;
	int i, base, nr_resets;

	nr_resets = ARRAY_SIZE(apbc_gate_clks);
	cells = kcalloc(nr_resets, sizeof(*cells), GFP_KERNEL);
	if (!cells)
		return;

	base = 0;
	for (i = 0; i < nr_resets; i++) {
		cells[base + i].clk_id = apbc_gate_clks[i].id;
		cells[base + i].reg =
			pxa_unit->apbc_base + apbc_gate_clks[i].offset;
		cells[base + i].flags = 0;
		cells[base + i].lock = apbc_gate_clks[i].lock;
		cells[base + i].bits = 0x4;
	}

	mmp_clk_reset_register(np, cells, nr_resets);
}

