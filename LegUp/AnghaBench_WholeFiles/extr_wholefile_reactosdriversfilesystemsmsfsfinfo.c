#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {scalar_t__ MessagesAvailable; int /*<<< orphan*/  NextMessageSize; int /*<<< orphan*/  ReadTimeout; int /*<<< orphan*/  MaximumMessageSize; } ;
struct TYPE_14__ {int /*<<< orphan*/ * ReadTimeout; } ;
struct TYPE_11__ {int /*<<< orphan*/  Flink; } ;
struct TYPE_13__ {scalar_t__ MessageCount; int /*<<< orphan*/  TimeOut; int /*<<< orphan*/  MessageListLock; TYPE_1__ MessageListHead; int /*<<< orphan*/  MaxMessageSize; } ;
struct TYPE_12__ {int /*<<< orphan*/  Size; } ;
typedef  int* PULONG ;
typedef  TYPE_2__* PMSFS_MESSAGE ;
typedef  TYPE_3__* PMSFS_FCB ;
typedef  TYPE_4__* PFILE_MAILSLOT_SET_INFORMATION ;
typedef  TYPE_5__* PFILE_MAILSLOT_QUERY_INFORMATION ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int /*<<< orphan*/  KIRQL ;
typedef  int /*<<< orphan*/  FILE_MAILSLOT_SET_INFORMATION ;
typedef  int /*<<< orphan*/  FILE_MAILSLOT_QUERY_INFORMATION ;

/* Variables and functions */
 TYPE_2__* CONTAINING_RECORD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KeAcquireSpinLock (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KeReleaseSpinLock (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAILSLOT_NO_MESSAGE ; 
 int /*<<< orphan*/  MSFS_MESSAGE ; 
 int /*<<< orphan*/  MessageListEntry ; 
 int /*<<< orphan*/  STATUS_BUFFER_OVERFLOW ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 

__attribute__((used)) static NTSTATUS
MsfsQueryMailslotInformation(PMSFS_FCB Fcb,
                             PFILE_MAILSLOT_QUERY_INFORMATION Buffer,
                             PULONG BufferLength)
{
    KIRQL oldIrql;

    if (*BufferLength < sizeof(FILE_MAILSLOT_QUERY_INFORMATION))
        return STATUS_BUFFER_OVERFLOW;

    Buffer->MaximumMessageSize = Fcb->MaxMessageSize;
    Buffer->ReadTimeout = Fcb->TimeOut;

    KeAcquireSpinLock(&Fcb->MessageListLock, &oldIrql);
    Buffer->MessagesAvailable = Fcb->MessageCount;
    if (Fcb->MessageCount == 0)
    {
        Buffer->NextMessageSize = MAILSLOT_NO_MESSAGE;
    }
    else
    {
        PMSFS_MESSAGE Message = CONTAINING_RECORD(Fcb->MessageListHead.Flink,
                                                  MSFS_MESSAGE,
                                                  MessageListEntry);
        Buffer->NextMessageSize = Message->Size;
    }
    KeReleaseSpinLock(&Fcb->MessageListLock, oldIrql);

    *BufferLength -= sizeof(FILE_MAILSLOT_QUERY_INFORMATION);

    return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
MsfsSetMailslotInformation(PMSFS_FCB Fcb,
                           PFILE_MAILSLOT_SET_INFORMATION Buffer,
                           PULONG BufferLength)
{
    if (*BufferLength < sizeof(FILE_MAILSLOT_SET_INFORMATION))
        return STATUS_BUFFER_OVERFLOW;

    Fcb->TimeOut = *Buffer->ReadTimeout;

    return STATUS_SUCCESS;
}

