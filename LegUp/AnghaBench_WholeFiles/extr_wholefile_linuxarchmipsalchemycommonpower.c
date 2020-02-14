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

/* Variables and functions */
#define  ALCHEMY_CPU_AU1000 133 
#define  ALCHEMY_CPU_AU1100 132 
#define  ALCHEMY_CPU_AU1200 131 
#define  ALCHEMY_CPU_AU1300 130 
#define  ALCHEMY_CPU_AU1500 129 
#define  ALCHEMY_CPU_AU1550 128 
 int /*<<< orphan*/  AU1000_MEM_STADDR0 ; 
 int /*<<< orphan*/  AU1000_MEM_STADDR1 ; 
 int /*<<< orphan*/  AU1000_MEM_STADDR2 ; 
 int /*<<< orphan*/  AU1000_MEM_STADDR3 ; 
 int /*<<< orphan*/  AU1000_MEM_STCFG0 ; 
 int /*<<< orphan*/  AU1000_MEM_STCFG1 ; 
 int /*<<< orphan*/  AU1000_MEM_STCFG2 ; 
 int /*<<< orphan*/  AU1000_MEM_STCFG3 ; 
 int /*<<< orphan*/  AU1000_MEM_STTIME0 ; 
 int /*<<< orphan*/  AU1000_MEM_STTIME1 ; 
 int /*<<< orphan*/  AU1000_MEM_STTIME2 ; 
 int /*<<< orphan*/  AU1000_MEM_STTIME3 ; 
 int /*<<< orphan*/  AU1000_SYS_AUXPLL ; 
 int /*<<< orphan*/  AU1000_SYS_CLKSRC ; 
 int /*<<< orphan*/  AU1000_SYS_CPUPLL ; 
 int /*<<< orphan*/  AU1000_SYS_FREQCTRL0 ; 
 int /*<<< orphan*/  AU1000_SYS_FREQCTRL1 ; 
 int /*<<< orphan*/  AU1000_SYS_PINFUNC ; 
 int alchemy_get_cputype () ; 
 int /*<<< orphan*/  alchemy_rdsmem (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alchemy_rdsys (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alchemy_sleep_au1000 () ; 
 int /*<<< orphan*/  alchemy_sleep_au1300 () ; 
 int /*<<< orphan*/  alchemy_sleep_au1550 () ; 
 int /*<<< orphan*/  alchemy_wrsmem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alchemy_wrsys (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  au1xxx_cpu_has_pll_wo () ; 
 int /*<<< orphan*/ ** sleep_static_memctlr ; 
 int /*<<< orphan*/ * sleep_sys_clocks ; 
 int /*<<< orphan*/  sleep_sys_pinfunc ; 

__attribute__((used)) static void save_core_regs(void)
{
	/* Clocks and PLLs. */
	sleep_sys_clocks[0] = alchemy_rdsys(AU1000_SYS_FREQCTRL0);
	sleep_sys_clocks[1] = alchemy_rdsys(AU1000_SYS_FREQCTRL1);
	sleep_sys_clocks[2] = alchemy_rdsys(AU1000_SYS_CLKSRC);
	sleep_sys_clocks[3] = alchemy_rdsys(AU1000_SYS_CPUPLL);
	sleep_sys_clocks[4] = alchemy_rdsys(AU1000_SYS_AUXPLL);

	/* pin mux config */
	sleep_sys_pinfunc = alchemy_rdsys(AU1000_SYS_PINFUNC);

	/* Save the static memory controller configuration. */
	sleep_static_memctlr[0][0] = alchemy_rdsmem(AU1000_MEM_STCFG0);
	sleep_static_memctlr[0][1] = alchemy_rdsmem(AU1000_MEM_STTIME0);
	sleep_static_memctlr[0][2] = alchemy_rdsmem(AU1000_MEM_STADDR0);
	sleep_static_memctlr[1][0] = alchemy_rdsmem(AU1000_MEM_STCFG1);
	sleep_static_memctlr[1][1] = alchemy_rdsmem(AU1000_MEM_STTIME1);
	sleep_static_memctlr[1][2] = alchemy_rdsmem(AU1000_MEM_STADDR1);
	sleep_static_memctlr[2][0] = alchemy_rdsmem(AU1000_MEM_STCFG2);
	sleep_static_memctlr[2][1] = alchemy_rdsmem(AU1000_MEM_STTIME2);
	sleep_static_memctlr[2][2] = alchemy_rdsmem(AU1000_MEM_STADDR2);
	sleep_static_memctlr[3][0] = alchemy_rdsmem(AU1000_MEM_STCFG3);
	sleep_static_memctlr[3][1] = alchemy_rdsmem(AU1000_MEM_STTIME3);
	sleep_static_memctlr[3][2] = alchemy_rdsmem(AU1000_MEM_STADDR3);
}

__attribute__((used)) static void restore_core_regs(void)
{
	/* restore clock configuration.  Writing CPUPLL last will
	 * stall a bit and stabilize other clocks (unless this is
	 * one of those Au1000 with a write-only PLL, where we dont
	 * have a valid value)
	 */
	alchemy_wrsys(sleep_sys_clocks[0], AU1000_SYS_FREQCTRL0);
	alchemy_wrsys(sleep_sys_clocks[1], AU1000_SYS_FREQCTRL1);
	alchemy_wrsys(sleep_sys_clocks[2], AU1000_SYS_CLKSRC);
	alchemy_wrsys(sleep_sys_clocks[4], AU1000_SYS_AUXPLL);
	if (!au1xxx_cpu_has_pll_wo())
		alchemy_wrsys(sleep_sys_clocks[3], AU1000_SYS_CPUPLL);

	alchemy_wrsys(sleep_sys_pinfunc, AU1000_SYS_PINFUNC);

	/* Restore the static memory controller configuration. */
	alchemy_wrsmem(sleep_static_memctlr[0][0], AU1000_MEM_STCFG0);
	alchemy_wrsmem(sleep_static_memctlr[0][1], AU1000_MEM_STTIME0);
	alchemy_wrsmem(sleep_static_memctlr[0][2], AU1000_MEM_STADDR0);
	alchemy_wrsmem(sleep_static_memctlr[1][0], AU1000_MEM_STCFG1);
	alchemy_wrsmem(sleep_static_memctlr[1][1], AU1000_MEM_STTIME1);
	alchemy_wrsmem(sleep_static_memctlr[1][2], AU1000_MEM_STADDR1);
	alchemy_wrsmem(sleep_static_memctlr[2][0], AU1000_MEM_STCFG2);
	alchemy_wrsmem(sleep_static_memctlr[2][1], AU1000_MEM_STTIME2);
	alchemy_wrsmem(sleep_static_memctlr[2][2], AU1000_MEM_STADDR2);
	alchemy_wrsmem(sleep_static_memctlr[3][0], AU1000_MEM_STCFG3);
	alchemy_wrsmem(sleep_static_memctlr[3][1], AU1000_MEM_STTIME3);
	alchemy_wrsmem(sleep_static_memctlr[3][2], AU1000_MEM_STADDR3);
}

void au_sleep(void)
{
	save_core_regs();

	switch (alchemy_get_cputype()) {
	case ALCHEMY_CPU_AU1000:
	case ALCHEMY_CPU_AU1500:
	case ALCHEMY_CPU_AU1100:
		alchemy_sleep_au1000();
		break;
	case ALCHEMY_CPU_AU1550:
	case ALCHEMY_CPU_AU1200:
		alchemy_sleep_au1550();
		break;
	case ALCHEMY_CPU_AU1300:
		alchemy_sleep_au1300();
		break;
	}

	restore_core_regs();
}

