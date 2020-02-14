#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  dwSoundOnClick ;
typedef  int /*<<< orphan*/  dwShowWarningData ;
typedef  int /*<<< orphan*/  dwPositionTop ;
typedef  int /*<<< orphan*/  dwPositionLeft ;
typedef  int /*<<< orphan*/  dwLayout ;
struct TYPE_5__ {scalar_t__ left; scalar_t__ top; } ;
struct TYPE_6__ {int length; TYPE_1__ rcNormalPosition; } ;
typedef  TYPE_2__ WINDOWPLACEMENT ;
struct TYPE_7__ {int bShowWarning; int bIsEnhancedKeyboard; int bSoundClick; int /*<<< orphan*/  hMainWnd; void* PosY; void* PosX; } ;
typedef  scalar_t__ LONG ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  void* BOOL ;

/* Variables and functions */
 void* CW_USEDEFAULT ; 
 scalar_t__ ERROR_SUCCESS ; 
 void* FALSE ; 
 int /*<<< orphan*/  GetWindowPlacement (int /*<<< orphan*/ ,TYPE_2__*) ; 
 TYPE_3__ Globals ; 
 int /*<<< orphan*/  HKEY_CURRENT_USER ; 
 int /*<<< orphan*/  KEY_READ ; 
 int /*<<< orphan*/  KEY_WRITE ; 
 int /*<<< orphan*/  REG_DWORD ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 scalar_t__ RegCreateKeyExW (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ RegOpenKeyExW (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ RegQueryValueExW (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__*) ; 
 scalar_t__ RegSetValueExW (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 void* TRUE ; 

BOOL LoadDataFromRegistry()
{
    HKEY hKey;
    LONG lResult;
    DWORD dwShowWarningData, dwLayout, dwSoundOnClick, dwPositionLeft, dwPositionTop;
    DWORD cbData = sizeof(DWORD);

    /* Set the structure members to TRUE (and the bSoundClick member to FALSE) */
    Globals.bShowWarning = TRUE;
    Globals.bIsEnhancedKeyboard = TRUE;
    Globals.bSoundClick = FALSE;

    /* Set the coordinate values to default */
    Globals.PosX = CW_USEDEFAULT;
    Globals.PosY = CW_USEDEFAULT;

    /* Open the key, so that we can query it */
    lResult = RegOpenKeyExW(HKEY_CURRENT_USER,
                            L"Software\\Microsoft\\Osk",
                            0,
                            KEY_READ,
                            &hKey);

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        return FALSE;
    }

    /* Query the key */
    lResult = RegQueryValueExW(hKey,
                               L"ShowWarning",
                               0,
                               0,
                               (BYTE *)&dwShowWarningData,
                               &cbData);

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* Load the data value (it can be either FALSE or TRUE depending on the data itself) */
    Globals.bShowWarning = (dwShowWarningData != 0);

    /* Query the key */
    lResult = RegQueryValueExW(hKey,
                               L"IsEnhancedKeyboard",
                               0,
                               0,
                               (BYTE *)&dwLayout,
                               &cbData);

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* Load the dialog layout value */
    Globals.bIsEnhancedKeyboard = (dwLayout != 0);

    /* Query the key */
    lResult = RegQueryValueExW(hKey,
                               L"ClickSound",
                               0,
                               0,
                               (BYTE *)&dwSoundOnClick,
                               &cbData);

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* Load the sound on click value event */
    Globals.bSoundClick = (dwSoundOnClick != 0);

    /* Query the key */
    lResult = RegQueryValueExW(hKey,
                               L"WindowLeft",
                               0,
                               0,
                               (BYTE *)&dwPositionLeft,
                               &cbData);

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* Load the X value data of the dialog's coordinate */
    Globals.PosX = dwPositionLeft;

    lResult = RegQueryValueExW(hKey,
                               L"WindowTop",
                               0,
                               0,
                               (BYTE *)&dwPositionTop,
                               &cbData);

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* Load the Y value data of the dialog's coordinate */
    Globals.PosY = dwPositionTop;
    
    /* If we're here then we succeed, close the key and return TRUE */
    RegCloseKey(hKey);
    return TRUE;
}

BOOL SaveDataToRegistry()
{
    HKEY hKey;
    LONG lResult;
    DWORD dwShowWarningData, dwLayout, dwSoundOnClick, dwPositionLeft, dwPositionTop;
    WINDOWPLACEMENT wp;

    /* Set the structure length and retrieve the dialog's placement */
    wp.length = sizeof(WINDOWPLACEMENT);
    GetWindowPlacement(Globals.hMainWnd, &wp);

    /* If no key has been made, create one */
    lResult = RegCreateKeyExW(HKEY_CURRENT_USER,
                              L"Software\\Microsoft\\Osk",
                              0,
                              NULL,
                              0,
                              KEY_WRITE,
                              NULL,
                              &hKey,
                              NULL);

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        return FALSE;
    }

    /* The data value of the subkey will be appended to the warning dialog switch */
    dwShowWarningData = Globals.bShowWarning;

    /* Welcome warning box value key */
    lResult = RegSetValueExW(hKey,
                             L"ShowWarning",
                             0,
                             REG_DWORD,
                             (BYTE *)&dwShowWarningData,
                             sizeof(dwShowWarningData));

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* The value will be appended to the layout dialog */
    dwLayout = Globals.bIsEnhancedKeyboard;

    /* Keyboard dialog switcher */
    lResult = RegSetValueExW(hKey,
                             L"IsEnhancedKeyboard",
                             0,
                             REG_DWORD,
                             (BYTE *)&dwLayout,
                             sizeof(dwLayout));

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* The value will be appended to the sound on click event */
    dwSoundOnClick = Globals.bSoundClick;

    /* "Sound on Click" switcher value key */
    lResult = RegSetValueExW(hKey,
                             L"ClickSound",
                             0,
                             REG_DWORD,
                             (BYTE *)&dwSoundOnClick,
                             sizeof(dwSoundOnClick));

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* The value will be appended to the X coordination dialog's placement */
    dwPositionLeft = wp.rcNormalPosition.left;

    /* Position X coordination of dialog's placement value key */
    lResult = RegSetValueExW(hKey,
                             L"WindowLeft",
                             0,
                             REG_DWORD,
                             (BYTE *)&dwPositionLeft,
                             sizeof(dwPositionLeft));

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* The value will be appended to the Y coordination dialog's placement */
    dwPositionTop = wp.rcNormalPosition.top;

    /* Position Y coordination of dialog's placement value key */
    lResult = RegSetValueExW(hKey,
                             L"WindowTop",
                             0,
                             REG_DWORD,
                             (BYTE *)&dwPositionTop,
                             sizeof(dwPositionTop));

    if (lResult != ERROR_SUCCESS)
    {
        /* Bail out and return FALSE if we fail */
        RegCloseKey(hKey);
        return FALSE;
    }

    /* If we're here then we succeed, close the key and return TRUE */
    RegCloseKey(hKey);
    return TRUE;
}

