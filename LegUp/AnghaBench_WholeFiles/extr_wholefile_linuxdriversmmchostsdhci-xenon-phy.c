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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct xenon_priv {scalar_t__ phy_type; scalar_t__ init_card_type; scalar_t__ clock; scalar_t__ bus_width; unsigned char timing; struct xenon_emmc_phy_params* phy_params; struct xenon_emmc_phy_regs* emmc_phy_regs; } ;
struct xenon_emmc_phy_regs {int timing_adj; int dll_ctrl; int dll_update; int pad_ctrl; int pad_ctrl2; int func_ctrl; int logic_timing_val; int logic_timing_adj; } ;
struct TYPE_5__ {scalar_t__ pad_type; void (* set_soc_pad ) (struct sdhci_host*,unsigned char) ;scalar_t__ reg; } ;
struct xenon_emmc_phy_params {int tun_step_divider; int nr_tun_times; int slow_mode; int znr; int zpr; TYPE_2__ pad_ctrl; } ;
struct sdhci_pltfm_host {void* private; } ;
struct sdhci_host {void* private; int flags; int clock; int timing; TYPE_3__* mmc; scalar_t__ ioaddr; } ;
struct resource {int dummy; } ;
struct mmc_ios {scalar_t__ bus_width; unsigned char timing; } ;
struct device_node {char const* name; } ;
typedef  int /*<<< orphan*/  ktime_t ;
struct TYPE_4__ {scalar_t__ enhanced_strobe; } ;
struct TYPE_6__ {TYPE_1__ ios; } ;

/* Variables and functions */
 int ARMADA_3700_SOC_PAD_1_8V ; 
 int ARMADA_3700_SOC_PAD_3_3V ; 
 int EINVAL ; 
 scalar_t__ EMMC_5_0_PHY ; 
 scalar_t__ EMMC_5_1_PHY ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ MMC_HIGH_52_MAX_DTR ; 
 unsigned char MMC_SIGNAL_VOLTAGE_180 ; 
 unsigned char MMC_SIGNAL_VOLTAGE_330 ; 
#define  MMC_TIMING_LEGACY 137 
#define  MMC_TIMING_MMC_DDR52 136 
#define  MMC_TIMING_MMC_HS 135 
#define  MMC_TIMING_MMC_HS200 134 
#define  MMC_TIMING_MMC_HS400 133 
#define  MMC_TIMING_SD_HS 132 
#define  MMC_TIMING_UHS_DDR50 131 
#define  MMC_TIMING_UHS_SDR104 130 
#define  MMC_TIMING_UHS_SDR12 129 
#define  MMC_TIMING_UHS_SDR25 128 
 scalar_t__ MMC_TYPE_SDIO ; 
 int /*<<< orphan*/  NR_PHY_TYPES ; 
 int PTR_ERR (scalar_t__) ; 
 int SDHCI_CLOCK_CARD_EN ; 
 int SDHCI_CLOCK_CONTROL ; 
 int SDHCI_SDIO_IRQ_ENABLED ; 
 scalar_t__ SOC_PAD_FIXED_1_8V ; 
 scalar_t__ SOC_PAD_SD ; 
 scalar_t__ WARN_ON (int) ; 
 int XENON_CMD_DDR_MODE ; 
 scalar_t__ XENON_DEFAULT_SDCLK_FREQ ; 
 int XENON_DLL_BYPASS_EN ; 
 int XENON_DLL_ENABLE ; 
 int XENON_DLL_FAST_LOCK ; 
 int XENON_DLL_LOCK_STATE ; 
 int XENON_DLL_PHASE_90_DEGREE ; 
 int XENON_DLL_PHASE_MASK ; 
 int XENON_DLL_PHSEL0_SHIFT ; 
 int XENON_DLL_PHSEL1_SHIFT ; 
 int XENON_DLL_REFCLK_SEL ; 
 int XENON_DQ_ASYNC_MODE ; 
 int XENON_DQ_DDR_MODE_MASK ; 
 int XENON_DQ_DDR_MODE_SHIFT ; 
 int XENON_EMMC5_1_FC_CMD_PD ; 
 int XENON_EMMC5_1_FC_CMD_PU ; 
 int XENON_EMMC5_1_FC_DQ_PD ; 
 int XENON_EMMC5_1_FC_DQ_PU ; 
 int XENON_EMMC5_1_FC_QSP_PD ; 
 int XENON_EMMC5_1_FC_QSP_PU ; 
 int XENON_EMMC5_FC_CMD_PD ; 
 int XENON_EMMC5_FC_CMD_PU ; 
 int XENON_EMMC5_FC_DQ_PD ; 
 int XENON_EMMC5_FC_DQ_PU ; 
 int XENON_EMMC5_FC_QSP_PD ; 
 int XENON_EMMC5_FC_QSP_PU ; 
 int XENON_EMMC_5_0_PHY_PAD_CONTROL ; 
 int XENON_EMMC_PHY_PAD_CONTROL1 ; 
 int XENON_ENABLE_DATA_STROBE ; 
 int XENON_ENABLE_RESP_STROBE ; 
 int XENON_FC_ALL_CMOS_RECEIVER ; 
 int XENON_FC_CMD_RECEN ; 
 int XENON_FC_DQ_RECEN ; 
 int XENON_FC_QSP_RECEN ; 
 int XENON_FC_SYNC_EN_DURATION_MASK ; 
 int XENON_FC_SYNC_EN_DURATION_SHIFT ; 
 int XENON_FC_SYNC_RST_DURATION_MASK ; 
 int XENON_FC_SYNC_RST_DURATION_SHIFT ; 
 int XENON_FC_SYNC_RST_EN_DURATION_MASK ; 
 int XENON_FC_SYNC_RST_EN_DURATION_SHIFT ; 
 int XENON_LOWEST_SDCLK_FREQ ; 
 int XENON_OEN_QSN ; 
 int XENON_PHY_INITIALIZAION ; 
 int XENON_SLOT_DLL_CUR_DLY_VAL ; 
 int XENON_SLOT_EMMC_CTRL ; 
 int XENON_SLOT_EXT_PRESENT_STATE ; 
 int XENON_SLOT_OP_STATUS_CTRL ; 
 int XENON_TIMING_ADJUST_SDIO_MODE ; 
 int XENON_TIMING_ADJUST_SLOW_MODE ; 
 int XENON_TUNING_STEP_DIVIDER ; 
 int XENON_TUNING_STEP_MASK ; 
 int XENON_TUNING_STEP_SHIFT ; 
 int XENON_TUN_CONSECUTIVE_TIMES ; 
 int XENON_TUN_CONSECUTIVE_TIMES_MASK ; 
 int XENON_TUN_CONSECUTIVE_TIMES_SHIFT ; 
 int XENON_WAIT_CYCLE_BEFORE_USING_MASK ; 
 int XENON_WAIT_CYCLE_BEFORE_USING_SHIFT ; 
 int XENON_ZNR_DEF_VALUE ; 
 int XENON_ZNR_MASK ; 
 int XENON_ZNR_SHIFT ; 
 int XENON_ZPR_DEF_VALUE ; 
 int XENON_ZPR_MASK ; 
 int /*<<< orphan*/  __sdhci_read_caps (struct sdhci_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_warn_once (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ ,struct resource*) ; 
 struct xenon_emmc_phy_params* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_add_ms (int /*<<< orphan*/ ,int) ; 
 int ktime_after (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_get () ; 
 scalar_t__ match_string (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  mmc_dev (TYPE_3__*) ; 
 scalar_t__ of_address_to_resource (struct device_node*,int,struct resource*) ; 
 scalar_t__ of_device_is_compatible (struct device_node*,char*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  phy_types ; 
 int /*<<< orphan*/  readb (scalar_t__) ; 
 int readl (scalar_t__) ; 
 int readw (scalar_t__) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 void stub1 (struct sdhci_host*,unsigned char) ; 
 int /*<<< orphan*/  udelay (int) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  writew (int,scalar_t__) ; 
 struct xenon_emmc_phy_regs xenon_emmc_5_0_phy_regs ; 
 struct xenon_emmc_phy_regs xenon_emmc_5_1_phy_regs ; 

__attribute__((used)) static inline void sdhci_writel(struct sdhci_host *host, u32 val, int reg)
{
	writel(val, host->ioaddr + reg);
}

__attribute__((used)) static inline void sdhci_writew(struct sdhci_host *host, u16 val, int reg)
{
	writew(val, host->ioaddr + reg);
}

__attribute__((used)) static inline void sdhci_writeb(struct sdhci_host *host, u8 val, int reg)
{
	writeb(val, host->ioaddr + reg);
}

__attribute__((used)) static inline u32 sdhci_readl(struct sdhci_host *host, int reg)
{
	return readl(host->ioaddr + reg);
}

__attribute__((used)) static inline u16 sdhci_readw(struct sdhci_host *host, int reg)
{
	return readw(host->ioaddr + reg);
}

__attribute__((used)) static inline u8 sdhci_readb(struct sdhci_host *host, int reg)
{
	return readb(host->ioaddr + reg);
}

__attribute__((used)) static inline void *sdhci_priv(struct sdhci_host *host)
{
	return host->private;
}

__attribute__((used)) static inline void sdhci_read_caps(struct sdhci_host *host)
{
	__sdhci_read_caps(host, NULL, NULL, NULL);
}

__attribute__((used)) static inline bool sdhci_sdio_irq_enabled(struct sdhci_host *host)
{
	return !!(host->flags & SDHCI_SDIO_IRQ_ENABLED);
}

__attribute__((used)) static inline void *sdhci_pltfm_priv(struct sdhci_pltfm_host *host)
{
	return host->private;
}

__attribute__((used)) static int xenon_alloc_emmc_phy(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	struct xenon_emmc_phy_params *params;

	params = devm_kzalloc(mmc_dev(host->mmc), sizeof(*params), GFP_KERNEL);
	if (!params)
		return -ENOMEM;

	priv->phy_params = params;
	if (priv->phy_type == EMMC_5_0_PHY)
		priv->emmc_phy_regs = &xenon_emmc_5_0_phy_regs;
	else
		priv->emmc_phy_regs = &xenon_emmc_5_1_phy_regs;

	return 0;
}

__attribute__((used)) static int xenon_emmc_phy_init(struct sdhci_host *host)
{
	u32 reg;
	u32 wait, clock;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	struct xenon_emmc_phy_regs *phy_regs = priv->emmc_phy_regs;

	reg = sdhci_readl(host, phy_regs->timing_adj);
	reg |= XENON_PHY_INITIALIZAION;
	sdhci_writel(host, reg, phy_regs->timing_adj);

	/* Add duration of FC_SYNC_RST */
	wait = ((reg >> XENON_FC_SYNC_RST_DURATION_SHIFT) &
			XENON_FC_SYNC_RST_DURATION_MASK);
	/* Add interval between FC_SYNC_EN and FC_SYNC_RST */
	wait += ((reg >> XENON_FC_SYNC_RST_EN_DURATION_SHIFT) &
			XENON_FC_SYNC_RST_EN_DURATION_MASK);
	/* Add duration of asserting FC_SYNC_EN */
	wait += ((reg >> XENON_FC_SYNC_EN_DURATION_SHIFT) &
			XENON_FC_SYNC_EN_DURATION_MASK);
	/* Add duration of waiting for PHY */
	wait += ((reg >> XENON_WAIT_CYCLE_BEFORE_USING_SHIFT) &
			XENON_WAIT_CYCLE_BEFORE_USING_MASK);
	/* 4 additional bus clock and 4 AXI bus clock are required */
	wait += 8;
	wait <<= 20;

	clock = host->clock;
	if (!clock)
		/* Use the possibly slowest bus frequency value */
		clock = XENON_LOWEST_SDCLK_FREQ;
	/* get the wait time */
	wait /= clock;
	wait++;
	/* wait for host eMMC PHY init completes */
	udelay(wait);

	reg = sdhci_readl(host, phy_regs->timing_adj);
	reg &= XENON_PHY_INITIALIZAION;
	if (reg) {
		dev_err(mmc_dev(host->mmc), "eMMC PHY init cannot complete after %d us\n",
			wait);
		return -ETIMEDOUT;
	}

	return 0;
}

__attribute__((used)) static void armada_3700_soc_pad_voltage_set(struct sdhci_host *host,
					    unsigned char signal_voltage)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	struct xenon_emmc_phy_params *params = priv->phy_params;

	if (params->pad_ctrl.pad_type == SOC_PAD_FIXED_1_8V) {
		writel(ARMADA_3700_SOC_PAD_1_8V, params->pad_ctrl.reg);
	} else if (params->pad_ctrl.pad_type == SOC_PAD_SD) {
		if (signal_voltage == MMC_SIGNAL_VOLTAGE_180)
			writel(ARMADA_3700_SOC_PAD_1_8V, params->pad_ctrl.reg);
		else if (signal_voltage == MMC_SIGNAL_VOLTAGE_330)
			writel(ARMADA_3700_SOC_PAD_3_3V, params->pad_ctrl.reg);
	}
}

__attribute__((used)) static void xenon_emmc_phy_set_soc_pad(struct sdhci_host *host,
				       unsigned char signal_voltage)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	struct xenon_emmc_phy_params *params = priv->phy_params;

	if (!params->pad_ctrl.reg)
		return;

	if (params->pad_ctrl.set_soc_pad)
		params->pad_ctrl.set_soc_pad(host, signal_voltage);
}

__attribute__((used)) static int xenon_emmc_phy_enable_dll(struct sdhci_host *host)
{
	u32 reg;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	struct xenon_emmc_phy_regs *phy_regs = priv->emmc_phy_regs;
	ktime_t timeout;

	if (WARN_ON(host->clock <= MMC_HIGH_52_MAX_DTR))
		return -EINVAL;

	reg = sdhci_readl(host, phy_regs->dll_ctrl);
	if (reg & XENON_DLL_ENABLE)
		return 0;

	/* Enable DLL */
	reg = sdhci_readl(host, phy_regs->dll_ctrl);
	reg |= (XENON_DLL_ENABLE | XENON_DLL_FAST_LOCK);

	/*
	 * Set Phase as 90 degree, which is most common value.
	 * Might set another value if necessary.
	 * The granularity is 1 degree.
	 */
	reg &= ~((XENON_DLL_PHASE_MASK << XENON_DLL_PHSEL0_SHIFT) |
		 (XENON_DLL_PHASE_MASK << XENON_DLL_PHSEL1_SHIFT));
	reg |= ((XENON_DLL_PHASE_90_DEGREE << XENON_DLL_PHSEL0_SHIFT) |
		(XENON_DLL_PHASE_90_DEGREE << XENON_DLL_PHSEL1_SHIFT));

	reg &= ~XENON_DLL_BYPASS_EN;
	reg |= phy_regs->dll_update;
	if (priv->phy_type == EMMC_5_1_PHY)
		reg &= ~XENON_DLL_REFCLK_SEL;
	sdhci_writel(host, reg, phy_regs->dll_ctrl);

	/* Wait max 32 ms */
	timeout = ktime_add_ms(ktime_get(), 32);
	while (1) {
		bool timedout = ktime_after(ktime_get(), timeout);

		if (sdhci_readw(host, XENON_SLOT_EXT_PRESENT_STATE) &
		    XENON_DLL_LOCK_STATE)
			break;
		if (timedout) {
			dev_err(mmc_dev(host->mmc), "Wait for DLL Lock time-out\n");
			return -ETIMEDOUT;
		}
		udelay(100);
	}
	return 0;
}

__attribute__((used)) static int xenon_emmc_phy_config_tuning(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	struct xenon_emmc_phy_params *params = priv->phy_params;
	u32 reg, tuning_step;
	int ret;

	if (host->clock <= MMC_HIGH_52_MAX_DTR)
		return -EINVAL;

	ret = xenon_emmc_phy_enable_dll(host);
	if (ret)
		return ret;

	/* Achieve TUNING_STEP with HW DLL help */
	reg = sdhci_readl(host, XENON_SLOT_DLL_CUR_DLY_VAL);
	tuning_step = reg / params->tun_step_divider;
	if (unlikely(tuning_step > XENON_TUNING_STEP_MASK)) {
		dev_warn(mmc_dev(host->mmc),
			 "HS200 TUNING_STEP %d is larger than MAX value\n",
			 tuning_step);
		tuning_step = XENON_TUNING_STEP_MASK;
	}

	/* Set TUNING_STEP for later tuning */
	reg = sdhci_readl(host, XENON_SLOT_OP_STATUS_CTRL);
	reg &= ~(XENON_TUN_CONSECUTIVE_TIMES_MASK <<
		 XENON_TUN_CONSECUTIVE_TIMES_SHIFT);
	reg |= (params->nr_tun_times << XENON_TUN_CONSECUTIVE_TIMES_SHIFT);
	reg &= ~(XENON_TUNING_STEP_MASK << XENON_TUNING_STEP_SHIFT);
	reg |= (tuning_step << XENON_TUNING_STEP_SHIFT);
	sdhci_writel(host, reg, XENON_SLOT_OP_STATUS_CTRL);

	return 0;
}

__attribute__((used)) static void xenon_emmc_phy_disable_strobe(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	u32 reg;

	/* Disable both SDHC Data Strobe and Enhanced Strobe */
	reg = sdhci_readl(host, XENON_SLOT_EMMC_CTRL);
	reg &= ~(XENON_ENABLE_DATA_STROBE | XENON_ENABLE_RESP_STROBE);
	sdhci_writel(host, reg, XENON_SLOT_EMMC_CTRL);

	/* Clear Strobe line Pull down or Pull up */
	if (priv->phy_type == EMMC_5_0_PHY) {
		reg = sdhci_readl(host, XENON_EMMC_5_0_PHY_PAD_CONTROL);
		reg &= ~(XENON_EMMC5_FC_QSP_PD | XENON_EMMC5_FC_QSP_PU);
		sdhci_writel(host, reg, XENON_EMMC_5_0_PHY_PAD_CONTROL);
	} else {
		reg = sdhci_readl(host, XENON_EMMC_PHY_PAD_CONTROL1);
		reg &= ~(XENON_EMMC5_1_FC_QSP_PD | XENON_EMMC5_1_FC_QSP_PU);
		sdhci_writel(host, reg, XENON_EMMC_PHY_PAD_CONTROL1);
	}
}

__attribute__((used)) static void xenon_emmc_phy_strobe_delay_adj(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	u32 reg;

	if (WARN_ON(host->timing != MMC_TIMING_MMC_HS400))
		return;

	if (host->clock <= MMC_HIGH_52_MAX_DTR)
		return;

	dev_dbg(mmc_dev(host->mmc), "starts HS400 strobe delay adjustment\n");

	xenon_emmc_phy_enable_dll(host);

	/* Enable SDHC Data Strobe */
	reg = sdhci_readl(host, XENON_SLOT_EMMC_CTRL);
	reg |= XENON_ENABLE_DATA_STROBE;
	/*
	 * Enable SDHC Enhanced Strobe if supported
	 * Xenon Enhanced Strobe should be enabled only when
	 * 1. card is in HS400 mode and
	 * 2. SDCLK is higher than 52MHz
	 * 3. DLL is enabled
	 */
	if (host->mmc->ios.enhanced_strobe)
		reg |= XENON_ENABLE_RESP_STROBE;
	sdhci_writel(host, reg, XENON_SLOT_EMMC_CTRL);

	/* Set Data Strobe Pull down */
	if (priv->phy_type == EMMC_5_0_PHY) {
		reg = sdhci_readl(host, XENON_EMMC_5_0_PHY_PAD_CONTROL);
		reg |= XENON_EMMC5_FC_QSP_PD;
		reg &= ~XENON_EMMC5_FC_QSP_PU;
		sdhci_writel(host, reg, XENON_EMMC_5_0_PHY_PAD_CONTROL);
	} else {
		reg = sdhci_readl(host, XENON_EMMC_PHY_PAD_CONTROL1);
		reg |= XENON_EMMC5_1_FC_QSP_PD;
		reg &= ~XENON_EMMC5_1_FC_QSP_PU;
		sdhci_writel(host, reg, XENON_EMMC_PHY_PAD_CONTROL1);
	}
}

__attribute__((used)) static bool xenon_emmc_phy_slow_mode(struct sdhci_host *host,
				     unsigned char timing)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	struct xenon_emmc_phy_params *params = priv->phy_params;
	struct xenon_emmc_phy_regs *phy_regs = priv->emmc_phy_regs;
	u32 reg;
	int ret;

	if (host->clock > MMC_HIGH_52_MAX_DTR)
		return false;

	reg = sdhci_readl(host, phy_regs->timing_adj);
	/* When in slower SDR mode, enable Slow Mode for SDIO
	 * or when Slow Mode flag is set
	 */
	switch (timing) {
	case MMC_TIMING_LEGACY:
		/*
		 * If Slow Mode is required, enable Slow Mode by default
		 * in early init phase to avoid any potential issue.
		 */
		if (params->slow_mode) {
			reg |= XENON_TIMING_ADJUST_SLOW_MODE;
			ret = true;
		} else {
			reg &= ~XENON_TIMING_ADJUST_SLOW_MODE;
			ret = false;
		}
		break;
	case MMC_TIMING_UHS_SDR25:
	case MMC_TIMING_UHS_SDR12:
	case MMC_TIMING_SD_HS:
	case MMC_TIMING_MMC_HS:
		if ((priv->init_card_type == MMC_TYPE_SDIO) ||
		    params->slow_mode) {
			reg |= XENON_TIMING_ADJUST_SLOW_MODE;
			ret = true;
			break;
		}
		/* else: fall through */
	default:
		reg &= ~XENON_TIMING_ADJUST_SLOW_MODE;
		ret = false;
	}

	sdhci_writel(host, reg, phy_regs->timing_adj);
	return ret;
}

__attribute__((used)) static void xenon_emmc_phy_set(struct sdhci_host *host,
			       unsigned char timing)
{
	u32 reg;
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	struct xenon_emmc_phy_params *params = priv->phy_params;
	struct xenon_emmc_phy_regs *phy_regs = priv->emmc_phy_regs;

	dev_dbg(mmc_dev(host->mmc), "eMMC PHY setting starts\n");

	/* Setup pad, set bit[28] and bits[26:24] */
	reg = sdhci_readl(host, phy_regs->pad_ctrl);
	reg |= (XENON_FC_DQ_RECEN | XENON_FC_CMD_RECEN |
		XENON_FC_QSP_RECEN | XENON_OEN_QSN);
	/* All FC_XX_RECEIVCE should be set as CMOS Type */
	reg |= XENON_FC_ALL_CMOS_RECEIVER;
	sdhci_writel(host, reg, phy_regs->pad_ctrl);

	/* Set CMD and DQ Pull Up */
	if (priv->phy_type == EMMC_5_0_PHY) {
		reg = sdhci_readl(host, XENON_EMMC_5_0_PHY_PAD_CONTROL);
		reg |= (XENON_EMMC5_FC_CMD_PU | XENON_EMMC5_FC_DQ_PU);
		reg &= ~(XENON_EMMC5_FC_CMD_PD | XENON_EMMC5_FC_DQ_PD);
		sdhci_writel(host, reg, XENON_EMMC_5_0_PHY_PAD_CONTROL);
	} else {
		reg = sdhci_readl(host, XENON_EMMC_PHY_PAD_CONTROL1);
		reg |= (XENON_EMMC5_1_FC_CMD_PU | XENON_EMMC5_1_FC_DQ_PU);
		reg &= ~(XENON_EMMC5_1_FC_CMD_PD | XENON_EMMC5_1_FC_DQ_PD);
		sdhci_writel(host, reg, XENON_EMMC_PHY_PAD_CONTROL1);
	}

	if (timing == MMC_TIMING_LEGACY) {
		xenon_emmc_phy_slow_mode(host, timing);
		goto phy_init;
	}

	/*
	 * If SDIO card, set SDIO Mode
	 * Otherwise, clear SDIO Mode
	 */
	reg = sdhci_readl(host, phy_regs->timing_adj);
	if (priv->init_card_type == MMC_TYPE_SDIO)
		reg |= XENON_TIMING_ADJUST_SDIO_MODE;
	else
		reg &= ~XENON_TIMING_ADJUST_SDIO_MODE;
	sdhci_writel(host, reg, phy_regs->timing_adj);

	if (xenon_emmc_phy_slow_mode(host, timing))
		goto phy_init;

	/*
	 * Set preferred ZNR and ZPR value
	 * The ZNR and ZPR value vary between different boards.
	 * Define them both in sdhci-xenon-emmc-phy.h.
	 */
	reg = sdhci_readl(host, phy_regs->pad_ctrl2);
	reg &= ~((XENON_ZNR_MASK << XENON_ZNR_SHIFT) | XENON_ZPR_MASK);
	reg |= ((params->znr << XENON_ZNR_SHIFT) | params->zpr);
	sdhci_writel(host, reg, phy_regs->pad_ctrl2);

	/*
	 * When setting EMMC_PHY_FUNC_CONTROL register,
	 * SD clock should be disabled
	 */
	reg = sdhci_readl(host, SDHCI_CLOCK_CONTROL);
	reg &= ~SDHCI_CLOCK_CARD_EN;
	sdhci_writew(host, reg, SDHCI_CLOCK_CONTROL);

	reg = sdhci_readl(host, phy_regs->func_ctrl);
	switch (timing) {
	case MMC_TIMING_MMC_HS400:
		reg |= (XENON_DQ_DDR_MODE_MASK << XENON_DQ_DDR_MODE_SHIFT) |
		       XENON_CMD_DDR_MODE;
		reg &= ~XENON_DQ_ASYNC_MODE;
		break;
	case MMC_TIMING_UHS_DDR50:
	case MMC_TIMING_MMC_DDR52:
		reg |= (XENON_DQ_DDR_MODE_MASK << XENON_DQ_DDR_MODE_SHIFT) |
		       XENON_CMD_DDR_MODE | XENON_DQ_ASYNC_MODE;
		break;
	default:
		reg &= ~((XENON_DQ_DDR_MODE_MASK << XENON_DQ_DDR_MODE_SHIFT) |
			 XENON_CMD_DDR_MODE);
		reg |= XENON_DQ_ASYNC_MODE;
	}
	sdhci_writel(host, reg, phy_regs->func_ctrl);

	/* Enable bus clock */
	reg = sdhci_readl(host, SDHCI_CLOCK_CONTROL);
	reg |= SDHCI_CLOCK_CARD_EN;
	sdhci_writew(host, reg, SDHCI_CLOCK_CONTROL);

	if (timing == MMC_TIMING_MMC_HS400)
		/* Hardware team recommend a value for HS400 */
		sdhci_writel(host, phy_regs->logic_timing_val,
			     phy_regs->logic_timing_adj);
	else
		xenon_emmc_phy_disable_strobe(host);

phy_init:
	xenon_emmc_phy_init(host);

	dev_dbg(mmc_dev(host->mmc), "eMMC PHY setting completes\n");
}

__attribute__((used)) static int get_dt_pad_ctrl_data(struct sdhci_host *host,
				struct device_node *np,
				struct xenon_emmc_phy_params *params)
{
	int ret = 0;
	const char *name;
	struct resource iomem;

	if (of_device_is_compatible(np, "marvell,armada-3700-sdhci"))
		params->pad_ctrl.set_soc_pad = armada_3700_soc_pad_voltage_set;
	else
		return 0;

	if (of_address_to_resource(np, 1, &iomem)) {
		dev_err(mmc_dev(host->mmc), "Unable to find SoC PAD ctrl register address for %s\n",
			np->name);
		return -EINVAL;
	}

	params->pad_ctrl.reg = devm_ioremap_resource(mmc_dev(host->mmc),
						     &iomem);
	if (IS_ERR(params->pad_ctrl.reg))
		return PTR_ERR(params->pad_ctrl.reg);

	ret = of_property_read_string(np, "marvell,pad-type", &name);
	if (ret) {
		dev_err(mmc_dev(host->mmc), "Unable to determine SoC PHY PAD ctrl type\n");
		return ret;
	}
	if (!strcmp(name, "sd")) {
		params->pad_ctrl.pad_type = SOC_PAD_SD;
	} else if (!strcmp(name, "fixed-1-8v")) {
		params->pad_ctrl.pad_type = SOC_PAD_FIXED_1_8V;
	} else {
		dev_err(mmc_dev(host->mmc), "Unsupported SoC PHY PAD ctrl type %s\n",
			name);
		return -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int xenon_emmc_phy_parse_param_dt(struct sdhci_host *host,
					 struct device_node *np,
					 struct xenon_emmc_phy_params *params)
{
	u32 value;

	params->slow_mode = false;
	if (of_property_read_bool(np, "marvell,xenon-phy-slow-mode"))
		params->slow_mode = true;

	params->znr = XENON_ZNR_DEF_VALUE;
	if (!of_property_read_u32(np, "marvell,xenon-phy-znr", &value))
		params->znr = value & XENON_ZNR_MASK;

	params->zpr = XENON_ZPR_DEF_VALUE;
	if (!of_property_read_u32(np, "marvell,xenon-phy-zpr", &value))
		params->zpr = value & XENON_ZPR_MASK;

	params->nr_tun_times = XENON_TUN_CONSECUTIVE_TIMES;
	if (!of_property_read_u32(np, "marvell,xenon-phy-nr-success-tun",
				  &value))
		params->nr_tun_times = value & XENON_TUN_CONSECUTIVE_TIMES_MASK;

	params->tun_step_divider = XENON_TUNING_STEP_DIVIDER;
	if (!of_property_read_u32(np, "marvell,xenon-phy-tun-step-divider",
				  &value))
		params->tun_step_divider = value & 0xFF;

	return get_dt_pad_ctrl_data(host, np, params);
}

void xenon_soc_pad_ctrl(struct sdhci_host *host,
			unsigned char signal_voltage)
{
	xenon_emmc_phy_set_soc_pad(host, signal_voltage);
}

__attribute__((used)) static int xenon_hs_delay_adj(struct sdhci_host *host)
{
	int ret = 0;

	if (WARN_ON(host->clock <= XENON_DEFAULT_SDCLK_FREQ))
		return -EINVAL;

	switch (host->timing) {
	case MMC_TIMING_MMC_HS400:
		xenon_emmc_phy_strobe_delay_adj(host);
		return 0;
	case MMC_TIMING_MMC_HS200:
	case MMC_TIMING_UHS_SDR104:
		return xenon_emmc_phy_config_tuning(host);
	case MMC_TIMING_MMC_DDR52:
	case MMC_TIMING_UHS_DDR50:
		/*
		 * DDR Mode requires driver to scan Sampling Fixed Delay Line,
		 * to find out a perfect operation sampling point.
		 * It is hard to implement such a scan in host driver
		 * since initiating commands by host driver is not safe.
		 * Thus so far just keep PHY Sampling Fixed Delay in
		 * default value of DDR mode.
		 *
		 * If any timing issue occurs in DDR mode on Marvell products,
		 * please contact maintainer for internal support in Marvell.
		 */
		dev_warn_once(mmc_dev(host->mmc), "Timing issue might occur in DDR mode\n");
		return 0;
	}

	return ret;
}

int xenon_phy_adj(struct sdhci_host *host, struct mmc_ios *ios)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	int ret = 0;

	if (!host->clock) {
		priv->clock = 0;
		return 0;
	}

	/*
	 * The timing, frequency or bus width is changed,
	 * better to set eMMC PHY based on current setting
	 * and adjust Xenon SDHC delay.
	 */
	if ((host->clock == priv->clock) &&
	    (ios->bus_width == priv->bus_width) &&
	    (ios->timing == priv->timing))
		return 0;

	xenon_emmc_phy_set(host, ios->timing);

	/* Update the record */
	priv->bus_width = ios->bus_width;

	priv->timing = ios->timing;
	priv->clock = host->clock;

	/* Legacy mode is a special case */
	if (ios->timing == MMC_TIMING_LEGACY)
		return 0;

	if (host->clock > XENON_DEFAULT_SDCLK_FREQ)
		ret = xenon_hs_delay_adj(host);
	return ret;
}

__attribute__((used)) static int xenon_add_phy(struct device_node *np, struct sdhci_host *host,
			 const char *phy_name)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	int ret;

	priv->phy_type = match_string(phy_types, NR_PHY_TYPES, phy_name);
	if (priv->phy_type < 0) {
		dev_err(mmc_dev(host->mmc),
			"Unable to determine PHY name %s. Use default eMMC 5.1 PHY\n",
			phy_name);
		priv->phy_type = EMMC_5_1_PHY;
	}

	ret = xenon_alloc_emmc_phy(host);
	if (ret)
		return ret;

	return xenon_emmc_phy_parse_param_dt(host, np, priv->phy_params);
}

int xenon_phy_parse_dt(struct device_node *np, struct sdhci_host *host)
{
	const char *phy_type = NULL;

	if (!of_property_read_string(np, "marvell,xenon-phy-type", &phy_type))
		return xenon_add_phy(np, host, phy_type);

	return xenon_add_phy(np, host, "emmc 5.1 phy");
}

