#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct of_device_id {int dummy; } ;
struct mcp4018_data {TYPE_2__* cfg; struct i2c_client* client; } ;
struct TYPE_5__ {struct device* parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  name; int /*<<< orphan*/ * channels; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  name; int /*<<< orphan*/  adapter; struct device dev; } ;
typedef  int s32 ;
struct TYPE_7__ {size_t driver_data; } ;
struct TYPE_6__ {int kohms; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int MCP4018_WIPER_MAX ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_4__* i2c_match_id (int /*<<< orphan*/ ,struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int i2c_smbus_read_byte (struct i2c_client*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int) ; 
 struct mcp4018_data* iio_priv (struct iio_dev*) ; 
 TYPE_2__* mcp4018_cfg ; 
 int /*<<< orphan*/  mcp4018_channel ; 
 int /*<<< orphan*/  mcp4018_id ; 
 int /*<<< orphan*/  mcp4018_info ; 
 int /*<<< orphan*/  mcp4018_of_match ; 
 TYPE_2__* of_device_get_match_data (struct device*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mcp4018_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct mcp4018_data *data = iio_priv(indio_dev);
	s32 ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = i2c_smbus_read_byte(data->client);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 1000 * data->cfg->kohms;
		*val2 = MCP4018_WIPER_MAX;
		return IIO_VAL_FRACTIONAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int mcp4018_write_raw(struct iio_dev *indio_dev,
			     struct iio_chan_spec const *chan,
			     int val, int val2, long mask)
{
	struct mcp4018_data *data = iio_priv(indio_dev);

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (val > MCP4018_WIPER_MAX || val < 0)
			return -EINVAL;
		break;
	default:
		return -EINVAL;
	}

	return i2c_smbus_write_byte(data->client, val);
}

__attribute__((used)) static int mcp4018_probe(struct i2c_client *client)
{
	struct device *dev = &client->dev;
	struct mcp4018_data *data;
	struct iio_dev *indio_dev;
	const struct of_device_id *match;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_BYTE)) {
		dev_err(dev, "SMBUS Byte transfers not supported\n");
		return -EOPNOTSUPP;
	}

	indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
	if (!indio_dev)
		return -ENOMEM;
	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;

	match = of_match_device(of_match_ptr(mcp4018_of_match), dev);
	if (match)
		data->cfg = of_device_get_match_data(dev);
	else
		data->cfg = &mcp4018_cfg[i2c_match_id(mcp4018_id, client)->driver_data];

	indio_dev->dev.parent = dev;
	indio_dev->info = &mcp4018_info;
	indio_dev->channels = &mcp4018_channel;
	indio_dev->num_channels = 1;
	indio_dev->name = client->name;

	return devm_iio_device_register(dev, indio_dev);
}

