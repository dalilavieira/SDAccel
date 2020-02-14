#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  acrFirmware ;
typedef  int UINT16 ;
struct TYPE_14__ {scalar_t__ hCard; } ;
struct TYPE_11__ {int SEL_RES; int /*<<< orphan*/  ATSLength; int /*<<< orphan*/  ATS; int /*<<< orphan*/  NFCIDLength; int /*<<< orphan*/  NFCID1; int /*<<< orphan*/  SENS_RES; } ;
struct TYPE_12__ {TYPE_1__ TypeA; } ;
struct TYPE_13__ {int BrTy; TYPE_2__ Target; int /*<<< orphan*/  Tg; } ;
typedef  TYPE_3__* PPN532_TARGET ;
typedef  int /*<<< orphan*/ * PBYTE ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  scalar_t__ LONG ;
typedef  int BYTE ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int ARRAYSIZE (char**) ; 
 int /*<<< orphan*/  FALSE ; 
 char** KUHL_M_ACR_FIRMWARE_PN532_SUPPORT ; 
 char** KUHL_M_ACR_PN532_BrTy ; 
 int /*<<< orphan*/  LocalFree (TYPE_3__*) ; 
 int /*<<< orphan*/  PRINT_ERROR (char*) ; 
 int /*<<< orphan*/  SCARD_SCOPE_SYSTEM ; 
 scalar_t__ SCARD_S_SUCCESS ; 
 scalar_t__ SCardEstablishContext (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__*) ; 
 int /*<<< orphan*/  SCardReleaseContext (scalar_t__) ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  kprintf (char*,...) ; 
 TYPE_4__ kuhl_m_acr_Comm ; 
 int /*<<< orphan*/  kuhl_m_acr_close (int,int /*<<< orphan*/ **) ; 
 scalar_t__ kuhl_m_acr_hContext ; 
 int /*<<< orphan*/  kuhl_m_acr_pn532Comm ; 
 int /*<<< orphan*/  kull_m_acr_finish (TYPE_4__*) ; 
 scalar_t__ kull_m_acr_init (scalar_t__,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_4__*) ; 
 scalar_t__ kull_m_acr_sendrecv_ins (TYPE_4__*,int,int,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kull_m_arcr_SendRecvDirect ; 
 scalar_t__ kull_m_pn532_GetFirmware (int /*<<< orphan*/ *,int*) ; 
 scalar_t__ kull_m_pn532_InListPassiveTarget (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*,TYPE_3__**) ; 
 int /*<<< orphan*/  kull_m_pn532_InRelease (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kull_m_pn532_init (int /*<<< orphan*/ ,TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kull_m_string_args_byName (int,int /*<<< orphan*/ **,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kull_m_string_wprintf_hex (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

NTSTATUS kuhl_m_acr_init()
{
	kuhl_m_acr_hContext = 0;
	kuhl_m_acr_Comm.hCard = 0;
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_acr_clean()
{
	kuhl_m_acr_close(0, NULL);
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_acr_open(int argc, wchar_t * argv[])
{
	LONG scStatus;
	BOOL isTrace = kull_m_string_args_byName(argc, argv, L"trace", NULL, NULL);

	if(!kuhl_m_acr_hContext)
	{
		scStatus = SCardEstablishContext(SCARD_SCOPE_SYSTEM, NULL, NULL, &kuhl_m_acr_hContext);
		if(scStatus == SCARD_S_SUCCESS)
		{
			kprintf(L"Opening ACR  : ");
			if(kull_m_acr_init(kuhl_m_acr_hContext, L"ACS ACR122 0", TRUE, NULL, isTrace, &kuhl_m_acr_Comm))
			{
				kprintf(L"OK!\nOpening PN532: ");
				kull_m_pn532_init(kull_m_arcr_SendRecvDirect, &kuhl_m_acr_Comm, isTrace, &kuhl_m_acr_pn532Comm);
				kprintf(L"OK!\n");
			}
			else kuhl_m_acr_close(0, NULL);
		}
	}
	else PRINT_ERROR(L"Already opened, close it first\n");
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_acr_close(int argc, wchar_t * argv[])
{
	kull_m_acr_finish(&kuhl_m_acr_Comm);
	if(kuhl_m_acr_hContext)
	{
		SCardReleaseContext(kuhl_m_acr_hContext);
		kuhl_m_acr_hContext = 0;
	}
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_acr_firmware(int argc, wchar_t * argv[])
{
	BYTE acrFirmware[10];
	BYTE firmwareInfo[4], i;
	UINT16 wOut = sizeof(acrFirmware);

	if(kull_m_acr_sendrecv_ins(&kuhl_m_acr_Comm, 0xff, 0x00, 0x48, 0x00, NULL, 0, acrFirmware, &wOut, FALSE))
		kprintf(L"ACR firmware: %.*S\n", wOut, acrFirmware);
	
	if(kull_m_pn532_GetFirmware(&kuhl_m_acr_pn532Comm, firmwareInfo))
	{
		kprintf(L"PN532 chip\n version    : 0x%02x\n firmware   : %hhu.%hhu\n support    : ", firmwareInfo[0], firmwareInfo[1], firmwareInfo[2]);
		for(i = 0; i < 8; i++)
			if((firmwareInfo[3] >> i) & 1)
				kprintf(L"%s ; ", (i < ARRAYSIZE(KUHL_M_ACR_FIRMWARE_PN532_SUPPORT)) ? KUHL_M_ACR_FIRMWARE_PN532_SUPPORT[i] : L"RFU");
		kprintf(L"\n");
	}
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_acr_info(int argc, wchar_t * argv[])
{
	BYTE i, NbTg;
	PPN532_TARGET pTargets;

	kull_m_pn532_InRelease(&kuhl_m_acr_pn532Comm, 0);
	if(kull_m_pn532_InListPassiveTarget(&kuhl_m_acr_pn532Comm, 2, 0 /* Type A */, NULL, 0, &NbTg, &pTargets))
	{
		for(i = 0; i < NbTg; i++)
		{
			kprintf(L"\nTarget: %hhu (0x%02x - %s)\n", pTargets[i].Tg, pTargets[i].BrTy, (pTargets[i].BrTy < ARRAYSIZE(KUHL_M_ACR_PN532_BrTy)) ? KUHL_M_ACR_PN532_BrTy[pTargets[i].BrTy] : L"?");
			switch(pTargets[i].BrTy)
			{
			case 0:
				kprintf(L"  SENS_RES: %02x %02x\n  SEL_RES : %02x\n    UID %scomplete\n    PICC %scompliant with ISO/IEC 14443-4\n    PICC %scompliant with ISO/IEC 18092 (NFC)\n",
					((PBYTE) &pTargets[i].Target.TypeA.SENS_RES)[0], ((PBYTE) &pTargets[i].Target.TypeA.SENS_RES)[1], pTargets[i].Target.TypeA.SEL_RES, (pTargets[i].Target.TypeA.SEL_RES & 0x04) ? L"NOT " : L"", (pTargets[i].Target.TypeA.SEL_RES & 0x20) ? L"" : L"NOT ", (pTargets[i].Target.TypeA.SEL_RES & 0x40) ? L"" : L"NOT ");
				if(pTargets[i].Target.TypeA.NFCIDLength && pTargets[i].Target.TypeA.NFCID1)
				{
					kprintf(L"  NFCID1  : ");
					kull_m_string_wprintf_hex(pTargets[i].Target.TypeA.NFCID1, pTargets[i].Target.TypeA.NFCIDLength, 1);
					kprintf(L"\n");
				}
				if(pTargets[i].Target.TypeA.ATSLength && pTargets[i].Target.TypeA.ATS)
				{
					kprintf(L"  ATS     : ");
					kull_m_string_wprintf_hex(pTargets[i].Target.TypeA.ATS, pTargets[i].Target.TypeA.ATSLength, 1);
					kprintf(L"\n");
				}
				break;
			default:
				PRINT_ERROR(L"Only BrTy = 0 (TypeA) at this time\n");
			}
		}
		LocalFree(pTargets);
	}
	kull_m_pn532_InRelease(&kuhl_m_acr_pn532Comm, 0);
	return STATUS_SUCCESS;
}

