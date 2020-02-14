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
typedef  scalar_t__ u32 ;
struct irq_data {scalar_t__ irq; } ;

/* Variables and functions */
 unsigned int EMMA2RH_BHIF_INT_EN_0 ; 
 unsigned int EMMA2RH_BHIF_INT_EN_1 ; 
 unsigned int EMMA2RH_BHIF_INT_EN_2 ; 
 unsigned int EMMA2RH_BHIF_INT_ST_0 ; 
 unsigned int EMMA2RH_BHIF_INT_ST_1 ; 
 unsigned int EMMA2RH_BHIF_INT_ST_2 ; 
 unsigned int EMMA2RH_BHIF_SW_INT_EN ; 
 unsigned int EMMA2RH_GPIO_INT_MASK ; 
 unsigned int EMMA2RH_GPIO_INT_ST ; 
 unsigned int EMMA2RH_GPIO_IRQ_BASE ; 
 scalar_t__ EMMA2RH_IRQ_BASE ; 
 unsigned int EMMA2RH_SW_IRQ_BASE ; 
 scalar_t__ NUM_EMMA2RH_IRQ ; 
 scalar_t__ NUM_EMMA2RH_IRQ_GPIO ; 
 scalar_t__ NUM_EMMA2RH_IRQ_SW ; 
 int /*<<< orphan*/  do_IRQ (scalar_t__) ; 
 int /*<<< orphan*/  emma2rh_gpio_irq_controller ; 
 scalar_t__ emma2rh_in32 (unsigned int) ; 
 int /*<<< orphan*/  emma2rh_irq_controller ; 
 int /*<<< orphan*/  emma2rh_out32 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  emma2rh_sw_irq_controller ; 
 int /*<<< orphan*/  handle_edge_irq ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler_name (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void emma2rh_irq_enable(struct irq_data *d)
{
	unsigned int irq = d->irq - EMMA2RH_IRQ_BASE;
	u32 reg_value, reg_bitmask, reg_index;

	reg_index = EMMA2RH_BHIF_INT_EN_0 +
		    (EMMA2RH_BHIF_INT_EN_1 - EMMA2RH_BHIF_INT_EN_0) * (irq / 32);
	reg_value = emma2rh_in32(reg_index);
	reg_bitmask = 0x1 << (irq % 32);
	emma2rh_out32(reg_index, reg_value | reg_bitmask);
}

__attribute__((used)) static void emma2rh_irq_disable(struct irq_data *d)
{
	unsigned int irq = d->irq - EMMA2RH_IRQ_BASE;
	u32 reg_value, reg_bitmask, reg_index;

	reg_index = EMMA2RH_BHIF_INT_EN_0 +
		    (EMMA2RH_BHIF_INT_EN_1 - EMMA2RH_BHIF_INT_EN_0) * (irq / 32);
	reg_value = emma2rh_in32(reg_index);
	reg_bitmask = 0x1 << (irq % 32);
	emma2rh_out32(reg_index, reg_value & ~reg_bitmask);
}

void emma2rh_irq_init(void)
{
	u32 i;

	for (i = 0; i < NUM_EMMA2RH_IRQ; i++)
		irq_set_chip_and_handler_name(EMMA2RH_IRQ_BASE + i,
					      &emma2rh_irq_controller,
					      handle_level_irq, "level");
}

__attribute__((used)) static void emma2rh_sw_irq_enable(struct irq_data *d)
{
	unsigned int irq = d->irq - EMMA2RH_SW_IRQ_BASE;
	u32 reg;

	reg = emma2rh_in32(EMMA2RH_BHIF_SW_INT_EN);
	reg |= 1 << irq;
	emma2rh_out32(EMMA2RH_BHIF_SW_INT_EN, reg);
}

__attribute__((used)) static void emma2rh_sw_irq_disable(struct irq_data *d)
{
	unsigned int irq = d->irq - EMMA2RH_SW_IRQ_BASE;
	u32 reg;

	reg = emma2rh_in32(EMMA2RH_BHIF_SW_INT_EN);
	reg &= ~(1 << irq);
	emma2rh_out32(EMMA2RH_BHIF_SW_INT_EN, reg);
}

void emma2rh_sw_irq_init(void)
{
	u32 i;

	for (i = 0; i < NUM_EMMA2RH_IRQ_SW; i++)
		irq_set_chip_and_handler_name(EMMA2RH_SW_IRQ_BASE + i,
					      &emma2rh_sw_irq_controller,
					      handle_level_irq, "level");
}

__attribute__((used)) static void emma2rh_gpio_irq_enable(struct irq_data *d)
{
	unsigned int irq = d->irq - EMMA2RH_GPIO_IRQ_BASE;
	u32 reg;

	reg = emma2rh_in32(EMMA2RH_GPIO_INT_MASK);
	reg |= 1 << irq;
	emma2rh_out32(EMMA2RH_GPIO_INT_MASK, reg);
}

__attribute__((used)) static void emma2rh_gpio_irq_disable(struct irq_data *d)
{
	unsigned int irq = d->irq - EMMA2RH_GPIO_IRQ_BASE;
	u32 reg;

	reg = emma2rh_in32(EMMA2RH_GPIO_INT_MASK);
	reg &= ~(1 << irq);
	emma2rh_out32(EMMA2RH_GPIO_INT_MASK, reg);
}

__attribute__((used)) static void emma2rh_gpio_irq_ack(struct irq_data *d)
{
	unsigned int irq = d->irq - EMMA2RH_GPIO_IRQ_BASE;

	emma2rh_out32(EMMA2RH_GPIO_INT_ST, ~(1 << irq));
}

__attribute__((used)) static void emma2rh_gpio_irq_mask_ack(struct irq_data *d)
{
	unsigned int irq = d->irq - EMMA2RH_GPIO_IRQ_BASE;
	u32 reg;

	emma2rh_out32(EMMA2RH_GPIO_INT_ST, ~(1 << irq));

	reg = emma2rh_in32(EMMA2RH_GPIO_INT_MASK);
	reg &= ~(1 << irq);
	emma2rh_out32(EMMA2RH_GPIO_INT_MASK, reg);
}

void emma2rh_gpio_irq_init(void)
{
	u32 i;

	for (i = 0; i < NUM_EMMA2RH_IRQ_GPIO; i++)
		irq_set_chip_and_handler_name(EMMA2RH_GPIO_IRQ_BASE + i,
					      &emma2rh_gpio_irq_controller,
					      handle_edge_irq, "edge");
}

void emma2rh_irq_dispatch(void)
{
	u32 intStatus;
	u32 bitmask;
	u32 i;

	intStatus = emma2rh_in32(EMMA2RH_BHIF_INT_ST_0) &
		    emma2rh_in32(EMMA2RH_BHIF_INT_EN_0);

#ifdef EMMA2RH_SW_CASCADE
	if (intStatus & (1UL << EMMA2RH_SW_CASCADE)) {
		u32 swIntStatus;
		swIntStatus = emma2rh_in32(EMMA2RH_BHIF_SW_INT)
		    & emma2rh_in32(EMMA2RH_BHIF_SW_INT_EN);
		for (i = 0, bitmask = 1; i < 32; i++, bitmask <<= 1) {
			if (swIntStatus & bitmask) {
				do_IRQ(EMMA2RH_SW_IRQ_BASE + i);
				return;
			}
		}
	}
	/* Skip S/W interrupt */
	intStatus &= ~(1UL << EMMA2RH_SW_CASCADE);
#endif

	for (i = 0, bitmask = 1; i < 32; i++, bitmask <<= 1) {
		if (intStatus & bitmask) {
			do_IRQ(EMMA2RH_IRQ_BASE + i);
			return;
		}
	}

	intStatus = emma2rh_in32(EMMA2RH_BHIF_INT_ST_1) &
		    emma2rh_in32(EMMA2RH_BHIF_INT_EN_1);

#ifdef EMMA2RH_GPIO_CASCADE
	if (intStatus & (1UL << (EMMA2RH_GPIO_CASCADE % 32))) {
		u32 gpioIntStatus;
		gpioIntStatus = emma2rh_in32(EMMA2RH_GPIO_INT_ST)
		    & emma2rh_in32(EMMA2RH_GPIO_INT_MASK);
		for (i = 0, bitmask = 1; i < 32; i++, bitmask <<= 1) {
			if (gpioIntStatus & bitmask) {
				do_IRQ(EMMA2RH_GPIO_IRQ_BASE + i);
				return;
			}
		}
	}
	/* Skip GPIO interrupt */
	intStatus &= ~(1UL << (EMMA2RH_GPIO_CASCADE % 32));
#endif

	for (i = 32, bitmask = 1; i < 64; i++, bitmask <<= 1) {
		if (intStatus & bitmask) {
			do_IRQ(EMMA2RH_IRQ_BASE + i);
			return;
		}
	}

	intStatus = emma2rh_in32(EMMA2RH_BHIF_INT_ST_2) &
		    emma2rh_in32(EMMA2RH_BHIF_INT_EN_2);

	for (i = 64, bitmask = 1; i < 96; i++, bitmask <<= 1) {
		if (intStatus & bitmask) {
			do_IRQ(EMMA2RH_IRQ_BASE + i);
			return;
		}
	}
}

