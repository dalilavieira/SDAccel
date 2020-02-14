#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_6__ {int x; int y; } ;
struct TYPE_5__ {int left; int right; int top; int bottom; } ;
typedef  TYPE_1__ RECT ;
typedef  TYPE_2__ POINT ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int INT ;
typedef  scalar_t__ HWND ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 scalar_t__ BST_CHECKED ; 
 scalar_t__ BST_UNCHECKED ; 
 int /*<<< orphan*/  CheckDlgButton (scalar_t__,int const,scalar_t__) ; 
 int /*<<< orphan*/  EndDialog (scalar_t__,int const) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetClientRect (scalar_t__,TYPE_1__*) ; 
 int const GetDlgCtrlID (scalar_t__) ; 
 scalar_t__ GetDlgItem (scalar_t__,int const) ; 
 scalar_t__ GetNextDlgGroupItem (scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ GetNextDlgTabItem (scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
#define  IDCANCEL 140 
#define  IDC_END 139 
#define  IDC_TEST1 138 
#define  IDC_TEST2 137 
#define  IDC_TEST3 136 
#define  IDOK 135 
 scalar_t__ IsDlgButtonChecked (scalar_t__,int const) ; 
 int /*<<< orphan*/  MAKELPARAM (int,int) ; 
 int /*<<< orphan*/  MAKEWPARAM (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MK_LBUTTON ; 
 int /*<<< orphan*/  PostMessage (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SW_HIDE ; 
 int /*<<< orphan*/  SW_SHOWNOACTIVATE ; 
 int /*<<< orphan*/  SendMessage (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ShowWindow (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WM_COMMAND ; 
 int /*<<< orphan*/  WM_LBUTTONDOWN ; 
 int /*<<< orphan*/  WM_LBUTTONUP ; 
 int /*<<< orphan*/  ok (int,char*,...) ; 
#define  psh1 134 
#define  rad1 133 
#define  rad2 132 
#define  rad3 131 
#define  rad5 130 
#define  rad6 129 
#define  rad7 128 

__attribute__((used)) static BOOL
OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    PostMessage(hwnd, WM_COMMAND, MAKEWPARAM(IDC_TEST1, 0), 0);
    return TRUE;
}

__attribute__((used)) static const char *
GetNameFromID(INT ID)
{
    switch (ID)
    {
        case rad1:      return "rad1";
        case rad2:      return "rad2";
        case rad3:      return "rad3";
        case psh1:      return "psh1";
        case rad5:      return "rad5";
        case rad6:      return "rad6";
        case rad7:      return "rad7";
        case IDOK:      return "OK button";
        case IDCANCEL:  return "Cancel button";
        default:        return "(unknown)";
    }
}

__attribute__((used)) static const char *
GetNameFromHWND(HWND hwnd)
{
    return GetNameFromID(GetDlgCtrlID(hwnd));
}

__attribute__((used)) static void
DoTest1(HWND hwnd)
{
    HWND hCtrl;
    HWND hRad1, hRad2, hRad3, hPsh1, hRad5, hRad6, hRad7, hOK, hCancel;

    // check control IDs
    hCtrl = GetDlgItem(hwnd, rad1);
    ok(GetDlgCtrlID(hCtrl) == rad1, "\n");
    hCtrl = GetDlgItem(hwnd, rad2);
    ok(GetDlgCtrlID(hCtrl) == rad2, "\n");
    hCtrl = GetDlgItem(hwnd, rad3);
    ok(GetDlgCtrlID(hCtrl) == rad3, "\n");
    hCtrl = GetDlgItem(hwnd, psh1);
    ok(GetDlgCtrlID(hCtrl) == psh1, "\n");
    hCtrl = GetDlgItem(hwnd, rad5);
    ok(GetDlgCtrlID(hCtrl) == rad5, "\n");
    hCtrl = GetDlgItem(hwnd, rad6);
    ok(GetDlgCtrlID(hCtrl) == rad6, "\n");
    hCtrl = GetDlgItem(hwnd, rad7);
    ok(GetDlgCtrlID(hCtrl) == rad7, "\n");
    hCtrl = GetDlgItem(hwnd, IDOK);
    ok(GetDlgCtrlID(hCtrl) == IDOK, "\n");
    hCtrl = GetDlgItem(hwnd, IDCANCEL);
    ok(GetDlgCtrlID(hCtrl) == IDCANCEL, "\n");

    // get dialog items
    hRad1 = GetDlgItem(hwnd, rad1);
    hRad2 = GetDlgItem(hwnd, rad2);
    hRad3 = GetDlgItem(hwnd, rad3);
    hPsh1 = GetDlgItem(hwnd, psh1);
    hRad5 = GetDlgItem(hwnd, rad5);
    hRad6 = GetDlgItem(hwnd, rad6);
    hRad7 = GetDlgItem(hwnd, rad7);
    hOK = GetDlgItem(hwnd, IDOK);
    hCancel = GetDlgItem(hwnd, IDCANCEL);

    // next
    hCtrl = GetNextDlgTabItem(hwnd, hRad1, FALSE);
    ok(hCtrl == hRad2, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad2, FALSE);
    ok(hCtrl == hRad3, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad3, FALSE);
    ok(hCtrl == hPsh1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hPsh1, FALSE);
    ok(hCtrl == hRad5, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad5, FALSE);
    ok(hCtrl == hRad6, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad6, FALSE);
    ok(hCtrl == hRad7, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad7, FALSE);
    ok(hCtrl == hOK, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hOK, FALSE);
    ok(hCtrl == hCancel, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hCancel, FALSE);
    ok(hCtrl == hRad1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));

    // prev
    hCtrl = GetNextDlgTabItem(hwnd, hRad1, TRUE);
    ok(hCtrl == hCancel, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad2, TRUE);
    ok(hCtrl == hRad1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad3, TRUE);
    ok(hCtrl == hRad2, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hPsh1, TRUE);
    ok(hCtrl == hRad3, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad5, TRUE);
    ok(hCtrl == hPsh1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad6, TRUE);
    ok(hCtrl == hRad5, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad7, TRUE);
    ok(hCtrl == hRad6, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hOK, TRUE);
    ok(hCtrl == hRad7, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hCancel, TRUE);
    ok(hCtrl == hOK, "hCtrl was %s\n", GetNameFromHWND(hCtrl));

    // hide
    ok(ShowWindow(hRad3, SW_HIDE) != 0, "\n");
    ok(ShowWindow(hRad6, SW_HIDE) != 0, "\n");

    // next with hidden
    hCtrl = GetNextDlgTabItem(hwnd, hRad1, FALSE);
    ok(hCtrl == hRad2, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad2, FALSE);
    ok(hCtrl == hPsh1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hPsh1, FALSE);
    ok(hCtrl == hRad5, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad5, FALSE);
    ok(hCtrl == hRad7, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad7, FALSE);
    ok(hCtrl == hOK, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hOK, FALSE);
    ok(hCtrl == hCancel, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hCancel, FALSE);
    ok(hCtrl == hRad1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));

    // prev with hidden
    hCtrl = GetNextDlgTabItem(hwnd, hRad1, TRUE);
    ok(hCtrl == hCancel, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad2, TRUE);
    ok(hCtrl == hRad1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hPsh1, TRUE);
    ok(hCtrl == hRad2, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad5, TRUE);
    ok(hCtrl == hPsh1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad7, TRUE);
    ok(hCtrl == hRad5, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hOK, TRUE);
    ok(hCtrl == hRad7, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hCancel, TRUE);
    ok(hCtrl == hOK, "hCtrl was %s\n", GetNameFromHWND(hCtrl));

    // show
    ShowWindow(hRad3, SW_SHOWNOACTIVATE);
    ShowWindow(hRad6, SW_SHOWNOACTIVATE);

    // next again
    hCtrl = GetNextDlgTabItem(hwnd, hRad1, FALSE);
    ok(hCtrl == hRad2, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad2, FALSE);
    ok(hCtrl == hRad3, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad3, FALSE);
    ok(hCtrl == hPsh1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hPsh1, FALSE);
    ok(hCtrl == hRad5, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad5, FALSE);
    ok(hCtrl == hRad6, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad6, FALSE);
    ok(hCtrl == hRad7, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad7, FALSE);
    ok(hCtrl == hOK, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hOK, FALSE);
    ok(hCtrl == hCancel, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hCancel, FALSE);
    ok(hCtrl == hRad1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));

    // prev again
    hCtrl = GetNextDlgTabItem(hwnd, hRad1, TRUE);
    ok(hCtrl == hCancel, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad2, TRUE);
    ok(hCtrl == hRad1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad3, TRUE);
    ok(hCtrl == hRad2, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hPsh1, TRUE);
    ok(hCtrl == hRad3, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad5, TRUE);
    ok(hCtrl == hPsh1, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad6, TRUE);
    ok(hCtrl == hRad5, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hRad7, TRUE);
    ok(hCtrl == hRad6, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hOK, TRUE);
    ok(hCtrl == hRad7, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgTabItem(hwnd, hCancel, TRUE);
    ok(hCtrl == hOK, "hCtrl was %s\n", GetNameFromHWND(hCtrl));
}

__attribute__((used)) static void
DoTest2(HWND hwnd)
{
    HWND hCtrl;
    HWND hRad1, hRad2, hRad3, hPsh1, hRad5, hRad6, hRad7, hOK, hCancel;

    // check control IDs
    hCtrl = GetDlgItem(hwnd, rad1);
    ok(GetDlgCtrlID(hCtrl) == rad1, "\n");
    hCtrl = GetDlgItem(hwnd, rad2);
    ok(GetDlgCtrlID(hCtrl) == rad2, "\n");
    hCtrl = GetDlgItem(hwnd, rad3);
    ok(GetDlgCtrlID(hCtrl) == rad3, "\n");
    hCtrl = GetDlgItem(hwnd, psh1);
    ok(GetDlgCtrlID(hCtrl) == psh1, "\n");
    hCtrl = GetDlgItem(hwnd, rad5);
    ok(GetDlgCtrlID(hCtrl) == rad5, "\n");
    hCtrl = GetDlgItem(hwnd, rad6);
    ok(GetDlgCtrlID(hCtrl) == rad6, "\n");
    hCtrl = GetDlgItem(hwnd, rad7);
    ok(GetDlgCtrlID(hCtrl) == rad7, "\n");
    hCtrl = GetDlgItem(hwnd, IDOK);
    ok(GetDlgCtrlID(hCtrl) == IDOK, "\n");
    hCtrl = GetDlgItem(hwnd, IDCANCEL);
    ok(GetDlgCtrlID(hCtrl) == IDCANCEL, "\n");

    // get dialog items
    hRad1 = GetDlgItem(hwnd, rad1);
    hRad2 = GetDlgItem(hwnd, rad2);
    hRad3 = GetDlgItem(hwnd, rad3);
    hPsh1 = GetDlgItem(hwnd, psh1);
    hRad5 = GetDlgItem(hwnd, rad5);
    hRad6 = GetDlgItem(hwnd, rad6);
    hRad7 = GetDlgItem(hwnd, rad7);
    hOK = GetDlgItem(hwnd, IDOK);
    hCancel = GetDlgItem(hwnd, IDCANCEL);

    // group next
    hCtrl = GetNextDlgGroupItem(hwnd, hRad1, FALSE);
    ok(hCtrl == hRad2, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad2, FALSE);
    ok(hCtrl == hRad3, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad3, FALSE);
    ok(hCtrl == hPsh1, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hPsh1, FALSE);
    ok(hCtrl == hRad5, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad5, FALSE);
    ok(hCtrl == hRad6, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad6, FALSE);
    ok(hCtrl == hRad7, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad7, FALSE);
    ok(hCtrl == hOK, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hOK, FALSE);
    ok(hCtrl == hCancel, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hCancel, FALSE);
    ok(hCtrl == hRad1, "hCtrl is %s\n", GetNameFromHWND(hCtrl));

    // group prev
    hCtrl = GetNextDlgGroupItem(hwnd, hRad1, TRUE);
    ok(hCtrl == hCancel, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad2, TRUE);
    ok(hCtrl == hRad1, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad3, TRUE);
    ok(hCtrl == hRad2, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hPsh1, TRUE);
    ok(hCtrl == hRad3, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad5, TRUE);
    ok(hCtrl == hPsh1, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad6, TRUE);
    ok(hCtrl == hRad5, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad7, TRUE);
    ok(hCtrl == hRad6, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hOK, TRUE);
    ok(hCtrl == hRad7, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hCancel, TRUE);
    ok(hCtrl == hOK, "hCtrl is %s\n", GetNameFromHWND(hCtrl));

    // hide
    ok(ShowWindow(hRad3, SW_HIDE) != 0, "\n");
    ok(ShowWindow(hRad6, SW_HIDE) != 0, "\n");

    // group next with hidden
    hCtrl = GetNextDlgGroupItem(hwnd, hRad1, FALSE);
    ok(hCtrl == hRad2, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad2, FALSE);
    ok(hCtrl == hPsh1, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hPsh1, FALSE);
    ok(hCtrl == hRad5, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad5, FALSE);
    ok(hCtrl == hRad7, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad7, FALSE);
    ok(hCtrl == hOK, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hOK, FALSE);
    ok(hCtrl == hCancel, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hCancel, FALSE);
    ok(hCtrl == hRad1, "hCtrl is %s\n", GetNameFromHWND(hCtrl));

    // group prev with hidden
    hCtrl = GetNextDlgGroupItem(hwnd, hRad1, TRUE);
    ok(hCtrl == hCancel, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad2, TRUE);
    ok(hCtrl == hRad1, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hPsh1, TRUE);
    ok(hCtrl == hRad2, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad5, TRUE);
    ok(hCtrl == hPsh1, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hRad7, TRUE);
    ok(hCtrl == hRad5, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hOK, TRUE);
    ok(hCtrl == hRad7, "hCtrl is %s\n", GetNameFromHWND(hCtrl));
    hCtrl = GetNextDlgGroupItem(hwnd, hCancel, TRUE);
    ok(hCtrl == hOK, "hCtrl is %s\n", GetNameFromHWND(hCtrl));

    // show
    ShowWindow(hRad3, SW_SHOWNOACTIVATE);
    ShowWindow(hRad6, SW_SHOWNOACTIVATE);
}

__attribute__((used)) static POINT
GetCtrlCenter(HWND hCtrl)
{
    RECT rc;
    POINT pt;

    GetClientRect(hCtrl, &rc);
    pt.x = (rc.left + rc.right) / 2;
    pt.y = (rc.top + rc.bottom) / 2;
    return pt;
}

__attribute__((used)) static void
DoTest3(HWND hwnd)
{
    HWND hCtrl;
    POINT pt;

    CheckDlgButton(hwnd, rad1, BST_CHECKED);
    CheckDlgButton(hwnd, rad5, BST_CHECKED);

    ok(IsDlgButtonChecked(hwnd, rad1) == BST_CHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad2) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad3) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad5) == BST_CHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad6) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad7) == BST_UNCHECKED, "\n");

    hCtrl = GetDlgItem(hwnd, rad1);
    pt = GetCtrlCenter(hCtrl);
    SendMessage(hCtrl, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
    SendMessage(hCtrl, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));

    ok(IsDlgButtonChecked(hwnd, rad1) == BST_CHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad2) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad3) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad5) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad6) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad7) == BST_UNCHECKED, "\n");

    hCtrl = GetDlgItem(hwnd, rad5);
    pt = GetCtrlCenter(hCtrl);
    SendMessage(hCtrl, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
    SendMessage(hCtrl, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));

    ok(IsDlgButtonChecked(hwnd, rad1) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad2) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad3) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad5) == BST_CHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad6) == BST_UNCHECKED, "\n");
    ok(IsDlgButtonChecked(hwnd, rad7) == BST_UNCHECKED, "\n");
}

__attribute__((used)) static void
OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
        case IDC_TEST1:
            DoTest1(hwnd);
            PostMessage(hwnd, WM_COMMAND, MAKEWPARAM(IDC_TEST2, 0), 0);
            break;
        case IDC_TEST2:
            DoTest2(hwnd);
            PostMessage(hwnd, WM_COMMAND, MAKEWPARAM(IDC_TEST3, 0), 0);
            break;
        case IDC_TEST3:
            DoTest3(hwnd);
            PostMessage(hwnd, WM_COMMAND, MAKEWPARAM(IDC_END, 0), 0);
            break;
        case IDC_END:
            EndDialog(hwnd, IDOK);
            break;
    }
}

