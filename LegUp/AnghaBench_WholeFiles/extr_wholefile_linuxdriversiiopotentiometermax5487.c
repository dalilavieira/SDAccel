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
typedef  int u16 ;
struct spi_device_id {int driver_data; int /*<<< orphan*/  name; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct max5487_data {int kohms; struct spi_device* spi; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; } ;
struct iio_chan_spec {int address; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 long IIO_CHAN_INFO_RAW ; 
 long IIO_CHAN_INFO_SCALE ; 
 int IIO_VAL_FRACTIONAL ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int MAX5487_COPY_AB_TO_NV ; 
 int MAX5487_COPY_NV_TO_AB ; 
 int MAX5487_MAX_POS ; 
 struct iio_dev* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct iio_dev*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct max5487_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  max5487_channels ; 
 int /*<<< orphan*/  max5487_info ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int spi_write (struct spi_device*,void const*,int) ; 

__attribute__((used)) static int max5487_write_cmd(struct spi_device *spi, u16 cmd)
{
	return spi_write(spi, (const void *) &cmd, sizeof(u16));
}

__attribute__((used)) static int max5487_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct max5487_data *data = iio_priv(indio_dev);

	if (mask != IIO_CHAN_INFO_SCALE)
		return -EINVAL;

	*val = 1000 * data->kohms;
	*val2 = MAX5487_MAX_POS;

	return IIO_VAL_FRACTIONAL;
}

__attribute__((used)) static int max5487_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct max5487_data *data = iio_priv(indio_dev);

	if (mask != IIO_CHAN_INFO_RAW)
		return -EINVAL;

	if (val < 0 || val > MAX5487_MAX_POS)
		return -EINVAL;

	return max5487_write_cmd(data->spi, chan->address | val);
}

__attribute__((used)) static int max5487_spi_probe(struct spi_device *spi)
{
	struct iio_dev *indio_dev;
	struct max5487_data *data;
	const struct spi_device_id *id = spi_get_device_id(spi);
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	dev_set_drvdata(&spi->dev, indio_dev);
	data = iio_priv(indio_dev);

	data->spi = spi;
	data->kohms = id->driver_data;

	indio_dev->info = &max5487_info;
	indio_dev->name = id->name;
	indio_dev->dev.parent = &spi->dev;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = max5487_channels;
	indio_dev->num_channels = ARRAY_SIZE(max5487_channels);

	/* restore both wiper regs from NV regs */
	ret = max5487_write_cmd(data->spi, MAX5487_COPY_NV_TO_AB);
	if (ret < 0)
		return ret;

	return iio_device_register(indio_dev);
}

__attribute__((used)) static int max5487_spi_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = dev_get_drvdata(&spi->dev);

	iio_device_unregister(indio_dev);

	/* save both wiper regs to NV regs */
	return max5487_write_cmd(spi, MAX5487_COPY_AB_TO_NV);
}

