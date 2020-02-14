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
typedef  int uint8_t ;
typedef  int uint16_t ;
typedef  int uint ;
struct usb_device {int /*<<< orphan*/  dev; } ;
struct roccat_common2_device {int /*<<< orphan*/  lock; } ;
struct roccat_common2_control {int value; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  size_t loff_t ;
struct TYPE_4__ {TYPE_1__* parent; } ;
struct TYPE_3__ {struct device* parent; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_REQ_GET_REPORT ; 
 int /*<<< orphan*/  HID_REQ_SET_REPORT ; 
 int ROCCAT_COMMON_COMMAND_CONTROL ; 
#define  ROCCAT_COMMON_CONTROL_STATUS_BUSY 132 
#define  ROCCAT_COMMON_CONTROL_STATUS_CRITICAL 131 
#define  ROCCAT_COMMON_CONTROL_STATUS_CRITICAL_NEW 130 
#define  ROCCAT_COMMON_CONTROL_STATUS_INVALID 129 
#define  ROCCAT_COMMON_CONTROL_STATUS_OK 128 
 int /*<<< orphan*/  USB_CTRL_SET_TIMEOUT ; 
 int USB_DIR_IN ; 
 int USB_DIR_OUT ; 
 int USB_RECIP_INTERFACE ; 
 int USB_TYPE_CLASS ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_get_drvdata (struct device*) ; 
 struct roccat_common2_device* hid_get_drvdata (int /*<<< orphan*/ ) ; 
 struct usb_device* interface_to_usbdev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kmalloc (int,int /*<<< orphan*/ ) ; 
 char* kmemdup (void const*,int,int /*<<< orphan*/ ) ; 
 TYPE_2__* kobj_to_dev (struct kobject*) ; 
 int /*<<< orphan*/  memcpy (void*,char*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  to_usb_interface (struct device*) ; 
 int usb_control_msg (struct usb_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint16_t roccat_common2_feature_report(uint8_t report_id)
{
	return 0x300 | report_id;
}

int roccat_common2_receive(struct usb_device *usb_dev, uint report_id,
		void *data, uint size)
{
	char *buf;
	int len;

	buf = kmalloc(size, GFP_KERNEL);
	if (buf == NULL)
		return -ENOMEM;

	len = usb_control_msg(usb_dev, usb_rcvctrlpipe(usb_dev, 0),
			HID_REQ_GET_REPORT,
			USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_IN,
			roccat_common2_feature_report(report_id),
			0, buf, size, USB_CTRL_SET_TIMEOUT);

	memcpy(data, buf, size);
	kfree(buf);
	return ((len < 0) ? len : ((len != size) ? -EIO : 0));
}

int roccat_common2_send(struct usb_device *usb_dev, uint report_id,
		void const *data, uint size)
{
	char *buf;
	int len;

	buf = kmemdup(data, size, GFP_KERNEL);
	if (buf == NULL)
		return -ENOMEM;

	len = usb_control_msg(usb_dev, usb_sndctrlpipe(usb_dev, 0),
			HID_REQ_SET_REPORT,
			USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_OUT,
			roccat_common2_feature_report(report_id),
			0, buf, size, USB_CTRL_SET_TIMEOUT);

	kfree(buf);
	return ((len < 0) ? len : ((len != size) ? -EIO : 0));
}

__attribute__((used)) static int roccat_common2_receive_control_status(struct usb_device *usb_dev)
{
	int retval;
	struct roccat_common2_control control;

	do {
		msleep(50);
		retval = roccat_common2_receive(usb_dev,
				ROCCAT_COMMON_COMMAND_CONTROL,
				&control, sizeof(struct roccat_common2_control));

		if (retval)
			return retval;

		switch (control.value) {
		case ROCCAT_COMMON_CONTROL_STATUS_OK:
			return 0;
		case ROCCAT_COMMON_CONTROL_STATUS_BUSY:
			msleep(500);
			continue;
		case ROCCAT_COMMON_CONTROL_STATUS_INVALID:
		case ROCCAT_COMMON_CONTROL_STATUS_CRITICAL:
		case ROCCAT_COMMON_CONTROL_STATUS_CRITICAL_NEW:
			return -EINVAL;
		default:
			dev_err(&usb_dev->dev,
					"roccat_common2_receive_control_status: "
					"unknown response value 0x%x\n",
					control.value);
			return -EINVAL;
		}

	} while (1);
}

int roccat_common2_send_with_status(struct usb_device *usb_dev,
		uint command, void const *buf, uint size)
{
	int retval;

	retval = roccat_common2_send(usb_dev, command, buf, size);
	if (retval)
		return retval;

	msleep(100);

	return roccat_common2_receive_control_status(usb_dev);
}

int roccat_common2_device_init_struct(struct usb_device *usb_dev,
		struct roccat_common2_device *dev)
{
	mutex_init(&dev->lock);
	return 0;
}

ssize_t roccat_common2_sysfs_read(struct file *fp, struct kobject *kobj,
		char *buf, loff_t off, size_t count,
		size_t real_size, uint command)
{
	struct device *dev = kobj_to_dev(kobj)->parent->parent;
	struct roccat_common2_device *roccat_dev = hid_get_drvdata(dev_get_drvdata(dev));
	struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
	int retval;

	if (off >= real_size)
		return 0;

	if (off != 0 || count != real_size)
		return -EINVAL;

	mutex_lock(&roccat_dev->lock);
	retval = roccat_common2_receive(usb_dev, command, buf, real_size);
	mutex_unlock(&roccat_dev->lock);

	return retval ? retval : real_size;
}

ssize_t roccat_common2_sysfs_write(struct file *fp, struct kobject *kobj,
		void const *buf, loff_t off, size_t count,
		size_t real_size, uint command)
{
	struct device *dev = kobj_to_dev(kobj)->parent->parent;
	struct roccat_common2_device *roccat_dev = hid_get_drvdata(dev_get_drvdata(dev));
	struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
	int retval;

	if (off != 0 || count != real_size)
		return -EINVAL;

	mutex_lock(&roccat_dev->lock);
	retval = roccat_common2_send_with_status(usb_dev, command, buf, real_size);
	mutex_unlock(&roccat_dev->lock);

	return retval ? retval : real_size;
}

