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
struct ocelot {int shared_queue_sz; int* base_mac; int /*<<< orphan*/  num_stats; int /*<<< orphan*/  stats_layout; int /*<<< orphan*/  map; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HSIO_PLL5G_CFG0 ; 
 int HSIO_PLL5G_CFG0_CORE_CLK_DIV (int) ; 
 int HSIO_PLL5G_CFG0_CPU_CLK_DIV (int) ; 
 int HSIO_PLL5G_CFG0_DIV4 ; 
 int HSIO_PLL5G_CFG0_ENA_BIAS ; 
 int HSIO_PLL5G_CFG0_ENA_CLKTREE ; 
 int HSIO_PLL5G_CFG0_ENA_CP1 ; 
 int HSIO_PLL5G_CFG0_ENA_LANE ; 
 int HSIO_PLL5G_CFG0_ENA_VCO_BUF ; 
 int HSIO_PLL5G_CFG0_LOOP_BW_RES (int) ; 
 int HSIO_PLL5G_CFG0_SELBGV820 (int) ; 
 int HSIO_PLL5G_CFG0_SELCPI (int) ; 
 int /*<<< orphan*/  HSIO_PLL5G_CFG2 ; 
 int HSIO_PLL5G_CFG2_AMPC_SEL (int) ; 
 int HSIO_PLL5G_CFG2_ENA_AMPCTRL ; 
 int HSIO_PLL5G_CFG2_EN_RESET_FRQ_DET ; 
 int HSIO_PLL5G_CFG2_EN_RESET_OVERRUN ; 
 int HSIO_PLL5G_CFG2_GAIN_TEST (int) ; 
 int HSIO_PLL5G_CFG2_PWD_AMPCTRL_N ; 
 int /*<<< orphan*/  HSIO_PLL5G_CFG4 ; 
 int HSIO_PLL5G_CFG4_IB_BIAS_CTRL (int) ; 
 int HSIO_PLL5G_CFG4_IB_CTRL (int) ; 
 int /*<<< orphan*/  eth_random_addr (int*) ; 
 int /*<<< orphan*/  ocelot_regfields ; 
 int ocelot_regfields_init (struct ocelot*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocelot_regmap ; 
 int /*<<< orphan*/  ocelot_stats_layout ; 
 int /*<<< orphan*/  ocelot_write (struct ocelot*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ocelot_pll5_init(struct ocelot *ocelot)
{
	/* Configure PLL5. This will need a proper CCF driver
	 * The values are coming from the VTSS API for Ocelot
	 */
	ocelot_write(ocelot, HSIO_PLL5G_CFG4_IB_CTRL(0x7600) |
		     HSIO_PLL5G_CFG4_IB_BIAS_CTRL(0x8), HSIO_PLL5G_CFG4);
	ocelot_write(ocelot, HSIO_PLL5G_CFG0_CORE_CLK_DIV(0x11) |
		     HSIO_PLL5G_CFG0_CPU_CLK_DIV(2) |
		     HSIO_PLL5G_CFG0_ENA_BIAS |
		     HSIO_PLL5G_CFG0_ENA_VCO_BUF |
		     HSIO_PLL5G_CFG0_ENA_CP1 |
		     HSIO_PLL5G_CFG0_SELCPI(2) |
		     HSIO_PLL5G_CFG0_LOOP_BW_RES(0xe) |
		     HSIO_PLL5G_CFG0_SELBGV820(4) |
		     HSIO_PLL5G_CFG0_DIV4 |
		     HSIO_PLL5G_CFG0_ENA_CLKTREE |
		     HSIO_PLL5G_CFG0_ENA_LANE, HSIO_PLL5G_CFG0);
	ocelot_write(ocelot, HSIO_PLL5G_CFG2_EN_RESET_FRQ_DET |
		     HSIO_PLL5G_CFG2_EN_RESET_OVERRUN |
		     HSIO_PLL5G_CFG2_GAIN_TEST(0x8) |
		     HSIO_PLL5G_CFG2_ENA_AMPCTRL |
		     HSIO_PLL5G_CFG2_PWD_AMPCTRL_N |
		     HSIO_PLL5G_CFG2_AMPC_SEL(0x10), HSIO_PLL5G_CFG2);
}

int ocelot_chip_init(struct ocelot *ocelot)
{
	int ret;

	ocelot->map = ocelot_regmap;
	ocelot->stats_layout = ocelot_stats_layout;
	ocelot->num_stats = ARRAY_SIZE(ocelot_stats_layout);
	ocelot->shared_queue_sz = 224 * 1024;

	ret = ocelot_regfields_init(ocelot, ocelot_regfields);
	if (ret)
		return ret;

	ocelot_pll5_init(ocelot);

	eth_random_addr(ocelot->base_mac);
	ocelot->base_mac[5] &= 0xf0;

	return 0;
}

