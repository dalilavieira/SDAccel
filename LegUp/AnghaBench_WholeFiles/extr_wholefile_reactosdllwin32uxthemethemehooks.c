#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WND_DATA ;
struct TYPE_8__ {int /*<<< orphan*/  (* SetWindowRgn ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
struct TYPE_7__ {int /*<<< orphan*/ * hthemeScrollbar; int /*<<< orphan*/ * hthemeWindow; int /*<<< orphan*/ * hTabBackgroundBmp; int /*<<< orphan*/ * hTabBackgroundBrush; scalar_t__ HasThemeRgn; } ;
typedef  TYPE_1__* PWND_DATA ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/ * HTHEME ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CloseThemeData (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ *) ; 
 scalar_t__ GetCurrentProcessId () ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 scalar_t__ GetPropW (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int GetThemeAppProperties () ; 
 int /*<<< orphan*/ * GetWindowTheme (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowThreadProcessId (int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 TYPE_1__* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 scalar_t__ MAKEINTATOM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OTD_NONCLIENT ; 
 void* OpenThemeDataEx (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int STAP_ALLOW_NONCLIENT ; 
 int /*<<< orphan*/  SetPropW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ WS_CAPTION ; 
 scalar_t__ WS_HSCROLL ; 
 scalar_t__ WS_VSCROLL ; 
 int /*<<< orphan*/  atWndContext ; 
 TYPE_2__ g_user32ApiHook ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

PWND_DATA ThemeGetWndData(HWND hWnd)
{
    PWND_DATA pwndData;

    pwndData = (PWND_DATA)GetPropW(hWnd, (LPCWSTR)MAKEINTATOM(atWndContext));
    if(pwndData == NULL)
    {
        pwndData = HeapAlloc(GetProcessHeap(), 
                            HEAP_ZERO_MEMORY, 
                            sizeof(WND_DATA));
        if(pwndData == NULL)
        {
            return NULL;
        }
        
        SetPropW( hWnd, (LPCWSTR)MAKEINTATOM(atWndContext), pwndData);
    }

    return pwndData;
}

void ThemeDestroyWndData(HWND hWnd)
{
    PWND_DATA pwndData;
    DWORD ProcessId;

    /*Do not destroy WND_DATA of a window that belong to another process */
    GetWindowThreadProcessId(hWnd, &ProcessId);
    if(ProcessId != GetCurrentProcessId())
    {
        return;
    }

    pwndData = (PWND_DATA)GetPropW(hWnd, (LPCWSTR)MAKEINTATOM(atWndContext));
    if(pwndData == NULL)
    {
        return;
    }

    if(pwndData->HasThemeRgn)
    {
        g_user32ApiHook.SetWindowRgn(hWnd, 0, TRUE);
    }

    if (pwndData->hTabBackgroundBrush != NULL)
    {
        CloseThemeData(GetWindowTheme(hWnd));

        DeleteObject(pwndData->hTabBackgroundBrush);
    }

    if (pwndData->hTabBackgroundBmp != NULL)
    {
        DeleteObject(pwndData->hTabBackgroundBmp);
    }

    if (pwndData->hthemeWindow)
    {
        CloseThemeData(pwndData->hthemeWindow);
    }

    if (pwndData->hthemeScrollbar)
    {
        CloseThemeData(pwndData->hthemeScrollbar);
    }

    HeapFree(GetProcessHeap(), 0, pwndData);

    SetPropW( hWnd, (LPCWSTR)MAKEINTATOM(atWndContext), NULL);
}

HTHEME GetNCCaptionTheme(HWND hWnd, DWORD style)
{
    PWND_DATA pwndData;

    /* We only get the theme for the window class if the window has a caption */
    if((style & WS_CAPTION) != WS_CAPTION)
        return NULL;

    /* Get theme data for this window */
    pwndData = ThemeGetWndData(hWnd);
    if (pwndData == NULL)
        return NULL;

    if (!(GetThemeAppProperties() & STAP_ALLOW_NONCLIENT))
    {
        if (pwndData->hthemeWindow)
        {
            CloseThemeData(pwndData->hthemeWindow);
            pwndData->hthemeWindow = NULL;
        }
        return NULL;
    }

    /* If the theme data was not cached, open it now */
    if (!pwndData->hthemeWindow)
        pwndData->hthemeWindow = OpenThemeDataEx(hWnd, L"WINDOW", OTD_NONCLIENT);

    return pwndData->hthemeWindow;
}

HTHEME GetNCScrollbarTheme(HWND hWnd, DWORD style)
{
    PWND_DATA pwndData;

    /* We only get the theme for the scrollbar class if the window has a scrollbar */
    if((style & (WS_HSCROLL|WS_VSCROLL)) == 0)
        return NULL;

    /* Get theme data for this window */
    pwndData = ThemeGetWndData(hWnd);
    if (pwndData == NULL)
        return NULL;

    if (!(GetThemeAppProperties() & STAP_ALLOW_NONCLIENT))
    {
        if (pwndData->hthemeScrollbar)
        {
            CloseThemeData(pwndData->hthemeScrollbar);
            pwndData->hthemeScrollbar = NULL;
        }
        return NULL;
    }

    /* If the theme data was not cached, open it now */
    if (!pwndData->hthemeScrollbar)
        pwndData->hthemeScrollbar = OpenThemeDataEx(hWnd, L"SCROLLBAR", OTD_NONCLIENT);

    return pwndData->hthemeScrollbar;
}

