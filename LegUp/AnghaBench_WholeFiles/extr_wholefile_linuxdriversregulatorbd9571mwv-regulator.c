#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct regulator_dev {TYPE_1__* desc; int /*<<< orphan*/  regmap; } ;
struct regulator_config {int /*<<< orphan*/  regmap; struct bd9571mwv* driver_data; TYPE_2__* dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {int /*<<< orphan*/  name; TYPE_2__ dev; } ;
struct bd9571mwv_reg {unsigned int bkup_mode_cnt_keepon; void* rstbmode_pulse; void* rstbmode_level; struct bd9571mwv* bd; } ;
struct bd9571mwv {TYPE_4__* dev; int /*<<< orphan*/  regmap; } ;
struct TYPE_7__ {int /*<<< orphan*/  of_node; } ;
struct TYPE_5__ {unsigned int vsel_mask; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BD9571MWV_AVS_SET_MONI ; 
 unsigned int BD9571MWV_AVS_SET_MONI_MASK ; 
 int /*<<< orphan*/  BD9571MWV_AVS_VD09_VID (int) ; 
 unsigned int BD9571MWV_BKUP_MODE_CNT_KEEPON_MASK ; 
 int /*<<< orphan*/  BD9571MWV_DVFS_SETVID ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,...) ; 
 struct bd9571mwv* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct bd9571mwv_reg* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_2__*,int /*<<< orphan*/ *,struct regulator_config*) ; 
 int ffs (unsigned int) ; 
 void* of_property_read_bool (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  of_property_read_u32 (int /*<<< orphan*/ ,char*,unsigned int*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct bd9571mwv_reg*) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int /*<<< orphan*/ * regulators ; 

__attribute__((used)) static int bd9571mwv_avs_get_moni_state(struct regulator_dev *rdev)
{
	unsigned int val;
	int ret;

	ret = regmap_read(rdev->regmap, BD9571MWV_AVS_SET_MONI, &val);
	if (ret != 0)
		return ret;

	return val & BD9571MWV_AVS_SET_MONI_MASK;
}

__attribute__((used)) static int bd9571mwv_avs_set_voltage_sel_regmap(struct regulator_dev *rdev,
						unsigned int sel)
{
	int ret;

	ret = bd9571mwv_avs_get_moni_state(rdev);
	if (ret < 0)
		return ret;

	return regmap_write_bits(rdev->regmap, BD9571MWV_AVS_VD09_VID(ret),
				 rdev->desc->vsel_mask, sel);
}

__attribute__((used)) static int bd9571mwv_avs_get_voltage_sel_regmap(struct regulator_dev *rdev)
{
	unsigned int val;
	int ret;

	ret = bd9571mwv_avs_get_moni_state(rdev);
	if (ret < 0)
		return ret;

	ret = regmap_read(rdev->regmap, BD9571MWV_AVS_VD09_VID(ret), &val);
	if (ret != 0)
		return ret;

	val &= rdev->desc->vsel_mask;
	val >>= ffs(rdev->desc->vsel_mask) - 1;

	return val;
}

__attribute__((used)) static int bd9571mwv_reg_set_voltage_sel_regmap(struct regulator_dev *rdev,
						unsigned int sel)
{
	return regmap_write_bits(rdev->regmap, BD9571MWV_DVFS_SETVID,
				 rdev->desc->vsel_mask, sel);
}

__attribute__((used)) static int bd9571mwv_regulator_probe(struct platform_device *pdev)
{
	struct bd9571mwv *bd = dev_get_drvdata(pdev->dev.parent);
	struct regulator_config config = { };
	struct bd9571mwv_reg *bdreg;
	struct regulator_dev *rdev;
	unsigned int val;
	int i;

	bdreg = devm_kzalloc(&pdev->dev, sizeof(*bdreg), GFP_KERNEL);
	if (!bdreg)
		return -ENOMEM;

	bdreg->bd = bd;

	platform_set_drvdata(pdev, bdreg);

	config.dev = &pdev->dev;
	config.dev->of_node = bd->dev->of_node;
	config.driver_data = bd;
	config.regmap = bd->regmap;

	for (i = 0; i < ARRAY_SIZE(regulators); i++) {
		rdev = devm_regulator_register(&pdev->dev, &regulators[i],
					       &config);
		if (IS_ERR(rdev)) {
			dev_err(bd->dev, "failed to register %s regulator\n",
				pdev->name);
			return PTR_ERR(rdev);
		}
	}

	val = 0;
	of_property_read_u32(bd->dev->of_node, "rohm,ddr-backup-power", &val);
	if (val & ~BD9571MWV_BKUP_MODE_CNT_KEEPON_MASK) {
		dev_err(bd->dev, "invalid %s mode %u\n",
			"rohm,ddr-backup-power", val);
		return -EINVAL;
	}
	bdreg->bkup_mode_cnt_keepon = val;

	bdreg->rstbmode_level = of_property_read_bool(bd->dev->of_node,
						      "rohm,rstbmode-level");
	bdreg->rstbmode_pulse = of_property_read_bool(bd->dev->of_node,
						      "rohm,rstbmode-pulse");
	if (bdreg->rstbmode_level && bdreg->rstbmode_pulse) {
		dev_err(bd->dev, "only one rohm,rstbmode-* may be specified");
		return -EINVAL;
	}

#ifdef CONFIG_PM_SLEEP
	if (bdreg->bkup_mode_cnt_keepon) {
		int ret;

		/*
		 * Backup mode is enabled by default in pulse mode, but needs
		 * explicit user setup in level mode.
		 */
		bdreg->bkup_mode_enabled = bdreg->rstbmode_pulse;

		ret = device_create_file(&pdev->dev, &dev_attr_backup_mode);
		if (ret)
			return ret;
	}
#endif /* CONFIG_PM_SLEEP */

	return 0;
}

