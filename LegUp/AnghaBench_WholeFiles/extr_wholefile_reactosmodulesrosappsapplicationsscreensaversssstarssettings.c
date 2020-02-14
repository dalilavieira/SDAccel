#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lf ;
typedef  int /*<<< orphan*/  dwValue ;
typedef  int /*<<< orphan*/  WPARAM ;
typedef  size_t UINT ;
struct TYPE_13__ {scalar_t__ uiNumStars; scalar_t__ uiSpeed; scalar_t__ uiRotation; scalar_t__ bDoBlending; scalar_t__ bFinePerspective; scalar_t__ bEnableFiltering; scalar_t__ bSmoothShading; } ;
struct TYPE_12__ {size_t bmHeight; } ;
struct TYPE_11__ {int lfHeight; int /*<<< orphan*/  lfFaceName; int /*<<< orphan*/  lfQuality; int /*<<< orphan*/  lfCharSet; int /*<<< orphan*/  lfWeight; } ;
struct TYPE_10__ {size_t cy; } ;
typedef  int /*<<< orphan*/  TCHAR ;
typedef  int /*<<< orphan*/  Strings ;
typedef  TYPE_1__ SIZE ;
typedef  int /*<<< orphan*/ * LPCTSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  scalar_t__ LPARAM ;
typedef  scalar_t__ LONG ;
typedef  TYPE_2__ LOGFONT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  scalar_t__ HINSTANCE ;
typedef  int /*<<< orphan*/  HICON ;
typedef  scalar_t__ HGDIOBJ ;
typedef  scalar_t__ HFONT ;
typedef  int /*<<< orphan*/  HDC ;
typedef  scalar_t__ HBITMAP ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BOOL ;
typedef  TYPE_3__ BITMAP ;

/* Variables and functions */
 int /*<<< orphan*/  ANSI_CHARSET ; 
 int /*<<< orphan*/  BM_GETCHECK ; 
 int /*<<< orphan*/  BM_SETCHECK ; 
 int /*<<< orphan*/  CB_ADDSTRING ; 
 int /*<<< orphan*/  CB_GETCURSEL ; 
 int /*<<< orphan*/  CB_SETCURSEL ; 
 int /*<<< orphan*/  CreateCompatibleDC (int /*<<< orphan*/ ) ; 
 scalar_t__ CreateFontIndirect (TYPE_2__*) ; 
 int /*<<< orphan*/  DeleteDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DeleteObject (scalar_t__) ; 
 scalar_t__ ERROR_SUCCESS ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FW_THIN ; 
 TYPE_5__ FactoryDefaults ; 
 int /*<<< orphan*/  GWLP_HINSTANCE ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetObject (scalar_t__,int,TYPE_3__*) ; 
 int /*<<< orphan*/  GetTextExtentPoint32 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t,TYPE_1__*) ; 
 scalar_t__ GetWindowLongPtr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HKEY_CURRENT_USER ; 
 int /*<<< orphan*/  IDB_COSMOS ; 
 int /*<<< orphan*/  IDC_CHECK_DOBLENDING ; 
 int /*<<< orphan*/  IDC_CHECK_FILTERING ; 
 int /*<<< orphan*/  IDC_CHECK_PERSPECTIVE ; 
 int /*<<< orphan*/  IDC_CHECK_SHADING ; 
 int /*<<< orphan*/  IDC_COMBO_ROTATION ; 
 int /*<<< orphan*/  IDC_IMAGE_COSMOS ; 
 int /*<<< orphan*/  IDC_SLIDER_NUM_OF_STARS ; 
 int /*<<< orphan*/  IDC_SLIDER_SPEED ; 
 int /*<<< orphan*/  IDC_TEXT_NUM_OF_STARS ; 
 int /*<<< orphan*/  IDC_TEXT_SPEED ; 
 int /*<<< orphan*/  IDI_STARFIELD ; 
 int /*<<< orphan*/  IDS_AUTHOR ; 
 int /*<<< orphan*/  IDS_DESCRIPTION ; 
 int /*<<< orphan*/  IDS_LICENSE ; 
 int /*<<< orphan*/  IMAGE_BITMAP ; 
 int /*<<< orphan*/  KEY_READ ; 
 int /*<<< orphan*/  KEY_WRITE ; 
 int LR_CREATEDIBSECTION ; 
 int LR_DEFAULTSIZE ; 
 int /*<<< orphan*/  LoadIcon (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ LoadImage (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 size_t LoadString (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  MAKEINTRESOURCE (int /*<<< orphan*/ ) ; 
 scalar_t__ MAKELPARAM (int,int) ; 
 scalar_t__ MAX_SPEED ; 
 scalar_t__ MAX_STARS ; 
 scalar_t__ MIN_SPEED ; 
 scalar_t__ MIN_STARS ; 
 int /*<<< orphan*/  PROOF_QUALITY ; 
 scalar_t__ REG_DWORD ; 
 int /*<<< orphan*/  RGB (int,int,int) ; 
 size_t ROTATION_ITEMS ; 
 scalar_t__ ROTATION_LINEAR ; 
 scalar_t__ ROTATION_NONE ; 
 scalar_t__ ROTATION_PERIODIC ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 scalar_t__ RegCreateKeyEx (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ RegQueryValueEx (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  RegSetValueEx (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * RotoStrings ; 
 int SIZEOF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  STM_SETIMAGE ; 
 scalar_t__ SelectObject (int /*<<< orphan*/ ,scalar_t__) ; 
 void* SendDlgItemMessage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  SetBkMode (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetDlgItemInt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetTextColor (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_5__ Settings ; 
 int /*<<< orphan*/  ShellAbout (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TBM_GETPOS ; 
 int /*<<< orphan*/  TBM_SETPOS ; 
 int /*<<< orphan*/  TBM_SETRANGE ; 
 int /*<<< orphan*/  TRANSPARENT ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  TextOut (int /*<<< orphan*/ ,int,size_t,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_2__*,int) ; 
 int /*<<< orphan*/ * _T (char*) ; 
 int /*<<< orphan*/  _tcscat (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _tcscpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static DWORD QueryDWORD(HKEY hKey, LPCTSTR pszValueName, DWORD Default)
{
    DWORD dwData, dwType, cbData;
    LONG  lRes;

    dwType = REG_DWORD;
    cbData = sizeof(DWORD);

    lRes = RegQueryValueEx(
                hKey,
                pszValueName,
                NULL,
                &dwType,
                (LPBYTE)&dwData,
                &cbData);

    if (lRes != ERROR_SUCCESS || dwType != REG_DWORD)
        return Default;

    return dwData;
}

__attribute__((used)) static void SaveDWORD(HKEY hKey, LPCTSTR pszValueName, DWORD dwValue)
{
    RegSetValueEx(hKey, pszValueName, 0, REG_DWORD, (LPBYTE)&dwValue, sizeof(dwValue));
}

void LoadSettings(void)
{
    HKEY  hKey;
    LONG  lRes;

    Settings = FactoryDefaults;

    lRes = RegCreateKeyEx(
            HKEY_CURRENT_USER,
            _T("Software\\Microsoft\\ScreenSavers\\Ssstars"),
            0,
            _T(""),
            0,
            KEY_READ,
            NULL,
            &hKey,
            NULL);

    if (lRes != ERROR_SUCCESS)
        return;

    Settings.uiNumStars = QueryDWORD(hKey, _T("NumberOfStars"),  Settings.uiNumStars);
    Settings.uiSpeed    = QueryDWORD(hKey, _T("Speed"),          Settings.uiSpeed);
    Settings.uiRotation = QueryDWORD(hKey, _T("TypeOfRotation"), Settings.uiRotation);

    Settings.bDoBlending      = QueryDWORD(hKey, _T("DoBlending"),      Settings.bDoBlending);
    Settings.bFinePerspective = QueryDWORD(hKey, _T("FinePerspective"), Settings.bFinePerspective);
    Settings.bEnableFiltering = QueryDWORD(hKey, _T("EnableFiltering"), Settings.bEnableFiltering);
    Settings.bSmoothShading   = QueryDWORD(hKey, _T("SmoothShading"),   Settings.bSmoothShading);

    // Check the number of stars to be in range
    if (Settings.uiNumStars < MIN_STARS)
        Settings.uiNumStars = MIN_STARS;
    else
    if (Settings.uiNumStars > MAX_STARS)
        Settings.uiNumStars = MAX_STARS;

    // Check the speed to be in range
    if (Settings.uiSpeed < MIN_SPEED)
        Settings.uiSpeed = MIN_SPEED;
    else
    if (Settings.uiSpeed > MAX_SPEED)
        Settings.uiSpeed = MAX_SPEED;

    // Check type of rotation to be in range
    if (Settings.uiRotation != ROTATION_NONE &&
        Settings.uiRotation != ROTATION_LINEAR &&
        Settings.uiRotation != ROTATION_PERIODIC)
        Settings.uiRotation = ROTATION_PERIODIC;

    RegCloseKey(hKey);
}

void SaveSettings(void)
{
    HKEY  hKey;
    LONG  lRes;

    lRes = RegCreateKeyEx(
            HKEY_CURRENT_USER,
            _T("Software\\Microsoft\\ScreenSavers\\Ssstars"),
            0,
            _T(""),
            0,
            KEY_WRITE,
            NULL,
            &hKey,
            NULL);

    if (lRes != ERROR_SUCCESS)
        return;

    SaveDWORD(hKey, _T("NumberOfStars"),  Settings.uiNumStars);
    SaveDWORD(hKey, _T("Speed"),          Settings.uiSpeed);
    SaveDWORD(hKey, _T("TypeOfRotation"), Settings.uiRotation);

    SaveDWORD(hKey, _T("DoBlending"),      Settings.bDoBlending);
    SaveDWORD(hKey, _T("FinePerspective"), Settings.bFinePerspective);
    SaveDWORD(hKey, _T("EnableFiltering"), Settings.bEnableFiltering);
    SaveDWORD(hKey, _T("SmoothShading"),   Settings.bSmoothShading);

    RegCloseKey(hKey);
}

__attribute__((used)) static void SetupControls(HWND hWnd)
{
    TCHAR     Strings[256];
    HINSTANCE hInstance;
    UINT      x, gap;
    LOGFONT   lf;
    HFONT     hFont;
    HBITMAP   hCosmos;
    HDC       hDC, hMemDC;
    HGDIOBJ   hOldBmp, hOldFnt;
    SIZE      sizeReactOS;
    SIZE      sizeStarfield;
    BITMAP    bm;

    hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);

    SendDlgItemMessage(hWnd, IDC_SLIDER_NUM_OF_STARS, TBM_SETRANGE, FALSE, MAKELPARAM(MIN_STARS, MAX_STARS));

    SendDlgItemMessage(hWnd, IDC_SLIDER_SPEED, TBM_SETRANGE, FALSE, MAKELPARAM(1, 100));

    for (x = 0; x < ROTATION_ITEMS; x++)
    {
        LoadString(hInstance, RotoStrings[x], Strings, sizeof(Strings)/sizeof(TCHAR));
        SendDlgItemMessage(hWnd, IDC_COMBO_ROTATION, CB_ADDSTRING, 0, (LPARAM)Strings);
    }

    hCosmos = LoadImage(hInstance, MAKEINTRESOURCE(IDB_COSMOS), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

    hDC = GetDC(hWnd);
    hMemDC = CreateCompatibleDC(hDC);

    // Create the font for the title
    ZeroMemory(&lf, sizeof(lf));

    lf.lfWeight  = FW_THIN;
    lf.lfCharSet = ANSI_CHARSET;
    lf.lfQuality = PROOF_QUALITY;
    lf.lfHeight  = 36;
    _tcscpy(lf.lfFaceName, _T("Tahoma"));

    hFont = CreateFontIndirect(&lf);

    hOldBmp = SelectObject(hMemDC, hCosmos);
    hOldFnt = SelectObject(hMemDC, hFont);

    SetBkMode(hMemDC, TRANSPARENT);
    SetTextColor(hMemDC, RGB(0xFF, 0xFF, 0xFF));

    x = LoadString(hInstance, IDS_DESCRIPTION, Strings, sizeof(Strings)/sizeof(TCHAR));

    GetTextExtentPoint32(hMemDC, _T("ReactOS"), 7, &sizeReactOS);
    GetTextExtentPoint32(hMemDC, Strings,       x, &sizeStarfield);

    GetObject(hCosmos, sizeof(BITMAP), &bm);

    gap = bm.bmHeight - sizeReactOS.cy - sizeStarfield.cy;

    TextOut(hMemDC, 16, gap * 2 / 5, _T("ReactOS"), 7);
    TextOut(hMemDC, 16, gap * 3 / 5 + sizeReactOS.cy, Strings, x);

    SelectObject(hMemDC, hOldBmp);
    SelectObject(hMemDC, hOldFnt);

    DeleteObject(hFont);

    DeleteDC(hMemDC);
    ReleaseDC(hWnd, hDC);

    SendDlgItemMessage(hWnd, IDC_IMAGE_COSMOS, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hCosmos);
}

__attribute__((used)) static void ApplySettings(HWND hWnd)
{
    SendDlgItemMessage(hWnd, IDC_SLIDER_NUM_OF_STARS, TBM_SETPOS, TRUE, Settings.uiNumStars);
    SetDlgItemInt(hWnd, IDC_TEXT_NUM_OF_STARS, Settings.uiNumStars, FALSE);

    SendDlgItemMessage(hWnd, IDC_SLIDER_SPEED, TBM_SETPOS, TRUE, Settings.uiSpeed);
    SetDlgItemInt(hWnd, IDC_TEXT_SPEED, Settings.uiSpeed, FALSE);

    SendDlgItemMessage(hWnd, IDC_COMBO_ROTATION, CB_SETCURSEL, (WPARAM)Settings.uiRotation, 0);

    SendDlgItemMessage(hWnd, IDC_CHECK_DOBLENDING,  BM_SETCHECK, (WPARAM)Settings.bDoBlending, 0);
    SendDlgItemMessage(hWnd, IDC_CHECK_PERSPECTIVE, BM_SETCHECK, (WPARAM)Settings.bFinePerspective, 0);
    SendDlgItemMessage(hWnd, IDC_CHECK_FILTERING,   BM_SETCHECK, (WPARAM)Settings.bEnableFiltering, 0);
    SendDlgItemMessage(hWnd, IDC_CHECK_SHADING,     BM_SETCHECK, (WPARAM)Settings.bSmoothShading, 0);
}

__attribute__((used)) static void ReadSettings(HWND hWnd)
{
    Settings.uiNumStars = SendDlgItemMessage(hWnd, IDC_SLIDER_NUM_OF_STARS, TBM_GETPOS, 0, 0);
    SetDlgItemInt(hWnd, IDC_TEXT_NUM_OF_STARS, Settings.uiNumStars, FALSE);

    Settings.uiSpeed = SendDlgItemMessage(hWnd, IDC_SLIDER_SPEED, TBM_GETPOS, 0, 0);
    SetDlgItemInt(hWnd, IDC_TEXT_SPEED, Settings.uiSpeed, FALSE);

    Settings.uiRotation = SendDlgItemMessage(hWnd, IDC_COMBO_ROTATION, CB_GETCURSEL, 0, 0);

    Settings.bDoBlending      = SendDlgItemMessage(hWnd, IDC_CHECK_DOBLENDING,  BM_GETCHECK, 0, 0);
    Settings.bFinePerspective = SendDlgItemMessage(hWnd, IDC_CHECK_PERSPECTIVE, BM_GETCHECK, 0, 0);
    Settings.bEnableFiltering = SendDlgItemMessage(hWnd, IDC_CHECK_FILTERING,   BM_GETCHECK, 0, 0);
    Settings.bSmoothShading   = SendDlgItemMessage(hWnd, IDC_CHECK_SHADING,     BM_GETCHECK, 0, 0);
}

__attribute__((used)) static BOOL OnCommandAbout(HWND hWnd)
{
    HINSTANCE hInstance;
    HICON     hIcon;
    TCHAR     szAppName[256];
    TCHAR     szAuthor[256];
    TCHAR     szLicense[1024];

    hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);

    hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_STARFIELD));

    LoadString(hInstance, IDS_DESCRIPTION, szAppName, SIZEOF(szAppName));
    LoadString(hInstance, IDS_AUTHOR,      szAuthor,  SIZEOF(szAuthor));
    LoadString(hInstance, IDS_LICENSE,     szLicense, SIZEOF(szLicense));

    _tcscat(szAppName, _T("#"));
    _tcscat(szAppName, szAuthor);

    ShellAbout(hWnd, szAppName, szLicense, hIcon);

    return TRUE;
}

