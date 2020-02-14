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
struct iio_dev {int num_channels; int /*<<< orphan*/  name; int /*<<< orphan*/ * channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_device_id {size_t driver_data; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; struct device dev; } ;
struct gpio_desc {int dummy; } ;
struct ad5272_data {int* buf; TYPE_2__* cfg; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct TYPE_4__ {int shift; int kohms; int max_pos; } ;

/* Variables and functions */
 int AD5272_CTL ; 
 int AD5272_RDAC_RD ; 
 int AD5272_RDAC_WR ; 
 int AD5272_RDAC_WR_EN ; 
 int AD5272_RESET ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 int PTR_ERR (struct gpio_desc*) ; 
 TYPE_2__* ad5272_cfg ; 
 int /*<<< orphan*/  ad5272_channel ; 
 int /*<<< orphan*/  ad5272_info ; 
 struct gpio_desc* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 int /*<<< orphan*/  gpiod_set_value (struct gpio_desc*,int) ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 struct ad5272_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int ad5272_write(struct ad5272_data *data, int reg, int val)
{
	int ret;

	data->buf[0] = (reg << 2) | ((val >> 8) & 0x3);
	data->buf[1] = (u8)val;

	mutex_lock(&data->lock);
	ret = i2c_master_send(data->client, data->buf, sizeof(data->buf));
	mutex_unlock(&data->lock);
	return ret < 0 ? ret : 0;
}

__attribute__((used)) static int ad5272_read(struct ad5272_data *data, int reg, int *val)
{
	int ret;

	data->buf[0] = reg << 2;
	data->buf[1] = 0;

	mutex_lock(&data->lock);
	ret = i2c_master_send(data->client, data->buf, sizeof(data->buf));
	if (ret < 0)
		goto error;

	ret = i2c_master_recv(data->client, data->buf, sizeof(data->buf));
	if (ret < 0)
		goto error;

	*val = ((data->buf[0] & 0x3) << 8) | data->buf[1];
	ret = 0;
error:
	mutex_unlock(&data->lock);
	return ret;
}

__attribute__((used)) static int ad5272_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	struct ad5272_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW: {
		ret = ad5272_read(data, AD5272_RDAC_RD, val);
		*val = *val >> data->cfg->shift;
		return ret ? ret : IIO_VAL_INT;
	}
	case IIO_CHAN_INFO_SCALE:
		*val = 1000 * data->cfg->kohms;
		*val2 = data->cfg->max_pos;
		return IIO_VAL_FRACTIONAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int ad5272_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int val, int val2, long mask)
{
	struct ad5272_data *data = iio_priv(indio_dev);

	if (mask != IIO_CHAN_INFO_RAW)
		return -EINVAL;

	if (val >= data->cfg->max_pos || val < 0 || val2)
		return -EINVAL;

	return ad5272_write(data, AD5272_RDAC_WR, val << data->cfg->shift);
}

__attribute__((used)) static int ad5272_reset(struct ad5272_data *data)
{
	struct gpio_desc *reset_gpio;

	reset_gpio = devm_gpiod_get_optional(&data->client->dev, "reset",
		GPIOD_OUT_LOW);
	if (IS_ERR(reset_gpio))
		return PTR_ERR(reset_gpio);

	if (reset_gpio) {
		udelay(1);
		gpiod_set_value(reset_gpio, 1);
	} else {
		ad5272_write(data, AD5272_RESET, 0);
	}
	usleep_range(1000, 2000);

	return 0;
}

__attribute__((used)) static int ad5272_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct iio_dev *indio_dev;
	struct ad5272_data *data;
	int ret;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	i2c_set_clientdata(client, indio_dev);

	data = iio_priv(indio_dev);
	data->client = client;
	mutex_init(&data->lock);
	data->cfg = &ad5272_cfg[id->driver_data];

	ret = ad5272_reset(data);
	if (ret)
		return ret;

	ret = ad5272_write(data, AD5272_CTL, AD5272_RDAC_WR_EN);
	if (ret < 0)
		return -ENODEV;

	indio_dev->dev.parent = dev;
	indio_dev->info = &ad5272_info;
	indio_dev->channels = &ad5272_channel;
	indio_dev->num_channels = 1;
	indio_dev->name = client->name;

	return devm_iio_device_register(dev, indio_dev);
}

