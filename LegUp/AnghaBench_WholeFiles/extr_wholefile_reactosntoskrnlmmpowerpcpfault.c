#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_11__ ;

/* Type definitions */
typedef  int vaddr_t ;
struct TYPE_14__ {int srr0; int srr1; int dar; int dsisr; int /*<<< orphan*/  xer; int /*<<< orphan*/  ctr; int /*<<< orphan*/  cr; int /*<<< orphan*/  lr; int /*<<< orphan*/  gpr; } ;
typedef  TYPE_2__ ppc_trap_frame_t ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_16__ {int NumberParameters; int* ExceptionInformation; scalar_t__ ExceptionFlags; int /*<<< orphan*/ * ExceptionAddress; int /*<<< orphan*/ * ExceptionRecord; int /*<<< orphan*/  ExceptionCode; } ;
struct TYPE_15__ {int Iar; int Msr; int Dr0; int Dr1; int /*<<< orphan*/  Xer; int /*<<< orphan*/  Ctr; int /*<<< orphan*/  Cr; int /*<<< orphan*/  Lr; int /*<<< orphan*/  Gpr0; } ;
struct TYPE_13__ {scalar_t__ UserApcPending; } ;
struct TYPE_12__ {TYPE_1__ ApcState; } ;
typedef  int /*<<< orphan*/ * PVOID ;
typedef  TYPE_3__* PKTRAP_FRAME ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  TYPE_3__ KTRAP_FRAME ;
typedef  int /*<<< orphan*/  KPROCESSOR_MODE ;
typedef  int /*<<< orphan*/  KIRQL ;
typedef  TYPE_5__ EXCEPTION_RECORD ;
typedef  int BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  APC_LEVEL ; 
 int /*<<< orphan*/  DPRINT (char*,int) ; 
 int /*<<< orphan*/  FALSE ; 
 int GetPhys (int) ; 
 TYPE_11__* KeGetCurrentThread () ; 
 int /*<<< orphan*/  KeLowerIrql (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KeRaiseIrql (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KernelMode ; 
 int /*<<< orphan*/  KiDeliverApc (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KiDispatchException (TYPE_5__*,int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MmAccessFault (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MmNotPresentFault (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MmuCallbackRet () ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RtlCopyMemory (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  STATUS_ACCESS_VIOLATION ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  UserMode ; 

VOID MmpPpcTrapFrameToTrapFrame(ppc_trap_frame_t *frame, PKTRAP_FRAME Tf)
{
    RtlCopyMemory(&Tf->Gpr0, frame->gpr, 12 * sizeof(ULONG));
    Tf->Lr = frame->lr;
    Tf->Cr = frame->cr;
    Tf->Ctr = frame->ctr;
    Tf->Xer = frame->xer;
    Tf->Iar = frame->srr0;
    Tf->Msr = frame->srr1 & 0xffff;
    Tf->Dr0 = frame->dar;
    Tf->Dr1 = frame->dsisr;
}

void CopyFrame(int *oldframe, int *ourframe)
{
    int i;

    for (i = 0; i < sizeof(ppc_trap_frame_t) / sizeof(int); i++)
    {
        ourframe[i] = GetPhys((int)&oldframe[i]);
    }
}

void KiPageFaultHandler(int trap, ppc_trap_frame_t *frame)
{
    NTSTATUS Status = STATUS_SUCCESS;
    KPROCESSOR_MODE Mode;
    EXCEPTION_RECORD Er;
    KTRAP_FRAME Tf;
    BOOLEAN AccessFault = !!(frame->dsisr & (1<<28));
    vaddr_t VirtualAddr;
    PVOID TrapInfo = NULL;

    /* get the faulting address */
    if (trap == 4) /* Instruction miss */
        VirtualAddr = frame->srr0;
    else /* Data miss */
        VirtualAddr = frame->dar;

    /* MSR_PR */
    Mode = frame->srr1 & 0x4000 ? UserMode : KernelMode;
    DPRINT("Page Fault at %08x\n", frame->srr0);

    /* handle the fault */
    if (AccessFault)
    {
        Status = MmAccessFault(Mode, (PVOID)VirtualAddr, FALSE, TrapInfo);
    }
    else
    {
        Status = MmNotPresentFault(Mode, VirtualAddr, FALSE);
    }

    if (NT_SUCCESS(Status))
    {
        MmuCallbackRet();
    }

    if (KeGetCurrentThread()->ApcState.UserApcPending)
    {
        KIRQL oldIrql;

        KeRaiseIrql(APC_LEVEL, &oldIrql);
        KiDeliverApc(UserMode, NULL, NULL);
        KeLowerIrql(oldIrql);
    }

    MmpPpcTrapFrameToTrapFrame(frame, &Tf);

    Er.ExceptionCode = STATUS_ACCESS_VIOLATION;
    Er.ExceptionFlags = 0;
    Er.ExceptionRecord = NULL;
    Er.ExceptionAddress = (PVOID)frame->srr0;
    Er.NumberParameters = 2;
    Er.ExceptionInformation[0] = AccessFault;
    Er.ExceptionInformation[1] = VirtualAddr;

    /* FIXME: Which exceptions are noncontinuable? */
    Er.ExceptionFlags = 0;

    KiDispatchException(&Er, 0, &Tf, Mode, TRUE);
    MmuCallbackRet();
}

