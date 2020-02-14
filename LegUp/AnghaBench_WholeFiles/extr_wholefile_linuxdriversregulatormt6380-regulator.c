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
struct regulator_dev {int /*<<< orphan*/  regmap; } ;
struct regulator_config {struct regmap* regmap; TYPE_1__* driver_data; TYPE_2__* dev; } ;
struct regmap {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct mt6380_regulator_info {unsigned int modeset_mask; int /*<<< orphan*/  modeset_reg; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;
struct TYPE_5__ {TYPE_3__ desc; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int MT6380_MAX_REGULATOR ; 
#define  MT6380_REGULATOR_MODE_AUTO 131 
#define  MT6380_REGULATOR_MODE_FORCE_PWM 130 
 int PTR_ERR (struct regulator_dev*) ; 
#define  REGULATOR_MODE_FAST 129 
#define  REGULATOR_MODE_NORMAL 128 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 struct regmap* dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct regulator_dev* devm_regulator_register (TYPE_2__*,TYPE_3__*,struct regulator_config*) ; 
 int ffs (unsigned int) ; 
 TYPE_1__* mt6380_regulators ; 
 struct mt6380_regulator_info* rdev_get_drvdata (struct regulator_dev*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int) ; 

__attribute__((used)) static int mt6380_regulator_set_mode(struct regulator_dev *rdev,
				     unsigned int mode)
{
	int ret, val = 0;
	struct mt6380_regulator_info *info = rdev_get_drvdata(rdev);

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		val = MT6380_REGULATOR_MODE_AUTO;
		break;
	case REGULATOR_MODE_FAST:
		val = MT6380_REGULATOR_MODE_FORCE_PWM;
		break;
	default:
		return -EINVAL;
	}

	val <<= ffs(info->modeset_mask) - 1;

	ret = regmap_update_bits(rdev->regmap, info->modeset_reg,
				 info->modeset_mask, val);

	return ret;
}

__attribute__((used)) static unsigned int mt6380_regulator_get_mode(struct regulator_dev *rdev)
{
	unsigned int val;
	unsigned int mode;
	int ret;
	struct mt6380_regulator_info *info = rdev_get_drvdata(rdev);

	ret = regmap_read(rdev->regmap, info->modeset_reg, &val);
	if (ret < 0)
		return ret;

	val &= info->modeset_mask;
	val >>= ffs(info->modeset_mask) - 1;

	switch (val) {
	case MT6380_REGULATOR_MODE_AUTO:
		mode = REGULATOR_MODE_NORMAL;
		break;
	case MT6380_REGULATOR_MODE_FORCE_PWM:
		mode = REGULATOR_MODE_FAST;
		break;
	default:
		return -EINVAL;
	}

	return mode;
}

__attribute__((used)) static int mt6380_regulator_probe(struct platform_device *pdev)
{
	struct regmap *regmap = dev_get_regmap(pdev->dev.parent, NULL);
	struct regulator_config config = {};
	struct regulator_dev *rdev;
	int i;

	for (i = 0; i < MT6380_MAX_REGULATOR; i++) {
		config.dev = &pdev->dev;
		config.driver_data = &mt6380_regulators[i];
		config.regmap = regmap;
		rdev = devm_regulator_register(&pdev->dev,
					       &mt6380_regulators[i].desc,
				&config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "failed to register %s\n",
				mt6380_regulators[i].desc.name);
			return PTR_ERR(rdev);
		}
	}
	return 0;
}

