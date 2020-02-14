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
typedef  int u8 ;
struct regulator_dev {TYPE_1__* desc; } ;
struct regulator_config {int /*<<< orphan*/  init_data; int /*<<< orphan*/  regmap; struct da9052_regulator* driver_data; TYPE_2__* dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct mfd_cell {int id; } ;
struct TYPE_8__ {int id; int /*<<< orphan*/  name; } ;
struct da9052_regulator_info {int max_uV; int min_uV; unsigned int step_uV; int activate_bit; TYPE_3__ reg_desc; } ;
struct da9052_regulator {int /*<<< orphan*/  rdev; struct da9052_regulator_info* info; struct da9052* da9052; } ;
struct da9052_pdata {int /*<<< orphan*/ * regulators; } ;
struct da9052 {scalar_t__ chip_id; int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int vsel_mask; scalar_t__ vsel_reg; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct da9052_regulator_info*) ; 
#define  DA9052 137 
 scalar_t__ DA9052_BUCKA_REG ; 
 int DA9052_BUCK_ILIM_MASK_EVEN ; 
 int DA9052_BUCK_ILIM_MASK_ODD ; 
 unsigned int DA9052_BUCK_PERI_3uV_STEP ; 
 unsigned int DA9052_BUCK_PERI_REG_MAP_UPTO_3uV ; 
 int DA9052_CONST_3uV ; 
 int DA9052_CURRENT_RANGE ; 
#define  DA9052_ID_BUCK1 136 
#define  DA9052_ID_BUCK2 135 
#define  DA9052_ID_BUCK3 134 
 int DA9052_ID_BUCK4 ; 
#define  DA9052_ID_LDO2 133 
#define  DA9052_ID_LDO3 132 
 scalar_t__ DA9052_SUPPLY_REG ; 
#define  DA9053_AA 131 
#define  DA9053_BA 130 
#define  DA9053_BB 129 
#define  DA9053_BC 128 
 unsigned int DIV_ROUND_UP (int,unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int** da9052_current_limits ; 
 int da9052_reg_read (struct da9052*,scalar_t__) ; 
 int da9052_reg_update (struct da9052*,scalar_t__,int,unsigned int) ; 
 struct da9052_regulator_info* da9052_regulator_info ; 
 struct da9052_regulator_info* da9053_regulator_info ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct da9052* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct da9052_pdata* dev_get_platdata (int /*<<< orphan*/ ) ; 
 struct da9052_regulator* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regulator_register (TYPE_2__*,TYPE_3__*,struct regulator_config*) ; 
 struct mfd_cell* mfd_get_cell (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct da9052_regulator*) ; 
 struct da9052_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 

__attribute__((used)) static int verify_range(struct da9052_regulator_info *info,
			 int min_uV, int max_uV)
{
	if (min_uV > info->max_uV || max_uV < info->min_uV)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int da9052_dcdc_get_current_limit(struct regulator_dev *rdev)
{
	struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
	int offset = rdev_get_id(rdev);
	int ret, row = 2;

	ret = da9052_reg_read(regulator->da9052, DA9052_BUCKA_REG + offset/2);
	if (ret < 0)
		return ret;

	/* Determine the even or odd position of the buck current limit
	 * register field
	*/
	if (offset % 2 == 0)
		ret = (ret & DA9052_BUCK_ILIM_MASK_EVEN) >> 2;
	else
		ret = (ret & DA9052_BUCK_ILIM_MASK_ODD) >> 6;

	/* Select the appropriate current limit range */
	if (regulator->da9052->chip_id == DA9052)
		row = 0;
	else if (offset == 0)
		row = 1;

	return da9052_current_limits[row][ret];
}

__attribute__((used)) static int da9052_dcdc_set_current_limit(struct regulator_dev *rdev, int min_uA,
					  int max_uA)
{
	struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
	int offset = rdev_get_id(rdev);
	int reg_val = 0;
	int i, row = 2;

	/* Select the appropriate current limit range */
	if (regulator->da9052->chip_id == DA9052)
		row = 0;
	else if (offset == 0)
		row = 1;

	for (i = DA9052_CURRENT_RANGE - 1; i >= 0; i--) {
		if ((min_uA <= da9052_current_limits[row][i]) &&
		    (da9052_current_limits[row][i] <= max_uA)) {
			reg_val = i;
			break;
		}
	}

	if (i < 0)
		return -EINVAL;

	/* Determine the even or odd position of the buck current limit
	 * register field
	*/
	if (offset % 2 == 0)
		return da9052_reg_update(regulator->da9052,
					 DA9052_BUCKA_REG + offset/2,
					 DA9052_BUCK_ILIM_MASK_EVEN,
					 reg_val << 2);
	else
		return da9052_reg_update(regulator->da9052,
					 DA9052_BUCKA_REG + offset/2,
					 DA9052_BUCK_ILIM_MASK_ODD,
					 reg_val << 6);
}

__attribute__((used)) static int da9052_list_voltage(struct regulator_dev *rdev,
				unsigned int selector)
{
	struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
	struct da9052_regulator_info *info = regulator->info;
	int id = rdev_get_id(rdev);
	int volt_uV;

	if ((id == DA9052_ID_BUCK4) && (regulator->da9052->chip_id == DA9052)
		&& (selector >= DA9052_BUCK_PERI_REG_MAP_UPTO_3uV)) {
		volt_uV = ((DA9052_BUCK_PERI_REG_MAP_UPTO_3uV * info->step_uV)
			  + info->min_uV);
		volt_uV += (selector - DA9052_BUCK_PERI_REG_MAP_UPTO_3uV)
				    * (DA9052_BUCK_PERI_3uV_STEP);
	} else {
		volt_uV = (selector * info->step_uV) + info->min_uV;
	}

	if (volt_uV > info->max_uV)
		return -EINVAL;

	return volt_uV;
}

__attribute__((used)) static int da9052_map_voltage(struct regulator_dev *rdev,
			      int min_uV, int max_uV)
{
	struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
	struct da9052_regulator_info *info = regulator->info;
	int id = rdev_get_id(rdev);
	int ret, sel;

	ret = verify_range(info, min_uV, max_uV);
	if (ret < 0)
		return ret;

	if (min_uV < info->min_uV)
		min_uV = info->min_uV;

	if ((id == DA9052_ID_BUCK4) && (regulator->da9052->chip_id == DA9052)
		&& (min_uV >= DA9052_CONST_3uV)) {
			sel = DA9052_BUCK_PERI_REG_MAP_UPTO_3uV +
			      DIV_ROUND_UP(min_uV - DA9052_CONST_3uV,
					   DA9052_BUCK_PERI_3uV_STEP);
	} else {
		sel = DIV_ROUND_UP(min_uV - info->min_uV, info->step_uV);
	}

	ret = da9052_list_voltage(rdev, sel);
	if (ret < 0)
		return ret;

	return sel;
}

__attribute__((used)) static int da9052_regulator_set_voltage_sel(struct regulator_dev *rdev,
					    unsigned int selector)
{
	struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
	struct da9052_regulator_info *info = regulator->info;
	int id = rdev_get_id(rdev);
	int ret;

	ret = da9052_reg_update(regulator->da9052, rdev->desc->vsel_reg,
				rdev->desc->vsel_mask, selector);
	if (ret < 0)
		return ret;

	/* Some LDOs and DCDCs are DVC controlled which requires enabling of
	 * the activate bit to implment the changes on the output.
	 */
	switch (id) {
	case DA9052_ID_BUCK1:
	case DA9052_ID_BUCK2:
	case DA9052_ID_BUCK3:
	case DA9052_ID_LDO2:
	case DA9052_ID_LDO3:
		ret = da9052_reg_update(regulator->da9052, DA9052_SUPPLY_REG,
					info->activate_bit, info->activate_bit);
		break;
	}

	return ret;
}

__attribute__((used)) static int da9052_regulator_set_voltage_time_sel(struct regulator_dev *rdev,
						 unsigned int old_sel,
						 unsigned int new_sel)
{
	struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
	struct da9052_regulator_info *info = regulator->info;
	int id = rdev_get_id(rdev);
	int ret = 0;

	/* The DVC controlled LDOs and DCDCs ramp with 6.25mV/µs after enabling
	 * the activate bit.
	 */
	switch (id) {
	case DA9052_ID_BUCK1:
	case DA9052_ID_BUCK2:
	case DA9052_ID_BUCK3:
	case DA9052_ID_LDO2:
	case DA9052_ID_LDO3:
		ret = (new_sel - old_sel) * info->step_uV / 6250;
		break;
	}

	return ret;
}

__attribute__((used)) static inline struct da9052_regulator_info *find_regulator_info(u8 chip_id,
								 int id)
{
	struct da9052_regulator_info *info;
	int i;

	switch (chip_id) {
	case DA9052:
		for (i = 0; i < ARRAY_SIZE(da9052_regulator_info); i++) {
			info = &da9052_regulator_info[i];
			if (info->reg_desc.id == id)
				return info;
		}
		break;
	case DA9053_AA:
	case DA9053_BA:
	case DA9053_BB:
	case DA9053_BC:
		for (i = 0; i < ARRAY_SIZE(da9053_regulator_info); i++) {
			info = &da9053_regulator_info[i];
			if (info->reg_desc.id == id)
				return info;
		}
		break;
	}

	return NULL;
}

__attribute__((used)) static int da9052_regulator_probe(struct platform_device *pdev)
{
	const struct mfd_cell *cell = mfd_get_cell(pdev);
	struct regulator_config config = { };
	struct da9052_regulator *regulator;
	struct da9052 *da9052;
	struct da9052_pdata *pdata;

	regulator = devm_kzalloc(&pdev->dev, sizeof(struct da9052_regulator),
				 GFP_KERNEL);
	if (!regulator)
		return -ENOMEM;

	da9052 = dev_get_drvdata(pdev->dev.parent);
	pdata = dev_get_platdata(da9052->dev);
	regulator->da9052 = da9052;

	regulator->info = find_regulator_info(regulator->da9052->chip_id,
					      cell->id);
	if (regulator->info == NULL) {
		dev_err(&pdev->dev, "invalid regulator ID specified\n");
		return -EINVAL;
	}

	config.dev = &pdev->dev;
	config.driver_data = regulator;
	config.regmap = da9052->regmap;
	if (pdata && pdata->regulators) {
		config.init_data = pdata->regulators[cell->id];
	} else {
#ifdef CONFIG_OF
		struct device_node *nproot = da9052->dev->of_node;
		struct device_node *np;

		if (!nproot)
			return -ENODEV;

		nproot = of_get_child_by_name(nproot, "regulators");
		if (!nproot)
			return -ENODEV;

		for_each_child_of_node(nproot, np) {
			if (!of_node_cmp(np->name,
					 regulator->info->reg_desc.name)) {
				config.init_data = of_get_regulator_init_data(
					&pdev->dev, np,
					&regulator->info->reg_desc);
				config.of_node = np;
				break;
			}
		}
		of_node_put(nproot);
#endif
	}

	regulator->rdev = devm_regulator_register(&pdev->dev,
						  &regulator->info->reg_desc,
						  &config);
	if (IS_ERR(regulator->rdev)) {
		dev_err(&pdev->dev, "failed to register regulator %s\n",
			regulator->info->reg_desc.name);
		return PTR_ERR(regulator->rdev);
	}

	platform_set_drvdata(pdev, regulator);

	return 0;
}

