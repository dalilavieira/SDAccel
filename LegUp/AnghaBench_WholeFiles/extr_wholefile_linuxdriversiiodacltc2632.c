#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct ltc2632_state {int vref_mv; int powerdown_cache_mask; int /*<<< orphan*/ * vref_reg; struct spi_device* spi_dev; } ;
struct ltc2632_chip_info {int vref_mv; int /*<<< orphan*/  channels; } ;
struct TYPE_6__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_2__ dev; } ;
struct TYPE_5__ {int realbits; int shift; } ;
struct iio_chan_spec {int address; int channel; TYPE_1__ scan_type; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  msg ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; scalar_t__ driver_data; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int LTC2632_CMD_EXTERNAL_REFER ; 
 int LTC2632_CMD_INTERNAL_REFER ; 
 int LTC2632_CMD_POWERDOWN_DAC_N ; 
 int LTC2632_CMD_WRITE_INPUT_N_UPDATE_N ; 
 int /*<<< orphan*/  LTC2632_DAC_CHANNELS ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 TYPE_4__* dev_of_node (int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * devm_regulator_get_optional (int /*<<< orphan*/ *,char*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 void* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  ltc2632_info ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ *) ; 
 int regulator_enable (int /*<<< orphan*/ *) ; 
 int regulator_get_voltage (int /*<<< orphan*/ *) ; 
 TYPE_3__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_write (struct spi_device*,int*,int) ; 
 int sprintf (char*,char*,int) ; 
 int strtobool (char const*,int*) ; 

__attribute__((used)) static int ltc2632_spi_write(struct spi_device *spi,
			     u8 cmd, u8 addr, u16 val, u8 shift)
{
	u32 data;
	u8 msg[3];

	/*
	 * The input shift register is 24 bits wide.
	 * The next four are the command bits, C3 to C0,
	 * followed by the 4-bit DAC address, A3 to A0, and then the
	 * 12-, 10-, 8-bit data-word. The data-word comprises the 12-,
	 * 10-, 8-bit input code followed by 4, 6, or 8 don't care bits.
	 */
	data = (cmd << 20) | (addr << 16) | (val << shift);
	msg[0] = data >> 16;
	msg[1] = data >> 8;
	msg[2] = data;

	return spi_write(spi, msg, sizeof(msg));
}

__attribute__((used)) static int ltc2632_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val,
			    int *val2,
			    long m)
{
	const struct ltc2632_state *st = iio_priv(indio_dev);

	switch (m) {
	case IIO_CHAN_INFO_SCALE:
		*val = st->vref_mv;
		*val2 = chan->scan_type.realbits;
		return IIO_VAL_FRACTIONAL_LOG2;
	}
	return -EINVAL;
}

__attribute__((used)) static int ltc2632_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val,
			     int val2,
			     long mask)
{
	struct ltc2632_state *st = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val >= (1 << chan->scan_type.realbits) || val < 0)
			return -EINVAL;

		return ltc2632_spi_write(st->spi_dev,
					 LTC2632_CMD_WRITE_INPUT_N_UPDATE_N,
					 chan->address, val,
					 chan->scan_type.shift);
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static ssize_t ltc2632_read_dac_powerdown(struct iio_dev *indio_dev,
					  uintptr_t private,
					  const struct iio_chan_spec *chan,
					  char *buf)
{
	struct ltc2632_state *st = iio_priv(indio_dev);

	return sprintf(buf, "%d\n",
		       !!(st->powerdown_cache_mask & (1 << chan->channel)));
}

__attribute__((used)) static ssize_t ltc2632_write_dac_powerdown(struct iio_dev *indio_dev,
					   uintptr_t private,
					   const struct iio_chan_spec *chan,
					   const char *buf,
					   size_t len)
{
	bool pwr_down;
	int ret;
	struct ltc2632_state *st = iio_priv(indio_dev);

	ret = strtobool(buf, &pwr_down);
	if (ret)
		return ret;

	if (pwr_down)
		st->powerdown_cache_mask |= (1 << chan->channel);
	else
		st->powerdown_cache_mask &= ~(1 << chan->channel);

	ret = ltc2632_spi_write(st->spi_dev,
				LTC2632_CMD_POWERDOWN_DAC_N,
				chan->channel, 0, 0);

	return ret ? ret : len;
}

__attribute__((used)) static int ltc2632_probe(struct spi_device *spi)
{
	struct ltc2632_state *st;
	struct iio_dev *indio_dev;
	struct ltc2632_chip_info *chip_info;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (!indio_dev)
		return -ENOMEM;

	st = iio_priv(indio_dev);

	spi_set_drvdata(spi, indio_dev);
	st->spi_dev = spi;

	chip_info = (struct ltc2632_chip_info *)
			spi_get_device_id(spi)->driver_data;

	st->vref_reg = devm_regulator_get_optional(&spi->dev, "vref");
	if (PTR_ERR(st->vref_reg) == -ENODEV) {
		/* use internal reference voltage */
		st->vref_reg = NULL;
		st->vref_mv = chip_info->vref_mv;

		ret = ltc2632_spi_write(spi, LTC2632_CMD_INTERNAL_REFER,
				0, 0, 0);
		if (ret) {
			dev_err(&spi->dev,
				"Set internal reference command failed, %d\n",
				ret);
			return ret;
		}
	} else if (IS_ERR(st->vref_reg)) {
		dev_err(&spi->dev,
				"Error getting voltage reference regulator\n");
		return PTR_ERR(st->vref_reg);
	} else {
		/* use external reference voltage */
		ret = regulator_enable(st->vref_reg);
		if (ret) {
			dev_err(&spi->dev,
				"enable reference regulator failed, %d\n",
				ret);
			return ret;
		}
		st->vref_mv = regulator_get_voltage(st->vref_reg) / 1000;

		ret = ltc2632_spi_write(spi, LTC2632_CMD_EXTERNAL_REFER,
				0, 0, 0);
		if (ret) {
			dev_err(&spi->dev,
				"Set external reference command failed, %d\n",
				ret);
			return ret;
		}
	}

	indio_dev->dev.parent = &spi->dev;
	indio_dev->name = dev_of_node(&spi->dev) ? dev_of_node(&spi->dev)->name
						 : spi_get_device_id(spi)->name;
	indio_dev->info = &ltc2632_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = chip_info->channels;
	indio_dev->num_channels = LTC2632_DAC_CHANNELS;

	return iio_device_register(indio_dev);
}

__attribute__((used)) static int ltc2632_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct ltc2632_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	if (st->vref_reg)
		regulator_disable(st->vref_reg);

	return 0;
}

