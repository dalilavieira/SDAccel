#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct platform_device {int /*<<< orphan*/  dev; } ;
struct lcd_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ETIMEDOUT ; 
 int FB_BLANK_POWERDOWN ; 
 int FB_BLANK_UNBLANK ; 
 int GETCONTRAST ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 int LCD_DEF_CONTRAST ; 
 int PPC_LDD2 ; 
 int PPDR ; 
 int PPSR ; 
 int PTR_ERR (struct lcd_device*) ; 
 int /*<<< orphan*/  S1D_DEVICENAME ; 
 int SETCONTRAST ; 
 int TXDUMMY ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct lcd_device* devm_lcd_device_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  jornada_lcd_props ; 
 int jornada_ssp_byte (int) ; 
 int /*<<< orphan*/  jornada_ssp_end () ; 
 int /*<<< orphan*/  jornada_ssp_start () ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct lcd_device*) ; 

__attribute__((used)) static int jornada_lcd_get_power(struct lcd_device *ld)
{
	return PPSR & PPC_LDD2 ? FB_BLANK_UNBLANK : FB_BLANK_POWERDOWN;
}

__attribute__((used)) static int jornada_lcd_get_contrast(struct lcd_device *ld)
{
	int ret;

	if (jornada_lcd_get_power(ld) != FB_BLANK_UNBLANK)
		return 0;

	jornada_ssp_start();

	if (jornada_ssp_byte(GETCONTRAST) == TXDUMMY) {
		ret = jornada_ssp_byte(TXDUMMY);
		goto success;
	}

	dev_err(&ld->dev, "failed to set contrast\n");
	ret = -ETIMEDOUT;

success:
	jornada_ssp_end();
	return ret;
}

__attribute__((used)) static int jornada_lcd_set_contrast(struct lcd_device *ld, int value)
{
	int ret = 0;

	jornada_ssp_start();

	/* start by sending our set contrast cmd to mcu */
	if (jornada_ssp_byte(SETCONTRAST) == TXDUMMY) {
		/* if successful push the new value */
		if (jornada_ssp_byte(value) == TXDUMMY)
			goto success;
	}

	dev_err(&ld->dev, "failed to set contrast\n");
	ret = -ETIMEDOUT;

success:
	jornada_ssp_end();
	return ret;
}

__attribute__((used)) static int jornada_lcd_set_power(struct lcd_device *ld, int power)
{
	if (power != FB_BLANK_UNBLANK) {
		PPSR &= ~PPC_LDD2;
		PPDR |= PPC_LDD2;
	} else {
		PPSR |= PPC_LDD2;
	}

	return 0;
}

__attribute__((used)) static int jornada_lcd_probe(struct platform_device *pdev)
{
	struct lcd_device *lcd_device;
	int ret;

	lcd_device = devm_lcd_device_register(&pdev->dev, S1D_DEVICENAME,
					&pdev->dev, NULL, &jornada_lcd_props);

	if (IS_ERR(lcd_device)) {
		ret = PTR_ERR(lcd_device);
		dev_err(&pdev->dev, "failed to register device\n");
		return ret;
	}

	platform_set_drvdata(pdev, lcd_device);

	/* lets set our default values */
	jornada_lcd_set_contrast(lcd_device, LCD_DEF_CONTRAST);
	jornada_lcd_set_power(lcd_device, FB_BLANK_UNBLANK);
	/* give it some time to startup */
	msleep(100);

	return 0;
}

