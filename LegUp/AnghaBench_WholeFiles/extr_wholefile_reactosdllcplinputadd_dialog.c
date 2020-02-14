#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WPARAM ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_8__ {scalar_t__ dwId; int /*<<< orphan*/  pszName; struct TYPE_8__* pNext; } ;
typedef  TYPE_1__ LOCALE_LIST_NODE ;
typedef  TYPE_1__ LAYOUT_LIST_NODE ;
typedef  int /*<<< orphan*/  INT ;
typedef  int /*<<< orphan*/  INFCONTEXT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  scalar_t__ HINF ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAYSIZE (char*) ; 
 int /*<<< orphan*/  CBN_SELCHANGE ; 
 int /*<<< orphan*/  ComboBox_AddString (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ComboBox_GetCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ComboBox_GetCurSel (int /*<<< orphan*/ ) ; 
 scalar_t__ ComboBox_GetItemData (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ComboBox_SetCurSel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ComboBox_SetItemData (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  EndDialog (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int const) ; 
 scalar_t__ GetSystemDefaultLCID () ; 
 int /*<<< orphan*/  HIWORD (int /*<<< orphan*/ ) ; 
#define  IDCANCEL 130 
#define  IDC_INPUT_LANG_COMBO 129 
 int const IDC_KEYBOARD_LO_COMBO ; 
#define  IDOK 128 
 int /*<<< orphan*/  INF_STYLE_WIN4 ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  InputList_Add (TYPE_1__*,TYPE_1__*) ; 
 int LOWORD (int /*<<< orphan*/ ) ; 
 TYPE_1__* LayoutList_GetFirst () ; 
 TYPE_1__* LocaleList_GetFirst () ; 
 int MAX_STR_LEN ; 
 int /*<<< orphan*/  SetupCloseInfFile (scalar_t__) ; 
 scalar_t__ SetupFindFirstLineW (scalar_t__,char*,char*,int /*<<< orphan*/ *) ; 
 int SetupGetFieldCount (int /*<<< orphan*/ *) ; 
 scalar_t__ SetupGetStringFieldW (int /*<<< orphan*/ *,int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ SetupOpenInfFileW (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  StringCchPrintfW (char*,int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int wcslen (char*) ; 
 char* wcstok (char*,char*) ; 
 scalar_t__ wcstoul (char const*,char**,int) ; 

__attribute__((used)) static inline DWORD
DWORDfromString(const WCHAR *pszString)
{
    WCHAR *pszEnd;

    return wcstoul(pszString, &pszEnd, 16);
}

__attribute__((used)) static DWORD
GetDefaultLayoutForLocale(DWORD dwLocaleId)
{
    DWORD dwResult = 0;
    HINF hIntlInf;

    hIntlInf = SetupOpenInfFileW(L"intl.inf", NULL, INF_STYLE_WIN4, NULL);
    if (hIntlInf != INVALID_HANDLE_VALUE)
    {
        WCHAR szLangID[MAX_STR_LEN];
        INFCONTEXT InfContext;

        StringCchPrintfW(szLangID, ARRAYSIZE(szLangID), L"%08X", dwLocaleId);

        if (SetupFindFirstLineW(hIntlInf, L"Locales", szLangID, &InfContext))
        {
            if (SetupGetFieldCount(&InfContext) >= 5)
            {
                WCHAR szField[MAX_STR_LEN];

                if (SetupGetStringFieldW(&InfContext, 5, szField, ARRAYSIZE(szField), NULL))
                {
                    if (wcslen(szField) == 13) // like 0409:00000409 (13 chars)
                    {
                        WCHAR *pszSeparator = L":";
                        WCHAR *pszToken;

                        pszToken = wcstok(szField, pszSeparator);
                        if (pszToken != NULL)
                            pszToken = wcstok(NULL, pszSeparator);

                        if (pszToken != NULL)
                        {
                            dwResult = DWORDfromString(pszToken);
                        }
                    }
                }
            }
        }

        SetupCloseInfFile(hIntlInf);
    }

    return dwResult;
}

__attribute__((used)) static VOID
OnInitAddDialog(HWND hwndDlg)
{
    HWND hwndLocaleCombo = GetDlgItem(hwndDlg, IDC_INPUT_LANG_COMBO);
    HWND hwndLayoutCombo = GetDlgItem(hwndDlg, IDC_KEYBOARD_LO_COMBO);
    LOCALE_LIST_NODE *pCurrentLocale;
    LAYOUT_LIST_NODE *pCurrentLayout;
    DWORD dwDefaultLocaleId;
    DWORD dwDefaultLayoutId;
    INT iItemIndex;

    dwDefaultLocaleId = GetSystemDefaultLCID();

    for (pCurrentLocale = LocaleList_GetFirst();
         pCurrentLocale != NULL;
         pCurrentLocale = pCurrentLocale->pNext)
    {
        iItemIndex = ComboBox_AddString(hwndLocaleCombo, pCurrentLocale->pszName);
        ComboBox_SetItemData(hwndLocaleCombo, iItemIndex, pCurrentLocale);

        if (pCurrentLocale->dwId == dwDefaultLocaleId)
        {
            ComboBox_SetCurSel(hwndLocaleCombo, iItemIndex);
        }
    }

    dwDefaultLayoutId = GetDefaultLayoutForLocale(dwDefaultLocaleId);

    for (pCurrentLayout = LayoutList_GetFirst();
         pCurrentLayout != NULL;
         pCurrentLayout = pCurrentLayout->pNext)
    {
        iItemIndex = ComboBox_AddString(hwndLayoutCombo, pCurrentLayout->pszName);
        ComboBox_SetItemData(hwndLayoutCombo, iItemIndex, pCurrentLayout);

        if (pCurrentLayout->dwId == dwDefaultLayoutId)
        {
            ComboBox_SetCurSel(hwndLayoutCombo, iItemIndex);
        }
    }

    if (dwDefaultLayoutId == 0)
        ComboBox_SetCurSel(hwndLayoutCombo, 0);
}

__attribute__((used)) static VOID
OnCommandAddDialog(HWND hwndDlg, WPARAM wParam)
{
    switch (LOWORD(wParam))
    {
        case IDOK:
        {
            HWND hwndLocaleCombo = GetDlgItem(hwndDlg, IDC_INPUT_LANG_COMBO);
            HWND hwndLayoutCombo = GetDlgItem(hwndDlg, IDC_KEYBOARD_LO_COMBO);
            LOCALE_LIST_NODE *pCurrentLocale;
            LAYOUT_LIST_NODE *pCurrentLayout;

            pCurrentLocale = (LOCALE_LIST_NODE*)ComboBox_GetItemData(hwndLocaleCombo,
                                                                     ComboBox_GetCurSel(hwndLocaleCombo));
            pCurrentLayout = (LAYOUT_LIST_NODE*)ComboBox_GetItemData(hwndLayoutCombo,
                                                                     ComboBox_GetCurSel(hwndLayoutCombo));

            InputList_Add(pCurrentLocale, pCurrentLayout);

            EndDialog(hwndDlg, LOWORD(wParam));
        }
        break;

        case IDCANCEL:
        {
            EndDialog(hwndDlg, LOWORD(wParam));
        }
        break;

        case IDC_INPUT_LANG_COMBO:
        {
            if (HIWORD(wParam) == CBN_SELCHANGE)
            {
                HWND hwndLocaleCombo = GetDlgItem(hwndDlg, IDC_INPUT_LANG_COMBO);
                HWND hwndLayoutCombo = GetDlgItem(hwndDlg, IDC_KEYBOARD_LO_COMBO);
                LOCALE_LIST_NODE *pCurrentLocale;

                pCurrentLocale = (LOCALE_LIST_NODE*)ComboBox_GetItemData(hwndLocaleCombo,
                                                                         ComboBox_GetCurSel(hwndLocaleCombo));
                if (pCurrentLocale != NULL)
                {
                    DWORD dwLayoutId;
                    INT iIndex;
                    INT iCount;

                    dwLayoutId = GetDefaultLayoutForLocale(pCurrentLocale->dwId);

                    iCount = ComboBox_GetCount(hwndLayoutCombo);

                    for (iIndex = 0; iIndex < iCount; iIndex++)
                    {
                        LAYOUT_LIST_NODE *pCurrentLayout;

                        pCurrentLayout = (LAYOUT_LIST_NODE*)ComboBox_GetItemData(hwndLayoutCombo, iIndex);

                        if (pCurrentLayout != NULL && pCurrentLayout->dwId == dwLayoutId)
                        {
                            ComboBox_SetCurSel(hwndLayoutCombo, iIndex);
                            break;
                        }
                    }
                }
            }
        }
        break;
    }
}

