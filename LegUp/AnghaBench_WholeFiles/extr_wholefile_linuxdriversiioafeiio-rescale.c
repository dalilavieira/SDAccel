#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct iio_chan_spec {int indexed; int info_mask_separate; int info_mask_separate_available; struct iio_chan_spec_ext_info* ext_info; int /*<<< orphan*/  type; int /*<<< orphan*/  output; } ;
struct rescale {int numerator; int denominator; struct iio_chan_spec_ext_info* ext_info; struct iio_chan_spec chan; struct iio_channel* source; TYPE_2__* cfg; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct TYPE_3__ {struct device* parent; } ;
struct iio_dev {int num_channels; struct iio_chan_spec* channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct iio_channel {struct iio_chan_spec* channel; } ;
struct iio_chan_spec_ext_info {int private; int /*<<< orphan*/  (* write ) (struct iio_dev*,uintptr_t,struct iio_chan_spec const*,char const*,size_t) ;int /*<<< orphan*/  (* read ) (struct iio_dev*,uintptr_t,struct iio_chan_spec const*,char*) ;scalar_t__ name; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_4__ {int (* props ) (struct device*,struct rescale*) ;int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int BIT (int const) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IIO_CHAN_INFO_RAW 132 
#define  IIO_CHAN_INFO_SCALE 131 
#define  IIO_VAL_FRACTIONAL 130 
#define  IIO_VAL_FRACTIONAL_LOG2 129 
#define  IIO_VAL_INT 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (struct iio_channel*) ; 
 int PTR_ERR (struct iio_channel*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int device_property_read_u32 (struct device*,char*,int*) ; 
 struct iio_channel* devm_iio_channel_get (struct device*,int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 struct iio_chan_spec_ext_info* devm_kmemdup (struct device*,struct iio_chan_spec_ext_info*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_div (unsigned long long,long long) ; 
 int gcd (int,int) ; 
 scalar_t__ iio_channel_has_available (struct iio_chan_spec const*,int const) ; 
 int /*<<< orphan*/  iio_channel_has_info (struct iio_chan_spec const*,int const) ; 
 int iio_get_channel_ext_info_count (struct iio_channel*) ; 
 struct rescale* iio_priv (struct iio_dev*) ; 
 int iio_read_avail_channel_raw (struct iio_channel*,int const**,int*) ; 
 int /*<<< orphan*/  iio_read_channel_ext_info (struct iio_channel*,scalar_t__,char*) ; 
 int iio_read_channel_raw (struct iio_channel*,int*) ; 
 int iio_read_channel_scale (struct iio_channel*,int*,int*) ; 
 int /*<<< orphan*/  iio_write_channel_ext_info (struct iio_channel*,scalar_t__,char const*,size_t) ; 
 TYPE_2__* of_device_get_match_data (struct device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 int /*<<< orphan*/  rescale_info ; 
 int stub1 (struct device*,struct rescale*) ; 

__attribute__((used)) static int rescale_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct rescale *rescale = iio_priv(indio_dev);
	unsigned long long tmp;
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		return iio_read_channel_raw(rescale->source, val);

	case IIO_CHAN_INFO_SCALE:
		ret = iio_read_channel_scale(rescale->source, val, val2);
		switch (ret) {
		case IIO_VAL_FRACTIONAL:
			*val *= rescale->numerator;
			*val2 *= rescale->denominator;
			return ret;
		case IIO_VAL_INT:
			*val *= rescale->numerator;
			if (rescale->denominator == 1)
				return ret;
			*val2 = rescale->denominator;
			return IIO_VAL_FRACTIONAL;
		case IIO_VAL_FRACTIONAL_LOG2:
			tmp = *val * 1000000000LL;
			do_div(tmp, rescale->denominator);
			tmp *= rescale->numerator;
			do_div(tmp, 1000000000LL);
			*val = tmp;
			return ret;
		default:
			return -EOPNOTSUPP;
		}
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int rescale_read_avail(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      const int **vals, int *type, int *length,
			      long mask)
{
	struct rescale *rescale = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		*type = IIO_VAL_INT;
		return iio_read_avail_channel_raw(rescale->source,
						  vals, length);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static ssize_t rescale_read_ext_info(struct iio_dev *indio_dev,
				     uintptr_t private,
				     struct iio_chan_spec const *chan,
				     char *buf)
{
	struct rescale *rescale = iio_priv(indio_dev);

	return iio_read_channel_ext_info(rescale->source,
					 rescale->ext_info[private].name,
					 buf);
}

__attribute__((used)) static ssize_t rescale_write_ext_info(struct iio_dev *indio_dev,
				      uintptr_t private,
				      struct iio_chan_spec const *chan,
				      const char *buf, size_t len)
{
	struct rescale *rescale = iio_priv(indio_dev);

	return iio_write_channel_ext_info(rescale->source,
					  rescale->ext_info[private].name,
					  buf, len);
}

__attribute__((used)) static int rescale_configure_channel(struct device *dev,
				     struct rescale *rescale)
{
	struct iio_chan_spec *chan = &rescale->chan;
	struct iio_chan_spec const *schan = rescale->source->channel;

	chan->indexed = 1;
	chan->output = schan->output;
	chan->ext_info = rescale->ext_info;
	chan->type = rescale->cfg->type;

	if (!iio_channel_has_info(schan, IIO_CHAN_INFO_RAW) ||
	    !iio_channel_has_info(schan, IIO_CHAN_INFO_SCALE)) {
		dev_err(dev, "source channel does not support raw/scale\n");
		return -EINVAL;
	}

	chan->info_mask_separate = BIT(IIO_CHAN_INFO_RAW) |
		BIT(IIO_CHAN_INFO_SCALE);

	if (iio_channel_has_available(schan, IIO_CHAN_INFO_RAW))
		chan->info_mask_separate_available |= BIT(IIO_CHAN_INFO_RAW);

	return 0;
}

__attribute__((used)) static int rescale_current_sense_amplifier_props(struct device *dev,
						 struct rescale *rescale)
{
	u32 sense;
	u32 gain_mult = 1;
	u32 gain_div = 1;
	u32 factor;
	int ret;

	ret = device_property_read_u32(dev, "sense-resistor-micro-ohms",
				       &sense);
	if (ret) {
		dev_err(dev, "failed to read the sense resistance: %d\n", ret);
		return ret;
	}

	device_property_read_u32(dev, "sense-gain-mult", &gain_mult);
	device_property_read_u32(dev, "sense-gain-div", &gain_div);

	/*
	 * Calculate the scaling factor, 1 / (gain * sense), or
	 * gain_div / (gain_mult * sense), while trying to keep the
	 * numerator/denominator from overflowing.
	 */
	factor = gcd(sense, 1000000);
	rescale->numerator = 1000000 / factor;
	rescale->denominator = sense / factor;

	factor = gcd(rescale->numerator, gain_mult);
	rescale->numerator /= factor;
	rescale->denominator *= gain_mult / factor;

	factor = gcd(rescale->denominator, gain_div);
	rescale->numerator *= gain_div / factor;
	rescale->denominator /= factor;

	return 0;
}

__attribute__((used)) static int rescale_current_sense_shunt_props(struct device *dev,
					     struct rescale *rescale)
{
	u32 shunt;
	u32 factor;
	int ret;

	ret = device_property_read_u32(dev, "shunt-resistor-micro-ohms",
				       &shunt);
	if (ret) {
		dev_err(dev, "failed to read the shunt resistance: %d\n", ret);
		return ret;
	}

	factor = gcd(shunt, 1000000);
	rescale->numerator = 1000000 / factor;
	rescale->denominator = shunt / factor;

	return 0;
}

__attribute__((used)) static int rescale_voltage_divider_props(struct device *dev,
					 struct rescale *rescale)
{
	int ret;
	u32 factor;

	ret = device_property_read_u32(dev, "output-ohms",
				       &rescale->denominator);
	if (ret) {
		dev_err(dev, "failed to read output-ohms: %d\n", ret);
		return ret;
	}

	ret = device_property_read_u32(dev, "full-ohms",
				       &rescale->numerator);
	if (ret) {
		dev_err(dev, "failed to read full-ohms: %d\n", ret);
		return ret;
	}

	factor = gcd(rescale->numerator, rescale->denominator);
	rescale->numerator /= factor;
	rescale->denominator /= factor;

	return 0;
}

__attribute__((used)) static int rescale_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct iio_dev *indio_dev;
	struct iio_channel *source;
	struct rescale *rescale;
	int sizeof_ext_info;
	int sizeof_priv;
	int i;
	int ret;

	source = devm_iio_channel_get(dev, NULL);
	if (IS_ERR(source)) {
		if (PTR_ERR(source) != -EPROBE_DEFER)
			dev_err(dev, "failed to get source channel\n");
		return PTR_ERR(source);
	}

	sizeof_ext_info = iio_get_channel_ext_info_count(source);
	if (sizeof_ext_info) {
		sizeof_ext_info += 1; /* one extra entry for the sentinel */
		sizeof_ext_info *= sizeof(*rescale->ext_info);
	}

	sizeof_priv = sizeof(*rescale) + sizeof_ext_info;

	indio_dev = devm_iio_device_alloc(dev, sizeof_priv);
	if (!indio_dev)
		return -ENOMEM;

	rescale = iio_priv(indio_dev);

	rescale->cfg = of_device_get_match_data(dev);
	rescale->numerator = 1;
	rescale->denominator = 1;

	ret = rescale->cfg->props(dev, rescale);
	if (ret)
		return ret;

	if (!rescale->numerator || !rescale->denominator) {
		dev_err(dev, "invalid scaling factor.\n");
		return -EINVAL;
	}

	platform_set_drvdata(pdev, indio_dev);

	rescale->source = source;

	indio_dev->name = dev_name(dev);
	indio_dev->dev.parent = dev;
	indio_dev->info = &rescale_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = &rescale->chan;
	indio_dev->num_channels = 1;
	if (sizeof_ext_info) {
		rescale->ext_info = devm_kmemdup(dev,
						 source->channel->ext_info,
						 sizeof_ext_info, GFP_KERNEL);
		if (!rescale->ext_info)
			return -ENOMEM;

		for (i = 0; rescale->ext_info[i].name; ++i) {
			struct iio_chan_spec_ext_info *ext_info =
				&rescale->ext_info[i];

			if (source->channel->ext_info[i].read)
				ext_info->read = rescale_read_ext_info;
			if (source->channel->ext_info[i].write)
				ext_info->write = rescale_write_ext_info;
			ext_info->private = i;
		}
	}

	ret = rescale_configure_channel(dev, rescale);
	if (ret)
		return ret;

	return devm_iio_device_register(dev, indio_dev);
}

