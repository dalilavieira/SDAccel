#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct twidjoy_button_spec {int bitmask; int bitshift; int /*<<< orphan*/ * buttons; } ;
struct twidjoy {unsigned char* data; scalar_t__ idx; struct input_dev* dev; int /*<<< orphan*/  phys; } ;
struct serio_driver {int dummy; } ;
struct serio {char* phys; int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int product; int version; int /*<<< orphan*/  vendor; int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; int* evbit; int /*<<< orphan*/  keybit; TYPE_2__ dev; TYPE_1__ id; int /*<<< orphan*/  phys; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int BIT_MASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUS_RS232 ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  SERIO_TWIDJOY ; 
 scalar_t__ TWIDJOY_MAX_LENGTH ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int,int,int,int) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct twidjoy*) ; 
 struct twidjoy* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_close (struct serio*) ; 
 struct twidjoy* serio_get_drvdata (struct serio*) ; 
 int serio_open (struct serio*,struct serio_driver*) ; 
 int /*<<< orphan*/  serio_set_drvdata (struct serio*,struct twidjoy*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 struct twidjoy_button_spec* twidjoy_buttons ; 

__attribute__((used)) static void twidjoy_process_packet(struct twidjoy *twidjoy)
{
	struct input_dev *dev = twidjoy->dev;
	unsigned char *data = twidjoy->data;
	struct twidjoy_button_spec *bp;
	int button_bits, abs_x, abs_y;

	button_bits = ((data[1] & 0x7f) << 7) | (data[0] & 0x7f);

	for (bp = twidjoy_buttons; bp->bitmask; bp++) {
		int value = (button_bits & (bp->bitmask << bp->bitshift)) >> bp->bitshift;
		int i;

		for (i = 0; i < bp->bitmask; i++)
			input_report_key(dev, bp->buttons[i], i+1 == value);
	}

	abs_x = ((data[4] & 0x07) << 5) | ((data[3] & 0x7C) >> 2);
	if (data[4] & 0x08) abs_x -= 256;

	abs_y = ((data[3] & 0x01) << 7) | ((data[2] & 0x7F) >> 0);
	if (data[3] & 0x02) abs_y -= 256;

	input_report_abs(dev, ABS_X, -abs_x);
	input_report_abs(dev, ABS_Y, +abs_y);

	input_sync(dev);
}

__attribute__((used)) static irqreturn_t twidjoy_interrupt(struct serio *serio, unsigned char data, unsigned int flags)
{
	struct twidjoy *twidjoy = serio_get_drvdata(serio);

	/* All Twiddler packets are 5 bytes. The fact that the first byte
	 * has a MSB of 0 and all other bytes have a MSB of 1 can be used
	 * to check and regain sync. */

	if ((data & 0x80) == 0)
		twidjoy->idx = 0;	/* this byte starts a new packet */
	else if (twidjoy->idx == 0)
		return IRQ_HANDLED;	/* wrong MSB -- ignore this byte */

	if (twidjoy->idx < TWIDJOY_MAX_LENGTH)
		twidjoy->data[twidjoy->idx++] = data;

	if (twidjoy->idx == TWIDJOY_MAX_LENGTH) {
		twidjoy_process_packet(twidjoy);
		twidjoy->idx = 0;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static void twidjoy_disconnect(struct serio *serio)
{
	struct twidjoy *twidjoy = serio_get_drvdata(serio);

	serio_close(serio);
	serio_set_drvdata(serio, NULL);
	input_unregister_device(twidjoy->dev);
	kfree(twidjoy);
}

__attribute__((used)) static int twidjoy_connect(struct serio *serio, struct serio_driver *drv)
{
	struct twidjoy_button_spec *bp;
	struct twidjoy *twidjoy;
	struct input_dev *input_dev;
	int err = -ENOMEM;
	int i;

	twidjoy = kzalloc(sizeof(struct twidjoy), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!twidjoy || !input_dev)
		goto fail1;

	twidjoy->dev = input_dev;
	snprintf(twidjoy->phys, sizeof(twidjoy->phys), "%s/input0", serio->phys);

	input_dev->name = "Handykey Twiddler";
	input_dev->phys = twidjoy->phys;
	input_dev->id.bustype = BUS_RS232;
	input_dev->id.vendor = SERIO_TWIDJOY;
	input_dev->id.product = 0x0001;
	input_dev->id.version = 0x0100;
	input_dev->dev.parent = &serio->dev;

	input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
	input_set_abs_params(input_dev, ABS_X, -50, 50, 4, 4);
	input_set_abs_params(input_dev, ABS_Y, -50, 50, 4, 4);

	for (bp = twidjoy_buttons; bp->bitmask; bp++)
		for (i = 0; i < bp->bitmask; i++)
			set_bit(bp->buttons[i], input_dev->keybit);

	serio_set_drvdata(serio, twidjoy);

	err = serio_open(serio, drv);
	if (err)
		goto fail2;

	err = input_register_device(twidjoy->dev);
	if (err)
		goto fail3;

	return 0;

 fail3:	serio_close(serio);
 fail2:	serio_set_drvdata(serio, NULL);
 fail1:	input_free_device(input_dev);
	kfree(twidjoy);
	return err;
}

