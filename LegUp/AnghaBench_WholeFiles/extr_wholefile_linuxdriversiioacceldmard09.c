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
struct iio_dev {int /*<<< orphan*/ * info; int /*<<< orphan*/  num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {size_t address; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct dmard09_data {struct i2c_client* client; } ;
typedef  int s16 ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int DMARD09_BUF_LEN ; 
 int DMARD09_CHIPID ; 
 int /*<<< orphan*/  DMARD09_DRV_NAME ; 
 int /*<<< orphan*/  DMARD09_REG_CHIPID ; 
 int DMARD09_REG_STAT ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 128 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* devm_iio_device_alloc (int /*<<< orphan*/ *,int) ; 
 int devm_iio_device_register (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  dmard09_channels ; 
 int /*<<< orphan*/  dmard09_info ; 
 int get_unaligned_le16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int,int,int /*<<< orphan*/ *) ; 
 struct dmard09_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int dmard09_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct dmard09_data *data = iio_priv(indio_dev);
	u8 buf[DMARD09_BUF_LEN];
	int ret;
	s16 accel;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		/*
		 * Read from the DMAR09_REG_STAT register, since the chip
		 * caches reads from the individual X, Y, Z registers.
		 */
		ret = i2c_smbus_read_i2c_block_data(data->client,
						    DMARD09_REG_STAT,
						    DMARD09_BUF_LEN, buf);
		if (ret < 0) {
			dev_err(&data->client->dev, "Error reading reg %d\n",
				DMARD09_REG_STAT);
			return ret;
		}

		accel = get_unaligned_le16(&buf[chan->address]);

		/* Remove lower 3 bits and sign extend */
		accel <<= 4;
		accel >>= 7;

		*val = accel;

		return IIO_VAL_INT;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int dmard09_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int ret;
	struct iio_dev *indio_dev;
	struct dmard09_data *data;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev) {
		dev_err(&client->dev, "iio allocation failed\n");
		return -ENOMEM;
	}

	data = iio_priv(indio_dev);
	data->client = client;

	ret = i2c_smbus_read_byte_data(data->client, DMARD09_REG_CHIPID);
	if (ret < 0) {
		dev_err(&client->dev, "Error reading chip id %d\n", ret);
		return ret;
	}

	if (ret != DMARD09_CHIPID) {
		dev_err(&client->dev, "Invalid chip id %d\n", ret);
		return -ENODEV;
	}

	i2c_set_clientdata(client, indio_dev);
	indio_dev->dev.parent = &client->dev;
	indio_dev->name = DMARD09_DRV_NAME;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = dmard09_channels;
	indio_dev->num_channels = ARRAY_SIZE(dmard09_channels);
	indio_dev->info = &dmard09_info;

	return devm_iio_device_register(&client->dev, indio_dev);
}

