#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct timer_list {int dummy; } ;
struct pci_dev {scalar_t__ devfn; int broken_parity_status; TYPE_1__* bus; } ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;
struct TYPE_5__ {scalar_t__ expires; } ;
struct TYPE_4__ {scalar_t__ number; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int HZ ; 
 int* IOP3XX_ICR0 ; 
 int* IOP3XX_IDBR0 ; 
 int /*<<< orphan*/  N2100_HARDWARE_RESET ; 
 int /*<<< orphan*/  N2100_POWER_BUTTON ; 
 scalar_t__ PCI_DEVFN (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  add_timer (TYPE_2__*) ; 
 int /*<<< orphan*/  ctrl_alt_del () ; 
 int gpio_direction_output (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_get_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iop32x_gpio_res ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  platform_device_register_simple (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__ power_button_poll_timer ; 
 int /*<<< orphan*/  pr_crit (char*) ; 

__attribute__((used)) static inline void register_iop32x_gpio(void)
{
	platform_device_register_simple("gpio-iop", 0,
					iop32x_gpio_res,
					ARRAY_SIZE(iop32x_gpio_res));
}

__attribute__((used)) static void n2100_fixup_r8169(struct pci_dev *dev)
{
	if (dev->bus->number == 0 &&
	    (dev->devfn == PCI_DEVFN(1, 0) ||
	     dev->devfn == PCI_DEVFN(2, 0)))
		dev->broken_parity_status = 1;
}

__attribute__((used)) static void n2100_power_off(void)
{
	local_irq_disable();

	/* Start condition, I2C address of PCA9532, write transaction.  */
	*IOP3XX_IDBR0 = 0xc0;
	*IOP3XX_ICR0 = 0xe9;
	mdelay(1);

	/* Write address 0x08.  */
	*IOP3XX_IDBR0 = 0x08;
	*IOP3XX_ICR0 = 0xe8;
	mdelay(1);

	/* Write data 0x01, stop condition.  */
	*IOP3XX_IDBR0 = 0x01;
	*IOP3XX_ICR0 = 0xea;

	while (1)
		;
}

__attribute__((used)) static void n2100_restart(enum reboot_mode mode, const char *cmd)
{
	int ret;

	ret = gpio_direction_output(N2100_HARDWARE_RESET, 0);
	if (ret) {
		pr_crit("could not drive reset GPIO low\n");
		return;
	}
	/* Wait for reset to happen */
	while (1)
		;
}

__attribute__((used)) static void power_button_poll(struct timer_list *unused)
{
	if (gpio_get_value(N2100_POWER_BUTTON) == 0) {
		ctrl_alt_del();
		return;
	}

	power_button_poll_timer.expires = jiffies + (HZ / 10);
	add_timer(&power_button_poll_timer);
}

