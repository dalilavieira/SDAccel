#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct usb_interface {int dummy; } ;
struct usb_device_id {int dummy; } ;
struct rc_map_table {int scancode; } ;
struct i2c_msg {int* buf; int len; int addr; int /*<<< orphan*/  flags; } ;
struct dvb_usb_adapter {TYPE_5__* fe_adap; TYPE_3__* dev; struct dibusb_state* priv; } ;
struct TYPE_9__ {int (* i2c_gate_ctrl ) (struct dvb_frontend*,int) ;} ;
struct dvb_frontend {TYPE_4__ ops; TYPE_1__* dvb; } ;
struct TYPE_7__ {int (* tuner_pass_ctrl ) (struct dvb_frontend*,int,int) ;} ;
struct dibusb_state {int tuner_addr; TYPE_2__ ops; } ;
struct dib3000_config {int demod_address; } ;
struct TYPE_10__ {struct dvb_frontend* fe; } ;
struct TYPE_8__ {int /*<<< orphan*/  i2c_adap; } ;
struct TYPE_6__ {struct dvb_usb_adapter* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  DVB_PLL_TDA665X ; 
 int /*<<< orphan*/  DVB_PLL_TUA6010XS ; 
 int EINVAL ; 
 int ENODEV ; 
 int EREMOTEIO ; 
 int /*<<< orphan*/  I2C_M_RD ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  adapter_nr ; 
 int /*<<< orphan*/  artec_t1_usb2_properties ; 
 int /*<<< orphan*/  dib3000mb_attach ; 
 int /*<<< orphan*/  dibusb1_1_an2235_properties ; 
 int /*<<< orphan*/  dibusb1_1_properties ; 
 int /*<<< orphan*/  dibusb2_0b_properties ; 
 struct dvb_frontend* dvb_attach (int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  dvb_pll_attach ; 
 scalar_t__ dvb_usb_device_init (struct usb_interface*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  err (char*) ; 
 int i2c_transfer (int /*<<< orphan*/ *,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  info (char*) ; 
 int stub1 (struct dvb_frontend*,int,int) ; 
 int stub2 (struct dvb_frontend*,int) ; 
 int stub3 (struct dvb_frontend*,int) ; 

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

__attribute__((used)) static int dib3000mb_i2c_gate_ctrl(struct dvb_frontend* fe, int enable)
{
	struct dvb_usb_adapter *adap = fe->dvb->priv;
	struct dibusb_state *st = adap->priv;

	return st->ops.tuner_pass_ctrl(fe, enable, st->tuner_addr);
}

__attribute__((used)) static int dibusb_dib3000mb_frontend_attach(struct dvb_usb_adapter *adap)
{
	struct dib3000_config demod_cfg;
	struct dibusb_state *st = adap->priv;

	demod_cfg.demod_address = 0x8;

	adap->fe_adap[0].fe = dvb_attach(dib3000mb_attach, &demod_cfg,
					 &adap->dev->i2c_adap, &st->ops);
	if ((adap->fe_adap[0].fe) == NULL)
		return -ENODEV;

	adap->fe_adap[0].fe->ops.i2c_gate_ctrl = dib3000mb_i2c_gate_ctrl;

	return 0;
}

__attribute__((used)) static int dibusb_thomson_tuner_attach(struct dvb_usb_adapter *adap)
{
	struct dibusb_state *st = adap->priv;

	st->tuner_addr = 0x61;

	dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x61, &adap->dev->i2c_adap,
		   DVB_PLL_TUA6010XS);
	return 0;
}

__attribute__((used)) static int dibusb_panasonic_tuner_attach(struct dvb_usb_adapter *adap)
{
	struct dibusb_state *st = adap->priv;

	st->tuner_addr = 0x60;

	dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x60, &adap->dev->i2c_adap,
		   DVB_PLL_TDA665X);
	return 0;
}

__attribute__((used)) static int dibusb_tuner_probe_and_attach(struct dvb_usb_adapter *adap)
{
	u8 b[2] = { 0,0 }, b2[1];
	int ret = 0;
	struct i2c_msg msg[2] = {
		{ .flags = 0,        .buf = b,  .len = 2 },
		{ .flags = I2C_M_RD, .buf = b2, .len = 1 },
	};
	struct dibusb_state *st = adap->priv;

	/* the Panasonic sits on I2C addrass 0x60, the Thomson on 0x61 */
	msg[0].addr = msg[1].addr = st->tuner_addr = 0x60;

	if (adap->fe_adap[0].fe->ops.i2c_gate_ctrl)
		adap->fe_adap[0].fe->ops.i2c_gate_ctrl(adap->fe_adap[0].fe, 1);

	if (i2c_transfer(&adap->dev->i2c_adap, msg, 2) != 2) {
		err("tuner i2c write failed.");
		ret = -EREMOTEIO;
	}

	if (adap->fe_adap[0].fe->ops.i2c_gate_ctrl)
		adap->fe_adap[0].fe->ops.i2c_gate_ctrl(adap->fe_adap[0].fe, 0);

	if (b2[0] == 0xfe) {
		info("This device has the Thomson Cable onboard. Which is default.");
		ret = dibusb_thomson_tuner_attach(adap);
	} else {
		info("This device has the Panasonic ENV77H11D5 onboard.");
		ret = dibusb_panasonic_tuner_attach(adap);
	}

	return ret;
}

__attribute__((used)) static int dibusb_probe(struct usb_interface *intf,
		const struct usb_device_id *id)
{
	if (0 == dvb_usb_device_init(intf, &dibusb1_1_properties,
				     THIS_MODULE, NULL, adapter_nr) ||
	    0 == dvb_usb_device_init(intf, &dibusb1_1_an2235_properties,
				     THIS_MODULE, NULL, adapter_nr) ||
	    0 == dvb_usb_device_init(intf, &dibusb2_0b_properties,
				     THIS_MODULE, NULL, adapter_nr) ||
	    0 == dvb_usb_device_init(intf, &artec_t1_usb2_properties,
				     THIS_MODULE, NULL, adapter_nr))
		return 0;

	return -EINVAL;
}

