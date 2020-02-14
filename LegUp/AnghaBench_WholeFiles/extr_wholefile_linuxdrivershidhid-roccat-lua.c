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
typedef  int /*<<< orphan*/  uint ;
struct TYPE_3__ {int /*<<< orphan*/  kobj; } ;
struct usb_interface {TYPE_1__ dev; } ;
struct usb_device {int dummy; } ;
struct lua_device {int /*<<< orphan*/  lua_lock; } ;
struct kobject {int dummy; } ;
struct hid_device_id {int dummy; } ;
struct TYPE_4__ {struct device* parent; } ;
struct hid_device {TYPE_2__ dev; } ;
struct file {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  size_t loff_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_CONNECT_DEFAULT ; 
 struct hid_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 struct lua_device* hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_hw_stop (struct hid_device*) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,struct lua_device*) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 int /*<<< orphan*/  kfree (struct lua_device*) ; 
 struct device* kobj_to_dev (struct kobject*) ; 
 struct lua_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_control_attr ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int roccat_common2_receive (struct usb_device*,int /*<<< orphan*/ ,char*,size_t) ; 
 int roccat_common2_send (struct usb_device*,int /*<<< orphan*/ ,void const*,size_t) ; 
 int sysfs_create_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct usb_interface* to_usb_interface (struct device*) ; 

__attribute__((used)) static ssize_t lua_sysfs_read(struct file *fp, struct kobject *kobj,
		char *buf, loff_t off, size_t count,
		size_t real_size, uint command)
{
	struct device *dev = kobj_to_dev(kobj);
	struct lua_device *lua = hid_get_drvdata(dev_get_drvdata(dev));
	struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
	int retval;

	if (off >= real_size)
		return 0;

	if (off != 0 || count != real_size)
		return -EINVAL;

	mutex_lock(&lua->lua_lock);
	retval = roccat_common2_receive(usb_dev, command, buf, real_size);
	mutex_unlock(&lua->lua_lock);

	return retval ? retval : real_size;
}

__attribute__((used)) static ssize_t lua_sysfs_write(struct file *fp, struct kobject *kobj,
		void const *buf, loff_t off, size_t count,
		size_t real_size, uint command)
{
	struct device *dev = kobj_to_dev(kobj);
	struct lua_device *lua = hid_get_drvdata(dev_get_drvdata(dev));
	struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
	int retval;

	if (off != 0 || count != real_size)
		return -EINVAL;

	mutex_lock(&lua->lua_lock);
	retval = roccat_common2_send(usb_dev, command, buf, real_size);
	mutex_unlock(&lua->lua_lock);

	return retval ? retval : real_size;
}

__attribute__((used)) static int lua_create_sysfs_attributes(struct usb_interface *intf)
{
	return sysfs_create_bin_file(&intf->dev.kobj, &lua_control_attr);
}

__attribute__((used)) static void lua_remove_sysfs_attributes(struct usb_interface *intf)
{
	sysfs_remove_bin_file(&intf->dev.kobj, &lua_control_attr);
}

__attribute__((used)) static int lua_init_lua_device_struct(struct usb_device *usb_dev,
		struct lua_device *lua)
{
	mutex_init(&lua->lua_lock);

	return 0;
}

__attribute__((used)) static int lua_init_specials(struct hid_device *hdev)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	struct usb_device *usb_dev = interface_to_usbdev(intf);
	struct lua_device *lua;
	int retval;

	lua = kzalloc(sizeof(*lua), GFP_KERNEL);
	if (!lua) {
		hid_err(hdev, "can't alloc device descriptor\n");
		return -ENOMEM;
	}
	hid_set_drvdata(hdev, lua);

	retval = lua_init_lua_device_struct(usb_dev, lua);
	if (retval) {
		hid_err(hdev, "couldn't init struct lua_device\n");
		goto exit;
	}

	retval = lua_create_sysfs_attributes(intf);
	if (retval) {
		hid_err(hdev, "cannot create sysfs files\n");
		goto exit;
	}

	return 0;
exit:
	kfree(lua);
	return retval;
}

__attribute__((used)) static void lua_remove_specials(struct hid_device *hdev)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	struct lua_device *lua;

	lua_remove_sysfs_attributes(intf);

	lua = hid_get_drvdata(hdev);
	kfree(lua);
}

__attribute__((used)) static int lua_probe(struct hid_device *hdev,
		const struct hid_device_id *id)
{
	int retval;

	retval = hid_parse(hdev);
	if (retval) {
		hid_err(hdev, "parse failed\n");
		goto exit;
	}

	retval = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
	if (retval) {
		hid_err(hdev, "hw start failed\n");
		goto exit;
	}

	retval = lua_init_specials(hdev);
	if (retval) {
		hid_err(hdev, "couldn't install mouse\n");
		goto exit_stop;
	}

	return 0;

exit_stop:
	hid_hw_stop(hdev);
exit:
	return retval;
}

__attribute__((used)) static void lua_remove(struct hid_device *hdev)
{
	lua_remove_specials(hdev);
	hid_hw_stop(hdev);
}

