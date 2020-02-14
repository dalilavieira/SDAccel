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
struct input_dev {int /*<<< orphan*/  evbit; int /*<<< orphan*/  keybit; } ;
struct hid_usage {int hid; int /*<<< orphan*/  type; int /*<<< orphan*/  code; } ;
struct hid_input {struct input_dev* input; } ;
struct hid_field {TYPE_1__* hidinput; } ;
struct hid_device_id {unsigned long driver_data; } ;
struct hid_device {int claimed; int /*<<< orphan*/  quirks; } ;
typedef  int __u8 ;
typedef  int __s32 ;
struct TYPE_2__ {struct input_dev* input; } ;

/* Variables and functions */
 int /*<<< orphan*/  EV_REL ; 
 unsigned int EV_REP ; 
 int HID_CLAIMED_INPUT ; 
 int HID_CONNECT_DEFAULT ; 
 int HID_CONNECT_HIDINPUT_FORCE ; 
#define  HID_GD_RFKILL_BTN 132 
#define  HID_GD_X 131 
#define  HID_GD_Y 130 
 int /*<<< orphan*/  HID_QUIRK_INPUT_PER_APP ; 
 int /*<<< orphan*/  HID_QUIRK_NOGET ; 
 int HID_UP_CONSUMER ; 
#define  HID_UP_DIGITIZER 129 
#define  HID_UP_GENDESK 128 
 int HID_UP_MSVENDOR ; 
 int HID_USAGE ; 
 int HID_USAGE_PAGE ; 
 unsigned int KEY_BACK ; 
 unsigned int KEY_CHAT ; 
 unsigned int KEY_CLOSE ; 
 unsigned int KEY_F13 ; 
 unsigned int KEY_F14 ; 
 unsigned int KEY_F15 ; 
 unsigned int KEY_F16 ; 
 unsigned int KEY_F17 ; 
 unsigned int KEY_F18 ; 
 unsigned int KEY_FORWARD ; 
 unsigned int KEY_KPEQUAL ; 
 unsigned int KEY_KPLEFTPAREN ; 
 unsigned int KEY_KPRIGHTPAREN ; 
 unsigned int KEY_PHONE ; 
 unsigned int KEY_PLAY ; 
 unsigned int KEY_PLAYPAUSE ; 
 unsigned int KEY_PROG1 ; 
 unsigned int KEY_PROG2 ; 
 unsigned long MS_DUPLICATE_USAGES ; 
 unsigned long MS_ERGONOMY ; 
 unsigned long MS_HIDINPUT ; 
 unsigned long MS_NOGET ; 
 unsigned long MS_PRESENTER ; 
 unsigned long MS_RDESC ; 
 unsigned long MS_SURFACE_DIAL ; 
 int /*<<< orphan*/  REL_WHEEL ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 scalar_t__ hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,int) ; 
 int /*<<< orphan*/  hid_info (struct hid_device*,char*) ; 
 int /*<<< orphan*/  hid_map_usage_clear (struct hid_input*,struct hid_usage*,unsigned long**,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,void*) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,unsigned int,int) ; 
 int /*<<< orphan*/  input_report_rel (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ms_map_key_clear (unsigned int) ; 
 int /*<<< orphan*/  set_bit (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __u8 *ms_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);

	/*
	 * Microsoft Wireless Desktop Receiver (Model 1028) has
	 * 'Usage Min/Max' where it ought to have 'Physical Min/Max'
	 */
	if ((quirks & MS_RDESC) && *rsize == 571 && rdesc[557] == 0x19 &&
			rdesc[559] == 0x29) {
		hid_info(hdev, "fixing up Microsoft Wireless Receiver Model 1028 report descriptor\n");
		rdesc[557] = 0x35;
		rdesc[559] = 0x45;
	}
	return rdesc;
}

__attribute__((used)) static int ms_ergonomy_kb_quirk(struct hid_input *hi, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	struct input_dev *input = hi->input;

	if ((usage->hid & HID_USAGE_PAGE) == HID_UP_CONSUMER) {
		switch (usage->hid & HID_USAGE) {
		/*
		 * Microsoft uses these 2 reserved usage ids for 2 keys on
		 * the MS office kb labelled "Office Home" and "Task Pane".
		 */
		case 0x29d:
			ms_map_key_clear(KEY_PROG1);
			return 1;
		case 0x29e:
			ms_map_key_clear(KEY_PROG2);
			return 1;
		}
		return 0;
	}

	if ((usage->hid & HID_USAGE_PAGE) != HID_UP_MSVENDOR)
		return 0;

	switch (usage->hid & HID_USAGE) {
	case 0xfd06: ms_map_key_clear(KEY_CHAT);	break;
	case 0xfd07: ms_map_key_clear(KEY_PHONE);	break;
	case 0xff00:
		/* Special keypad keys */
		ms_map_key_clear(KEY_KPEQUAL);
		set_bit(KEY_KPLEFTPAREN, input->keybit);
		set_bit(KEY_KPRIGHTPAREN, input->keybit);
		break;
	case 0xff01:
		/* Scroll wheel */
		hid_map_usage_clear(hi, usage, bit, max, EV_REL, REL_WHEEL);
		break;
	case 0xff02:
		/*
		 * This byte contains a copy of the modifier keys byte of a
		 * standard hid keyboard report, as send by interface 0
		 * (this usage is found on interface 1).
		 *
		 * This byte only gets send when another key in the same report
		 * changes state, and as such is useless, ignore it.
		 */
		return -1;
	case 0xff05:
		set_bit(EV_REP, input->evbit);
		ms_map_key_clear(KEY_F13);
		set_bit(KEY_F14, input->keybit);
		set_bit(KEY_F15, input->keybit);
		set_bit(KEY_F16, input->keybit);
		set_bit(KEY_F17, input->keybit);
		set_bit(KEY_F18, input->keybit);
		break;
	default:
		return 0;
	}
	return 1;
}

__attribute__((used)) static int ms_presenter_8k_quirk(struct hid_input *hi, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	if ((usage->hid & HID_USAGE_PAGE) != HID_UP_MSVENDOR)
		return 0;

	set_bit(EV_REP, hi->input->evbit);
	switch (usage->hid & HID_USAGE) {
	case 0xfd08: ms_map_key_clear(KEY_FORWARD);	break;
	case 0xfd09: ms_map_key_clear(KEY_BACK);	break;
	case 0xfd0b: ms_map_key_clear(KEY_PLAYPAUSE);	break;
	case 0xfd0e: ms_map_key_clear(KEY_CLOSE);	break;
	case 0xfd0f: ms_map_key_clear(KEY_PLAY);	break;
	default:
		return 0;
	}
	return 1;
}

__attribute__((used)) static int ms_surface_dial_quirk(struct hid_input *hi, struct hid_field *field,
		struct hid_usage *usage, unsigned long **bit, int *max)
{
	switch (usage->hid & HID_USAGE_PAGE) {
	case 0xff070000:
		/* fall-through */
	case HID_UP_DIGITIZER:
		/* ignore those axis */
		return -1;
	case HID_UP_GENDESK:
		switch (usage->hid) {
		case HID_GD_X:
			/* fall-through */
		case HID_GD_Y:
			/* fall-through */
		case HID_GD_RFKILL_BTN:
			/* ignore those axis */
			return -1;
		}
	}

	return 0;
}

__attribute__((used)) static int ms_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);

	if (quirks & MS_ERGONOMY) {
		int ret = ms_ergonomy_kb_quirk(hi, usage, bit, max);
		if (ret)
			return ret;
	}

	if ((quirks & MS_PRESENTER) &&
			ms_presenter_8k_quirk(hi, usage, bit, max))
		return 1;

	if (quirks & MS_SURFACE_DIAL) {
		int ret = ms_surface_dial_quirk(hi, field, usage, bit, max);

		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int ms_input_mapped(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);

	if (quirks & MS_DUPLICATE_USAGES)
		clear_bit(usage->code, *bit);

	return 0;
}

__attribute__((used)) static int ms_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	unsigned long quirks = (unsigned long)hid_get_drvdata(hdev);
	struct input_dev *input;

	if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
			!usage->type)
		return 0;

	input = field->hidinput->input;

	/* Handling MS keyboards special buttons */
	if (quirks & MS_ERGONOMY && usage->hid == (HID_UP_MSVENDOR | 0xff00)) {
		/* Special keypad keys */
		input_report_key(input, KEY_KPEQUAL, value & 0x01);
		input_report_key(input, KEY_KPLEFTPAREN, value & 0x02);
		input_report_key(input, KEY_KPRIGHTPAREN, value & 0x04);
		return 1;
	}

	if (quirks & MS_ERGONOMY && usage->hid == (HID_UP_MSVENDOR | 0xff01)) {
		/* Scroll wheel */
		int step = ((value & 0x60) >> 5) + 1;

		switch (value & 0x1f) {
		case 0x01:
			input_report_rel(input, REL_WHEEL, step);
			break;
		case 0x1f:
			input_report_rel(input, REL_WHEEL, -step);
			break;
		}
		return 1;
	}

	if (quirks & MS_ERGONOMY && usage->hid == (HID_UP_MSVENDOR | 0xff05)) {
		static unsigned int last_key = 0;
		unsigned int key = 0;
		switch (value) {
		case 0x01: key = KEY_F14; break;
		case 0x02: key = KEY_F15; break;
		case 0x04: key = KEY_F16; break;
		case 0x08: key = KEY_F17; break;
		case 0x10: key = KEY_F18; break;
		}
		if (key) {
			input_event(input, usage->type, key, 1);
			last_key = key;
		} else
			input_event(input, usage->type, last_key, 0);

		return 1;
	}

	return 0;
}

__attribute__((used)) static int ms_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
	unsigned long quirks = id->driver_data;
	int ret;

	hid_set_drvdata(hdev, (void *)quirks);

	if (quirks & MS_NOGET)
		hdev->quirks |= HID_QUIRK_NOGET;

	if (quirks & MS_SURFACE_DIAL)
		hdev->quirks |= HID_QUIRK_INPUT_PER_APP;

	ret = hid_parse(hdev);
	if (ret) {
		hid_err(hdev, "parse failed\n");
		goto err_free;
	}

	ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT | ((quirks & MS_HIDINPUT) ?
				HID_CONNECT_HIDINPUT_FORCE : 0));
	if (ret) {
		hid_err(hdev, "hw start failed\n");
		goto err_free;
	}

	return 0;
err_free:
	return ret;
}

