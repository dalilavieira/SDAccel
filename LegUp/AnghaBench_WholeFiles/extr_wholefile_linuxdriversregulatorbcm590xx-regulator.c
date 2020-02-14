#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct regulator_init_data {int dummy; } ;
struct regulator_dev {int dummy; } ;
struct regulator_desc {int dummy; } ;
struct regulator_config {int /*<<< orphan*/  of_node; int /*<<< orphan*/  regmap; struct bcm590xx_reg* driver_data; struct regulator_init_data* init_data; TYPE_1__* dev; } ;
struct TYPE_10__ {TYPE_8__* parent; } ;
struct platform_device {int name; TYPE_1__ dev; } ;
struct of_regulator_match {int /*<<< orphan*/  of_node; struct regulator_init_data* init_data; } ;
struct device_node {int dummy; } ;
struct bcm590xx_reg {TYPE_3__* desc; struct bcm590xx* mfd; } ;
struct bcm590xx_info {int /*<<< orphan*/  n_linear_ranges; int /*<<< orphan*/  linear_ranges; int /*<<< orphan*/  n_voltages; int /*<<< orphan*/  volt_table; int /*<<< orphan*/  vin_name; int /*<<< orphan*/  name; } ;
struct bcm590xx_board {struct regulator_init_data** bcm590xx_pmu_init_data; } ;
struct bcm590xx {TYPE_1__* dev; int /*<<< orphan*/  regmap_pri; int /*<<< orphan*/  regmap_sec; } ;
struct TYPE_12__ {struct device_node* of_node; } ;
struct TYPE_11__ {int id; int vsel_reg; int enable_is_inverted; int enable_reg; int /*<<< orphan*/  owner; int /*<<< orphan*/  type; int /*<<< orphan*/  enable_mask; int /*<<< orphan*/  vsel_mask; int /*<<< orphan*/ * ops; int /*<<< orphan*/  n_linear_ranges; int /*<<< orphan*/  linear_ranges; int /*<<< orphan*/  n_voltages; int /*<<< orphan*/  volt_table; int /*<<< orphan*/  supply_name; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct of_regulator_match*) ; 
 int BCM590XX_CSRPMCTRL1 ; 
 int BCM590XX_CSRVOUT1 ; 
 int BCM590XX_GPLDO1CTRL ; 
 int BCM590XX_GPLDO1PMCTRL1 ; 
 int BCM590XX_IOSR1PMCTRL1 ; 
 int BCM590XX_IOSR2PMCTRL1 ; 
 int /*<<< orphan*/  BCM590XX_LDO_VSEL_MASK ; 
 int BCM590XX_MSRPMCTRL1 ; 
 int BCM590XX_NUM_REGS ; 
 int BCM590XX_OTG_CTRL ; 
#define  BCM590XX_REG_CSR 134 
 int /*<<< orphan*/  BCM590XX_REG_ENABLE ; 
#define  BCM590XX_REG_IOSR1 133 
#define  BCM590XX_REG_IOSR2 132 
 scalar_t__ BCM590XX_REG_IS_GPLDO (int) ; 
 scalar_t__ BCM590XX_REG_IS_LDO (int) ; 
 scalar_t__ BCM590XX_REG_IS_VBUS (int) ; 
#define  BCM590XX_REG_MSR 131 
#define  BCM590XX_REG_SDSR1 130 
#define  BCM590XX_REG_SDSR2 129 
#define  BCM590XX_REG_VBUS 128 
 int BCM590XX_RFLDOCTRL ; 
 int BCM590XX_RFLDOPMCTRL1 ; 
 int BCM590XX_SDSR1PMCTRL1 ; 
 int BCM590XX_SDSR2PMCTRL1 ; 
 int /*<<< orphan*/  BCM590XX_SR_VSEL_MASK ; 
 int /*<<< orphan*/  BCM590XX_VBUS_ENABLE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct of_regulator_match* bcm590xx_matches ; 
 int /*<<< orphan*/  bcm590xx_ops_dcdc ; 
 int /*<<< orphan*/  bcm590xx_ops_ldo ; 
 int /*<<< orphan*/  bcm590xx_ops_vbus ; 
 struct bcm590xx_info* bcm590xx_regs ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct bcm590xx* dev_get_drvdata (TYPE_8__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*) ; 
 TYPE_3__* devm_kcalloc (TYPE_1__*,int,int,int /*<<< orphan*/ ) ; 
 void* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_1__*,TYPE_3__*,struct regulator_config*) ; 
 struct device_node* of_get_child_by_name (struct device_node*,char*) ; 
 struct device_node* of_node_get (struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_regulator_match (TYPE_1__*,struct device_node*,struct of_regulator_match*,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct bcm590xx_reg*) ; 

__attribute__((used)) static int bcm590xx_get_vsel_register(int id)
{
	if (BCM590XX_REG_IS_LDO(id))
		return BCM590XX_RFLDOCTRL + id;
	else if (BCM590XX_REG_IS_GPLDO(id))
		return BCM590XX_GPLDO1CTRL + id;
	else
		return BCM590XX_CSRVOUT1 + (id - BCM590XX_REG_CSR) * 3;
}

__attribute__((used)) static int bcm590xx_get_enable_register(int id)
{
	int reg = 0;

	if (BCM590XX_REG_IS_LDO(id))
		reg = BCM590XX_RFLDOPMCTRL1 + id * 2;
	else if (BCM590XX_REG_IS_GPLDO(id))
		reg = BCM590XX_GPLDO1PMCTRL1 + id * 2;
	else
		switch (id) {
		case BCM590XX_REG_CSR:
			reg = BCM590XX_CSRPMCTRL1;
			break;
		case BCM590XX_REG_IOSR1:
			reg = BCM590XX_IOSR1PMCTRL1;
			break;
		case BCM590XX_REG_IOSR2:
			reg = BCM590XX_IOSR2PMCTRL1;
			break;
		case BCM590XX_REG_MSR:
			reg = BCM590XX_MSRPMCTRL1;
			break;
		case BCM590XX_REG_SDSR1:
			reg = BCM590XX_SDSR1PMCTRL1;
			break;
		case BCM590XX_REG_SDSR2:
			reg = BCM590XX_SDSR2PMCTRL1;
			break;
		case BCM590XX_REG_VBUS:
			reg = BCM590XX_OTG_CTRL;
		}


	return reg;
}

__attribute__((used)) static struct bcm590xx_board *bcm590xx_parse_dt_reg_data(
		struct platform_device *pdev,
		struct of_regulator_match **bcm590xx_reg_matches)
{
	struct bcm590xx_board *data;
	struct device_node *np = pdev->dev.parent->of_node;
	struct device_node *regulators;
	struct of_regulator_match *matches = bcm590xx_matches;
	int count = ARRAY_SIZE(bcm590xx_matches);
	int idx = 0;
	int ret;

	if (!np) {
		dev_err(&pdev->dev, "of node not found\n");
		return NULL;
	}

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return NULL;

	np = of_node_get(np);
	regulators = of_get_child_by_name(np, "regulators");
	if (!regulators) {
		dev_warn(&pdev->dev, "regulator node not found\n");
		return NULL;
	}

	ret = of_regulator_match(&pdev->dev, regulators, matches, count);
	of_node_put(regulators);
	if (ret < 0) {
		dev_err(&pdev->dev, "Error parsing regulator init data: %d\n",
			ret);
		return NULL;
	}

	*bcm590xx_reg_matches = matches;

	for (idx = 0; idx < count; idx++) {
		if (!matches[idx].init_data || !matches[idx].of_node)
			continue;

		data->bcm590xx_pmu_init_data[idx] = matches[idx].init_data;
	}

	return data;
}

__attribute__((used)) static int bcm590xx_probe(struct platform_device *pdev)
{
	struct bcm590xx *bcm590xx = dev_get_drvdata(pdev->dev.parent);
	struct bcm590xx_board *pmu_data = NULL;
	struct bcm590xx_reg *pmu;
	struct regulator_config config = { };
	struct bcm590xx_info *info;
	struct regulator_init_data *reg_data;
	struct regulator_dev *rdev;
	struct of_regulator_match *bcm590xx_reg_matches = NULL;
	int i;

	pmu_data = bcm590xx_parse_dt_reg_data(pdev,
					      &bcm590xx_reg_matches);

	pmu = devm_kzalloc(&pdev->dev, sizeof(*pmu), GFP_KERNEL);
	if (!pmu)
		return -ENOMEM;

	pmu->mfd = bcm590xx;

	platform_set_drvdata(pdev, pmu);

	pmu->desc = devm_kcalloc(&pdev->dev,
				 BCM590XX_NUM_REGS,
				 sizeof(struct regulator_desc),
				 GFP_KERNEL);
	if (!pmu->desc)
		return -ENOMEM;

	info = bcm590xx_regs;

	for (i = 0; i < BCM590XX_NUM_REGS; i++, info++) {
		if (pmu_data)
			reg_data = pmu_data->bcm590xx_pmu_init_data[i];
		else
			reg_data = NULL;

		/* Register the regulators */
		pmu->desc[i].name = info->name;
		pmu->desc[i].supply_name = info->vin_name;
		pmu->desc[i].id = i;
		pmu->desc[i].volt_table = info->volt_table;
		pmu->desc[i].n_voltages = info->n_voltages;
		pmu->desc[i].linear_ranges = info->linear_ranges;
		pmu->desc[i].n_linear_ranges = info->n_linear_ranges;

		if ((BCM590XX_REG_IS_LDO(i)) || (BCM590XX_REG_IS_GPLDO(i))) {
			pmu->desc[i].ops = &bcm590xx_ops_ldo;
			pmu->desc[i].vsel_mask = BCM590XX_LDO_VSEL_MASK;
		} else if (BCM590XX_REG_IS_VBUS(i))
			pmu->desc[i].ops = &bcm590xx_ops_vbus;
		else {
			pmu->desc[i].ops = &bcm590xx_ops_dcdc;
			pmu->desc[i].vsel_mask = BCM590XX_SR_VSEL_MASK;
		}

		if (BCM590XX_REG_IS_VBUS(i))
			pmu->desc[i].enable_mask = BCM590XX_VBUS_ENABLE;
		else {
			pmu->desc[i].vsel_reg = bcm590xx_get_vsel_register(i);
			pmu->desc[i].enable_is_inverted = true;
			pmu->desc[i].enable_mask = BCM590XX_REG_ENABLE;
		}
		pmu->desc[i].enable_reg = bcm590xx_get_enable_register(i);
		pmu->desc[i].type = REGULATOR_VOLTAGE;
		pmu->desc[i].owner = THIS_MODULE;

		config.dev = bcm590xx->dev;
		config.init_data = reg_data;
		config.driver_data = pmu;
		if (BCM590XX_REG_IS_GPLDO(i) || BCM590XX_REG_IS_VBUS(i))
			config.regmap = bcm590xx->regmap_sec;
		else
			config.regmap = bcm590xx->regmap_pri;

		if (bcm590xx_reg_matches)
			config.of_node = bcm590xx_reg_matches[i].of_node;

		rdev = devm_regulator_register(&pdev->dev, &pmu->desc[i],
					       &config);
		if (IS_ERR(rdev)) {
			dev_err(bcm590xx->dev,
				"failed to register %s regulator\n",
				pdev->name);
			return PTR_ERR(rdev);
		}
	}

	return 0;
}

