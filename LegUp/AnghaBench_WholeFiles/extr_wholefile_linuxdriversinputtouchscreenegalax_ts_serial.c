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
typedef  int u16 ;
struct serio_driver {int dummy; } ;
struct serio {char* phys; int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_3__ {int version; scalar_t__ product; int /*<<< orphan*/  vendor; int /*<<< orphan*/  bustype; } ;
struct input_dev {char* name; TYPE_2__ dev; TYPE_1__ id; int /*<<< orphan*/  phys; } ;
struct egalax {int* data; int idx; struct input_dev* input; int /*<<< orphan*/  phys; struct serio* serio; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int /*<<< orphan*/  BUS_RS232 ; 
 int EGALAX_FORMAT_PRESSURE_BIT ; 
 int EGALAX_FORMAT_RESOLUTION_MASK ; 
 int EGALAX_FORMAT_START_BIT ; 
 int EGALAX_FORMAT_TOUCH_BIT ; 
 int /*<<< orphan*/  EGALAX_MAX_XC ; 
 int /*<<< orphan*/  EGALAX_MAX_YC ; 
 int /*<<< orphan*/  EGALAX_MIN_XC ; 
 int /*<<< orphan*/  EGALAX_MIN_YC ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  SERIO_EGALAX ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct egalax*) ; 
 struct egalax* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  serio_close (struct serio*) ; 
 struct egalax* serio_get_drvdata (struct serio*) ; 
 int serio_open (struct serio*,struct serio_driver*) ; 
 int /*<<< orphan*/  serio_set_drvdata (struct serio*,struct egalax*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 

__attribute__((used)) static void egalax_process_data(struct egalax *egalax)
{
	struct input_dev *dev = egalax->input;
	u8 *data = egalax->data;
	u16 x, y;
	u8 shift;
	u8 mask;

	shift = 3 - ((data[0] & EGALAX_FORMAT_RESOLUTION_MASK) >> 1);
	mask = 0xff >> (shift + 1);

	x = (((u16)(data[1] & mask) << 7) | (data[2] & 0x7f)) << shift;
	y = (((u16)(data[3] & mask) << 7) | (data[4] & 0x7f)) << shift;

	input_report_key(dev, BTN_TOUCH, data[0] & EGALAX_FORMAT_TOUCH_BIT);
	input_report_abs(dev, ABS_X, x);
	input_report_abs(dev, ABS_Y, y);
	input_sync(dev);
}

__attribute__((used)) static irqreturn_t egalax_interrupt(struct serio *serio,
				    unsigned char data, unsigned int flags)
{
	struct egalax *egalax = serio_get_drvdata(serio);
	int pkt_len;

	egalax->data[egalax->idx++] = data;

	if (likely(egalax->data[0] & EGALAX_FORMAT_START_BIT)) {
		pkt_len = egalax->data[0] & EGALAX_FORMAT_PRESSURE_BIT ? 6 : 5;
		if (pkt_len == egalax->idx) {
			egalax_process_data(egalax);
			egalax->idx = 0;
		}
	} else {
		dev_dbg(&serio->dev, "unknown/unsynchronized data: %x\n",
			egalax->data[0]);
		egalax->idx = 0;
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int egalax_connect(struct serio *serio, struct serio_driver *drv)
{
	struct egalax *egalax;
	struct input_dev *input_dev;
	int error;

	egalax = kzalloc(sizeof(struct egalax), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!egalax || !input_dev) {
		error = -ENOMEM;
		goto err_free_mem;
	}

	egalax->serio = serio;
	egalax->input = input_dev;
	snprintf(egalax->phys, sizeof(egalax->phys),
		 "%s/input0", serio->phys);

	input_dev->name = "EETI eGalaxTouch Serial TouchScreen";
	input_dev->phys = egalax->phys;
	input_dev->id.bustype = BUS_RS232;
	input_dev->id.vendor = SERIO_EGALAX;
	input_dev->id.product = 0;
	input_dev->id.version = 0x0001;
	input_dev->dev.parent = &serio->dev;

	input_set_capability(input_dev, EV_KEY, BTN_TOUCH);
	input_set_abs_params(input_dev, ABS_X,
			     EGALAX_MIN_XC, EGALAX_MAX_XC, 0, 0);
	input_set_abs_params(input_dev, ABS_Y,
			     EGALAX_MIN_YC, EGALAX_MAX_YC, 0, 0);

	serio_set_drvdata(serio, egalax);

	error = serio_open(serio, drv);
	if (error)
		goto err_reset_drvdata;

	error = input_register_device(input_dev);
	if (error)
		goto err_close_serio;

	return 0;

err_close_serio:
	serio_close(serio);
err_reset_drvdata:
	serio_set_drvdata(serio, NULL);
err_free_mem:
	input_free_device(input_dev);
	kfree(egalax);
	return error;
}

__attribute__((used)) static void egalax_disconnect(struct serio *serio)
{
	struct egalax *egalax = serio_get_drvdata(serio);

	serio_close(serio);
	serio_set_drvdata(serio, NULL);
	input_unregister_device(egalax->input);
	kfree(egalax);
}

