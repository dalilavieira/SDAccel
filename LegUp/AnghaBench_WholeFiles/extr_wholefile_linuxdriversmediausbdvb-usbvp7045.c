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
struct usb_interface {int dummy; } ;
struct usb_device_id {int dummy; } ;
struct rc_map_table {int scancode; } ;
struct dvb_usb_device {int* priv; int /*<<< orphan*/  rc_dev; int /*<<< orphan*/  usb_mutex; int /*<<< orphan*/  udev; } ;
struct dvb_usb_adapter {struct dvb_usb_device* dev; TYPE_1__* fe_adap; } ;
struct TYPE_2__ {int /*<<< orphan*/  fe; } ;

/* Variables and functions */
 int EIO ; 
 int FW_VERSION_READ ; 
 int GET_EE_VALUE ; 
 int MAC_0_ADDR ; 
 int PRODUCT_STRING_READ ; 
 int /*<<< orphan*/  RC_PROTO_NEC ; 
 int /*<<< orphan*/  RC_SCANCODE_NEC (int /*<<< orphan*/ ,int) ; 
 int RC_VAL_READ ; 
 int SET_TUNER_POWER ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  TH_COMMAND_IN ; 
 int /*<<< orphan*/  TH_COMMAND_OUT ; 
 int TUNER_REG_READ ; 
 int USB_DIR_IN ; 
 int USB_DIR_OUT ; 
 int USB_TYPE_VENDOR ; 
 int VENDOR_STRING_READ ; 
 int /*<<< orphan*/  adapter_nr ; 
 int /*<<< orphan*/  deb_info (char*,...) ; 
 int /*<<< orphan*/  deb_rc (char*,int,int) ; 
 int /*<<< orphan*/  deb_xfer (char*,...) ; 
 int /*<<< orphan*/  debug_dump (int*,int,int /*<<< orphan*/  (*) (char*,int*)) ; 
 int dvb_usb_device_init (struct usb_interface*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  err (char*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rc_keydown (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int usb_control_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int,int) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vp7045_fe_attach (struct dvb_usb_device*) ; 
 int /*<<< orphan*/  vp7045_properties ; 

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

int vp7045_usb_op(struct dvb_usb_device *d, u8 cmd, u8 *out, int outlen, u8 *in, int inlen, int msec)
{
	int ret = 0;
	u8 *buf = d->priv;

	buf[0] = cmd;

	if (outlen > 19)
		outlen = 19;

	if (inlen > 11)
		inlen = 11;

	ret = mutex_lock_interruptible(&d->usb_mutex);
	if (ret)
		return ret;

	if (out != NULL && outlen > 0)
		memcpy(&buf[1], out, outlen);

	deb_xfer("out buffer: ");
	debug_dump(buf, outlen+1, deb_xfer);


	if (usb_control_msg(d->udev,
			usb_sndctrlpipe(d->udev,0),
			TH_COMMAND_OUT, USB_TYPE_VENDOR | USB_DIR_OUT, 0, 0,
			buf, 20, 2000) != 20) {
		err("USB control message 'out' went wrong.");
		ret = -EIO;
		goto unlock;
	}

	msleep(msec);

	if (usb_control_msg(d->udev,
			usb_rcvctrlpipe(d->udev,0),
			TH_COMMAND_IN, USB_TYPE_VENDOR | USB_DIR_IN, 0, 0,
			buf, 12, 2000) != 12) {
		err("USB control message 'in' went wrong.");
		ret = -EIO;
		goto unlock;
	}

	deb_xfer("in buffer: ");
	debug_dump(buf, 12, deb_xfer);

	if (in != NULL && inlen > 0)
		memcpy(in, &buf[1], inlen);

unlock:
	mutex_unlock(&d->usb_mutex);

	return ret;
}

u8 vp7045_read_reg(struct dvb_usb_device *d, u8 reg)
{
	u8 obuf[2] = { 0 },v;
	obuf[1] = reg;

	vp7045_usb_op(d,TUNER_REG_READ,obuf,2,&v,1,30);

	return v;
}

__attribute__((used)) static int vp7045_power_ctrl(struct dvb_usb_device *d, int onoff)
{
	u8 v = onoff;
	return vp7045_usb_op(d,SET_TUNER_POWER,&v,1,NULL,0,150);
}

__attribute__((used)) static int vp7045_rc_query(struct dvb_usb_device *d)
{
	u8 key;
	vp7045_usb_op(d,RC_VAL_READ,NULL,0,&key,1,20);

	deb_rc("remote query key: %x %d\n",key,key);

	if (key != 0x44) {
		/*
		 * The 8 bit address isn't available, but since the remote uses
		 * address 0 we'll use that. nec repeats are ignored too, even
		 * though the remote sends them.
		 */
		rc_keydown(d->rc_dev, RC_PROTO_NEC, RC_SCANCODE_NEC(0, key), 0);
	}

	return 0;
}

__attribute__((used)) static int vp7045_read_eeprom(struct dvb_usb_device *d,u8 *buf, int len, int offset)
{
	int i = 0;
	u8 v,br[2];
	for (i=0; i < len; i++) {
		v = offset + i;
		vp7045_usb_op(d,GET_EE_VALUE,&v,1,br,2,5);
		buf[i] = br[1];
	}
	deb_info("VP7045 EEPROM read (offs: %d, len: %d) : ",offset, i);
	debug_dump(buf,i,deb_info);
	return 0;
}

__attribute__((used)) static int vp7045_read_mac_addr(struct dvb_usb_device *d,u8 mac[6])
{
	return vp7045_read_eeprom(d,mac, 6, MAC_0_ADDR);
}

__attribute__((used)) static int vp7045_frontend_attach(struct dvb_usb_adapter *adap)
{
	u8 buf[255] = { 0 };

	vp7045_usb_op(adap->dev,VENDOR_STRING_READ,NULL,0,buf,20,0);
	buf[10] = '\0';
	deb_info("firmware says: %s ",buf);

	vp7045_usb_op(adap->dev,PRODUCT_STRING_READ,NULL,0,buf,20,0);
	buf[10] = '\0';
	deb_info("%s ",buf);

	vp7045_usb_op(adap->dev,FW_VERSION_READ,NULL,0,buf,20,0);
	buf[10] = '\0';
	deb_info("v%s\n",buf);

/*	Dump the EEPROM */
/*	vp7045_read_eeprom(d,buf, 255, FX2_ID_ADDR); */

	adap->fe_adap[0].fe = vp7045_fe_attach(adap->dev);

	return 0;
}

__attribute__((used)) static int vp7045_usb_probe(struct usb_interface *intf,
		const struct usb_device_id *id)
{
	return dvb_usb_device_init(intf, &vp7045_properties,
				   THIS_MODULE, NULL, adapter_nr);
}

