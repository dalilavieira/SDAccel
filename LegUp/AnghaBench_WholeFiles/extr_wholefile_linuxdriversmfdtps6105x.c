#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct tps6105x_platform_data {int mode; } ;
struct tps6105x {int /*<<< orphan*/  regmap; struct tps6105x_platform_data* pdata; struct i2c_client* client; } ;
struct mfd_cell {int pdata_size; struct tps6105x* platform_data; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLATFORM_DEVID_AUTO ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
#define  TPS6105X_MODE_SHUTDOWN 135 
#define  TPS6105X_MODE_TORCH 134 
#define  TPS6105X_MODE_TORCH_FLASH 133 
#define  TPS6105X_MODE_VOLTAGE 132 
 int /*<<< orphan*/  TPS6105X_REG0_MODE_MASK ; 
 unsigned int TPS6105X_REG0_MODE_SHIFT ; 
#define  TPS6105X_REG0_MODE_SHUTDOWN 131 
#define  TPS6105X_REG0_MODE_TORCH 130 
#define  TPS6105X_REG0_MODE_TORCH_FLASH 129 
#define  TPS6105X_REG0_MODE_VOLTAGE 128 
 int /*<<< orphan*/  TPS6105X_REG_0 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct tps6105x_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 struct tps6105x* devm_kmalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct tps6105x* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct tps6105x*) ; 
 int mfd_add_devices (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct mfd_cell*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (int /*<<< orphan*/ *) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const) ; 
 struct mfd_cell tps6105x_flash_cell ; 
 struct mfd_cell tps6105x_gpio_cell ; 
 struct mfd_cell tps6105x_leds_cell ; 
 int /*<<< orphan*/  tps6105x_regmap_config ; 
 struct mfd_cell tps6105x_regulator_cell ; 

__attribute__((used)) static int tps6105x_startup(struct tps6105x *tps6105x)
{
	int ret;
	unsigned int regval;

	ret = regmap_read(tps6105x->regmap, TPS6105X_REG_0, &regval);
	if (ret)
		return ret;
	switch (regval >> TPS6105X_REG0_MODE_SHIFT) {
	case TPS6105X_REG0_MODE_SHUTDOWN:
		dev_info(&tps6105x->client->dev,
			 "TPS6105x found in SHUTDOWN mode\n");
		break;
	case TPS6105X_REG0_MODE_TORCH:
		dev_info(&tps6105x->client->dev,
			 "TPS6105x found in TORCH mode\n");
		break;
	case TPS6105X_REG0_MODE_TORCH_FLASH:
		dev_info(&tps6105x->client->dev,
			 "TPS6105x found in FLASH mode\n");
		break;
	case TPS6105X_REG0_MODE_VOLTAGE:
		dev_info(&tps6105x->client->dev,
			 "TPS6105x found in VOLTAGE mode\n");
		break;
	default:
		break;
	}

	return ret;
}

__attribute__((used)) static int tps6105x_add_device(struct tps6105x *tps6105x,
			       struct mfd_cell *cell)
{
	cell->platform_data = tps6105x;
	cell->pdata_size = sizeof(*tps6105x);

	return mfd_add_devices(&tps6105x->client->dev,
			       PLATFORM_DEVID_AUTO, cell, 1, NULL, 0, NULL);
}

__attribute__((used)) static int tps6105x_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct tps6105x			*tps6105x;
	struct tps6105x_platform_data	*pdata;
	int ret;

	pdata = dev_get_platdata(&client->dev);
	if (!pdata) {
		dev_err(&client->dev, "missing platform data\n");
		return -ENODEV;
	}

	tps6105x = devm_kmalloc(&client->dev, sizeof(*tps6105x), GFP_KERNEL);
	if (!tps6105x)
		return -ENOMEM;

	tps6105x->regmap = devm_regmap_init_i2c(client, &tps6105x_regmap_config);
	if (IS_ERR(tps6105x->regmap))
		return PTR_ERR(tps6105x->regmap);

	i2c_set_clientdata(client, tps6105x);
	tps6105x->client = client;
	tps6105x->pdata = pdata;

	ret = tps6105x_startup(tps6105x);
	if (ret) {
		dev_err(&client->dev, "chip initialization failed\n");
		return ret;
	}

	ret = tps6105x_add_device(tps6105x, &tps6105x_gpio_cell);
	if (ret)
		return ret;

	switch (pdata->mode) {
	case TPS6105X_MODE_SHUTDOWN:
		dev_info(&client->dev,
			 "present, not used for anything, only GPIO\n");
		break;
	case TPS6105X_MODE_TORCH:
		ret = tps6105x_add_device(tps6105x, &tps6105x_leds_cell);
		break;
	case TPS6105X_MODE_TORCH_FLASH:
		ret = tps6105x_add_device(tps6105x, &tps6105x_flash_cell);
		break;
	case TPS6105X_MODE_VOLTAGE:
		ret = tps6105x_add_device(tps6105x, &tps6105x_regulator_cell);
		break;
	default:
		dev_warn(&client->dev, "invalid mode: %d\n", pdata->mode);
		break;
	}

	if (ret)
		mfd_remove_devices(&client->dev);

	return ret;
}

__attribute__((used)) static int tps6105x_remove(struct i2c_client *client)
{
	struct tps6105x *tps6105x = i2c_get_clientdata(client);

	mfd_remove_devices(&client->dev);

	/* Put chip in shutdown mode */
	regmap_update_bits(tps6105x->regmap, TPS6105X_REG_0,
		TPS6105X_REG0_MODE_MASK,
		TPS6105X_MODE_SHUTDOWN << TPS6105X_REG0_MODE_SHIFT);

	return 0;
}

