#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_8__ ;
typedef  struct TYPE_35__   TYPE_7__ ;
typedef  struct TYPE_34__   TYPE_5__ ;
typedef  struct TYPE_33__   TYPE_4__ ;
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ WPARAM ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_36__ {scalar_t__ ThemeActive; TYPE_3__* Theme; TYPE_2__* Color; TYPE_2__* Size; } ;
struct TYPE_35__ {int /*<<< orphan*/ * crColor; } ;
struct TYPE_34__ {scalar_t__ pwszFile; scalar_t__ pwszAction; int /*<<< orphan*/  desktop_color; } ;
struct TYPE_33__ {void* bInitializing; TYPE_8__ ActiveTheme; TYPE_3__* pThemes; int /*<<< orphan*/  hbmpThemePreview; scalar_t__ hdcThemePreview; TYPE_8__ ClassicTheme; void* bSchemeChanged; void* bThemeChanged; TYPE_7__ Scheme; } ;
struct TYPE_32__ {scalar_t__ DisplayName; struct TYPE_32__* NextTheme; TYPE_2__* ColoursList; TYPE_2__* SizesList; } ;
struct TYPE_31__ {struct TYPE_31__* ChildStyle; scalar_t__ DisplayName; struct TYPE_31__* NextStyle; } ;
struct TYPE_30__ {int /*<<< orphan*/  bottom; int /*<<< orphan*/  right; } ;
typedef  TYPE_1__ RECT ;
typedef  int /*<<< orphan*/ * PVOID ;
typedef  TYPE_2__* PTHEME_STYLE ;
typedef  TYPE_3__* PTHEME ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  LONG_PTR ;
typedef  scalar_t__ INT_PTR ;
typedef  scalar_t__ INT ;
typedef  scalar_t__ HWND ;
typedef  int /*<<< orphan*/  HDC ;
typedef  TYPE_4__ GLOBALS ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CB_ADDSTRING ; 
 scalar_t__ CB_ERR ; 
 int /*<<< orphan*/  CB_GETCURSEL ; 
 int /*<<< orphan*/  CB_GETITEMDATA ; 
 int /*<<< orphan*/  CB_RESETCONTENT ; 
 int /*<<< orphan*/  CB_SETCURSEL ; 
 int /*<<< orphan*/  CB_SETITEMDATA ; 
 size_t COLOR_DESKTOP ; 
 int /*<<< orphan*/  CreateCompatibleBitmap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ CreateCompatibleDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DWLP_USER ; 
 scalar_t__ DrawThemePreview (scalar_t__,TYPE_7__*,TYPE_8__*,TYPE_1__*) ; 
 scalar_t__ FALSE ; 
 scalar_t__ FindOrAppendTheme (TYPE_3__*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_8__*) ; 
 int /*<<< orphan*/  GetActiveClassicTheme (TYPE_3__*,TYPE_8__*) ; 
 int /*<<< orphan*/  GetActiveTheme (TYPE_3__*,TYPE_8__*) ; 
 int /*<<< orphan*/  GetClientRect (scalar_t__,TYPE_1__*) ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ *) ; 
 scalar_t__ GetDlgItem (scalar_t__,int) ; 
 int /*<<< orphan*/  GetParent (scalar_t__) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 scalar_t__ HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*) ; 
 int IDC_APPEARANCE_COLORSCHEME ; 
 int IDC_APPEARANCE_PREVIEW ; 
 int IDC_APPEARANCE_SIZE ; 
 int IDC_APPEARANCE_VISUAL_STYLE ; 
 int /*<<< orphan*/  LoadCurrentScheme (TYPE_7__*) ; 
 int /*<<< orphan*/  LoadSchemeFromReg (TYPE_7__*,TYPE_8__*) ; 
 int /*<<< orphan*/  LoadSchemeFromTheme (TYPE_7__*,TYPE_8__*) ; 
 TYPE_3__* LoadThemes () ; 
 int /*<<< orphan*/  PSM_CHANGED ; 
 int /*<<< orphan*/  PVM_SET_HDC_PREVIEW ; 
 int /*<<< orphan*/  PVM_UPDATETHEME ; 
 int /*<<< orphan*/  PostMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SelectObject (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SendDlgItemMessage (scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* SendMessage (scalar_t__,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetWindowLongPtr (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* TRUE ; 
 TYPE_5__ g_GlobalData ; 
 scalar_t__ wcscmp (scalar_t__,char*) ; 

__attribute__((used)) static void
AppearancePage_UpdateThemePreview(HWND hwndDlg, GLOBALS *g)
{
    if (g->ActiveTheme.ThemeActive)
    {
        RECT rcWindow;

        GetClientRect(GetDlgItem(hwndDlg, IDC_APPEARANCE_PREVIEW), &rcWindow);
        if (DrawThemePreview(g->hdcThemePreview, &g->Scheme, &g->ActiveTheme, &rcWindow))
        {
            SendDlgItemMessage(hwndDlg, IDC_APPEARANCE_PREVIEW, PVM_SET_HDC_PREVIEW, 0, (LPARAM)g->hdcThemePreview);
            return;
        }
    }

    SendDlgItemMessage(hwndDlg, IDC_APPEARANCE_PREVIEW, PVM_UPDATETHEME, 0, (LPARAM)&g->Scheme);
    SendDlgItemMessage(hwndDlg, IDC_APPEARANCE_PREVIEW, PVM_SET_HDC_PREVIEW, 0, 0);
}

__attribute__((used)) static void
AppearancePage_LoadSelectedScheme(HWND hwndDlg, GLOBALS *g)
{
    if (g->ActiveTheme.ThemeActive == FALSE )
    {
        LoadSchemeFromReg(&g->Scheme, &g->ActiveTheme);
    }
    else
    {
        LoadSchemeFromTheme(&g->Scheme, &g->ActiveTheme);
    }

    g_GlobalData.desktop_color = g->Scheme.crColor[COLOR_DESKTOP];
}

__attribute__((used)) static void
AppearancePage_ShowStyles(HWND hwndDlg, int nIDDlgItem, PTHEME_STYLE pStyles, PTHEME_STYLE pActiveStyle)
{
    int iListIndex;
    HWND hwndList = GetDlgItem(hwndDlg, nIDDlgItem);
    PTHEME_STYLE pCurrentStyle;

    SendMessage(hwndList, CB_RESETCONTENT , 0, 0);

    for (pCurrentStyle = pStyles;
         pCurrentStyle;
         pCurrentStyle = pCurrentStyle->NextStyle)
    {
        iListIndex = SendMessage(hwndList, CB_ADDSTRING, 0, (LPARAM)pCurrentStyle->DisplayName);
        SendMessage(hwndList, CB_SETITEMDATA, iListIndex, (LPARAM)pCurrentStyle);
        if (pCurrentStyle == pActiveStyle)
        {
            SendMessage(hwndList, CB_SETCURSEL, (WPARAM)iListIndex, 0);
        }
    }
}

__attribute__((used)) static void
AppearancePage_ShowColorSchemes(HWND hwndDlg, GLOBALS *g)
{
    AppearancePage_ShowStyles(hwndDlg,
                              IDC_APPEARANCE_COLORSCHEME,
                              g->ActiveTheme.Theme->ColoursList,
                              g->ActiveTheme.Color);
}

__attribute__((used)) static void
AppearancePage_ShowSizes(HWND hwndDlg, GLOBALS *g)
{
    PTHEME_STYLE pSizes;

    if (g->ActiveTheme.Theme->SizesList)
        pSizes = g->ActiveTheme.Theme->SizesList;
    else
        pSizes = g->ActiveTheme.Color->ChildStyle;

    AppearancePage_ShowStyles(hwndDlg,
                              IDC_APPEARANCE_SIZE,
                              pSizes,
                              g->ActiveTheme.Size);
}

__attribute__((used)) static INT_PTR
AppearancePage_OnInit(HWND hwndDlg)
{
    INT iListIndex;
    HWND hwndTheme;
    GLOBALS *g;
    RECT rcPreview;
    HDC hdcScreen;
    PTHEME pTheme;

    g = (GLOBALS*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(GLOBALS));
    if (g == NULL)
        return FALSE;

    SetWindowLongPtr(hwndDlg, DWLP_USER, (LONG_PTR)g);

    g->bInitializing = TRUE;

    if (!LoadCurrentScheme(&g->Scheme))
        return FALSE;

    g->pThemes = LoadThemes();
    if (g->pThemes)
    {
        BOOL bLoadedTheme = FALSE;

        if (g_GlobalData.pwszAction && 
            g_GlobalData.pwszFile && 
            wcscmp(g_GlobalData.pwszAction, L"OpenMSTheme") == 0)
        {
            bLoadedTheme = FindOrAppendTheme(g->pThemes, 
                                             g_GlobalData.pwszFile,
                                             NULL,
                                             NULL,
                                             &g->ActiveTheme);
        }

        if (bLoadedTheme)
        {
            g->bThemeChanged = TRUE;
            g->bSchemeChanged = TRUE;

            PostMessageW(GetParent(hwndDlg), PSM_CHANGED, (WPARAM)hwndDlg, 0);

            AppearancePage_LoadSelectedScheme(hwndDlg, g);
        }
        else
        {
            if (!GetActiveTheme(g->pThemes, &g->ActiveTheme))
            {
                g->ActiveTheme.ThemeActive = FALSE;
            }
        }

        /*
         * Keep a copy of the selected classic theme in order to select this
         * when user selects the classic theme (and not a horrible random theme )
         */
        if (!GetActiveClassicTheme(g->pThemes, &g->ClassicTheme))
        {
            g->ClassicTheme.Theme = g->pThemes;
            g->ClassicTheme.Color = g->pThemes->ColoursList;
            g->ClassicTheme.Size = g->ClassicTheme.Color->ChildStyle;
        }

        if (g->ActiveTheme.ThemeActive == FALSE)
            g->ActiveTheme = g->ClassicTheme;

        GetClientRect(GetDlgItem(hwndDlg, IDC_APPEARANCE_PREVIEW), &rcPreview);

        hdcScreen = GetDC(NULL);
        g->hbmpThemePreview = CreateCompatibleBitmap(hdcScreen, rcPreview.right, rcPreview.bottom);
        g->hdcThemePreview = CreateCompatibleDC(hdcScreen);
        SelectObject(g->hdcThemePreview, g->hbmpThemePreview);
        ReleaseDC(NULL, hdcScreen);

        hwndTheme = GetDlgItem(hwndDlg, IDC_APPEARANCE_VISUAL_STYLE);

        for (pTheme = g->pThemes; pTheme; pTheme = pTheme->NextTheme)
        {
            iListIndex = SendMessage(hwndTheme, CB_ADDSTRING, 0, (LPARAM)pTheme->DisplayName);
            SendMessage(hwndTheme, CB_SETITEMDATA, iListIndex, (LPARAM)pTheme);
            if (pTheme == g->ActiveTheme.Theme)
            {
                SendMessage(hwndTheme, CB_SETCURSEL, (WPARAM)iListIndex, 0);
            }
        }

        if (g->ActiveTheme.Theme)
        {
            AppearancePage_ShowColorSchemes(hwndDlg, g);
            AppearancePage_ShowSizes(hwndDlg, g);
            AppearancePage_UpdateThemePreview(hwndDlg, g);
        }
    }
    g->bInitializing = FALSE;

    return FALSE;
}

__attribute__((used)) static VOID
AppearancePage_OnDestroy(HWND hwndDlg, GLOBALS *g)
{
    HeapFree(GetProcessHeap(), 0, g);
}

__attribute__((used)) static PVOID
GetSelectedData(HWND hwndDlg, int nIDDlgItem)
{
    HWND hwndCombo;
    INT sel;

    hwndCombo = GetDlgItem(hwndDlg, nIDDlgItem);
    sel = SendMessage(hwndCombo, CB_GETCURSEL, 0, 0);
    if (sel == CB_ERR)
        return NULL;
    return (PVOID)SendMessage(hwndCombo, CB_GETITEMDATA, (WPARAM)sel, 0);
}

