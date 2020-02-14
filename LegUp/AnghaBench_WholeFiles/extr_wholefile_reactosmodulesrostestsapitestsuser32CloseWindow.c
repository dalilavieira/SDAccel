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

/* Variables and functions */
 int /*<<< orphan*/  CloseWindow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DestroyWindow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/ * GetActiveWindow () ; 
 int /*<<< orphan*/ * GetDesktopWindow () ; 
 int /*<<< orphan*/ * GetFocus () ; 
 int /*<<< orphan*/ * GetForegroundWindow () ; 
 int /*<<< orphan*/  KillTimer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  SW_RESTORE ; 
 int /*<<< orphan*/  SetActiveWindow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetForegroundWindow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetTimer (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ShowWindow (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
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
 int s_nWM_SYSCOMMAND ; 
 int s_nWM_WINDOWPOSCHANGING ; 
 int /*<<< orphan*/  trace (char*,...) ; 

__attribute__((used)) static void
DoMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_TIMER || !s_bTracing)
        return;

    trace("uMsg:0x%04X, wParam:0x%08lX, lParam:0x%08lX\n", uMsg, (LONG)wParam, (LONG)lParam);

    if (uMsg == WM_SYSCOMMAND)
    {
        ++s_nWM_SYSCOMMAND;
    }

    if (uMsg == WM_NCACTIVATE)
        ++s_nWM_NCACTIVATE;

    if (uMsg == WM_WINDOWPOSCHANGING)
        ++s_nWM_WINDOWPOSCHANGING;

    if (uMsg == WM_ACTIVATE)
        ++s_nWM_ACTIVATE;
}

__attribute__((used)) static void
OnTimer(HWND hwnd, UINT id)
{
    KillTimer(hwnd, id);
    switch (id)
    {
        //
        // SetActiveWindow(GetDesktopWindow());
        //
        case 0:
            SetForegroundWindow(GetDesktopWindow());
            SetActiveWindow(GetDesktopWindow());
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == NULL, "GetActiveWindow() != NULL\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            s_nWM_SYSCOMMAND = 0;
            s_nWM_NCACTIVATE = 0;
            s_nWM_WINDOWPOSCHANGING = 0;
            s_nWM_ACTIVATE = 0;
            s_bTracing = TRUE;
            trace("CloseWindow(hwnd): tracing...\n");
            ok(CloseWindow(hwnd), "CloseWindow failed\n");
            break;
        case 1:
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            s_bTracing = FALSE;
            trace("CloseWindow(hwnd): tracing done\n");
            ok(s_nWM_SYSCOMMAND == 0, "WM_SYSCOMMAND: %d\n", s_nWM_SYSCOMMAND);
            ok(s_nWM_NCACTIVATE == 1, "WM_NCACTIVATE: %d\n", s_nWM_NCACTIVATE);
            ok(s_nWM_WINDOWPOSCHANGING == 2, "WM_WINDOWPOSCHANGING: %d\n", s_nWM_WINDOWPOSCHANGING);
            ok(s_nWM_ACTIVATE == 1, "WM_ACTIVATE: %d\n", s_nWM_ACTIVATE);
            ShowWindow(hwnd, SW_RESTORE);
            break;
        //
        // SetActiveWindow(hwnd);
        //
        case 2:
            SetForegroundWindow(GetDesktopWindow());
            SetActiveWindow(hwnd);
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == hwnd, "GetFocus() != hwnd\n");
            s_nWM_SYSCOMMAND = 0;
            s_nWM_NCACTIVATE = 0;
            s_nWM_WINDOWPOSCHANGING = 0;
            s_nWM_ACTIVATE = 0;
            s_bTracing = TRUE;
            trace("CloseWindow(hwnd): tracing...\n");
            ok(CloseWindow(hwnd), "CloseWindow failed\n");
            break;
        case 3:
            ok(GetForegroundWindow() == NULL, "GetForegroundWindow() != NULL\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            s_bTracing = FALSE;
            trace("CloseWindow(hwnd): tracing done\n");
            ok(s_nWM_SYSCOMMAND == 0, "WM_SYSCOMMAND: %d\n", s_nWM_SYSCOMMAND);
            ok(s_nWM_NCACTIVATE == 0, "WM_NCACTIVATE: %d\n", s_nWM_NCACTIVATE);
            ok(s_nWM_WINDOWPOSCHANGING == 1, "WM_WINDOWPOSCHANGING: %d\n", s_nWM_WINDOWPOSCHANGING);
            ok(s_nWM_ACTIVATE == 0, "WM_ACTIVATE: %d\n", s_nWM_ACTIVATE);
            ShowWindow(hwnd, SW_RESTORE);
            break;
        //
        // SetForegroundWindow(hwnd);
        //
        case 4:
            SetActiveWindow(GetDesktopWindow());
            SetForegroundWindow(hwnd);
            ok(GetForegroundWindow() == hwnd, "GetForegroundWindow() != hwnd\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == hwnd, "GetFocus() != hwnd\n");
            s_nWM_SYSCOMMAND = 0;
            s_nWM_NCACTIVATE = 0;
            s_nWM_WINDOWPOSCHANGING = 0;
            s_nWM_ACTIVATE = 0;
            s_bTracing = TRUE;
            trace("CloseWindow(hwnd): tracing...\n");
            ok(CloseWindow(hwnd), "CloseWindow failed\n");
            break;
        case 5:
            ok(GetForegroundWindow() == hwnd, "GetForegroundWindow() != hwnd\n");
            ok(GetActiveWindow() == hwnd, "GetActiveWindow() != hwnd\n");
            ok(GetFocus() == NULL, "GetFocus() != NULL\n");
            s_bTracing = FALSE;
            trace("CloseWindow(hwnd): tracing done\n");
            ok(s_nWM_SYSCOMMAND == 0, "WM_SYSCOMMAND: %d\n", s_nWM_SYSCOMMAND);
            ok(s_nWM_NCACTIVATE == 0, "WM_NCACTIVATE: %d\n", s_nWM_NCACTIVATE);
            ok(s_nWM_WINDOWPOSCHANGING == 1, "WM_WINDOWPOSCHANGING: %d\n", s_nWM_WINDOWPOSCHANGING);
            ok(s_nWM_ACTIVATE == 0, "WM_ACTIVATE: %d\n", s_nWM_ACTIVATE);
            ShowWindow(hwnd, SW_RESTORE);
            break;
        default: // finish
            DestroyWindow(hwnd);
            return;
    }
    SetTimer(hwnd, id + 1, TIMER_INTERVAL, NULL);
}

