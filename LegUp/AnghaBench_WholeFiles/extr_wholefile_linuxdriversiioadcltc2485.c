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
struct ltc2485_data {void* time_prev; struct i2c_client* client; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
typedef  scalar_t__ __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE ; 
 long IIO_CHAN_INFO_RAW ; 
 long IIO_CHAN_INFO_SCALE ; 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  LTC2485_CONFIG_DEFAULT ; 
 int be32_to_cpu (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int i2c_master_recv (struct i2c_client*,char*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 struct ltc2485_data* iio_priv (struct iio_dev*) ; 
 void* ktime_get () ; 
 unsigned int ktime_ms_delta (void*,void*) ; 
 int /*<<< orphan*/  ltc2485_channel ; 
 int /*<<< orphan*/  ltc2485_info ; 
 int /*<<< orphan*/  msleep (unsigned int const) ; 
 int sign_extend32 (int,int) ; 

__attribute__((used)) static void ltc2485_wait_conv(struct ltc2485_data *data)
{
	const unsigned int conv_time = 147;	/* conversion time ms */
	unsigned int time_elapsed;

	/* delay if conversion time not passed since last read or write */
	time_elapsed = ktime_ms_delta(ktime_get(), data->time_prev);

	if (time_elapsed < conv_time)
		msleep(conv_time - time_elapsed);
}

__attribute__((used)) static int ltc2485_read(struct ltc2485_data *data, int *val)
{
	struct i2c_client *client = data->client;
	__be32 buf = 0;
	int ret;

	ltc2485_wait_conv(data);

	ret = i2c_master_recv(client, (char *)&buf, 4);
	if (ret < 0)  {
		dev_err(&client->dev, "i2c_master_recv failed\n");
		return ret;
	}
	data->time_prev = ktime_get();
	*val = sign_extend32(be32_to_cpu(buf) >> 6, 24);

	return ret;
}

__attribute__((used)) static int ltc2485_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct ltc2485_data *data = iio_priv(indio_dev);
	int ret;

	if (mask == IIO_CHAN_INFO_RAW) {
		ret = ltc2485_read(data, val);
		if (ret < 0)
			return ret;

		return IIO_VAL_INT;

	} else if (mask == IIO_CHAN_INFO_SCALE) {
		*val = 5000;			/* on board vref millivolts */
		*val2 = 25;			/* 25 (24 + sign) data bits */
		return IIO_VAL_FRACTIONAL_LOG2;

	} else {
		return -EINVAL;
	}
}

__attribute__((used)) static int ltc2485_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct ltc2485_data *data;
	int ret;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C |
				     I2C_FUNC_SMBUS_WRITE_BYTE))
		return -EOPNOTSUPP;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	indio_dev->dev.parent = &client->dev;
	indio_dev->name = id->name;
	indio_dev->info = &ltc2485_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = ltc2485_channel;
	indio_dev->num_channels = ARRAY_SIZE(ltc2485_channel);

	ret = i2c_smbus_write_byte(data->client, LTC2485_CONFIG_DEFAULT);
	if (ret < 0)
		return ret;

	data->time_prev = ktime_get();

	return devm_iio_device_register(&client->dev, indio_dev);
}

