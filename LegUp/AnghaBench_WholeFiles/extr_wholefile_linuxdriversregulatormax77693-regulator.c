#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct regulator_dev {int /*<<< orphan*/  regmap; TYPE_1__* constraints; } ;
struct regulator_desc {int id; } ;
struct regulator_config {struct regmap* regmap; void* driver_data; int /*<<< orphan*/  dev; } ;
struct regmap {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct max77693_dev {int /*<<< orphan*/  dev; struct regmap* regmap; struct regmap* regmap_chg; } ;
struct chg_reg_data {unsigned int linear_mask; unsigned int min_sel; unsigned int uA_step; int /*<<< orphan*/  linear_reg; } ;
typedef  enum max77693_types { ____Placeholder_max77693_types } max77693_types ;
struct TYPE_6__ {int driver_data; } ;
struct TYPE_5__ {unsigned int min_uA; unsigned int max_uA; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct regulator_desc*) ; 
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
#define  MAX77843_CHARGER 132 
#define  MAX77843_SAFEOUT1 131 
#define  MAX77843_SAFEOUT2 130 
 int PTR_ERR (struct regulator_dev*) ; 
#define  TYPE_MAX77693 129 
#define  TYPE_MAX77843 128 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,int) ; 
 struct max77693_dev* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_3__*,struct regulator_desc const*,struct regulator_config*) ; 
 int /*<<< orphan*/  max77693_chg_reg_data ; 
 struct regulator_desc* max77693_supported_regulators ; 
 int /*<<< orphan*/  max77843_chg_reg_data ; 
 struct regulator_desc* max77843_supported_regulators ; 
 TYPE_2__* platform_get_device_id (struct platform_device*) ; 
 struct chg_reg_data* rdev_get_drvdata (struct regulator_dev*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int max77693_chg_get_current_limit(struct regulator_dev *rdev)
{
	const struct chg_reg_data *reg_data = rdev_get_drvdata(rdev);
	unsigned int chg_min_uA = rdev->constraints->min_uA;
	unsigned int chg_max_uA = rdev->constraints->max_uA;
	unsigned int reg, sel;
	unsigned int val;
	int ret;

	ret = regmap_read(rdev->regmap, reg_data->linear_reg, &reg);
	if (ret < 0)
		return ret;

	sel = reg & reg_data->linear_mask;

	/* the first four codes for charger current are all 60mA */
	if (sel <= reg_data->min_sel)
		sel = 0;
	else
		sel -= reg_data->min_sel;

	val = chg_min_uA + reg_data->uA_step * sel;
	if (val > chg_max_uA)
		return -EINVAL;

	return val;
}

__attribute__((used)) static int max77693_chg_set_current_limit(struct regulator_dev *rdev,
						int min_uA, int max_uA)
{
	const struct chg_reg_data *reg_data = rdev_get_drvdata(rdev);
	unsigned int chg_min_uA = rdev->constraints->min_uA;
	int sel = 0;

	while (chg_min_uA + reg_data->uA_step * sel < min_uA)
		sel++;

	if (chg_min_uA + reg_data->uA_step * sel > max_uA)
		return -EINVAL;

	/* the first four codes for charger current are all 60mA */
	sel += reg_data->min_sel;

	return regmap_write(rdev->regmap, reg_data->linear_reg, sel);
}

__attribute__((used)) static struct regmap *max77693_get_regmap(enum max77693_types type,
					  struct max77693_dev *max77693,
					  int reg_id)
{
	if (type == TYPE_MAX77693)
		return max77693->regmap;

	/* Else: TYPE_MAX77843 */
	switch (reg_id) {
	case MAX77843_SAFEOUT1:
	case MAX77843_SAFEOUT2:
		return max77693->regmap;
	case MAX77843_CHARGER:
		return max77693->regmap_chg;
	default:
		return max77693->regmap;
	}
}

__attribute__((used)) static int max77693_pmic_probe(struct platform_device *pdev)
{
	enum max77693_types type = platform_get_device_id(pdev)->driver_data;
	struct max77693_dev *iodev = dev_get_drvdata(pdev->dev.parent);
	const struct regulator_desc *regulators;
	unsigned int regulators_size;
	int i;
	struct regulator_config config = { };

	config.dev = iodev->dev;

	switch (type) {
	case TYPE_MAX77693:
		regulators = max77693_supported_regulators;
		regulators_size = ARRAY_SIZE(max77693_supported_regulators);
		config.driver_data = (void *)&max77693_chg_reg_data;
		break;
	case TYPE_MAX77843:
		regulators = max77843_supported_regulators;
		regulators_size = ARRAY_SIZE(max77843_supported_regulators);
		config.driver_data = (void *)&max77843_chg_reg_data;
		break;
	default:
		dev_err(&pdev->dev, "Unsupported device type: %u\n", type);
		return -ENODEV;
	}

	for (i = 0; i < regulators_size; i++) {
		struct regulator_dev *rdev;

		config.regmap = max77693_get_regmap(type, iodev,
						    regulators[i].id);

		rdev = devm_regulator_register(&pdev->dev,
						&regulators[i], &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev,
				"Failed to initialize regulator-%d\n", i);
			return PTR_ERR(rdev);
		}
	}

	return 0;
}

