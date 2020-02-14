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
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct usb_interface {int dummy; } ;
struct usb_device_id {int dummy; } ;
struct rc_map_table {int scancode; } ;
struct dvb_usb_device {scalar_t__ last_event; int /*<<< orphan*/  data_mutex; struct cinergyt2_state* priv; } ;
struct dvb_usb_adapter {struct dvb_usb_device* dev; TYPE_1__* fe_adap; } ;
struct cinergyt2_state {int* data; scalar_t__ rc_counter; } ;
struct TYPE_2__ {int /*<<< orphan*/  fe; } ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 int CINERGYT2_EP1_CONTROL_STREAM_TRANSFER ; 
 int CINERGYT2_EP1_GET_FIRMWARE_VERSION ; 
 int CINERGYT2_EP1_GET_RC_EVENTS ; 
 int CINERGYT2_EP1_SLEEP_MODE ; 
 scalar_t__ RC_REPEAT_DELAY ; 
 int REMOTE_KEY_REPEAT ; 
 int REMOTE_NO_KEY_PRESSED ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  adapter_nr ; 
 int /*<<< orphan*/  cinergyt2_fe_attach (struct dvb_usb_device*) ; 
 int /*<<< orphan*/  cinergyt2_properties ; 
 struct dvb_usb_device* cinergyt2_usb_device ; 
 int /*<<< orphan*/  deb_rc (char*,...) ; 
 int dvb_usb_device_init (struct usb_interface*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int dvb_usb_generic_rw (struct dvb_usb_device*,int*,int,int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dvb_usb_nec_rc_key_to_event (struct dvb_usb_device*,int*,scalar_t__*,int*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__* repeatable_keys ; 

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

__attribute__((used)) static int cinergyt2_streaming_ctrl(struct dvb_usb_adapter *adap, int enable)
{
	struct dvb_usb_device *d = adap->dev;
	struct cinergyt2_state *st = d->priv;
	int ret;

	mutex_lock(&d->data_mutex);
	st->data[0] = CINERGYT2_EP1_CONTROL_STREAM_TRANSFER;
	st->data[1] = enable ? 1 : 0;

	ret = dvb_usb_generic_rw(d, st->data, 2, st->data, 64, 0);
	mutex_unlock(&d->data_mutex);

	return ret;
}

__attribute__((used)) static int cinergyt2_power_ctrl(struct dvb_usb_device *d, int enable)
{
	struct cinergyt2_state *st = d->priv;
	int ret;

	mutex_lock(&d->data_mutex);
	st->data[0] = CINERGYT2_EP1_SLEEP_MODE;
	st->data[1] = enable ? 0 : 1;

	ret = dvb_usb_generic_rw(d, st->data, 2, st->data, 3, 0);
	mutex_unlock(&d->data_mutex);

	return ret;
}

__attribute__((used)) static int cinergyt2_frontend_attach(struct dvb_usb_adapter *adap)
{
	struct dvb_usb_device *d = adap->dev;
	struct cinergyt2_state *st = d->priv;
	int ret;

	adap->fe_adap[0].fe = cinergyt2_fe_attach(adap->dev);

	mutex_lock(&d->data_mutex);
	st->data[0] = CINERGYT2_EP1_GET_FIRMWARE_VERSION;

	ret = dvb_usb_generic_rw(d, st->data, 1, st->data, 3, 0);
	if (ret < 0) {
		deb_rc("cinergyt2_power_ctrl() Failed to retrieve sleep state info\n");
	}
	mutex_unlock(&d->data_mutex);

	/* Copy this pointer as we are gonna need it in the release phase */
	cinergyt2_usb_device = adap->dev;

	return ret;
}

__attribute__((used)) static int cinergyt2_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
	struct cinergyt2_state *st = d->priv;
	int i, ret;

	*state = REMOTE_NO_KEY_PRESSED;

	mutex_lock(&d->data_mutex);
	st->data[0] = CINERGYT2_EP1_GET_RC_EVENTS;

	ret = dvb_usb_generic_rw(d, st->data, 1, st->data, 5, 0);
	if (ret < 0)
		goto ret;

	if (st->data[4] == 0xff) {
		/* key repeat */
		st->rc_counter++;
		if (st->rc_counter > RC_REPEAT_DELAY) {
			for (i = 0; i < ARRAY_SIZE(repeatable_keys); i++) {
				if (d->last_event == repeatable_keys[i]) {
					*state = REMOTE_KEY_REPEAT;
					*event = d->last_event;
					deb_rc("repeat key, event %x\n",
						   *event);
					goto ret;
				}
			}
			deb_rc("repeated key (non repeatable)\n");
		}
		goto ret;
	}

	/* hack to pass checksum on the custom field */
	st->data[2] = ~st->data[1];
	dvb_usb_nec_rc_key_to_event(d, st->data, event, state);
	if (st->data[0] != 0) {
		if (*event != d->last_event)
			st->rc_counter = 0;

		deb_rc("key: %*ph\n", 5, st->data);
	}

ret:
	mutex_unlock(&d->data_mutex);
	return ret;
}

__attribute__((used)) static int cinergyt2_usb_probe(struct usb_interface *intf,
				const struct usb_device_id *id)
{
	return dvb_usb_device_init(intf, &cinergyt2_properties,
				   THIS_MODULE, NULL, adapter_nr);
}

