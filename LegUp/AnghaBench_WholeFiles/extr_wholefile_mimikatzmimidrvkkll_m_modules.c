#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_7__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ULONG_PTR ;
typedef  int ULONG ;
struct TYPE_32__ {scalar_t__ size; scalar_t__ addr; } ;
struct TYPE_28__ {TYPE_2__* ImageBase; } ;
struct TYPE_31__ {scalar_t__ ImageSize; scalar_t__ FullPathName; scalar_t__ FileNameOffset; TYPE_1__ BasicInfo; } ;
struct TYPE_30__ {scalar_t__ addr; void* isFound; } ;
struct TYPE_29__ {scalar_t__ member_1; int /*<<< orphan*/  isFound; void* member_0; } ;
typedef  int /*<<< orphan*/  SIZE_T ;
typedef  TYPE_2__* PVOID ;
typedef  scalar_t__ PUCHAR ;
typedef  TYPE_3__* PKKLL_M_MODULE_FROM_ADDR ;
typedef  int /*<<< orphan*/  (* PKKLL_M_MODULE_CALLBACK ) (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ,TYPE_5__*,TYPE_2__*,void**) ;
typedef  TYPE_7__* PKKLL_M_MODULE_BASIC_INFOS ;
typedef  int /*<<< orphan*/  PKIWI_BUFFER ;
typedef  TYPE_5__* PAUX_MODULE_EXTENDED_INFO ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  TYPE_2__ KKLL_M_MODULE_FROM_ADDR ;
typedef  void* BOOLEAN ;
typedef  int /*<<< orphan*/  AUX_MODULE_EXTENDED_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  AuxKlibQueryModuleInformation (int*,int,TYPE_5__*) ; 
 scalar_t__ ExAllocatePoolWithTag (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (TYPE_5__*,int /*<<< orphan*/ ) ; 
 void* FALSE ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  POOL_TAG ; 
 int /*<<< orphan*/  PagedPool ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 void* TRUE ; 
 int /*<<< orphan*/  kkll_m_modules_fromAddr_callback (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ,TYPE_5__*,TYPE_2__*,void**) ; 
 int /*<<< orphan*/  kprintf (int /*<<< orphan*/ ,char*,TYPE_2__*,...) ; 

NTSTATUS kkll_m_modules_enum(SIZE_T szBufferIn, PVOID bufferIn, PKIWI_BUFFER outBuffer, PKKLL_M_MODULE_CALLBACK callback, PVOID pvArg)
{
	NTSTATUS status = STATUS_SUCCESS;
	ULONG i, modulesSize, numberOfModules;
	PAUX_MODULE_EXTENDED_INFO pModules;
	BOOLEAN mustContinue = TRUE;

	status = AuxKlibQueryModuleInformation(&modulesSize, sizeof(AUX_MODULE_EXTENDED_INFO), NULL);		
	if(NT_SUCCESS(status) && modulesSize)
	{
		if(pModules = (PAUX_MODULE_EXTENDED_INFO) ExAllocatePoolWithTag(PagedPool, modulesSize, POOL_TAG))
		{
			numberOfModules = modulesSize / sizeof(AUX_MODULE_EXTENDED_INFO);
			status = AuxKlibQueryModuleInformation(&modulesSize, sizeof(AUX_MODULE_EXTENDED_INFO), pModules);
			for(i = 0; NT_SUCCESS(status) && mustContinue && (i < numberOfModules); i++)
				status = callback(szBufferIn, bufferIn, outBuffer, pModules + i, pvArg, &mustContinue);	
			ExFreePoolWithTag(pModules, POOL_TAG);
		}
	}
	return status;	
}

NTSTATUS kkll_m_modules_list_callback(SIZE_T szBufferIn, PVOID bufferIn, PKIWI_BUFFER outBuffer, PAUX_MODULE_EXTENDED_INFO pModule, PVOID pvArg, BOOLEAN * mustContinue)
{
	return kprintf(outBuffer, L"0x%p - %u\t%S\n", pModule->BasicInfo.ImageBase, pModule->ImageSize, pModule->FullPathName + pModule->FileNameOffset);
}

NTSTATUS kkll_m_modules_fromAddr(PKIWI_BUFFER outBuffer, PVOID addr)
{
	KKLL_M_MODULE_FROM_ADDR structAddr = {FALSE, (ULONG_PTR) addr};
	NTSTATUS status = kkll_m_modules_enum(0, NULL, outBuffer, kkll_m_modules_fromAddr_callback, &structAddr);

	if(NT_SUCCESS(status) && !structAddr.isFound)
		status = kprintf(outBuffer, L"0x%p [ ? ]\n", addr);

	return status;
}

NTSTATUS kkll_m_modules_fromAddr_callback(SIZE_T szBufferIn, PVOID bufferIn, PKIWI_BUFFER outBuffer, PAUX_MODULE_EXTENDED_INFO pModule, PVOID pvArg, BOOLEAN * mustContinue)
{
	NTSTATUS status = STATUS_SUCCESS;
	PKKLL_M_MODULE_FROM_ADDR pStructAddr = (PKKLL_M_MODULE_FROM_ADDR) pvArg;

	if((pStructAddr->addr >= (ULONG_PTR) pModule->BasicInfo.ImageBase) && (pStructAddr->addr < ((ULONG_PTR) pModule->BasicInfo.ImageBase + pModule->ImageSize)))
	{
		*mustContinue = FALSE;
		pStructAddr->isFound = TRUE;
		status = kprintf(outBuffer, L"0x%p [%S + 0x%x]\n", (PVOID) pStructAddr->addr, pModule->FullPathName + pModule->FileNameOffset, pStructAddr->addr - (ULONG_PTR) pModule->BasicInfo.ImageBase);
	}
	return status;
}

NTSTATUS kkll_m_modules_first_callback(SIZE_T szBufferIn, PVOID bufferIn, PKIWI_BUFFER outBuffer, PAUX_MODULE_EXTENDED_INFO pModule, PVOID pvArg, BOOLEAN * mustContinue)
{
	*mustContinue = FALSE;
	((PKKLL_M_MODULE_BASIC_INFOS) pvArg)->addr = (PUCHAR) pModule->BasicInfo.ImageBase;
	((PKKLL_M_MODULE_BASIC_INFOS) pvArg)->size = pModule->ImageSize;
	return STATUS_SUCCESS;
}

