#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WPARAM ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_9__ {int bInitialized; char* szAccountName; char* szPassword1; char* szPassword2; int bLocalSystem; int bAccountChanged; TYPE_2__* pService; TYPE_1__* pServiceConfig; scalar_t__ nInteractive; } ;
struct TYPE_8__ {char* lpServiceName; } ;
struct TYPE_7__ {int /*<<< orphan*/  dwServiceType; } ;
typedef  int /*<<< orphan*/  SC_LOCK ;
typedef  scalar_t__ SC_HANDLE ;
typedef  TYPE_3__* PLOGONDATA ;
typedef  char* LPWSTR ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  scalar_t__ HWND ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  BM_GETCHECK ; 
 int /*<<< orphan*/  BM_SETCHECK ; 
 scalar_t__ BST_CHECKED ; 
 scalar_t__ BST_UNCHECKED ; 
 scalar_t__ ChangeServiceConfigW (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CloseServiceHandle (scalar_t__) ; 
 char* DEFAULT_PASSWORD ; 
 int /*<<< orphan*/  DWLP_MSGRESULT ; 
 int /*<<< orphan*/  EnableWindow (scalar_t__,int) ; 
 int FALSE ; 
 scalar_t__ GetDlgItem (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetDlgItemText (scalar_t__,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  GetError () ; 
 int /*<<< orphan*/  GetModuleHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IDC_LOGON_ACCOUNTNAME ; 
 int /*<<< orphan*/  IDC_LOGON_INTERACTIVE ; 
 int /*<<< orphan*/  IDC_LOGON_PASSWORD1 ; 
 int /*<<< orphan*/  IDC_LOGON_PASSWORD2 ; 
 int /*<<< orphan*/  IDC_LOGON_PW1TEXT ; 
 int /*<<< orphan*/  IDC_LOGON_PW2TEXT ; 
 int /*<<< orphan*/  IDC_LOGON_SEARCH ; 
 int /*<<< orphan*/  IDC_LOGON_SYSTEMACCOUNT ; 
 int /*<<< orphan*/  IDC_LOGON_THISACCOUNT ; 
 int /*<<< orphan*/  IDS_APPNAME ; 
 int /*<<< orphan*/  IDS_INVALID_PASSWORD ; 
 int /*<<< orphan*/  IDS_NOT_SAME_PASSWORD ; 
 int /*<<< orphan*/  LockServiceDatabase (scalar_t__) ; 
 int MB_ICONWARNING ; 
 int MB_OK ; 
 scalar_t__ OpenSCManagerW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ OpenServiceW (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ResourceMessageBox (int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SC_MANAGER_LOCK ; 
 int /*<<< orphan*/  SERVICE_CHANGE_CONFIG ; 
 int /*<<< orphan*/  SERVICE_INTERACTIVE_PROCESS ; 
 int /*<<< orphan*/  SERVICE_NO_CHANGE ; 
 scalar_t__ SendDlgItemMessageW (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetDlgItemText (scalar_t__,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  SetWindowLongPtr (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int TRUE ; 
 int /*<<< orphan*/  UnlockServiceDatabase (int /*<<< orphan*/ ) ; 
 scalar_t__ wcscmp (char*,char*) ; 
 int /*<<< orphan*/  wcscpy (char*,char*) ; 

__attribute__((used)) static
VOID
SetControlStates(
    HWND hwndDlg,
    PLOGONDATA pLogonData,
    BOOL bLocalSystem)
{
    EnableWindow(GetDlgItem(hwndDlg, IDC_LOGON_INTERACTIVE), bLocalSystem);
    EnableWindow(GetDlgItem(hwndDlg, IDC_LOGON_ACCOUNTNAME), !bLocalSystem);
    EnableWindow(GetDlgItem(hwndDlg, IDC_LOGON_SEARCH), FALSE /*!bLocalSystem*/);
    EnableWindow(GetDlgItem(hwndDlg, IDC_LOGON_PW1TEXT), !bLocalSystem);
    EnableWindow(GetDlgItem(hwndDlg, IDC_LOGON_PASSWORD1), !bLocalSystem);
    EnableWindow(GetDlgItem(hwndDlg, IDC_LOGON_PW2TEXT), !bLocalSystem);
    EnableWindow(GetDlgItem(hwndDlg, IDC_LOGON_PASSWORD2), !bLocalSystem);

    if (bLocalSystem)
    {
        SendDlgItemMessageW(hwndDlg, IDC_LOGON_INTERACTIVE, BM_SETCHECK, (WPARAM)pLogonData->nInteractive, 0);

        if (pLogonData->bInitialized == TRUE)
        {
            GetDlgItemText(hwndDlg, IDC_LOGON_ACCOUNTNAME, pLogonData->szAccountName, 64);
            GetDlgItemText(hwndDlg, IDC_LOGON_PASSWORD1, pLogonData->szPassword1, 64);
            GetDlgItemText(hwndDlg, IDC_LOGON_PASSWORD2, pLogonData->szPassword2, 64);
        }

        SetDlgItemText(hwndDlg, IDC_LOGON_ACCOUNTNAME, L"");
        SetDlgItemText(hwndDlg, IDC_LOGON_PASSWORD1, L"");
        SetDlgItemText(hwndDlg, IDC_LOGON_PASSWORD2, L"");
    }
    else
    {
        if (pLogonData->bInitialized == TRUE)
            pLogonData->nInteractive = SendDlgItemMessageW(hwndDlg, IDC_LOGON_INTERACTIVE, BM_GETCHECK, 0, 0);
        SendDlgItemMessageW(hwndDlg, IDC_LOGON_INTERACTIVE, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);

        SetDlgItemText(hwndDlg, IDC_LOGON_ACCOUNTNAME, pLogonData->szAccountName);
        SetDlgItemText(hwndDlg, IDC_LOGON_PASSWORD1, pLogonData->szPassword1);
        SetDlgItemText(hwndDlg, IDC_LOGON_PASSWORD2, pLogonData->szPassword2);
    }

    pLogonData->bLocalSystem = bLocalSystem;
}

__attribute__((used)) static
BOOL
SetServiceAccount(
    LPWSTR lpServiceName,
    DWORD dwServiceType,
    LPWSTR lpStartName,
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
                                         dwServiceType,
                                         SERVICE_NO_CHANGE,
                                         SERVICE_NO_CHANGE,
                                         NULL,
                                         NULL,
                                         NULL,
                                         NULL,
                                         lpStartName,
                                         lpPassword,
                                         NULL))
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

__attribute__((used)) static
BOOL
OnQueryInitialFocus(
    HWND hwndDlg,
    PLOGONDATA pLogonData)
{
    HWND hwnd = GetDlgItem(hwndDlg, pLogonData->bLocalSystem ? IDC_LOGON_SYSTEMACCOUNT : IDC_LOGON_THISACCOUNT);

    SetWindowLongPtr(hwndDlg, DWLP_MSGRESULT, (LPARAM)hwnd);

    return TRUE;
}

__attribute__((used)) static
BOOL
OnApply(
    HWND hwndDlg,
    PLOGONDATA pLogonData)
{
    WCHAR szAccountName[64];
    WCHAR szPassword1[64];
    WCHAR szPassword2[64];
    DWORD dwServiceType = SERVICE_NO_CHANGE;
    BOOL bRet = TRUE;

    if (!pLogonData->bAccountChanged)
        return TRUE;

    if (SendDlgItemMessageW(hwndDlg, IDC_LOGON_SYSTEMACCOUNT, BM_GETCHECK, 0, 0) == BST_CHECKED)
    {
        /* System account selected */
        wcscpy(szAccountName, L"LocalSystem");
        wcscpy(szPassword1, L"");
        wcscpy(szPassword2, L"");

        /* Handle the interactive flag */
        dwServiceType = pLogonData->pServiceConfig->dwServiceType;
        if (SendDlgItemMessageW(hwndDlg, IDC_LOGON_INTERACTIVE, BM_GETCHECK, 0, 0) == BST_CHECKED)
            dwServiceType |= SERVICE_INTERACTIVE_PROCESS;
        else
            dwServiceType &= ~SERVICE_INTERACTIVE_PROCESS;
    }
    else
    {
        /* Other account selected */
        GetDlgItemText(hwndDlg, IDC_LOGON_ACCOUNTNAME, szAccountName, 64);
        GetDlgItemText(hwndDlg, IDC_LOGON_PASSWORD1, szPassword1, 64);
        GetDlgItemText(hwndDlg, IDC_LOGON_PASSWORD2, szPassword2, 64);

        if (wcscmp(szPassword1, szPassword2))
        {
            ResourceMessageBox(GetModuleHandle(NULL), hwndDlg, MB_OK | MB_ICONWARNING, IDS_APPNAME, IDS_NOT_SAME_PASSWORD);
            return FALSE;
        }

        if (!wcscmp(szPassword1, DEFAULT_PASSWORD))
        {
            ResourceMessageBox(GetModuleHandle(NULL), hwndDlg, MB_OK | MB_ICONWARNING, IDS_APPNAME, IDS_INVALID_PASSWORD);
            return FALSE;
        }
    }


    bRet = SetServiceAccount(pLogonData->pService->lpServiceName,
                             dwServiceType,
                             szAccountName,
                             szPassword1);
    if (bRet == FALSE)
    {

    }

    if (bRet == TRUE)
    {
        pLogonData->bAccountChanged = FALSE;

    }

    return bRet;
}

