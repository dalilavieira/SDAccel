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
typedef  int u32 ;
struct notifier_block {int dummy; } ;

/* Variables and functions */
 int SLCR_A9_CPU_CLKSTOP ; 
 int SLCR_A9_CPU_RST ; 
 int SLCR_A9_CPU_RST_CTRL_OFFSET ; 
 int SLCR_PSS_IDCODE ; 
 int SLCR_PSS_IDCODE_DEVICE_MASK ; 
 int SLCR_PSS_IDCODE_DEVICE_SHIFT ; 
 int SLCR_PS_RST_CTRL_OFFSET ; 
 int SLCR_REBOOT_STATUS_OFFSET ; 
 int SLCR_UNLOCK_MAGIC ; 
 int SLCR_UNLOCK_OFFSET ; 
 int readl (int) ; 
 int regmap_read (int /*<<< orphan*/ ,int,int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  writel (int,int) ; 
 int zynq_slcr_base ; 
 void zynq_slcr_cpu_state_write (int,int) ; 
 int /*<<< orphan*/  zynq_slcr_regmap ; 

__attribute__((used)) static inline void zynq_core_pm_init(void)
{
	/* A9 clock gating */
	asm volatile ("mrc  p15, 0, r12, c15, c0, 0\n"
		      "orr  r12, r12, #1\n"
		      "mcr  p15, 0, r12, c15, c0, 0\n"
		      : /* no outputs */
		      : /* no inputs */
		      : "r12");
}

__attribute__((used)) static int zynq_slcr_write(u32 val, u32 offset)
{
	return regmap_write(zynq_slcr_regmap, offset, val);
}

__attribute__((used)) static int zynq_slcr_read(u32 *val, u32 offset)
{
	return regmap_read(zynq_slcr_regmap, offset, val);
}

__attribute__((used)) static inline int zynq_slcr_unlock(void)
{
	zynq_slcr_write(SLCR_UNLOCK_MAGIC, SLCR_UNLOCK_OFFSET);

	return 0;
}

u32 zynq_slcr_get_device_id(void)
{
	u32 val;

	zynq_slcr_read(&val, SLCR_PSS_IDCODE);
	val >>= SLCR_PSS_IDCODE_DEVICE_SHIFT;
	val &= SLCR_PSS_IDCODE_DEVICE_MASK;

	return val;
}

__attribute__((used)) static
int zynq_slcr_system_restart(struct notifier_block *nb,
			     unsigned long action, void *data)
{
	u32 reboot;

	/*
	 * Clear 0x0F000000 bits of reboot status register to workaround
	 * the FSBL not loading the bitstream after soft-reboot
	 * This is a temporary solution until we know more.
	 */
	zynq_slcr_read(&reboot, SLCR_REBOOT_STATUS_OFFSET);
	zynq_slcr_write(reboot & 0xF0FFFFFF, SLCR_REBOOT_STATUS_OFFSET);
	zynq_slcr_write(1, SLCR_PS_RST_CTRL_OFFSET);
	return 0;
}

void zynq_slcr_cpu_start(int cpu)
{
	u32 reg;

	zynq_slcr_read(&reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
	reg &= ~(SLCR_A9_CPU_RST << cpu);
	zynq_slcr_write(reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
	reg &= ~(SLCR_A9_CPU_CLKSTOP << cpu);
	zynq_slcr_write(reg, SLCR_A9_CPU_RST_CTRL_OFFSET);

	zynq_slcr_cpu_state_write(cpu, false);
}

void zynq_slcr_cpu_stop(int cpu)
{
	u32 reg;

	zynq_slcr_read(&reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
	reg |= (SLCR_A9_CPU_CLKSTOP | SLCR_A9_CPU_RST) << cpu;
	zynq_slcr_write(reg, SLCR_A9_CPU_RST_CTRL_OFFSET);
}

bool zynq_slcr_cpu_state_read(int cpu)
{
	u32 state;

	state = readl(zynq_slcr_base + SLCR_REBOOT_STATUS_OFFSET);
	state &= 1 << (31 - cpu);

	return !state;
}

void zynq_slcr_cpu_state_write(int cpu, bool die)
{
	u32 state, mask;

	state = readl(zynq_slcr_base + SLCR_REBOOT_STATUS_OFFSET);
	mask = 1 << (31 - cpu);
	if (die)
		state |= mask;
	else
		state &= ~mask;
	writel(state, zynq_slcr_base + SLCR_REBOOT_STATUS_OFFSET);
}

