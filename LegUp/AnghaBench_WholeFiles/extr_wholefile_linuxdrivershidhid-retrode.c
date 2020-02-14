#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct hid_input {TYPE_3__* input; TYPE_1__* report; } ;
struct hid_field {TYPE_2__* report; } ;
struct hid_device_id {int dummy; } ;
struct hid_device {int /*<<< orphan*/  quirks; int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {char* name; } ;
struct TYPE_5__ {int id; } ;
struct TYPE_4__ {struct hid_field** field; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONTROLLER_NAME_BASE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_CONNECT_DEFAULT ; 
 int /*<<< orphan*/  HID_QUIRK_MULTI_INPUT ; 
 char* devm_kasprintf (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char const*,...) ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*,int) ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int hid_parse (struct hid_device*) ; 

__attribute__((used)) static int retrode_input_configured(struct hid_device *hdev,
					struct hid_input *hi)
{
	struct hid_field *field = hi->report->field[0];
	const char *suffix;
	int number = 0;
	char *name;

	switch (field->report->id) {
	case 0:
		suffix = "SNES Mouse";
		break;
	case 1:
	case 2:
		suffix = "SNES / N64";
		number = field->report->id;
		break;
	case 3:
	case 4:
		suffix = "Mega Drive";
		number = field->report->id - 2;
		break;
	default:
		hid_err(hdev, "Got unhandled report id %d\n", field->report->id);
		suffix = "Unknown";
	}

	if (number)
		name = devm_kasprintf(&hdev->dev, GFP_KERNEL,
				"%s %s #%d", CONTROLLER_NAME_BASE,
				suffix, number);
	else
		name = devm_kasprintf(&hdev->dev, GFP_KERNEL,
				"%s %s", CONTROLLER_NAME_BASE, suffix);

	if (!name)
		return -ENOMEM;

	hi->input->name = name;

	return 0;
}

__attribute__((used)) static int retrode_probe(struct hid_device *hdev,
			const struct hid_device_id *id)
{

	int ret;

	/* Has no effect on the mouse device */
	hdev->quirks |= HID_QUIRK_MULTI_INPUT;

	ret = hid_parse(hdev);
	if (ret)
		return ret;

	ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
	if (ret)
		return ret;

	return 0;
}

