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
struct TYPE_6__ {int /*<<< orphan*/  parent; } ;
struct locomo_dev {TYPE_3__ dev; scalar_t__ mapbase; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_4__ {int brightness; scalar_t__ power; scalar_t__ fb_blank; } ;
struct backlight_device {TYPE_1__ props; } ;
struct TYPE_5__ {int comadj; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int ENODEV ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int LOCOMOLCD_SUSPENDED ; 
 scalar_t__ LOCOMO_CPSD ; 
 int /*<<< orphan*/  LOCOMO_GPIO_FL_VR ; 
 int /*<<< orphan*/  LOCOMO_GPIO_LCD_MOD ; 
 int /*<<< orphan*/  LOCOMO_GPIO_LCD_VEE_ON ; 
 int /*<<< orphan*/  LOCOMO_GPIO_LCD_VSHA_ON ; 
 int /*<<< orphan*/  LOCOMO_GPIO_LCD_VSHD_ON ; 
 scalar_t__ LOCOMO_TC ; 
 int PTR_ERR (struct backlight_device*) ; 
 struct backlight_device* backlight_device_register (char*,TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int /*<<< orphan*/  backlight_device_unregister (struct backlight_device*) ; 
 int current_intensity ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  locomo_frontlight_set (struct locomo_dev*,int,int,int) ; 
 int /*<<< orphan*/  locomo_gpio_set_dir (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  locomo_gpio_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  locomo_m62332_senddata (struct locomo_dev*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  locomo_writel (int,scalar_t__) ; 
 int /*<<< orphan*/  locomobl_data ; 
 struct backlight_device* locomolcd_bl_device ; 
 struct locomo_dev* locomolcd_dev ; 
 int locomolcd_flags ; 
 scalar_t__ machine_is_collie () ; 
 scalar_t__ machine_is_poodle () ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 TYPE_2__ sharpsl_param ; 

__attribute__((used)) static inline int sa11x0_pm_init(void) { return 0; }

__attribute__((used)) static void locomolcd_on(int comadj)
{
	locomo_gpio_set_dir(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHA_ON, 0);
	locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHA_ON, 1);
	mdelay(2);

	locomo_gpio_set_dir(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHD_ON, 0);
	locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHD_ON, 1);
	mdelay(2);

	locomo_m62332_senddata(locomolcd_dev, comadj, 0);
	mdelay(5);

	locomo_gpio_set_dir(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VEE_ON, 0);
	locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VEE_ON, 1);
	mdelay(10);

	/* TFTCRST | CPSOUT=0 | CPSEN */
	locomo_writel(0x01, locomolcd_dev->mapbase + LOCOMO_TC);

	/* Set CPSD */
	locomo_writel(6, locomolcd_dev->mapbase + LOCOMO_CPSD);

	/* TFTCRST | CPSOUT=0 | CPSEN */
	locomo_writel((0x04 | 0x01), locomolcd_dev->mapbase + LOCOMO_TC);
	mdelay(10);

	locomo_gpio_set_dir(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_MOD, 0);
	locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_MOD, 1);
}

__attribute__((used)) static void locomolcd_off(int comadj)
{
	/* TFTCRST=1 | CPSOUT=1 | CPSEN = 0 */
	locomo_writel(0x06, locomolcd_dev->mapbase + LOCOMO_TC);
	mdelay(1);

	locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHA_ON, 0);
	mdelay(110);

	locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VEE_ON, 0);
	mdelay(700);

	/* TFTCRST=0 | CPSOUT=0 | CPSEN = 0 */
	locomo_writel(0, locomolcd_dev->mapbase + LOCOMO_TC);
	locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_MOD, 0);
	locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHD_ON, 0);
}

void locomolcd_power(int on)
{
	int comadj = sharpsl_param.comadj;
	unsigned long flags;

	local_irq_save(flags);

	if (!locomolcd_dev) {
		local_irq_restore(flags);
		return;
	}

	/* read comadj */
	if (comadj == -1 && machine_is_collie())
		comadj = 128;
	if (comadj == -1 && machine_is_poodle())
		comadj = 118;

	if (on)
		locomolcd_on(comadj);
	else
		locomolcd_off(comadj);

	local_irq_restore(flags);
}

__attribute__((used)) static int locomolcd_set_intensity(struct backlight_device *bd)
{
	int intensity = bd->props.brightness;

	if (bd->props.power != FB_BLANK_UNBLANK)
		intensity = 0;
	if (bd->props.fb_blank != FB_BLANK_UNBLANK)
		intensity = 0;
	if (locomolcd_flags & LOCOMOLCD_SUSPENDED)
		intensity = 0;

	switch (intensity) {
	/*
	 * AC and non-AC are handled differently,
	 * but produce same results in sharp code?
	 */
	case 0:
		locomo_frontlight_set(locomolcd_dev, 0, 0, 161);
		break;
	case 1:
		locomo_frontlight_set(locomolcd_dev, 117, 0, 161);
		break;
	case 2:
		locomo_frontlight_set(locomolcd_dev, 163, 0, 148);
		break;
	case 3:
		locomo_frontlight_set(locomolcd_dev, 194, 0, 161);
		break;
	case 4:
		locomo_frontlight_set(locomolcd_dev, 194, 1, 161);
		break;
	default:
		return -ENODEV;
	}
	current_intensity = intensity;
	return 0;
}

__attribute__((used)) static int locomolcd_get_intensity(struct backlight_device *bd)
{
	return current_intensity;
}

__attribute__((used)) static int locomolcd_probe(struct locomo_dev *ldev)
{
	struct backlight_properties props;
	unsigned long flags;

	local_irq_save(flags);
	locomolcd_dev = ldev;

	locomo_gpio_set_dir(ldev->dev.parent, LOCOMO_GPIO_FL_VR, 0);

	/*
	 * the poodle_lcd_power function is called for the first time
	 * from fs_initcall, which is before locomo is activated.
	 * We need to recall poodle_lcd_power here
	 */
	if (machine_is_poodle())
		locomolcd_power(1);

	local_irq_restore(flags);

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = 4;
	locomolcd_bl_device = backlight_device_register("locomo-bl",
							&ldev->dev, NULL,
							&locomobl_data, &props);

	if (IS_ERR(locomolcd_bl_device))
		return PTR_ERR(locomolcd_bl_device);

	/* Set up frontlight so that screen is readable */
	locomolcd_bl_device->props.brightness = 2;
	locomolcd_set_intensity(locomolcd_bl_device);

	return 0;
}

__attribute__((used)) static int locomolcd_remove(struct locomo_dev *dev)
{
	unsigned long flags;

	locomolcd_bl_device->props.brightness = 0;
	locomolcd_bl_device->props.power = 0;
	locomolcd_set_intensity(locomolcd_bl_device);

	backlight_device_unregister(locomolcd_bl_device);
	local_irq_save(flags);
	locomolcd_dev = NULL;
	local_irq_restore(flags);
	return 0;
}

