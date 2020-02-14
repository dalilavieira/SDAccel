#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_12__ {struct TYPE_12__* Options; struct TYPE_12__* Description; struct TYPE_12__* BinPath; struct TYPE_12__* DisplayName; struct TYPE_12__* ServiceName; int /*<<< orphan*/  hSelf; } ;
typedef  scalar_t__ SC_HANDLE ;
typedef  TYPE_1__* PCREATE_DATA ;
typedef  void* LPWSTR ;
typedef  int INT ;
typedef  scalar_t__ HWND ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 scalar_t__ AllocAndLoadString (void**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CloseServiceHandle (scalar_t__) ; 
 scalar_t__ CreateServiceW (scalar_t__,TYPE_1__*,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DisplayString (void*) ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int GetWindowTextLengthW (scalar_t__) ; 
 int /*<<< orphan*/  GetWindowTextW (scalar_t__,void*,int) ; 
 scalar_t__ HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  IDC_CREATE_DESC ; 
 int /*<<< orphan*/  IDC_CREATE_DISPNAME ; 
 int /*<<< orphan*/  IDC_CREATE_OPTIONS ; 
 int /*<<< orphan*/  IDC_CREATE_PATH ; 
 int /*<<< orphan*/  IDC_CREATE_SERVNAME ; 
 int /*<<< orphan*/  IDS_CREATE_SUCCESS ; 
 int /*<<< orphan*/  LocalFree (void*) ; 
 scalar_t__ OpenSCManagerW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ProcessHeap ; 
 int /*<<< orphan*/  SC_MANAGER_ALL_ACCESS ; 
 int /*<<< orphan*/  SERVICE_ALL_ACCESS ; 
 int /*<<< orphan*/  SERVICE_DEMAND_START ; 
 int /*<<< orphan*/  SERVICE_ERROR_NORMAL ; 
 int /*<<< orphan*/  SERVICE_WIN32_OWN_PROCESS ; 
 int /*<<< orphan*/  SetServiceDescription (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  hInstance ; 

__attribute__((used)) static BOOL
DoCreate(PCREATE_DATA Data)
{
    SC_HANDLE hSCManager;
    SC_HANDLE hSc;
    BOOL bRet = FALSE;

    /* open handle to the SCM */
    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_ALL_ACCESS);
    if (hSCManager)
    {
        hSc = CreateServiceW(hSCManager,
                             Data->ServiceName,
                             Data->DisplayName,
                             SERVICE_ALL_ACCESS,
                             SERVICE_WIN32_OWN_PROCESS,
                             SERVICE_DEMAND_START,
                             SERVICE_ERROR_NORMAL,
                             Data->BinPath,
                             NULL,
                             NULL,
                             NULL,
                             NULL,
                             NULL);

        if (hSc)
        {
            LPWSTR lpSuccess;

            /* Set the service description as CreateService
               does not do this for us */
            SetServiceDescription(Data->ServiceName,
                                  Data->Description);

            /* report success to user */
            if (AllocAndLoadString(&lpSuccess,
                                   hInstance,
                                   IDS_CREATE_SUCCESS))
            {
                DisplayString(lpSuccess);

                LocalFree(lpSuccess);
            }

            CloseServiceHandle(hSc);
            bRet = TRUE;
        }

        CloseServiceHandle(hSCManager);
    }

    return bRet;
}

__attribute__((used)) static LPWSTR
GetStringFromDialog(PCREATE_DATA Data,
                    UINT id)
{
    HWND hwnd;
    LPWSTR lpString = NULL;
    INT iLen = 0;

    hwnd = GetDlgItem(Data->hSelf,
                      id);
    if (hwnd)
    {
        iLen = GetWindowTextLengthW(hwnd);
        if (iLen)
        {
            lpString = (LPWSTR)HeapAlloc(ProcessHeap,
                                         0,
                                         (iLen + 1) * sizeof(WCHAR));
            if (lpString)
            {
                GetWindowTextW(hwnd,
                               lpString,
                               iLen + 1);
            }
        }
    }

    return lpString;
}

__attribute__((used)) static BOOL
GetDataFromDialog(PCREATE_DATA Data)
{
    BOOL bRet = FALSE;

    if ((Data->ServiceName = GetStringFromDialog(Data, IDC_CREATE_SERVNAME)))
    {
        if ((Data->DisplayName = GetStringFromDialog(Data, IDC_CREATE_DISPNAME)))
        {
            if ((Data->BinPath = GetStringFromDialog(Data, IDC_CREATE_PATH)))
            {
                Data->Description = GetStringFromDialog(Data, IDC_CREATE_DESC);
                Data->Options = GetStringFromDialog(Data, IDC_CREATE_OPTIONS);

                bRet = TRUE;
            }
        }
    }

    return bRet;
}

__attribute__((used)) static VOID
FreeMemory(PCREATE_DATA Data)
{
    if (Data->ServiceName != NULL)
        HeapFree(ProcessHeap,
                 0,
                 Data->ServiceName);
    if (Data->DisplayName != NULL)
        HeapFree(ProcessHeap,
                 0,
                 Data->DisplayName);
    if (Data->BinPath != NULL)
        HeapFree(ProcessHeap,
                 0,
                 Data->BinPath);
    if (Data->Description != NULL)
        HeapFree(ProcessHeap,
                 0,
                 Data->Description);
    if (Data->Options != NULL)
        HeapFree(ProcessHeap,
                 0,
                 Data->Options);

    HeapFree(ProcessHeap,
             0,
             Data);
}

