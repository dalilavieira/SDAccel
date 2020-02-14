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
typedef  unsigned long u8 ;
struct TYPE_3__ {int brightness; int /*<<< orphan*/  power; } ;
struct rfkill {TYPE_1__ props; } ;
struct platform_device {int dummy; } ;
struct dmi_system_id {int /*<<< orphan*/  ident; } ;
struct backlight_properties {unsigned long max_brightness; int /*<<< orphan*/  type; } ;
struct backlight_device {TYPE_1__ props; } ;
typedef  enum rfkill_type { ____Placeholder_rfkill_type } rfkill_type ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_PLATFORM ; 
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EINVAL ; 
 int ENOMEM ; 
 struct rfkill* ERR_PTR (int) ; 
 int /*<<< orphan*/  FB_BLANK_UNBLANK ; 
 scalar_t__ IS_ERR (struct rfkill*) ; 
 int /*<<< orphan*/  OT_EC_BL_BRIGHTNESS_ADDRESS ; 
 unsigned long OT_EC_BL_BRIGHTNESS_MAX ; 
 int /*<<< orphan*/  OT_EC_BL_CONTROL_ADDRESS ; 
 unsigned long OT_EC_BL_CONTROL_ON_DATA ; 
 unsigned long OT_EC_BT_MASK ; 
 int /*<<< orphan*/  OT_EC_DEVICE_STATE_ADDRESS ; 
 unsigned long OT_EC_GPS_MASK ; 
 unsigned long OT_EC_WIFI_MASK ; 
 unsigned long OT_EC_WWAN_MASK ; 
 int PTR_ERR (struct rfkill*) ; 
 int RFKILL_TYPE_BLUETOOTH ; 
 int RFKILL_TYPE_GPS ; 
 int RFKILL_TYPE_WLAN ; 
 int RFKILL_TYPE_WWAN ; 
 struct rfkill* backlight_device_register (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int /*<<< orphan*/  backlight_device_unregister (struct rfkill*) ; 
 int /*<<< orphan*/  backlight_update_status (struct rfkill*) ; 
 struct rfkill* bt_rfkill ; 
 int /*<<< orphan*/  ec_read (int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  ec_write (int /*<<< orphan*/ ,unsigned long) ; 
 struct rfkill* gps_rfkill ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 struct rfkill* oaktrail_bl_device ; 
 int /*<<< orphan*/  oaktrail_bl_ops ; 
 TYPE_2__* oaktrail_device ; 
 int /*<<< orphan*/  oaktrail_rfkill_ops ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warning (char*) ; 
 struct rfkill* rfkill_alloc (char*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  rfkill_destroy (struct rfkill*) ; 
 int /*<<< orphan*/  rfkill_init_sw_state (struct rfkill*,int) ; 
 int rfkill_register (struct rfkill*) ; 
 int /*<<< orphan*/  rfkill_unregister (struct rfkill*) ; 
 struct rfkill* wifi_rfkill ; 
 struct rfkill* wwan_rfkill ; 

__attribute__((used)) static int oaktrail_rfkill_set(void *data, bool blocked)
{
	u8 value;
	u8 result;
	unsigned long radio = (unsigned long) data;

	ec_read(OT_EC_DEVICE_STATE_ADDRESS, &result);

	if (!blocked)
		value = (u8) (result | radio);
	else
		value = (u8) (result & ~radio);

	ec_write(OT_EC_DEVICE_STATE_ADDRESS, value);

	return 0;
}

__attribute__((used)) static struct rfkill *oaktrail_rfkill_new(char *name, enum rfkill_type type,
					  unsigned long mask)
{
	struct rfkill *rfkill_dev;
	u8 value;
	int err;

	rfkill_dev = rfkill_alloc(name, &oaktrail_device->dev, type,
				  &oaktrail_rfkill_ops, (void *)mask);
	if (!rfkill_dev)
		return ERR_PTR(-ENOMEM);

	ec_read(OT_EC_DEVICE_STATE_ADDRESS, &value);
	rfkill_init_sw_state(rfkill_dev, (value & mask) != 1);

	err = rfkill_register(rfkill_dev);
	if (err) {
		rfkill_destroy(rfkill_dev);
		return ERR_PTR(err);
	}

	return rfkill_dev;
}

__attribute__((used)) static inline void __oaktrail_rfkill_cleanup(struct rfkill *rf)
{
	if (rf) {
		rfkill_unregister(rf);
		rfkill_destroy(rf);
	}
}

__attribute__((used)) static void oaktrail_rfkill_cleanup(void)
{
	__oaktrail_rfkill_cleanup(wifi_rfkill);
	__oaktrail_rfkill_cleanup(bt_rfkill);
	__oaktrail_rfkill_cleanup(gps_rfkill);
	__oaktrail_rfkill_cleanup(wwan_rfkill);
}

__attribute__((used)) static int oaktrail_rfkill_init(void)
{
	int ret;

	wifi_rfkill = oaktrail_rfkill_new("oaktrail-wifi",
					  RFKILL_TYPE_WLAN,
					  OT_EC_WIFI_MASK);
	if (IS_ERR(wifi_rfkill)) {
		ret = PTR_ERR(wifi_rfkill);
		wifi_rfkill = NULL;
		goto cleanup;
	}

	bt_rfkill = oaktrail_rfkill_new("oaktrail-bluetooth",
					RFKILL_TYPE_BLUETOOTH,
					OT_EC_BT_MASK);
	if (IS_ERR(bt_rfkill)) {
		ret = PTR_ERR(bt_rfkill);
		bt_rfkill = NULL;
		goto cleanup;
	}

	gps_rfkill = oaktrail_rfkill_new("oaktrail-gps",
					 RFKILL_TYPE_GPS,
					 OT_EC_GPS_MASK);
	if (IS_ERR(gps_rfkill)) {
		ret = PTR_ERR(gps_rfkill);
		gps_rfkill = NULL;
		goto cleanup;
	}

	wwan_rfkill = oaktrail_rfkill_new("oaktrail-wwan",
					  RFKILL_TYPE_WWAN,
					  OT_EC_WWAN_MASK);
	if (IS_ERR(wwan_rfkill)) {
		ret = PTR_ERR(wwan_rfkill);
		wwan_rfkill = NULL;
		goto cleanup;
	}

	return 0;

cleanup:
	oaktrail_rfkill_cleanup();
	return ret;
}

__attribute__((used)) static int get_backlight_brightness(struct backlight_device *b)
{
	u8 value;
	ec_read(OT_EC_BL_BRIGHTNESS_ADDRESS, &value);

	return value;
}

__attribute__((used)) static int set_backlight_brightness(struct backlight_device *b)
{
	u8 percent = (u8) b->props.brightness;
	if (percent < 0 || percent > OT_EC_BL_BRIGHTNESS_MAX)
		return -EINVAL;

	ec_write(OT_EC_BL_BRIGHTNESS_ADDRESS, percent);
	ec_write(OT_EC_BL_CONTROL_ADDRESS, OT_EC_BL_CONTROL_ON_DATA);

	return 0;
}

__attribute__((used)) static int oaktrail_backlight_init(void)
{
	struct backlight_device *bd;
	struct backlight_properties props;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_PLATFORM;
	props.max_brightness = OT_EC_BL_BRIGHTNESS_MAX;
	bd = backlight_device_register(DRIVER_NAME,
				       &oaktrail_device->dev, NULL,
				       &oaktrail_bl_ops,
				       &props);

	if (IS_ERR(bd)) {
		oaktrail_bl_device = NULL;
		pr_warning("Unable to register backlight device\n");
		return PTR_ERR(bd);
	}

	oaktrail_bl_device = bd;

	bd->props.brightness = get_backlight_brightness(bd);
	bd->props.power = FB_BLANK_UNBLANK;
	backlight_update_status(bd);

	return 0;
}

__attribute__((used)) static void oaktrail_backlight_exit(void)
{
	backlight_device_unregister(oaktrail_bl_device);
}

__attribute__((used)) static int oaktrail_probe(struct platform_device *pdev)
{
	return 0;
}

__attribute__((used)) static int oaktrail_remove(struct platform_device *pdev)
{
	return 0;
}

__attribute__((used)) static int dmi_check_cb(const struct dmi_system_id *id)
{
	pr_info("Identified model '%s'\n", id->ident);
	return 0;
}

