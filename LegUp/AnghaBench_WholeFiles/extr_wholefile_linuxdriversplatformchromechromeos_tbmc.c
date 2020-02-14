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
typedef  int u32 ;
struct TYPE_2__ {int version; scalar_t__ product; int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; int (* open ) (struct input_dev*) ;TYPE_1__ id; int /*<<< orphan*/  phys; } ;
struct device {int dummy; } ;
struct acpi_device {struct input_dev* driver_data; struct device dev; int /*<<< orphan*/  handle; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUS_HOST ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_SW ; 
 int /*<<< orphan*/  SW_TABLET_MODE ; 
 int /*<<< orphan*/  acpi_device_hid (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_evaluate_integer (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,unsigned long long*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct input_dev* devm_input_allocate_device (struct device*) ; 
 struct acpi_device* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_switch (struct input_dev*,int /*<<< orphan*/ ,unsigned long long) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct acpi_device*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 

__attribute__((used)) static int chromeos_tbmc_query_switch(struct acpi_device *adev,
				     struct input_dev *idev)
{
	unsigned long long state;
	acpi_status status;

	status = acpi_evaluate_integer(adev->handle, "TBMC", NULL, &state);
	if (ACPI_FAILURE(status))
		return -ENODEV;

	/* input layer checks if event is redundant */
	input_report_switch(idev, SW_TABLET_MODE, state);
	input_sync(idev);

	return 0;
}

__attribute__((used)) static void chromeos_tbmc_notify(struct acpi_device *adev, u32 event)
{
	switch (event) {
	case 0x80:
		chromeos_tbmc_query_switch(adev, adev->driver_data);
		break;
	default:
		dev_err(&adev->dev, "Unexpected event: 0x%08X\n", event);
	}
}

__attribute__((used)) static int chromeos_tbmc_open(struct input_dev *idev)
{
	struct acpi_device *adev = input_get_drvdata(idev);

	return chromeos_tbmc_query_switch(adev, idev);
}

__attribute__((used)) static int chromeos_tbmc_add(struct acpi_device *adev)
{
	struct input_dev *idev;
	struct device *dev = &adev->dev;
	int ret;

	idev = devm_input_allocate_device(dev);
	if (!idev)
		return -ENOMEM;

	idev->name = "Tablet Mode Switch";
	idev->phys = acpi_device_hid(adev);

	idev->id.bustype = BUS_HOST;
	idev->id.version = 1;
	idev->id.product = 0;
	idev->open = chromeos_tbmc_open;

	input_set_drvdata(idev, adev);
	adev->driver_data = idev;

	input_set_capability(idev, EV_SW, SW_TABLET_MODE);
	ret = input_register_device(idev);
	if (ret) {
		dev_err(dev, "cannot register input device\n");
		return ret;
	}
	return 0;
}

