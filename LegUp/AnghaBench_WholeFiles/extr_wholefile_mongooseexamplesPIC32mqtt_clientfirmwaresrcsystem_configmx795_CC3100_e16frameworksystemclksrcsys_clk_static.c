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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  SYS_CLK_INIT ;
typedef  int /*<<< orphan*/  CLK_BUSES_REFERENCE ;
typedef  int /*<<< orphan*/  CLK_BUSES_PERIPHERAL ;

/* Variables and functions */
 int /*<<< orphan*/  OSC_FRC_DIV_2 ; 
 int /*<<< orphan*/  OSC_ID_0 ; 
 int /*<<< orphan*/  PLIB_OSC_FRCDivisorSelect (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_OSC_PBClockDivisorSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PLIB_OSC_SecondaryDisable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLIB_OSC_SecondaryEnable (int /*<<< orphan*/ ) ; 
 int PLIB_OSC_SecondaryIsEnabled (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SYS_CLK_BUS_PERIPHERAL_1 ; 
 int /*<<< orphan*/  SYS_CLK_FREQ ; 
 int /*<<< orphan*/  SYS_DEVCON_SystemLock () ; 
 int /*<<< orphan*/  SYS_DEVCON_SystemUnlock () ; 

void SYS_CLK_Initialize(const SYS_CLK_INIT const *clkInit) {
  SYS_DEVCON_SystemUnlock();

  PLIB_OSC_FRCDivisorSelect(OSC_ID_0, OSC_FRC_DIV_2);

  /* Enable Peripheral Bus 1 */
  PLIB_OSC_PBClockDivisorSet(OSC_ID_0, 0, 1);

  SYS_DEVCON_SystemLock();
}

inline uint32_t SYS_CLK_SystemFrequencyGet(void) {
  return SYS_CLK_FREQ;
}

inline uint32_t SYS_CLK_PeripheralFrequencyGet(
    CLK_BUSES_PERIPHERAL peripheralBus) {
  return SYS_CLK_BUS_PERIPHERAL_1;
}

inline uint32_t SYS_CLK_ReferenceClockFrequencyGet(
    CLK_BUSES_REFERENCE referenceBus) {
  return 0;
}

void SYS_CLK_SecondaryOscillatorEnable(void) {
  /* Check for secondary oscillator status */
  if (!PLIB_OSC_SecondaryIsEnabled(OSC_ID_0)) {
    /* Unlock and enable secondary oscillator */
    SYS_DEVCON_SystemUnlock();

    PLIB_OSC_SecondaryEnable(OSC_ID_0);

    SYS_DEVCON_SystemLock();
  }
}

void SYS_CLK_SecondaryOscillatorDisable(void) {
  /* Check for secondary oscillator status */
  if (PLIB_OSC_SecondaryIsEnabled(OSC_ID_0)) {
    /* Unlock and disable secondary oscillator*/
    SYS_DEVCON_SystemUnlock();

    PLIB_OSC_SecondaryDisable(OSC_ID_0);

    SYS_DEVCON_SystemLock();
  }
}

bool SYS_CLK_SecondaryOscillatorIsEnabled(void) {
  return (PLIB_OSC_SecondaryIsEnabled(OSC_ID_0));
}

