#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WSADATA ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_9__ {scalar_t__ lpName; } ;
struct TYPE_8__ {scalar_t__ dwCheckPoint; scalar_t__ dwCurrentState; } ;
struct TYPE_7__ {TYPE_3__ servStatus; int /*<<< orphan*/  hStatus; } ;
typedef  TYPE_1__* PSERVICEINFO ;
typedef  int INT ;
typedef  int /*<<< orphan*/ * HANDLE ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateThread (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  INFINITE ; 
 int /*<<< orphan*/  LOG_ALL ; 
 int /*<<< orphan*/  LOG_FILE ; 
 int /*<<< orphan*/  LogEvent (char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAKEWORD (int,int) ; 
 int NUM_SERVICES ; 
 scalar_t__ SERVICE_RUNNING ; 
 TYPE_4__* Services ; 
 int /*<<< orphan*/  SetServiceStatus (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  StartServer ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WSACleanup () ; 
 scalar_t__ WSAStartup (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WaitForMultipleObjects (int,int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _snwprintf (char*,int,char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  swprintf (char*,char*,scalar_t__) ; 

__attribute__((used)) static VOID
UpdateStatus(PSERVICEINFO pServInfo,
             DWORD NewStatus,
             DWORD Check)
{
    WCHAR szSet[50];

    if (Check > 0)
        pServInfo->servStatus.dwCheckPoint += Check;
    else
        pServInfo->servStatus.dwCheckPoint = Check;

    if (NewStatus > 0)
        pServInfo->servStatus.dwCurrentState = NewStatus;

    _snwprintf(szSet,
               49,
               L"Service state 0x%lx, CheckPoint %lu",
               pServInfo->servStatus.dwCurrentState,
               pServInfo->servStatus.dwCheckPoint);
    LogEvent(szSet, 0, 0, LOG_FILE);

    if (!SetServiceStatus(pServInfo->hStatus, &pServInfo->servStatus))
        LogEvent(L"Cannot set service status", GetLastError(), 0, LOG_ALL);
}

__attribute__((used)) static BOOL
CreateServers(PSERVICEINFO pServInfo)
{
    DWORD dwThreadId[NUM_SERVICES];
    HANDLE hThread[NUM_SERVICES];
    WSADATA wsaData;
    WCHAR buf[256];
    INT i;
    DWORD RetVal;

    if ((RetVal = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
        swprintf(buf, L"WSAStartup() failed : %lu\n", RetVal);
        LogEvent(buf, 0, 100, LOG_ALL);
        return FALSE;
    }

    UpdateStatus(pServInfo, 0, 1);

    LogEvent(L"\nCreating server Threads", 0, 0, LOG_FILE);

    /* Create worker threads. */
    for (i = 0; i < NUM_SERVICES; i++)
    {
        swprintf(buf, L"Creating thread for %s server", Services[i].lpName);
        LogEvent(buf, 0, 0, LOG_FILE);

        hThread[i] = CreateThread(NULL,
                                  0,
                                  StartServer,
                                  &Services[i],
                                  0,
                                  &dwThreadId[i]);

        if (hThread[i] == NULL)
        {
            swprintf(buf, L"\nError creating %s server thread\n", Services[i].lpName);
            LogEvent(buf, GetLastError(), 0, LOG_ALL);
            return FALSE;
        }

        UpdateStatus(pServInfo, 0, 1);
    }

    LogEvent(L"Setting service status to running", 0, 0, LOG_FILE);
    UpdateStatus(pServInfo, SERVICE_RUNNING, 0);

    /* Wait until all threads have terminated. */
    WaitForMultipleObjects(NUM_SERVICES, hThread, TRUE, INFINITE);

    for (i = 0; i < NUM_SERVICES; i++)
    {
        if (hThread[i] != NULL)
            CloseHandle(hThread[i]);
    }

    LogEvent(L"Detaching Winsock2", 0, 0, LOG_FILE);
    WSACleanup();

    return TRUE;
}

