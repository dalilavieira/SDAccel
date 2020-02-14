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
struct hid_usage {int hid; } ;
struct hid_input {int dummy; } ;
struct hid_field {unsigned long application; } ;
struct hid_device_id {int dummy; } ;
struct hid_device {unsigned long product; unsigned int maxcollection; TYPE_1__* collection; } ;
struct TYPE_2__ {unsigned long usage; } ;

/* Variables and functions */
 int /*<<< orphan*/  EV_KEY ; 
 int HID_CONNECT_DEFAULT ; 
 int HID_CONNECT_HIDDEV_FORCE ; 
 int HID_CONNECT_HIDINPUT_FORCE ; 
 unsigned long HID_GD_JOYSTICK ; 
 unsigned long HID_USAGE ; 
 unsigned long HID_USAGE_PAGE ; 
 unsigned short KEY_VOLUMEDOWN ; 
 unsigned short KEY_VOLUMEUP ; 
#define  PLT1_VOL_DOWN 132 
#define  PLT1_VOL_UP 131 
#define  PLT2_VOL_DOWN 130 
#define  PLT2_VOL_UP 129 
 scalar_t__ PLT_ALLOW_CONSUMER ; 
 unsigned long PLT_BASIC_EXCEPTION ; 
 unsigned long PLT_BASIC_TELEPHONY ; 
 unsigned long PLT_BT300_MAX ; 
 unsigned long PLT_BT300_MIN ; 
#define  PLT_DA60 128 
 unsigned int PLT_HID_1_0_PAGE ; 
 unsigned int PLT_HID_2_0_PAGE ; 
 int /*<<< orphan*/  hid_dbg (struct hid_device*,char*,unsigned long,...) ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 scalar_t__ hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,int) ; 
 int /*<<< orphan*/  hid_map_usage_clear (struct hid_input*,struct hid_usage*,unsigned long**,int*,int /*<<< orphan*/ ,unsigned short) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,void*) ; 

__attribute__((used)) static int plantronics_input_mapping(struct hid_device *hdev,
				     struct hid_input *hi,
				     struct hid_field *field,
				     struct hid_usage *usage,
				     unsigned long **bit, int *max)
{
	unsigned short mapped_key;
	unsigned long plt_type = (unsigned long)hid_get_drvdata(hdev);

	/* special case for PTT products */
	if (field->application == HID_GD_JOYSTICK)
		goto defaulted;

	/* handle volume up/down mapping */
	/* non-standard types or multi-HID interfaces - plt_type is PID */
	if (!(plt_type & HID_USAGE_PAGE)) {
		switch (plt_type) {
		case PLT_DA60:
			if (PLT_ALLOW_CONSUMER)
				goto defaulted;
			goto ignored;
		default:
			if (PLT_ALLOW_CONSUMER)
				goto defaulted;
		}
	}
	/* handle standard types - plt_type is 0xffa0uuuu or 0xffa2uuuu */
	/* 'basic telephony compliant' - allow default consumer page map */
	else if ((plt_type & HID_USAGE) >= PLT_BASIC_TELEPHONY &&
		 (plt_type & HID_USAGE) != PLT_BASIC_EXCEPTION) {
		if (PLT_ALLOW_CONSUMER)
			goto defaulted;
	}
	/* not 'basic telephony' - apply legacy mapping */
	/* only map if the field is in the device's primary vendor page */
	else if (!((field->application ^ plt_type) & HID_USAGE_PAGE)) {
		switch (usage->hid) {
		case PLT1_VOL_UP:
		case PLT2_VOL_UP:
			mapped_key = KEY_VOLUMEUP;
			goto mapped;
		case PLT1_VOL_DOWN:
		case PLT2_VOL_DOWN:
			mapped_key = KEY_VOLUMEDOWN;
			goto mapped;
		}
	}

/*
 * Future mapping of call control or other usages,
 * if and when keys are defined would go here
 * otherwise, ignore everything else that was not mapped
 */

ignored:
	return -1;

defaulted:
	hid_dbg(hdev, "usage: %08x (appl: %08x) - defaulted\n",
		usage->hid, field->application);
	return 0;

mapped:
	hid_map_usage_clear(hi, usage, bit, max, EV_KEY, mapped_key);
	hid_dbg(hdev, "usage: %08x (appl: %08x) - mapped to key %d\n",
		usage->hid, field->application, mapped_key);
	return 1;
}

__attribute__((used)) static unsigned long plantronics_device_type(struct hid_device *hdev)
{
	unsigned i, col_page;
	unsigned long plt_type = hdev->product;

	/* multi-HID interfaces? - plt_type is PID */
	if (plt_type >= PLT_BT300_MIN && plt_type <= PLT_BT300_MAX)
		goto exit;

	/* determine primary vendor page */
	for (i = 0; i < hdev->maxcollection; i++) {
		col_page = hdev->collection[i].usage & HID_USAGE_PAGE;
		if (col_page == PLT_HID_2_0_PAGE) {
			plt_type = hdev->collection[i].usage;
			break;
		}
		if (col_page == PLT_HID_1_0_PAGE)
			plt_type = hdev->collection[i].usage;
	}

exit:
	hid_dbg(hdev, "plt_type decoded as: %08lx\n", plt_type);
	return plt_type;
}

__attribute__((used)) static int plantronics_probe(struct hid_device *hdev,
			     const struct hid_device_id *id)
{
	int ret;

	ret = hid_parse(hdev);
	if (ret) {
		hid_err(hdev, "parse failed\n");
		goto err;
	}

	hid_set_drvdata(hdev, (void *)plantronics_device_type(hdev));

	ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT |
		HID_CONNECT_HIDINPUT_FORCE | HID_CONNECT_HIDDEV_FORCE);
	if (ret)
		hid_err(hdev, "hw start failed\n");

err:
	return ret;
}

