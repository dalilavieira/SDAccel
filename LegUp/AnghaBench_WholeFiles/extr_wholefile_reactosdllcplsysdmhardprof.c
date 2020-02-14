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
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_10__ {scalar_t__ dwSelectedProfileIndex; int dwProfileCount; } ;
struct TYPE_9__ {int /*<<< orphan*/  szDestinationName; TYPE_2__* pProfileData; } ;
struct TYPE_8__ {scalar_t__ dwProfileCount; scalar_t__ dwSelectedProfileIndex; TYPE_1__* pProfiles; } ;
struct TYPE_7__ {int /*<<< orphan*/  szFriendlyName; } ;
typedef  TYPE_3__* PPROFILENAMES ;
typedef  TYPE_4__* PPROFILEDATA ;
typedef  int /*<<< orphan*/  HWND ;
typedef  scalar_t__ DWORD ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  EnableWindow (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IDC_HRDPROFCOPY ; 
 int /*<<< orphan*/  IDC_HRDPROFDEL ; 
 int /*<<< orphan*/  IDC_HRDPROFDWN ; 
 int /*<<< orphan*/  IDC_HRDPROFPROP ; 
 int /*<<< orphan*/  IDC_HRDPROFRENAME ; 
 int /*<<< orphan*/  IDC_HRDPROFUP ; 
 scalar_t__ TRUE ; 
 scalar_t__ wcscmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
VOID
UpdateButtons(
    HWND hwndDlg,
    PPROFILEDATA pProfileData)
{
    EnableWindow(GetDlgItem(hwndDlg, IDC_HRDPROFPROP), (pProfileData->dwSelectedProfileIndex != (DWORD)-1) ? TRUE : FALSE);
    EnableWindow(GetDlgItem(hwndDlg, IDC_HRDPROFCOPY), (pProfileData->dwSelectedProfileIndex != (DWORD)-1) ? TRUE : FALSE);
    EnableWindow(GetDlgItem(hwndDlg, IDC_HRDPROFRENAME), (pProfileData->dwSelectedProfileIndex != (DWORD)-1) ? TRUE : FALSE);
    EnableWindow(GetDlgItem(hwndDlg, IDC_HRDPROFDEL), (pProfileData->dwSelectedProfileIndex != (DWORD)-1) ? TRUE : FALSE);

    if (pProfileData->dwProfileCount < 2)
    {
        EnableWindow(GetDlgItem(hwndDlg, IDC_HRDPROFUP), FALSE);
        EnableWindow(GetDlgItem(hwndDlg, IDC_HRDPROFDWN), FALSE);
    }
    else
    {
        EnableWindow(GetDlgItem(hwndDlg, IDC_HRDPROFUP),
                     (pProfileData->dwSelectedProfileIndex > 0) ? TRUE : FALSE);
        EnableWindow(GetDlgItem(hwndDlg, IDC_HRDPROFDWN),
                     (pProfileData->dwSelectedProfileIndex < pProfileData->dwProfileCount - 1) ? TRUE : FALSE);
    }
}

__attribute__((used)) static
BOOL
IsProfileNameInUse(
    PPROFILENAMES pProfileNames,
    BOOL bIgnoreCurrent)
{
    DWORD i;

    for (i = 0; i < pProfileNames->pProfileData->dwProfileCount; i++)
    {
        if (bIgnoreCurrent == TRUE && i == pProfileNames->pProfileData->dwSelectedProfileIndex)
            continue;

        if (wcscmp(pProfileNames->pProfileData->pProfiles[i].szFriendlyName, pProfileNames->szDestinationName) == 0)
            return TRUE;
    }

    return FALSE;
}

