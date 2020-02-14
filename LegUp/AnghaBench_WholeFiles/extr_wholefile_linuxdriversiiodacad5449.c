#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct spi_transfer {int len; int cs_change; void** rx_buf; void** tx_buf; } ;
struct spi_device_id {size_t driver_data; int /*<<< orphan*/  name; } ;
struct TYPE_8__ {struct ad5449_platform_data* platform_data; } ;
struct spi_device {TYPE_3__ dev; } ;
struct regulator_bulk_data {char const* supply; int /*<<< orphan*/  consumer; } ;
struct TYPE_6__ {TYPE_3__* parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/  mlock; } ;
struct TYPE_7__ {int realbits; int shift; } ;
struct iio_chan_spec {size_t address; size_t channel; TYPE_2__ scan_type; } ;
struct ad5449_platform_data {unsigned int sdo_mode; scalar_t__ hardware_clear_to_midscale; } ;
struct ad5449 {int has_sdo; int* dac_cache; struct regulator_bulk_data* vref_reg; TYPE_5__* chip_info; struct spi_device* spi; void** data; } ;
struct TYPE_9__ {int num_channels; scalar_t__ has_ctrl; int /*<<< orphan*/  channels; } ;

/* Variables and functions */
 unsigned int AD5449_CMD_CTRL ; 
 unsigned int AD5449_CMD_LOAD_AND_UPDATE (size_t) ; 
 unsigned int AD5449_CMD_NOOP ; 
 unsigned int AD5449_CMD_READ (size_t) ; 
 unsigned int AD5449_CTRL_HCLR_TO_MIDSCALE ; 
 unsigned int AD5449_CTRL_SDO_OFFSET ; 
 unsigned int AD5449_SDO_DISABLED ; 
 int /*<<< orphan*/  ARRAY_SIZE (struct spi_transfer*) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 TYPE_5__* ad5449_chip_info ; 
 int /*<<< orphan*/  ad5449_info ; 
 unsigned int be16_to_cpu (void*) ; 
 void* cpu_to_be16 (unsigned int) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_3__*,int) ; 
 int devm_regulator_bulk_get (TYPE_3__*,int,struct regulator_bulk_data*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct ad5449* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,struct regulator_bulk_data*) ; 
 int regulator_bulk_enable (int,struct regulator_bulk_data*) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync_transfer (struct spi_device*,struct spi_transfer*,int /*<<< orphan*/ ) ; 
 int spi_write (struct spi_device*,void**,int) ; 

__attribute__((used)) static int ad5449_write(struct iio_dev *indio_dev, unsigned int addr,
	unsigned int val)
{
	struct ad5449 *st = iio_priv(indio_dev);
	int ret;

	mutex_lock(&indio_dev->mlock);
	st->data[0] = cpu_to_be16((addr << 12) | val);
	ret = spi_write(st->spi, st->data, 2);
	mutex_unlock(&indio_dev->mlock);

	return ret;
}

__attribute__((used)) static int ad5449_read(struct iio_dev *indio_dev, unsigned int addr,
	unsigned int *val)
{
	struct ad5449 *st = iio_priv(indio_dev);
	int ret;
	struct spi_transfer t[] = {
		{
			.tx_buf = &st->data[0],
			.len = 2,
			.cs_change = 1,
		}, {
			.tx_buf = &st->data[1],
			.rx_buf = &st->data[1],
			.len = 2,
		},
	};

	mutex_lock(&indio_dev->mlock);
	st->data[0] = cpu_to_be16(addr << 12);
	st->data[1] = cpu_to_be16(AD5449_CMD_NOOP);

	ret = spi_sync_transfer(st->spi, t, ARRAY_SIZE(t));
	if (ret < 0)
		goto out_unlock;

	*val = be16_to_cpu(st->data[1]);

out_unlock:
	mutex_unlock(&indio_dev->mlock);
	return ret;
}

__attribute__((used)) static int ad5449_read_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
	struct ad5449 *st = iio_priv(indio_dev);
	struct regulator_bulk_data *reg;
	int scale_uv;
	int ret;

	switch (info) {
	case IIO_CHAN_INFO_RAW:
		if (st->has_sdo) {
			ret = ad5449_read(indio_dev,
				AD5449_CMD_READ(chan->address), val);
			if (ret)
				return ret;
			*val &= 0xfff;
		} else {
			*val = st->dac_cache[chan->address];
		}

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		reg = &st->vref_reg[chan->channel];
		scale_uv = regulator_get_voltage(reg->consumer);
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

__attribute__((used)) static int ad5449_write_raw(struct iio_dev *indio_dev,
	struct iio_chan_spec const *chan, int val, int val2, long info)
{
	struct ad5449 *st = iio_priv(indio_dev);
	int ret;

	switch (info) {
	case IIO_CHAN_INFO_RAW:
		if (val < 0 || val >= (1 << chan->scan_type.realbits))
			return -EINVAL;

		ret = ad5449_write(indio_dev,
			AD5449_CMD_LOAD_AND_UPDATE(chan->address),
			val << chan->scan_type.shift);
		if (ret == 0)
			st->dac_cache[chan->address] = val;
		break;
	default:
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static const char *ad5449_vref_name(struct ad5449 *st, int n)
{
	if (st->chip_info->num_channels == 1)
		return "VREF";

	if (n == 0)
		return "VREFA";
	else
		return "VREFB";
}

__attribute__((used)) static int ad5449_spi_probe(struct spi_device *spi)
{
	struct ad5449_platform_data *pdata = spi->dev.platform_data;
	const struct spi_device_id *id = spi_get_device_id(spi);
	struct iio_dev *indio_dev;
	struct ad5449 *st;
	unsigned int i;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (indio_dev == NULL)
		return -ENOMEM;

	st = iio_priv(indio_dev);
	spi_set_drvdata(spi, indio_dev);

	st->chip_info = &ad5449_chip_info[id->driver_data];
	st->spi = spi;

	for (i = 0; i < st->chip_info->num_channels; ++i)
		st->vref_reg[i].supply = ad5449_vref_name(st, i);

	ret = devm_regulator_bulk_get(&spi->dev, st->chip_info->num_channels,
				st->vref_reg);
	if (ret)
		return ret;

	ret = regulator_bulk_enable(st->chip_info->num_channels, st->vref_reg);
	if (ret)
		return ret;

	indio_dev->dev.parent = &spi->dev;
	indio_dev->name = id->name;
	indio_dev->info = &ad5449_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = st->chip_info->channels;
	indio_dev->num_channels = st->chip_info->num_channels;

	if (st->chip_info->has_ctrl) {
		unsigned int ctrl = 0x00;
		if (pdata) {
			if (pdata->hardware_clear_to_midscale)
				ctrl |= AD5449_CTRL_HCLR_TO_MIDSCALE;
			ctrl |= pdata->sdo_mode << AD5449_CTRL_SDO_OFFSET;
			st->has_sdo = pdata->sdo_mode != AD5449_SDO_DISABLED;
		} else {
			st->has_sdo = true;
		}
		ad5449_write(indio_dev, AD5449_CMD_CTRL, ctrl);
	}

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_disable_reg;

	return 0;

error_disable_reg:
	regulator_bulk_disable(st->chip_info->num_channels, st->vref_reg);

	return ret;
}

__attribute__((used)) static int ad5449_spi_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct ad5449 *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	regulator_bulk_disable(st->chip_info->num_channels, st->vref_reg);

	return 0;
}

