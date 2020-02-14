#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  openfilename ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_6__ {int /*<<< orphan*/  hInstance; } ;
struct TYPE_5__ {int lStructSize; char* lpstrFilter; char* lpstrFile; char* lpstrInitialDir; char* lpstrDefExt; int /*<<< orphan*/ * lpTemplateName; int /*<<< orphan*/ * lpfnHook; scalar_t__ lCustData; scalar_t__ nFileExtension; scalar_t__ nFileOffset; int /*<<< orphan*/ * lpstrTitle; scalar_t__ nMaxFileTitle; int /*<<< orphan*/ * lpstrFileTitle; scalar_t__ nFilterIndex; scalar_t__ nMaxCustFilter; int /*<<< orphan*/ * lpstrCustomFilter; scalar_t__ Flags; int /*<<< orphan*/  nMaxFile; int /*<<< orphan*/  hInstance; int /*<<< orphan*/  hwndOwner; } ;
typedef  TYPE_1__ OPENFILENAMEW ;
typedef  char* LPWSTR ;
typedef  char* LPCWSTR ;
typedef  int /*<<< orphan*/  INT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  size_t GROUPFORMAT ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAYSIZE (char*) ; 
 int /*<<< orphan*/  GetCurrentDirectoryW (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  GetOpenFileNameW (TYPE_1__*) ; 
 TYPE_3__ Globals ; 
 int /*<<< orphan*/  IDS_ALL_FILES ; 
 int /*<<< orphan*/  IDS_LIBRARIES_DLL ; 
 int /*<<< orphan*/  IDS_PROGRAMS ; 
 int /*<<< orphan*/  IDS_SYMBOLS_ICO ; 
 int /*<<< orphan*/  IDS_SYMBOL_FILES ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 
 int MAX_PATH ; 
 int MAX_STRING_LEN ; 
 size_t NT_Unicode ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_1__*,int) ; 
 int /*<<< orphan*/  lstrcpyW (char*,char*) ; 
 scalar_t__ wcslen (char*) ; 

__attribute__((used)) static
VOID
DIALOG_AddFilterItem(LPWSTR* p, UINT ids, LPCWSTR filter)
{
    LoadStringW(Globals.hInstance, ids, *p, MAX_STRING_LEN);
    *p += wcslen(*p) + 1;
    lstrcpyW(*p, filter);
    *p += wcslen(*p) + 1;
    **p = '\0';
}

__attribute__((used)) static
BOOL
DIALOG_Browse(HWND hWnd, LPCWSTR lpszzFilter, LPWSTR lpstrFile, INT nMaxFile)
{
    OPENFILENAMEW openfilename;
    WCHAR szDir[MAX_PATH];

    ZeroMemory(&openfilename, sizeof(openfilename));

    GetCurrentDirectoryW(ARRAYSIZE(szDir), szDir);

    openfilename.lStructSize       = sizeof(openfilename);
    openfilename.hwndOwner         = hWnd;
    openfilename.hInstance         = Globals.hInstance;
    openfilename.lpstrFilter       = lpszzFilter;
    openfilename.lpstrFile         = lpstrFile;
    openfilename.nMaxFile          = nMaxFile;
    openfilename.lpstrInitialDir   = szDir;
    openfilename.Flags             = 0;
    openfilename.lpstrDefExt       = L"exe";
    openfilename.lpstrCustomFilter = NULL;
    openfilename.nMaxCustFilter    = 0;
    openfilename.nFilterIndex      = 0;
    openfilename.lpstrFileTitle    = NULL;
    openfilename.nMaxFileTitle     = 0;
    openfilename.lpstrTitle        = NULL;
    openfilename.nFileOffset       = 0;
    openfilename.nFileExtension    = 0;
    openfilename.lCustData         = 0;
    openfilename.lpfnHook          = NULL;
    openfilename.lpTemplateName    = NULL;

    return GetOpenFileNameW(&openfilename);
}

__attribute__((used)) static
BOOL
DIALOG_BrowsePrograms(HWND hWnd, LPWSTR lpszFile, INT nMaxFile)
{
    WCHAR szzFilter[2 * MAX_STRING_LEN + 100];
    LPWSTR p = szzFilter;

    DIALOG_AddFilterItem(&p, IDS_PROGRAMS , L"*.exe;*.pif;*.com;*.bat;*.cmd");
    DIALOG_AddFilterItem(&p, IDS_ALL_FILES, L"*.*");

    return DIALOG_Browse(hWnd, szzFilter, lpszFile, nMaxFile);
}

__attribute__((used)) static
BOOL
DIALOG_BrowseSymbols(HWND hWnd, LPWSTR lpszFile, INT nMaxFile)
{
    WCHAR szzFilter[5 * MAX_STRING_LEN + 100];
    LPWSTR p = szzFilter;

    DIALOG_AddFilterItem(&p, IDS_SYMBOL_FILES, L"*.ico;*.exe;*.dll");
    DIALOG_AddFilterItem(&p, IDS_PROGRAMS, L"*.exe");
    DIALOG_AddFilterItem(&p, IDS_LIBRARIES_DLL, L"*.dll");
    DIALOG_AddFilterItem(&p, IDS_SYMBOLS_ICO, L"*.ico");
    DIALOG_AddFilterItem(&p, IDS_ALL_FILES, L"*.*");

    return DIALOG_Browse(hWnd, szzFilter, lpszFile, nMaxFile);
}

LPCWSTR GroupFormatToFormatName(GROUPFORMAT Format)
{
    static const LPCWSTR FormatNames[] =
    {
        L"Windows 3.1",
        L"NT Ansi",
        L"NT Unicode"
    };

    if (Format > NT_Unicode)
        return NULL;
    else
        return FormatNames[Format];
}

