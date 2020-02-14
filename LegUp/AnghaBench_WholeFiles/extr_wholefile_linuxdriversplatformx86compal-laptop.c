#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
union power_supply_propval {int intval; unsigned long* strval; } ;
typedef  unsigned long u8 ;
typedef  int u16 ;
struct rfkill {int dummy; } ;
struct power_supply {int dummy; } ;
struct dmi_system_id {int /*<<< orphan*/  ident; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct compal_data {int pwm_enable; int curr_pwm; unsigned long* bat_model_name; unsigned long* bat_manufacturer_name; unsigned long* bat_serial_number; } ;
struct TYPE_3__ {int brightness; scalar_t__ power; int state; } ;
struct backlight_device {TYPE_1__ props; } ;
typedef  int ssize_t ;
typedef  int s8 ;
typedef  int s16 ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 unsigned long BACKLIGHT_LEVEL_ADDR ; 
 int BACKLIGHT_LEVEL_MAX ; 
 int /*<<< orphan*/  BACKLIGHT_STATE_ADDR ; 
 unsigned long BACKLIGHT_STATE_OFF_DATA ; 
 unsigned long BACKLIGHT_STATE_ON_DATA ; 
 unsigned long BAT_CAPACITY ; 
 unsigned long BAT_CHARGE_DESIGN ; 
 unsigned long BAT_CHARGE_LIMIT ; 
 int BAT_CHARGE_LIMIT_MAX ; 
 unsigned long BAT_CHARGE_NOW ; 
 unsigned long BAT_CURRENT_AVG ; 
 unsigned long BAT_CURRENT_NOW ; 
 unsigned long BAT_MANUFACTURER_NAME_ADDR ; 
 size_t BAT_MANUFACTURER_NAME_LEN ; 
 unsigned long BAT_MODEL_NAME_ADDR ; 
 size_t BAT_MODEL_NAME_LEN ; 
 unsigned long BAT_POWER ; 
 unsigned long BAT_S0_CHARGING ; 
 unsigned long BAT_S0_DISCHARGE ; 
 unsigned long BAT_S0_DISCHRG_CRITICAL ; 
 unsigned long BAT_S0_LOW ; 
 unsigned long BAT_S1_EMPTY ; 
 unsigned long BAT_S1_EXISTS ; 
 unsigned long BAT_S1_FULL ; 
 unsigned long BAT_S1_LiION_OR_NiMH ; 
 unsigned long BAT_S2_LOW_LOW ; 
 unsigned long BAT_SERIAL_NUMBER_ADDR ; 
 scalar_t__ BAT_SERIAL_NUMBER_LEN ; 
 unsigned long BAT_STATUS0 ; 
 unsigned long BAT_STATUS1 ; 
 unsigned long BAT_STATUS2 ; 
 unsigned long BAT_STOP_CHARGE1 ; 
 unsigned long BAT_STOP_CHRG1_BAD_CELL ; 
 unsigned long BAT_STOP_CHRG1_COMM_FAIL ; 
 unsigned long BAT_STOP_CHRG1_OVERTEMPERATURE ; 
 unsigned long BAT_STOP_CHRG1_OVERVOLTAGE ; 
 unsigned long BAT_TEMP ; 
 unsigned long BAT_TEMP_AVG ; 
 unsigned long BAT_VOLTAGE_DESIGN ; 
 unsigned long BAT_VOLTAGE_NOW ; 
 int BL_CORE_FBBLANK ; 
 int BL_CORE_SUSPENDED ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FAN_ADDRESS ; 
 unsigned long FAN_DATA ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL ; 
 int POWER_SUPPLY_CAPACITY_LEVEL_FULL ; 
 int POWER_SUPPLY_CAPACITY_LEVEL_LOW ; 
 int POWER_SUPPLY_CAPACITY_LEVEL_NORMAL ; 
 int POWER_SUPPLY_HEALTH_DEAD ; 
 int POWER_SUPPLY_HEALTH_GOOD ; 
 int POWER_SUPPLY_HEALTH_OVERHEAT ; 
 int POWER_SUPPLY_HEALTH_OVERVOLTAGE ; 
 int POWER_SUPPLY_HEALTH_UNKNOWN ; 
#define  POWER_SUPPLY_PROP_CAPACITY 147 
#define  POWER_SUPPLY_PROP_CAPACITY_LEVEL 146 
#define  POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT 145 
#define  POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT_MAX 144 
#define  POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN 143 
#define  POWER_SUPPLY_PROP_CHARGE_NOW 142 
#define  POWER_SUPPLY_PROP_CURRENT_AVG 141 
#define  POWER_SUPPLY_PROP_CURRENT_NOW 140 
#define  POWER_SUPPLY_PROP_HEALTH 139 
#define  POWER_SUPPLY_PROP_MANUFACTURER 138 
#define  POWER_SUPPLY_PROP_MODEL_NAME 137 
#define  POWER_SUPPLY_PROP_POWER_NOW 136 
#define  POWER_SUPPLY_PROP_PRESENT 135 
#define  POWER_SUPPLY_PROP_SERIAL_NUMBER 134 
#define  POWER_SUPPLY_PROP_STATUS 133 
#define  POWER_SUPPLY_PROP_TECHNOLOGY 132 
#define  POWER_SUPPLY_PROP_TEMP 131 
#define  POWER_SUPPLY_PROP_TEMP_AMBIENT 130 
#define  POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_NOW 128 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_FULL ; 
 int POWER_SUPPLY_STATUS_NOT_CHARGING ; 
 int POWER_SUPPLY_TECHNOLOGY_LION ; 
 int POWER_SUPPLY_TECHNOLOGY_NiMH ; 
 int /*<<< orphan*/  PWM_ADDRESS ; 
 int /*<<< orphan*/  PWM_DISABLE_ADDR ; 
 unsigned char PWM_DISABLE_DATA ; 
 int /*<<< orphan*/  PWM_ENABLE_ADDR ; 
 unsigned char PWM_ENABLE_DATA ; 
 int /*<<< orphan*/  RFKILL_TYPE_BLUETOOTH ; 
 int /*<<< orphan*/  RFKILL_TYPE_WLAN ; 
 unsigned long WIRELESS_ADDR ; 
 scalar_t__ WIRELESS_BT ; 
 unsigned long WIRELESS_KILLSWITCH ; 
 scalar_t__ WIRELESS_WLAN ; 
 int /*<<< orphan*/  bt_rfkill ; 
 TYPE_2__* compal_device ; 
 int /*<<< orphan*/  compal_rfkill_ops ; 
 struct compal_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  ec_read (unsigned long,unsigned long*) ; 
 int /*<<< orphan*/  ec_transaction (int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  ec_write (unsigned long,int) ; 
 int extra_features ; 
 int kstrtol (char const*,int,long*) ; 
 struct compal_data* power_supply_get_drvdata (struct power_supply*) ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ) ; 
 unsigned long* pwm_lookup_table ; 
 int /*<<< orphan*/  rfkill_alloc (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  rfkill_destroy (int /*<<< orphan*/ ) ; 
 int rfkill_register (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rfkill_set_hw_state (struct rfkill*,int) ; 
 int /*<<< orphan*/  rfkill_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  scnprintf (unsigned long*,scalar_t__,char*,int) ; 
 int sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  wifi_rfkill ; 

__attribute__((used)) static u8 ec_read_u8(u8 addr)
{
	u8 value;
	ec_read(addr, &value);
	return value;
}

__attribute__((used)) static s8 ec_read_s8(u8 addr)
{
	return (s8)ec_read_u8(addr);
}

__attribute__((used)) static u16 ec_read_u16(u8 addr)
{
	int hi, lo;
	lo = ec_read_u8(addr);
	hi = ec_read_u8(addr + 1);
	return (hi << 8) + lo;
}

__attribute__((used)) static s16 ec_read_s16(u8 addr)
{
	return (s16) ec_read_u16(addr);
}

__attribute__((used)) static void ec_read_sequence(u8 addr, u8 *buf, int len)
{
	int i;
	for (i = 0; i < len; i++)
		ec_read(addr + i, buf + i);
}

__attribute__((used)) static int set_backlight_level(int level)
{
	if (level < 0 || level > BACKLIGHT_LEVEL_MAX)
		return -EINVAL;

	ec_write(BACKLIGHT_LEVEL_ADDR, level);

	return 0;
}

__attribute__((used)) static int get_backlight_level(void)
{
	return (int) ec_read_u8(BACKLIGHT_LEVEL_ADDR);
}

__attribute__((used)) static void set_backlight_state(bool on)
{
	u8 data = on ? BACKLIGHT_STATE_ON_DATA : BACKLIGHT_STATE_OFF_DATA;
	ec_transaction(BACKLIGHT_STATE_ADDR, &data, 1, NULL, 0);
}

__attribute__((used)) static void pwm_enable_control(void)
{
	unsigned char writeData = PWM_ENABLE_DATA;
	ec_transaction(PWM_ENABLE_ADDR, &writeData, 1, NULL, 0);
}

__attribute__((used)) static void pwm_disable_control(void)
{
	unsigned char writeData = PWM_DISABLE_DATA;
	ec_transaction(PWM_DISABLE_ADDR, &writeData, 1, NULL, 0);
}

__attribute__((used)) static void set_pwm(int pwm)
{
	ec_transaction(PWM_ADDRESS, &pwm_lookup_table[pwm], 1, NULL, 0);
}

__attribute__((used)) static int get_fan_rpm(void)
{
	u8 value, data = FAN_DATA;
	ec_transaction(FAN_ADDRESS, &data, 1, &value, 1);
	return 100 * (int)value;
}

__attribute__((used)) static int bl_get_brightness(struct backlight_device *b)
{
	return get_backlight_level();
}

__attribute__((used)) static int bl_update_status(struct backlight_device *b)
{
	int ret = set_backlight_level(b->props.brightness);
	if (ret)
		return ret;

	set_backlight_state((b->props.power == FB_BLANK_UNBLANK)
		&&    !(b->props.state & BL_CORE_SUSPENDED)
		&&    !(b->props.state & BL_CORE_FBBLANK));
	return 0;
}

__attribute__((used)) static int compal_rfkill_set(void *data, bool blocked)
{
	unsigned long radio = (unsigned long) data;
	u8 result = ec_read_u8(WIRELESS_ADDR);
	u8 value;

	if (!blocked)
		value = (u8) (result | radio);
	else
		value = (u8) (result & ~radio);
	ec_write(WIRELESS_ADDR, value);

	return 0;
}

__attribute__((used)) static void compal_rfkill_poll(struct rfkill *rfkill, void *data)
{
	u8 result = ec_read_u8(WIRELESS_ADDR);
	bool hw_blocked = !(result & WIRELESS_KILLSWITCH);
	rfkill_set_hw_state(rfkill, hw_blocked);
}

__attribute__((used)) static ssize_t pwm_enable_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct compal_data *data = dev_get_drvdata(dev);
	return sprintf(buf, "%d\n", data->pwm_enable);
}

__attribute__((used)) static ssize_t pwm_enable_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct compal_data *data = dev_get_drvdata(dev);
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;
	if (val < 0)
		return -EINVAL;

	data->pwm_enable = val;

	switch (val) {
	case 0:  /* Full speed */
		pwm_enable_control();
		set_pwm(255);
		break;
	case 1:  /* As set by pwm1 */
		pwm_enable_control();
		set_pwm(data->curr_pwm);
		break;
	default: /* Control by motherboard */
		pwm_disable_control();
		break;
	}

	return count;
}

__attribute__((used)) static ssize_t pwm_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct compal_data *data = dev_get_drvdata(dev);
	return sprintf(buf, "%hhu\n", data->curr_pwm);
}

__attribute__((used)) static ssize_t pwm_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct compal_data *data = dev_get_drvdata(dev);
	long val;
	int err;

	err = kstrtol(buf, 10, &val);
	if (err)
		return err;
	if (val < 0 || val > 255)
		return -EINVAL;

	data->curr_pwm = val;

	if (data->pwm_enable != 1)
		return count;
	set_pwm(val);

	return count;
}

__attribute__((used)) static ssize_t fan_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	return sprintf(buf, "%d\n", get_fan_rpm());
}

__attribute__((used)) static int bat_status(void)
{
	u8 status0 = ec_read_u8(BAT_STATUS0);
	u8 status1 = ec_read_u8(BAT_STATUS1);

	if (status0 & BAT_S0_CHARGING)
		return POWER_SUPPLY_STATUS_CHARGING;
	if (status0 & BAT_S0_DISCHARGE)
		return POWER_SUPPLY_STATUS_DISCHARGING;
	if (status1 & BAT_S1_FULL)
		return POWER_SUPPLY_STATUS_FULL;
	return POWER_SUPPLY_STATUS_NOT_CHARGING;
}

__attribute__((used)) static int bat_health(void)
{
	u8 status = ec_read_u8(BAT_STOP_CHARGE1);

	if (status & BAT_STOP_CHRG1_OVERTEMPERATURE)
		return POWER_SUPPLY_HEALTH_OVERHEAT;
	if (status & BAT_STOP_CHRG1_OVERVOLTAGE)
		return POWER_SUPPLY_HEALTH_OVERVOLTAGE;
	if (status & BAT_STOP_CHRG1_BAD_CELL)
		return POWER_SUPPLY_HEALTH_DEAD;
	if (status & BAT_STOP_CHRG1_COMM_FAIL)
		return POWER_SUPPLY_HEALTH_UNKNOWN;
	return POWER_SUPPLY_HEALTH_GOOD;
}

__attribute__((used)) static int bat_is_present(void)
{
	u8 status = ec_read_u8(BAT_STATUS2);
	return ((status & BAT_S1_EXISTS) != 0);
}

__attribute__((used)) static int bat_technology(void)
{
	u8 status = ec_read_u8(BAT_STATUS1);

	if (status & BAT_S1_LiION_OR_NiMH)
		return POWER_SUPPLY_TECHNOLOGY_LION;
	return POWER_SUPPLY_TECHNOLOGY_NiMH;
}

__attribute__((used)) static int bat_capacity_level(void)
{
	u8 status0 = ec_read_u8(BAT_STATUS0);
	u8 status1 = ec_read_u8(BAT_STATUS1);
	u8 status2 = ec_read_u8(BAT_STATUS2);

	if (status0 & BAT_S0_DISCHRG_CRITICAL
			|| status1 & BAT_S1_EMPTY
			|| status2 & BAT_S2_LOW_LOW)
		return POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
	if (status0 & BAT_S0_LOW)
		return POWER_SUPPLY_CAPACITY_LEVEL_LOW;
	if (status1 & BAT_S1_FULL)
		return POWER_SUPPLY_CAPACITY_LEVEL_FULL;
	return POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
}

__attribute__((used)) static int bat_get_property(struct power_supply *psy,
				enum power_supply_property psp,
				union power_supply_propval *val)
{
	struct compal_data *data = power_supply_get_drvdata(psy);

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		val->intval = bat_status();
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		val->intval = bat_health();
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = bat_is_present();
		break;
	case POWER_SUPPLY_PROP_TECHNOLOGY:
		val->intval = bat_technology();
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN: /* THE design voltage... */
		val->intval = ec_read_u16(BAT_VOLTAGE_DESIGN) * 1000;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
		val->intval = ec_read_u16(BAT_VOLTAGE_NOW) * 1000;
		break;
	case POWER_SUPPLY_PROP_CURRENT_NOW:
		val->intval = ec_read_s16(BAT_CURRENT_NOW) * 1000;
		break;
	case POWER_SUPPLY_PROP_CURRENT_AVG:
		val->intval = ec_read_s16(BAT_CURRENT_AVG) * 1000;
		break;
	case POWER_SUPPLY_PROP_POWER_NOW:
		val->intval = ec_read_u8(BAT_POWER) * 1000000;
		break;
	case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
		val->intval = ec_read_u16(BAT_CHARGE_DESIGN) * 1000;
		break;
	case POWER_SUPPLY_PROP_CHARGE_NOW:
		val->intval = ec_read_u16(BAT_CHARGE_NOW) * 1000;
		break;
	case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT:
		val->intval = ec_read_u8(BAT_CHARGE_LIMIT);
		break;
	case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT_MAX:
		val->intval = BAT_CHARGE_LIMIT_MAX;
		break;
	case POWER_SUPPLY_PROP_CAPACITY:
		val->intval = ec_read_u8(BAT_CAPACITY);
		break;
	case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
		val->intval = bat_capacity_level();
		break;
	/* It smees that BAT_TEMP_AVG is a (2's complement?) value showing
	 * the number of degrees, whereas BAT_TEMP is somewhat more
	 * complicated. It looks like this is a negative nember with a
	 * 100/256 divider and an offset of 222. Both were determined
	 * experimentally by comparing BAT_TEMP and BAT_TEMP_AVG. */
	case POWER_SUPPLY_PROP_TEMP:
		val->intval = ((222 - (int)ec_read_u8(BAT_TEMP)) * 1000) >> 8;
		break;
	case POWER_SUPPLY_PROP_TEMP_AMBIENT: /* Ambient, Avg, ... same thing */
		val->intval = ec_read_s8(BAT_TEMP_AVG) * 10;
		break;
	/* Neither the model name nor manufacturer name work for me. */
	case POWER_SUPPLY_PROP_MODEL_NAME:
		val->strval = data->bat_model_name;
		break;
	case POWER_SUPPLY_PROP_MANUFACTURER:
		val->strval = data->bat_manufacturer_name;
		break;
	case POWER_SUPPLY_PROP_SERIAL_NUMBER:
		val->strval = data->bat_serial_number;
		break;
	default:
		break;
	}
	return 0;
}

__attribute__((used)) static int bat_set_property(struct power_supply *psy,
				enum power_supply_property psp,
				const union power_supply_propval *val)
{
	int level;

	switch (psp) {
	case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT:
		level = val->intval;
		if (level < 0 || level > BAT_CHARGE_LIMIT_MAX)
			return -EINVAL;
		if (ec_write(BAT_CHARGE_LIMIT, level) < 0)
			return -EIO;
		break;
	default:
		break;
	}
	return 0;
}

__attribute__((used)) static int bat_writeable_property(struct power_supply *psy,
				enum power_supply_property psp)
{
	switch (psp) {
	case POWER_SUPPLY_PROP_CHARGE_CONTROL_LIMIT:
		return 1;
	default:
		return 0;
	}
}

__attribute__((used)) static int dmi_check_cb(const struct dmi_system_id *id)
{
	pr_info("Identified laptop model '%s'\n", id->ident);
	extra_features = false;
	return 1;
}

__attribute__((used)) static int dmi_check_cb_extra(const struct dmi_system_id *id)
{
	pr_info("Identified laptop model '%s', enabling extra features\n",
		id->ident);
	extra_features = true;
	return 1;
}

__attribute__((used)) static void initialize_power_supply_data(struct compal_data *data)
{
	ec_read_sequence(BAT_MANUFACTURER_NAME_ADDR,
					data->bat_manufacturer_name,
					BAT_MANUFACTURER_NAME_LEN);
	data->bat_manufacturer_name[BAT_MANUFACTURER_NAME_LEN] = 0;

	ec_read_sequence(BAT_MODEL_NAME_ADDR,
					data->bat_model_name,
					BAT_MODEL_NAME_LEN);
	data->bat_model_name[BAT_MODEL_NAME_LEN] = 0;

	scnprintf(data->bat_serial_number, BAT_SERIAL_NUMBER_LEN + 1, "%d",
				ec_read_u16(BAT_SERIAL_NUMBER_ADDR));
}

__attribute__((used)) static void initialize_fan_control_data(struct compal_data *data)
{
	data->pwm_enable = 2; /* Keep motherboard in control for now */
	data->curr_pwm = 255; /* Try not to cause a CPU_on_fire exception
				 if we take over... */
}

__attribute__((used)) static int setup_rfkill(void)
{
	int ret;

	wifi_rfkill = rfkill_alloc("compal-wifi", &compal_device->dev,
				RFKILL_TYPE_WLAN, &compal_rfkill_ops,
				(void *) WIRELESS_WLAN);
	if (!wifi_rfkill)
		return -ENOMEM;

	ret = rfkill_register(wifi_rfkill);
	if (ret)
		goto err_wifi;

	bt_rfkill = rfkill_alloc("compal-bluetooth", &compal_device->dev,
				RFKILL_TYPE_BLUETOOTH, &compal_rfkill_ops,
				(void *) WIRELESS_BT);
	if (!bt_rfkill) {
		ret = -ENOMEM;
		goto err_allocate_bt;
	}
	ret = rfkill_register(bt_rfkill);
	if (ret)
		goto err_register_bt;

	return 0;

err_register_bt:
	rfkill_destroy(bt_rfkill);

err_allocate_bt:
	rfkill_unregister(wifi_rfkill);

err_wifi:
	rfkill_destroy(wifi_rfkill);

	return ret;
}

