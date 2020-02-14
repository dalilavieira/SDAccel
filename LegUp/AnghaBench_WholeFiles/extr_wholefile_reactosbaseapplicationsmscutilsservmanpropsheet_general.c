#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_6__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_4__ ;
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_23__ ;
typedef  struct TYPE_26__   TYPE_1__ ;
typedef  struct TYPE_25__   TYPE_13__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ UINT ;
struct TYPE_32__ {TYPE_1__* dlgInfo; scalar_t__ bDescriptionChanged; scalar_t__ bStartTypeChanged; scalar_t__ bDisplayNameChanged; scalar_t__ bBinaryPathChanged; } ;
struct TYPE_31__ {TYPE_13__* Info; TYPE_3__* pService; } ;
struct TYPE_30__ {scalar_t__ dwStartType; struct TYPE_30__* lpBinaryPathName; struct TYPE_30__* lpDisplayName; void* dwErrorControl; void* dwServiceType; } ;
struct TYPE_28__ {scalar_t__ dwControlsAccepted; scalar_t__ dwCurrentState; } ;
struct TYPE_29__ {TYPE_4__* lpServiceName; scalar_t__ lpDisplayName; TYPE_2__ ServiceStatusProcess; } ;
struct TYPE_27__ {int /*<<< orphan*/  lpServiceName; TYPE_4__* lpDisplayName; } ;
struct TYPE_26__ {TYPE_23__* pService; int /*<<< orphan*/  Info; } ;
struct TYPE_25__ {scalar_t__ bIsUserAnAdmin; } ;
typedef  TYPE_4__* PWSTR ;
typedef  TYPE_5__* PSERVICEPROPSHEET ;
typedef  TYPE_6__* PPAGEDATA ;
typedef  TYPE_4__* LPWSTR ;
typedef  TYPE_4__* LPQUERY_SERVICE_CONFIG ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int INT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 scalar_t__ AllocAndLoadString (TYPE_4__**,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  CB_ADDSTRING ; 
 int /*<<< orphan*/  CB_GETCURSEL ; 
 int /*<<< orphan*/  CB_SETCURSEL ; 
 int /*<<< orphan*/  ChangeListViewText (int /*<<< orphan*/ ,TYPE_23__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EnableWindow (int /*<<< orphan*/ ,int) ; 
 int FALSE ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 TYPE_4__* GetServiceConfig (TYPE_4__*) ; 
 TYPE_4__* GetServiceDescription (TYPE_4__*) ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*) ; 
 scalar_t__ IDC_DESCRIPTION ; 
 scalar_t__ IDC_DISP_NAME ; 
 scalar_t__ IDC_EDIT ; 
 scalar_t__ IDC_EXEPATH ; 
 scalar_t__ IDC_PAUSE ; 
 scalar_t__ IDC_RESUME ; 
 scalar_t__ IDC_SERV_NAME ; 
 scalar_t__ IDC_SERV_STATUS ; 
 scalar_t__ IDC_START ; 
 scalar_t__ IDC_START_PARAM ; 
 scalar_t__ IDC_START_TYPE ; 
 scalar_t__ IDC_STOP ; 
 scalar_t__ IDS_SERVICES_AUTO ; 
 scalar_t__ IDS_SERVICES_DIS ; 
 scalar_t__ IDS_SERVICES_STARTED ; 
 scalar_t__ IDS_SERVICES_STOPPED ; 
 int /*<<< orphan*/  LVDESC ; 
 int /*<<< orphan*/  LVNAME ; 
 int /*<<< orphan*/  LVSTARTUP ; 
 int /*<<< orphan*/  LocalFree (TYPE_4__*) ; 
 int /*<<< orphan*/  ProcessHeap ; 
 scalar_t__ SERVICE_ACCEPT_PAUSE_CONTINUE ; 
 scalar_t__ SERVICE_ACCEPT_STOP ; 
#define  SERVICE_AUTO_START 130 
#define  SERVICE_DEMAND_START 129 
#define  SERVICE_DISABLED 128 
 void* SERVICE_NO_CHANGE ; 
 scalar_t__ SERVICE_RUNNING ; 
 scalar_t__ SERVICE_STOPPED ; 
 void* SendDlgItemMessageW (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SendMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetMenuAndButtonStates (TYPE_13__*) ; 
 scalar_t__ SetServiceConfig (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ SetServiceDescription (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int TRUE ; 
 int /*<<< orphan*/  WM_GETTEXT ; 
 int /*<<< orphan*/  WM_GETTEXTLENGTH ; 
 int /*<<< orphan*/  WM_SETTEXT ; 
 int /*<<< orphan*/  hInstance ; 

__attribute__((used)) static VOID
SetButtonStates(PSERVICEPROPSHEET dlgInfo,
                HWND hwndDlg)
{
    HWND hButton;
    LPQUERY_SERVICE_CONFIG lpServiceConfig;
    DWORD Flags, State;
    UINT i;

    Flags = dlgInfo->pService->ServiceStatusProcess.dwControlsAccepted;
    State = dlgInfo->pService->ServiceStatusProcess.dwCurrentState;

    for (i = IDC_START; i <= IDC_RESUME; i++)
    {
        hButton = GetDlgItem(hwndDlg, i);
        EnableWindow (hButton, FALSE);
    }

    lpServiceConfig = GetServiceConfig(dlgInfo->pService->lpServiceName);
    if (State == SERVICE_STOPPED &&
        lpServiceConfig && lpServiceConfig->dwStartType != SERVICE_DISABLED)
    {
        hButton = GetDlgItem(hwndDlg, IDC_START);
        EnableWindow (hButton, TRUE);
    }
    else if ( (Flags & SERVICE_ACCEPT_STOP) && (State == SERVICE_RUNNING) )
    {
        hButton = GetDlgItem(hwndDlg, IDC_STOP);
        EnableWindow (hButton, TRUE);
    }
    else if ( (Flags & SERVICE_ACCEPT_PAUSE_CONTINUE) && (State == SERVICE_RUNNING) )
    {
        hButton = GetDlgItem(hwndDlg, IDC_PAUSE);
        EnableWindow (hButton, TRUE);
    }

    hButton = GetDlgItem(hwndDlg, IDC_START_PARAM);
    EnableWindow(hButton, (State == SERVICE_STOPPED && lpServiceConfig && lpServiceConfig->dwStartType != SERVICE_DISABLED));

    if (lpServiceConfig)
        HeapFree(GetProcessHeap(), 0, lpServiceConfig);

    /* set the main toolbar */
    SetMenuAndButtonStates(dlgInfo->Info);
}

__attribute__((used)) static VOID
SetServiceStatusText(PSERVICEPROPSHEET dlgInfo,
                     HWND hwndDlg)
{
    LPWSTR lpStatus;
    UINT id;

    if (dlgInfo->pService->ServiceStatusProcess.dwCurrentState == SERVICE_RUNNING)
    {
        id = IDS_SERVICES_STARTED;
    }
    else
    {
        id = IDS_SERVICES_STOPPED;
    }

    if (AllocAndLoadString(&lpStatus,
                           hInstance,
                           id))
    {
        SendDlgItemMessageW(hwndDlg,
                            IDC_SERV_STATUS,
                            WM_SETTEXT,
                            0,
                            (LPARAM)lpStatus);
        LocalFree(lpStatus);
    }
}

__attribute__((used)) static VOID
SetStartupType(LPWSTR lpServiceName,
               HWND hwndDlg)
{
    HWND hList;
    LPQUERY_SERVICE_CONFIG pServiceConfig;
    LPWSTR lpBuf;
    DWORD StartUp = 0;
    UINT i;

    hList = GetDlgItem(hwndDlg, IDC_START_TYPE);

    for (i = IDS_SERVICES_AUTO; i <= IDS_SERVICES_DIS; i++)
    {
        if (AllocAndLoadString(&lpBuf,
                               hInstance,
                               i))
        {
            SendMessageW(hList,
                         CB_ADDSTRING,
                         0,
                         (LPARAM)lpBuf);
            LocalFree(lpBuf);
        }
    }

    pServiceConfig = GetServiceConfig(lpServiceName);

    if (pServiceConfig)
    {
        switch (pServiceConfig->dwStartType)
        {
            case SERVICE_AUTO_START:   StartUp = 0; break;
            case SERVICE_DEMAND_START: StartUp = 1; break;
            case SERVICE_DISABLED:     StartUp = 2; break;
        }

        SendMessageW(hList,
                     CB_SETCURSEL,
                     StartUp,
                     0);

        HeapFree(ProcessHeap,
                 0,
                 pServiceConfig);
    }
}

__attribute__((used)) static VOID
InitGeneralPage(PSERVICEPROPSHEET dlgInfo,
                HWND hwndDlg)
{
    LPQUERY_SERVICE_CONFIG pServiceConfig;
    LPWSTR lpDescription;

    /* set the service name */
    SendDlgItemMessageW(hwndDlg,
                        IDC_SERV_NAME,
                        WM_SETTEXT,
                        0,
                        (LPARAM)dlgInfo->pService->lpServiceName);

    /* set the display name */
    SendDlgItemMessageW(hwndDlg,
                        IDC_DISP_NAME,
                        WM_SETTEXT,
                        0,
                        (LPARAM)dlgInfo->pService->lpDisplayName);

    /* set the description */
    if ((lpDescription = GetServiceDescription(dlgInfo->pService->lpServiceName)))
    {
        SendDlgItemMessageW(hwndDlg,
                            IDC_DESCRIPTION,
                            WM_SETTEXT,
                            0,
                            (LPARAM)lpDescription);

        HeapFree(ProcessHeap,
                 0,
                 lpDescription);
    }

    pServiceConfig = GetServiceConfig(dlgInfo->pService->lpServiceName);
    if (pServiceConfig)
    {
        SendDlgItemMessageW(hwndDlg,
                            IDC_EXEPATH,
                            WM_SETTEXT,
                            0,
                            (LPARAM)pServiceConfig->lpBinaryPathName);
        HeapFree(ProcessHeap,
                 0,
                 pServiceConfig);
    }


    /* set startup type */
    SetStartupType(dlgInfo->pService->lpServiceName, hwndDlg);

    SetServiceStatusText(dlgInfo,
                         hwndDlg);

    if (dlgInfo->Info->bIsUserAnAdmin)
    {
        EnableWindow(GetDlgItem(hwndDlg, IDC_EDIT), TRUE);
    }
}

VOID
SaveDlgInfo(PPAGEDATA pPageData,
            HWND hwndDlg)
{
    LPQUERY_SERVICE_CONFIG pServiceConfig = NULL;
    PWSTR pDisplayName = NULL;
    PWSTR pDescription;
    INT nLength;
    DWORD StartUp;

    pServiceConfig = HeapAlloc(ProcessHeap,
                               HEAP_ZERO_MEMORY,
                               sizeof(*pServiceConfig));
    if (pServiceConfig)
    {
        pServiceConfig->dwServiceType = SERVICE_NO_CHANGE;
        pServiceConfig->dwErrorControl = SERVICE_NO_CHANGE;
        pServiceConfig->dwStartType = SERVICE_NO_CHANGE;

        if (pPageData->bStartTypeChanged)
        {
            StartUp = SendDlgItemMessageW(hwndDlg, IDC_START_TYPE, CB_GETCURSEL, 0, 0);
            switch (StartUp)
            {
                case 0:
                    pServiceConfig->dwStartType = SERVICE_AUTO_START;
                    break;

                case 1:
                    pServiceConfig->dwStartType = SERVICE_DEMAND_START;
                    break;
                case 2:
                    pServiceConfig->dwStartType = SERVICE_DISABLED;
                    break;
            }
        }

        if (pPageData->bBinaryPathChanged)
        {
            nLength = SendDlgItemMessageW(hwndDlg, IDC_EXEPATH, WM_GETTEXTLENGTH, 0, 0);
            pServiceConfig->lpBinaryPathName = HeapAlloc(ProcessHeap,
                                                         HEAP_ZERO_MEMORY,
                                                         (nLength + 1) * sizeof(WCHAR));
            if (pServiceConfig->lpBinaryPathName != NULL)
                SendDlgItemMessageW(hwndDlg, IDC_EXEPATH, WM_GETTEXT, nLength + 1, (LPARAM)pServiceConfig->lpBinaryPathName);
        }

        if (pPageData->bDisplayNameChanged)
        {
            nLength = SendDlgItemMessageW(hwndDlg, IDC_DISP_NAME, WM_GETTEXTLENGTH, 0, 0);
            pDisplayName = HeapAlloc(ProcessHeap,
                                     HEAP_ZERO_MEMORY,
                                     (nLength + 1) * sizeof(WCHAR));
            if (pDisplayName != NULL)
            {
                SendDlgItemMessageW(hwndDlg, IDC_DISP_NAME, WM_GETTEXT, nLength + 1, (LPARAM)pDisplayName);

                if (pPageData->dlgInfo->pService->lpDisplayName)
                    HeapFree(ProcessHeap, 0, pPageData->dlgInfo->pService->lpDisplayName);

                pPageData->dlgInfo->pService->lpDisplayName = pDisplayName;
                pServiceConfig->lpDisplayName = pDisplayName;
            }
        }

        if (SetServiceConfig(pServiceConfig,
                             pPageData->dlgInfo->pService->lpServiceName,
                             NULL))
        {
            if (pPageData->bDisplayNameChanged)
                ChangeListViewText(pPageData->dlgInfo->Info,
                                   pPageData->dlgInfo->pService,
                                   LVNAME);

            if (pPageData->bStartTypeChanged)
                ChangeListViewText(pPageData->dlgInfo->Info,
                                   pPageData->dlgInfo->pService,
                                   LVSTARTUP);
        }

        if (pServiceConfig->lpBinaryPathName != NULL)
            HeapFree(ProcessHeap, 0, pServiceConfig->lpBinaryPathName);

        HeapFree(ProcessHeap, 0, pServiceConfig);
    }

    if (pPageData->bDescriptionChanged)
    {
        nLength = SendDlgItemMessageW(hwndDlg, IDC_DESCRIPTION, WM_GETTEXTLENGTH, 0, 0);
        pDescription = HeapAlloc(ProcessHeap, HEAP_ZERO_MEMORY, (nLength + 1) * sizeof(WCHAR));
        if (pDescription != NULL)
        {
            SendDlgItemMessageW(hwndDlg, IDC_DESCRIPTION, WM_GETTEXT, nLength + 1, (LPARAM)pDescription);

            if (SetServiceDescription(pPageData->dlgInfo->pService->lpServiceName,
                                      pDescription))
            {
                ChangeListViewText(pPageData->dlgInfo->Info,
                                   pPageData->dlgInfo->pService,
                                   LVDESC);
            }

            HeapFree(ProcessHeap, 0, pDescription);
        }
    }
}

