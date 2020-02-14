#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct mapleq {TYPE_1__* recvbuf; struct maple_device* dev; } ;
struct maple_driver {int dummy; } ;
struct maple_device {unsigned long function; struct maple_driver* driver; int /*<<< orphan*/  dev; int /*<<< orphan*/  product_name; } ;
struct TYPE_6__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_5__ {int /*<<< orphan*/  bustype; } ;
struct input_dev {int* evbit; int* keycode; int keycodesize; int /*<<< orphan*/  keybit; TYPE_3__ dev; TYPE_2__ id; int /*<<< orphan*/  keycodemax; int /*<<< orphan*/  name; } ;
struct device {int /*<<< orphan*/  driver; } ;
struct dc_kbd {int* keycode; int* new; int* old; struct input_dev* dev; } ;
struct TYPE_4__ {scalar_t__ buf; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int*) ; 
 int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUS_HOST ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  KEY_RESERVED ; 
 int /*<<< orphan*/  MAPLE_FUNC_KEYBOARD ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 int NR_SCANCODES ; 
 int /*<<< orphan*/  __clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __set_bit (unsigned long,int /*<<< orphan*/ ) ; 
 unsigned long* dc_kbd_keycode ; 
 int /*<<< orphan*/  dev_dbg (TYPE_3__*,char*,int) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int,int) ; 
 int /*<<< orphan*/  input_set_capability (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct dc_kbd*) ; 
 struct dc_kbd* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int /*<<< orphan*/ ) ; 
 struct dc_kbd* maple_get_drvdata (struct maple_device*) ; 
 int /*<<< orphan*/  maple_getcond_callback (struct maple_device*,void (*) (struct mapleq*),int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  maple_keyb_mutex ; 
 int /*<<< orphan*/  maple_set_drvdata (struct maple_device*,struct dc_kbd*) ; 
 void* memchr (int*,int,int) ; 
 int /*<<< orphan*/  memcpy (int*,unsigned long*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct maple_device* to_maple_dev (struct device*) ; 
 struct maple_driver* to_maple_driver (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dc_scan_kbd(struct dc_kbd *kbd)
{
	struct input_dev *dev = kbd->dev;
	void *ptr;
	int code, keycode;
	int i;

	for (i = 0; i < 8; i++) {
		code = i + 224;
		keycode = kbd->keycode[code];
		input_event(dev, EV_MSC, MSC_SCAN, code);
		input_report_key(dev, keycode, (kbd->new[0] >> i) & 1);
	}

	for (i = 2; i < 8; i++) {
		ptr = memchr(kbd->new + 2, kbd->old[i], 6);
		code = kbd->old[i];
		if (code > 3 && ptr == NULL) {
			keycode = kbd->keycode[code];
			if (keycode) {
				input_event(dev, EV_MSC, MSC_SCAN, code);
				input_report_key(dev, keycode, 0);
			} else
				dev_dbg(&dev->dev,
					"Unknown key (scancode %#x) released.",
					code);
		}
		ptr = memchr(kbd->old + 2, kbd->new[i], 6);
		code = kbd->new[i];
		if (code > 3 && ptr) {
			keycode = kbd->keycode[code];
			if (keycode) {
				input_event(dev, EV_MSC, MSC_SCAN, code);
				input_report_key(dev, keycode, 1);
			} else
				dev_dbg(&dev->dev,
					"Unknown key (scancode %#x) pressed.",
					code);
		}
	}
	input_sync(dev);
	memcpy(kbd->old, kbd->new, 8);
}

__attribute__((used)) static void dc_kbd_callback(struct mapleq *mq)
{
	struct maple_device *mapledev = mq->dev;
	struct dc_kbd *kbd = maple_get_drvdata(mapledev);
	unsigned long *buf = (unsigned long *)(mq->recvbuf->buf);

	/*
	 * We should always get the lock because the only
	 * time it may be locked is if the driver is in the cleanup phase.
	 */
	if (likely(mutex_trylock(&maple_keyb_mutex))) {

		if (buf[1] == mapledev->function) {
			memcpy(kbd->new, buf + 2, 8);
			dc_scan_kbd(kbd);
		}

		mutex_unlock(&maple_keyb_mutex);
	}
}

__attribute__((used)) static int probe_maple_kbd(struct device *dev)
{
	struct maple_device *mdev;
	struct maple_driver *mdrv;
	int i, error;
	struct dc_kbd *kbd;
	struct input_dev *idev;

	mdev = to_maple_dev(dev);
	mdrv = to_maple_driver(dev->driver);

	kbd = kzalloc(sizeof(struct dc_kbd), GFP_KERNEL);
	if (!kbd) {
		error = -ENOMEM;
		goto fail;
	}

	idev = input_allocate_device();
	if (!idev) {
		error = -ENOMEM;
		goto fail_idev_alloc;
	}

	kbd->dev = idev;
	memcpy(kbd->keycode, dc_kbd_keycode, sizeof(kbd->keycode));

	idev->name = mdev->product_name;
	idev->evbit[0] = BIT(EV_KEY) | BIT(EV_REP);
	idev->keycode = kbd->keycode;
	idev->keycodesize = sizeof(unsigned short);
	idev->keycodemax = ARRAY_SIZE(kbd->keycode);
	idev->id.bustype = BUS_HOST;
	idev->dev.parent = &mdev->dev;

	for (i = 0; i < NR_SCANCODES; i++)
		__set_bit(dc_kbd_keycode[i], idev->keybit);
	__clear_bit(KEY_RESERVED, idev->keybit);

	input_set_capability(idev, EV_MSC, MSC_SCAN);

	error = input_register_device(idev);
	if (error)
		goto fail_register;

	/* Maple polling is locked to VBLANK - which may be just 50/s */
	maple_getcond_callback(mdev, dc_kbd_callback, HZ/50,
		MAPLE_FUNC_KEYBOARD);

	mdev->driver = mdrv;

	maple_set_drvdata(mdev, kbd);

	return error;

fail_register:
	maple_set_drvdata(mdev, NULL);
	input_free_device(idev);
fail_idev_alloc:
	kfree(kbd);
fail:
	return error;
}

__attribute__((used)) static int remove_maple_kbd(struct device *dev)
{
	struct maple_device *mdev = to_maple_dev(dev);
	struct dc_kbd *kbd = maple_get_drvdata(mdev);

	mutex_lock(&maple_keyb_mutex);

	input_unregister_device(kbd->dev);
	kfree(kbd);

	maple_set_drvdata(mdev, NULL);

	mutex_unlock(&maple_keyb_mutex);
	return 0;
}

