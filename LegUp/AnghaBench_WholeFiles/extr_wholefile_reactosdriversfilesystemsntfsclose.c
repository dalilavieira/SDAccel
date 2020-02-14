#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_8__ ;
typedef  struct TYPE_23__   TYPE_7__ ;
typedef  struct TYPE_22__   TYPE_6__ ;
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_11__ ;

/* Type definitions */
struct TYPE_24__ {int /*<<< orphan*/  DirResource; int /*<<< orphan*/  OpenHandleCount; } ;
struct TYPE_23__ {TYPE_8__* DeviceExtension; } ;
struct TYPE_17__ {scalar_t__ Buffer; } ;
struct TYPE_22__ {TYPE_1__ FileName; int /*<<< orphan*/ * SectionObjectPointer; int /*<<< orphan*/ * FsContext; int /*<<< orphan*/ * FsContext2; } ;
struct TYPE_21__ {struct TYPE_21__* DirectorySearchPattern; } ;
struct TYPE_20__ {TYPE_3__* Irp; int /*<<< orphan*/  Flags; TYPE_6__* FileObject; TYPE_7__* DeviceObject; } ;
struct TYPE_18__ {scalar_t__ Information; } ;
struct TYPE_19__ {TYPE_2__ IoStatus; } ;
struct TYPE_16__ {TYPE_7__* DeviceObject; } ;
typedef  TYPE_4__* PNTFS_IRP_CONTEXT ;
typedef  scalar_t__ PNTFS_FCB ;
typedef  TYPE_5__* PNTFS_CCB ;
typedef  TYPE_6__* PFILE_OBJECT ;
typedef  TYPE_7__* PDEVICE_OBJECT ;
typedef  TYPE_8__* PDEVICE_EXTENSION ;
typedef  scalar_t__ NTSTATUS ;

/* Variables and functions */
 int /*<<< orphan*/  BooleanFlagOn (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DPRINT (char*,...) ; 
 int /*<<< orphan*/  ExAcquireResourceExclusiveLite (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExFreePool (TYPE_5__*) ; 
 int /*<<< orphan*/  ExReleaseResourceLite (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IRPCONTEXT_CANWAIT ; 
 TYPE_11__* NtfsGlobalData ; 
 scalar_t__ NtfsMarkIrpContextForQueue (TYPE_4__*) ; 
 int /*<<< orphan*/  NtfsReleaseFCB (TYPE_8__*,scalar_t__) ; 
 scalar_t__ STATUS_PENDING ; 
 scalar_t__ STATUS_SUCCESS ; 

NTSTATUS
NtfsCloseFile(PDEVICE_EXTENSION DeviceExt,
              PFILE_OBJECT FileObject)
{
    PNTFS_CCB Ccb;
    PNTFS_FCB Fcb;

    DPRINT("NtfsCloseFile(DeviceExt %p, FileObject %p)\n",
           DeviceExt,
           FileObject);

    Ccb = (PNTFS_CCB)(FileObject->FsContext2);
    Fcb = (PNTFS_FCB)(FileObject->FsContext);

    DPRINT("Ccb %p\n", Ccb);
    if (Ccb == NULL)
    {
        return STATUS_SUCCESS;
    }

    FileObject->FsContext2 = NULL;
    FileObject->FsContext = NULL;
    FileObject->SectionObjectPointer = NULL;
    DeviceExt->OpenHandleCount--;

    if (FileObject->FileName.Buffer)
    {
        // This a FO, that was created outside from FSD.
        // Some FO's are created with IoCreateStreamFileObject() insid from FSD.
        // This FO's don't have a FileName.
        NtfsReleaseFCB(DeviceExt, Fcb);
    }

    if (Ccb->DirectorySearchPattern)
    {
        ExFreePool(Ccb->DirectorySearchPattern);
    }

    ExFreePool(Ccb);

    return STATUS_SUCCESS;
}

NTSTATUS
NtfsClose(PNTFS_IRP_CONTEXT IrpContext)
{
    PDEVICE_EXTENSION DeviceExtension;
    PFILE_OBJECT FileObject;
    NTSTATUS Status;
    PDEVICE_OBJECT DeviceObject;

    DPRINT("NtfsClose() called\n");

    DeviceObject = IrpContext->DeviceObject;
    if (DeviceObject == NtfsGlobalData->DeviceObject)
    {
        DPRINT("Closing file system\n");
        IrpContext->Irp->IoStatus.Information = 0;
        return STATUS_SUCCESS;
    }

    FileObject = IrpContext->FileObject;
    DeviceExtension = DeviceObject->DeviceExtension;

    if (!ExAcquireResourceExclusiveLite(&DeviceExtension->DirResource,
                                        BooleanFlagOn(IrpContext->Flags, IRPCONTEXT_CANWAIT)))
    {
        return NtfsMarkIrpContextForQueue(IrpContext);
    }

    Status = NtfsCloseFile(DeviceExtension, FileObject);

    ExReleaseResourceLite(&DeviceExtension->DirResource);

    if (Status == STATUS_PENDING)
    {
        return NtfsMarkIrpContextForQueue(IrpContext);
    }

    IrpContext->Irp->IoStatus.Information = 0;
    return Status;
}

