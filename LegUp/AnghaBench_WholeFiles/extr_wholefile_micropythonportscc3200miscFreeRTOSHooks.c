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
typedef  int /*<<< orphan*/  OsiTaskHandle ;

/* Variables and functions */
 int /*<<< orphan*/  HAL_IncrementTick () ; 
 int /*<<< orphan*/  __WFI () ; 
 int /*<<< orphan*/  __fatal_error (char*) ; 
 int /*<<< orphan*/  mperror_heartbeat_signal () ; 

void vApplicationIdleHook (void)
{
    // signal that we are alive and kicking
    mperror_heartbeat_signal();
    // gate the processor's clock to save power
    __WFI();
}

void vApplicationMallocFailedHook (void)
{
#ifdef DEBUG
    // break into the debugger
    __asm volatile ("bkpt #0  \n");
#endif

    __fatal_error("FreeRTOS malloc failed!");
}

void vApplicationStackOverflowHook (OsiTaskHandle *pxTask, signed char *pcTaskName)
{
#ifdef DEBUG
    // Break into the debugger
    __asm volatile ("bkpt #0  \n");
#endif

    __fatal_error("Stack overflow!");
}

void vApplicationTickHook (void)
{
    HAL_IncrementTick();
}

