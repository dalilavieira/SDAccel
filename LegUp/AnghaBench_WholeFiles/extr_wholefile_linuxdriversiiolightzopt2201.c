#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct zopt2201_data {size_t res; size_t gain; int rate; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct TYPE_9__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_2__* channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int address; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_12__ {int scale; } ;
struct TYPE_11__ {int gain; int scale; } ;
struct TYPE_10__ {unsigned long us; int res; int gain; int scale; int uscale; int /*<<< orphan*/  bits; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_2__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_READ_I2C_BLOCK ; 
#define  IIO_CHAN_INFO_INT_TIME 133 
#define  IIO_CHAN_INFO_PROCESSED 132 
#define  IIO_CHAN_INFO_RAW 131 
#define  IIO_CHAN_INFO_SCALE 130 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ PAGE_SIZE ; 
#define  ZOPT2201_ALS_DATA 129 
 int /*<<< orphan*/  ZOPT2201_DRV_NAME ; 
 int /*<<< orphan*/  ZOPT2201_LS_GAIN ; 
 int ZOPT2201_LS_GAIN_3 ; 
 int /*<<< orphan*/  ZOPT2201_LS_MEAS_RATE ; 
 int /*<<< orphan*/  ZOPT2201_MAIN_CTRL ; 
 int ZOPT2201_MAIN_CTRL_LS_EN ; 
 int ZOPT2201_MAIN_CTRL_LS_MODE ; 
 int /*<<< orphan*/  ZOPT2201_MAIN_STATUS ; 
 int ZOPT2201_MAIN_STATUS_DRDY ; 
 int ZOPT2201_MEAS_FREQ_100MS ; 
 int ZOPT2201_MEAS_RES_18BIT ; 
 int ZOPT2201_MEAS_RES_SHIFT ; 
 int /*<<< orphan*/  ZOPT2201_PART_ID ; 
 int ZOPT2201_PART_NUMBER ; 
#define  ZOPT2201_UVB_DATA 128 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  div_s64 (int,int) ; 
 int div_s64_rem (int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int,int,int*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 struct zopt2201_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  msleep (unsigned long) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ scnprintf (char*,scalar_t__,char*,int,...) ; 
 int /*<<< orphan*/  usleep_range (unsigned long,unsigned long) ; 
 TYPE_2__* zopt2201_channels ; 
 TYPE_6__* zopt2201_gain_als ; 
 TYPE_5__* zopt2201_gain_uvb ; 
 int /*<<< orphan*/  zopt2201_info ; 
 TYPE_2__* zopt2201_resolution ; 
 TYPE_2__* zopt2201_scale_als ; 
 TYPE_2__* zopt2201_scale_uvb ; 

__attribute__((used)) static int zopt2201_enable_mode(struct zopt2201_data *data, bool uvb_mode)
{
	u8 out = ZOPT2201_MAIN_CTRL_LS_EN;

	if (uvb_mode)
		out |= ZOPT2201_MAIN_CTRL_LS_MODE;

	return i2c_smbus_write_byte_data(data->client, ZOPT2201_MAIN_CTRL, out);
}

__attribute__((used)) static int zopt2201_read(struct zopt2201_data *data, u8 reg)
{
	struct i2c_client *client = data->client;
	int tries = 10;
	u8 buf[3];
	int ret;

	mutex_lock(&data->lock);
	ret = zopt2201_enable_mode(data, reg == ZOPT2201_UVB_DATA);
	if (ret < 0)
		goto fail;

	while (tries--) {
		unsigned long t = zopt2201_resolution[data->res].us;

		if (t <= 20000)
			usleep_range(t, t + 1000);
		else
			msleep(t / 1000);
		ret = i2c_smbus_read_byte_data(client, ZOPT2201_MAIN_STATUS);
		if (ret < 0)
			goto fail;
		if (ret & ZOPT2201_MAIN_STATUS_DRDY)
			break;
	}

	if (tries < 0) {
		ret = -ETIMEDOUT;
		goto fail;
	}

	ret = i2c_smbus_read_i2c_block_data(client, reg, sizeof(buf), buf);
	if (ret < 0)
		goto fail;

	ret = i2c_smbus_write_byte_data(client, ZOPT2201_MAIN_CTRL, 0x00);
	if (ret < 0)
		goto fail;
	mutex_unlock(&data->lock);

	return (buf[2] << 16) | (buf[1] << 8) | buf[0];

fail:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int zopt2201_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct zopt2201_data *data = iio_priv(indio_dev);
	u64 tmp;
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = zopt2201_read(data, chan->address);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_PROCESSED:
		ret = zopt2201_read(data, ZOPT2201_UVB_DATA);
		if (ret < 0)
			return ret;
		*val = ret * 18 *
			(1 << (20 - zopt2201_resolution[data->res].bits)) /
			zopt2201_gain_uvb[data->gain].gain;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		switch (chan->address) {
		case ZOPT2201_ALS_DATA:
			*val = zopt2201_gain_als[data->gain].scale;
			break;
		case ZOPT2201_UVB_DATA:
			*val = zopt2201_gain_uvb[data->gain].scale;
			break;
		default:
			return -EINVAL;
		}

		*val2 = 1000000;
		*val2 *= (1 << (zopt2201_resolution[data->res].bits - 13));
		tmp = div_s64(*val * 1000000ULL, *val2);
		*val = div_s64_rem(tmp, 1000000, val2);

		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_INT_TIME:
		*val = 0;
		*val2 = zopt2201_resolution[data->res].us;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int zopt2201_set_resolution(struct zopt2201_data *data, u8 res)
{
	int ret;

	ret = i2c_smbus_write_byte_data(data->client, ZOPT2201_LS_MEAS_RATE,
					(res << ZOPT2201_MEAS_RES_SHIFT) |
					data->rate);
	if (ret < 0)
		return ret;

	data->res = res;

	return 0;
}

__attribute__((used)) static int zopt2201_write_resolution(struct zopt2201_data *data,
				     int val, int val2)
{
	int i, ret;

	if (val != 0)
		return -EINVAL;

	for (i = 0; i < ARRAY_SIZE(zopt2201_resolution); i++)
		if (val2 == zopt2201_resolution[i].us) {
			mutex_lock(&data->lock);
			ret = zopt2201_set_resolution(data, i);
			mutex_unlock(&data->lock);
			return ret;
		}

	return -EINVAL;
}

__attribute__((used)) static int zopt2201_set_gain(struct zopt2201_data *data, u8 gain)
{
	int ret;

	ret = i2c_smbus_write_byte_data(data->client, ZOPT2201_LS_GAIN, gain);
	if (ret < 0)
		return ret;

	data->gain = gain;

	return 0;
}

__attribute__((used)) static int zopt2201_write_scale_als_by_idx(struct zopt2201_data *data, int idx)
{
	int ret;

	mutex_lock(&data->lock);
	ret = zopt2201_set_resolution(data, zopt2201_scale_als[idx].res);
	if (ret < 0)
		goto unlock;

	ret = zopt2201_set_gain(data, zopt2201_scale_als[idx].gain);

unlock:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int zopt2201_write_scale_als(struct zopt2201_data *data,
				     int val, int val2)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(zopt2201_scale_als); i++)
		if (val == zopt2201_scale_als[i].scale &&
		    val2 == zopt2201_scale_als[i].uscale) {
			return zopt2201_write_scale_als_by_idx(data, i);
		}

	return -EINVAL;
}

__attribute__((used)) static int zopt2201_write_scale_uvb_by_idx(struct zopt2201_data *data, int idx)
{
	int ret;

	mutex_lock(&data->lock);
	ret = zopt2201_set_resolution(data, zopt2201_scale_als[idx].res);
	if (ret < 0)
		goto unlock;

	ret = zopt2201_set_gain(data, zopt2201_scale_als[idx].gain);

unlock:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int zopt2201_write_scale_uvb(struct zopt2201_data *data,
				     int val, int val2)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(zopt2201_scale_uvb); i++)
		if (val == zopt2201_scale_uvb[i].scale &&
		    val2 == zopt2201_scale_uvb[i].uscale)
			return zopt2201_write_scale_uvb_by_idx(data, i);

	return -EINVAL;
}

__attribute__((used)) static int zopt2201_write_raw(struct iio_dev *indio_dev,
			      struct iio_chan_spec const *chan,
			      int val, int val2, long mask)
{
	struct zopt2201_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_INT_TIME:
		return zopt2201_write_resolution(data, val, val2);
	case IIO_CHAN_INFO_SCALE:
		switch (chan->address) {
		case ZOPT2201_ALS_DATA:
			return zopt2201_write_scale_als(data, val, val2);
		case ZOPT2201_UVB_DATA:
			return zopt2201_write_scale_uvb(data, val, val2);
		default:
			return -EINVAL;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static ssize_t zopt2201_show_int_time_available(struct device *dev,
						struct device_attribute *attr,
						char *buf)
{
	size_t len = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(zopt2201_resolution); i++)
		len += scnprintf(buf + len, PAGE_SIZE - len, "0.%06lu ",
				 zopt2201_resolution[i].us);
	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static ssize_t zopt2201_show_als_scale_avail(struct device *dev,
					     struct device_attribute *attr,
					     char *buf)
{
	ssize_t len = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(zopt2201_scale_als); i++)
		len += scnprintf(buf + len, PAGE_SIZE - len, "%d.%06u ",
				 zopt2201_scale_als[i].scale,
				 zopt2201_scale_als[i].uscale);
	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static ssize_t zopt2201_show_uvb_scale_avail(struct device *dev,
					     struct device_attribute *attr,
					     char *buf)
{
	ssize_t len = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(zopt2201_scale_uvb); i++)
		len += scnprintf(buf + len, PAGE_SIZE - len, "%d.%06u ",
				 zopt2201_scale_uvb[i].scale,
				 zopt2201_scale_uvb[i].uscale);
	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static int zopt2201_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct zopt2201_data *data;
	struct iio_dev *indio_dev;
	int ret;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_READ_I2C_BLOCK))
		return -EOPNOTSUPP;

	ret = i2c_smbus_read_byte_data(client, ZOPT2201_PART_ID);
	if (ret < 0)
		return ret;
	if (ret != ZOPT2201_PART_NUMBER)
		return -ENODEV;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &zopt2201_info;
	indio_dev->channels = zopt2201_channels;
	indio_dev->num_channels = ARRAY_SIZE(zopt2201_channels);
	indio_dev->name = ZOPT2201_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;

	data->rate = ZOPT2201_MEAS_FREQ_100MS;
	ret = zopt2201_set_resolution(data, ZOPT2201_MEAS_RES_18BIT);
	if (ret < 0)
		return ret;

	ret = zopt2201_set_gain(data, ZOPT2201_LS_GAIN_3);
	if (ret < 0)
		return ret;

	return devm_iio_device_register(&client->dev, indio_dev);
}

