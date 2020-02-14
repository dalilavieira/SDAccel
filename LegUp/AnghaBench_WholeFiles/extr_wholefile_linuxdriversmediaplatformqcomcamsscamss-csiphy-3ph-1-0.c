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
struct csiphy_config {TYPE_1__* csi2; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int pos; } ;
struct TYPE_4__ {struct csiphy_lanes_cfg lane_cfg; } ;

/* Variables and functions */
 int BIT (int) ; 
 int CSIPHY_3PH_CMN_CSI_COMMON_CTRL6_COMMON_PWRDN_B ; 
 int /*<<< orphan*/  CSIPHY_3PH_CMN_CSI_COMMON_CTRL6_SHOW_REV_ID ; 
 scalar_t__ CSIPHY_3PH_CMN_CSI_COMMON_CTRLn (int) ; 
 scalar_t__ CSIPHY_3PH_CMN_CSI_COMMON_STATUSn (int) ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG1 (int) ; 
 int CSIPHY_3PH_LNn_CFG1_SWI_REC_DLY_PRG ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG2 (int) ; 
 int CSIPHY_3PH_LNn_CFG2_LP_REC_EN_INT ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG3 (int) ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG4 (int) ; 
 int CSIPHY_3PH_LNn_CFG4_T_HS_CLK_MISS ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG5 (int) ; 
 int CSIPHY_3PH_LNn_CFG5_HS_REC_EQ_FQ_INT ; 
 int CSIPHY_3PH_LNn_CFG5_T_HS_DTERM ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG6 (int) ; 
 int CSIPHY_3PH_LNn_CFG6_SWI_FORCE_INIT_EXIT ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG7 (int) ; 
 int CSIPHY_3PH_LNn_CFG7_SWI_T_INIT ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG8 (int) ; 
 int CSIPHY_3PH_LNn_CFG8_SKEW_FILTER_ENABLE ; 
 int CSIPHY_3PH_LNn_CFG8_SWI_SKIP_WAKEUP ; 
 scalar_t__ CSIPHY_3PH_LNn_CFG9 (int) ; 
 int CSIPHY_3PH_LNn_CFG9_SWI_T_WAKEUP ; 
 scalar_t__ CSIPHY_3PH_LNn_CSI_LANE_CTRL15 (int) ; 
 int CSIPHY_3PH_LNn_CSI_LANE_CTRL15_SWI_SOT_SYMBOL ; 
 scalar_t__ CSIPHY_3PH_LNn_MISC1 (int) ; 
 int CSIPHY_3PH_LNn_MISC1_IS_CLKLANE ; 
 scalar_t__ CSIPHY_3PH_LNn_TEST_IMP (int) ; 
 int CSIPHY_3PH_LNn_TEST_IMP_HS_TERM_IMP ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 int div_u64 (long long,int) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static void csiphy_hw_version_read(struct csiphy_device *csiphy,
				   struct device *dev)
{
	u32 hw_version;

	writel(CSIPHY_3PH_CMN_CSI_COMMON_CTRL6_SHOW_REV_ID,
	       csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(6));

	hw_version = readl_relaxed(csiphy->base +
				   CSIPHY_3PH_CMN_CSI_COMMON_STATUSn(12));
	hw_version |= readl_relaxed(csiphy->base +
				   CSIPHY_3PH_CMN_CSI_COMMON_STATUSn(13)) << 8;
	hw_version |= readl_relaxed(csiphy->base +
				   CSIPHY_3PH_CMN_CSI_COMMON_STATUSn(14)) << 16;
	hw_version |= readl_relaxed(csiphy->base +
				   CSIPHY_3PH_CMN_CSI_COMMON_STATUSn(15)) << 24;

	dev_err(dev, "CSIPHY 3PH HW Version = 0x%08x\n", hw_version);
}

__attribute__((used)) static void csiphy_reset(struct csiphy_device *csiphy)
{
	writel_relaxed(0x1, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(0));
	usleep_range(5000, 8000);
	writel_relaxed(0x0, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(0));
}

__attribute__((used)) static irqreturn_t csiphy_isr(int irq, void *dev)
{
	struct csiphy_device *csiphy = dev;
	int i;

	for (i = 0; i < 11; i++) {
		int c = i + 22;
		u8 val = readl_relaxed(csiphy->base +
				       CSIPHY_3PH_CMN_CSI_COMMON_STATUSn(i));

		writel_relaxed(val, csiphy->base +
				    CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(c));
	}

	writel_relaxed(0x1, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(10));
	writel_relaxed(0x0, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(10));

	for (i = 22; i < 33; i++)
		writel_relaxed(0x0, csiphy->base +
				    CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(i));

	return IRQ_HANDLED;
}

__attribute__((used)) static u8 csiphy_settle_cnt_calc(u32 pixel_clock, u8 bpp, u8 num_lanes,
				 u32 timer_clk_rate)
{
	u32 mipi_clock; /* Hz */
	u32 ui; /* ps */
	u32 timer_period; /* ps */
	u32 t_hs_prepare_max; /* ps */
	u32 t_hs_settle; /* ps */
	u8 settle_cnt;

	mipi_clock = pixel_clock * bpp / (2 * num_lanes);
	ui = div_u64(1000000000000LL, mipi_clock);
	ui /= 2;
	t_hs_prepare_max = 85000 + 6 * ui;
	t_hs_settle = t_hs_prepare_max;

	timer_period = div_u64(1000000000000LL, timer_clk_rate);
	settle_cnt = t_hs_settle / timer_period - 6;

	return settle_cnt;
}

__attribute__((used)) static void csiphy_lanes_enable(struct csiphy_device *csiphy,
				struct csiphy_config *cfg,
				u32 pixel_clock, u8 bpp, u8 lane_mask)
{
	struct csiphy_lanes_cfg *c = &cfg->csi2->lane_cfg;
	u8 settle_cnt;
	u8 val, l = 0;
	int i;

	settle_cnt = csiphy_settle_cnt_calc(pixel_clock, bpp, c->num_data,
					    csiphy->timer_clk_rate);

	val = BIT(c->clk.pos);
	for (i = 0; i < c->num_data; i++)
		val |= BIT(c->data[i].pos * 2);

	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(5));

	val = CSIPHY_3PH_CMN_CSI_COMMON_CTRL6_COMMON_PWRDN_B;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(6));

	for (i = 0; i <= c->num_data; i++) {
		if (i == c->num_data)
			l = 7;
		else
			l = c->data[i].pos * 2;

		val = CSIPHY_3PH_LNn_CFG1_SWI_REC_DLY_PRG;
		val |= 0x17;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG1(l));

		val = CSIPHY_3PH_LNn_CFG2_LP_REC_EN_INT;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG2(l));

		val = settle_cnt;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG3(l));

		val = CSIPHY_3PH_LNn_CFG5_T_HS_DTERM |
			CSIPHY_3PH_LNn_CFG5_HS_REC_EQ_FQ_INT;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG5(l));

		val = CSIPHY_3PH_LNn_CFG6_SWI_FORCE_INIT_EXIT;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG6(l));

		val = CSIPHY_3PH_LNn_CFG7_SWI_T_INIT;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG7(l));

		val = CSIPHY_3PH_LNn_CFG8_SWI_SKIP_WAKEUP |
			CSIPHY_3PH_LNn_CFG8_SKEW_FILTER_ENABLE;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG8(l));

		val = CSIPHY_3PH_LNn_CFG9_SWI_T_WAKEUP;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG9(l));

		val = CSIPHY_3PH_LNn_TEST_IMP_HS_TERM_IMP;
		writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_TEST_IMP(l));

		val = CSIPHY_3PH_LNn_CSI_LANE_CTRL15_SWI_SOT_SYMBOL;
		writel_relaxed(val, csiphy->base +
				    CSIPHY_3PH_LNn_CSI_LANE_CTRL15(l));
	}

	val = CSIPHY_3PH_LNn_CFG1_SWI_REC_DLY_PRG;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG1(l));

	val = CSIPHY_3PH_LNn_CFG4_T_HS_CLK_MISS;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_CFG4(l));

	val = CSIPHY_3PH_LNn_MISC1_IS_CLKLANE;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_LNn_MISC1(l));

	val = 0xff;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(11));

	val = 0xff;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(12));

	val = 0xfb;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(13));

	val = 0xff;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(14));

	val = 0x7f;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(15));

	val = 0xff;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(16));

	val = 0xff;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(17));

	val = 0xef;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(18));

	val = 0xff;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(19));

	val = 0xff;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(20));

	val = 0xff;
	writel_relaxed(val, csiphy->base + CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(21));
}

__attribute__((used)) static void csiphy_lanes_disable(struct csiphy_device *csiphy,
				 struct csiphy_config *cfg)
{
	writel_relaxed(0, csiphy->base +
			  CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(5));

	writel_relaxed(0, csiphy->base +
			  CSIPHY_3PH_CMN_CSI_COMMON_CTRLn(6));
}

