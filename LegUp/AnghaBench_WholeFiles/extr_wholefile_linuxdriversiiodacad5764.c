#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int u16 ;
struct spi_transfer {int len; int cs_change; char* supply; int /*<<< orphan*/  consumer; int /*<<< orphan*/ * rx_buf; int /*<<< orphan*/ * tx_buf; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  channels; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/  mlock; } ;
struct TYPE_8__ {int realbits; int shift; } ;
struct iio_chan_spec {unsigned int channel; TYPE_3__ scan_type; int /*<<< orphan*/  address; } ;
struct ad5764_state {struct spi_transfer* vref_reg; TYPE_5__* chip_info; struct spi_device* spi; TYPE_2__* data; } ;
typedef  enum ad5764_type { ____Placeholder_ad5764_type } ad5764_type ;
struct TYPE_10__ {scalar_t__ int_vref; int /*<<< orphan*/  channels; } ;
struct TYPE_9__ {int driver_data; int /*<<< orphan*/  name; } ;
struct TYPE_7__ {void* d32; int /*<<< orphan*/ * d8; } ;

/* Variables and functions */
 int /*<<< orphan*/  AD5764_NUM_CHANNELS ; 
 int AD5764_REG_DATA (int /*<<< orphan*/ ) ; 
 int AD5764_REG_FINE_GAIN (int /*<<< orphan*/ ) ; 
 int AD5764_REG_OFFSET (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ARRAY_SIZE (struct spi_transfer*) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_CALIBBIAS 132 
#define  IIO_CHAN_INFO_CALIBSCALE 131 
#define  IIO_CHAN_INFO_OFFSET 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 TYPE_5__* ad5764_chip_infos ; 
 int /*<<< orphan*/  ad5764_info ; 
 int be32_to_cpu (void*) ; 
 void* cpu_to_be32 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_regulator_bulk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct spi_transfer*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ad5764_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int /*<<< orphan*/ ,struct spi_transfer*) ; 
 int regulator_bulk_enable (int /*<<< orphan*/ ,struct spi_transfer*) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 int sign_extend32 (int,int) ; 
 TYPE_4__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int /*<<< orphan*/ ) ; 
 int spi_write (struct spi_device*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int ad5764_write(struct iio_dev *indio_dev, unsigned int reg,
	unsigned int val)
{
	struct ad5764_state *st = iio_priv(indio_dev);
	int ret;

	mutex_lock(&indio_dev->mlock);
	st->data[0].d32 = cpu_to_be32((reg << 16) | val);

	ret = spi_write(st->spi, &st->data[0].d8[1], 3);
	mutex_unlock(&indio_dev->mlock);

	return ret;
}

__attribute__((used)) static int ad5764_read(struct iio_dev *indio_dev, unsigned int reg,
	unsigned int *val)
{
	struct ad5764_state *st = iio_priv(indio_dev);
	int ret;
	struct spi_transfer t[] = {
		{
			.tx_buf = &st->data[0].d8[1],
			.len = 3,
			.cs_change = 1,
		}, {
			.rx_buf = &st->data[1].d8[1],
			.len = 3,
		},
	};

	mutex_lock(&indio_dev->mlock);

	st->data[0].d32 = cpu_to_be32((1 << 23) | (reg << 16));

	ret = spi_sync_transfer(st->spi, t, ARRAY_SIZE(t));
	if (ret >= 0)
		*val = be32_to_cpu(st->data[1].d32) & 0xffff;

	mutex_unlock(&indio_dev->mlock);

	return ret;
}

__attribute__((used)) static int ad5764_chan_info_to_reg(struct iio_chan_spec const *chan, long info)
{
	switch (info) {
	case IIO_CHAN_INFO_RAW:
		return AD5764_REG_DATA(chan->address);
	case IIO_CHAN_INFO_CALIBBIAS:
		return AD5764_REG_OFFSET(chan->address);
	case IIO_CHAN_INFO_CALIBSCALE:
		return AD5764_REG_FINE_GAIN(chan->address);
	default:
		break;
	}

	return 0;
}

__attribute__((used)) static int ad5764_write_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int val, int val2, long info)
{
	const int max_val = (1 << chan->scan_type.realbits);
	unsigned int reg;

	switch (info) {
	case IIO_CHAN_INFO_RAW:
		if (val >= max_val || val < 0)
			return -EINVAL;
		val <<= chan->scan_type.shift;
		break;
	case IIO_CHAN_INFO_CALIBBIAS:
		if (val >= 128 || val < -128)
			return -EINVAL;
		break;
	case IIO_CHAN_INFO_CALIBSCALE:
		if (val >= 32 || val < -32)
			return -EINVAL;
		break;
	default:
		return -EINVAL;
	}

	reg = ad5764_chan_info_to_reg(chan, info);
	return ad5764_write(indio_dev, reg, (u16)val);
}

__attribute__((used)) static int ad5764_get_channel_vref(struct ad5764_state *st,
	unsigned int channel)
{
	if (st->chip_info->int_vref)
		return st->chip_info->int_vref;
	else
		return regulator_get_voltage(st->vref_reg[channel / 2].consumer);
}

__attribute__((used)) static int ad5764_read_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
	struct ad5764_state *st = iio_priv(indio_dev);
	unsigned int reg;
	int vref;
	int ret;

	switch (info) {
	case IIO_CHAN_INFO_RAW:
		reg = AD5764_REG_DATA(chan->address);
		ret = ad5764_read(indio_dev, reg, val);
		if (ret < 0)
			return ret;
		*val >>= chan->scan_type.shift;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_CALIBBIAS:
		reg = AD5764_REG_OFFSET(chan->address);
		ret = ad5764_read(indio_dev, reg, val);
		if (ret < 0)
			return ret;
		*val = sign_extend32(*val, 7);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_CALIBSCALE:
		reg = AD5764_REG_FINE_GAIN(chan->address);
		ret = ad5764_read(indio_dev, reg, val);
		if (ret < 0)
			return ret;
		*val = sign_extend32(*val, 5);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		/* vout = 4 * vref + ((dac_code / 65536) - 0.5) */
		vref = ad5764_get_channel_vref(st, chan->channel);
		if (vref < 0)
			return vref;

		*val = vref * 4 / 1000;
		*val2 = chan->scan_type.realbits;
		return IIO_VAL_FRACTIONAL_LOG2;
	case IIO_CHAN_INFO_OFFSET:
		*val = -(1 << chan->scan_type.realbits) / 2;
		return IIO_VAL_INT;
	}

	return -EINVAL;
}

__attribute__((used)) static int ad5764_probe(struct spi_device *spi)
{
	enum ad5764_type type = spi_get_device_id(spi)->driver_data;
	struct iio_dev *indio_dev;
	struct ad5764_state *st;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (indio_dev == NULL) {
		dev_err(&spi->dev, "Failed to allocate iio device\n");
		return -ENOMEM;
	}

	st = iio_priv(indio_dev);
	spi_set_drvdata(spi, indio_dev);

	st->spi = spi;
	st->chip_info = &ad5764_chip_infos[type];

	indio_dev->dev.parent = &spi->dev;
	indio_dev->name = spi_get_device_id(spi)->name;
	indio_dev->info = &ad5764_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->num_channels = AD5764_NUM_CHANNELS;
	indio_dev->channels = st->chip_info->channels;

	if (st->chip_info->int_vref == 0) {
		st->vref_reg[0].supply = "vrefAB";
		st->vref_reg[1].supply = "vrefCD";

		ret = devm_regulator_bulk_get(&st->spi->dev,
			ARRAY_SIZE(st->vref_reg), st->vref_reg);
		if (ret) {
			dev_err(&spi->dev, "Failed to request vref regulators: %d\n",
				ret);
			return ret;
		}

		ret = regulator_bulk_enable(ARRAY_SIZE(st->vref_reg),
			st->vref_reg);
		if (ret) {
			dev_err(&spi->dev, "Failed to enable vref regulators: %d\n",
				ret);
			return ret;
		}
	}

	ret = iio_device_register(indio_dev);
	if (ret) {
		dev_err(&spi->dev, "Failed to register iio device: %d\n", ret);
		goto error_disable_reg;
	}

	return 0;

error_disable_reg:
	if (st->chip_info->int_vref == 0)
		regulator_bulk_disable(ARRAY_SIZE(st->vref_reg), st->vref_reg);
	return ret;
}

__attribute__((used)) static int ad5764_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct ad5764_state *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	if (st->chip_info->int_vref == 0)
		regulator_bulk_disable(ARRAY_SIZE(st->vref_reg), st->vref_reg);

	return 0;
}

