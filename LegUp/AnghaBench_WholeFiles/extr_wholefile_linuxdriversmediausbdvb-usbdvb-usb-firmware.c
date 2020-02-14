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
struct rc_map_table {int scancode; } ;
struct hexline {int addr; int len; int chk; int* data; int type; } ;
struct firmware {int size; int /*<<< orphan*/ * data; } ;
struct dvb_usb_device_properties {int usb_ctrl; int (* download_firmware ) (struct usb_device*,struct firmware const*) ;int /*<<< orphan*/  firmware; } ;
struct TYPE_2__ {int cpu_cs_register; } ;

/* Variables and functions */
#define  CYPRESS_AN2135 131 
#define  CYPRESS_AN2235 130 
#define  CYPRESS_FX2 129 
#define  DEVICE_SPECIFIC 128 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  USB_TYPE_VENDOR ; 
 TYPE_1__* cypress ; 
 int /*<<< orphan*/  deb_fw (char*,int,int,int) ; 
 int dvb_usb_get_hexline (struct firmware const*,struct hexline*,int*) ; 
 int /*<<< orphan*/  err (char*,...) ; 
 int /*<<< orphan*/  info (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (struct hexline*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  release_firmware (struct firmware const*) ; 
 int request_firmware (struct firmware const**,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub1 (struct usb_device*,struct firmware const*) ; 
 int usb_control_msg (struct usb_device*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int,int*,int,int) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u8 rc5_custom(struct rc_map_table *key)
{
	return (key->scancode >> 8) & 0xff;
}

__attribute__((used)) static inline u8 rc5_data(struct rc_map_table *key)
{
	return key->scancode & 0xff;
}

__attribute__((used)) static inline u16 rc5_scan(struct rc_map_table *key)
{
	return key->scancode & 0xffff;
}

__attribute__((used)) static int usb_cypress_writemem(struct usb_device *udev,u16 addr,u8 *data, u8 len)
{
	return usb_control_msg(udev, usb_sndctrlpipe(udev,0),
			0xa0, USB_TYPE_VENDOR, addr, 0x00, data, len, 5000);
}

int usb_cypress_load_firmware(struct usb_device *udev, const struct firmware *fw, int type)
{
	struct hexline *hx;
	u8 *buf;
	int ret, pos = 0;
	u16 cpu_cs_register = cypress[type].cpu_cs_register;

	buf = kmalloc(sizeof(*hx), GFP_KERNEL);
	if (!buf)
		return -ENOMEM;
	hx = (struct hexline *)buf;

	/* stop the CPU */
	buf[0] = 1;
	if (usb_cypress_writemem(udev, cpu_cs_register, buf, 1) != 1)
		err("could not stop the USB controller CPU.");

	while ((ret = dvb_usb_get_hexline(fw, hx, &pos)) > 0) {
		deb_fw("writing to address 0x%04x (buffer: 0x%02x %02x)\n", hx->addr, hx->len, hx->chk);
		ret = usb_cypress_writemem(udev, hx->addr, hx->data, hx->len);

		if (ret != hx->len) {
			err("error while transferring firmware (transferred size: %d, block size: %d)",
				ret, hx->len);
			ret = -EINVAL;
			break;
		}
	}
	if (ret < 0) {
		err("firmware download failed at %d with %d",pos,ret);
		kfree(buf);
		return ret;
	}

	if (ret == 0) {
		/* restart the CPU */
		buf[0] = 0;
		if (usb_cypress_writemem(udev, cpu_cs_register, buf, 1) != 1) {
			err("could not restart the USB controller CPU.");
			ret = -EINVAL;
		}
	} else
		ret = -EIO;

	kfree(buf);

	return ret;
}

int dvb_usb_download_firmware(struct usb_device *udev, struct dvb_usb_device_properties *props)
{
	int ret;
	const struct firmware *fw = NULL;

	if ((ret = request_firmware(&fw, props->firmware, &udev->dev)) != 0) {
		err("did not find the firmware file '%s' (status %d). You can use <kernel_dir>/scripts/get_dvb_firmware to get the firmware",
			props->firmware,ret);
		return ret;
	}

	info("downloading firmware from file '%s'",props->firmware);

	switch (props->usb_ctrl) {
		case CYPRESS_AN2135:
		case CYPRESS_AN2235:
		case CYPRESS_FX2:
			ret = usb_cypress_load_firmware(udev, fw, props->usb_ctrl);
			break;
		case DEVICE_SPECIFIC:
			if (props->download_firmware)
				ret = props->download_firmware(udev,fw);
			else {
				err("BUG: driver didn't specified a download_firmware-callback, although it claims to have a DEVICE_SPECIFIC one.");
				ret = -EINVAL;
			}
			break;
		default:
			ret = -EINVAL;
			break;
	}

	release_firmware(fw);
	return ret;
}

int dvb_usb_get_hexline(const struct firmware *fw, struct hexline *hx,
			       int *pos)
{
	u8 *b = (u8 *) &fw->data[*pos];
	int data_offs = 4;
	if (*pos >= fw->size)
		return 0;

	memset(hx,0,sizeof(struct hexline));

	hx->len  = b[0];

	if ((*pos + hx->len + 4) >= fw->size)
		return -EINVAL;

	hx->addr = b[1] | (b[2] << 8);
	hx->type = b[3];

	if (hx->type == 0x04) {
		/* b[4] and b[5] are the Extended linear address record data field */
		hx->addr |= (b[4] << 24) | (b[5] << 16);
/*		hx->len -= 2;
		data_offs += 2; */
	}
	memcpy(hx->data,&b[data_offs],hx->len);
	hx->chk = b[hx->len + data_offs];

	*pos += hx->len + 5;

	return *pos;
}

