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
 int /*<<< orphan*/  COLLIE_GPIO_IR_ON ; 
 int /*<<< orphan*/  COLLIE_GPIO_VPEN ; 
 int gpio_direction_output (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int sa11x0_pm_init(void) { return 0; }

__attribute__((used)) static int collie_ir_startup(struct device *dev)
{
	int rc = gpio_request(COLLIE_GPIO_IR_ON, "IrDA");
	if (rc)
		return rc;
	rc = gpio_direction_output(COLLIE_GPIO_IR_ON, 1);

	if (!rc)
		return 0;

	gpio_free(COLLIE_GPIO_IR_ON);
	return rc;
}

__attribute__((used)) static void collie_ir_shutdown(struct device *dev)
{
	gpio_free(COLLIE_GPIO_IR_ON);
}

__attribute__((used)) static int collie_ir_set_power(struct device *dev, unsigned int state)
{
	gpio_set_value(COLLIE_GPIO_IR_ON, !state);
	return 0;
}

__attribute__((used)) static int collie_flash_init(void)
{
	int rc = gpio_request(COLLIE_GPIO_VPEN, "flash Vpp enable");
	if (rc)
		return rc;

	rc = gpio_direction_output(COLLIE_GPIO_VPEN, 1);
	if (rc)
		gpio_free(COLLIE_GPIO_VPEN);

	return rc;
}

__attribute__((used)) static void collie_set_vpp(int vpp)
{
	gpio_set_value(COLLIE_GPIO_VPEN, vpp);
}

__attribute__((used)) static void collie_flash_exit(void)
{
	gpio_free(COLLIE_GPIO_VPEN);
}

