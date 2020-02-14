#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int intval; } ;
struct power_supply_desc {int dummy; } ;
struct power_supply_config {struct axp20x_usb_power* drv_data; int /*<<< orphan*/  of_node; } ;
struct power_supply {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct axp20x_usb_power {scalar_t__ axp20x_id; void* supply; int /*<<< orphan*/  regmap; int /*<<< orphan*/  np; void* vbus_i; void* vbus_v; } ;
struct axp20x_dev {int /*<<< orphan*/  regmap_irqc; int /*<<< orphan*/  variant; int /*<<< orphan*/  regmap; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;
typedef  enum axp20x_variants { ____Placeholder_axp20x_variants } axp20x_variants ;

/* Variables and functions */
 scalar_t__ AXP202_ID ; 
 int /*<<< orphan*/  AXP20X_ADC_EN1 ; 
 unsigned int AXP20X_ADC_EN1_VBUS_CURR ; 
 unsigned int AXP20X_ADC_EN1_VBUS_VOLT ; 
 int /*<<< orphan*/  AXP20X_PWR_INPUT_STATUS ; 
 unsigned int AXP20X_PWR_STATUS_VBUS_PRESENT ; 
 unsigned int AXP20X_PWR_STATUS_VBUS_USED ; 
 int /*<<< orphan*/  AXP20X_USB_OTG_STATUS ; 
 unsigned int AXP20X_USB_STATUS_VBUS_VALID ; 
#define  AXP20X_VBUC_CLIMIT_100mA 138 
#define  AXP20X_VBUC_CLIMIT_500mA 137 
#define  AXP20X_VBUC_CLIMIT_900mA 136 
#define  AXP20X_VBUC_CLIMIT_NONE 135 
 unsigned int AXP20X_VBUS_CLIMIT_MASK ; 
 int /*<<< orphan*/  AXP20X_VBUS_IPSOUT_MGMT ; 
 int /*<<< orphan*/  AXP20X_VBUS_I_ADC_H ; 
 int /*<<< orphan*/  AXP20X_VBUS_MON ; 
 unsigned int AXP20X_VBUS_MON_VBUS_VALID ; 
 unsigned int AXP20X_VBUS_VHOLD_MASK ; 
 int AXP20X_VBUS_VHOLD_OFFSET ; 
 int AXP20X_VBUS_VHOLD_uV (unsigned int) ; 
 int /*<<< orphan*/  AXP20X_VBUS_V_ADC_H ; 
 scalar_t__ AXP221_ID ; 
 scalar_t__ AXP223_ID ; 
 int /*<<< orphan*/  CONFIG_AXP20X_ADC ; 
 int /*<<< orphan*/  DRVNAME ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (void*) ; 
 int POWER_SUPPLY_HEALTH_GOOD ; 
 int POWER_SUPPLY_HEALTH_UNKNOWN ; 
 int POWER_SUPPLY_HEALTH_UNSPEC_FAILURE ; 
#define  POWER_SUPPLY_PROP_CURRENT_MAX 134 
#define  POWER_SUPPLY_PROP_CURRENT_NOW 133 
#define  POWER_SUPPLY_PROP_HEALTH 132 
#define  POWER_SUPPLY_PROP_ONLINE 131 
#define  POWER_SUPPLY_PROP_PRESENT 130 
#define  POWER_SUPPLY_PROP_VOLTAGE_MIN 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 128 
 int PTR_ERR (void*) ; 
 int axp20x_read_variable_width (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct power_supply_desc axp20x_usb_power_desc ; 
 struct power_supply_desc axp22x_usb_power_desc ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct axp20x_dev* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*,char const* const,int) ; 
 void* devm_iio_channel_get (TYPE_1__*,char*) ; 
 struct axp20x_usb_power* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 void* devm_power_supply_register (TYPE_1__*,struct power_supply_desc const*,struct power_supply_config*) ; 
 int devm_request_any_context_irq (TYPE_1__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct axp20x_usb_power*) ; 
 int iio_read_channel_processed (void*,int*) ; 
 scalar_t__ of_device_get_match_data (TYPE_1__*) ; 
 int /*<<< orphan*/  of_device_is_available (int /*<<< orphan*/ ) ; 
 int platform_get_irq_byname (struct platform_device*,char const* const) ; 
 int /*<<< orphan*/  power_supply_changed (void*) ; 
 struct axp20x_usb_power* power_supply_get_drvdata (struct power_supply*) ; 
 int regmap_irq_get_virq (int /*<<< orphan*/ ,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 

__attribute__((used)) static irqreturn_t axp20x_usb_power_irq(int irq, void *devid)
{
	struct axp20x_usb_power *power = devid;

	power_supply_changed(power->supply);

	return IRQ_HANDLED;
}

__attribute__((used)) static int axp20x_usb_power_get_property(struct power_supply *psy,
	enum power_supply_property psp, union power_supply_propval *val)
{
	struct axp20x_usb_power *power = power_supply_get_drvdata(psy);
	unsigned int input, v;
	int ret;

	switch (psp) {
	case POWER_SUPPLY_PROP_VOLTAGE_MIN:
		ret = regmap_read(power->regmap, AXP20X_VBUS_IPSOUT_MGMT, &v);
		if (ret)
			return ret;

		val->intval = AXP20X_VBUS_VHOLD_uV(v);
		return 0;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		if (IS_ENABLED(CONFIG_AXP20X_ADC)) {
			ret = iio_read_channel_processed(power->vbus_v,
							 &val->intval);
			if (ret)
				return ret;

			/*
			 * IIO framework gives mV but Power Supply framework
			 * gives uV.
			 */
			val->intval *= 1000;
			return 0;
		}

		ret = axp20x_read_variable_width(power->regmap,
						 AXP20X_VBUS_V_ADC_H, 12);
		if (ret < 0)
			return ret;

		val->intval = ret * 1700; /* 1 step = 1.7 mV */
		return 0;
	case POWER_SUPPLY_PROP_CURRENT_MAX:
		ret = regmap_read(power->regmap, AXP20X_VBUS_IPSOUT_MGMT, &v);
		if (ret)
			return ret;

		switch (v & AXP20X_VBUS_CLIMIT_MASK) {
		case AXP20X_VBUC_CLIMIT_100mA:
			if (power->axp20x_id == AXP221_ID)
				val->intval = -1; /* No 100mA limit */
			else
				val->intval = 100000;
			break;
		case AXP20X_VBUC_CLIMIT_500mA:
			val->intval = 500000;
			break;
		case AXP20X_VBUC_CLIMIT_900mA:
			val->intval = 900000;
			break;
		case AXP20X_VBUC_CLIMIT_NONE:
			val->intval = -1;
			break;
		}
		return 0;
	case POWER_SUPPLY_PROP_CURRENT_NOW:
		if (IS_ENABLED(CONFIG_AXP20X_ADC)) {
			ret = iio_read_channel_processed(power->vbus_i,
							 &val->intval);
			if (ret)
				return ret;

			/*
			 * IIO framework gives mA but Power Supply framework
			 * gives uA.
			 */
			val->intval *= 1000;
			return 0;
		}

		ret = axp20x_read_variable_width(power->regmap,
						 AXP20X_VBUS_I_ADC_H, 12);
		if (ret < 0)
			return ret;

		val->intval = ret * 375; /* 1 step = 0.375 mA */
		return 0;
	default:
		break;
	}

	/* All the properties below need the input-status reg value */
	ret = regmap_read(power->regmap, AXP20X_PWR_INPUT_STATUS, &input);
	if (ret)
		return ret;

	switch (psp) {
	case POWER_SUPPLY_PROP_HEALTH:
		if (!(input & AXP20X_PWR_STATUS_VBUS_PRESENT)) {
			val->intval = POWER_SUPPLY_HEALTH_UNKNOWN;
			break;
		}

		val->intval = POWER_SUPPLY_HEALTH_GOOD;

		if (power->axp20x_id == AXP202_ID) {
			ret = regmap_read(power->regmap,
					  AXP20X_USB_OTG_STATUS, &v);
			if (ret)
				return ret;

			if (!(v & AXP20X_USB_STATUS_VBUS_VALID))
				val->intval =
					POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
		}
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = !!(input & AXP20X_PWR_STATUS_VBUS_PRESENT);
		break;
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = !!(input & AXP20X_PWR_STATUS_VBUS_USED);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int axp20x_usb_power_set_voltage_min(struct axp20x_usb_power *power,
					    int intval)
{
	int val;

	switch (intval) {
	case 4000000:
	case 4100000:
	case 4200000:
	case 4300000:
	case 4400000:
	case 4500000:
	case 4600000:
	case 4700000:
		val = (intval - 4000000) / 100000;
		return regmap_update_bits(power->regmap,
					  AXP20X_VBUS_IPSOUT_MGMT,
					  AXP20X_VBUS_VHOLD_MASK,
					  val << AXP20X_VBUS_VHOLD_OFFSET);
	default:
		return -EINVAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int axp20x_usb_power_set_current_max(struct axp20x_usb_power *power,
					    int intval)
{
	int val;

	switch (intval) {
	case 100000:
		if (power->axp20x_id == AXP221_ID)
			return -EINVAL;
		/* fall through */
	case 500000:
	case 900000:
		val = (900000 - intval) / 400000;
		return regmap_update_bits(power->regmap,
					  AXP20X_VBUS_IPSOUT_MGMT,
					  AXP20X_VBUS_CLIMIT_MASK, val);
	default:
		return -EINVAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int axp20x_usb_power_set_property(struct power_supply *psy,
					 enum power_supply_property psp,
					 const union power_supply_propval *val)
{
	struct axp20x_usb_power *power = power_supply_get_drvdata(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_VOLTAGE_MIN:
		return axp20x_usb_power_set_voltage_min(power, val->intval);

	case POWER_SUPPLY_PROP_CURRENT_MAX:
		return axp20x_usb_power_set_current_max(power, val->intval);

	default:
		return -EINVAL;
	}

	return -EINVAL;
}

__attribute__((used)) static int axp20x_usb_power_prop_writeable(struct power_supply *psy,
					   enum power_supply_property psp)
{
	return psp == POWER_SUPPLY_PROP_VOLTAGE_MIN ||
	       psp == POWER_SUPPLY_PROP_CURRENT_MAX;
}

__attribute__((used)) static int configure_iio_channels(struct platform_device *pdev,
				  struct axp20x_usb_power *power)
{
	power->vbus_v = devm_iio_channel_get(&pdev->dev, "vbus_v");
	if (IS_ERR(power->vbus_v)) {
		if (PTR_ERR(power->vbus_v) == -ENODEV)
			return -EPROBE_DEFER;
		return PTR_ERR(power->vbus_v);
	}

	power->vbus_i = devm_iio_channel_get(&pdev->dev, "vbus_i");
	if (IS_ERR(power->vbus_i)) {
		if (PTR_ERR(power->vbus_i) == -ENODEV)
			return -EPROBE_DEFER;
		return PTR_ERR(power->vbus_i);
	}

	return 0;
}

__attribute__((used)) static int configure_adc_registers(struct axp20x_usb_power *power)
{
	/* Enable vbus voltage and current measurement */
	return regmap_update_bits(power->regmap, AXP20X_ADC_EN1,
				  AXP20X_ADC_EN1_VBUS_CURR |
				  AXP20X_ADC_EN1_VBUS_VOLT,
				  AXP20X_ADC_EN1_VBUS_CURR |
				  AXP20X_ADC_EN1_VBUS_VOLT);
}

__attribute__((used)) static int axp20x_usb_power_probe(struct platform_device *pdev)
{
	struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
	struct power_supply_config psy_cfg = {};
	struct axp20x_usb_power *power;
	static const char * const axp20x_irq_names[] = { "VBUS_PLUGIN",
		"VBUS_REMOVAL", "VBUS_VALID", "VBUS_NOT_VALID", NULL };
	static const char * const axp22x_irq_names[] = {
		"VBUS_PLUGIN", "VBUS_REMOVAL", NULL };
	const char * const *irq_names;
	const struct power_supply_desc *usb_power_desc;
	int i, irq, ret;

	if (!of_device_is_available(pdev->dev.of_node))
		return -ENODEV;

	if (!axp20x) {
		dev_err(&pdev->dev, "Parent drvdata not set\n");
		return -EINVAL;
	}

	power = devm_kzalloc(&pdev->dev, sizeof(*power), GFP_KERNEL);
	if (!power)
		return -ENOMEM;

	power->axp20x_id = (enum axp20x_variants)of_device_get_match_data(
								&pdev->dev);

	power->np = pdev->dev.of_node;
	power->regmap = axp20x->regmap;

	if (power->axp20x_id == AXP202_ID) {
		/* Enable vbus valid checking */
		ret = regmap_update_bits(power->regmap, AXP20X_VBUS_MON,
					 AXP20X_VBUS_MON_VBUS_VALID,
					 AXP20X_VBUS_MON_VBUS_VALID);
		if (ret)
			return ret;

		if (IS_ENABLED(CONFIG_AXP20X_ADC))
			ret = configure_iio_channels(pdev, power);
		else
			ret = configure_adc_registers(power);

		if (ret)
			return ret;

		usb_power_desc = &axp20x_usb_power_desc;
		irq_names = axp20x_irq_names;
	} else if (power->axp20x_id == AXP221_ID ||
		   power->axp20x_id == AXP223_ID) {
		usb_power_desc = &axp22x_usb_power_desc;
		irq_names = axp22x_irq_names;
	} else {
		dev_err(&pdev->dev, "Unsupported AXP variant: %ld\n",
			axp20x->variant);
		return -EINVAL;
	}

	psy_cfg.of_node = pdev->dev.of_node;
	psy_cfg.drv_data = power;

	power->supply = devm_power_supply_register(&pdev->dev, usb_power_desc,
						   &psy_cfg);
	if (IS_ERR(power->supply))
		return PTR_ERR(power->supply);

	/* Request irqs after registering, as irqs may trigger immediately */
	for (i = 0; irq_names[i]; i++) {
		irq = platform_get_irq_byname(pdev, irq_names[i]);
		if (irq < 0) {
			dev_warn(&pdev->dev, "No IRQ for %s: %d\n",
				 irq_names[i], irq);
			continue;
		}
		irq = regmap_irq_get_virq(axp20x->regmap_irqc, irq);
		ret = devm_request_any_context_irq(&pdev->dev, irq,
				axp20x_usb_power_irq, 0, DRVNAME, power);
		if (ret < 0)
			dev_warn(&pdev->dev, "Error requesting %s IRQ: %d\n",
				 irq_names[i], ret);
	}

	return 0;
}

