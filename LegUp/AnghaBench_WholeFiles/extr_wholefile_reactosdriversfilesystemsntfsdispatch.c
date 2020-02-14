#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;
typedef  struct TYPE_25__   TYPE_12__ ;

/* Type definitions */
struct TYPE_26__ {int /*<<< orphan*/  Status; } ;
struct TYPE_28__ {TYPE_1__ IoStatus; } ;
struct TYPE_27__ {int Flags; int MajorFunction; int /*<<< orphan*/  PriorityBoost; TYPE_3__* Irp; int /*<<< orphan*/  WorkQueueItem; } ;
struct TYPE_25__ {int /*<<< orphan*/  IrpContextLookasideList; int /*<<< orphan*/  EnableWriteSupport; } ;
typedef  TYPE_2__* PNTFS_IRP_CONTEXT ;
typedef  TYPE_3__* PIRP ;
typedef  int /*<<< orphan*/  NTSTATUS ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  CriticalWorkQueue ; 
 int /*<<< orphan*/  DPRINT (char*,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DPRINT1 (char*) ; 
 int /*<<< orphan*/  ExFreeToNPagedLookasideList (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  ExInitializeWorkItem (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  ExQueueWorkItem (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FsRtlEnterFileSystem () ; 
 int /*<<< orphan*/  FsRtlExitFileSystem () ; 
 int IRPCONTEXT_CANWAIT ; 
 int IRPCONTEXT_COMPLETE ; 
 int IRPCONTEXT_QUEUE ; 
#define  IRP_MJ_CLEANUP 139 
#define  IRP_MJ_CLOSE 138 
#define  IRP_MJ_CREATE 137 
#define  IRP_MJ_DEVICE_CONTROL 136 
#define  IRP_MJ_DIRECTORY_CONTROL 135 
#define  IRP_MJ_FILE_SYSTEM_CONTROL 134 
#define  IRP_MJ_QUERY_INFORMATION 133 
#define  IRP_MJ_QUERY_VOLUME_INFORMATION 132 
#define  IRP_MJ_READ 131 
#define  IRP_MJ_SET_INFORMATION 130 
#define  IRP_MJ_SET_VOLUME_INFORMATION 129 
#define  IRP_MJ_WRITE 128 
 int /*<<< orphan*/  InterlockedIncrement (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IoCompleteRequest (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IoMarkIrpPending (TYPE_3__*) ; 
 int /*<<< orphan*/  IoSetTopLevelIrp (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NTFS ; 
 int /*<<< orphan*/  NtfsCleanup (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsClose (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsCreate (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsDeviceControl (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsDirectoryControl (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsDoRequest ; 
 int /*<<< orphan*/  NtfsFileSystemControl (TYPE_2__*) ; 
 TYPE_12__* NtfsGlobalData ; 
 int /*<<< orphan*/  NtfsIsIrpTopLevel (TYPE_3__*) ; 
 int /*<<< orphan*/  NtfsQueryInformation (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsQueryVolumeInformation (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsRead (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsSetInformation (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsSetVolumeInformation (TYPE_2__*) ; 
 int /*<<< orphan*/  NtfsWrite (TYPE_2__*) ; 
 int /*<<< orphan*/  QueueCount ; 
 int /*<<< orphan*/  STATUS_ACCESS_DENIED ; 
 int /*<<< orphan*/  STATUS_PENDING ; 
 int /*<<< orphan*/  STATUS_UNSUCCESSFUL ; 
 int /*<<< orphan*/  TRACE_ (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static
NTSTATUS
NtfsQueueRequest(PNTFS_IRP_CONTEXT IrpContext)
{
    InterlockedIncrement(&QueueCount);
    DPRINT("NtfsQueueRequest(IrpContext %p), %d\n", IrpContext, QueueCount);

    ASSERT(!(IrpContext->Flags & IRPCONTEXT_QUEUE) &&
           (IrpContext->Flags & IRPCONTEXT_COMPLETE));
    IrpContext->Flags |= IRPCONTEXT_CANWAIT;
    IoMarkIrpPending(IrpContext->Irp);
    ExInitializeWorkItem(&IrpContext->WorkQueueItem, NtfsDoRequest, IrpContext);
    ExQueueWorkItem(&IrpContext->WorkQueueItem, CriticalWorkQueue);

    return STATUS_PENDING;
}

__attribute__((used)) static
NTSTATUS
NtfsDispatch(PNTFS_IRP_CONTEXT IrpContext)
{
    PIRP Irp = IrpContext->Irp;
    NTSTATUS Status = STATUS_UNSUCCESSFUL;

    TRACE_(NTFS, "NtfsDispatch()\n");

    FsRtlEnterFileSystem();

    NtfsIsIrpTopLevel(Irp);

    switch (IrpContext->MajorFunction)
    {
        case IRP_MJ_QUERY_VOLUME_INFORMATION:
            Status = NtfsQueryVolumeInformation(IrpContext);
            break;

        case IRP_MJ_SET_VOLUME_INFORMATION:
            Status = NtfsSetVolumeInformation(IrpContext);
            break;

        case IRP_MJ_QUERY_INFORMATION:
            Status = NtfsQueryInformation(IrpContext);
            break;

        case IRP_MJ_SET_INFORMATION:
            if (!NtfsGlobalData->EnableWriteSupport)
            {
                DPRINT1("NTFS write-support is EXPERIMENTAL and is disabled by default!\n");
                Status = STATUS_ACCESS_DENIED;
            }
            else
            {
                Status = NtfsSetInformation(IrpContext);
            }
            break;

        case IRP_MJ_DIRECTORY_CONTROL:
            Status = NtfsDirectoryControl(IrpContext);
            break;

        case IRP_MJ_READ:
            Status = NtfsRead(IrpContext);
            break;

        case IRP_MJ_DEVICE_CONTROL:
            Status = NtfsDeviceControl(IrpContext);
             break;

        case IRP_MJ_WRITE:
            if (!NtfsGlobalData->EnableWriteSupport)
            {
                DPRINT1("NTFS write-support is EXPERIMENTAL and is disabled by default!\n");
                Status = STATUS_ACCESS_DENIED;
            }
            else
            {
                Status = NtfsWrite(IrpContext);
            }
            break;

        case IRP_MJ_CLOSE:
            Status = NtfsClose(IrpContext);
            break;

        case IRP_MJ_CLEANUP:
            Status = NtfsCleanup(IrpContext);
            break;

        case IRP_MJ_CREATE:
            Status = NtfsCreate(IrpContext);
            break;

        case IRP_MJ_FILE_SYSTEM_CONTROL:
            Status = NtfsFileSystemControl(IrpContext);
            break;
    }

    ASSERT((!(IrpContext->Flags & IRPCONTEXT_COMPLETE) && !(IrpContext->Flags & IRPCONTEXT_QUEUE)) ||
           ((IrpContext->Flags & IRPCONTEXT_COMPLETE) && !(IrpContext->Flags & IRPCONTEXT_QUEUE)) ||
           (!(IrpContext->Flags & IRPCONTEXT_COMPLETE) && (IrpContext->Flags & IRPCONTEXT_QUEUE)));

    if (IrpContext->Flags & IRPCONTEXT_COMPLETE)
    {
        Irp->IoStatus.Status = Status;
        IoCompleteRequest(Irp, IrpContext->PriorityBoost);
    }

    if (IrpContext->Flags & IRPCONTEXT_QUEUE)
    {
        /* Reset our status flags before queueing the IRP */
        IrpContext->Flags |= IRPCONTEXT_COMPLETE;
        IrpContext->Flags &= ~IRPCONTEXT_QUEUE;
        Status = NtfsQueueRequest(IrpContext);
    }
    else
    {
        ExFreeToNPagedLookasideList(&NtfsGlobalData->IrpContextLookasideList, IrpContext);
    }

    IoSetTopLevelIrp(NULL);
    FsRtlExitFileSystem();

    return Status;
}

