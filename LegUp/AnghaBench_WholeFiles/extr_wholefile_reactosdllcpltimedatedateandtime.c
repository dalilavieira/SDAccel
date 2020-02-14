#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  szBuf ;
typedef  int /*<<< orphan*/  previouspriv ;
typedef  int /*<<< orphan*/  WPARAM ;
typedef  scalar_t__ WORD ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int UINT ;
struct TYPE_17__ {scalar_t__ wMonth; int /*<<< orphan*/  member_0; } ;
struct TYPE_16__ {int /*<<< orphan*/  DaylightName; int /*<<< orphan*/  StandardName; } ;
struct TYPE_15__ {int PrivilegeCount; TYPE_1__* Privileges; } ;
struct TYPE_14__ {int /*<<< orphan*/  Luid; int /*<<< orphan*/  Attributes; } ;
typedef  TYPE_2__ TOKEN_PRIVILEGES ;
typedef  TYPE_3__ TIME_ZONE_INFORMATION ;
typedef  TYPE_4__ SYSTEMTIME ;
typedef  int /*<<< orphan*/  PNMMCCAUTOUPDATE ;
typedef  TYPE_4__* LPSYSTEMTIME ;
typedef  int LPARAM ;
typedef  int INT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ AdjustTokenPrivileges (int /*<<< orphan*/ ,int,TYPE_2__*,int,TYPE_2__*,int*) ; 
 int /*<<< orphan*/  CB_ADDSTRING ; 
 int CB_ERR ; 
 int /*<<< orphan*/  CB_GETCURSEL ; 
 int /*<<< orphan*/  CB_GETITEMDATA ; 
 int /*<<< orphan*/  CB_RESETCONTENT ; 
 int /*<<< orphan*/  CB_SETCURSEL ; 
 int /*<<< orphan*/  CB_SETITEMDATA ; 
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DWLP_MSGRESULT ; 
 scalar_t__ DateTime_GetSystemtime (int /*<<< orphan*/ ,TYPE_4__*) ; 
 scalar_t__ ERROR_SUCCESS ; 
 int FALSE ; 
 scalar_t__ GDT_VALID ; 
 int /*<<< orphan*/  GetCurrentProcess () ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  GetLocalTime (TYPE_4__*) ; 
 int GetLocaleInfoW (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,int) ; 
 int GetTimeZoneInformation (TYPE_3__*) ; 
 int /*<<< orphan*/  HWND_BROADCAST ; 
 int /*<<< orphan*/  IDC_MONTHCALENDAR ; 
 int /*<<< orphan*/  IDC_MONTHCB ; 
 int /*<<< orphan*/  IDC_TIMEPICKER ; 
 int /*<<< orphan*/  IDC_TIMEZONE ; 
 int /*<<< orphan*/  IDS_TIMEZONEINVALID ; 
 int /*<<< orphan*/  IDS_TIMEZONETEXT ; 
 scalar_t__ LOCALE_SMONTHNAME1 ; 
 scalar_t__ LOCALE_SMONTHNAME13 ; 
 int /*<<< orphan*/  LOCALE_USER_DEFAULT ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 scalar_t__ LookupPrivilegeValueW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int MAKELPARAM (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAKEWPARAM (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  MCCM_GETDATE ; 
 int /*<<< orphan*/  MCCM_RESET ; 
 int /*<<< orphan*/  MCCM_SETDATE ; 
 scalar_t__ OpenProcessToken (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PSNRET_NOERROR ; 
 int /*<<< orphan*/  SE_PRIVILEGE_ENABLED ; 
 int /*<<< orphan*/  SE_SYSTEMTIME_NAME ; 
 int /*<<< orphan*/  SendDlgItemMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ SendMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ SetLocalTime (TYPE_4__*) ; 
 int SetSystemTime (TYPE_4__*) ; 
 int /*<<< orphan*/  SetWindowLongPtrW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  TIME_ZONE_ID_DAYLIGHT 131 
#define  TIME_ZONE_ID_INVALID 130 
#define  TIME_ZONE_ID_STANDARD 129 
#define  TIME_ZONE_ID_UNKNOWN 128 
 int TOKEN_ADJUST_PRIVILEGES ; 
 int TOKEN_QUERY ; 
 int /*<<< orphan*/  UNREFERENCED_PARAMETER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WM_SETTEXT ; 
 int /*<<< orphan*/  WM_TIMECHANGE ; 
 int /*<<< orphan*/  hApplet ; 
 int /*<<< orphan*/  wcscpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wsprintfW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

BOOL
SystemSetTime(LPSYSTEMTIME lpSystemTime,
              BOOL SystemTime)
{
    HANDLE hToken;
    DWORD PrevSize;
    TOKEN_PRIVILEGES priv, previouspriv;
    BOOL Ret = FALSE;

    /*
     * Enable the SeSystemtimePrivilege privilege
     */

    if (OpenProcessToken(GetCurrentProcess(),
                         TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
                         &hToken))
    {
        priv.PrivilegeCount = 1;
        priv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

        if (LookupPrivilegeValueW(NULL,
                                  SE_SYSTEMTIME_NAME,
                                  &priv.Privileges[0].Luid))
        {
            if (AdjustTokenPrivileges(hToken,
                                      FALSE,
                                      &priv,
                                      sizeof(previouspriv),
                                      &previouspriv,
                                      &PrevSize) &&
                GetLastError() == ERROR_SUCCESS)
            {
                /*
                 * We successfully enabled it, we're permitted to change the time.
                 * Check the second parameter for SystemTime and if TRUE set System Time.
                 * Otherwise, if FALSE set the Local Time.
                 * Call SetLocalTime twice to ensure correct results.
                 */
                if (SystemTime)
                {
                    Ret = SetSystemTime(lpSystemTime);
                }
                else
                {
                    Ret = SetLocalTime(lpSystemTime) &&
                          SetLocalTime(lpSystemTime);
                }

                /*
                 * For the sake of security, restore the previous status again
                 */
                if (previouspriv.PrivilegeCount > 0)
                {
                    AdjustTokenPrivileges(hToken,
                                          FALSE,
                                          &previouspriv,
                                          0,
                                          NULL,
                                          0);
                }
            }
        }
        CloseHandle(hToken);
    }

    return Ret;
}

__attribute__((used)) static VOID
SetLocalSystemTime(HWND hwnd)
{
    SYSTEMTIME Time;

    if (DateTime_GetSystemtime(GetDlgItem(hwnd,
                                          IDC_TIMEPICKER),
                               &Time) == GDT_VALID &&
        SendMessageW(GetDlgItem(hwnd,
                                IDC_MONTHCALENDAR),
                     MCCM_GETDATE,
                     (WPARAM)&Time,
                     0))
    {
        /* Set Local Time with SystemTime = FALSE */
        SystemSetTime(&Time, FALSE);

        SetWindowLongPtrW(hwnd,
                          DWLP_MSGRESULT,
                          PSNRET_NOERROR);

        SendMessageW(GetDlgItem(hwnd,
                                IDC_MONTHCALENDAR),
                     MCCM_RESET,
                     (WPARAM)&Time,
                     0);

        /* Broadcast the time change message */
        SendMessageW(HWND_BROADCAST,
                     WM_TIMECHANGE,
                     0,
                     0);
    }
}

__attribute__((used)) static VOID
SetTimeZoneName(HWND hwnd)
{
    TIME_ZONE_INFORMATION TimeZoneInfo;
    WCHAR TimeZoneString[128];
    WCHAR TimeZoneText[128];
    WCHAR TimeZoneName[128];
    DWORD TimeZoneId;

    TimeZoneId = GetTimeZoneInformation(&TimeZoneInfo);

    LoadStringW(hApplet, IDS_TIMEZONETEXT, TimeZoneText, 128);

    switch (TimeZoneId)
    {
        case TIME_ZONE_ID_STANDARD:
        case TIME_ZONE_ID_UNKNOWN:
            wcscpy(TimeZoneName, TimeZoneInfo.StandardName);
            break;

        case TIME_ZONE_ID_DAYLIGHT:
            wcscpy(TimeZoneName, TimeZoneInfo.DaylightName);
            break;

        case TIME_ZONE_ID_INVALID:
        default:
            LoadStringW(hApplet, IDS_TIMEZONEINVALID, TimeZoneName, 128);
            break;
    }

    wsprintfW(TimeZoneString, TimeZoneText, TimeZoneName);
    SendDlgItemMessageW(hwnd, IDC_TIMEZONE, WM_SETTEXT, 0, (LPARAM)TimeZoneString);
}

__attribute__((used)) static VOID
FillMonthsComboBox(HWND hCombo)
{
    SYSTEMTIME LocalDate = {0};
    WCHAR szBuf[64];
    INT i;
    UINT Month;

    GetLocalTime(&LocalDate);

    SendMessageW(hCombo,
                 CB_RESETCONTENT,
                 0,
                 0);

    for (Month = 1;
         Month <= 13;
         Month++)
    {
        i = GetLocaleInfoW(LOCALE_USER_DEFAULT,
                           ((Month < 13) ? LOCALE_SMONTHNAME1 + Month - 1 : LOCALE_SMONTHNAME13),
                           szBuf,
                           sizeof(szBuf) / sizeof(szBuf[0]));
        if (i > 1)
        {
            i = (INT)SendMessageW(hCombo,
                                  CB_ADDSTRING,
                                  0,
                                  (LPARAM)szBuf);
            if (i != CB_ERR)
            {
                SendMessageW(hCombo,
                             CB_SETITEMDATA,
                             (WPARAM)i,
                             Month);

                if (Month == (UINT)LocalDate.wMonth)
                {
                    SendMessageW(hCombo,
                                 CB_SETCURSEL,
                                 (WPARAM)i,
                                 0);
                }
            }
        }
    }
}

__attribute__((used)) static WORD
GetCBSelectedMonth(HWND hCombo)
{
    INT i;
    WORD Ret = (WORD)-1;

    i = (INT)SendMessageW(hCombo,
                          CB_GETCURSEL,
                          0,
                          0);
    if (i != CB_ERR)
    {
        i = (INT)SendMessageW(hCombo,
                              CB_GETITEMDATA,
                              (WPARAM)i,
                              0);

        if (i >= 1 && i <= 13)
            Ret = (WORD)i;
    }

    return Ret;
}

__attribute__((used)) static VOID
ChangeMonthCalDate(HWND hMonthCal,
                   WORD Day,
                   WORD Month,
                   WORD Year)
{
    SendMessageW(hMonthCal,
                 MCCM_SETDATE,
                 MAKEWPARAM(Day,
                            Month),
                 MAKELPARAM(Year,
                            0));
}

__attribute__((used)) static VOID
AutoUpdateMonthCal(HWND hwndDlg,
                   PNMMCCAUTOUPDATE lpAutoUpdate)
{
    UNREFERENCED_PARAMETER(lpAutoUpdate);

    /* Update the controls */
    FillMonthsComboBox(GetDlgItem(hwndDlg,
                                  IDC_MONTHCB));
}

