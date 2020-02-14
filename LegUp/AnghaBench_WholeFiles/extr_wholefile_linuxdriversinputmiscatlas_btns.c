#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
struct acpi_device {int /*<<< orphan*/  handle; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int acpi_physical_address ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_11__ {int /*<<< orphan*/  bustype; } ;
struct TYPE_12__ {char* name; char* phys; int keycodesize; int keycodemax; int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; scalar_t__* keycode; TYPE_1__ id; } ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_REGION_DEACTIVATE ; 
 scalar_t__ ACPI_WRITE ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_OK ; 
 int ARRAY_SIZE (scalar_t__*) ; 
 int /*<<< orphan*/  BUS_HOST ; 
 int EINVAL ; 
 int ENOMEM ; 
 scalar_t__ EV_KEY ; 
 int /*<<< orphan*/  EV_MSC ; 
 scalar_t__ KEY_F1 ; 
 scalar_t__ KEY_RESERVED ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int /*<<< orphan*/  __set_bit (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_install_address_space_handler (int /*<<< orphan*/ ,int,int /*<<< orphan*/  (*) (scalar_t__,int,scalar_t__,scalar_t__*,void*,void*),int /*<<< orphan*/  (*) (int /*<<< orphan*/ ,scalar_t__,void*,void**),struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_remove_address_space_handler (int /*<<< orphan*/ ,int,int /*<<< orphan*/  (*) (scalar_t__,int,scalar_t__,scalar_t__*,void*,void*)) ; 
 scalar_t__* atlas_keymap ; 
 TYPE_2__* input_allocate_device () ; 
 TYPE_2__* input_dev ; 
 int /*<<< orphan*/  input_event (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_free_device (TYPE_2__*) ; 
 int input_register_device (TYPE_2__*) ; 
 int /*<<< orphan*/  input_report_key (TYPE_2__*,scalar_t__,int) ; 
 int /*<<< orphan*/  input_set_capability (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (TYPE_2__*) ; 
 int /*<<< orphan*/  input_unregister_device (TYPE_2__*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_warn (char*,scalar_t__,unsigned long,scalar_t__) ; 

__attribute__((used)) static acpi_status acpi_atlas_button_setup(acpi_handle region_handle,
		    u32 function, void *handler_context, void **return_context)
{
	*return_context =
		(function != ACPI_REGION_DEACTIVATE) ? handler_context : NULL;

	return AE_OK;
}

__attribute__((used)) static acpi_status acpi_atlas_button_handler(u32 function,
		      acpi_physical_address address,
		      u32 bit_width, u64 *value,
		      void *handler_context, void *region_context)
{
	acpi_status status;

	if (function == ACPI_WRITE) {
		int code = address & 0x0f;
		int key_down = !(address & 0x10);

		input_event(input_dev, EV_MSC, MSC_SCAN, code);
		input_report_key(input_dev, atlas_keymap[code], key_down);
		input_sync(input_dev);

		status = AE_OK;
	} else {
		pr_warn("shrugged on unexpected function: function=%x,address=%lx,value=%x\n",
			function, (unsigned long)address, (u32)*value);
		status = AE_BAD_PARAMETER;
	}

	return status;
}

__attribute__((used)) static int atlas_acpi_button_add(struct acpi_device *device)
{
	acpi_status status;
	int i;
	int err;

	input_dev = input_allocate_device();
	if (!input_dev) {
		pr_err("unable to allocate input device\n");
		return -ENOMEM;
	}

	input_dev->name = "Atlas ACPI button driver";
	input_dev->phys = "ASIM0000/atlas/input0";
	input_dev->id.bustype = BUS_HOST;
	input_dev->keycode = atlas_keymap;
	input_dev->keycodesize = sizeof(unsigned short);
	input_dev->keycodemax = ARRAY_SIZE(atlas_keymap);

	input_set_capability(input_dev, EV_MSC, MSC_SCAN);
	__set_bit(EV_KEY, input_dev->evbit);
	for (i = 0; i < ARRAY_SIZE(atlas_keymap); i++) {
		if (i < 9) {
			atlas_keymap[i] = KEY_F1 + i;
			__set_bit(KEY_F1 + i, input_dev->keybit);
		} else
			atlas_keymap[i] = KEY_RESERVED;
	}

	err = input_register_device(input_dev);
	if (err) {
		pr_err("couldn't register input device\n");
		input_free_device(input_dev);
		return err;
	}

	/* hookup button handler */
	status = acpi_install_address_space_handler(device->handle,
				0x81, &acpi_atlas_button_handler,
				&acpi_atlas_button_setup, device);
	if (ACPI_FAILURE(status)) {
		pr_err("error installing addr spc handler\n");
		input_unregister_device(input_dev);
		err = -EINVAL;
	}

	return err;
}

__attribute__((used)) static int atlas_acpi_button_remove(struct acpi_device *device)
{
	acpi_status status;

	status = acpi_remove_address_space_handler(device->handle,
				0x81, &acpi_atlas_button_handler);
	if (ACPI_FAILURE(status))
		pr_err("error removing addr spc handler\n");

	input_unregister_device(input_dev);

	return 0;
}

