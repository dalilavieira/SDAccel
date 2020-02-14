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
typedef  int /*<<< orphan*/  u32 ;
struct irq_data {int irq; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* irq_mask ) (struct irq_data*) ;} ;
struct irq_chip_type {TYPE_1__ chip; } ;
struct i2c_board_info {int dummy; } ;
struct TYPE_4__ {scalar_t__ va; } ;

/* Variables and functions */
 int IRQ_BANK (int) ; 
 int IRQ_BIT (int) ; 
 scalar_t__ IRQ_CONTROL_REG_OFFSET ; 
 int IRQ_ILR0_REG_OFFSET ; 
 TYPE_2__* irq_banks ; 
 struct irq_chip_type* irq_data_get_chip_type (struct irq_data*) ; 
 unsigned int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  stub1 (struct irq_data*) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static inline int omap_register_i2c_bus(int bus_id, u32 clkrate,
				 struct i2c_board_info const *info,
				 unsigned len)
{
	return 0;
}

__attribute__((used)) static inline int omap_register_i2c_bus_cmdline(void)
{
	return 0;
}

__attribute__((used)) static inline void omap7xx_map_io(void)
{
}

__attribute__((used)) static inline void omap1510_fpga_init_irq(void)
{
}

__attribute__((used)) static inline void omap15xx_map_io(void)
{
}

__attribute__((used)) static inline void omap16xx_map_io(void)
{
}

__attribute__((used)) static inline int omap_serial_wakeup_init(void)
{
	return 0;
}

__attribute__((used)) static inline unsigned int irq_bank_readl(int bank, int offset)
{
	return readl_relaxed(irq_banks[bank].va + offset);
}

__attribute__((used)) static inline void irq_bank_writel(unsigned long value, int bank, int offset)
{
	writel_relaxed(value, irq_banks[bank].va + offset);
}

__attribute__((used)) static void omap_ack_irq(int irq)
{
	if (irq > 31)
		writel_relaxed(0x1, irq_banks[1].va + IRQ_CONTROL_REG_OFFSET);

	writel_relaxed(0x1, irq_banks[0].va + IRQ_CONTROL_REG_OFFSET);
}

__attribute__((used)) static void omap_mask_ack_irq(struct irq_data *d)
{
	struct irq_chip_type *ct = irq_data_get_chip_type(d);

	ct->chip.irq_mask(d);
	omap_ack_irq(d->irq);
}

__attribute__((used)) static void omap_irq_set_cfg(int irq, int fiq, int priority, int trigger)
{
	signed int bank;
	unsigned long val, offset;

	bank = IRQ_BANK(irq);
	/* FIQ is only available on bank 0 interrupts */
	fiq = bank ? 0 : (fiq & 0x1);
	val = fiq | ((priority & 0x1f) << 2) | ((trigger & 0x1) << 1);
	offset = IRQ_ILR0_REG_OFFSET + IRQ_BIT(irq) * 0x4;
	irq_bank_writel(val, bank, offset);
}

