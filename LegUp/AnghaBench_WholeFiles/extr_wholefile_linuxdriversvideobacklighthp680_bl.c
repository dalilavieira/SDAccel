#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct backlight_properties {int /*<<< orphan*/  max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_2__ {int brightness; scalar_t__ power; scalar_t__ fb_blank; } ;
struct backlight_device {TYPE_1__ props; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int /*<<< orphan*/  DAC_LCD_BRIGHTNESS ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  HD64461_GPBDR ; 
 int /*<<< orphan*/  HD64461_GPBDR_LCDOFF ; 
 int HP680_DEFAULT_INTENSITY ; 
 int /*<<< orphan*/  HP680_MAX_INTENSITY ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int PTR_ERR (struct backlight_device*) ; 
 int /*<<< orphan*/  bl_lock ; 
 int current_intensity ; 
 struct backlight_device* devm_backlight_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 int /*<<< orphan*/  hp680bl_ops ; 
 scalar_t__ hp680bl_suspended ; 
 int /*<<< orphan*/  inw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  outw (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct backlight_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct backlight_device*) ; 
 int /*<<< orphan*/  sh_dac_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sh_dac_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sh_dac_output (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void hp680bl_send_intensity(struct backlight_device *bd)
{
	unsigned long flags;
	u16 v;
	int intensity = bd->props.brightness;

	if (bd->props.power != FB_BLANK_UNBLANK)
		intensity = 0;
	if (bd->props.fb_blank != FB_BLANK_UNBLANK)
		intensity = 0;
	if (hp680bl_suspended)
		intensity = 0;

	spin_lock_irqsave(&bl_lock, flags);
	if (intensity && current_intensity == 0) {
		sh_dac_enable(DAC_LCD_BRIGHTNESS);
		v = inw(HD64461_GPBDR);
		v &= ~HD64461_GPBDR_LCDOFF;
		outw(v, HD64461_GPBDR);
		sh_dac_output(255-(u8)intensity, DAC_LCD_BRIGHTNESS);
	} else if (intensity == 0 && current_intensity != 0) {
		sh_dac_output(255-(u8)intensity, DAC_LCD_BRIGHTNESS);
		sh_dac_disable(DAC_LCD_BRIGHTNESS);
		v = inw(HD64461_GPBDR);
		v |= HD64461_GPBDR_LCDOFF;
		outw(v, HD64461_GPBDR);
	} else if (intensity) {
		sh_dac_output(255-(u8)intensity, DAC_LCD_BRIGHTNESS);
	}
	spin_unlock_irqrestore(&bl_lock, flags);

	current_intensity = intensity;
}

__attribute__((used)) static int hp680bl_set_intensity(struct backlight_device *bd)
{
	hp680bl_send_intensity(bd);
	return 0;
}

__attribute__((used)) static int hp680bl_get_intensity(struct backlight_device *bd)
{
	return current_intensity;
}

__attribute__((used)) static int hp680bl_probe(struct platform_device *pdev)
{
	struct backlight_properties props;
	struct backlight_device *bd;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = HP680_MAX_INTENSITY;
	bd = devm_backlight_device_register(&pdev->dev, "hp680-bl", &pdev->dev,
					NULL, &hp680bl_ops, &props);
	if (IS_ERR(bd))
		return PTR_ERR(bd);

	platform_set_drvdata(pdev, bd);

	bd->props.brightness = HP680_DEFAULT_INTENSITY;
	hp680bl_send_intensity(bd);

	return 0;
}

__attribute__((used)) static int hp680bl_remove(struct platform_device *pdev)
{
	struct backlight_device *bd = platform_get_drvdata(pdev);

	bd->props.brightness = 0;
	bd->props.power = 0;
	hp680bl_send_intensity(bd);

	return 0;
}

