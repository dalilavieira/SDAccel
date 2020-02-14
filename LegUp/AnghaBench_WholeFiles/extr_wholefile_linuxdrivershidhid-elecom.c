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
struct hid_device {int product; } ;
typedef  int __u8 ;

/* Variables and functions */
 int MOUSE_BUTTONS_MAX ; 
#define  USB_DEVICE_ID_ELECOM_BM084 135 
#define  USB_DEVICE_ID_ELECOM_M_DT1DRBK 134 
#define  USB_DEVICE_ID_ELECOM_M_DT1URBK 133 
#define  USB_DEVICE_ID_ELECOM_M_HT1DRBK 132 
#define  USB_DEVICE_ID_ELECOM_M_HT1URBK 131 
#define  USB_DEVICE_ID_ELECOM_M_XT3DRBK 130 
#define  USB_DEVICE_ID_ELECOM_M_XT3URBK 129 
#define  USB_DEVICE_ID_ELECOM_M_XT4DRBK 128 
 int clamp (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  hid_info (struct hid_device*,char*) ; 

__attribute__((used)) static void mouse_button_fixup(struct hid_device *hdev,
			       __u8 *rdesc, unsigned int rsize,
			       int nbuttons)
{
	if (rsize < 32 || rdesc[12] != 0x95 ||
	    rdesc[14] != 0x75 || rdesc[15] != 0x01 ||
	    rdesc[20] != 0x29 || rdesc[30] != 0x75)
		return;
	hid_info(hdev, "Fixing up Elecom mouse button count\n");
	nbuttons = clamp(nbuttons, 0, MOUSE_BUTTONS_MAX);
	rdesc[13] = nbuttons;
	rdesc[21] = nbuttons;
	rdesc[31] = MOUSE_BUTTONS_MAX - nbuttons;
}

__attribute__((used)) static __u8 *elecom_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	switch (hdev->product) {
	case USB_DEVICE_ID_ELECOM_BM084:
		/* The BM084 Bluetooth mouse includes a non-existing horizontal
		 * wheel in the HID descriptor. */
		if (*rsize >= 48 && rdesc[46] == 0x05 && rdesc[47] == 0x0c) {
			hid_info(hdev, "Fixing up Elecom BM084 report descriptor\n");
			rdesc[47] = 0x00;
		}
		break;
	case USB_DEVICE_ID_ELECOM_M_XT3URBK:
	case USB_DEVICE_ID_ELECOM_M_XT3DRBK:
	case USB_DEVICE_ID_ELECOM_M_XT4DRBK:
		mouse_button_fixup(hdev, rdesc, *rsize, 6);
		break;
	case USB_DEVICE_ID_ELECOM_M_DT1URBK:
	case USB_DEVICE_ID_ELECOM_M_DT1DRBK:
	case USB_DEVICE_ID_ELECOM_M_HT1URBK:
	case USB_DEVICE_ID_ELECOM_M_HT1DRBK:
		mouse_button_fixup(hdev, rdesc, *rsize, 8);
		break;
	}
	return rdesc;
}

