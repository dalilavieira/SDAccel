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
struct usb_interface {TYPE_3__* cur_altsetting; } ;
struct hid_usage {int hid; } ;
struct hid_input {int dummy; } ;
struct hid_field {int dummy; } ;
struct hid_device_id {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct hid_device {scalar_t__ product; int rsize; TYPE_1__ dev; } ;
typedef  int __u8 ;
struct TYPE_5__ {unsigned short bInterfaceNumber; } ;
struct TYPE_6__ {TYPE_2__ desc; } ;

/* Variables and functions */
 unsigned int HID_CONNECT_DEFAULT ; 
 unsigned int HID_CONNECT_HIDDEV_FORCE ; 
 unsigned int HID_CONNECT_HIDINPUT ; 
 int HID_UP_CONSUMER ; 
 int HID_USAGE ; 
 int HID_USAGE_PAGE ; 
 int /*<<< orphan*/  KEY_BACK ; 
 int /*<<< orphan*/  KEY_CALC ; 
 int /*<<< orphan*/  KEY_COMPUTER ; 
 int /*<<< orphan*/  KEY_EMAIL ; 
 int /*<<< orphan*/  KEY_FAVORITES ; 
 int /*<<< orphan*/  KEY_FORWARD ; 
 int /*<<< orphan*/  KEY_MEDIA ; 
 int /*<<< orphan*/  KEY_REFRESH ; 
 int /*<<< orphan*/  KEY_SEARCH ; 
 int /*<<< orphan*/  KEY_STOP ; 
 int /*<<< orphan*/  KEY_WWW ; 
 scalar_t__ USB_DEVICE_ID_SAMSUNG_IR_REMOTE ; 
 scalar_t__ USB_DEVICE_ID_SAMSUNG_WIRELESS_KBD_MOUSE ; 
 int /*<<< orphan*/  dbg_hid (char*,int) ; 
 int /*<<< orphan*/  hid_err (struct hid_device*,char*) ; 
 int hid_hw_start (struct hid_device*,unsigned int) ; 
 int /*<<< orphan*/  hid_info (struct hid_device*,char*,unsigned int) ; 
 int hid_parse (struct hid_device*) ; 
 int /*<<< orphan*/  samsung_kbd_mouse_map_key_clear (int /*<<< orphan*/ ) ; 
 struct usb_interface* to_usb_interface (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void samsung_irda_dev_trace(struct hid_device *hdev,
		unsigned int rsize)
{
	hid_info(hdev, "fixing up Samsung IrDA %d byte report descriptor\n",
		 rsize);
}

__attribute__((used)) static __u8 *samsung_irda_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	if (*rsize == 184 && rdesc[175] == 0x25 && rdesc[176] == 0x40 &&
			rdesc[177] == 0x75 && rdesc[178] == 0x30 &&
			rdesc[179] == 0x95 && rdesc[180] == 0x01 &&
			rdesc[182] == 0x40) {
		samsung_irda_dev_trace(hdev, 184);
		rdesc[176] = 0xff;
		rdesc[178] = 0x08;
		rdesc[180] = 0x06;
		rdesc[182] = 0x42;
	} else
	if (*rsize == 203 && rdesc[192] == 0x15 && rdesc[193] == 0x0 &&
			rdesc[194] == 0x25 && rdesc[195] == 0x12) {
		samsung_irda_dev_trace(hdev, 203);
		rdesc[193] = 0x1;
		rdesc[195] = 0xf;
	} else
	if (*rsize == 135 && rdesc[124] == 0x15 && rdesc[125] == 0x0 &&
			rdesc[126] == 0x25 && rdesc[127] == 0x11) {
		samsung_irda_dev_trace(hdev, 135);
		rdesc[125] = 0x1;
		rdesc[127] = 0xe;
	} else
	if (*rsize == 171 && rdesc[160] == 0x15 && rdesc[161] == 0x0 &&
			rdesc[162] == 0x25 && rdesc[163] == 0x01) {
		samsung_irda_dev_trace(hdev, 171);
		rdesc[161] = 0x1;
		rdesc[163] = 0x3;
	}
	return rdesc;
}

__attribute__((used)) static int samsung_kbd_mouse_input_mapping(struct hid_device *hdev,
	struct hid_input *hi, struct hid_field *field, struct hid_usage *usage,
	unsigned long **bit, int *max)
{
	struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
	unsigned short ifnum = intf->cur_altsetting->desc.bInterfaceNumber;

	if (1 != ifnum || HID_UP_CONSUMER != (usage->hid & HID_USAGE_PAGE))
		return 0;

	dbg_hid("samsung wireless keyboard/mouse input mapping event [0x%x]\n",
		usage->hid & HID_USAGE);

	switch (usage->hid & HID_USAGE) {
	/* report 2 */
	case 0x183: samsung_kbd_mouse_map_key_clear(KEY_MEDIA); break;
	case 0x195: samsung_kbd_mouse_map_key_clear(KEY_EMAIL);	break;
	case 0x196: samsung_kbd_mouse_map_key_clear(KEY_CALC); break;
	case 0x197: samsung_kbd_mouse_map_key_clear(KEY_COMPUTER); break;
	case 0x22b: samsung_kbd_mouse_map_key_clear(KEY_SEARCH); break;
	case 0x22c: samsung_kbd_mouse_map_key_clear(KEY_WWW); break;
	case 0x22d: samsung_kbd_mouse_map_key_clear(KEY_BACK); break;
	case 0x22e: samsung_kbd_mouse_map_key_clear(KEY_FORWARD); break;
	case 0x22f: samsung_kbd_mouse_map_key_clear(KEY_FAVORITES); break;
	case 0x230: samsung_kbd_mouse_map_key_clear(KEY_REFRESH); break;
	case 0x231: samsung_kbd_mouse_map_key_clear(KEY_STOP); break;
	default:
		return 0;
	}

	return 1;
}

__attribute__((used)) static __u8 *samsung_report_fixup(struct hid_device *hdev, __u8 *rdesc,
	unsigned int *rsize)
{
	if (USB_DEVICE_ID_SAMSUNG_IR_REMOTE == hdev->product)
		rdesc = samsung_irda_report_fixup(hdev, rdesc, rsize);
	return rdesc;
}

__attribute__((used)) static int samsung_input_mapping(struct hid_device *hdev, struct hid_input *hi,
	struct hid_field *field, struct hid_usage *usage,
	unsigned long **bit, int *max)
{
	int ret = 0;

	if (USB_DEVICE_ID_SAMSUNG_WIRELESS_KBD_MOUSE == hdev->product)
		ret = samsung_kbd_mouse_input_mapping(hdev,
			hi, field, usage, bit, max);

	return ret;
}

__attribute__((used)) static int samsung_probe(struct hid_device *hdev,
		const struct hid_device_id *id)
{
	int ret;
	unsigned int cmask = HID_CONNECT_DEFAULT;

	ret = hid_parse(hdev);
	if (ret) {
		hid_err(hdev, "parse failed\n");
		goto err_free;
	}

	if (USB_DEVICE_ID_SAMSUNG_IR_REMOTE == hdev->product) {
		if (hdev->rsize == 184) {
			/* disable hidinput, force hiddev */
			cmask = (cmask & ~HID_CONNECT_HIDINPUT) |
				HID_CONNECT_HIDDEV_FORCE;
		}
	}

	ret = hid_hw_start(hdev, cmask);
	if (ret) {
		hid_err(hdev, "hw start failed\n");
		goto err_free;
	}

	return 0;
err_free:
	return ret;
}

