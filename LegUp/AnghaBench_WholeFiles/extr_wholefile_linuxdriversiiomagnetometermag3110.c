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
struct mag3110_data {int ctrl_reg1; int sleep_val; int /*<<< orphan*/  lock; struct i2c_client* client; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  available_scan_masks; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; int /*<<< orphan*/  trig; int /*<<< orphan*/  active_scan_mask; } ;
struct iio_chan_spec {size_t scan_index; int /*<<< orphan*/  type; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_CALIBBIAS 133 
#define  IIO_CHAN_INFO_RAW 132 
#define  IIO_CHAN_INFO_SAMP_FREQ 131 
#define  IIO_CHAN_INFO_SCALE 130 
#define  IIO_MAGN 129 
#define  IIO_TEMP 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int MAG3110_CTRL_AC ; 
 int MAG3110_CTRL_AUTO_MRST_EN ; 
 int MAG3110_CTRL_DR_DEFAULT ; 
 int MAG3110_CTRL_DR_MASK ; 
 int MAG3110_CTRL_DR_SHIFT ; 
 int MAG3110_CTRL_REG1 ; 
 int MAG3110_CTRL_REG2 ; 
 int MAG3110_CTRL_TM ; 
 int MAG3110_DEVICE_ID ; 
 int MAG3110_DIE_TEMP ; 
 int /*<<< orphan*/  MAG3110_OFF_X ; 
 int /*<<< orphan*/  MAG3110_OUT_X ; 
 int MAG3110_STATUS ; 
 int MAG3110_STATUS_DRDY ; 
 int MAG3110_SYSMOD ; 
 int MAG3110_SYSMOD_MODE_MASK ; 
 int MAG3110_WHO_AM_I ; 
 scalar_t__ PAGE_SIZE ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,int,int*) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_claim_direct_mode (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct mag3110_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mag3110_channels ; 
 int /*<<< orphan*/  mag3110_info ; 
 int** mag3110_samp_freq ; 
 int /*<<< orphan*/  mag3110_scan_masks ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  msleep_interruptible (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ scnprintf (char*,scalar_t__,char*,int const,int const) ; 
 int sign_extend32 (int,int) ; 
 scalar_t__ test_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int mag3110_request(struct mag3110_data *data)
{
	int ret, tries = 150;

	if ((data->ctrl_reg1 & MAG3110_CTRL_AC) == 0) {
		/* trigger measurement */
		ret = i2c_smbus_write_byte_data(data->client, MAG3110_CTRL_REG1,
			data->ctrl_reg1 | MAG3110_CTRL_TM);
		if (ret < 0)
			return ret;
	}

	while (tries-- > 0) {
		ret = i2c_smbus_read_byte_data(data->client, MAG3110_STATUS);
		if (ret < 0)
			return ret;
		/* wait for data ready */
		if ((ret & MAG3110_STATUS_DRDY) == MAG3110_STATUS_DRDY)
			break;

		if (data->sleep_val <= 20)
			usleep_range(data->sleep_val * 250, data->sleep_val * 500);
		else
			msleep(20);
	}

	if (tries < 0) {
		dev_err(&data->client->dev, "data not ready\n");
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int mag3110_read(struct mag3110_data *data, __be16 buf[3])
{
	int ret;

	mutex_lock(&data->lock);
	ret = mag3110_request(data);
	if (ret < 0) {
		mutex_unlock(&data->lock);
		return ret;
	}
	ret = i2c_smbus_read_i2c_block_data(data->client,
		MAG3110_OUT_X, 3 * sizeof(__be16), (u8 *) buf);
	mutex_unlock(&data->lock);

	return ret;
}

__attribute__((used)) static ssize_t mag3110_show_int_plus_micros(char *buf,
	const int (*vals)[2], int n)
{
	size_t len = 0;

	while (n-- > 0)
		len += scnprintf(buf + len, PAGE_SIZE - len,
			"%d.%06d ", vals[n][0], vals[n][1]);

	/* replace trailing space by newline */
	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static int mag3110_get_int_plus_micros_index(const int (*vals)[2], int n,
					int val, int val2)
{
	while (n-- > 0)
		if (val == vals[n][0] && val2 == vals[n][1])
			return n;

	return -EINVAL;
}

__attribute__((used)) static ssize_t mag3110_show_samp_freq_avail(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	return mag3110_show_int_plus_micros(buf, mag3110_samp_freq, 8);
}

__attribute__((used)) static int mag3110_get_samp_freq_index(struct mag3110_data *data,
	int val, int val2)
{
	return mag3110_get_int_plus_micros_index(mag3110_samp_freq, 8, val,
		val2);
}

__attribute__((used)) static int mag3110_calculate_sleep(struct mag3110_data *data)
{
	int ret, i = data->ctrl_reg1 >> MAG3110_CTRL_DR_SHIFT;

	if (mag3110_samp_freq[i][0] > 0)
		ret = 1000 / mag3110_samp_freq[i][0];
	else
		ret = 1000;

	return ret == 0 ? 1 : ret;
}

__attribute__((used)) static int mag3110_standby(struct mag3110_data *data)
{
	return i2c_smbus_write_byte_data(data->client, MAG3110_CTRL_REG1,
		data->ctrl_reg1 & ~MAG3110_CTRL_AC);
}

__attribute__((used)) static int mag3110_wait_standby(struct mag3110_data *data)
{
	int ret, tries = 30;

	/*
	 * Takes up to 1/ODR to come out of active mode into stby
	 * Longest expected period is 12.5seconds.
	 * We'll sleep for 500ms between checks
	 */
	while (tries-- > 0) {
		ret = i2c_smbus_read_byte_data(data->client, MAG3110_SYSMOD);
		if (ret < 0) {
			dev_err(&data->client->dev, "i2c error\n");
			return ret;
		}
		/* wait for standby */
		if ((ret & MAG3110_SYSMOD_MODE_MASK) == 0)
			break;

		msleep_interruptible(500);
	}

	if (tries < 0) {
		dev_err(&data->client->dev, "device not entering standby mode\n");
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int mag3110_active(struct mag3110_data *data)
{
	return i2c_smbus_write_byte_data(data->client, MAG3110_CTRL_REG1,
					 data->ctrl_reg1);
}

__attribute__((used)) static int mag3110_is_active(struct mag3110_data *data)
{
	int reg;

	reg = i2c_smbus_read_byte_data(data->client, MAG3110_CTRL_REG1);
	if (reg < 0)
		return reg;

	return reg & MAG3110_CTRL_AC;
}

__attribute__((used)) static int mag3110_change_config(struct mag3110_data *data, u8 reg, u8 val)
{
	int ret;
	int is_active;

	mutex_lock(&data->lock);

	is_active = mag3110_is_active(data);
	if (is_active < 0) {
		ret = is_active;
		goto fail;
	}

	/* config can only be changed when in standby */
	if (is_active > 0) {
		ret = mag3110_standby(data);
		if (ret < 0)
			goto fail;
	}

	/*
	 * After coming out of active we must wait for the part
	 * to transition to STBY. This can take up to 1 /ODR to occur
	 */
	ret = mag3110_wait_standby(data);
	if (ret < 0)
		goto fail;

	ret = i2c_smbus_write_byte_data(data->client, reg, val);
	if (ret < 0)
		goto fail;

	if (is_active > 0) {
		ret = mag3110_active(data);
		if (ret < 0)
			goto fail;
	}

	ret = 0;
fail:
	mutex_unlock(&data->lock);

	return ret;
}

__attribute__((used)) static int mag3110_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct mag3110_data *data = iio_priv(indio_dev);
	__be16 buffer[3];
	int i, ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = iio_device_claim_direct_mode(indio_dev);
		if (ret)
			return ret;

		switch (chan->type) {
		case IIO_MAGN: /* in 0.1 uT / LSB */
			ret = mag3110_read(data, buffer);
			if (ret < 0)
				goto release;
			*val = sign_extend32(
				be16_to_cpu(buffer[chan->scan_index]), 15);
			ret = IIO_VAL_INT;
			break;
		case IIO_TEMP: /* in 1 C / LSB */
			mutex_lock(&data->lock);
			ret = mag3110_request(data);
			if (ret < 0) {
				mutex_unlock(&data->lock);
				goto release;
			}
			ret = i2c_smbus_read_byte_data(data->client,
				MAG3110_DIE_TEMP);
			mutex_unlock(&data->lock);
			if (ret < 0)
				goto release;
			*val = sign_extend32(ret, 7);
			ret = IIO_VAL_INT;
			break;
		default:
			ret = -EINVAL;
		}
release:
		iio_device_release_direct_mode(indio_dev);
		return ret;

	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_MAGN:
			*val = 0;
			*val2 = 1000;
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_TEMP:
			*val = 1000;
			return IIO_VAL_INT;
		default:
			return -EINVAL;
		}
	case IIO_CHAN_INFO_SAMP_FREQ:
		i = data->ctrl_reg1 >> MAG3110_CTRL_DR_SHIFT;
		*val = mag3110_samp_freq[i][0];
		*val2 = mag3110_samp_freq[i][1];
		return IIO_VAL_INT_PLUS_MICRO;
	case IIO_CHAN_INFO_CALIBBIAS:
		ret = i2c_smbus_read_word_swapped(data->client,
			MAG3110_OFF_X +	2 * chan->scan_index);
		if (ret < 0)
			return ret;
		*val = sign_extend32(ret >> 1, 14);
		return IIO_VAL_INT;
	}
	return -EINVAL;
}

__attribute__((used)) static int mag3110_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct mag3110_data *data = iio_priv(indio_dev);
	int rate, ret;

	ret = iio_device_claim_direct_mode(indio_dev);
	if (ret)
		return ret;

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		rate = mag3110_get_samp_freq_index(data, val, val2);
		if (rate < 0) {
			ret = -EINVAL;
			break;
		}
		data->ctrl_reg1 &= 0xff & ~MAG3110_CTRL_DR_MASK
					& ~MAG3110_CTRL_AC;
		data->ctrl_reg1 |= rate << MAG3110_CTRL_DR_SHIFT;
		data->sleep_val = mag3110_calculate_sleep(data);
		if (data->sleep_val < 40)
			data->ctrl_reg1 |= MAG3110_CTRL_AC;

		ret = mag3110_change_config(data, MAG3110_CTRL_REG1,
					    data->ctrl_reg1);
		break;
	case IIO_CHAN_INFO_CALIBBIAS:
		if (val < -10000 || val > 10000) {
			ret = -EINVAL;
			break;
		}
		ret = i2c_smbus_write_word_swapped(data->client,
			MAG3110_OFF_X + 2 * chan->scan_index, val << 1);
		break;
	default:
		ret = -EINVAL;
		break;
	}
	iio_device_release_direct_mode(indio_dev);
	return ret;
}

__attribute__((used)) static irqreturn_t mag3110_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct mag3110_data *data = iio_priv(indio_dev);
	u8 buffer[16]; /* 3 16-bit channels + 1 byte temp + padding + ts */
	int ret;

	ret = mag3110_read(data, (__be16 *) buffer);
	if (ret < 0)
		goto done;

	if (test_bit(3, indio_dev->active_scan_mask)) {
		ret = i2c_smbus_read_byte_data(data->client,
			MAG3110_DIE_TEMP);
		if (ret < 0)
			goto done;
		buffer[6] = ret;
	}

	iio_push_to_buffers_with_timestamp(indio_dev, buffer,
		iio_get_time_ns(indio_dev));

done:
	iio_trigger_notify_done(indio_dev->trig);
	return IRQ_HANDLED;
}

__attribute__((used)) static int mag3110_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct mag3110_data *data;
	struct iio_dev *indio_dev;
	int ret;

	ret = i2c_smbus_read_byte_data(client, MAG3110_WHO_AM_I);
	if (ret < 0)
		return ret;
	if (ret != MAG3110_DEVICE_ID)
		return -ENODEV;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	data->client = client;
	mutex_init(&data->lock);

	i2c_set_clientdata(client, indio_dev);
	indio_dev->info = &mag3110_info;
	indio_dev->name = id->name;
	indio_dev->dev.parent = &client->dev;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = mag3110_channels;
	indio_dev->num_channels = ARRAY_SIZE(mag3110_channels);
	indio_dev->available_scan_masks = mag3110_scan_masks;

	data->ctrl_reg1 = MAG3110_CTRL_DR_DEFAULT << MAG3110_CTRL_DR_SHIFT;
	data->sleep_val = mag3110_calculate_sleep(data);
	if (data->sleep_val < 40)
		data->ctrl_reg1 |= MAG3110_CTRL_AC;

	ret = mag3110_change_config(data, MAG3110_CTRL_REG1, data->ctrl_reg1);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_write_byte_data(client, MAG3110_CTRL_REG2,
		MAG3110_CTRL_AUTO_MRST_EN);
	if (ret < 0)
		goto standby_on_error;

	ret = iio_triggered_buffer_setup(indio_dev, NULL,
		mag3110_trigger_handler, NULL);
	if (ret < 0)
		goto standby_on_error;

	ret = iio_device_register(indio_dev);
	if (ret < 0)
		goto buffer_cleanup;
	return 0;

buffer_cleanup:
	iio_triggered_buffer_cleanup(indio_dev);
standby_on_error:
	mag3110_standby(iio_priv(indio_dev));
	return ret;
}

__attribute__((used)) static int mag3110_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);
	mag3110_standby(iio_priv(indio_dev));

	return 0;
}

