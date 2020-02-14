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
struct fb_info {int dummy; } ;

/* Variables and functions */
 unsigned int EP93XX_SYSCON_DEVCFG_EXVC ; 
 unsigned int EP93XX_SYSCON_DEVCFG_RAS ; 
 unsigned int EP93XX_SYSCON_DEVCFG_RASONP3 ; 
 int /*<<< orphan*/  GPIOF_INIT_HIGH ; 
 int /*<<< orphan*/  VISION_LCD_ENABLE ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ep93xx_devcfg_set_clear (int,unsigned int) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int gpio_request_one (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void ep93xx_devcfg_set_bits(unsigned int bits)
{
	ep93xx_devcfg_set_clear(bits, 0x00);
}

__attribute__((used)) static inline void ep93xx_devcfg_clear_bits(unsigned int bits)
{
	ep93xx_devcfg_set_clear(0x00, bits);
}

__attribute__((used)) static int vision_lcd_setup(struct platform_device *pdev)
{
	int err;

	err = gpio_request_one(VISION_LCD_ENABLE, GPIOF_INIT_HIGH,
				dev_name(&pdev->dev));
	if (err)
		return err;

	ep93xx_devcfg_clear_bits(EP93XX_SYSCON_DEVCFG_RAS |
				 EP93XX_SYSCON_DEVCFG_RASONP3 |
				 EP93XX_SYSCON_DEVCFG_EXVC);

	return 0;
}

__attribute__((used)) static void vision_lcd_teardown(struct platform_device *pdev)
{
	gpio_free(VISION_LCD_ENABLE);
}

__attribute__((used)) static void vision_lcd_blank(int blank_mode, struct fb_info *info)
{
	if (blank_mode)
		gpio_set_value(VISION_LCD_ENABLE, 0);
	else
		gpio_set_value(VISION_LCD_ENABLE, 1);
}

