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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
#define  BCM3368_CPU_ID 134 
#define  BCM6328_CPU_ID 133 
#define  BCM6338_CPU_ID 132 
#define  BCM6345_CPU_ID 131 
#define  BCM6348_CPU_ID 130 
#define  BCM6358_CPU_ID 129 
#define  BCM6362_CPU_ID 128 
 scalar_t__ BCMCPU_IS_6328 () ; 
 scalar_t__ BCMCPU_IS_6348 () ; 
 int /*<<< orphan*/  CONF_CM_CMASK ; 
 int /*<<< orphan*/  CONF_CM_UNCACHED ; 
 int /*<<< orphan*/  EXTIRQ_CFG_CLEAR_ALL ; 
 int /*<<< orphan*/  EXTIRQ_CFG_CLEAR_ALL_6348 ; 
 int /*<<< orphan*/  EXTIRQ_CFG_MASK_ALL ; 
 int /*<<< orphan*/  EXTIRQ_CFG_MASK_ALL_6348 ; 
 int /*<<< orphan*/  PERF_EXTIRQ_CFG_REG_3368 ; 
 int /*<<< orphan*/  PERF_EXTIRQ_CFG_REG_6328 ; 
 int /*<<< orphan*/  PERF_EXTIRQ_CFG_REG_6338 ; 
 int /*<<< orphan*/  PERF_EXTIRQ_CFG_REG_6345 ; 
 int /*<<< orphan*/  PERF_EXTIRQ_CFG_REG_6348 ; 
 int /*<<< orphan*/  PERF_EXTIRQ_CFG_REG_6358 ; 
 int /*<<< orphan*/  PERF_EXTIRQ_CFG_REG_6362 ; 
 int /*<<< orphan*/  PERF_SOFTRESET_REG ; 
 int /*<<< orphan*/  PERF_SYS_PLL_CTL_REG ; 
 int /*<<< orphan*/  SOFTRESET_6348_ALL ; 
 int ST0_BEV ; 
 int ST0_ERL ; 
 int /*<<< orphan*/  SYS_PLL_SOFT_RESET ; 
 int /*<<< orphan*/  WDT_SOFTRESET_REG ; 
 int /*<<< orphan*/  __flush_cache_all () ; 
 int bcm63xx_get_cpu_id () ; 
 int bcm63xx_get_cpu_rev () ; 
 int /*<<< orphan*/  bcm_perf_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcm_perf_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcm_wdt_writel (int,int /*<<< orphan*/ ) ; 
 char* board_get_name () ; 
 int /*<<< orphan*/  change_c0_config (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  set_c0_status (int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,int,int) ; 
 int /*<<< orphan*/  write_c0_wired (int /*<<< orphan*/ ) ; 

void bcm63xx_machine_halt(void)
{
	pr_info("System halted\n");
	while (1)
		;
}

__attribute__((used)) static void bcm6348_a1_reboot(void)
{
	u32 reg;

	/* soft reset all blocks */
	pr_info("soft-resetting all blocks ...\n");
	reg = bcm_perf_readl(PERF_SOFTRESET_REG);
	reg &= ~SOFTRESET_6348_ALL;
	bcm_perf_writel(reg, PERF_SOFTRESET_REG);
	mdelay(10);

	reg = bcm_perf_readl(PERF_SOFTRESET_REG);
	reg |= SOFTRESET_6348_ALL;
	bcm_perf_writel(reg, PERF_SOFTRESET_REG);
	mdelay(10);

	/* Jump to the power on address. */
	pr_info("jumping to reset vector.\n");
	/* set high vectors (base at 0xbfc00000 */
	set_c0_status(ST0_BEV | ST0_ERL);
	/* run uncached in kseg0 */
	change_c0_config(CONF_CM_CMASK, CONF_CM_UNCACHED);
	__flush_cache_all();
	/* remove all wired TLB entries */
	write_c0_wired(0);
	__asm__ __volatile__(
		"jr\t%0"
		:
		: "r" (0xbfc00000));
	while (1)
		;
}

void bcm63xx_machine_reboot(void)
{
	u32 reg, perf_regs[2] = { 0, 0 };
	unsigned int i;

	/* mask and clear all external irq */
	switch (bcm63xx_get_cpu_id()) {
	case BCM3368_CPU_ID:
		perf_regs[0] = PERF_EXTIRQ_CFG_REG_3368;
		break;
	case BCM6328_CPU_ID:
		perf_regs[0] = PERF_EXTIRQ_CFG_REG_6328;
		break;
	case BCM6338_CPU_ID:
		perf_regs[0] = PERF_EXTIRQ_CFG_REG_6338;
		break;
	case BCM6345_CPU_ID:
		perf_regs[0] = PERF_EXTIRQ_CFG_REG_6345;
		break;
	case BCM6348_CPU_ID:
		perf_regs[0] = PERF_EXTIRQ_CFG_REG_6348;
		break;
	case BCM6358_CPU_ID:
		perf_regs[0] = PERF_EXTIRQ_CFG_REG_6358;
		break;
	case BCM6362_CPU_ID:
		perf_regs[0] = PERF_EXTIRQ_CFG_REG_6362;
		break;
	}

	for (i = 0; i < 2; i++) {
		if (!perf_regs[i])
			break;

		reg = bcm_perf_readl(perf_regs[i]);
		if (BCMCPU_IS_6348()) {
			reg &= ~EXTIRQ_CFG_MASK_ALL_6348;
			reg |= EXTIRQ_CFG_CLEAR_ALL_6348;
		} else {
			reg &= ~EXTIRQ_CFG_MASK_ALL;
			reg |= EXTIRQ_CFG_CLEAR_ALL;
		}
		bcm_perf_writel(reg, perf_regs[i]);
	}

	if (BCMCPU_IS_6348() && (bcm63xx_get_cpu_rev() == 0xa1))
		bcm6348_a1_reboot();

	pr_info("triggering watchdog soft-reset...\n");
	if (BCMCPU_IS_6328()) {
		bcm_wdt_writel(1, WDT_SOFTRESET_REG);
	} else {
		reg = bcm_perf_readl(PERF_SYS_PLL_CTL_REG);
		reg |= SYS_PLL_SOFT_RESET;
		bcm_perf_writel(reg, PERF_SYS_PLL_CTL_REG);
	}
	while (1)
		;
}

__attribute__((used)) static void __bcm63xx_machine_reboot(char *p)
{
	bcm63xx_machine_reboot();
}

const char *get_system_type(void)
{
	static char buf[128];
	snprintf(buf, sizeof(buf), "bcm63xx/%s (0x%04x/0x%02X)",
		 board_get_name(),
		 bcm63xx_get_cpu_id(), bcm63xx_get_cpu_rev());
	return buf;
}

