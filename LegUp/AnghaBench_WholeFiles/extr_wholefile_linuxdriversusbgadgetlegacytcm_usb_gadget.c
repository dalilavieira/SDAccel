#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct usb_function_instance {int dummy; } ;
struct usb_configuration {int dummy; } ;
struct usb_composite_dev {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  iConfiguration; } ;
struct TYPE_7__ {int /*<<< orphan*/  iSerialNumber; int /*<<< orphan*/  iProduct; int /*<<< orphan*/  iManufacturer; } ;
struct TYPE_6__ {int /*<<< orphan*/  id; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IS_ERR_OR_NULL (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 size_t USB_GADGET_MANUFACTURER_IDX ; 
 size_t USB_GADGET_PRODUCT_IDX ; 
 size_t USB_GADGET_SERIAL_IDX ; 
 size_t USB_G_STR_CONFIG ; 
 int /*<<< orphan*/  coverwrite ; 
 int /*<<< orphan*/  f_tcm ; 
 int /*<<< orphan*/  fi_tcm ; 
 int usb_add_config (struct usb_composite_dev*,TYPE_3__*,int (*) (struct usb_configuration*)) ; 
 int usb_add_function (struct usb_configuration*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_composite_overwrite_options (struct usb_composite_dev*,int /*<<< orphan*/ *) ; 
 int usb_composite_probe (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_composite_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_get_function (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_put_function (int /*<<< orphan*/ ) ; 
 int usb_string_ids_tab (struct usb_composite_dev*,TYPE_1__*) ; 
 TYPE_3__ usbg_config_driver ; 
 TYPE_2__ usbg_device_desc ; 
 int /*<<< orphan*/  usbg_driver ; 
 TYPE_1__* usbg_us_strings ; 

__attribute__((used)) static int guas_unbind(struct usb_composite_dev *cdev)
{
	if (!IS_ERR_OR_NULL(f_tcm))
		usb_put_function(f_tcm);

	return 0;
}

__attribute__((used)) static int tcm_do_config(struct usb_configuration *c)
{
	int status;

	f_tcm = usb_get_function(fi_tcm);
	if (IS_ERR(f_tcm))
		return PTR_ERR(f_tcm);

	status = usb_add_function(c, f_tcm);
	if (status < 0) {
		usb_put_function(f_tcm);
		return status;
	}

	return 0;
}

__attribute__((used)) static int usb_target_bind(struct usb_composite_dev *cdev)
{
	int ret;

	ret = usb_string_ids_tab(cdev, usbg_us_strings);
	if (ret)
		return ret;

	usbg_device_desc.iManufacturer =
		usbg_us_strings[USB_GADGET_MANUFACTURER_IDX].id;
	usbg_device_desc.iProduct = usbg_us_strings[USB_GADGET_PRODUCT_IDX].id;
	usbg_device_desc.iSerialNumber =
		usbg_us_strings[USB_GADGET_SERIAL_IDX].id;
	usbg_config_driver.iConfiguration =
		usbg_us_strings[USB_G_STR_CONFIG].id;

	ret = usb_add_config(cdev, &usbg_config_driver, tcm_do_config);
	if (ret)
		return ret;
	usb_composite_overwrite_options(cdev, &coverwrite);
	return 0;
}

__attribute__((used)) static int usbg_attach(struct usb_function_instance *f)
{
	return usb_composite_probe(&usbg_driver);
}

__attribute__((used)) static void usbg_detach(struct usb_function_instance *f)
{
	usb_composite_unregister(&usbg_driver);
}

