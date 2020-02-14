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
struct platform_device_id {int /*<<< orphan*/  name; scalar_t__ driver_data; } ;
struct device {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {struct device dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  of_node; struct device* parent; } ;
struct iio_dev {int /*<<< orphan*/  channels; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  info; int /*<<< orphan*/  name; int /*<<< orphan*/  modes; TYPE_1__ dev; } ;
struct iio_chan_spec {scalar_t__ type; scalar_t__ channel; int /*<<< orphan*/  address; } ;
struct axp_data {scalar_t__ adc_en2; int /*<<< orphan*/  maps; int /*<<< orphan*/  (* adc_rate ) (struct axp20x_adc_iio*,int) ;int /*<<< orphan*/  adc_en1_mask; int /*<<< orphan*/  channels; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  iio_info; } ;
struct axp20x_dev {int /*<<< orphan*/  regmap; } ;
struct axp20x_adc_iio {int /*<<< orphan*/  regmap; struct axp_data* data; } ;

/* Variables and functions */
#define  AXP20X_ACIN_I 145 
#define  AXP20X_ACIN_V 144 
 int /*<<< orphan*/  AXP20X_ADC_EN1 ; 
 int /*<<< orphan*/  AXP20X_ADC_EN2 ; 
 unsigned int AXP20X_ADC_EN2_MASK ; 
 int /*<<< orphan*/  AXP20X_ADC_RATE ; 
 unsigned int AXP20X_ADC_RATE_HZ (int) ; 
 unsigned int AXP20X_ADC_RATE_MASK ; 
#define  AXP20X_BATT_CHRG_I 143 
#define  AXP20X_BATT_DISCHRG_I 142 
#define  AXP20X_BATT_V 141 
#define  AXP20X_GPIO0_V 140 
 int /*<<< orphan*/  AXP20X_GPIO10_IN_RANGE ; 
 int AXP20X_GPIO10_IN_RANGE_GPIO0 ; 
 unsigned int AXP20X_GPIO10_IN_RANGE_GPIO0_VAL (int) ; 
 int AXP20X_GPIO10_IN_RANGE_GPIO1 ; 
 unsigned int AXP20X_GPIO10_IN_RANGE_GPIO1_VAL (int) ; 
#define  AXP20X_GPIO1_V 139 
#define  AXP20X_IPSOUT_V 138 
#define  AXP20X_VBUS_I 137 
#define  AXP20X_VBUS_V 136 
 unsigned int AXP22X_ADC_RATE_HZ (int) ; 
 scalar_t__ AXP22X_BATT_DISCHRG_I ; 
 int AXP22X_BATT_V ; 
 int /*<<< orphan*/  AXP813_ADC_RATE ; 
 unsigned int AXP813_ADC_RATE_HZ (int) ; 
 unsigned int AXP813_ADC_RATE_MASK ; 
#define  AXP813_BATT_V 135 
#define  AXP813_GPIO0_V 134 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_OFFSET 133 
#define  IIO_CHAN_INFO_RAW 132 
#define  IIO_CHAN_INFO_SCALE 131 
#define  IIO_CURRENT 130 
#define  IIO_TEMP 129 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
#define  IIO_VOLTAGE 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int axp20x_read_variable_width (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct axp20x_dev* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int iio_map_array_register (struct iio_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_map_array_unregister (struct iio_dev*) ; 
 struct axp20x_adc_iio* iio_priv (struct iio_dev*) ; 
 scalar_t__ of_device_get_match_data (struct device*) ; 
 struct platform_device_id* platform_get_device_id (struct platform_device*) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct axp20x_adc_iio*,int) ; 

__attribute__((used)) static int axp20x_adc_raw(struct iio_dev *indio_dev,
			  struct iio_chan_spec const *chan, int *val)
{
	struct axp20x_adc_iio *info = iio_priv(indio_dev);
	int size = 12;

	/*
	 * N.B.:  Unlike the Chinese datasheets tell, the charging current is
	 * stored on 12 bits, not 13 bits. Only discharging current is on 13
	 * bits.
	 */
	if (chan->type == IIO_CURRENT && chan->channel == AXP20X_BATT_DISCHRG_I)
		size = 13;
	else
		size = 12;

	*val = axp20x_read_variable_width(info->regmap, chan->address, size);
	if (*val < 0)
		return *val;

	return IIO_VAL_INT;
}

__attribute__((used)) static int axp22x_adc_raw(struct iio_dev *indio_dev,
			  struct iio_chan_spec const *chan, int *val)
{
	struct axp20x_adc_iio *info = iio_priv(indio_dev);
	int size;

	/*
	 * N.B.: Unlike the Chinese datasheets tell, the charging current is
	 * stored on 12 bits, not 13 bits. Only discharging current is on 13
	 * bits.
	 */
	if (chan->type == IIO_CURRENT && chan->channel == AXP22X_BATT_DISCHRG_I)
		size = 13;
	else
		size = 12;

	*val = axp20x_read_variable_width(info->regmap, chan->address, size);
	if (*val < 0)
		return *val;

	return IIO_VAL_INT;
}

__attribute__((used)) static int axp813_adc_raw(struct iio_dev *indio_dev,
			  struct iio_chan_spec const *chan, int *val)
{
	struct axp20x_adc_iio *info = iio_priv(indio_dev);

	*val = axp20x_read_variable_width(info->regmap, chan->address, 12);
	if (*val < 0)
		return *val;

	return IIO_VAL_INT;
}

__attribute__((used)) static int axp20x_adc_scale_voltage(int channel, int *val, int *val2)
{
	switch (channel) {
	case AXP20X_ACIN_V:
	case AXP20X_VBUS_V:
		*val = 1;
		*val2 = 700000;
		return IIO_VAL_INT_PLUS_MICRO;

	case AXP20X_GPIO0_V:
	case AXP20X_GPIO1_V:
		*val = 0;
		*val2 = 500000;
		return IIO_VAL_INT_PLUS_MICRO;

	case AXP20X_BATT_V:
		*val = 1;
		*val2 = 100000;
		return IIO_VAL_INT_PLUS_MICRO;

	case AXP20X_IPSOUT_V:
		*val = 1;
		*val2 = 400000;
		return IIO_VAL_INT_PLUS_MICRO;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp813_adc_scale_voltage(int channel, int *val, int *val2)
{
	switch (channel) {
	case AXP813_GPIO0_V:
		*val = 0;
		*val2 = 800000;
		return IIO_VAL_INT_PLUS_MICRO;

	case AXP813_BATT_V:
		*val = 1;
		*val2 = 100000;
		return IIO_VAL_INT_PLUS_MICRO;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp20x_adc_scale_current(int channel, int *val, int *val2)
{
	switch (channel) {
	case AXP20X_ACIN_I:
		*val = 0;
		*val2 = 625000;
		return IIO_VAL_INT_PLUS_MICRO;

	case AXP20X_VBUS_I:
		*val = 0;
		*val2 = 375000;
		return IIO_VAL_INT_PLUS_MICRO;

	case AXP20X_BATT_DISCHRG_I:
	case AXP20X_BATT_CHRG_I:
		*val = 0;
		*val2 = 500000;
		return IIO_VAL_INT_PLUS_MICRO;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp20x_adc_scale(struct iio_chan_spec const *chan, int *val,
			    int *val2)
{
	switch (chan->type) {
	case IIO_VOLTAGE:
		return axp20x_adc_scale_voltage(chan->channel, val, val2);

	case IIO_CURRENT:
		return axp20x_adc_scale_current(chan->channel, val, val2);

	case IIO_TEMP:
		*val = 100;
		return IIO_VAL_INT;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp22x_adc_scale(struct iio_chan_spec const *chan, int *val,
			    int *val2)
{
	switch (chan->type) {
	case IIO_VOLTAGE:
		if (chan->channel != AXP22X_BATT_V)
			return -EINVAL;

		*val = 1;
		*val2 = 100000;
		return IIO_VAL_INT_PLUS_MICRO;

	case IIO_CURRENT:
		*val = 0;
		*val2 = 500000;
		return IIO_VAL_INT_PLUS_MICRO;

	case IIO_TEMP:
		*val = 100;
		return IIO_VAL_INT;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp813_adc_scale(struct iio_chan_spec const *chan, int *val,
			    int *val2)
{
	switch (chan->type) {
	case IIO_VOLTAGE:
		return axp813_adc_scale_voltage(chan->channel, val, val2);

	case IIO_CURRENT:
		*val = 1;
		return IIO_VAL_INT;

	case IIO_TEMP:
		*val = 100;
		return IIO_VAL_INT;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp20x_adc_offset_voltage(struct iio_dev *indio_dev, int channel,
				     int *val)
{
	struct axp20x_adc_iio *info = iio_priv(indio_dev);
	int ret;

	ret = regmap_read(info->regmap, AXP20X_GPIO10_IN_RANGE, val);
	if (ret < 0)
		return ret;

	switch (channel) {
	case AXP20X_GPIO0_V:
		*val &= AXP20X_GPIO10_IN_RANGE_GPIO0;
		break;

	case AXP20X_GPIO1_V:
		*val &= AXP20X_GPIO10_IN_RANGE_GPIO1;
		break;

	default:
		return -EINVAL;
	}

	*val = *val ? 700000 : 0;

	return IIO_VAL_INT;
}

__attribute__((used)) static int axp20x_adc_offset(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan, int *val)
{
	switch (chan->type) {
	case IIO_VOLTAGE:
		return axp20x_adc_offset_voltage(indio_dev, chan->channel, val);

	case IIO_TEMP:
		*val = -1447;
		return IIO_VAL_INT;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp20x_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan, int *val,
			   int *val2, long mask)
{
	switch (mask) {
	case IIO_CHAN_INFO_OFFSET:
		return axp20x_adc_offset(indio_dev, chan, val);

	case IIO_CHAN_INFO_SCALE:
		return axp20x_adc_scale(chan, val, val2);

	case IIO_CHAN_INFO_RAW:
		return axp20x_adc_raw(indio_dev, chan, val);

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp22x_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan, int *val,
			   int *val2, long mask)
{
	switch (mask) {
	case IIO_CHAN_INFO_OFFSET:
		*val = -2677;
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		return axp22x_adc_scale(chan, val, val2);

	case IIO_CHAN_INFO_RAW:
		return axp22x_adc_raw(indio_dev, chan, val);

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp813_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan, int *val,
			   int *val2, long mask)
{
	switch (mask) {
	case IIO_CHAN_INFO_OFFSET:
		*val = -2667;
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		return axp813_adc_scale(chan, val, val2);

	case IIO_CHAN_INFO_RAW:
		return axp813_adc_raw(indio_dev, chan, val);

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int axp20x_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan, int val, int val2,
			    long mask)
{
	struct axp20x_adc_iio *info = iio_priv(indio_dev);
	unsigned int reg, regval;

	/*
	 * The AXP20X PMIC allows the user to choose between 0V and 0.7V offsets
	 * for (independently) GPIO0 and GPIO1 when in ADC mode.
	 */
	if (mask != IIO_CHAN_INFO_OFFSET)
		return -EINVAL;

	if (val != 0 && val != 700000)
		return -EINVAL;

	val = val ? 1 : 0;

	switch (chan->channel) {
	case AXP20X_GPIO0_V:
		reg = AXP20X_GPIO10_IN_RANGE_GPIO0;
		regval = AXP20X_GPIO10_IN_RANGE_GPIO0_VAL(val);
		break;

	case AXP20X_GPIO1_V:
		reg = AXP20X_GPIO10_IN_RANGE_GPIO1;
		regval = AXP20X_GPIO10_IN_RANGE_GPIO1_VAL(val);
		break;

	default:
		return -EINVAL;
	}

	return regmap_update_bits(info->regmap, AXP20X_GPIO10_IN_RANGE, reg,
				  regval);
}

__attribute__((used)) static int axp20x_adc_rate(struct axp20x_adc_iio *info, int rate)
{
	return regmap_update_bits(info->regmap, AXP20X_ADC_RATE,
				  AXP20X_ADC_RATE_MASK,
				  AXP20X_ADC_RATE_HZ(rate));
}

__attribute__((used)) static int axp22x_adc_rate(struct axp20x_adc_iio *info, int rate)
{
	return regmap_update_bits(info->regmap, AXP20X_ADC_RATE,
				  AXP20X_ADC_RATE_MASK,
				  AXP22X_ADC_RATE_HZ(rate));
}

__attribute__((used)) static int axp813_adc_rate(struct axp20x_adc_iio *info, int rate)
{
	return regmap_update_bits(info->regmap, AXP813_ADC_RATE,
				 AXP813_ADC_RATE_MASK,
				 AXP813_ADC_RATE_HZ(rate));
}

__attribute__((used)) static int axp20x_probe(struct platform_device *pdev)
{
	struct axp20x_adc_iio *info;
	struct iio_dev *indio_dev;
	struct axp20x_dev *axp20x_dev;
	int ret;

	axp20x_dev = dev_get_drvdata(pdev->dev.parent);

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
	if (!indio_dev)
		return -ENOMEM;

	info = iio_priv(indio_dev);
	platform_set_drvdata(pdev, indio_dev);

	info->regmap = axp20x_dev->regmap;
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->dev.of_node = pdev->dev.of_node;
	indio_dev->modes = INDIO_DIRECT_MODE;

	if (!pdev->dev.of_node) {
		const struct platform_device_id *id;

		id = platform_get_device_id(pdev);
		info->data = (struct axp_data *)id->driver_data;
	} else {
		struct device *dev = &pdev->dev;

		info->data = (struct axp_data *)of_device_get_match_data(dev);
	}

	indio_dev->name = platform_get_device_id(pdev)->name;
	indio_dev->info = info->data->iio_info;
	indio_dev->num_channels = info->data->num_channels;
	indio_dev->channels = info->data->channels;

	/* Enable the ADCs on IP */
	regmap_write(info->regmap, AXP20X_ADC_EN1, info->data->adc_en1_mask);

	if (info->data->adc_en2)
		/* Enable GPIO0/1 and internal temperature ADCs */
		regmap_update_bits(info->regmap, AXP20X_ADC_EN2,
				   AXP20X_ADC_EN2_MASK, AXP20X_ADC_EN2_MASK);

	/* Configure ADCs rate */
	info->data->adc_rate(info, 100);

	ret = iio_map_array_register(indio_dev, info->data->maps);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to register IIO maps: %d\n", ret);
		goto fail_map;
	}

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&pdev->dev, "could not register the device\n");
		goto fail_register;
	}

	return 0;

fail_register:
	iio_map_array_unregister(indio_dev);

fail_map:
	regmap_write(info->regmap, AXP20X_ADC_EN1, 0);

	if (info->data->adc_en2)
		regmap_write(info->regmap, AXP20X_ADC_EN2, 0);

	return ret;
}

__attribute__((used)) static int axp20x_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);
	struct axp20x_adc_iio *info = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	iio_map_array_unregister(indio_dev);

	regmap_write(info->regmap, AXP20X_ADC_EN1, 0);

	if (info->data->adc_en2)
		regmap_write(info->regmap, AXP20X_ADC_EN2, 0);

	return 0;
}

