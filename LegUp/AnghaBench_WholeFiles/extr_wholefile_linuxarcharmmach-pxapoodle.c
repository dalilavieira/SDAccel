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
struct pxamci_platform_data {int ocr_mask; } ;
struct device {struct pxamci_platform_data* platform_data; } ;
typedef  int /*<<< orphan*/  irq_handler_t ;

/* Variables and functions */
 int /*<<< orphan*/  POODLE_GPIO_SD_PWR ; 
 int /*<<< orphan*/  POODLE_GPIO_SD_PWR1 ; 
 int /*<<< orphan*/  REBOOT_HARD ; 
 int /*<<< orphan*/  gpio_direction_output (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  pxa_restart (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static inline void poodle_init_spi(void) {}

__attribute__((used)) static int poodle_mci_init(struct device *dev, irq_handler_t poodle_detect_int, void *data)
{
	int err;

	err = gpio_request(POODLE_GPIO_SD_PWR, "SD_PWR");
	if (err)
		goto err_free_2;

	err = gpio_request(POODLE_GPIO_SD_PWR1, "SD_PWR1");
	if (err)
		goto err_free_3;

	gpio_direction_output(POODLE_GPIO_SD_PWR, 0);
	gpio_direction_output(POODLE_GPIO_SD_PWR1, 0);

	return 0;

err_free_3:
	gpio_free(POODLE_GPIO_SD_PWR);
err_free_2:
	return err;
}

__attribute__((used)) static int poodle_mci_setpower(struct device *dev, unsigned int vdd)
{
	struct pxamci_platform_data* p_d = dev->platform_data;

	if ((1 << vdd) & p_d->ocr_mask) {
		gpio_set_value(POODLE_GPIO_SD_PWR, 1);
		mdelay(2);
		gpio_set_value(POODLE_GPIO_SD_PWR1, 1);
	} else {
		gpio_set_value(POODLE_GPIO_SD_PWR1, 0);
		gpio_set_value(POODLE_GPIO_SD_PWR, 0);
	}

	return 0;
}

__attribute__((used)) static void poodle_mci_exit(struct device *dev, void *data)
{
	gpio_free(POODLE_GPIO_SD_PWR1);
	gpio_free(POODLE_GPIO_SD_PWR);
}

__attribute__((used)) static void poodle_poweroff(void)
{
	pxa_restart(REBOOT_HARD, NULL);
}

