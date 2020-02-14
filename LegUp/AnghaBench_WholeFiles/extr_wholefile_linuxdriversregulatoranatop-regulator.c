#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct regulator_init_data {char* supply_regulator; } ;
struct regulator_dev {int dummy; } ;
struct regulator_desc {int n_voltages; int min_uV; int uV_step; int linear_min_sel; int vsel_reg; int vsel_mask; int min_dropout_uV; int enable_reg; int /*<<< orphan*/  name; int /*<<< orphan*/  enable_mask; TYPE_1__* ops; int /*<<< orphan*/  owner; int /*<<< orphan*/  type; } ;
struct regulator_config {struct regulator_dev* regmap; struct device_node* of_node; struct anatop_regulator* driver_data; struct regulator_init_data* init_data; struct device* dev; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
struct anatop_regulator {int delay_bit_width; int delay_reg; int delay_bit_shift; int bypass; int sel; int control_reg; int vol_bit_width; int vol_bit_shift; int min_bit_val; int min_voltage; int max_voltage; struct regulator_dev* anatop; struct regulator_init_data* initdata; struct regulator_desc rdesc; } ;
struct TYPE_3__ {int /*<<< orphan*/  is_enabled; int /*<<< orphan*/  disable; int /*<<< orphan*/  enable; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int LDO_FET_FULL_ON ; 
 int LDO_POWER_GATE ; 
 unsigned int LDO_RAMP_UP_FREQ_IN_MHZ ; 
 int LDO_RAMP_UP_UNIT_IN_CYCLES ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 TYPE_1__ anatop_core_rops ; 
 TYPE_1__ anatop_rops ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct anatop_regulator* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (struct device*,struct regulator_desc*,struct regulator_config*) ; 
 struct device_node* of_get_parent (struct device_node*) ; 
 struct regulator_init_data* of_get_regulator_init_data (struct device*,struct device_node*,struct regulator_desc*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_property_read_string (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct regulator_dev*) ; 
 struct anatop_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int regmap_read (struct regulator_dev*,int,int*) ; 
 int /*<<< orphan*/  regulator_disable_regmap ; 
 int /*<<< orphan*/  regulator_enable_regmap ; 
 int regulator_get_voltage_sel_regmap (struct regulator_dev*) ; 
 int /*<<< orphan*/  regulator_is_enabled_regmap ; 
 int regulator_set_voltage_sel_regmap (struct regulator_dev*,int) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 struct regulator_dev* syscon_node_to_regmap (struct device_node*) ; 

__attribute__((used)) static int anatop_regmap_set_voltage_time_sel(struct regulator_dev *reg,
	unsigned int old_sel,
	unsigned int new_sel)
{
	struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
	u32 val;
	int ret = 0;

	/* check whether need to care about LDO ramp up speed */
	if (anatop_reg->delay_bit_width && new_sel > old_sel) {
		/*
		 * the delay for LDO ramp up time is
		 * based on the register setting, we need
		 * to calculate how many steps LDO need to
		 * ramp up, and how much delay needed. (us)
		 */
		regmap_read(anatop_reg->anatop, anatop_reg->delay_reg, &val);
		val = (val >> anatop_reg->delay_bit_shift) &
			((1 << anatop_reg->delay_bit_width) - 1);
		ret = (new_sel - old_sel) * (LDO_RAMP_UP_UNIT_IN_CYCLES <<
			val) / LDO_RAMP_UP_FREQ_IN_MHZ + 1;
	}

	return ret;
}

__attribute__((used)) static int anatop_regmap_enable(struct regulator_dev *reg)
{
	struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
	int sel;

	sel = anatop_reg->bypass ? LDO_FET_FULL_ON : anatop_reg->sel;
	return regulator_set_voltage_sel_regmap(reg, sel);
}

__attribute__((used)) static int anatop_regmap_disable(struct regulator_dev *reg)
{
	return regulator_set_voltage_sel_regmap(reg, LDO_POWER_GATE);
}

__attribute__((used)) static int anatop_regmap_is_enabled(struct regulator_dev *reg)
{
	return regulator_get_voltage_sel_regmap(reg) != LDO_POWER_GATE;
}

__attribute__((used)) static int anatop_regmap_core_set_voltage_sel(struct regulator_dev *reg,
					      unsigned selector)
{
	struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
	int ret;

	if (anatop_reg->bypass || !anatop_regmap_is_enabled(reg)) {
		anatop_reg->sel = selector;
		return 0;
	}

	ret = regulator_set_voltage_sel_regmap(reg, selector);
	if (!ret)
		anatop_reg->sel = selector;
	return ret;
}

__attribute__((used)) static int anatop_regmap_core_get_voltage_sel(struct regulator_dev *reg)
{
	struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);

	if (anatop_reg->bypass || !anatop_regmap_is_enabled(reg))
		return anatop_reg->sel;

	return regulator_get_voltage_sel_regmap(reg);
}

__attribute__((used)) static int anatop_regmap_get_bypass(struct regulator_dev *reg, bool *enable)
{
	struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
	int sel;

	sel = regulator_get_voltage_sel_regmap(reg);
	if (sel == LDO_FET_FULL_ON)
		WARN_ON(!anatop_reg->bypass);
	else if (sel != LDO_POWER_GATE)
		WARN_ON(anatop_reg->bypass);

	*enable = anatop_reg->bypass;
	return 0;
}

__attribute__((used)) static int anatop_regmap_set_bypass(struct regulator_dev *reg, bool enable)
{
	struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
	int sel;

	if (enable == anatop_reg->bypass)
		return 0;

	sel = enable ? LDO_FET_FULL_ON : anatop_reg->sel;
	anatop_reg->bypass = enable;

	return regulator_set_voltage_sel_regmap(reg, sel);
}

__attribute__((used)) static int anatop_regulator_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct device_node *anatop_np;
	struct regulator_desc *rdesc;
	struct regulator_dev *rdev;
	struct anatop_regulator *sreg;
	struct regulator_init_data *initdata;
	struct regulator_config config = { };
	int ret = 0;
	u32 val;

	sreg = devm_kzalloc(dev, sizeof(*sreg), GFP_KERNEL);
	if (!sreg)
		return -ENOMEM;

	rdesc = &sreg->rdesc;
	rdesc->type = REGULATOR_VOLTAGE;
	rdesc->owner = THIS_MODULE;

	of_property_read_string(np, "regulator-name", &rdesc->name);
	if (!rdesc->name) {
		dev_err(dev, "failed to get a regulator-name\n");
		return -EINVAL;
	}

	initdata = of_get_regulator_init_data(dev, np, rdesc);
	if (!initdata)
		return -ENOMEM;

	initdata->supply_regulator = "vin";
	sreg->initdata = initdata;

	anatop_np = of_get_parent(np);
	if (!anatop_np)
		return -ENODEV;
	sreg->anatop = syscon_node_to_regmap(anatop_np);
	of_node_put(anatop_np);
	if (IS_ERR(sreg->anatop))
		return PTR_ERR(sreg->anatop);

	ret = of_property_read_u32(np, "anatop-reg-offset",
				   &sreg->control_reg);
	if (ret) {
		dev_err(dev, "no anatop-reg-offset property set\n");
		return ret;
	}
	ret = of_property_read_u32(np, "anatop-vol-bit-width",
				   &sreg->vol_bit_width);
	if (ret) {
		dev_err(dev, "no anatop-vol-bit-width property set\n");
		return ret;
	}
	ret = of_property_read_u32(np, "anatop-vol-bit-shift",
				   &sreg->vol_bit_shift);
	if (ret) {
		dev_err(dev, "no anatop-vol-bit-shift property set\n");
		return ret;
	}
	ret = of_property_read_u32(np, "anatop-min-bit-val",
				   &sreg->min_bit_val);
	if (ret) {
		dev_err(dev, "no anatop-min-bit-val property set\n");
		return ret;
	}
	ret = of_property_read_u32(np, "anatop-min-voltage",
				   &sreg->min_voltage);
	if (ret) {
		dev_err(dev, "no anatop-min-voltage property set\n");
		return ret;
	}
	ret = of_property_read_u32(np, "anatop-max-voltage",
				   &sreg->max_voltage);
	if (ret) {
		dev_err(dev, "no anatop-max-voltage property set\n");
		return ret;
	}

	/* read LDO ramp up setting, only for core reg */
	of_property_read_u32(np, "anatop-delay-reg-offset",
			     &sreg->delay_reg);
	of_property_read_u32(np, "anatop-delay-bit-width",
			     &sreg->delay_bit_width);
	of_property_read_u32(np, "anatop-delay-bit-shift",
			     &sreg->delay_bit_shift);

	rdesc->n_voltages = (sreg->max_voltage - sreg->min_voltage) / 25000 + 1
			    + sreg->min_bit_val;
	rdesc->min_uV = sreg->min_voltage;
	rdesc->uV_step = 25000;
	rdesc->linear_min_sel = sreg->min_bit_val;
	rdesc->vsel_reg = sreg->control_reg;
	rdesc->vsel_mask = ((1 << sreg->vol_bit_width) - 1) <<
			   sreg->vol_bit_shift;
	rdesc->min_dropout_uV = 125000;

	config.dev = &pdev->dev;
	config.init_data = initdata;
	config.driver_data = sreg;
	config.of_node = pdev->dev.of_node;
	config.regmap = sreg->anatop;

	/* Only core regulators have the ramp up delay configuration. */
	if (sreg->control_reg && sreg->delay_bit_width) {
		rdesc->ops = &anatop_core_rops;

		ret = regmap_read(config.regmap, rdesc->vsel_reg, &val);
		if (ret) {
			dev_err(dev, "failed to read initial state\n");
			return ret;
		}

		sreg->sel = (val & rdesc->vsel_mask) >> sreg->vol_bit_shift;
		if (sreg->sel == LDO_FET_FULL_ON) {
			sreg->sel = 0;
			sreg->bypass = true;
		}

		/*
		 * In case vddpu was disabled by the bootloader, we need to set
		 * a sane default until imx6-cpufreq was probed and changes the
		 * voltage to the correct value. In this case we set 1.25V.
		 */
		if (!sreg->sel && !strcmp(rdesc->name, "vddpu"))
			sreg->sel = 22;

		/* set the default voltage of the pcie phy to be 1.100v */
		if (!sreg->sel && !strcmp(rdesc->name, "vddpcie"))
			sreg->sel = 0x10;

		if (!sreg->bypass && !sreg->sel) {
			dev_err(&pdev->dev, "Failed to read a valid default voltage selector.\n");
			return -EINVAL;
		}
	} else {
		u32 enable_bit;

		rdesc->ops = &anatop_rops;

		if (!of_property_read_u32(np, "anatop-enable-bit",
					  &enable_bit)) {
			anatop_rops.enable  = regulator_enable_regmap;
			anatop_rops.disable = regulator_disable_regmap;
			anatop_rops.is_enabled = regulator_is_enabled_regmap;

			rdesc->enable_reg = sreg->control_reg;
			rdesc->enable_mask = BIT(enable_bit);
		}
	}

	/* register regulator */
	rdev = devm_regulator_register(dev, rdesc, &config);
	if (IS_ERR(rdev)) {
		dev_err(dev, "failed to register %s\n",
			rdesc->name);
		return PTR_ERR(rdev);
	}

	platform_set_drvdata(pdev, rdev);

	return 0;
}

