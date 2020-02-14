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
typedef  unsigned int u8 ;
struct TYPE_4__ {struct device* parent; } ;
struct iio_dev {char const* name; int num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  mlock; } ;
struct TYPE_5__ {int shift; int realbits; } ;
struct iio_chan_spec {int channel; TYPE_2__ scan_type; int /*<<< orphan*/  address; } ;
struct device {int dummy; } ;
struct ad5686_state {int pwr_down_mode; int pwr_down_mask; int use_internal_vref; int (* write ) (struct ad5686_state*,unsigned int,int /*<<< orphan*/ ,unsigned int) ;int (* read ) (struct ad5686_state*,int /*<<< orphan*/ ) ;int vref_mv; int /*<<< orphan*/  reg; TYPE_3__* chip_info; struct device* dev; } ;
typedef  int ssize_t ;
typedef  enum ad5686_supported_device_ids { ____Placeholder_ad5686_supported_device_ids } ad5686_supported_device_ids ;
typedef  int (* ad5686_write_func ) (struct ad5686_state*,unsigned int,int /*<<< orphan*/ ,int) ;
typedef  int (* ad5686_read_func ) (struct ad5686_state*,int /*<<< orphan*/ ) ;
struct TYPE_6__ {int regmap_type; int int_vref_mv; int num_channels; int /*<<< orphan*/  channels; } ;

/* Variables and functions */
 unsigned int AD5683_REF_BIT_MSK ; 
#define  AD5683_REGMAP 132 
 unsigned int AD5686_CMD_CONTROL_REG ; 
 unsigned int AD5686_CMD_INTERNAL_REFER_SETUP ; 
 unsigned int AD5686_CMD_POWERDOWN_DAC ; 
 unsigned int AD5686_CMD_WRITE_INPUT_N_UPDATE_N ; 
#define  AD5686_REGMAP 131 
 unsigned int AD5693_REF_BIT_MSK ; 
#define  AD5693_REGMAP 130 
 int EINVAL ; 
 int ENOMEM ; 
 int GENMASK (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 TYPE_3__* ad5686_chip_info_tbl ; 
 int /*<<< orphan*/  ad5686_info ; 
 struct iio_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct iio_dev*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int /*<<< orphan*/  devm_regulator_get_optional (struct device*,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ad5686_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 int sprintf (char*,char*,int) ; 
 int strtobool (char const*,int*) ; 
 int stub1 (struct ad5686_state*,unsigned int,int /*<<< orphan*/ ,unsigned int) ; 
 int stub2 (struct ad5686_state*,int /*<<< orphan*/ ) ; 
 int stub3 (struct ad5686_state*,unsigned int,int /*<<< orphan*/ ,int) ; 
 int stub4 (struct ad5686_state*,unsigned int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ad5686_get_powerdown_mode(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan)
{
	struct ad5686_state *st = iio_priv(indio_dev);

	return ((st->pwr_down_mode >> (chan->channel * 2)) & 0x3) - 1;
}

__attribute__((used)) static int ad5686_set_powerdown_mode(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     unsigned int mode)
{
	struct ad5686_state *st = iio_priv(indio_dev);

	st->pwr_down_mode &= ~(0x3 << (chan->channel * 2));
	st->pwr_down_mode |= ((mode + 1) << (chan->channel * 2));

	return 0;
}

__attribute__((used)) static ssize_t ad5686_read_dac_powerdown(struct iio_dev *indio_dev,
		uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
	struct ad5686_state *st = iio_priv(indio_dev);

	return sprintf(buf, "%d\n", !!(st->pwr_down_mask &
				       (0x3 << (chan->channel * 2))));
}

__attribute__((used)) static ssize_t ad5686_write_dac_powerdown(struct iio_dev *indio_dev,
					  uintptr_t private,
					  const struct iio_chan_spec *chan,
					  const char *buf,
					  size_t len)
{
	bool readin;
	int ret;
	struct ad5686_state *st = iio_priv(indio_dev);
	unsigned int val, ref_bit_msk;
	u8 shift;

	ret = strtobool(buf, &readin);
	if (ret)
		return ret;

	if (readin)
		st->pwr_down_mask |= (0x3 << (chan->channel * 2));
	else
		st->pwr_down_mask &= ~(0x3 << (chan->channel * 2));

	switch (st->chip_info->regmap_type) {
	case AD5683_REGMAP:
		shift = 13;
		ref_bit_msk = AD5683_REF_BIT_MSK;
		break;
	case AD5686_REGMAP:
		shift = 0;
		ref_bit_msk = 0;
		break;
	case AD5693_REGMAP:
		shift = 13;
		ref_bit_msk = AD5693_REF_BIT_MSK;
		break;
	default:
		return -EINVAL;
	}

	val = ((st->pwr_down_mask & st->pwr_down_mode) << shift);
	if (!st->use_internal_vref)
		val |= ref_bit_msk;

	ret = st->write(st, AD5686_CMD_POWERDOWN_DAC, 0, val);

	return ret ? ret : len;
}

__attribute__((used)) static int ad5686_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val,
			   int *val2,
			   long m)
{
	struct ad5686_state *st = iio_priv(indio_dev);
	int ret;

	switch (m) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&indio_dev->mlock);
		ret = st->read(st, chan->address);
		mutex_unlock(&indio_dev->mlock);
		if (ret < 0)
			return ret;
		*val = (ret >> chan->scan_type.shift) &
			GENMASK(chan->scan_type.realbits - 1, 0);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = st->vref_mv;
		*val2 = chan->scan_type.realbits;
		return IIO_VAL_FRACTIONAL_LOG2;
	}
	return -EINVAL;
}

__attribute__((used)) static int ad5686_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int val,
			    int val2,
			    long mask)
{
	struct ad5686_state *st = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val > (1 << chan->scan_type.realbits) || val < 0)
			return -EINVAL;

		mutex_lock(&indio_dev->mlock);
		ret = st->write(st,
				AD5686_CMD_WRITE_INPUT_N_UPDATE_N,
				chan->address,
				val << chan->scan_type.shift);
		mutex_unlock(&indio_dev->mlock);
		break;
	default:
		ret = -EINVAL;
	}

	return ret;
}

int ad5686_probe(struct device *dev,
		 enum ad5686_supported_device_ids chip_type,
		 const char *name, ad5686_write_func write,
		 ad5686_read_func read)
{
	struct ad5686_state *st;
	struct iio_dev *indio_dev;
	unsigned int val, ref_bit_msk;
	u8 cmd;
	int ret, i, voltage_uv = 0;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*st));
	if (indio_dev == NULL)
		return  -ENOMEM;

	st = iio_priv(indio_dev);
	dev_set_drvdata(dev, indio_dev);

	st->dev = dev;
	st->write = write;
	st->read = read;

	st->reg = devm_regulator_get_optional(dev, "vcc");
	if (!IS_ERR(st->reg)) {
		ret = regulator_enable(st->reg);
		if (ret)
			return ret;

		ret = regulator_get_voltage(st->reg);
		if (ret < 0)
			goto error_disable_reg;

		voltage_uv = ret;
	}

	st->chip_info = &ad5686_chip_info_tbl[chip_type];

	if (voltage_uv)
		st->vref_mv = voltage_uv / 1000;
	else
		st->vref_mv = st->chip_info->int_vref_mv;

	/* Set all the power down mode for all channels to 1K pulldown */
	for (i = 0; i < st->chip_info->num_channels; i++)
		st->pwr_down_mode |= (0x01 << (i * 2));

	indio_dev->dev.parent = dev;
	indio_dev->name = name;
	indio_dev->info = &ad5686_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = st->chip_info->channels;
	indio_dev->num_channels = st->chip_info->num_channels;

	switch (st->chip_info->regmap_type) {
	case AD5683_REGMAP:
		cmd = AD5686_CMD_CONTROL_REG;
		ref_bit_msk = AD5683_REF_BIT_MSK;
		st->use_internal_vref = !voltage_uv;
		break;
	case AD5686_REGMAP:
		cmd = AD5686_CMD_INTERNAL_REFER_SETUP;
		ref_bit_msk = 0;
		break;
	case AD5693_REGMAP:
		cmd = AD5686_CMD_CONTROL_REG;
		ref_bit_msk = AD5693_REF_BIT_MSK;
		st->use_internal_vref = !voltage_uv;
		break;
	default:
		ret = -EINVAL;
		goto error_disable_reg;
	}

	val = (voltage_uv | ref_bit_msk);

	ret = st->write(st, cmd, 0, !!val);
	if (ret)
		goto error_disable_reg;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_disable_reg;

	return 0;

error_disable_reg:
	if (!IS_ERR(st->reg))
		regulator_disable(st->reg);
	return ret;
}

int ad5686_remove(struct device *dev)
{
	struct iio_dev *indio_dev = dev_get_drvdata(dev);
	struct ad5686_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	if (!IS_ERR(st->reg))
		regulator_disable(st->reg);

	return 0;
}

