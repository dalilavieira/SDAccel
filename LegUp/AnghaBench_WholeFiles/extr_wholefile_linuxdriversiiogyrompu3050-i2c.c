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
typedef  int /*<<< orphan*/  u32 ;
struct regmap {int dummy; } ;
struct mpu3050 {TYPE_1__* i2cmux; int /*<<< orphan*/  dev; } ;
struct iio_dev {int dummy; } ;
struct i2c_mux_core {int dummy; } ;
struct i2c_device_id {char* name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  irq; } ;
struct TYPE_4__ {struct mpu3050* priv; } ;

/* Variables and functions */
 int ENODEV ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int I2C_MUX_GATE ; 
 int I2C_MUX_LOCKED ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct iio_dev* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_mux_add_adapter (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__* i2c_mux_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int,int (*) (struct i2c_mux_core*,int /*<<< orphan*/ ),int (*) (struct i2c_mux_core*,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  i2c_mux_del_adapters (TYPE_1__*) ; 
 struct mpu3050* i2c_mux_priv (struct i2c_mux_core*) ; 
 struct mpu3050* iio_priv (struct iio_dev*) ; 
 int mpu3050_common_probe (int /*<<< orphan*/ *,struct regmap*,int /*<<< orphan*/ ,char const*) ; 
 int mpu3050_common_remove (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mpu3050_i2c_regmap_config ; 
 int /*<<< orphan*/  pm_runtime_get_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mpu3050_i2c_bypass_select(struct i2c_mux_core *mux, u32 chan_id)
{
	struct mpu3050 *mpu3050 = i2c_mux_priv(mux);

	/* Just power up the device, that is all that is needed */
	pm_runtime_get_sync(mpu3050->dev);
	return 0;
}

__attribute__((used)) static int mpu3050_i2c_bypass_deselect(struct i2c_mux_core *mux, u32 chan_id)
{
	struct mpu3050 *mpu3050 = i2c_mux_priv(mux);

	pm_runtime_mark_last_busy(mpu3050->dev);
	pm_runtime_put_autosuspend(mpu3050->dev);
	return 0;
}

__attribute__((used)) static int mpu3050_i2c_probe(struct i2c_client *client,
			     const struct i2c_device_id *id)
{
	struct regmap *regmap;
	const char *name;
	struct mpu3050 *mpu3050;
	int ret;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_I2C_BLOCK))
		return -EOPNOTSUPP;

	if (id)
		name = id->name;
	else
		return -ENODEV;

	regmap = devm_regmap_init_i2c(client, &mpu3050_i2c_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&client->dev, "Failed to register i2c regmap %d\n",
			(int)PTR_ERR(regmap));
		return PTR_ERR(regmap);
	}

	ret = mpu3050_common_probe(&client->dev, regmap, client->irq, name);
	if (ret)
		return ret;

	/* The main driver is up, now register the I2C mux */
	mpu3050 = iio_priv(dev_get_drvdata(&client->dev));
	mpu3050->i2cmux = i2c_mux_alloc(client->adapter, &client->dev,
					1, 0, I2C_MUX_LOCKED | I2C_MUX_GATE,
					mpu3050_i2c_bypass_select,
					mpu3050_i2c_bypass_deselect);
	/* Just fail the mux, there is no point in killing the driver */
	if (!mpu3050->i2cmux)
		dev_err(&client->dev, "failed to allocate I2C mux\n");
	else {
		mpu3050->i2cmux->priv = mpu3050;
		/* Ignore failure, not critical */
		i2c_mux_add_adapter(mpu3050->i2cmux, 0, 0, 0);
	}

	return 0;
}

__attribute__((used)) static int mpu3050_i2c_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = dev_get_drvdata(&client->dev);
	struct mpu3050 *mpu3050 = iio_priv(indio_dev);

	if (mpu3050->i2cmux)
		i2c_mux_del_adapters(mpu3050->i2cmux);

	return mpu3050_common_remove(&client->dev);
}

