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
struct regulator_config {struct lp3971* driver_data; int /*<<< orphan*/  init_data; int /*<<< orphan*/ * dev; } ;
struct lp3971_regulator_subdev {size_t id; int /*<<< orphan*/  initdata; } ;
struct lp3971_platform_data {int num_regulators; struct lp3971_regulator_subdev* regulators; } ;
struct lp3971 {int /*<<< orphan*/  io_lock; int /*<<< orphan*/ * dev; struct i2c_client* i2c; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int BUCK_TARGET_VOL_MASK ; 
 int BUCK_VOL_CHANGE_FLAG_GO ; 
 int BUCK_VOL_CHANGE_FLAG_MASK ; 
 int BUCK_VOL_CHANGE_SHIFT (int) ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int LDO_VOL_CONTR_MASK ; 
 unsigned int LDO_VOL_CONTR_SHIFT (int) ; 
 int LP3971_BUCK_TARGET_VOL1_REG (int) ; 
 int LP3971_BUCK_VOL_CHANGE_REG ; 
 int LP3971_BUCK_VOL_ENABLE_REG ; 
 int LP3971_DCDC1 ; 
 int LP3971_LDO1 ; 
 int LP3971_LDO_ENABLE_REG ; 
 int LP3971_LDO_VOL_CONTR_REG (int) ; 
 char LP3971_SYS_CONTROL1_REG ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int SYS_CONTROL1_INIT_MASK ; 
 int SYS_CONTROL1_INIT_VAL ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct lp3971_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct lp3971* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct regulator_config*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct lp3971*) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,char) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,char,int const) ; 
static  int lp3971_reg_read (struct lp3971*,int) ; 
static  int lp3971_set_bits (struct lp3971*,int,int,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct lp3971* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int /*<<< orphan*/ * regulators ; 

__attribute__((used)) static int lp3971_ldo_is_enabled(struct regulator_dev *dev)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3971_LDO1;
	u16 mask = 1 << (1 + ldo);
	u16 val;

	val = lp3971_reg_read(lp3971, LP3971_LDO_ENABLE_REG);
	return (val & mask) != 0;
}

__attribute__((used)) static int lp3971_ldo_enable(struct regulator_dev *dev)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3971_LDO1;
	u16 mask = 1 << (1 + ldo);

	return lp3971_set_bits(lp3971, LP3971_LDO_ENABLE_REG, mask, mask);
}

__attribute__((used)) static int lp3971_ldo_disable(struct regulator_dev *dev)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3971_LDO1;
	u16 mask = 1 << (1 + ldo);

	return lp3971_set_bits(lp3971, LP3971_LDO_ENABLE_REG, mask, 0);
}

__attribute__((used)) static int lp3971_ldo_get_voltage_sel(struct regulator_dev *dev)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3971_LDO1;
	u16 val, reg;

	reg = lp3971_reg_read(lp3971, LP3971_LDO_VOL_CONTR_REG(ldo));
	val = (reg >> LDO_VOL_CONTR_SHIFT(ldo)) & LDO_VOL_CONTR_MASK;

	return val;
}

__attribute__((used)) static int lp3971_ldo_set_voltage_sel(struct regulator_dev *dev,
				      unsigned int selector)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int ldo = rdev_get_id(dev) - LP3971_LDO1;

	return lp3971_set_bits(lp3971, LP3971_LDO_VOL_CONTR_REG(ldo),
			LDO_VOL_CONTR_MASK << LDO_VOL_CONTR_SHIFT(ldo),
			selector << LDO_VOL_CONTR_SHIFT(ldo));
}

__attribute__((used)) static int lp3971_dcdc_is_enabled(struct regulator_dev *dev)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3971_DCDC1;
	u16 mask = 1 << (buck * 2);
	u16 val;

	val = lp3971_reg_read(lp3971, LP3971_BUCK_VOL_ENABLE_REG);
	return (val & mask) != 0;
}

__attribute__((used)) static int lp3971_dcdc_enable(struct regulator_dev *dev)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3971_DCDC1;
	u16 mask = 1 << (buck * 2);

	return lp3971_set_bits(lp3971, LP3971_BUCK_VOL_ENABLE_REG, mask, mask);
}

__attribute__((used)) static int lp3971_dcdc_disable(struct regulator_dev *dev)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3971_DCDC1;
	u16 mask = 1 << (buck * 2);

	return lp3971_set_bits(lp3971, LP3971_BUCK_VOL_ENABLE_REG, mask, 0);
}

__attribute__((used)) static int lp3971_dcdc_get_voltage_sel(struct regulator_dev *dev)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3971_DCDC1;
	u16 reg;

	reg = lp3971_reg_read(lp3971, LP3971_BUCK_TARGET_VOL1_REG(buck));
	reg &= BUCK_TARGET_VOL_MASK;

	return reg;
}

__attribute__((used)) static int lp3971_dcdc_set_voltage_sel(struct regulator_dev *dev,
				       unsigned int selector)
{
	struct lp3971 *lp3971 = rdev_get_drvdata(dev);
	int buck = rdev_get_id(dev) - LP3971_DCDC1;
	int ret;

	ret = lp3971_set_bits(lp3971, LP3971_BUCK_TARGET_VOL1_REG(buck),
	       BUCK_TARGET_VOL_MASK, selector);
	if (ret)
		return ret;

	ret = lp3971_set_bits(lp3971, LP3971_BUCK_VOL_CHANGE_REG,
	       BUCK_VOL_CHANGE_FLAG_MASK << BUCK_VOL_CHANGE_SHIFT(buck),
	       BUCK_VOL_CHANGE_FLAG_GO << BUCK_VOL_CHANGE_SHIFT(buck));
	if (ret)
		return ret;

	return lp3971_set_bits(lp3971, LP3971_BUCK_VOL_CHANGE_REG,
	       BUCK_VOL_CHANGE_FLAG_MASK << BUCK_VOL_CHANGE_SHIFT(buck),
	       0 << BUCK_VOL_CHANGE_SHIFT(buck));
}

__attribute__((used)) static int lp3971_i2c_read(struct i2c_client *i2c, char reg, int count,
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

__attribute__((used)) static int lp3971_i2c_write(struct i2c_client *i2c, char reg, int count,
	const u16 *src)
{
	if (count != 1)
		return -EIO;
	return i2c_smbus_write_byte_data(i2c, reg, *src);
}

__attribute__((used)) static u8 lp3971_reg_read(struct lp3971 *lp3971, u8 reg)
{
	u16 val = 0;

	mutex_lock(&lp3971->io_lock);

	lp3971_i2c_read(lp3971->i2c, reg, 1, &val);

	dev_dbg(lp3971->dev, "reg read 0x%02x -> 0x%02x\n", (int)reg,
		(unsigned)val&0xff);

	mutex_unlock(&lp3971->io_lock);

	return val & 0xff;
}

__attribute__((used)) static int lp3971_set_bits(struct lp3971 *lp3971, u8 reg, u16 mask, u16 val)
{
	u16 tmp;
	int ret;

	mutex_lock(&lp3971->io_lock);

	ret = lp3971_i2c_read(lp3971->i2c, reg, 1, &tmp);
	if (ret == 0) {
		tmp = (tmp & ~mask) | val;
		ret = lp3971_i2c_write(lp3971->i2c, reg, 1, &tmp);
		dev_dbg(lp3971->dev, "reg write 0x%02x -> 0x%02x\n", (int)reg,
			(unsigned)val&0xff);
	}
	mutex_unlock(&lp3971->io_lock);

	return ret;
}

__attribute__((used)) static int setup_regulators(struct lp3971 *lp3971,
				      struct lp3971_platform_data *pdata)
{
	int i, err;

	/* Instantiate the regulators */
	for (i = 0; i < pdata->num_regulators; i++) {
		struct regulator_config config = { };
		struct lp3971_regulator_subdev *reg = &pdata->regulators[i];
		struct regulator_dev *rdev;

		config.dev = lp3971->dev;
		config.init_data = reg->initdata;
		config.driver_data = lp3971;

		rdev = devm_regulator_register(lp3971->dev,
					       &regulators[reg->id], &config);
		if (IS_ERR(rdev)) {
			err = PTR_ERR(rdev);
			dev_err(lp3971->dev, "regulator init failed: %d\n",
				err);
			return err;
		}
	}

	return 0;
}

__attribute__((used)) static int lp3971_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct lp3971 *lp3971;
	struct lp3971_platform_data *pdata = dev_get_platdata(&i2c->dev);
	int ret;
	u16 val;

	if (!pdata) {
		dev_dbg(&i2c->dev, "No platform init data supplied\n");
		return -ENODEV;
	}

	lp3971 = devm_kzalloc(&i2c->dev, sizeof(struct lp3971), GFP_KERNEL);
	if (lp3971 == NULL)
		return -ENOMEM;

	lp3971->i2c = i2c;
	lp3971->dev = &i2c->dev;

	mutex_init(&lp3971->io_lock);

	/* Detect LP3971 */
	ret = lp3971_i2c_read(i2c, LP3971_SYS_CONTROL1_REG, 1, &val);
	if (ret == 0 && (val & SYS_CONTROL1_INIT_MASK) != SYS_CONTROL1_INIT_VAL)
		ret = -ENODEV;
	if (ret < 0) {
		dev_err(&i2c->dev, "failed to detect device\n");
		return ret;
	}

	ret = setup_regulators(lp3971, pdata);
	if (ret < 0)
		return ret;

	i2c_set_clientdata(i2c, lp3971);
	return 0;
}

