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
typedef  int u8 ;
struct work_struct {int dummy; } ;
struct serio {int dummy; } ;
struct rfkill {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct dmi_system_id {TYPE_2__* driver_data; int /*<<< orphan*/  ident; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_3__ {int brightness; } ;
struct backlight_device {TYPE_1__ props; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_4__ {scalar_t__ ec_delay; scalar_t__ ec_read_only; scalar_t__ old_ec_model; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 double HZ ; 
 unsigned char I8042_STR_AUXDATA ; 
 int /*<<< orphan*/  KEY_TOUCHPAD_OFF ; 
 int /*<<< orphan*/  KEY_TOUCHPAD_ON ; 
 int /*<<< orphan*/  MSI_EC_COMMAND_LCD_LEVEL ; 
 int /*<<< orphan*/  MSI_EC_COMMAND_WIRELESS ; 
 int MSI_LCD_LEVEL_MAX ; 
 int MSI_STANDARD_EC_3G_MASK ; 
 int MSI_STANDARD_EC_AUTOFAN_MASK ; 
 int MSI_STANDARD_EC_BLUETOOTH_MASK ; 
 int /*<<< orphan*/  MSI_STANDARD_EC_COMMAND_ADDRESS ; 
 int /*<<< orphan*/  MSI_STANDARD_EC_DEVICES_EXISTS_ADDRESS ; 
 int MSI_STANDARD_EC_ECO_MASK ; 
 int /*<<< orphan*/  MSI_STANDARD_EC_FAN_ADDRESS ; 
 int /*<<< orphan*/  MSI_STANDARD_EC_FUNCTIONS_ADDRESS ; 
 int MSI_STANDARD_EC_TOUCHPAD_MASK ; 
 int MSI_STANDARD_EC_TURBO_COOLDOWN_MASK ; 
 int MSI_STANDARD_EC_TURBO_MASK ; 
 int MSI_STANDARD_EC_WLAN_MASK ; 
 int /*<<< orphan*/  RFKILL_TYPE_BLUETOOTH ; 
 int /*<<< orphan*/  RFKILL_TYPE_WLAN ; 
 int /*<<< orphan*/  RFKILL_TYPE_WWAN ; 
 int bluetooth_s ; 
 int ec_read (int /*<<< orphan*/ ,int*) ; 
 int ec_transaction (int /*<<< orphan*/ ,int*,int,int*,int) ; 
 int ec_write (int /*<<< orphan*/ ,int) ; 
 int min (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msi_laptop_input_dev ; 
 int /*<<< orphan*/  msi_rfkill_dwork ; 
 int /*<<< orphan*/  msi_rfkill_init ; 
 int /*<<< orphan*/  msi_rfkill_work ; 
 int /*<<< orphan*/  msi_touchpad_dwork ; 
 int /*<<< orphan*/  msi_touchpad_work ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ) ; 
 TYPE_2__* quirks ; 
 struct rfkill* rfk_bluetooth ; 
 struct rfkill* rfk_threeg ; 
 struct rfkill* rfk_wlan ; 
 struct rfkill* rfkill_alloc (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rfkill_bluetooth_ops ; 
 int /*<<< orphan*/  rfkill_destroy (struct rfkill*) ; 
 int rfkill_register (struct rfkill*) ; 
 int rfkill_set_hw_state (struct rfkill*,int) ; 
 int rfkill_set_sw_state (struct rfkill*,int) ; 
 int /*<<< orphan*/  rfkill_threeg_ops ; 
 int /*<<< orphan*/  rfkill_unregister (struct rfkill*) ; 
 int /*<<< orphan*/  rfkill_wlan_ops ; 
 int /*<<< orphan*/  round_jiffies_relative (int) ; 
 int /*<<< orphan*/  schedule_delayed_work (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sparse_keymap_report_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int sprintf (char*,char*,int) ; 
 int sscanf (char const*,char*,int*) ; 
 int threeg_exists ; 
 int threeg_s ; 
 scalar_t__ unlikely (int) ; 
 int wlan_s ; 

__attribute__((used)) static int set_lcd_level(int level)
{
	u8 buf[2];

	if (level < 0 || level >= MSI_LCD_LEVEL_MAX)
		return -EINVAL;

	buf[0] = 0x80;
	buf[1] = (u8) (level*31);

	return ec_transaction(MSI_EC_COMMAND_LCD_LEVEL, buf, sizeof(buf),
			      NULL, 0);
}

__attribute__((used)) static int get_lcd_level(void)
{
	u8 wdata = 0, rdata;
	int result;

	result = ec_transaction(MSI_EC_COMMAND_LCD_LEVEL, &wdata, 1,
				&rdata, 1);
	if (result < 0)
		return result;

	return (int) rdata / 31;
}

__attribute__((used)) static int get_auto_brightness(void)
{
	u8 wdata = 4, rdata;
	int result;

	result = ec_transaction(MSI_EC_COMMAND_LCD_LEVEL, &wdata, 1,
				&rdata, 1);
	if (result < 0)
		return result;

	return !!(rdata & 8);
}

__attribute__((used)) static int set_auto_brightness(int enable)
{
	u8 wdata[2], rdata;
	int result;

	wdata[0] = 4;

	result = ec_transaction(MSI_EC_COMMAND_LCD_LEVEL, wdata, 1,
				&rdata, 1);
	if (result < 0)
		return result;

	wdata[0] = 0x84;
	wdata[1] = (rdata & 0xF7) | (enable ? 8 : 0);

	return ec_transaction(MSI_EC_COMMAND_LCD_LEVEL, wdata, 2,
			      NULL, 0);
}

__attribute__((used)) static ssize_t set_device_state(const char *buf, size_t count, u8 mask)
{
	int status;
	u8 wdata = 0, rdata;
	int result;

	if (sscanf(buf, "%i", &status) != 1 || (status < 0 || status > 1))
		return -EINVAL;

	if (quirks->ec_read_only)
		return -EOPNOTSUPP;

	/* read current device state */
	result = ec_read(MSI_STANDARD_EC_COMMAND_ADDRESS, &rdata);
	if (result < 0)
		return result;

	if (!!(rdata & mask) != status) {
		/* reverse device bit */
		if (rdata & mask)
			wdata = rdata & ~mask;
		else
			wdata = rdata | mask;

		result = ec_write(MSI_STANDARD_EC_COMMAND_ADDRESS, wdata);
		if (result < 0)
			return result;
	}

	return count;
}

__attribute__((used)) static int get_wireless_state(int *wlan, int *bluetooth)
{
	u8 wdata = 0, rdata;
	int result;

	result = ec_transaction(MSI_EC_COMMAND_WIRELESS, &wdata, 1, &rdata, 1);
	if (result < 0)
		return result;

	if (wlan)
		*wlan = !!(rdata & 8);

	if (bluetooth)
		*bluetooth = !!(rdata & 128);

	return 0;
}

__attribute__((used)) static int get_wireless_state_ec_standard(void)
{
	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_COMMAND_ADDRESS, &rdata);
	if (result < 0)
		return result;

	wlan_s = !!(rdata & MSI_STANDARD_EC_WLAN_MASK);

	bluetooth_s = !!(rdata & MSI_STANDARD_EC_BLUETOOTH_MASK);

	threeg_s = !!(rdata & MSI_STANDARD_EC_3G_MASK);

	return 0;
}

__attribute__((used)) static int get_threeg_exists(void)
{
	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_DEVICES_EXISTS_ADDRESS, &rdata);
	if (result < 0)
		return result;

	threeg_exists = !!(rdata & MSI_STANDARD_EC_3G_MASK);

	return 0;
}

__attribute__((used)) static int bl_get_brightness(struct backlight_device *b)
{
	return get_lcd_level();
}

__attribute__((used)) static int bl_update_status(struct backlight_device *b)
{
	return set_lcd_level(b->props.brightness);
}

__attribute__((used)) static ssize_t show_wlan(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	int ret, enabled = 0;

	if (quirks->old_ec_model) {
		ret = get_wireless_state(&enabled, NULL);
	} else {
		ret = get_wireless_state_ec_standard();
		enabled = wlan_s;
	}
	if (ret < 0)
		return ret;

	return sprintf(buf, "%i\n", enabled);
}

__attribute__((used)) static ssize_t store_wlan(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return set_device_state(buf, count, MSI_STANDARD_EC_WLAN_MASK);
}

__attribute__((used)) static ssize_t show_bluetooth(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	int ret, enabled = 0;

	if (quirks->old_ec_model) {
		ret = get_wireless_state(NULL, &enabled);
	} else {
		ret = get_wireless_state_ec_standard();
		enabled = bluetooth_s;
	}
	if (ret < 0)
		return ret;

	return sprintf(buf, "%i\n", enabled);
}

__attribute__((used)) static ssize_t store_bluetooth(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return set_device_state(buf, count, MSI_STANDARD_EC_BLUETOOTH_MASK);
}

__attribute__((used)) static ssize_t show_threeg(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	int ret;

	/* old msi ec not support 3G */
	if (quirks->old_ec_model)
		return -ENODEV;

	ret = get_wireless_state_ec_standard();
	if (ret < 0)
		return ret;

	return sprintf(buf, "%i\n", threeg_s);
}

__attribute__((used)) static ssize_t store_threeg(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return set_device_state(buf, count, MSI_STANDARD_EC_3G_MASK);
}

__attribute__((used)) static ssize_t show_lcd_level(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	int ret;

	ret = get_lcd_level();
	if (ret < 0)
		return ret;

	return sprintf(buf, "%i\n", ret);
}

__attribute__((used)) static ssize_t store_lcd_level(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{

	int level, ret;

	if (sscanf(buf, "%i", &level) != 1 ||
	    (level < 0 || level >= MSI_LCD_LEVEL_MAX))
		return -EINVAL;

	ret = set_lcd_level(level);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t show_auto_brightness(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	int ret;

	ret = get_auto_brightness();
	if (ret < 0)
		return ret;

	return sprintf(buf, "%i\n", ret);
}

__attribute__((used)) static ssize_t store_auto_brightness(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{

	int enable, ret;

	if (sscanf(buf, "%i", &enable) != 1 || (enable != (enable & 1)))
		return -EINVAL;

	ret = set_auto_brightness(enable);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static ssize_t show_touchpad(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_FUNCTIONS_ADDRESS, &rdata);
	if (result < 0)
		return result;

	return sprintf(buf, "%i\n", !!(rdata & MSI_STANDARD_EC_TOUCHPAD_MASK));
}

__attribute__((used)) static ssize_t show_turbo(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_FUNCTIONS_ADDRESS, &rdata);
	if (result < 0)
		return result;

	return sprintf(buf, "%i\n", !!(rdata & MSI_STANDARD_EC_TURBO_MASK));
}

__attribute__((used)) static ssize_t show_eco(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_FUNCTIONS_ADDRESS, &rdata);
	if (result < 0)
		return result;

	return sprintf(buf, "%i\n", !!(rdata & MSI_STANDARD_EC_ECO_MASK));
}

__attribute__((used)) static ssize_t show_turbo_cooldown(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_FUNCTIONS_ADDRESS, &rdata);
	if (result < 0)
		return result;

	return sprintf(buf, "%i\n", (!!(rdata & MSI_STANDARD_EC_TURBO_MASK)) |
		(!!(rdata & MSI_STANDARD_EC_TURBO_COOLDOWN_MASK) << 1));
}

__attribute__((used)) static ssize_t show_auto_fan(struct device *dev,
	struct device_attribute *attr, char *buf)
{

	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_FAN_ADDRESS, &rdata);
	if (result < 0)
		return result;

	return sprintf(buf, "%i\n", !!(rdata & MSI_STANDARD_EC_AUTOFAN_MASK));
}

__attribute__((used)) static ssize_t store_auto_fan(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{

	int enable, result;

	if (sscanf(buf, "%i", &enable) != 1 || (enable != (enable & 1)))
		return -EINVAL;

	result = ec_write(MSI_STANDARD_EC_FAN_ADDRESS, enable);
	if (result < 0)
		return result;

	return count;
}

__attribute__((used)) static int dmi_check_cb(const struct dmi_system_id *dmi)
{
	pr_info("Identified laptop model '%s'\n", dmi->ident);

	quirks = dmi->driver_data;

	return 1;
}

__attribute__((used)) static int rfkill_bluetooth_set(void *data, bool blocked)
{
	/* Do something with blocked...*/
	/*
	 * blocked == false is on
	 * blocked == true is off
	 */
	int result = set_device_state(blocked ? "0" : "1", 0,
			MSI_STANDARD_EC_BLUETOOTH_MASK);

	return min(result, 0);
}

__attribute__((used)) static int rfkill_wlan_set(void *data, bool blocked)
{
	int result = set_device_state(blocked ? "0" : "1", 0,
			MSI_STANDARD_EC_WLAN_MASK);

	return min(result, 0);
}

__attribute__((used)) static int rfkill_threeg_set(void *data, bool blocked)
{
	int result = set_device_state(blocked ? "0" : "1", 0,
			MSI_STANDARD_EC_3G_MASK);

	return min(result, 0);
}

__attribute__((used)) static void rfkill_cleanup(void)
{
	if (rfk_bluetooth) {
		rfkill_unregister(rfk_bluetooth);
		rfkill_destroy(rfk_bluetooth);
	}

	if (rfk_threeg) {
		rfkill_unregister(rfk_threeg);
		rfkill_destroy(rfk_threeg);
	}

	if (rfk_wlan) {
		rfkill_unregister(rfk_wlan);
		rfkill_destroy(rfk_wlan);
	}
}

__attribute__((used)) static bool msi_rfkill_set_state(struct rfkill *rfkill, bool blocked)
{
	if (quirks->ec_read_only)
		return rfkill_set_hw_state(rfkill, blocked);
	else
		return rfkill_set_sw_state(rfkill, blocked);
}

__attribute__((used)) static void msi_update_rfkill(struct work_struct *ignored)
{
	get_wireless_state_ec_standard();

	if (rfk_wlan)
		msi_rfkill_set_state(rfk_wlan, !wlan_s);
	if (rfk_bluetooth)
		msi_rfkill_set_state(rfk_bluetooth, !bluetooth_s);
	if (rfk_threeg)
		msi_rfkill_set_state(rfk_threeg, !threeg_s);
}

__attribute__((used)) static void msi_send_touchpad_key(struct work_struct *ignored)
{
	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_FUNCTIONS_ADDRESS, &rdata);
	if (result < 0)
		return;

	sparse_keymap_report_event(msi_laptop_input_dev,
		(rdata & MSI_STANDARD_EC_TOUCHPAD_MASK) ?
		KEY_TOUCHPAD_ON : KEY_TOUCHPAD_OFF, 1, true);
}

__attribute__((used)) static bool msi_laptop_i8042_filter(unsigned char data, unsigned char str,
				struct serio *port)
{
	static bool extended;

	if (str & I8042_STR_AUXDATA)
		return false;

	/* 0x54 wwan, 0x62 bluetooth, 0x76 wlan, 0xE4 touchpad toggle*/
	if (unlikely(data == 0xe0)) {
		extended = true;
		return false;
	} else if (unlikely(extended)) {
		extended = false;
		switch (data) {
		case 0xE4:
			if (quirks->ec_delay) {
				schedule_delayed_work(&msi_touchpad_dwork,
					round_jiffies_relative(0.5 * HZ));
			} else
				schedule_work(&msi_touchpad_work);
			break;
		case 0x54:
		case 0x62:
		case 0x76:
			if (quirks->ec_delay) {
				schedule_delayed_work(&msi_rfkill_dwork,
					round_jiffies_relative(0.5 * HZ));
			} else
				schedule_work(&msi_rfkill_work);
			break;
		}
	}

	return false;
}

__attribute__((used)) static void msi_init_rfkill(struct work_struct *ignored)
{
	if (rfk_wlan) {
		rfkill_set_sw_state(rfk_wlan, !wlan_s);
		rfkill_wlan_set(NULL, !wlan_s);
	}
	if (rfk_bluetooth) {
		rfkill_set_sw_state(rfk_bluetooth, !bluetooth_s);
		rfkill_bluetooth_set(NULL, !bluetooth_s);
	}
	if (rfk_threeg) {
		rfkill_set_sw_state(rfk_threeg, !threeg_s);
		rfkill_threeg_set(NULL, !threeg_s);
	}
}

__attribute__((used)) static int rfkill_init(struct platform_device *sdev)
{
	/* add rfkill */
	int retval;

	/* keep the hardware wireless state */
	get_wireless_state_ec_standard();

	rfk_bluetooth = rfkill_alloc("msi-bluetooth", &sdev->dev,
				RFKILL_TYPE_BLUETOOTH,
				&rfkill_bluetooth_ops, NULL);
	if (!rfk_bluetooth) {
		retval = -ENOMEM;
		goto err_bluetooth;
	}
	retval = rfkill_register(rfk_bluetooth);
	if (retval)
		goto err_bluetooth;

	rfk_wlan = rfkill_alloc("msi-wlan", &sdev->dev, RFKILL_TYPE_WLAN,
				&rfkill_wlan_ops, NULL);
	if (!rfk_wlan) {
		retval = -ENOMEM;
		goto err_wlan;
	}
	retval = rfkill_register(rfk_wlan);
	if (retval)
		goto err_wlan;

	if (threeg_exists) {
		rfk_threeg = rfkill_alloc("msi-threeg", &sdev->dev,
				RFKILL_TYPE_WWAN, &rfkill_threeg_ops, NULL);
		if (!rfk_threeg) {
			retval = -ENOMEM;
			goto err_threeg;
		}
		retval = rfkill_register(rfk_threeg);
		if (retval)
			goto err_threeg;
	}

	/* schedule to run rfkill state initial */
	if (quirks->ec_delay) {
		schedule_delayed_work(&msi_rfkill_init,
			round_jiffies_relative(1 * HZ));
	} else
		schedule_work(&msi_rfkill_work);

	return 0;

err_threeg:
	rfkill_destroy(rfk_threeg);
	if (rfk_wlan)
		rfkill_unregister(rfk_wlan);
err_wlan:
	rfkill_destroy(rfk_wlan);
	if (rfk_bluetooth)
		rfkill_unregister(rfk_bluetooth);
err_bluetooth:
	rfkill_destroy(rfk_bluetooth);

	return retval;
}

