#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct regulator_init_data {int num_consumer_supplies; TYPE_3__* consumer_supplies; } ;
struct regulator_dev {TYPE_2__* desc; } ;
struct regulator_desc {int dummy; } ;
struct regulator_config {scalar_t__ ena_gpiod; struct device_node* of_node; struct regulator_init_data* init_data; struct regmap* regmap; struct arizona_ldo1* driver_data; struct device* dev; } ;
struct regmap {int dummy; } ;
struct TYPE_10__ {struct device* parent; } ;
struct platform_device {TYPE_4__ dev; } ;
struct device_node {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct arizona_ldo1_pdata {struct regulator_init_data* init_data; } ;
struct TYPE_9__ {char* supply; int /*<<< orphan*/  dev_name; } ;
struct arizona_ldo1 {scalar_t__ ena_gpiod; struct regulator_init_data init_data; struct regmap* regmap; scalar_t__ regulator; TYPE_3__ supply; } ;
struct TYPE_7__ {struct arizona_ldo1_pdata ldo1; } ;
struct arizona {int type; int /*<<< orphan*/  external_dcvdd; TYPE_1__ pdata; struct regmap* regmap; } ;
struct TYPE_8__ {unsigned int n_voltages; int min_uV; unsigned int uV_step; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARIZONA_LDO1_CONTROL_1 ; 
 int /*<<< orphan*/  ARIZONA_LDO1_CONTROL_2 ; 
 unsigned int ARIZONA_LDO1_HI_PWR ; 
 unsigned int ARIZONA_LDO1_VSEL_MASK ; 
 unsigned int ARIZONA_LDO1_VSEL_SHIFT ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int DIV_ROUND_UP (int,unsigned int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
#define  WM1814 133 
#define  WM5102 132 
#define  WM5110 131 
#define  WM8280 130 
#define  WM8997 129 
#define  WM8998 128 
 struct regulator_desc arizona_ldo1 ; 
 struct regulator_init_data arizona_ldo1_default ; 
 struct regulator_init_data arizona_ldo1_dvfs ; 
 struct regulator_desc arizona_ldo1_hc ; 
 struct regulator_init_data arizona_ldo1_wm5110 ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,int) ; 
 struct arizona* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct arizona_ldo1* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ devm_regulator_register (TYPE_4__*,struct regulator_desc const*,struct regulator_config*) ; 
 scalar_t__ gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_put (scalar_t__) ; 
 struct device_node* of_get_child_by_name (struct device_node*,char*) ; 
 struct regulator_init_data* of_get_regulator_init_data (struct device*,struct device_node*,struct regulator_desc const*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 struct arizona_ldo1* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct arizona_ldo1*) ; 
 struct arizona_ldo1* rdev_get_drvdata (struct regulator_dev*) ; 
 int regmap_read (struct regmap*,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 

__attribute__((used)) static int arizona_ldo1_hc_list_voltage(struct regulator_dev *rdev,
					unsigned int selector)
{
	if (selector >= rdev->desc->n_voltages)
		return -EINVAL;

	if (selector == rdev->desc->n_voltages - 1)
		return 1800000;
	else
		return rdev->desc->min_uV + (rdev->desc->uV_step * selector);
}

__attribute__((used)) static int arizona_ldo1_hc_map_voltage(struct regulator_dev *rdev,
				       int min_uV, int max_uV)
{
	int sel;

	sel = DIV_ROUND_UP(min_uV - rdev->desc->min_uV, rdev->desc->uV_step);
	if (sel >= rdev->desc->n_voltages)
		sel = rdev->desc->n_voltages - 1;

	return sel;
}

__attribute__((used)) static int arizona_ldo1_hc_set_voltage_sel(struct regulator_dev *rdev,
					   unsigned sel)
{
	struct arizona_ldo1 *ldo = rdev_get_drvdata(rdev);
	struct regmap *regmap = ldo->regmap;
	unsigned int val;
	int ret;

	if (sel == rdev->desc->n_voltages - 1)
		val = ARIZONA_LDO1_HI_PWR;
	else
		val = 0;

	ret = regmap_update_bits(regmap, ARIZONA_LDO1_CONTROL_2,
				 ARIZONA_LDO1_HI_PWR, val);
	if (ret != 0)
		return ret;

	if (val)
		return 0;

	val = sel << ARIZONA_LDO1_VSEL_SHIFT;

	return regmap_update_bits(regmap, ARIZONA_LDO1_CONTROL_1,
				  ARIZONA_LDO1_VSEL_MASK, val);
}

__attribute__((used)) static int arizona_ldo1_hc_get_voltage_sel(struct regulator_dev *rdev)
{
	struct arizona_ldo1 *ldo = rdev_get_drvdata(rdev);
	struct regmap *regmap = ldo->regmap;
	unsigned int val;
	int ret;

	ret = regmap_read(regmap, ARIZONA_LDO1_CONTROL_2, &val);
	if (ret != 0)
		return ret;

	if (val & ARIZONA_LDO1_HI_PWR)
		return rdev->desc->n_voltages - 1;

	ret = regmap_read(regmap, ARIZONA_LDO1_CONTROL_1, &val);
	if (ret != 0)
		return ret;

	return (val & ARIZONA_LDO1_VSEL_MASK) >> ARIZONA_LDO1_VSEL_SHIFT;
}

__attribute__((used)) static int arizona_ldo1_of_get_pdata(struct arizona_ldo1_pdata *pdata,
				     struct regulator_config *config,
				     const struct regulator_desc *desc,
				     bool *external_dcvdd)
{
	struct arizona_ldo1 *ldo1 = config->driver_data;
	struct device_node *np = config->dev->of_node;
	struct device_node *init_node, *dcvdd_node;
	struct regulator_init_data *init_data;

	init_node = of_get_child_by_name(np, "ldo1");
	dcvdd_node = of_parse_phandle(np, "DCVDD-supply", 0);

	if (init_node) {
		config->of_node = init_node;

		init_data = of_get_regulator_init_data(config->dev, init_node,
						       desc);
		if (init_data) {
			init_data->consumer_supplies = &ldo1->supply;
			init_data->num_consumer_supplies = 1;

			if (dcvdd_node && dcvdd_node != init_node)
				*external_dcvdd = true;

			pdata->init_data = init_data;
		}
	} else if (dcvdd_node) {
		*external_dcvdd = true;
	}

	of_node_put(dcvdd_node);

	return 0;
}

__attribute__((used)) static int arizona_ldo1_common_init(struct platform_device *pdev,
				    struct arizona_ldo1 *ldo1,
				    const struct regulator_desc *desc,
				    struct arizona_ldo1_pdata *pdata,
				    bool *external_dcvdd)
{
	struct device *parent_dev = pdev->dev.parent;
	struct regulator_config config = { };
	int ret;

	*external_dcvdd = false;

	ldo1->supply.supply = "DCVDD";
	ldo1->init_data.consumer_supplies = &ldo1->supply;
	ldo1->supply.dev_name = dev_name(parent_dev);

	config.dev = parent_dev;
	config.driver_data = ldo1;
	config.regmap = ldo1->regmap;

	if (IS_ENABLED(CONFIG_OF)) {
		if (!dev_get_platdata(parent_dev)) {
			ret = arizona_ldo1_of_get_pdata(pdata,
							&config, desc,
							external_dcvdd);
			if (ret < 0)
				return ret;
		}
	}

	/* We assume that high output = regulator off
	 * Don't use devm, since we need to get against the parent device
	 * so clean up would happen at the wrong time
	 */
	config.ena_gpiod = gpiod_get_optional(parent_dev, "wlf,ldoena",
					      GPIOD_OUT_LOW);
	if (IS_ERR(config.ena_gpiod))
		return PTR_ERR(config.ena_gpiod);

	ldo1->ena_gpiod = config.ena_gpiod;

	if (pdata->init_data)
		config.init_data = pdata->init_data;
	else
		config.init_data = &ldo1->init_data;

	/*
	 * LDO1 can only be used to supply DCVDD so if it has no
	 * consumers then DCVDD is supplied externally.
	 */
	if (config.init_data->num_consumer_supplies == 0)
		*external_dcvdd = true;

	ldo1->regulator = devm_regulator_register(&pdev->dev, desc, &config);

	of_node_put(config.of_node);

	if (IS_ERR(ldo1->regulator)) {
		if (config.ena_gpiod)
			gpiod_put(config.ena_gpiod);

		ret = PTR_ERR(ldo1->regulator);
		dev_err(&pdev->dev, "Failed to register LDO1 supply: %d\n",
			ret);
		return ret;
	}

	platform_set_drvdata(pdev, ldo1);

	return 0;
}

__attribute__((used)) static int arizona_ldo1_probe(struct platform_device *pdev)
{
	struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
	struct arizona_ldo1 *ldo1;
	const struct regulator_desc *desc;
	bool external_dcvdd;
	int ret;

	ldo1 = devm_kzalloc(&pdev->dev, sizeof(*ldo1), GFP_KERNEL);
	if (!ldo1)
		return -ENOMEM;

	ldo1->regmap = arizona->regmap;

	/*
	 * Since the chip usually supplies itself we provide some
	 * default init_data for it.  This will be overridden with
	 * platform data if provided.
	 */
	switch (arizona->type) {
	case WM5102:
	case WM8997:
	case WM8998:
	case WM1814:
		desc = &arizona_ldo1_hc;
		ldo1->init_data = arizona_ldo1_dvfs;
		break;
	case WM5110:
	case WM8280:
		desc = &arizona_ldo1;
		ldo1->init_data = arizona_ldo1_wm5110;
		break;
	default:
		desc = &arizona_ldo1;
		ldo1->init_data = arizona_ldo1_default;
		break;
	}

	ret = arizona_ldo1_common_init(pdev, ldo1, desc,
				       &arizona->pdata.ldo1,
				       &external_dcvdd);
	if (ret == 0)
		arizona->external_dcvdd = external_dcvdd;

	return ret;
}

__attribute__((used)) static int arizona_ldo1_remove(struct platform_device *pdev)
{
	struct arizona_ldo1 *ldo1 = platform_get_drvdata(pdev);

	if (ldo1->ena_gpiod)
		gpiod_put(ldo1->ena_gpiod);

	return 0;
}

