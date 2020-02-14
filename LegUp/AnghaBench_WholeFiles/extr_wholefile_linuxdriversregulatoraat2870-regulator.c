#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct regulator_dev {int dummy; } ;
struct regulator_config {int /*<<< orphan*/  init_data; struct aat2870_regulator* driver_data; TYPE_1__* dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct platform_device {int id; TYPE_1__ dev; } ;
struct TYPE_6__ {int id; int name; } ;
struct aat2870_regulator {unsigned int voltage_mask; unsigned int voltage_shift; unsigned int enable_mask; int enable_shift; TYPE_2__ desc; struct aat2870_data* aat2870; int /*<<< orphan*/  voltage_addr; int /*<<< orphan*/  enable_addr; } ;
struct aat2870_data {int (* update ) (struct aat2870_data*,int /*<<< orphan*/ ,unsigned int,unsigned int) ;int (* read ) (struct aat2870_data*,int /*<<< orphan*/ ,int*) ;} ;

/* Variables and functions */
 int AAT2870_ID_LDOA ; 
 int /*<<< orphan*/  AAT2870_LDO_AB ; 
 int /*<<< orphan*/  AAT2870_LDO_CD ; 
 int /*<<< orphan*/  AAT2870_LDO_EN ; 
 int ARRAY_SIZE (struct aat2870_regulator*) ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 struct aat2870_regulator* aat2870_regulators ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 struct aat2870_data* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_get_platdata (TYPE_1__*) ; 
 struct regulator_dev* devm_regulator_register (TYPE_1__*,TYPE_2__*,struct regulator_config*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct regulator_dev*) ; 
 struct aat2870_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int stub1 (struct aat2870_data*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int stub2 (struct aat2870_data*,int /*<<< orphan*/ ,int*) ; 
 int stub3 (struct aat2870_data*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int stub4 (struct aat2870_data*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int stub5 (struct aat2870_data*,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int aat2870_ldo_set_voltage_sel(struct regulator_dev *rdev,
				       unsigned selector)
{
	struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
	struct aat2870_data *aat2870 = ri->aat2870;

	return aat2870->update(aat2870, ri->voltage_addr, ri->voltage_mask,
			       selector << ri->voltage_shift);
}

__attribute__((used)) static int aat2870_ldo_get_voltage_sel(struct regulator_dev *rdev)
{
	struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
	struct aat2870_data *aat2870 = ri->aat2870;
	u8 val;
	int ret;

	ret = aat2870->read(aat2870, ri->voltage_addr, &val);
	if (ret)
		return ret;

	return (val & ri->voltage_mask) >> ri->voltage_shift;
}

__attribute__((used)) static int aat2870_ldo_enable(struct regulator_dev *rdev)
{
	struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
	struct aat2870_data *aat2870 = ri->aat2870;

	return aat2870->update(aat2870, ri->enable_addr, ri->enable_mask,
			       ri->enable_mask);
}

__attribute__((used)) static int aat2870_ldo_disable(struct regulator_dev *rdev)
{
	struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
	struct aat2870_data *aat2870 = ri->aat2870;

	return aat2870->update(aat2870, ri->enable_addr, ri->enable_mask, 0);
}

__attribute__((used)) static int aat2870_ldo_is_enabled(struct regulator_dev *rdev)
{
	struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
	struct aat2870_data *aat2870 = ri->aat2870;
	u8 val;
	int ret;

	ret = aat2870->read(aat2870, ri->enable_addr, &val);
	if (ret)
		return ret;

	return val & ri->enable_mask ? 1 : 0;
}

__attribute__((used)) static struct aat2870_regulator *aat2870_get_regulator(int id)
{
	struct aat2870_regulator *ri = NULL;
	int i;

	for (i = 0; i < ARRAY_SIZE(aat2870_regulators); i++) {
		ri = &aat2870_regulators[i];
		if (ri->desc.id == id)
			break;
	}

	if (i == ARRAY_SIZE(aat2870_regulators))
		return NULL;

	ri->enable_addr = AAT2870_LDO_EN;
	ri->enable_shift = id - AAT2870_ID_LDOA;
	ri->enable_mask = 0x1 << ri->enable_shift;

	ri->voltage_addr = (id - AAT2870_ID_LDOA) / 2 ?
			   AAT2870_LDO_CD : AAT2870_LDO_AB;
	ri->voltage_shift = (id - AAT2870_ID_LDOA) % 2 ? 0 : 4;
	ri->voltage_mask = 0xF << ri->voltage_shift;

	return ri;
}

__attribute__((used)) static int aat2870_regulator_probe(struct platform_device *pdev)
{
	struct aat2870_regulator *ri;
	struct regulator_config config = { };
	struct regulator_dev *rdev;

	ri = aat2870_get_regulator(pdev->id);
	if (!ri) {
		dev_err(&pdev->dev, "Invalid device ID, %d\n", pdev->id);
		return -EINVAL;
	}
	ri->aat2870 = dev_get_drvdata(pdev->dev.parent);

	config.dev = &pdev->dev;
	config.driver_data = ri;
	config.init_data = dev_get_platdata(&pdev->dev);

	rdev = devm_regulator_register(&pdev->dev, &ri->desc, &config);
	if (IS_ERR(rdev)) {
		dev_err(&pdev->dev, "Failed to register regulator %s\n",
			ri->desc.name);
		return PTR_ERR(rdev);
	}
	platform_set_drvdata(pdev, rdev);

	return 0;
}

