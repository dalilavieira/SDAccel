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
struct power_supply {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  irq_handler_t ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO_CHARGE_DC_OK ; 
 int /*<<< orphan*/  GPIO_CHARGE_DONE ; 
 int /*<<< orphan*/  GPIO_W1_PULLUP_ENABLE ; 
 int /*<<< orphan*/  GPIO_W2W_PDN ; 
 int /*<<< orphan*/  GPIO_W2W_RESET ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  gpio_get_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mfp_config (unsigned long*,int) ; 
 unsigned long mfp_read (int) ; 
 int /*<<< orphan*/  mfp_write (int,unsigned long) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct power_supply* power_supply_get_by_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  power_supply_put (struct power_supply*) ; 
 int /*<<< orphan*/  power_supply_set_battery_charged (struct power_supply*) ; 
 int /*<<< orphan*/ * raumfeld_power_supplicants ; 

__attribute__((used)) static inline unsigned long pxa3xx_mfp_read(int mfp)
{
	return mfp_read(mfp);
}

__attribute__((used)) static inline void pxa3xx_mfp_write(int mfp, unsigned long val)
{
	mfp_write(mfp, val);
}

__attribute__((used)) static inline void pxa3xx_mfp_config(unsigned long *mfp_cfg, int num)
{
	mfp_config(mfp_cfg, num);
}

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static void w1_enable_external_pullup(int enable)
{
	gpio_set_value(GPIO_W1_PULLUP_ENABLE, enable);
	msleep(100);
}

__attribute__((used)) static int raumfeld_mci_init(struct device *dev, irq_handler_t isr, void *data)
{
	gpio_set_value(GPIO_W2W_RESET, 1);
	gpio_set_value(GPIO_W2W_PDN, 1);

	return 0;
}

__attribute__((used)) static void raumfeld_mci_exit(struct device *dev, void *data)
{
	gpio_set_value(GPIO_W2W_RESET, 0);
	gpio_set_value(GPIO_W2W_PDN, 0);
}

__attribute__((used)) static int power_supply_init(struct device *dev)
{
	return 0;
}

__attribute__((used)) static void power_supply_exit(struct device *dev)
{
}

__attribute__((used)) static int raumfeld_is_ac_online(void)
{
	return !gpio_get_value(GPIO_CHARGE_DC_OK);
}

__attribute__((used)) static int raumfeld_is_usb_online(void)
{
	return 0;
}

__attribute__((used)) static void raumfeld_power_signal_charged(void)
{
	struct power_supply *psy =
		power_supply_get_by_name(raumfeld_power_supplicants[0]);

	if (psy) {
		power_supply_set_battery_charged(psy);
		power_supply_put(psy);
	}
}

__attribute__((used)) static int raumfeld_power_resume(void)
{
	/* check if GPIO_CHARGE_DONE went low while we were sleeping */
	if (!gpio_get_value(GPIO_CHARGE_DONE))
		raumfeld_power_signal_charged();

	return 0;
}

__attribute__((used)) static irqreturn_t charge_done_irq(int irq, void *dev_id)
{
	raumfeld_power_signal_charged();
	return IRQ_HANDLED;
}

