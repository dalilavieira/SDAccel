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
struct plat_lcd_data {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO110_HX4700_LCD_LVDD_3V3_ON ; 
 int /*<<< orphan*/  GPIO111_HX4700_LCD_AVDD_3V3_ON ; 
 int /*<<< orphan*/  GPIO112_HX4700_LCD_N2V7_7V3_ON ; 
 int /*<<< orphan*/  GPIO59_HX4700_LCD_PC1 ; 
 int /*<<< orphan*/  GPIO62_HX4700_LCD_nRESET ; 
 int /*<<< orphan*/  GPIO70_HX4700_LCD_SLIN1 ; 
 int /*<<< orphan*/  GPIO84_HX4700_LCD_SQN ; 
 int /*<<< orphan*/  GPIO91_HX4700_FLASH_VPEN ; 
 int /*<<< orphan*/  GPIOD9_nAC_IN ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_get_value (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static void sony_lcd_init(void)
{
	gpio_set_value(GPIO84_HX4700_LCD_SQN, 1);
	gpio_set_value(GPIO110_HX4700_LCD_LVDD_3V3_ON, 0);
	gpio_set_value(GPIO111_HX4700_LCD_AVDD_3V3_ON, 0);
	gpio_set_value(GPIO70_HX4700_LCD_SLIN1, 0);
	gpio_set_value(GPIO62_HX4700_LCD_nRESET, 0);
	mdelay(10);
	gpio_set_value(GPIO59_HX4700_LCD_PC1, 0);
	gpio_set_value(GPIO110_HX4700_LCD_LVDD_3V3_ON, 0);
	mdelay(20);

	gpio_set_value(GPIO110_HX4700_LCD_LVDD_3V3_ON, 1);
	mdelay(5);
	gpio_set_value(GPIO111_HX4700_LCD_AVDD_3V3_ON, 1);

	/* FIXME: init w3220 registers here */

	mdelay(5);
	gpio_set_value(GPIO70_HX4700_LCD_SLIN1, 1);
	mdelay(10);
	gpio_set_value(GPIO62_HX4700_LCD_nRESET, 1);
	mdelay(10);
	gpio_set_value(GPIO59_HX4700_LCD_PC1, 1);
	mdelay(10);
	gpio_set_value(GPIO112_HX4700_LCD_N2V7_7V3_ON, 1);
}

__attribute__((used)) static void sony_lcd_off(void)
{
	gpio_set_value(GPIO59_HX4700_LCD_PC1, 0);
	gpio_set_value(GPIO62_HX4700_LCD_nRESET, 0);
	mdelay(10);
	gpio_set_value(GPIO112_HX4700_LCD_N2V7_7V3_ON, 0);
	mdelay(10);
	gpio_set_value(GPIO111_HX4700_LCD_AVDD_3V3_ON, 0);
	mdelay(10);
	gpio_set_value(GPIO110_HX4700_LCD_LVDD_3V3_ON, 0);
}

__attribute__((used)) static void hx4700_lcd_set_power(struct plat_lcd_data *pd, unsigned int power)
{
	if (power)
		sony_lcd_init();
	else
		sony_lcd_off();
}

__attribute__((used)) static int power_supply_init(struct device *dev)
{
	return gpio_request(GPIOD9_nAC_IN, "AC charger detect");
}

__attribute__((used)) static int hx4700_is_ac_online(void)
{
	return !gpio_get_value(GPIOD9_nAC_IN);
}

__attribute__((used)) static void power_supply_exit(struct device *dev)
{
	gpio_free(GPIOD9_nAC_IN);
}

__attribute__((used)) static void hx4700_set_vpp(struct platform_device *pdev, int vpp)
{
	gpio_set_value(GPIO91_HX4700_FLASH_VPEN, vpp);
}

