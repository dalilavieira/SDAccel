#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_23__ {struct TYPE_23__* Flink; } ;
struct TYPE_22__ {int /*<<< orphan*/  Spinlock; int /*<<< orphan*/  OpenCount; int /*<<< orphan*/  DeviceName; int /*<<< orphan*/  PacketPoolHandle; int /*<<< orphan*/  BufferPoolHandle; } ;
struct TYPE_21__ {TYPE_1__* FileObject; int /*<<< orphan*/  ListEntry; } ;
struct TYPE_20__ {int /*<<< orphan*/ * FsContext2; int /*<<< orphan*/ * FsContext; } ;
typedef  TYPE_2__* PVOID ;
typedef  int /*<<< orphan*/  PNDIS_STRING ;
typedef  int /*<<< orphan*/ * PNDIS_PACKET ;
typedef  int /*<<< orphan*/  PNDIS_BUFFER ;
typedef  TYPE_2__* PNDISUIO_OPEN_ENTRY ;
typedef  TYPE_4__* PNDISUIO_ADAPTER_CONTEXT ;
typedef  TYPE_5__* PLIST_ENTRY ;
typedef  scalar_t__ NDIS_STATUS ;
typedef  int /*<<< orphan*/  KIRQL ;
typedef  scalar_t__ BOOLEAN ;

/* Variables and functions */
 TYPE_4__* CONTAINING_RECORD (TYPE_5__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DPRINT1 (char*) ; 
 int /*<<< orphan*/  ExFreePool (TYPE_2__*) ; 
 TYPE_5__ GlobalAdapterList ; 
 int /*<<< orphan*/  GlobalAdapterListLock ; 
 int /*<<< orphan*/  KeAcquireSpinLock (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KeReleaseSpinLock (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ListEntry ; 
 int /*<<< orphan*/  NDISUIO_ADAPTER_CONTEXT ; 
 scalar_t__ NDIS_STATUS_SUCCESS ; 
 int /*<<< orphan*/  NdisAllocateBuffer (scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NdisAllocatePacket (scalar_t__*,int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NdisChainBufferAtBack (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NdisChainBufferAtFront (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NdisFreeBuffer (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NdisFreePacket (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NdisQueryBuffer (int /*<<< orphan*/ ,TYPE_2__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NdisUnchainBufferAtFront (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RemoveEntryList (int /*<<< orphan*/ *) ; 
 scalar_t__ RtlEqualUnicodeString (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ TRUE ; 

NDIS_STATUS
AllocateAndChainBuffer(PNDISUIO_ADAPTER_CONTEXT AdapterContext,
                       PNDIS_PACKET Packet,
                       PVOID Buffer,
                       ULONG BufferSize,
                       BOOLEAN Front)
{
    NDIS_STATUS Status;
    PNDIS_BUFFER NdisBuffer;

    /* Allocate the NDIS buffer mapping the pool */
    NdisAllocateBuffer(&Status,
                       &NdisBuffer,
                       AdapterContext->BufferPoolHandle,
                       Buffer,
                       BufferSize);
    if (Status != NDIS_STATUS_SUCCESS)
    {
        DPRINT1("No free buffer descriptors\n");
        return Status;
    }

    if (Front)
    {
        /* Chain the buffer to front */
        NdisChainBufferAtFront(Packet, NdisBuffer);
    }
    else
    {
        /* Chain the buffer to back */
        NdisChainBufferAtBack(Packet, NdisBuffer);
    }

    /* Return success */
    return NDIS_STATUS_SUCCESS;
}

PNDIS_PACKET
CreatePacketFromPoolBuffer(PNDISUIO_ADAPTER_CONTEXT AdapterContext,
                           PVOID Buffer,
                           ULONG BufferSize)
{
    PNDIS_PACKET Packet;
    NDIS_STATUS Status;

    /* Allocate a packet descriptor */
    NdisAllocatePacket(&Status,
                       &Packet,
                       AdapterContext->PacketPoolHandle);
    if (Status != NDIS_STATUS_SUCCESS)
    {
        DPRINT1("No free packet descriptors\n");
        return NULL;
    }

    /* Use the helper to chain the buffer */
    Status = AllocateAndChainBuffer(AdapterContext, Packet,
                                    Buffer, BufferSize, TRUE);
    if (Status != NDIS_STATUS_SUCCESS)
    {
        NdisFreePacket(Packet);
        return NULL;
    }

    /* Return the packet */
    return Packet;
}

VOID
CleanupAndFreePacket(PNDIS_PACKET Packet, BOOLEAN FreePool)
{
    PNDIS_BUFFER Buffer;
    PVOID Data;
    ULONG Length;

    /* Free each buffer and its backing pool memory */
    while (TRUE)
    {
        /* Unchain each buffer */
        NdisUnchainBufferAtFront(Packet, &Buffer);
        if (!Buffer)
            break;
        
        /* Get the backing memory */
        NdisQueryBuffer(Buffer, &Data, &Length);
        
        /* Free the buffer */
        NdisFreeBuffer(Buffer);

        if (FreePool)
        {
            /* Free the backing memory */
            ExFreePool(Data);
        }
    }
    
    /* Free the packet descriptor */
    NdisFreePacket(Packet);
}

PNDISUIO_ADAPTER_CONTEXT
FindAdapterContextByName(PNDIS_STRING DeviceName)
{
    KIRQL OldIrql;
    PLIST_ENTRY CurrentEntry;
    PNDISUIO_ADAPTER_CONTEXT AdapterContext;

    KeAcquireSpinLock(&GlobalAdapterListLock, &OldIrql);
    CurrentEntry = GlobalAdapterList.Flink;
    while (CurrentEntry != &GlobalAdapterList)
    {
        AdapterContext = CONTAINING_RECORD(CurrentEntry, NDISUIO_ADAPTER_CONTEXT, ListEntry);
        
        /* Check if the device name matches */
        if (RtlEqualUnicodeString(&AdapterContext->DeviceName, DeviceName, TRUE))
        {
            KeReleaseSpinLock(&GlobalAdapterListLock, OldIrql);
            return AdapterContext;
        }
        
        CurrentEntry = CurrentEntry->Flink;
    }
    KeReleaseSpinLock(&GlobalAdapterListLock, OldIrql);
    
    return NULL;
}

VOID
ReferenceAdapterContext(PNDISUIO_ADAPTER_CONTEXT AdapterContext)
{
    /* Increment the open count */
    AdapterContext->OpenCount++;
}

VOID
DereferenceAdapterContextWithOpenEntry(PNDISUIO_ADAPTER_CONTEXT AdapterContext,
                                       PNDISUIO_OPEN_ENTRY OpenEntry)
{
    KIRQL OldIrql;

    /* Lock the adapter context */
    KeAcquireSpinLock(&AdapterContext->Spinlock, &OldIrql);
    
    /* Decrement the open count */
    AdapterContext->OpenCount--;

    /* Cleanup the open entry if we were given one */
    if (OpenEntry != NULL)
    {
        /* Remove the open entry */
        RemoveEntryList(&OpenEntry->ListEntry);

        /* Invalidate the FO */
        OpenEntry->FileObject->FsContext = NULL;
        OpenEntry->FileObject->FsContext2 = NULL;

        /* Free the open entry */
        ExFreePool(OpenEntry);
    }

    /* Release the adapter context lock */
    KeReleaseSpinLock(&AdapterContext->Spinlock, OldIrql);
}

