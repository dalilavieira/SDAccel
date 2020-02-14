#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_8__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {struct device* parent; } ;
struct iio_dev {char const* name; unsigned int num_channels; TYPE_4__* channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_2__ dev; int /*<<< orphan*/  mlock; } ;
struct TYPE_9__ {int realbits; unsigned int shift; } ;
struct iio_chan_spec {unsigned int address; size_t channel; TYPE_1__ scan_type; } ;
struct device {int dummy; } ;
struct ad5064_state {int (* write ) (struct ad5064_state*,unsigned int,unsigned int,unsigned int) ;int* pwr_down; unsigned int* pwr_down_mode; int use_internal_vref; int* dac_cache; TYPE_5__* vref_reg; TYPE_8__* chip_info; struct device* dev; } ;
typedef  int ssize_t ;
typedef  enum ad5064_type { ____Placeholder_ad5064_type } ad5064_type ;
typedef  int (* ad5064_write_func ) (struct ad5064_state*,unsigned int,unsigned int,unsigned int) ;
struct TYPE_14__ {scalar_t__ regmap_type; int internal_vref; unsigned int num_channels; TYPE_4__* channels; scalar_t__ shared_vref; } ;
struct TYPE_13__ {char* supply; int /*<<< orphan*/  consumer; } ;
struct TYPE_11__ {int realbits; } ;
struct TYPE_12__ {TYPE_3__ scan_type; } ;

/* Variables and functions */
 unsigned int AD5064_CMD_CONFIG ; 
 unsigned int AD5064_CMD_CONFIG_V2 ; 
 unsigned int AD5064_CMD_POWERDOWN_DAC ; 
 unsigned int AD5064_CMD_WRITE_INPUT_N_UPDATE_N ; 
 unsigned int AD5064_CONFIG_INT_VREF_ENABLE ; 
 unsigned int AD5064_LDAC_PWRDN_1K ; 
#define  AD5064_REGMAP_ADI2 130 
 scalar_t__ AD5064_REGMAP_LTC ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 TYPE_8__* ad5064_chip_info_tbl ; 
 int /*<<< orphan*/  ad5064_info ; 
 char const* const* ad5064_vref_names ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct iio_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct iio_dev*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_regulator_bulk_get (struct device*,unsigned int,TYPE_5__*) ; 
 int /*<<< orphan*/  devm_regulator_get_optional (struct device*,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ad5064_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_bulk_disable (unsigned int,TYPE_5__*) ; 
 int regulator_bulk_enable (unsigned int,TYPE_5__*) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 int sprintf (char*,char*,int) ; 
 int strtobool (char const*,int*) ; 
 int stub1 (struct ad5064_state*,unsigned int,unsigned int,unsigned int) ; 

__attribute__((used)) static int ad5064_write(struct ad5064_state *st, unsigned int cmd,
	unsigned int addr, unsigned int val, unsigned int shift)
{
	val <<= shift;

	return st->write(st, cmd, addr, val);
}

__attribute__((used)) static int ad5064_sync_powerdown_mode(struct ad5064_state *st,
	const struct iio_chan_spec *chan)
{
	unsigned int val, address;
	unsigned int shift;
	int ret;

	if (st->chip_info->regmap_type == AD5064_REGMAP_LTC) {
		val = 0;
		address = chan->address;
	} else {
		if (st->chip_info->regmap_type == AD5064_REGMAP_ADI2)
			shift = 4;
		else
			shift = 8;

		val = (0x1 << chan->address);
		address = 0;

		if (st->pwr_down[chan->channel])
			val |= st->pwr_down_mode[chan->channel] << shift;
	}

	ret = ad5064_write(st, AD5064_CMD_POWERDOWN_DAC, address, val, 0);

	return ret;
}

__attribute__((used)) static int ad5064_get_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan)
{
	struct ad5064_state *st = iio_priv(indio_dev);

	return st->pwr_down_mode[chan->channel] - 1;
}

__attribute__((used)) static int ad5064_set_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, unsigned int mode)
{
	struct ad5064_state *st = iio_priv(indio_dev);
	int ret;

	mutex_lock(&indio_dev->mlock);
	st->pwr_down_mode[chan->channel] = mode + 1;

	ret = ad5064_sync_powerdown_mode(st, chan);
	mutex_unlock(&indio_dev->mlock);

	return ret;
}

__attribute__((used)) static ssize_t ad5064_read_dac_powerdown(struct iio_dev *indio_dev,
	uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
	struct ad5064_state *st = iio_priv(indio_dev);

	return sprintf(buf, "%d\n", st->pwr_down[chan->channel]);
}

__attribute__((used)) static ssize_t ad5064_write_dac_powerdown(struct iio_dev *indio_dev,
	 uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
	 size_t len)
{
	struct ad5064_state *st = iio_priv(indio_dev);
	bool pwr_down;
	int ret;

	ret = strtobool(buf, &pwr_down);
	if (ret)
		return ret;

	mutex_lock(&indio_dev->mlock);
	st->pwr_down[chan->channel] = pwr_down;

	ret = ad5064_sync_powerdown_mode(st, chan);
	mutex_unlock(&indio_dev->mlock);
	return ret ? ret : len;
}

__attribute__((used)) static int ad5064_get_vref(struct ad5064_state *st,
	struct iio_chan_spec const *chan)
{
	unsigned int i;

	if (st->use_internal_vref)
		return st->chip_info->internal_vref;

	i = st->chip_info->shared_vref ? 0 : chan->channel;
	return regulator_get_voltage(st->vref_reg[i].consumer);
}

__attribute__((used)) static int ad5064_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val,
			   int *val2,
			   long m)
{
	struct ad5064_state *st = iio_priv(indio_dev);
	int scale_uv;

	switch (m) {
	case IIO_CHAN_INFO_RAW:
		*val = st->dac_cache[chan->channel];
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		scale_uv = ad5064_get_vref(st, chan);
		if (scale_uv < 0)
			return scale_uv;

		*val = scale_uv / 1000;
		*val2 = chan->scan_type.realbits;
		return IIO_VAL_FRACTIONAL_LOG2;
	default:
		break;
	}
	return -EINVAL;
}

__attribute__((used)) static int ad5064_write_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int val, int val2, long mask)
{
	struct ad5064_state *st = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val >= (1 << chan->scan_type.realbits) || val < 0)
			return -EINVAL;

		mutex_lock(&indio_dev->mlock);
		ret = ad5064_write(st, AD5064_CMD_WRITE_INPUT_N_UPDATE_N,
				chan->address, val, chan->scan_type.shift);
		if (ret == 0)
			st->dac_cache[chan->channel] = val;
		mutex_unlock(&indio_dev->mlock);
		break;
	default:
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static inline unsigned int ad5064_num_vref(struct ad5064_state *st)
{
	return st->chip_info->shared_vref ? 1 : st->chip_info->num_channels;
}

__attribute__((used)) static const char * const ad5064_vref_name(struct ad5064_state *st,
	unsigned int vref)
{
	return st->chip_info->shared_vref ? "vref" : ad5064_vref_names[vref];
}

__attribute__((used)) static int ad5064_set_config(struct ad5064_state *st, unsigned int val)
{
	unsigned int cmd;

	switch (st->chip_info->regmap_type) {
	case AD5064_REGMAP_ADI2:
		cmd = AD5064_CMD_CONFIG_V2;
		break;
	default:
		cmd = AD5064_CMD_CONFIG;
		break;
	}

	return ad5064_write(st, cmd, 0, val, 0);
}

__attribute__((used)) static int ad5064_request_vref(struct ad5064_state *st, struct device *dev)
{
	unsigned int i;
	int ret;

	for (i = 0; i < ad5064_num_vref(st); ++i)
		st->vref_reg[i].supply = ad5064_vref_name(st, i);

	if (!st->chip_info->internal_vref)
		return devm_regulator_bulk_get(dev, ad5064_num_vref(st),
					       st->vref_reg);

	/*
	 * This assumes that when the regulator has an internal VREF
	 * there is only one external VREF connection, which is
	 * currently the case for all supported devices.
	 */
	st->vref_reg[0].consumer = devm_regulator_get_optional(dev, "vref");
	if (!IS_ERR(st->vref_reg[0].consumer))
		return 0;

	ret = PTR_ERR(st->vref_reg[0].consumer);
	if (ret != -ENODEV)
		return ret;

	/* If no external regulator was supplied use the internal VREF */
	st->use_internal_vref = true;
	ret = ad5064_set_config(st, AD5064_CONFIG_INT_VREF_ENABLE);
	if (ret)
		dev_err(dev, "Failed to enable internal vref: %d\n", ret);

	return ret;
}

__attribute__((used)) static int ad5064_probe(struct device *dev, enum ad5064_type type,
			const char *name, ad5064_write_func write)
{
	struct iio_dev *indio_dev;
	struct ad5064_state *st;
	unsigned int midscale;
	unsigned int i;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*st));
	if (indio_dev == NULL)
		return  -ENOMEM;

	st = iio_priv(indio_dev);
	dev_set_drvdata(dev, indio_dev);

	st->chip_info = &ad5064_chip_info_tbl[type];
	st->dev = dev;
	st->write = write;

	ret = ad5064_request_vref(st, dev);
	if (ret)
		return ret;

	if (!st->use_internal_vref) {
		ret = regulator_bulk_enable(ad5064_num_vref(st), st->vref_reg);
		if (ret)
			return ret;
	}

	indio_dev->dev.parent = dev;
	indio_dev->name = name;
	indio_dev->info = &ad5064_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = st->chip_info->channels;
	indio_dev->num_channels = st->chip_info->num_channels;

	midscale = (1 << indio_dev->channels[0].scan_type.realbits) /  2;

	for (i = 0; i < st->chip_info->num_channels; ++i) {
		st->pwr_down_mode[i] = AD5064_LDAC_PWRDN_1K;
		st->dac_cache[i] = midscale;
	}

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_disable_reg;

	return 0;

error_disable_reg:
	if (!st->use_internal_vref)
		regulator_bulk_disable(ad5064_num_vref(st), st->vref_reg);

	return ret;
}

__attribute__((used)) static int ad5064_remove(struct device *dev)
{
	struct iio_dev *indio_dev = dev_get_drvdata(dev);
	struct ad5064_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	if (!st->use_internal_vref)
		regulator_bulk_disable(ad5064_num_vref(st), st->vref_reg);

	return 0;
}

__attribute__((used)) static inline int ad5064_spi_register_driver(void) { return 0; }

__attribute__((used)) static inline void ad5064_spi_unregister_driver(void) { }

__attribute__((used)) static inline int ad5064_i2c_register_driver(void) { return 0; }

__attribute__((used)) static inline void ad5064_i2c_unregister_driver(void) { }

