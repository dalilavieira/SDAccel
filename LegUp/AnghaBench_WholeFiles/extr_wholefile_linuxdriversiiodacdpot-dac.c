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
struct device {struct device* parent; } ;
struct platform_device {struct device dev; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/ * channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; struct device dev; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {int dummy; } ;
struct dpot_dac {long long max_ohms; int /*<<< orphan*/  vref; int /*<<< orphan*/  dpot; } ;
typedef  enum iio_chan_type { ____Placeholder_iio_chan_type } iio_chan_type ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
#define  IIO_CHAN_INFO_RAW 132 
#define  IIO_CHAN_INFO_SCALE 131 
 int IIO_RESISTANCE ; 
#define  IIO_VAL_FRACTIONAL 130 
#define  IIO_VAL_FRACTIONAL_LOG2 129 
#define  IIO_VAL_INT 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  devm_iio_channel_get (struct device*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int /*<<< orphan*/  devm_regulator_get (struct device*,char*) ; 
 int /*<<< orphan*/  do_div (unsigned long long,long long) ; 
 int /*<<< orphan*/  dpot_dac_iio_channel ; 
 int /*<<< orphan*/  dpot_dac_info ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int iio_get_channel_type (int /*<<< orphan*/ ,int*) ; 
 struct dpot_dac* iio_priv (struct iio_dev*) ; 
 int iio_read_avail_channel_raw (int /*<<< orphan*/ ,int const**,int*) ; 
 int iio_read_channel_raw (int /*<<< orphan*/ ,int*) ; 
 int iio_read_channel_scale (int /*<<< orphan*/ ,int*,int*) ; 
 int iio_read_max_channel_raw (int /*<<< orphan*/ ,int*) ; 
 int iio_write_channel_raw (int /*<<< orphan*/ ,int) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dpot_dac_read_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int *val, int *val2, long mask)
{
	struct dpot_dac *dac = iio_priv(indio_dev);
	int ret;
	unsigned long long tmp;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return iio_read_channel_raw(dac->dpot, val);

	case IIO_CHAN_INFO_SCALE:
		ret = iio_read_channel_scale(dac->dpot, val, val2);
		switch (ret) {
		case IIO_VAL_FRACTIONAL_LOG2:
			tmp = *val * 1000000000LL;
			do_div(tmp, dac->max_ohms);
			tmp *= regulator_get_voltage(dac->vref) / 1000;
			do_div(tmp, 1000000000LL);
			*val = tmp;
			return ret;
		case IIO_VAL_INT:
			/*
			 * Convert integer scale to fractional scale by
			 * setting the denominator (val2) to one...
			 */
			*val2 = 1;
			ret = IIO_VAL_FRACTIONAL;
			/* ...and fall through. */
		case IIO_VAL_FRACTIONAL:
			*val *= regulator_get_voltage(dac->vref) / 1000;
			*val2 *= dac->max_ohms;
			break;
		}

		return ret;
	}

	return -EINVAL;
}

__attribute__((used)) static int dpot_dac_read_avail(struct iio_dev *indio_dev,
			       struct iio_chan_spec const *chan,
			       const int **vals, int *type, int *length,
			       long mask)
{
	struct dpot_dac *dac = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		*type = IIO_VAL_INT;
		return iio_read_avail_channel_raw(dac->dpot, vals, length);
	}

	return -EINVAL;
}

__attribute__((used)) static int dpot_dac_write_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      int val, int val2, long mask)
{
	struct dpot_dac *dac = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return iio_write_channel_raw(dac->dpot, val);
	}

	return -EINVAL;
}

__attribute__((used)) static int dpot_dac_channel_max_ohms(struct iio_dev *indio_dev)
{
	struct device *dev = &indio_dev->dev;
	struct dpot_dac *dac = iio_priv(indio_dev);
	unsigned long long tmp;
	int ret;
	int val;
	int val2;
	int max;

	ret = iio_read_max_channel_raw(dac->dpot, &max);
	if (ret < 0) {
		dev_err(dev, "dpot does not indicate its raw maximum value\n");
		return ret;
	}

	switch (iio_read_channel_scale(dac->dpot, &val, &val2)) {
	case IIO_VAL_INT:
		return max * val;
	case IIO_VAL_FRACTIONAL:
		tmp = (unsigned long long)max * val;
		do_div(tmp, val2);
		return tmp;
	case IIO_VAL_FRACTIONAL_LOG2:
		tmp = val * 1000000000LL * max >> val2;
		do_div(tmp, 1000000000LL);
		return tmp;
	default:
		dev_err(dev, "dpot has a scale that is too weird\n");
	}

	return -EINVAL;
}

__attribute__((used)) static int dpot_dac_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct iio_dev *indio_dev;
	struct dpot_dac *dac;
	enum iio_chan_type type;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*dac));
	if (!indio_dev)
		return -ENOMEM;

	platform_set_drvdata(pdev, indio_dev);
	dac = iio_priv(indio_dev);

	indio_dev->name = dev_name(dev);
	indio_dev->dev.parent = dev;
	indio_dev->info = &dpot_dac_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = &dpot_dac_iio_channel;
	indio_dev->num_channels = 1;

	dac->vref = devm_regulator_get(dev, "vref");
	if (IS_ERR(dac->vref)) {
		if (PTR_ERR(dac->vref) != -EPROBE_DEFER)
			dev_err(&pdev->dev, "failed to get vref regulator\n");
		return PTR_ERR(dac->vref);
	}

	dac->dpot = devm_iio_channel_get(dev, "dpot");
	if (IS_ERR(dac->dpot)) {
		if (PTR_ERR(dac->dpot) != -EPROBE_DEFER)
			dev_err(dev, "failed to get dpot input channel\n");
		return PTR_ERR(dac->dpot);
	}

	ret = iio_get_channel_type(dac->dpot, &type);
	if (ret < 0)
		return ret;

	if (type != IIO_RESISTANCE) {
		dev_err(dev, "dpot is of the wrong type\n");
		return -EINVAL;
	}

	ret = dpot_dac_channel_max_ohms(indio_dev);
	if (ret < 0)
		return ret;
	dac->max_ohms = ret;

	ret = regulator_enable(dac->vref);
	if (ret) {
		dev_err(dev, "failed to enable the vref regulator\n");
		return ret;
	}

	ret = iio_device_register(indio_dev);
	if (ret) {
		dev_err(dev, "failed to register iio device\n");
		goto disable_reg;
	}

	return 0;

disable_reg:
	regulator_disable(dac->vref);
	return ret;
}

__attribute__((used)) static int dpot_dac_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);
	struct dpot_dac *dac = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	regulator_disable(dac->vref);

	return 0;
}

