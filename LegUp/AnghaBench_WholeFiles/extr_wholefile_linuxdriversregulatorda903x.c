#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct regulator_dev {TYPE_2__* desc; } ;
struct regulator_config {struct da903x_regulator_info* driver_data; int /*<<< orphan*/  init_data; int /*<<< orphan*/ * dev; } ;
struct platform_device {int id; int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct TYPE_8__ {int min_uV; int id; int n_voltages; int n_linear_ranges; int /*<<< orphan*/  name; int /*<<< orphan*/ * ops; struct da903x_regulator_info* linear_ranges; int /*<<< orphan*/  uV_step; } ;
struct da903x_regulator_info {int max_uV; unsigned int vol_shift; int vol_nbits; int enable_bit; int update_bit; TYPE_4__ desc; int /*<<< orphan*/  update_reg; int /*<<< orphan*/  vol_reg; int /*<<< orphan*/  enable_reg; } ;
struct TYPE_7__ {TYPE_1__* parent; } ;
struct TYPE_6__ {int n_voltages; int min_uV; int uV_step; } ;
struct TYPE_5__ {struct device* parent; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct da903x_regulator_info*) ; 
 scalar_t__ DA9030_ID_LDO1 ; 
 scalar_t__ DA9030_ID_LDO14 ; 
 scalar_t__ DA9030_ID_LDO15 ; 
 int DA9030_LDO_UNLOCK ; 
 int DA9030_LDO_UNLOCK_MASK ; 
 scalar_t__ DA9034_ID_LDO12 ; 
 int DIV_ROUND_UP (int,int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  da9030_regulator_ldo14_ops ; 
 int /*<<< orphan*/  da9030_regulator_ldo1_15_ops ; 
 struct da903x_regulator_info* da9034_ldo12_ranges ; 
 int /*<<< orphan*/  da9034_regulator_ldo12_ops ; 
 int da903x_clr_bits (struct device*,int /*<<< orphan*/ ,int) ; 
 int da903x_read (struct device*,int /*<<< orphan*/ ,int*) ; 
 struct da903x_regulator_info* da903x_regulator_info ; 
 int da903x_set_bits (struct device*,int /*<<< orphan*/ ,int) ; 
 int da903x_update (struct device*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct regulator_dev* devm_regulator_register (int /*<<< orphan*/ *,TYPE_4__*,struct regulator_config*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct regulator_dev*) ; 
 int /*<<< orphan*/  pr_err (char*,int,int) ; 
 TYPE_3__* rdev_get_dev (struct regulator_dev*) ; 
 struct da903x_regulator_info* rdev_get_drvdata (struct regulator_dev*) ; 

__attribute__((used)) static inline struct device *to_da903x_dev(struct regulator_dev *rdev)
{
	return rdev_get_dev(rdev)->parent->parent;
}

__attribute__((used)) static inline int check_range(struct da903x_regulator_info *info,
				int min_uV, int max_uV)
{
	if (min_uV < info->desc.min_uV || min_uV > info->max_uV)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int da903x_set_voltage_sel(struct regulator_dev *rdev, unsigned selector)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	struct device *da9034_dev = to_da903x_dev(rdev);
	uint8_t val, mask;

	if (rdev->desc->n_voltages == 1)
		return -EINVAL;

	val = selector << info->vol_shift;
	mask = ((1 << info->vol_nbits) - 1)  << info->vol_shift;

	return da903x_update(da9034_dev, info->vol_reg, val, mask);
}

__attribute__((used)) static int da903x_get_voltage_sel(struct regulator_dev *rdev)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	struct device *da9034_dev = to_da903x_dev(rdev);
	uint8_t val, mask;
	int ret;

	if (rdev->desc->n_voltages == 1)
		return 0;

	ret = da903x_read(da9034_dev, info->vol_reg, &val);
	if (ret)
		return ret;

	mask = ((1 << info->vol_nbits) - 1)  << info->vol_shift;
	val = (val & mask) >> info->vol_shift;

	return val;
}

__attribute__((used)) static int da903x_enable(struct regulator_dev *rdev)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	struct device *da9034_dev = to_da903x_dev(rdev);

	return da903x_set_bits(da9034_dev, info->enable_reg,
					1 << info->enable_bit);
}

__attribute__((used)) static int da903x_disable(struct regulator_dev *rdev)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	struct device *da9034_dev = to_da903x_dev(rdev);

	return da903x_clr_bits(da9034_dev, info->enable_reg,
					1 << info->enable_bit);
}

__attribute__((used)) static int da903x_is_enabled(struct regulator_dev *rdev)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	struct device *da9034_dev = to_da903x_dev(rdev);
	uint8_t reg_val;
	int ret;

	ret = da903x_read(da9034_dev, info->enable_reg, &reg_val);
	if (ret)
		return ret;

	return !!(reg_val & (1 << info->enable_bit));
}

__attribute__((used)) static int da9030_set_ldo1_15_voltage_sel(struct regulator_dev *rdev,
					  unsigned selector)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	struct device *da903x_dev = to_da903x_dev(rdev);
	uint8_t val, mask;
	int ret;

	val = selector << info->vol_shift;
	mask = ((1 << info->vol_nbits) - 1)  << info->vol_shift;
	val |= DA9030_LDO_UNLOCK; /* have to set UNLOCK bits */
	mask |= DA9030_LDO_UNLOCK_MASK;

	/* write twice */
	ret = da903x_update(da903x_dev, info->vol_reg, val, mask);
	if (ret)
		return ret;

	return da903x_update(da903x_dev, info->vol_reg, val, mask);
}

__attribute__((used)) static int da9030_map_ldo14_voltage(struct regulator_dev *rdev,
				    int min_uV, int max_uV)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	int thresh, sel;

	if (check_range(info, min_uV, max_uV)) {
		pr_err("invalid voltage range (%d, %d) uV\n", min_uV, max_uV);
		return -EINVAL;
	}

	thresh = (info->max_uV + info->desc.min_uV) / 2;
	if (min_uV < thresh) {
		sel = DIV_ROUND_UP(thresh - min_uV, info->desc.uV_step);
		sel |= 0x4;
	} else {
		sel = DIV_ROUND_UP(min_uV - thresh, info->desc.uV_step);
	}

	return sel;
}

__attribute__((used)) static int da9030_list_ldo14_voltage(struct regulator_dev *rdev,
				     unsigned selector)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	int volt;

	if (selector & 0x4)
		volt = rdev->desc->min_uV +
		       rdev->desc->uV_step * (3 - (selector & ~0x4));
	else
		volt = (info->max_uV + rdev->desc->min_uV) / 2 +
		       rdev->desc->uV_step * (selector & ~0x4);

	if (volt > info->max_uV)
		return -EINVAL;

	return volt;
}

__attribute__((used)) static int da9034_set_dvc_voltage_sel(struct regulator_dev *rdev,
				      unsigned selector)
{
	struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
	struct device *da9034_dev = to_da903x_dev(rdev);
	uint8_t val, mask;
	int ret;

	val = selector << info->vol_shift;
	mask = ((1 << info->vol_nbits) - 1)  << info->vol_shift;

	ret = da903x_update(da9034_dev, info->vol_reg, val, mask);
	if (ret)
		return ret;

	ret = da903x_set_bits(da9034_dev, info->update_reg,
					1 << info->update_bit);
	return ret;
}

__attribute__((used)) static inline struct da903x_regulator_info *find_regulator_info(int id)
{
	struct da903x_regulator_info *ri;
	int i;

	for (i = 0; i < ARRAY_SIZE(da903x_regulator_info); i++) {
		ri = &da903x_regulator_info[i];
		if (ri->desc.id == id)
			return ri;
	}
	return NULL;
}

__attribute__((used)) static int da903x_regulator_probe(struct platform_device *pdev)
{
	struct da903x_regulator_info *ri = NULL;
	struct regulator_dev *rdev;
	struct regulator_config config = { };

	ri = find_regulator_info(pdev->id);
	if (ri == NULL) {
		dev_err(&pdev->dev, "invalid regulator ID specified\n");
		return -EINVAL;
	}

	/* Workaround for the weird LDO12 voltage setting */
	if (ri->desc.id == DA9034_ID_LDO12) {
		ri->desc.ops = &da9034_regulator_ldo12_ops;
		ri->desc.n_voltages = 16;
		ri->desc.linear_ranges = da9034_ldo12_ranges;
		ri->desc.n_linear_ranges = ARRAY_SIZE(da9034_ldo12_ranges);
	}

	if (ri->desc.id == DA9030_ID_LDO14)
		ri->desc.ops = &da9030_regulator_ldo14_ops;

	if (ri->desc.id == DA9030_ID_LDO1 || ri->desc.id == DA9030_ID_LDO15)
		ri->desc.ops = &da9030_regulator_ldo1_15_ops;

	config.dev = &pdev->dev;
	config.init_data = dev_get_platdata(&pdev->dev);
	config.driver_data = ri;

	rdev = devm_regulator_register(&pdev->dev, &ri->desc, &config);
	if (IS_ERR(rdev)) {
		dev_err(&pdev->dev, "failed to register regulator %s\n",
				ri->desc.name);
		return PTR_ERR(rdev);
	}

	platform_set_drvdata(pdev, rdev);
	return 0;
}

