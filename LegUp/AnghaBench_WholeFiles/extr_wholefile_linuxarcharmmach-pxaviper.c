#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_4__ {TYPE_1__* chip; } ;
struct irq_desc {TYPE_2__ irq_data; } ;
struct irq_data {unsigned int irq; } ;
struct device {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* irq_ack ) (TYPE_2__*) ;} ;

/* Variables and functions */
 unsigned int PXA_ISA_IRQ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VIPER_BCKLIGHT_EN_GPIO ; 
 int VIPER_HI_IRQ_STATUS ; 
 unsigned int VIPER_ICR ; 
 unsigned int VIPER_ICR_CF_RST ; 
 unsigned int VIPER_ICR_R_DIS ; 
 int /*<<< orphan*/  VIPER_LCD_EN_GPIO ; 
 int VIPER_LO_IRQ_STATUS ; 
 int /*<<< orphan*/  VIPER_PSU_CLK_GPIO ; 
 int /*<<< orphan*/  VIPER_PSU_DATA_GPIO ; 
 int /*<<< orphan*/  VIPER_PSU_nCS_LD_GPIO ; 
 int VIPER_VERSION ; 
 int __ffs (unsigned long) ; 
 unsigned int current_voltage_divisor ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 int gpio_direction_output (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 unsigned int icr ; 
 scalar_t__ likely (unsigned long) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  ndelay (int) ; 
 int /*<<< orphan*/  pr_debug (char*,char const*,int,int) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int viper_irq_enabled_mask ; 
 int* viper_isa_irq_map ; 
 int* viper_isa_irqs ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static void viper_icr_set_bit(unsigned int bit)
{
	icr |= bit;
	VIPER_ICR = icr;
}

__attribute__((used)) static void viper_icr_clear_bit(unsigned int bit)
{
	icr &= ~bit;
	VIPER_ICR = icr;
}

__attribute__((used)) static void viper_cf_reset(int state)
{
	if (state)
		viper_icr_set_bit(VIPER_ICR_CF_RST);
	else
		viper_icr_clear_bit(VIPER_ICR_CF_RST);
}

__attribute__((used)) static u8 viper_hw_version(void)
{
	u8 v1, v2;
	unsigned long flags;

	local_irq_save(flags);

	VIPER_VERSION = 0;
	v1 = VIPER_VERSION;
	VIPER_VERSION = 0xff;
	v2 = VIPER_VERSION;

	v1 = (v1 != v2 || v1 == 0xff) ? 0 : v1;

	local_irq_restore(flags);
	return v1;
}

__attribute__((used)) static int viper_cpu_suspend(void)
{
	viper_icr_set_bit(VIPER_ICR_R_DIS);
	return 0;
}

__attribute__((used)) static void viper_cpu_resume(void)
{
	viper_icr_clear_bit(VIPER_ICR_R_DIS);
}

__attribute__((used)) static void viper_set_core_cpu_voltage(unsigned long khz, int force)
{
	int i = 0;
	unsigned int divisor = 0;
	const char *v;

	if (khz < 200000) {
		v = "1.0"; divisor = 0xfff;
	} else if (khz < 300000) {
		v = "1.1"; divisor = 0xde5;
	} else {
		v = "1.3"; divisor = 0x325;
	}

	pr_debug("viper: setting CPU core voltage to %sV at %d.%03dMHz\n",
		 v, (int)khz / 1000, (int)khz % 1000);

#define STEP 0x100
	do {
		int step;

		if (force)
			step = divisor;
		else if (current_voltage_divisor < divisor - STEP)
			step = current_voltage_divisor + STEP;
		else if (current_voltage_divisor > divisor + STEP)
			step = current_voltage_divisor - STEP;
		else
			step = divisor;
		force = 0;

		gpio_set_value(VIPER_PSU_CLK_GPIO, 0);
		gpio_set_value(VIPER_PSU_nCS_LD_GPIO, 0);

		for (i = 1 << 11 ; i > 0 ; i >>= 1) {
			udelay(1);

			gpio_set_value(VIPER_PSU_DATA_GPIO, step & i);
			udelay(1);

			gpio_set_value(VIPER_PSU_CLK_GPIO, 1);
			udelay(1);

			gpio_set_value(VIPER_PSU_CLK_GPIO, 0);
		}
		udelay(1);

		gpio_set_value(VIPER_PSU_nCS_LD_GPIO, 1);
		udelay(1);

		gpio_set_value(VIPER_PSU_nCS_LD_GPIO, 0);

		current_voltage_divisor = step;
	} while (current_voltage_divisor != divisor);
}

__attribute__((used)) static inline int viper_irq_to_bitmask(unsigned int irq)
{
	return viper_isa_irq_map[irq - PXA_ISA_IRQ(0)];
}

__attribute__((used)) static inline int viper_bit_to_irq(int bit)
{
	return viper_isa_irqs[bit] + PXA_ISA_IRQ(0);
}

__attribute__((used)) static void viper_ack_irq(struct irq_data *d)
{
	int viper_irq = viper_irq_to_bitmask(d->irq);

	if (viper_irq & 0xff)
		VIPER_LO_IRQ_STATUS = viper_irq;
	else
		VIPER_HI_IRQ_STATUS = (viper_irq >> 8);
}

__attribute__((used)) static void viper_mask_irq(struct irq_data *d)
{
	viper_irq_enabled_mask &= ~(viper_irq_to_bitmask(d->irq));
}

__attribute__((used)) static void viper_unmask_irq(struct irq_data *d)
{
	viper_irq_enabled_mask |= viper_irq_to_bitmask(d->irq);
}

__attribute__((used)) static inline unsigned long viper_irq_pending(void)
{
	return (VIPER_HI_IRQ_STATUS << 8 | VIPER_LO_IRQ_STATUS) &
			viper_irq_enabled_mask;
}

__attribute__((used)) static void viper_irq_handler(struct irq_desc *desc)
{
	unsigned int irq;
	unsigned long pending;

	pending = viper_irq_pending();
	do {
		/* we're in a chained irq handler,
		 * so ack the interrupt by hand */
		desc->irq_data.chip->irq_ack(&desc->irq_data);

		if (likely(pending)) {
			irq = viper_bit_to_irq(__ffs(pending));
			generic_handle_irq(irq);
		}
		pending = viper_irq_pending();
	} while (pending);
}

__attribute__((used)) static int viper_backlight_init(struct device *dev)
{
	int ret;

	/* GPIO9 and 10 control FB backlight. Initialise to off */
	ret = gpio_request(VIPER_BCKLIGHT_EN_GPIO, "Backlight");
	if (ret)
		goto err_request_bckl;

	ret = gpio_request(VIPER_LCD_EN_GPIO, "LCD");
	if (ret)
		goto err_request_lcd;

	ret = gpio_direction_output(VIPER_BCKLIGHT_EN_GPIO, 0);
	if (ret)
		goto err_dir;

	ret = gpio_direction_output(VIPER_LCD_EN_GPIO, 0);
	if (ret)
		goto err_dir;

	return 0;

err_dir:
	gpio_free(VIPER_LCD_EN_GPIO);
err_request_lcd:
	gpio_free(VIPER_BCKLIGHT_EN_GPIO);
err_request_bckl:
	dev_err(dev, "Failed to setup LCD GPIOs\n");

	return ret;
}

__attribute__((used)) static int viper_backlight_notify(struct device *dev, int brightness)
{
	gpio_set_value(VIPER_LCD_EN_GPIO, !!brightness);
	gpio_set_value(VIPER_BCKLIGHT_EN_GPIO, !!brightness);

	return brightness;
}

__attribute__((used)) static void viper_backlight_exit(struct device *dev)
{
	gpio_free(VIPER_LCD_EN_GPIO);
	gpio_free(VIPER_BCKLIGHT_EN_GPIO);
}

__attribute__((used)) static void isp116x_delay(struct device *dev, int delay)
{
	ndelay(delay);
}

