#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_5__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct i2c_msg {int flags; int addr; int* buf; int len; } ;
struct i2c_adapter {int dummy; } ;
struct dvb_usb_device {TYPE_1__* udev; int /*<<< orphan*/  i2c_mutex; } ;
struct dvb_usb_adapter {int /*<<< orphan*/ ** fe; } ;
struct TYPE_7__ {int /*<<< orphan*/  i2c_adap; } ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
#define  AU6610_REQ_I2C_READ 129 
 int AU6610_REQ_I2C_WRITE ; 
#define  AU6610_REQ_USB_READ 128 
 int /*<<< orphan*/  AU6610_USB_TIMEOUT ; 
 int EAGAIN ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int USB_DIR_IN ; 
 int USB_TYPE_VENDOR ; 
 TYPE_5__* adap_to_d (struct dvb_usb_adapter*) ; 
 int /*<<< orphan*/  au6610_qt1010_config ; 
 int /*<<< orphan*/  au6610_zl10353_config ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * dvb_attach (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  dvb_usb_dbg_usb_control_msg (TYPE_1__*,int,int,int,int,int*,int) ; 
 struct dvb_usb_device* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qt1010_attach ; 
 int usb_control_msg (TYPE_1__*,int /*<<< orphan*/ ,int,int,int,int,int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int usb_set_interface (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  zl10353_attach ; 

__attribute__((used)) static int au6610_usb_msg(struct dvb_usb_device *d, u8 operation, u8 addr,
			  u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
	int ret;
	u16 index;
	u8 *usb_buf;

	/*
	 * allocate enough for all known requests,
	 * read returns 5 and write 6 bytes
	 */
	usb_buf = kmalloc(6, GFP_KERNEL);
	if (!usb_buf)
		return -ENOMEM;

	switch (wlen) {
	case 1:
		index = wbuf[0] << 8;
		break;
	case 2:
		index = wbuf[0] << 8;
		index += wbuf[1];
		break;
	default:
		dev_err(&d->udev->dev, "%s: wlen=%d, aborting\n",
				KBUILD_MODNAME, wlen);
		ret = -EINVAL;
		goto error;
	}

	ret = usb_control_msg(d->udev, usb_rcvctrlpipe(d->udev, 0), operation,
			      USB_TYPE_VENDOR|USB_DIR_IN, addr << 1, index,
			      usb_buf, 6, AU6610_USB_TIMEOUT);

	dvb_usb_dbg_usb_control_msg(d->udev, operation,
			(USB_TYPE_VENDOR|USB_DIR_IN), addr << 1, index,
			usb_buf, 6);

	if (ret < 0)
		goto error;

	switch (operation) {
	case AU6610_REQ_I2C_READ:
	case AU6610_REQ_USB_READ:
		/* requested value is always 5th byte in buffer */
		rbuf[0] = usb_buf[4];
	}
error:
	kfree(usb_buf);
	return ret;
}

__attribute__((used)) static int au6610_i2c_msg(struct dvb_usb_device *d, u8 addr,
			  u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
	u8 request;
	u8 wo = (rbuf == NULL || rlen == 0); /* write-only */

	if (wo) {
		request = AU6610_REQ_I2C_WRITE;
	} else { /* rw */
		request = AU6610_REQ_I2C_READ;
	}

	return au6610_usb_msg(d, request, addr, wbuf, wlen, rbuf, rlen);
}

__attribute__((used)) static int au6610_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
			   int num)
{
	struct dvb_usb_device *d = i2c_get_adapdata(adap);
	int i;

	if (num > 2)
		return -EINVAL;

	if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
		return -EAGAIN;

	for (i = 0; i < num; i++) {
		/* write/read request */
		if (i+1 < num && (msg[i+1].flags & I2C_M_RD)) {
			if (au6610_i2c_msg(d, msg[i].addr, msg[i].buf,
					   msg[i].len, msg[i+1].buf,
					   msg[i+1].len) < 0)
				break;
			i++;
		} else if (au6610_i2c_msg(d, msg[i].addr, msg[i].buf,
					       msg[i].len, NULL, 0) < 0)
				break;
	}

	mutex_unlock(&d->i2c_mutex);
	return i;
}

__attribute__((used)) static u32 au6610_i2c_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_I2C;
}

__attribute__((used)) static int au6610_zl10353_frontend_attach(struct dvb_usb_adapter *adap)
{
	adap->fe[0] = dvb_attach(zl10353_attach, &au6610_zl10353_config,
			&adap_to_d(adap)->i2c_adap);
	if (adap->fe[0] == NULL)
		return -ENODEV;

	return 0;
}

__attribute__((used)) static int au6610_qt1010_tuner_attach(struct dvb_usb_adapter *adap)
{
	return dvb_attach(qt1010_attach, adap->fe[0],
			&adap_to_d(adap)->i2c_adap,
			&au6610_qt1010_config) == NULL ? -ENODEV : 0;
}

__attribute__((used)) static int au6610_init(struct dvb_usb_device *d)
{
	/* TODO: this functionality belongs likely to the streaming control */
	/* bInterfaceNumber 0, bAlternateSetting 5 */
	return usb_set_interface(d->udev, 0, 5);
}

