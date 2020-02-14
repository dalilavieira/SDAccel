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
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ ULONG_PTR ;
typedef  scalar_t__ UINT ;
typedef  int /*<<< orphan*/ **** PVOID ;
typedef  scalar_t__* PUINT ;
typedef  int /*<<< orphan*/ * PNDIS_PACKET ;
typedef  int /*<<< orphan*/ * PNDIS_BUFFER ;
typedef  int /*<<< orphan*/ **** PCHAR ;
typedef  scalar_t__ NDIS_STATUS ;
typedef  int INT ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG_PBUFFER ; 
 int /*<<< orphan*/  FreeNdisPacket (int /*<<< orphan*/ *) ; 
 scalar_t__ GlobalBufferPool ; 
 scalar_t__ GlobalPacketPool ; 
 int /*<<< orphan*/  LA_DbgPrint (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  NDIS_BUFFER_TAG ; 
 int /*<<< orphan*/  NDIS_PACKET_TAG ; 
 scalar_t__ NDIS_STATUS_NOT_ACCEPTED ; 
 scalar_t__ NDIS_STATUS_SUCCESS ; 
 int /*<<< orphan*/  NT_SUCCESS (scalar_t__) ; 
 int /*<<< orphan*/  NdisAllocateBuffer (scalar_t__*,int /*<<< orphan*/ **,scalar_t__,int /*<<< orphan*/ ****,scalar_t__) ; 
 int /*<<< orphan*/  NdisAllocateBufferPool (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  NdisAllocatePacket (scalar_t__*,int /*<<< orphan*/ **,scalar_t__) ; 
 int /*<<< orphan*/  NdisAllocatePacketPool (scalar_t__*,scalar_t__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NdisChainBufferAtFront (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NdisFreeBuffer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NdisFreeBufferPool (scalar_t__) ; 
 int /*<<< orphan*/  NdisFreePacket (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NdisFreePacketPool (scalar_t__) ; 
 int /*<<< orphan*/  NdisGetNextBuffer (int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  NdisQueryBuffer (int /*<<< orphan*/ *,int /*<<< orphan*/ *****,scalar_t__*) ; 
 int /*<<< orphan*/  NdisQueryPacket (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NonPagedPool ; 
 int /*<<< orphan*/  RtlCopyMemory (int /*<<< orphan*/ ****,int /*<<< orphan*/ ****,scalar_t__) ; 
 int /*<<< orphan*/  TrackWithTag (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ****,scalar_t__) ; 
 int /*<<< orphan*/  UntrackFL (int /*<<< orphan*/ ****,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ ****** exAllocatePool (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  exFreePool (int /*<<< orphan*/ ****) ; 

NDIS_STATUS InitNdisPools() {
    NDIS_STATUS NdisStatus;
    /* Last argument is extra space size */
    NdisAllocatePacketPool( &NdisStatus, &GlobalPacketPool, 100, 0 );
    if( !NT_SUCCESS(NdisStatus) ) return NdisStatus;

    NdisAllocateBufferPool( &NdisStatus, &GlobalBufferPool, 100 );
    if( !NT_SUCCESS(NdisStatus) )
	NdisFreePacketPool(GlobalPacketPool);

    return NdisStatus;
}

VOID CloseNdisPools() {
    if( GlobalPacketPool ) NdisFreePacketPool( GlobalPacketPool );
    if( GlobalBufferPool ) NdisFreeBufferPool( GlobalBufferPool );
}

__inline INT SkipToOffset(
    PNDIS_BUFFER Buffer,
    UINT Offset,
    PCHAR *Data,
    PUINT Size)
/*
 * FUNCTION: Skip Offset bytes into a buffer chain
 * ARGUMENTS:
 *     Buffer = Pointer to NDIS buffer
 *     Offset = Number of bytes to skip
 *     Data   = Address of a pointer that on return will contain the
 *              address of the offset in the buffer
 *     Size   = Address of a pointer that on return will contain the
 *              size of the destination buffer
 * RETURNS:
 *     Offset into buffer, -1 if buffer chain was smaller than Offset bytes
 * NOTES:
 *     Buffer may be NULL
 */
{
    for (;;) {

        if (!Buffer)
            return -1;

        NdisQueryBuffer(Buffer, (PVOID)Data, Size);

        if (Offset < *Size) {
            *Data = (PCHAR)((ULONG_PTR) *Data + Offset);
            *Size              -= Offset;
            break;
        }

        Offset -= *Size;

        NdisGetNextBuffer(Buffer, &Buffer);
    }

    return Offset;
}

void GetDataPtr( PNDIS_PACKET Packet,
		 UINT Offset,
		 PCHAR *DataOut,
		 PUINT Size ) {
    PNDIS_BUFFER Buffer;

    NdisQueryPacket(Packet, NULL, NULL, &Buffer, NULL);
    if( !Buffer ) return;
    SkipToOffset( Buffer, Offset, DataOut, Size );
}

NDIS_STATUS AllocatePacketWithBufferX( PNDIS_PACKET *NdisPacket,
				       PCHAR Data, UINT Len,
				       PCHAR File, UINT Line ) {
    PNDIS_PACKET Packet;
    PNDIS_BUFFER Buffer;
    NDIS_STATUS Status;
    PCHAR NewData;

    NewData = exAllocatePool( NonPagedPool, Len );
    if( !NewData ) return NDIS_STATUS_NOT_ACCEPTED; // XXX

    if( Data )
	RtlCopyMemory(NewData, Data, Len);

    NdisAllocatePacket( &Status, &Packet, GlobalPacketPool );
    if( Status != NDIS_STATUS_SUCCESS ) {
	exFreePool( NewData );
	return Status;
    }
    TrackWithTag(NDIS_PACKET_TAG, Packet, File, Line);

    NdisAllocateBuffer( &Status, &Buffer, GlobalBufferPool, NewData, Len );
    if( Status != NDIS_STATUS_SUCCESS ) {
	exFreePool( NewData );
	FreeNdisPacket( Packet );
    }
    TrackWithTag(NDIS_BUFFER_TAG, Buffer, File, Line);

    NdisChainBufferAtFront( Packet, Buffer );
    *NdisPacket = Packet;

    return NDIS_STATUS_SUCCESS;
}

VOID FreeNdisPacketX
( PNDIS_PACKET Packet,
  PCHAR File,
  UINT Line )
/*
 * FUNCTION: Frees an NDIS packet
 * ARGUMENTS:
 *     Packet = Pointer to NDIS packet to be freed
 */
{
    PNDIS_BUFFER Buffer, NextBuffer;

    LA_DbgPrint(DEBUG_PBUFFER, ("Packet (0x%X)\n", Packet));

    /* Free all the buffers in the packet first */
    NdisQueryPacket(Packet, NULL, NULL, &Buffer, NULL);
    for (; Buffer != NULL; Buffer = NextBuffer) {
        PVOID Data;
        UINT Length;

        NdisGetNextBuffer(Buffer, &NextBuffer);
        NdisQueryBuffer(Buffer, &Data, &Length);
        NdisFreeBuffer(Buffer);
	UntrackFL(File,Line,Buffer);
        exFreePool(Data);
    }

    /* Finally free the NDIS packet descriptor */
    NdisFreePacket(Packet);
    UntrackFL(File,Line,Packet);
}

