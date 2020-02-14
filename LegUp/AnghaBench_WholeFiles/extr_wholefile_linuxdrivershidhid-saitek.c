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
typedef  int u8 ;
struct saitek_sc {unsigned long quirks; int mode; } ;
struct input_dev {int dummy; } ;
struct hid_usage {scalar_t__ type; int code; } ;
struct hid_report {int dummy; } ;
struct hid_field {TYPE_1__* hidinput; } ;
struct hid_device_id {unsigned long driver_data; } ;
struct hid_device {int /*<<< orphan*/  dev; } ;
typedef  int __u8 ;
typedef  scalar_t__ __s32 ;
struct TYPE_2__ {struct input_dev* input; } ;

/* Variables and functions */
 int BTN_MOUSE ; 
 int ENOMEM ; 
 scalar_t__ EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_CONNECT_DEFAULT ; 
 int SAITEK_FIX_PS1000 ; 
 int SAITEK_RELEASE_MODE_MMO7 ; 
 int SAITEK_RELEASE_MODE_RAT7 ; 
 struct saitek_sc* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_dbg (struct hid_device*,char*,int) ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 struct saitek_sc* hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_info (struct hid_device*,char*) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,struct saitek_sc*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int,int) ; 

__attribute__((used)) static int saitek_probe(struct hid_device *hdev,
		const struct hid_device_id *id)
{
	unsigned long quirks = id->driver_data;
	struct saitek_sc *ssc;
	int ret;

	ssc = devm_kzalloc(&hdev->dev, sizeof(*ssc), GFP_KERNEL);
	if (ssc == NULL) {
		hid_err(hdev, "can't alloc saitek descriptor\n");
		return -ENOMEM;
	}

	ssc->quirks = quirks;
	ssc->mode = -1;

	hid_set_drvdata(hdev, ssc);

	ret = hid_parse(hdev);
	if (ret) {
		hid_err(hdev, "parse failed\n");
		return ret;
	}

	ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
	if (ret) {
		hid_err(hdev, "hw start failed\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static __u8 *saitek_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	struct saitek_sc *ssc = hid_get_drvdata(hdev);

	if ((ssc->quirks & SAITEK_FIX_PS1000) && *rsize == 137 &&
			rdesc[20] == 0x09 && rdesc[21] == 0x33 &&
			rdesc[94] == 0x81 && rdesc[95] == 0x03 &&
			rdesc[110] == 0x81 && rdesc[111] == 0x03) {

		hid_info(hdev, "Fixing up Saitek PS1000 report descriptor\n");

		/* convert spurious axis to a "noop" Logical Minimum (0) */
		rdesc[20] = 0x15;
		rdesc[21] = 0x00;

		/* clear constant bit on buttons and d-pad */
		rdesc[95] = 0x02;
		rdesc[111] = 0x02;

	}
	return rdesc;
}

__attribute__((used)) static int saitek_raw_event(struct hid_device *hdev,
		struct hid_report *report, u8 *raw_data, int size)
{
	struct saitek_sc *ssc = hid_get_drvdata(hdev);

	if (ssc->quirks & SAITEK_RELEASE_MODE_RAT7 && size == 7) {
		/* R.A.T.7 uses bits 13, 14, 15 for the mode */
		int mode = -1;
		if (raw_data[1] & 0x01)
			mode = 0;
		else if (raw_data[1] & 0x02)
			mode = 1;
		else if (raw_data[1] & 0x04)
			mode = 2;

		/* clear mode bits */
		raw_data[1] &= ~0x07;

		if (mode != ssc->mode) {
			hid_dbg(hdev, "entered mode %d\n", mode);
			if (ssc->mode != -1) {
				/* use bit 13 as the mode button */
				raw_data[1] |= 0x04;
			}
			ssc->mode = mode;
		}
	} else if (ssc->quirks & SAITEK_RELEASE_MODE_MMO7 && size == 8) {

		/* M.M.O.7 uses bits 8, 22, 23 for the mode */
		int mode = -1;
		if (raw_data[1] & 0x80)
			mode = 0;
		else if (raw_data[2] & 0x01)
			mode = 1;
		else if (raw_data[2] & 0x02)
			mode = 2;

		/* clear mode bits */
		raw_data[1] &= ~0x80;
		raw_data[2] &= ~0x03;

		if (mode != ssc->mode) {
			hid_dbg(hdev, "entered mode %d\n", mode);
			if (ssc->mode != -1) {
				/* use bit 8 as the mode button, bits 22
				 * and 23 do not represent buttons
				 * according to the HID report descriptor
				 */
				raw_data[1] |= 0x80;
			}
			ssc->mode = mode;
		}
	}

	return 0;
}

__attribute__((used)) static int saitek_event(struct hid_device *hdev, struct hid_field *field,
		struct hid_usage *usage, __s32 value)
{
	struct saitek_sc *ssc = hid_get_drvdata(hdev);
	struct input_dev *input = field->hidinput->input;

	if (usage->type == EV_KEY && value &&
			(((ssc->quirks & SAITEK_RELEASE_MODE_RAT7) &&
			  usage->code - BTN_MOUSE == 10) ||
			((ssc->quirks & SAITEK_RELEASE_MODE_MMO7) &&
			 usage->code - BTN_MOUSE == 15))) {

		input_report_key(input, usage->code, 1);

		/* report missing release event */
		input_report_key(input, usage->code, 0);

		return 1;
	}

	return 0;
}

