#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct spi_device_id {size_t driver_data; int /*<<< orphan*/  name; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;
struct of_device_id {int dummy; } ;
struct max5481_data {int* msg; TYPE_2__* cfg; struct spi_device* spi; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
struct iio_chan_spec {int dummy; } ;
struct TYPE_5__ {int kohms; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 long IIO_CHAN_INFO_RAW ; 
 long IIO_CHAN_INFO_SCALE ; 
 int IIO_VAL_FRACTIONAL ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
#define  MAX5481_COPY_AB_TO_NV 130 
#define  MAX5481_COPY_NV_TO_AB 129 
 int MAX5481_MAX_POS ; 
#define  MAX5481_WRITE_WIPER 128 
 struct iio_dev* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct iio_dev*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct max5481_data* iio_priv (struct iio_dev*) ; 
 TYPE_2__* max5481_cfg ; 
 int /*<<< orphan*/  max5481_channels ; 
 int /*<<< orphan*/  max5481_info ; 
 int /*<<< orphan*/  max5481_match ; 
 TYPE_2__* of_device_get_match_data (int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 
 int spi_write (struct spi_device*,int*,int) ; 

__attribute__((used)) static int max5481_write_cmd(struct max5481_data *data, u8 cmd, u16 val)
{
	struct spi_device *spi = data->spi;

	data->msg[0] = cmd;

	switch (cmd) {
	case MAX5481_WRITE_WIPER:
		data->msg[1] = val >> 2;
		data->msg[2] = (val & 0x3) << 6;
		return spi_write(spi, data->msg, 3);

	case MAX5481_COPY_AB_TO_NV:
	case MAX5481_COPY_NV_TO_AB:
		return spi_write(spi, data->msg, 1);

	default:
		return -EIO;
	}
}

__attribute__((used)) static int max5481_read_raw(struct iio_dev *indio_dev,
		struct iio_chan_spec const *chan,
		int *val, int *val2, long mask)
{
	struct max5481_data *data = iio_priv(indio_dev);

	if (mask != IIO_CHAN_INFO_SCALE)
		return -EINVAL;

	*val = 1000 * data->cfg->kohms;
	*val2 = MAX5481_MAX_POS;

	return IIO_VAL_FRACTIONAL;
}

__attribute__((used)) static int max5481_write_raw(struct iio_dev *indio_dev,
		struct iio_chan_spec const *chan,
		int val, int val2, long mask)
{
	struct max5481_data *data = iio_priv(indio_dev);

	if (mask != IIO_CHAN_INFO_RAW)
		return -EINVAL;

	if (val < 0 || val > MAX5481_MAX_POS)
		return -EINVAL;

	return max5481_write_cmd(data, MAX5481_WRITE_WIPER, val);
}

__attribute__((used)) static int max5481_probe(struct spi_device *spi)
{
	struct iio_dev *indio_dev;
	struct max5481_data *data;
	const struct spi_device_id *id = spi_get_device_id(spi);
	const struct of_device_id *match;
	int ret;

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	dev_set_drvdata(&spi->dev, indio_dev);
	data = iio_priv(indio_dev);

	data->spi = spi;

	match = of_match_device(of_match_ptr(max5481_match), &spi->dev);
	if (match)
		data->cfg = of_device_get_match_data(&spi->dev);
	else
		data->cfg = &max5481_cfg[id->driver_data];

	indio_dev->name = id->name;
	indio_dev->dev.parent = &spi->dev;
	indio_dev->modes = INDIO_DIRECT_MODE;

	/* variant specific configuration */
	indio_dev->info = &max5481_info;
	indio_dev->channels = max5481_channels;
	indio_dev->num_channels = ARRAY_SIZE(max5481_channels);

	/* restore wiper from NV */
	ret = max5481_write_cmd(data, MAX5481_COPY_NV_TO_AB, 0);
	if (ret < 0)
		return ret;

	return iio_device_register(indio_dev);
}

__attribute__((used)) static int max5481_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = dev_get_drvdata(&spi->dev);
	struct max5481_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	/* save wiper reg to NV reg */
	return max5481_write_cmd(data, MAX5481_COPY_AB_TO_NV, 0);
}

