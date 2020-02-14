#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
typedef  struct sdhci_tegra_soc_data {int nvquirks; int /*<<< orphan*/  pdata; } const sdhci_tegra_soc_data ;
struct sdhci_tegra {int pad_calib_required; int ddr_signaling; struct sdhci_host* rst; struct sdhci_host* power_gpio; struct sdhci_tegra_soc_data const* soc_data; } ;
struct sdhci_pltfm_host {void* private; int xfer_mode_shadow; struct sdhci_host* clk; } ;
struct sdhci_host {int const ioaddr; void* private; int flags; unsigned long max_clk; TYPE_2__* mmc; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct of_device_id {struct sdhci_tegra_soc_data const* data; } ;
struct clk {int const ioaddr; void* private; int flags; unsigned long max_clk; TYPE_2__* mmc; } ;
struct TYPE_6__ {struct sdhci_host* vqmmc; } ;
struct TYPE_7__ {int /*<<< orphan*/  caps; TYPE_1__ supply; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 scalar_t__ IS_ERR (struct sdhci_host*) ; 
 int /*<<< orphan*/  MMC_CAP_1_8V_DDR ; 
 unsigned int MMC_TIMING_MMC_DDR52 ; 
 unsigned int MMC_TIMING_UHS_DDR50 ; 
 int NVQUIRK_ENABLE_BLOCK_GAP_DET ; 
 int NVQUIRK_ENABLE_DDR50 ; 
 int NVQUIRK_ENABLE_SDHCI_SPEC_300 ; 
 int NVQUIRK_ENABLE_SDR104 ; 
 int NVQUIRK_ENABLE_SDR50 ; 
 int NVQUIRK_FORCE_SDHCI_SPEC_200 ; 
 int NVQUIRK_HAS_PADCALIB ; 
 int PTR_ERR (struct sdhci_host*) ; 
 int SDHCI_AUTO_CAL_ENABLE ; 
 int SDHCI_AUTO_CAL_START ; 
 int const SDHCI_BLOCK_GAP_CONTROL ; 
 int SDHCI_CLOCK_CTRL_SDR50_TUNING_OVERRIDE ; 
 int SDHCI_CLOCK_CTRL_SPI_MODE_CLKEN_OVERRIDE ; 
 int SDHCI_CLOCK_CTRL_TAP_MASK ; 
 unsigned int SDHCI_CLOCK_CTRL_TAP_SHIFT ; 
#define  SDHCI_COMMAND 129 
 int SDHCI_HOST_VERSION ; 
 int SDHCI_INT_CARD_INT ; 
 int SDHCI_INT_CRC ; 
 int SDHCI_INT_ENABLE ; 
 int SDHCI_INT_TIMEOUT ; 
 int SDHCI_MISC_CTRL_ENABLE_DDR50 ; 
 int SDHCI_MISC_CTRL_ENABLE_SDHCI_SPEC_300 ; 
 int SDHCI_MISC_CTRL_ENABLE_SDR104 ; 
 int SDHCI_MISC_CTRL_ENABLE_SDR50 ; 
 int SDHCI_RESET_ALL ; 
 int SDHCI_SDIO_IRQ_ENABLED ; 
 int SDHCI_SIGNAL_ENABLE ; 
 int SDHCI_SPEC_200 ; 
 int SDHCI_TEGRA_AUTO_CAL_CONFIG ; 
 int SDHCI_TEGRA_VENDOR_CLOCK_CTRL ; 
 int SDHCI_TEGRA_VENDOR_MISC_CTRL ; 
#define  SDHCI_TRANSFER_MODE 128 
 int /*<<< orphan*/  UINT_MAX ; 
 int /*<<< orphan*/  __sdhci_read_caps (struct sdhci_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct sdhci_host*) ; 
 unsigned long clk_get_rate (struct sdhci_host*) ; 
 int /*<<< orphan*/  clk_prepare_enable (struct sdhci_host*) ; 
 unsigned int clk_round_rate (struct sdhci_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_set_rate (struct sdhci_host*,unsigned long) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct sdhci_host* devm_clk_get (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct sdhci_host* devm_gpiod_get_optional (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct sdhci_host* devm_reset_control_get_exclusive (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  mmc_dev (TYPE_2__*) ; 
 unsigned int mmc_gpio_get_ro (TYPE_2__*) ; 
 int mmc_of_parse (TYPE_2__*) ; 
 int mmc_send_tuning (TYPE_2__*,int,int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct sdhci_host* platform_get_drvdata (struct platform_device*) ; 
 int readb (int const) ; 
 int readl (int const) ; 
 int readw (int const) ; 
 int reset_control_assert (struct sdhci_host*) ; 
 int reset_control_deassert (struct sdhci_host*) ; 
 int sdhci_add_host (struct sdhci_host*) ; 
 int /*<<< orphan*/  sdhci_pltfm_free (struct platform_device*) ; 
 struct sdhci_host* sdhci_pltfm_init (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sdhci_remove_host (struct sdhci_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdhci_reset (struct sdhci_host*,int) ; 
 void sdhci_set_clock (struct sdhci_host*,unsigned int) ; 
 int /*<<< orphan*/  sdhci_set_uhs_signaling (struct sdhci_host*,unsigned int) ; 
 int /*<<< orphan*/  sdhci_tegra_dt_match ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  writeb (int,int const) ; 
 int /*<<< orphan*/  writel (int,int const) ; 
 int /*<<< orphan*/  writew (int,int const) ; 

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

__attribute__((used)) static u16 tegra_sdhci_readw(struct sdhci_host *host, int reg)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
	const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;

	if (unlikely((soc_data->nvquirks & NVQUIRK_FORCE_SDHCI_SPEC_200) &&
			(reg == SDHCI_HOST_VERSION))) {
		/* Erratum: Version register is invalid in HW. */
		return SDHCI_SPEC_200;
	}

	return readw(host->ioaddr + reg);
}

__attribute__((used)) static void tegra_sdhci_writew(struct sdhci_host *host, u16 val, int reg)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);

	switch (reg) {
	case SDHCI_TRANSFER_MODE:
		/*
		 * Postpone this write, we must do it together with a
		 * command write that is down below.
		 */
		pltfm_host->xfer_mode_shadow = val;
		return;
	case SDHCI_COMMAND:
		writel((val << 16) | pltfm_host->xfer_mode_shadow,
			host->ioaddr + SDHCI_TRANSFER_MODE);
		return;
	}

	writew(val, host->ioaddr + reg);
}

__attribute__((used)) static void tegra_sdhci_writel(struct sdhci_host *host, u32 val, int reg)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
	const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;

	/* Seems like we're getting spurious timeout and crc errors, so
	 * disable signalling of them. In case of real errors software
	 * timers should take care of eventually detecting them.
	 */
	if (unlikely(reg == SDHCI_SIGNAL_ENABLE))
		val &= ~(SDHCI_INT_TIMEOUT|SDHCI_INT_CRC);

	writel(val, host->ioaddr + reg);

	if (unlikely((soc_data->nvquirks & NVQUIRK_ENABLE_BLOCK_GAP_DET) &&
			(reg == SDHCI_INT_ENABLE))) {
		/* Erratum: Must enable block gap interrupt detection */
		u8 gap_ctrl = readb(host->ioaddr + SDHCI_BLOCK_GAP_CONTROL);
		if (val & SDHCI_INT_CARD_INT)
			gap_ctrl |= 0x8;
		else
			gap_ctrl &= ~0x8;
		writeb(gap_ctrl, host->ioaddr + SDHCI_BLOCK_GAP_CONTROL);
	}
}

__attribute__((used)) static unsigned int tegra_sdhci_get_ro(struct sdhci_host *host)
{
	return mmc_gpio_get_ro(host->mmc);
}

__attribute__((used)) static void tegra_sdhci_reset(struct sdhci_host *host, u8 mask)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
	const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
	u32 misc_ctrl, clk_ctrl;

	sdhci_reset(host, mask);

	if (!(mask & SDHCI_RESET_ALL))
		return;

	misc_ctrl = sdhci_readl(host, SDHCI_TEGRA_VENDOR_MISC_CTRL);
	clk_ctrl = sdhci_readl(host, SDHCI_TEGRA_VENDOR_CLOCK_CTRL);

	misc_ctrl &= ~(SDHCI_MISC_CTRL_ENABLE_SDHCI_SPEC_300 |
		       SDHCI_MISC_CTRL_ENABLE_SDR50 |
		       SDHCI_MISC_CTRL_ENABLE_DDR50 |
		       SDHCI_MISC_CTRL_ENABLE_SDR104);

	clk_ctrl &= ~SDHCI_CLOCK_CTRL_SPI_MODE_CLKEN_OVERRIDE;

	/*
	 * If the board does not define a regulator for the SDHCI
	 * IO voltage, then don't advertise support for UHS modes
	 * even if the device supports it because the IO voltage
	 * cannot be configured.
	 */
	if (!IS_ERR(host->mmc->supply.vqmmc)) {
		/* Erratum: Enable SDHCI spec v3.00 support */
		if (soc_data->nvquirks & NVQUIRK_ENABLE_SDHCI_SPEC_300)
			misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_SDHCI_SPEC_300;
		/* Advertise UHS modes as supported by host */
		if (soc_data->nvquirks & NVQUIRK_ENABLE_SDR50)
			misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_SDR50;
		if (soc_data->nvquirks & NVQUIRK_ENABLE_DDR50)
			misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_DDR50;
		if (soc_data->nvquirks & NVQUIRK_ENABLE_SDR104)
			misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_SDR104;
		if (soc_data->nvquirks & SDHCI_MISC_CTRL_ENABLE_SDR50)
			clk_ctrl |= SDHCI_CLOCK_CTRL_SDR50_TUNING_OVERRIDE;
	}

	sdhci_writel(host, misc_ctrl, SDHCI_TEGRA_VENDOR_MISC_CTRL);
	sdhci_writel(host, clk_ctrl, SDHCI_TEGRA_VENDOR_CLOCK_CTRL);

	if (soc_data->nvquirks & NVQUIRK_HAS_PADCALIB)
		tegra_host->pad_calib_required = true;

	tegra_host->ddr_signaling = false;
}

__attribute__((used)) static void tegra_sdhci_pad_autocalib(struct sdhci_host *host)
{
	u32 val;

	mdelay(1);

	val = sdhci_readl(host, SDHCI_TEGRA_AUTO_CAL_CONFIG);
	val |= SDHCI_AUTO_CAL_ENABLE | SDHCI_AUTO_CAL_START;
	sdhci_writel(host,val, SDHCI_TEGRA_AUTO_CAL_CONFIG);
}

__attribute__((used)) static void tegra_sdhci_set_clock(struct sdhci_host *host, unsigned int clock)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
	unsigned long host_clk;

	if (!clock)
		return sdhci_set_clock(host, clock);

	/*
	 * In DDR50/52 modes the Tegra SDHCI controllers require the SDHCI
	 * divider to be configured to divided the host clock by two. The SDHCI
	 * clock divider is calculated as part of sdhci_set_clock() by
	 * sdhci_calc_clk(). The divider is calculated from host->max_clk and
	 * the requested clock rate.
	 *
	 * By setting the host->max_clk to clock * 2 the divider calculation
	 * will always result in the correct value for DDR50/52 modes,
	 * regardless of clock rate rounding, which may happen if the value
	 * from clk_get_rate() is used.
	 */
	host_clk = tegra_host->ddr_signaling ? clock * 2 : clock;
	clk_set_rate(pltfm_host->clk, host_clk);
	if (tegra_host->ddr_signaling)
		host->max_clk = host_clk;
	else
		host->max_clk = clk_get_rate(pltfm_host->clk);

	sdhci_set_clock(host, clock);

	if (tegra_host->pad_calib_required) {
		tegra_sdhci_pad_autocalib(host);
		tegra_host->pad_calib_required = false;
	}
}

__attribute__((used)) static void tegra_sdhci_set_uhs_signaling(struct sdhci_host *host,
					  unsigned timing)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);

	if (timing == MMC_TIMING_UHS_DDR50 ||
	    timing == MMC_TIMING_MMC_DDR52)
		tegra_host->ddr_signaling = true;

	sdhci_set_uhs_signaling(host, timing);
}

__attribute__((used)) static unsigned int tegra_sdhci_get_max_clock(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);

	return clk_round_rate(pltfm_host->clk, UINT_MAX);
}

__attribute__((used)) static void tegra_sdhci_set_tap(struct sdhci_host *host, unsigned int tap)
{
	u32 reg;

	reg = sdhci_readl(host, SDHCI_TEGRA_VENDOR_CLOCK_CTRL);
	reg &= ~SDHCI_CLOCK_CTRL_TAP_MASK;
	reg |= tap << SDHCI_CLOCK_CTRL_TAP_SHIFT;
	sdhci_writel(host, reg, SDHCI_TEGRA_VENDOR_CLOCK_CTRL);
}

__attribute__((used)) static int tegra_sdhci_execute_tuning(struct sdhci_host *host, u32 opcode)
{
	unsigned int min, max;

	/*
	 * Start search for minimum tap value at 10, as smaller values are
	 * may wrongly be reported as working but fail at higher speeds,
	 * according to the TRM.
	 */
	min = 10;
	while (min < 255) {
		tegra_sdhci_set_tap(host, min);
		if (!mmc_send_tuning(host->mmc, opcode, NULL))
			break;
		min++;
	}

	/* Find the maximum tap value that still passes. */
	max = min + 1;
	while (max < 255) {
		tegra_sdhci_set_tap(host, max);
		if (mmc_send_tuning(host->mmc, opcode, NULL)) {
			max--;
			break;
		}
		max++;
	}

	/* The TRM states the ideal tap value is at 75% in the passing range. */
	tegra_sdhci_set_tap(host, min + ((max - min) * 3 / 4));

	return mmc_send_tuning(host->mmc, opcode, NULL);
}

__attribute__((used)) static void tegra_sdhci_voltage_switch(struct sdhci_host *host)
{
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);
	const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;

	if (soc_data->nvquirks & NVQUIRK_HAS_PADCALIB)
		tegra_host->pad_calib_required = true;
}

__attribute__((used)) static int sdhci_tegra_probe(struct platform_device *pdev)
{
	const struct of_device_id *match;
	const struct sdhci_tegra_soc_data *soc_data;
	struct sdhci_host *host;
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_tegra *tegra_host;
	struct clk *clk;
	int rc;

	match = of_match_device(sdhci_tegra_dt_match, &pdev->dev);
	if (!match)
		return -EINVAL;
	soc_data = match->data;

	host = sdhci_pltfm_init(pdev, soc_data->pdata, sizeof(*tegra_host));
	if (IS_ERR(host))
		return PTR_ERR(host);
	pltfm_host = sdhci_priv(host);

	tegra_host = sdhci_pltfm_priv(pltfm_host);
	tegra_host->ddr_signaling = false;
	tegra_host->pad_calib_required = false;
	tegra_host->soc_data = soc_data;

	rc = mmc_of_parse(host->mmc);
	if (rc)
		goto err_parse_dt;

	if (tegra_host->soc_data->nvquirks & NVQUIRK_ENABLE_DDR50)
		host->mmc->caps |= MMC_CAP_1_8V_DDR;

	tegra_host->power_gpio = devm_gpiod_get_optional(&pdev->dev, "power",
							 GPIOD_OUT_HIGH);
	if (IS_ERR(tegra_host->power_gpio)) {
		rc = PTR_ERR(tegra_host->power_gpio);
		goto err_power_req;
	}

	clk = devm_clk_get(mmc_dev(host->mmc), NULL);
	if (IS_ERR(clk)) {
		dev_err(mmc_dev(host->mmc), "clk err\n");
		rc = PTR_ERR(clk);
		goto err_clk_get;
	}
	clk_prepare_enable(clk);
	pltfm_host->clk = clk;

	tegra_host->rst = devm_reset_control_get_exclusive(&pdev->dev,
							   "sdhci");
	if (IS_ERR(tegra_host->rst)) {
		rc = PTR_ERR(tegra_host->rst);
		dev_err(&pdev->dev, "failed to get reset control: %d\n", rc);
		goto err_rst_get;
	}

	rc = reset_control_assert(tegra_host->rst);
	if (rc)
		goto err_rst_get;

	usleep_range(2000, 4000);

	rc = reset_control_deassert(tegra_host->rst);
	if (rc)
		goto err_rst_get;

	usleep_range(2000, 4000);

	rc = sdhci_add_host(host);
	if (rc)
		goto err_add_host;

	return 0;

err_add_host:
	reset_control_assert(tegra_host->rst);
err_rst_get:
	clk_disable_unprepare(pltfm_host->clk);
err_clk_get:
err_power_req:
err_parse_dt:
	sdhci_pltfm_free(pdev);
	return rc;
}

__attribute__((used)) static int sdhci_tegra_remove(struct platform_device *pdev)
{
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct sdhci_tegra *tegra_host = sdhci_pltfm_priv(pltfm_host);

	sdhci_remove_host(host, 0);

	reset_control_assert(tegra_host->rst);
	usleep_range(2000, 4000);
	clk_disable_unprepare(pltfm_host->clk);

	sdhci_pltfm_free(pdev);

	return 0;
}

