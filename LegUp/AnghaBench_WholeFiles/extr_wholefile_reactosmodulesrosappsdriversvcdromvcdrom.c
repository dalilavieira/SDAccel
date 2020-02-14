#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ USHORT ;
typedef  int /*<<< orphan*/  ULONG_PTR ;
struct TYPE_13__ {scalar_t__ Length; scalar_t__ MaximumLength; int /*<<< orphan*/ * Buffer; } ;
struct TYPE_12__ {scalar_t__ Length; scalar_t__ MaximumLength; int /*<<< orphan*/ * Buffer; } ;
struct TYPE_18__ {TYPE_2__ ImageName; TYPE_1__ GlobalName; scalar_t__ ChangeCount; int /*<<< orphan*/ * VolumeObject; TYPE_6__* DeviceObject; } ;
struct TYPE_17__ {TYPE_7__* DeviceExtension; } ;
struct TYPE_14__ {int /*<<< orphan*/  Status; int /*<<< orphan*/  Information; } ;
struct TYPE_16__ {TYPE_3__ IoStatus; } ;
struct TYPE_15__ {scalar_t__ MaximumLength; scalar_t__ Length; int /*<<< orphan*/ * Buffer; } ;
typedef  int /*<<< orphan*/ * PVOID ;
typedef  TYPE_4__* PUNICODE_STRING ;
typedef  TYPE_5__* PIRP ;
typedef  TYPE_6__* PDEVICE_OBJECT ;
typedef  TYPE_7__* PDEVICE_EXTENSION ;
typedef  int /*<<< orphan*/  NTSTATUS ;

/* Variables and functions */
 int /*<<< orphan*/ * ExAllocatePoolWithTag (int /*<<< orphan*/ ,scalar_t__,char) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NonPagedPool ; 
 int /*<<< orphan*/  STATUS_NO_MEMORY ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 

VOID
ViInitializeDeviceExtension(PDEVICE_OBJECT DeviceObject)
{
    PDEVICE_EXTENSION DeviceExtension;

    DeviceExtension = DeviceObject->DeviceExtension;

    /* Zero mandatory fields, the rest will be zeroed when needed */
    DeviceExtension->DeviceObject = DeviceObject;
    DeviceExtension->VolumeObject = NULL;
    DeviceExtension->ChangeCount = 0;
    DeviceExtension->GlobalName.Buffer = NULL;
    DeviceExtension->GlobalName.MaximumLength = 0;
    DeviceExtension->GlobalName.Length = 0;
    DeviceExtension->ImageName.Buffer = NULL;
    DeviceExtension->ImageName.MaximumLength = 0;
    DeviceExtension->ImageName.Length = 0;
}

NTSTATUS
ViAllocateUnicodeString(USHORT BufferLength, PUNICODE_STRING UnicodeString)
{
    PVOID Buffer;

    /* Allocate the buffer */
    Buffer = ExAllocatePoolWithTag(NonPagedPool, BufferLength, ' dCV');
    /* Initialize */
    UnicodeString->Length = 0;
    UnicodeString->MaximumLength = BufferLength;
    UnicodeString->Buffer = Buffer;

    /* Return success if it went fine */
    if (Buffer != NULL)
    {
        return STATUS_SUCCESS;
    }

    return STATUS_NO_MEMORY;
}

VOID
ViFreeUnicodeString(PUNICODE_STRING UnicodeString)
{
    /* Only free if allocate, that allows using this
     * on cleanup in short memory situations
     */
    if (UnicodeString->Buffer != NULL)
    {
        ExFreePoolWithTag(UnicodeString->Buffer, 0);
        UnicodeString->Buffer = NULL;
    }

    /* Zero the rest */
    UnicodeString->Length = 0;
    UnicodeString->MaximumLength = 0;
}

NTSTATUS
ViSetIoStatus(NTSTATUS Status, ULONG_PTR Information, PIRP Irp)
{
    /* Only set what we got */
    Irp->IoStatus.Information = Information;
    Irp->IoStatus.Status = Status;

    /* And return the status, so that caller can return with us */
    return Status;
}

