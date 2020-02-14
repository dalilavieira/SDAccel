#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  int ULONG ;
struct TYPE_9__ {int Type; int /*<<< orphan*/  (* Free ) (TYPE_1__*) ;struct TYPE_9__* Header; int /*<<< orphan*/  MappedHeader; int /*<<< orphan*/ * NdisPacket; scalar_t__ ReturnPacket; } ;
typedef  TYPE_1__* PVOID ;
typedef  TYPE_1__* PIP_PACKET ;
typedef  int /*<<< orphan*/  IP_PACKET ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FreeNdisPacket (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IP_INTERFACE_TAG ; 
 int /*<<< orphan*/  MAX_TRACE ; 
 int /*<<< orphan*/  NdisReturnPackets (int /*<<< orphan*/ **,int) ; 
 int /*<<< orphan*/  PACKET_BUFFER_TAG ; 
 int /*<<< orphan*/  RtlZeroMemory (TYPE_1__*,int) ; 
 int /*<<< orphan*/  TI_DbgPrint (int /*<<< orphan*/ ,char*) ; 

VOID DeinitializePacket(
    PVOID Object)
/*
 * FUNCTION: Frees buffers attached to the packet
 * ARGUMENTS:
 *     Object = Pointer to an IP packet structure
 */
{
    PIP_PACKET IPPacket = Object;

    TI_DbgPrint(MAX_TRACE, ("Freeing object: 0x%p\n", Object));

    /* Detect double free */
    ASSERT(IPPacket->Type != 0xFF);
    IPPacket->Type = 0xFF;

    /* Check if there's a packet to free */
    if (IPPacket->NdisPacket != NULL)
    {
        if (IPPacket->ReturnPacket)
        {
            /* Return the packet to the miniport driver */
            TI_DbgPrint(MAX_TRACE, ("Returning packet 0x%p\n",
                                    IPPacket->NdisPacket));
            NdisReturnPackets(&IPPacket->NdisPacket, 1);
        }
        else
        {
            /* Free it the conventional way */
            TI_DbgPrint(MAX_TRACE, ("Freeing packet 0x%p\n",
                                    IPPacket->NdisPacket));
            FreeNdisPacket(IPPacket->NdisPacket);
        }
    }

    /* Check if we have a pool-allocated header */
    if (!IPPacket->MappedHeader && IPPacket->Header)
    {
        /* Free it */
        TI_DbgPrint(MAX_TRACE, ("Freeing header: 0x%p\n",
                                IPPacket->Header));
        ExFreePoolWithTag(IPPacket->Header,
                          PACKET_BUFFER_TAG);
    }
}

VOID FreeIF(
    PVOID Object)
/*
 * FUNCTION: Frees an interface object
 * ARGUMENTS:
 *     Object = Pointer to an interface structure
 */
{
    ExFreePoolWithTag(Object, IP_INTERFACE_TAG);
}

PIP_PACKET IPInitializePacket(
    PIP_PACKET IPPacket,
    ULONG Type)
/*
 * FUNCTION: Creates an IP packet object
 * ARGUMENTS:
 *     Type = Type of IP packet
 * RETURNS:
 *     Pointer to the created IP packet. NULL if there was not enough free resources.
 */
{
    RtlZeroMemory(IPPacket, sizeof(IP_PACKET));

    IPPacket->Free     = DeinitializePacket;
    IPPacket->Type     = Type;

    return IPPacket;
}

