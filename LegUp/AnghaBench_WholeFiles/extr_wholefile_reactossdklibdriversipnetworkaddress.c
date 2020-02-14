#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  int ULONG ;
typedef  scalar_t__ UINT ;
struct TYPE_27__ {int IPv4Address; } ;
struct TYPE_26__ {int Type; TYPE_5__ Address; } ;
struct TYPE_25__ {int AddressType; scalar_t__ AddressLength; scalar_t__ Address; } ;
struct TYPE_24__ {int /*<<< orphan*/  sin_port; int /*<<< orphan*/  in_addr; } ;
struct TYPE_23__ {int TAAddressCount; TYPE_3__* Address; } ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  int /*<<< orphan*/ * PUSHORT ;
typedef  TYPE_1__* PTRANSPORT_ADDRESS ;
typedef  TYPE_2__* PTDI_ADDRESS_IP ;
typedef  TYPE_3__* PTA_ADDRESS ;
typedef  TYPE_4__* PIP_ADDRESS ;
typedef  int /*<<< orphan*/  PCHAR ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int /*<<< orphan*/  IPv6_RAW_ADDRESS ;
typedef  scalar_t__ IPv4_RAW_ADDRESS ;
typedef  int INT ;
typedef  int BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  A2SStr ; 
 int /*<<< orphan*/  AddrInitIPv4 (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DEBUG_DATALINK ; 
 int DN2H (int) ; 
 int /*<<< orphan*/  DbgPrint (char*) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int FALSE ; 
 int /*<<< orphan*/  IP_ADDRESS_TAG ; 
#define  IP_ADDRESS_V4 130 
#define  IP_ADDRESS_V6 129 
 int /*<<< orphan*/  MID_TRACE ; 
 int /*<<< orphan*/  MIN_TRACE ; 
 int RtlCompareMemory (TYPE_5__*,TYPE_5__*,int) ; 
 int /*<<< orphan*/  STATUS_INVALID_ADDRESS ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 scalar_t__ TDI_ADDRESS_LENGTH_IP ; 
#define  TDI_ADDRESS_TYPE_IP 128 
 int /*<<< orphan*/  TI_DbgPrint (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,int,int,int,int) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 

PCHAR A2S(
    PIP_ADDRESS Address)
/*
 * FUNCTION: Convert an IP address to a string (for debugging)
 * ARGUMENTS:
 *     Address = Pointer to an IP address structure
 * RETURNS:
 *     Pointer to buffer with string representation of IP address
 */
{
    ULONG ip;
    PCHAR p;

    p = A2SStr;

    if (!Address) {
        TI_DbgPrint(MIN_TRACE, ("NULL address given.\n"));
        strcpy(p, "(NULL)");
        return p;
    }

    switch (Address->Type) {
    case IP_ADDRESS_V4:
	ip = DN2H(Address->Address.IPv4Address);
	sprintf(p, "%d.%d.%d.%d",
		(INT)((ip >> 24) & 0xFF),
		(INT)((ip >> 16) & 0xFF),
		(INT)((ip >> 8) & 0xFF),
		(INT)(ip & 0xFF));
	break;

    case IP_ADDRESS_V6:
	/* FIXME: IPv6 is not supported */
	strcpy(p, "(IPv6 address not supported)");
	break;
    }
    return p;
}

ULONG IPv4NToHl( ULONG Address ) {
    return
	((Address & 0xff) << 24) |
	((Address & 0xff00) << 8) |
	((Address >> 8) & 0xff00) |
	((Address >> 24) & 0xff);
}

UINT AddrCountPrefixBits( PIP_ADDRESS Netmask ) {
    UINT Prefix = 0;
    if( Netmask->Type == IP_ADDRESS_V4 ) {
	ULONG BitTest = 0x80000000;

	/* The mask has been read in network order.  Put it in host order
	 * in order to scan it. */

	ULONG TestMask = IPv4NToHl(Netmask->Address.IPv4Address);

	while( (BitTest & TestMask) == BitTest ) {
	    Prefix++;
	    BitTest >>= 1;
	}
	return Prefix;
    } else {
	TI_DbgPrint(DEBUG_DATALINK, ("Don't know address type %d\n",
				     Netmask->Type));
	return 0;
    }
}

VOID AddrWidenAddress( PIP_ADDRESS Network, PIP_ADDRESS Source,
		       PIP_ADDRESS Netmask ) {
    if( Netmask->Type == IP_ADDRESS_V4 ) {
        Network->Type = Netmask->Type;
	Network->Address.IPv4Address =
	    Source->Address.IPv4Address & Netmask->Address.IPv4Address;
    } else {
	TI_DbgPrint(DEBUG_DATALINK, ("Don't know address type %d\n",
				     Netmask->Type));
	*Network = *Source;
    }
}

VOID IPAddressFree(
    PVOID Object)
/*
 * FUNCTION: Frees an IP_ADDRESS object
 * ARGUMENTS:
 *     Object = Pointer to an IP address structure
 * RETURNS:
 *     Nothing
 */
{
    ExFreePoolWithTag(Object, IP_ADDRESS_TAG);
}

BOOLEAN AddrIsUnspecified(
    PIP_ADDRESS Address)
/*
 * FUNCTION: Return wether IP address is an unspecified address
 * ARGUMENTS:
 *     Address = Pointer to an IP address structure
 * RETURNS:
 *     TRUE if the IP address is an unspecified address, FALSE if not
 */
{
    switch (Address->Type) {
        case IP_ADDRESS_V4:
            return (Address->Address.IPv4Address == 0 ||
                    Address->Address.IPv4Address == 0xFFFFFFFF);

        case IP_ADDRESS_V6:
        /* FIXME: IPv6 is not supported */
        default:
            return FALSE;
    }
}

NTSTATUS AddrGetAddress(
    PTRANSPORT_ADDRESS AddrList,
    PIP_ADDRESS Address,
    PUSHORT Port)
{
    PTA_ADDRESS CurAddr;
    INT i;

    /* We can only use IP addresses. Search the list until we find one */
    CurAddr = AddrList->Address;

    for (i = 0; i < AddrList->TAAddressCount; i++) {
        switch (CurAddr->AddressType) {
        case TDI_ADDRESS_TYPE_IP:
            if (CurAddr->AddressLength >= TDI_ADDRESS_LENGTH_IP) {
                /* This is an IPv4 address */
                PTDI_ADDRESS_IP ValidAddr = (PTDI_ADDRESS_IP)CurAddr->Address;
                *Port = ValidAddr->sin_port;
		Address->Type = CurAddr->AddressType;
		ValidAddr = (PTDI_ADDRESS_IP)CurAddr->Address;
		AddrInitIPv4(Address, ValidAddr->in_addr);
		return STATUS_SUCCESS;
	    }
	}
    }

    return STATUS_INVALID_ADDRESS;
}

NTSTATUS AddrBuildAddress(
    PTRANSPORT_ADDRESS TaAddress,
    PIP_ADDRESS Address,
    PUSHORT Port)
{
  PTDI_ADDRESS_IP ValidAddr;
  PTA_ADDRESS TdiAddress = &TaAddress->Address[0];

  if (TdiAddress->AddressType != TDI_ADDRESS_TYPE_IP) {
      TI_DbgPrint
	  (MID_TRACE,("AddressType %x, Not valid\n", TdiAddress->AddressType));
    return STATUS_INVALID_ADDRESS;
  }
  if (TdiAddress->AddressLength < TDI_ADDRESS_LENGTH_IP) {
      TI_DbgPrint
	  (MID_TRACE,("AddressLength %x, Not valid (expected %x)\n",
		      TdiAddress->AddressLength, TDI_ADDRESS_LENGTH_IP));
      return STATUS_INVALID_ADDRESS;
  }


  ValidAddr = (PTDI_ADDRESS_IP)TdiAddress->Address;

  AddrInitIPv4(Address, ValidAddr->in_addr);
  *Port = ValidAddr->sin_port;

  return STATUS_SUCCESS;
}

BOOLEAN AddrIsEqual(
    PIP_ADDRESS Address1,
    PIP_ADDRESS Address2)
{
    if (Address1->Type != Address2->Type) {
        DbgPrint("AddrIsEqual: Unequal Address Types\n");
        return FALSE;
    }

    switch (Address1->Type) {
        case IP_ADDRESS_V4:
            return (Address1->Address.IPv4Address == Address2->Address.IPv4Address);

        case IP_ADDRESS_V6:
            return (RtlCompareMemory(&Address1->Address, &Address2->Address,
                sizeof(IPv6_RAW_ADDRESS)) == sizeof(IPv6_RAW_ADDRESS));
            break;

        default:
            DbgPrint("AddrIsEqual: Bad address type\n");
            break;
    }

    return FALSE;
}

INT AddrCompare(
    PIP_ADDRESS Address1,
    PIP_ADDRESS Address2)
{
    switch (Address1->Type) {
        case IP_ADDRESS_V4: {
            ULONG Addr1, Addr2;
            if (Address2->Type == IP_ADDRESS_V4) {
                Addr1 = DN2H(Address1->Address.IPv4Address);
                Addr2 = DN2H(Address2->Address.IPv4Address);
                if (Addr1 < Addr2)
                    return -1;
                else
                    if (Addr1 == Addr2)
                        return 0;
                    else
                        return 1;
            } else
                /* FIXME: Support IPv6 */
                return -1;

        case IP_ADDRESS_V6:
            /* FIXME: Support IPv6 */
        break;
        }
    }

    return FALSE;
}

BOOLEAN AddrIsEqualIPv4(
    PIP_ADDRESS Address1,
    IPv4_RAW_ADDRESS Address2)
{
    if (Address1->Type == IP_ADDRESS_V4)
        return (Address1->Address.IPv4Address == Address2);

    return FALSE;
}

