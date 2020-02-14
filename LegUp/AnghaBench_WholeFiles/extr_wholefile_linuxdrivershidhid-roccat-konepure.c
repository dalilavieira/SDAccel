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
typedef  scalar_t__ u8 ;
struct usb_interface {TYPE_3__* cur_altsetting; } ;
struct usb_device {int dummy; } ;
struct roccat_common2_device {int chrdev_minor; int roccat_claimed; } ;
struct konepure_mouse_report_button {int dummy; } ;
struct hid_report {int dummy; } ;
struct hid_device_id {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct hid_device {TYPE_1__ dev; } ;
struct TYPE_5__ {scalar_t__ bInterfaceProtocol; } ;
struct TYPE_6__ {TYPE_2__ desc; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HID_CONNECT_DEFAULT ; 
 scalar_t__ KONEPURE_MOUSE_REPORT_NUMBER_BUTTON ; 
 scalar_t__ USB_INTERFACE_PROTOCOL_MOUSE ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 struct roccat_common2_device* hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_hw_stop (struct hid_device*) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,struct roccat_common2_device*) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 int /*<<< orphan*/  kfree (struct roccat_common2_device*) ; 
 int /*<<< orphan*/  konepure_class ; 
 struct roccat_common2_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int roccat_common2_device_init_struct (struct usb_device*,struct roccat_common2_device*) ; 
 int roccat_connect (int /*<<< orphan*/ ,struct hid_device*,int) ; 
 int /*<<< orphan*/  roccat_disconnect (int) ; 
 int /*<<< orphan*/  roccat_report_event (int,scalar_t__*) ; 
 struct usb_interface* to_usb_interface (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int konepure_init_specials(struct hid_device *hdev)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	struct usb_device *usb_dev = interface_to_usbdev(intf);
	struct roccat_common2_device *konepure;
	int retval;

	if (intf->cur_altsetting->desc.bInterfaceProtocol
			!= USB_INTERFACE_PROTOCOL_MOUSE) {
		hid_set_drvdata(hdev, NULL);
		return 0;
	}

	konepure = kzalloc(sizeof(*konepure), GFP_KERNEL);
	if (!konepure) {
		hid_err(hdev, "can't alloc device descriptor\n");
		return -ENOMEM;
	}
	hid_set_drvdata(hdev, konepure);

	retval = roccat_common2_device_init_struct(usb_dev, konepure);
	if (retval) {
		hid_err(hdev, "couldn't init KonePure device\n");
		goto exit_free;
	}

	retval = roccat_connect(konepure_class, hdev,
			sizeof(struct konepure_mouse_report_button));
	if (retval < 0) {
		hid_err(hdev, "couldn't init char dev\n");
	} else {
		konepure->chrdev_minor = retval;
		konepure->roccat_claimed = 1;
	}

	return 0;
exit_free:
	kfree(konepure);
	return retval;
}

__attribute__((used)) static void konepure_remove_specials(struct hid_device *hdev)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	struct roccat_common2_device *konepure;

	if (intf->cur_altsetting->desc.bInterfaceProtocol
			!= USB_INTERFACE_PROTOCOL_MOUSE)
		return;

	konepure = hid_get_drvdata(hdev);
	if (konepure->roccat_claimed)
		roccat_disconnect(konepure->chrdev_minor);
	kfree(konepure);
}

__attribute__((used)) static int konepure_probe(struct hid_device *hdev,
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

	retval = konepure_init_specials(hdev);
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

__attribute__((used)) static void konepure_remove(struct hid_device *hdev)
{
	konepure_remove_specials(hdev);
	hid_hw_stop(hdev);
}

__attribute__((used)) static int konepure_raw_event(struct hid_device *hdev,
		struct hid_report *report, u8 *data, int size)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	struct roccat_common2_device *konepure = hid_get_drvdata(hdev);

	if (intf->cur_altsetting->desc.bInterfaceProtocol
			!= USB_INTERFACE_PROTOCOL_MOUSE)
		return 0;

	if (data[0] != KONEPURE_MOUSE_REPORT_NUMBER_BUTTON)
		return 0;

	if (konepure != NULL && konepure->roccat_claimed)
		roccat_report_event(konepure->chrdev_minor, data);

	return 0;
}

