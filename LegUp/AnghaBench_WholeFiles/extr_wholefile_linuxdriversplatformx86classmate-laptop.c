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
struct TYPE_6__ {int value; } ;
struct device {struct device* parent; } ;
struct TYPE_4__ {unsigned char* pointer; } ;
union acpi_object {char* name; int sensitivity; int g_select; int (* open ) (union acpi_object*) ;void (* close ) (union acpi_object*) ;int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; int /*<<< orphan*/ * rf; int /*<<< orphan*/  bd; TYPE_3__ integer; void* type; struct device dev; int /*<<< orphan*/  swbit; TYPE_1__ buffer; void* inputdev_state; } ;
typedef  int u32 ;
struct rfkill {int dummy; } ;
struct ipml200_dev {char* name; int sensitivity; int g_select; int (* open ) (union acpi_object*) ;void (* close ) (union acpi_object*) ;int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; int /*<<< orphan*/ * rf; int /*<<< orphan*/  bd; TYPE_3__ integer; void* type; struct device dev; int /*<<< orphan*/  swbit; TYPE_1__ buffer; void* inputdev_state; } ;
struct input_dev {char* name; int sensitivity; int g_select; int (* open ) (union acpi_object*) ;void (* close ) (union acpi_object*) ;int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; int /*<<< orphan*/ * rf; int /*<<< orphan*/  bd; TYPE_3__ integer; void* type; struct device dev; int /*<<< orphan*/  swbit; TYPE_1__ buffer; void* inputdev_state; } ;
struct device_attribute {int dummy; } ;
struct cmpc_accel {char* name; int sensitivity; int g_select; int (* open ) (union acpi_object*) ;void (* close ) (union acpi_object*) ;int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; int /*<<< orphan*/ * rf; int /*<<< orphan*/  bd; TYPE_3__ integer; void* type; struct device dev; int /*<<< orphan*/  swbit; TYPE_1__ buffer; void* inputdev_state; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_5__ {unsigned long long brightness; } ;
struct backlight_device {TYPE_2__ props; } ;
struct acpi_object_list {int count; union acpi_object* pointer; } ;
struct acpi_device {struct device dev; void* handle; } ;
struct acpi_buffer {union acpi_object* pointer; int /*<<< orphan*/ * member_1; int /*<<< orphan*/  member_0; } ;
typedef  int ssize_t ;
typedef  unsigned char int16_t ;
typedef  void (* input_device_init ) (union acpi_object*) ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  void* acpi_handle ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  ABS_Z ; 
 int /*<<< orphan*/  ACPI_ALLOCATE_BUFFER ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 void* ACPI_TYPE_INTEGER ; 
 int ARRAY_SIZE (int*) ; 
 int /*<<< orphan*/  BACKLIGHT_PLATFORM ; 
 void* CMPC_ACCEL_DEV_STATE_CLOSED ; 
 void* CMPC_ACCEL_DEV_STATE_OPEN ; 
 int CMPC_ACCEL_G_SELECT_DEFAULT ; 
 void* CMPC_ACCEL_SENSITIVITY_DEFAULT ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EV_ABS ; 
 int EV_KEY ; 
 int EV_SW ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int KEY_MAX ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RFKILL_TYPE_WLAN ; 
 int SW_TABLET_MODE ; 
 int acpi_bus_register_driver (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_bus_unregister_driver (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_evaluate_integer (void*,char*,struct acpi_object_list*,unsigned long long*) ; 
 int /*<<< orphan*/  acpi_evaluate_object (void*,char*,struct acpi_object_list*,struct acpi_buffer*) ; 
 int /*<<< orphan*/  backlight_device_register (char*,struct device*,void*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int /*<<< orphan*/  backlight_device_unregister (int /*<<< orphan*/ ) ; 
 void* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  cmpc_accel_acpi_driver ; 
 int /*<<< orphan*/  cmpc_accel_acpi_driver_v4 ; 
 int /*<<< orphan*/  cmpc_accel_g_select_attr_v4 ; 
 int /*<<< orphan*/  cmpc_accel_sensitivity_attr ; 
 int /*<<< orphan*/  cmpc_accel_sensitivity_attr_v4 ; 
 int /*<<< orphan*/  cmpc_bl_ops ; 
 int /*<<< orphan*/  cmpc_ipml_acpi_driver ; 
 int /*<<< orphan*/  cmpc_keys_acpi_driver ; 
 int* cmpc_keys_codes ; 
 int /*<<< orphan*/  cmpc_rfkill_ops ; 
 int /*<<< orphan*/  cmpc_tablet_acpi_driver ; 
 union acpi_object* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,union acpi_object*) ; 
 int device_create_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (struct device*,int /*<<< orphan*/ *) ; 
 union acpi_object* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (union acpi_object*) ; 
 int input_register_device (union acpi_object*) ; 
 int /*<<< orphan*/  input_report_abs (union acpi_object*,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  input_report_key (union acpi_object*,int,int) ; 
 int /*<<< orphan*/  input_report_switch (union acpi_object*,int,int) ; 
 int /*<<< orphan*/  input_set_abs_params (union acpi_object*,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (union acpi_object*) ; 
 int /*<<< orphan*/  input_unregister_device (union acpi_object*) ; 
 int /*<<< orphan*/  kfree (union acpi_object*) ; 
 union acpi_object* kmalloc (int,int /*<<< orphan*/ ) ; 
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * rfkill_alloc (char*,struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  rfkill_destroy (int /*<<< orphan*/ *) ; 
 int rfkill_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rfkill_set_sw_state (struct rfkill*,int) ; 
 int /*<<< orphan*/  rfkill_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ ) ; 
 int sprintf (char*,char*,int) ; 
 int strnlen (char const*,size_t) ; 
 struct acpi_device* to_acpi_device (struct device*) ; 

__attribute__((used)) static int cmpc_add_acpi_notify_device(struct acpi_device *acpi, char *name,
				       input_device_init idev_init)
{
	struct input_dev *inputdev;
	int error;

	inputdev = input_allocate_device();
	if (!inputdev)
		return -ENOMEM;
	inputdev->name = name;
	inputdev->dev.parent = &acpi->dev;
	idev_init(inputdev);
	error = input_register_device(inputdev);
	if (error) {
		input_free_device(inputdev);
		return error;
	}
	dev_set_drvdata(&acpi->dev, inputdev);
	return 0;
}

__attribute__((used)) static int cmpc_remove_acpi_notify_device(struct acpi_device *acpi)
{
	struct input_dev *inputdev = dev_get_drvdata(&acpi->dev);
	input_unregister_device(inputdev);
	return 0;
}

__attribute__((used)) static acpi_status cmpc_start_accel_v4(acpi_handle handle)
{
	union acpi_object param[4];
	struct acpi_object_list input;
	acpi_status status;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x3;
	param[1].type = ACPI_TYPE_INTEGER;
	param[1].integer.value = 0;
	param[2].type = ACPI_TYPE_INTEGER;
	param[2].integer.value = 0;
	param[3].type = ACPI_TYPE_INTEGER;
	param[3].integer.value = 0;
	input.count = 4;
	input.pointer = param;
	status = acpi_evaluate_object(handle, "ACMD", &input, NULL);
	return status;
}

__attribute__((used)) static acpi_status cmpc_stop_accel_v4(acpi_handle handle)
{
	union acpi_object param[4];
	struct acpi_object_list input;
	acpi_status status;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x4;
	param[1].type = ACPI_TYPE_INTEGER;
	param[1].integer.value = 0;
	param[2].type = ACPI_TYPE_INTEGER;
	param[2].integer.value = 0;
	param[3].type = ACPI_TYPE_INTEGER;
	param[3].integer.value = 0;
	input.count = 4;
	input.pointer = param;
	status = acpi_evaluate_object(handle, "ACMD", &input, NULL);
	return status;
}

__attribute__((used)) static acpi_status cmpc_accel_set_sensitivity_v4(acpi_handle handle, int val)
{
	union acpi_object param[4];
	struct acpi_object_list input;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x02;
	param[1].type = ACPI_TYPE_INTEGER;
	param[1].integer.value = val;
	param[2].type = ACPI_TYPE_INTEGER;
	param[2].integer.value = 0;
	param[3].type = ACPI_TYPE_INTEGER;
	param[3].integer.value = 0;
	input.count = 4;
	input.pointer = param;
	return acpi_evaluate_object(handle, "ACMD", &input, NULL);
}

__attribute__((used)) static acpi_status cmpc_accel_set_g_select_v4(acpi_handle handle, int val)
{
	union acpi_object param[4];
	struct acpi_object_list input;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x05;
	param[1].type = ACPI_TYPE_INTEGER;
	param[1].integer.value = val;
	param[2].type = ACPI_TYPE_INTEGER;
	param[2].integer.value = 0;
	param[3].type = ACPI_TYPE_INTEGER;
	param[3].integer.value = 0;
	input.count = 4;
	input.pointer = param;
	return acpi_evaluate_object(handle, "ACMD", &input, NULL);
}

__attribute__((used)) static acpi_status cmpc_get_accel_v4(acpi_handle handle,
				     int16_t *x,
				     int16_t *y,
				     int16_t *z)
{
	union acpi_object param[4];
	struct acpi_object_list input;
	struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
	int16_t *locs;
	acpi_status status;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x01;
	param[1].type = ACPI_TYPE_INTEGER;
	param[1].integer.value = 0;
	param[2].type = ACPI_TYPE_INTEGER;
	param[2].integer.value = 0;
	param[3].type = ACPI_TYPE_INTEGER;
	param[3].integer.value = 0;
	input.count = 4;
	input.pointer = param;
	status = acpi_evaluate_object(handle, "ACMD", &input, &output);
	if (ACPI_SUCCESS(status)) {
		union acpi_object *obj;
		obj = output.pointer;
		locs = (int16_t *) obj->buffer.pointer;
		*x = locs[0];
		*y = locs[1];
		*z = locs[2];
		kfree(output.pointer);
	}
	return status;
}

__attribute__((used)) static void cmpc_accel_handler_v4(struct acpi_device *dev, u32 event)
{
	if (event == 0x81) {
		int16_t x, y, z;
		acpi_status status;

		status = cmpc_get_accel_v4(dev->handle, &x, &y, &z);
		if (ACPI_SUCCESS(status)) {
			struct input_dev *inputdev = dev_get_drvdata(&dev->dev);

			input_report_abs(inputdev, ABS_X, x);
			input_report_abs(inputdev, ABS_Y, y);
			input_report_abs(inputdev, ABS_Z, z);
			input_sync(inputdev);
		}
	}
}

__attribute__((used)) static ssize_t cmpc_accel_sensitivity_show_v4(struct device *dev,
					      struct device_attribute *attr,
					      char *buf)
{
	struct acpi_device *acpi;
	struct input_dev *inputdev;
	struct cmpc_accel *accel;

	acpi = to_acpi_device(dev);
	inputdev = dev_get_drvdata(&acpi->dev);
	accel = dev_get_drvdata(&inputdev->dev);

	return sprintf(buf, "%d\n", accel->sensitivity);
}

__attribute__((used)) static ssize_t cmpc_accel_sensitivity_store_v4(struct device *dev,
					       struct device_attribute *attr,
					       const char *buf, size_t count)
{
	struct acpi_device *acpi;
	struct input_dev *inputdev;
	struct cmpc_accel *accel;
	unsigned long sensitivity;
	int r;

	acpi = to_acpi_device(dev);
	inputdev = dev_get_drvdata(&acpi->dev);
	accel = dev_get_drvdata(&inputdev->dev);

	r = kstrtoul(buf, 0, &sensitivity);
	if (r)
		return r;

	/* sensitivity must be between 1 and 127 */
	if (sensitivity < 1 || sensitivity > 127)
		return -EINVAL;

	accel->sensitivity = sensitivity;
	cmpc_accel_set_sensitivity_v4(acpi->handle, sensitivity);

	return strnlen(buf, count);
}

__attribute__((used)) static ssize_t cmpc_accel_g_select_show_v4(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct acpi_device *acpi;
	struct input_dev *inputdev;
	struct cmpc_accel *accel;

	acpi = to_acpi_device(dev);
	inputdev = dev_get_drvdata(&acpi->dev);
	accel = dev_get_drvdata(&inputdev->dev);

	return sprintf(buf, "%d\n", accel->g_select);
}

__attribute__((used)) static ssize_t cmpc_accel_g_select_store_v4(struct device *dev,
					    struct device_attribute *attr,
					    const char *buf, size_t count)
{
	struct acpi_device *acpi;
	struct input_dev *inputdev;
	struct cmpc_accel *accel;
	unsigned long g_select;
	int r;

	acpi = to_acpi_device(dev);
	inputdev = dev_get_drvdata(&acpi->dev);
	accel = dev_get_drvdata(&inputdev->dev);

	r = kstrtoul(buf, 0, &g_select);
	if (r)
		return r;

	/* 0 means 1.5g, 1 means 6g, everything else is wrong */
	if (g_select != 0 && g_select != 1)
		return -EINVAL;

	accel->g_select = g_select;
	cmpc_accel_set_g_select_v4(acpi->handle, g_select);

	return strnlen(buf, count);
}

__attribute__((used)) static int cmpc_accel_open_v4(struct input_dev *input)
{
	struct acpi_device *acpi;
	struct cmpc_accel *accel;

	acpi = to_acpi_device(input->dev.parent);
	accel = dev_get_drvdata(&input->dev);

	cmpc_accel_set_sensitivity_v4(acpi->handle, accel->sensitivity);
	cmpc_accel_set_g_select_v4(acpi->handle, accel->g_select);

	if (ACPI_SUCCESS(cmpc_start_accel_v4(acpi->handle))) {
		accel->inputdev_state = CMPC_ACCEL_DEV_STATE_OPEN;
		return 0;
	}
	return -EIO;
}

__attribute__((used)) static void cmpc_accel_close_v4(struct input_dev *input)
{
	struct acpi_device *acpi;
	struct cmpc_accel *accel;

	acpi = to_acpi_device(input->dev.parent);
	accel = dev_get_drvdata(&input->dev);

	cmpc_stop_accel_v4(acpi->handle);
	accel->inputdev_state = CMPC_ACCEL_DEV_STATE_CLOSED;
}

__attribute__((used)) static void cmpc_accel_idev_init_v4(struct input_dev *inputdev)
{
	set_bit(EV_ABS, inputdev->evbit);
	input_set_abs_params(inputdev, ABS_X, -255, 255, 16, 0);
	input_set_abs_params(inputdev, ABS_Y, -255, 255, 16, 0);
	input_set_abs_params(inputdev, ABS_Z, -255, 255, 16, 0);
	inputdev->open = cmpc_accel_open_v4;
	inputdev->close = cmpc_accel_close_v4;
}

__attribute__((used)) static int cmpc_accel_add_v4(struct acpi_device *acpi)
{
	int error;
	struct input_dev *inputdev;
	struct cmpc_accel *accel;

	accel = kmalloc(sizeof(*accel), GFP_KERNEL);
	if (!accel)
		return -ENOMEM;

	accel->inputdev_state = CMPC_ACCEL_DEV_STATE_CLOSED;

	accel->sensitivity = CMPC_ACCEL_SENSITIVITY_DEFAULT;
	cmpc_accel_set_sensitivity_v4(acpi->handle, accel->sensitivity);

	error = device_create_file(&acpi->dev, &cmpc_accel_sensitivity_attr_v4);
	if (error)
		goto failed_sensitivity;

	accel->g_select = CMPC_ACCEL_G_SELECT_DEFAULT;
	cmpc_accel_set_g_select_v4(acpi->handle, accel->g_select);

	error = device_create_file(&acpi->dev, &cmpc_accel_g_select_attr_v4);
	if (error)
		goto failed_g_select;

	error = cmpc_add_acpi_notify_device(acpi, "cmpc_accel_v4",
					    cmpc_accel_idev_init_v4);
	if (error)
		goto failed_input;

	inputdev = dev_get_drvdata(&acpi->dev);
	dev_set_drvdata(&inputdev->dev, accel);

	return 0;

failed_input:
	device_remove_file(&acpi->dev, &cmpc_accel_g_select_attr_v4);
failed_g_select:
	device_remove_file(&acpi->dev, &cmpc_accel_sensitivity_attr_v4);
failed_sensitivity:
	kfree(accel);
	return error;
}

__attribute__((used)) static int cmpc_accel_remove_v4(struct acpi_device *acpi)
{
	struct input_dev *inputdev;
	struct cmpc_accel *accel;

	inputdev = dev_get_drvdata(&acpi->dev);
	accel = dev_get_drvdata(&inputdev->dev);

	device_remove_file(&acpi->dev, &cmpc_accel_sensitivity_attr_v4);
	device_remove_file(&acpi->dev, &cmpc_accel_g_select_attr_v4);
	return cmpc_remove_acpi_notify_device(acpi);
}

__attribute__((used)) static acpi_status cmpc_start_accel(acpi_handle handle)
{
	union acpi_object param[2];
	struct acpi_object_list input;
	acpi_status status;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x3;
	param[1].type = ACPI_TYPE_INTEGER;
	input.count = 2;
	input.pointer = param;
	status = acpi_evaluate_object(handle, "ACMD", &input, NULL);
	return status;
}

__attribute__((used)) static acpi_status cmpc_stop_accel(acpi_handle handle)
{
	union acpi_object param[2];
	struct acpi_object_list input;
	acpi_status status;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x4;
	param[1].type = ACPI_TYPE_INTEGER;
	input.count = 2;
	input.pointer = param;
	status = acpi_evaluate_object(handle, "ACMD", &input, NULL);
	return status;
}

__attribute__((used)) static acpi_status cmpc_accel_set_sensitivity(acpi_handle handle, int val)
{
	union acpi_object param[2];
	struct acpi_object_list input;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x02;
	param[1].type = ACPI_TYPE_INTEGER;
	param[1].integer.value = val;
	input.count = 2;
	input.pointer = param;
	return acpi_evaluate_object(handle, "ACMD", &input, NULL);
}

__attribute__((used)) static acpi_status cmpc_get_accel(acpi_handle handle,
				  unsigned char *x,
				  unsigned char *y,
				  unsigned char *z)
{
	union acpi_object param[2];
	struct acpi_object_list input;
	struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
	unsigned char *locs;
	acpi_status status;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0x01;
	param[1].type = ACPI_TYPE_INTEGER;
	input.count = 2;
	input.pointer = param;
	status = acpi_evaluate_object(handle, "ACMD", &input, &output);
	if (ACPI_SUCCESS(status)) {
		union acpi_object *obj;
		obj = output.pointer;
		locs = obj->buffer.pointer;
		*x = locs[0];
		*y = locs[1];
		*z = locs[2];
		kfree(output.pointer);
	}
	return status;
}

__attribute__((used)) static void cmpc_accel_handler(struct acpi_device *dev, u32 event)
{
	if (event == 0x81) {
		unsigned char x, y, z;
		acpi_status status;

		status = cmpc_get_accel(dev->handle, &x, &y, &z);
		if (ACPI_SUCCESS(status)) {
			struct input_dev *inputdev = dev_get_drvdata(&dev->dev);

			input_report_abs(inputdev, ABS_X, x);
			input_report_abs(inputdev, ABS_Y, y);
			input_report_abs(inputdev, ABS_Z, z);
			input_sync(inputdev);
		}
	}
}

__attribute__((used)) static ssize_t cmpc_accel_sensitivity_show(struct device *dev,
					   struct device_attribute *attr,
					   char *buf)
{
	struct acpi_device *acpi;
	struct input_dev *inputdev;
	struct cmpc_accel *accel;

	acpi = to_acpi_device(dev);
	inputdev = dev_get_drvdata(&acpi->dev);
	accel = dev_get_drvdata(&inputdev->dev);

	return sprintf(buf, "%d\n", accel->sensitivity);
}

__attribute__((used)) static ssize_t cmpc_accel_sensitivity_store(struct device *dev,
					    struct device_attribute *attr,
					    const char *buf, size_t count)
{
	struct acpi_device *acpi;
	struct input_dev *inputdev;
	struct cmpc_accel *accel;
	unsigned long sensitivity;
	int r;

	acpi = to_acpi_device(dev);
	inputdev = dev_get_drvdata(&acpi->dev);
	accel = dev_get_drvdata(&inputdev->dev);

	r = kstrtoul(buf, 0, &sensitivity);
	if (r)
		return r;

	accel->sensitivity = sensitivity;
	cmpc_accel_set_sensitivity(acpi->handle, sensitivity);

	return strnlen(buf, count);
}

__attribute__((used)) static int cmpc_accel_open(struct input_dev *input)
{
	struct acpi_device *acpi;

	acpi = to_acpi_device(input->dev.parent);
	if (ACPI_SUCCESS(cmpc_start_accel(acpi->handle)))
		return 0;
	return -EIO;
}

__attribute__((used)) static void cmpc_accel_close(struct input_dev *input)
{
	struct acpi_device *acpi;

	acpi = to_acpi_device(input->dev.parent);
	cmpc_stop_accel(acpi->handle);
}

__attribute__((used)) static void cmpc_accel_idev_init(struct input_dev *inputdev)
{
	set_bit(EV_ABS, inputdev->evbit);
	input_set_abs_params(inputdev, ABS_X, 0, 255, 8, 0);
	input_set_abs_params(inputdev, ABS_Y, 0, 255, 8, 0);
	input_set_abs_params(inputdev, ABS_Z, 0, 255, 8, 0);
	inputdev->open = cmpc_accel_open;
	inputdev->close = cmpc_accel_close;
}

__attribute__((used)) static int cmpc_accel_add(struct acpi_device *acpi)
{
	int error;
	struct input_dev *inputdev;
	struct cmpc_accel *accel;

	accel = kmalloc(sizeof(*accel), GFP_KERNEL);
	if (!accel)
		return -ENOMEM;

	accel->sensitivity = CMPC_ACCEL_SENSITIVITY_DEFAULT;
	cmpc_accel_set_sensitivity(acpi->handle, accel->sensitivity);

	error = device_create_file(&acpi->dev, &cmpc_accel_sensitivity_attr);
	if (error)
		goto failed_file;

	error = cmpc_add_acpi_notify_device(acpi, "cmpc_accel",
					    cmpc_accel_idev_init);
	if (error)
		goto failed_input;

	inputdev = dev_get_drvdata(&acpi->dev);
	dev_set_drvdata(&inputdev->dev, accel);

	return 0;

failed_input:
	device_remove_file(&acpi->dev, &cmpc_accel_sensitivity_attr);
failed_file:
	kfree(accel);
	return error;
}

__attribute__((used)) static int cmpc_accel_remove(struct acpi_device *acpi)
{
	struct input_dev *inputdev;
	struct cmpc_accel *accel;

	inputdev = dev_get_drvdata(&acpi->dev);
	accel = dev_get_drvdata(&inputdev->dev);

	device_remove_file(&acpi->dev, &cmpc_accel_sensitivity_attr);
	return cmpc_remove_acpi_notify_device(acpi);
}

__attribute__((used)) static acpi_status cmpc_get_tablet(acpi_handle handle,
				   unsigned long long *value)
{
	union acpi_object param;
	struct acpi_object_list input;
	unsigned long long output;
	acpi_status status;

	param.type = ACPI_TYPE_INTEGER;
	param.integer.value = 0x01;
	input.count = 1;
	input.pointer = &param;
	status = acpi_evaluate_integer(handle, "TCMD", &input, &output);
	if (ACPI_SUCCESS(status))
		*value = output;
	return status;
}

__attribute__((used)) static void cmpc_tablet_handler(struct acpi_device *dev, u32 event)
{
	unsigned long long val = 0;
	struct input_dev *inputdev = dev_get_drvdata(&dev->dev);

	if (event == 0x81) {
		if (ACPI_SUCCESS(cmpc_get_tablet(dev->handle, &val))) {
			input_report_switch(inputdev, SW_TABLET_MODE, !val);
			input_sync(inputdev);
		}
	}
}

__attribute__((used)) static void cmpc_tablet_idev_init(struct input_dev *inputdev)
{
	unsigned long long val = 0;
	struct acpi_device *acpi;

	set_bit(EV_SW, inputdev->evbit);
	set_bit(SW_TABLET_MODE, inputdev->swbit);

	acpi = to_acpi_device(inputdev->dev.parent);
	if (ACPI_SUCCESS(cmpc_get_tablet(acpi->handle, &val))) {
		input_report_switch(inputdev, SW_TABLET_MODE, !val);
		input_sync(inputdev);
	}
}

__attribute__((used)) static int cmpc_tablet_add(struct acpi_device *acpi)
{
	return cmpc_add_acpi_notify_device(acpi, "cmpc_tablet",
					   cmpc_tablet_idev_init);
}

__attribute__((used)) static int cmpc_tablet_remove(struct acpi_device *acpi)
{
	return cmpc_remove_acpi_notify_device(acpi);
}

__attribute__((used)) static acpi_status cmpc_get_brightness(acpi_handle handle,
				       unsigned long long *value)
{
	union acpi_object param;
	struct acpi_object_list input;
	unsigned long long output;
	acpi_status status;

	param.type = ACPI_TYPE_INTEGER;
	param.integer.value = 0xC0;
	input.count = 1;
	input.pointer = &param;
	status = acpi_evaluate_integer(handle, "GRDI", &input, &output);
	if (ACPI_SUCCESS(status))
		*value = output;
	return status;
}

__attribute__((used)) static acpi_status cmpc_set_brightness(acpi_handle handle,
				       unsigned long long value)
{
	union acpi_object param[2];
	struct acpi_object_list input;
	acpi_status status;
	unsigned long long output;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0xC0;
	param[1].type = ACPI_TYPE_INTEGER;
	param[1].integer.value = value;
	input.count = 2;
	input.pointer = param;
	status = acpi_evaluate_integer(handle, "GWRI", &input, &output);
	return status;
}

__attribute__((used)) static int cmpc_bl_get_brightness(struct backlight_device *bd)
{
	acpi_status status;
	acpi_handle handle;
	unsigned long long brightness;

	handle = bl_get_data(bd);
	status = cmpc_get_brightness(handle, &brightness);
	if (ACPI_SUCCESS(status))
		return brightness;
	else
		return -1;
}

__attribute__((used)) static int cmpc_bl_update_status(struct backlight_device *bd)
{
	acpi_status status;
	acpi_handle handle;

	handle = bl_get_data(bd);
	status = cmpc_set_brightness(handle, bd->props.brightness);
	if (ACPI_SUCCESS(status))
		return 0;
	else
		return -1;
}

__attribute__((used)) static acpi_status cmpc_get_rfkill_wlan(acpi_handle handle,
					unsigned long long *value)
{
	union acpi_object param;
	struct acpi_object_list input;
	unsigned long long output;
	acpi_status status;

	param.type = ACPI_TYPE_INTEGER;
	param.integer.value = 0xC1;
	input.count = 1;
	input.pointer = &param;
	status = acpi_evaluate_integer(handle, "GRDI", &input, &output);
	if (ACPI_SUCCESS(status))
		*value = output;
	return status;
}

__attribute__((used)) static acpi_status cmpc_set_rfkill_wlan(acpi_handle handle,
					unsigned long long value)
{
	union acpi_object param[2];
	struct acpi_object_list input;
	acpi_status status;
	unsigned long long output;

	param[0].type = ACPI_TYPE_INTEGER;
	param[0].integer.value = 0xC1;
	param[1].type = ACPI_TYPE_INTEGER;
	param[1].integer.value = value;
	input.count = 2;
	input.pointer = param;
	status = acpi_evaluate_integer(handle, "GWRI", &input, &output);
	return status;
}

__attribute__((used)) static void cmpc_rfkill_query(struct rfkill *rfkill, void *data)
{
	acpi_status status;
	acpi_handle handle;
	unsigned long long state;
	bool blocked;

	handle = data;
	status = cmpc_get_rfkill_wlan(handle, &state);
	if (ACPI_SUCCESS(status)) {
		blocked = state & 1 ? false : true;
		rfkill_set_sw_state(rfkill, blocked);
	}
}

__attribute__((used)) static int cmpc_rfkill_block(void *data, bool blocked)
{
	acpi_status status;
	acpi_handle handle;
	unsigned long long state;
	bool is_blocked;

	handle = data;
	status = cmpc_get_rfkill_wlan(handle, &state);
	if (ACPI_FAILURE(status))
		return -ENODEV;
	/* Check if we really need to call cmpc_set_rfkill_wlan */
	is_blocked = state & 1 ? false : true;
	if (is_blocked != blocked) {
		state = blocked ? 0 : 1;
		status = cmpc_set_rfkill_wlan(handle, state);
		if (ACPI_FAILURE(status))
			return -ENODEV;
	}
	return 0;
}

__attribute__((used)) static int cmpc_ipml_add(struct acpi_device *acpi)
{
	int retval;
	struct ipml200_dev *ipml;
	struct backlight_properties props;

	ipml = kmalloc(sizeof(*ipml), GFP_KERNEL);
	if (ipml == NULL)
		return -ENOMEM;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_PLATFORM;
	props.max_brightness = 7;
	ipml->bd = backlight_device_register("cmpc_bl", &acpi->dev,
					     acpi->handle, &cmpc_bl_ops,
					     &props);
	if (IS_ERR(ipml->bd)) {
		retval = PTR_ERR(ipml->bd);
		goto out_bd;
	}

	ipml->rf = rfkill_alloc("cmpc_rfkill", &acpi->dev, RFKILL_TYPE_WLAN,
				&cmpc_rfkill_ops, acpi->handle);
	/*
	 * If RFKILL is disabled, rfkill_alloc will return ERR_PTR(-ENODEV).
	 * This is OK, however, since all other uses of the device will not
	 * derefence it.
	 */
	if (ipml->rf) {
		retval = rfkill_register(ipml->rf);
		if (retval) {
			rfkill_destroy(ipml->rf);
			ipml->rf = NULL;
		}
	}

	dev_set_drvdata(&acpi->dev, ipml);
	return 0;

out_bd:
	kfree(ipml);
	return retval;
}

__attribute__((used)) static int cmpc_ipml_remove(struct acpi_device *acpi)
{
	struct ipml200_dev *ipml;

	ipml = dev_get_drvdata(&acpi->dev);

	backlight_device_unregister(ipml->bd);

	if (ipml->rf) {
		rfkill_unregister(ipml->rf);
		rfkill_destroy(ipml->rf);
	}

	kfree(ipml);

	return 0;
}

__attribute__((used)) static void cmpc_keys_handler(struct acpi_device *dev, u32 event)
{
	struct input_dev *inputdev;
	int code = KEY_MAX;

	if ((event & 0x0F) < ARRAY_SIZE(cmpc_keys_codes))
		code = cmpc_keys_codes[event & 0x0F];
	inputdev = dev_get_drvdata(&dev->dev);
	input_report_key(inputdev, code, !(event & 0x10));
	input_sync(inputdev);
}

__attribute__((used)) static void cmpc_keys_idev_init(struct input_dev *inputdev)
{
	int i;

	set_bit(EV_KEY, inputdev->evbit);
	for (i = 0; cmpc_keys_codes[i] != KEY_MAX; i++)
		set_bit(cmpc_keys_codes[i], inputdev->keybit);
}

__attribute__((used)) static int cmpc_keys_add(struct acpi_device *acpi)
{
	return cmpc_add_acpi_notify_device(acpi, "cmpc_keys",
					   cmpc_keys_idev_init);
}

__attribute__((used)) static int cmpc_keys_remove(struct acpi_device *acpi)
{
	return cmpc_remove_acpi_notify_device(acpi);
}

__attribute__((used)) static int cmpc_init(void)
{
	int r;

	r = acpi_bus_register_driver(&cmpc_keys_acpi_driver);
	if (r)
		goto failed_keys;

	r = acpi_bus_register_driver(&cmpc_ipml_acpi_driver);
	if (r)
		goto failed_bl;

	r = acpi_bus_register_driver(&cmpc_tablet_acpi_driver);
	if (r)
		goto failed_tablet;

	r = acpi_bus_register_driver(&cmpc_accel_acpi_driver);
	if (r)
		goto failed_accel;

	r = acpi_bus_register_driver(&cmpc_accel_acpi_driver_v4);
	if (r)
		goto failed_accel_v4;

	return r;

failed_accel_v4:
	acpi_bus_unregister_driver(&cmpc_accel_acpi_driver);

failed_accel:
	acpi_bus_unregister_driver(&cmpc_tablet_acpi_driver);

failed_tablet:
	acpi_bus_unregister_driver(&cmpc_ipml_acpi_driver);

failed_bl:
	acpi_bus_unregister_driver(&cmpc_keys_acpi_driver);

failed_keys:
	return r;
}

__attribute__((used)) static void cmpc_exit(void)
{
	acpi_bus_unregister_driver(&cmpc_accel_acpi_driver_v4);
	acpi_bus_unregister_driver(&cmpc_accel_acpi_driver);
	acpi_bus_unregister_driver(&cmpc_tablet_acpi_driver);
	acpi_bus_unregister_driver(&cmpc_ipml_acpi_driver);
	acpi_bus_unregister_driver(&cmpc_keys_acpi_driver);
}

