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
typedef  int /*<<< orphan*/  val ;
typedef  char u8 ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_3__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int* channels; int num_channels; int /*<<< orphan*/  available_scan_masks; int /*<<< orphan*/ * info; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/  trig; } ;
struct iio_chan_spec {size_t address; int /*<<< orphan*/  type; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct hdc100x_data {int config; int* adc_int_us; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
typedef  int /*<<< orphan*/  s16 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __be16 ;
struct TYPE_4__ {int shift; int mask; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  HDC100X_REG_CONFIG ; 
 int HDC100X_REG_CONFIG_ACQ_MODE ; 
 int HDC100X_REG_CONFIG_HEATER_EN ; 
 size_t HDC100X_REG_TEMP ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
#define  IIO_CHAN_INFO_INT_TIME 131 
#define  IIO_CHAN_INFO_OFFSET 130 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int /*<<< orphan*/  IIO_CURRENT ; 
 int /*<<< orphan*/  IIO_TEMP ; 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int* hdc100x_channels ; 
 int /*<<< orphan*/  hdc100x_info ; 
 int** hdc100x_int_time ; 
 TYPE_2__* hdc100x_resolution_shift ; 
 int /*<<< orphan*/  hdc100x_scan_masks ; 
 int /*<<< orphan*/  hdc_buffer_setup_ops ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_recv (struct i2c_client*,char*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,size_t) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_claim_direct_mode (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct hdc100x_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_postenable (struct iio_dev*) ; 
 int iio_triggered_buffer_predisable (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int hdc100x_update_config(struct hdc100x_data *data, int mask, int val)
{
	int tmp = (~mask & data->config) | val;
	int ret;

	ret = i2c_smbus_write_word_swapped(data->client,
						HDC100X_REG_CONFIG, tmp);
	if (!ret)
		data->config = tmp;

	return ret;
}

__attribute__((used)) static int hdc100x_set_it_time(struct hdc100x_data *data, int chan, int val2)
{
	int shift = hdc100x_resolution_shift[chan].shift;
	int ret = -EINVAL;
	int i;

	for (i = 0; i < ARRAY_SIZE(hdc100x_int_time[chan]); i++) {
		if (val2 && val2 == hdc100x_int_time[chan][i]) {
			ret = hdc100x_update_config(data,
				hdc100x_resolution_shift[chan].mask << shift,
				i << shift);
			if (!ret)
				data->adc_int_us[chan] = val2;
			break;
		}
	}

	return ret;
}

__attribute__((used)) static int hdc100x_get_measurement(struct hdc100x_data *data,
				   struct iio_chan_spec const *chan)
{
	struct i2c_client *client = data->client;
	int delay = data->adc_int_us[chan->address];
	int ret;
	__be16 val;

	/* start measurement */
	ret = i2c_smbus_write_byte(client, chan->address);
	if (ret < 0) {
		dev_err(&client->dev, "cannot start measurement");
		return ret;
	}

	/* wait for integration time to pass */
	usleep_range(delay, delay + 1000);

	/* read measurement */
	ret = i2c_master_recv(data->client, (char *)&val, sizeof(val));
	if (ret < 0) {
		dev_err(&client->dev, "cannot read sensor data\n");
		return ret;
	}
	return be16_to_cpu(val);
}

__attribute__((used)) static int hdc100x_get_heater_status(struct hdc100x_data *data)
{
	return !!(data->config & HDC100X_REG_CONFIG_HEATER_EN);
}

__attribute__((used)) static int hdc100x_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan, int *val,
			    int *val2, long mask)
{
	struct hdc100x_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW: {
		int ret;

		mutex_lock(&data->lock);
		if (chan->type == IIO_CURRENT) {
			*val = hdc100x_get_heater_status(data);
			ret = IIO_VAL_INT;
		} else {
			ret = iio_device_claim_direct_mode(indio_dev);
			if (ret) {
				mutex_unlock(&data->lock);
				return ret;
			}

			ret = hdc100x_get_measurement(data, chan);
			iio_device_release_direct_mode(indio_dev);
			if (ret >= 0) {
				*val = ret;
				ret = IIO_VAL_INT;
			}
		}
		mutex_unlock(&data->lock);
		return ret;
	}
	case IIO_CHAN_INFO_INT_TIME:
		*val = 0;
		*val2 = data->adc_int_us[chan->address];
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_SCALE:
		if (chan->type == IIO_TEMP) {
			*val = 165000;
			*val2 = 65536;
			return IIO_VAL_FRACTIONAL;
		} else {
			*val = 100;
			*val2 = 65536;
			return IIO_VAL_FRACTIONAL;
		}
		break;
	case IIO_CHAN_INFO_OFFSET:
		*val = -15887;
		*val2 = 515151;
		return IIO_VAL_INT_PLUS_MICRO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int hdc100x_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct hdc100x_data *data = iio_priv(indio_dev);
	int ret = -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_INT_TIME:
		if (val != 0)
			return -EINVAL;

		mutex_lock(&data->lock);
		ret = hdc100x_set_it_time(data, chan->address, val2);
		mutex_unlock(&data->lock);
		return ret;
	case IIO_CHAN_INFO_RAW:
		if (chan->type != IIO_CURRENT || val2 != 0)
			return -EINVAL;

		mutex_lock(&data->lock);
		ret = hdc100x_update_config(data, HDC100X_REG_CONFIG_HEATER_EN,
					val ? HDC100X_REG_CONFIG_HEATER_EN : 0);
		mutex_unlock(&data->lock);
		return ret;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int hdc100x_buffer_postenable(struct iio_dev *indio_dev)
{
	struct hdc100x_data *data = iio_priv(indio_dev);
	int ret;

	/* Buffer is enabled. First set ACQ Mode, then attach poll func */
	mutex_lock(&data->lock);
	ret = hdc100x_update_config(data, HDC100X_REG_CONFIG_ACQ_MODE,
				    HDC100X_REG_CONFIG_ACQ_MODE);
	mutex_unlock(&data->lock);
	if (ret)
		return ret;

	return iio_triggered_buffer_postenable(indio_dev);
}

__attribute__((used)) static int hdc100x_buffer_predisable(struct iio_dev *indio_dev)
{
	struct hdc100x_data *data = iio_priv(indio_dev);
	int ret;

	/* First detach poll func, then reset ACQ mode. OK to disable buffer */
	ret = iio_triggered_buffer_predisable(indio_dev);
	if (ret)
		return ret;

	mutex_lock(&data->lock);
	ret = hdc100x_update_config(data, HDC100X_REG_CONFIG_ACQ_MODE, 0);
	mutex_unlock(&data->lock);

	return ret;
}

__attribute__((used)) static irqreturn_t hdc100x_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct hdc100x_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;
	int delay = data->adc_int_us[0] + data->adc_int_us[1];
	int ret;
	s16 buf[8];  /* 2x s16 + padding + 8 byte timestamp */

	/* dual read starts at temp register */
	mutex_lock(&data->lock);
	ret = i2c_smbus_write_byte(client, HDC100X_REG_TEMP);
	if (ret < 0) {
		dev_err(&client->dev, "cannot start measurement\n");
		goto err;
	}
	usleep_range(delay, delay + 1000);

	ret = i2c_master_recv(client, (u8 *)buf, 4);
	if (ret < 0) {
		dev_err(&client->dev, "cannot read sensor data\n");
		goto err;
	}

	iio_push_to_buffers_with_timestamp(indio_dev, buf,
					   iio_get_time_ns(indio_dev));
err:
	mutex_unlock(&data->lock);
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int hdc100x_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct hdc100x_data *data;
	int ret;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA |
				     I2C_FUNC_SMBUS_BYTE | I2C_FUNC_I2C))
		return -EOPNOTSUPP;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->name = dev_name(&client->dev);
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->info = &hdc100x_info;

	indio_dev->channels = hdc100x_channels;
	indio_dev->num_channels = ARRAY_SIZE(hdc100x_channels);
	indio_dev->available_scan_masks = hdc100x_scan_masks;

	/* be sure we are in a known state */
	hdc100x_set_it_time(data, 0, hdc100x_int_time[0][0]);
	hdc100x_set_it_time(data, 1, hdc100x_int_time[1][0]);
	hdc100x_update_config(data, HDC100X_REG_CONFIG_ACQ_MODE, 0);

	ret = iio_triggered_buffer_setup(indio_dev, NULL,
					 hdc100x_trigger_handler,
					 &hdc_buffer_setup_ops);
	if (ret < 0) {
		dev_err(&client->dev, "iio triggered buffer setup failed\n");
		return ret;
	}
	ret = iio_device_register(indio_dev);
	if (ret < 0)
		iio_triggered_buffer_cleanup(indio_dev);

	return ret;
}

__attribute__((used)) static int hdc100x_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);

	return 0;
}

