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
typedef  scalar_t__ WPARAM ;
typedef  scalar_t__ UINT ;
typedef  scalar_t__ LPARAM ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int /*<<< orphan*/ * HWND ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CloseWindow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DestroyWindow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/ * GetActiveWindow () ; 
 int /*<<< orphan*/  GetDesktopWindow () ; 
 int /*<<< orphan*/ * GetFocus () ; 
 int /*<<< orphan*/ * GetForegroundWindow () ; 
 int ISMEX_CALLBACK ; 
 int ISMEX_NOSEND ; 
 int ISMEX_NOTIFY ; 
 int ISMEX_REPLIED ; 
 int ISMEX_SEND ; 
 scalar_t__ InSendMessage () ; 
 int InSendMessageEx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KillTimer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ SC_RESTORE ; 
 int /*<<< orphan*/  SetActiveWindow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetForegroundWindow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetTimer (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SwitchToThisWindow (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TIMER_INTERVAL ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ WM_ACTIVATE ; 
 scalar_t__ WM_NCACTIVATE ; 
 scalar_t__ WM_SYSCOMMAND ; 
 scalar_t__ WM_TIMER ; 
 scalar_t__ WM_WINDOWPOSCHANGING ; 
 int /*<<< orphan*/  ok (int,char*,...) ; 
 int /*<<< orphan*/  s_bTracing ; 
 int s_nWM_ACTIVATE ; 
 int s_nWM_NCACTIVATE ; 
 int s_nWM_SYSCOMMAND_NOT_SC_RESTORE ; 
 int s_nWM_SYSCOMMAND_SC_RESTORE ; 
 int s_nWM_WINDOWPOSCHANGING ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int /*<<< orphan*/  trace (char*,...) ; 

__attribute__((used)) static const char *
DumpInSMEX(void)
{
    static char s_buf[128];
    DWORD dwRet = InSendMessageEx(NULL);
    if (dwRet == ISMEX_NOSEND)
    {
        strcpy(s_buf, "ISMEX_NOSEND,");
        return s_buf;
    }
    s_buf[0] = 0;
    if (dwRet & ISMEX_CALLBACK)
        strcat(s_buf, "ISMEX_CALLBACK,");
    if (dwRet & ISMEX_NOTIFY)
        strcat(s_buf, "ISMEX_NOTIFY,");
    if (dwRet & ISMEX_REPLIED)
        strcat(s_buf, "ISMEX_REPLIED,");
    if (dwRet & ISMEX_SEND)
        strcat(s_buf, "ISMEX_SEND,");
    return s_buf;
}

__attribute__((used)) static void
DoMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_TIMER || !s_bTracing)
        return;

    trace("%s: uMsg:0x%04X, wParam:0x%08lX, lParam:0x%08lX, ISMEX_:%s\n",
          (InSendMessage() ? "S" : "P"), uMsg, (LONG)wParam, (LONG)lParam,
           DumpInSMEX());

    if (uMsg == WM_SYSCOMMAND)  // 0x0112
    {
        ok(InSendMessageEx(NULL) == ISMEX_NOSEND,
           "InSendMessageEx(NULL) was 0x%08lX\n", InSendMessageEx(NULL));
        if (wParam == SC_RESTORE)
            ++s_nWM_SYSCOMMAND_SC_RESTORE;
        else
            ++s_nWM_SYSCOMMAND_NOT_SC_RESTORE;
    }

    if (uMsg == WM_NCACTIVATE)  // 0x0086
    {
        ok(InSendMessageEx(NULL) == ISMEX_NOSEND,
           "InSendMessageEx(NULL) was 0x%08lX\n", InSendMessageEx(NULL));
        ++s_nWM_NCACTIVATE;
    }

    if (uMsg == WM_WINDOWPOSCHANGING)   // 0x0046
    {
        ok(InSendMessageEx(NULL) == ISMEX_NOSEND,
           "InSendMessageEx(NULL) was 0x%08lX\n", InSendMessageEx(NULL));
        ++s_nWM_WINDOWPOSCHANGING;
    }

    if (uMsg == WM_ACTIVATE)    // 0x0006
    {
        ok(InSendMessageEx(NULL) == ISMEX_NOSEND,
           "InSendMessageEx(NULL) was 0x%08lX\n", InSendMessageEx(NULL));
        ++s_nWM_ACTIVATE;
    }
}

__attribute__((used)) static void
OnTimer(HWND hwnd, UINT id)
{
    KillTimer(hwnd, id);
    switch (id)
    {
        //
        // SwitchToThisWindow(TRUE)
        //
        case 0: // minimize
            SetForegroundWindow(GetDesktopWindow());
            SetActiveWindow(GetDesktopWindow());
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == NULL, "GetActiveWindow() != NULL\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            CloseWindow(hwnd);  // minimize
            break;
        case 1: // start tracing
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            s_nWM_SYSCOMMAND_SC_RESTORE = 0;
            s_nWM_SYSCOMMAND_NOT_SC_RESTORE = 0;
            s_nWM_NCACTIVATE = 0;
            s_nWM_WINDOWPOSCHANGING = 0;
            s_nWM_ACTIVATE = 0;
            s_bTracing = TRUE;
            SwitchToThisWindow(hwnd, TRUE);
            trace("SwitchToThisWindow(TRUE): tracing...\n");
            break;
        case 2: // tracing done
            s_bTracing = FALSE;
            trace("SwitchToThisWindow(TRUE): tracing done\n");
            ok(GetForegroundWindow() == hwnd, "GetForegroundWindow() != hwnd\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == hwnd, "GetFocus() != hwnd\n");
            ok(s_nWM_SYSCOMMAND_SC_RESTORE == 1, "WM_SYSCOMMAND SC_RESTORE: %d\n", s_nWM_SYSCOMMAND_SC_RESTORE);
            ok(!s_nWM_SYSCOMMAND_NOT_SC_RESTORE, "WM_SYSCOMMAND non-SC_RESTORE: %d\n", s_nWM_SYSCOMMAND_NOT_SC_RESTORE);
            ok(s_nWM_NCACTIVATE == 1, "WM_NCACTIVATE: %d\n", s_nWM_NCACTIVATE);
            ok(s_nWM_WINDOWPOSCHANGING == 2, "WM_WINDOWPOSCHANGING: %d\n", s_nWM_WINDOWPOSCHANGING);
            ok(s_nWM_ACTIVATE == 1, "WM_ACTIVATE: %d\n", s_nWM_ACTIVATE);
            break;
        //
        // SwitchToThisWindow(FALSE)
        //
        case 3: // minimize
            SetForegroundWindow(GetDesktopWindow());
            SetActiveWindow(GetDesktopWindow());
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == NULL, "GetActiveWindow() != NULL\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            CloseWindow(hwnd);  // minimize
            break;
        case 4: // start tracing
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            s_nWM_SYSCOMMAND_SC_RESTORE = 0;
            s_nWM_SYSCOMMAND_NOT_SC_RESTORE = 0;
            s_nWM_NCACTIVATE = 0;
            s_nWM_WINDOWPOSCHANGING = 0;
            s_nWM_ACTIVATE = 0;
            s_bTracing = TRUE;
            SwitchToThisWindow(hwnd, FALSE);
            trace("SwitchToThisWindow(FALSE): tracing...\n");
            break;
        case 5: // tracing done
            s_bTracing = FALSE;
            trace("SwitchToThisWindow(FALSE): tracing done\n");
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            ok(!s_nWM_SYSCOMMAND_SC_RESTORE, "WM_SYSCOMMAND SC_RESTORE: %d\n", s_nWM_SYSCOMMAND_SC_RESTORE);
            ok(!s_nWM_SYSCOMMAND_NOT_SC_RESTORE, "WM_SYSCOMMAND non-SC_RESTORE: %d\n", s_nWM_SYSCOMMAND_NOT_SC_RESTORE);
            ok(!s_nWM_NCACTIVATE, "WM_NCACTIVATE: %d\n", s_nWM_NCACTIVATE);
            ok(!s_nWM_WINDOWPOSCHANGING, "WM_WINDOWPOSCHANGING: %d\n", s_nWM_WINDOWPOSCHANGING);
            ok(!s_nWM_ACTIVATE, "WM_ACTIVATE: %d\n", s_nWM_ACTIVATE);
            break;
        default: // finish
            DestroyWindow(hwnd);
            return;
    }
    SetTimer(hwnd, id + 1, TIMER_INTERVAL, NULL);
}

