#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct TYPE_5__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  modes; TYPE_2__* channels; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  address; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct cm3323_data {int reg_conf; int /*<<< orphan*/  mutex; struct i2c_client* client; } ;
struct TYPE_6__ {int val; int val2; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int /*<<< orphan*/  CM3323_CMD_CONF ; 
 int CM3323_CONF_AF_BIT ; 
 int CM3323_CONF_IT_MASK ; 
 int CM3323_CONF_IT_SHIFT ; 
 int CM3323_CONF_SD_BIT ; 
 int /*<<< orphan*/  CM3323_DRV_NAME ; 
 int EINVAL ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_INT_TIME 129 
#define  IIO_CHAN_INFO_RAW 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 TYPE_2__* cm3323_channels ; 
 int /*<<< orphan*/  cm3323_info ; 
 TYPE_2__* cm3323_int_time ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_word_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct cm3323_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int cm3323_init(struct iio_dev *indio_dev)
{
	int ret;
	struct cm3323_data *data = iio_priv(indio_dev);

	ret = i2c_smbus_read_word_data(data->client, CM3323_CMD_CONF);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error reading reg_conf\n");
		return ret;
	}

	/* enable sensor and set auto force mode */
	ret &= ~(CM3323_CONF_SD_BIT | CM3323_CONF_AF_BIT);

	ret = i2c_smbus_write_word_data(data->client, CM3323_CMD_CONF, ret);
	if (ret < 0) {
		dev_err(&data->client->dev, "Error writing reg_conf\n");
		return ret;
	}

	data->reg_conf = ret;

	return 0;
}

__attribute__((used)) static void cm3323_disable(struct iio_dev *indio_dev)
{
	int ret;
	struct cm3323_data *data = iio_priv(indio_dev);

	ret = i2c_smbus_write_word_data(data->client, CM3323_CMD_CONF,
					CM3323_CONF_SD_BIT);
	if (ret < 0)
		dev_err(&data->client->dev, "Error writing reg_conf\n");
}

__attribute__((used)) static int cm3323_set_it_bits(struct cm3323_data *data, int val, int val2)
{
	int i, ret;
	u16 reg_conf;

	for (i = 0; i < ARRAY_SIZE(cm3323_int_time); i++) {
		if (val == cm3323_int_time[i].val &&
		    val2 == cm3323_int_time[i].val2) {
			reg_conf = data->reg_conf & ~CM3323_CONF_IT_MASK;
			reg_conf |= i << CM3323_CONF_IT_SHIFT;

			ret = i2c_smbus_write_word_data(data->client,
							CM3323_CMD_CONF,
							reg_conf);
			if (ret < 0)
				return ret;

			data->reg_conf = reg_conf;

			return 0;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static int cm3323_get_it_bits(struct cm3323_data *data)
{
	int bits;

	bits = (data->reg_conf & CM3323_CONF_IT_MASK) >>
		CM3323_CONF_IT_SHIFT;

	if (bits >= ARRAY_SIZE(cm3323_int_time))
		return -EINVAL;

	return bits;
}

__attribute__((used)) static int cm3323_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan, int *val,
			   int *val2, long mask)
{
	int ret;
	struct cm3323_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		mutex_lock(&data->mutex);
		ret = i2c_smbus_read_word_data(data->client, chan->address);
		if (ret < 0) {
			mutex_unlock(&data->mutex);
			return ret;
		}
		*val = ret;
		mutex_unlock(&data->mutex);

		return IIO_VAL_INT;
	case IIO_CHAN_INFO_INT_TIME:
		mutex_lock(&data->mutex);
		ret = cm3323_get_it_bits(data);
		if (ret < 0) {
			mutex_unlock(&data->mutex);
			return ret;
		}

		*val = cm3323_int_time[ret].val;
		*val2 = cm3323_int_time[ret].val2;
		mutex_unlock(&data->mutex);

		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int cm3323_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan, int val,
			    int val2, long mask)
{
	struct cm3323_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_INT_TIME:
		mutex_lock(&data->mutex);
		ret = cm3323_set_it_bits(data, val, val2);
		mutex_unlock(&data->mutex);

		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int cm3323_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct cm3323_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	mutex_init(&data->mutex);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &cm3323_info;
	indio_dev->name = CM3323_DRV_NAME;
	indio_dev->channels = cm3323_channels;
	indio_dev->num_channels = ARRAY_SIZE(cm3323_channels);
	indio_dev->modes = INDIO_DIRECT_MODE;

	ret = cm3323_init(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "cm3323 chip init failed\n");
		return ret;
	}

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "failed to register iio dev\n");
		goto err_init;
	}

	return 0;
err_init:
	cm3323_disable(indio_dev);
	return ret;
}

__attribute__((used)) static int cm3323_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);
	cm3323_disable(indio_dev);

	return 0;
}

