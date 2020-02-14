#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct tps65090_regulator_plat_data {int overcurrent_wait; scalar_t__ enable_ext_control; TYPE_4__* reg_init_data; int /*<<< orphan*/  gpiod; scalar_t__ overcurrent_wait_valid; } ;
struct tps65090_regulator {int overcurrent_wait; scalar_t__ overcurrent_wait_valid; struct tps65090_platform_data* rdev; TYPE_5__* desc; TYPE_6__* dev; } ;
struct TYPE_17__ {struct device* parent; } ;
struct tps65090_platform_data {struct tps65090_regulator_plat_data** reg_pdata; TYPE_2__* desc; TYPE_6__ dev; int /*<<< orphan*/  regmap; } ;
struct tps65090 {int /*<<< orphan*/  rmap; TYPE_1__* dev; } ;
struct regulator_dev {struct tps65090_regulator_plat_data** reg_pdata; TYPE_2__* desc; TYPE_6__ dev; int /*<<< orphan*/  regmap; } ;
struct regulator_config {int /*<<< orphan*/ * of_node; TYPE_4__* init_data; int /*<<< orphan*/  regmap; struct tps65090_regulator* driver_data; struct device* dev; int /*<<< orphan*/  ena_gpiod; } ;
struct platform_device {TYPE_6__ dev; } ;
struct of_regulator_match {int /*<<< orphan*/ * of_node; } ;
struct device {int dummy; } ;
struct TYPE_16__ {unsigned int enable_reg; unsigned int name; int /*<<< orphan*/ * ops; } ;
struct TYPE_14__ {scalar_t__ boot_on; scalar_t__ always_on; } ;
struct TYPE_15__ {TYPE_3__ constraints; } ;
struct TYPE_13__ {unsigned int enable_reg; int enable_mask; } ;
struct TYPE_12__ {scalar_t__ of_node; } ;

/* Variables and functions */
 unsigned int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CTRL_PG_BIT ; 
 int /*<<< orphan*/  CTRL_TO_BIT ; 
 int CTRL_WT_BIT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENOTRECOVERABLE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct tps65090_platform_data*) ; 
 scalar_t__ IS_ERR_OR_NULL (struct tps65090_platform_data*) ; 
 int MAX_CTRL_READ_TRIES ; 
 int MAX_FET_ENABLE_TRIES ; 
 int MAX_OVERCURRENT_WAIT ; 
 int PTR_ERR (struct tps65090_platform_data*) ; 
#define  TPS65090_REGULATOR_DCDC1 130 
#define  TPS65090_REGULATOR_DCDC2 129 
#define  TPS65090_REGULATOR_DCDC3 128 
 int TPS65090_REGULATOR_MAX ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_6__*,char*) ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,...) ; 
 struct tps65090* dev_get_drvdata (struct device*) ; 
 struct tps65090_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_6__*,char*,unsigned int,...) ; 
 struct tps65090_regulator* devm_kcalloc (TYPE_6__*,int,int,int /*<<< orphan*/ ) ; 
 struct tps65090_platform_data* devm_regulator_register (TYPE_6__*,TYPE_5__*,struct regulator_config*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tps65090_regulator*) ; 
 int regmap_read (int /*<<< orphan*/ ,unsigned int,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,int,int) ; 
 int tps65090_clr_bits (struct device*,unsigned int,int) ; 
 int /*<<< orphan*/  tps65090_ext_control_ops ; 
 TYPE_5__* tps65090_regulator_desc ; 
 int tps65090_set_bits (struct device*,unsigned int,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int tps65090_reg_set_overcurrent_wait(struct tps65090_regulator *ri,
					     struct regulator_dev *rdev)
{
	int ret;

	ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				 MAX_OVERCURRENT_WAIT << CTRL_WT_BIT,
				 ri->overcurrent_wait << CTRL_WT_BIT);
	if (ret) {
		dev_err(&rdev->dev, "Error updating overcurrent wait %#x\n",
			rdev->desc->enable_reg);
	}

	return ret;
}

__attribute__((used)) static int tps65090_try_enable_fet(struct regulator_dev *rdev)
{
	unsigned int control;
	int ret, i;

	ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				 rdev->desc->enable_mask,
				 rdev->desc->enable_mask);
	if (ret < 0) {
		dev_err(&rdev->dev, "Error in updating reg %#x\n",
			rdev->desc->enable_reg);
		return ret;
	}

	for (i = 0; i < MAX_CTRL_READ_TRIES; i++) {
		ret = regmap_read(rdev->regmap, rdev->desc->enable_reg,
				  &control);
		if (ret < 0)
			return ret;

		if (!(control & BIT(CTRL_TO_BIT)))
			break;

		usleep_range(1000, 1500);
	}
	if (!(control & BIT(CTRL_PG_BIT)))
		return -ENOTRECOVERABLE;

	return 0;
}

__attribute__((used)) static int tps65090_fet_enable(struct regulator_dev *rdev)
{
	int ret, tries;

	/*
	 * Try enabling multiple times until we succeed since sometimes the
	 * first try times out.
	 */
	tries = 0;
	while (true) {
		ret = tps65090_try_enable_fet(rdev);
		if (!ret)
			break;
		if (ret != -ENOTRECOVERABLE || tries == MAX_FET_ENABLE_TRIES)
			goto err;

		/* Try turning the FET off (and then on again) */
		ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
					 rdev->desc->enable_mask, 0);
		if (ret)
			goto err;

		tries++;
	}

	if (tries)
		dev_warn(&rdev->dev, "reg %#x enable ok after %d tries\n",
			 rdev->desc->enable_reg, tries);

	return 0;
err:
	dev_warn(&rdev->dev, "reg %#x enable failed\n", rdev->desc->enable_reg);
	WARN_ON(1);

	return ret;
}

__attribute__((used)) static inline bool is_dcdc(int id)
{
	switch (id) {
	case TPS65090_REGULATOR_DCDC1:
	case TPS65090_REGULATOR_DCDC2:
	case TPS65090_REGULATOR_DCDC3:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int tps65090_config_ext_control(
	struct tps65090_regulator *ri, bool enable)
{
	int ret;
	struct device *parent = ri->dev->parent;
	unsigned int reg_en_reg = ri->desc->enable_reg;

	if (enable)
		ret = tps65090_set_bits(parent, reg_en_reg, 1);
	else
		ret =  tps65090_clr_bits(parent, reg_en_reg, 1);
	if (ret < 0)
		dev_err(ri->dev, "Error in updating reg 0x%x\n", reg_en_reg);
	return ret;
}

__attribute__((used)) static int tps65090_regulator_disable_ext_control(
		struct tps65090_regulator *ri,
		struct tps65090_regulator_plat_data *tps_pdata)
{
	int ret = 0;
	struct device *parent = ri->dev->parent;
	unsigned int reg_en_reg = ri->desc->enable_reg;

	/*
	 * First enable output for internal control if require.
	 * And then disable external control.
	 */
	if (tps_pdata->reg_init_data->constraints.always_on ||
			tps_pdata->reg_init_data->constraints.boot_on) {
		ret =  tps65090_set_bits(parent, reg_en_reg, 0);
		if (ret < 0) {
			dev_err(ri->dev, "Error in set reg 0x%x\n", reg_en_reg);
			return ret;
		}
	}
	return tps65090_config_ext_control(ri, false);
}

__attribute__((used)) static inline struct tps65090_platform_data *tps65090_parse_dt_reg_data(
			struct platform_device *pdev,
			struct of_regulator_match **tps65090_reg_matches)
{
	*tps65090_reg_matches = NULL;
	return NULL;
}

__attribute__((used)) static int tps65090_regulator_probe(struct platform_device *pdev)
{
	struct tps65090 *tps65090_mfd = dev_get_drvdata(pdev->dev.parent);
	struct tps65090_regulator *ri = NULL;
	struct regulator_config config = { };
	struct regulator_dev *rdev;
	struct tps65090_regulator_plat_data *tps_pdata;
	struct tps65090_regulator *pmic;
	struct tps65090_platform_data *tps65090_pdata;
	struct of_regulator_match *tps65090_reg_matches = NULL;
	int num;
	int ret;

	dev_dbg(&pdev->dev, "Probing regulator\n");

	tps65090_pdata = dev_get_platdata(pdev->dev.parent);
	if (!tps65090_pdata && tps65090_mfd->dev->of_node)
		tps65090_pdata = tps65090_parse_dt_reg_data(pdev,
					&tps65090_reg_matches);
	if (IS_ERR_OR_NULL(tps65090_pdata)) {
		dev_err(&pdev->dev, "Platform data missing\n");
		return tps65090_pdata ? PTR_ERR(tps65090_pdata) : -EINVAL;
	}

	pmic = devm_kcalloc(&pdev->dev,
			    TPS65090_REGULATOR_MAX, sizeof(*pmic),
			    GFP_KERNEL);
	if (!pmic)
		return -ENOMEM;

	for (num = 0; num < TPS65090_REGULATOR_MAX; num++) {
		tps_pdata = tps65090_pdata->reg_pdata[num];

		ri = &pmic[num];
		ri->dev = &pdev->dev;
		ri->desc = &tps65090_regulator_desc[num];
		if (tps_pdata) {
			ri->overcurrent_wait_valid =
				tps_pdata->overcurrent_wait_valid;
			ri->overcurrent_wait = tps_pdata->overcurrent_wait;
		}

		/*
		 * TPS5090 DCDC support the control from external digital input.
		 * Configure it as per platform data.
		 */
		if (tps_pdata && is_dcdc(num) && tps_pdata->reg_init_data) {
			if (tps_pdata->enable_ext_control) {
				config.ena_gpiod = tps_pdata->gpiod;
				ri->desc->ops = &tps65090_ext_control_ops;
			} else {
				ret = tps65090_regulator_disable_ext_control(
						ri, tps_pdata);
				if (ret < 0) {
					dev_err(&pdev->dev,
						"failed disable ext control\n");
					return ret;
				}
			}
		}

		config.dev = pdev->dev.parent;
		config.driver_data = ri;
		config.regmap = tps65090_mfd->rmap;
		if (tps_pdata)
			config.init_data = tps_pdata->reg_init_data;
		else
			config.init_data = NULL;
		if (tps65090_reg_matches)
			config.of_node = tps65090_reg_matches[num].of_node;
		else
			config.of_node = NULL;

		rdev = devm_regulator_register(&pdev->dev, ri->desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "failed to register regulator %s\n",
				ri->desc->name);
			return PTR_ERR(rdev);
		}
		ri->rdev = rdev;

		if (ri->overcurrent_wait_valid) {
			ret = tps65090_reg_set_overcurrent_wait(ri, rdev);
			if (ret < 0)
				return ret;
		}

		/* Enable external control if it is require */
		if (tps_pdata && is_dcdc(num) && tps_pdata->reg_init_data &&
				tps_pdata->enable_ext_control) {
			ret = tps65090_config_ext_control(ri, true);
			if (ret < 0)
				return ret;
		}
	}

	platform_set_drvdata(pdev, pmic);
	return 0;
}

