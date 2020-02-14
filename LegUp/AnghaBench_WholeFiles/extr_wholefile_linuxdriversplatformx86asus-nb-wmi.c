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
struct serio {int dummy; } ;
struct dmi_system_id {TYPE_1__* driver_data; int /*<<< orphan*/  ident; } ;
struct asus_wmi_driver {int /*<<< orphan*/  panel_power; TYPE_1__* quirks; } ;
struct TYPE_3__ {int wapf; scalar_t__ i8042_filter; } ;

/* Variables and functions */
 int /*<<< orphan*/  FB_BLANK_UNBLANK ; 
 unsigned char I8042_STR_AUXDATA ; 
 int /*<<< orphan*/  asus_quirks ; 
 int /*<<< orphan*/  dmi_check_system (int /*<<< orphan*/ ) ; 
 int i8042_install_filter (scalar_t__) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 TYPE_1__ quirk_asus_unknown ; 
 TYPE_1__* quirks ; 
 scalar_t__ unlikely (int) ; 
 int wapf ; 

__attribute__((used)) static bool asus_q500a_i8042_filter(unsigned char data, unsigned char str,
			      struct serio *port)
{
	static bool extended;
	bool ret = false;

	if (str & I8042_STR_AUXDATA)
		return false;

	if (unlikely(data == 0xe1)) {
		extended = true;
		ret = true;
	} else if (unlikely(extended)) {
		extended = false;
		ret = true;
	}

	return ret;
}

__attribute__((used)) static int dmi_matched(const struct dmi_system_id *dmi)
{
	pr_info("Identified laptop model '%s'\n", dmi->ident);
	quirks = dmi->driver_data;
	return 1;
}

__attribute__((used)) static void asus_nb_wmi_quirks(struct asus_wmi_driver *driver)
{
	int ret;

	quirks = &quirk_asus_unknown;
	dmi_check_system(asus_quirks);

	driver->quirks = quirks;
	driver->panel_power = FB_BLANK_UNBLANK;

	/* overwrite the wapf setting if the wapf paramater is specified */
	if (wapf != -1)
		quirks->wapf = wapf;
	else
		wapf = quirks->wapf;

	if (quirks->i8042_filter) {
		ret = i8042_install_filter(quirks->i8042_filter);
		if (ret) {
			pr_warn("Unable to install key filter\n");
			return;
		}
		pr_info("Using i8042 filter function for receiving events\n");
	}
}

