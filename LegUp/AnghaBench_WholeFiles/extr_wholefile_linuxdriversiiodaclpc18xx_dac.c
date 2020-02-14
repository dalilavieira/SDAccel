#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct lpc18xx_dac {scalar_t__ vref; scalar_t__ clk; scalar_t__ base; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 scalar_t__ LPC18XX_DAC_CR ; 
 int LPC18XX_DAC_CR_BIAS ; 
 int LPC18XX_DAC_CR_VALUE_MASK ; 
 int LPC18XX_DAC_CR_VALUE_SHIFT ; 
 scalar_t__ LPC18XX_DAC_CTRL ; 
 int LPC18XX_DAC_CTRL_DMA_ENA ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 scalar_t__ devm_regulator_get (int /*<<< orphan*/ *,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct lpc18xx_dac* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  lpc18xx_dac_iio_channels ; 
 int /*<<< orphan*/  lpc18xx_dac_info ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  regulator_disable (scalar_t__) ; 
 int regulator_enable (scalar_t__) ; 
 int regulator_get_voltage (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int lpc18xx_dac_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct lpc18xx_dac *dac = iio_priv(indio_dev);
	u32 reg;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		reg = readl(dac->base + LPC18XX_DAC_CR);
		*val = reg >> LPC18XX_DAC_CR_VALUE_SHIFT;
		*val &= LPC18XX_DAC_CR_VALUE_MASK;

		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		*val = regulator_get_voltage(dac->vref) / 1000;
		*val2 = 10;

		return IIO_VAL_FRACTIONAL_LOG2;
	}

	return -EINVAL;
}

__attribute__((used)) static int lpc18xx_dac_write_raw(struct iio_dev *indio_dev,
				 struct iio_chan_spec const *chan,
				 int val, int val2, long mask)
{
	struct lpc18xx_dac *dac = iio_priv(indio_dev);
	u32 reg;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val < 0 || val > LPC18XX_DAC_CR_VALUE_MASK)
			return -EINVAL;

		reg = LPC18XX_DAC_CR_BIAS;
		reg |= val << LPC18XX_DAC_CR_VALUE_SHIFT;

		mutex_lock(&dac->lock);
		writel(reg, dac->base + LPC18XX_DAC_CR);
		writel(LPC18XX_DAC_CTRL_DMA_ENA, dac->base + LPC18XX_DAC_CTRL);
		mutex_unlock(&dac->lock);

		return 0;
	}

	return -EINVAL;
}

__attribute__((used)) static int lpc18xx_dac_probe(struct platform_device *pdev)
{
	struct iio_dev *indio_dev;
	struct lpc18xx_dac *dac;
	struct resource *res;
	int ret;

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*dac));
	if (!indio_dev)
		return -ENOMEM;

	platform_set_drvdata(pdev, indio_dev);
	dac = iio_priv(indio_dev);
	mutex_init(&dac->lock);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	dac->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(dac->base))
		return PTR_ERR(dac->base);

	dac->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(dac->clk)) {
		dev_err(&pdev->dev, "error getting clock\n");
		return PTR_ERR(dac->clk);
	}

	dac->vref = devm_regulator_get(&pdev->dev, "vref");
	if (IS_ERR(dac->vref)) {
		dev_err(&pdev->dev, "error getting regulator\n");
		return PTR_ERR(dac->vref);
	}

	indio_dev->name = dev_name(&pdev->dev);
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->info = &lpc18xx_dac_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = lpc18xx_dac_iio_channels;
	indio_dev->num_channels = ARRAY_SIZE(lpc18xx_dac_iio_channels);

	ret = regulator_enable(dac->vref);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable regulator\n");
		return ret;
	}

	ret = clk_prepare_enable(dac->clk);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable clock\n");
		goto dis_reg;
	}

	writel(0, dac->base + LPC18XX_DAC_CTRL);
	writel(0, dac->base + LPC18XX_DAC_CR);

	ret = iio_device_register(indio_dev);
	if (ret) {
		dev_err(&pdev->dev, "unable to register device\n");
		goto dis_clk;
	}

	return 0;

dis_clk:
	clk_disable_unprepare(dac->clk);
dis_reg:
	regulator_disable(dac->vref);
	return ret;
}

__attribute__((used)) static int lpc18xx_dac_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);
	struct lpc18xx_dac *dac = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	writel(0, dac->base + LPC18XX_DAC_CTRL);
	clk_disable_unprepare(dac->clk);
	regulator_disable(dac->vref);

	return 0;
}

