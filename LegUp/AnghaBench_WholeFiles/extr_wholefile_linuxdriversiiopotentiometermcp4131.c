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
struct spi_transfer {void* tx_buf; void* rx_buf; size_t len; } ;
struct spi_message {int dummy; } ;
struct device {int dummy; } ;
struct spi_device {struct device dev; } ;
struct mcp4131_data {int* buf; TYPE_3__* cfg; int /*<<< orphan*/  lock; struct spi_device* spi; } ;
struct TYPE_4__ {struct device* parent; } ;
struct iio_dev {int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int channel; } ;
struct TYPE_6__ {int kohms; int max_pos; int /*<<< orphan*/  wipers; } ;
struct TYPE_5__ {unsigned long driver_data; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  MCP4131_CMDERR (int*) ; 
 int MCP4131_RAW (int*) ; 
 int MCP4131_READ ; 
 int MCP4131_WIPER_SHIFT ; 
 int MCP4131_WRITE ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 struct mcp4131_data* iio_priv (struct iio_dev*) ; 
 TYPE_3__* mcp4131_cfg ; 
 int /*<<< orphan*/  mcp4131_channels ; 
 int /*<<< orphan*/  mcp4131_info ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_2__* spi_get_device_id (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_add_tail (struct spi_transfer*,struct spi_message*) ; 
 int /*<<< orphan*/  spi_message_init (struct spi_message*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_sync (struct spi_device*,struct spi_message*) ; 
 int spi_write (struct spi_device*,int*,int) ; 

__attribute__((used)) static int mcp4131_read(struct spi_device *spi, void *buf, size_t len)
{
	struct spi_transfer t = {
		.tx_buf = buf, /* We need to send addr, cmd and 12 bits */
		.rx_buf	= buf,
		.len = len,
	};
	struct spi_message m;

	spi_message_init(&m);
	spi_message_add_tail(&t, &m);

	return spi_sync(spi, &m);
}

__attribute__((used)) static int mcp4131_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	int err;
	struct mcp4131_data *data = iio_priv(indio_dev);
	int address = chan->channel;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&data->lock);

		data->buf[0] = (address << MCP4131_WIPER_SHIFT) | MCP4131_READ;
		data->buf[1] = 0;

		err = mcp4131_read(data->spi, data->buf, 2);
		if (err) {
			mutex_unlock(&data->lock);
			return err;
		}

		/* Error, bad address/command combination */
		if (!MCP4131_CMDERR(data->buf)) {
			mutex_unlock(&data->lock);
			return -EIO;
		}

		*val = MCP4131_RAW(data->buf);
		mutex_unlock(&data->lock);

		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		*val = 1000 * data->cfg->kohms;
		*val2 = data->cfg->max_pos;
		return IIO_VAL_FRACTIONAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int mcp4131_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	int err;
	struct mcp4131_data *data = iio_priv(indio_dev);
	int address = chan->channel << MCP4131_WIPER_SHIFT;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val > data->cfg->max_pos || val < 0)
			return -EINVAL;
		break;

	default:
		return -EINVAL;
	}

	mutex_lock(&data->lock);

	data->buf[0] = address << MCP4131_WIPER_SHIFT;
	data->buf[0] |= MCP4131_WRITE | (val >> 8);
	data->buf[1] = val & 0xFF; /* 8 bits here */

	err = spi_write(data->spi, data->buf, 2);
	mutex_unlock(&data->lock);

	return err;
}

__attribute__((used)) static int mcp4131_probe(struct spi_device *spi)
{
	int err;
	struct device *dev = &spi->dev;
	unsigned long devid = spi_get_device_id(spi)->driver_data;
	struct mcp4131_data *data;
	struct iio_dev *indio_dev;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	spi_set_drvdata(spi, indio_dev);
	data->spi = spi;
	data->cfg = &mcp4131_cfg[devid];

	mutex_init(&data->lock);

	indio_dev->dev.parent = dev;
	indio_dev->info = &mcp4131_info;
	indio_dev->channels = mcp4131_channels;
	indio_dev->num_channels = data->cfg->wipers;
	indio_dev->name = spi_get_device_id(spi)->name;

	err = devm_iio_device_register(dev, indio_dev);
	if (err) {
		dev_info(&spi->dev, "Unable to register %s\n", indio_dev->name);
		return err;
	}

	return 0;
}

