#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct usb_interface {int /*<<< orphan*/  dev; } ;
struct usb_device_id {int dummy; } ;
struct i2c_adapter {int /*<<< orphan*/  name; struct osif_priv* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  class; int /*<<< orphan*/  owner; int /*<<< orphan*/  dev; } ;
struct osif_priv {TYPE_3__* usb_dev; struct i2c_adapter adapter; struct usb_interface* interface; int /*<<< orphan*/  status; } ;
struct i2c_msg {int flags; int addr; int len; void* buf; } ;
struct TYPE_8__ {int /*<<< orphan*/  bcdDevice; } ;
struct TYPE_10__ {int devnum; TYPE_2__* bus; TYPE_1__ descriptor; } ;
struct TYPE_9__ {int busnum; } ;

/* Variables and functions */
 int ENOMEM ; 
 int EREMOTEIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_CLASS_HWMON ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_RD ; 
 int OSIFI2C_READ ; 
 int OSIFI2C_SET_BIT_RATE ; 
 int OSIFI2C_STATUS ; 
 int OSIFI2C_STOP ; 
 int OSIFI2C_WRITE ; 
 int /*<<< orphan*/  STATUS_ADDRESS_ACK ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int USB_DIR_IN ; 
 int USB_RECIP_INTERFACE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int,int,int,int) ; 
 struct osif_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  interface_to_usbdev (struct usb_interface*) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  osif_algorithm ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int,int) ; 
 int usb_control_msg (TYPE_3__*,int /*<<< orphan*/ ,int,int,int,int,void*,int,int) ; 
 TYPE_3__* usb_get_dev (int /*<<< orphan*/ ) ; 
 struct osif_priv* usb_get_intfdata (struct usb_interface*) ; 
 int /*<<< orphan*/  usb_put_dev (TYPE_3__*) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_set_intfdata (struct usb_interface*,struct osif_priv*) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (TYPE_3__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int osif_usb_read(struct i2c_adapter *adapter, int cmd,
			 int value, int index, void *data, int len)
{
	struct osif_priv *priv = adapter->algo_data;

	return usb_control_msg(priv->usb_dev, usb_rcvctrlpipe(priv->usb_dev, 0),
			       cmd, USB_TYPE_VENDOR | USB_RECIP_INTERFACE |
			       USB_DIR_IN, value, index, data, len, 2000);
}

__attribute__((used)) static int osif_usb_write(struct i2c_adapter *adapter, int cmd,
			  int value, int index, void *data, int len)
{

	struct osif_priv *priv = adapter->algo_data;

	return usb_control_msg(priv->usb_dev, usb_sndctrlpipe(priv->usb_dev, 0),
			       cmd, USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
			       value, index, data, len, 2000);
}

__attribute__((used)) static int osif_xfer(struct i2c_adapter *adapter, struct i2c_msg *msgs,
			 int num)
{
	struct osif_priv *priv = adapter->algo_data;
	struct i2c_msg *pmsg;
	int ret;
	int i;

	for (i = 0; i < num; i++) {
		pmsg = &msgs[i];

		if (pmsg->flags & I2C_M_RD) {
			ret = osif_usb_read(adapter, OSIFI2C_READ,
					    pmsg->flags, pmsg->addr,
					    pmsg->buf, pmsg->len);
			if (ret != pmsg->len) {
				dev_err(&adapter->dev, "failure reading data\n");
				return -EREMOTEIO;
			}
		} else {
			ret = osif_usb_write(adapter, OSIFI2C_WRITE,
					     pmsg->flags, pmsg->addr,
					     pmsg->buf, pmsg->len);
			if (ret != pmsg->len) {
				dev_err(&adapter->dev, "failure writing data\n");
				return -EREMOTEIO;
			}
		}

		ret = osif_usb_read(adapter, OSIFI2C_STOP, 0, 0, NULL, 0);
		if (ret) {
			dev_err(&adapter->dev, "failure sending STOP\n");
			return -EREMOTEIO;
		}

		/* read status */
		ret = osif_usb_read(adapter, OSIFI2C_STATUS, 0, 0,
				    &priv->status, 1);
		if (ret != 1) {
			dev_err(&adapter->dev, "failure reading status\n");
			return -EREMOTEIO;
		}

		if (priv->status != STATUS_ADDRESS_ACK) {
			dev_dbg(&adapter->dev, "status = %d\n", priv->status);
			return -EREMOTEIO;
		}
	}

	return i;
}

__attribute__((used)) static u32 osif_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static int osif_probe(struct usb_interface *interface,
			     const struct usb_device_id *id)
{
	int ret;
	struct osif_priv *priv;
	u16 version;

	priv = devm_kzalloc(&interface->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->usb_dev = usb_get_dev(interface_to_usbdev(interface));
	priv->interface = interface;

	usb_set_intfdata(interface, priv);

	priv->adapter.owner = THIS_MODULE;
	priv->adapter.class = I2C_CLASS_HWMON;
	priv->adapter.algo = &osif_algorithm;
	priv->adapter.algo_data = priv;
	snprintf(priv->adapter.name, sizeof(priv->adapter.name),
		 "OSIF at bus %03d device %03d",
		 priv->usb_dev->bus->busnum, priv->usb_dev->devnum);

	/*
	 * Set bus frequency. The frequency is:
	 * 120,000,000 / ( 16 + 2 * div * 4^prescale).
	 * Using dev = 52, prescale = 0 give 100KHz */
	ret = osif_usb_read(&priv->adapter, OSIFI2C_SET_BIT_RATE, 52, 0,
			    NULL, 0);
	if (ret) {
		dev_err(&interface->dev, "failure sending bit rate");
		usb_put_dev(priv->usb_dev);
		return ret;
	}

	i2c_add_adapter(&(priv->adapter));

	version = le16_to_cpu(priv->usb_dev->descriptor.bcdDevice);
	dev_info(&interface->dev,
		 "version %x.%02x found at bus %03d address %03d",
		 version >> 8, version & 0xff,
		 priv->usb_dev->bus->busnum, priv->usb_dev->devnum);

	return 0;
}

__attribute__((used)) static void osif_disconnect(struct usb_interface *interface)
{
	struct osif_priv *priv = usb_get_intfdata(interface);

	i2c_del_adapter(&(priv->adapter));
	usb_set_intfdata(interface, NULL);
	usb_put_dev(priv->usb_dev);
}

