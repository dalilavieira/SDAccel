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
typedef  int /*<<< orphan*/  u32 ;
struct platform_device {int dummy; } ;
struct mmc_ios {scalar_t__ timing; } ;
struct hi3798cv200_priv {void* sample_clk; void* drive_clk; } ;
struct dw_mci_slot {int /*<<< orphan*/  mmc; struct dw_mci* host; } ;
struct dw_mci {struct hi3798cv200_priv* priv; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALL_INT_CLR ; 
 int ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  DDR_REG ; 
 int EINVAL ; 
 int /*<<< orphan*/  ENABLE_SHIFT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (void*) ; 
 scalar_t__ MMC_TIMING_LEGACY ; 
 scalar_t__ MMC_TIMING_MMC_DDR52 ; 
 scalar_t__ MMC_TIMING_MMC_HS ; 
 scalar_t__ MMC_TIMING_MMC_HS200 ; 
 scalar_t__ MMC_TIMING_MMC_HS400 ; 
 scalar_t__ MMC_TIMING_UHS_DDR50 ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  RINTSTS ; 
 int /*<<< orphan*/  SDMMC_DDR_HS400 ; 
 int /*<<< orphan*/  SDMMC_ENABLE_PHASE ; 
 int /*<<< orphan*/  SDMMC_UHS_DDR ; 
 int /*<<< orphan*/  UHS_REG ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  clk_set_phase (void*,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 void* devm_clk_get (int /*<<< orphan*/ ,char*) ; 
 struct hi3798cv200_priv* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int dw_mci_pltfm_register (struct platform_device*,int /*<<< orphan*/ *) ; 
 int dw_mci_pltfm_remove (struct platform_device*) ; 
 int /*<<< orphan*/  hi3798cv200_data ; 
 int /*<<< orphan*/  mci_readl (struct dw_mci*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mci_writel (struct dw_mci*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mmc_send_tuning (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct dw_mci* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static void dw_mci_hi3798cv200_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
	struct hi3798cv200_priv *priv = host->priv;
	u32 val;

	val = mci_readl(host, UHS_REG);
	if (ios->timing == MMC_TIMING_MMC_DDR52 ||
	    ios->timing == MMC_TIMING_UHS_DDR50)
		val |= SDMMC_UHS_DDR;
	else
		val &= ~SDMMC_UHS_DDR;
	mci_writel(host, UHS_REG, val);

	val = mci_readl(host, ENABLE_SHIFT);
	if (ios->timing == MMC_TIMING_MMC_DDR52)
		val |= SDMMC_ENABLE_PHASE;
	else
		val &= ~SDMMC_ENABLE_PHASE;
	mci_writel(host, ENABLE_SHIFT, val);

	val = mci_readl(host, DDR_REG);
	if (ios->timing == MMC_TIMING_MMC_HS400)
		val |= SDMMC_DDR_HS400;
	else
		val &= ~SDMMC_DDR_HS400;
	mci_writel(host, DDR_REG, val);

	if (ios->timing == MMC_TIMING_MMC_HS ||
	    ios->timing == MMC_TIMING_LEGACY)
		clk_set_phase(priv->drive_clk, 180);
	else if (ios->timing == MMC_TIMING_MMC_HS200)
		clk_set_phase(priv->drive_clk, 135);
}

__attribute__((used)) static int dw_mci_hi3798cv200_execute_tuning(struct dw_mci_slot *slot,
					     u32 opcode)
{
	int degrees[] = { 0, 45, 90, 135, 180, 225, 270, 315 };
	struct dw_mci *host = slot->host;
	struct hi3798cv200_priv *priv = host->priv;
	int raise_point = -1, fall_point = -1;
	int err, prev_err = -1;
	int found = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(degrees); i++) {
		clk_set_phase(priv->sample_clk, degrees[i]);
		mci_writel(host, RINTSTS, ALL_INT_CLR);

		err = mmc_send_tuning(slot->mmc, opcode, NULL);
		if (!err)
			found = 1;

		if (i > 0) {
			if (err && !prev_err)
				fall_point = i - 1;
			if (!err && prev_err)
				raise_point = i;
		}

		if (raise_point != -1 && fall_point != -1)
			goto tuning_out;

		prev_err = err;
		err = 0;
	}

tuning_out:
	if (found) {
		if (raise_point == -1)
			raise_point = 0;
		if (fall_point == -1)
			fall_point = ARRAY_SIZE(degrees) - 1;
		if (fall_point < raise_point) {
			if ((raise_point + fall_point) >
			    (ARRAY_SIZE(degrees) - 1))
				i = fall_point / 2;
			else
				i = (raise_point + ARRAY_SIZE(degrees) - 1) / 2;
		} else {
			i = (raise_point + fall_point) / 2;
		}

		clk_set_phase(priv->sample_clk, degrees[i]);
		dev_dbg(host->dev, "Tuning clk_sample[%d, %d], set[%d]\n",
			raise_point, fall_point, degrees[i]);
	} else {
		dev_err(host->dev, "No valid clk_sample shift! use default\n");
		err = -EINVAL;
	}

	mci_writel(host, RINTSTS, ALL_INT_CLR);
	return err;
}

__attribute__((used)) static int dw_mci_hi3798cv200_init(struct dw_mci *host)
{
	struct hi3798cv200_priv *priv;
	int ret;

	priv = devm_kzalloc(host->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->sample_clk = devm_clk_get(host->dev, "ciu-sample");
	if (IS_ERR(priv->sample_clk)) {
		dev_err(host->dev, "failed to get ciu-sample clock\n");
		return PTR_ERR(priv->sample_clk);
	}

	priv->drive_clk = devm_clk_get(host->dev, "ciu-drive");
	if (IS_ERR(priv->drive_clk)) {
		dev_err(host->dev, "failed to get ciu-drive clock\n");
		return PTR_ERR(priv->drive_clk);
	}

	ret = clk_prepare_enable(priv->sample_clk);
	if (ret) {
		dev_err(host->dev, "failed to enable ciu-sample clock\n");
		return ret;
	}

	ret = clk_prepare_enable(priv->drive_clk);
	if (ret) {
		dev_err(host->dev, "failed to enable ciu-drive clock\n");
		goto disable_sample_clk;
	}

	host->priv = priv;
	return 0;

disable_sample_clk:
	clk_disable_unprepare(priv->sample_clk);
	return ret;
}

__attribute__((used)) static int dw_mci_hi3798cv200_probe(struct platform_device *pdev)
{
	return dw_mci_pltfm_register(pdev, &hi3798cv200_data);
}

__attribute__((used)) static int dw_mci_hi3798cv200_remove(struct platform_device *pdev)
{
	struct dw_mci *host = platform_get_drvdata(pdev);
	struct hi3798cv200_priv *priv = host->priv;

	clk_disable_unprepare(priv->drive_clk);
	clk_disable_unprepare(priv->sample_clk);

	return dw_mci_pltfm_remove(pdev);
}

