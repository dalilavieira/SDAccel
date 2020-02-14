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
struct regulator_dev {TYPE_1__* constraints; } ;
struct regulator_config {int /*<<< orphan*/  regmap; struct lp87565* driver_data; TYPE_3__* dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {int name; TYPE_3__ dev; } ;
struct lp87565 {scalar_t__ dev_type; TYPE_4__* dev; int /*<<< orphan*/  regmap; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; } ;
struct TYPE_6__ {int /*<<< orphan*/  desc; int /*<<< orphan*/  ctrl2_reg; } ;
struct TYPE_5__ {int ramp_delay; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int LP87565_BUCK_1 ; 
 int LP87565_BUCK_10 ; 
 int LP87565_BUCK_23 ; 
 int LP87565_BUCK_3 ; 
 unsigned int LP87565_BUCK_CTRL_2_ILIM ; 
 unsigned int LP87565_BUCK_CTRL_2_SLEW_RATE ; 
 scalar_t__ LP87565_DEVICE_TYPE_LP87565_Q1 ; 
 int PTR_ERR (struct regulator_dev*) ; 
 unsigned int __ffs (unsigned int) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,int) ; 
 struct lp87565* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_3__*,int /*<<< orphan*/ *,struct regulator_config*) ; 
 int* lp87565_buck_ramp_delay ; 
 int* lp87565_buck_uA ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lp87565*) ; 
 struct lp87565* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int) ; 
 TYPE_2__* regulators ; 

__attribute__((used)) static int lp87565_buck_set_ramp_delay(struct regulator_dev *rdev,
				       int ramp_delay)
{
	int id = rdev_get_id(rdev);
	struct lp87565 *lp87565 = rdev_get_drvdata(rdev);
	unsigned int reg;
	int ret;

	if (ramp_delay <= 470)
		reg = 7;
	else if (ramp_delay <= 940)
		reg = 6;
	else if (ramp_delay <= 1900)
		reg = 5;
	else if (ramp_delay <= 3800)
		reg = 4;
	else if (ramp_delay <= 7500)
		reg = 3;
	else if (ramp_delay <= 10000)
		reg = 2;
	else if (ramp_delay <= 15000)
		reg = 1;
	else
		reg = 0;

	ret = regmap_update_bits(lp87565->regmap, regulators[id].ctrl2_reg,
				 LP87565_BUCK_CTRL_2_SLEW_RATE,
				 reg << __ffs(LP87565_BUCK_CTRL_2_SLEW_RATE));
	if (ret) {
		dev_err(lp87565->dev, "SLEW RATE write failed: %d\n", ret);
		return ret;
	}

	rdev->constraints->ramp_delay = lp87565_buck_ramp_delay[reg];

	/* Conservatively give a 15% margin */
	rdev->constraints->ramp_delay =
				rdev->constraints->ramp_delay * 85 / 100;

	return 0;
}

__attribute__((used)) static int lp87565_buck_set_current_limit(struct regulator_dev *rdev,
					  int min_uA, int max_uA)
{
	int id = rdev_get_id(rdev);
	struct lp87565 *lp87565 = rdev_get_drvdata(rdev);
	int i;

	for (i = ARRAY_SIZE(lp87565_buck_uA) - 1; i >= 0; i--) {
		if (lp87565_buck_uA[i] >= min_uA &&
		    lp87565_buck_uA[i] <= max_uA)
			return regmap_update_bits(lp87565->regmap,
						  regulators[id].ctrl2_reg,
						  LP87565_BUCK_CTRL_2_ILIM,
						  i << __ffs(LP87565_BUCK_CTRL_2_ILIM));
	}

	return -EINVAL;
}

__attribute__((used)) static int lp87565_buck_get_current_limit(struct regulator_dev *rdev)
{
	int id = rdev_get_id(rdev);
	struct lp87565 *lp87565 = rdev_get_drvdata(rdev);
	int ret;
	unsigned int val;

	ret = regmap_read(lp87565->regmap, regulators[id].ctrl2_reg, &val);
	if (ret)
		return ret;

	val = (val & LP87565_BUCK_CTRL_2_ILIM) >>
	       __ffs(LP87565_BUCK_CTRL_2_ILIM);

	return (val < ARRAY_SIZE(lp87565_buck_uA)) ?
			lp87565_buck_uA[val] : -EINVAL;
}

__attribute__((used)) static int lp87565_regulator_probe(struct platform_device *pdev)
{
	struct lp87565 *lp87565 = dev_get_drvdata(pdev->dev.parent);
	struct regulator_config config = { };
	struct regulator_dev *rdev;
	int i, min_idx = LP87565_BUCK_1, max_idx = LP87565_BUCK_3;

	platform_set_drvdata(pdev, lp87565);

	config.dev = &pdev->dev;
	config.dev->of_node = lp87565->dev->of_node;
	config.driver_data = lp87565;
	config.regmap = lp87565->regmap;

	if (lp87565->dev_type == LP87565_DEVICE_TYPE_LP87565_Q1) {
		min_idx = LP87565_BUCK_10;
		max_idx = LP87565_BUCK_23;
	}

	for (i = min_idx; i <= max_idx; i++) {
		rdev = devm_regulator_register(&pdev->dev, &regulators[i].desc,
					       &config);
		if (IS_ERR(rdev)) {
			dev_err(lp87565->dev, "failed to register %s regulator\n",
				pdev->name);
			return PTR_ERR(rdev);
		}
	}

	return 0;
}

