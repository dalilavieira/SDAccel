#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  fcrdiv; int /*<<< orphan*/  ircs; int /*<<< orphan*/  irclkEnableMode; int /*<<< orphan*/  pll0Config; int /*<<< orphan*/  oscsel; } ;
struct TYPE_8__ {int /*<<< orphan*/  coreClock; int /*<<< orphan*/  simConfig; TYPE_1__ mcgConfig; int /*<<< orphan*/  oscConfig; } ;
struct TYPE_6__ {int /*<<< orphan*/  irclkEnableMode; int /*<<< orphan*/  ircs; int /*<<< orphan*/  fcrdiv; } ;
struct TYPE_7__ {int /*<<< orphan*/  coreClock; int /*<<< orphan*/  simConfig; TYPE_2__ mcgConfig; } ;

/* Variables and functions */
 int /*<<< orphan*/  BOARD_XTAL0_CLK_HZ ; 
 int /*<<< orphan*/  CLOCK_BootToBlpiMode (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLOCK_BootToPeeMode (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CLOCK_InitOsc0 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CLOCK_SetInternalRefClkConfig (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLOCK_SetSimConfig (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CLOCK_SetSimSafeDivs () ; 
 int /*<<< orphan*/  CLOCK_SetXtal0Freq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SMC ; 
 scalar_t__ SMC_GetPowerModeState (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SMC_SetPowerModeProtection (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SMC_SetPowerModeVlpr (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SystemCoreClock ; 
 TYPE_4__ g_defaultClockConfigRun ; 
 TYPE_3__ g_defaultClockConfigVlpr ; 
 int /*<<< orphan*/  kMCG_PllClkSelPll0 ; 
 int /*<<< orphan*/  kSMC_AllowPowerModeAll ; 
 scalar_t__ kSMC_PowerStateVlpr ; 

void BOARD_BootClockVLPR(void)
{
    CLOCK_SetSimSafeDivs();

    CLOCK_BootToBlpiMode(g_defaultClockConfigVlpr.mcgConfig.fcrdiv, g_defaultClockConfigVlpr.mcgConfig.ircs,
                         g_defaultClockConfigVlpr.mcgConfig.irclkEnableMode);

    CLOCK_SetSimConfig(&g_defaultClockConfigVlpr.simConfig);

    SystemCoreClock = g_defaultClockConfigVlpr.coreClock;

    SMC_SetPowerModeProtection(SMC, kSMC_AllowPowerModeAll);
    SMC_SetPowerModeVlpr(SMC, false);
    while (SMC_GetPowerModeState(SMC) != kSMC_PowerStateVlpr)
    {
    }
}

void BOARD_BootClockRUN(void)
{
    CLOCK_SetSimSafeDivs();

    CLOCK_InitOsc0(&g_defaultClockConfigRun.oscConfig);
    CLOCK_SetXtal0Freq(BOARD_XTAL0_CLK_HZ);

    CLOCK_BootToPeeMode(g_defaultClockConfigRun.mcgConfig.oscsel, kMCG_PllClkSelPll0,
                        &g_defaultClockConfigRun.mcgConfig.pll0Config);

    CLOCK_SetInternalRefClkConfig(g_defaultClockConfigRun.mcgConfig.irclkEnableMode,
                                  g_defaultClockConfigRun.mcgConfig.ircs, g_defaultClockConfigRun.mcgConfig.fcrdiv);

    CLOCK_SetSimConfig(&g_defaultClockConfigRun.simConfig);

    SystemCoreClock = g_defaultClockConfigRun.coreClock;
}

