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
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct mfd_cell {size_t id; } ;
struct irq_desc {int dummy; } ;
struct irq_data {int irq; TYPE_1__* chip; } ;
struct asic3 {unsigned int bus_shift; unsigned int irq_base; int* irq_bothedge; int /*<<< orphan*/ * clocks; int /*<<< orphan*/  gpio; int /*<<< orphan*/  tmio_cnf; int /*<<< orphan*/  lock; int /*<<< orphan*/  dev; scalar_t__ mapping; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* irq_ack ) (struct irq_data*) ;} ;

/* Variables and functions */
 size_t ASIC3_CLOCK_EX0 ; 
 size_t ASIC3_CLOCK_EX1 ; 
 size_t ASIC3_CLOCK_OWM ; 
 size_t ASIC3_CLOCK_SD_BUS ; 
 size_t ASIC3_CLOCK_SD_HOST ; 
 int ASIC3_EXTCF_OWM_EN ; 
 int ASIC3_EXTCF_OWM_RESET ; 
 int ASIC3_EXTCF_SD_MEM_ENABLE ; 
 int ASIC3_GPIO (int /*<<< orphan*/ ,size_t) ; 
 int ASIC3_GPIOS_PER_BANK ; 
 int ASIC3_GPIO_A_BASE ; 
 int ASIC3_GPIO_BASE_INCR ; 
 int ASIC3_GPIO_B_BASE ; 
 int ASIC3_GPIO_EDGE_TRIGGER ; 
 unsigned long ASIC3_GPIO_INT_STATUS ; 
 int ASIC3_GPIO_LEVEL_TRIGGER ; 
 int ASIC3_GPIO_MASK ; 
 int ASIC3_GPIO_SLEEP_MASK ; 
 int ASIC3_GPIO_TRIGGER_TYPE ; 
 int ASIC3_INTMASK_MASK0 ; 
 unsigned int ASIC3_INTR_BASE ; 
 unsigned int ASIC3_INTR_INT_MASK ; 
 int ASIC3_NR_IRQS ; 
 int ASIC3_NUM_GPIOS ; 
 int ASIC3_NUM_GPIO_BANKS ; 
 void* ASIC3_OFFSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ASIC3_SDHWCTRL_LEVCD ; 
 int ASIC3_SDHWCTRL_LEVWP ; 
 int ASIC3_SDHWCTRL_PCLR ; 
 int ASIC3_SDHWCTRL_SDPWR ; 
 int ASIC3_SDHWCTRL_SUSPEND ; 
 int ASIC3_SD_CTRL_BASE ; 
 int /*<<< orphan*/  C ; 
 int /*<<< orphan*/  CLOCK ; 
 int CLOCK_SEL_CX ; 
 int CLOCK_SEL_SD_HCLK_SEL ; 
 int /*<<< orphan*/  EXTCF ; 
 int /*<<< orphan*/  INTR ; 
 unsigned int IRQ_TYPE_EDGE_BOTH ; 
 unsigned int IRQ_TYPE_EDGE_FALLING ; 
 unsigned int IRQ_TYPE_EDGE_RISING ; 
 unsigned int IRQ_TYPE_LEVEL_HIGH ; 
 unsigned int IRQ_TYPE_LEVEL_LOW ; 
 int MAX_ASIC_ISR_LOOPS ; 
 int /*<<< orphan*/  P_INT_STAT ; 
 int /*<<< orphan*/  RESET ; 
 int /*<<< orphan*/  SDCONF ; 
 int /*<<< orphan*/  SDHWCTRL ; 
 int /*<<< orphan*/  SEL ; 
 int /*<<< orphan*/  SELECT ; 
 int /*<<< orphan*/  asic3_clk_disable (struct asic3*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  asic3_clk_enable (struct asic3*,int /*<<< orphan*/ *) ; 
 scalar_t__ asic3_gpio_get (int /*<<< orphan*/ *,int) ; 
 size_t* clock_ledn ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 struct asic3* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 int ioread16 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite16 (int,scalar_t__) ; 
 struct asic3* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct asic3* irq_desc_get_handler_data (struct irq_desc*) ; 
 struct irq_data* irq_desc_get_irq_data (struct irq_desc*) ; 
 struct mfd_cell* mfd_get_cell (struct platform_device*) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct irq_data*) ; 
 int /*<<< orphan*/  tmio_core_mmc_clk_div (int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  tmio_core_mmc_enable (int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  tmio_core_mmc_pwr (int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

void asic3_write_register(struct asic3 *asic, unsigned int reg, u32 value)
{
	iowrite16(value, asic->mapping +
		  (reg >> asic->bus_shift));
}

u32 asic3_read_register(struct asic3 *asic, unsigned int reg)
{
	return ioread16(asic->mapping +
			(reg >> asic->bus_shift));
}

__attribute__((used)) static void asic3_set_register(struct asic3 *asic, u32 reg, u32 bits, bool set)
{
	unsigned long flags;
	u32 val;

	raw_spin_lock_irqsave(&asic->lock, flags);
	val = asic3_read_register(asic, reg);
	if (set)
		val |= bits;
	else
		val &= ~bits;
	asic3_write_register(asic, reg, val);
	raw_spin_unlock_irqrestore(&asic->lock, flags);
}

__attribute__((used)) static void asic3_irq_flip_edge(struct asic3 *asic,
				u32 base, int bit)
{
	u16 edge;
	unsigned long flags;

	raw_spin_lock_irqsave(&asic->lock, flags);
	edge = asic3_read_register(asic,
				   base + ASIC3_GPIO_EDGE_TRIGGER);
	edge ^= bit;
	asic3_write_register(asic,
			     base + ASIC3_GPIO_EDGE_TRIGGER, edge);
	raw_spin_unlock_irqrestore(&asic->lock, flags);
}

__attribute__((used)) static void asic3_irq_demux(struct irq_desc *desc)
{
	struct asic3 *asic = irq_desc_get_handler_data(desc);
	struct irq_data *data = irq_desc_get_irq_data(desc);
	int iter, i;
	unsigned long flags;

	data->chip->irq_ack(data);

	for (iter = 0 ; iter < MAX_ASIC_ISR_LOOPS; iter++) {
		u32 status;
		int bank;

		raw_spin_lock_irqsave(&asic->lock, flags);
		status = asic3_read_register(asic,
					     ASIC3_OFFSET(INTR, P_INT_STAT));
		raw_spin_unlock_irqrestore(&asic->lock, flags);

		/* Check all ten register bits */
		if ((status & 0x3ff) == 0)
			break;

		/* Handle GPIO IRQs */
		for (bank = 0; bank < ASIC3_NUM_GPIO_BANKS; bank++) {
			if (status & (1 << bank)) {
				unsigned long base, istat;

				base = ASIC3_GPIO_A_BASE
				       + bank * ASIC3_GPIO_BASE_INCR;
				raw_spin_lock_irqsave(&asic->lock, flags);
				istat = asic3_read_register(asic,
							    base +
							    ASIC3_GPIO_INT_STATUS);
				/* Clearing IntStatus */
				asic3_write_register(asic,
						     base +
						     ASIC3_GPIO_INT_STATUS, 0);
				raw_spin_unlock_irqrestore(&asic->lock, flags);

				for (i = 0; i < ASIC3_GPIOS_PER_BANK; i++) {
					int bit = (1 << i);
					unsigned int irqnr;

					if (!(istat & bit))
						continue;

					irqnr = asic->irq_base +
						(ASIC3_GPIOS_PER_BANK * bank)
						+ i;
					generic_handle_irq(irqnr);
					if (asic->irq_bothedge[bank] & bit)
						asic3_irq_flip_edge(asic, base,
								    bit);
				}
			}
		}

		/* Handle remaining IRQs in the status register */
		for (i = ASIC3_NUM_GPIOS; i < ASIC3_NR_IRQS; i++) {
			/* They start at bit 4 and go up */
			if (status & (1 << (i - ASIC3_NUM_GPIOS + 4)))
				generic_handle_irq(asic->irq_base + i);
		}
	}

	if (iter >= MAX_ASIC_ISR_LOOPS)
		dev_err(asic->dev, "interrupt processing overrun\n");
}

__attribute__((used)) static inline int asic3_irq_to_bank(struct asic3 *asic, int irq)
{
	int n;

	n = (irq - asic->irq_base) >> 4;

	return (n * (ASIC3_GPIO_B_BASE - ASIC3_GPIO_A_BASE));
}

__attribute__((used)) static inline int asic3_irq_to_index(struct asic3 *asic, int irq)
{
	return (irq - asic->irq_base) & 0xf;
}

__attribute__((used)) static void asic3_mask_gpio_irq(struct irq_data *data)
{
	struct asic3 *asic = irq_data_get_irq_chip_data(data);
	u32 val, bank, index;
	unsigned long flags;

	bank = asic3_irq_to_bank(asic, data->irq);
	index = asic3_irq_to_index(asic, data->irq);

	raw_spin_lock_irqsave(&asic->lock, flags);
	val = asic3_read_register(asic, bank + ASIC3_GPIO_MASK);
	val |= 1 << index;
	asic3_write_register(asic, bank + ASIC3_GPIO_MASK, val);
	raw_spin_unlock_irqrestore(&asic->lock, flags);
}

__attribute__((used)) static void asic3_mask_irq(struct irq_data *data)
{
	struct asic3 *asic = irq_data_get_irq_chip_data(data);
	int regval;
	unsigned long flags;

	raw_spin_lock_irqsave(&asic->lock, flags);
	regval = asic3_read_register(asic,
				     ASIC3_INTR_BASE +
				     ASIC3_INTR_INT_MASK);

	regval &= ~(ASIC3_INTMASK_MASK0 <<
		    (data->irq - (asic->irq_base + ASIC3_NUM_GPIOS)));

	asic3_write_register(asic,
			     ASIC3_INTR_BASE +
			     ASIC3_INTR_INT_MASK,
			     regval);
	raw_spin_unlock_irqrestore(&asic->lock, flags);
}

__attribute__((used)) static void asic3_unmask_gpio_irq(struct irq_data *data)
{
	struct asic3 *asic = irq_data_get_irq_chip_data(data);
	u32 val, bank, index;
	unsigned long flags;

	bank = asic3_irq_to_bank(asic, data->irq);
	index = asic3_irq_to_index(asic, data->irq);

	raw_spin_lock_irqsave(&asic->lock, flags);
	val = asic3_read_register(asic, bank + ASIC3_GPIO_MASK);
	val &= ~(1 << index);
	asic3_write_register(asic, bank + ASIC3_GPIO_MASK, val);
	raw_spin_unlock_irqrestore(&asic->lock, flags);
}

__attribute__((used)) static void asic3_unmask_irq(struct irq_data *data)
{
	struct asic3 *asic = irq_data_get_irq_chip_data(data);
	int regval;
	unsigned long flags;

	raw_spin_lock_irqsave(&asic->lock, flags);
	regval = asic3_read_register(asic,
				     ASIC3_INTR_BASE +
				     ASIC3_INTR_INT_MASK);

	regval |= (ASIC3_INTMASK_MASK0 <<
		   (data->irq - (asic->irq_base + ASIC3_NUM_GPIOS)));

	asic3_write_register(asic,
			     ASIC3_INTR_BASE +
			     ASIC3_INTR_INT_MASK,
			     regval);
	raw_spin_unlock_irqrestore(&asic->lock, flags);
}

__attribute__((used)) static int asic3_gpio_irq_type(struct irq_data *data, unsigned int type)
{
	struct asic3 *asic = irq_data_get_irq_chip_data(data);
	u32 bank, index;
	u16 trigger, level, edge, bit;
	unsigned long flags;

	bank = asic3_irq_to_bank(asic, data->irq);
	index = asic3_irq_to_index(asic, data->irq);
	bit = 1<<index;

	raw_spin_lock_irqsave(&asic->lock, flags);
	level = asic3_read_register(asic,
				    bank + ASIC3_GPIO_LEVEL_TRIGGER);
	edge = asic3_read_register(asic,
				   bank + ASIC3_GPIO_EDGE_TRIGGER);
	trigger = asic3_read_register(asic,
				      bank + ASIC3_GPIO_TRIGGER_TYPE);
	asic->irq_bothedge[(data->irq - asic->irq_base) >> 4] &= ~bit;

	if (type == IRQ_TYPE_EDGE_RISING) {
		trigger |= bit;
		edge |= bit;
	} else if (type == IRQ_TYPE_EDGE_FALLING) {
		trigger |= bit;
		edge &= ~bit;
	} else if (type == IRQ_TYPE_EDGE_BOTH) {
		trigger |= bit;
		if (asic3_gpio_get(&asic->gpio, data->irq - asic->irq_base))
			edge &= ~bit;
		else
			edge |= bit;
		asic->irq_bothedge[(data->irq - asic->irq_base) >> 4] |= bit;
	} else if (type == IRQ_TYPE_LEVEL_LOW) {
		trigger &= ~bit;
		level &= ~bit;
	} else if (type == IRQ_TYPE_LEVEL_HIGH) {
		trigger &= ~bit;
		level |= bit;
	} else {
		/*
		 * if type == IRQ_TYPE_NONE, we should mask interrupts, but
		 * be careful to not unmask them if mask was also called.
		 * Probably need internal state for mask.
		 */
		dev_notice(asic->dev, "irq type not changed\n");
	}
	asic3_write_register(asic, bank + ASIC3_GPIO_LEVEL_TRIGGER,
			     level);
	asic3_write_register(asic, bank + ASIC3_GPIO_EDGE_TRIGGER,
			     edge);
	asic3_write_register(asic, bank + ASIC3_GPIO_TRIGGER_TYPE,
			     trigger);
	raw_spin_unlock_irqrestore(&asic->lock, flags);
	return 0;
}

__attribute__((used)) static int asic3_gpio_irq_set_wake(struct irq_data *data, unsigned int on)
{
	struct asic3 *asic = irq_data_get_irq_chip_data(data);
	u32 bank, index;
	u16 bit;

	bank = asic3_irq_to_bank(asic, data->irq);
	index = asic3_irq_to_index(asic, data->irq);
	bit = 1<<index;

	asic3_set_register(asic, bank + ASIC3_GPIO_SLEEP_MASK, bit, !on);

	return 0;
}

__attribute__((used)) static int ds1wm_enable(struct platform_device *pdev)
{
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	/* Turn on external clocks and the OWM clock */
	asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_EX0]);
	asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_EX1]);
	asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_OWM]);
	usleep_range(1000, 5000);

	/* Reset and enable DS1WM */
	asic3_set_register(asic, ASIC3_OFFSET(EXTCF, RESET),
			   ASIC3_EXTCF_OWM_RESET, 1);
	usleep_range(1000, 5000);
	asic3_set_register(asic, ASIC3_OFFSET(EXTCF, RESET),
			   ASIC3_EXTCF_OWM_RESET, 0);
	usleep_range(1000, 5000);
	asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
			   ASIC3_EXTCF_OWM_EN, 1);
	usleep_range(1000, 5000);

	return 0;
}

__attribute__((used)) static int ds1wm_disable(struct platform_device *pdev)
{
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
			   ASIC3_EXTCF_OWM_EN, 0);

	asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_OWM]);
	asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_EX0]);
	asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_EX1]);

	return 0;
}

__attribute__((used)) static void asic3_mmc_pwr(struct platform_device *pdev, int state)
{
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	tmio_core_mmc_pwr(asic->tmio_cnf, 1 - asic->bus_shift, state);
}

__attribute__((used)) static void asic3_mmc_clk_div(struct platform_device *pdev, int state)
{
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	tmio_core_mmc_clk_div(asic->tmio_cnf, 1 - asic->bus_shift, state);
}

__attribute__((used)) static int asic3_mmc_enable(struct platform_device *pdev)
{
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	/* Not sure if it must be done bit by bit, but leaving as-is */
	asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
			   ASIC3_SDHWCTRL_LEVCD, 1);
	asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
			   ASIC3_SDHWCTRL_LEVWP, 1);
	asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
			   ASIC3_SDHWCTRL_SUSPEND, 0);
	asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
			   ASIC3_SDHWCTRL_PCLR, 0);

	asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_EX0]);
	/* CLK32 used for card detection and for interruption detection
	 * when HCLK is stopped.
	 */
	asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_EX1]);
	usleep_range(1000, 5000);

	/* HCLK 24.576 MHz, BCLK 12.288 MHz: */
	asic3_write_register(asic, ASIC3_OFFSET(CLOCK, SEL),
		CLOCK_SEL_CX | CLOCK_SEL_SD_HCLK_SEL);

	asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_SD_HOST]);
	asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_SD_BUS]);
	usleep_range(1000, 5000);

	asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
			   ASIC3_EXTCF_SD_MEM_ENABLE, 1);

	/* Enable SD card slot 3.3V power supply */
	asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
			   ASIC3_SDHWCTRL_SDPWR, 1);

	/* ASIC3_SD_CTRL_BASE assumes 32-bit addressing, TMIO is 16-bit */
	tmio_core_mmc_enable(asic->tmio_cnf, 1 - asic->bus_shift,
			     ASIC3_SD_CTRL_BASE >> 1);

	return 0;
}

__attribute__((used)) static int asic3_mmc_disable(struct platform_device *pdev)
{
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	/* Put in suspend mode */
	asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
			   ASIC3_SDHWCTRL_SUSPEND, 1);

	/* Disable clocks */
	asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_SD_HOST]);
	asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_SD_BUS]);
	asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_EX0]);
	asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_EX1]);
	return 0;
}

__attribute__((used)) static int asic3_leds_enable(struct platform_device *pdev)
{
	const struct mfd_cell *cell = mfd_get_cell(pdev);
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	asic3_clk_enable(asic, &asic->clocks[clock_ledn[cell->id]]);

	return 0;
}

__attribute__((used)) static int asic3_leds_disable(struct platform_device *pdev)
{
	const struct mfd_cell *cell = mfd_get_cell(pdev);
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	asic3_clk_disable(asic, &asic->clocks[clock_ledn[cell->id]]);

	return 0;
}

__attribute__((used)) static int asic3_leds_suspend(struct platform_device *pdev)
{
	const struct mfd_cell *cell = mfd_get_cell(pdev);
	struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);

	while (asic3_gpio_get(&asic->gpio, ASIC3_GPIO(C, cell->id)) != 0)
		usleep_range(1000, 5000);

	asic3_clk_disable(asic, &asic->clocks[clock_ledn[cell->id]]);

	return 0;
}

