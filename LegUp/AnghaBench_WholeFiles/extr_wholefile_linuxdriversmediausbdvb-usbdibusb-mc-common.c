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
struct rc_map_table {int scancode; } ;
struct i2c_adapter {int dummy; } ;
struct dvb_usb_adapter {TYPE_4__* fe_adap; TYPE_5__* dev; struct dibusb_state* priv; } ;
struct TYPE_6__ {int /*<<< orphan*/  pid_ctrl; int /*<<< orphan*/  pid_parse; } ;
struct dibusb_state {int mt2060_present; TYPE_1__ ops; } ;
struct TYPE_10__ {TYPE_3__* udev; int /*<<< orphan*/  i2c_adap; } ;
struct TYPE_9__ {int /*<<< orphan*/ * fe; } ;
struct TYPE_7__ {int /*<<< orphan*/  idProduct; int /*<<< orphan*/  idVendor; } ;
struct TYPE_8__ {TYPE_2__ descriptor; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFAULT_DIB3000MC_I2C_ADDRESS ; 
 int /*<<< orphan*/  DEFAULT_DIB3000P_I2C_ADDRESS ; 
 int /*<<< orphan*/  DVB_PLL_ENV57H1XD5 ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ USB_PID_DIBCOM_MOD3001_WARM ; 
 scalar_t__ USB_PID_LITEON_DVB_T_WARM ; 
 scalar_t__ USB_VID_DIBCOM ; 
 scalar_t__ USB_VID_LITEON ; 
 int /*<<< orphan*/  dib3000mc_attach ; 
 struct i2c_adapter* dib3000mc_get_tuner_i2c_master (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dib3000mc_pid_control ; 
 int /*<<< orphan*/  dib3000mc_pid_parse ; 
 int /*<<< orphan*/  dib3000mc_set_config (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dibusb_read_eeprom_byte (TYPE_5__*,int,int*) ; 
 int /*<<< orphan*/ * dvb_attach (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,struct i2c_adapter*,...) ; 
 int /*<<< orphan*/  dvb_pll_attach ; 
 scalar_t__ le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mod3000p_dib3000p_config ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mt2060_attach ; 
 int /*<<< orphan*/  stk3000p_dib3000p_config ; 
 int /*<<< orphan*/  stk3000p_mt2060_config ; 
 int /*<<< orphan*/  warn (char*,int,int) ; 

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

int dibusb_dib3000mc_frontend_attach(struct dvb_usb_adapter *adap)
{
	if (le16_to_cpu(adap->dev->udev->descriptor.idVendor) == USB_VID_LITEON &&
	    le16_to_cpu(adap->dev->udev->descriptor.idProduct) ==
			USB_PID_LITEON_DVB_T_WARM) {
		msleep(1000);
	}

	adap->fe_adap[0].fe = dvb_attach(dib3000mc_attach,
					 &adap->dev->i2c_adap,
					 DEFAULT_DIB3000P_I2C_ADDRESS,
					 &mod3000p_dib3000p_config);
	if ((adap->fe_adap[0].fe) == NULL)
		adap->fe_adap[0].fe = dvb_attach(dib3000mc_attach,
						 &adap->dev->i2c_adap,
						 DEFAULT_DIB3000MC_I2C_ADDRESS,
						 &mod3000p_dib3000p_config);
	if ((adap->fe_adap[0].fe) != NULL) {
		if (adap->priv != NULL) {
			struct dibusb_state *st = adap->priv;
			st->ops.pid_parse = dib3000mc_pid_parse;
			st->ops.pid_ctrl  = dib3000mc_pid_control;
		}
		return 0;
	}
	return -ENODEV;
}

int dibusb_dib3000mc_tuner_attach(struct dvb_usb_adapter *adap)
{
	struct dibusb_state *st = adap->priv;
	u8 a,b;
	u16 if1 = 1220;
	struct i2c_adapter *tun_i2c;

	// First IF calibration for Liteon Sticks
	if (le16_to_cpu(adap->dev->udev->descriptor.idVendor) == USB_VID_LITEON &&
	    le16_to_cpu(adap->dev->udev->descriptor.idProduct) == USB_PID_LITEON_DVB_T_WARM) {

		dibusb_read_eeprom_byte(adap->dev,0x7E,&a);
		dibusb_read_eeprom_byte(adap->dev,0x7F,&b);

		if (a == 0x00)
			if1 += b;
		else if (a == 0x80)
			if1 -= b;
		else
			warn("LITE-ON DVB-T: Strange IF1 calibration :%2X %2X\n", a, b);

	} else if (le16_to_cpu(adap->dev->udev->descriptor.idVendor) == USB_VID_DIBCOM &&
		   le16_to_cpu(adap->dev->udev->descriptor.idProduct) == USB_PID_DIBCOM_MOD3001_WARM) {
		u8 desc;
		dibusb_read_eeprom_byte(adap->dev, 7, &desc);
		if (desc == 2) {
			a = 127;
			do {
				dibusb_read_eeprom_byte(adap->dev, a, &desc);
				a--;
			} while (a > 7 && (desc == 0xff || desc == 0x00));
			if (desc & 0x80)
				if1 -= (0xff - desc);
			else
				if1 += desc;
		}
	}

	tun_i2c = dib3000mc_get_tuner_i2c_master(adap->fe_adap[0].fe, 1);
	if (dvb_attach(mt2060_attach, adap->fe_adap[0].fe, tun_i2c, &stk3000p_mt2060_config, if1) == NULL) {
		/* not found - use panasonic pll parameters */
		if (dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x60, tun_i2c, DVB_PLL_ENV57H1XD5) == NULL)
			return -ENOMEM;
	} else {
		st->mt2060_present = 1;
		/* set the correct parameters for the dib3000p */
		dib3000mc_set_config(adap->fe_adap[0].fe, &stk3000p_dib3000p_config);
	}
	return 0;
}

