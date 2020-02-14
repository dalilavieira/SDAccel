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
typedef  int u8 ;
typedef  int u32 ;
struct tsc_ser {int* data; size_t idx; struct input_dev* dev; int /*<<< orphan*/  phys; struct serio* serio; } ;
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
 int /*<<< orphan*/  BTN_TOUCH ; 
 int /*<<< orphan*/  BUS_RS232 ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  SERIO_TSC40 ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,unsigned char,...) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct tsc_ser*) ; 
 struct tsc_ser* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_close (struct serio*) ; 
 struct tsc_ser* serio_get_drvdata (struct serio*) ; 
 int serio_open (struct serio*,struct serio_driver*) ; 
 int /*<<< orphan*/  serio_set_drvdata (struct serio*,struct tsc_ser*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 int /*<<< orphan*/  unlikely (unsigned char) ; 

__attribute__((used)) static void tsc_process_data(struct tsc_ser *ptsc)
{
	struct input_dev *dev = ptsc->dev;
	u8 *data = ptsc->data;
	u32 x;
	u32 y;

	x = ((data[1] & 0x03) << 8) | data[2];
	y = ((data[3] & 0x03) << 8) | data[4];

	input_report_abs(dev, ABS_X, x);
	input_report_abs(dev, ABS_Y, y);
	input_report_key(dev, BTN_TOUCH, 1);

	input_sync(dev);
}

__attribute__((used)) static irqreturn_t tsc_interrupt(struct serio *serio,
		unsigned char data, unsigned int flags)
{
	struct tsc_ser *ptsc = serio_get_drvdata(serio);
	struct input_dev *dev = ptsc->dev;

	ptsc->data[ptsc->idx] = data;
	switch (ptsc->idx++) {
	case 0:
		if (unlikely((data & 0x3e) != 0x10)) {
			dev_dbg(&serio->dev,
				"unsynchronized packet start (0x%02x)\n", data);
			ptsc->idx = 0;
		} else if (!(data & 0x01)) {
			input_report_key(dev, BTN_TOUCH, 0);
			input_sync(dev);
			ptsc->idx = 0;
		}
		break;

	case 1:
	case 3:
		if (unlikely(data & 0xfc)) {
			dev_dbg(&serio->dev,
				"unsynchronized data 0x%02x at offset %d\n",
				data, ptsc->idx - 1);
			ptsc->idx = 0;
		}
		break;

	case 4:
		tsc_process_data(ptsc);
		ptsc->idx = 0;
		break;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int tsc_connect(struct serio *serio, struct serio_driver *drv)
{
	struct tsc_ser *ptsc;
	struct input_dev *input_dev;
	int error;

	ptsc = kzalloc(sizeof(struct tsc_ser), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!ptsc || !input_dev) {
		error = -ENOMEM;
		goto fail1;
	}

	ptsc->serio = serio;
	ptsc->dev = input_dev;
	snprintf(ptsc->phys, sizeof(ptsc->phys), "%s/input0", serio->phys);

	input_dev->name = "TSC-10/25/40 Serial TouchScreen";
	input_dev->phys = ptsc->phys;
	input_dev->id.bustype = BUS_RS232;
	input_dev->id.vendor = SERIO_TSC40;
	input_dev->id.product = 40;
	input_dev->id.version = 0x0001;
	input_dev->dev.parent = &serio->dev;

	input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
	__set_bit(BTN_TOUCH, input_dev->keybit);
	input_set_abs_params(ptsc->dev, ABS_X, 0, 0x3ff, 0, 0);
	input_set_abs_params(ptsc->dev, ABS_Y, 0, 0x3ff, 0, 0);

	serio_set_drvdata(serio, ptsc);

	error = serio_open(serio, drv);
	if (error)
		goto fail2;

	error = input_register_device(ptsc->dev);
	if (error)
		goto fail3;

	return 0;

fail3:
	serio_close(serio);
fail2:
	serio_set_drvdata(serio, NULL);
fail1:
	input_free_device(input_dev);
	kfree(ptsc);
	return error;
}

__attribute__((used)) static void tsc_disconnect(struct serio *serio)
{
	struct tsc_ser *ptsc = serio_get_drvdata(serio);

	serio_close(serio);

	input_unregister_device(ptsc->dev);
	kfree(ptsc);

	serio_set_drvdata(serio, NULL);
}

