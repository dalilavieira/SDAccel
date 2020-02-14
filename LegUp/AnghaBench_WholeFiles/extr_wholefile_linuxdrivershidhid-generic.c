#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct hid_driver {int dummy; } ;
struct hid_device_id {int dummy; } ;
struct hid_device {int quirks; } ;
struct device_driver {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HID_CONNECT_DEFAULT ; 
 int HID_QUIRK_HAVE_SPECIAL_DRIVER ; 
 int HID_QUIRK_INPUT_PER_APP ; 
 scalar_t__ bus_for_each_drv (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct hid_device*,int (*) (struct device_driver*,void*)) ; 
 int /*<<< orphan*/  hid_bus_type ; 
 struct hid_driver hid_generic ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * hid_match_device (struct hid_device*,struct hid_driver*) ; 
 int hid_parse (struct hid_device*) ; 
 struct hid_driver* to_hid_driver (struct device_driver*) ; 

__attribute__((used)) static int __check_hid_generic(struct device_driver *drv, void *data)
{
	struct hid_driver *hdrv = to_hid_driver(drv);
	struct hid_device *hdev = data;

	if (hdrv == &hid_generic)
		return 0;

	return hid_match_device(hdev, hdrv) != NULL;
}

__attribute__((used)) static bool hid_generic_match(struct hid_device *hdev,
			      bool ignore_special_driver)
{
	if (ignore_special_driver)
		return true;

	if (hdev->quirks & HID_QUIRK_HAVE_SPECIAL_DRIVER)
		return false;

	/*
	 * If any other driver wants the device, leave the device to this other
	 * driver.
	 */
	if (bus_for_each_drv(&hid_bus_type, NULL, hdev, __check_hid_generic))
		return false;

	return true;
}

__attribute__((used)) static int hid_generic_probe(struct hid_device *hdev,
			     const struct hid_device_id *id)
{
	int ret;

	hdev->quirks |= HID_QUIRK_INPUT_PER_APP;

	ret = hid_parse(hdev);
	if (ret)
		return ret;

	return hid_hw_start(hdev, HID_CONNECT_DEFAULT);
}

