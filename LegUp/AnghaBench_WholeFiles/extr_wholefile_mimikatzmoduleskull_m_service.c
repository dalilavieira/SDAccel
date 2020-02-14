#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  ptstrName; } ;
struct TYPE_5__ {int /*<<< orphan*/ * member_4; int /*<<< orphan*/  member_3; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; int /*<<< orphan*/ * member_0; } ;
struct TYPE_7__ {int member_0; TYPE_2__ Trustee; TYPE_1__ member_3; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; } ;
typedef  int /*<<< orphan*/  SID_IDENTIFIER_AUTHORITY ;
typedef  int /*<<< orphan*/  SERVICE_STATUS_PROCESS ;
typedef  int /*<<< orphan*/  SERVICE_STATUS ;
typedef  int /*<<< orphan*/  SECURITY_DESCRIPTOR ;
typedef  int /*<<< orphan*/ * SC_HANDLE ;
typedef  int /*<<< orphan*/  PSID ;
typedef  int /*<<< orphan*/ * PSECURITY_DESCRIPTOR ;
typedef  int /*<<< orphan*/  PCWSTR ;
typedef  int /*<<< orphan*/ * LPSERVICE_STATUS ;
typedef  TYPE_3__ EXPLICIT_ACCESS ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 scalar_t__ AllocateAndInitializeSid (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ BuildSecurityDescriptor (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  CloseServiceHandle (int /*<<< orphan*/ *) ; 
 scalar_t__ ControlService (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateService (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DACL_SECURITY_INFORMATION ; 
 int DELETE ; 
 scalar_t__ DeleteService (int /*<<< orphan*/ *) ; 
 scalar_t__ ERROR_INSUFFICIENT_BUFFER ; 
 scalar_t__ ERROR_SERVICE_ALREADY_RUNNING ; 
 scalar_t__ ERROR_SERVICE_DOES_NOT_EXIST ; 
 scalar_t__ ERROR_SERVICE_NOT_ACTIVE ; 
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  FreeSid (int /*<<< orphan*/ ) ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  LPTR ; 
 scalar_t__ LocalAlloc (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  LocalFree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NO_INHERITANCE ; 
 int /*<<< orphan*/  NO_MULTIPLE_TRUSTEE ; 
 int /*<<< orphan*/ * OpenSCManager (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * OpenService (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PRINT_ERROR_AUTO (char*) ; 
 scalar_t__ QueryServiceObjectSecurity (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int*) ; 
 scalar_t__ QueryServiceStatusEx (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int*) ; 
 int READ_CONTROL ; 
 int SC_MANAGER_CONNECT ; 
 int SC_MANAGER_CREATE_SERVICE ; 
 int /*<<< orphan*/  SC_STATUS_PROCESS_INFO ; 
 int /*<<< orphan*/  SECURITY_WORLD_RID ; 
 int /*<<< orphan*/  SECURITY_WORLD_SID_AUTHORITY ; 
 int /*<<< orphan*/  SERVICES_ACTIVE_DATABASE ; 
 int SERVICE_ALL_ACCESS ; 
 int SERVICE_CONTROL_CONTINUE ; 
 int SERVICE_CONTROL_PAUSE ; 
 int SERVICE_CONTROL_PRESHUTDOWN ; 
 int SERVICE_CONTROL_SHUTDOWN ; 
 int SERVICE_CONTROL_STOP ; 
 int SERVICE_ENUMERATE_DEPENDENTS ; 
 int /*<<< orphan*/  SERVICE_ERROR_NORMAL ; 
 int SERVICE_INTERROGATE ; 
 int SERVICE_PAUSE_CONTINUE ; 
 int SERVICE_QUERY_CONFIG ; 
 int SERVICE_QUERY_STATUS ; 
 int SERVICE_START ; 
 int SERVICE_STOP ; 
 int SERVICE_USER_DEFINED_CONTROL ; 
 int /*<<< orphan*/  SET_ACCESS ; 
 scalar_t__ STATUS_SUCCESS ; 
 scalar_t__ SetServiceObjectSecurity (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ StartService (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  TRUSTEE_IS_SID ; 
 int /*<<< orphan*/  TRUSTEE_IS_WELL_KNOWN_GROUP ; 
 int WRITE_DAC ; 
 int /*<<< orphan*/  kprintf (char*,int /*<<< orphan*/ ) ; 

BOOL kull_m_service_getUniqueForName(PCWSTR serviceName, SERVICE_STATUS_PROCESS * pServiceStatusProcess)
{
	BOOL status = FALSE;
	SC_HANDLE hSC, hS;
	DWORD szNeeded;

	if(hSC = OpenSCManager(NULL, SERVICES_ACTIVE_DATABASE, SC_MANAGER_CONNECT))
	{
		if(hS = OpenService(hSC, serviceName, SERVICE_QUERY_STATUS))
		{
			status = QueryServiceStatusEx(hS, SC_STATUS_PROCESS_INFO, (BYTE *) pServiceStatusProcess, sizeof(SERVICE_STATUS_PROCESS), &szNeeded);
			CloseServiceHandle(hS);
		}
		CloseServiceHandle(hSC);
	}
	return status;	
}

BOOL kull_m_service_start(PCWSTR serviceName)
{
	BOOL status = FALSE;
	SC_HANDLE hSC, hS;

	if(hSC = OpenSCManager(NULL, SERVICES_ACTIVE_DATABASE, SC_MANAGER_CONNECT))
	{
		if(hS = OpenService(hSC, serviceName, SERVICE_START))
		{
			status = StartService(hS, 0, NULL);
			CloseServiceHandle(hS);
		}
		CloseServiceHandle(hSC);
	}
	return status;
}

BOOL kull_m_service_remove(PCWSTR serviceName)
{
	BOOL status = FALSE;
	SC_HANDLE hSC, hS;

	if(hSC = OpenSCManager(NULL, SERVICES_ACTIVE_DATABASE, SC_MANAGER_CONNECT))
	{
		if(hS = OpenService(hSC, serviceName, DELETE))
		{
			status = DeleteService(hS);
			CloseServiceHandle(hS);
		}
		CloseServiceHandle(hSC);
	}
	return status;
}

BOOL kull_m_service_genericControl(PCWSTR serviceName, DWORD dwDesiredAccess, DWORD dwControl, LPSERVICE_STATUS ptrServiceStatus)
{
	BOOL status = FALSE;
	SC_HANDLE hSC, hS;
	SERVICE_STATUS serviceStatus;

	if(hSC = OpenSCManager(NULL, SERVICES_ACTIVE_DATABASE, SC_MANAGER_CONNECT))
	{
		if(hS = OpenService(hSC, serviceName, dwDesiredAccess))
		{
			status = ControlService(hS, dwControl, ptrServiceStatus ? ptrServiceStatus : &serviceStatus);
			CloseServiceHandle(hS);
		}
		CloseServiceHandle(hSC);
	}
	return status;
}

BOOL kull_m_service_stop(PCWSTR serviceName)
{
	return(kull_m_service_genericControl(serviceName, SERVICE_STOP, SERVICE_CONTROL_STOP, NULL));
}

BOOL kull_m_service_suspend(PCWSTR serviceName)
{
	return(kull_m_service_genericControl(serviceName, SERVICE_PAUSE_CONTINUE, SERVICE_CONTROL_PAUSE, NULL));
}

BOOL kull_m_service_resume(PCWSTR serviceName)
{
	return(kull_m_service_genericControl(serviceName, SERVICE_PAUSE_CONTINUE, SERVICE_CONTROL_CONTINUE, NULL));
}

BOOL kull_m_service_preshutdown(PCWSTR serviceName)
{
	return(kull_m_service_genericControl(serviceName, SERVICE_ALL_ACCESS, SERVICE_CONTROL_PRESHUTDOWN, NULL));
}

BOOL kull_m_service_shutdown(PCWSTR serviceName)
{
	return(kull_m_service_genericControl(serviceName, SERVICE_ALL_ACCESS, SERVICE_CONTROL_SHUTDOWN, NULL));
}

BOOL kull_m_service_addWorldToSD(SC_HANDLE monHandle)
{
	BOOL status = FALSE;
	DWORD dwSizeNeeded;
	PSECURITY_DESCRIPTOR oldSd, newSd;
	SECURITY_DESCRIPTOR dummySdForXP;
	SID_IDENTIFIER_AUTHORITY SIDAuthWorld = SECURITY_WORLD_SID_AUTHORITY;
	EXPLICIT_ACCESS ForEveryOne = {
		SERVICE_QUERY_STATUS | SERVICE_QUERY_CONFIG | SERVICE_INTERROGATE | SERVICE_ENUMERATE_DEPENDENTS | SERVICE_PAUSE_CONTINUE | SERVICE_START | SERVICE_STOP | SERVICE_USER_DEFINED_CONTROL | READ_CONTROL,
		SET_ACCESS,
		NO_INHERITANCE,
		{NULL, NO_MULTIPLE_TRUSTEE, TRUSTEE_IS_SID, TRUSTEE_IS_WELL_KNOWN_GROUP, NULL}
	};
	if(!QueryServiceObjectSecurity(monHandle, DACL_SECURITY_INFORMATION, &dummySdForXP, 0, &dwSizeNeeded) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER))
	{
		if(oldSd = (PSECURITY_DESCRIPTOR) LocalAlloc(LPTR, dwSizeNeeded))
		{
			if(QueryServiceObjectSecurity(monHandle, DACL_SECURITY_INFORMATION, oldSd, dwSizeNeeded, &dwSizeNeeded))
			{
				if(AllocateAndInitializeSid(&SIDAuthWorld, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, (PSID *)&ForEveryOne.Trustee.ptstrName))
				{
					if(BuildSecurityDescriptor(NULL, NULL, 1, &ForEveryOne, 0, NULL, oldSd, &dwSizeNeeded, &newSd) == ERROR_SUCCESS)
					{
						status = SetServiceObjectSecurity(monHandle, DACL_SECURITY_INFORMATION, newSd);
						LocalFree(newSd);
					}
					FreeSid(ForEveryOne.Trustee.ptstrName);
				}
			}
			LocalFree(oldSd);
		}
	}
	return status;
}

BOOL kull_m_service_install(PCWSTR serviceName, PCWSTR displayName, PCWSTR binPath, DWORD serviceType, DWORD startType, BOOL startIt)
{
	BOOL status = FALSE;
	SC_HANDLE hSC = NULL, hS = NULL;

	if(hSC = OpenSCManager(NULL, SERVICES_ACTIVE_DATABASE, SC_MANAGER_CONNECT | SC_MANAGER_CREATE_SERVICE))
	{
		if(hS = OpenService(hSC, serviceName, SERVICE_START))
		{
			kprintf(L"[+] \'%s\' service already registered\n", serviceName);
		}
		else
		{
			if(GetLastError() == ERROR_SERVICE_DOES_NOT_EXIST)
			{
				kprintf(L"[*] \'%s\' service not present\n", serviceName);
				if(hS = CreateService(hSC, serviceName, displayName, READ_CONTROL | WRITE_DAC | SERVICE_START, serviceType, startType, SERVICE_ERROR_NORMAL, binPath, NULL, NULL, NULL, NULL, NULL))
				{
					kprintf(L"[+] \'%s\' service successfully registered\n", serviceName);
					if(status = kull_m_service_addWorldToSD(hS))
						kprintf(L"[+] \'%s\' service ACL to everyone\n", serviceName);
					else PRINT_ERROR_AUTO(L"kull_m_service_addWorldToSD");
				}
				else PRINT_ERROR_AUTO(L"CreateService");
			}
			else PRINT_ERROR_AUTO(L"OpenService");
		}
		if(hS)
		{
			if(startIt)
			{
				if(status = StartService(hS, 0, NULL))
					kprintf(L"[+] \'%s\' service started\n", serviceName);
				else if(GetLastError() == ERROR_SERVICE_ALREADY_RUNNING)
					kprintf(L"[*] \'%s\' service already started\n", serviceName);
				else PRINT_ERROR_AUTO(L"StartService");
			}
			CloseServiceHandle(hS);
		}
		CloseServiceHandle(hSC);
	}
	else PRINT_ERROR_AUTO(L"OpenSCManager(create)");
	return status;
}

BOOL kull_m_service_uninstall(PCWSTR serviceName)
{
	BOOL status = FALSE, toRemove = TRUE;
	if(kull_m_service_stop(serviceName))
		kprintf(L"[+] \'%s\' service stopped\n", serviceName);
	else if(GetLastError() == ERROR_SERVICE_NOT_ACTIVE)
		kprintf(L"[*] \'%s\' service not running\n", serviceName);
	else
	{
		toRemove = FALSE;
		PRINT_ERROR_AUTO(L"kull_m_service_stop");
	}

	if(toRemove)
	{
		if(status = kull_m_service_remove(serviceName))
			kprintf(L"[+] \'%s\' service removed\n", serviceName);
		else PRINT_ERROR_AUTO(L"kull_m_service_remove");
	}
	return STATUS_SUCCESS;
}

