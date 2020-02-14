#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct spi_device_id {char* name; scalar_t__ driver_data; } ;
struct TYPE_9__ {TYPE_3__* driver; } ;
struct spi_device {int /*<<< orphan*/  irq; TYPE_4__ dev; } ;
struct regmap {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  user_ctrl; } ;
struct inv_mpu6050_state {TYPE_2__ chip_config; TYPE_1__* reg; int /*<<< orphan*/  map; } ;
struct iio_dev {int dummy; } ;
struct acpi_device_id {scalar_t__ driver_data; } ;
typedef  enum inv_devices { ____Placeholder_inv_devices } inv_devices ;
struct TYPE_8__ {int /*<<< orphan*/  acpi_match_table; } ;
struct TYPE_6__ {int /*<<< orphan*/  user_ctrl; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  INV_MPU6050_BIT_I2C_IF_DIS ; 
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,int) ; 
 struct regmap* devm_regmap_init_spi (struct spi_device*,int /*<<< orphan*/ *) ; 
 struct inv_mpu6050_state* iio_priv (struct iio_dev*) ; 
 int inv_mpu6050_set_power_itg (struct inv_mpu6050_state*,int) ; 
 int inv_mpu_core_probe (struct regmap*,int /*<<< orphan*/ ,char const*,int (*) (struct iio_dev*),int) ; 
 int /*<<< orphan*/  inv_mpu_regmap_config ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct spi_device_id* spi_get_device_id (struct spi_device*) ; 

__attribute__((used)) static int inv_mpu_i2c_disable(struct iio_dev *indio_dev)
{
	struct inv_mpu6050_state *st = iio_priv(indio_dev);
	int ret = 0;

	ret = inv_mpu6050_set_power_itg(st, true);
	if (ret)
		return ret;

	st->chip_config.user_ctrl |= INV_MPU6050_BIT_I2C_IF_DIS;
	ret = regmap_write(st->map, st->reg->user_ctrl,
			   st->chip_config.user_ctrl);
	if (ret) {
		inv_mpu6050_set_power_itg(st, false);
		return ret;
	}

	return inv_mpu6050_set_power_itg(st, false);
}

__attribute__((used)) static int inv_mpu_probe(struct spi_device *spi)
{
	struct regmap *regmap;
	const struct spi_device_id *spi_id;
	const struct acpi_device_id *acpi_id;
	const char *name = NULL;
	enum inv_devices chip_type;

	if ((spi_id = spi_get_device_id(spi))) {
		chip_type = (enum inv_devices)spi_id->driver_data;
		name = spi_id->name;
	} else if ((acpi_id = acpi_match_device(spi->dev.driver->acpi_match_table, &spi->dev))) {
		chip_type = (enum inv_devices)acpi_id->driver_data;
	} else {
		return -ENODEV;
	}

	regmap = devm_regmap_init_spi(spi, &inv_mpu_regmap_config);
	if (IS_ERR(regmap)) {
		dev_err(&spi->dev, "Failed to register spi regmap %d\n",
			(int)PTR_ERR(regmap));
		return PTR_ERR(regmap);
	}

	return inv_mpu_core_probe(regmap, spi->irq, name,
				  inv_mpu_i2c_disable, chip_type);
}

