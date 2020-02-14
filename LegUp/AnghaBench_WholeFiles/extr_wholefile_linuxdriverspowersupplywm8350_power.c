#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int intval; } ;
typedef  int u16 ;
struct wm8350_power {void* usb; void* ac; void* battery; struct wm8350_charger_policy* policy; int /*<<< orphan*/  rev_g_coeff; } ;
struct wm8350_charger_policy {int fast_limit_USB_mA; int trickle_start_mV; int charge_mV; int trickle_charge_USB_mA; int charge_timeout; int fast_limit_mA; int trickle_charge_mA; int /*<<< orphan*/  eoc_mA; } ;
struct wm8350 {int irq_base; struct wm8350_power power; int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {struct device* parent; } ;
struct power_supply {TYPE_1__ dev; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (void*) ; 
 int POWER_SUPPLY_CHARGE_TYPE_FAST ; 
 int POWER_SUPPLY_CHARGE_TYPE_NONE ; 
 int POWER_SUPPLY_CHARGE_TYPE_TRICKLE ; 
 int POWER_SUPPLY_CHARGE_TYPE_UNKNOWN ; 
 int POWER_SUPPLY_HEALTH_COLD ; 
 int POWER_SUPPLY_HEALTH_GOOD ; 
 int POWER_SUPPLY_HEALTH_OVERHEAT ; 
 int POWER_SUPPLY_HEALTH_UNSPEC_FAILURE ; 
#define  POWER_SUPPLY_PROP_CHARGE_TYPE 148 
#define  POWER_SUPPLY_PROP_HEALTH 147 
#define  POWER_SUPPLY_PROP_ONLINE 146 
#define  POWER_SUPPLY_PROP_STATUS 145 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 144 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_UNKNOWN ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  WM8350_AUXADC_BATT ; 
 int /*<<< orphan*/  WM8350_AUXADC_LINE ; 
 int /*<<< orphan*/  WM8350_AUXADC_USB ; 
 int WM8350_AUX_COEFF ; 
 int /*<<< orphan*/  WM8350_BATTERY_CHARGER_CONTROL_1 ; 
 int /*<<< orphan*/  WM8350_BATTERY_CHARGER_CONTROL_2 ; 
 int WM8350_BATT_SUPPLY ; 
 int /*<<< orphan*/  WM8350_CHARGER_OVERRIDES ; 
 int WM8350_CHG_BATT_COLD_OVRDE ; 
 int WM8350_CHG_BATT_HOT_OVRDE ; 
 int /*<<< orphan*/  WM8350_CHG_ENA ; 
 int WM8350_CHG_ENA_R168 ; 
 int WM8350_CHG_EOC_mA (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WM8350_CHG_FAST ; 
 int WM8350_CHG_FAST_LIMIT_mA (int) ; 
 int WM8350_CHG_FAST_USB_THROTTLE ; 
 int WM8350_CHG_ISEL_MASK ; 
#define  WM8350_CHG_STS_FAST 143 
 int WM8350_CHG_STS_MASK ; 
#define  WM8350_CHG_STS_OFF 142 
#define  WM8350_CHG_STS_TRICKLE 141 
 int WM8350_CHG_TRICKLE_TEMP_CHOKE ; 
 int WM8350_CHG_TRICKLE_USB_CHOKE ; 
 int /*<<< orphan*/  WM8350_COMPARATOR_OVERRIDES ; 
#define  WM8350_IRQ_CHG_BAT_COLD 140 
#define  WM8350_IRQ_CHG_BAT_FAIL 139 
#define  WM8350_IRQ_CHG_BAT_HOT 138 
#define  WM8350_IRQ_CHG_END 137 
#define  WM8350_IRQ_CHG_FAST_RDY 136 
#define  WM8350_IRQ_CHG_START 135 
#define  WM8350_IRQ_CHG_TO 134 
#define  WM8350_IRQ_CHG_VBATT_LT_2P85 133 
#define  WM8350_IRQ_CHG_VBATT_LT_3P1 132 
#define  WM8350_IRQ_CHG_VBATT_LT_3P9 131 
#define  WM8350_IRQ_EXT_BAT_FB 130 
#define  WM8350_IRQ_EXT_USB_FB 129 
#define  WM8350_IRQ_EXT_WALL_FB 128 
 int WM8350_LINE_SUPPLY ; 
 int /*<<< orphan*/  WM8350_MISC_OVERRIDES ; 
 int /*<<< orphan*/  WM8350_POWER_MGMT_5 ; 
 int /*<<< orphan*/  WM8350_STATE_MACHINE_STATUS ; 
 int WM8350_USB_LIMIT_OVRDE ; 
 int WM8350_USB_SM_100_SLV ; 
 int WM8350_USB_SM_500_SLV ; 
 int WM8350_USB_SM_MASK ; 
 int WM8350_USB_SM_SHIFT ; 
 int WM8350_USB_SM_STDBY_SLV ; 
 int WM8350_USB_SUPPLY ; 
 int WM8350_WALL_FB_OVRDE ; 
 int /*<<< orphan*/  dev_attr_charger_state ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 struct wm8350* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,...) ; 
 int device_create_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct wm8350* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  power_supply_changed (void*) ; 
 void* power_supply_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  power_supply_unregister (void*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 
 int /*<<< orphan*/  wm8350_ac_desc ; 
 int /*<<< orphan*/  wm8350_battery_desc ; 
 int /*<<< orphan*/  wm8350_free_irq (struct wm8350*,int const,struct wm8350*) ; 
 int wm8350_read_auxadc (struct wm8350*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm8350_reg_lock (struct wm8350*) ; 
 int wm8350_reg_read (struct wm8350*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm8350_reg_unlock (struct wm8350*) ; 
 int /*<<< orphan*/  wm8350_reg_write (struct wm8350*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  wm8350_register_irq (struct wm8350*,int const,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct wm8350*) ; 
 int /*<<< orphan*/  wm8350_set_bits (struct wm8350*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm8350_usb_desc ; 

__attribute__((used)) static int wm8350_read_battery_uvolts(struct wm8350 *wm8350)
{
	return wm8350_read_auxadc(wm8350, WM8350_AUXADC_BATT, 0, 0)
		* WM8350_AUX_COEFF;
}

__attribute__((used)) static int wm8350_read_line_uvolts(struct wm8350 *wm8350)
{
	return wm8350_read_auxadc(wm8350, WM8350_AUXADC_LINE, 0, 0)
		* WM8350_AUX_COEFF;
}

__attribute__((used)) static int wm8350_read_usb_uvolts(struct wm8350 *wm8350)
{
	return wm8350_read_auxadc(wm8350, WM8350_AUXADC_USB, 0, 0)
		* WM8350_AUX_COEFF;
}

__attribute__((used)) static inline int wm8350_charge_time_min(struct wm8350 *wm8350, int min)
{
	if (!wm8350->power.rev_g_coeff)
		return (((min - 30) / 15) & 0xf) << 8;
	else
		return (((min - 30) / 30) & 0xf) << 8;
}

__attribute__((used)) static int wm8350_get_supplies(struct wm8350 *wm8350)
{
	u16 sm, ov, co, chrg;
	int supplies = 0;

	sm = wm8350_reg_read(wm8350, WM8350_STATE_MACHINE_STATUS);
	ov = wm8350_reg_read(wm8350, WM8350_MISC_OVERRIDES);
	co = wm8350_reg_read(wm8350, WM8350_COMPARATOR_OVERRIDES);
	chrg = wm8350_reg_read(wm8350, WM8350_BATTERY_CHARGER_CONTROL_2);

	/* USB_SM */
	sm = (sm & WM8350_USB_SM_MASK) >> WM8350_USB_SM_SHIFT;

	/* CHG_ISEL */
	chrg &= WM8350_CHG_ISEL_MASK;

	/* If the USB state machine is active then we're using that with or
	 * without battery, otherwise check for wall supply */
	if (((sm == WM8350_USB_SM_100_SLV) ||
	     (sm == WM8350_USB_SM_500_SLV) ||
	     (sm == WM8350_USB_SM_STDBY_SLV))
	    && !(ov & WM8350_USB_LIMIT_OVRDE))
		supplies = WM8350_USB_SUPPLY;
	else if (((sm == WM8350_USB_SM_100_SLV) ||
		  (sm == WM8350_USB_SM_500_SLV) ||
		  (sm == WM8350_USB_SM_STDBY_SLV))
		 && (ov & WM8350_USB_LIMIT_OVRDE) && (chrg == 0))
		supplies = WM8350_USB_SUPPLY | WM8350_BATT_SUPPLY;
	else if (co & WM8350_WALL_FB_OVRDE)
		supplies = WM8350_LINE_SUPPLY;
	else
		supplies = WM8350_BATT_SUPPLY;

	return supplies;
}

__attribute__((used)) static int wm8350_charger_config(struct wm8350 *wm8350,
				 struct wm8350_charger_policy *policy)
{
	u16 reg, eoc_mA, fast_limit_mA;

	if (!policy) {
		dev_warn(wm8350->dev,
			 "No charger policy, charger not configured.\n");
		return -EINVAL;
	}

	/* make sure USB fast charge current is not > 500mA */
	if (policy->fast_limit_USB_mA > 500) {
		dev_err(wm8350->dev, "USB fast charge > 500mA\n");
		return -EINVAL;
	}

	eoc_mA = WM8350_CHG_EOC_mA(policy->eoc_mA);

	wm8350_reg_unlock(wm8350);

	reg = wm8350_reg_read(wm8350, WM8350_BATTERY_CHARGER_CONTROL_1)
		& WM8350_CHG_ENA_R168;
	wm8350_reg_write(wm8350, WM8350_BATTERY_CHARGER_CONTROL_1,
			 reg | eoc_mA | policy->trickle_start_mV |
			 WM8350_CHG_TRICKLE_TEMP_CHOKE |
			 WM8350_CHG_TRICKLE_USB_CHOKE |
			 WM8350_CHG_FAST_USB_THROTTLE);

	if (wm8350_get_supplies(wm8350) & WM8350_USB_SUPPLY) {
		fast_limit_mA =
			WM8350_CHG_FAST_LIMIT_mA(policy->fast_limit_USB_mA);
		wm8350_reg_write(wm8350, WM8350_BATTERY_CHARGER_CONTROL_2,
			    policy->charge_mV | policy->trickle_charge_USB_mA |
			    fast_limit_mA | wm8350_charge_time_min(wm8350,
						policy->charge_timeout));

	} else {
		fast_limit_mA =
			WM8350_CHG_FAST_LIMIT_mA(policy->fast_limit_mA);
		wm8350_reg_write(wm8350, WM8350_BATTERY_CHARGER_CONTROL_2,
			    policy->charge_mV | policy->trickle_charge_mA |
			    fast_limit_mA | wm8350_charge_time_min(wm8350,
						policy->charge_timeout));
	}

	wm8350_reg_lock(wm8350);
	return 0;
}

__attribute__((used)) static int wm8350_batt_status(struct wm8350 *wm8350)
{
	u16 state;

	state = wm8350_reg_read(wm8350, WM8350_BATTERY_CHARGER_CONTROL_2);
	state &= WM8350_CHG_STS_MASK;

	switch (state) {
	case WM8350_CHG_STS_OFF:
		return POWER_SUPPLY_STATUS_DISCHARGING;

	case WM8350_CHG_STS_TRICKLE:
	case WM8350_CHG_STS_FAST:
		return POWER_SUPPLY_STATUS_CHARGING;

	default:
		return POWER_SUPPLY_STATUS_UNKNOWN;
	}
}

__attribute__((used)) static ssize_t charger_state_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	struct wm8350 *wm8350 = dev_get_drvdata(dev);
	char *charge;
	int state;

	state = wm8350_reg_read(wm8350, WM8350_BATTERY_CHARGER_CONTROL_2) &
	    WM8350_CHG_STS_MASK;
	switch (state) {
	case WM8350_CHG_STS_OFF:
		charge = "Charger Off";
		break;
	case WM8350_CHG_STS_TRICKLE:
		charge = "Trickle Charging";
		break;
	case WM8350_CHG_STS_FAST:
		charge = "Fast Charging";
		break;
	default:
		return 0;
	}

	return sprintf(buf, "%s\n", charge);
}

__attribute__((used)) static irqreturn_t wm8350_charger_handler(int irq, void *data)
{
	struct wm8350 *wm8350 = data;
	struct wm8350_power *power = &wm8350->power;
	struct wm8350_charger_policy *policy = power->policy;

	switch (irq - wm8350->irq_base) {
	case WM8350_IRQ_CHG_BAT_FAIL:
		dev_err(wm8350->dev, "battery failed\n");
		break;
	case WM8350_IRQ_CHG_TO:
		dev_err(wm8350->dev, "charger timeout\n");
		power_supply_changed(power->battery);
		break;

	case WM8350_IRQ_CHG_BAT_HOT:
	case WM8350_IRQ_CHG_BAT_COLD:
	case WM8350_IRQ_CHG_START:
	case WM8350_IRQ_CHG_END:
		power_supply_changed(power->battery);
		break;

	case WM8350_IRQ_CHG_FAST_RDY:
		dev_dbg(wm8350->dev, "fast charger ready\n");
		wm8350_charger_config(wm8350, policy);
		wm8350_reg_unlock(wm8350);
		wm8350_set_bits(wm8350, WM8350_BATTERY_CHARGER_CONTROL_1,
				WM8350_CHG_FAST);
		wm8350_reg_lock(wm8350);
		break;

	case WM8350_IRQ_CHG_VBATT_LT_3P9:
		dev_warn(wm8350->dev, "battery < 3.9V\n");
		break;
	case WM8350_IRQ_CHG_VBATT_LT_3P1:
		dev_warn(wm8350->dev, "battery < 3.1V\n");
		break;
	case WM8350_IRQ_CHG_VBATT_LT_2P85:
		dev_warn(wm8350->dev, "battery < 2.85V\n");
		break;

		/* Supply change.  We will overnotify but it should do
		 * no harm. */
	case WM8350_IRQ_EXT_USB_FB:
	case WM8350_IRQ_EXT_WALL_FB:
		wm8350_charger_config(wm8350, policy);
		/* Fall through */
	case WM8350_IRQ_EXT_BAT_FB:
		power_supply_changed(power->battery);
		power_supply_changed(power->usb);
		power_supply_changed(power->ac);
		break;

	default:
		dev_err(wm8350->dev, "Unknown interrupt %d\n", irq);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int wm8350_ac_get_prop(struct power_supply *psy,
			      enum power_supply_property psp,
			      union power_supply_propval *val)
{
	struct wm8350 *wm8350 = dev_get_drvdata(psy->dev.parent);
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = !!(wm8350_get_supplies(wm8350) &
				 WM8350_LINE_SUPPLY);
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		val->intval = wm8350_read_line_uvolts(wm8350);
		break;
	default:
		ret = -EINVAL;
		break;
	}
	return ret;
}

__attribute__((used)) static int wm8350_usb_get_prop(struct power_supply *psy,
			       enum power_supply_property psp,
			       union power_supply_propval *val)
{
	struct wm8350 *wm8350 = dev_get_drvdata(psy->dev.parent);
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = !!(wm8350_get_supplies(wm8350) &
				 WM8350_USB_SUPPLY);
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		val->intval = wm8350_read_usb_uvolts(wm8350);
		break;
	default:
		ret = -EINVAL;
		break;
	}
	return ret;
}

__attribute__((used)) static int wm8350_bat_check_health(struct wm8350 *wm8350)
{
	u16 reg;

	if (wm8350_read_battery_uvolts(wm8350) < 2850000)
		return POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;

	reg = wm8350_reg_read(wm8350, WM8350_CHARGER_OVERRIDES);
	if (reg & WM8350_CHG_BATT_HOT_OVRDE)
		return POWER_SUPPLY_HEALTH_OVERHEAT;

	if (reg & WM8350_CHG_BATT_COLD_OVRDE)
		return POWER_SUPPLY_HEALTH_COLD;

	return POWER_SUPPLY_HEALTH_GOOD;
}

__attribute__((used)) static int wm8350_bat_get_charge_type(struct wm8350 *wm8350)
{
	int state;

	state = wm8350_reg_read(wm8350, WM8350_BATTERY_CHARGER_CONTROL_2) &
	    WM8350_CHG_STS_MASK;
	switch (state) {
	case WM8350_CHG_STS_OFF:
		return POWER_SUPPLY_CHARGE_TYPE_NONE;
	case WM8350_CHG_STS_TRICKLE:
		return POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
	case WM8350_CHG_STS_FAST:
		return POWER_SUPPLY_CHARGE_TYPE_FAST;
	default:
		return POWER_SUPPLY_CHARGE_TYPE_UNKNOWN;
	}
}

__attribute__((used)) static int wm8350_bat_get_property(struct power_supply *psy,
				   enum power_supply_property psp,
				   union power_supply_propval *val)
{
	struct wm8350 *wm8350 = dev_get_drvdata(psy->dev.parent);
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		val->intval = wm8350_batt_status(wm8350);
		break;
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = !!(wm8350_get_supplies(wm8350) &
				 WM8350_BATT_SUPPLY);
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		val->intval = wm8350_read_battery_uvolts(wm8350);
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		val->intval = wm8350_bat_check_health(wm8350);
		break;
	case POWER_SUPPLY_PROP_CHARGE_TYPE:
		val->intval = wm8350_bat_get_charge_type(wm8350);
		break;
	default:
		ret = -EINVAL;
		break;
	}

	return ret;
}

__attribute__((used)) static void wm8350_init_charger(struct wm8350 *wm8350)
{
	/* register our interest in charger events */
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_BAT_HOT,
			    wm8350_charger_handler, 0, "Battery hot", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_BAT_COLD,
			    wm8350_charger_handler, 0, "Battery cold", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_BAT_FAIL,
			    wm8350_charger_handler, 0, "Battery fail", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_TO,
			    wm8350_charger_handler, 0,
			    "Charger timeout", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_END,
			    wm8350_charger_handler, 0,
			    "Charge end", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_START,
			    wm8350_charger_handler, 0,
			    "Charge start", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_FAST_RDY,
			    wm8350_charger_handler, 0,
			    "Fast charge ready", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_VBATT_LT_3P9,
			    wm8350_charger_handler, 0,
			    "Battery <3.9V", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_VBATT_LT_3P1,
			    wm8350_charger_handler, 0,
			    "Battery <3.1V", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_CHG_VBATT_LT_2P85,
			    wm8350_charger_handler, 0,
			    "Battery <2.85V", wm8350);

	/* and supply change events */
	wm8350_register_irq(wm8350, WM8350_IRQ_EXT_USB_FB,
			    wm8350_charger_handler, 0, "USB", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_EXT_WALL_FB,
			    wm8350_charger_handler, 0, "Wall", wm8350);
	wm8350_register_irq(wm8350, WM8350_IRQ_EXT_BAT_FB,
			    wm8350_charger_handler, 0, "Battery", wm8350);
}

__attribute__((used)) static void free_charger_irq(struct wm8350 *wm8350)
{
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_BAT_HOT, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_BAT_COLD, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_BAT_FAIL, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_TO, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_END, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_START, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_VBATT_LT_3P9, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_VBATT_LT_3P1, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_CHG_VBATT_LT_2P85, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_EXT_USB_FB, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_EXT_WALL_FB, wm8350);
	wm8350_free_irq(wm8350, WM8350_IRQ_EXT_BAT_FB, wm8350);
}

__attribute__((used)) static int wm8350_power_probe(struct platform_device *pdev)
{
	struct wm8350 *wm8350 = platform_get_drvdata(pdev);
	struct wm8350_power *power = &wm8350->power;
	struct wm8350_charger_policy *policy = power->policy;
	int ret;

	power->ac = power_supply_register(&pdev->dev, &wm8350_ac_desc, NULL);
	if (IS_ERR(power->ac))
		return PTR_ERR(power->ac);

	power->battery = power_supply_register(&pdev->dev, &wm8350_battery_desc,
					       NULL);
	if (IS_ERR(power->battery)) {
		ret = PTR_ERR(power->battery);
		goto battery_failed;
	}

	power->usb = power_supply_register(&pdev->dev, &wm8350_usb_desc, NULL);
	if (IS_ERR(power->usb)) {
		ret = PTR_ERR(power->usb);
		goto usb_failed;
	}

	ret = device_create_file(&pdev->dev, &dev_attr_charger_state);
	if (ret < 0)
		dev_warn(wm8350->dev, "failed to add charge sysfs: %d\n", ret);
	ret = 0;

	wm8350_init_charger(wm8350);
	if (wm8350_charger_config(wm8350, policy) == 0) {
		wm8350_reg_unlock(wm8350);
		wm8350_set_bits(wm8350, WM8350_POWER_MGMT_5, WM8350_CHG_ENA);
		wm8350_reg_lock(wm8350);
	}

	return ret;

usb_failed:
	power_supply_unregister(power->battery);
battery_failed:
	power_supply_unregister(power->ac);

	return ret;
}

__attribute__((used)) static int wm8350_power_remove(struct platform_device *pdev)
{
	struct wm8350 *wm8350 = platform_get_drvdata(pdev);
	struct wm8350_power *power = &wm8350->power;

	free_charger_irq(wm8350);
	device_remove_file(&pdev->dev, &dev_attr_charger_state);
	power_supply_unregister(power->battery);
	power_supply_unregister(power->ac);
	power_supply_unregister(power->usb);
	return 0;
}

