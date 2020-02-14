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
typedef  scalar_t__ u16 ;
struct input_dev {int /*<<< orphan*/  evbit; int /*<<< orphan*/  keybit; int /*<<< orphan*/  led; } ;
struct hid_usage {scalar_t__ code; int hid; int /*<<< orphan*/  type; } ;
struct hid_input {struct input_dev* input; } ;
struct hid_field {TYPE_1__* hidinput; } ;
struct hid_device_id {unsigned long driver_data; } ;
struct hid_device {int product; scalar_t__ country; int claimed; int /*<<< orphan*/  dev; } ;
struct apple_sc {int fn_on; int quirks; int /*<<< orphan*/  pressed_numlock; int /*<<< orphan*/  pressed_fn; } ;
struct apple_key_translation {scalar_t__ from; int flags; scalar_t__ to; } ;
typedef  int __u8 ;
typedef  scalar_t__ __s32 ;
struct TYPE_2__ {struct input_dev* input; } ;

/* Variables and functions */
 int APPLE_FLAG_FKEY ; 
 int APPLE_HAS_FN ; 
 unsigned long APPLE_HIDDEV ; 
 unsigned long APPLE_IGNORE_HIDINPUT ; 
 int APPLE_INVERT_HWHEEL ; 
 int APPLE_MIGHTYMOUSE ; 
 int APPLE_NUMLOCK_EMULATION ; 
 int APPLE_RDESC_JIS ; 
 scalar_t__ BTN_1 ; 
 scalar_t__ BTN_2 ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  EV_REL ; 
 scalar_t__ EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HID_CLAIMED_INPUT ; 
 unsigned int HID_CONNECT_DEFAULT ; 
 unsigned int HID_CONNECT_HIDDEV_FORCE ; 
 unsigned int HID_CONNECT_HIDINPUT ; 
 scalar_t__ HID_COUNTRY_INTERNATIONAL_ISO ; 
 scalar_t__ HID_GD_Z ; 
 int HID_UP_CUSTOM ; 
 int HID_UP_MSVENDOR ; 
 scalar_t__ KEY_FN ; 
 scalar_t__ KEY_NUMLOCK ; 
 scalar_t__ LED_NUML ; 
 scalar_t__ REL_HWHEEL ; 
 int USB_DEVICE_ID_APPLE_WELLSPRING4A_JIS ; 
 int USB_DEVICE_ID_APPLE_WELLSPRING4_ANSI ; 
 struct apple_key_translation* apple_fn_keys ; 
 struct apple_key_translation* apple_iso_keyboard ; 
 int /*<<< orphan*/  clear_bit (scalar_t__,int /*<<< orphan*/ ) ; 
 struct apple_sc* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int fnmode ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 struct apple_sc* hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,unsigned int) ; 
 int /*<<< orphan*/  hid_info (struct hid_device*,char*) ; 
 int /*<<< orphan*/  hid_map_usage (struct hid_input*,struct hid_usage*,unsigned long**,int*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  hid_map_usage_clear (struct hid_input*,struct hid_usage*,unsigned long**,int*,int /*<<< orphan*/ ,scalar_t__) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,struct apple_sc*) ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 scalar_t__ iso_layout ; 
 struct apple_key_translation* macbookair_fn_keys ; 
 struct apple_key_translation* powerbook_fn_keys ; 
 struct apple_key_translation* powerbook_numlock_keys ; 
 int /*<<< orphan*/  set_bit (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ swap_opt_cmd ; 
 struct apple_key_translation* swapped_option_cmd_keys ; 
 scalar_t__ test_bit (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static const struct apple_key_translation *apple_find_translation(
		const struct apple_key_translation *table, u16 from)
{
	const struct apple_key_translation *trans;

	/* Look for the translation */
	for (trans = table; trans->from; trans++)
		if (trans->from == from)
			return trans;

	return NULL;
}

__attribute__((used)) static int hidinput_apple_event(struct hid_device *hid, struct input_dev *input,
		struct hid_usage *usage, __s32 value)
{
	struct apple_sc *asc = hid_get_drvdata(hid);
	const struct apple_key_translation *trans, *table;

	if (usage->code == KEY_FN) {
		asc->fn_on = !!value;
		input_event(input, usage->type, usage->code, value);
		return 1;
	}

	if (fnmode) {
		int do_translate;

		if (hid->product >= USB_DEVICE_ID_APPLE_WELLSPRING4_ANSI &&
				hid->product <= USB_DEVICE_ID_APPLE_WELLSPRING4A_JIS)
			table = macbookair_fn_keys;
		else if (hid->product < 0x21d || hid->product >= 0x300)
			table = powerbook_fn_keys;
		else
			table = apple_fn_keys;

		trans = apple_find_translation (table, usage->code);

		if (trans) {
			if (test_bit(usage->code, asc->pressed_fn))
				do_translate = 1;
			else if (trans->flags & APPLE_FLAG_FKEY)
				do_translate = (fnmode == 2 && asc->fn_on) ||
					(fnmode == 1 && !asc->fn_on);
			else
				do_translate = asc->fn_on;

			if (do_translate) {
				if (value)
					set_bit(usage->code, asc->pressed_fn);
				else
					clear_bit(usage->code, asc->pressed_fn);

				input_event(input, usage->type, trans->to,
						value);

				return 1;
			}
		}

		if (asc->quirks & APPLE_NUMLOCK_EMULATION &&
				(test_bit(usage->code, asc->pressed_numlock) ||
				test_bit(LED_NUML, input->led))) {
			trans = apple_find_translation(powerbook_numlock_keys,
					usage->code);

			if (trans) {
				if (value)
					set_bit(usage->code,
							asc->pressed_numlock);
				else
					clear_bit(usage->code,
							asc->pressed_numlock);

				input_event(input, usage->type, trans->to,
						value);
			}

			return 1;
		}
	}

	if (iso_layout) {
		if (hid->country == HID_COUNTRY_INTERNATIONAL_ISO) {
			trans = apple_find_translation(apple_iso_keyboard, usage->code);
			if (trans) {
				input_event(input, usage->type, trans->to, value);
				return 1;
			}
		}
	}

	if (swap_opt_cmd) {
		trans = apple_find_translation(swapped_option_cmd_keys, usage->code);
		if (trans) {
			input_event(input, usage->type, trans->to, value);
			return 1;
		}
	}

	return 0;
}

__attribute__((used)) static int apple_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	struct apple_sc *asc = hid_get_drvdata(hdev);

	if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
			!usage->type)
		return 0;

	if ((asc->quirks & APPLE_INVERT_HWHEEL) &&
			usage->code == REL_HWHEEL) {
		input_event(field->hidinput->input, usage->type, usage->code,
				-value);
		return 1;
	}

	if ((asc->quirks & APPLE_HAS_FN) &&
			hidinput_apple_event(hdev, field->hidinput->input,
				usage, value))
		return 1;


	return 0;
}

__attribute__((used)) static __u8 *apple_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	struct apple_sc *asc = hid_get_drvdata(hdev);

	if ((asc->quirks & APPLE_RDESC_JIS) && *rsize >= 60 &&
			rdesc[53] == 0x65 && rdesc[59] == 0x65) {
		hid_info(hdev,
			 "fixing up MacBook JIS keyboard report descriptor\n");
		rdesc[53] = rdesc[59] = 0xe7;
	}
	return rdesc;
}

__attribute__((used)) static void apple_setup_input(struct input_dev *input)
{
	const struct apple_key_translation *trans;

	set_bit(KEY_NUMLOCK, input->keybit);

	/* Enable all needed keys */
	for (trans = apple_fn_keys; trans->from; trans++)
		set_bit(trans->to, input->keybit);

	for (trans = powerbook_fn_keys; trans->from; trans++)
		set_bit(trans->to, input->keybit);

	for (trans = powerbook_numlock_keys; trans->from; trans++)
		set_bit(trans->to, input->keybit);

	for (trans = apple_iso_keyboard; trans->from; trans++)
		set_bit(trans->to, input->keybit);
}

__attribute__((used)) static int apple_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	if (usage->hid == (HID_UP_CUSTOM | 0x0003) ||
			usage->hid == (HID_UP_MSVENDOR | 0x0003)) {
		/* The fn key on Apple USB keyboards */
		set_bit(EV_REP, hi->input->evbit);
		hid_map_usage_clear(hi, usage, bit, max, EV_KEY, KEY_FN);
		apple_setup_input(hi->input);
		return 1;
	}

	/* we want the hid layer to go through standard path (set and ignore) */
	return 0;
}

__attribute__((used)) static int apple_input_mapped(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	struct apple_sc *asc = hid_get_drvdata(hdev);

	if (asc->quirks & APPLE_MIGHTYMOUSE) {
		if (usage->hid == HID_GD_Z)
			hid_map_usage(hi, usage, bit, max, EV_REL, REL_HWHEEL);
		else if (usage->code == BTN_1)
			hid_map_usage(hi, usage, bit, max, EV_KEY, BTN_2);
		else if (usage->code == BTN_2)
			hid_map_usage(hi, usage, bit, max, EV_KEY, BTN_1);
	}

	return 0;
}

__attribute__((used)) static int apple_probe(struct hid_device *hdev,
		const struct hid_device_id *id)
{
	unsigned long quirks = id->driver_data;
	struct apple_sc *asc;
	unsigned int connect_mask = HID_CONNECT_DEFAULT;
	int ret;

	asc = devm_kzalloc(&hdev->dev, sizeof(*asc), GFP_KERNEL);
	if (asc == NULL) {
		hid_err(hdev, "can't alloc apple descriptor\n");
		return -ENOMEM;
	}

	asc->quirks = quirks;

	hid_set_drvdata(hdev, asc);

	ret = hid_parse(hdev);
	if (ret) {
		hid_err(hdev, "parse failed\n");
		return ret;
	}

	if (quirks & APPLE_HIDDEV)
		connect_mask |= HID_CONNECT_HIDDEV_FORCE;
	if (quirks & APPLE_IGNORE_HIDINPUT)
		connect_mask &= ~HID_CONNECT_HIDINPUT;

	ret = hid_hw_start(hdev, connect_mask);
	if (ret) {
		hid_err(hdev, "hw start failed\n");
		return ret;
	}

	return 0;
}

