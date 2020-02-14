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
typedef  int u32 ;
typedef  int u16 ;
struct usb_interface {int dummy; } ;
struct usb_device_id {int dummy; } ;
struct rc_map_table {int scancode; } ;
struct dvb_usb_device {int /*<<< orphan*/  data_mutex; int /*<<< orphan*/  rc_dev; struct dtt200u_state* priv; } ;
struct dvb_usb_adapter {struct dvb_usb_device* dev; TYPE_1__* fe_adap; } ;
struct dtt200u_state {int* data; } ;
typedef  enum rc_proto { ____Placeholder_rc_proto } rc_proto ;
struct TYPE_2__ {int /*<<< orphan*/  fe; } ;

/* Variables and functions */
 int ENODEV ; 
 int GET_RC_CODE ; 
 int RC_PROTO_NEC ; 
 int RC_PROTO_NECX ; 
 int RESET_PID_FILTER ; 
 int SET_INIT ; 
 int SET_PID_FILTER ; 
 int SET_STREAMING ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  adapter_nr ; 
 int /*<<< orphan*/  deb_info (char*,int,int*) ; 
 int /*<<< orphan*/  dtt200u_fe_attach (struct dvb_usb_device*) ; 
 int /*<<< orphan*/  dtt200u_properties ; 
 scalar_t__ dvb_usb_device_init (struct usb_interface*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int dvb_usb_generic_rw (struct dvb_usb_device*,int*,int,int*,int,int /*<<< orphan*/ ) ; 
 int dvb_usb_generic_write (struct dvb_usb_device*,int*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rc_keydown (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rc_keyup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rc_repeat (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wt220u_fc_properties ; 
 int /*<<< orphan*/  wt220u_miglia_properties ; 
 int /*<<< orphan*/  wt220u_properties ; 
 int /*<<< orphan*/  wt220u_zl0353_properties ; 

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

__attribute__((used)) static int dtt200u_power_ctrl(struct dvb_usb_device *d, int onoff)
{
	struct dtt200u_state *st = d->priv;
	int ret = 0;

	mutex_lock(&d->data_mutex);

	st->data[0] = SET_INIT;

	if (onoff)
		ret = dvb_usb_generic_write(d, st->data, 2);

	mutex_unlock(&d->data_mutex);
	return ret;
}

__attribute__((used)) static int dtt200u_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
	struct dvb_usb_device *d = adap->dev;
	struct dtt200u_state *st = d->priv;
	int ret;

	mutex_lock(&d->data_mutex);
	st->data[0] = SET_STREAMING;
	st->data[1] = onoff;

	ret = dvb_usb_generic_write(adap->dev, st->data, 2);
	if (ret < 0)
		goto ret;

	if (onoff)
		goto ret;

	st->data[0] = RESET_PID_FILTER;
	ret = dvb_usb_generic_write(adap->dev, st->data, 1);

ret:
	mutex_unlock(&d->data_mutex);

	return ret;
}

__attribute__((used)) static int dtt200u_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid, int onoff)
{
	struct dvb_usb_device *d = adap->dev;
	struct dtt200u_state *st = d->priv;
	int ret;

	pid = onoff ? pid : 0;

	mutex_lock(&d->data_mutex);
	st->data[0] = SET_PID_FILTER;
	st->data[1] = index;
	st->data[2] = pid & 0xff;
	st->data[3] = (pid >> 8) & 0x1f;

	ret = dvb_usb_generic_write(adap->dev, st->data, 4);
	mutex_unlock(&d->data_mutex);

	return ret;
}

__attribute__((used)) static int dtt200u_rc_query(struct dvb_usb_device *d)
{
	struct dtt200u_state *st = d->priv;
	u32 scancode;
	int ret;

	mutex_lock(&d->data_mutex);
	st->data[0] = GET_RC_CODE;

	ret = dvb_usb_generic_rw(d, st->data, 1, st->data, 5, 0);
	if (ret < 0)
		goto ret;

	if (st->data[0] == 1) {
		enum rc_proto proto = RC_PROTO_NEC;

		scancode = st->data[1];
		if ((u8) ~st->data[1] != st->data[2]) {
			/* Extended NEC */
			scancode = scancode << 8;
			scancode |= st->data[2];
			proto = RC_PROTO_NECX;
		}
		scancode = scancode << 8;
		scancode |= st->data[3];

		/* Check command checksum is ok */
		if ((u8) ~st->data[3] == st->data[4])
			rc_keydown(d->rc_dev, proto, scancode, 0);
		else
			rc_keyup(d->rc_dev);
	} else if (st->data[0] == 2) {
		rc_repeat(d->rc_dev);
	} else {
		rc_keyup(d->rc_dev);
	}

	if (st->data[0] != 0)
		deb_info("st->data: %*ph\n", 5, st->data);

ret:
	mutex_unlock(&d->data_mutex);
	return ret;
}

__attribute__((used)) static int dtt200u_frontend_attach(struct dvb_usb_adapter *adap)
{
	adap->fe_adap[0].fe = dtt200u_fe_attach(adap->dev);
	return 0;
}

__attribute__((used)) static int dtt200u_usb_probe(struct usb_interface *intf,
		const struct usb_device_id *id)
{
	if (0 == dvb_usb_device_init(intf, &dtt200u_properties,
				     THIS_MODULE, NULL, adapter_nr) ||
	    0 == dvb_usb_device_init(intf, &wt220u_properties,
				     THIS_MODULE, NULL, adapter_nr) ||
	    0 == dvb_usb_device_init(intf, &wt220u_fc_properties,
				     THIS_MODULE, NULL, adapter_nr) ||
	    0 == dvb_usb_device_init(intf, &wt220u_zl0353_properties,
				     THIS_MODULE, NULL, adapter_nr) ||
	    0 == dvb_usb_device_init(intf, &wt220u_miglia_properties,
				     THIS_MODULE, NULL, adapter_nr))
		return 0;

	return -ENODEV;
}

