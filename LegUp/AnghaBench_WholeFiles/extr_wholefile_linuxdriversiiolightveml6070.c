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
typedef  int u8 ;
struct veml6070_data {int config; struct i2c_client* client2; struct i2c_client* client1; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {unsigned int* channels; int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned int*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_PROCESSED 129 
#define  IIO_CHAN_INFO_RAW 128 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  VEML6070_ADDR_DATA_LSB ; 
 int VEML6070_COMMAND_RSRVD ; 
 int VEML6070_COMMAND_SD ; 
 int /*<<< orphan*/  VEML6070_DRV_NAME ; 
 int VEML6070_IT_10 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 struct i2c_client* i2c_new_dummy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte (struct i2c_client*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int) ; 
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct veml6070_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned int* veml6070_channels ; 
 int /*<<< orphan*/  veml6070_info ; 

__attribute__((used)) static int veml6070_read(struct veml6070_data *data)
{
	int ret;
	u8 msb, lsb;

	mutex_lock(&data->lock);

	/* disable shutdown */
	ret = i2c_smbus_write_byte(data->client1,
	    data->config & ~VEML6070_COMMAND_SD);
	if (ret < 0)
		goto out;

	msleep(125 + 10); /* measurement takes up to 125 ms for IT 1x */

	ret = i2c_smbus_read_byte(data->client2); /* read MSB, address 0x39 */
	if (ret < 0)
		goto out;
	msb = ret;

	ret = i2c_smbus_read_byte(data->client1); /* read LSB, address 0x38 */
	if (ret < 0)
		goto out;
	lsb = ret;

	/* shutdown again */
	ret = i2c_smbus_write_byte(data->client1, data->config);
	if (ret < 0)
		goto out;

	ret = (msb << 8) | lsb;

out:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int veml6070_to_uv_index(unsigned val)
{
	/*
	 * conversion of raw UV intensity values to UV index depends on
	 * integration time (IT) and value of the resistor connected to
	 * the RSET pin (default: 270 KOhm)
	 */
	unsigned uvi[11] = {
		187, 373, 560, /* low */
		746, 933, 1120, /* moderate */
		1308, 1494, /* high */
		1681, 1868, 2054}; /* very high */
	int i;

	for (i = 0; i < ARRAY_SIZE(uvi); i++)
		if (val <= uvi[i])
			return i;

	return 11; /* extreme */
}

__attribute__((used)) static int veml6070_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct veml6070_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
	case IIO_CHAN_INFO_PROCESSED:
		ret = veml6070_read(data);
		if (ret < 0)
			return ret;
		if (mask == IIO_CHAN_INFO_PROCESSED)
			*val = veml6070_to_uv_index(ret);
		else
			*val = ret;
		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int veml6070_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct veml6070_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client1 = client;
	mutex_init(&data->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &veml6070_info;
	indio_dev->channels = veml6070_channels;
	indio_dev->num_channels = ARRAY_SIZE(veml6070_channels);
	indio_dev->name = VEML6070_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;

	data->client2 = i2c_new_dummy(client->adapter, VEML6070_ADDR_DATA_LSB);
	if (!data->client2) {
		dev_err(&client->dev, "i2c device for second chip address failed\n");
		return -ENODEV;
	}

	data->config = VEML6070_IT_10 | VEML6070_COMMAND_RSRVD |
		VEML6070_COMMAND_SD;
	ret = i2c_smbus_write_byte(data->client1, data->config);
	if (ret < 0)
		goto fail;

	ret = iio_device_register(indio_dev);
	if (ret < 0)
		goto fail;

	return ret;

fail:
	i2c_unregister_device(data->client2);
	return ret;
}

__attribute__((used)) static int veml6070_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct veml6070_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	i2c_unregister_device(data->client2);

	return 0;
}

