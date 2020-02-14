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
typedef  int __u8 ;

/* Variables and functions */
 int HID_UP_CONSUMER ; 
 int HID_USAGE ; 
 int HID_USAGE_PAGE ; 
 int /*<<< orphan*/  KEY_PROG1 ; 
 int /*<<< orphan*/  KEY_PROG2 ; 
 int /*<<< orphan*/  KEY_PROG3 ; 
 int /*<<< orphan*/  ch_map_key_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_info (struct hid_device*,char*) ; 

__attribute__((used)) static __u8 *ch_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	if (*rsize >= 18 && rdesc[11] == 0x3c && rdesc[12] == 0x02) {
		hid_info(hdev, "fixing up Cherry Cymotion report descriptor\n");
		rdesc[11] = rdesc[16] = 0xff;
		rdesc[12] = rdesc[17] = 0x03;
	}
	return rdesc;
}

__attribute__((used)) static int ch_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	if ((usage->hid & HID_USAGE_PAGE) != HID_UP_CONSUMER)
		return 0;

	switch (usage->hid & HID_USAGE) {
	case 0x301: ch_map_key_clear(KEY_PROG1);	break;
	case 0x302: ch_map_key_clear(KEY_PROG2);	break;
	case 0x303: ch_map_key_clear(KEY_PROG3);	break;
	default:
		return 0;
	}

	return 1;
}

