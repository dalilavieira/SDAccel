#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct rc_map_table {int scancode; } ;
struct TYPE_10__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_12__ {TYPE_3__ dev; int /*<<< orphan*/ * algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  name; } ;
struct TYPE_9__ {int caps; int /*<<< orphan*/ * i2c_algo; } ;
struct dvb_usb_device {int state; TYPE_5__ i2c_adap; TYPE_4__* udev; TYPE_2__ props; TYPE_1__* desc; } ;
struct TYPE_11__ {int /*<<< orphan*/  dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int DVB_USB_IS_AN_I2C_ADAPTER ; 
 int DVB_USB_STATE_I2C ; 
 int EINVAL ; 
 int /*<<< orphan*/  err (char*) ; 
 int i2c_add_adapter (TYPE_5__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_5__*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_5__*,struct dvb_usb_device*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

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

int dvb_usb_i2c_init(struct dvb_usb_device *d)
{
	int ret = 0;

	if (!(d->props.caps & DVB_USB_IS_AN_I2C_ADAPTER))
		return 0;

	if (d->props.i2c_algo == NULL) {
		err("no i2c algorithm specified");
		return -EINVAL;
	}

	strlcpy(d->i2c_adap.name, d->desc->name, sizeof(d->i2c_adap.name));
	d->i2c_adap.algo      = d->props.i2c_algo;
	d->i2c_adap.algo_data = NULL;
	d->i2c_adap.dev.parent = &d->udev->dev;

	i2c_set_adapdata(&d->i2c_adap, d);

	if ((ret = i2c_add_adapter(&d->i2c_adap)) < 0)
		err("could not add i2c adapter");

	d->state |= DVB_USB_STATE_I2C;

	return ret;
}

int dvb_usb_i2c_exit(struct dvb_usb_device *d)
{
	if (d->state & DVB_USB_STATE_I2C)
		i2c_del_adapter(&d->i2c_adap);
	d->state &= ~DVB_USB_STATE_I2C;
	return 0;
}

