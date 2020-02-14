#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_10__ {int /*<<< orphan*/  parent; } ;
struct regulator_dev {TYPE_3__ dev; int /*<<< orphan*/  regmap; } ;
struct regulator_config {int /*<<< orphan*/  regmap; TYPE_2__* driver_data; TYPE_3__* dev; } ;
struct platform_device {TYPE_3__ dev; } ;
struct TYPE_8__ {scalar_t__ enable_reg; } ;
struct mt6397_regulator_info {int modeset_mask; int modeset_shift; int qi; TYPE_1__ desc; scalar_t__ modeset_reg; } ;
struct mt6397_chip {int /*<<< orphan*/  regmap; } ;
struct TYPE_11__ {int name; int /*<<< orphan*/  volt_table; int /*<<< orphan*/  vsel_reg; } ;
struct TYPE_9__ {int vselctrl_mask; TYPE_4__ desc; int /*<<< orphan*/  vselon_reg; scalar_t__ vselctrl_reg; } ;

/* Variables and functions */
 unsigned int EINVAL ; 
 int EIO ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
#define  MT6397_BUCK_MODE_AUTO 132 
#define  MT6397_BUCK_MODE_FORCE_PWM 131 
 scalar_t__ MT6397_CID ; 
 size_t MT6397_ID_VGP2 ; 
 int MT6397_MAX_REGULATOR ; 
#define  MT6397_REGULATOR_ID91 130 
 int PTR_ERR (struct regulator_dev*) ; 
#define  REGULATOR_MODE_FAST 129 
#define  REGULATOR_MODE_NORMAL 128 
 int REGULATOR_STATUS_OFF ; 
 int REGULATOR_STATUS_ON ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,scalar_t__,int,int,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 struct mt6397_chip* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (TYPE_3__*,char*,int) ; 
 struct regulator_dev* devm_regulator_register (TYPE_3__*,TYPE_4__*,struct regulator_config*) ; 
 int /*<<< orphan*/  ldo_volt_table5_v2 ; 
 TYPE_2__* mt6397_regulators ; 
 struct mt6397_regulator_info* rdev_get_drvdata (struct regulator_dev*) ; 
 scalar_t__ regmap_read (int /*<<< orphan*/ ,scalar_t__,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,scalar_t__,int,int) ; 

__attribute__((used)) static int mt6397_regulator_set_mode(struct regulator_dev *rdev,
				     unsigned int mode)
{
	struct mt6397_regulator_info *info = rdev_get_drvdata(rdev);
	int ret, val;

	switch (mode) {
	case REGULATOR_MODE_FAST:
		val = MT6397_BUCK_MODE_FORCE_PWM;
		break;
	case REGULATOR_MODE_NORMAL:
		val = MT6397_BUCK_MODE_AUTO;
		break;
	default:
		ret = -EINVAL;
		goto err_mode;
	}

	dev_dbg(&rdev->dev, "mt6397 buck set_mode %#x, %#x, %#x, %#x\n",
		info->modeset_reg, info->modeset_mask,
		info->modeset_shift, val);

	val <<= info->modeset_shift;
	ret = regmap_update_bits(rdev->regmap, info->modeset_reg,
				 info->modeset_mask, val);
err_mode:
	if (ret != 0) {
		dev_err(&rdev->dev,
			"Failed to set mt6397 buck mode: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static unsigned int mt6397_regulator_get_mode(struct regulator_dev *rdev)
{
	struct mt6397_regulator_info *info = rdev_get_drvdata(rdev);
	int ret, regval;

	ret = regmap_read(rdev->regmap, info->modeset_reg, &regval);
	if (ret != 0) {
		dev_err(&rdev->dev,
			"Failed to get mt6397 buck mode: %d\n", ret);
		return ret;
	}

	switch ((regval & info->modeset_mask) >> info->modeset_shift) {
	case MT6397_BUCK_MODE_AUTO:
		return REGULATOR_MODE_NORMAL;
	case MT6397_BUCK_MODE_FORCE_PWM:
		return REGULATOR_MODE_FAST;
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static int mt6397_get_status(struct regulator_dev *rdev)
{
	int ret;
	u32 regval;
	struct mt6397_regulator_info *info = rdev_get_drvdata(rdev);

	ret = regmap_read(rdev->regmap, info->desc.enable_reg, &regval);
	if (ret != 0) {
		dev_err(&rdev->dev, "Failed to get enable reg: %d\n", ret);
		return ret;
	}

	return (regval & info->qi) ? REGULATOR_STATUS_ON : REGULATOR_STATUS_OFF;
}

__attribute__((used)) static int mt6397_set_buck_vosel_reg(struct platform_device *pdev)
{
	struct mt6397_chip *mt6397 = dev_get_drvdata(pdev->dev.parent);
	int i;
	u32 regval;

	for (i = 0; i < MT6397_MAX_REGULATOR; i++) {
		if (mt6397_regulators[i].vselctrl_reg) {
			if (regmap_read(mt6397->regmap,
				mt6397_regulators[i].vselctrl_reg,
				&regval) < 0) {
				dev_err(&pdev->dev,
					"Failed to read buck ctrl\n");
				return -EIO;
			}

			if (regval & mt6397_regulators[i].vselctrl_mask) {
				mt6397_regulators[i].desc.vsel_reg =
				mt6397_regulators[i].vselon_reg;
			}
		}
	}

	return 0;
}

__attribute__((used)) static int mt6397_regulator_probe(struct platform_device *pdev)
{
	struct mt6397_chip *mt6397 = dev_get_drvdata(pdev->dev.parent);
	struct regulator_config config = {};
	struct regulator_dev *rdev;
	int i;
	u32 reg_value, version;

	/* Query buck controller to select activated voltage register part */
	if (mt6397_set_buck_vosel_reg(pdev))
		return -EIO;

	/* Read PMIC chip revision to update constraints and voltage table */
	if (regmap_read(mt6397->regmap, MT6397_CID, &reg_value) < 0) {
		dev_err(&pdev->dev, "Failed to read Chip ID\n");
		return -EIO;
	}
	dev_info(&pdev->dev, "Chip ID = 0x%x\n", reg_value);

	version = (reg_value & 0xFF);
	switch (version) {
	case MT6397_REGULATOR_ID91:
		mt6397_regulators[MT6397_ID_VGP2].desc.volt_table =
		ldo_volt_table5_v2;
		break;
	default:
		break;
	}

	for (i = 0; i < MT6397_MAX_REGULATOR; i++) {
		config.dev = &pdev->dev;
		config.driver_data = &mt6397_regulators[i];
		config.regmap = mt6397->regmap;
		rdev = devm_regulator_register(&pdev->dev,
				&mt6397_regulators[i].desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "failed to register %s\n",
				mt6397_regulators[i].desc.name);
			return PTR_ERR(rdev);
		}
	}

	return 0;
}

