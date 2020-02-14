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
typedef  int u8 ;
struct regulator_dev {int dummy; } ;
struct regulator_config {struct regulator_dev* ena_gpiod; scalar_t__ of_node; struct max8952_data* driver_data; TYPE_2__* init_data; struct device* dev; } ;
struct max8952_platform_data {int* dvs_mode; int gpio_vid0; int gpio_vid1; int default_mode; int sync_freq; int ramp_speed; TYPE_2__* reg_data; } ;
struct max8952_data {unsigned int vid0; unsigned int vid1; struct max8952_platform_data* pdata; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct device {scalar_t__ of_node; int /*<<< orphan*/  parent; } ;
struct i2c_client {struct device dev; } ;
struct i2c_adapter {int dummy; } ;
typedef  struct regulator_dev gpio_desc ;
typedef  enum gpiod_flags { ____Placeholder_gpiod_flags } gpiod_flags ;
struct TYPE_3__ {scalar_t__ boot_on; } ;
struct TYPE_4__ {TYPE_1__ constraints; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIOD_OUT_HIGH ; 
 int GPIOD_OUT_LOW ; 
 unsigned long GPIOF_OUT_INIT_HIGH ; 
 unsigned long GPIOF_OUT_INIT_LOW ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int MAX8952_REG_CONTROL ; 
 int MAX8952_REG_MODE0 ; 
 int MAX8952_REG_MODE1 ; 
 int MAX8952_REG_MODE2 ; 
 int MAX8952_REG_MODE3 ; 
 int MAX8952_REG_RAMP ; 
 int MAX8952_REG_SYNC ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct max8952_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 scalar_t__ devm_gpio_request_one (struct device*,int,unsigned long,char*) ; 
 struct regulator_dev* devm_gpiod_get_optional (struct device*,char*,int) ; 
 struct max8952_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (struct device*,int /*<<< orphan*/ *,struct regulator_config*) ; 
 scalar_t__ gpio_is_valid (int) ; 
 int /*<<< orphan*/  gpio_set_value (int,unsigned int) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct max8952_data*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 struct max8952_data* rdev_get_drvdata (struct regulator_dev*) ; 
 scalar_t__ rdev_get_id (struct regulator_dev*) ; 
 int /*<<< orphan*/  regulator ; 
 struct i2c_adapter* to_i2c_adapter (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int max8952_read_reg(struct max8952_data *max8952, u8 reg)
{
	int ret = i2c_smbus_read_byte_data(max8952->client, reg);

	if (ret > 0)
		ret &= 0xff;

	return ret;
}

__attribute__((used)) static int max8952_write_reg(struct max8952_data *max8952,
		u8 reg, u8 value)
{
	return i2c_smbus_write_byte_data(max8952->client, reg, value);
}

__attribute__((used)) static int max8952_list_voltage(struct regulator_dev *rdev,
		unsigned int selector)
{
	struct max8952_data *max8952 = rdev_get_drvdata(rdev);

	if (rdev_get_id(rdev) != 0)
		return -EINVAL;

	return (max8952->pdata->dvs_mode[selector] * 10 + 770) * 1000;
}

__attribute__((used)) static int max8952_get_voltage_sel(struct regulator_dev *rdev)
{
	struct max8952_data *max8952 = rdev_get_drvdata(rdev);
	u8 vid = 0;

	if (max8952->vid0)
		vid += 1;
	if (max8952->vid1)
		vid += 2;

	return vid;
}

__attribute__((used)) static int max8952_set_voltage_sel(struct regulator_dev *rdev,
				   unsigned selector)
{
	struct max8952_data *max8952 = rdev_get_drvdata(rdev);

	if (!gpio_is_valid(max8952->pdata->gpio_vid0) ||
			!gpio_is_valid(max8952->pdata->gpio_vid1)) {
		/* DVS not supported */
		return -EPERM;
	}

	max8952->vid0 = selector & 0x1;
	max8952->vid1 = (selector >> 1) & 0x1;
	gpio_set_value(max8952->pdata->gpio_vid0, max8952->vid0);
	gpio_set_value(max8952->pdata->gpio_vid1, max8952->vid1);

	return 0;
}

__attribute__((used)) static struct max8952_platform_data *max8952_parse_dt(struct device *dev)
{
	return NULL;
}

__attribute__((used)) static int max8952_pmic_probe(struct i2c_client *client,
		const struct i2c_device_id *i2c_id)
{
	struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
	struct max8952_platform_data *pdata = dev_get_platdata(&client->dev);
	struct regulator_config config = { };
	struct max8952_data *max8952;
	struct regulator_dev *rdev;
	struct gpio_desc *gpiod;
	enum gpiod_flags gflags;

	int ret = 0, err = 0;

	if (client->dev.of_node)
		pdata = max8952_parse_dt(&client->dev);

	if (!pdata) {
		dev_err(&client->dev, "Require the platform data\n");
		return -EINVAL;
	}

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE))
		return -EIO;

	max8952 = devm_kzalloc(&client->dev, sizeof(struct max8952_data),
			       GFP_KERNEL);
	if (!max8952)
		return -ENOMEM;

	max8952->client = client;
	max8952->pdata = pdata;

	config.dev = &client->dev;
	config.init_data = pdata->reg_data;
	config.driver_data = max8952;
	config.of_node = client->dev.of_node;

	if (pdata->reg_data->constraints.boot_on)
		gflags = GPIOD_OUT_HIGH;
	else
		gflags = GPIOD_OUT_LOW;
	gpiod = devm_gpiod_get_optional(&client->dev,
					"max8952,en",
					gflags);
	if (IS_ERR(gpiod))
		return PTR_ERR(gpiod);
	if (gpiod)
		config.ena_gpiod = gpiod;

	rdev = devm_regulator_register(&client->dev, &regulator, &config);
	if (IS_ERR(rdev)) {
		ret = PTR_ERR(rdev);
		dev_err(&client->dev, "regulator init failed (%d)\n", ret);
		return ret;
	}

	max8952->vid0 = pdata->default_mode & 0x1;
	max8952->vid1 = (pdata->default_mode >> 1) & 0x1;

	if (gpio_is_valid(pdata->gpio_vid0) &&
			gpio_is_valid(pdata->gpio_vid1)) {
		unsigned long gpio_flags;

		gpio_flags = max8952->vid0 ?
			     GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
		if (devm_gpio_request_one(&client->dev, pdata->gpio_vid0,
					  gpio_flags, "MAX8952 VID0"))
			err = 1;

		gpio_flags = max8952->vid1 ?
			     GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
		if (devm_gpio_request_one(&client->dev, pdata->gpio_vid1,
					  gpio_flags, "MAX8952 VID1"))
			err = 2;
	} else
		err = 3;

	if (err) {
		dev_warn(&client->dev, "VID0/1 gpio invalid: "
				"DVS not available.\n");
		max8952->vid0 = 0;
		max8952->vid1 = 0;
		/* Mark invalid */
		pdata->gpio_vid0 = -1;
		pdata->gpio_vid1 = -1;

		/* Disable Pulldown of EN only */
		max8952_write_reg(max8952, MAX8952_REG_CONTROL, 0x60);

		dev_err(&client->dev, "DVS modes disabled because VID0 and VID1"
				" do not have proper controls.\n");
	} else {
		/*
		 * Disable Pulldown on EN, VID0, VID1 to reduce
		 * leakage current of MAX8952 assuming that MAX8952
		 * is turned on (EN==1). Note that without having VID0/1
		 * properly connected, turning pulldown off can be
		 * problematic. Thus, turn this off only when they are
		 * controllable by GPIO.
		 */
		max8952_write_reg(max8952, MAX8952_REG_CONTROL, 0x0);
	}

	max8952_write_reg(max8952, MAX8952_REG_MODE0,
			(max8952_read_reg(max8952,
					  MAX8952_REG_MODE0) & 0xC0) |
			(pdata->dvs_mode[0] & 0x3F));
	max8952_write_reg(max8952, MAX8952_REG_MODE1,
			(max8952_read_reg(max8952,
					  MAX8952_REG_MODE1) & 0xC0) |
			(pdata->dvs_mode[1] & 0x3F));
	max8952_write_reg(max8952, MAX8952_REG_MODE2,
			(max8952_read_reg(max8952,
					  MAX8952_REG_MODE2) & 0xC0) |
			(pdata->dvs_mode[2] & 0x3F));
	max8952_write_reg(max8952, MAX8952_REG_MODE3,
			(max8952_read_reg(max8952,
					  MAX8952_REG_MODE3) & 0xC0) |
			(pdata->dvs_mode[3] & 0x3F));

	max8952_write_reg(max8952, MAX8952_REG_SYNC,
			(max8952_read_reg(max8952, MAX8952_REG_SYNC) & 0x3F) |
			((pdata->sync_freq & 0x3) << 6));
	max8952_write_reg(max8952, MAX8952_REG_RAMP,
			(max8952_read_reg(max8952, MAX8952_REG_RAMP) & 0x1F) |
			((pdata->ramp_speed & 0x7) << 5));

	i2c_set_clientdata(client, max8952);

	return 0;
}

