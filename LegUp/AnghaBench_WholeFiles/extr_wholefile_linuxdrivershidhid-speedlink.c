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
struct hid_usage {int hid; } ;
struct hid_input {int dummy; } ;
struct hid_field {int dummy; } ;
struct hid_device {int dummy; } ;
typedef  scalar_t__ __s32 ;

/* Variables and functions */
#define  HID_UP_LED 128 
 int HID_USAGE_PAGE ; 
 int abs (scalar_t__) ; 

__attribute__((used)) static int speedlink_input_mapping(struct hid_device *hdev,
		struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	/*
	 * The Cezanne mouse has a second "keyboard" USB endpoint for it is
	 * able to map keyboard events to the button presses.
	 * It sends a standard keyboard report descriptor, though, whose
	 * LEDs we ignore.
	 */
	switch (usage->hid & HID_USAGE_PAGE) {
	case HID_UP_LED:
		return -1;
	}
	return 0;
}

__attribute__((used)) static int speedlink_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	/* No other conditions due to usage_table. */

	/* This fixes the "jumpy" cursor occuring due to invalid events sent
	 * by the device. Some devices only send them with value==+256, others
	 * don't. However, catching abs(value)>=256 is restrictive enough not
	 * to interfere with devices that were bug-free (has been tested).
	 */
	if (abs(value) >= 256)
		return 1;
	/* Drop useless distance 0 events (on button clicks etc.) as well */
	if (value == 0)
		return 1;

	return 0;
}

