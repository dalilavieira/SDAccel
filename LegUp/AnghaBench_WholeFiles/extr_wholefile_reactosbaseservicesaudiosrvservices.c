#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ULONG ;
struct TYPE_2__ {scalar_t__ dwCurrentState; } ;
typedef  TYPE_1__ SERVICE_STATUS_PROCESS ;
typedef  int /*<<< orphan*/  SC_HANDLE ;
typedef  char* LPWSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CloseServiceHandle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  OpenSCManager (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OpenService (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QueryServiceStatusEx (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SC_MANAGER_CONNECT ; 
 int /*<<< orphan*/  SC_STATUS_PROCESS_INFO ; 
 int /*<<< orphan*/  SERVICE_ALL_ACCESS ; 
 scalar_t__ SERVICE_RUNNING ; 
 int /*<<< orphan*/  Sleep (int) ; 
 int /*<<< orphan*/  StartService (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  logmsg (char*,...) ; 

BOOL
WaitForService(
    SC_HANDLE hService,
    ULONG RetryCount)
{
    ULONG Index = 0;
    DWORD dwSize;
    SERVICE_STATUS_PROCESS Info;

    do
    {
        if (!QueryServiceStatusEx(hService, SC_STATUS_PROCESS_INFO, (LPBYTE)&Info, sizeof(SERVICE_STATUS_PROCESS), &dwSize))
        {
            logmsg("QueryServiceStatusEx failed %x\n", GetLastError());
            break;
        }

        if (Info.dwCurrentState == SERVICE_RUNNING)
            return TRUE;

        Sleep(1000);

    }while(Index++ < RetryCount);

    logmsg("Timeout while waiting for service to become ready %p\n", hService);

    return FALSE;
}

BOOL
StartAudioService(
    SC_HANDLE hSCManager,
    LPWSTR ServiceName,
    ULONG RetryCount)
{
    SC_HANDLE hService;
    BOOL ret;

    hService = OpenService(hSCManager, ServiceName, SERVICE_ALL_ACCESS);

    if (!hService)
    {
        logmsg("Failed to open service %S %x\n", ServiceName, GetLastError());
        return FALSE;
    }

    if (!StartService(hService, 0, NULL))
    {
        logmsg("Failed to start service %S %x\n", ServiceName, GetLastError());
        CloseServiceHandle(hService);
        return FALSE;
    }

    ret = WaitForService(hService, RetryCount);

    CloseServiceHandle(hService);
    return ret;
}

BOOL
StartSystemAudioServices()
{
    SC_HANDLE hSCManager;

    logmsg("Starting system audio services\n");

    hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
    if (!hSCManager)
    {
        logmsg("Failed to open service manager %x\n", GetLastError());
        return FALSE;
    }

    logmsg("Starting sysaudio service\n");
    StartAudioService(hSCManager, L"sysaudio", 20);
    logmsg("Starting wdmaud service\n");
    StartAudioService(hSCManager, L"wdmaud", 20);

    CloseServiceHandle(hSCManager);
    return TRUE;
}

