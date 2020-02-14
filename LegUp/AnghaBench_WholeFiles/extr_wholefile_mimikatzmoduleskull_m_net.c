#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  WELL_KNOWN_SID_TYPE ;
struct TYPE_7__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_6__ {scalar_t__ DomainControllerName; } ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  int /*<<< orphan*/ * PSID ;
typedef  int /*<<< orphan*/  PPOLICY_DNS_DOMAIN_INFO ;
typedef  TYPE_1__* PDOMAIN_CONTROLLER_INFO ;
typedef  TYPE_2__ LSA_OBJECT_ATTRIBUTES ;
typedef  int /*<<< orphan*/  LSA_HANDLE ;
typedef  int /*<<< orphan*/ * LPWSTR ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  COMPUTER_NAME_FORMAT ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ComputerNamePhysicalDnsFullyQualified ; 
 int /*<<< orphan*/  ComputerNamePhysicalNetBIOS ; 
 scalar_t__ CreateWellKnownSid (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__*) ; 
 scalar_t__ DS_IS_DNS_NAME ; 
 scalar_t__ DS_RETURN_DNS_NAME ; 
 scalar_t__ DsGetDcName (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__,TYPE_1__**) ; 
 scalar_t__ ERROR_INSUFFICIENT_BUFFER ; 
 scalar_t__ ERROR_INVALID_PARAMETER ; 
 scalar_t__ ERROR_MORE_DATA ; 
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ FALSE ; 
 scalar_t__ GetComputerNameEx (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__*) ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  LPTR ; 
 scalar_t__ LocalAlloc (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/ * LocalFree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LsaClose (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LsaOpenPolicy (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LsaQueryInformationPolicy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NetApiBufferFree (TYPE_1__*) ; 
 int /*<<< orphan*/  POLICY_VIEW_LOCAL_INFORMATION ; 
 int /*<<< orphan*/  PRINT_ERROR (char*,scalar_t__) ; 
 int /*<<< orphan*/  PRINT_ERROR_AUTO (char*) ; 
 int /*<<< orphan*/  PolicyDnsDomainInformation ; 
 int /*<<< orphan*/  RtlCopyMemory (int /*<<< orphan*/ *,scalar_t__,scalar_t__) ; 
 scalar_t__ TRUE ; 
 scalar_t__ wcslen (scalar_t__) ; 

BOOL kull_m_net_getCurrentDomainInfo(PPOLICY_DNS_DOMAIN_INFO * pDomainInfo)
{
	BOOL status = FALSE;
	LSA_HANDLE hLSA;
	LSA_OBJECT_ATTRIBUTES oaLsa = {0};

	if(NT_SUCCESS(LsaOpenPolicy(NULL, &oaLsa, POLICY_VIEW_LOCAL_INFORMATION, &hLSA)))
	{
		status = NT_SUCCESS(LsaQueryInformationPolicy(hLSA, PolicyDnsDomainInformation, (PVOID *) pDomainInfo));
		LsaClose(hLSA);
	}
	return status;
}

BOOL kull_m_net_CreateWellKnownSid(WELL_KNOWN_SID_TYPE WellKnownSidType, PSID DomainSid, PSID * pSid)
{
	BOOL status = FALSE;
	DWORD szNeeded = 0, dwError;
	CreateWellKnownSid(WellKnownSidType, DomainSid, NULL, &szNeeded);
	dwError = GetLastError();
	if((dwError == ERROR_INVALID_PARAMETER) || (dwError == ERROR_INSUFFICIENT_BUFFER))
		if(*pSid = (PSID) LocalAlloc(LPTR, szNeeded))
			if(!(status = CreateWellKnownSid(WellKnownSidType, DomainSid, *pSid, &szNeeded)))
				*pSid = LocalFree(*pSid);
	return status;
}

BOOL kull_m_net_getDC(LPCWSTR fullDomainName, DWORD altFlags, LPWSTR * fullDCName)
{
	BOOL status = FALSE;
	DWORD ret, size;
	PDOMAIN_CONTROLLER_INFO cInfo = NULL;
	ret = DsGetDcName(NULL, fullDomainName, NULL, NULL, altFlags | DS_IS_DNS_NAME | DS_RETURN_DNS_NAME, &cInfo);
	if(ret == ERROR_SUCCESS)
	{
		size = (DWORD) (wcslen(cInfo->DomainControllerName + 2) + 1) * sizeof(wchar_t);
		if(*fullDCName = (wchar_t *) LocalAlloc(LPTR, size))
		{
			status = TRUE;
			RtlCopyMemory(*fullDCName, cInfo->DomainControllerName + 2, size);
		}
		NetApiBufferFree(cInfo);
	}
	else PRINT_ERROR(L"DsGetDcName: %u\n", ret);
	return status;
}

BOOL kull_m_net_getComputerName(BOOL isFull, LPWSTR *name)
{
	BOOL status = FALSE;
	COMPUTER_NAME_FORMAT ft = isFull ? ComputerNamePhysicalDnsFullyQualified : ComputerNamePhysicalNetBIOS;
	DWORD dwSize = 0;
	if(!GetComputerNameEx(ft, NULL, &dwSize) && (GetLastError() == ERROR_MORE_DATA))
	{
		if(*name = (wchar_t *) LocalAlloc(LPTR, dwSize * sizeof(wchar_t)))
		{
			if(!(status = GetComputerNameEx(ft, *name, &dwSize)))
			{
				PRINT_ERROR_AUTO(L"GetComputerNameEx(data)");
				LocalFree(*name);
			}
		}
	}
	else PRINT_ERROR_AUTO(L"GetComputerNameEx(init)");
	return status;
}

