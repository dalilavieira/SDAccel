#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct sdhci_sirf_priv {int gpio_cd; } ;
struct sdhci_pltfm_host {void* private; struct sdhci_host* clk; } ;
struct sdhci_host {void* private; int flags; struct mmc_host* mmc; scalar_t__ ioaddr; } ;
struct TYPE_3__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct mmc_host {int caps; } ;
struct clk {void* private; int flags; struct mmc_host* mmc; scalar_t__ ioaddr; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 scalar_t__ IS_ERR (struct sdhci_host*) ; 
 int MMC_BUS_WIDTH_4 ; 
 int MMC_BUS_WIDTH_8 ; 
 int MMC_CAP_UHS_SDR50 ; 
 int PTR_ERR (struct sdhci_host*) ; 
 int SDHCI_CAPABILITIES_1 ; 
 int SDHCI_CLK_DELAY_SETTING ; 
 int SDHCI_CTRL_4BITBUS ; 
 int SDHCI_HOST_CONTROL ; 
 int SDHCI_HOST_VERSION ; 
 int SDHCI_SDIO_IRQ_ENABLED ; 
 int SDHCI_SIRF_8BITBUS ; 
 int SDHCI_SLOT_INT_STATUS ; 
 int SDHCI_SPEC_300 ; 
 int SDHCI_SUPPORT_DDR50 ; 
 int SDHCI_SUPPORT_SDR50 ; 
 int SDHCI_USE_SDR50_TUNING ; 
 int SIRF_TUNING_COUNT ; 
 int /*<<< orphan*/  __sdhci_read_caps (struct sdhci_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct sdhci_host*) ; 
 int clk_prepare_enable (struct sdhci_host*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct sdhci_host* devm_clk_get (TYPE_1__*,int /*<<< orphan*/ *) ; 
 scalar_t__ gpio_is_valid (int) ; 
 int /*<<< orphan*/  mmc_dev (struct mmc_host*) ; 
 int mmc_gpio_request_cd (struct mmc_host*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_gpiod_request_cd_irq (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_hostname (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_send_tuning (struct mmc_host*,int,int /*<<< orphan*/ *) ; 
 int of_get_named_gpio (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int readb (scalar_t__) ; 
 int readl (scalar_t__) ; 
 int readw (scalar_t__) ; 
 int sdhci_add_host (struct sdhci_host*) ; 
 int /*<<< orphan*/  sdhci_get_of_property (struct platform_device*) ; 
 int /*<<< orphan*/  sdhci_pltfm_free (struct platform_device*) ; 
 struct sdhci_host* sdhci_pltfm_init (struct platform_device*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sdhci_remove_host (struct sdhci_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdhci_sirf_pdata ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  writew (int,scalar_t__) ; 

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

__attribute__((used)) static void sdhci_sirf_set_bus_width(struct sdhci_host *host, int width)
{
	u8 ctrl;

	ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
	ctrl &= ~(SDHCI_CTRL_4BITBUS | SDHCI_SIRF_8BITBUS);

	/*
	 * CSR atlas7 and prima2 SD host version is not 3.0
	 * 8bit-width enable bit of CSR SD hosts is 3,
	 * while stardard hosts use bit 5
	 */
	if (width == MMC_BUS_WIDTH_8)
		ctrl |= SDHCI_SIRF_8BITBUS;
	else if (width == MMC_BUS_WIDTH_4)
		ctrl |= SDHCI_CTRL_4BITBUS;

	sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);
}

__attribute__((used)) static u32 sdhci_sirf_readl_le(struct sdhci_host *host, int reg)
{
	u32 val = readl(host->ioaddr + reg);

	if (unlikely((reg == SDHCI_CAPABILITIES_1) &&
			(host->mmc->caps & MMC_CAP_UHS_SDR50))) {
		/* fake CAP_1 register */
		val = SDHCI_SUPPORT_DDR50 |
			SDHCI_SUPPORT_SDR50 | SDHCI_USE_SDR50_TUNING;
	}

	if (unlikely(reg == SDHCI_SLOT_INT_STATUS)) {
		u32 prss = val;
		/* fake chips as V3.0 host conreoller */
		prss &= ~(0xFF << 16);
		val = prss | (SDHCI_SPEC_300 << 16);
	}
	return val;
}

__attribute__((used)) static u16 sdhci_sirf_readw_le(struct sdhci_host *host, int reg)
{
	u16 ret = 0;

	ret = readw(host->ioaddr + reg);

	if (unlikely(reg == SDHCI_HOST_VERSION)) {
		ret = readw(host->ioaddr + SDHCI_HOST_VERSION);
		ret |= SDHCI_SPEC_300;
	}

	return ret;
}

__attribute__((used)) static int sdhci_sirf_execute_tuning(struct sdhci_host *host, u32 opcode)
{
	int tuning_seq_cnt = 3;
	int phase;
	u8 tuned_phase_cnt = 0;
	int rc = 0, longest_range = 0;
	int start = -1, end = 0, tuning_value = -1, range = 0;
	u16 clock_setting;
	struct mmc_host *mmc = host->mmc;

	clock_setting = sdhci_readw(host, SDHCI_CLK_DELAY_SETTING);
	clock_setting &= ~0x3fff;

retry:
	phase = 0;
	tuned_phase_cnt = 0;
	do {
		sdhci_writel(host,
			clock_setting | phase,
			SDHCI_CLK_DELAY_SETTING);

		if (!mmc_send_tuning(mmc, opcode, NULL)) {
			/* Tuning is successful at this tuning point */
			tuned_phase_cnt++;
			dev_dbg(mmc_dev(mmc), "%s: Found good phase = %d\n",
				 mmc_hostname(mmc), phase);
			if (start == -1)
				start = phase;
			end = phase;
			range++;
			if (phase == (SIRF_TUNING_COUNT - 1)
				&& range > longest_range)
				tuning_value = (start + end) / 2;
		} else {
			dev_dbg(mmc_dev(mmc), "%s: Found bad phase = %d\n",
				 mmc_hostname(mmc), phase);
			if (range > longest_range) {
				tuning_value = (start + end) / 2;
				longest_range = range;
			}
			start = -1;
			end = range = 0;
		}
	} while (++phase < SIRF_TUNING_COUNT);

	if (tuned_phase_cnt && tuning_value > 0) {
		/*
		 * Finally set the selected phase in delay
		 * line hw block.
		 */
		phase = tuning_value;
		sdhci_writel(host,
			clock_setting | phase,
			SDHCI_CLK_DELAY_SETTING);

		dev_dbg(mmc_dev(mmc), "%s: Setting the tuning phase to %d\n",
			 mmc_hostname(mmc), phase);
	} else {
		if (--tuning_seq_cnt)
			goto retry;
		/* Tuning failed */
		dev_dbg(mmc_dev(mmc), "%s: No tuning point found\n",
		       mmc_hostname(mmc));
		rc = -EIO;
	}

	return rc;
}

__attribute__((used)) static int sdhci_sirf_probe(struct platform_device *pdev)
{
	struct sdhci_host *host;
	struct sdhci_pltfm_host *pltfm_host;
	struct sdhci_sirf_priv *priv;
	struct clk *clk;
	int gpio_cd;
	int ret;

	clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(clk)) {
		dev_err(&pdev->dev, "unable to get clock");
		return PTR_ERR(clk);
	}

	if (pdev->dev.of_node)
		gpio_cd = of_get_named_gpio(pdev->dev.of_node, "cd-gpios", 0);
	else
		gpio_cd = -EINVAL;

	host = sdhci_pltfm_init(pdev, &sdhci_sirf_pdata, sizeof(struct sdhci_sirf_priv));
	if (IS_ERR(host))
		return PTR_ERR(host);

	pltfm_host = sdhci_priv(host);
	pltfm_host->clk = clk;
	priv = sdhci_pltfm_priv(pltfm_host);
	priv->gpio_cd = gpio_cd;

	sdhci_get_of_property(pdev);

	ret = clk_prepare_enable(pltfm_host->clk);
	if (ret)
		goto err_clk_prepare;

	ret = sdhci_add_host(host);
	if (ret)
		goto err_sdhci_add;

	/*
	 * We must request the IRQ after sdhci_add_host(), as the tasklet only
	 * gets setup in sdhci_add_host() and we oops.
	 */
	if (gpio_is_valid(priv->gpio_cd)) {
		ret = mmc_gpio_request_cd(host->mmc, priv->gpio_cd, 0);
		if (ret) {
			dev_err(&pdev->dev, "card detect irq request failed: %d\n",
				ret);
			goto err_request_cd;
		}
		mmc_gpiod_request_cd_irq(host->mmc);
	}

	return 0;

err_request_cd:
	sdhci_remove_host(host, 0);
err_sdhci_add:
	clk_disable_unprepare(pltfm_host->clk);
err_clk_prepare:
	sdhci_pltfm_free(pdev);
	return ret;
}

