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
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct iio_dev {char* name; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {size_t address; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct dmard10_data {struct i2c_client* client; } ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DMARD10_MODE_ACTIVE ; 
 unsigned char DMARD10_MODE_OFF ; 
 unsigned char DMARD10_MODE_READ_OTP ; 
 unsigned char DMARD10_MODE_RESET_DATA_PATH ; 
 unsigned char DMARD10_MODE_STANDBY ; 
 unsigned char DMARD10_REG_ACTR ; 
 unsigned char DMARD10_REG_AFEM ; 
 unsigned char DMARD10_REG_MISC2 ; 
 unsigned char DMARD10_REG_PD ; 
 int /*<<< orphan*/  DMARD10_REG_STADR ; 
 int /*<<< orphan*/  DMARD10_REG_STAINT ; 
 unsigned char DMARD10_VALUE_AFEM_AFEN_NORMAL ; 
 unsigned char DMARD10_VALUE_CKSEL_ODR_100_204 ; 
 unsigned char DMARD10_VALUE_INTC ; 
 int /*<<< orphan*/  DMARD10_VALUE_MISC2_OSCA_EN ; 
 int /*<<< orphan*/  DMARD10_VALUE_PD_RST ; 
 int DMARD10_VALUE_STADR ; 
 int DMARD10_VALUE_STAINT ; 
 unsigned char DMARD10_VALUE_TAPNS_AVE_2 ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dmard10_channels ; 
 int /*<<< orphan*/  dmard10_info ; 
 int dmard10_nscale ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_send (struct i2c_client*,unsigned char*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,unsigned char,int /*<<< orphan*/ ) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct dmard10_data* iio_priv (struct iio_dev*) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int sign_extend32 (int,int) ; 

__attribute__((used)) static int dmard10_reset(struct i2c_client *client)
{
	unsigned char buffer[7];
	int ret;

	/* 1. Powerdown reset */
	ret = i2c_smbus_write_byte_data(client, DMARD10_REG_PD,
						DMARD10_VALUE_PD_RST);
	if (ret < 0)
		return ret;

	/*
	 * 2. ACTR => Standby mode => Download OTP to parameter reg =>
	 *    Standby mode => Reset data path => Standby mode
	 */
	buffer[0] = DMARD10_REG_ACTR;
	buffer[1] = DMARD10_MODE_STANDBY;
	buffer[2] = DMARD10_MODE_READ_OTP;
	buffer[3] = DMARD10_MODE_STANDBY;
	buffer[4] = DMARD10_MODE_RESET_DATA_PATH;
	buffer[5] = DMARD10_MODE_STANDBY;
	ret = i2c_master_send(client, buffer, 6);
	if (ret < 0)
		return ret;

	/* 3. OSCA_EN = 1, TSTO = b'000 (INT1 = normal, TEST0 = normal) */
	ret = i2c_smbus_write_byte_data(client, DMARD10_REG_MISC2,
						DMARD10_VALUE_MISC2_OSCA_EN);
	if (ret < 0)
		return ret;

	/* 4. AFEN = 1 (AFE will powerdown after ADC) */
	buffer[0] = DMARD10_REG_AFEM;
	buffer[1] = DMARD10_VALUE_AFEM_AFEN_NORMAL;
	buffer[2] = DMARD10_VALUE_CKSEL_ODR_100_204;
	buffer[3] = DMARD10_VALUE_INTC;
	buffer[4] = DMARD10_VALUE_TAPNS_AVE_2;
	buffer[5] = 0x00; /* DLYC, no delay timing */
	buffer[6] = 0x07; /* INTD=1 push-pull, INTA=1 active high, AUTOT=1 */
	ret = i2c_master_send(client, buffer, 7);
	if (ret < 0)
		return ret;

	/* 5. Activation mode */
	ret = i2c_smbus_write_byte_data(client, DMARD10_REG_ACTR,
						DMARD10_MODE_ACTIVE);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int dmard10_shutdown(struct i2c_client *client)
{
	unsigned char buffer[3];

	buffer[0] = DMARD10_REG_ACTR;
	buffer[1] = DMARD10_MODE_STANDBY;
	buffer[2] = DMARD10_MODE_OFF;

	return i2c_master_send(client, buffer, 3);
}

__attribute__((used)) static int dmard10_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct dmard10_data *data = iio_priv(indio_dev);
	__le16 buf[4];
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		/*
		 * Read 8 bytes starting at the REG_STADR register, trying to
		 * read the individual X, Y, Z registers will always read 0.
		 */
		ret = i2c_smbus_read_i2c_block_data(data->client,
						    DMARD10_REG_STADR,
						    sizeof(buf), (u8 *)buf);
		if (ret < 0)
			return ret;
		ret = le16_to_cpu(buf[chan->address]);
		*val = sign_extend32(ret, 12);
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 0;
		*val2 = dmard10_nscale;
		return IIO_VAL_INT_PLUS_NANO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int dmard10_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int ret;
	struct iio_dev *indio_dev;
	struct dmard10_data *data;

	/* These 2 registers have special POR reset values used for id */
	ret = i2c_smbus_read_byte_data(client, DMARD10_REG_STADR);
	if (ret != DMARD10_VALUE_STADR)
		return (ret < 0) ? ret : -ENODEV;

	ret = i2c_smbus_read_byte_data(client, DMARD10_REG_STAINT);
	if (ret != DMARD10_VALUE_STAINT)
		return (ret < 0) ? ret : -ENODEV;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev) {
		dev_err(&client->dev, "iio allocation failed!\n");
		return -ENOMEM;
	}

	data = iio_priv(indio_dev);
	data->client = client;
	i2c_set_clientdata(client, indio_dev);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &dmard10_info;
	indio_dev->name = "dmard10";
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = dmard10_channels;
	indio_dev->num_channels = ARRAY_SIZE(dmard10_channels);

	ret = dmard10_reset(client);
	if (ret < 0)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "device_register failed\n");
		dmard10_shutdown(client);
	}

	return ret;
}

__attribute__((used)) static int dmard10_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);

	return dmard10_shutdown(client);
}

