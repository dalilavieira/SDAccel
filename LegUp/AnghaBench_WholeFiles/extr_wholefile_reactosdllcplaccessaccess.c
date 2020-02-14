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
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WORD ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_10__ {int cbSize; int /*<<< orphan*/  lpszPort; int /*<<< orphan*/  lpszActivePort; } ;
struct TYPE_9__ {void* bSoundOnActivation; void* bWarningSounds; TYPE_4__ serialKeys; int /*<<< orphan*/  szPort; int /*<<< orphan*/  szActivePort; TYPE_4__ accessTimeout; TYPE_4__ mouseKeys; TYPE_4__ bShowSounds; TYPE_4__ ssSoundSentry; int /*<<< orphan*/  uCaretBlinkTime; TYPE_4__ uCaretWidth; TYPE_4__ highContrast; TYPE_4__ bKeyboardPref; TYPE_4__ toggleKeys; TYPE_4__ filterKeys; TYPE_4__ stickyKeys; } ;
struct TYPE_8__ {int dwSize; scalar_t__ lParam; int /*<<< orphan*/  pfnDlgProc; int /*<<< orphan*/  pszTemplate; int /*<<< orphan*/  hInstance; int /*<<< orphan*/  dwFlags; } ;
typedef  int /*<<< orphan*/  TOGGLEKEYS ;
typedef  int /*<<< orphan*/  STICKYKEYS ;
typedef  int /*<<< orphan*/  SOUNDSENTRY ;
typedef  int /*<<< orphan*/  SERIALKEYS ;
typedef  TYPE_1__ PROPSHEETPAGE ;
typedef  TYPE_2__* PGLOBAL_DATA ;
typedef  int /*<<< orphan*/  MOUSEKEYS ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  scalar_t__ LPARAM ;
typedef  scalar_t__ LONG ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  int /*<<< orphan*/  HIGHCONTRAST ;
typedef  int /*<<< orphan*/  FILTERKEYS ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  DLGPROC ;
typedef  void* BOOL ;
typedef  int /*<<< orphan*/  ACCESSTIMEOUT ;

/* Variables and functions */
 scalar_t__ ERROR_SUCCESS ; 
 void* FALSE ; 
 int /*<<< orphan*/  GetCaretBlinkTime () ; 
 int /*<<< orphan*/  HKEY_CURRENT_USER ; 
 int KEY_EXECUTE ; 
 int KEY_QUERY_VALUE ; 
 int /*<<< orphan*/  MAKEINTRESOURCE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PSP_DEFAULT ; 
 int /*<<< orphan*/  REG_OPTION_NON_VOLATILE ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 scalar_t__ RegCreateKeyEx (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 
 scalar_t__ RegQueryValueEx (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  SPI_GETACCESSTIMEOUT ; 
 int /*<<< orphan*/  SPI_GETCARETWIDTH ; 
 int /*<<< orphan*/  SPI_GETFILTERKEYS ; 
 int /*<<< orphan*/  SPI_GETHIGHCONTRAST ; 
 int /*<<< orphan*/  SPI_GETKEYBOARDPREF ; 
 int /*<<< orphan*/  SPI_GETMOUSEKEYS ; 
 int /*<<< orphan*/  SPI_GETSERIALKEYS ; 
 int /*<<< orphan*/  SPI_GETSHOWSOUNDS ; 
 int /*<<< orphan*/  SPI_GETSOUNDSENTRY ; 
 int /*<<< orphan*/  SPI_GETSTICKYKEYS ; 
 int /*<<< orphan*/  SPI_GETTOGGLEKEYS ; 
 int /*<<< orphan*/  SystemParametersInfo (int /*<<< orphan*/ ,int,TYPE_4__*,int /*<<< orphan*/ ) ; 
 void* TRUE ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_1__*,int) ; 
 int /*<<< orphan*/  _T (char*) ; 
 int /*<<< orphan*/  hApplet ; 

__attribute__((used)) static BOOL
ReadSettings(PGLOBAL_DATA pGlobalData)
{
    DWORD dwDisposition;
    DWORD dwLength;
    HKEY hKey;
    LONG lError;

    /* Get sticky keys information */
    pGlobalData->stickyKeys.cbSize = sizeof(STICKYKEYS);
    if (!SystemParametersInfo(SPI_GETSTICKYKEYS,
                              sizeof(STICKYKEYS),
                              &pGlobalData->stickyKeys,
                              0))
        return FALSE;

    /* Get filter keys information */
    pGlobalData->filterKeys.cbSize = sizeof(FILTERKEYS);
    if (!SystemParametersInfo(SPI_GETFILTERKEYS,
                              sizeof(FILTERKEYS),
                              &pGlobalData->filterKeys,
                              0))
        return FALSE;

    /* Get toggle keys information */
    pGlobalData->toggleKeys.cbSize = sizeof(TOGGLEKEYS);
    if (!SystemParametersInfo(SPI_GETTOGGLEKEYS,
                              sizeof(TOGGLEKEYS),
                              &pGlobalData->toggleKeys,
                              0))
        return FALSE;

    /* Get keyboard preference information */
    if (!SystemParametersInfo(SPI_GETKEYBOARDPREF,
                              0,
                              &pGlobalData->bKeyboardPref,
                              0))
        return FALSE;

    /* Get high contrast information */
    pGlobalData->highContrast.cbSize = sizeof(HIGHCONTRAST);
    SystemParametersInfo(SPI_GETHIGHCONTRAST,
                         sizeof(HIGHCONTRAST),
                         &pGlobalData->highContrast,
                         0);

    SystemParametersInfo(SPI_GETCARETWIDTH,
                         0,
                         &pGlobalData->uCaretWidth,
                         0);

    pGlobalData->uCaretBlinkTime = GetCaretBlinkTime();

    /* Get sound settings */
    pGlobalData->ssSoundSentry.cbSize = sizeof(SOUNDSENTRY);
    SystemParametersInfo(SPI_GETSOUNDSENTRY,
                         sizeof(SOUNDSENTRY),
                         &pGlobalData->ssSoundSentry,
                         0);

    SystemParametersInfo(SPI_GETSHOWSOUNDS,
                         0,
                         &pGlobalData->bShowSounds,
                         0);

    /* Get mouse keys information */
    pGlobalData->mouseKeys.cbSize = sizeof(MOUSEKEYS);
    SystemParametersInfo(SPI_GETMOUSEKEYS,
                         sizeof(MOUSEKEYS),
                         &pGlobalData->mouseKeys,
                         0);

    /* Get access timeout information */
    pGlobalData->accessTimeout.cbSize = sizeof(ACCESSTIMEOUT);
    SystemParametersInfo(SPI_GETACCESSTIMEOUT,
                         sizeof(ACCESSTIMEOUT),
                         &pGlobalData->accessTimeout,
                         0);

    /* Get serial keys information */
    pGlobalData->serialKeys.cbSize = sizeof(SERIALKEYS);
    pGlobalData->serialKeys.lpszActivePort = pGlobalData->szActivePort;
    pGlobalData->serialKeys.lpszPort = pGlobalData->szPort;
    SystemParametersInfo(SPI_GETSERIALKEYS,
                         sizeof(SERIALKEYS),
                         &pGlobalData->serialKeys,
                         0);

    pGlobalData->bWarningSounds = TRUE;
    pGlobalData->bSoundOnActivation = TRUE;

    lError = RegCreateKeyEx(HKEY_CURRENT_USER,
                            _T("Control Panel\\Accessibility"),
                            0,
                            NULL,
                            REG_OPTION_NON_VOLATILE,
                            KEY_EXECUTE | KEY_QUERY_VALUE,
                            NULL,
                            &hKey,
                            &dwDisposition);
    if (lError != ERROR_SUCCESS)
        return TRUE;

    dwLength = sizeof(BOOL);
    lError = RegQueryValueEx(hKey,
                             _T("Warning Sounds"),
                             NULL,
                             NULL,
                             (LPBYTE)&pGlobalData->bWarningSounds,
                             &dwLength);
    if (lError != ERROR_SUCCESS)
        pGlobalData->bWarningSounds = TRUE;

    dwLength = sizeof(BOOL);
    lError = RegQueryValueEx(hKey,
                             _T("Sound On Activation"),
                             NULL,
                             NULL,
                             (LPBYTE)&pGlobalData->bSoundOnActivation,
                             &dwLength);
    if (lError != ERROR_SUCCESS)
        pGlobalData->bSoundOnActivation = TRUE;

    RegCloseKey(hKey);

    return TRUE;
}

__attribute__((used)) static VOID
InitPropSheetPage(PROPSHEETPAGE *psp, WORD idDlg, DLGPROC DlgProc, PGLOBAL_DATA pGlobalData)
{
    ZeroMemory(psp, sizeof(PROPSHEETPAGE));
    psp->dwSize = sizeof(PROPSHEETPAGE);
    psp->dwFlags = PSP_DEFAULT;
    psp->hInstance = hApplet;
    psp->pszTemplate = MAKEINTRESOURCE(idDlg);
    psp->pfnDlgProc = DlgProc;
    psp->lParam = (LPARAM)pGlobalData;
}

