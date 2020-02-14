#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  char u8 ;
struct iio_trigger {int dummy; } ;
struct iio_poll_func {struct iio_dev* indio_dev; } ;
struct TYPE_11__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {TYPE_4__* trig; int /*<<< orphan*/  id; int /*<<< orphan*/  name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  channel2; int /*<<< orphan*/  type; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct i2c_client {scalar_t__ irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct TYPE_13__ {int /*<<< orphan*/  voc; int /*<<< orphan*/  co2; int /*<<< orphan*/  raw_data; } ;
struct ccs811_data {int drdy_trig_on; TYPE_4__* drdy_trig; int /*<<< orphan*/  lock; struct i2c_client* client; TYPE_3__ buffer; } ;
typedef  int /*<<< orphan*/  s16 ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_12__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_14__ {int /*<<< orphan*/ * ops; TYPE_2__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CCS811_ALG_RESULT_DATA ; 
 int /*<<< orphan*/  CCS811_APP_START ; 
 int /*<<< orphan*/  CCS811_HW_ID ; 
 int CCS811_HW_ID_VALUE ; 
 int /*<<< orphan*/  CCS811_HW_VERSION ; 
 int CCS811_HW_VERSION_MASK ; 
 int CCS811_HW_VERSION_VALUE ; 
 int /*<<< orphan*/  CCS811_MEAS_MODE ; 
 int CCS811_MEAS_MODE_INTERRUPT ; 
 int CCS811_MODE_IAQ_1SEC ; 
 int CCS811_MODE_IDLE ; 
 int /*<<< orphan*/  CCS811_STATUS ; 
 int CCS811_STATUS_APP_VALID_LOADED ; 
 int CCS811_STATUS_APP_VALID_MASK ; 
 int CCS811_STATUS_DATA_READY ; 
 int CCS811_STATUS_FW_MODE_APPLICATION ; 
 int CCS811_STATUS_FW_MODE_MASK ; 
 int CCS811_VOLTAGE_MASK ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_READ_I2C_BLOCK ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE ; 
#define  IIO_CHAN_INFO_RAW 134 
#define  IIO_CHAN_INFO_SCALE 133 
#define  IIO_CONCENTRATION 132 
#define  IIO_CURRENT 131 
#define  IIO_MOD_CO2 130 
#define  IIO_MOD_VOC 129 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int IIO_VAL_INT_PLUS_NANO ; 
#define  IIO_VOLTAGE 128 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ccs811_channels ; 
 int /*<<< orphan*/  ccs811_info ; 
 int /*<<< orphan*/  ccs811_trigger_ops ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 TYPE_4__* devm_iio_trigger_alloc (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *,int,char*,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,int,char*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int iio_device_claim_direct_mode (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_release_direct_mode (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct ccs811_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_get (TYPE_4__*) ; 
 struct iio_dev* iio_trigger_get_drvdata (struct iio_trigger*) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (TYPE_4__*) ; 
 int /*<<< orphan*/  iio_trigger_poll (TYPE_4__*) ; 
 int iio_trigger_register (TYPE_4__*) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (TYPE_4__*,struct iio_dev*) ; 
 int /*<<< orphan*/  iio_trigger_unregister (TYPE_4__*) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ccs811_start_sensor_application(struct i2c_client *client)
{
	int ret;

	ret = i2c_smbus_read_byte_data(client, CCS811_STATUS);
	if (ret < 0)
		return ret;

	if ((ret & CCS811_STATUS_FW_MODE_APPLICATION))
		return 0;

	if ((ret & CCS811_STATUS_APP_VALID_MASK) !=
	    CCS811_STATUS_APP_VALID_LOADED)
		return -EIO;

	ret = i2c_smbus_write_byte(client, CCS811_APP_START);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_read_byte_data(client, CCS811_STATUS);
	if (ret < 0)
		return ret;

	if ((ret & CCS811_STATUS_FW_MODE_MASK) !=
	    CCS811_STATUS_FW_MODE_APPLICATION) {
		dev_err(&client->dev, "Application failed to start. Sensor is still in boot mode.\n");
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int ccs811_setup(struct i2c_client *client)
{
	int ret;

	ret = ccs811_start_sensor_application(client);
	if (ret < 0)
		return ret;

	return i2c_smbus_write_byte_data(client, CCS811_MEAS_MODE,
					 CCS811_MODE_IAQ_1SEC);
}

__attribute__((used)) static int ccs811_get_measurement(struct ccs811_data *data)
{
	int ret, tries = 11;

	/* Maximum waiting time: 1s, as measurements are made every second */
	while (tries-- > 0) {
		ret = i2c_smbus_read_byte_data(data->client, CCS811_STATUS);
		if (ret < 0)
			return ret;

		if ((ret & CCS811_STATUS_DATA_READY) || tries == 0)
			break;
		msleep(100);
	}
	if (!(ret & CCS811_STATUS_DATA_READY))
		return -EIO;

	return i2c_smbus_read_i2c_block_data(data->client,
					    CCS811_ALG_RESULT_DATA, 8,
					    (char *)&data->buffer);
}

__attribute__((used)) static int ccs811_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	struct ccs811_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = iio_device_claim_direct_mode(indio_dev);
		if (ret)
			return ret;
		mutex_lock(&data->lock);
		ret = ccs811_get_measurement(data);
		if (ret < 0) {
			mutex_unlock(&data->lock);
			iio_device_release_direct_mode(indio_dev);
			return ret;
		}

		switch (chan->type) {
		case IIO_VOLTAGE:
			*val = be16_to_cpu(data->buffer.raw_data) &
					   CCS811_VOLTAGE_MASK;
			ret = IIO_VAL_INT;
			break;
		case IIO_CURRENT:
			*val = be16_to_cpu(data->buffer.raw_data) >> 10;
			ret = IIO_VAL_INT;
			break;
		case IIO_CONCENTRATION:
			switch (chan->channel2) {
			case IIO_MOD_CO2:
				*val = be16_to_cpu(data->buffer.co2);
				ret =  IIO_VAL_INT;
				break;
			case IIO_MOD_VOC:
				*val = be16_to_cpu(data->buffer.voc);
				ret = IIO_VAL_INT;
				break;
			default:
				ret = -EINVAL;
			}
			break;
		default:
			ret = -EINVAL;
		}
		mutex_unlock(&data->lock);
		iio_device_release_direct_mode(indio_dev);

		return ret;

	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_VOLTAGE:
			*val = 1;
			*val2 = 612903;
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_CURRENT:
			*val = 0;
			*val2 = 1000;
			return IIO_VAL_INT_PLUS_MICRO;
		case IIO_CONCENTRATION:
			switch (chan->channel2) {
			case IIO_MOD_CO2:
				*val = 0;
				*val2 = 100;
				return IIO_VAL_INT_PLUS_MICRO;
			case IIO_MOD_VOC:
				*val = 0;
				*val2 = 100;
				return IIO_VAL_INT_PLUS_NANO;
			default:
				return -EINVAL;
			}
		default:
			return -EINVAL;
		}
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int ccs811_set_trigger_state(struct iio_trigger *trig,
				    bool state)
{
	struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
	struct ccs811_data *data = iio_priv(indio_dev);
	int ret;

	ret = i2c_smbus_read_byte_data(data->client, CCS811_MEAS_MODE);
	if (ret < 0)
		return ret;

	if (state)
		ret |= CCS811_MEAS_MODE_INTERRUPT;
	else
		ret &= ~CCS811_MEAS_MODE_INTERRUPT;

	data->drdy_trig_on = state;

	return i2c_smbus_write_byte_data(data->client, CCS811_MEAS_MODE, ret);
}

__attribute__((used)) static irqreturn_t ccs811_trigger_handler(int irq, void *p)
{
	struct iio_poll_func *pf = p;
	struct iio_dev *indio_dev = pf->indio_dev;
	struct ccs811_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;
	s16 buf[8]; /* s16 eCO2 + s16 TVOC + padding + 8 byte timestamp */
	int ret;

	ret = i2c_smbus_read_i2c_block_data(client, CCS811_ALG_RESULT_DATA, 4,
					    (u8 *)&buf);
	if (ret != 4) {
		dev_err(&client->dev, "cannot read sensor data\n");
		goto err;
	}

	iio_push_to_buffers_with_timestamp(indio_dev, buf,
					   iio_get_time_ns(indio_dev));

err:
	iio_trigger_notify_done(indio_dev->trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static irqreturn_t ccs811_data_rdy_trigger_poll(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct ccs811_data *data = iio_priv(indio_dev);

	if (data->drdy_trig_on)
		iio_trigger_poll(data->drdy_trig);

	return IRQ_HANDLED;
}

__attribute__((used)) static int ccs811_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct ccs811_data *data;
	int ret;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WRITE_BYTE
				     | I2C_FUNC_SMBUS_BYTE_DATA
				     | I2C_FUNC_SMBUS_READ_I2C_BLOCK))
		return -EOPNOTSUPP;

	/* Check hardware id (should be 0x81 for this family of devices) */
	ret = i2c_smbus_read_byte_data(client, CCS811_HW_ID);
	if (ret < 0)
		return ret;

	if (ret != CCS811_HW_ID_VALUE) {
		dev_err(&client->dev, "hardware id doesn't match CCS81x\n");
		return -ENODEV;
	}

	ret = i2c_smbus_read_byte_data(client, CCS811_HW_VERSION);
	if (ret < 0)
		return ret;

	if ((ret & CCS811_HW_VERSION_MASK) != CCS811_HW_VERSION_VALUE) {
		dev_err(&client->dev, "no CCS811 sensor\n");
		return -ENODEV;
	}

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	ret = ccs811_setup(client);
	if (ret < 0)
		return ret;

	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	mutex_init(&data->lock);

	indio_dev->dev.parent = &client->dev;
	indio_dev->name = id->name;
	indio_dev->info = &ccs811_info;
	indio_dev->modes = INDIO_DIRECT_MODE;

	indio_dev->channels = ccs811_channels;
	indio_dev->num_channels = ARRAY_SIZE(ccs811_channels);

	if (client->irq > 0) {
		ret = devm_request_threaded_irq(&client->dev, client->irq,
						ccs811_data_rdy_trigger_poll,
						NULL,
						IRQF_TRIGGER_FALLING |
						IRQF_ONESHOT,
						"ccs811_irq", indio_dev);
		if (ret) {
			dev_err(&client->dev, "irq request error %d\n", -ret);
			goto err_poweroff;
		}

		data->drdy_trig = devm_iio_trigger_alloc(&client->dev,
							 "%s-dev%d",
							 indio_dev->name,
							 indio_dev->id);
		if (!data->drdy_trig) {
			ret = -ENOMEM;
			goto err_poweroff;
		}

		data->drdy_trig->dev.parent = &client->dev;
		data->drdy_trig->ops = &ccs811_trigger_ops;
		iio_trigger_set_drvdata(data->drdy_trig, indio_dev);
		indio_dev->trig = data->drdy_trig;
		iio_trigger_get(indio_dev->trig);
		ret = iio_trigger_register(data->drdy_trig);
		if (ret)
			goto err_poweroff;
	}

	ret = iio_triggered_buffer_setup(indio_dev, NULL,
					 ccs811_trigger_handler, NULL);

	if (ret < 0) {
		dev_err(&client->dev, "triggered buffer setup failed\n");
		goto err_trigger_unregister;
	}

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "unable to register iio device\n");
		goto err_buffer_cleanup;
	}
	return 0;

err_buffer_cleanup:
	iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
	if (data->drdy_trig)
		iio_trigger_unregister(data->drdy_trig);
err_poweroff:
	i2c_smbus_write_byte_data(client, CCS811_MEAS_MODE, CCS811_MODE_IDLE);

	return ret;
}

__attribute__((used)) static int ccs811_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct ccs811_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);
	if (data->drdy_trig)
		iio_trigger_unregister(data->drdy_trig);

	return i2c_smbus_write_byte_data(client, CCS811_MEAS_MODE,
					 CCS811_MODE_IDLE);
}

