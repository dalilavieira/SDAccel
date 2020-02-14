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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ u8 ;
struct usb_interface {TYPE_3__* cur_altsetting; } ;
struct usb_device {int dummy; } ;
struct savu_roccat_report {int /*<<< orphan*/ * data; int /*<<< orphan*/  type; } ;
struct savu_mouse_report_special {int /*<<< orphan*/ * data; int /*<<< orphan*/  type; } ;
struct roccat_common2_device {int chrdev_minor; int roccat_claimed; } ;
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
 scalar_t__ const SAVU_MOUSE_REPORT_NUMBER_SPECIAL ; 
 scalar_t__ USB_INTERFACE_PROTOCOL_MOUSE ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 struct roccat_common2_device* hid_get_drvdata (struct hid_device*) ; 
 int hid_hw_start (struct hid_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hid_hw_stop (struct hid_device*) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  hid_set_drvdata (struct hid_device*,struct roccat_common2_device*) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 int /*<<< orphan*/  kfree (struct roccat_common2_device*) ; 
 struct roccat_common2_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int roccat_common2_device_init_struct (struct usb_device*,struct roccat_common2_device*) ; 
 int roccat_connect (int /*<<< orphan*/ ,struct hid_device*,int) ; 
 int /*<<< orphan*/  roccat_disconnect (int) ; 
 int /*<<< orphan*/  roccat_report_event (int,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  savu_class ; 
 struct usb_interface* to_usb_interface (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int savu_init_specials(struct hid_device *hdev)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	struct usb_device *usb_dev = interface_to_usbdev(intf);
	struct roccat_common2_device *savu;
	int retval;

	if (intf->cur_altsetting->desc.bInterfaceProtocol
			!= USB_INTERFACE_PROTOCOL_MOUSE) {
		hid_set_drvdata(hdev, NULL);
		return 0;
	}

	savu = kzalloc(sizeof(*savu), GFP_KERNEL);
	if (!savu) {
		hid_err(hdev, "can't alloc device descriptor\n");
		return -ENOMEM;
	}
	hid_set_drvdata(hdev, savu);

	retval = roccat_common2_device_init_struct(usb_dev, savu);
	if (retval) {
		hid_err(hdev, "couldn't init Savu device\n");
		goto exit_free;
	}

	retval = roccat_connect(savu_class, hdev,
			sizeof(struct savu_roccat_report));
	if (retval < 0) {
		hid_err(hdev, "couldn't init char dev\n");
	} else {
		savu->chrdev_minor = retval;
		savu->roccat_claimed = 1;
	}

	return 0;
exit_free:
	kfree(savu);
	return retval;
}

__attribute__((used)) static void savu_remove_specials(struct hid_device *hdev)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	struct roccat_common2_device *savu;

	if (intf->cur_altsetting->desc.bInterfaceProtocol
			!= USB_INTERFACE_PROTOCOL_MOUSE)
		return;

	savu = hid_get_drvdata(hdev);
	if (savu->roccat_claimed)
		roccat_disconnect(savu->chrdev_minor);
	kfree(savu);
}

__attribute__((used)) static int savu_probe(struct hid_device *hdev,
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

	retval = savu_init_specials(hdev);
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

__attribute__((used)) static void savu_remove(struct hid_device *hdev)
{
	savu_remove_specials(hdev);
	hid_hw_stop(hdev);
}

__attribute__((used)) static void savu_report_to_chrdev(struct roccat_common2_device const *savu,
		u8 const *data)
{
	struct savu_roccat_report roccat_report;
	struct savu_mouse_report_special const *special_report;

	if (data[0] != SAVU_MOUSE_REPORT_NUMBER_SPECIAL)
		return;

	special_report = (struct savu_mouse_report_special const *)data;

	roccat_report.type = special_report->type;
	roccat_report.data[0] = special_report->data[0];
	roccat_report.data[1] = special_report->data[1];
	roccat_report_event(savu->chrdev_minor,
			(uint8_t const *)&roccat_report);
}

__attribute__((used)) static int savu_raw_event(struct hid_device *hdev,
		struct hid_report *report, u8 *data, int size)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	struct roccat_common2_device *savu = hid_get_drvdata(hdev);

	if (intf->cur_altsetting->desc.bInterfaceProtocol
			!= USB_INTERFACE_PROTOCOL_MOUSE)
		return 0;

	if (savu == NULL)
		return 0;

	if (savu->roccat_claimed)
		savu_report_to_chrdev(savu, data);

	return 0;
}

