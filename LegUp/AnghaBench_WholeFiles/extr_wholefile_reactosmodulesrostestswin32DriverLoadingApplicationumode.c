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
typedef  int /*<<< orphan*/  SERVICE_STATUS ;
typedef  scalar_t__ SC_HANDLE ;
typedef  char* LPCWSTR ;
typedef  scalar_t__ DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CloseServiceHandle (scalar_t__) ; 
 int ControlService (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ CreateServiceW (scalar_t__,char*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* DRIVER_NAME ; 
 int DeleteService (scalar_t__) ; 
 scalar_t__ ERROR_SERVICE_ALREADY_RUNNING ; 
 scalar_t__ ERROR_SERVICE_EXISTS ; 
 scalar_t__ ERROR_SERVICE_MARKED_FOR_DELETE ; 
 scalar_t__ ERROR_SERVICE_NOT_ACTIVE ; 
 int FALSE ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ OpenSCManagerW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ OpenServiceW (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SC_MANAGER_ALL_ACCESS ; 
 int /*<<< orphan*/  SERVICE_ALL_ACCESS ; 
 int /*<<< orphan*/  SERVICE_CONTROL_STOP ; 
 int /*<<< orphan*/  SERVICE_DEMAND_START ; 
 int /*<<< orphan*/  SERVICE_ERROR_NORMAL ; 
 int /*<<< orphan*/  SERVICE_KERNEL_DRIVER ; 
 int StartServiceW (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int StopDriver (char*) ; 
 int TRUE ; 
 int /*<<< orphan*/  wprintf (char*,char*) ; 

BOOL
RegisterDriver(LPCWSTR lpDriverName,
               LPCWSTR lpPathName)
{
    SC_HANDLE hSCManager;
    SC_HANDLE hService;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_ALL_ACCESS);
    if (!hSCManager)
        return FALSE;

retry:
    hService = CreateServiceW(hSCManager,
                              lpDriverName,
                              lpDriverName,
                              SERVICE_ALL_ACCESS,
                              SERVICE_KERNEL_DRIVER,
                              SERVICE_DEMAND_START,
                              SERVICE_ERROR_NORMAL,
                              lpPathName,
                              NULL,
                              NULL,
                              NULL,
                              NULL,
                              NULL);

    if (hService)
    {
        CloseServiceHandle(hService);
        CloseServiceHandle(hSCManager);
        return TRUE;
    }
    else
    {
        DWORD err = GetLastError();

        if (err == ERROR_SERVICE_MARKED_FOR_DELETE)
        {
            StopDriver(DRIVER_NAME);
            goto retry;
        }

        CloseServiceHandle(hSCManager);

        // return TRUE if the driver is already registered
        return (err == ERROR_SERVICE_EXISTS);
    }
}

BOOL
StartDriver(LPCWSTR lpDriverName)
{
    SC_HANDLE hSCManager;
    SC_HANDLE hService;
    BOOL bRet;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_ALL_ACCESS);
    if (!hSCManager)
        return FALSE;

    hService = OpenServiceW(hSCManager,
                            lpDriverName,
                            SERVICE_ALL_ACCESS);
    if (!hService)
    {
        CloseServiceHandle(hSCManager);
        return FALSE;
    }

    bRet = StartServiceW(hService, 0, NULL);
    if (!bRet)
    {
        if (GetLastError() == ERROR_SERVICE_ALREADY_RUNNING)
        {
            wprintf(L"%s.sys already running\n", DRIVER_NAME);
            bRet = TRUE;
        }
    }

    CloseServiceHandle(hService);
    CloseServiceHandle(hSCManager);

    return bRet;
}

BOOL
StopDriver(LPCWSTR lpDriverName)
{
    SC_HANDLE hSCManager;
    SC_HANDLE hService;
    SERVICE_STATUS serviceStatus;
    BOOL bRet;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_ALL_ACCESS);
    if (!hSCManager)
        return FALSE;

    hService = OpenServiceW(hSCManager,
                            lpDriverName,
                            SERVICE_ALL_ACCESS);
    if (!hService)
    {
        CloseServiceHandle(hSCManager);
        return FALSE;
    }

    bRet = ControlService(hService,
                          SERVICE_CONTROL_STOP,
                          &serviceStatus);
    if (!bRet)
    {
        if (GetLastError() == ERROR_SERVICE_NOT_ACTIVE)
        {
            wprintf(L"%s.sys wasn't running\n", DRIVER_NAME);
            bRet = TRUE;
        }
    }

    CloseServiceHandle(hService);
    CloseServiceHandle(hSCManager);

    return bRet;
}

BOOL
UnregisterDriver(LPCWSTR lpDriverName)
{
    SC_HANDLE hService;
    SC_HANDLE hSCManager;
    BOOL bRet;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_ALL_ACCESS);
    if (!hSCManager)
        return FALSE;

    hService = OpenServiceW(hSCManager,
                            lpDriverName,
                            SERVICE_ALL_ACCESS);
    if (!hService)
    {
        CloseServiceHandle(hSCManager);
        return FALSE;
    }

    bRet = DeleteService(hService);

    CloseServiceHandle(hService);
    CloseServiceHandle(hSCManager);

    return bRet;
}

