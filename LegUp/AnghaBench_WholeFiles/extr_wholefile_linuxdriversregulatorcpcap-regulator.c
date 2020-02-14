#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct regulator_init_data {void* driver_data; struct regulator_init_data* init_data; scalar_t__ regmap; TYPE_2__* dev; } ;
struct regulator_dev {TYPE_1__* desc; int /*<<< orphan*/  regmap; } ;
struct regulator_config {void* driver_data; struct regulator_config* init_data; scalar_t__ regmap; TYPE_2__* dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct of_device_id {struct cpcap_regulator* data; } ;
struct TYPE_9__ {scalar_t__ volt_table; int /*<<< orphan*/  name; } ;
struct cpcap_regulator {int const assign_mask; TYPE_4__ rdesc; int /*<<< orphan*/  assign_reg; } ;
struct cpcap_ddata {struct cpcap_regulator* soc; scalar_t__ reg; TYPE_2__* dev; } ;
typedef  int /*<<< orphan*/  init_data ;
typedef  int /*<<< orphan*/  config ;
struct TYPE_7__ {int enable_val; int /*<<< orphan*/  enable_reg; } ;

/* Variables and functions */
#define  CPCAP_BIT_AUDIO_LOW_PWR 131 
#define  CPCAP_BIT_AUDIO_NORMAL_MODE 130 
 int CPCAP_NR_REGULATORS ; 
 int CPCAP_REG_OFF_MODE_SEC ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 unsigned int REGULATOR_MODE_INVALID ; 
#define  REGULATOR_MODE_NORMAL 129 
#define  REGULATOR_MODE_STANDBY 128 
 int /*<<< orphan*/  cpcap_regulator_id_table ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 scalar_t__ dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct cpcap_ddata* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_2__*,TYPE_4__*,struct regulator_init_data*) ; 
 int /*<<< orphan*/  memset (struct regulator_init_data*,int /*<<< orphan*/ ,int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  of_match_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct cpcap_ddata*) ; 
 struct cpcap_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const,int) ; 
 int regulator_disable_regmap (struct regulator_dev*) ; 
 int regulator_enable_regmap (struct regulator_dev*) ; 
 scalar_t__ unknown_val_tbl ; 

__attribute__((used)) static int cpcap_regulator_enable(struct regulator_dev *rdev)
{
	struct cpcap_regulator *regulator = rdev_get_drvdata(rdev);
	int error, ignore;

	error = regulator_enable_regmap(rdev);
	if (error)
		return error;

	if (rdev->desc->enable_val & CPCAP_REG_OFF_MODE_SEC) {
		error = regmap_update_bits(rdev->regmap, regulator->assign_reg,
					   regulator->assign_mask,
					   regulator->assign_mask);
		if (error)
			ignore = regulator_disable_regmap(rdev);
	}

	return error;
}

__attribute__((used)) static int cpcap_regulator_disable(struct regulator_dev *rdev)
{
	struct cpcap_regulator *regulator = rdev_get_drvdata(rdev);
	int error, ignore;

	if (rdev->desc->enable_val & CPCAP_REG_OFF_MODE_SEC) {
		error = regmap_update_bits(rdev->regmap, regulator->assign_reg,
					   regulator->assign_mask, 0);
		if (error)
			return error;
	}

	error = regulator_disable_regmap(rdev);
	if (error && (rdev->desc->enable_val & CPCAP_REG_OFF_MODE_SEC)) {
		ignore = regmap_update_bits(rdev->regmap, regulator->assign_reg,
					    regulator->assign_mask,
					    regulator->assign_mask);
	}

	return error;
}

__attribute__((used)) static unsigned int cpcap_map_mode(unsigned int mode)
{
	switch (mode) {
	case CPCAP_BIT_AUDIO_NORMAL_MODE:
		return REGULATOR_MODE_NORMAL;
	case CPCAP_BIT_AUDIO_LOW_PWR:
		return REGULATOR_MODE_STANDBY;
	default:
		return REGULATOR_MODE_INVALID;
	}
}

__attribute__((used)) static unsigned int cpcap_regulator_get_mode(struct regulator_dev *rdev)
{
	int value;

	regmap_read(rdev->regmap, rdev->desc->enable_reg, &value);

	if (value & CPCAP_BIT_AUDIO_LOW_PWR)
		return REGULATOR_MODE_STANDBY;

	return REGULATOR_MODE_NORMAL;
}

__attribute__((used)) static int cpcap_regulator_set_mode(struct regulator_dev *rdev,
				    unsigned int mode)
{
	int value;

	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		value = CPCAP_BIT_AUDIO_NORMAL_MODE;
		break;
	case REGULATOR_MODE_STANDBY:
		value = CPCAP_BIT_AUDIO_LOW_PWR;
		break;
	default:
		return -EINVAL;
	}

	return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
				  CPCAP_BIT_AUDIO_LOW_PWR, value);
}

__attribute__((used)) static int cpcap_regulator_probe(struct platform_device *pdev)
{
	struct cpcap_ddata *ddata;
	const struct of_device_id *match;
	struct regulator_config config;
	struct regulator_init_data init_data;
	int i;

	match = of_match_device(of_match_ptr(cpcap_regulator_id_table),
				&pdev->dev);
	if (!match)
		return -EINVAL;

	if (!match->data) {
		dev_err(&pdev->dev, "no configuration data found\n");

		return -ENODEV;
	}

	ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
	if (!ddata)
		return -ENOMEM;

	ddata->reg = dev_get_regmap(pdev->dev.parent, NULL);
	if (!ddata->reg)
		return -ENODEV;

	ddata->dev = &pdev->dev;
	ddata->soc = match->data;
	platform_set_drvdata(pdev, ddata);

	memset(&config, 0, sizeof(config));
	memset(&init_data, 0, sizeof(init_data));
	config.dev = &pdev->dev;
	config.regmap = ddata->reg;
	config.init_data = &init_data;

	for (i = 0; i < CPCAP_NR_REGULATORS; i++) {
		const struct cpcap_regulator *regulator = &ddata->soc[i];
		struct regulator_dev *rdev;

		if (!regulator->rdesc.name)
			break;

		if (regulator->rdesc.volt_table == unknown_val_tbl)
			continue;

		config.driver_data = (void *)regulator;
		rdev = devm_regulator_register(&pdev->dev,
					       &regulator->rdesc,
					       &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "failed to register regulator %s\n",
				regulator->rdesc.name);

			return PTR_ERR(rdev);
		}
	}

	return 0;
}

