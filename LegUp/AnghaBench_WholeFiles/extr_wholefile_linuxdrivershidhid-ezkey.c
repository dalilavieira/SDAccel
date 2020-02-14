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
struct hid_usage {int hid; scalar_t__ type; scalar_t__ code; } ;
struct hid_input {int dummy; } ;
struct hid_field {TYPE_1__* hidinput; } ;
struct hid_device {int claimed; } ;
typedef  int /*<<< orphan*/  __s32 ;
struct TYPE_2__ {struct input_dev* input; } ;

/* Variables and functions */
 int /*<<< orphan*/  BTN_MOUSE ; 
 scalar_t__ EV_REL ; 
 int HID_CLAIMED_INPUT ; 
 int HID_UP_CONSUMER ; 
 int HID_USAGE ; 
 int HID_USAGE_PAGE ; 
 scalar_t__ REL_HWHEEL ; 
 scalar_t__ REL_WHEEL ; 
 int /*<<< orphan*/  ez_map_key (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ez_map_rel (scalar_t__) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ez_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER)
		return 0;

	switch (usage->hid & HID_USAGE) {
	case 0x230: ez_map_key(BTN_MOUSE);	break;
	case 0x231: ez_map_rel(REL_WHEEL);	break;
	/*
	 * this keyboard has a scrollwheel implemented in
	 * totally broken way. We map this usage temporarily
	 * to HWHEEL and handle it in the event quirk handler
	 */
	case 0x232: ez_map_rel(REL_HWHEEL);	break;
	default:
		return 0;
	}
	return 1;
}

__attribute__((used)) static int ez_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
			!usage->type)
		return 0;

	/* handle the temporary quirky mapping to HWHEEL */
	if (usage->type == EV_REL && usage->code == REL_HWHEEL) {
		struct input_dev *input = field->hidinput->input;
		input_event(input, usage->type, REL_WHEEL, -value);
		return 1;
	}

	return 0;
}

