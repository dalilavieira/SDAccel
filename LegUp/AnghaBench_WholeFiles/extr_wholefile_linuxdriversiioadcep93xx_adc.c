#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct resource {int dummy; } ;
struct TYPE_7__ {struct TYPE_7__* parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct iio_dev {int /*<<< orphan*/  channels; int /*<<< orphan*/  num_channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {int channel; int address; } ;
struct ep93xx_adc_priv {int lastch; scalar_t__ clk; int /*<<< orphan*/  lock; scalar_t__ base; } ;
struct clk {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int DIV_ROUND_UP (int,int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ EP93XX_ADC_RESULT ; 
 int EP93XX_ADC_SDR ; 
 scalar_t__ EP93XX_ADC_SWITCH ; 
 scalar_t__ EP93XX_ADC_SW_LOCK ; 
 int ETIMEDOUT ; 
#define  IIO_CHAN_INFO_OFFSET 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  clk_disable (scalar_t__) ; 
 int clk_enable (scalar_t__) ; 
 struct clk* clk_get_parent (scalar_t__) ; 
 int clk_get_rate (struct clk*) ; 
 int clk_set_rate (scalar_t__,int) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  dev_name (TYPE_1__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*) ; 
 scalar_t__ devm_clk_get (TYPE_1__*,int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_1__*,int) ; 
 scalar_t__ devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 int /*<<< orphan*/  ep93xx_adc_channels ; 
 int /*<<< orphan*/  ep93xx_adc_delay (int,int) ; 
 int /*<<< orphan*/  ep93xx_adc_info ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ep93xx_adc_priv* iio_priv (struct iio_dev*) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 scalar_t__ msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int readl_relaxed (scalar_t__) ; 
 int sign_extend32 (int,int) ; 
 int /*<<< orphan*/  time_after (scalar_t__,unsigned long) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static int ep93xx_read_raw(struct iio_dev *iiodev,
			   struct iio_chan_spec const *channel, int *value,
			   int *shift, long mask)
{
	struct ep93xx_adc_priv *priv = iio_priv(iiodev);
	unsigned long timeout;
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&priv->lock);
		if (priv->lastch != channel->channel) {
			priv->lastch = channel->channel;
			/*
			 * Switch register is software-locked, unlocking must be
			 * immediately followed by write
			 */
			local_irq_disable();
			writel_relaxed(0xAA, priv->base + EP93XX_ADC_SW_LOCK);
			writel_relaxed(channel->address,
				       priv->base + EP93XX_ADC_SWITCH);
			local_irq_enable();
			/*
			 * Settling delay depends on module clock and could be
			 * 2ms or 500us
			 */
			ep93xx_adc_delay(2000, 2000);
		}
		/* Start the conversion, eventually discarding old result */
		readl_relaxed(priv->base + EP93XX_ADC_RESULT);
		/* Ensure maximum conversion rate is not exceeded */
		ep93xx_adc_delay(DIV_ROUND_UP(1000000, 925),
				 DIV_ROUND_UP(1000000, 925));
		/* At this point conversion must be completed, but anyway... */
		ret = IIO_VAL_INT;
		timeout = jiffies + msecs_to_jiffies(1) + 1;
		while (1) {
			u32 t;

			t = readl_relaxed(priv->base + EP93XX_ADC_RESULT);
			if (t & EP93XX_ADC_SDR) {
				*value = sign_extend32(t, 15);
				break;
			}

			if (time_after(jiffies, timeout)) {
				dev_err(&iiodev->dev, "Conversion timeout\n");
				ret = -ETIMEDOUT;
				break;
			}

			cpu_relax();
		}
		mutex_unlock(&priv->lock);
		return ret;

	case IIO_CHAN_INFO_OFFSET:
		/* According to datasheet, range is -25000..25000 */
		*value = 25000;
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		/* Typical supply voltage is 3.3v */
		*value = (1ULL << 32) * 3300 / 50000;
		*shift = 32;
		return IIO_VAL_FRACTIONAL_LOG2;
	}

	return -EINVAL;
}

__attribute__((used)) static int ep93xx_adc_probe(struct platform_device *pdev)
{
	int ret;
	struct iio_dev *iiodev;
	struct ep93xx_adc_priv *priv;
	struct clk *pclk;
	struct resource *res;

	iiodev = devm_iio_device_alloc(&pdev->dev, sizeof(*priv));
	if (!iiodev)
		return -ENOMEM;
	priv = iio_priv(iiodev);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->base)) {
		dev_err(&pdev->dev, "Cannot map memory resource\n");
		return PTR_ERR(priv->base);
	}

	iiodev->dev.parent = &pdev->dev;
	iiodev->name = dev_name(&pdev->dev);
	iiodev->modes = INDIO_DIRECT_MODE;
	iiodev->info = &ep93xx_adc_info;
	iiodev->num_channels = ARRAY_SIZE(ep93xx_adc_channels);
	iiodev->channels = ep93xx_adc_channels;

	priv->lastch = -1;
	mutex_init(&priv->lock);

	platform_set_drvdata(pdev, iiodev);

	priv->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(priv->clk)) {
		dev_err(&pdev->dev, "Cannot obtain clock\n");
		return PTR_ERR(priv->clk);
	}

	pclk = clk_get_parent(priv->clk);
	if (!pclk) {
		dev_warn(&pdev->dev, "Cannot obtain parent clock\n");
	} else {
		/*
		 * This is actually a place for improvement:
		 * EP93xx ADC supports two clock divisors -- 4 and 16,
		 * resulting in conversion rates 3750 and 925 samples per second
		 * with 500us or 2ms settling time respectively.
		 * One might find this interesting enough to be configurable.
		 */
		ret = clk_set_rate(priv->clk, clk_get_rate(pclk) / 16);
		if (ret)
			dev_warn(&pdev->dev, "Cannot set clock rate\n");
		/*
		 * We can tolerate rate setting failure because the module should
		 * work in any case.
		 */
	}

	ret = clk_enable(priv->clk);
	if (ret) {
		dev_err(&pdev->dev, "Cannot enable clock\n");
		return ret;
	}

	ret = iio_device_register(iiodev);
	if (ret)
		clk_disable(priv->clk);

	return ret;
}

__attribute__((used)) static int ep93xx_adc_remove(struct platform_device *pdev)
{
	struct iio_dev *iiodev = platform_get_drvdata(pdev);
	struct ep93xx_adc_priv *priv = iio_priv(iiodev);

	iio_device_unregister(iiodev);
	clk_disable(priv->clk);

	return 0;
}

