#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tConfig ;
typedef  int /*<<< orphan*/  szBuffer ;
typedef  int /*<<< orphan*/  WINDOWPLACEMENT ;
typedef  int /*<<< orphan*/  WCHAR ;
struct TYPE_10__ {int length; } ;
struct TYPE_9__ {int /*<<< orphan*/  hListWnd; int /*<<< orphan*/  nSplitPos; int /*<<< orphan*/  hTreeWnd; } ;
struct TYPE_8__ {int /*<<< orphan*/  bottom; int /*<<< orphan*/  right; } ;
struct TYPE_7__ {int StatusBarVisible; TYPE_4__ tPlacement; void* DataColumnSize; void* TypeColumnSize; void* NameColumnSize; int /*<<< orphan*/  TreeViewSize; } ;
typedef  TYPE_1__ RegistryBinaryConfig ;
typedef  TYPE_2__ RECT ;
typedef  char* LPCWSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int /*<<< orphan*/ * HKEY ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  COUNT_OF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CheckMenuItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DbgPrint (char*,char*,int,char*,...) ; 
 scalar_t__ ERROR_SUCCESS ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ ,TYPE_2__*) ; 
 char* GetItemPath (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int GetMenuState (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GetSubMenu (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowPlacement (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  HKEY_CURRENT_USER ; 
 int /*<<< orphan*/  IDS_MY_COMPUTER ; 
 int /*<<< orphan*/  ID_VIEW_MENU ; 
 int /*<<< orphan*/  ID_VIEW_STATUSBAR ; 
 void* ListView_GetColumnWidth (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ListView_SetColumnWidth (int /*<<< orphan*/ ,int,void*) ; 
 scalar_t__ LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int MAX_PATH ; 
 int MF_BYCOMMAND ; 
 int MF_CHECKED ; 
 int MF_UNCHECKED ; 
 scalar_t__ QueryStringValue (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_BINARY ; 
 int /*<<< orphan*/  REG_SZ ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ *) ; 
 scalar_t__ RegCreateKeyW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 scalar_t__ RegOpenKeyW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 scalar_t__ RegQueryValueExW (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  RegSetValueExW (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ResizeWnd (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ SUCCEEDED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SW_HIDE ; 
 int /*<<< orphan*/  SW_SHOW ; 
 int /*<<< orphan*/  SW_SHOWNORMAL ; 
 int /*<<< orphan*/  S_OK ; 
 int /*<<< orphan*/  SelectNode (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetWindowPlacement (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  ShowWindow (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  StringCbCatW (int /*<<< orphan*/ *,int,char*) ; 
 TYPE_3__* g_pChildWnd ; 
 int /*<<< orphan*/  g_szGeneralRegKey ; 
 char* get_root_key_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hFrameWnd ; 
 int /*<<< orphan*/  hInst ; 
 int /*<<< orphan*/  hMenuFrame ; 
 int /*<<< orphan*/  hStatusBar ; 
 scalar_t__ wcslen (int /*<<< orphan*/ *) ; 

extern void LoadSettings(void)
{
    HKEY hKey = NULL;
    WCHAR szBuffer[MAX_PATH];

    if (RegOpenKeyW(HKEY_CURRENT_USER, g_szGeneralRegKey, &hKey) == ERROR_SUCCESS)
    {
        RegistryBinaryConfig tConfig;
        DWORD iBufferSize = sizeof(tConfig);
        BOOL bVisible = FALSE;

        if (RegQueryValueExW(hKey, L"View", NULL, NULL, (LPBYTE)&tConfig, &iBufferSize) == ERROR_SUCCESS)
        {
            if (iBufferSize == sizeof(tConfig))
            {
                RECT rcTemp;

                /* Update status bar settings */
                CheckMenuItem(GetSubMenu(hMenuFrame, ID_VIEW_MENU), ID_VIEW_STATUSBAR, MF_BYCOMMAND | (tConfig.StatusBarVisible ? MF_CHECKED : MF_UNCHECKED));
                ShowWindow(hStatusBar, (tConfig.StatusBarVisible ? SW_SHOW : SW_HIDE));

                /* Update listview column width */
                (void)ListView_SetColumnWidth(g_pChildWnd->hListWnd, 0, tConfig.NameColumnSize);
                (void)ListView_SetColumnWidth(g_pChildWnd->hListWnd, 1, tConfig.TypeColumnSize);
                (void)ListView_SetColumnWidth(g_pChildWnd->hListWnd, 2, tConfig.DataColumnSize);

                /* Update treeview (splitter) */
                GetClientRect(hFrameWnd, &rcTemp);
                g_pChildWnd->nSplitPos = tConfig.TreeViewSize;
                ResizeWnd(rcTemp.right, rcTemp.bottom);

                /* Apply program window settings */
                tConfig.tPlacement.length = sizeof(WINDOWPLACEMENT);
                bVisible = SetWindowPlacement(hFrameWnd, &tConfig.tPlacement);
            }
        }

        /* In case we fail to restore the window, or open the key, show normal */
        if (!bVisible)
            ShowWindow(hFrameWnd, SW_SHOWNORMAL);

        /* Restore key position */
        if (QueryStringValue(HKEY_CURRENT_USER, g_szGeneralRegKey, L"LastKey", szBuffer, COUNT_OF(szBuffer)) == ERROR_SUCCESS)
        {
            SelectNode(g_pChildWnd->hTreeWnd, szBuffer);
        }

        RegCloseKey(hKey);
    }
    else
    {
        /* Failed to open key, show normal */
        ShowWindow(hFrameWnd, SW_SHOWNORMAL);
    }
}

extern void SaveSettings(void)
{
    HKEY hKey = NULL;

    if (RegCreateKeyW(HKEY_CURRENT_USER, g_szGeneralRegKey, &hKey) == ERROR_SUCCESS)
    {
        RegistryBinaryConfig tConfig;
        DWORD iBufferSize = sizeof(tConfig);
        WCHAR szBuffer[MAX_PATH]; /* FIXME: a complete registry path can be longer than that */
        LPCWSTR keyPath, rootName;
        HKEY hRootKey;

        /* Save key position */
        keyPath = GetItemPath(g_pChildWnd->hTreeWnd, 0, &hRootKey);
        rootName = get_root_key_name(hRootKey);

        /* Load "My Computer" string and complete it */
        if (LoadStringW(hInst, IDS_MY_COMPUTER, szBuffer, COUNT_OF(szBuffer)) &&
            SUCCEEDED(StringCbCatW(szBuffer, sizeof(szBuffer), L"\\")) &&
            SUCCEEDED(StringCbCatW(szBuffer, sizeof(szBuffer), rootName)) &&
            SUCCEEDED(StringCbCatW(szBuffer, sizeof(szBuffer), L"\\")))
        {
            HRESULT hr = S_OK;
            if (keyPath)
                hr = StringCbCatW(szBuffer, sizeof(szBuffer), keyPath);
            if (SUCCEEDED(hr))
                RegSetValueExW(hKey, L"LastKey", 0, REG_SZ, (LPBYTE)szBuffer, (DWORD)wcslen(szBuffer) * sizeof(WCHAR));
            else
                DbgPrint("err: (%s:%d): Buffer not big enough for '%S + %S'\n", __FILE__, __LINE__, rootName, keyPath);
        }
        else
        {
            DbgPrint("err: (%s:%d): Buffer not big enough for '%S'\n", __FILE__, __LINE__, rootName);
        }

        /* Get statusbar settings */
        tConfig.StatusBarVisible = ((GetMenuState(GetSubMenu(hMenuFrame, ID_VIEW_MENU), ID_VIEW_STATUSBAR, MF_BYCOMMAND) & MF_CHECKED) ? 1 : 0);

        /* Get splitter position */
        tConfig.TreeViewSize = g_pChildWnd->nSplitPos;

        /* Get list view column width*/
        tConfig.NameColumnSize = ListView_GetColumnWidth(g_pChildWnd->hListWnd, 0);
        tConfig.TypeColumnSize = ListView_GetColumnWidth(g_pChildWnd->hListWnd, 1);
        tConfig.DataColumnSize = ListView_GetColumnWidth(g_pChildWnd->hListWnd, 2);

        /* Get program window settings */
        tConfig.tPlacement.length = sizeof(WINDOWPLACEMENT);
        GetWindowPlacement(hFrameWnd, &tConfig.tPlacement);

        /* Save all the data */
        RegSetValueExW(hKey, L"View", 0, REG_BINARY, (LPBYTE)&tConfig, iBufferSize);

        RegCloseKey(hKey);
    }
}

