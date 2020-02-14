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
typedef  int u8 ;
struct regmap {int dummy; } ;
struct TYPE_4__ {struct TYPE_4__* parent; } ;
struct platform_device {TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct iio_dev {int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {unsigned long address; } ;
struct axp288_adc_info {int ts_enabled; scalar_t__ irq; struct regmap* regmap; } ;
struct axp20x_dev {struct regmap* regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AXP20X_ADC_EN1 ; 
 unsigned int AXP288_ADC_EN_MASK ; 
 unsigned int AXP288_ADC_TS_CURRENT_OFF ; 
 unsigned int AXP288_ADC_TS_CURRENT_ON ; 
 unsigned int AXP288_ADC_TS_CURRENT_ON_OFF_MASK ; 
 unsigned int AXP288_ADC_TS_CURRENT_ON_ONDEMAND ; 
 int AXP288_ADC_TS_ENABLE ; 
 int /*<<< orphan*/  AXP288_ADC_TS_PIN_CTRL ; 
 unsigned long AXP288_GP_ADC_H ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 128 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  axp288_adc_channels ; 
 int /*<<< orphan*/  axp288_adc_default_maps ; 
 int /*<<< orphan*/  axp288_adc_iio_info ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 struct axp20x_dev* dev_get_drvdata (TYPE_1__*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_1__*,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int iio_map_array_register (struct iio_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_map_array_unregister (struct iio_dev*) ; 
 struct axp288_adc_info* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 scalar_t__ regmap_bulk_read (struct regmap*,unsigned long,int*,int) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int axp288_adc_read_channel(int *val, unsigned long address,
				struct regmap *regmap)
{
	u8 buf[2];

	if (regmap_bulk_read(regmap, address, buf, 2))
		return -EIO;
	*val = (buf[0] << 4) + ((buf[1] >> 4) & 0x0F);

	return IIO_VAL_INT;
}

__attribute__((used)) static int axp288_adc_set_ts(struct axp288_adc_info *info,
			     unsigned int mode, unsigned long address)
{
	int ret;

	/* No need to switch the current-source if the TS pin is disabled */
	if (!info->ts_enabled)
		return 0;

	/* Channels other than GPADC do not need the current source */
	if (address != AXP288_GP_ADC_H)
		return 0;

	ret = regmap_update_bits(info->regmap, AXP288_ADC_TS_PIN_CTRL,
				 AXP288_ADC_TS_CURRENT_ON_OFF_MASK, mode);
	if (ret)
		return ret;

	/* When switching to the GPADC pin give things some time to settle */
	if (mode == AXP288_ADC_TS_CURRENT_ON_ONDEMAND)
		usleep_range(6000, 10000);

	return 0;
}

__attribute__((used)) static int axp288_adc_read_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan,
			int *val, int *val2, long mask)
{
	int ret;
	struct axp288_adc_info *info = iio_priv(indio_dev);

	mutex_lock(&indio_dev->mlock);
	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (axp288_adc_set_ts(info, AXP288_ADC_TS_CURRENT_ON_ONDEMAND,
					chan->address)) {
			dev_err(&indio_dev->dev, "GPADC mode\n");
			ret = -EINVAL;
			break;
		}
		ret = axp288_adc_read_channel(val, chan->address, info->regmap);
		if (axp288_adc_set_ts(info, AXP288_ADC_TS_CURRENT_ON,
						chan->address))
			dev_err(&indio_dev->dev, "TS pin restore\n");
		break;
	default:
		ret = -EINVAL;
	}
	mutex_unlock(&indio_dev->mlock);

	return ret;
}

__attribute__((used)) static int axp288_adc_initialize(struct axp288_adc_info *info)
{
	int ret, adc_enable_val;

	/*
	 * Determine if the TS pin is enabled and set the TS current-source
	 * accordingly.
	 */
	ret = regmap_read(info->regmap, AXP20X_ADC_EN1, &adc_enable_val);
	if (ret)
		return ret;

	if (adc_enable_val & AXP288_ADC_TS_ENABLE) {
		info->ts_enabled = true;
		ret = regmap_update_bits(info->regmap, AXP288_ADC_TS_PIN_CTRL,
					 AXP288_ADC_TS_CURRENT_ON_OFF_MASK,
					 AXP288_ADC_TS_CURRENT_ON);
	} else {
		info->ts_enabled = false;
		ret = regmap_update_bits(info->regmap, AXP288_ADC_TS_PIN_CTRL,
					 AXP288_ADC_TS_CURRENT_ON_OFF_MASK,
					 AXP288_ADC_TS_CURRENT_OFF);
	}
	if (ret)
		return ret;

	/* Turn on the ADC for all channels except TS, leave TS as is */
	return regmap_update_bits(info->regmap, AXP20X_ADC_EN1,
				  AXP288_ADC_EN_MASK, AXP288_ADC_EN_MASK);
}

__attribute__((used)) static int axp288_adc_probe(struct platform_device *pdev)
{
	int ret;
	struct axp288_adc_info *info;
	struct iio_dev *indio_dev;
	struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
	if (!indio_dev)
		return -ENOMEM;

	info = iio_priv(indio_dev);
	info->irq = platform_get_irq(pdev, 0);
	if (info->irq < 0) {
		dev_err(&pdev->dev, "no irq resource?\n");
		return info->irq;
	}
	platform_set_drvdata(pdev, indio_dev);
	info->regmap = axp20x->regmap;
	/*
	 * Set ADC to enabled state at all time, including system suspend.
	 * otherwise internal fuel gauge functionality may be affected.
	 */
	ret = axp288_adc_initialize(info);
	if (ret) {
		dev_err(&pdev->dev, "unable to enable ADC device\n");
		return ret;
	}

	indio_dev->dev.parent = &pdev->dev;
	indio_dev->name = pdev->name;
	indio_dev->channels = axp288_adc_channels;
	indio_dev->num_channels = ARRAY_SIZE(axp288_adc_channels);
	indio_dev->info = &axp288_adc_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	ret = iio_map_array_register(indio_dev, axp288_adc_default_maps);
	if (ret < 0)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&pdev->dev, "unable to register iio device\n");
		goto err_array_unregister;
	}
	return 0;

err_array_unregister:
	iio_map_array_unregister(indio_dev);

	return ret;
}

__attribute__((used)) static int axp288_adc_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);

	iio_device_unregister(indio_dev);
	iio_map_array_unregister(indio_dev);

	return 0;
}

