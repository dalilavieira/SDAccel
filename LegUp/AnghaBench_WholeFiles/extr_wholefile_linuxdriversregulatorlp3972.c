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
typedef  int u8 ;
typedef  int u16 ;
struct regulator_dev {int dummy; } ;
struct regulator_config {struct lp3972* driver_data; int /*<<< orphan*/  init_data; int /*<<< orphan*/ * dev; } ;
struct lp3972_regulator_subdev {size_t id; int /*<<< orphan*/  initdata; } ;
struct lp3972_platform_data {int num_regulators; struct lp3972_regulator_subdev* regulators; } ;
struct lp3972 {int /*<<< orphan*/  io_lock; int /*<<< orphan*/ * dev; struct i2c_client* i2c; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int LP3972_BUCK_VOL1_REG (int) ; 
 int LP3972_BUCK_VOL_ENABLE_REG (int) ; 
 int LP3972_BUCK_VOL_MASK ; 
 int LP3972_DCDC1 ; 
#define  LP3972_LDO1 129 
#define  LP3972_LDO5 128 
 int LP3972_LDO_OUTPUT_ENABLE_MASK (int) ; 
 int LP3972_LDO_OUTPUT_ENABLE_REG (int) ; 
 int LP3972_LDO_VOL_CHANGE_SHIFT (int) ; 
 int LP3972_LDO_VOL_CONTR_REG (int) ; 
 int LP3972_LDO_VOL_CONTR_SHIFT (int) ; 
 int LP3972_LDO_VOL_MASK (int) ; 
 char LP3972_SYS_CONTROL1_REG ; 
 int LP3972_VOL_CHANGE_FLAG_GO ; 
 int LP3972_VOL_CHANGE_FLAG_MASK ; 
 int LP3972_VOL_CHANGE_REG ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int SYS_CONTROL1_INIT_MASK ; 
 int SYS_CONTROL1_INIT_VAL ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct lp3972_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct lp3972* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct regulator_config*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lp3972*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,char) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,char,int const) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct lp3972* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int /*<<< orphan*/ * regulators ; 

__attribute__((used)) static int lp3972_i2c_read(struct i2c_client *i2c, char reg, int count,
	u16 *dest)
{
	int ret;

	if (count != 1)
		return -EIO;
	ret = i2c_smbus_read_byte_data(i2c, reg);
	if (ret < 0)
		return ret;

	*dest = ret;
	return 0;
}

__attribute__((used)) static int lp3972_i2c_write(struct i2c_client *i2c, char reg, int count,
	const u16 *src)
{
	if (count != 1)
		return -EIO;
	return i2c_smbus_write_byte_data(i2c, reg, *src);
}

__attribute__((used)) static u8 lp3972_reg_read(struct lp3972 *lp3972, u8 reg)
{
	u16 val = 0;

	mutex_lock(&lp3972->io_lock);

	lp3972_i2c_read(lp3972->i2c, reg, 1, &val);

	dev_dbg(lp3972->dev, "reg read 0x%02x -> 0x%02x\n", (int)reg,
		(unsigned)val & 0xff);

	mutex_unlock(&lp3972->io_lock);

	return val & 0xff;
}

__attribute__((used)) static int lp3972_set_bits(struct lp3972 *lp3972, u8 reg, u16 mask, u16 val)
{
	u16 tmp;
	int ret;

	mutex_lock(&lp3972->io_lock);

	ret = lp3972_i2c_read(lp3972->i2c, reg, 1, &tmp);
	if (ret == 0) {
		tmp = (tmp & ~mask) | val;
		ret = lp3972_i2c_write(lp3972->i2c, reg, 1, &tmp);
		dev_dbg(lp3972->dev, "reg write 0x%02x -> 0x%02x\n", (int)reg,
			(unsigned)val & 0xff);
	}
	mutex_unlock(&lp3972->io_lock);

	return ret;
}

__attribute__((used)) static int lp3972_ldo_is_enabled(struct regulator_dev *dev)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3972_LDO1;
	u16 mask = LP3972_LDO_OUTPUT_ENABLE_MASK(ldo);
	u16 val;

	val = lp3972_reg_read(lp3972, LP3972_LDO_OUTPUT_ENABLE_REG(ldo));
	return !!(val & mask);
}

__attribute__((used)) static int lp3972_ldo_enable(struct regulator_dev *dev)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3972_LDO1;
	u16 mask = LP3972_LDO_OUTPUT_ENABLE_MASK(ldo);

	return lp3972_set_bits(lp3972, LP3972_LDO_OUTPUT_ENABLE_REG(ldo),
				mask, mask);
}

__attribute__((used)) static int lp3972_ldo_disable(struct regulator_dev *dev)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3972_LDO1;
	u16 mask = LP3972_LDO_OUTPUT_ENABLE_MASK(ldo);

	return lp3972_set_bits(lp3972, LP3972_LDO_OUTPUT_ENABLE_REG(ldo),
				mask, 0);
}

__attribute__((used)) static int lp3972_ldo_get_voltage_sel(struct regulator_dev *dev)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3972_LDO1;
	u16 mask = LP3972_LDO_VOL_MASK(ldo);
	u16 val, reg;

	reg = lp3972_reg_read(lp3972, LP3972_LDO_VOL_CONTR_REG(ldo));
	val = (reg >> LP3972_LDO_VOL_CONTR_SHIFT(ldo)) & mask;

	return val;
}

__attribute__((used)) static int lp3972_ldo_set_voltage_sel(struct regulator_dev *dev,
				      unsigned int selector)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3972_LDO1;
	int shift, ret;

	shift = LP3972_LDO_VOL_CONTR_SHIFT(ldo);
	ret = lp3972_set_bits(lp3972, LP3972_LDO_VOL_CONTR_REG(ldo),
		LP3972_LDO_VOL_MASK(ldo) << shift, selector << shift);

	if (ret)
		return ret;

	/*
	 * LDO1 and LDO5 support voltage control by either target voltage1
	 * or target voltage2 register.
	 * We use target voltage1 register for LDO1 and LDO5 in this driver.
	 * We need to update voltage change control register(0x20) to enable
	 * LDO1 and LDO5 to change to their programmed target values.
	 */
	switch (ldo) {
	case LP3972_LDO1:
	case LP3972_LDO5:
		shift = LP3972_LDO_VOL_CHANGE_SHIFT(ldo);
		ret = lp3972_set_bits(lp3972, LP3972_VOL_CHANGE_REG,
			LP3972_VOL_CHANGE_FLAG_MASK << shift,
			LP3972_VOL_CHANGE_FLAG_GO << shift);
		if (ret)
			return ret;

		ret = lp3972_set_bits(lp3972, LP3972_VOL_CHANGE_REG,
			LP3972_VOL_CHANGE_FLAG_MASK << shift, 0);
		break;
	}

	return ret;
}

__attribute__((used)) static int lp3972_dcdc_is_enabled(struct regulator_dev *dev)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3972_DCDC1;
	u16 mask = 1 << (buck * 2);
	u16 val;

	val = lp3972_reg_read(lp3972, LP3972_BUCK_VOL_ENABLE_REG(buck));
	return !!(val & mask);
}

__attribute__((used)) static int lp3972_dcdc_enable(struct regulator_dev *dev)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3972_DCDC1;
	u16 mask = 1 << (buck * 2);
	u16 val;

	val = lp3972_set_bits(lp3972, LP3972_BUCK_VOL_ENABLE_REG(buck),
				mask, mask);
	return val;
}

__attribute__((used)) static int lp3972_dcdc_disable(struct regulator_dev *dev)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3972_DCDC1;
	u16 mask = 1 << (buck * 2);
	u16 val;

	val = lp3972_set_bits(lp3972, LP3972_BUCK_VOL_ENABLE_REG(buck),
				mask, 0);
	return val;
}

__attribute__((used)) static int lp3972_dcdc_get_voltage_sel(struct regulator_dev *dev)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3972_DCDC1;
	u16 reg;

	reg = lp3972_reg_read(lp3972, LP3972_BUCK_VOL1_REG(buck));
	reg &= LP3972_BUCK_VOL_MASK;

	return reg;
}

__attribute__((used)) static int lp3972_dcdc_set_voltage_sel(struct regulator_dev *dev,
				       unsigned int selector)
{
	struct lp3972 *lp3972 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3972_DCDC1;
	int ret;

	ret = lp3972_set_bits(lp3972, LP3972_BUCK_VOL1_REG(buck),
				LP3972_BUCK_VOL_MASK, selector);
	if (ret)
		return ret;

	if (buck != 0)
		return ret;

	ret = lp3972_set_bits(lp3972, LP3972_VOL_CHANGE_REG,
		LP3972_VOL_CHANGE_FLAG_MASK, LP3972_VOL_CHANGE_FLAG_GO);
	if (ret)
		return ret;

	return lp3972_set_bits(lp3972, LP3972_VOL_CHANGE_REG,
				LP3972_VOL_CHANGE_FLAG_MASK, 0);
}

__attribute__((used)) static int setup_regulators(struct lp3972 *lp3972,
	struct lp3972_platform_data *pdata)
{
	int i, err;

	/* Instantiate the regulators */
	for (i = 0; i < pdata->num_regulators; i++) {
		struct lp3972_regulator_subdev *reg = &pdata->regulators[i];
		struct regulator_config config = { };
		struct regulator_dev *rdev;

		config.dev = lp3972->dev;
		config.init_data = reg->initdata;
		config.driver_data = lp3972;

		rdev = devm_regulator_register(lp3972->dev,
					       &regulators[reg->id], &config);
		if (IS_ERR(rdev)) {
			err = PTR_ERR(rdev);
			dev_err(lp3972->dev, "regulator init failed: %d\n",
				err);
			return err;
		}
	}

	return 0;
}

__attribute__((used)) static int lp3972_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct lp3972 *lp3972;
	struct lp3972_platform_data *pdata = dev_get_platdata(&i2c->dev);
	int ret;
	u16 val;

	if (!pdata) {
		dev_dbg(&i2c->dev, "No platform init data supplied\n");
		return -ENODEV;
	}

	lp3972 = devm_kzalloc(&i2c->dev, sizeof(struct lp3972), GFP_KERNEL);
	if (!lp3972)
		return -ENOMEM;

	lp3972->i2c = i2c;
	lp3972->dev = &i2c->dev;

	mutex_init(&lp3972->io_lock);

	/* Detect LP3972 */
	ret = lp3972_i2c_read(i2c, LP3972_SYS_CONTROL1_REG, 1, &val);
	if (ret == 0 &&
		(val & SYS_CONTROL1_INIT_MASK) != SYS_CONTROL1_INIT_VAL) {
		ret = -ENODEV;
		dev_err(&i2c->dev, "chip reported: val = 0x%x\n", val);
	}
	if (ret < 0) {
		dev_err(&i2c->dev, "failed to detect device. ret = %d\n", ret);
		return ret;
	}

	ret = setup_regulators(lp3972, pdata);
	if (ret < 0)
		return ret;

	i2c_set_clientdata(i2c, lp3972);
	return 0;
}

