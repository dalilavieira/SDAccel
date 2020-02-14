#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct device {int dummy; } ;
struct TYPE_5__ {int pos; } ;
struct csiphy_lanes_cfg {int num_data; TYPE_3__* data; TYPE_2__ clk; } ;
struct csiphy_device {int timer_clk_rate; scalar_t__ base; } ;
struct csiphy_config {int combo_mode; TYPE_1__* csi2; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int pos; } ;
struct TYPE_4__ {struct csiphy_lanes_cfg lane_cfg; } ;

/* Variables and functions */
 scalar_t__ CAMSS_CSI_PHY_GLBL_IRQ_CMD ; 
 scalar_t__ CAMSS_CSI_PHY_GLBL_PWR_CFG ; 
 scalar_t__ CAMSS_CSI_PHY_GLBL_RESET ; 
 scalar_t__ CAMSS_CSI_PHY_GLBL_T_INIT_CFG0 ; 
 scalar_t__ CAMSS_CSI_PHY_HW_VERSION ; 
 scalar_t__ CAMSS_CSI_PHY_INTERRUPT_CLEARn (int) ; 
 scalar_t__ CAMSS_CSI_PHY_INTERRUPT_MASKn (int) ; 
 scalar_t__ CAMSS_CSI_PHY_INTERRUPT_STATUSn (int) ; 
 scalar_t__ CAMSS_CSI_PHY_LNn_CFG2 (int) ; 
 scalar_t__ CAMSS_CSI_PHY_LNn_CFG3 (int) ; 
 scalar_t__ CAMSS_CSI_PHY_T_WAKEUP_CFG0 ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int div_u64 (long long,int) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static void csiphy_hw_version_read(struct csiphy_device *csiphy,
				   struct device *dev)
{
	u8 hw_version = readl_relaxed(csiphy->base +
				      CAMSS_CSI_PHY_HW_VERSION);

	dev_dbg(dev, "CSIPHY HW Version = 0x%02x\n", hw_version);
}

__attribute__((used)) static void csiphy_reset(struct csiphy_device *csiphy)
{
	writel_relaxed(0x1, csiphy->base + CAMSS_CSI_PHY_GLBL_RESET);
	usleep_range(5000, 8000);
	writel_relaxed(0x0, csiphy->base + CAMSS_CSI_PHY_GLBL_RESET);
}

__attribute__((used)) static u8 csiphy_settle_cnt_calc(u32 pixel_clock, u8 bpp, u8 num_lanes,
				 u32 timer_clk_rate)
{
	u32 mipi_clock; /* Hz */
	u32 ui; /* ps */
	u32 timer_period; /* ps */
	u32 t_hs_prepare_max; /* ps */
	u32 t_hs_prepare_zero_min; /* ps */
	u32 t_hs_settle; /* ps */
	u8 settle_cnt;

	mipi_clock = pixel_clock * bpp / (2 * num_lanes);
	ui = div_u64(1000000000000LL, mipi_clock);
	ui /= 2;
	t_hs_prepare_max = 85000 + 6 * ui;
	t_hs_prepare_zero_min = 145000 + 10 * ui;
	t_hs_settle = (t_hs_prepare_max + t_hs_prepare_zero_min) / 2;

	timer_period = div_u64(1000000000000LL, timer_clk_rate);
	settle_cnt = t_hs_settle / timer_period - 1;

	return settle_cnt;
}

__attribute__((used)) static void csiphy_lanes_enable(struct csiphy_device *csiphy,
				struct csiphy_config *cfg,
				u32 pixel_clock, u8 bpp, u8 lane_mask)
{
	struct csiphy_lanes_cfg *c = &cfg->csi2->lane_cfg;
	u8 settle_cnt;
	u8 val, l = 0;
	int i = 0;

	settle_cnt = csiphy_settle_cnt_calc(pixel_clock, bpp, c->num_data,
					    csiphy->timer_clk_rate);

	writel_relaxed(0x1, csiphy->base +
		       CAMSS_CSI_PHY_GLBL_T_INIT_CFG0);
	writel_relaxed(0x1, csiphy->base +
		       CAMSS_CSI_PHY_T_WAKEUP_CFG0);

	val = 0x1;
	val |= lane_mask << 1;
	writel_relaxed(val, csiphy->base + CAMSS_CSI_PHY_GLBL_PWR_CFG);

	val = cfg->combo_mode << 4;
	writel_relaxed(val, csiphy->base + CAMSS_CSI_PHY_GLBL_RESET);

	for (i = 0; i <= c->num_data; i++) {
		if (i == c->num_data)
			l = c->clk.pos;
		else
			l = c->data[i].pos;

		writel_relaxed(0x10, csiphy->base +
			       CAMSS_CSI_PHY_LNn_CFG2(l));
		writel_relaxed(settle_cnt, csiphy->base +
			       CAMSS_CSI_PHY_LNn_CFG3(l));
		writel_relaxed(0x3f, csiphy->base +
			       CAMSS_CSI_PHY_INTERRUPT_MASKn(l));
		writel_relaxed(0x3f, csiphy->base +
			       CAMSS_CSI_PHY_INTERRUPT_CLEARn(l));
	}
}

__attribute__((used)) static void csiphy_lanes_disable(struct csiphy_device *csiphy,
				 struct csiphy_config *cfg)
{
	struct csiphy_lanes_cfg *c = &cfg->csi2->lane_cfg;
	u8 l = 0;
	int i = 0;

	for (i = 0; i <= c->num_data; i++) {
		if (i == c->num_data)
			l = c->clk.pos;
		else
			l = c->data[i].pos;

		writel_relaxed(0x0, csiphy->base +
			       CAMSS_CSI_PHY_LNn_CFG2(l));
	}

	writel_relaxed(0x0, csiphy->base + CAMSS_CSI_PHY_GLBL_PWR_CFG);
}

__attribute__((used)) static irqreturn_t csiphy_isr(int irq, void *dev)
{
	struct csiphy_device *csiphy = dev;
	u8 i;

	for (i = 0; i < 8; i++) {
		u8 val = readl_relaxed(csiphy->base +
				       CAMSS_CSI_PHY_INTERRUPT_STATUSn(i));
		writel_relaxed(val, csiphy->base +
			       CAMSS_CSI_PHY_INTERRUPT_CLEARn(i));
		writel_relaxed(0x1, csiphy->base + CAMSS_CSI_PHY_GLBL_IRQ_CMD);
		writel_relaxed(0x0, csiphy->base + CAMSS_CSI_PHY_GLBL_IRQ_CMD);
		writel_relaxed(0x0, csiphy->base +
			       CAMSS_CSI_PHY_INTERRUPT_CLEARn(i));
	}

	return IRQ_HANDLED;
}

