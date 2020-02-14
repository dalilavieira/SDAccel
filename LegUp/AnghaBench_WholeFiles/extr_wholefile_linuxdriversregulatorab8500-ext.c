#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct regulator_dev {struct regulation_constraints* constraints; } ;
struct regulator_config {TYPE_1__* init_data; int /*<<< orphan*/  of_node; struct ab8500_ext_regulator_info* driver_data; TYPE_2__* dev; } ;
struct regulation_constraints {int min_uV; int max_uV; } ;
struct TYPE_11__ {struct device_node* of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct device_node {int dummy; } ;
struct ab8500_regulator_platform_data {int num_ext_regulator; TYPE_1__* ext_regulator; } ;
struct TYPE_12__ {int name; } ;
struct ab8500_ext_regulator_info {int update_val_hp; int update_val; int update_reg; int update_mask; int update_val_hw; int update_val_lp; TYPE_5__ desc; struct regulator_dev* rdev; TYPE_1__* init_data; int /*<<< orphan*/  of_node; struct ab8500_ext_regulator_cfg* cfg; TYPE_2__* dev; int /*<<< orphan*/  update_bank; } ;
struct ab8500_ext_regulator_cfg {scalar_t__ hwreq; } ;
struct ab8500 {int dummy; } ;
struct TYPE_10__ {scalar_t__ driver_data; } ;

/* Variables and functions */
 size_t AB8500_EXT_SUPPLY3 ; 
 int ARRAY_SIZE (struct ab8500_ext_regulator_info*) ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
#define  REGULATOR_MODE_IDLE 129 
#define  REGULATOR_MODE_NORMAL 128 
 struct ab8500_ext_regulator_info* ab8500_ext_regulator_info ; 
 struct ab8500_ext_regulator_info* ab8500_ext_regulator_match ; 
 struct ab8500_regulator_platform_data ab8500_regulator_plat_data ; 
 int abx500_get_register_interruptible (TYPE_2__*,int /*<<< orphan*/ ,int,int*) ; 
 int abx500_mask_and_set_register_interruptible (TYPE_2__*,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,int,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct ab8500* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_2__*,TYPE_5__*,struct regulator_config*) ; 
 scalar_t__ is_ab8500_2p0_or_earlier (struct ab8500*) ; 
 int of_regulator_match (TYPE_2__*,struct device_node*,struct ab8500_ext_regulator_info*,int) ; 
 TYPE_2__* rdev_get_dev (struct regulator_dev*) ; 
 struct ab8500_ext_regulator_info* rdev_get_drvdata (struct regulator_dev*) ; 

__attribute__((used)) static int ab8500_ext_regulator_enable(struct regulator_dev *rdev)
{
	int ret;
	struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
	u8 regval;

	if (info == NULL) {
		dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
		return -EINVAL;
	}

	/*
	 * To satisfy both HW high power request and SW request, the regulator
	 * must be on in high power.
	 */
	if (info->cfg && info->cfg->hwreq)
		regval = info->update_val_hp;
	else
		regval = info->update_val;

	ret = abx500_mask_and_set_register_interruptible(info->dev,
		info->update_bank, info->update_reg,
		info->update_mask, regval);
	if (ret < 0) {
		dev_err(rdev_get_dev(info->rdev),
			"couldn't set enable bits for regulator\n");
		return ret;
	}

	dev_dbg(rdev_get_dev(rdev),
		"%s-enable (bank, reg, mask, value): 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
		info->desc.name, info->update_bank, info->update_reg,
		info->update_mask, regval);

	return 0;
}

__attribute__((used)) static int ab8500_ext_regulator_disable(struct regulator_dev *rdev)
{
	int ret;
	struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
	u8 regval;

	if (info == NULL) {
		dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
		return -EINVAL;
	}

	/*
	 * Set the regulator in HW request mode if configured
	 */
	if (info->cfg && info->cfg->hwreq)
		regval = info->update_val_hw;
	else
		regval = 0;

	ret = abx500_mask_and_set_register_interruptible(info->dev,
		info->update_bank, info->update_reg,
		info->update_mask, regval);
	if (ret < 0) {
		dev_err(rdev_get_dev(info->rdev),
			"couldn't set disable bits for regulator\n");
		return ret;
	}

	dev_dbg(rdev_get_dev(rdev), "%s-disable (bank, reg, mask, value):"
		" 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
		info->desc.name, info->update_bank, info->update_reg,
		info->update_mask, regval);

	return 0;
}

__attribute__((used)) static int ab8500_ext_regulator_is_enabled(struct regulator_dev *rdev)
{
	int ret;
	struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
	u8 regval;

	if (info == NULL) {
		dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
		return -EINVAL;
	}

	ret = abx500_get_register_interruptible(info->dev,
		info->update_bank, info->update_reg, &regval);
	if (ret < 0) {
		dev_err(rdev_get_dev(rdev),
			"couldn't read 0x%x register\n", info->update_reg);
		return ret;
	}

	dev_dbg(rdev_get_dev(rdev), "%s-is_enabled (bank, reg, mask, value):"
		" 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
		info->desc.name, info->update_bank, info->update_reg,
		info->update_mask, regval);

	if (((regval & info->update_mask) == info->update_val_lp) ||
	    ((regval & info->update_mask) == info->update_val_hp))
		return 1;
	else
		return 0;
}

__attribute__((used)) static int ab8500_ext_regulator_set_mode(struct regulator_dev *rdev,
					 unsigned int mode)
{
	int ret = 0;
	struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
	u8 regval;

	if (info == NULL) {
		dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
		return -EINVAL;
	}

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		regval = info->update_val_hp;
		break;
	case REGULATOR_MODE_IDLE:
		regval = info->update_val_lp;
		break;

	default:
		return -EINVAL;
	}

	/* If regulator is enabled and info->cfg->hwreq is set, the regulator
	   must be on in high power, so we don't need to write the register with
	   the same value.
	 */
	if (ab8500_ext_regulator_is_enabled(rdev) &&
	    !(info->cfg && info->cfg->hwreq)) {
		ret = abx500_mask_and_set_register_interruptible(info->dev,
					info->update_bank, info->update_reg,
					info->update_mask, regval);
		if (ret < 0) {
			dev_err(rdev_get_dev(rdev),
				"Could not set regulator mode.\n");
			return ret;
		}

		dev_dbg(rdev_get_dev(rdev),
			"%s-set_mode (bank, reg, mask, value): "
			"0x%x, 0x%x, 0x%x, 0x%x\n",
			info->desc.name, info->update_bank, info->update_reg,
			info->update_mask, regval);
	}

	info->update_val = regval;

	return 0;
}

__attribute__((used)) static unsigned int ab8500_ext_regulator_get_mode(struct regulator_dev *rdev)
{
	struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
	int ret;

	if (info == NULL) {
		dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
		return -EINVAL;
	}

	if (info->update_val == info->update_val_hp)
		ret = REGULATOR_MODE_NORMAL;
	else if (info->update_val == info->update_val_lp)
		ret = REGULATOR_MODE_IDLE;
	else
		ret = -EINVAL;

	return ret;
}

__attribute__((used)) static int ab8500_ext_set_voltage(struct regulator_dev *rdev, int min_uV,
				  int max_uV, unsigned *selector)
{
	struct regulation_constraints *regu_constraints = rdev->constraints;

	if (!regu_constraints) {
		dev_err(rdev_get_dev(rdev), "No regulator constraints\n");
		return -EINVAL;
	}

	if (regu_constraints->min_uV == min_uV &&
	    regu_constraints->max_uV == max_uV)
		return 0;

	dev_err(rdev_get_dev(rdev),
		"Requested min %duV max %duV != constrained min %duV max %duV\n",
		min_uV, max_uV,
		regu_constraints->min_uV, regu_constraints->max_uV);

	return -EINVAL;
}

__attribute__((used)) static int ab8500_ext_list_voltage(struct regulator_dev *rdev,
				   unsigned selector)
{
	struct regulation_constraints *regu_constraints = rdev->constraints;

	if (regu_constraints == NULL) {
		dev_err(rdev_get_dev(rdev), "regulator constraints null pointer\n");
		return -EINVAL;
	}
	/* return the uV for the fixed regulators */
	if (regu_constraints->min_uV && regu_constraints->max_uV) {
		if (regu_constraints->min_uV == regu_constraints->max_uV)
			return regu_constraints->min_uV;
	}
	return -EINVAL;
}

__attribute__((used)) static int ab8500_ext_regulator_probe(struct platform_device *pdev)
{
	struct ab8500 *ab8500 = dev_get_drvdata(pdev->dev.parent);
	struct ab8500_regulator_platform_data *pdata = &ab8500_regulator_plat_data;
	struct device_node *np = pdev->dev.of_node;
	struct regulator_config config = { };
	int i, err;

	if (np) {
		err = of_regulator_match(&pdev->dev, np,
					 ab8500_ext_regulator_match,
					 ARRAY_SIZE(ab8500_ext_regulator_match));
		if (err < 0) {
			dev_err(&pdev->dev,
				"Error parsing regulator init data: %d\n", err);
			return err;
		}
	}

	if (!ab8500) {
		dev_err(&pdev->dev, "null mfd parent\n");
		return -EINVAL;
	}

	/* make sure the platform data has the correct size */
	if (pdata->num_ext_regulator != ARRAY_SIZE(ab8500_ext_regulator_info)) {
		dev_err(&pdev->dev, "Configuration error: size mismatch.\n");
		return -EINVAL;
	}

	/* check for AB8500 2.x */
	if (is_ab8500_2p0_or_earlier(ab8500)) {
		struct ab8500_ext_regulator_info *info;

		/* VextSupply3LPn is inverted on AB8500 2.x */
		info = &ab8500_ext_regulator_info[AB8500_EXT_SUPPLY3];
		info->update_val = 0x30;
		info->update_val_hp = 0x30;
		info->update_val_lp = 0x10;
	}

	/* register all regulators */
	for (i = 0; i < ARRAY_SIZE(ab8500_ext_regulator_info); i++) {
		struct ab8500_ext_regulator_info *info = NULL;

		/* assign per-regulator data */
		info = &ab8500_ext_regulator_info[i];
		info->dev = &pdev->dev;
		info->cfg = (struct ab8500_ext_regulator_cfg *)
			pdata->ext_regulator[i].driver_data;

		config.dev = &pdev->dev;
		config.driver_data = info;
		config.of_node = ab8500_ext_regulator_match[i].of_node;
		config.init_data = (np) ?
			ab8500_ext_regulator_match[i].init_data :
			&pdata->ext_regulator[i];

		/* register regulator with framework */
		info->rdev = devm_regulator_register(&pdev->dev, &info->desc,
						     &config);
		if (IS_ERR(info->rdev)) {
			err = PTR_ERR(info->rdev);
			dev_err(&pdev->dev, "failed to register regulator %s\n",
					info->desc.name);
			return err;
		}

		dev_dbg(rdev_get_dev(info->rdev),
			"%s-probed\n", info->desc.name);
	}

	return 0;
}

