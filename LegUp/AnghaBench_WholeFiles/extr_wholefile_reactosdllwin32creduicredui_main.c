#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  toolinfo ;
struct cred_dialog_params {int dwFlags; void* hwndBalloonTip; void* fBalloonTipActive; int /*<<< orphan*/ * pszUsername; } ;
typedef  int /*<<< orphan*/  WCHAR ;
struct TYPE_12__ {int iItem; int /*<<< orphan*/ * pszText; int /*<<< orphan*/  mask; } ;
struct TYPE_11__ {scalar_t__ Type; int /*<<< orphan*/ * UserName; } ;
struct TYPE_10__ {int right; int top; int bottom; int left; } ;
struct TYPE_9__ {int cbSize; int uId; void* hwnd; int /*<<< orphan*/ * lpReserved; scalar_t__ lParam; int /*<<< orphan*/ * lpszText; int /*<<< orphan*/ * hinst; int /*<<< orphan*/  rect; int /*<<< orphan*/  uFlags; } ;
typedef  TYPE_1__ TTTOOLINFOW ;
typedef  TYPE_2__ RECT ;
typedef  TYPE_3__* PCREDENTIALW ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int INT ;
typedef  void* HWND ;
typedef  size_t DWORD ;
typedef  TYPE_4__ COMBOBOXEXITEMW ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CBEIF_TEXT ; 
 int /*<<< orphan*/  CBEM_INSERTITEMW ; 
 int CREDUI_FLAGS_GENERIC_CREDENTIALS ; 
 scalar_t__ CRED_TYPE_GENERIC ; 
 int /*<<< orphan*/  CW_USEDEFAULT ; 
 void* CreateWindowExW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CredEnumerateW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t*,TYPE_3__***) ; 
 int /*<<< orphan*/  CredFree (TYPE_3__**) ; 
 int /*<<< orphan*/  ERR (char*) ; 
 void* FALSE ; 
 int /*<<< orphan*/  GetDlgItem (void*,int /*<<< orphan*/ ) ; 
 int GetKeyState (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowRect (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  HWND_TOPMOST ; 
 int /*<<< orphan*/  IDC_PASSWORD ; 
 int /*<<< orphan*/  IDS_CAPSLOCKON ; 
 int /*<<< orphan*/  IDS_CAPSLOCKONTITLE ; 
 int /*<<< orphan*/  IDS_INCORRECTPASSWORD ; 
 int /*<<< orphan*/  IDS_INCORRECTPASSWORDTITLE ; 
 int /*<<< orphan*/  ID_CAPSLOCKPOP ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAKELONG (int,int) ; 
 int SWP_NOACTIVATE ; 
 int SWP_NOMOVE ; 
 int SWP_NOSIZE ; 
 int /*<<< orphan*/  SendMessageW (void*,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetRectEmpty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetTimer (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetWindowPos (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 void* TOOLID_CAPSLOCKON ; 
 void* TOOLID_INCORRECTPASSWORD ; 
 int /*<<< orphan*/  TOOLTIPS_CLASSW ; 
 void* TRUE ; 
 void* TTDT_AUTOPOP ; 
 int /*<<< orphan*/  TTF_TRACK ; 
 void* TTI_ERROR ; 
 void* TTI_WARNING ; 
 int /*<<< orphan*/  TTM_ADDTOOLW ; 
 int /*<<< orphan*/  TTM_GETDELAYTIME ; 
 int /*<<< orphan*/  TTM_SETTITLEW ; 
 int /*<<< orphan*/  TTM_TRACKACTIVATE ; 
 int /*<<< orphan*/  TTM_TRACKPOSITION ; 
 int TTS_BALLOON ; 
 int TTS_NOPREFIX ; 
 int /*<<< orphan*/  VK_CAPITAL ; 
 int /*<<< orphan*/  WS_EX_TOOLWINDOW ; 
 int WS_POPUP ; 
 int /*<<< orphan*/  hinstCredUI ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strcmpW (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void CredDialogFillUsernameCombo(HWND hwndUsername, const struct cred_dialog_params *params)
{
    DWORD count;
    DWORD i;
    PCREDENTIALW *credentials;

    if (!CredEnumerateW(NULL, 0, &count, &credentials))
        return;

    for (i = 0; i < count; i++)
    {
        COMBOBOXEXITEMW comboitem;
        DWORD j;
        BOOL duplicate = FALSE;

        if (!credentials[i]->UserName)
            continue;

        if (params->dwFlags & CREDUI_FLAGS_GENERIC_CREDENTIALS)
        {
            if (credentials[i]->Type != CRED_TYPE_GENERIC)
            {
                credentials[i]->UserName = NULL;
                continue;
            }
        }
        else if (credentials[i]->Type == CRED_TYPE_GENERIC)
        {
            credentials[i]->UserName = NULL;
            continue;
        }

        /* don't add another item with the same name if we've already added it */
        for (j = 0; j < i; j++)
            if (credentials[j]->UserName
                && !strcmpW(credentials[i]->UserName, credentials[j]->UserName))
            {
                duplicate = TRUE;
                break;
            }

        if (duplicate)
            continue;

        comboitem.mask = CBEIF_TEXT;
        comboitem.iItem = -1;
        comboitem.pszText = credentials[i]->UserName;
        SendMessageW(hwndUsername, CBEM_INSERTITEMW, 0, (LPARAM)&comboitem);
    }

    CredFree(credentials);
}

__attribute__((used)) static void CredDialogCreateBalloonTip(HWND hwndDlg, struct cred_dialog_params *params)
{
    TTTOOLINFOW toolinfo;
    WCHAR wszText[256];

    if (params->hwndBalloonTip)
        return;

    params->hwndBalloonTip = CreateWindowExW(WS_EX_TOOLWINDOW, TOOLTIPS_CLASSW,
        NULL, WS_POPUP | TTS_NOPREFIX | TTS_BALLOON, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hwndDlg, NULL,
        hinstCredUI, NULL);
    SetWindowPos(params->hwndBalloonTip, HWND_TOPMOST, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

    if (!LoadStringW(hinstCredUI, IDS_INCORRECTPASSWORD, wszText, ARRAY_SIZE(wszText)))
    {
        ERR("failed to load IDS_INCORRECTPASSWORD\n");
        return;
    }

    toolinfo.cbSize = sizeof(toolinfo);
    toolinfo.uFlags = TTF_TRACK;
    toolinfo.hwnd = hwndDlg;
    toolinfo.uId = TOOLID_INCORRECTPASSWORD;
    SetRectEmpty(&toolinfo.rect);
    toolinfo.hinst = NULL;
    toolinfo.lpszText = wszText;
    toolinfo.lParam = 0;
    toolinfo.lpReserved = NULL;
    SendMessageW(params->hwndBalloonTip, TTM_ADDTOOLW, 0, (LPARAM)&toolinfo);

    if (!LoadStringW(hinstCredUI, IDS_CAPSLOCKON, wszText, ARRAY_SIZE(wszText)))
    {
        ERR("failed to load IDS_CAPSLOCKON\n");
        return;
    }

    toolinfo.uId = TOOLID_CAPSLOCKON;
    SendMessageW(params->hwndBalloonTip, TTM_ADDTOOLW, 0, (LPARAM)&toolinfo);
}

__attribute__((used)) static void CredDialogShowIncorrectPasswordBalloon(HWND hwndDlg, struct cred_dialog_params *params)
{
    TTTOOLINFOW toolinfo;
    RECT rcPassword;
    INT x;
    INT y;
    WCHAR wszTitle[256];

    /* user name likely wrong so balloon would be confusing. focus is also
     * not set to the password edit box, so more notification would need to be
     * handled */
    if (!params->pszUsername[0])
        return;

    /* don't show two balloon tips at once */
    if (params->fBalloonTipActive)
        return;

    if (!LoadStringW(hinstCredUI, IDS_INCORRECTPASSWORDTITLE, wszTitle, ARRAY_SIZE(wszTitle)))
    {
        ERR("failed to load IDS_INCORRECTPASSWORDTITLE\n");
        return;
    }

    CredDialogCreateBalloonTip(hwndDlg, params);

    memset(&toolinfo, 0, sizeof(toolinfo));
    toolinfo.cbSize = sizeof(toolinfo);
    toolinfo.hwnd = hwndDlg;
    toolinfo.uId = TOOLID_INCORRECTPASSWORD;

    SendMessageW(params->hwndBalloonTip, TTM_SETTITLEW, TTI_ERROR, (LPARAM)wszTitle);

    GetWindowRect(GetDlgItem(hwndDlg, IDC_PASSWORD), &rcPassword);
    /* centered vertically and in the right side of the password edit control */
    x = rcPassword.right - 12;
    y = (rcPassword.top + rcPassword.bottom) / 2;
    SendMessageW(params->hwndBalloonTip, TTM_TRACKPOSITION, 0, MAKELONG(x, y));

    SendMessageW(params->hwndBalloonTip, TTM_TRACKACTIVATE, TRUE, (LPARAM)&toolinfo);

    params->fBalloonTipActive = TRUE;
}

__attribute__((used)) static void CredDialogShowCapsLockBalloon(HWND hwndDlg, struct cred_dialog_params *params)
{
    TTTOOLINFOW toolinfo;
    RECT rcPassword;
    INT x;
    INT y;
    WCHAR wszTitle[256];

    /* don't show two balloon tips at once */
    if (params->fBalloonTipActive)
        return;

    if (!LoadStringW(hinstCredUI, IDS_CAPSLOCKONTITLE, wszTitle, ARRAY_SIZE(wszTitle)))
    {
        ERR("failed to load IDS_IDSCAPSLOCKONTITLE\n");
        return;
    }

    CredDialogCreateBalloonTip(hwndDlg, params);

    memset(&toolinfo, 0, sizeof(toolinfo));
    toolinfo.cbSize = sizeof(toolinfo);
    toolinfo.hwnd = hwndDlg;
    toolinfo.uId = TOOLID_CAPSLOCKON;

    SendMessageW(params->hwndBalloonTip, TTM_SETTITLEW, TTI_WARNING, (LPARAM)wszTitle);

    GetWindowRect(GetDlgItem(hwndDlg, IDC_PASSWORD), &rcPassword);
    /* just inside the left side of the password edit control */
    x = rcPassword.left + 12;
    y = rcPassword.bottom - 3;
    SendMessageW(params->hwndBalloonTip, TTM_TRACKPOSITION, 0, MAKELONG(x, y));

    SendMessageW(params->hwndBalloonTip, TTM_TRACKACTIVATE, TRUE, (LPARAM)&toolinfo);

    SetTimer(hwndDlg, ID_CAPSLOCKPOP,
             SendMessageW(params->hwndBalloonTip, TTM_GETDELAYTIME, TTDT_AUTOPOP, 0),
             NULL);

    params->fBalloonTipActive = TRUE;
}

__attribute__((used)) static void CredDialogHideBalloonTip(HWND hwndDlg, struct cred_dialog_params *params)
{
    TTTOOLINFOW toolinfo;

    if (!params->hwndBalloonTip)
        return;

    memset(&toolinfo, 0, sizeof(toolinfo));

    toolinfo.cbSize = sizeof(toolinfo);
    toolinfo.hwnd = hwndDlg;
    toolinfo.uId = 0;
    SendMessageW(params->hwndBalloonTip, TTM_TRACKACTIVATE, FALSE, (LPARAM)&toolinfo);
    toolinfo.uId = 1;
    SendMessageW(params->hwndBalloonTip, TTM_TRACKACTIVATE, FALSE, (LPARAM)&toolinfo);

    params->fBalloonTipActive = FALSE;
}

__attribute__((used)) static inline BOOL CredDialogCapsLockOn(void)
{
    return (GetKeyState(VK_CAPITAL) & 0x1) != 0;
}

