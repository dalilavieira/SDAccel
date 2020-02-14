#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct regulator_dev {int /*<<< orphan*/  regmap; } ;
struct regulator_config {struct hi655x_regulator* driver_data; int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; } ;
struct TYPE_9__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;
struct hi655x_regulator {TYPE_1__ rdesc; int /*<<< orphan*/  ctrl_mask; int /*<<< orphan*/  disable_reg; int /*<<< orphan*/  status_reg; } ;
struct hi655x_pmic {int /*<<< orphan*/  regmap; } ;
struct TYPE_8__ {int /*<<< orphan*/  rdesc; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_2__*) ; 
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 struct hi655x_pmic* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct hi655x_regulator* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_3__*,int /*<<< orphan*/ *,struct regulator_config*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct hi655x_regulator*) ; 
 struct hi655x_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 TYPE_2__* regulators ; 

__attribute__((used)) static int hi655x_is_enabled(struct regulator_dev *rdev)
{
	unsigned int value = 0;

	struct hi655x_regulator *regulator = rdev_get_drvdata(rdev);

	regmap_read(rdev->regmap, regulator->status_reg, &value);
	return (value & BIT(regulator->ctrl_mask));
}

__attribute__((used)) static int hi655x_disable(struct regulator_dev *rdev)
{
	int ret = 0;

	struct hi655x_regulator *regulator = rdev_get_drvdata(rdev);

	ret = regmap_write(rdev->regmap, regulator->disable_reg,
			   BIT(regulator->ctrl_mask));
	return ret;
}

__attribute__((used)) static int hi655x_regulator_probe(struct platform_device *pdev)
{
	unsigned int i;
	struct hi655x_regulator *regulator;
	struct hi655x_pmic *pmic;
	struct regulator_config config = { };
	struct regulator_dev *rdev;

	pmic = dev_get_drvdata(pdev->dev.parent);
	if (!pmic) {
		dev_err(&pdev->dev, "no pmic in the regulator parent node\n");
		return -ENODEV;
	}

	regulator = devm_kzalloc(&pdev->dev, sizeof(*regulator), GFP_KERNEL);
	if (!regulator)
		return -ENOMEM;

	platform_set_drvdata(pdev, regulator);

	config.dev = pdev->dev.parent;
	config.regmap = pmic->regmap;
	config.driver_data = regulator;
	for (i = 0; i < ARRAY_SIZE(regulators); i++) {
		rdev = devm_regulator_register(&pdev->dev,
					       &regulators[i].rdesc,
					       &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "failed to register regulator %s\n",
				regulator->rdesc.name);
			return PTR_ERR(rdev);
		}
	}
	return 0;
}

