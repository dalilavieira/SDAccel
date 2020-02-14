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
typedef  int u8 ;
typedef  int u16 ;
struct usb_device {int /*<<< orphan*/  dev; } ;
struct hexline {int len; int addr; int type; int* data; int chk; } ;
struct firmware {int size; int /*<<< orphan*/ * data; } ;
struct TYPE_2__ {int cs_reg; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int /*<<< orphan*/  USB_TYPE_VENDOR ; 
 TYPE_1__* cypress ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int,...) ; 
 int /*<<< orphan*/  kfree (struct hexline*) ; 
 struct hexline* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (struct hexline*,int /*<<< orphan*/ ,int) ; 
 int usb_control_msg (struct usb_device*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int,int*,int,int) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int usb_cypress_writemem(struct usb_device *udev, u16 addr, u8 *data,
		u8 len)
{
	return usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
			0xa0, USB_TYPE_VENDOR, addr, 0x00, data, len, 5000);
}

__attribute__((used)) static int cypress_get_hexline(const struct firmware *fw,
				struct hexline *hx, int *pos)
{
	u8 *b = (u8 *) &fw->data[*pos];
	int data_offs = 4;

	if (*pos >= fw->size)
		return 0;

	memset(hx, 0, sizeof(struct hexline));
	hx->len = b[0];

	if ((*pos + hx->len + 4) >= fw->size)
		return -EINVAL;

	hx->addr = b[1] | (b[2] << 8);
	hx->type = b[3];

	if (hx->type == 0x04) {
		/* b[4] and b[5] are the Extended linear address record data
		 * field */
		hx->addr |= (b[4] << 24) | (b[5] << 16);
	}

	memcpy(hx->data, &b[data_offs], hx->len);
	hx->chk = b[hx->len + data_offs];
	*pos += hx->len + 5;

	return *pos;
}

int cypress_load_firmware(struct usb_device *udev,
		const struct firmware *fw, int type)
{
	struct hexline *hx;
	int ret, pos = 0;

	hx = kmalloc(sizeof(*hx), GFP_KERNEL);
	if (!hx)
		return -ENOMEM;

	/* stop the CPU */
	hx->data[0] = 1;
	ret = usb_cypress_writemem(udev, cypress[type].cs_reg, hx->data, 1);
	if (ret != 1) {
		dev_err(&udev->dev, "%s: CPU stop failed=%d\n",
				KBUILD_MODNAME, ret);
		ret = -EIO;
		goto err_kfree;
	}

	/* write firmware to memory */
	for (;;) {
		ret = cypress_get_hexline(fw, hx, &pos);
		if (ret < 0)
			goto err_kfree;
		else if (ret == 0)
			break;

		ret = usb_cypress_writemem(udev, hx->addr, hx->data, hx->len);
		if (ret < 0) {
			goto err_kfree;
		} else if (ret != hx->len) {
			dev_err(&udev->dev,
					"%s: error while transferring firmware (transferred size=%d, block size=%d)\n",
					KBUILD_MODNAME, ret, hx->len);
			ret = -EIO;
			goto err_kfree;
		}
	}

	/* start the CPU */
	hx->data[0] = 0;
	ret = usb_cypress_writemem(udev, cypress[type].cs_reg, hx->data, 1);
	if (ret != 1) {
		dev_err(&udev->dev, "%s: CPU start failed=%d\n",
				KBUILD_MODNAME, ret);
		ret = -EIO;
		goto err_kfree;
	}

	ret = 0;
err_kfree:
	kfree(hx);
	return ret;
}

