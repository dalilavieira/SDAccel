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
typedef  int /*<<< orphan*/  WPARAM ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  TCHAR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  INFCONTEXT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  scalar_t__ HINF ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  Buffer ;

/* Variables and functions */
 int /*<<< orphan*/  BM_SETCHECK ; 
 int /*<<< orphan*/  CB_ADDSTRING ; 
 int CB_ERR ; 
 int /*<<< orphan*/  CB_SETCURSEL ; 
 int /*<<< orphan*/  CB_SETITEMDATA ; 
 scalar_t__ ERROR_SUCCESS ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HKEY_CURRENT_USER ; 
 int /*<<< orphan*/  HKEY_LOCAL_MACHINE ; 
 int /*<<< orphan*/  IDC_ASKME_RB ; 
 int /*<<< orphan*/  IDC_FONTSIZE_COMBO ; 
 int /*<<< orphan*/  IDC_FONTSIZE_CUSTOM ; 
 int /*<<< orphan*/  IDC_RESTART_RB ; 
 int /*<<< orphan*/  IDC_WITHOUTREBOOT_RB ; 
 int /*<<< orphan*/  INF_STYLE_WIN4 ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  KEY_READ ; 
 int LINE_LEN ; 
 int MAX_PATH ; 
 int REG_DWORD ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 scalar_t__ RegOpenKeyEx (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ RegQueryValueEx (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  SendDlgItemMessage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int SendMessage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetWindowText (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetupCloseInfFile (scalar_t__) ; 
 scalar_t__ SetupFindFirstLine (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetupFindNextLine (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ SetupGetIntField (int /*<<< orphan*/ *,int,int*) ; 
 scalar_t__ SetupGetStringField (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 scalar_t__ SetupOpenInfFile (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _T (char*) ; 
 int /*<<< orphan*/  _stprintf (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int _ttoi (int /*<<< orphan*/ *) ; 

__attribute__((used)) static VOID
InitFontSizeList(HWND hWnd)
{
    HINF hInf;
    HKEY hKey;
    HWND hFontSize;
    INFCONTEXT Context;
    int i, ci = 0;
    DWORD dwSize, dwValue, dwType;

    hFontSize = GetDlgItem(hWnd, IDC_FONTSIZE_COMBO);

    hInf = SetupOpenInfFile(_T("font.inf"), NULL,
                            INF_STYLE_WIN4, NULL);

    if (hInf != INVALID_HANDLE_VALUE)
    {
        if (SetupFindFirstLine(hInf, _T("Font Sizes"), NULL, &Context))
        {
            if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SYSTEM\\CurrentControlSet\\Hardware Profiles\\Current\\Software\\Fonts"),
                             0, KEY_READ, &hKey) == ERROR_SUCCESS)
            {
                dwSize = MAX_PATH;
                dwType = REG_DWORD;

                if (RegQueryValueEx(hKey, _T("LogPixels"), NULL, &dwType,
                                    (LPBYTE)&dwValue, &dwSize) != ERROR_SUCCESS)
                {
                    dwValue = 0;
                }

                RegCloseKey(hKey);
            }

            for (;;)
            {
                TCHAR Buffer[LINE_LEN];
                TCHAR Desc[LINE_LEN];

                if (SetupGetStringField(&Context, 0, Buffer, sizeof(Buffer) / sizeof(TCHAR), NULL) &&
                    SetupGetIntField(&Context, 1, &ci))
                {
                    _stprintf(Desc, _T("%s (%d DPI)"), Buffer, ci);
                    i = SendMessage(hFontSize, CB_ADDSTRING, 0, (LPARAM)Desc);
                    if (i != CB_ERR)
                        SendMessage(hFontSize, CB_SETITEMDATA, (WPARAM)i, (LPARAM)ci);

                    if ((int)dwValue == ci)
                    {
                        SendMessage(hFontSize, CB_SETCURSEL, (WPARAM)i, 0);
                        SetWindowText(GetDlgItem(hWnd, IDC_FONTSIZE_CUSTOM), Desc);
                    }
                    else
                        SendMessage(hFontSize, CB_SETCURSEL, 0, 0);
                }

                if (!SetupFindNextLine(&Context, &Context))
                {
                    break;
                }
            }
        }
    }

    SetupCloseInfFile(hInf);
}

__attribute__((used)) static VOID
InitRadioButtons(HWND hWnd)
{
    HKEY hKey;

    if (RegOpenKeyEx(HKEY_CURRENT_USER,
                     _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Controls Folder\\Display"),
                     0, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        TCHAR szBuf[64];
        DWORD dwSize = 64;

        if (RegQueryValueEx(hKey, _T("DynaSettingsChange"), 0, NULL,
                            (LPBYTE)szBuf, &dwSize) == ERROR_SUCCESS)
        {
            switch (_ttoi(szBuf))
            {
                case 0:
                    SendDlgItemMessage(hWnd, IDC_RESTART_RB, BM_SETCHECK, 1, 1);
                    break;
                case 1:
                    SendDlgItemMessage(hWnd, IDC_WITHOUTREBOOT_RB, BM_SETCHECK, 1, 1);
                    break;
                case 3:
                    SendDlgItemMessage(hWnd, IDC_ASKME_RB, BM_SETCHECK, 1, 1);
                    break;
            }
        }
        else
            SendDlgItemMessage(hWnd, IDC_WITHOUTREBOOT_RB, BM_SETCHECK, 1, 1);

        RegCloseKey(hKey);
    }
    else
        SendDlgItemMessage(hWnd, IDC_WITHOUTREBOOT_RB, BM_SETCHECK, 1, 1);
}

