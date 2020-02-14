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
typedef  int u16 ;
struct lidar_data {int (* xfer ) (struct lidar_data*,int,int*,int) ;int i2c_enabled; int* buffer; struct iio_dev* indio_dev; struct i2c_client* client; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; int /*<<< orphan*/  trig; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_msg {int flags; int len; char* buf; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int flags; int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  addr; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int I2C_M_RD ; 
 int I2C_M_STOP ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  LIDAR_DRV_NAME ; 
 int /*<<< orphan*/  LIDAR_REG_CONTROL ; 
 int LIDAR_REG_CONTROL_ACQUIRE ; 
 int LIDAR_REG_DATA_HBYTE ; 
 int LIDAR_REG_DATA_WORD_READ ; 
 int /*<<< orphan*/  LIDAR_REG_PWR_CONTROL ; 
 int LIDAR_REG_STATUS ; 
 int LIDAR_REG_STATUS_INVALID ; 
 int LIDAR_REG_STATUS_READY ; 
 int be16_to_cpu (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 scalar_t__ i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte (struct i2c_client*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  iio_device_claim_direct_mode (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct lidar_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lidar_channels ; 
 int /*<<< orphan*/  lidar_info ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_idle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (int /*<<< orphan*/ *) ; 
 int pm_runtime_set_active (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pm_runtime_set_suspended (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (int /*<<< orphan*/ *) ; 
 int stub1 (struct lidar_data*,int,int*,int) ; 
 int stub2 (struct lidar_data*,int,int*,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int lidar_i2c_xfer(struct lidar_data *data, u8 reg, u8 *val, int len)
{
	struct i2c_client *client = data->client;
	struct i2c_msg msg[2];
	int ret;

	msg[0].addr = client->addr;
	msg[0].flags = client->flags | I2C_M_STOP;
	msg[0].len = 1;
	msg[0].buf  = (char *) &reg;

	msg[1].addr = client->addr;
	msg[1].flags = client->flags | I2C_M_RD;
	msg[1].len = len;
	msg[1].buf = (char *) val;

	ret = i2c_transfer(client->adapter, msg, 2);

	return (ret == 2) ? 0 : -EIO;
}

__attribute__((used)) static int lidar_smbus_xfer(struct lidar_data *data, u8 reg, u8 *val, int len)
{
	struct i2c_client *client = data->client;
	int ret;

	/*
	 * Device needs a STOP condition between address write, and data read
	 * so in turn i2c_smbus_read_byte_data cannot be used
	 */

	while (len--) {
		ret = i2c_smbus_write_byte(client, reg++);
		if (ret < 0) {
			dev_err(&client->dev, "cannot write addr value");
			return ret;
		}

		ret = i2c_smbus_read_byte(client);
		if (ret < 0) {
			dev_err(&client->dev, "cannot read data value");
			return ret;
		}

		*(val++) = ret;
	}

	return 0;
}

__attribute__((used)) static int lidar_read_byte(struct lidar_data *data, u8 reg)
{
	int ret;
	u8 val;

	ret = data->xfer(data, reg, &val, 1);
	if (ret < 0)
		return ret;

	return val;
}

__attribute__((used)) static inline int lidar_write_control(struct lidar_data *data, int val)
{
	return i2c_smbus_write_byte_data(data->client, LIDAR_REG_CONTROL, val);
}

__attribute__((used)) static inline int lidar_write_power(struct lidar_data *data, int val)
{
	return i2c_smbus_write_byte_data(data->client,
					 LIDAR_REG_PWR_CONTROL, val);
}

__attribute__((used)) static int lidar_read_measurement(struct lidar_data *data, u16 *reg)
{
	int ret = data->xfer(data, LIDAR_REG_DATA_HBYTE |
			(data->i2c_enabled ? LIDAR_REG_DATA_WORD_READ : 0),
			(u8 *) reg, 2);

	if (!ret)
		*reg = be16_to_cpu(*reg);

	return ret;
}

__attribute__((used)) static int lidar_get_measurement(struct lidar_data *data, u16 *reg)
{
	struct i2c_client *client = data->client;
	int tries = 10;
	int ret;

	pm_runtime_get_sync(&client->dev);

	/* start sample */
	ret = lidar_write_control(data, LIDAR_REG_CONTROL_ACQUIRE);
	if (ret < 0) {
		dev_err(&client->dev, "cannot send start measurement command");
		return ret;
	}

	while (tries--) {
		usleep_range(1000, 2000);

		ret = lidar_read_byte(data, LIDAR_REG_STATUS);
		if (ret < 0)
			break;

		/* return -EINVAL since laser is likely pointed out of range */
		if (ret & LIDAR_REG_STATUS_INVALID) {
			*reg = 0;
			ret = -EINVAL;
			break;
		}

		/* sample ready to read */
		if (!(ret & LIDAR_REG_STATUS_READY)) {
			ret = lidar_read_measurement(data, reg);
			break;
		}
		ret = -EIO;
	}
	pm_runtime_mark_last_busy(&client->dev);
	pm_runtime_put_autosuspend(&client->dev);

	return ret;
}

__attribute__((used)) static int lidar_read_raw(struct iio_dev *indio_dev,
			  struct iio_chan_spec const *chan,
			  int *val, int *val2, long mask)
{
	struct lidar_data *data = iio_priv(indio_dev);
	int ret = -EINVAL;

	switch (mask) {
	case IIO_CHAN_INFO_RAW: {
		u16 reg;

		if (iio_device_claim_direct_mode(indio_dev))
			return -EBUSY;

		ret = lidar_get_measurement(data, &reg);
		if (!ret) {
			*val = reg;
			ret = IIO_VAL_INT;
		}
		iio_device_release_direct_mode(indio_dev);
		break;
	}
	case IIO_CHAN_INFO_SCALE:
		*val = 0;
		*val2 = 10000;
		ret = IIO_VAL_INT_PLUS_MICRO;
		break;
	}

	return ret;
}

__attribute__((used)) static irqreturn_t lidar_trigger_handler(int irq, void *private)
{
	struct iio_poll_func *pf = private;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct lidar_data *data = iio_priv(indio_dev);
	int ret;

	ret = lidar_get_measurement(data, data->buffer);
	if (!ret) {
		iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
						   iio_get_time_ns(indio_dev));
	} else if (ret != -EINVAL) {
		dev_err(&data->client->dev, "cannot read LIDAR measurement");
	}

	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int lidar_probe(struct i2c_client *client,
		       const struct i2c_device_id *id)
{
	struct lidar_data *data;
	struct iio_dev *indio_dev;
	int ret;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;
	data = iio_priv(indio_dev);

	if (i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		data->xfer = lidar_i2c_xfer;
		data->i2c_enabled = 1;
	} else if (i2c_check_functionality(client->adapter,
				I2C_FUNC_SMBUS_WORD_DATA | I2C_FUNC_SMBUS_BYTE))
		data->xfer = lidar_smbus_xfer;
	else
		return -EOPNOTSUPP;

	indio_dev->info = &lidar_info;
	indio_dev->name = LIDAR_DRV_NAME;
	indio_dev->channels = lidar_channels;
	indio_dev->num_channels = ARRAY_SIZE(lidar_channels);
	indio_dev->dev.parent = &client->dev;
	indio_dev->modes = INDIO_DIRECT_MODE;

	i2c_set_clientdata(client, indio_dev);

	data->client = client;
	data->indio_dev = indio_dev;

	ret = iio_triggered_buffer_setup(indio_dev, NULL,
					 lidar_trigger_handler, NULL);
	if (ret)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_unreg_buffer;

	pm_runtime_set_autosuspend_delay(&client->dev, 1000);
	pm_runtime_use_autosuspend(&client->dev);

	ret = pm_runtime_set_active(&client->dev);
	if (ret)
		goto error_unreg_buffer;
	pm_runtime_enable(&client->dev);
	pm_runtime_idle(&client->dev);

	return 0;

error_unreg_buffer:
	iio_triggered_buffer_cleanup(indio_dev);

	return ret;
}

__attribute__((used)) static int lidar_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);

	pm_runtime_disable(&client->dev);
	pm_runtime_set_suspended(&client->dev);

	return 0;
}

