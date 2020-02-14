#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_4__ {struct TYPE_4__* parent; } ;
struct iio_dev {int* channels; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  modes; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/ * info; } ;
struct iio_chan_spec {int type; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct i2c_client {TYPE_1__ dev; int /*<<< orphan*/  adapter; } ;
struct hp206c_osr_setting {int osr_mask; unsigned int temp_conv_time_us; unsigned int pres_conv_time_us; } ;
struct hp206c_data {size_t temp_osr_index; size_t pres_osr_index; int /*<<< orphan*/  mutex; struct i2c_client* client; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int HP206C_CMD_ADC_CVT ; 
 int HP206C_CMD_ADC_CVT_CHNL_PT ; 
 int HP206C_CMD_ADC_CVT_CHNL_T ; 
 int HP206C_CMD_READ_P ; 
 int HP206C_CMD_READ_REG ; 
 int HP206C_CMD_READ_T ; 
 int HP206C_CMD_SOFT_RST ; 
 int HP206C_CMD_WRITE_REG ; 
 int HP206C_DEV_RDY_WAIT_US ; 
 int HP206C_FLAG_CMPS_EN ; 
 int HP206C_FLAG_DEV_RDY ; 
 int HP206C_MAX_DEV_RDY_WAIT_COUNT ; 
 int HP206C_REG_INT_SRC ; 
 int HP206C_REG_PARA ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_READ_I2C_BLOCK ; 
#define  IIO_CHAN_INFO_OVERSAMPLING_RATIO 132 
#define  IIO_CHAN_INFO_RAW 131 
#define  IIO_CHAN_INFO_SCALE 130 
#define  IIO_PRESSURE 129 
#define  IIO_TEMP 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_1__*,int) ; 
 int devm_iio_device_register (TYPE_1__*,struct iio_dev*) ; 
 void* find_closest_descending (int,int*,int /*<<< orphan*/ ) ; 
 int* hp206c_channels ; 
 int /*<<< orphan*/  hp206c_info ; 
 int* hp206c_osr_rates ; 
 struct hp206c_osr_setting* hp206c_osr_settings ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int,int,int*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 struct hp206c_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int sign_extend32 (int,int) ; 
 int /*<<< orphan*/  usleep_range (unsigned int,unsigned int) ; 

__attribute__((used)) static inline int hp206c_read_reg(struct i2c_client *client, u8 reg)
{
	return i2c_smbus_read_byte_data(client, HP206C_CMD_READ_REG | reg);
}

__attribute__((used)) static inline int hp206c_write_reg(struct i2c_client *client, u8 reg, u8 val)
{
	return i2c_smbus_write_byte_data(client,
			HP206C_CMD_WRITE_REG | reg, val);
}

__attribute__((used)) static int hp206c_read_20bit(struct i2c_client *client, u8 cmd)
{
	int ret;
	u8 values[3];

	ret = i2c_smbus_read_i2c_block_data(client, cmd, 3, values);
	if (ret < 0)
		return ret;
	if (ret != 3)
		return -EIO;
	return ((values[0] & 0xF) << 16) | (values[1] << 8) | (values[2]);
}

__attribute__((used)) static int hp206c_wait_dev_rdy(struct iio_dev *indio_dev)
{
	int ret;
	int count = 0;
	struct hp206c_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;

	while (++count <= HP206C_MAX_DEV_RDY_WAIT_COUNT) {
		ret = hp206c_read_reg(client, HP206C_REG_INT_SRC);
		if (ret < 0) {
			dev_err(&indio_dev->dev, "Failed READ_REG INT_SRC: %d\n", ret);
			return ret;
		}
		if (ret & HP206C_FLAG_DEV_RDY)
			return 0;
		usleep_range(HP206C_DEV_RDY_WAIT_US, HP206C_DEV_RDY_WAIT_US * 3 / 2);
	}
	return -ETIMEDOUT;
}

__attribute__((used)) static int hp206c_set_compensation(struct i2c_client *client, bool enabled)
{
	int val;

	val = hp206c_read_reg(client, HP206C_REG_PARA);
	if (val < 0)
		return val;
	if (enabled)
		val |= HP206C_FLAG_CMPS_EN;
	else
		val &= ~HP206C_FLAG_CMPS_EN;

	return hp206c_write_reg(client, HP206C_REG_PARA, val);
}

__attribute__((used)) static int hp206c_soft_reset(struct iio_dev *indio_dev)
{
	int ret;
	struct hp206c_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;

	ret = i2c_smbus_write_byte(client, HP206C_CMD_SOFT_RST);
	if (ret) {
		dev_err(&client->dev, "Failed to reset device: %d\n", ret);
		return ret;
	}

	usleep_range(400, 600);

	ret = hp206c_wait_dev_rdy(indio_dev);
	if (ret) {
		dev_err(&client->dev, "Device not ready after soft reset: %d\n", ret);
		return ret;
	}

	ret = hp206c_set_compensation(client, true);
	if (ret)
		dev_err(&client->dev, "Failed to enable compensation: %d\n", ret);
	return ret;
}

__attribute__((used)) static int hp206c_conv_and_read(struct iio_dev *indio_dev,
				u8 conv_cmd, u8 read_cmd,
				unsigned int sleep_us)
{
	int ret;
	struct hp206c_data *data = iio_priv(indio_dev);
	struct i2c_client *client = data->client;

	ret = hp206c_wait_dev_rdy(indio_dev);
	if (ret < 0) {
		dev_err(&indio_dev->dev, "Device not ready: %d\n", ret);
		return ret;
	}

	ret = i2c_smbus_write_byte(client, conv_cmd);
	if (ret < 0) {
		dev_err(&indio_dev->dev, "Failed convert: %d\n", ret);
		return ret;
	}

	usleep_range(sleep_us, sleep_us * 3 / 2);

	ret = hp206c_wait_dev_rdy(indio_dev);
	if (ret < 0) {
		dev_err(&indio_dev->dev, "Device not ready: %d\n", ret);
		return ret;
	}

	ret = hp206c_read_20bit(client, read_cmd);
	if (ret < 0)
		dev_err(&indio_dev->dev, "Failed read: %d\n", ret);

	return ret;
}

__attribute__((used)) static int hp206c_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan, int *val,
			   int *val2, long mask)
{
	int ret;
	struct hp206c_data *data = iio_priv(indio_dev);
	const struct hp206c_osr_setting *osr_setting;
	u8 conv_cmd;

	mutex_lock(&data->mutex);

	switch (mask) {
	case IIO_CHAN_INFO_OVERSAMPLING_RATIO:
		switch (chan->type) {
		case IIO_TEMP:
			*val = hp206c_osr_rates[data->temp_osr_index];
			ret = IIO_VAL_INT;
			break;

		case IIO_PRESSURE:
			*val = hp206c_osr_rates[data->pres_osr_index];
			ret = IIO_VAL_INT;
			break;
		default:
			ret = -EINVAL;
		}
		break;

	case IIO_CHAN_INFO_RAW:
		switch (chan->type) {
		case IIO_TEMP:
			osr_setting = &hp206c_osr_settings[data->temp_osr_index];
			conv_cmd = HP206C_CMD_ADC_CVT |
					osr_setting->osr_mask |
					HP206C_CMD_ADC_CVT_CHNL_T;
			ret = hp206c_conv_and_read(indio_dev,
					conv_cmd,
					HP206C_CMD_READ_T,
					osr_setting->temp_conv_time_us);
			if (ret >= 0) {
				/* 20 significant bits are provided.
				 * Extend sign over the rest.
				 */
				*val = sign_extend32(ret, 19);
				ret = IIO_VAL_INT;
			}
			break;

		case IIO_PRESSURE:
			osr_setting = &hp206c_osr_settings[data->pres_osr_index];
			conv_cmd = HP206C_CMD_ADC_CVT |
					osr_setting->osr_mask |
					HP206C_CMD_ADC_CVT_CHNL_PT;
			ret = hp206c_conv_and_read(indio_dev,
					conv_cmd,
					HP206C_CMD_READ_P,
					osr_setting->pres_conv_time_us);
			if (ret >= 0) {
				*val = ret;
				ret = IIO_VAL_INT;
			}
			break;
		default:
			ret = -EINVAL;
		}
		break;

	case IIO_CHAN_INFO_SCALE:
		switch (chan->type) {
		case IIO_TEMP:
			*val = 0;
			*val2 = 10000;
			ret = IIO_VAL_INT_PLUS_MICRO;
			break;

		case IIO_PRESSURE:
			*val = 0;
			*val2 = 1000;
			ret = IIO_VAL_INT_PLUS_MICRO;
			break;
		default:
			ret = -EINVAL;
		}
		break;

	default:
		ret = -EINVAL;
	}

	mutex_unlock(&data->mutex);
	return ret;
}

__attribute__((used)) static int hp206c_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int val, int val2, long mask)
{
	int ret = 0;
	struct hp206c_data *data = iio_priv(indio_dev);

	if (mask != IIO_CHAN_INFO_OVERSAMPLING_RATIO)
		return -EINVAL;
	mutex_lock(&data->mutex);
	switch (chan->type) {
	case IIO_TEMP:
		data->temp_osr_index = find_closest_descending(val,
			hp206c_osr_rates, ARRAY_SIZE(hp206c_osr_rates));
		break;
	case IIO_PRESSURE:
		data->pres_osr_index = find_closest_descending(val,
			hp206c_osr_rates, ARRAY_SIZE(hp206c_osr_rates));
		break;
	default:
		ret = -EINVAL;
	}
	mutex_unlock(&data->mutex);
	return ret;
}

__attribute__((used)) static int hp206c_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct iio_dev *indio_dev;
	struct hp206c_data *data;
	int ret;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_BYTE |
				     I2C_FUNC_SMBUS_BYTE_DATA |
				     I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
		dev_err(&client->dev, "Adapter does not support "
				"all required i2c functionality\n");
		return -ENODEV;
	}

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	data->client = client;
	mutex_init(&data->mutex);

	indio_dev->info = &hp206c_info;
	indio_dev->name = id->name;
	indio_dev->dev.parent = &client->dev;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = hp206c_channels;
	indio_dev->num_channels = ARRAY_SIZE(hp206c_channels);

	i2c_set_clientdata(client, indio_dev);

	/* Do a soft reset on probe */
	ret = hp206c_soft_reset(indio_dev);
	if (ret) {
		dev_err(&client->dev, "Failed to reset on startup: %d\n", ret);
		return -ENODEV;
	}

	return devm_iio_device_register(&client->dev, indio_dev);
}

