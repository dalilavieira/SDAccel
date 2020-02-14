#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int value; } ;
struct TYPE_5__ {int /*<<< orphan*/  length; } ;
union acpi_object {scalar_t__ type; TYPE_3__ integer; TYPE_1__ buffer; } ;
typedef  int /*<<< orphan*/  u32 ;
struct key_entry {int code; scalar_t__ type; int keycode; } ;
struct TYPE_6__ {int brightness; } ;
struct backlight_device {TYPE_2__ props; } ;
struct acpi_buffer {int member_0; int* member_1; union acpi_object* pointer; } ;
typedef  int /*<<< orphan*/  ktime_t ;
typedef  scalar_t__ acpi_status ;
struct TYPE_8__ {scalar_t__ quirk_last_pressed; } ;

/* Variables and functions */
 int ACPI_ALLOCATE_BUFFER ; 
 scalar_t__ ACPI_SUCCESS (scalar_t__) ; 
 scalar_t__ ACPI_TYPE_BUFFER ; 
 scalar_t__ ACPI_TYPE_INTEGER ; 
 scalar_t__ AE_OK ; 
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 scalar_t__ KE_KEY ; 
 int /*<<< orphan*/  MSIWMI_BIOS_GUID ; 
 int MSI_KEY_BRIGHTNESSDOWN ; 
 int MSI_KEY_BRIGHTNESSUP ; 
 scalar_t__ backlight ; 
 int* backlight_map ; 
 TYPE_4__* event_wmi ; 
 int /*<<< orphan*/  kfree (union acpi_object*) ; 
 int /*<<< orphan*/  ktime_get_real () ; 
 int /*<<< orphan*/  ktime_sub (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ktime_to_us (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  last_pressed ; 
 int /*<<< orphan*/  msi_wmi_input_dev ; 
 int /*<<< orphan*/  pr_debug (char*,int,...) ; 
 int /*<<< orphan*/  pr_err (char*,int,...) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 struct key_entry* sparse_keymap_entry_from_scancode (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sparse_keymap_report_entry (int /*<<< orphan*/ ,struct key_entry*,int,int) ; 
 scalar_t__ wmi_get_event_data (int /*<<< orphan*/ ,struct acpi_buffer*) ; 
 scalar_t__ wmi_query_block (int /*<<< orphan*/ ,int,struct acpi_buffer*) ; 
 scalar_t__ wmi_set_block (int /*<<< orphan*/ ,int,struct acpi_buffer*) ; 

__attribute__((used)) static int msi_wmi_query_block(int instance, int *ret)
{
	acpi_status status;
	union acpi_object *obj;

	struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };

	status = wmi_query_block(MSIWMI_BIOS_GUID, instance, &output);

	obj = output.pointer;

	if (!obj || obj->type != ACPI_TYPE_INTEGER) {
		if (obj) {
			pr_err("query block returned object "
			       "type: %d - buffer length:%d\n", obj->type,
			       obj->type == ACPI_TYPE_BUFFER ?
			       obj->buffer.length : 0);
		}
		kfree(obj);
		return -EINVAL;
	}
	*ret = obj->integer.value;
	kfree(obj);
	return 0;
}

__attribute__((used)) static int msi_wmi_set_block(int instance, int value)
{
	acpi_status status;

	struct acpi_buffer input = { sizeof(int), &value };

	pr_debug("Going to set block of instance: %d - value: %d\n",
		 instance, value);

	status = wmi_set_block(MSIWMI_BIOS_GUID, instance, &input);

	return ACPI_SUCCESS(status) ? 0 : 1;
}

__attribute__((used)) static int bl_get(struct backlight_device *bd)
{
	int level, err, ret;

	/* Instance 1 is "get backlight", cmp with DSDT */
	err = msi_wmi_query_block(1, &ret);
	if (err) {
		pr_err("Could not query backlight: %d\n", err);
		return -EINVAL;
	}
	pr_debug("Get: Query block returned: %d\n", ret);
	for (level = 0; level < ARRAY_SIZE(backlight_map); level++) {
		if (backlight_map[level] == ret) {
			pr_debug("Current backlight level: 0x%X - index: %d\n",
				 backlight_map[level], level);
			break;
		}
	}
	if (level == ARRAY_SIZE(backlight_map)) {
		pr_err("get: Invalid brightness value: 0x%X\n", ret);
		return -EINVAL;
	}
	return level;
}

__attribute__((used)) static int bl_set_status(struct backlight_device *bd)
{
	int bright = bd->props.brightness;
	if (bright >= ARRAY_SIZE(backlight_map) || bright < 0)
		return -EINVAL;

	/* Instance 0 is "set backlight" */
	return msi_wmi_set_block(0, backlight_map[bright]);
}

__attribute__((used)) static void msi_wmi_notify(u32 value, void *context)
{
	struct acpi_buffer response = { ACPI_ALLOCATE_BUFFER, NULL };
	struct key_entry *key;
	union acpi_object *obj;
	acpi_status status;

	status = wmi_get_event_data(value, &response);
	if (status != AE_OK) {
		pr_info("bad event status 0x%x\n", status);
		return;
	}

	obj = (union acpi_object *)response.pointer;

	if (obj && obj->type == ACPI_TYPE_INTEGER) {
		int eventcode = obj->integer.value;
		pr_debug("Eventcode: 0x%x\n", eventcode);
		key = sparse_keymap_entry_from_scancode(msi_wmi_input_dev,
				eventcode);
		if (!key) {
			pr_info("Unknown key pressed - %x\n", eventcode);
			goto msi_wmi_notify_exit;
		}

		if (event_wmi->quirk_last_pressed) {
			ktime_t cur = ktime_get_real();
			ktime_t diff = ktime_sub(cur, last_pressed);
			/* Ignore event if any event happened in a 50 ms
			   timeframe -> Key press may result in 10-20 GPEs */
			if (ktime_to_us(diff) < 1000 * 50) {
				pr_debug("Suppressed key event 0x%X - "
					 "Last press was %lld us ago\n",
					 key->code, ktime_to_us(diff));
				goto msi_wmi_notify_exit;
			}
			last_pressed = cur;
		}

		if (key->type == KE_KEY &&
		/* Brightness is served via acpi video driver */
		(backlight ||
		(key->code != MSI_KEY_BRIGHTNESSUP &&
		key->code != MSI_KEY_BRIGHTNESSDOWN))) {
			pr_debug("Send key: 0x%X - Input layer keycode: %d\n",
				 key->code, key->keycode);
			sparse_keymap_report_entry(msi_wmi_input_dev, key, 1,
						   true);
		}
	} else
		pr_info("Unknown event received\n");

msi_wmi_notify_exit:
	kfree(response.pointer);
}

