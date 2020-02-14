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

/* Variables and functions */
 unsigned long UNIPHIER_PIN_DRVCTRL_MASK ; 
 unsigned long UNIPHIER_PIN_DRVCTRL_SHIFT ; 
 unsigned long UNIPHIER_PIN_DRV_TYPE_MASK ; 
 unsigned long UNIPHIER_PIN_DRV_TYPE_SHIFT ; 
 unsigned long UNIPHIER_PIN_IECTRL_MASK ; 
 unsigned long UNIPHIER_PIN_IECTRL_SHIFT ; 
 unsigned long UNIPHIER_PIN_PULL_DIR_MASK ; 
 unsigned long UNIPHIER_PIN_PULL_DIR_SHIFT ; 
 unsigned long UNIPHIER_PIN_PUPDCTRL_MASK ; 
 unsigned long UNIPHIER_PIN_PUPDCTRL_SHIFT ; 
 int uniphier_pinctrl_probe (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uniphier_pro5_pindata ; 

__attribute__((used)) static inline unsigned int uniphier_pin_get_iectrl(void *drv_data)
{
	return ((unsigned long)drv_data >> UNIPHIER_PIN_IECTRL_SHIFT) &
						UNIPHIER_PIN_IECTRL_MASK;
}

__attribute__((used)) static inline unsigned int uniphier_pin_get_drvctrl(void *drv_data)
{
	return ((unsigned long)drv_data >> UNIPHIER_PIN_DRVCTRL_SHIFT) &
						UNIPHIER_PIN_DRVCTRL_MASK;
}

__attribute__((used)) static inline unsigned int uniphier_pin_get_drv_type(void *drv_data)
{
	return ((unsigned long)drv_data >> UNIPHIER_PIN_DRV_TYPE_SHIFT) &
						UNIPHIER_PIN_DRV_TYPE_MASK;
}

__attribute__((used)) static inline unsigned int uniphier_pin_get_pupdctrl(void *drv_data)
{
	return ((unsigned long)drv_data >> UNIPHIER_PIN_PUPDCTRL_SHIFT) &
						UNIPHIER_PIN_PUPDCTRL_MASK;
}

__attribute__((used)) static inline unsigned int uniphier_pin_get_pull_dir(void *drv_data)
{
	return ((unsigned long)drv_data >> UNIPHIER_PIN_PULL_DIR_SHIFT) &
						UNIPHIER_PIN_PULL_DIR_MASK;
}

__attribute__((used)) static int uniphier_pro5_get_gpio_muxval(unsigned int pin,
					 unsigned int gpio_offset)
{
	if (gpio_offset >= 120 && gpio_offset <= 141)	/* XIRQ0-20 */
		return 14;

	return 15;
}

__attribute__((used)) static int uniphier_pro5_pinctrl_probe(struct platform_device *pdev)
{
	return uniphier_pinctrl_probe(pdev, &uniphier_pro5_pindata);
}

