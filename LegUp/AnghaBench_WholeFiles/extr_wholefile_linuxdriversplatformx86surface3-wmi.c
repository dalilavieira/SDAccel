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
struct TYPE_6__ {int value; } ;
struct TYPE_5__ {int /*<<< orphan*/  length; } ;
union acpi_object {scalar_t__ type; TYPE_2__ integer; TYPE_1__ buffer; } ;
typedef  int /*<<< orphan*/  u32 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_7__ {int product; int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; char* phys; TYPE_3__ id; } ;
struct device {int dummy; } ;
struct acpi_device {int dummy; } ;
struct acpi_buffer {union acpi_object* pointer; int /*<<< orphan*/ * member_1; int /*<<< orphan*/  member_0; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_8__ {struct input_dev* input; struct acpi_device* touchscreen_adev; struct acpi_device* pnp0c0d_adev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ALLOCATE_BUFFER ; 
 int /*<<< orphan*/  ACPI_BUTTON_HID_LID ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_HANDLE (struct device*) ; 
 scalar_t__ ACPI_TYPE_BUFFER ; 
 int /*<<< orphan*/  ACPI_TYPE_DEVICE ; 
 scalar_t__ ACPI_TYPE_INTEGER ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  BUS_HOST ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_SW ; 
 int /*<<< orphan*/  SPI_CTL_OBJ_NAME ; 
 int /*<<< orphan*/  SPI_TS_OBJ_NAME ; 
 char* SURFACE3_LID_GUID ; 
 int /*<<< orphan*/  SW_LID ; 
 scalar_t__ acpi_bus_get_device (int /*<<< orphan*/ ,struct acpi_device**) ; 
 int /*<<< orphan*/  acpi_device_bid (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_device_hid (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_walk_namespace (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/  (*) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,void**),int /*<<< orphan*/ *,struct acpi_device**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct input_dev* devm_input_allocate_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_switch (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (union acpi_object*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*,scalar_t__,...) ; 
 TYPE_4__ s3_wmi ; 
 int /*<<< orphan*/  s3_wmi_lock ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wmi_query_block (char const*,int,struct acpi_buffer*) ; 

__attribute__((used)) static int s3_wmi_query_block(const char *guid, int instance, int *ret)
{
	struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
	acpi_status status;
	union acpi_object *obj;
	int error = 0;

	mutex_lock(&s3_wmi_lock);
	status = wmi_query_block(guid, instance, &output);

	obj = output.pointer;

	if (!obj || obj->type != ACPI_TYPE_INTEGER) {
		if (obj) {
			pr_err("query block returned object type: %d - buffer length:%d\n",
			       obj->type,
			       obj->type == ACPI_TYPE_BUFFER ?
						obj->buffer.length : 0);
		}
		error = -EINVAL;
		goto out_free_unlock;
	}
	*ret = obj->integer.value;
 out_free_unlock:
	kfree(obj);
	mutex_unlock(&s3_wmi_lock);
	return error;
}

__attribute__((used)) static inline int s3_wmi_query_lid(int *ret)
{
	return s3_wmi_query_block(SURFACE3_LID_GUID, 0, ret);
}

__attribute__((used)) static int s3_wmi_send_lid_state(void)
{
	int ret, lid_sw;

	ret = s3_wmi_query_lid(&lid_sw);
	if (ret)
		return ret;

	input_report_switch(s3_wmi.input, SW_LID, lid_sw);
	input_sync(s3_wmi.input);

	return 0;
}

__attribute__((used)) static int s3_wmi_hp_notify(struct acpi_device *adev, u32 value)
{
	return s3_wmi_send_lid_state();
}

__attribute__((used)) static acpi_status s3_wmi_attach_spi_device(acpi_handle handle,
					    u32 level,
					    void *data,
					    void **return_value)
{
	struct acpi_device *adev, **ts_adev;

	if (acpi_bus_get_device(handle, &adev))
		return AE_OK;

	ts_adev = data;

	if (strncmp(acpi_device_bid(adev), SPI_TS_OBJ_NAME,
	    strlen(SPI_TS_OBJ_NAME)))
		return AE_OK;

	if (*ts_adev) {
		pr_err("duplicate entry %s\n", SPI_TS_OBJ_NAME);
		return AE_OK;
	}

	*ts_adev = adev;

	return AE_OK;
}

__attribute__((used)) static int s3_wmi_check_platform_device(struct device *dev, void *data)
{
	struct acpi_device *adev, *ts_adev = NULL;
	acpi_handle handle;
	acpi_status status;

	/* ignore non ACPI devices */
	handle = ACPI_HANDLE(dev);
	if (!handle || acpi_bus_get_device(handle, &adev))
		return 0;

	/* check for LID ACPI switch */
	if (!strcmp(ACPI_BUTTON_HID_LID, acpi_device_hid(adev))) {
		s3_wmi.pnp0c0d_adev = adev;
		return 0;
	}

	/* ignore non SPI controllers */
	if (strncmp(acpi_device_bid(adev), SPI_CTL_OBJ_NAME,
	    strlen(SPI_CTL_OBJ_NAME)))
		return 0;

	status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, 1,
				     s3_wmi_attach_spi_device, NULL,
				     &ts_adev, NULL);
	if (ACPI_FAILURE(status))
		dev_warn(dev, "failed to enumerate SPI slaves\n");

	if (!ts_adev)
		return 0;

	s3_wmi.touchscreen_adev = ts_adev;

	return 0;
}

__attribute__((used)) static int s3_wmi_create_and_register_input(struct platform_device *pdev)
{
	struct input_dev *input;
	int error;

	input = devm_input_allocate_device(&pdev->dev);
	if (!input)
		return -ENOMEM;

	input->name = "Lid Switch";
	input->phys = "button/input0";
	input->id.bustype = BUS_HOST;
	input->id.product = 0x0005;

	input_set_capability(input, EV_SW, SW_LID);

	error = input_register_device(input);
	if (error)
		goto out_err;

	s3_wmi.input = input;

	return 0;
 out_err:
	input_free_device(s3_wmi.input);
	return error;
}

