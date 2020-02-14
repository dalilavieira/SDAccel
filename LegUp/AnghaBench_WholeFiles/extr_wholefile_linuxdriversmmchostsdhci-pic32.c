#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct sdhci_pltfm_host {void* private; } ;
struct sdhci_host {void* private; int flags; scalar_t__ version; int caps; scalar_t__ ioaddr; int /*<<< orphan*/  mmc; } ;
struct TYPE_4__ {struct pic32_sdhci_platform_data* platform_data; } ;
struct platform_device {TYPE_1__ dev; } ;
struct pic32_sdhci_priv {struct sdhci_host* sys_clk; struct sdhci_host* base_clk; } ;
struct pic32_sdhci_platform_data {int (* setup_dma ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ADMA_FIFO_RD_THSHLD ; 
 int /*<<< orphan*/  ADMA_FIFO_WR_THSHLD ; 
 scalar_t__ IS_ERR (struct sdhci_host*) ; 
 int MMC_BUS_WIDTH_4 ; 
 int MMC_BUS_WIDTH_8 ; 
 int PTR_ERR (struct sdhci_host*) ; 
 scalar_t__ SDHCI_CAPABILITIES ; 
 int /*<<< orphan*/  SDHCI_CTRL_4BITBUS ; 
 int /*<<< orphan*/  SDHCI_CTRL_8BITBUS ; 
 int /*<<< orphan*/  SDHCI_CTRL_CDSSEL ; 
 int /*<<< orphan*/  SDHCI_CTRL_CDTLVL ; 
 int SDHCI_HOST_CONTROL ; 
 scalar_t__ SDHCI_INT_STATUS ; 
 int SDHCI_SDIO_IRQ_ENABLED ; 
 scalar_t__ SDHCI_SPEC_300 ; 
 int SDH_CAPS_SDH_SLOT_TYPE_MASK ; 
 int SDH_SHARED_BUS_CLK_PINS ; 
 scalar_t__ SDH_SHARED_BUS_CTRL ; 
 int SDH_SHARED_BUS_IRQ_PINS ; 
 int SDH_SHARED_BUS_NR_CLK_PINS_MASK ; 
 int SDH_SHARED_BUS_NR_IRQ_PINS_MASK ; 
 int SDH_SLOT_TYPE_SHARED_BUS ; 
 int /*<<< orphan*/  __sdhci_read_caps (struct sdhci_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct sdhci_host*) ; 
 unsigned int clk_get_rate (struct sdhci_host*) ; 
 int clk_prepare_enable (struct sdhci_host*) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_1__*,char*) ; 
 void* devm_clk_get (TYPE_1__*,char*) ; 
 int mmc_of_parse (int /*<<< orphan*/ ) ; 
 struct sdhci_host* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  readb (scalar_t__) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  readw (scalar_t__) ; 
 int sdhci_add_host (struct sdhci_host*) ; 
 int /*<<< orphan*/  sdhci_pic32_pdata ; 
 int /*<<< orphan*/  sdhci_pltfm_free (struct platform_device*) ; 
 struct sdhci_host* sdhci_pltfm_init (struct platform_device*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sdhci_remove_host (struct sdhci_host*,int) ; 
 int stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 
 int /*<<< orphan*/  writew (int /*<<< orphan*/ ,scalar_t__) ; 

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

__attribute__((used)) static unsigned int pic32_sdhci_get_max_clock(struct sdhci_host *host)
{
	struct pic32_sdhci_priv *sdhci_pdata = sdhci_priv(host);

	return clk_get_rate(sdhci_pdata->base_clk);
}

__attribute__((used)) static void pic32_sdhci_set_bus_width(struct sdhci_host *host, int width)
{
	u8 ctrl;

	ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
	if (width == MMC_BUS_WIDTH_8) {
		ctrl &= ~SDHCI_CTRL_4BITBUS;
		if (host->version >= SDHCI_SPEC_300)
			ctrl |= SDHCI_CTRL_8BITBUS;
	} else {
		if (host->version >= SDHCI_SPEC_300)
			ctrl &= ~SDHCI_CTRL_8BITBUS;
		if (width == MMC_BUS_WIDTH_4)
			ctrl |= SDHCI_CTRL_4BITBUS;
		else
			ctrl &= ~SDHCI_CTRL_4BITBUS;
	}

	/* CD select and test bits must be set for errata workaround. */
	ctrl &= ~SDHCI_CTRL_CDTLVL;
	ctrl |= SDHCI_CTRL_CDSSEL;
	sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);
}

__attribute__((used)) static unsigned int pic32_sdhci_get_ro(struct sdhci_host *host)
{
	/*
	 * The SDHCI_WRITE_PROTECT bit is unstable on current hardware so we
	 * can't depend on its value in any way.
	 */
	return 0;
}

__attribute__((used)) static void pic32_sdhci_shared_bus(struct platform_device *pdev)
{
	struct sdhci_host *host = platform_get_drvdata(pdev);
	u32 bus = readl(host->ioaddr + SDH_SHARED_BUS_CTRL);
	u32 clk_pins = (bus & SDH_SHARED_BUS_NR_CLK_PINS_MASK) >> 0;
	u32 irq_pins = (bus & SDH_SHARED_BUS_NR_IRQ_PINS_MASK) >> 4;

	/* select first clock */
	if (clk_pins & 1)
		bus |= (1 << SDH_SHARED_BUS_CLK_PINS);

	/* select first interrupt */
	if (irq_pins & 1)
		bus |= (1 << SDH_SHARED_BUS_IRQ_PINS);

	writel(bus, host->ioaddr + SDH_SHARED_BUS_CTRL);
}

__attribute__((used)) static int pic32_sdhci_probe_platform(struct platform_device *pdev,
				      struct pic32_sdhci_priv *pdata)
{
	int ret = 0;
	u32 caps_slot_type;
	struct sdhci_host *host = platform_get_drvdata(pdev);

	/* Check card slot connected on shared bus. */
	host->caps = readl(host->ioaddr + SDHCI_CAPABILITIES);
	caps_slot_type = (host->caps & SDH_CAPS_SDH_SLOT_TYPE_MASK) >> 30;
	if (caps_slot_type == SDH_SLOT_TYPE_SHARED_BUS)
		pic32_sdhci_shared_bus(pdev);

	return ret;
}

__attribute__((used)) static int pic32_sdhci_probe(struct platform_device *pdev)
{
	struct sdhci_host *host;
	struct sdhci_pltfm_host *pltfm_host;
	struct pic32_sdhci_priv *sdhci_pdata;
	struct pic32_sdhci_platform_data *plat_data;
	int ret;

	host = sdhci_pltfm_init(pdev, &sdhci_pic32_pdata,
				sizeof(struct pic32_sdhci_priv));
	if (IS_ERR(host)) {
		ret = PTR_ERR(host);
		goto err;
	}

	pltfm_host = sdhci_priv(host);
	sdhci_pdata = sdhci_pltfm_priv(pltfm_host);

	plat_data = pdev->dev.platform_data;
	if (plat_data && plat_data->setup_dma) {
		ret = plat_data->setup_dma(ADMA_FIFO_RD_THSHLD,
					   ADMA_FIFO_WR_THSHLD);
		if (ret)
			goto err_host;
	}

	sdhci_pdata->sys_clk = devm_clk_get(&pdev->dev, "sys_clk");
	if (IS_ERR(sdhci_pdata->sys_clk)) {
		ret = PTR_ERR(sdhci_pdata->sys_clk);
		dev_err(&pdev->dev, "Error getting clock\n");
		goto err_host;
	}

	ret = clk_prepare_enable(sdhci_pdata->sys_clk);
	if (ret) {
		dev_err(&pdev->dev, "Error enabling clock\n");
		goto err_host;
	}

	sdhci_pdata->base_clk = devm_clk_get(&pdev->dev, "base_clk");
	if (IS_ERR(sdhci_pdata->base_clk)) {
		ret = PTR_ERR(sdhci_pdata->base_clk);
		dev_err(&pdev->dev, "Error getting clock\n");
		goto err_sys_clk;
	}

	ret = clk_prepare_enable(sdhci_pdata->base_clk);
	if (ret) {
		dev_err(&pdev->dev, "Error enabling clock\n");
		goto err_base_clk;
	}

	ret = mmc_of_parse(host->mmc);
	if (ret)
		goto err_base_clk;

	ret = pic32_sdhci_probe_platform(pdev, sdhci_pdata);
	if (ret) {
		dev_err(&pdev->dev, "failed to probe platform!\n");
		goto err_base_clk;
	}

	ret = sdhci_add_host(host);
	if (ret)
		goto err_base_clk;

	dev_info(&pdev->dev, "Successfully added sdhci host\n");
	return 0;

err_base_clk:
	clk_disable_unprepare(sdhci_pdata->base_clk);
err_sys_clk:
	clk_disable_unprepare(sdhci_pdata->sys_clk);
err_host:
	sdhci_pltfm_free(pdev);
err:
	dev_err(&pdev->dev, "pic32-sdhci probe failed: %d\n", ret);
	return ret;
}

__attribute__((used)) static int pic32_sdhci_remove(struct platform_device *pdev)
{
	struct sdhci_host *host = platform_get_drvdata(pdev);
	struct pic32_sdhci_priv *sdhci_pdata = sdhci_priv(host);
	u32 scratch;

	scratch = readl(host->ioaddr + SDHCI_INT_STATUS);
	sdhci_remove_host(host, scratch == (u32)~0);
	clk_disable_unprepare(sdhci_pdata->base_clk);
	clk_disable_unprepare(sdhci_pdata->sys_clk);
	sdhci_pltfm_free(pdev);

	return 0;
}

