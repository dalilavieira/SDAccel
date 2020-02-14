#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WORD ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_4__ {int dwSize; scalar_t__ lParam; int /*<<< orphan*/  pfnDlgProc; int /*<<< orphan*/  pszTemplate; int /*<<< orphan*/  hInstance; int /*<<< orphan*/  dwFlags; } ;
typedef  TYPE_1__ PROPSHEETPAGEW ;
typedef  int /*<<< orphan*/  PCONSOLE_STATE_INFO ;
typedef  int /*<<< orphan*/  DLGPROC ;

/* Variables and functions */
 int /*<<< orphan*/  ConCfgGetDefaultSettings (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAKEINTRESOURCEW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PSP_DEFAULT ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_1__*,int) ; 
 int /*<<< orphan*/  hApplet ; 

__attribute__((used)) static VOID
InitPropSheetPage(PROPSHEETPAGEW *psp,
                  WORD idDlg,
                  DLGPROC DlgProc)
{
    ZeroMemory(psp, sizeof(*psp));
    psp->dwSize      = sizeof(*psp);
    psp->dwFlags     = PSP_DEFAULT;
    psp->hInstance   = hApplet;
    psp->pszTemplate = MAKEINTRESOURCEW(idDlg);
    psp->pfnDlgProc  = DlgProc;
    psp->lParam      = 0;
}

__attribute__((used)) static VOID
InitDefaultConsoleInfo(PCONSOLE_STATE_INFO pConInfo)
{
    // FIXME: Also retrieve the value of REG_DWORD CurrentPage.
    ConCfgGetDefaultSettings(pConInfo);
}

