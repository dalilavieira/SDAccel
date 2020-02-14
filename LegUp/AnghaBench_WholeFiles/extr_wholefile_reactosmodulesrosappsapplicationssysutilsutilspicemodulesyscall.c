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
typedef  int /*<<< orphan*/  ULONG ;
typedef  int /*<<< orphan*/  FRAME_SYSCALL ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENTER_FUNC () ; 
 int /*<<< orphan*/  LEAVE_FUNC () ; 
 int /*<<< orphan*/  RevirtualizeBreakpointsForModule (scalar_t__) ; 
 int /*<<< orphan*/  old_cleanup_module () ; 
 scalar_t__ pModJustFreed ; 

void other_module_cleanup_module(void)
{
    DPRINT((0,"other_module_cleanup_module()\n"));

    if(old_cleanup_module)
    {
        DPRINT((0,"other_module_cleanup_module(): calling %x\n",(ULONG)old_cleanup_module));
        old_cleanup_module();
    }

    if(pModJustFreed)
    {
        DPRINT((0,"other_module_cleanup_module(): calling RevirtualizeBreakpointsForModule(%x)\n",(ULONG)pModJustFreed));
        RevirtualizeBreakpointsForModule(pModJustFreed);
    }
}

void CSyscallHandler(FRAME_SYSCALL* ptr,ULONG ulSysCall,ULONG ebx)
{
//	DPRINT((0,"CSyscallHandler(): %.4X:%.8X (syscall = %u)\n",ptr->cs,ptr->eip,ulSysCall));
/*
	switch(ulSysCall)
    {
        case 1: // sys_exit
            DPRINT((0,"CSysCallHandler(): 1\n"));
			if(bReportProcessEvents)
			{
				PICE_sprintf(syscallTemp,"pICE: process destroyed \"%s\" PID=%.4X\n",current->comm,current->pid);
				AddToRingBuffer(syscallTemp);
			}
            break;
        case 11: // sys_execve
            DPRINT((0,"CSysCallHandler(): 11\n"));
			if(bReportProcessEvents)
			{
				if(PICE_strlen((char*)ebx))
					PICE_sprintf(syscallTemp,"pICE: process created \"%s\" PID=%.4X (parent \"%s\")\n",(char *)ebx,current->pid,current->comm);
				else
					PICE_sprintf(syscallTemp,"pICE: process created PID=%.4X (parent \"%s\")\n",current->pid,current->comm);
				AddToRingBuffer(syscallTemp);
			}
            break;
        case 128: // sys_init_module
            DPRINT((0,"CSysCallHandler(): 128\n"));
            if(PICE_strlen((char *)ebx))
            {
                if(pmodule_list)
                {
                    struct module* pMod = *pmodule_list;
                    do
                    {
                        if(PICE_strcmpi((char*)ebx,(LPSTR)pMod->name)==0)
                        {
                            ULONG ulInitAddress;
                            PICE_sprintf(syscallTemp,"pICE: module \"%s\" loaded (%x-%x init @ %x)\n",(char*)ebx,pMod,(ULONG)pMod+pMod->size,pMod->init);
                            if((ulInitAddress=FindFunctionInModuleByName("init_module",pMod)))
                            {
			                    DPRINT((0,"setting DR1=%.8x\n",ulInitAddress));

                                SetHardwareBreakPoint(ulInitAddress,1);
                            }
                        }
                    }while((pMod = pMod->next));
                }
                else
                {
                    PICE_sprintf(syscallTemp,"pICE: module loaded \"%s\"\n",(char *)ebx);
                }
            }
            else
                PICE_sprintf(syscallTemp,"pICE: module loaded\n");
            AddToRingBuffer(syscallTemp);
            break;
        case 129: // sys_delete_module
            DPRINT((0,"CSysCallHandler(): 129\n"));
            if(PICE_strlen((char *)ebx))
            {
                if(IsModuleLoaded((LPSTR)ebx)!=NULL && PICE_strcmpi((char*)ebx,"pice")!=0 )
                {
                    PICE_sprintf(syscallTemp,"pICE: module freed \"%s\"\n",(char *)ebx);
                    Print(OUTPUT_WINDOW,syscallTemp);
					if((pModJustFreed = FindModuleByName((char*)ebx)) )
					{
                        if(pModJustFreed->cleanup)
                        {
                            old_cleanup_module = pModJustFreed->cleanup;
                            pModJustFreed->cleanup = other_module_cleanup_module;
                        }
                        else
                        {
						    RevirtualizeBreakpointsForModule(pModJustFreed);
                        }
					}
                }
            }
            else
            {
                PICE_sprintf(syscallTemp,"pICE: module freed\n");
                AddToRingBuffer(syscallTemp);
            }
			break;
    }
 */
}

void InstallSyscallHook(void)
{
	ULONG LocalSyscallHandler;

	ENTER_FUNC();
/*ei  fix later
	MaskIrqs();
	if(!OldSyscallHandler)
	{
		__asm__("mov $NewSyscallHandler,%0"
			:"=r" (LocalSyscallHandler)
			:
			:"eax");
		OldSyscallHandler=SetGlobalInt(0x2e,(ULONG)LocalSyscallHandler);

		ScanExports("free_module",(PULONG)&ulFreeModule);

		DPRINT((0,"InstallSyscallHook(): free_module @ %x\n",ulFreeModule));
	}
	UnmaskIrqs();
 */
    LEAVE_FUNC();
}

void DeInstallSyscallHook(void)
{
	ENTER_FUNC();
/*ei
	MaskIrqs();
	if(OldSyscallHandler)
	{
		SetGlobalInt(0x2e,(ULONG)OldSyscallHandler);
        (ULONG)OldSyscallHandler=0;
	}
	UnmaskIrqs();
*/
    LEAVE_FUNC();
}

