#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ WPARAM ;
struct TYPE_9__ {int /*<<< orphan*/  hdc; } ;
struct TYPE_8__ {int left; int right; } ;
typedef  TYPE_1__ RECT ;
typedef  TYPE_2__ PAINTSTRUCT ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int /*<<< orphan*/  ChildWnd ;

/* Variables and functions */
 int /*<<< orphan*/  BLACK_BRUSH ; 
 int /*<<< orphan*/  BeginPaint (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  EndPaint (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  FillRect (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetStockObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InvertRect (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ SIZE_MINIMIZED ; 
 int SPLIT_WIDTH ; 

__attribute__((used)) static void draw_splitbar(HWND hWnd, int x)
{
    RECT rt;
    HDC hdc = GetDC(hWnd);

    GetClientRect(hWnd, &rt);
    rt.left = x - SPLIT_WIDTH/2;
    rt.right = x + SPLIT_WIDTH/2+1;
    InvertRect(hdc, &rt);
    ReleaseDC(hWnd, hdc);
}

__attribute__((used)) static void OnPaint(HWND hWnd, ChildWnd* pChildWnd)
{
    PAINTSTRUCT ps;
    RECT rt;
    GetClientRect(hWnd, &rt);
    BeginPaint(hWnd, &ps);

//    lastBrush = SelectObject(ps.hdc, (HBRUSH)GetStockObject(WHITE_BRUSH));
//    Rectangle(ps.hdc, rt.left, rt.top-1, rt.right, rt.bottom+1);
//    SelectObject(ps.hdc, lastBrush);
//    rt.top = rt.bottom - GetSystemMetrics(SM_CYHSCROLL);
    FillRect(ps.hdc, &rt, GetStockObject(BLACK_BRUSH));
/*
    rt.left = pChildWnd->nSplitPos-SPLIT_WIDTH/2;
    rt.right = pChildWnd->nSplitPos+SPLIT_WIDTH/2+1;
    lastBrush = SelectBrush(ps.hdc, (HBRUSH)GetStockObject(COLOR_SPLITBAR));
    Rectangle(ps.hdc, rt.left, rt.top-1, rt.right, rt.bottom+1);
    SelectObject(ps.hdc, lastBrush);
#ifdef _NO_EXTENSIONS
    rt.top = rt.bottom - GetSystemMetrics(SM_CYHSCROLL);
    FillRect(ps.hdc, &rt, GetStockObject(BLACK_BRUSH));
#endif
 */
    EndPaint(hWnd, &ps);
}

__attribute__((used)) static void OnSize(ChildWnd* pChildWnd, WPARAM wParam, LPARAM lParam)
{
    if (wParam != SIZE_MINIMIZED) {
        //resize_tree(pChildWnd, LOWORD(lParam), HIWORD(lParam));
    }
}

