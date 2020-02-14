#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_36__ {scalar_t__ lParam; int /*<<< orphan*/  iItem; int /*<<< orphan*/  mask; } ;
struct TYPE_35__ {int NumServices; TYPE_1__* pAllServices; int /*<<< orphan*/  hListView; int /*<<< orphan*/  SelectedItem; } ;
struct TYPE_34__ {int /*<<< orphan*/  ServiceStatusProcess; struct TYPE_34__* lpServiceName; struct TYPE_34__* lpDisplayName; struct TYPE_34__* lpDescription; int /*<<< orphan*/  lpServiceStartName; int /*<<< orphan*/  lpDependencies; scalar_t__ dwTagId; int /*<<< orphan*/  lpLoadOrderGroup; int /*<<< orphan*/  lpBinaryPathName; int /*<<< orphan*/  dwErrorControl; int /*<<< orphan*/  dwStartType; int /*<<< orphan*/  dwServiceType; } ;
typedef  int /*<<< orphan*/  SERVICE_STATUS_PROCESS ;
typedef  TYPE_1__ SERVICE_DESCRIPTIONW ;
typedef  TYPE_1__ SERVICE_DESCRIPTION ;
typedef  int /*<<< orphan*/  SC_LOCK ;
typedef  int /*<<< orphan*/ * SC_HANDLE ;
typedef  TYPE_3__* PMAIN_WND_INFO ;
typedef  TYPE_4__ LVITEM ;
typedef  TYPE_1__* LPWSTR ;
typedef  TYPE_1__* LPQUERY_SERVICE_CONFIGW ;
typedef  TYPE_1__* LPQUERY_SERVICE_CONFIG ;
typedef  int /*<<< orphan*/ * LPBYTE ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  TYPE_1__ ENUM_SERVICE_STATUS_PROCESS ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 scalar_t__ ChangeServiceConfig2W (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 
 scalar_t__ ChangeServiceConfigW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  CloseServiceHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CopyMemory (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ ERROR_INSUFFICIENT_BUFFER ; 
 scalar_t__ ERROR_MORE_DATA ; 
 scalar_t__ EnumServicesStatusEx (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int*,int*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetError () ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  LVIF_PARAM ; 
 int /*<<< orphan*/  LVM_GETITEM ; 
 int /*<<< orphan*/  LockServiceDatabase (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * OpenSCManagerW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * OpenServiceW (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ProcessHeap ; 
 scalar_t__ QueryServiceConfig2W (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int*) ; 
 int /*<<< orphan*/  QueryServiceConfigW (int /*<<< orphan*/ *,TYPE_1__*,int,int*) ; 
 int /*<<< orphan*/  QueryServiceStatusEx (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int*) ; 
 int /*<<< orphan*/  SC_ENUM_PROCESS_INFO ; 
 int /*<<< orphan*/  SC_MANAGER_CONNECT ; 
 int /*<<< orphan*/  SC_MANAGER_ENUMERATE_SERVICE ; 
 int /*<<< orphan*/  SC_MANAGER_LOCK ; 
 int /*<<< orphan*/  SC_STATUS_PROCESS_INFO ; 
 int /*<<< orphan*/  SERVICE_CHANGE_CONFIG ; 
 int /*<<< orphan*/  SERVICE_CONFIG_DESCRIPTION ; 
 int /*<<< orphan*/  SERVICE_QUERY_CONFIG ; 
 int /*<<< orphan*/  SERVICE_QUERY_STATUS ; 
 int /*<<< orphan*/  SERVICE_STATE_ALL ; 
 int /*<<< orphan*/  SERVICE_WIN32 ; 
 int /*<<< orphan*/  SendMessage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  StringCchCopyW (TYPE_1__*,int,TYPE_1__*) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  UnlockServiceDatabase (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wcscpy (TYPE_1__*,TYPE_1__*) ; 
 int wcslen (TYPE_1__*) ; 

ENUM_SERVICE_STATUS_PROCESS*
GetSelectedService(PMAIN_WND_INFO Info)
{
    LVITEM lvItem;

    lvItem.mask = LVIF_PARAM;
    lvItem.iItem = Info->SelectedItem;
    SendMessage(Info->hListView,
                LVM_GETITEM,
                0,
                (LPARAM)&lvItem);

    /* return pointer to selected service */
    return (ENUM_SERVICE_STATUS_PROCESS *)lvItem.lParam;
}

LPQUERY_SERVICE_CONFIG
GetServiceConfig(LPWSTR lpServiceName)
{
    LPQUERY_SERVICE_CONFIGW lpServiceConfig = NULL;
    SC_HANDLE hSCManager;
    SC_HANDLE hService;
    DWORD dwBytesNeeded;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_CONNECT);
    if (hSCManager)
    {
        hService = OpenServiceW(hSCManager,
                                lpServiceName,
                                SERVICE_QUERY_CONFIG);
        if (hService)
        {
            if (!QueryServiceConfigW(hService,
                                     NULL,
                                     0,
                                     &dwBytesNeeded))
            {
                if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
                {
                    lpServiceConfig = (LPQUERY_SERVICE_CONFIG)HeapAlloc(GetProcessHeap(),
                                                                        0,
                                                                        dwBytesNeeded);
                    if (lpServiceConfig)
                    {
                        if (!QueryServiceConfigW(hService,
                                                lpServiceConfig,
                                                dwBytesNeeded,
                                                &dwBytesNeeded))
                        {
                            HeapFree(GetProcessHeap(),
                                     0,
                                     lpServiceConfig);
                            lpServiceConfig = NULL;
                        }
                    }
                }
            }

            CloseServiceHandle(hService);
        }

        CloseServiceHandle(hSCManager);
    }

    return lpServiceConfig;
}

BOOL
SetServiceConfig(LPQUERY_SERVICE_CONFIG pServiceConfig,
                 LPWSTR lpServiceName,
                 LPWSTR lpPassword)
{
    SC_HANDLE hSCManager;
    SC_HANDLE hSc;
    SC_LOCK scLock;
    BOOL bRet = FALSE;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_LOCK);
    if (hSCManager)
    {
        scLock = LockServiceDatabase(hSCManager);
        if (scLock)
        {
            hSc = OpenServiceW(hSCManager,
                               lpServiceName,
                               SERVICE_CHANGE_CONFIG);
            if (hSc)
            {
                if (ChangeServiceConfigW(hSc,
                                         pServiceConfig->dwServiceType,
                                         pServiceConfig->dwStartType,
                                         pServiceConfig->dwErrorControl,
                                         pServiceConfig->lpBinaryPathName,
                                         pServiceConfig->lpLoadOrderGroup,
                                         pServiceConfig->dwTagId ? &pServiceConfig->dwTagId : NULL,
                                         pServiceConfig->lpDependencies,
                                         pServiceConfig->lpServiceStartName,
                                         lpPassword,
                                         pServiceConfig->lpDisplayName))
                {
                    bRet = TRUE;
                }

                CloseServiceHandle(hSc);
            }

            UnlockServiceDatabase(scLock);
        }

        CloseServiceHandle(hSCManager);
    }

    if (!bRet)
        GetError();

    return bRet;
}

LPWSTR
GetServiceDescription(LPWSTR lpServiceName)
{
    SC_HANDLE hSCManager = NULL;
    SC_HANDLE hSc = NULL;
    SERVICE_DESCRIPTIONW *pServiceDescription = NULL;
    LPWSTR lpDescription = NULL;
    DWORD BytesNeeded = 0;
    DWORD dwSize;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_ENUMERATE_SERVICE);
    if (hSCManager == NULL)
    {
        GetError();
        return NULL;
    }

    hSc = OpenServiceW(hSCManager,
                       lpServiceName,
                       SERVICE_QUERY_CONFIG);
    if (hSc)
    {
        if (!QueryServiceConfig2W(hSc,
                                  SERVICE_CONFIG_DESCRIPTION,
                                  NULL,
                                  0,
                                  &BytesNeeded))
        {
            if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
            {
                pServiceDescription = (SERVICE_DESCRIPTION *) HeapAlloc(ProcessHeap,
                                                                        0,
                                                                        BytesNeeded);
                if (pServiceDescription == NULL)
                    goto cleanup;

                if (QueryServiceConfig2W(hSc,
                                         SERVICE_CONFIG_DESCRIPTION,
                                         (LPBYTE)pServiceDescription,
                                         BytesNeeded,
                                         &BytesNeeded))
                {
                    if (pServiceDescription->lpDescription)
                    {
                        dwSize = wcslen(pServiceDescription->lpDescription) + 1;
                        lpDescription = HeapAlloc(ProcessHeap,
                                                  0,
                                                  dwSize * sizeof(WCHAR));
                        if (lpDescription)
                        {
                            StringCchCopyW(lpDescription,
                                           dwSize,
                                           pServiceDescription->lpDescription);
                        }
                    }
                }
            }
        }
    }

cleanup:
    if (pServiceDescription)
        HeapFree(ProcessHeap,
                 0,
                 pServiceDescription);
    if (hSCManager != NULL)
        CloseServiceHandle(hSCManager);
    if (hSc != NULL)
        CloseServiceHandle(hSc);

    return lpDescription;
}

BOOL
SetServiceDescription(LPWSTR lpServiceName,
                      LPWSTR lpDescription)
{
    SC_HANDLE hSCManager;
    SC_HANDLE hSc;
    SC_LOCK scLock;
    SERVICE_DESCRIPTION ServiceDescription;
    BOOL bRet = FALSE;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_LOCK);
    if (hSCManager)
    {
        scLock = LockServiceDatabase(hSCManager);
        if (scLock)
        {
            hSc = OpenServiceW(hSCManager,
                               lpServiceName,
                               SERVICE_CHANGE_CONFIG);
            if (hSc)
            {
                ServiceDescription.lpDescription = lpDescription;

                if (ChangeServiceConfig2W(hSc,
                                          SERVICE_CONFIG_DESCRIPTION,
                                          &ServiceDescription))
                {
                    bRet = TRUE;
                }

                CloseServiceHandle(hSc);
            }

            UnlockServiceDatabase(scLock);
        }

        CloseServiceHandle(hSCManager);
    }

    if (!bRet)
        GetError();

    return bRet;
}

VOID
FreeServiceList(PMAIN_WND_INFO Info)
{
    DWORD i;

    if (Info->pAllServices != NULL)
    {
        for (i = 0; i < Info->NumServices; i++)
        {
            if (Info->pAllServices[i].lpServiceName)
                HeapFree(ProcessHeap, 0, Info->pAllServices[i].lpServiceName);

            if (Info->pAllServices[i].lpDisplayName)
                HeapFree(ProcessHeap, 0, Info->pAllServices[i].lpDisplayName);
        }

        HeapFree(ProcessHeap, 0, Info->pAllServices);
        Info->pAllServices = NULL;
        Info->NumServices = 0;
    }
}

BOOL
GetServiceList(PMAIN_WND_INFO Info)
{
    ENUM_SERVICE_STATUS_PROCESS *pServices = NULL;
    SC_HANDLE ScHandle;
    BOOL bRet = FALSE;

    DWORD BytesNeeded = 0;
    DWORD ResumeHandle = 0;
    DWORD NumServices = 0;
    DWORD i;

    FreeServiceList(Info);

    ScHandle = OpenSCManagerW(NULL,
                              NULL,
                              SC_MANAGER_ENUMERATE_SERVICE);
    if (ScHandle != NULL)
    {
        if (!EnumServicesStatusEx(ScHandle,
                                  SC_ENUM_PROCESS_INFO,
                                  SERVICE_WIN32,
                                  SERVICE_STATE_ALL,
                                  NULL,
                                  0,
                                  &BytesNeeded,
                                  &NumServices,
                                  &ResumeHandle,
                                  0))
        {
            /* Call function again if required size was returned */
            if (GetLastError() == ERROR_MORE_DATA)
            {
                /* reserve memory for service info array */
                pServices = (ENUM_SERVICE_STATUS_PROCESS *)HeapAlloc(ProcessHeap,
                                                                     0,
                                                                     BytesNeeded);
                if (pServices)
                {
                    /* fill array with service info */
                    if (EnumServicesStatusEx(ScHandle,
                                             SC_ENUM_PROCESS_INFO,
                                             SERVICE_WIN32,
                                             SERVICE_STATE_ALL,
                                             (LPBYTE)pServices,
                                             BytesNeeded,
                                             &BytesNeeded,
                                             &NumServices,
                                             &ResumeHandle,
                                             0))
                    {
                        bRet = TRUE;
                    }
                }
            }
        }
    }

    if (ScHandle)
        CloseServiceHandle(ScHandle);

    Info->pAllServices = (ENUM_SERVICE_STATUS_PROCESS *)HeapAlloc(ProcessHeap,
                                                                  HEAP_ZERO_MEMORY,
                                                                  NumServices * sizeof(ENUM_SERVICE_STATUS_PROCESS));
    if (Info->pAllServices != NULL)
    {
        Info->NumServices = NumServices;

        for (i = 0; i < NumServices; i++)
        {
            Info->pAllServices[i].lpServiceName = HeapAlloc(ProcessHeap,
                                                            HEAP_ZERO_MEMORY,
                                                            (wcslen(pServices[i].lpServiceName) + 1) * sizeof(WCHAR));
            if (Info->pAllServices[i].lpServiceName)
                wcscpy(Info->pAllServices[i].lpServiceName, pServices[i].lpServiceName);

            Info->pAllServices[i].lpDisplayName = HeapAlloc(ProcessHeap,
                                                            HEAP_ZERO_MEMORY,
                                                            (wcslen(pServices[i].lpDisplayName) + 1) * sizeof(WCHAR));
            if (Info->pAllServices[i].lpDisplayName)
                wcscpy(Info->pAllServices[i].lpDisplayName, pServices[i].lpDisplayName);

            CopyMemory(&Info->pAllServices[i].ServiceStatusProcess,
                       &pServices[i].ServiceStatusProcess,
                       sizeof(SERVICE_STATUS_PROCESS));
        }
    }

    if (pServices)
        HeapFree(ProcessHeap, 0, pServices);

    return bRet;
}

BOOL
UpdateServiceStatus(ENUM_SERVICE_STATUS_PROCESS* pService)
{
    SC_HANDLE hScm;
    BOOL bRet = FALSE;

    hScm = OpenSCManagerW(NULL,
                          NULL,
                          SC_MANAGER_ENUMERATE_SERVICE);
    if (hScm != NULL)
    {
        SC_HANDLE hService;

        hService = OpenServiceW(hScm,
                                pService->lpServiceName,
                                SERVICE_QUERY_STATUS);
        if (hService)
        {
            DWORD size;

            QueryServiceStatusEx(hService,
                                 SC_STATUS_PROCESS_INFO,
                                 (LPBYTE)&pService->ServiceStatusProcess,
                                 sizeof(SERVICE_STATUS_PROCESS),
                                 &size);

            CloseServiceHandle(hService);
            bRet = TRUE;
        }

        CloseServiceHandle(hScm);
    }

    return bRet;
}

