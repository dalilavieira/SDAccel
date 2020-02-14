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
struct phy_device {int /*<<< orphan*/  dev_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  DNS323C_GPIO_POWER_OFF ; 
 int /*<<< orphan*/  DNS323_GPIO_POWER_OFF ; 
 int /*<<< orphan*/  MARVELL_PHY_M1118_DNS323_LEDS ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  pr_info (char*) ; 

__attribute__((used)) static inline void mss2_init(void) {}

__attribute__((used)) static void dns323a_power_off(void)
{
	pr_info("DNS-323: Triggering power-off...\n");
	gpio_set_value(DNS323_GPIO_POWER_OFF, 1);
}

__attribute__((used)) static void dns323b_power_off(void)
{
	pr_info("DNS-323: Triggering power-off...\n");
	/* Pin has to be changed to 1 and back to 0 to do actual power off. */
	gpio_set_value(DNS323_GPIO_POWER_OFF, 1);
	mdelay(100);
	gpio_set_value(DNS323_GPIO_POWER_OFF, 0);
}

__attribute__((used)) static void dns323c_power_off(void)
{
	pr_info("DNS-323: Triggering power-off...\n");
	gpio_set_value(DNS323C_GPIO_POWER_OFF, 1);
}

__attribute__((used)) static int dns323c_phy_fixup(struct phy_device *phy)
{
	phy->dev_flags |= MARVELL_PHY_M1118_DNS323_LEDS;

	return 0;
}

