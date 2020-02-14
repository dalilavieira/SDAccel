#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u16 ;
struct icade_key {scalar_t__ to; int /*<<< orphan*/  press; } ;
struct hid_usage {scalar_t__ type; size_t hid; } ;
struct hid_input {TYPE_2__* input; } ;
struct hid_field {TYPE_1__* hidinput; } ;
struct hid_device {int claimed; } ;
typedef  int /*<<< orphan*/  __s32 ;
struct TYPE_4__ {int /*<<< orphan*/  evbit; int /*<<< orphan*/  keybit; } ;
struct TYPE_3__ {int /*<<< orphan*/  input; } ;

/* Variables and functions */
 scalar_t__ EV_KEY ; 
 int HID_CLAIMED_INPUT ; 
 int HID_UP_KEYBOARD ; 
 size_t HID_USAGE ; 
 int HID_USAGE_PAGE ; 
 size_t ICADE_MAX_USAGE ; 
 int /*<<< orphan*/  hid_map_usage (struct hid_input*,struct hid_usage*,unsigned long**,int*,scalar_t__,scalar_t__) ; 
 struct icade_key const* icade_usage_table ; 
 int /*<<< orphan*/  input_event (int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static const struct icade_key *icade_find_translation(u16 from)
{
	if (from > ICADE_MAX_USAGE)
		return NULL;
	return &icade_usage_table[from];
}

__attribute__((used)) static int icade_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	const struct icade_key *trans;

	if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
			!usage->type)
		return 0;

	/* We ignore the fake key up, and act only on key down */
	if (!value)
		return 1;

	trans = icade_find_translation(usage->hid & HID_USAGE);

	if (!trans)
		return 1;

	input_event(field->hidinput->input, usage->type,
			trans->to, trans->press);

	return 1;
}

__attribute__((used)) static int icade_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	const struct icade_key *trans;

	if ((usage->hid & HID_USAGE_PAGE) == HID_UP_KEYBOARD) {
		trans = icade_find_translation(usage->hid & HID_USAGE);

		if (!trans)
			return -1;

		hid_map_usage(hi, usage, bit, max, EV_KEY, trans->to);
		set_bit(trans->to, hi->input->keybit);

		return 1;
	}

	/* ignore others */
	return -1;

}

__attribute__((used)) static int icade_input_mapped(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
	if (usage->type == EV_KEY)
		set_bit(usage->type, hi->input->evbit);

	return -1;
}

