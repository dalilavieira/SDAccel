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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_AND_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO_NR_PALMTE2_BL_POWER ; 
 int /*<<< orphan*/  GPIO_NR_PALMTE2_LCD_POWER ; 
 int /*<<< orphan*/  GPIO_NR_PALMTE2_POWER_DETECT ; 
 int gpio_direction_input (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free_array (int /*<<< orphan*/ ) ; 
 int gpio_get_value (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int gpio_request_array (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  palmte_bl_gpios ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static int palmte2_backlight_init(struct device *dev)
{
	return gpio_request_array(ARRAY_AND_SIZE(palmte_bl_gpios));
}

__attribute__((used)) static int palmte2_backlight_notify(struct device *dev, int brightness)
{
	gpio_set_value(GPIO_NR_PALMTE2_BL_POWER, brightness);
	gpio_set_value(GPIO_NR_PALMTE2_LCD_POWER, brightness);
	return brightness;
}

__attribute__((used)) static void palmte2_backlight_exit(struct device *dev)
{
	gpio_free_array(ARRAY_AND_SIZE(palmte_bl_gpios));
}

__attribute__((used)) static int power_supply_init(struct device *dev)
{
	int ret;

	ret = gpio_request(GPIO_NR_PALMTE2_POWER_DETECT, "CABLE_STATE_AC");
	if (ret)
		goto err1;
	ret = gpio_direction_input(GPIO_NR_PALMTE2_POWER_DETECT);
	if (ret)
		goto err2;

	return 0;

err2:
	gpio_free(GPIO_NR_PALMTE2_POWER_DETECT);
err1:
	return ret;
}

__attribute__((used)) static int palmte2_is_ac_online(void)
{
	return gpio_get_value(GPIO_NR_PALMTE2_POWER_DETECT);
}

__attribute__((used)) static void power_supply_exit(struct device *dev)
{
	gpio_free(GPIO_NR_PALMTE2_POWER_DETECT);
}

