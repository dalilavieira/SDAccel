#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_9__ {struct device_node* of_node; } ;
struct regulator_dev {TYPE_2__ dev; TYPE_1__* desc; int /*<<< orphan*/  regmap; } ;
struct regulator_desc {char* name; char const* supply_name; } ;
struct regulator_config {struct axp20x_dev* driver_data; int /*<<< orphan*/  regmap; TYPE_6__* dev; } ;
struct TYPE_10__ {TYPE_6__* parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct device_node {int dummy; } ;
struct axp20x_dev {int variant; int /*<<< orphan*/  regmap; } ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; } ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
#define  AXP202_ID 140 
#define  AXP209_ID 139 
 int AXP20X_DCDC2 ; 
 int AXP20X_DCDC3 ; 
 unsigned int AXP20X_DCDC_FREQ ; 
 unsigned int AXP20X_DCDC_MODE ; 
 unsigned int AXP20X_FREQ_DCDC_MASK ; 
 unsigned int AXP20X_OVER_TMP ; 
 int AXP20X_REG_ID_MAX ; 
 unsigned int AXP20X_WORKMODE_DCDC2_MASK ; 
 unsigned int AXP20X_WORKMODE_DCDC3_MASK ; 
#define  AXP221_ID 138 
#define  AXP223_ID 137 
 int AXP22X_DC1SW ; 
 int AXP22X_DC5LDO ; 
 int AXP22X_DCDC1 ; 
 int AXP22X_DCDC5 ; 
 unsigned int AXP22X_MISC_N_VBUSEN_FUNC ; 
 int AXP22X_REG_ID_MAX ; 
 unsigned int AXP22X_WORKMODE_DCDCX_MASK (int) ; 
 int AXP803_DC1SW ; 
 int AXP803_DCDC1 ; 
#define  AXP803_DCDC3 136 
#define  AXP803_DCDC6 135 
 unsigned int AXP803_DCDC_FREQ_CTRL ; 
#define  AXP803_ID 134 
 unsigned int AXP803_POLYPHASE_CTRL ; 
 int AXP803_REG_ID_MAX ; 
#define  AXP806_DCDCB 133 
#define  AXP806_DCDCC 132 
#define  AXP806_DCDCE 131 
 unsigned int AXP806_DCDC_FREQ_CTRL ; 
 unsigned int AXP806_DCDC_MODE_CTRL2 ; 
#define  AXP806_ID 130 
 int AXP806_REG_ID_MAX ; 
 int AXP809_DC1SW ; 
 int AXP809_DC5LDO ; 
 int AXP809_DCDC1 ; 
 int AXP809_DCDC5 ; 
#define  AXP809_ID 129 
 int AXP809_REG_ID_MAX ; 
 int AXP813_DCDC1 ; 
 int AXP813_DCDC7 ; 
 int AXP813_FLDO3 ; 
#define  AXP813_ID 128 
 int AXP813_REG_ID_MAX ; 
 int BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int GENMASK (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 struct regulator_desc* axp20x_regulators ; 
 struct regulator_desc const axp22x_drivevbus_regulator ; 
 struct regulator_desc const* axp22x_regulators ; 
 struct regulator_desc const* axp803_regulators ; 
 struct regulator_desc* axp806_regulators ; 
 struct regulator_desc const* axp809_regulators ; 
 struct regulator_desc* axp813_regulators ; 
 int /*<<< orphan*/  dev_err (TYPE_3__*,char*,...) ; 
 struct axp20x_dev* dev_get_drvdata (TYPE_6__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_3__*,char*,...) ; 
 struct regulator_desc* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_3__*,struct regulator_desc const*,struct regulator_config*) ; 
 int /*<<< orphan*/  ffs (unsigned int) ; 
 struct device_node* of_get_child_by_name (struct device_node*,char*) ; 
 struct device_node* of_node_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_property_read_bool (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  of_property_read_string (struct device_node*,char*,char const**) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct axp20x_dev* rdev_get_drvdata (struct regulator_dev*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,unsigned int,int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,unsigned int,unsigned int,int) ; 

__attribute__((used)) static int axp20x_set_dcdc_freq(struct platform_device *pdev, u32 dcdcfreq)
{
	struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
	unsigned int reg = AXP20X_DCDC_FREQ;
	u32 min, max, def, step;

	switch (axp20x->variant) {
	case AXP202_ID:
	case AXP209_ID:
		min = 750;
		max = 1875;
		def = 1500;
		step = 75;
		break;
	case AXP803_ID:
	case AXP813_ID:
		/*
		 * AXP803/AXP813 DCDC work frequency setting has the same
		 * range and step as AXP22X, but at a different register.
		 * Fall through to the check below.
		 * (See include/linux/mfd/axp20x.h)
		 */
		reg = AXP803_DCDC_FREQ_CTRL;
	case AXP806_ID:
		/*
		 * AXP806 also have DCDC work frequency setting register at a
		 * different position.
		 */
		if (axp20x->variant == AXP806_ID)
			reg = AXP806_DCDC_FREQ_CTRL;
	case AXP221_ID:
	case AXP223_ID:
	case AXP809_ID:
		min = 1800;
		max = 4050;
		def = 3000;
		step = 150;
		break;
	default:
		dev_err(&pdev->dev,
			"Setting DCDC frequency for unsupported AXP variant\n");
		return -EINVAL;
	}

	if (dcdcfreq == 0)
		dcdcfreq = def;

	if (dcdcfreq < min) {
		dcdcfreq = min;
		dev_warn(&pdev->dev, "DCDC frequency too low. Set to %ukHz\n",
			 min);
	}

	if (dcdcfreq > max) {
		dcdcfreq = max;
		dev_warn(&pdev->dev, "DCDC frequency too high. Set to %ukHz\n",
			 max);
	}

	dcdcfreq = (dcdcfreq - min) / step;

	return regmap_update_bits(axp20x->regmap, reg,
				  AXP20X_FREQ_DCDC_MASK, dcdcfreq);
}

__attribute__((used)) static int axp20x_regulator_parse_dt(struct platform_device *pdev)
{
	struct device_node *np, *regulators;
	int ret;
	u32 dcdcfreq = 0;

	np = of_node_get(pdev->dev.parent->of_node);
	if (!np)
		return 0;

	regulators = of_get_child_by_name(np, "regulators");
	if (!regulators) {
		dev_warn(&pdev->dev, "regulators node not found\n");
	} else {
		of_property_read_u32(regulators, "x-powers,dcdc-freq", &dcdcfreq);
		ret = axp20x_set_dcdc_freq(pdev, dcdcfreq);
		if (ret < 0) {
			dev_err(&pdev->dev, "Error setting dcdc frequency: %d\n", ret);
			return ret;
		}

		of_node_put(regulators);
	}

	return 0;
}

__attribute__((used)) static int axp20x_set_dcdc_workmode(struct regulator_dev *rdev, int id, u32 workmode)
{
	struct axp20x_dev *axp20x = rdev_get_drvdata(rdev);
	unsigned int reg = AXP20X_DCDC_MODE;
	unsigned int mask;

	switch (axp20x->variant) {
	case AXP202_ID:
	case AXP209_ID:
		if ((id != AXP20X_DCDC2) && (id != AXP20X_DCDC3))
			return -EINVAL;

		mask = AXP20X_WORKMODE_DCDC2_MASK;
		if (id == AXP20X_DCDC3)
			mask = AXP20X_WORKMODE_DCDC3_MASK;

		workmode <<= ffs(mask) - 1;
		break;

	case AXP806_ID:
		reg = AXP806_DCDC_MODE_CTRL2;
		/*
		 * AXP806 DCDC regulator IDs have the same range as AXP22X.
		 * Fall through to the check below.
		 * (See include/linux/mfd/axp20x.h)
		 */
	case AXP221_ID:
	case AXP223_ID:
	case AXP809_ID:
		if (id < AXP22X_DCDC1 || id > AXP22X_DCDC5)
			return -EINVAL;

		mask = AXP22X_WORKMODE_DCDCX_MASK(id - AXP22X_DCDC1);
		workmode <<= id - AXP22X_DCDC1;
		break;

	case AXP803_ID:
		if (id < AXP803_DCDC1 || id > AXP803_DCDC6)
			return -EINVAL;

		mask = AXP22X_WORKMODE_DCDCX_MASK(id - AXP803_DCDC1);
		workmode <<= id - AXP803_DCDC1;
		break;

	case AXP813_ID:
		if (id < AXP813_DCDC1 || id > AXP813_DCDC7)
			return -EINVAL;

		mask = AXP22X_WORKMODE_DCDCX_MASK(id - AXP813_DCDC1);
		workmode <<= id - AXP813_DCDC1;
		break;

	default:
		/* should not happen */
		WARN_ON(1);
		return -EINVAL;
	}

	return regmap_update_bits(rdev->regmap, reg, mask, workmode);
}

__attribute__((used)) static bool axp20x_is_polyphase_slave(struct axp20x_dev *axp20x, int id)
{
	u32 reg = 0;

	/*
	 * Currently in our supported AXP variants, only AXP803, AXP806,
	 * and AXP813 have polyphase regulators.
	 */
	switch (axp20x->variant) {
	case AXP803_ID:
	case AXP813_ID:
		regmap_read(axp20x->regmap, AXP803_POLYPHASE_CTRL, &reg);

		switch (id) {
		case AXP803_DCDC3:
			return !!(reg & BIT(6));
		case AXP803_DCDC6:
			return !!(reg & BIT(5));
		}
		break;

	case AXP806_ID:
		regmap_read(axp20x->regmap, AXP806_DCDC_MODE_CTRL2, &reg);

		switch (id) {
		case AXP806_DCDCB:
			return (((reg & GENMASK(7, 6)) == BIT(6)) ||
				((reg & GENMASK(7, 6)) == BIT(7)));
		case AXP806_DCDCC:
			return ((reg & GENMASK(7, 6)) == BIT(7));
		case AXP806_DCDCE:
			return !!(reg & BIT(5));
		}
		break;

	default:
		return false;
	}

	return false;
}

__attribute__((used)) static int axp20x_regulator_probe(struct platform_device *pdev)
{
	struct regulator_dev *rdev;
	struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
	const struct regulator_desc *regulators;
	struct regulator_config config = {
		.dev = pdev->dev.parent,
		.regmap = axp20x->regmap,
		.driver_data = axp20x,
	};
	int ret, i, nregulators;
	u32 workmode;
	const char *dcdc1_name = axp22x_regulators[AXP22X_DCDC1].name;
	const char *dcdc5_name = axp22x_regulators[AXP22X_DCDC5].name;
	bool drivevbus = false;

	switch (axp20x->variant) {
	case AXP202_ID:
	case AXP209_ID:
		regulators = axp20x_regulators;
		nregulators = AXP20X_REG_ID_MAX;
		break;
	case AXP221_ID:
	case AXP223_ID:
		regulators = axp22x_regulators;
		nregulators = AXP22X_REG_ID_MAX;
		drivevbus = of_property_read_bool(pdev->dev.parent->of_node,
						  "x-powers,drive-vbus-en");
		break;
	case AXP803_ID:
		regulators = axp803_regulators;
		nregulators = AXP803_REG_ID_MAX;
		drivevbus = of_property_read_bool(pdev->dev.parent->of_node,
						  "x-powers,drive-vbus-en");
		break;
	case AXP806_ID:
		regulators = axp806_regulators;
		nregulators = AXP806_REG_ID_MAX;
		break;
	case AXP809_ID:
		regulators = axp809_regulators;
		nregulators = AXP809_REG_ID_MAX;
		break;
	case AXP813_ID:
		regulators = axp813_regulators;
		nregulators = AXP813_REG_ID_MAX;
		drivevbus = of_property_read_bool(pdev->dev.parent->of_node,
						  "x-powers,drive-vbus-en");
		break;
	default:
		dev_err(&pdev->dev, "Unsupported AXP variant: %ld\n",
			axp20x->variant);
		return -EINVAL;
	}

	/* This only sets the dcdc freq. Ignore any errors */
	axp20x_regulator_parse_dt(pdev);

	for (i = 0; i < nregulators; i++) {
		const struct regulator_desc *desc = &regulators[i];
		struct regulator_desc *new_desc;

		/*
		 * If this regulator is a slave in a poly-phase setup,
		 * skip it, as its controls are bound to the master
		 * regulator and won't work.
		 */
		if (axp20x_is_polyphase_slave(axp20x, i))
			continue;

		/* Support for AXP813's FLDO3 is not implemented */
		if (axp20x->variant == AXP813_ID && i == AXP813_FLDO3)
			continue;

		/*
		 * Regulators DC1SW and DC5LDO are connected internally,
		 * so we have to handle their supply names separately.
		 *
		 * We always register the regulators in proper sequence,
		 * so the supply names are correctly read. See the last
		 * part of this loop to see where we save the DT defined
		 * name.
		 */
		if ((regulators == axp22x_regulators && i == AXP22X_DC1SW) ||
		    (regulators == axp803_regulators && i == AXP803_DC1SW) ||
		    (regulators == axp809_regulators && i == AXP809_DC1SW)) {
			new_desc = devm_kzalloc(&pdev->dev, sizeof(*desc),
						GFP_KERNEL);
			if (!new_desc)
				return -ENOMEM;

			*new_desc = regulators[i];
			new_desc->supply_name = dcdc1_name;
			desc = new_desc;
		}

		if ((regulators == axp22x_regulators && i == AXP22X_DC5LDO) ||
		    (regulators == axp809_regulators && i == AXP809_DC5LDO)) {
			new_desc = devm_kzalloc(&pdev->dev, sizeof(*desc),
						GFP_KERNEL);
			if (!new_desc)
				return -ENOMEM;

			*new_desc = regulators[i];
			new_desc->supply_name = dcdc5_name;
			desc = new_desc;
		}

		rdev = devm_regulator_register(&pdev->dev, desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "Failed to register %s\n",
				regulators[i].name);

			return PTR_ERR(rdev);
		}

		ret = of_property_read_u32(rdev->dev.of_node,
					   "x-powers,dcdc-workmode",
					   &workmode);
		if (!ret) {
			if (axp20x_set_dcdc_workmode(rdev, i, workmode))
				dev_err(&pdev->dev, "Failed to set workmode on %s\n",
					rdev->desc->name);
		}

		/*
		 * Save AXP22X DCDC1 / DCDC5 regulator names for later.
		 */
		if ((regulators == axp22x_regulators && i == AXP22X_DCDC1) ||
		    (regulators == axp809_regulators && i == AXP809_DCDC1))
			of_property_read_string(rdev->dev.of_node,
						"regulator-name",
						&dcdc1_name);

		if ((regulators == axp22x_regulators && i == AXP22X_DCDC5) ||
		    (regulators == axp809_regulators && i == AXP809_DCDC5))
			of_property_read_string(rdev->dev.of_node,
						"regulator-name",
						&dcdc5_name);
	}

	if (drivevbus) {
		/* Change N_VBUSEN sense pin to DRIVEVBUS output pin */
		regmap_update_bits(axp20x->regmap, AXP20X_OVER_TMP,
				   AXP22X_MISC_N_VBUSEN_FUNC, 0);
		rdev = devm_regulator_register(&pdev->dev,
					       &axp22x_drivevbus_regulator,
					       &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "Failed to register drivevbus\n");
			return PTR_ERR(rdev);
		}
	}

	return 0;
}

