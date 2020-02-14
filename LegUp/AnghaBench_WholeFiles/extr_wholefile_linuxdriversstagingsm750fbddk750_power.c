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
typedef  enum dpms { ____Placeholder_dpms } dpms ;

/* Variables and functions */
 unsigned int CRT_DISPLAY_CTRL ; 
 unsigned int CRT_DISPLAY_CTRL_DPMS_MASK ; 
 int CRT_DISPLAY_CTRL_DPMS_SHIFT ; 
 unsigned int CURRENT_GATE ; 
 unsigned int CURRENT_GATE_CSC ; 
 unsigned int CURRENT_GATE_DE ; 
 unsigned int CURRENT_GATE_DMA ; 
 unsigned int CURRENT_GATE_GPIO ; 
 unsigned int CURRENT_GATE_I2C ; 
 unsigned int MODE0_GATE ; 
 unsigned int MODE1_GATE ; 
 unsigned int POWER_MODE_CTRL ; 
 unsigned int POWER_MODE_CTRL_MODE_MASK ; 
#define  POWER_MODE_CTRL_MODE_MODE0 130 
#define  POWER_MODE_CTRL_MODE_MODE1 129 
#define  POWER_MODE_CTRL_MODE_SLEEP 128 
 unsigned int POWER_MODE_CTRL_OSC_INPUT ; 
 scalar_t__ SM750LE ; 
 unsigned int SYSTEM_CTRL ; 
 unsigned int SYSTEM_CTRL_DPMS_MASK ; 
 unsigned int mmio750 ; 
 unsigned int readl (unsigned int) ; 
 scalar_t__ sm750_get_chip_type () ; 
 int /*<<< orphan*/  writel (unsigned int,unsigned int) ; 

__attribute__((used)) static inline u32 peek32(u32 addr)
{
	return readl(addr + mmio750);
}

__attribute__((used)) static inline void poke32(u32 addr, u32 data)
{
	writel(data, addr + mmio750);
}

void ddk750_set_dpms(enum dpms state)
{
	unsigned int value;

	if (sm750_get_chip_type() == SM750LE) {
		value = peek32(CRT_DISPLAY_CTRL) & ~CRT_DISPLAY_CTRL_DPMS_MASK;
		value |= (state << CRT_DISPLAY_CTRL_DPMS_SHIFT);
		poke32(CRT_DISPLAY_CTRL, value);
	} else {
		value = peek32(SYSTEM_CTRL);
		value = (value & ~SYSTEM_CTRL_DPMS_MASK) | state;
		poke32(SYSTEM_CTRL, value);
	}
}

__attribute__((used)) static unsigned int get_power_mode(void)
{
	if (sm750_get_chip_type() == SM750LE)
		return 0;
	return peek32(POWER_MODE_CTRL) & POWER_MODE_CTRL_MODE_MASK;
}

void sm750_set_power_mode(unsigned int mode)
{
	unsigned int ctrl = 0;

	ctrl = peek32(POWER_MODE_CTRL) & ~POWER_MODE_CTRL_MODE_MASK;

	if (sm750_get_chip_type() == SM750LE)
		return;

	switch (mode) {
	case POWER_MODE_CTRL_MODE_MODE0:
		ctrl |= POWER_MODE_CTRL_MODE_MODE0;
		break;

	case POWER_MODE_CTRL_MODE_MODE1:
		ctrl |= POWER_MODE_CTRL_MODE_MODE1;
		break;

	case POWER_MODE_CTRL_MODE_SLEEP:
		ctrl |= POWER_MODE_CTRL_MODE_SLEEP;
		break;

	default:
		break;
	}

	/* Set up other fields in Power Control Register */
	if (mode == POWER_MODE_CTRL_MODE_SLEEP) {
		ctrl &= ~POWER_MODE_CTRL_OSC_INPUT;
#ifdef VALIDATION_CHIP
		ctrl &= ~POWER_MODE_CTRL_336CLK;
#endif
	} else {
		ctrl |= POWER_MODE_CTRL_OSC_INPUT;
#ifdef VALIDATION_CHIP
		ctrl |= POWER_MODE_CTRL_336CLK;
#endif
	}

	/* Program new power mode. */
	poke32(POWER_MODE_CTRL, ctrl);
}

void sm750_set_current_gate(unsigned int gate)
{
	if (get_power_mode() == POWER_MODE_CTRL_MODE_MODE1)
		poke32(MODE1_GATE, gate);
	else
		poke32(MODE0_GATE, gate);
}

void sm750_enable_2d_engine(unsigned int enable)
{
	u32 gate;

	gate = peek32(CURRENT_GATE);
	if (enable)
		gate |= (CURRENT_GATE_DE | CURRENT_GATE_CSC);
	else
		gate &= ~(CURRENT_GATE_DE | CURRENT_GATE_CSC);

	sm750_set_current_gate(gate);
}

void sm750_enable_dma(unsigned int enable)
{
	u32 gate;

	/* Enable DMA Gate */
	gate = peek32(CURRENT_GATE);
	if (enable)
		gate |= CURRENT_GATE_DMA;
	else
		gate &= ~CURRENT_GATE_DMA;

	sm750_set_current_gate(gate);
}

void sm750_enable_gpio(unsigned int enable)
{
	u32 gate;

	/* Enable GPIO Gate */
	gate = peek32(CURRENT_GATE);
	if (enable)
		gate |= CURRENT_GATE_GPIO;
	else
		gate &= ~CURRENT_GATE_GPIO;

	sm750_set_current_gate(gate);
}

void sm750_enable_i2c(unsigned int enable)
{
	u32 gate;

	/* Enable I2C Gate */
	gate = peek32(CURRENT_GATE);
	if (enable)
		gate |= CURRENT_GATE_I2C;
	else
		gate &= ~CURRENT_GATE_I2C;

	sm750_set_current_gate(gate);
}

