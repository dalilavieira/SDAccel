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
typedef  scalar_t__ ULONG ;
typedef  int /*<<< orphan*/  FRAME ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENTER_FUNC () ; 
 int /*<<< orphan*/  LEAVE_FUNC () ; 
 int /*<<< orphan*/  MaskIrqs () ; 
 scalar_t__ OldDblFltHandler ; 
 int /*<<< orphan*/  RemoveAllSWBreakpoints (int /*<<< orphan*/ ) ; 
 scalar_t__ SetGlobalInt (int,scalar_t__) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  UnmaskIrqs () ; 

void HandleDoubleFault(FRAME* ptr)
{
    DPRINT((0,"HandleDoubleFault(): ptr = %x\n",ptr));
}

void InstallDblFltHook(void)
{
	ULONG LocalDblFltHandler;

	ENTER_FUNC();

	MaskIrqs();
	if(!OldDblFltHandler)
	{
		__asm__("mov $NewDblFltHandler,%0"
			:"=r" (LocalDblFltHandler)
			:
			:"eax");
		OldDblFltHandler=SetGlobalInt(0x08,(ULONG)LocalDblFltHandler);
	}
	UnmaskIrqs();

    LEAVE_FUNC();
}

void DeInstallDblFltHook(void)
{
	ENTER_FUNC();

	MaskIrqs();
	if(OldDblFltHandler)
	{
        RemoveAllSWBreakpoints(TRUE);
		SetGlobalInt(0x08,(ULONG)OldDblFltHandler);
        OldDblFltHandler=0;
	}
	UnmaskIrqs();

    LEAVE_FUNC();
}

