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
typedef  int /*<<< orphan*/  WCHAR ;
typedef  scalar_t__ ULONG ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  scalar_t__ HANDLE ;
typedef  scalar_t__ DWORD ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  GetLastErrorText (int /*<<< orphan*/ *,int) ; 
 scalar_t__ GetSelectedProcessId () ; 
 int /*<<< orphan*/  IDS_MSG_CLOSESYSTEMPROCESS ; 
 int /*<<< orphan*/  IDS_MSG_TASKMGRWARNING ; 
 int /*<<< orphan*/  IDS_MSG_UNABLETERMINATEPRO ; 
 int /*<<< orphan*/  IDS_MSG_WARNINGTERMINATING ; 
 scalar_t__ IDYES ; 
 scalar_t__ IsCriticalProcess (scalar_t__) ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int MB_ICONSTOP ; 
 int MB_ICONWARNING ; 
 int MB_OK ; 
 int MB_TOPMOST ; 
 int MB_YESNO ; 
 scalar_t__ MessageBoxW (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NtQueryInformationProcess (scalar_t__,int /*<<< orphan*/ ,scalar_t__*,int,int /*<<< orphan*/ *) ; 
 scalar_t__ OpenProcess (int,scalar_t__,scalar_t__) ; 
 int PROCESS_QUERY_INFORMATION ; 
 int PROCESS_TERMINATE ; 
 int /*<<< orphan*/  ProcessBreakOnTermination ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  TerminateProcess (scalar_t__,int) ; 
 int /*<<< orphan*/  hInst ; 
 int /*<<< orphan*/  hMainWnd ; 

void ProcessPage_OnEndProcess(void)
{
    DWORD   dwProcessId;
    HANDLE  hProcess;
    WCHAR   szTitle[256];
    WCHAR   strErrorText[260];

    dwProcessId = GetSelectedProcessId();

    if (dwProcessId == 0)
        return;

    hProcess = OpenProcess(PROCESS_TERMINATE | PROCESS_QUERY_INFORMATION, FALSE, dwProcessId);

    /* forbid killing system processes even if we have privileges -- sigh, windows kludge! */
    if (hProcess && IsCriticalProcess(hProcess))
    {
        LoadStringW(hInst, IDS_MSG_UNABLETERMINATEPRO, szTitle, 256);
        LoadStringW(hInst, IDS_MSG_CLOSESYSTEMPROCESS, strErrorText, 256);
        MessageBoxW(hMainWnd, strErrorText, szTitle, MB_OK|MB_ICONWARNING|MB_TOPMOST);
        CloseHandle(hProcess);
        return;
    }

    /* if this is a standard process just ask for confirmation before doing it */
    LoadStringW(hInst, IDS_MSG_WARNINGTERMINATING, strErrorText, 256);
    LoadStringW(hInst, IDS_MSG_TASKMGRWARNING, szTitle, 256);
    if (MessageBoxW(hMainWnd, strErrorText, szTitle, MB_YESNO|MB_ICONWARNING|MB_TOPMOST) != IDYES)
    {
        if (hProcess) CloseHandle(hProcess);
        return;
    }

    /* no such process or not enough privileges to open its token */
    if (!hProcess)
    {
        GetLastErrorText(strErrorText, 260);
        LoadStringW(hInst, IDS_MSG_UNABLETERMINATEPRO, szTitle, 256);
        MessageBoxW(hMainWnd, strErrorText, szTitle, MB_OK|MB_ICONSTOP|MB_TOPMOST);
        return;
    }

    /* try to kill it, and notify the user if didn't work */
    if (!TerminateProcess(hProcess, 1))
    {
        GetLastErrorText(strErrorText, 260);
        LoadStringW(hInst, IDS_MSG_UNABLETERMINATEPRO, szTitle, 256);
        MessageBoxW(hMainWnd, strErrorText, szTitle, MB_OK|MB_ICONSTOP|MB_TOPMOST);
    }

    CloseHandle(hProcess);
}

BOOL IsCriticalProcess(HANDLE hProcess)
{
    NTSTATUS status;
    ULONG BreakOnTermination;

    /* return early if the process handle does not exist */
    if (!hProcess)
        return FALSE;

    /* the important system processes that we don't want to let the user
       kill come marked as critical, this simplifies the check greatly.

       a critical process brings the system down when is terminated:
       <http://www.geoffchappell.com/studies/windows/win32/ntdll/api/rtl/peb/setprocessiscritical.htm> */

    status = NtQueryInformationProcess(hProcess,
                                       ProcessBreakOnTermination,
                                       &BreakOnTermination,
                                       sizeof(ULONG),
                                       NULL);

    if (NT_SUCCESS(status) && BreakOnTermination)
        return TRUE;

    return FALSE;
}

void ProcessPage_OnEndProcessTree(void)
{
    DWORD   dwProcessId;
    HANDLE  hProcess;
    WCHAR   szTitle[256];
    WCHAR   strErrorText[260];

    dwProcessId = GetSelectedProcessId();

    if (dwProcessId == 0)
        return;

    hProcess = OpenProcess(PROCESS_TERMINATE | PROCESS_QUERY_INFORMATION, FALSE, dwProcessId);

    /* forbid killing system processes even if we have privileges -- sigh, windows kludge! */
    if (hProcess && IsCriticalProcess(hProcess))
    {
        LoadStringW(hInst, IDS_MSG_UNABLETERMINATEPRO, szTitle, 256);
        LoadStringW(hInst, IDS_MSG_CLOSESYSTEMPROCESS, strErrorText, 256);
        MessageBoxW(hMainWnd, strErrorText, szTitle, MB_OK|MB_ICONWARNING|MB_TOPMOST);
        CloseHandle(hProcess);
        return;
    }

    LoadStringW(hInst, IDS_MSG_WARNINGTERMINATING, strErrorText, 256);
    LoadStringW(hInst, IDS_MSG_TASKMGRWARNING, szTitle, 256);
    if (MessageBoxW(hMainWnd, strErrorText, szTitle, MB_YESNO|MB_ICONWARNING) != IDYES)
    {
        if (hProcess) CloseHandle(hProcess);
        return;
    }

    if (!hProcess)
    {
        GetLastErrorText(strErrorText, 260);
        LoadStringW(hInst, IDS_MSG_UNABLETERMINATEPRO, szTitle, 256);
        MessageBoxW(hMainWnd, strErrorText, szTitle, MB_OK|MB_ICONSTOP);
        return;
    }

    if (!TerminateProcess(hProcess, 0))
    {
        GetLastErrorText(strErrorText, 260);
        LoadStringW(hInst, IDS_MSG_UNABLETERMINATEPRO, szTitle, 256);
        MessageBoxW(hMainWnd, strErrorText, szTitle, MB_OK|MB_ICONSTOP);
    }

    CloseHandle(hProcess);
}

