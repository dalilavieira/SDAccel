#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UINT16 ;
struct TYPE_6__ {int withoutCard; int descr; scalar_t__ hCard; int /*<<< orphan*/  suppdata; } ;
typedef  int /*<<< orphan*/  SCARDCONTEXT ;
typedef  TYPE_1__* PKULL_M_ACR_COMM ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  scalar_t__ LONG ;
typedef  scalar_t__ DWORD ;
typedef  int BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ const ACR_MAX_LEN ; 
 int FALSE ; 
 int /*<<< orphan*/  IOCTL_CCID_ESCAPE ; 
 int /*<<< orphan*/  PRINT_ERROR (char*,...) ; 
 int /*<<< orphan*/  RtlCopyMemory (int*,int const*,scalar_t__ const) ; 
 int /*<<< orphan*/  SCARD_LEAVE_CARD ; 
 int /*<<< orphan*/  SCARD_PROTOCOL_Tx ; 
 int /*<<< orphan*/  SCARD_PROTOCOL_UNDEFINED ; 
 int /*<<< orphan*/  SCARD_SHARE_DIRECT ; 
 int /*<<< orphan*/  SCARD_SHARE_SHARED ; 
 scalar_t__ SCARD_S_SUCCESS ; 
 scalar_t__ SCardConnect (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,scalar_t__*) ; 
 scalar_t__ SCardControl (scalar_t__,int /*<<< orphan*/ ,int const*,scalar_t__ const,int*,scalar_t__,scalar_t__*) ; 
 scalar_t__ SCardDisconnect (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ SCardTransmit (scalar_t__,int /*<<< orphan*/ *,int const*,scalar_t__ const,int /*<<< orphan*/ *,int*,scalar_t__*) ; 
 int /*<<< orphan*/  kprintf (char*) ; 
 int /*<<< orphan*/  kull_m_string_wprintf_hex (int const*,scalar_t__ const,int) ; 

BOOL kull_m_acr_init(SCARDCONTEXT hContext, LPCWSTR szReaderName, BOOL withoutCard, LPVOID suppdata, BOOL descr, PKULL_M_ACR_COMM comm)
{
	BOOL status = FALSE;
	DWORD dwActiveProtocol;
	LONG scStatus;
	comm->hCard = 0;
	comm->withoutCard = withoutCard;
	comm->suppdata = suppdata;
	comm->descr = descr;
	scStatus = SCardConnect(hContext, szReaderName, withoutCard ? SCARD_SHARE_DIRECT : SCARD_SHARE_SHARED, withoutCard ? SCARD_PROTOCOL_UNDEFINED : SCARD_PROTOCOL_Tx, &comm->hCard, &dwActiveProtocol);
	if(!(status = (scStatus == SCARD_S_SUCCESS)))
		PRINT_ERROR(L"SCardConnect: 0x%08x\n", scStatus);
	return status;
}

void kull_m_acr_finish(PKULL_M_ACR_COMM comm)
{
	LONG scStatus;
	if(comm->hCard)
	{
		scStatus = SCardDisconnect(comm->hCard, SCARD_LEAVE_CARD);
		if(scStatus == SCARD_S_SUCCESS)
			comm->hCard = 0;
		else PRINT_ERROR(L"SCardDisconnect: 0x%08x\n", scStatus);
	}
}

BOOL kull_m_arc_sendrecv(PKULL_M_ACR_COMM comm, const BYTE *pbData, const UINT16 cbData, BYTE *pbResult, UINT16 *cbResult)
{
	BOOL status = FALSE;
	LONG scStatus;
	DWORD ret = *cbResult;

	if(comm->hCard)
	{
		if(cbData <= ACR_MAX_LEN)
		{
			if(comm->descr)
			{
				kprintf(L"ACR  > ");
				kull_m_string_wprintf_hex(pbData, cbData, 1);
				kprintf(L"\n");
			}
			scStatus = comm->withoutCard ?
				SCardControl(comm->hCard, IOCTL_CCID_ESCAPE, pbData, cbData, pbResult, *cbResult, &ret) :
				SCardTransmit(comm->hCard, NULL, pbData, cbData, NULL, pbResult, &ret);

			if(scStatus == SCARD_S_SUCCESS)
			{
				if(comm->descr)
				{
					kprintf(L"ACR  < ");
					kull_m_string_wprintf_hex(pbResult, ret, 1);
					kprintf(L"\n");
				}
				if(status = (ret <= *cbResult))
					*cbResult = (UINT16) ret;
			}
			else PRINT_ERROR(L"%s: 0x%08x\n", comm->withoutCard ? L"SCardControl" : L"SCardTransmit", scStatus);
		}
		else PRINT_ERROR(L"cbData = %hu / cbResult = %hu (max is %hu)\n", cbData, cbResult, ACR_MAX_LEN);
	}
	else PRINT_ERROR(L"No handle to Card\n");
	return status;
}

BOOL kull_m_acr_sendrecv_ins(PKULL_M_ACR_COMM comm, BYTE cla, BYTE ins, BYTE p1, BYTE p2, const BYTE *pbData, const UINT16 cbData, BYTE *pbResult, UINT16 *cbResult, BOOL noLe)
{
	BOOL status = FALSE;
	BYTE buffer[ACR_MAX_LEN], idx = 4;
	//BYTE max = sizeof(buffer) - idx -
	// CHECK SIZES !
	buffer[0] = cla;
	buffer[1] = ins;
	buffer[2] = p1;
	buffer[3] = p2;

	if(cbData)
	{
		buffer[idx++] = (BYTE) cbData;
		RtlCopyMemory(buffer + idx, pbData, cbData);
		idx += cbData;
	}
	if(!noLe && *cbResult)
		buffer[idx++] = (BYTE) *cbResult;
	return kull_m_arc_sendrecv(comm, buffer, idx, pbResult, cbResult);
}

