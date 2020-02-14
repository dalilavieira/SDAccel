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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct sunxi_pinctrl_desc {int* irq_bank_map; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int BANK_MEM_SIZE ; 
 int DATA_PINS_BITS ; 
 int DATA_PINS_PER_REG ; 
 scalar_t__ DATA_REGS_OFFSET ; 
 int DLEVEL_PINS_BITS ; 
 int DLEVEL_PINS_PER_REG ; 
 scalar_t__ DLEVEL_REGS_OFFSET ; 
 int IRQ_CFG_IRQ_BITS ; 
 int IRQ_CFG_IRQ_PER_REG ; 
 int IRQ_CFG_REG ; 
 int IRQ_CTRL_IRQ_BITS ; 
 int IRQ_CTRL_IRQ_PER_REG ; 
 int IRQ_CTRL_REG ; 
 int IRQ_DEBOUNCE_REG ; 
 int IRQ_MEM_SIZE ; 
 int IRQ_PER_BANK ; 
 int IRQ_STATUS_IRQ_BITS ; 
 int IRQ_STATUS_IRQ_PER_REG ; 
 int IRQ_STATUS_REG ; 
 int MUX_PINS_BITS ; 
 int MUX_PINS_PER_REG ; 
 scalar_t__ MUX_REGS_OFFSET ; 
 int PINS_PER_BANK ; 
 int PULL_PINS_BITS ; 
 int PULL_PINS_PER_REG ; 
 scalar_t__ PULL_REGS_OFFSET ; 
 scalar_t__ of_device_get_match_data (int /*<<< orphan*/ *) ; 
 int round_down (int,int) ; 
 int /*<<< orphan*/  sun6i_a31_pinctrl_data ; 
 int sunxi_pinctrl_init_with_variant (struct platform_device*,int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline u32 sunxi_mux_reg(u16 pin)
{
	u8 bank = pin / PINS_PER_BANK;
	u32 offset = bank * BANK_MEM_SIZE;
	offset += MUX_REGS_OFFSET;
	offset += pin % PINS_PER_BANK / MUX_PINS_PER_REG * 0x04;
	return round_down(offset, 4);
}

__attribute__((used)) static inline u32 sunxi_mux_offset(u16 pin)
{
	u32 pin_num = pin % MUX_PINS_PER_REG;
	return pin_num * MUX_PINS_BITS;
}

__attribute__((used)) static inline u32 sunxi_data_reg(u16 pin)
{
	u8 bank = pin / PINS_PER_BANK;
	u32 offset = bank * BANK_MEM_SIZE;
	offset += DATA_REGS_OFFSET;
	offset += pin % PINS_PER_BANK / DATA_PINS_PER_REG * 0x04;
	return round_down(offset, 4);
}

__attribute__((used)) static inline u32 sunxi_data_offset(u16 pin)
{
	u32 pin_num = pin % DATA_PINS_PER_REG;
	return pin_num * DATA_PINS_BITS;
}

__attribute__((used)) static inline u32 sunxi_dlevel_reg(u16 pin)
{
	u8 bank = pin / PINS_PER_BANK;
	u32 offset = bank * BANK_MEM_SIZE;
	offset += DLEVEL_REGS_OFFSET;
	offset += pin % PINS_PER_BANK / DLEVEL_PINS_PER_REG * 0x04;
	return round_down(offset, 4);
}

__attribute__((used)) static inline u32 sunxi_dlevel_offset(u16 pin)
{
	u32 pin_num = pin % DLEVEL_PINS_PER_REG;
	return pin_num * DLEVEL_PINS_BITS;
}

__attribute__((used)) static inline u32 sunxi_pull_reg(u16 pin)
{
	u8 bank = pin / PINS_PER_BANK;
	u32 offset = bank * BANK_MEM_SIZE;
	offset += PULL_REGS_OFFSET;
	offset += pin % PINS_PER_BANK / PULL_PINS_PER_REG * 0x04;
	return round_down(offset, 4);
}

__attribute__((used)) static inline u32 sunxi_pull_offset(u16 pin)
{
	u32 pin_num = pin % PULL_PINS_PER_REG;
	return pin_num * PULL_PINS_BITS;
}

__attribute__((used)) static inline u32 sunxi_irq_hw_bank_num(const struct sunxi_pinctrl_desc *desc, u8 bank)
{
	if (!desc->irq_bank_map)
		return bank;
	else
		return desc->irq_bank_map[bank];
}

__attribute__((used)) static inline u32 sunxi_irq_cfg_reg(const struct sunxi_pinctrl_desc *desc,
				    u16 irq)
{
	u8 bank = irq / IRQ_PER_BANK;
	u8 reg = (irq % IRQ_PER_BANK) / IRQ_CFG_IRQ_PER_REG * 0x04;

	return IRQ_CFG_REG +
	       sunxi_irq_hw_bank_num(desc, bank) * IRQ_MEM_SIZE + reg;
}

__attribute__((used)) static inline u32 sunxi_irq_cfg_offset(u16 irq)
{
	u32 irq_num = irq % IRQ_CFG_IRQ_PER_REG;
	return irq_num * IRQ_CFG_IRQ_BITS;
}

__attribute__((used)) static inline u32 sunxi_irq_ctrl_reg_from_bank(const struct sunxi_pinctrl_desc *desc, u8 bank)
{
	return IRQ_CTRL_REG + sunxi_irq_hw_bank_num(desc, bank) * IRQ_MEM_SIZE;
}

__attribute__((used)) static inline u32 sunxi_irq_ctrl_reg(const struct sunxi_pinctrl_desc *desc,
				     u16 irq)
{
	u8 bank = irq / IRQ_PER_BANK;

	return sunxi_irq_ctrl_reg_from_bank(desc, bank);
}

__attribute__((used)) static inline u32 sunxi_irq_ctrl_offset(u16 irq)
{
	u32 irq_num = irq % IRQ_CTRL_IRQ_PER_REG;
	return irq_num * IRQ_CTRL_IRQ_BITS;
}

__attribute__((used)) static inline u32 sunxi_irq_debounce_reg_from_bank(const struct sunxi_pinctrl_desc *desc, u8 bank)
{
	return IRQ_DEBOUNCE_REG +
	       sunxi_irq_hw_bank_num(desc, bank) * IRQ_MEM_SIZE;
}

__attribute__((used)) static inline u32 sunxi_irq_status_reg_from_bank(const struct sunxi_pinctrl_desc *desc, u8 bank)
{
	return IRQ_STATUS_REG +
	       sunxi_irq_hw_bank_num(desc, bank) * IRQ_MEM_SIZE;
}

__attribute__((used)) static inline u32 sunxi_irq_status_reg(const struct sunxi_pinctrl_desc *desc,
				       u16 irq)
{
	u8 bank = irq / IRQ_PER_BANK;

	return sunxi_irq_status_reg_from_bank(desc, bank);
}

__attribute__((used)) static inline u32 sunxi_irq_status_offset(u16 irq)
{
	u32 irq_num = irq % IRQ_STATUS_IRQ_PER_REG;
	return irq_num * IRQ_STATUS_IRQ_BITS;
}

__attribute__((used)) static int sun6i_a31_pinctrl_probe(struct platform_device *pdev)
{
	unsigned long variant =
		(unsigned long)of_device_get_match_data(&pdev->dev);

	return sunxi_pinctrl_init_with_variant(pdev,
					       &sun6i_a31_pinctrl_data,
					       variant);
}

