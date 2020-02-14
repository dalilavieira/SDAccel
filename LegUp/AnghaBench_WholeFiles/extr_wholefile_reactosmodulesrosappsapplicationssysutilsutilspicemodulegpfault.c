#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ULONG ;
struct TYPE_3__ {int /*<<< orphan*/  eip; } ;
typedef  TYPE_1__ FRAME ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENTER_FUNC () ; 
 int /*<<< orphan*/  LEAVE_FUNC () ; 
 int /*<<< orphan*/  MaskIrqs () ; 
 scalar_t__ OldGPFaultHandler ; 
 int /*<<< orphan*/  RemoveAllSWBreakpoints (int /*<<< orphan*/ ) ; 
 scalar_t__ SetGlobalInt (int,scalar_t__) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  UnmaskIrqs () ; 

void HandleGPFault(FRAME* ptr)
{
	DPRINT((0,"HandleGPFault(): ptr = %x at eip: %x\n",ptr, ptr->eip));
}

void InstallGPFaultHook(void)
{
	ULONG LocalGPFaultHandler;

	ENTER_FUNC();

	MaskIrqs();
	if(!OldGPFaultHandler)
	{
		__asm__("mov $NewGPFaultHandler,%0"
			:"=r" (LocalGPFaultHandler)
			:
			:"eax");
		OldGPFaultHandler=SetGlobalInt(0x0D,(ULONG)LocalGPFaultHandler);
	}
	UnmaskIrqs();

    LEAVE_FUNC();
}

void DeInstallGPFaultHook(void)
{
	ENTER_FUNC();

	MaskIrqs();
	if(OldGPFaultHandler)
	{
        RemoveAllSWBreakpoints(TRUE);
		SetGlobalInt(0x0D,(ULONG)OldGPFaultHandler);
        OldGPFaultHandler=0;
	}
	UnmaskIrqs();

    LEAVE_FUNC();
}

