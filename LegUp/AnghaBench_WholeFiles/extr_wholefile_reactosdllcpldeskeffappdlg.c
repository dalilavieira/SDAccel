#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ WPARAM ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_7__ {int bMenuAnimation; int bFontSmoothing; int bDropShadow; int bDragFullWindows; int bKeyboardCues; scalar_t__ uiFontSmoothingType; scalar_t__ bMenuFade; } ;
struct TYPE_8__ {int bFlatMenus; TYPE_1__ Effects; } ;
struct TYPE_9__ {TYPE_2__ SchemeAdv; TYPE_2__ Scheme; scalar_t__ bSchemeChanged; } ;
typedef  int /*<<< orphan*/  TCHAR ;
typedef  int /*<<< orphan*/  LPTSTR ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  scalar_t__ INT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  TYPE_3__ GLOBALS ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAYSIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BM_GETCHECK ; 
 int /*<<< orphan*/  BM_SETCHECK ; 
 scalar_t__ BST_CHECKED ; 
 scalar_t__ BST_UNCHECKED ; 
 int /*<<< orphan*/  CB_ADDSTRING ; 
 int /*<<< orphan*/  CB_SETCURSEL ; 
 int /*<<< orphan*/  EnableWindow (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ IDC_EFFAPPEARANCE_ANIMATION ; 
 scalar_t__ IDC_EFFAPPEARANCE_ANIMATIONTYPE ; 
 scalar_t__ IDC_EFFAPPEARANCE_DRAGFULLWINDOWS ; 
 scalar_t__ IDC_EFFAPPEARANCE_FLATMENUS ; 
 scalar_t__ IDC_EFFAPPEARANCE_KEYBOARDCUES ; 
 scalar_t__ IDC_EFFAPPEARANCE_SETDROPSHADOW ; 
 scalar_t__ IDC_EFFAPPEARANCE_SMOOTHING ; 
 scalar_t__ IDC_EFFAPPEARANCE_SMOOTHINGTYPE ; 
 scalar_t__ IDS_CLEARTYPEEFFECT ; 
 scalar_t__ IDS_FADEEFFECT ; 
 scalar_t__ IDS_SLIDEEFFECT ; 
 scalar_t__ IDS_STANDARDEFFECT ; 
 int /*<<< orphan*/  LoadString (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SendDlgItemMessage (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ SendDlgItemMessageW (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  hApplet ; 

__attribute__((used)) static VOID
EffAppearanceDlgUpdateControls(HWND hwndDlg, GLOBALS *g)
{
    WPARAM state;

#define SAVE_CHECKBOX(__CONTROL_ID, __MEMBER)                               \
do { \
    state = SendDlgItemMessageW(hwndDlg, __CONTROL_ID, BM_GETCHECK, 0, 0);  \
    g->SchemeAdv.Effects.__MEMBER = /* Do a XOR of both the conditions */   \
        ((state == BST_CHECKED) != (__CONTROL_ID == IDC_EFFAPPEARANCE_KEYBOARDCUES)); \
} while(0)

#define SAVE_CHECKBOX_SCH(__CONTROL_ID, __MEMBER)                           \
do { \
    state = SendDlgItemMessageW(hwndDlg, __CONTROL_ID, BM_GETCHECK, 0, 0);  \
    g->SchemeAdv.__MEMBER = (state == BST_CHECKED);                         \
} while(0)

#define RSET_COMBOBOX(__CONTROL_ID, __PARENT_MEMBER, __MEMBER)                                          \
do { \
    SendDlgItemMessageW(hwndDlg, __CONTROL_ID, CB_SETCURSEL, (WPARAM)g->SchemeAdv.Effects.__MEMBER, 0); \
    EnableWindow(GetDlgItem(hwndDlg, __CONTROL_ID), g->SchemeAdv.Effects.__PARENT_MEMBER);              \
} while(0)

    /* Animated menu transitions section (checkbox + combo) */
    SAVE_CHECKBOX(IDC_EFFAPPEARANCE_ANIMATION,       bMenuAnimation);
    RSET_COMBOBOX(IDC_EFFAPPEARANCE_ANIMATIONTYPE,   bMenuAnimation, bMenuFade);

    /* Font antialiasing section (checkbox + combo) */
    SAVE_CHECKBOX(IDC_EFFAPPEARANCE_SMOOTHING,       bFontSmoothing);
    RSET_COMBOBOX(IDC_EFFAPPEARANCE_SMOOTHINGTYPE,   bFontSmoothing, uiFontSmoothingType - 1);

    /* Other checkboxes */
    SAVE_CHECKBOX(IDC_EFFAPPEARANCE_SETDROPSHADOW,   bDropShadow);
    SAVE_CHECKBOX(IDC_EFFAPPEARANCE_DRAGFULLWINDOWS, bDragFullWindows);
    SAVE_CHECKBOX(IDC_EFFAPPEARANCE_KEYBOARDCUES,    bKeyboardCues);
    SAVE_CHECKBOX_SCH(IDC_EFFAPPEARANCE_FLATMENUS,   bFlatMenus);

#undef SAVE_CHECKBOX
#undef RSET_COMBOBOX

    g->bSchemeChanged = TRUE;
}

__attribute__((used)) static VOID
EffAppearanceDlgSaveCurrentValues(HWND hwndDlg, GLOBALS *g)
{
    /* The settings get saved at the end of ApplyScheme() in theme.c,
     * when clicking Apply in the main dialog. */
}

__attribute__((used)) static VOID
AddToCombobox(INT Combo, HWND hwndDlg, INT From, INT To)
{
    INT iElement;
    TCHAR tstrText[80];

    for (iElement = From; iElement <= To; iElement++)
    {
        LoadString(hApplet, iElement, (LPTSTR)tstrText, ARRAYSIZE(tstrText));
        SendDlgItemMessage(hwndDlg, Combo, CB_ADDSTRING, 0, (LPARAM)tstrText);
    }
}

__attribute__((used)) static VOID
EffAppearanceDlg_Init(HWND hwndDlg, GLOBALS *g)
{
    WPARAM state;

    /* Copy the current theme values */
    g->SchemeAdv = g->Scheme;

#define INIT_CHECKBOX(__CONTROL_ID, __MEMBER)                           \
do { \
    state = /* Do a XOR of both the conditions */                       \
        ((g->SchemeAdv.Effects.__MEMBER) != (__CONTROL_ID == IDC_EFFAPPEARANCE_KEYBOARDCUES)) \
            ? BST_CHECKED : BST_UNCHECKED;                              \
    SendDlgItemMessageW(hwndDlg, __CONTROL_ID, BM_SETCHECK, state, 0);  \
} while(0)

#define INIT_CHECKBOX_SCH(__CONTROL_ID, __MEMBER)                       \
do { \
    state = /* Do a XOR of both the conditions */                       \
        ((g->SchemeAdv.__MEMBER) == TRUE)                               \
            ? BST_CHECKED : BST_UNCHECKED;                              \
    SendDlgItemMessageW(hwndDlg, __CONTROL_ID, BM_SETCHECK, state, 0);  \
} while(0)

#define FILL_COMBOBOX(__CONTROL_ID, __FIRST_STR, __LAST_STR) \
    AddToCombobox(__CONTROL_ID, hwndDlg, __FIRST_STR, __LAST_STR)

    /* Animated menu transitions section (checkbox + combo) */
    INIT_CHECKBOX(IDC_EFFAPPEARANCE_ANIMATION,       bMenuAnimation);
    FILL_COMBOBOX(IDC_EFFAPPEARANCE_ANIMATIONTYPE,   IDS_SLIDEEFFECT,
                                                     IDS_FADEEFFECT);

    /* Font antialiasing section (checkbox + combo) */
    INIT_CHECKBOX(IDC_EFFAPPEARANCE_SMOOTHING,       bFontSmoothing);
    FILL_COMBOBOX(IDC_EFFAPPEARANCE_SMOOTHINGTYPE,   IDS_STANDARDEFFECT,
                                                     IDS_CLEARTYPEEFFECT);

    /* Other checkboxes */
    INIT_CHECKBOX(IDC_EFFAPPEARANCE_SETDROPSHADOW,   bDropShadow);
    INIT_CHECKBOX(IDC_EFFAPPEARANCE_DRAGFULLWINDOWS, bDragFullWindows);
    INIT_CHECKBOX(IDC_EFFAPPEARANCE_KEYBOARDCUES,    bKeyboardCues);
    INIT_CHECKBOX_SCH(IDC_EFFAPPEARANCE_FLATMENUS,   bFlatMenus);

#undef INIT_CHECKBOX
#undef FILL_COMBOBOX

    /* Update the controls */
    EffAppearanceDlgUpdateControls(hwndDlg, g);
}

