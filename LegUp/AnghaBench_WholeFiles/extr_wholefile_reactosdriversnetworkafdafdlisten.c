#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_9__ ;
typedef  struct TYPE_35__   TYPE_8__ ;
typedef  struct TYPE_34__   TYPE_7__ ;
typedef  struct TYPE_33__   TYPE_6__ ;
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;
typedef  struct TYPE_27__   TYPE_11__ ;
typedef  struct TYPE_26__   TYPE_10__ ;

/* Type definitions */
struct TYPE_36__ {TYPE_2__* ConnInfo; int /*<<< orphan*/  Seq; int /*<<< orphan*/  Object; } ;
struct TYPE_35__ {TYPE_11__* FsContext; } ;
struct TYPE_32__ {int /*<<< orphan*/  Status; scalar_t__ Information; } ;
struct TYPE_28__ {int /*<<< orphan*/  SystemBuffer; } ;
struct TYPE_34__ {TYPE_5__ IoStatus; scalar_t__ MdlAddress; TYPE_1__ AssociatedIrp; } ;
struct TYPE_33__ {TYPE_4__* Address; int /*<<< orphan*/  TAAddressCount; } ;
struct TYPE_31__ {TYPE_3__* Address; int /*<<< orphan*/  AddressLength; int /*<<< orphan*/  AddressType; } ;
struct TYPE_30__ {int /*<<< orphan*/  in_addr; int /*<<< orphan*/  sin_port; } ;
struct TYPE_29__ {int /*<<< orphan*/  RemoteAddress; } ;
struct TYPE_27__ {scalar_t__ RemoteAddress; int /*<<< orphan*/  ConnectReturnInfo; int /*<<< orphan*/  ConnectCallInfo; int /*<<< orphan*/  Connection; } ;
struct TYPE_26__ {int /*<<< orphan*/  Address; int /*<<< orphan*/  SequenceNumber; } ;
typedef  TYPE_6__* PTA_IP_ADDRESS ;
typedef  TYPE_7__* PIRP ;
typedef  TYPE_8__* PFILE_OBJECT ;
typedef  scalar_t__ PCHAR ;
typedef  TYPE_9__* PAFD_TDI_OBJECT_QELT ;
typedef  TYPE_10__* PAFD_RECEIVED_ACCEPT_DATA ;
typedef  TYPE_11__* PAFD_FCB ;
typedef  int /*<<< orphan*/  PAFD_DEVICE_EXTENSION ;
typedef  int /*<<< orphan*/  NTSTATUS ;

/* Variables and functions */
 int /*<<< orphan*/  AFD_DbgPrint (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IO_NETWORK_INCREMENT ; 
 int /*<<< orphan*/  IoCompleteRequest (TYPE_7__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IoGetCurrentIrpStackLocation (TYPE_7__*) ; 
 int /*<<< orphan*/  IoSetCancelRoutine (TYPE_7__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LostSocket (TYPE_7__*) ; 
 int /*<<< orphan*/  MID_TRACE ; 
 int /*<<< orphan*/  MakeSocketIntoConnection (TYPE_11__*) ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STATUS_NO_MEMORY ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  SocketAcquireStateLock (TYPE_11__*) ; 
 int /*<<< orphan*/  TAG_AFD_TRANSPORT_ADDRESS ; 
 scalar_t__ TaCopyTransportAddress (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TaCopyTransportAddressInPlace (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TdiBuildConnectionInfo (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  UNREFERENCED_PARAMETER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UnlockAndMaybeComplete (TYPE_11__*,int /*<<< orphan*/ ,TYPE_7__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UnlockRequest (TYPE_7__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static NTSTATUS SatisfyAccept( PAFD_DEVICE_EXTENSION DeviceExt,
                               PIRP Irp,
                               PFILE_OBJECT NewFileObject,
                               PAFD_TDI_OBJECT_QELT Qelt ) {
    PAFD_FCB FCB = NewFileObject->FsContext;
    NTSTATUS Status;

    UNREFERENCED_PARAMETER(DeviceExt);

    if( !SocketAcquireStateLock( FCB ) )
        return LostSocket( Irp );

    /* Transfer the connection to the new socket, launch the opening read */
    AFD_DbgPrint(MID_TRACE,("Completing a real accept (FCB %p)\n", FCB));

    FCB->Connection = Qelt->Object;

    if (FCB->RemoteAddress)
    {
        ExFreePoolWithTag(FCB->RemoteAddress, TAG_AFD_TRANSPORT_ADDRESS);
    }

    FCB->RemoteAddress =
        TaCopyTransportAddress( Qelt->ConnInfo->RemoteAddress );

    if( !FCB->RemoteAddress )
        Status = STATUS_NO_MEMORY;
    else
        Status = MakeSocketIntoConnection( FCB );

    if (NT_SUCCESS(Status))
        Status = TdiBuildConnectionInfo(&FCB->ConnectCallInfo, FCB->RemoteAddress);

    if (NT_SUCCESS(Status))
        Status = TdiBuildConnectionInfo(&FCB->ConnectReturnInfo, FCB->RemoteAddress);

    return UnlockAndMaybeComplete( FCB, Status, Irp, 0 );
}

__attribute__((used)) static NTSTATUS SatisfyPreAccept( PIRP Irp, PAFD_TDI_OBJECT_QELT Qelt ) {
    PAFD_RECEIVED_ACCEPT_DATA ListenReceive =
        (PAFD_RECEIVED_ACCEPT_DATA)Irp->AssociatedIrp.SystemBuffer;
    PTA_IP_ADDRESS IPAddr;

    ListenReceive->SequenceNumber = Qelt->Seq;

    AFD_DbgPrint(MID_TRACE,("Giving SEQ %u to userland\n", Qelt->Seq));
    AFD_DbgPrint(MID_TRACE,("Socket Address (K) %p (U) %p\n",
                            &ListenReceive->Address,
                            Qelt->ConnInfo->RemoteAddress));

    TaCopyTransportAddressInPlace( &ListenReceive->Address,
                                   Qelt->ConnInfo->RemoteAddress );

    IPAddr = (PTA_IP_ADDRESS)&ListenReceive->Address;

    AFD_DbgPrint(MID_TRACE,("IPAddr->TAAddressCount %d\n",
                            IPAddr->TAAddressCount));
    AFD_DbgPrint(MID_TRACE,("IPAddr->Address[0].AddressType %u\n",
                            IPAddr->Address[0].AddressType));
    AFD_DbgPrint(MID_TRACE,("IPAddr->Address[0].AddressLength %u\n",
                            IPAddr->Address[0].AddressLength));
    AFD_DbgPrint(MID_TRACE,("IPAddr->Address[0].Address[0].sin_port %x\n",
                            IPAddr->Address[0].Address[0].sin_port));
    AFD_DbgPrint(MID_TRACE,("IPAddr->Address[0].Address[0].sin_addr %x\n",
                            IPAddr->Address[0].Address[0].in_addr));

    if( Irp->MdlAddress ) UnlockRequest( Irp, IoGetCurrentIrpStackLocation( Irp ) );

    Irp->IoStatus.Information = ((PCHAR)&IPAddr[1]) - ((PCHAR)ListenReceive);
    Irp->IoStatus.Status = STATUS_SUCCESS;
    (void)IoSetCancelRoutine(Irp, NULL);
    IoCompleteRequest( Irp, IO_NETWORK_INCREMENT );
    return STATUS_SUCCESS;
}

