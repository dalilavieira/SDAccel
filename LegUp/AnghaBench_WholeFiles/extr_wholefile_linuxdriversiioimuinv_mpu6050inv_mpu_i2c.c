#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct regmap {int dummy; } ;
struct inv_mpu6050_state {int irq_mask; int chip_type; TYPE_3__* muxc; int /*<<< orphan*/  lock; TYPE_1__* reg; int /*<<< orphan*/  map; } ;
struct iio_dev {int dummy; } ;
struct i2c_mux_core {int dummy; } ;
struct i2c_device_id {char* name; scalar_t__ driver_data; } ;
struct device {scalar_t__ of_node; TYPE_2__* driver; } ;
struct i2c_client {char* name; struct device dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  irq; } ;
struct acpi_device_id {scalar_t__ driver_data; } ;
typedef  enum inv_devices { ____Placeholder_inv_devices } inv_devices ;
struct TYPE_8__ {struct iio_dev* priv; } ;
struct TYPE_7__ {int /*<<< orphan*/  acpi_match_table; } ;
struct TYPE_6__ {int /*<<< orphan*/  int_pin_cfg; } ;

/* Variables and functions */
 scalar_t__ ACPI_HANDLE (struct device*) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int I2C_MUX_GATE ; 
 int I2C_MUX_LOCKED ; 
#define  INV_ICM20608 128 
 int INV_MPU6050_BIT_BYPASS_EN ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct iio_dev* dev_get_drvdata (struct device*) ; 
 char const* dev_name (struct device*) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_mux_add_adapter (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_3__* i2c_mux_alloc (int /*<<< orphan*/ ,struct device*,int,int /*<<< orphan*/ ,int,int (*) (struct i2c_mux_core*,int /*<<< orphan*/ ),int (*) (struct i2c_mux_core*,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  i2c_mux_del_adapters (TYPE_3__*) ; 
 struct iio_dev* i2c_mux_priv (struct i2c_mux_core*) ; 
 struct inv_mpu6050_state* iio_priv (struct iio_dev*) ; 
 int inv_mpu6050_set_power_itg (struct inv_mpu6050_state*,int) ; 
 int inv_mpu_acpi_create_mux_client (struct i2c_client*) ; 
 int /*<<< orphan*/  inv_mpu_acpi_delete_mux_client (struct i2c_client*) ; 
 int inv_mpu_core_probe (struct regmap*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  inv_mpu_regmap_config ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ of_device_get_match_data (struct device*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int inv_mpu6050_select_bypass(struct i2c_mux_core *muxc, u32 chan_id)
{
	struct iio_dev *indio_dev = i2c_mux_priv(muxc);
	struct inv_mpu6050_state *st = iio_priv(indio_dev);
	int ret;

	mutex_lock(&st->lock);

	ret = inv_mpu6050_set_power_itg(st, true);
	if (ret)
		goto error_unlock;

	ret = regmap_write(st->map, st->reg->int_pin_cfg,
			   st->irq_mask | INV_MPU6050_BIT_BYPASS_EN);

error_unlock:
	mutex_unlock(&st->lock);

	return ret;
}

__attribute__((used)) static int inv_mpu6050_deselect_bypass(struct i2c_mux_core *muxc, u32 chan_id)
{
	struct iio_dev *indio_dev = i2c_mux_priv(muxc);
	struct inv_mpu6050_state *st = iio_priv(indio_dev);

	mutex_lock(&st->lock);

	/* It doesn't really matter if any of the calls fail */
	regmap_write(st->map, st->reg->int_pin_cfg, st->irq_mask);
	inv_mpu6050_set_power_itg(st, false);

	mutex_unlock(&st->lock);

	return 0;
}

__attribute__((used)) static const char *inv_mpu_match_acpi_device(struct device *dev,
					     enum inv_devices *chip_id)
{
	const struct acpi_device_id *id;

	id = acpi_match_device(dev->driver->acpi_match_table, dev);
	if (!id)
		return NULL;

	*chip_id = (int)id->driver_data;

	return dev_name(dev);
}

__attribute__((used)) static int inv_mpu_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	struct inv_mpu6050_state *st;
	int result;
	enum inv_devices chip_type;
	struct regmap *regmap;
	const char *name;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_I2C_BLOCK))
		return -EOPNOTSUPP;

	if (client->dev.of_node) {
		chip_type = (enum inv_devices)
			of_device_get_match_data(&client->dev);
		name = client->name;
	} else if (id) {
		chip_type = (enum inv_devices)
			id->driver_data;
		name = id->name;
	} else if (ACPI_HANDLE(&client->dev)) {
		name = inv_mpu_match_acpi_device(&client->dev, &chip_type);
		if (!name)
			return -ENODEV;
	} else {
		return -ENOSYS;
	}

	regmap = devm_regmap_init_i2c(client, &inv_mpu_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&client->dev, "Failed to register i2c regmap %d\n",
			(int)PTR_ERR(regmap));
		return PTR_ERR(regmap);
	}

	result = inv_mpu_core_probe(regmap, client->irq, name,
				    NULL, chip_type);
	if (result < 0)
		return result;

	st = iio_priv(dev_get_drvdata(&client->dev));
	switch (st->chip_type) {
	case INV_ICM20608:
		/* no i2c auxiliary bus on the chip */
		break;
	default:
		/* declare i2c auxiliary bus */
		st->muxc = i2c_mux_alloc(client->adapter, &client->dev,
					 1, 0, I2C_MUX_LOCKED | I2C_MUX_GATE,
					 inv_mpu6050_select_bypass,
					 inv_mpu6050_deselect_bypass);
		if (!st->muxc)
			return -ENOMEM;
		st->muxc->priv = dev_get_drvdata(&client->dev);
		result = i2c_mux_add_adapter(st->muxc, 0, 0, 0);
		if (result)
			return result;
		result = inv_mpu_acpi_create_mux_client(client);
		if (result)
			goto out_del_mux;
		break;
	}

	return 0;

out_del_mux:
	i2c_mux_del_adapters(st->muxc);
	return result;
}

__attribute__((used)) static int inv_mpu_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);
	struct inv_mpu6050_state *st = iio_priv(indio_dev);

	if (st->muxc) {
		inv_mpu_acpi_delete_mux_client(client);
		i2c_mux_del_adapters(st->muxc);
	}

	return 0;
}

