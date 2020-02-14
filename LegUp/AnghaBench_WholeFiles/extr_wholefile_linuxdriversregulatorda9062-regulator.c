#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct regulator_dev {TYPE_1__* desc; } ;
struct regulator_config {int /*<<< orphan*/  regmap; struct da9062_regulator* driver_data; TYPE_3__* dev; } ;
struct regmap_field {int dummy; } ;
struct TYPE_13__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct da9062_regulators {int n_regulators; int irq_ldo_lim; struct da9062_regulator* regulator; } ;
struct TYPE_15__ {scalar_t__ reg; } ;
struct TYPE_14__ {int /*<<< orphan*/  name; int /*<<< orphan*/  owner; int /*<<< orphan*/  type; } ;
struct TYPE_12__ {scalar_t__ reg; int /*<<< orphan*/  lsb; } ;
typedef  struct da9062_regulator_info {int n_current_limits; int* current_limits; TYPE_7__ ilimit; TYPE_7__ suspend_sleep; TYPE_7__ sleep; TYPE_7__ suspend; TYPE_7__ mode; TYPE_5__ desc; TYPE_2__ oc_event; int /*<<< orphan*/  suspend_vsel_reg; } const da9062_regulator_info ;
struct da9062_regulator {int /*<<< orphan*/  rdev; TYPE_5__ desc; struct da9062_regulator_info const* info; struct regmap_field* ilimit; struct regmap_field* suspend_sleep; struct regmap_field* sleep; struct regmap_field* suspend; struct regmap_field* mode; struct da9062* hw; } ;
struct da9062 {int chip_type; int /*<<< orphan*/  regmap; TYPE_3__* dev; } ;
typedef  int irqreturn_t ;
typedef  int /*<<< orphan*/  config ;
struct TYPE_11__ {int /*<<< orphan*/  vsel_mask; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
#define  BUCK_MODE_AUTO 136 
#define  BUCK_MODE_MANUAL 135 
#define  BUCK_MODE_SLEEP 134 
#define  BUCK_MODE_SYNC 133 
#define  COMPAT_TYPE_DA9061 132 
#define  COMPAT_TYPE_DA9062 131 
 int DA9061_MAX_REGULATORS ; 
 scalar_t__ DA9062AA_STATUS_D ; 
 int DA9062_MAX_REGULATORS ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_LOW ; 
 int IRQ_HANDLED ; 
 int IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REGULATOR_EVENT_OVER_CURRENT ; 
#define  REGULATOR_MODE_FAST 130 
#define  REGULATOR_MODE_NORMAL 129 
#define  REGULATOR_MODE_STANDBY 128 
 int REGULATOR_STATUS_OFF ; 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 struct da9062* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*) ; 
 struct da9062_regulators* devm_kzalloc (TYPE_3__*,size_t,int /*<<< orphan*/ ) ; 
 void* devm_regmap_field_alloc (TYPE_3__*,int /*<<< orphan*/ ,TYPE_7__) ; 
 int /*<<< orphan*/  devm_regulator_register (TYPE_3__*,TYPE_5__*,struct regulator_config*) ; 
 int devm_request_threaded_irq (TYPE_3__*,int,int /*<<< orphan*/ *,int (*) (int,void*),int,char*,struct da9062_regulators*) ; 
 int ffs (int /*<<< orphan*/ ) ; 
 struct da9062_regulator_info const* local_da9061_regulator_info ; 
 struct da9062_regulator_info const* local_da9062_regulator_info ; 
 int /*<<< orphan*/  memset (struct regulator_config*,int /*<<< orphan*/ ,int) ; 
 int platform_get_irq_byname (struct platform_device*,char*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct da9062_regulators*) ; 
 struct da9062_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int regmap_field_read (struct regmap_field*,...) ; 
 int regmap_field_write (struct regmap_field*,unsigned int) ; 
 int regmap_read (int /*<<< orphan*/ ,scalar_t__,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int regulator_is_enabled_regmap (struct regulator_dev*) ; 
 int regulator_map_voltage_linear (struct regulator_dev*,int,int) ; 
 int regulator_mode_to_status (int) ; 
 int /*<<< orphan*/  regulator_notifier_call_chain (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int da9062_set_current_limit(struct regulator_dev *rdev,
				    int min_ua, int max_ua)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	const struct da9062_regulator_info *rinfo = regl->info;
	int n, tval;

	for (n = 0; n < rinfo->n_current_limits; n++) {
		tval = rinfo->current_limits[n];
		if (tval >= min_ua && tval <= max_ua)
			return regmap_field_write(regl->ilimit, n);
	}

	return -EINVAL;
}

__attribute__((used)) static int da9062_get_current_limit(struct regulator_dev *rdev)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	const struct da9062_regulator_info *rinfo = regl->info;
	unsigned int sel;
	int ret;

	ret = regmap_field_read(regl->ilimit, &sel);
	if (ret < 0)
		return ret;

	if (sel >= rinfo->n_current_limits)
		sel = rinfo->n_current_limits - 1;

	return rinfo->current_limits[sel];
}

__attribute__((used)) static int da9062_buck_set_mode(struct regulator_dev *rdev, unsigned mode)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	unsigned val;

	switch (mode) {
	case REGULATOR_MODE_FAST:
		val = BUCK_MODE_SYNC;
		break;
	case REGULATOR_MODE_NORMAL:
		val = BUCK_MODE_AUTO;
		break;
	case REGULATOR_MODE_STANDBY:
		val = BUCK_MODE_SLEEP;
		break;
	default:
		return -EINVAL;
	}

	return regmap_field_write(regl->mode, val);
}

__attribute__((used)) static unsigned da9062_buck_get_mode(struct regulator_dev *rdev)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	struct regmap_field *field;
	unsigned int val, mode = 0;
	int ret;

	ret = regmap_field_read(regl->mode, &val);
	if (ret < 0)
		return ret;

	switch (val) {
	default:
	case BUCK_MODE_MANUAL:
		mode = REGULATOR_MODE_FAST | REGULATOR_MODE_STANDBY;
		/* Sleep flag bit decides the mode */
		break;
	case BUCK_MODE_SLEEP:
		return REGULATOR_MODE_STANDBY;
	case BUCK_MODE_SYNC:
		return REGULATOR_MODE_FAST;
	case BUCK_MODE_AUTO:
		return REGULATOR_MODE_NORMAL;
	}

	/* Detect current regulator state */
	ret = regmap_field_read(regl->suspend, &val);
	if (ret < 0)
		return 0;

	/* Read regulator mode from proper register, depending on state */
	if (val)
		field = regl->suspend_sleep;
	else
		field = regl->sleep;

	ret = regmap_field_read(field, &val);
	if (ret < 0)
		return 0;

	if (val)
		mode &= REGULATOR_MODE_STANDBY;
	else
		mode &= REGULATOR_MODE_NORMAL | REGULATOR_MODE_FAST;

	return mode;
}

__attribute__((used)) static int da9062_ldo_set_mode(struct regulator_dev *rdev, unsigned mode)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	unsigned val;

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		val = 0;
		break;
	case REGULATOR_MODE_STANDBY:
		val = 1;
		break;
	default:
		return -EINVAL;
	}

	return regmap_field_write(regl->sleep, val);
}

__attribute__((used)) static unsigned da9062_ldo_get_mode(struct regulator_dev *rdev)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	struct regmap_field *field;
	int ret, val;

	/* Detect current regulator state */
	ret = regmap_field_read(regl->suspend, &val);
	if (ret < 0)
		return 0;

	/* Read regulator mode from proper register, depending on state */
	if (val)
		field = regl->suspend_sleep;
	else
		field = regl->sleep;

	ret = regmap_field_read(field, &val);
	if (ret < 0)
		return 0;

	if (val)
		return REGULATOR_MODE_STANDBY;
	else
		return REGULATOR_MODE_NORMAL;
}

__attribute__((used)) static int da9062_buck_get_status(struct regulator_dev *rdev)
{
	int ret = regulator_is_enabled_regmap(rdev);

	if (ret == 0) {
		ret = REGULATOR_STATUS_OFF;
	} else if (ret > 0) {
		ret = da9062_buck_get_mode(rdev);
		if (ret > 0)
			ret = regulator_mode_to_status(ret);
		else if (ret == 0)
			ret = -EIO;
	}

	return ret;
}

__attribute__((used)) static int da9062_ldo_get_status(struct regulator_dev *rdev)
{
	int ret = regulator_is_enabled_regmap(rdev);

	if (ret == 0) {
		ret = REGULATOR_STATUS_OFF;
	} else if (ret > 0) {
		ret = da9062_ldo_get_mode(rdev);
		if (ret > 0)
			ret = regulator_mode_to_status(ret);
		else if (ret == 0)
			ret = -EIO;
	}

	return ret;
}

__attribute__((used)) static int da9062_set_suspend_voltage(struct regulator_dev *rdev, int uv)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	const struct da9062_regulator_info *rinfo = regl->info;
	int ret, sel;

	sel = regulator_map_voltage_linear(rdev, uv, uv);
	if (sel < 0)
		return sel;

	sel <<= ffs(rdev->desc->vsel_mask) - 1;

	ret = regmap_update_bits(regl->hw->regmap, rinfo->suspend_vsel_reg,
				 rdev->desc->vsel_mask, sel);

	return ret;
}

__attribute__((used)) static int da9062_suspend_enable(struct regulator_dev *rdev)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);

	return regmap_field_write(regl->suspend, 1);
}

__attribute__((used)) static int da9062_suspend_disable(struct regulator_dev *rdev)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);

	return regmap_field_write(regl->suspend, 0);
}

__attribute__((used)) static int da9062_buck_set_suspend_mode(struct regulator_dev *rdev,
					unsigned mode)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	int val;

	switch (mode) {
	case REGULATOR_MODE_FAST:
		val = BUCK_MODE_SYNC;
		break;
	case REGULATOR_MODE_NORMAL:
		val = BUCK_MODE_AUTO;
		break;
	case REGULATOR_MODE_STANDBY:
		val = BUCK_MODE_SLEEP;
		break;
	default:
		return -EINVAL;
	}

	return regmap_field_write(regl->mode, val);
}

__attribute__((used)) static int da9062_ldo_set_suspend_mode(struct regulator_dev *rdev,
						unsigned mode)
{
	struct da9062_regulator *regl = rdev_get_drvdata(rdev);
	unsigned val;

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		val = 0;
		break;
	case REGULATOR_MODE_STANDBY:
		val = 1;
		break;
	default:
		return -EINVAL;
	}

	return regmap_field_write(regl->suspend_sleep, val);
}

__attribute__((used)) static irqreturn_t da9062_ldo_lim_event(int irq, void *data)
{
	struct da9062_regulators *regulators = data;
	struct da9062 *hw = regulators->regulator[0].hw;
	struct da9062_regulator *regl;
	int handled = IRQ_NONE;
	int bits, i, ret;

	ret = regmap_read(hw->regmap, DA9062AA_STATUS_D, &bits);
	if (ret < 0) {
		dev_err(hw->dev,
			"Failed to read LDO overcurrent indicator\n");
		goto ldo_lim_error;
	}

	for (i = regulators->n_regulators - 1; i >= 0; i--) {
		regl = &regulators->regulator[i];
		if (regl->info->oc_event.reg != DA9062AA_STATUS_D)
			continue;

		if (BIT(regl->info->oc_event.lsb) & bits) {
			regulator_notifier_call_chain(regl->rdev,
					REGULATOR_EVENT_OVER_CURRENT, NULL);
			handled = IRQ_HANDLED;
		}
	}

ldo_lim_error:
	return handled;
}

__attribute__((used)) static int da9062_regulator_probe(struct platform_device *pdev)
{
	struct da9062 *chip = dev_get_drvdata(pdev->dev.parent);
	struct da9062_regulators *regulators;
	struct da9062_regulator *regl;
	struct regulator_config config = { };
	const struct da9062_regulator_info *rinfo;
	int irq, n, ret;
	size_t size;
	int max_regulators;

	switch (chip->chip_type) {
	case COMPAT_TYPE_DA9061:
		max_regulators = DA9061_MAX_REGULATORS;
		rinfo = local_da9061_regulator_info;
		break;
	case COMPAT_TYPE_DA9062:
		max_regulators = DA9062_MAX_REGULATORS;
		rinfo = local_da9062_regulator_info;
		break;
	default:
		dev_err(chip->dev, "Unrecognised chip type\n");
		return -ENODEV;
	}

	/* Allocate memory required by usable regulators */
	size = sizeof(struct da9062_regulators) +
		max_regulators * sizeof(struct da9062_regulator);
	regulators = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
	if (!regulators)
		return -ENOMEM;

	regulators->n_regulators = max_regulators;
	platform_set_drvdata(pdev, regulators);

	n = 0;
	while (n < regulators->n_regulators) {
		/* Initialise regulator structure */
		regl = &regulators->regulator[n];
		regl->hw = chip;
		regl->info = &rinfo[n];
		regl->desc = regl->info->desc;
		regl->desc.type = REGULATOR_VOLTAGE;
		regl->desc.owner = THIS_MODULE;

		if (regl->info->mode.reg)
			regl->mode = devm_regmap_field_alloc(
					&pdev->dev,
					chip->regmap,
					regl->info->mode);
		if (regl->info->suspend.reg)
			regl->suspend = devm_regmap_field_alloc(
					&pdev->dev,
					chip->regmap,
					regl->info->suspend);
		if (regl->info->sleep.reg)
			regl->sleep = devm_regmap_field_alloc(
					&pdev->dev,
					chip->regmap,
					regl->info->sleep);
		if (regl->info->suspend_sleep.reg)
			regl->suspend_sleep = devm_regmap_field_alloc(
					&pdev->dev,
					chip->regmap,
					regl->info->suspend_sleep);
		if (regl->info->ilimit.reg)
			regl->ilimit = devm_regmap_field_alloc(
					&pdev->dev,
					chip->regmap,
					regl->info->ilimit);

		/* Register regulator */
		memset(&config, 0, sizeof(config));
		config.dev = chip->dev;
		config.driver_data = regl;
		config.regmap = chip->regmap;

		regl->rdev = devm_regulator_register(&pdev->dev, &regl->desc,
						     &config);
		if (IS_ERR(regl->rdev)) {
			dev_err(&pdev->dev,
				"Failed to register %s regulator\n",
				regl->desc.name);
			return PTR_ERR(regl->rdev);
		}

		n++;
	}

	/* LDOs overcurrent event support */
	irq = platform_get_irq_byname(pdev, "LDO_LIM");
	if (irq < 0) {
		dev_err(&pdev->dev, "Failed to get IRQ.\n");
		return irq;
	}
	regulators->irq_ldo_lim = irq;

	ret = devm_request_threaded_irq(&pdev->dev, irq,
					NULL, da9062_ldo_lim_event,
					IRQF_TRIGGER_LOW | IRQF_ONESHOT,
					"LDO_LIM", regulators);
	if (ret) {
		dev_warn(&pdev->dev,
			 "Failed to request LDO_LIM IRQ.\n");
		regulators->irq_ldo_lim = -ENXIO;
	}

	return 0;
}

