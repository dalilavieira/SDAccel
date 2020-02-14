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
struct input_dev {int dummy; } ;
struct hid_usage {scalar_t__ type; scalar_t__ code; int hid; } ;
struct hid_input {int dummy; } ;
struct hid_field {TYPE_1__* hidinput; } ;
struct hid_device_id {unsigned long driver_data; } ;
struct hid_device {int claimed; } ;
typedef  int __u8 ;
typedef  scalar_t__ __s32 ;
struct TYPE_2__ {struct input_dev* input; } ;

/* Variables and functions */
 unsigned long CP_2WHEEL_MOUSE_HACK ; 
 unsigned long CP_2WHEEL_MOUSE_HACK_ON ; 
 unsigned long CP_RDESC_SWAPPED_MIN_MAX ; 
 scalar_t__ EV_REL ; 
 int HID_CLAIMED_INPUT ; 
 int /*<<< orphan*/  HID_CONNECT_DEFAULT ; 
 int /*<<< orphan*/  REL_HWHEEL ; 
 scalar_t__ REL_WHEEL ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 scalar_t__ hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,void*) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  swap (int,int) ; 

__attribute__((used)) static __u8 *cp_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
	unsigned int i;

	if (!(quirks & CP_RDESC_SWAPPED_MIN_MAX))
		return rdesc;

	if (*rsize < 4)
		return rdesc;

	for (i = 0; i < *rsize - 4; i++)
		if (rdesc[i] == 0x29 && rdesc[i + 2] == 0x19) {
			rdesc[i] = 0x19;
			rdesc[i + 2] = 0x29;
			swap(rdesc[i + 3], rdesc[i + 1]);
		}
	return rdesc;
}

__attribute__((used)) static int cp_input_mapped(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);

	if (!(quirks & CP_2WHEEL_MOUSE_HACK))
		return 0;

	if (usage->type == EV_REL && usage->code == REL_WHEEL)
		set_bit(REL_HWHEEL, *bit);
	if (usage->hid == 0x00090005)
		return -1;

	return 0;
}

__attribute__((used)) static int cp_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);

	if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
			!usage->type || !(quirks & CP_2WHEEL_MOUSE_HACK))
		return 0;

	if (usage->hid == 0x00090005) {
		if (value)
			quirks |=  CP_2WHEEL_MOUSE_HACK_ON;
		else
			quirks &= ~CP_2WHEEL_MOUSE_HACK_ON;
		hid_set_drvdata(hdev, (void *)quirks);
		return 1;
	}

	if (usage->code == REL_WHEEL && (quirks & CP_2WHEEL_MOUSE_HACK_ON)) {
		struct input_dev *input = field->hidinput->input;

		input_event(input, usage->type, REL_HWHEEL, value);
		return 1;
	}

	return 0;
}

__attribute__((used)) static int cp_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
	unsigned long quirks = id->driver_data;
	int ret;

	hid_set_drvdata(hdev, (void *)quirks);

	ret = hid_parse(hdev);
	if (ret) {
		hid_err(hdev, "parse failed\n");
		goto err_free;
	}

	ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
	if (ret) {
		hid_err(hdev, "hw start failed\n");
		goto err_free;
	}

	return 0;
err_free:
	return ret;
}

