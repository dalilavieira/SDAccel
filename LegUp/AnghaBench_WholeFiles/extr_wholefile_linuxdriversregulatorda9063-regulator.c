#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct regulator_init_data {int dummy; } ;
struct regulator_dev {TYPE_1__* desc; } ;
struct regulator_config {int /*<<< orphan*/  regmap; int /*<<< orphan*/  of_node; struct da9063_regulator* driver_data; struct regulator_init_data const* init_data; TYPE_4__* dev; } ;
struct regmap_field {int dummy; } ;
struct TYPE_14__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_4__ dev; } ;
struct of_regulator_match {int /*<<< orphan*/  of_node; } ;
struct da9063_regulators_pdata {int n_regulators; TYPE_3__* regulator_data; } ;
struct da9063_regulators {int n_regulators; struct da9063_regulator* regulator; } ;
struct TYPE_16__ {scalar_t__ reg; } ;
struct TYPE_15__ {int /*<<< orphan*/  name; int /*<<< orphan*/  owner; int /*<<< orphan*/  type; } ;
struct TYPE_12__ {scalar_t__ reg; int /*<<< orphan*/  lsb; } ;
struct da9063_regulator_info {int n_current_limits; int* current_limits; TYPE_8__ ilimit; TYPE_8__ suspend_sleep; TYPE_8__ sleep; TYPE_8__ suspend; TYPE_8__ mode; TYPE_6__ desc; TYPE_2__ oc_event; int /*<<< orphan*/  suspend_vsel_reg; } ;
struct da9063_regulator {struct da9063_regulators_pdata* rdev; TYPE_6__ desc; struct da9063_regulator_info* info; struct regmap_field* ilimit; struct regmap_field* suspend_sleep; struct regmap_field* sleep; struct regmap_field* suspend; struct regmap_field* mode; struct da9063* hw; } ;
struct da9063_pdata {struct da9063_regulators_pdata* regulators_pdata; } ;
struct da9063_dev_model {scalar_t__ type; int n_regulators; struct da9063_regulator_info* regulator_info; } ;
struct da9063 {scalar_t__ type; int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  config ;
struct TYPE_13__ {int id; struct regulator_init_data const* initdata; } ;
struct TYPE_11__ {int /*<<< orphan*/  vsel_mask; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
#define  BUCK_MODE_AUTO 140 
#define  BUCK_MODE_MANUAL 139 
#define  BUCK_MODE_SLEEP 138 
#define  BUCK_MODE_SYNC 137 
 int DA9063_BCORE_MERGE ; 
 int DA9063_BUCK_MERGE ; 
#define  DA9063_ID_BCORE1 136 
#define  DA9063_ID_BCORE2 135 
#define  DA9063_ID_BCORES_MERGED 134 
#define  DA9063_ID_BIO 133 
#define  DA9063_ID_BMEM 132 
#define  DA9063_ID_BMEM_BIO_MERGED 131 
 scalar_t__ DA9063_REG_CONFIG_H ; 
 scalar_t__ DA9063_REG_STATUS_D ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct da9063_regulators_pdata* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (struct da9063_regulators_pdata*) ; 
 int PTR_ERR (struct da9063_regulators_pdata*) ; 
 int /*<<< orphan*/  REGULATOR_EVENT_OVER_CURRENT ; 
#define  REGULATOR_MODE_FAST 130 
#define  REGULATOR_MODE_NORMAL 129 
#define  REGULATOR_MODE_STANDBY 128 
 int REGULATOR_STATUS_OFF ; 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,...) ; 
 struct da9063* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct da9063_pdata* dev_get_platdata (int /*<<< orphan*/ ) ; 
 struct da9063_regulators* devm_kzalloc (TYPE_4__*,size_t,int /*<<< orphan*/ ) ; 
 void* devm_regmap_field_alloc (TYPE_4__*,int /*<<< orphan*/ ,TYPE_8__) ; 
 struct da9063_regulators_pdata* devm_regulator_register (TYPE_4__*,TYPE_6__*,struct regulator_config*) ; 
 int devm_request_threaded_irq (TYPE_4__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char*,struct da9063_regulators*) ; 
 int ffs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct regulator_config*,int /*<<< orphan*/ ,int) ; 
 int platform_get_irq_byname (struct platform_device*,char*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct da9063_regulators*) ; 
 struct da9063_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int regmap_field_read (struct regmap_field*,...) ; 
 int regmap_field_write (struct regmap_field*,unsigned int) ; 
 int regmap_read (int /*<<< orphan*/ ,scalar_t__,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int regulator_is_enabled_regmap (struct regulator_dev*) ; 
 int regulator_map_voltage_linear (struct regulator_dev*,int,int) ; 
 int regulator_mode_to_status (int) ; 
 int /*<<< orphan*/  regulator_notifier_call_chain (struct da9063_regulators_pdata*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct da9063_dev_model* regulators_models ; 

__attribute__((used)) static int da9063_set_current_limit(struct regulator_dev *rdev,
							int min_uA, int max_uA)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
	const struct da9063_regulator_info *rinfo = regl->info;
	int n, tval;

	for (n = 0; n < rinfo->n_current_limits; n++) {
		tval = rinfo->current_limits[n];
		if (tval >= min_uA && tval <= max_uA)
			return regmap_field_write(regl->ilimit, n);
	}

	return -EINVAL;
}

__attribute__((used)) static int da9063_get_current_limit(struct regulator_dev *rdev)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
	const struct da9063_regulator_info *rinfo = regl->info;
	unsigned int sel;
	int ret;

	ret = regmap_field_read(regl->ilimit, &sel);
	if (ret < 0)
		return ret;

	if (sel >= rinfo->n_current_limits)
		sel = rinfo->n_current_limits - 1;

	return rinfo->current_limits[sel];
}

__attribute__((used)) static int da9063_buck_set_mode(struct regulator_dev *rdev, unsigned mode)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
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

__attribute__((used)) static unsigned da9063_buck_get_mode(struct regulator_dev *rdev)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
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

__attribute__((used)) static int da9063_ldo_set_mode(struct regulator_dev *rdev, unsigned mode)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
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

__attribute__((used)) static unsigned da9063_ldo_get_mode(struct regulator_dev *rdev)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
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

__attribute__((used)) static int da9063_buck_get_status(struct regulator_dev *rdev)
{
	int ret = regulator_is_enabled_regmap(rdev);

	if (ret == 0) {
		ret = REGULATOR_STATUS_OFF;
	} else if (ret > 0) {
		ret = da9063_buck_get_mode(rdev);
		if (ret > 0)
			ret = regulator_mode_to_status(ret);
		else if (ret == 0)
			ret = -EIO;
	}

	return ret;
}

__attribute__((used)) static int da9063_ldo_get_status(struct regulator_dev *rdev)
{
	int ret = regulator_is_enabled_regmap(rdev);

	if (ret == 0) {
		ret = REGULATOR_STATUS_OFF;
	} else if (ret > 0) {
		ret = da9063_ldo_get_mode(rdev);
		if (ret > 0)
			ret = regulator_mode_to_status(ret);
		else if (ret == 0)
			ret = -EIO;
	}

	return ret;
}

__attribute__((used)) static int da9063_set_suspend_voltage(struct regulator_dev *rdev, int uV)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
	const struct da9063_regulator_info *rinfo = regl->info;
	int ret, sel;

	sel = regulator_map_voltage_linear(rdev, uV, uV);
	if (sel < 0)
		return sel;

	sel <<= ffs(rdev->desc->vsel_mask) - 1;

	ret = regmap_update_bits(regl->hw->regmap, rinfo->suspend_vsel_reg,
				 rdev->desc->vsel_mask, sel);

	return ret;
}

__attribute__((used)) static int da9063_suspend_enable(struct regulator_dev *rdev)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);

	return regmap_field_write(regl->suspend, 1);
}

__attribute__((used)) static int da9063_suspend_disable(struct regulator_dev *rdev)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);

	return regmap_field_write(regl->suspend, 0);
}

__attribute__((used)) static int da9063_buck_set_suspend_mode(struct regulator_dev *rdev, unsigned mode)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
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

__attribute__((used)) static int da9063_ldo_set_suspend_mode(struct regulator_dev *rdev, unsigned mode)
{
	struct da9063_regulator *regl = rdev_get_drvdata(rdev);
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

__attribute__((used)) static irqreturn_t da9063_ldo_lim_event(int irq, void *data)
{
	struct da9063_regulators *regulators = data;
	struct da9063 *hw = regulators->regulator[0].hw;
	struct da9063_regulator *regl;
	int bits, i , ret;

	ret = regmap_read(hw->regmap, DA9063_REG_STATUS_D, &bits);
	if (ret < 0)
		return IRQ_NONE;

	for (i = regulators->n_regulators - 1; i >= 0; i--) {
		regl = &regulators->regulator[i];
		if (regl->info->oc_event.reg != DA9063_REG_STATUS_D)
			continue;

		if (BIT(regl->info->oc_event.lsb) & bits)
			regulator_notifier_call_chain(regl->rdev,
					REGULATOR_EVENT_OVER_CURRENT, NULL);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static const struct regulator_init_data *da9063_get_regulator_initdata(
		const struct da9063_regulators_pdata *regl_pdata, int id)
{
	int i;

	for (i = 0; i < regl_pdata->n_regulators; i++) {
		if (id == regl_pdata->regulator_data[i].id)
			return regl_pdata->regulator_data[i].initdata;
	}

	return NULL;
}

__attribute__((used)) static struct da9063_regulators_pdata *da9063_parse_regulators_dt(
		struct platform_device *pdev,
		struct of_regulator_match **da9063_reg_matches)
{
	*da9063_reg_matches = NULL;
	return ERR_PTR(-ENODEV);
}

__attribute__((used)) static int da9063_regulator_probe(struct platform_device *pdev)
{
	struct da9063 *da9063 = dev_get_drvdata(pdev->dev.parent);
	struct da9063_pdata *da9063_pdata = dev_get_platdata(da9063->dev);
	struct of_regulator_match *da9063_reg_matches = NULL;
	struct da9063_regulators_pdata *regl_pdata;
	const struct da9063_dev_model *model;
	struct da9063_regulators *regulators;
	struct da9063_regulator *regl;
	struct regulator_config config;
	bool bcores_merged, bmem_bio_merged;
	int id, irq, n, n_regulators, ret, val;
	size_t size;

	regl_pdata = da9063_pdata ? da9063_pdata->regulators_pdata : NULL;

	if (!regl_pdata)
		regl_pdata = da9063_parse_regulators_dt(pdev,
							&da9063_reg_matches);

	if (IS_ERR(regl_pdata) || regl_pdata->n_regulators == 0) {
		dev_err(&pdev->dev,
			"No regulators defined for the platform\n");
		return -ENODEV;
	}

	/* Find regulators set for particular device model */
	for (model = regulators_models; model->regulator_info; model++) {
		if (model->type == da9063->type)
			break;
	}
	if (!model->regulator_info) {
		dev_err(&pdev->dev, "Chip model not recognised (%u)\n",
			da9063->type);
		return -ENODEV;
	}

	ret = regmap_read(da9063->regmap, DA9063_REG_CONFIG_H, &val);
	if (ret < 0) {
		dev_err(&pdev->dev,
			"Error while reading BUCKs configuration\n");
		return ret;
	}
	bcores_merged = val & DA9063_BCORE_MERGE;
	bmem_bio_merged = val & DA9063_BUCK_MERGE;

	n_regulators = model->n_regulators;
	if (bcores_merged)
		n_regulators -= 2; /* remove BCORE1, BCORE2 */
	else
		n_regulators--;    /* remove BCORES_MERGED */
	if (bmem_bio_merged)
		n_regulators -= 2; /* remove BMEM, BIO */
	else
		n_regulators--;    /* remove BMEM_BIO_MERGED */

	/* Allocate memory required by usable regulators */
	size = sizeof(struct da9063_regulators) +
		n_regulators * sizeof(struct da9063_regulator);
	regulators = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
	if (!regulators)
		return -ENOMEM;

	regulators->n_regulators = n_regulators;
	platform_set_drvdata(pdev, regulators);

	/* Register all regulators declared in platform information */
	n = 0;
	id = 0;
	while (n < regulators->n_regulators) {
		/* Skip regulator IDs depending on merge mode configuration */
		switch (id) {
		case DA9063_ID_BCORE1:
		case DA9063_ID_BCORE2:
			if (bcores_merged) {
				id++;
				continue;
			}
			break;
		case DA9063_ID_BMEM:
		case DA9063_ID_BIO:
			if (bmem_bio_merged) {
				id++;
				continue;
			}
			break;
		case DA9063_ID_BCORES_MERGED:
			if (!bcores_merged) {
				id++;
				continue;
			}
			break;
		case DA9063_ID_BMEM_BIO_MERGED:
			if (!bmem_bio_merged) {
				id++;
				continue;
			}
			break;
		}

		/* Initialise regulator structure */
		regl = &regulators->regulator[n];
		regl->hw = da9063;
		regl->info = &model->regulator_info[id];
		regl->desc = regl->info->desc;
		regl->desc.type = REGULATOR_VOLTAGE;
		regl->desc.owner = THIS_MODULE;

		if (regl->info->mode.reg)
			regl->mode = devm_regmap_field_alloc(&pdev->dev,
					da9063->regmap, regl->info->mode);
		if (regl->info->suspend.reg)
			regl->suspend = devm_regmap_field_alloc(&pdev->dev,
					da9063->regmap, regl->info->suspend);
		if (regl->info->sleep.reg)
			regl->sleep = devm_regmap_field_alloc(&pdev->dev,
					da9063->regmap, regl->info->sleep);
		if (regl->info->suspend_sleep.reg)
			regl->suspend_sleep = devm_regmap_field_alloc(&pdev->dev,
					da9063->regmap, regl->info->suspend_sleep);
		if (regl->info->ilimit.reg)
			regl->ilimit = devm_regmap_field_alloc(&pdev->dev,
					da9063->regmap, regl->info->ilimit);

		/* Register regulator */
		memset(&config, 0, sizeof(config));
		config.dev = &pdev->dev;
		config.init_data = da9063_get_regulator_initdata(regl_pdata, id);
		config.driver_data = regl;
		if (da9063_reg_matches)
			config.of_node = da9063_reg_matches[id].of_node;
		config.regmap = da9063->regmap;
		regl->rdev = devm_regulator_register(&pdev->dev, &regl->desc,
						     &config);
		if (IS_ERR(regl->rdev)) {
			dev_err(&pdev->dev,
				"Failed to register %s regulator\n",
				regl->desc.name);
			return PTR_ERR(regl->rdev);
		}
		id++;
		n++;
	}

	/* LDOs overcurrent event support */
	irq = platform_get_irq_byname(pdev, "LDO_LIM");
	if (irq < 0) {
		dev_err(&pdev->dev, "Failed to get IRQ.\n");
		return irq;
	}

	ret = devm_request_threaded_irq(&pdev->dev, irq,
				NULL, da9063_ldo_lim_event,
				IRQF_TRIGGER_LOW | IRQF_ONESHOT,
				"LDO_LIM", regulators);
	if (ret) {
		dev_err(&pdev->dev, "Failed to request LDO_LIM IRQ.\n");
		return ret;
	}

	return 0;
}

