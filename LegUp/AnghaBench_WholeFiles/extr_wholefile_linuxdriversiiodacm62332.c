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
struct m62332_data {int* raw; int /*<<< orphan*/  vcc; int /*<<< orphan*/  mutex; struct i2c_client* client; } ;
struct TYPE_4__ {TYPE_2__* parent; } ;
struct iio_dev {int num_channels; int* channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; TYPE_1__ dev; } ;
struct iio_chan_spec {size_t channel; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  platform_data; } ;
struct i2c_client {TYPE_2__ dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_OFFSET 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_2__*,int) ; 
 int /*<<< orphan*/  devm_regulator_get (TYPE_2__*,char*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int iio_map_array_register (struct iio_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_map_array_unregister (struct iio_dev*) ; 
 struct m62332_data* iio_priv (struct iio_dev*) ; 
 int* m62332_channels ; 
 int /*<<< orphan*/  m62332_info ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int regulator_get_voltage (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int m62332_set_value(struct iio_dev *indio_dev, u8 val, int channel)
{
	struct m62332_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;
	u8 outbuf[2];
	int res;

	if (val == data->raw[channel])
		return 0;

	outbuf[0] = channel;
	outbuf[1] = val;

	mutex_lock(&data->mutex);

	if (val) {
		res = regulator_enable(data->vcc);
		if (res)
			goto out;
	}

	res = i2c_master_send(client, outbuf, ARRAY_SIZE(outbuf));
	if (res >= 0 && res != ARRAY_SIZE(outbuf))
		res = -EIO;
	if (res < 0)
		goto out;

	data->raw[channel] = val;

	if (!val)
		regulator_disable(data->vcc);

	mutex_unlock(&data->mutex);

	return 0;

out:
	mutex_unlock(&data->mutex);

	return res;
}

__attribute__((used)) static int m62332_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val,
			   int *val2,
			   long mask)
{
	struct m62332_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_SCALE:
		/* Corresponds to Vref / 2^(bits) */
		ret = regulator_get_voltage(data->vcc);
		if (ret < 0)
			return ret;

		*val = ret / 1000; /* mV */
		*val2 = 8;

		return IIO_VAL_FRACTIONAL_LOG2;
	case IIO_CHAN_INFO_RAW:
		*val = data->raw[chan->channel];

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_OFFSET:
		*val = 1;

		return IIO_VAL_INT;
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int m62332_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan, int val, int val2,
			    long mask)
{
	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val < 0 || val > 255)
			return -EINVAL;

		return m62332_set_value(indio_dev, val, chan->channel);
	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int m62332_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct m62332_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	mutex_init(&data->mutex);

	data->vcc = devm_regulator_get(&client->dev, "VCC");
	if (IS_ERR(data->vcc))
		return PTR_ERR(data->vcc);

	/* establish that the iio_dev is a child of the i2c device */
	indio_dev->dev.parent = &client->dev;

	indio_dev->num_channels = ARRAY_SIZE(m62332_channels);
	indio_dev->channels = m62332_channels;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &m62332_info;

	ret = iio_map_array_register(indio_dev, client->dev.platform_data);
	if (ret < 0)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret < 0)
		goto err;

	return 0;

err:
	iio_map_array_unregister(indio_dev);

	return ret;
}

__attribute__((used)) static int m62332_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);
	iio_map_array_unregister(indio_dev);
	m62332_set_value(indio_dev, 0, 0);
	m62332_set_value(indio_dev, 0, 1);

	return 0;
}

