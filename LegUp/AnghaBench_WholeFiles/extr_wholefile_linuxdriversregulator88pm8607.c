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
struct regulator_config {int /*<<< orphan*/  regmap; struct regulator_init_data* init_data; struct pm8607_regulator_info* driver_data; TYPE_2__* dev; } ;
struct pm860x_chip {scalar_t__ id; int /*<<< orphan*/  regmap_companion; int /*<<< orphan*/  regmap; scalar_t__ buck3_double; int /*<<< orphan*/  client; int /*<<< orphan*/  companion; } ;
struct TYPE_8__ {scalar_t__ vsel_reg; unsigned long long name; } ;
struct pm8607_regulator_info {int* vol_table; int slope_double; int /*<<< orphan*/  regulator; TYPE_3__ desc; struct pm860x_chip* chip; int /*<<< orphan*/  i2c_8606; int /*<<< orphan*/  i2c; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_6__ {unsigned int n_voltages; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct pm8607_regulator_info*) ; 
 scalar_t__ CHIP_PM8607 ; 
 int EINVAL ; 
 int /*<<< orphan*/  IORESOURCE_REG ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PM8607_ID_BUCK3 ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,unsigned long long) ; 
 struct pm860x_chip* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct regulator_init_data* dev_get_platdata (TYPE_2__*) ; 
 int /*<<< orphan*/  devm_regulator_register (TYPE_2__*,TYPE_3__*,struct regulator_config*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct pm8607_regulator_info*) ; 
 struct pm8607_regulator_info* pm8606_regulator_info ; 
 scalar_t__ pm8607_regulator_dt_init (struct platform_device*,struct pm8607_regulator_info*,struct regulator_config*) ; 
 struct pm8607_regulator_info* pm8607_regulator_info ; 
 struct pm8607_regulator_info* rdev_get_drvdata (struct regulator_dev*) ; 

__attribute__((used)) static int pm8607_list_voltage(struct regulator_dev *rdev, unsigned index)
{
	struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
	int ret = -EINVAL;

	if (info->vol_table && (index < rdev->desc->n_voltages)) {
		ret = info->vol_table[index];
		if (info->slope_double)
			ret <<= 1;
	}
	return ret;
}

__attribute__((used)) static int pm8607_regulator_probe(struct platform_device *pdev)
{
	struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
	struct pm8607_regulator_info *info = NULL;
	struct regulator_init_data *pdata = dev_get_platdata(&pdev->dev);
	struct regulator_config config = { };
	struct resource *res;
	int i;

	res = platform_get_resource(pdev, IORESOURCE_REG, 0);
	if (res) {
		/* There're resources in 88PM8607 regulator driver */
		for (i = 0; i < ARRAY_SIZE(pm8607_regulator_info); i++) {
			info = &pm8607_regulator_info[i];
			if (info->desc.vsel_reg == res->start)
				break;
		}
		if (i == ARRAY_SIZE(pm8607_regulator_info)) {
			dev_err(&pdev->dev, "Failed to find regulator %llu\n",
				(unsigned long long)res->start);
			return -EINVAL;
		}
	} else {
		/* There's no resource in 88PM8606 PREG regulator driver */
		info = &pm8606_regulator_info[0];
		/* i is used to check regulator ID */
		i = -1;
	}
	info->i2c = (chip->id == CHIP_PM8607) ? chip->client : chip->companion;
	info->i2c_8606 = (chip->id == CHIP_PM8607) ? chip->companion :
			chip->client;
	info->chip = chip;

	/* check DVC ramp slope double */
	if ((i == PM8607_ID_BUCK3) && info->chip->buck3_double)
		info->slope_double = 1;

	config.dev = &pdev->dev;
	config.driver_data = info;

	if (pm8607_regulator_dt_init(pdev, info, &config))
		if (pdata)
			config.init_data = pdata;

	if (chip->id == CHIP_PM8607)
		config.regmap = chip->regmap;
	else
		config.regmap = chip->regmap_companion;

	info->regulator = devm_regulator_register(&pdev->dev, &info->desc,
						  &config);
	if (IS_ERR(info->regulator)) {
		dev_err(&pdev->dev, "failed to register regulator %s\n",
			info->desc.name);
		return PTR_ERR(info->regulator);
	}

	platform_set_drvdata(pdev, info);
	return 0;
}

