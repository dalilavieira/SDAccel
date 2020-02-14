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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO_FN_INTC_IRQ0 ; 
 int /*<<< orphan*/  GPIO_PTB3 ; 
 int /*<<< orphan*/  GPIO_PTB4 ; 
 int /*<<< orphan*/  GPIO_PTB5 ; 
 int /*<<< orphan*/  GPIO_PTB6 ; 
 int /*<<< orphan*/  GPIO_PTZ0 ; 
 int /*<<< orphan*/  gpio_direction_input (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int gpio_get_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_request (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void usb0_port_power(int port, int power)
{
	gpio_set_value(GPIO_PTB4, power);
}

__attribute__((used)) static void usb1_port_power(int port, int power)
{
	gpio_set_value(GPIO_PTB5, power);
}

__attribute__((used)) static int usbhs_get_id(struct platform_device *pdev)
{
	return gpio_get_value(GPIO_PTB3);
}

__attribute__((used)) static int usbhs_phy_reset(struct platform_device *pdev)
{
	/* enable vbus if HOST */
	if (!gpio_get_value(GPIO_PTB3))
		gpio_set_value(GPIO_PTB5, 1);

	return 0;
}

__attribute__((used)) static int ts_get_pendown_state(struct device *dev)
{
	int val = 0;
	gpio_free(GPIO_FN_INTC_IRQ0);
	gpio_request(GPIO_PTZ0, NULL);
	gpio_direction_input(GPIO_PTZ0);

	val = gpio_get_value(GPIO_PTZ0);

	gpio_free(GPIO_PTZ0);
	gpio_request(GPIO_FN_INTC_IRQ0, NULL);

	return val ? 0 : 1;
}

__attribute__((used)) static int ts_init(void)
{
	gpio_request(GPIO_FN_INTC_IRQ0, NULL);
	return 0;
}

__attribute__((used)) static void mmc_spi_setpower(struct device *dev, unsigned int maskval)
{
	gpio_set_value(GPIO_PTB6, maskval ? 1 : 0);
}

