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
struct resource {scalar_t__ start; } ;
struct regulator_init_data {int dummy; } ;
struct regulator_dev {TYPE_1__* desc; } ;
struct regulator_config {struct regulator_init_data* init_data; struct max8925_regulator_info* driver_data; TYPE_2__* dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_8__ {unsigned long long name; } ;
struct max8925_regulator_info {scalar_t__ vol_reg; scalar_t__ enable_reg; TYPE_3__ desc; int /*<<< orphan*/  i2c; } ;
struct max8925_chip {int /*<<< orphan*/  i2c; } ;
struct TYPE_6__ {int n_voltages; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct max8925_regulator_info*) ; 
 unsigned char DIV_ROUND_UP (int,int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int /*<<< orphan*/  IORESOURCE_REG ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int LDO_I2C_EN ; 
 int LDO_I2C_EN_MASK ; 
 int LDO_I2C_EN_SHIFT ; 
 int LDO_SEQ_I2C ; 
 int LDO_SEQ_MASK ; 
 int LDO_SEQ_SHIFT ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int SD1_DVM_EN ; 
 unsigned char SD1_DVM_SHIFT ; 
 int /*<<< orphan*/  SD1_DVM_STEP ; 
 int SD1_DVM_VMAX ; 
 int SD1_DVM_VMIN ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct max8925_chip* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct regulator_init_data* dev_get_platdata (TYPE_2__*) ; 
 struct regulator_dev* devm_regulator_register (TYPE_2__*,TYPE_3__*,struct regulator_config*) ; 
 int max8925_reg_read (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ max8925_regulator_dt_init (struct platform_device*,struct regulator_config*,int) ; 
 struct max8925_regulator_info* max8925_regulator_info ; 
 int max8925_set_bits (int /*<<< orphan*/ ,scalar_t__,int,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct regulator_dev*) ; 
 struct max8925_regulator_info* rdev_get_drvdata (struct regulator_dev*) ; 

__attribute__((used)) static int max8925_set_voltage_sel(struct regulator_dev *rdev,
				   unsigned int selector)
{
	struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
	unsigned char mask = rdev->desc->n_voltages - 1;

	return max8925_set_bits(info->i2c, info->vol_reg, mask, selector);
}

__attribute__((used)) static int max8925_get_voltage_sel(struct regulator_dev *rdev)
{
	struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
	unsigned char data, mask;
	int ret;

	ret = max8925_reg_read(info->i2c, info->vol_reg);
	if (ret < 0)
		return ret;
	mask = rdev->desc->n_voltages - 1;
	data = ret & mask;

	return data;
}

__attribute__((used)) static int max8925_enable(struct regulator_dev *rdev)
{
	struct max8925_regulator_info *info = rdev_get_drvdata(rdev);

	return max8925_set_bits(info->i2c, info->enable_reg,
				LDO_SEQ_MASK << LDO_SEQ_SHIFT |
				LDO_I2C_EN_MASK << LDO_I2C_EN_SHIFT,
				LDO_SEQ_I2C << LDO_SEQ_SHIFT |
				LDO_I2C_EN << LDO_I2C_EN_SHIFT);
}

__attribute__((used)) static int max8925_disable(struct regulator_dev *rdev)
{
	struct max8925_regulator_info *info = rdev_get_drvdata(rdev);

	return max8925_set_bits(info->i2c, info->enable_reg,
				LDO_SEQ_MASK << LDO_SEQ_SHIFT |
				LDO_I2C_EN_MASK << LDO_I2C_EN_SHIFT,
				LDO_SEQ_I2C << LDO_SEQ_SHIFT);
}

__attribute__((used)) static int max8925_is_enabled(struct regulator_dev *rdev)
{
	struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
	int ldo_seq, ret;

	ret = max8925_reg_read(info->i2c, info->enable_reg);
	if (ret < 0)
		return ret;
	ldo_seq = (ret >> LDO_SEQ_SHIFT) & LDO_SEQ_MASK;
	if (ldo_seq != LDO_SEQ_I2C)
		return 1;
	else
		return ret & (LDO_I2C_EN_MASK << LDO_I2C_EN_SHIFT);
}

__attribute__((used)) static int max8925_set_dvm_voltage(struct regulator_dev *rdev, int uV)
{
	struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
	unsigned char data, mask;

	if (uV < SD1_DVM_VMIN || uV > SD1_DVM_VMAX)
		return -EINVAL;

	data = DIV_ROUND_UP(uV - SD1_DVM_VMIN, SD1_DVM_STEP);
	data <<= SD1_DVM_SHIFT;
	mask = 3 << SD1_DVM_SHIFT;

	return max8925_set_bits(info->i2c, info->enable_reg, mask, data);
}

__attribute__((used)) static int max8925_set_dvm_enable(struct regulator_dev *rdev)
{
	struct max8925_regulator_info *info = rdev_get_drvdata(rdev);

	return max8925_set_bits(info->i2c, info->vol_reg, 1 << SD1_DVM_EN,
				1 << SD1_DVM_EN);
}

__attribute__((used)) static int max8925_set_dvm_disable(struct regulator_dev *rdev)
{
	struct max8925_regulator_info *info = rdev_get_drvdata(rdev);

	return max8925_set_bits(info->i2c, info->vol_reg, 1 << SD1_DVM_EN, 0);
}

__attribute__((used)) static int max8925_regulator_probe(struct platform_device *pdev)
{
	struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
	struct regulator_init_data *pdata = dev_get_platdata(&pdev->dev);
	struct regulator_config config = { };
	struct max8925_regulator_info *ri;
	struct resource *res;
	struct regulator_dev *rdev;
	int i, regulator_idx;

	res = platform_get_resource(pdev, IORESOURCE_REG, 0);
	if (!res) {
		dev_err(&pdev->dev, "No REG resource!\n");
		return -EINVAL;
	}
	for (i = 0; i < ARRAY_SIZE(max8925_regulator_info); i++) {
		ri = &max8925_regulator_info[i];
		if (ri->vol_reg == res->start) {
			regulator_idx = i;
			break;
		}
	}

	if (i == ARRAY_SIZE(max8925_regulator_info)) {
		dev_err(&pdev->dev, "Failed to find regulator %llu\n",
			(unsigned long long)res->start);
		return -EINVAL;
	}
	ri->i2c = chip->i2c;

	config.dev = &pdev->dev;
	config.driver_data = ri;

	if (max8925_regulator_dt_init(pdev, &config, regulator_idx))
		if (pdata)
			config.init_data = pdata;

	rdev = devm_regulator_register(&pdev->dev, &ri->desc, &config);
	if (IS_ERR(rdev)) {
		dev_err(&pdev->dev, "failed to register regulator %s\n",
				ri->desc.name);
		return PTR_ERR(rdev);
	}

	platform_set_drvdata(pdev, rdev);
	return 0;
}

