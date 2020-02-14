#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_10__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_3__ dev; } ;
struct mfd_cell {size_t id; } ;
struct led_classdev {TYPE_1__* dev; } ;
struct asic3_led {TYPE_2__* cdev; int /*<<< orphan*/  default_trigger; int /*<<< orphan*/  name; } ;
struct asic3 {int dummy; } ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;
struct TYPE_9__ {void (* brightness_set ) (struct led_classdev*,int) ;int (* blink_set ) (struct led_classdev*,unsigned long*,unsigned long*) ;int /*<<< orphan*/  default_trigger; int /*<<< orphan*/  flags; int /*<<< orphan*/  name; } ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 scalar_t__ ASIC3_LED_AutoStopCount ; 
 scalar_t__ ASIC3_LED_DutyTime ; 
 scalar_t__ ASIC3_LED_PeriodTime ; 
 scalar_t__ ASIC3_LED_TimeBase ; 
 unsigned long CLK_TO_MS (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  LED_CORE_SUSPENDRESUME ; 
 int LED_EN ; 
 int LED_OFF ; 
 int MAX_CLK ; 
 unsigned long MAX_MS ; 
 int MS_TO_CLK (unsigned long) ; 
 int /*<<< orphan*/  asic3_write_register (struct asic3*,scalar_t__,int) ; 
 struct asic3* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct asic3_led* dev_get_platdata (TYPE_3__*) ; 
 TYPE_2__* devm_kzalloc (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int led_classdev_register (TYPE_3__*,TYPE_2__*) ; 
 int /*<<< orphan*/  led_classdev_unregister (TYPE_2__*) ; 
 unsigned int* led_n_base ; 
 int mfd_cell_disable (struct platform_device*) ; 
 int mfd_cell_enable (struct platform_device*) ; 
 struct mfd_cell* mfd_get_cell (struct platform_device*) ; 
 struct platform_device* to_platform_device (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void brightness_set(struct led_classdev *cdev,
	enum led_brightness value)
{
	struct platform_device *pdev = to_platform_device(cdev->dev->parent);
	const struct mfd_cell *cell = mfd_get_cell(pdev);
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
	u32 timebase;
	unsigned int base;

	timebase = (value == LED_OFF) ? 0 : (LED_EN|0x4);

	base = led_n_base[cell->id];
	asic3_write_register(asic, (base + ASIC3_LED_PeriodTime), 32);
	asic3_write_register(asic, (base + ASIC3_LED_DutyTime), 32);
	asic3_write_register(asic, (base + ASIC3_LED_AutoStopCount), 0);
	asic3_write_register(asic, (base + ASIC3_LED_TimeBase), timebase);
}

__attribute__((used)) static int blink_set(struct led_classdev *cdev,
	unsigned long *delay_on,
	unsigned long *delay_off)
{
	struct platform_device *pdev = to_platform_device(cdev->dev->parent);
	const struct mfd_cell *cell = mfd_get_cell(pdev);
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
	u32 on;
	u32 off;
	unsigned int base;

	if (*delay_on > MAX_MS || *delay_off > MAX_MS)
		return -EINVAL;

	if (*delay_on == 0 && *delay_off == 0) {
		/* If both are zero then a sensible default should be chosen */
		on = MS_TO_CLK(500);
		off = MS_TO_CLK(500);
	} else {
		on = MS_TO_CLK(*delay_on);
		off = MS_TO_CLK(*delay_off);
		if ((on + off) > MAX_CLK)
			return -EINVAL;
	}

	base = led_n_base[cell->id];
	asic3_write_register(asic, (base + ASIC3_LED_PeriodTime), (on + off));
	asic3_write_register(asic, (base + ASIC3_LED_DutyTime), on);
	asic3_write_register(asic, (base + ASIC3_LED_AutoStopCount), 0);
	asic3_write_register(asic, (base + ASIC3_LED_TimeBase), (LED_EN|0x4));

	*delay_on = CLK_TO_MS(on);
	*delay_off = CLK_TO_MS(off);

	return 0;
}

__attribute__((used)) static int asic3_led_probe(struct platform_device *pdev)
{
	struct asic3_led *led = dev_get_platdata(&pdev->dev);
	int ret;

	ret = mfd_cell_enable(pdev);
	if (ret < 0)
		return ret;

	led->cdev = devm_kzalloc(&pdev->dev, sizeof(struct led_classdev),
				GFP_KERNEL);
	if (!led->cdev) {
		ret = -ENOMEM;
		goto out;
	}

	led->cdev->name = led->name;
	led->cdev->flags = LED_CORE_SUSPENDRESUME;
	led->cdev->brightness_set = brightness_set;
	led->cdev->blink_set = blink_set;
	led->cdev->default_trigger = led->default_trigger;

	ret = led_classdev_register(&pdev->dev, led->cdev);
	if (ret < 0)
		goto out;

	return 0;

out:
	(void) mfd_cell_disable(pdev);
	return ret;
}

__attribute__((used)) static int asic3_led_remove(struct platform_device *pdev)
{
	struct asic3_led *led = dev_get_platdata(&pdev->dev);

	led_classdev_unregister(led->cdev);

	return mfd_cell_disable(pdev);
}

