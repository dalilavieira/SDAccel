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
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct thermal_zone_device {int polling_delay; } ;
struct thermal_cooling_device {int polling_delay; TYPE_1__* governor; } ;
struct platform_device {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_7__ {int cmd_off; unsigned char cmd_auto; } ;
struct bios_settings {char* vendor; char* product; char* version; scalar_t__ mcmd_enable; int /*<<< orphan*/  fanreg; TYPE_2__ cmd; int /*<<< orphan*/  tempreg; } ;
typedef  enum thermal_trip_type { ____Placeholder_thermal_trip_type } thermal_trip_type ;
typedef  enum thermal_device_mode { ____Placeholder_thermal_device_mode } thermal_device_mode ;
struct TYPE_9__ {unsigned char moff; int /*<<< orphan*/  mreg; } ;
struct TYPE_8__ {int governor_name; } ;
struct TYPE_6__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ACERHDF_FAN_AUTO ; 
 int ACERHDF_FAN_OFF ; 
 int ACERHDF_MAX_FANON ; 
 int ACERHDF_MAX_INTERVAL ; 
 int ACERHDF_TEMP_CRIT ; 
 int /*<<< orphan*/  DMI_BIOS_VERSION ; 
 int /*<<< orphan*/  DMI_PRODUCT_NAME ; 
 int /*<<< orphan*/  DMI_SYS_VENDOR ; 
 int /*<<< orphan*/  DRV_VER ; 
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ IS_ERR (struct thermal_cooling_device*) ; 
 int THERMAL_DEVICE_DISABLED ; 
 int THERMAL_DEVICE_ENABLED ; 
 int /*<<< orphan*/  THERMAL_EVENT_UNSPECIFIED ; 
 int /*<<< orphan*/  THERMAL_NO_LIMIT ; 
 int THERMAL_TRIP_ACTIVE ; 
 int THERMAL_TRIP_CRITICAL ; 
 int /*<<< orphan*/  THERMAL_WEIGHT_DEFAULT ; 
 int /*<<< orphan*/  acerhdf_cooling_ops ; 
 int /*<<< orphan*/  acerhdf_dev ; 
 int /*<<< orphan*/  acerhdf_dev_ops ; 
 int /*<<< orphan*/  acerhdf_driver ; 
 TYPE_3__ acerhdf_zone_params ; 
 struct bios_settings const* bios_cfg ; 
 struct bios_settings* bios_tbl ; 
 struct thermal_cooling_device* cl_dev ; 
 char* dmi_get_system_info (int /*<<< orphan*/ ) ; 
 scalar_t__ ec_read (int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  ec_write (int /*<<< orphan*/ ,unsigned char) ; 
 int fanoff ; 
 int fanon ; 
 int fanstate ; 
 char* force_bios ; 
 char* force_product ; 
 int interval ; 
 int kernelmode ; 
 TYPE_4__ mcmd ; 
 int platform_device_add (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_alloc (char*,int) ; 
 int /*<<< orphan*/  platform_device_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_unregister (int /*<<< orphan*/ ) ; 
 int platform_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  platform_driver_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,char const*,...) ; 
 int /*<<< orphan*/  pr_notice (char*,...) ; 
 int prev_interval ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int) ; 
 unsigned long strlen (char const*) ; 
 int /*<<< orphan*/  strncmp (char const*,char const*,unsigned long) ; 
 struct thermal_cooling_device* thermal_cooling_device_register (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  thermal_cooling_device_unregister (struct thermal_cooling_device*) ; 
 scalar_t__ thermal_zone_bind_cooling_device (struct thermal_zone_device*,int /*<<< orphan*/ ,struct thermal_cooling_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct thermal_cooling_device* thermal_zone_device_register (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  thermal_zone_device_unregister (struct thermal_cooling_device*) ; 
 int /*<<< orphan*/  thermal_zone_device_update (struct thermal_cooling_device*,int /*<<< orphan*/ ) ; 
 scalar_t__ thermal_zone_unbind_cooling_device (struct thermal_zone_device*,int /*<<< orphan*/ ,struct thermal_cooling_device*) ; 
 struct thermal_cooling_device* thz_dev ; 
 scalar_t__ verbose ; 

__attribute__((used)) static int acerhdf_get_temp(int *temp)
{
	u8 read_temp;

	if (ec_read(bios_cfg->tempreg, &read_temp))
		return -EINVAL;

	*temp = read_temp * 1000;

	return 0;
}

__attribute__((used)) static int acerhdf_get_fanstate(int *state)
{
	u8 fan;

	if (ec_read(bios_cfg->fanreg, &fan))
		return -EINVAL;

	if (fan != bios_cfg->cmd.cmd_off)
		*state = ACERHDF_FAN_AUTO;
	else
		*state = ACERHDF_FAN_OFF;

	return 0;
}

__attribute__((used)) static void acerhdf_change_fanstate(int state)
{
	unsigned char cmd;

	if (verbose)
		pr_notice("fan %s\n", state == ACERHDF_FAN_OFF ? "OFF" : "ON");

	if ((state != ACERHDF_FAN_OFF) && (state != ACERHDF_FAN_AUTO)) {
		pr_err("invalid fan state %d requested, setting to auto!\n",
		       state);
		state = ACERHDF_FAN_AUTO;
	}

	cmd = (state == ACERHDF_FAN_OFF) ? bios_cfg->cmd.cmd_off
					 : bios_cfg->cmd.cmd_auto;
	fanstate = state;

	ec_write(bios_cfg->fanreg, cmd);

	if (bios_cfg->mcmd_enable && state == ACERHDF_FAN_OFF) {
		if (verbose)
			pr_notice("turning off fan manually\n");
		ec_write(mcmd.mreg, mcmd.moff);
	}
}

__attribute__((used)) static void acerhdf_check_param(struct thermal_zone_device *thermal)
{
	if (fanon > ACERHDF_MAX_FANON) {
		pr_err("fanon temperature too high, set to %d\n",
		       ACERHDF_MAX_FANON);
		fanon = ACERHDF_MAX_FANON;
	}

	if (kernelmode && prev_interval != interval) {
		if (interval > ACERHDF_MAX_INTERVAL) {
			pr_err("interval too high, set to %d\n",
			       ACERHDF_MAX_INTERVAL);
			interval = ACERHDF_MAX_INTERVAL;
		}
		if (verbose)
			pr_notice("interval changed to: %d\n", interval);
		thermal->polling_delay = interval*1000;
		prev_interval = interval;
	}
}

__attribute__((used)) static int acerhdf_get_ec_temp(struct thermal_zone_device *thermal, int *t)
{
	int temp, err = 0;

	acerhdf_check_param(thermal);

	err = acerhdf_get_temp(&temp);
	if (err)
		return err;

	if (verbose)
		pr_notice("temp %d\n", temp);

	*t = temp;
	return 0;
}

__attribute__((used)) static int acerhdf_bind(struct thermal_zone_device *thermal,
			struct thermal_cooling_device *cdev)
{
	/* if the cooling device is the one from acerhdf bind it */
	if (cdev != cl_dev)
		return 0;

	if (thermal_zone_bind_cooling_device(thermal, 0, cdev,
			THERMAL_NO_LIMIT, THERMAL_NO_LIMIT,
			THERMAL_WEIGHT_DEFAULT)) {
		pr_err("error binding cooling dev\n");
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static int acerhdf_unbind(struct thermal_zone_device *thermal,
			  struct thermal_cooling_device *cdev)
{
	if (cdev != cl_dev)
		return 0;

	if (thermal_zone_unbind_cooling_device(thermal, 0, cdev)) {
		pr_err("error unbinding cooling dev\n");
		return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static inline void acerhdf_revert_to_bios_mode(void)
{
	acerhdf_change_fanstate(ACERHDF_FAN_AUTO);
	kernelmode = 0;
	if (thz_dev)
		thz_dev->polling_delay = 0;
	pr_notice("kernel mode fan control OFF\n");
}

__attribute__((used)) static inline void acerhdf_enable_kernelmode(void)
{
	kernelmode = 1;

	thz_dev->polling_delay = interval*1000;
	thermal_zone_device_update(thz_dev, THERMAL_EVENT_UNSPECIFIED);
	pr_notice("kernel mode fan control ON\n");
}

__attribute__((used)) static int acerhdf_get_mode(struct thermal_zone_device *thermal,
			    enum thermal_device_mode *mode)
{
	if (verbose)
		pr_notice("kernel mode fan control %d\n", kernelmode);

	*mode = (kernelmode) ? THERMAL_DEVICE_ENABLED
			     : THERMAL_DEVICE_DISABLED;

	return 0;
}

__attribute__((used)) static int acerhdf_set_mode(struct thermal_zone_device *thermal,
			    enum thermal_device_mode mode)
{
	if (mode == THERMAL_DEVICE_DISABLED && kernelmode)
		acerhdf_revert_to_bios_mode();
	else if (mode == THERMAL_DEVICE_ENABLED && !kernelmode)
		acerhdf_enable_kernelmode();

	return 0;
}

__attribute__((used)) static int acerhdf_get_trip_type(struct thermal_zone_device *thermal, int trip,
				 enum thermal_trip_type *type)
{
	if (trip == 0)
		*type = THERMAL_TRIP_ACTIVE;
	else if (trip == 1)
		*type = THERMAL_TRIP_CRITICAL;
	else
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int acerhdf_get_trip_hyst(struct thermal_zone_device *thermal, int trip,
				 int *temp)
{
	if (trip != 0)
		return -EINVAL;

	*temp = fanon - fanoff;

	return 0;
}

__attribute__((used)) static int acerhdf_get_trip_temp(struct thermal_zone_device *thermal, int trip,
				 int *temp)
{
	if (trip == 0)
		*temp = fanon;
	else if (trip == 1)
		*temp = ACERHDF_TEMP_CRIT;
	else
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int acerhdf_get_crit_temp(struct thermal_zone_device *thermal,
				 int *temperature)
{
	*temperature = ACERHDF_TEMP_CRIT;
	return 0;
}

__attribute__((used)) static int acerhdf_get_max_state(struct thermal_cooling_device *cdev,
				 unsigned long *state)
{
	*state = 1;

	return 0;
}

__attribute__((used)) static int acerhdf_get_cur_state(struct thermal_cooling_device *cdev,
				 unsigned long *state)
{
	int err = 0, tmp;

	err = acerhdf_get_fanstate(&tmp);
	if (err)
		return err;

	*state = (tmp == ACERHDF_FAN_AUTO) ? 1 : 0;
	return 0;
}

__attribute__((used)) static int acerhdf_set_cur_state(struct thermal_cooling_device *cdev,
				 unsigned long state)
{
	int cur_temp, cur_state, err = 0;

	if (!kernelmode)
		return 0;

	err = acerhdf_get_temp(&cur_temp);
	if (err) {
		pr_err("error reading temperature, hand off control to BIOS\n");
		goto err_out;
	}

	err = acerhdf_get_fanstate(&cur_state);
	if (err) {
		pr_err("error reading fan state, hand off control to BIOS\n");
		goto err_out;
	}

	if (state == 0) {
		if (cur_state == ACERHDF_FAN_AUTO)
			acerhdf_change_fanstate(ACERHDF_FAN_OFF);
	} else {
		if (cur_state == ACERHDF_FAN_OFF)
			acerhdf_change_fanstate(ACERHDF_FAN_AUTO);
	}
	return 0;

err_out:
	acerhdf_revert_to_bios_mode();
	return -EINVAL;
}

__attribute__((used)) static int acerhdf_suspend(struct device *dev)
{
	if (kernelmode)
		acerhdf_change_fanstate(ACERHDF_FAN_AUTO);

	if (verbose)
		pr_notice("going suspend\n");

	return 0;
}

__attribute__((used)) static int acerhdf_probe(struct platform_device *device)
{
	return 0;
}

__attribute__((used)) static int acerhdf_remove(struct platform_device *device)
{
	return 0;
}

__attribute__((used)) static int str_starts_with(const char *str, const char *start)
{
	unsigned long str_len = 0, start_len = 0;

	str_len = strlen(str);
	start_len = strlen(start);

	if (str_len >= start_len &&
			!strncmp(str, start, start_len))
		return 1;

	return 0;
}

__attribute__((used)) static int acerhdf_check_hardware(void)
{
	char const *vendor, *version, *product;
	const struct bios_settings *bt = NULL;

	/* get BIOS data */
	vendor  = dmi_get_system_info(DMI_SYS_VENDOR);
	version = dmi_get_system_info(DMI_BIOS_VERSION);
	product = dmi_get_system_info(DMI_PRODUCT_NAME);

	if (!vendor || !version || !product) {
		pr_err("error getting hardware information\n");
		return -EINVAL;
	}

	pr_info("Acer Aspire One Fan driver, v.%s\n", DRV_VER);

	if (force_bios[0]) {
		version = force_bios;
		pr_info("forcing BIOS version: %s\n", version);
		kernelmode = 0;
	}

	if (force_product[0]) {
		product = force_product;
		pr_info("forcing BIOS product: %s\n", product);
		kernelmode = 0;
	}

	if (verbose)
		pr_info("BIOS info: %s %s, product: %s\n",
			vendor, version, product);

	/* search BIOS version and vendor in BIOS settings table */
	for (bt = bios_tbl; bt->vendor[0]; bt++) {
		/*
		 * check if actual hardware BIOS vendor, product and version
		 * IDs start with the strings of BIOS table entry
		 */
		if (str_starts_with(vendor, bt->vendor) &&
				str_starts_with(product, bt->product) &&
				str_starts_with(version, bt->version)) {
			bios_cfg = bt;
			break;
		}
	}

	if (!bios_cfg) {
		pr_err("unknown (unsupported) BIOS version %s/%s/%s, please report, aborting!\n",
		       vendor, product, version);
		return -EINVAL;
	}

	/*
	 * if started with kernel mode off, prevent the kernel from switching
	 * off the fan
	 */
	if (!kernelmode) {
		pr_notice("Fan control off, to enable do:\n");
		pr_notice("echo -n \"enabled\" > /sys/class/thermal/thermal_zone0/mode\n");
	}

	return 0;
}

__attribute__((used)) static int acerhdf_register_platform(void)
{
	int err = 0;

	err = platform_driver_register(&acerhdf_driver);
	if (err)
		return err;

	acerhdf_dev = platform_device_alloc("acerhdf", -1);
	if (!acerhdf_dev) {
		err = -ENOMEM;
		goto err_device_alloc;
	}
	err = platform_device_add(acerhdf_dev);
	if (err)
		goto err_device_add;

	return 0;

err_device_add:
	platform_device_put(acerhdf_dev);
err_device_alloc:
	platform_driver_unregister(&acerhdf_driver);
	return err;
}

__attribute__((used)) static void acerhdf_unregister_platform(void)
{
	platform_device_unregister(acerhdf_dev);
	platform_driver_unregister(&acerhdf_driver);
}

__attribute__((used)) static int acerhdf_register_thermal(void)
{
	cl_dev = thermal_cooling_device_register("acerhdf-fan", NULL,
						 &acerhdf_cooling_ops);

	if (IS_ERR(cl_dev))
		return -EINVAL;

	thz_dev = thermal_zone_device_register("acerhdf", 2, 0, NULL,
					      &acerhdf_dev_ops,
					      &acerhdf_zone_params, 0,
					      (kernelmode) ? interval*1000 : 0);
	if (IS_ERR(thz_dev))
		return -EINVAL;

	if (strcmp(thz_dev->governor->name,
				acerhdf_zone_params.governor_name)) {
		pr_err("Didn't get thermal governor %s, perhaps not compiled into thermal subsystem.\n",
				acerhdf_zone_params.governor_name);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static void acerhdf_unregister_thermal(void)
{
	if (cl_dev) {
		thermal_cooling_device_unregister(cl_dev);
		cl_dev = NULL;
	}

	if (thz_dev) {
		thermal_zone_device_unregister(thz_dev);
		thz_dev = NULL;
	}
}

