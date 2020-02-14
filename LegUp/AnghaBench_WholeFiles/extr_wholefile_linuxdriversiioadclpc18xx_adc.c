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
struct lpc18xx_adc {int cr_reg; scalar_t__ vref; scalar_t__ clk; scalar_t__ base; int /*<<< orphan*/  lock; int /*<<< orphan*/ * dev; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {unsigned int channel; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int BIT (unsigned int) ; 
 unsigned int DIV_ROUND_UP (unsigned long,int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int /*<<< orphan*/  LPC18XX_ADC_CLK_TARGET ; 
 int LPC18XX_ADC_CONV_DONE ; 
 scalar_t__ LPC18XX_ADC_CR ; 
 unsigned int LPC18XX_ADC_CR_CLKDIV_SHIFT ; 
 unsigned int LPC18XX_ADC_CR_PDN ; 
 int LPC18XX_ADC_CR_START_NOW ; 
 scalar_t__ LPC18XX_ADC_GDR ; 
 int LPC18XX_ADC_SAMPLE_MASK ; 
 int LPC18XX_ADC_SAMPLE_SHIFT ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  clk_disable_unprepare (scalar_t__) ; 
 unsigned long clk_get_rate (scalar_t__) ; 
 int clk_prepare_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 scalar_t__ devm_regulator_get (int /*<<< orphan*/ *,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct lpc18xx_adc* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  lpc18xx_adc_iio_channels ; 
 int /*<<< orphan*/  lpc18xx_adc_info ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int readl_poll_timeout (scalar_t__,int,int,int,int) ; 
 int /*<<< orphan*/  regulator_disable (scalar_t__) ; 
 int regulator_enable (scalar_t__) ; 
 int regulator_get_voltage (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int lpc18xx_adc_read_chan(struct lpc18xx_adc *adc, unsigned int ch)
{
	int ret;
	u32 reg;

	reg = adc->cr_reg | BIT(ch) | LPC18XX_ADC_CR_START_NOW;
	writel(reg, adc->base + LPC18XX_ADC_CR);

	ret = readl_poll_timeout(adc->base + LPC18XX_ADC_GDR, reg,
				 reg & LPC18XX_ADC_CONV_DONE, 3, 9);
	if (ret) {
		dev_warn(adc->dev, "adc read timed out\n");
		return ret;
	}

	return (reg >> LPC18XX_ADC_SAMPLE_SHIFT) & LPC18XX_ADC_SAMPLE_MASK;
}

__attribute__((used)) static int lpc18xx_adc_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct lpc18xx_adc *adc = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&adc->lock);
		*val = lpc18xx_adc_read_chan(adc, chan->channel);
		mutex_unlock(&adc->lock);
		if (*val < 0)
			return *val;

		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		*val = regulator_get_voltage(adc->vref) / 1000;
		*val2 = 10;

		return IIO_VAL_FRACTIONAL_LOG2;
	}

	return -EINVAL;
}

__attribute__((used)) static int lpc18xx_adc_probe(struct platform_device *pdev)
{
	struct iio_dev *indio_dev;
	struct lpc18xx_adc *adc;
	struct resource *res;
	unsigned int clkdiv;
	unsigned long rate;
	int ret;

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*adc));
	if (!indio_dev)
		return -ENOMEM;

	platform_set_drvdata(pdev, indio_dev);
	adc = iio_priv(indio_dev);
	adc->dev = &pdev->dev;
	mutex_init(&adc->lock);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	adc->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(adc->base))
		return PTR_ERR(adc->base);

	adc->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(adc->clk)) {
		dev_err(&pdev->dev, "error getting clock\n");
		return PTR_ERR(adc->clk);
	}

	rate = clk_get_rate(adc->clk);
	clkdiv = DIV_ROUND_UP(rate, LPC18XX_ADC_CLK_TARGET);

	adc->vref = devm_regulator_get(&pdev->dev, "vref");
	if (IS_ERR(adc->vref)) {
		dev_err(&pdev->dev, "error getting regulator\n");
		return PTR_ERR(adc->vref);
	}

	indio_dev->name = dev_name(&pdev->dev);
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->info = &lpc18xx_adc_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = lpc18xx_adc_iio_channels;
	indio_dev->num_channels = ARRAY_SIZE(lpc18xx_adc_iio_channels);

	ret = regulator_enable(adc->vref);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable regulator\n");
		return ret;
	}

	ret = clk_prepare_enable(adc->clk);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable clock\n");
		goto dis_reg;
	}

	adc->cr_reg = (clkdiv << LPC18XX_ADC_CR_CLKDIV_SHIFT) |
			LPC18XX_ADC_CR_PDN;
	writel(adc->cr_reg, adc->base + LPC18XX_ADC_CR);

	ret = iio_device_register(indio_dev);
	if (ret) {
		dev_err(&pdev->dev, "unable to register device\n");
		goto dis_clk;
	}

	return 0;

dis_clk:
	writel(0, adc->base + LPC18XX_ADC_CR);
	clk_disable_unprepare(adc->clk);
dis_reg:
	regulator_disable(adc->vref);
	return ret;
}

__attribute__((used)) static int lpc18xx_adc_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);
	struct lpc18xx_adc *adc = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	writel(0, adc->base + LPC18XX_ADC_CR);
	clk_disable_unprepare(adc->clk);
	regulator_disable(adc->vref);

	return 0;
}

