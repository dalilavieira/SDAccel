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
struct mcp4725_platform_data {scalar_t__ use_vref; scalar_t__ vref_buffered; } ;
struct mcp4725_data {int powerdown_mode; int powerdown; int dac_value; int ref_mode; int id; void* vdd_reg; void* vref_reg; struct i2c_client* client; } ;
struct TYPE_2__ {struct device* parent; } ;
struct iio_dev {int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * channels; int /*<<< orphan*/ * info; int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct iio_chan_spec {int dummy; } ;
struct i2c_device_id {size_t driver_data; int /*<<< orphan*/  name; } ;
struct device {scalar_t__ of_node; } ;
struct i2c_client {struct device dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  enum chip_id { ____Placeholder_chip_id } chip_id ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (void*) ; 
 scalar_t__ MCP4725 ; 
 scalar_t__ MCP4726 ; 
 int MCP472X_REF_VDD ; 
 int MCP472X_REF_VREF_BUFFERED ; 
 int MCP472X_REF_VREF_UNBUFFERED ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct mcp4725_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int,int,int) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 void* devm_regulator_get (struct device*,char*) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_recv (struct i2c_client*,int*,int) ; 
 int i2c_master_send (struct i2c_client*,int*,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct mcp4725_data* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mcp4725_info ; 
 int /*<<< orphan*/ * mcp472x_channel ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ of_device_get_match_data (struct device*) ; 
 int /*<<< orphan*/  regulator_disable (void*) ; 
 int regulator_enable (void*) ; 
 int regulator_get_voltage (void*) ; 
 int sprintf (char*,char*,int) ; 
 int strtobool (char const*,int*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

__attribute__((used)) static int mcp4725_suspend(struct device *dev)
{
	struct mcp4725_data *data = iio_priv(i2c_get_clientdata(
		to_i2c_client(dev)));
	u8 outbuf[2];

	outbuf[0] = (data->powerdown_mode + 1) << 4;
	outbuf[1] = 0;
	data->powerdown = true;

	return i2c_master_send(data->client, outbuf, 2);
}

__attribute__((used)) static int mcp4725_resume(struct device *dev)
{
	struct mcp4725_data *data = iio_priv(i2c_get_clientdata(
		to_i2c_client(dev)));
	u8 outbuf[2];

	/* restore previous DAC value */
	outbuf[0] = (data->dac_value >> 8) & 0xf;
	outbuf[1] = data->dac_value & 0xff;
	data->powerdown = false;

	return i2c_master_send(data->client, outbuf, 2);
}

__attribute__((used)) static ssize_t mcp4725_store_eeprom(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	struct iio_dev *indio_dev = dev_to_iio_dev(dev);
	struct mcp4725_data *data = iio_priv(indio_dev);
	int tries = 20;
	u8 inoutbuf[3];
	bool state;
	int ret;

	ret = strtobool(buf, &state);
	if (ret < 0)
		return ret;

	if (!state)
		return 0;

	inoutbuf[0] = 0x60; /* write EEPROM */
	inoutbuf[0] |= data->ref_mode << 3;
	inoutbuf[0] |= data->powerdown ? ((data->powerdown_mode + 1) << 1) : 0;
	inoutbuf[1] = data->dac_value >> 4;
	inoutbuf[2] = (data->dac_value & 0xf) << 4;

	ret = i2c_master_send(data->client, inoutbuf, 3);
	if (ret < 0)
		return ret;
	else if (ret != 3)
		return -EIO;

	/* wait for write complete, takes up to 50ms */
	while (tries--) {
		msleep(20);
		ret = i2c_master_recv(data->client, inoutbuf, 3);
		if (ret < 0)
			return ret;
		else if (ret != 3)
			return -EIO;

		if (inoutbuf[0] & 0x80)
			break;
	}

	if (tries < 0) {
		dev_err(&data->client->dev,
			"mcp4725_store_eeprom() failed, incomplete\n");
		return -EIO;
	}

	return len;
}

__attribute__((used)) static int mcp4725_get_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan)
{
	struct mcp4725_data *data = iio_priv(indio_dev);

	return data->powerdown_mode;
}

__attribute__((used)) static int mcp4725_set_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, unsigned mode)
{
	struct mcp4725_data *data = iio_priv(indio_dev);

	data->powerdown_mode = mode;

	return 0;
}

__attribute__((used)) static ssize_t mcp4725_read_powerdown(struct iio_dev *indio_dev,
	uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
	struct mcp4725_data *data = iio_priv(indio_dev);

	return sprintf(buf, "%d\n", data->powerdown);
}

__attribute__((used)) static ssize_t mcp4725_write_powerdown(struct iio_dev *indio_dev,
	 uintptr_t private, const struct iio_chan_spec *chan,
	 const char *buf, size_t len)
{
	struct mcp4725_data *data = iio_priv(indio_dev);
	bool state;
	int ret;

	ret = strtobool(buf, &state);
	if (ret)
		return ret;

	if (state)
		ret = mcp4725_suspend(&data->client->dev);
	else
		ret = mcp4725_resume(&data->client->dev);
	if (ret < 0)
		return ret;

	return len;
}

__attribute__((used)) static int mcp4725_set_value(struct iio_dev *indio_dev, int val)
{
	struct mcp4725_data *data = iio_priv(indio_dev);
	u8 outbuf[2];
	int ret;

	if (val >= (1 << 12) || val < 0)
		return -EINVAL;

	outbuf[0] = (val >> 8) & 0xf;
	outbuf[1] = val & 0xff;

	ret = i2c_master_send(data->client, outbuf, 2);
	if (ret < 0)
		return ret;
	else if (ret != 2)
		return -EIO;
	else
		return 0;
}

__attribute__((used)) static int mcp4726_set_cfg(struct iio_dev *indio_dev)
{
	struct mcp4725_data *data = iio_priv(indio_dev);
	u8 outbuf[3];
	int ret;

	outbuf[0] = 0x40;
	outbuf[0] |= data->ref_mode << 3;
	if (data->powerdown)
		outbuf[0] |= data->powerdown << 1;
	outbuf[1] = data->dac_value >> 4;
	outbuf[2] = (data->dac_value & 0xf) << 4;

	ret = i2c_master_send(data->client, outbuf, 3);
	if (ret < 0)
		return ret;
	else if (ret != 3)
		return -EIO;
	else
		return 0;
}

__attribute__((used)) static int mcp4725_read_raw(struct iio_dev *indio_dev,
			   struct iio_chan_spec const *chan,
			   int *val, int *val2, long mask)
{
	struct mcp4725_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		*val = data->dac_value;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		if (data->ref_mode == MCP472X_REF_VDD)
			ret = regulator_get_voltage(data->vdd_reg);
		else
			ret = regulator_get_voltage(data->vref_reg);

		if (ret < 0)
			return ret;

		*val = ret / 1000;
		*val2 = 12;
		return IIO_VAL_FRACTIONAL_LOG2;
	}
	return -EINVAL;
}

__attribute__((used)) static int mcp4725_write_raw(struct iio_dev *indio_dev,
			       struct iio_chan_spec const *chan,
			       int val, int val2, long mask)
{
	struct mcp4725_data *data = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = mcp4725_set_value(indio_dev, val);
		data->dac_value = val;
		break;
	default:
		ret = -EINVAL;
		break;
	}

	return ret;
}

__attribute__((used)) static int mcp4725_probe_dt(struct device *dev,
			    struct mcp4725_platform_data *platform_data)
{
	return -ENODEV;
}

__attribute__((used)) static int mcp4725_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct mcp4725_data *data;
	struct iio_dev *indio_dev;
	struct mcp4725_platform_data *pdata, pdata_dt;
	u8 inbuf[4];
	u8 pd;
	u8 ref;
	int err;

	indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
	if (indio_dev == NULL)
		return -ENOMEM;
	data = iio_priv(indio_dev);
	i2c_set_clientdata(client, indio_dev);
	data->client = client;
	if (client->dev.of_node)
		data->id = (enum chip_id)of_device_get_match_data(&client->dev);
	else
		data->id = id->driver_data;
	pdata = dev_get_platdata(&client->dev);

	if (!pdata) {
		err = mcp4725_probe_dt(&client->dev, &pdata_dt);
		if (err) {
			dev_err(&client->dev,
				"invalid platform or devicetree data");
			return err;
		}
		pdata = &pdata_dt;
	}

	if (data->id == MCP4725 && pdata->use_vref) {
		dev_err(&client->dev,
			"external reference is unavailable on MCP4725");
		return -EINVAL;
	}

	if (!pdata->use_vref && pdata->vref_buffered) {
		dev_err(&client->dev,
			"buffering is unavailable on the internal reference");
		return -EINVAL;
	}

	if (!pdata->use_vref)
		data->ref_mode = MCP472X_REF_VDD;
	else
		data->ref_mode = pdata->vref_buffered ?
			MCP472X_REF_VREF_BUFFERED :
			MCP472X_REF_VREF_UNBUFFERED;

	data->vdd_reg = devm_regulator_get(&client->dev, "vdd");
	if (IS_ERR(data->vdd_reg))
		return PTR_ERR(data->vdd_reg);

	err = regulator_enable(data->vdd_reg);
	if (err)
		return err;

	if (pdata->use_vref) {
		data->vref_reg = devm_regulator_get(&client->dev, "vref");
		if (IS_ERR(data->vref_reg)) {
			err = PTR_ERR(data->vref_reg);
			goto err_disable_vdd_reg;
		}

		err = regulator_enable(data->vref_reg);
		if (err)
			goto err_disable_vdd_reg;
	}

	indio_dev->dev.parent = &client->dev;
	indio_dev->name = id->name;
	indio_dev->info = &mcp4725_info;
	indio_dev->channels = &mcp472x_channel[id->driver_data];
	indio_dev->num_channels = 1;
	indio_dev->modes = INDIO_DIRECT_MODE;

	/* read current DAC value and settings */
	err = i2c_master_recv(client, inbuf, data->id == MCP4725 ? 3 : 4);

	if (err < 0) {
		dev_err(&client->dev, "failed to read DAC value");
		goto err_disable_vref_reg;
	}
	pd = (inbuf[0] >> 1) & 0x3;
	data->powerdown = pd > 0;
	data->powerdown_mode = pd ? pd - 1 : 2; /* largest resistor to gnd */
	data->dac_value = (inbuf[1] << 4) | (inbuf[2] >> 4);
	if (data->id == MCP4726)
		ref = (inbuf[3] >> 3) & 0x3;

	if (data->id == MCP4726 && ref != data->ref_mode) {
		dev_info(&client->dev,
			"voltage reference mode differs (conf: %u, eeprom: %u), setting %u",
			data->ref_mode, ref, data->ref_mode);
		err = mcp4726_set_cfg(indio_dev);
		if (err < 0)
			goto err_disable_vref_reg;
	}
 
	err = iio_device_register(indio_dev);
	if (err)
		goto err_disable_vref_reg;

	return 0;

err_disable_vref_reg:
	if (data->vref_reg)
		regulator_disable(data->vref_reg);

err_disable_vdd_reg:
	regulator_disable(data->vdd_reg);

	return err;
}

__attribute__((used)) static int mcp4725_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct mcp4725_data *data = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);

	if (data->vref_reg)
		regulator_disable(data->vref_reg);
	regulator_disable(data->vdd_reg);

	return 0;
}

