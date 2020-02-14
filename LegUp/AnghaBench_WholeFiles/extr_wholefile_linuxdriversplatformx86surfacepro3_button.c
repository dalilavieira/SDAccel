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
typedef  int u32 ;
struct surface_button {struct input_dev* input; int /*<<< orphan*/  phys; scalar_t__ suspended; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; TYPE_2__ dev; TYPE_1__ id; int /*<<< orphan*/  phys; } ;
struct acpi_device {int /*<<< orphan*/  dev; struct surface_button* driver_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_HOST ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int KEY_LEFTMETA ; 
 int KEY_POWER ; 
 int KEY_RESERVED ; 
 int KEY_VOLUMEDOWN ; 
 int KEY_VOLUMEUP ; 
 int /*<<< orphan*/  SURFACE_BUTTON_DEVICE_NAME ; 
#define  SURFACE_BUTTON_NOTIFY_PRESS_HOME 136 
#define  SURFACE_BUTTON_NOTIFY_PRESS_POWER 135 
#define  SURFACE_BUTTON_NOTIFY_PRESS_VOLUME_DOWN 134 
#define  SURFACE_BUTTON_NOTIFY_PRESS_VOLUME_UP 133 
#define  SURFACE_BUTTON_NOTIFY_RELEASE_HOME 132 
#define  SURFACE_BUTTON_NOTIFY_RELEASE_POWER 131 
#define  SURFACE_BUTTON_NOTIFY_RELEASE_VOLUME_DOWN 130 
#define  SURFACE_BUTTON_NOTIFY_RELEASE_VOLUME_UP 129 
#define  SURFACE_BUTTON_NOTIFY_TABLET_MODE 128 
 int /*<<< orphan*/  SURFACE_BUTTON_OBJ_NAME ; 
 int /*<<< orphan*/  acpi_device_bid (struct acpi_device*) ; 
 char* acpi_device_hid (struct acpi_device*) ; 
 char* acpi_device_name (struct acpi_device*) ; 
 struct surface_button* acpi_driver_data (struct acpi_device*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info_ratelimited (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_warn_once (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  device_init_wakeup (int /*<<< orphan*/ *,int) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct surface_button*) ; 
 struct surface_button* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_wakeup_dev_event (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void surface_button_notify(struct acpi_device *device, u32 event)
{
	struct surface_button *button = acpi_driver_data(device);
	struct input_dev *input;
	int key_code = KEY_RESERVED;
	bool pressed = false;

	switch (event) {
	/* Power button press,release handle */
	case SURFACE_BUTTON_NOTIFY_PRESS_POWER:
		pressed = true;
		/*fall through*/
	case SURFACE_BUTTON_NOTIFY_RELEASE_POWER:
		key_code = KEY_POWER;
		break;
	/* Home button press,release handle */
	case SURFACE_BUTTON_NOTIFY_PRESS_HOME:
		pressed = true;
		/*fall through*/
	case SURFACE_BUTTON_NOTIFY_RELEASE_HOME:
		key_code = KEY_LEFTMETA;
		break;
	/* Volume up button press,release handle */
	case SURFACE_BUTTON_NOTIFY_PRESS_VOLUME_UP:
		pressed = true;
		/*fall through*/
	case SURFACE_BUTTON_NOTIFY_RELEASE_VOLUME_UP:
		key_code = KEY_VOLUMEUP;
		break;
	/* Volume down button press,release handle */
	case SURFACE_BUTTON_NOTIFY_PRESS_VOLUME_DOWN:
		pressed = true;
		/*fall through*/
	case SURFACE_BUTTON_NOTIFY_RELEASE_VOLUME_DOWN:
		key_code = KEY_VOLUMEDOWN;
		break;
	case SURFACE_BUTTON_NOTIFY_TABLET_MODE:
		dev_warn_once(&device->dev, "Tablet mode is not supported\n");
		break;
	default:
		dev_info_ratelimited(&device->dev,
				     "Unsupported event [0x%x]\n", event);
		break;
	}
	input = button->input;
	if (key_code == KEY_RESERVED)
		return;
	if (pressed)
		pm_wakeup_dev_event(&device->dev, 0, button->suspended);
	if (button->suspended)
		return;
	input_report_key(input, key_code, pressed?1:0);
	input_sync(input);
}

__attribute__((used)) static int surface_button_add(struct acpi_device *device)
{
	struct surface_button *button;
	struct input_dev *input;
	const char *hid = acpi_device_hid(device);
	char *name;
	int error;

	if (strncmp(acpi_device_bid(device), SURFACE_BUTTON_OBJ_NAME,
	    strlen(SURFACE_BUTTON_OBJ_NAME)))
		return -ENODEV;

	button = kzalloc(sizeof(struct surface_button), GFP_KERNEL);
	if (!button)
		return -ENOMEM;

	device->driver_data = button;
	button->input = input = input_allocate_device();
	if (!input) {
		error = -ENOMEM;
		goto err_free_button;
	}

	name = acpi_device_name(device);
	strcpy(name, SURFACE_BUTTON_DEVICE_NAME);
	snprintf(button->phys, sizeof(button->phys), "%s/buttons", hid);

	input->name = name;
	input->phys = button->phys;
	input->id.bustype = BUS_HOST;
	input->dev.parent = &device->dev;
	input_set_capability(input, EV_KEY, KEY_POWER);
	input_set_capability(input, EV_KEY, KEY_LEFTMETA);
	input_set_capability(input, EV_KEY, KEY_VOLUMEUP);
	input_set_capability(input, EV_KEY, KEY_VOLUMEDOWN);

	error = input_register_device(input);
	if (error)
		goto err_free_input;

	device_init_wakeup(&device->dev, true);
	dev_info(&device->dev,
			"%s [%s]\n", name, acpi_device_bid(device));
	return 0;

 err_free_input:
	input_free_device(input);
 err_free_button:
	kfree(button);
	return error;
}

__attribute__((used)) static int surface_button_remove(struct acpi_device *device)
{
	struct surface_button *button = acpi_driver_data(device);

	input_unregister_device(button->input);
	kfree(button);
	return 0;
}

