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
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_4__ {struct device* parent; } ;
struct iio_dev {char* name; int num_channels; int /*<<< orphan*/  channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_2__ dev; } ;
struct iio_chan_spec {int /*<<< orphan*/  address; } ;
struct i2c_device_id {int driver_data; } ;
struct device {TYPE_1__* driver; } ;
struct i2c_client {struct device dev; } ;
struct da280_data {struct i2c_client* client; } ;
struct acpi_device_id {int /*<<< orphan*/  driver_data; } ;
typedef  enum da280_chipset { ____Placeholder_da280_chipset } da280_chipset ;
struct TYPE_3__ {int /*<<< orphan*/  acpi_match_table; } ;

/* Variables and functions */
 scalar_t__ ACPI_HANDLE (struct device*) ; 
 int DA280_CHIP_ID ; 
 int /*<<< orphan*/  DA280_MODE_DISABLE ; 
 int /*<<< orphan*/  DA280_MODE_ENABLE ; 
 int /*<<< orphan*/  DA280_REG_CHIP_ID ; 
 int /*<<< orphan*/  DA280_REG_MODE_BW ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_INT ; 
 int IIO_VAL_INT_PLUS_NANO ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int da226 ; 
 int /*<<< orphan*/  da280_channels ; 
 int /*<<< orphan*/  da280_info ; 
 int da280_nscale ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct da280_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int da280_enable(struct i2c_client *client, bool enable)
{
	u8 data = enable ? DA280_MODE_ENABLE : DA280_MODE_DISABLE;

	return i2c_smbus_write_byte_data(client, DA280_REG_MODE_BW, data);
}

__attribute__((used)) static int da280_read_raw(struct iio_dev *indio_dev,
				struct iio_chan_spec const *chan,
				int *val, int *val2, long mask)
{
	struct da280_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = i2c_smbus_read_word_data(data->client, chan->address);
		if (ret < 0)
			return ret;
		/*
		 * Values are 14 bits, stored as 16 bits with the 2
		 * least significant bits always 0.
		 */
		*val = (short)ret >> 2;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 0;
		*val2 = da280_nscale;
		return IIO_VAL_INT_PLUS_NANO;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static enum da280_chipset da280_match_acpi_device(struct device *dev)
{
	const struct acpi_device_id *id;

	id = acpi_match_device(dev->driver->acpi_match_table, dev);
	if (!id)
		return -EINVAL;

	return (enum da280_chipset) id->driver_data;
}

__attribute__((used)) static int da280_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int ret;
	struct iio_dev *indio_dev;
	struct da280_data *data;
	enum da280_chipset chip;

	ret = i2c_smbus_read_byte_data(client, DA280_REG_CHIP_ID);
	if (ret != DA280_CHIP_ID)
		return (ret < 0) ? ret : -ENODEV;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;

	data = iio_priv(indio_dev);
	data->client = client;
	i2c_set_clientdata(client, indio_dev);

	indio_dev->dev.parent = &client->dev;
	indio_dev->info = &da280_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = da280_channels;

	if (ACPI_HANDLE(&client->dev)) {
		chip = da280_match_acpi_device(&client->dev);
	} else {
		chip = id->driver_data;
	}

	if (chip == da226) {
		indio_dev->name = "da226";
		indio_dev->num_channels = 2;
	} else {
		indio_dev->name = "da280";
		indio_dev->num_channels = 3;
	}

	ret = da280_enable(client, true);
	if (ret < 0)
		return ret;

	ret = iio_device_register(indio_dev);
	if (ret < 0) {
		dev_err(&client->dev, "device_register failed\n");
		da280_enable(client, false);
	}

	return ret;
}

__attribute__((used)) static int da280_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);

	return da280_enable(client, false);
}

