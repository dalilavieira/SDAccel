#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct usb_interface {int dummy; } ;
struct usb_device_id {int dummy; } ;
struct rc_map_table {int scancode; int /*<<< orphan*/  keycode; } ;
struct dvb_usb_device {struct dibusb_device_state* priv; } ;
struct dibusb_device_state {int old_toggle; int /*<<< orphan*/  last_repeat_count; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct rc_map_table*) ; 
#define  DIBUSB_RC_HAUPPAUGE_KEY_EMPTY 129 
#define  DIBUSB_RC_HAUPPAUGE_KEY_PRESSED 128 
 int DIBUSB_REQ_POLL_REMOTE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int REMOTE_KEY_PRESSED ; 
 int REMOTE_NO_KEY_PRESSED ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  adapter_nr ; 
 int /*<<< orphan*/  deb_rc (char*,int,int,...) ; 
 int /*<<< orphan*/  dibusb_read_eeprom_byte (struct dvb_usb_device*,int,int*) ; 
 int dvb_usb_device_init (struct usb_interface*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int dvb_usb_generic_rw (struct dvb_usb_device*,int*,int,int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nova_t_properties ; 
 struct rc_map_table* rc_map_haupp_table ; 

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

__attribute__((used)) static int nova_t_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
	u8 *buf, data, toggle, custom;
	u16 raw;
	int i, ret;
	struct dibusb_device_state *st = d->priv;

	buf = kmalloc(5, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	buf[0] = DIBUSB_REQ_POLL_REMOTE;
	buf[1] = 0x35;
	ret = dvb_usb_generic_rw(d, buf, 2, buf, 5, 0);
	if (ret < 0)
		goto ret;

	*state = REMOTE_NO_KEY_PRESSED;
	switch (buf[0]) {
		case DIBUSB_RC_HAUPPAUGE_KEY_PRESSED:
			raw = ((buf[1] << 8) | buf[2]) >> 3;
			toggle = !!(raw & 0x800);
			data = raw & 0x3f;
			custom = (raw >> 6) & 0x1f;

			deb_rc("raw key code 0x%02x, 0x%02x, 0x%02x to c: %02x d: %02x toggle: %d\n",
			       buf[1], buf[2], buf[3], custom, data, toggle);

			for (i = 0; i < ARRAY_SIZE(rc_map_haupp_table); i++) {
				if (rc5_data(&rc_map_haupp_table[i]) == data &&
					rc5_custom(&rc_map_haupp_table[i]) == custom) {

					deb_rc("c: %x, d: %x\n", rc5_data(&rc_map_haupp_table[i]),
								 rc5_custom(&rc_map_haupp_table[i]));

					*event = rc_map_haupp_table[i].keycode;
					*state = REMOTE_KEY_PRESSED;
					if (st->old_toggle == toggle) {
						if (st->last_repeat_count++ < 2)
							*state = REMOTE_NO_KEY_PRESSED;
					} else {
						st->last_repeat_count = 0;
						st->old_toggle = toggle;
					}
					break;
				}
			}

			break;
		case DIBUSB_RC_HAUPPAUGE_KEY_EMPTY:
		default:
			break;
	}

ret:
	kfree(buf);
	return ret;
}

__attribute__((used)) static int nova_t_read_mac_address (struct dvb_usb_device *d, u8 mac[6])
{
	int i;
	u8 b;

	mac[0] = 0x00;
	mac[1] = 0x0d;
	mac[2] = 0xfe;

	/* this is a complete guess, but works for my box */
	for (i = 136; i < 139; i++) {
		dibusb_read_eeprom_byte(d,i, &b);

		mac[5 - (i - 136)] = b;
	}

	return 0;
}

__attribute__((used)) static int nova_t_probe(struct usb_interface *intf,
		const struct usb_device_id *id)
{
	return dvb_usb_device_init(intf, &nova_t_properties,
				   THIS_MODULE, NULL, adapter_nr);
}

