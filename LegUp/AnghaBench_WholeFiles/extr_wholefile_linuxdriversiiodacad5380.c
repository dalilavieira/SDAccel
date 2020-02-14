#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct regmap {int dummy; } ;
struct TYPE_4__ {struct device* parent; } ;
struct iio_dev {char const* name; unsigned int num_channels; struct iio_chan_spec* channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  mlock; } ;
struct TYPE_5__ {int realbits; int shift; } ;
struct iio_chan_spec {unsigned int address; unsigned int channel; TYPE_2__ scan_type; } ;
struct device {int dummy; } ;
struct ad5380_state {int pwr_down; int vref; int /*<<< orphan*/  vref_reg; struct regmap* regmap; TYPE_3__* chip_info; } ;
typedef  int ssize_t ;
typedef  enum ad5380_type { ____Placeholder_ad5380_type } ad5380_type ;
struct TYPE_6__ {unsigned int num_channels; int int_vref; struct iio_chan_spec channel_template; } ;

/* Variables and functions */
 unsigned int AD5380_CTRL_INT_VREF_2V5 ; 
 unsigned int AD5380_CTRL_INT_VREF_EN ; 
 unsigned int AD5380_CTRL_PWR_DOWN_MODE_OFFSET ; 
 unsigned int AD5380_REG_DATA (unsigned int) ; 
 unsigned int AD5380_REG_GAIN (unsigned int) ; 
 unsigned int AD5380_REG_OFFSET (unsigned int) ; 
 unsigned int AD5380_REG_SF_CTRL ; 
 unsigned int AD5380_REG_SF_PWR_DOWN ; 
 unsigned int AD5380_REG_SF_PWR_UP ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IIO_CHAN_INFO_CALIBBIAS 131 
#define  IIO_CHAN_INFO_CALIBSCALE 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 TYPE_3__* ad5380_chip_info_tbl ; 
 int /*<<< orphan*/  ad5380_info ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct iio_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct iio_dev*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int /*<<< orphan*/  devm_regulator_get (struct device*,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ad5380_state* iio_priv (struct iio_dev*) ; 
 struct iio_chan_spec* kcalloc (unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct iio_chan_spec*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_read (struct regmap*,unsigned int,...) ; 
 int regmap_update_bits (struct regmap*,unsigned int,int,unsigned int) ; 
 int regmap_write (struct regmap*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 int sprintf (char*,char*,int) ; 
 int strtobool (char const*,int*) ; 

__attribute__((used)) static ssize_t ad5380_read_dac_powerdown(struct iio_dev *indio_dev,
	uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
	struct ad5380_state *st = iio_priv(indio_dev);

	return sprintf(buf, "%d\n", st->pwr_down);
}

__attribute__((used)) static ssize_t ad5380_write_dac_powerdown(struct iio_dev *indio_dev,
	 uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
	 size_t len)
{
	struct ad5380_state *st = iio_priv(indio_dev);
	bool pwr_down;
	int ret;

	ret = strtobool(buf, &pwr_down);
	if (ret)
		return ret;

	mutex_lock(&indio_dev->mlock);

	if (pwr_down)
		ret = regmap_write(st->regmap, AD5380_REG_SF_PWR_DOWN, 0);
	else
		ret = regmap_write(st->regmap, AD5380_REG_SF_PWR_UP, 0);

	st->pwr_down = pwr_down;

	mutex_unlock(&indio_dev->mlock);

	return ret ? ret : len;
}

__attribute__((used)) static int ad5380_get_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan)
{
	struct ad5380_state *st = iio_priv(indio_dev);
	unsigned int mode;
	int ret;

	ret = regmap_read(st->regmap, AD5380_REG_SF_CTRL, &mode);
	if (ret)
		return ret;

	mode = (mode >> AD5380_CTRL_PWR_DOWN_MODE_OFFSET) & 1;

	return mode;
}

__attribute__((used)) static int ad5380_set_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, unsigned int mode)
{
	struct ad5380_state *st = iio_priv(indio_dev);
	int ret;

	ret = regmap_update_bits(st->regmap, AD5380_REG_SF_CTRL,
		1 << AD5380_CTRL_PWR_DOWN_MODE_OFFSET,
		mode << AD5380_CTRL_PWR_DOWN_MODE_OFFSET);

	return ret;
}

__attribute__((used)) static unsigned int ad5380_info_to_reg(struct iio_chan_spec const *chan,
	long info)
{
	switch (info) {
	case IIO_CHAN_INFO_RAW:
		return AD5380_REG_DATA(chan->address);
	case IIO_CHAN_INFO_CALIBBIAS:
		return AD5380_REG_OFFSET(chan->address);
	case IIO_CHAN_INFO_CALIBSCALE:
		return AD5380_REG_GAIN(chan->address);
	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int ad5380_write_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int val, int val2, long info)
{
	const unsigned int max_val = (1 << chan->scan_type.realbits);
	struct ad5380_state *st = iio_priv(indio_dev);

	switch (info) {
	case IIO_CHAN_INFO_RAW:
	case IIO_CHAN_INFO_CALIBSCALE:
		if (val >= max_val || val < 0)
			return -EINVAL;

		return regmap_write(st->regmap,
			ad5380_info_to_reg(chan, info),
			val << chan->scan_type.shift);
	case IIO_CHAN_INFO_CALIBBIAS:
		val += (1 << chan->scan_type.realbits) / 2;
		if (val >= max_val || val < 0)
			return -EINVAL;

		return regmap_write(st->regmap,
			AD5380_REG_OFFSET(chan->address),
			val << chan->scan_type.shift);
	default:
		break;
	}
	return -EINVAL;
}

__attribute__((used)) static int ad5380_read_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
	struct ad5380_state *st = iio_priv(indio_dev);
	int ret;

	switch (info) {
	case IIO_CHAN_INFO_RAW:
	case IIO_CHAN_INFO_CALIBSCALE:
		ret = regmap_read(st->regmap, ad5380_info_to_reg(chan, info),
					val);
		if (ret)
			return ret;
		*val >>= chan->scan_type.shift;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_CALIBBIAS:
		ret = regmap_read(st->regmap, AD5380_REG_OFFSET(chan->address),
					val);
		if (ret)
			return ret;
		*val >>= chan->scan_type.shift;
		val -= (1 << chan->scan_type.realbits) / 2;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 2 * st->vref;
		*val2 = chan->scan_type.realbits;
		return IIO_VAL_FRACTIONAL_LOG2;
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int ad5380_alloc_channels(struct iio_dev *indio_dev)
{
	struct ad5380_state *st = iio_priv(indio_dev);
	struct iio_chan_spec *channels;
	unsigned int i;

	channels = kcalloc(st->chip_info->num_channels,
			   sizeof(struct iio_chan_spec), GFP_KERNEL);

	if (!channels)
		return -ENOMEM;

	for (i = 0; i < st->chip_info->num_channels; ++i) {
		channels[i] = st->chip_info->channel_template;
		channels[i].channel = i;
		channels[i].address = i;
	}

	indio_dev->channels = channels;

	return 0;
}

__attribute__((used)) static int ad5380_probe(struct device *dev, struct regmap *regmap,
			enum ad5380_type type, const char *name)
{
	struct iio_dev *indio_dev;
	struct ad5380_state *st;
	unsigned int ctrl = 0;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*st));
	if (indio_dev == NULL) {
		dev_err(dev, "Failed to allocate iio device\n");
		return -ENOMEM;
	}

	st = iio_priv(indio_dev);
	dev_set_drvdata(dev, indio_dev);

	st->chip_info = &ad5380_chip_info_tbl[type];
	st->regmap = regmap;

	indio_dev->dev.parent = dev;
	indio_dev->name = name;
	indio_dev->info = &ad5380_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->num_channels = st->chip_info->num_channels;

	ret = ad5380_alloc_channels(indio_dev);
	if (ret) {
		dev_err(dev, "Failed to allocate channel spec: %d\n", ret);
		return ret;
	}

	if (st->chip_info->int_vref == 2500)
		ctrl |= AD5380_CTRL_INT_VREF_2V5;

	st->vref_reg = devm_regulator_get(dev, "vref");
	if (!IS_ERR(st->vref_reg)) {
		ret = regulator_enable(st->vref_reg);
		if (ret) {
			dev_err(dev, "Failed to enable vref regulators: %d\n",
				ret);
			goto error_free_reg;
		}

		ret = regulator_get_voltage(st->vref_reg);
		if (ret < 0)
			goto error_disable_reg;

		st->vref = ret / 1000;
	} else {
		st->vref = st->chip_info->int_vref;
		ctrl |= AD5380_CTRL_INT_VREF_EN;
	}

	ret = regmap_write(st->regmap, AD5380_REG_SF_CTRL, ctrl);
	if (ret) {
		dev_err(dev, "Failed to write to device: %d\n", ret);
		goto error_disable_reg;
	}

	ret = iio_device_register(indio_dev);
	if (ret) {
		dev_err(dev, "Failed to register iio device: %d\n", ret);
		goto error_disable_reg;
	}

	return 0;

error_disable_reg:
	if (!IS_ERR(st->vref_reg))
		regulator_disable(st->vref_reg);
error_free_reg:
	kfree(indio_dev->channels);

	return ret;
}

__attribute__((used)) static int ad5380_remove(struct device *dev)
{
	struct iio_dev *indio_dev = dev_get_drvdata(dev);
	struct ad5380_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	kfree(indio_dev->channels);

	if (!IS_ERR(st->vref_reg)) {
		regulator_disable(st->vref_reg);
	}

	return 0;
}

__attribute__((used)) static bool ad5380_reg_false(struct device *dev, unsigned int reg)
{
	return false;
}

__attribute__((used)) static inline int ad5380_spi_register_driver(void)
{
	return 0;
}

__attribute__((used)) static inline void ad5380_spi_unregister_driver(void)
{
}

__attribute__((used)) static inline int ad5380_i2c_register_driver(void)
{
	return 0;
}

__attribute__((used)) static inline void ad5380_i2c_unregister_driver(void)
{
}

