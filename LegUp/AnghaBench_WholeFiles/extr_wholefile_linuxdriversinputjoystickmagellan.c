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
struct serio_driver {int dummy; } ;
struct serio {char* phys; int /*<<< orphan*/  dev; } ;
struct magellan {unsigned char* data; int idx; struct input_dev* dev; int /*<<< orphan*/  phys; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int product; int version; int /*<<< orphan*/  vendor; int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; int* evbit; int /*<<< orphan*/  keybit; TYPE_2__ dev; TYPE_1__ id; int /*<<< orphan*/  phys; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int BIT_MASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUS_RS232 ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ MAGELLAN_MAX_LENGTH ; 
 int /*<<< orphan*/  SERIO_MAGELLAN ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct magellan*) ; 
 struct magellan* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * magellan_axes ; 
 int /*<<< orphan*/ * magellan_buttons ; 
 int /*<<< orphan*/  serio_close (struct serio*) ; 
 struct magellan* serio_get_drvdata (struct serio*) ; 
 int serio_open (struct serio*,struct serio_driver*) ; 
 int /*<<< orphan*/  serio_set_drvdata (struct serio*,struct magellan*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 

__attribute__((used)) static int magellan_crunch_nibbles(unsigned char *data, int count)
{
	static unsigned char nibbles[16] = "0AB3D56GH9:K<MN?";

	do {
		if (data[count] == nibbles[data[count] & 0xf])
			data[count] = data[count] & 0xf;
		else
			return -1;
	} while (--count);

	return 0;
}

__attribute__((used)) static void magellan_process_packet(struct magellan* magellan)
{
	struct input_dev *dev = magellan->dev;
	unsigned char *data = magellan->data;
	int i, t;

	if (!magellan->idx) return;

	switch (magellan->data[0]) {

		case 'd':				/* Axis data */
			if (magellan->idx != 25) return;
			if (magellan_crunch_nibbles(data, 24)) return;
			for (i = 0; i < 6; i++)
				input_report_abs(dev, magellan_axes[i],
					(data[(i << 2) + 1] << 12 | data[(i << 2) + 2] << 8 |
					 data[(i << 2) + 3] <<  4 | data[(i << 2) + 4]) - 32768);
			break;

		case 'k':				/* Button data */
			if (magellan->idx != 4) return;
			if (magellan_crunch_nibbles(data, 3)) return;
			t = (data[1] << 1) | (data[2] << 5) | data[3];
			for (i = 0; i < 9; i++) input_report_key(dev, magellan_buttons[i], (t >> i) & 1);
			break;
	}

	input_sync(dev);
}

__attribute__((used)) static irqreturn_t magellan_interrupt(struct serio *serio,
		unsigned char data, unsigned int flags)
{
	struct magellan* magellan = serio_get_drvdata(serio);

	if (data == '\r') {
		magellan_process_packet(magellan);
		magellan->idx = 0;
	} else {
		if (magellan->idx < MAGELLAN_MAX_LENGTH)
			magellan->data[magellan->idx++] = data;
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static void magellan_disconnect(struct serio *serio)
{
	struct magellan* magellan = serio_get_drvdata(serio);

	serio_close(serio);
	serio_set_drvdata(serio, NULL);
	input_unregister_device(magellan->dev);
	kfree(magellan);
}

__attribute__((used)) static int magellan_connect(struct serio *serio, struct serio_driver *drv)
{
	struct magellan *magellan;
	struct input_dev *input_dev;
	int err = -ENOMEM;
	int i;

	magellan = kzalloc(sizeof(struct magellan), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!magellan || !input_dev)
		goto fail1;

	magellan->dev = input_dev;
	snprintf(magellan->phys, sizeof(magellan->phys), "%s/input0", serio->phys);

	input_dev->name = "LogiCad3D Magellan / SpaceMouse";
	input_dev->phys = magellan->phys;
	input_dev->id.bustype = BUS_RS232;
	input_dev->id.vendor = SERIO_MAGELLAN;
	input_dev->id.product = 0x0001;
	input_dev->id.version = 0x0100;
	input_dev->dev.parent = &serio->dev;

	input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);

	for (i = 0; i < 9; i++)
		set_bit(magellan_buttons[i], input_dev->keybit);

	for (i = 0; i < 6; i++)
		input_set_abs_params(input_dev, magellan_axes[i], -360, 360, 0, 0);

	serio_set_drvdata(serio, magellan);

	err = serio_open(serio, drv);
	if (err)
		goto fail2;

	err = input_register_device(magellan->dev);
	if (err)
		goto fail3;

	return 0;

 fail3:	serio_close(serio);
 fail2:	serio_set_drvdata(serio, NULL);
 fail1:	input_free_device(input_dev);
	kfree(magellan);
	return err;
}

