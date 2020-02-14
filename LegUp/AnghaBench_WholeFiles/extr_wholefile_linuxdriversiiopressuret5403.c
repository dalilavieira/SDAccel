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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct t5403_data {int mode; scalar_t__ c; struct i2c_client* client; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int* channels; int num_channels; int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; } ;
struct iio_chan_spec {int /*<<< orphan*/  type; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
typedef  int s32 ;
typedef  int s16 ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
#define  IIO_CHAN_INFO_INT_TIME 131 
#define  IIO_CHAN_INFO_PROCESSED 130 
#define  IIO_PRESSURE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int T5403_C (int) ; 
 int /*<<< orphan*/  T5403_CALIB_DATA ; 
 int /*<<< orphan*/  T5403_COMMAND ; 
 int T5403_C_U16 (int) ; 
 int /*<<< orphan*/  T5403_DATA ; 
 int T5403_I2C_ADDR ; 
 int T5403_I2C_MASK ; 
 int T5403_MODE_SHIFT ; 
 int T5403_MODE_STANDARD ; 
 int T5403_PT ; 
 int T5403_SCO ; 
 int /*<<< orphan*/  T5403_SLAVE_ADDR ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 struct t5403_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int* t5403_channels ; 
 int /*<<< orphan*/  t5403_info ; 
 int* t5403_pressure_conv_ms ; 

__attribute__((used)) static int t5403_read(struct t5403_data *data, bool pressure)
{
	int wait_time = 3;  /* wakeup time in ms */

	int ret = i2c_smbus_write_byte_data(data->client, T5403_COMMAND,
		(pressure ? (data->mode << T5403_MODE_SHIFT) : T5403_PT) |
		T5403_SCO);
	if (ret < 0)
		return ret;

	wait_time += pressure ? t5403_pressure_conv_ms[data->mode] : 2;

	msleep(wait_time);

	return i2c_smbus_read_word_data(data->client, T5403_DATA);
}

__attribute__((used)) static int t5403_comp_pressure(struct t5403_data *data, int *val, int *val2)
{
	int ret;
	s16 t_r;
	u16 p_r;
	s32 S, O, X;

	mutex_lock(&data->lock);

	ret = t5403_read(data, false);
	if (ret < 0)
		goto done;
	t_r = ret;

	ret = t5403_read(data, true);
	if (ret < 0)
		goto done;
	p_r = ret;

	/* see EPCOS application note */
	S = T5403_C_U16(3) + (s32) T5403_C_U16(4) * t_r / 0x20000 +
		T5403_C(5) * t_r / 0x8000 * t_r / 0x80000 +
		T5403_C(9) * t_r / 0x8000 * t_r / 0x8000 * t_r / 0x10000;

	O = T5403_C(6) * 0x4000 + T5403_C(7) * t_r / 8 +
		T5403_C(8) * t_r / 0x8000 * t_r / 16 +
		T5403_C(9) * t_r / 0x8000 * t_r / 0x10000 * t_r;

	X = (S * p_r + O) / 0x4000;

	X += ((X - 75000) * (X - 75000) / 0x10000 - 9537) *
	    T5403_C(10) / 0x10000;

	*val = X / 1000;
	*val2 = (X % 1000) * 1000;

done:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int t5403_comp_temp(struct t5403_data *data, int *val)
{
	int ret;
	s16 t_r;

	mutex_lock(&data->lock);
	ret = t5403_read(data, false);
	if (ret < 0)
		goto done;
	t_r = ret;

	/* see EPCOS application note */
	*val = ((s32) T5403_C_U16(1) * t_r / 0x100 +
		(s32) T5403_C_U16(2) * 0x40) * 1000 / 0x10000;

done:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int t5403_read_raw(struct iio_dev *indio_dev,
			  struct iio_chan_spec const *chan,
			  int *val, int *val2, long mask)
{
	struct t5403_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_PROCESSED:
		switch (chan->type) {
		case IIO_PRESSURE:
			ret = t5403_comp_pressure(data, val, val2);
			if (ret < 0)
				return ret;
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_TEMP:
			ret = t5403_comp_temp(data, val);
			if (ret < 0)
				return ret;
			return IIO_VAL_INT;
		default:
			return -EINVAL;
	    }
	case IIO_CHAN_INFO_INT_TIME:
		*val = 0;
		*val2 = t5403_pressure_conv_ms[data->mode] * 1000;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int t5403_write_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int val, int val2, long mask)
{
	struct t5403_data *data = iio_priv(indio_dev);
	int i;

	switch (mask) {
	case IIO_CHAN_INFO_INT_TIME:
		if (val != 0)
			return -EINVAL;
		for (i = 0; i < ARRAY_SIZE(t5403_pressure_conv_ms); i++)
			if (val2 == t5403_pressure_conv_ms[i] * 1000) {
				mutex_lock(&data->lock);
				data->mode = i;
				mutex_unlock(&data->lock);
				return 0;
			}
		return -EINVAL;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int t5403_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct t5403_data *data;
	struct iio_dev *indio_dev;
	int ret;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA |
	    I2C_FUNC_SMBUS_I2C_BLOCK))
		return -EOPNOTSUPP;

	ret = i2c_smbus_read_byte_data(client, T5403_SLAVE_ADDR);
	if (ret < 0)
		return ret;
	if ((ret & T5403_I2C_MASK) != T5403_I2C_ADDR)
		return -ENODEV;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	i2c_set_clientdata(client, indio_dev);
	indio_dev->info = &t5403_info;
	indio_dev->name = id->name;
	indio_dev->dev.parent = &client->dev;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = t5403_channels;
	indio_dev->num_channels = ARRAY_SIZE(t5403_channels);

	data->mode = T5403_MODE_STANDARD;

	ret = i2c_smbus_read_i2c_block_data(data->client, T5403_CALIB_DATA,
	    sizeof(data->c), (u8 *) data->c);
	if (ret < 0)
		return ret;

	return devm_iio_device_register(&client->dev, indio_dev);
}

