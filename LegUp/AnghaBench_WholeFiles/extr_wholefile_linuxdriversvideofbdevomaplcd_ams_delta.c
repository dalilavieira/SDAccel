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
struct platform_device {int dummy; } ;
struct omapfb_device {int dummy; } ;
struct lcd_panel {int dummy; } ;
struct lcd_device {int dummy; } ;

/* Variables and functions */
 int AMS_DELTA_DEFAULT_CONTRAST ; 
 int /*<<< orphan*/  AMS_DELTA_GPIO_PIN_LCD_NDISP ; 
 int /*<<< orphan*/  AMS_DELTA_GPIO_PIN_LCD_VBLEN ; 
 int AMS_DELTA_LCD_POWER ; 
 int AMS_DELTA_MAX_CONTRAST ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  OMAP_PWL_CLK_ENABLE ; 
 int /*<<< orphan*/  OMAP_PWL_ENABLE ; 
 int /*<<< orphan*/  _gpios ; 
 int ams_delta_lcd ; 
 int /*<<< orphan*/  ams_delta_panel ; 
 int /*<<< orphan*/  gpio_free_array (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gpio_request_array (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  omap_writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omapfb_register_panel (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ams_delta_lcd_set_power(struct lcd_device *dev, int power)
{
	if (power == FB_BLANK_UNBLANK) {
		if (!(ams_delta_lcd & AMS_DELTA_LCD_POWER)) {
			omap_writeb(ams_delta_lcd & AMS_DELTA_MAX_CONTRAST,
					OMAP_PWL_ENABLE);
			omap_writeb(1, OMAP_PWL_CLK_ENABLE);
			ams_delta_lcd |= AMS_DELTA_LCD_POWER;
		}
	} else {
		if (ams_delta_lcd & AMS_DELTA_LCD_POWER) {
			omap_writeb(0, OMAP_PWL_ENABLE);
			omap_writeb(0, OMAP_PWL_CLK_ENABLE);
			ams_delta_lcd &= ~AMS_DELTA_LCD_POWER;
		}
	}
	return 0;
}

__attribute__((used)) static int ams_delta_lcd_set_contrast(struct lcd_device *dev, int value)
{
	if ((value >= 0) && (value <= AMS_DELTA_MAX_CONTRAST)) {
		omap_writeb(value, OMAP_PWL_ENABLE);
		ams_delta_lcd &= ~AMS_DELTA_MAX_CONTRAST;
		ams_delta_lcd |= value;
	}
	return 0;
}

__attribute__((used)) static int ams_delta_panel_init(struct lcd_panel *panel,
		struct omapfb_device *fbdev)
{
	return gpio_request_array(_gpios, ARRAY_SIZE(_gpios));
}

__attribute__((used)) static void ams_delta_panel_cleanup(struct lcd_panel *panel)
{
	gpio_free_array(_gpios, ARRAY_SIZE(_gpios));
}

__attribute__((used)) static int ams_delta_panel_enable(struct lcd_panel *panel)
{
	gpio_set_value(AMS_DELTA_GPIO_PIN_LCD_NDISP, 1);
	gpio_set_value(AMS_DELTA_GPIO_PIN_LCD_VBLEN, 1);
	return 0;
}

__attribute__((used)) static void ams_delta_panel_disable(struct lcd_panel *panel)
{
	gpio_set_value(AMS_DELTA_GPIO_PIN_LCD_VBLEN, 0);
	gpio_set_value(AMS_DELTA_GPIO_PIN_LCD_NDISP, 0);
}

__attribute__((used)) static int ams_delta_panel_probe(struct platform_device *pdev)
{
	struct lcd_device *lcd_device = NULL;
#ifdef CONFIG_LCD_CLASS_DEVICE
	int ret;

	lcd_device = lcd_device_register("omapfb", &pdev->dev, NULL,
						&ams_delta_lcd_ops);

	if (IS_ERR(lcd_device)) {
		ret = PTR_ERR(lcd_device);
		dev_err(&pdev->dev, "failed to register device\n");
		return ret;
	}

	platform_set_drvdata(pdev, lcd_device);
	lcd_device->props.max_contrast = AMS_DELTA_MAX_CONTRAST;
#endif

	ams_delta_lcd_set_contrast(lcd_device, AMS_DELTA_DEFAULT_CONTRAST);
	ams_delta_lcd_set_power(lcd_device, FB_BLANK_UNBLANK);

	omapfb_register_panel(&ams_delta_panel);
	return 0;
}

