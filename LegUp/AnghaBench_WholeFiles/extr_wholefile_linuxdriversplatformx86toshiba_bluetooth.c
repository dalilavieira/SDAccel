#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct toshiba_bluetooth_dev {int killswitch; int plugged; int powered; scalar_t__ rfk; struct acpi_device* acpi_dev; } ;
struct rfkill {int dummy; } ;
struct acpi_device {int /*<<< orphan*/  handle; int /*<<< orphan*/  dev; struct toshiba_bluetooth_dev* driver_data; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int BT_KILLSWITCH_MASK ; 
 int BT_PLUGGED_MASK ; 
 int BT_POWER_MASK ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  RFKILL_TYPE_BLUETOOTH ; 
 struct toshiba_bluetooth_dev* acpi_driver_data (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_evaluate_integer (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  acpi_evaluate_object (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct toshiba_bluetooth_dev*) ; 
 int /*<<< orphan*/  kfree (struct toshiba_bluetooth_dev*) ; 
 struct toshiba_bluetooth_dev* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int,int,int,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  rfk_ops ; 
 scalar_t__ rfkill_alloc (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct toshiba_bluetooth_dev*) ; 
 int /*<<< orphan*/  rfkill_destroy (scalar_t__) ; 
 int rfkill_register (scalar_t__) ; 
 int /*<<< orphan*/  rfkill_set_hw_state (scalar_t__,int) ; 
 int /*<<< orphan*/  rfkill_unregister (scalar_t__) ; 

__attribute__((used)) static int toshiba_bluetooth_present(acpi_handle handle)
{
	acpi_status result;
	u64 bt_present;

	/*
	 * Some Toshiba laptops may have a fake TOS6205 device in
	 * their ACPI BIOS, so query the _STA method to see if there
	 * is really anything there.
	 */
	result = acpi_evaluate_integer(handle, "_STA", NULL, &bt_present);
	if (ACPI_FAILURE(result)) {
		pr_err("ACPI call to query Bluetooth presence failed\n");
		return -ENXIO;
	}

	if (!bt_present) {
		pr_info("Bluetooth device not present\n");
		return -ENODEV;
	}

	return 0;
}

__attribute__((used)) static int toshiba_bluetooth_status(acpi_handle handle)
{
	acpi_status result;
	u64 status;

	result = acpi_evaluate_integer(handle, "BTST", NULL, &status);
	if (ACPI_FAILURE(result)) {
		pr_err("Could not get Bluetooth device status\n");
		return -ENXIO;
	}

	return status;
}

__attribute__((used)) static int toshiba_bluetooth_enable(acpi_handle handle)
{
	acpi_status result;

	result = acpi_evaluate_object(handle, "AUSB", NULL, NULL);
	if (ACPI_FAILURE(result)) {
		pr_err("Could not attach USB Bluetooth device\n");
		return -ENXIO;
	}

	result = acpi_evaluate_object(handle, "BTPO", NULL, NULL);
	if (ACPI_FAILURE(result)) {
		pr_err("Could not power ON Bluetooth device\n");
		return -ENXIO;
	}

	return 0;
}

__attribute__((used)) static int toshiba_bluetooth_disable(acpi_handle handle)
{
	acpi_status result;

	result = acpi_evaluate_object(handle, "BTPF", NULL, NULL);
	if (ACPI_FAILURE(result)) {
		pr_err("Could not power OFF Bluetooth device\n");
		return -ENXIO;
	}

	result = acpi_evaluate_object(handle, "DUSB", NULL, NULL);
	if (ACPI_FAILURE(result)) {
		pr_err("Could not detach USB Bluetooth device\n");
		return -ENXIO;
	}

	return 0;
}

__attribute__((used)) static int toshiba_bluetooth_sync_status(struct toshiba_bluetooth_dev *bt_dev)
{
	int status;

	status = toshiba_bluetooth_status(bt_dev->acpi_dev->handle);
	if (status < 0) {
		pr_err("Could not sync bluetooth device status\n");
		return status;
	}

	bt_dev->killswitch = (status & BT_KILLSWITCH_MASK) ? true : false;
	bt_dev->plugged = (status & BT_PLUGGED_MASK) ? true : false;
	bt_dev->powered = (status & BT_POWER_MASK) ? true : false;

	pr_debug("Bluetooth status %d killswitch %d plugged %d powered %d\n",
		 status, bt_dev->killswitch, bt_dev->plugged, bt_dev->powered);

	return 0;
}

__attribute__((used)) static int bt_rfkill_set_block(void *data, bool blocked)
{
	struct toshiba_bluetooth_dev *bt_dev = data;
	int ret;

	ret = toshiba_bluetooth_sync_status(bt_dev);
	if (ret)
		return ret;

	if (!bt_dev->killswitch)
		return 0;

	if (blocked)
		ret = toshiba_bluetooth_disable(bt_dev->acpi_dev->handle);
	else
		ret = toshiba_bluetooth_enable(bt_dev->acpi_dev->handle);

	return ret;
}

__attribute__((used)) static void bt_rfkill_poll(struct rfkill *rfkill, void *data)
{
	struct toshiba_bluetooth_dev *bt_dev = data;

	if (toshiba_bluetooth_sync_status(bt_dev))
		return;

	/*
	 * Note the Toshiba Bluetooth RFKill switch seems to be a strange
	 * fish. It only provides a BT event when the switch is flipped to
	 * the 'on' position. When flipping it to 'off', the USB device is
	 * simply pulled away underneath us, without any BT event being
	 * delivered.
	 */
	rfkill_set_hw_state(bt_dev->rfk, !bt_dev->killswitch);
}

__attribute__((used)) static void toshiba_bt_rfkill_notify(struct acpi_device *device, u32 event)
{
	struct toshiba_bluetooth_dev *bt_dev = acpi_driver_data(device);

	if (toshiba_bluetooth_sync_status(bt_dev))
		return;

	rfkill_set_hw_state(bt_dev->rfk, !bt_dev->killswitch);
}

__attribute__((used)) static int toshiba_bt_rfkill_add(struct acpi_device *device)
{
	struct toshiba_bluetooth_dev *bt_dev;
	int result;

	result = toshiba_bluetooth_present(device->handle);
	if (result)
		return result;

	pr_info("Toshiba ACPI Bluetooth device driver\n");

	bt_dev = kzalloc(sizeof(*bt_dev), GFP_KERNEL);
	if (!bt_dev)
		return -ENOMEM;
	bt_dev->acpi_dev = device;
	device->driver_data = bt_dev;
	dev_set_drvdata(&device->dev, bt_dev);

	result = toshiba_bluetooth_sync_status(bt_dev);
	if (result) {
		kfree(bt_dev);
		return result;
	}

	bt_dev->rfk = rfkill_alloc("Toshiba Bluetooth",
				   &device->dev,
				   RFKILL_TYPE_BLUETOOTH,
				   &rfk_ops,
				   bt_dev);
	if (!bt_dev->rfk) {
		pr_err("Unable to allocate rfkill device\n");
		kfree(bt_dev);
		return -ENOMEM;
	}

	rfkill_set_hw_state(bt_dev->rfk, !bt_dev->killswitch);

	result = rfkill_register(bt_dev->rfk);
	if (result) {
		pr_err("Unable to register rfkill device\n");
		rfkill_destroy(bt_dev->rfk);
		kfree(bt_dev);
	}

	return result;
}

__attribute__((used)) static int toshiba_bt_rfkill_remove(struct acpi_device *device)
{
	struct toshiba_bluetooth_dev *bt_dev = acpi_driver_data(device);

	/* clean up */
	if (bt_dev->rfk) {
		rfkill_unregister(bt_dev->rfk);
		rfkill_destroy(bt_dev->rfk);
	}

	kfree(bt_dev);

	return toshiba_bluetooth_disable(device->handle);
}

