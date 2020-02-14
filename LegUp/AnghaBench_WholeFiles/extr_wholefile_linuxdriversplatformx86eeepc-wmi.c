#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct platform_device {int dummy; } ;
struct dmi_system_id {TYPE_1__* matches; TYPE_2__* driver_data; } ;
struct dmi_device {int /*<<< orphan*/  name; } ;
struct asus_wmi_driver {int /*<<< orphan*/  panel_power; TYPE_2__* quirks; } ;
struct TYPE_7__ {int wapf; int /*<<< orphan*/  hotplug_wireless; } ;
struct TYPE_6__ {scalar_t__ substr; } ;

/* Variables and functions */
 int ASUS_WMI_KEY_IGNORE ; 
 int /*<<< orphan*/  DMI_DEV_TYPE_OEM_STRING ; 
 int EBUSY ; 
 int /*<<< orphan*/  EEEPC_ACPI_HID ; 
 int /*<<< orphan*/  FB_BLANK_UNBLANK ; 
#define  HOME_HOLD 130 
#define  HOME_PRESS 129 
#define  HOME_RELEASE 128 
 scalar_t__ acpi_dev_found (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  asus_quirks ; 
 int /*<<< orphan*/  dmi_check_system (int /*<<< orphan*/ ) ; 
 struct dmi_device* dmi_find_device (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct dmi_device const*) ; 
 int /*<<< orphan*/  hotplug_wireless ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 TYPE_2__ quirk_asus_et2012_type1 ; 
 TYPE_2__ quirk_asus_et2012_type3 ; 
 TYPE_2__ quirk_asus_unknown ; 
 TYPE_2__* quirks ; 
 int sscanf (int /*<<< orphan*/ ,char*,char*) ; 
 scalar_t__ strncmp (char*,char*,int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static void et2012_quirks(void)
{
	const struct dmi_device *dev = NULL;
	char oemstring[30];

	while ((dev = dmi_find_device(DMI_DEV_TYPE_OEM_STRING, NULL, dev))) {
		if (sscanf(dev->name, "AEMS%24c", oemstring) == 1) {
			if (oemstring[18] == '1')
				quirks = &quirk_asus_et2012_type1;
			else if (oemstring[18] == '3')
				quirks = &quirk_asus_et2012_type3;
			break;
		}
	}
}

__attribute__((used)) static int dmi_matched(const struct dmi_system_id *dmi)
{
	char *model;

	quirks = dmi->driver_data;

	model = (char *)dmi->matches[1].substr;
	if (unlikely(strncmp(model, "ET2012", 6) == 0))
		et2012_quirks();

	return 1;
}

__attribute__((used)) static void eeepc_wmi_key_filter(struct asus_wmi_driver *asus_wmi, int *code,
				 unsigned int *value, bool *autorelease)
{
	switch (*code) {
	case HOME_PRESS:
		*value = 1;
		*autorelease = 0;
		break;
	case HOME_HOLD:
		*code = ASUS_WMI_KEY_IGNORE;
		break;
	case HOME_RELEASE:
		*code = HOME_PRESS;
		*value = 0;
		*autorelease = 0;
		break;
	}
}

__attribute__((used)) static int eeepc_wmi_probe(struct platform_device *pdev)
{
	if (acpi_dev_found(EEEPC_ACPI_HID)) {
		pr_warn("Found legacy ATKD device (%s)\n", EEEPC_ACPI_HID);
		pr_warn("WMI device present, but legacy ATKD device is also "
			"present and enabled\n");
		pr_warn("You probably booted with acpi_osi=\"Linux\" or "
			"acpi_osi=\"!Windows 2009\"\n");
		pr_warn("Can't load eeepc-wmi, use default acpi_osi "
			"(preferred) or eeepc-laptop\n");
		return -EBUSY;
	}
	return 0;
}

__attribute__((used)) static void eeepc_wmi_quirks(struct asus_wmi_driver *driver)
{
	quirks = &quirk_asus_unknown;
	quirks->hotplug_wireless = hotplug_wireless;

	dmi_check_system(asus_quirks);

	driver->quirks = quirks;
	driver->quirks->wapf = -1;
	driver->panel_power = FB_BLANK_UNBLANK;
}

