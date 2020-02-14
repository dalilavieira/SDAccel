#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct wm97xx {scalar_t__ id; scalar_t__ pen_irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  variant; int /*<<< orphan*/  acc_slot; int /*<<< orphan*/  acc_rate; int /*<<< orphan*/ * ac97; int /*<<< orphan*/  input_dev; } ;
struct platform_device {int dummy; } ;
struct TYPE_3__ {int reads; scalar_t__ id; scalar_t__ speed; int /*<<< orphan*/  code; } ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_PRESSURE ; 
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int ENODEV ; 
 int /*<<< orphan*/  IRQ_TYPE_EDGE_BOTH ; 
 int MODR ; 
 int RC_AGAIN ; 
 int RC_PENDOWN ; 
 int RC_PENUP ; 
#define  WM9705_ID2 130 
#define  WM9712_ID2 129 
#define  WM9713_ID2 128 
 int WM97XX_ADCSEL_MASK ; 
 int WM97XX_ADCSEL_PRES ; 
 int WM97XX_ADCSEL_X ; 
 int WM97XX_ADCSEL_Y ; 
 int /*<<< orphan*/  WM97XX_GPIO_13 ; 
 int /*<<< orphan*/  WM97XX_GPIO_2 ; 
 int /*<<< orphan*/  WM97XX_GPIO_IN ; 
 int /*<<< orphan*/  WM97XX_GPIO_NOTSTICKY ; 
 int /*<<< orphan*/  WM97XX_GPIO_NOWAKE ; 
 int /*<<< orphan*/  WM97XX_GPIO_OUT ; 
 int /*<<< orphan*/  WM97XX_GPIO_POL_HIGH ; 
 int /*<<< orphan*/  WM97XX_GPIO_STICKY ; 
 int /*<<< orphan*/  WM97XX_GPIO_WAKE ; 
 int /*<<< orphan*/  WM97xx_WM1613 ; 
 int /*<<< orphan*/  ac97_touch_slot ; 
 TYPE_1__* cinfo ; 
 scalar_t__ cont_rate ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int /*<<< orphan*/  disable_irq_nosync (scalar_t__) ; 
 int /*<<< orphan*/  enable_irq (scalar_t__) ; 
 int gpio_direction_input (int) ; 
 int /*<<< orphan*/  gpio_free (int) ; 
 int gpio_request (int,char*) ; 
 scalar_t__ gpio_to_irq (int) ; 
 int /*<<< orphan*/  input_report_abs (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_sync (int /*<<< orphan*/ ) ; 
 int irq ; 
 int /*<<< orphan*/  irq_set_irq_type (scalar_t__,int /*<<< orphan*/ ) ; 
 int last ; 
 scalar_t__ machine_is_mainstone () ; 
 scalar_t__ machine_is_palmld () ; 
 scalar_t__ machine_is_palmt5 () ; 
 scalar_t__ machine_is_palmtx () ; 
 int /*<<< orphan*/  mainstone_mach_ops ; 
 int pen_int ; 
 struct wm97xx* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ pressure ; 
 int /*<<< orphan*/  schedule_timeout_uninterruptible (int) ; 
 size_t sp_idx ; 
 int tries ; 
 int /*<<< orphan*/  wm97xx_config_gpio (struct wm97xx*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int wm97xx_register_mach_ops (struct wm97xx*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wm97xx_unregister_mach_ops (struct wm97xx*) ; 

__attribute__((used)) static void wm97xx_acc_pen_up(struct wm97xx *wm)
{
	unsigned int count;

	schedule_timeout_uninterruptible(1);

	for (count = 0; count < 16; count++)
		MODR;
}

__attribute__((used)) static int wm97xx_acc_pen_down(struct wm97xx *wm)
{
	u16 x, y, p = 0x100 | WM97XX_ADCSEL_PRES;
	int reads = 0;

	/* When the AC97 queue has been drained we need to allow time
	 * to buffer up samples otherwise we end up spinning polling
	 * for samples.  The controller can't have a suitably low
	 * threshold set to use the notifications it gives.
	 */
	schedule_timeout_uninterruptible(1);

	if (tries > 5) {
		tries = 0;
		return RC_PENUP;
	}

	x = MODR;
	if (x == last) {
		tries++;
		return RC_AGAIN;
	}
	last = x;
	do {
		if (reads)
			x = MODR;
		y = MODR;
		if (pressure)
			p = MODR;

		dev_dbg(wm->dev, "Raw coordinates: x=%x, y=%x, p=%x\n",
			x, y, p);

		/* are samples valid */
		if ((x & WM97XX_ADCSEL_MASK) != WM97XX_ADCSEL_X ||
		    (y & WM97XX_ADCSEL_MASK) != WM97XX_ADCSEL_Y ||
		    (p & WM97XX_ADCSEL_MASK) != WM97XX_ADCSEL_PRES)
			goto up;

		/* coordinate is good */
		tries = 0;
		input_report_abs(wm->input_dev, ABS_X, x & 0xfff);
		input_report_abs(wm->input_dev, ABS_Y, y & 0xfff);
		input_report_abs(wm->input_dev, ABS_PRESSURE, p & 0xfff);
		input_report_key(wm->input_dev, BTN_TOUCH, (p != 0));
		input_sync(wm->input_dev);
		reads++;
	} while (reads < cinfo[sp_idx].reads);
up:
	return RC_PENDOWN | RC_AGAIN;
}

__attribute__((used)) static int wm97xx_acc_startup(struct wm97xx *wm)
{
	int idx = 0, ret = 0;

	/* check we have a codec */
	if (wm->ac97 == NULL)
		return -ENODEV;

	/* Go you big red fire engine */
	for (idx = 0; idx < ARRAY_SIZE(cinfo); idx++) {
		if (wm->id != cinfo[idx].id)
			continue;
		sp_idx = idx;
		if (cont_rate <= cinfo[idx].speed)
			break;
	}
	wm->acc_rate = cinfo[sp_idx].code;
	wm->acc_slot = ac97_touch_slot;
	dev_info(wm->dev,
		 "mainstone accelerated touchscreen driver, %d samples/sec\n",
		 cinfo[sp_idx].speed);

	/* IRQ driven touchscreen is used on Palm hardware */
	if (machine_is_palmt5() || machine_is_palmtx() || machine_is_palmld()) {
		pen_int = 1;
		irq = 27;
		/* There is some obscure mutant of WM9712 interbred with WM9713
		 * used on Palm HW */
		wm->variant = WM97xx_WM1613;
	} else if (machine_is_mainstone() && pen_int)
		irq = 4;

	if (irq) {
		ret = gpio_request(irq, "Touchscreen IRQ");
		if (ret)
			goto out;

		ret = gpio_direction_input(irq);
		if (ret) {
			gpio_free(irq);
			goto out;
		}

		wm->pen_irq = gpio_to_irq(irq);
		irq_set_irq_type(wm->pen_irq, IRQ_TYPE_EDGE_BOTH);
	} else /* pen irq not supported */
		pen_int = 0;

	/* codec specific irq config */
	if (pen_int) {
		switch (wm->id) {
		case WM9705_ID2:
			break;
		case WM9712_ID2:
		case WM9713_ID2:
			/* use PEN_DOWN GPIO 13 to assert IRQ on GPIO line 2 */
			wm97xx_config_gpio(wm, WM97XX_GPIO_13, WM97XX_GPIO_IN,
					   WM97XX_GPIO_POL_HIGH,
					   WM97XX_GPIO_STICKY,
					   WM97XX_GPIO_WAKE);
			wm97xx_config_gpio(wm, WM97XX_GPIO_2, WM97XX_GPIO_OUT,
					   WM97XX_GPIO_POL_HIGH,
					   WM97XX_GPIO_NOTSTICKY,
					   WM97XX_GPIO_NOWAKE);
			break;
		default:
			dev_err(wm->dev,
				"pen down irq not supported on this device\n");
			pen_int = 0;
			break;
		}
	}

out:
	return ret;
}

__attribute__((used)) static void wm97xx_acc_shutdown(struct wm97xx *wm)
{
	/* codec specific deconfig */
	if (pen_int) {
		if (irq)
			gpio_free(irq);
		wm->pen_irq = 0;
	}
}

__attribute__((used)) static void wm97xx_irq_enable(struct wm97xx *wm, int enable)
{
	if (enable)
		enable_irq(wm->pen_irq);
	else
		disable_irq_nosync(wm->pen_irq);
}

__attribute__((used)) static int mainstone_wm97xx_probe(struct platform_device *pdev)
{
	struct wm97xx *wm = platform_get_drvdata(pdev);

	return wm97xx_register_mach_ops(wm, &mainstone_mach_ops);
}

__attribute__((used)) static int mainstone_wm97xx_remove(struct platform_device *pdev)
{
	struct wm97xx *wm = platform_get_drvdata(pdev);

	wm97xx_unregister_mach_ops(wm);
	return 0;
}

