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
typedef  int u8 ;
struct TYPE_3__ {struct device* parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  name; int /*<<< orphan*/  channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int channel; } ;
struct i2c_device_id {size_t driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
struct ds1803_data {TYPE_2__* cfg; struct i2c_client* client; } ;
struct TYPE_4__ {int kohms; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int DS1803_MAX_POS ; 
 int /*<<< orphan*/  DS1803_WRITE (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 TYPE_2__* ds1803_cfg ; 
 int /*<<< orphan*/  ds1803_channels ; 
 int /*<<< orphan*/  ds1803_info ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 struct ds1803_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int ds1803_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct ds1803_data *data = iio_priv(indio_dev);
	int pot = chan->channel;
	int ret;
	u8 result[ARRAY_SIZE(ds1803_channels)];

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = i2c_master_recv(data->client, result,
				indio_dev->num_channels);
		if (ret < 0)
			return ret;

		*val = result[pot];
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		*val = 1000 * data->cfg->kohms;
		*val2 = DS1803_MAX_POS;
		return IIO_VAL_FRACTIONAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int ds1803_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct ds1803_data *data = iio_priv(indio_dev);
	int pot = chan->channel;

	if (val2 != 0)
		return -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val > DS1803_MAX_POS || val < 0)
			return -EINVAL;
		break;
	default:
		return -EINVAL;
	}

	return i2c_smbus_write_byte_data(data->client, DS1803_WRITE(pot), val);
}

__attribute__((used)) static int ds1803_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct ds1803_data *data;
	struct iio_dev *indio_dev;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	i2c_set_clientdata(client, indio_dev);

	data = iio_priv(indio_dev);
	data->client = client;
	data->cfg = &ds1803_cfg[id->driver_data];

	indio_dev->dev.parent = dev;
	indio_dev->info = &ds1803_info;
	indio_dev->channels = ds1803_channels;
	indio_dev->num_channels = ARRAY_SIZE(ds1803_channels);
	indio_dev->name = client->name;

	return devm_iio_device_register(dev, indio_dev);
}

