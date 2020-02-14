#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct stm32_dac {TYPE_6__* common; } ;
struct TYPE_11__ {struct device_node* of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct TYPE_13__ {struct device_node* of_node; TYPE_3__* parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_7__ dev; int /*<<< orphan*/  name; TYPE_2__* channels; } ;
struct TYPE_9__ {int realbits; } ;
struct iio_chan_spec {int channel; TYPE_1__ scan_type; } ;
struct device_node {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_12__ {int vref_mv; int /*<<< orphan*/  regmap; scalar_t__ hfsel; } ;
struct TYPE_10__ {scalar_t__ channel; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_2__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ FIELD_GET (scalar_t__,scalar_t__) ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 unsigned int STM32_DAC_CR ; 
 scalar_t__ STM32_DAC_CR_EN1 ; 
 scalar_t__ STM32_DAC_CR_EN2 ; 
 unsigned int STM32_DAC_DHR12R1 ; 
 unsigned int STM32_DAC_DHR12R2 ; 
 unsigned int STM32_DAC_DOR1 ; 
 unsigned int STM32_DAC_DOR2 ; 
 scalar_t__ STM32_DAC_IS_CHAN_1 (int) ; 
 int /*<<< orphan*/  dev_err (TYPE_7__*,char*,...) ; 
 TYPE_6__* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (TYPE_3__*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_3__*,int) ; 
 int devm_iio_device_register (TYPE_3__*,struct iio_dev*) ; 
 struct stm32_dac* iio_priv (struct iio_dev*) ; 
 int of_property_read_u32 (struct device_node*,char*,scalar_t__*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int regmap_read (int /*<<< orphan*/ ,unsigned int,...) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,scalar_t__,scalar_t__) ; 
 int regmap_write (int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int sprintf (char*,char*,int) ; 
 TYPE_2__* stm32_dac_channels ; 
 int /*<<< orphan*/  stm32_dac_iio_info ; 
 int strtobool (char const*,int*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int stm32_dac_is_enabled(struct iio_dev *indio_dev, int channel)
{
	struct stm32_dac *dac = iio_priv(indio_dev);
	u32 en, val;
	int ret;

	ret = regmap_read(dac->common->regmap, STM32_DAC_CR, &val);
	if (ret < 0)
		return ret;
	if (STM32_DAC_IS_CHAN_1(channel))
		en = FIELD_GET(STM32_DAC_CR_EN1, val);
	else
		en = FIELD_GET(STM32_DAC_CR_EN2, val);

	return !!en;
}

__attribute__((used)) static int stm32_dac_set_enable_state(struct iio_dev *indio_dev, int ch,
				      bool enable)
{
	struct stm32_dac *dac = iio_priv(indio_dev);
	u32 msk = STM32_DAC_IS_CHAN_1(ch) ? STM32_DAC_CR_EN1 : STM32_DAC_CR_EN2;
	u32 en = enable ? msk : 0;
	int ret;

	ret = regmap_update_bits(dac->common->regmap, STM32_DAC_CR, msk, en);
	if (ret < 0) {
		dev_err(&indio_dev->dev, "%s failed\n", en ?
			"Enable" : "Disable");
		return ret;
	}

	/*
	 * When HFSEL is set, it is not allowed to write the DHRx register
	 * during 8 clock cycles after the ENx bit is set. It is not allowed
	 * to make software/hardware trigger during this period either.
	 */
	if (en && dac->common->hfsel)
		udelay(1);

	return 0;
}

__attribute__((used)) static int stm32_dac_get_value(struct stm32_dac *dac, int channel, int *val)
{
	int ret;

	if (STM32_DAC_IS_CHAN_1(channel))
		ret = regmap_read(dac->common->regmap, STM32_DAC_DOR1, val);
	else
		ret = regmap_read(dac->common->regmap, STM32_DAC_DOR2, val);

	return ret ? ret : IIO_VAL_INT;
}

__attribute__((used)) static int stm32_dac_set_value(struct stm32_dac *dac, int channel, int val)
{
	int ret;

	if (STM32_DAC_IS_CHAN_1(channel))
		ret = regmap_write(dac->common->regmap, STM32_DAC_DHR12R1, val);
	else
		ret = regmap_write(dac->common->regmap, STM32_DAC_DHR12R2, val);

	return ret;
}

__attribute__((used)) static int stm32_dac_read_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      int *val, int *val2, long mask)
{
	struct stm32_dac *dac = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return stm32_dac_get_value(dac, chan->channel, val);
	case IIO_CHAN_INFO_SCALE:
		*val = dac->common->vref_mv;
		*val2 = chan->scan_type.realbits;
		return IIO_VAL_FRACTIONAL_LOG2;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int stm32_dac_write_raw(struct iio_dev *indio_dev,
			       struct iio_chan_spec const *chan,
			       int val, int val2, long mask)
{
	struct stm32_dac *dac = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return stm32_dac_set_value(dac, chan->channel, val);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int stm32_dac_debugfs_reg_access(struct iio_dev *indio_dev,
					unsigned reg, unsigned writeval,
					unsigned *readval)
{
	struct stm32_dac *dac = iio_priv(indio_dev);

	if (!readval)
		return regmap_write(dac->common->regmap, reg, writeval);
	else
		return regmap_read(dac->common->regmap, reg, readval);
}

__attribute__((used)) static int stm32_dac_get_powerdown_mode(struct iio_dev *indio_dev,
					const struct iio_chan_spec *chan)
{
	return 0;
}

__attribute__((used)) static int stm32_dac_set_powerdown_mode(struct iio_dev *indio_dev,
					const struct iio_chan_spec *chan,
					unsigned int type)
{
	return 0;
}

__attribute__((used)) static ssize_t stm32_dac_read_powerdown(struct iio_dev *indio_dev,
					uintptr_t private,
					const struct iio_chan_spec *chan,
					char *buf)
{
	int ret = stm32_dac_is_enabled(indio_dev, chan->channel);

	if (ret < 0)
		return ret;

	return sprintf(buf, "%d\n", ret ? 0 : 1);
}

__attribute__((used)) static ssize_t stm32_dac_write_powerdown(struct iio_dev *indio_dev,
					 uintptr_t private,
					 const struct iio_chan_spec *chan,
					 const char *buf, size_t len)
{
	bool powerdown;
	int ret;

	ret = strtobool(buf, &powerdown);
	if (ret)
		return ret;

	ret = stm32_dac_set_enable_state(indio_dev, chan->channel, !powerdown);
	if (ret)
		return ret;

	return len;
}

__attribute__((used)) static int stm32_dac_chan_of_init(struct iio_dev *indio_dev)
{
	struct device_node *np = indio_dev->dev.of_node;
	unsigned int i;
	u32 channel;
	int ret;

	ret = of_property_read_u32(np, "reg", &channel);
	if (ret) {
		dev_err(&indio_dev->dev, "Failed to read reg property\n");
		return ret;
	}

	for (i = 0; i < ARRAY_SIZE(stm32_dac_channels); i++) {
		if (stm32_dac_channels[i].channel == channel)
			break;
	}
	if (i >= ARRAY_SIZE(stm32_dac_channels)) {
		dev_err(&indio_dev->dev, "Invalid reg property\n");
		return -EINVAL;
	}

	indio_dev->channels = &stm32_dac_channels[i];
	/*
	 * Expose only one channel here, as they can be used independently,
	 * with separate trigger. Then separate IIO devices are instantiated
	 * to manage this.
	 */
	indio_dev->num_channels = 1;

	return 0;
}

__attribute__((used)) static int stm32_dac_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct iio_dev *indio_dev;
	struct stm32_dac *dac;
	int ret;

	if (!np)
		return -ENODEV;

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*dac));
	if (!indio_dev)
		return -ENOMEM;
	platform_set_drvdata(pdev, indio_dev);

	dac = iio_priv(indio_dev);
	dac->common = dev_get_drvdata(pdev->dev.parent);
	indio_dev->name = dev_name(&pdev->dev);
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->dev.of_node = pdev->dev.of_node;
	indio_dev->info = &stm32_dac_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = stm32_dac_chan_of_init(indio_dev);
	if (ret < 0)
		return ret;

	return devm_iio_device_register(&pdev->dev, indio_dev);
}

