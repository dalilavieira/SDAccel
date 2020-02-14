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
typedef  unsigned int u32 ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;

/* Variables and functions */
 unsigned int CNS3XXX_PWR_PLL_ALL ; 
 unsigned int CNS3XXX_PWR_SOFTWARE_RST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GLOBAL ; 
 int /*<<< orphan*/  PM_CLK_CTRL_REG ; 
 unsigned int PM_CLK_CTRL_REG_OFFSET_CPU_CLK_DIV ; 
 unsigned int PM_CLK_CTRL_REG_OFFSET_PLL_CPU_SEL ; 
 int /*<<< orphan*/  PM_CLK_GATE_REG ; 
 unsigned int PM_CLK_GATE_REG_MASK ; 
 int /*<<< orphan*/  PM_PLL_HM_PD_CTRL_REG ; 
 int /*<<< orphan*/  PM_SOFT_RST_REG ; 
 unsigned int PM_SOFT_RST_REG_MASK ; 
 unsigned int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline void cns3xxx_l2x0_init(void) {}

void cns3xxx_pwr_clk_en(unsigned int block)
{
	u32 reg = __raw_readl(PM_CLK_GATE_REG);

	reg |= (block & PM_CLK_GATE_REG_MASK);
	__raw_writel(reg, PM_CLK_GATE_REG);
}

void cns3xxx_pwr_clk_dis(unsigned int block)
{
	u32 reg = __raw_readl(PM_CLK_GATE_REG);

	reg &= ~(block & PM_CLK_GATE_REG_MASK);
	__raw_writel(reg, PM_CLK_GATE_REG);
}

void cns3xxx_pwr_power_up(unsigned int block)
{
	u32 reg = __raw_readl(PM_PLL_HM_PD_CTRL_REG);

	reg &= ~(block & CNS3XXX_PWR_PLL_ALL);
	__raw_writel(reg, PM_PLL_HM_PD_CTRL_REG);

	/* Wait for 300us for the PLL output clock locked. */
	udelay(300);
}

void cns3xxx_pwr_power_down(unsigned int block)
{
	u32 reg = __raw_readl(PM_PLL_HM_PD_CTRL_REG);

	/* write '1' to power down */
	reg |= (block & CNS3XXX_PWR_PLL_ALL);
	__raw_writel(reg, PM_PLL_HM_PD_CTRL_REG);
}

__attribute__((used)) static void cns3xxx_pwr_soft_rst_force(unsigned int block)
{
	u32 reg = __raw_readl(PM_SOFT_RST_REG);

	/*
	 * bit 0, 28, 29 => program low to reset,
	 * the other else program low and then high
	 */
	if (block & 0x30000001) {
		reg &= ~(block & PM_SOFT_RST_REG_MASK);
	} else {
		reg &= ~(block & PM_SOFT_RST_REG_MASK);
		__raw_writel(reg, PM_SOFT_RST_REG);
		reg |= (block & PM_SOFT_RST_REG_MASK);
	}

	__raw_writel(reg, PM_SOFT_RST_REG);
}

void cns3xxx_pwr_soft_rst(unsigned int block)
{
	static unsigned int soft_reset;

	if (soft_reset & block) {
		/* SPI/I2C/GPIO use the same block, reset once. */
		return;
	} else {
		soft_reset |= block;
	}
	cns3xxx_pwr_soft_rst_force(block);
}

void cns3xxx_restart(enum reboot_mode mode, const char *cmd)
{
	/*
	 * To reset, we hit the on-board reset register
	 * in the system FPGA.
	 */
	cns3xxx_pwr_soft_rst(CNS3XXX_PWR_SOFTWARE_RST(GLOBAL));
}

int cns3xxx_cpu_clock(void)
{
	u32 reg = __raw_readl(PM_CLK_CTRL_REG);
	int cpu;
	int cpu_sel;
	int div_sel;

	cpu_sel = (reg >> PM_CLK_CTRL_REG_OFFSET_PLL_CPU_SEL) & 0xf;
	div_sel = (reg >> PM_CLK_CTRL_REG_OFFSET_CPU_CLK_DIV) & 0x3;

	cpu = (300 + ((cpu_sel / 3) * 100) + ((cpu_sel % 3) * 33)) >> div_sel;

	return cpu;
}

