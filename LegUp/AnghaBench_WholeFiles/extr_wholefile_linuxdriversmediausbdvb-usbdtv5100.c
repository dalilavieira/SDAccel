#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct usb_interface {int dummy; } ;
struct usb_device_id {int dummy; } ;
struct usb_device {int dummy; } ;
struct rc_map_table {int scancode; } ;
struct i2c_msg {int flags; int addr; int* buf; int len; } ;
struct i2c_adapter {int dummy; } ;
struct dvb_usb_device {int /*<<< orphan*/  i2c_mutex; struct usb_device* udev; struct dtv5100_state* priv; } ;
struct dvb_usb_adapter {TYPE_3__* dev; TYPE_2__* fe_adap; } ;
struct dtv5100_state {int /*<<< orphan*/ * data; } ;
struct TYPE_11__ {int request; int value; int index; } ;
struct TYPE_7__ {int /*<<< orphan*/ * i2c_gate_ctrl; } ;
struct TYPE_10__ {TYPE_1__ ops; } ;
struct TYPE_9__ {int /*<<< orphan*/  i2c_adap; } ;
struct TYPE_8__ {TYPE_4__* fe; } ;

/* Variables and functions */
 int DTV5100_DEMOD_ADDR ; 
 int DTV5100_DEMOD_READ ; 
 int DTV5100_DEMOD_WRITE ; 
 int DTV5100_TUNER_READ ; 
 int DTV5100_TUNER_WRITE ; 
 int /*<<< orphan*/  DTV5100_USB_TIMEOUT ; 
 int EAGAIN ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 int I2C_M_RD ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int USB_DIR_IN ; 
 int USB_DIR_OUT ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  adapter_nr ; 
 TYPE_6__* dtv5100_init ; 
 int /*<<< orphan*/  dtv5100_properties ; 
 int /*<<< orphan*/  dtv5100_qt1010_config ; 
 int /*<<< orphan*/  dtv5100_zl10353_config ; 
 TYPE_4__* dvb_attach (int /*<<< orphan*/ ,TYPE_4__*,int /*<<< orphan*/ *,...) ; 
 int dvb_usb_device_init (struct usb_interface*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct dvb_usb_device* i2c_get_adapdata (struct i2c_adapter*) ; 
 struct usb_device* interface_to_usbdev (struct usb_interface*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qt1010_attach ; 
 int usb_control_msg (struct usb_device*,int /*<<< orphan*/ ,int,int,int,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  warn (char*,int) ; 
 int /*<<< orphan*/  zl10353_attach ; 

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

__attribute__((used)) static int dtv5100_i2c_msg(struct dvb_usb_device *d, u8 addr,
			   u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
	struct dtv5100_state *st = d->priv;
	u8 request;
	u8 type;
	u16 value;
	u16 index;

	switch (wlen) {
	case 1:
		/* write { reg }, read { value } */
		request = (addr == DTV5100_DEMOD_ADDR ? DTV5100_DEMOD_READ :
							DTV5100_TUNER_READ);
		type = USB_TYPE_VENDOR | USB_DIR_IN;
		value = 0;
		break;
	case 2:
		/* write { reg, value } */
		request = (addr == DTV5100_DEMOD_ADDR ? DTV5100_DEMOD_WRITE :
							DTV5100_TUNER_WRITE);
		type = USB_TYPE_VENDOR | USB_DIR_OUT;
		value = wbuf[1];
		break;
	default:
		warn("wlen = %x, aborting.", wlen);
		return -EINVAL;
	}
	index = (addr << 8) + wbuf[0];

	memcpy(st->data, rbuf, rlen);
	msleep(1); /* avoid I2C errors */
	return usb_control_msg(d->udev, usb_rcvctrlpipe(d->udev, 0), request,
			       type, value, index, st->data, rlen,
			       DTV5100_USB_TIMEOUT);
}

__attribute__((used)) static int dtv5100_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
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
			if (dtv5100_i2c_msg(d, msg[i].addr, msg[i].buf,
					    msg[i].len, msg[i+1].buf,
					    msg[i+1].len) < 0)
				break;
			i++;
		} else if (dtv5100_i2c_msg(d, msg[i].addr, msg[i].buf,
					   msg[i].len, NULL, 0) < 0)
				break;
	}

	mutex_unlock(&d->i2c_mutex);
	return i;
}

__attribute__((used)) static u32 dtv5100_i2c_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_I2C;
}

__attribute__((used)) static int dtv5100_frontend_attach(struct dvb_usb_adapter *adap)
{
	adap->fe_adap[0].fe = dvb_attach(zl10353_attach, &dtv5100_zl10353_config,
			      &adap->dev->i2c_adap);
	if (adap->fe_adap[0].fe == NULL)
		return -EIO;

	/* disable i2c gate, or it won't work... is this safe? */
	adap->fe_adap[0].fe->ops.i2c_gate_ctrl = NULL;

	return 0;
}

__attribute__((used)) static int dtv5100_tuner_attach(struct dvb_usb_adapter *adap)
{
	return dvb_attach(qt1010_attach,
			  adap->fe_adap[0].fe, &adap->dev->i2c_adap,
			  &dtv5100_qt1010_config) == NULL ? -ENODEV : 0;
}

__attribute__((used)) static int dtv5100_probe(struct usb_interface *intf,
			 const struct usb_device_id *id)
{
	int i, ret;
	struct usb_device *udev = interface_to_usbdev(intf);

	/* initialize non qt1010/zl10353 part? */
	for (i = 0; dtv5100_init[i].request; i++) {
		ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
				      dtv5100_init[i].request,
				      USB_TYPE_VENDOR | USB_DIR_OUT,
				      dtv5100_init[i].value,
				      dtv5100_init[i].index, NULL, 0,
				      DTV5100_USB_TIMEOUT);
		if (ret)
			return ret;
	}

	ret = dvb_usb_device_init(intf, &dtv5100_properties,
				  THIS_MODULE, NULL, adapter_nr);
	if (ret)
		return ret;

	return 0;
}

