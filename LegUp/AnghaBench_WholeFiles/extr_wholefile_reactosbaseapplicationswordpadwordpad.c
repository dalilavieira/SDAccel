#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_9__ ;
typedef  struct TYPE_28__   TYPE_8__ ;
typedef  struct TYPE_27__   TYPE_6__ ;
typedef  struct TYPE_26__   TYPE_5__ ;
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;
typedef  struct TYPE_21__   TYPE_12__ ;
typedef  struct TYPE_20__   TYPE_11__ ;
typedef  struct TYPE_19__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  pf ;
typedef  int /*<<< orphan*/  params ;
typedef  int /*<<< orphan*/  mi ;
typedef  int /*<<< orphan*/  fmt ;
typedef  int /*<<< orphan*/  cf ;
typedef  int /*<<< orphan*/  button ;
typedef  int WPARAM ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_29__ {int cbSize; scalar_t__ dwLanguageId; int /*<<< orphan*/ * lpfnMsgBoxCallback; scalar_t__ dwContextHelpId; int /*<<< orphan*/ * lpszIcon; int /*<<< orphan*/  dwStyle; void* lpszCaption; void* lpszText; int /*<<< orphan*/  hInstance; scalar_t__ hwndOwner; } ;
struct TYPE_28__ {int cbSize; int dwMask; scalar_t__ wNumbering; int dxOffset; int wAlignment; } ;
struct TYPE_27__ {int y; int /*<<< orphan*/  x; } ;
struct TYPE_26__ {int bottom; int top; int right; int /*<<< orphan*/  left; } ;
struct TYPE_25__ {int codepage; int /*<<< orphan*/  flags; } ;
struct TYPE_24__ {int iBitmap; int idCommand; int iString; int cbSize; int dwMask; int dwEffects; int wAlignment; int /*<<< orphan*/  crTextColor; scalar_t__ dwData; int /*<<< orphan*/  fsStyle; scalar_t__ fsState; } ;
struct TYPE_22__ {int cpMax; int /*<<< orphan*/  cpMin; } ;
struct TYPE_23__ {char* lpstrText; TYPE_1__ chrg; } ;
struct TYPE_21__ {int member_1; int cpMax; int cpMin; int /*<<< orphan*/  member_0; } ;
struct TYPE_20__ {int codepage; int /*<<< orphan*/  flags; } ;
struct TYPE_19__ {int cbSize; scalar_t__ dwItemData; void* fMask; } ;
typedef  TYPE_2__ TEXTRANGEW ;
typedef  TYPE_3__ TBBUTTON ;
typedef  TYPE_4__ SETTEXTEX ;
typedef  TYPE_5__ RECT ;
typedef  TYPE_6__ POINT ;
typedef  TYPE_3__ PARAFORMAT2 ;
typedef  TYPE_8__ PARAFORMAT ;
typedef  TYPE_9__ MSGBOXPARAMSW ;
typedef  TYPE_10__ MENUITEMINFOW ;
typedef  int LRESULT ;
typedef  char* LPWSTR ;
typedef  void* LPCWSTR ;
typedef  int LPARAM ;
typedef  int LONG ;
typedef  scalar_t__ HWND ;
typedef  int /*<<< orphan*/  HMENU ;
typedef  int /*<<< orphan*/  HINSTANCE ;
typedef  TYPE_11__ GETTEXTLENGTHEX ;
typedef  int /*<<< orphan*/  FINDREPLACEW ;
typedef  int DWORD ;
typedef  TYPE_12__ CHARRANGE ;
typedef  TYPE_3__ CHARFORMAT2W ;

/* Variables and functions */
 int BANDID_FONTLIST ; 
 int BANDID_FORMATBAR ; 
 int BANDID_RULER ; 
 int BANDID_SIZELIST ; 
 int BANDID_STATUSBAR ; 
 int BANDID_TOOLBAR ; 
 int /*<<< orphan*/  BTNS_BUTTON ; 
 int /*<<< orphan*/  BTNS_SEP ; 
 int /*<<< orphan*/  CBN_SELENDOK ; 
 int CFE_AUTOCOLOR ; 
 int CFE_BOLD ; 
 int CFE_ITALIC ; 
 int CFE_UNDERLINE ; 
 int CFM_BOLD ; 
 int CFM_COLOR ; 
 int CFM_ITALIC ; 
 int CFM_UNDERLINE ; 
 int /*<<< orphan*/  CheckMenuItem (int /*<<< orphan*/ ,int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ClientToScreen (scalar_t__,TYPE_6__*) ; 
 int DefWindowProcW (scalar_t__,int /*<<< orphan*/ ,int,int) ; 
 int DialogBoxW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DialogOpenFile () ; 
 int /*<<< orphan*/  DialogSaveFile () ; 
 int /*<<< orphan*/  DoOpenFile (char*) ; 
 int /*<<< orphan*/  DoSaveFile (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EM_CANREDO ; 
 int /*<<< orphan*/  EM_CANUNDO ; 
 int /*<<< orphan*/  EM_EXGETSEL ; 
 int /*<<< orphan*/  EM_EXSETSEL ; 
 int /*<<< orphan*/  EM_GETCHARFORMAT ; 
 int /*<<< orphan*/  EM_GETMODIFY ; 
 int /*<<< orphan*/  EM_GETPARAFORMAT ; 
 int /*<<< orphan*/  EM_GETSEL ; 
 int /*<<< orphan*/  EM_GETSELTEXT ; 
 int /*<<< orphan*/  EM_GETTEXTLENGTHEX ; 
 int /*<<< orphan*/  EM_GETTEXTRANGE ; 
 int /*<<< orphan*/  EM_REDO ; 
 int /*<<< orphan*/  EM_SETBKGNDCOLOR ; 
 int /*<<< orphan*/  EM_SETCHARFORMAT ; 
 int /*<<< orphan*/  EM_SETMODIFY ; 
 int /*<<< orphan*/  EM_SETPARAFORMAT ; 
 int /*<<< orphan*/  EM_SETREADONLY ; 
 int /*<<< orphan*/  EM_SETTEXTEX ; 
 int /*<<< orphan*/  EM_UNDO ; 
 int ES_READONLY ; 
 int /*<<< orphan*/  EnableMenuItem (int /*<<< orphan*/ ,int const,int /*<<< orphan*/ ) ; 
 int FALSE ; 
 int /*<<< orphan*/  GTL_NUMCHARS ; 
 int /*<<< orphan*/  GWL_STYLE ; 
 int /*<<< orphan*/  GetClientRect (scalar_t__,TYPE_5__*) ; 
 scalar_t__ GetDlgItem (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetMenu (scalar_t__) ; 
 int /*<<< orphan*/  GetMenuItemInfoW (int /*<<< orphan*/ ,int const,int,TYPE_10__*) ; 
 int /*<<< orphan*/  GetModuleHandleW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  GetSubMenu (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int GetWindowLongW (scalar_t__,int /*<<< orphan*/ ) ; 
 int GetWindowTextLengthW (scalar_t__) ; 
 int /*<<< orphan*/  GetWindowTextW (scalar_t__,char*,int) ; 
 int /*<<< orphan*/  HIWORD (int) ; 
 char* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  IDC_EDITOR ; 
#define  IDC_FONTLIST 179 
 int /*<<< orphan*/  IDC_FORMATBAR ; 
 int /*<<< orphan*/  IDC_PREVIEW ; 
 int /*<<< orphan*/  IDC_REBAR ; 
 int /*<<< orphan*/  IDC_RULER ; 
#define  IDC_SIZELIST 178 
 int /*<<< orphan*/  IDC_STATUSBAR ; 
 int /*<<< orphan*/  IDD_DATETIME ; 
 int /*<<< orphan*/  IDD_NEWFILE ; 
 int /*<<< orphan*/  IDD_PARAFORMAT ; 
 int /*<<< orphan*/  IDD_TABSTOPS ; 
#define  ID_ABOUT 177 
#define  ID_ALIGN_CENTER 176 
#define  ID_ALIGN_LEFT 175 
#define  ID_ALIGN_RIGHT 174 
#define  ID_BACK_1 173 
#define  ID_BACK_2 172 
#define  ID_BULLET 171 
 int ID_COLOR_AUTOMATIC ; 
 int ID_COLOR_FIRST ; 
#define  ID_DATETIME 170 
#define  ID_EDIT_CHARFORMAT 169 
#define  ID_EDIT_CLEAR 168 
#define  ID_EDIT_COPY 167 
#define  ID_EDIT_CUT 166 
#define  ID_EDIT_DEFCHARFORMAT 165 
#define  ID_EDIT_GETTEXT 164 
#define  ID_EDIT_MODIFIED 163 
#define  ID_EDIT_PARAFORMAT 162 
#define  ID_EDIT_PASTE 161 
#define  ID_EDIT_READONLY 160 
#define  ID_EDIT_REDO 159 
#define  ID_EDIT_SELECTALL 158 
#define  ID_EDIT_SELECTIONINFO 157 
#define  ID_EDIT_UNDO 156 
#define  ID_FILE_EXIT 155 
#define  ID_FILE_NEW 154 
#define  ID_FILE_OPEN 153 
#define  ID_FILE_RECENT1 152 
#define  ID_FILE_RECENT2 151 
#define  ID_FILE_RECENT3 150 
#define  ID_FILE_RECENT4 149 
#define  ID_FILE_SAVE 148 
#define  ID_FILE_SAVEAS 147 
#define  ID_FIND 146 
#define  ID_FIND_NEXT 145 
#define  ID_FONTSETTINGS 144 
#define  ID_FORMAT_BOLD 143 
#define  ID_FORMAT_COLOR 142 
#define  ID_FORMAT_ITALIC 141 
#define  ID_FORMAT_UNDERLINE 140 
 int ID_NEWFILE_ABORT ; 
#define  ID_PARAFORMAT 139 
#define  ID_PREVIEW 138 
#define  ID_PRINT 137 
#define  ID_PRINTSETUP 136 
#define  ID_PRINT_QUICK 135 
#define  ID_REPLACE 134 
#define  ID_TABSTOPS 133 
#define  ID_TOGGLE_FORMATBAR 132 
#define  ID_TOGGLE_RULER 131 
#define  ID_TOGGLE_STATUSBAR 130 
#define  ID_TOGGLE_TOOLBAR 129 
#define  ID_VIEWPROPERTIES 128 
 int /*<<< orphan*/  InvalidateRect (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ IsWindowVisible (scalar_t__) ; 
 int LF_FACESIZE ; 
 int LOWORD (int) ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAKEINTRESOURCEW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX_STRING_LEN ; 
 int /*<<< orphan*/  MB_OK ; 
 int /*<<< orphan*/  MF_CHECKED ; 
 int /*<<< orphan*/  MF_ENABLED ; 
 int /*<<< orphan*/  MF_GRAYED ; 
 int /*<<< orphan*/  MF_UNCHECKED ; 
 void* MIIM_DATA ; 
 int /*<<< orphan*/  MessageBoxA (scalar_t__,char*,char*,int /*<<< orphan*/ ) ; 
 int MessageBoxIndirectW (TYPE_9__*) ; 
 int /*<<< orphan*/  MessageBoxW (scalar_t__,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MoveWindow (scalar_t__,int /*<<< orphan*/ ,int,int,int,int) ; 
 int PFA_CENTER ; 
 int PFA_LEFT ; 
 int PFA_RIGHT ; 
 int PFM_ALIGNMENT ; 
 int PFM_NUMBERING ; 
 int PFM_OFFSET ; 
 scalar_t__ PFN_BULLET ; 
 int /*<<< orphan*/  PostMessageW (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RB_GETBARHEIGHT ; 
 int RGB (int,int,int) ; 
 int SCF_SELECTION ; 
 int /*<<< orphan*/  STRING_ALL_FILES ; 
 int /*<<< orphan*/  STRING_DEFAULT_FILENAME ; 
 int /*<<< orphan*/  STRING_PROMPT_SAVE_CHANGES ; 
 int /*<<< orphan*/  STRING_RICHTEXT_FILES_RTF ; 
 int /*<<< orphan*/  STRING_TEXT_FILES_TXT ; 
 int /*<<< orphan*/  STRING_TEXT_FILES_UNICODE_TXT ; 
 int /*<<< orphan*/  STRING_UNITS_CM ; 
 int /*<<< orphan*/  STRING_UNITS_IN ; 
 int /*<<< orphan*/  STRING_UNITS_INCH ; 
 int /*<<< orphan*/  STRING_UNITS_PT ; 
 int /*<<< orphan*/  ST_DEFAULT ; 
 int SendMessageW (scalar_t__,int /*<<< orphan*/ ,int const,int) ; 
 int /*<<< orphan*/  SetMenu (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ShowWindow (scalar_t__,int) ; 
 scalar_t__ TBSTATE_ENABLED ; 
 int /*<<< orphan*/  TB_ADDBUTTONSW ; 
 int /*<<< orphan*/  TB_COMMANDTOINDEX ; 
 int /*<<< orphan*/  TB_GETITEMRECT ; 
 int TPM_LEFTALIGN ; 
 int TPM_LEFTBUTTON ; 
 int TPM_NONOTIFY ; 
 int TPM_RETURNCMD ; 
 int TPM_TOPALIGN ; 
 int TRUE ; 
 int TrackPopupMenu (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WM_CLEAR ; 
 int /*<<< orphan*/  WM_CLOSE ; 
 int /*<<< orphan*/  WM_COMMAND ; 
 int /*<<< orphan*/  WM_COPY ; 
 int /*<<< orphan*/  WM_CUT ; 
 int /*<<< orphan*/  WM_PASTE ; 
 int /*<<< orphan*/  WM_SIZE ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_3__*,int) ; 
 int* barState ; 
 int /*<<< orphan*/  clear_formatting () ; 
 int /*<<< orphan*/  datetime_proc ; 
 int /*<<< orphan*/  dialog_about () ; 
 int /*<<< orphan*/  dialog_choose_font () ; 
 int /*<<< orphan*/  dialog_find (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dialog_print (scalar_t__,char*) ; 
 int /*<<< orphan*/  dialog_printsetup (scalar_t__) ; 
 int /*<<< orphan*/  dialog_viewproperties () ; 
 int /*<<< orphan*/  fileFormat ; 
 int /*<<< orphan*/  get_comboexlist_selection (scalar_t__,char*,int) ; 
 int /*<<< orphan*/  hColorPopupMenu ; 
 scalar_t__ hEditorWnd ; 
 int /*<<< orphan*/  hMainWnd ; 
 int /*<<< orphan*/  handle_findmsg (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_preview (scalar_t__,char*) ; 
 scalar_t__ is_bar_visible (int) ; 
 int /*<<< orphan*/  lstrcpyW (char*,char const*) ; 
 scalar_t__ lstrlenW (char*) ; 
 int /*<<< orphan*/  newfile_proc ; 
 int /*<<< orphan*/  on_fontlist_modified (char*) ; 
 int /*<<< orphan*/  on_sizelist_modified (scalar_t__,char*) ; 
 int /*<<< orphan*/  paraformat_proc ; 
 scalar_t__ preview_isactive () ; 
 int /*<<< orphan*/  print_quick (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  prompt_save_changes () ; 
 int /*<<< orphan*/  redraw_ruler (scalar_t__) ; 
 size_t reg_formatindex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bar_states () ; 
 int /*<<< orphan*/  set_caption (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_fileformat (int) ; 
 int /*<<< orphan*/  set_statusbar_state (int) ; 
 int /*<<< orphan*/  set_toolbar_state (int,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int) ; 
 int /*<<< orphan*/  tabstops_proc ; 
 int /*<<< orphan*/  target_device (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * textcolors ; 
 char* units_cmW ; 
 char* units_inW ; 
 char* units_inchW ; 
 char* units_ptW ; 
 int /*<<< orphan*/  update_font_list () ; 
 int /*<<< orphan*/  update_window () ; 
 int /*<<< orphan*/ * wordWrap ; 
 int /*<<< orphan*/  wszAppTitle ; 
 char* wszDefaultFileName ; 
 char* wszFileName ; 
 char* wszFilter ; 
 char* wszSaveChanges ; 

__attribute__((used)) static void DoLoadStrings(void)
{
    LPWSTR p = wszFilter;
    static const WCHAR files_rtf[] = {'*','.','r','t','f','\0'};
    static const WCHAR files_txt[] = {'*','.','t','x','t','\0'};
    static const WCHAR files_all[] = {'*','.','*','\0'};

    HINSTANCE hInstance = GetModuleHandleW(0);

    LoadStringW(hInstance, STRING_RICHTEXT_FILES_RTF, p, MAX_STRING_LEN);
    p += lstrlenW(p) + 1;
    lstrcpyW(p, files_rtf);
    p += lstrlenW(p) + 1;
    LoadStringW(hInstance, STRING_TEXT_FILES_TXT, p, MAX_STRING_LEN);
    p += lstrlenW(p) + 1;
    lstrcpyW(p, files_txt);
    p += lstrlenW(p) + 1;
    LoadStringW(hInstance, STRING_TEXT_FILES_UNICODE_TXT, p, MAX_STRING_LEN);
    p += lstrlenW(p) + 1;
    lstrcpyW(p, files_txt);
    p += lstrlenW(p) + 1;
    LoadStringW(hInstance, STRING_ALL_FILES, p, MAX_STRING_LEN);
    p += lstrlenW(p) + 1;
    lstrcpyW(p, files_all);
    p += lstrlenW(p) + 1;
    *p = '\0';

    p = wszDefaultFileName;
    LoadStringW(hInstance, STRING_DEFAULT_FILENAME, p, MAX_STRING_LEN);

    p = wszSaveChanges;
    LoadStringW(hInstance, STRING_PROMPT_SAVE_CHANGES, p, MAX_STRING_LEN);

    LoadStringW(hInstance, STRING_UNITS_CM, units_cmW, MAX_STRING_LEN);
    LoadStringW(hInstance, STRING_UNITS_IN, units_inW, MAX_STRING_LEN);
    LoadStringW(hInstance, STRING_UNITS_INCH, units_inchW, MAX_STRING_LEN);
    LoadStringW(hInstance, STRING_UNITS_PT, units_ptW, MAX_STRING_LEN);
}

__attribute__((used)) static int MessageBoxWithResStringW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    MSGBOXPARAMSW params;

    params.cbSize             = sizeof(params);
    params.hwndOwner          = hWnd;
    params.hInstance          = GetModuleHandleW(0);
    params.lpszText           = lpText;
    params.lpszCaption        = lpCaption;
    params.dwStyle            = uType;
    params.lpszIcon           = NULL;
    params.dwContextHelpId    = 0;
    params.lpfnMsgBoxCallback = NULL;
    params.dwLanguageId       = 0;
    return MessageBoxIndirectW(&params);
}

__attribute__((used)) static void AddButton(HWND hwndToolBar, int nImage, int nCommand)
{
    TBBUTTON button;

    ZeroMemory(&button, sizeof(button));
    button.iBitmap = nImage;
    button.idCommand = nCommand;
    button.fsState = TBSTATE_ENABLED;
    button.fsStyle = BTNS_BUTTON;
    button.dwData = 0;
    button.iString = -1;
    SendMessageW(hwndToolBar, TB_ADDBUTTONSW, 1, (LPARAM)&button);
}

__attribute__((used)) static void AddSeparator(HWND hwndToolBar)
{
    TBBUTTON button;

    ZeroMemory(&button, sizeof(button));
    button.iBitmap = -1;
    button.idCommand = 0;
    button.fsState = 0;
    button.fsStyle = BTNS_SEP;
    button.dwData = 0;
    button.iString = -1;
    SendMessageW(hwndToolBar, TB_ADDBUTTONSW, 1, (LPARAM)&button);
}

__attribute__((used)) static LRESULT OnCommand( HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    HWND hwndEditor = GetDlgItem(hWnd, IDC_EDITOR);
    static FINDREPLACEW findreplace;

    if ((HWND)lParam == hwndEditor)
        return 0;

    switch(LOWORD(wParam))
    {

    case ID_FILE_EXIT:
        PostMessageW(hWnd, WM_CLOSE, 0, 0);
        break;

    case ID_FILE_NEW:
        {
            HINSTANCE hInstance = GetModuleHandleW(0);
            int ret = DialogBoxW(hInstance, MAKEINTRESOURCEW(IDD_NEWFILE), hWnd, newfile_proc);

            if(ret != ID_NEWFILE_ABORT)
            {
                if(prompt_save_changes())
                {
                    SETTEXTEX st;

                    set_caption(NULL);
                    wszFileName[0] = '\0';

                    clear_formatting();

                    st.flags = ST_DEFAULT;
                    st.codepage = 1200;
                    SendMessageW(hEditorWnd, EM_SETTEXTEX, (WPARAM)&st, 0);

                    SendMessageW(hEditorWnd, EM_SETMODIFY, FALSE, 0);
                    set_fileformat(ret);
                    update_font_list();
                }
            }
        }
        break;

    case ID_FILE_OPEN:
        DialogOpenFile();
        break;

    case ID_FILE_SAVE:
        if(wszFileName[0])
        {
            DoSaveFile(wszFileName, fileFormat);
            break;
        }
        /* Fall through */

    case ID_FILE_SAVEAS:
        DialogSaveFile();
        break;

    case ID_FILE_RECENT1:
    case ID_FILE_RECENT2:
    case ID_FILE_RECENT3:
    case ID_FILE_RECENT4:
        {
            HMENU hMenu = GetMenu(hWnd);
            MENUITEMINFOW mi;

            mi.cbSize = sizeof(MENUITEMINFOW);
            mi.fMask = MIIM_DATA;
            if(GetMenuItemInfoW(hMenu, LOWORD(wParam), FALSE, &mi))
                DoOpenFile((LPWSTR)mi.dwItemData);
        }
        break;

    case ID_FIND:
        dialog_find(&findreplace, FALSE);
        break;

    case ID_FIND_NEXT:
        handle_findmsg(&findreplace);
        break;

    case ID_REPLACE:
        dialog_find(&findreplace, TRUE);
        break;

    case ID_FONTSETTINGS:
        dialog_choose_font();
        break;

    case ID_PRINT:
        dialog_print(hWnd, wszFileName);
        target_device(hMainWnd, wordWrap[reg_formatindex(fileFormat)]);
        break;

    case ID_PRINT_QUICK:
        print_quick(hMainWnd, wszFileName);
        target_device(hMainWnd, wordWrap[reg_formatindex(fileFormat)]);
        break;

    case ID_PREVIEW:
        {
            int index = reg_formatindex(fileFormat);
            DWORD tmp = barState[index];
            barState[index] = 1 << BANDID_STATUSBAR;
            set_bar_states();
            barState[index] = tmp;
            ShowWindow(hEditorWnd, FALSE);

            init_preview(hWnd, wszFileName);

            SetMenu(hWnd, NULL);
            InvalidateRect(0, 0, TRUE);
        }
        break;

    case ID_PRINTSETUP:
        dialog_printsetup(hWnd);
        target_device(hMainWnd, wordWrap[reg_formatindex(fileFormat)]);
        break;

    case ID_FORMAT_BOLD:
    case ID_FORMAT_ITALIC:
    case ID_FORMAT_UNDERLINE:
        {
        CHARFORMAT2W fmt;
        int effects = CFE_BOLD;

        ZeroMemory(&fmt, sizeof(fmt));
        fmt.cbSize = sizeof(fmt);
        SendMessageW(hwndEditor, EM_GETCHARFORMAT, SCF_SELECTION, (LPARAM)&fmt);

        fmt.dwMask = CFM_BOLD;

        if (LOWORD(wParam) == ID_FORMAT_ITALIC)
        {
            effects = CFE_ITALIC;
            fmt.dwMask = CFM_ITALIC;
        } else if (LOWORD(wParam) == ID_FORMAT_UNDERLINE)
        {
            effects = CFE_UNDERLINE;
            fmt.dwMask = CFM_UNDERLINE;
        }

        fmt.dwEffects ^= effects;

        SendMessageW(hwndEditor, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&fmt);
        break;
        }

    case ID_FORMAT_COLOR:
    {
        HWND hReBarWnd = GetDlgItem(hWnd, IDC_REBAR);
        HWND hFormatBarWnd = GetDlgItem(hReBarWnd, IDC_FORMATBAR);
        HMENU hPop;
        RECT itemrc;
        POINT pt;
        int mid;
        int itemidx = SendMessageW(hFormatBarWnd, TB_COMMANDTOINDEX, ID_FORMAT_COLOR, 0);

        SendMessageW(hFormatBarWnd, TB_GETITEMRECT, itemidx, (LPARAM)&itemrc);
        pt.x = itemrc.left;
        pt.y = itemrc.bottom;
        ClientToScreen(hFormatBarWnd, &pt);
        hPop = GetSubMenu(hColorPopupMenu, 0);
        mid = TrackPopupMenu(hPop, TPM_LEFTALIGN | TPM_TOPALIGN | TPM_LEFTBUTTON |
                                   TPM_RETURNCMD | TPM_NONOTIFY,
                             pt.x, pt.y, 0, hWnd, 0);
        if (mid >= ID_COLOR_FIRST && mid <= ID_COLOR_AUTOMATIC)
        {
            CHARFORMAT2W fmt;

            ZeroMemory(&fmt, sizeof(fmt));
            fmt.cbSize = sizeof(fmt);
            SendMessageW(hwndEditor, EM_GETCHARFORMAT, SCF_SELECTION, (LPARAM)&fmt);

            fmt.dwMask = CFM_COLOR;

            if (mid < ID_COLOR_AUTOMATIC) {
                fmt.crTextColor = textcolors[mid - ID_COLOR_FIRST];
                fmt.dwEffects &= ~CFE_AUTOCOLOR;
            } else {
                fmt.dwEffects |= CFE_AUTOCOLOR;
            }

            SendMessageW(hwndEditor, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&fmt);
        }
        break;
    }

    case ID_EDIT_CUT:
        PostMessageW(hwndEditor, WM_CUT, 0, 0);
        break;

    case ID_EDIT_COPY:
        PostMessageW(hwndEditor, WM_COPY, 0, 0);
        break;

    case ID_EDIT_PASTE:
        PostMessageW(hwndEditor, WM_PASTE, 0, 0);
        break;

    case ID_EDIT_CLEAR:
        PostMessageW(hwndEditor, WM_CLEAR, 0, 0);
        break;

    case ID_EDIT_SELECTALL:
        {
        CHARRANGE range = {0, -1};
        SendMessageW(hwndEditor, EM_EXSETSEL, 0, (LPARAM)&range);
        /* SendMessage(hwndEditor, EM_SETSEL, 0, -1); */
        return 0;
        }

    case ID_EDIT_GETTEXT:
        {
        int nLen = GetWindowTextLengthW(hwndEditor);
        LPWSTR data = HeapAlloc( GetProcessHeap(), 0, (nLen+1)*sizeof(WCHAR) );
        TEXTRANGEW tr;

        GetWindowTextW(hwndEditor, data, nLen+1);
        MessageBoxW(NULL, data, wszAppTitle, MB_OK);

        HeapFree( GetProcessHeap(), 0, data);
        data = HeapAlloc(GetProcessHeap(), 0, (nLen+1)*sizeof(WCHAR));
        tr.chrg.cpMin = 0;
        tr.chrg.cpMax = nLen;
        tr.lpstrText = data;
        SendMessageW(hwndEditor, EM_GETTEXTRANGE, 0, (LPARAM)&tr);
        MessageBoxW(NULL, data, wszAppTitle, MB_OK);
        HeapFree( GetProcessHeap(), 0, data );

        /* SendMessage(hwndEditor, EM_SETSEL, 0, -1); */
        return 0;
        }

    case ID_EDIT_CHARFORMAT:
    case ID_EDIT_DEFCHARFORMAT:
        {
        CHARFORMAT2W cf;

        ZeroMemory(&cf, sizeof(cf));
        cf.cbSize = sizeof(cf);
        cf.dwMask = 0;
        SendMessageW(hwndEditor, EM_GETCHARFORMAT,
                     LOWORD(wParam) == ID_EDIT_CHARFORMAT, (LPARAM)&cf);
        return 0;
        }

    case ID_EDIT_PARAFORMAT:
        {
        PARAFORMAT2 pf;
        ZeroMemory(&pf, sizeof(pf));
        pf.cbSize = sizeof(pf);
        SendMessageW(hwndEditor, EM_GETPARAFORMAT, 0, (LPARAM)&pf);
        return 0;
        }

    case ID_EDIT_SELECTIONINFO:
        {
        CHARRANGE range = {0, -1};
        char buf[128];
        WCHAR *data = NULL;

        SendMessageW(hwndEditor, EM_EXGETSEL, 0, (LPARAM)&range);
        data = HeapAlloc(GetProcessHeap(), 0, sizeof(*data) * (range.cpMax-range.cpMin+1));
        SendMessageW(hwndEditor, EM_GETSELTEXT, 0, (LPARAM)data);
        sprintf(buf, "Start = %d, End = %d", range.cpMin, range.cpMax);
        MessageBoxA(hWnd, buf, "Editor", MB_OK);
        MessageBoxW(hWnd, data, wszAppTitle, MB_OK);
        HeapFree( GetProcessHeap(), 0, data);
        /* SendMessage(hwndEditor, EM_SETSEL, 0, -1); */
        return 0;
        }

    case ID_EDIT_READONLY:
        {
        LONG nStyle = GetWindowLongW(hwndEditor, GWL_STYLE);
        if (nStyle & ES_READONLY)
            SendMessageW(hwndEditor, EM_SETREADONLY, 0, 0);
        else
            SendMessageW(hwndEditor, EM_SETREADONLY, 1, 0);
        return 0;
        }

    case ID_EDIT_MODIFIED:
        if (SendMessageW(hwndEditor, EM_GETMODIFY, 0, 0))
            SendMessageW(hwndEditor, EM_SETMODIFY, 0, 0);
        else
            SendMessageW(hwndEditor, EM_SETMODIFY, 1, 0);
        return 0;

    case ID_EDIT_UNDO:
        SendMessageW(hwndEditor, EM_UNDO, 0, 0);
        return 0;

    case ID_EDIT_REDO:
        SendMessageW(hwndEditor, EM_REDO, 0, 0);
        return 0;

    case ID_BULLET:
        {
            PARAFORMAT pf;

            pf.cbSize = sizeof(pf);
            pf.dwMask = PFM_NUMBERING;
            SendMessageW(hwndEditor, EM_GETPARAFORMAT, 0, (LPARAM)&pf);

            pf.dwMask |=  PFM_OFFSET;

            if(pf.wNumbering == PFN_BULLET)
            {
                pf.wNumbering = 0;
                pf.dxOffset = 0;
            } else
            {
                pf.wNumbering = PFN_BULLET;
                pf.dxOffset = 720;
            }

            SendMessageW(hwndEditor, EM_SETPARAFORMAT, 0, (LPARAM)&pf);
        }
        break;

    case ID_ALIGN_LEFT:
    case ID_ALIGN_CENTER:
    case ID_ALIGN_RIGHT:
        {
        PARAFORMAT2 pf;

        pf.cbSize = sizeof(pf);
        pf.dwMask = PFM_ALIGNMENT;
        switch(LOWORD(wParam)) {
        case ID_ALIGN_LEFT: pf.wAlignment = PFA_LEFT; break;
        case ID_ALIGN_CENTER: pf.wAlignment = PFA_CENTER; break;
        case ID_ALIGN_RIGHT: pf.wAlignment = PFA_RIGHT; break;
        }
        SendMessageW(hwndEditor, EM_SETPARAFORMAT, 0, (LPARAM)&pf);
        break;
        }

    case ID_BACK_1:
        SendMessageW(hwndEditor, EM_SETBKGNDCOLOR, 1, 0);
        break;

    case ID_BACK_2:
        SendMessageW(hwndEditor, EM_SETBKGNDCOLOR, 0, RGB(255,255,192));
        break;

    case ID_TOGGLE_TOOLBAR:
        set_toolbar_state(BANDID_TOOLBAR, !is_bar_visible(BANDID_TOOLBAR));
        update_window();
        break;

    case ID_TOGGLE_FORMATBAR:
        set_toolbar_state(BANDID_FONTLIST, !is_bar_visible(BANDID_FORMATBAR));
        set_toolbar_state(BANDID_SIZELIST, !is_bar_visible(BANDID_FORMATBAR));
        set_toolbar_state(BANDID_FORMATBAR, !is_bar_visible(BANDID_FORMATBAR));
        update_window();
        break;

    case ID_TOGGLE_STATUSBAR:
        set_statusbar_state(!is_bar_visible(BANDID_STATUSBAR));
        update_window();
        break;

    case ID_TOGGLE_RULER:
        set_toolbar_state(BANDID_RULER, !is_bar_visible(BANDID_RULER));
        update_window();
        break;

    case ID_DATETIME:
        DialogBoxW(GetModuleHandleW(0), MAKEINTRESOURCEW(IDD_DATETIME), hWnd, datetime_proc);
        break;

    case ID_PARAFORMAT:
        DialogBoxW(GetModuleHandleW(0), MAKEINTRESOURCEW(IDD_PARAFORMAT), hWnd, paraformat_proc);
        break;

    case ID_TABSTOPS:
        DialogBoxW(GetModuleHandleW(0), MAKEINTRESOURCEW(IDD_TABSTOPS), hWnd, tabstops_proc);
        break;

    case ID_ABOUT:
        dialog_about();
        break;

    case ID_VIEWPROPERTIES:
        dialog_viewproperties();
        break;

    case IDC_FONTLIST:
        if (HIWORD(wParam) == CBN_SELENDOK)
        {
            WCHAR buffer[LF_FACESIZE];
            HWND hwndFontList = (HWND)lParam;
            get_comboexlist_selection(hwndFontList, buffer, LF_FACESIZE);
            on_fontlist_modified(buffer);
        }
        break;

    case IDC_SIZELIST:
        if (HIWORD(wParam) == CBN_SELENDOK)
        {
            WCHAR buffer[MAX_STRING_LEN+1];
            HWND hwndSizeList = (HWND)lParam;
            get_comboexlist_selection(hwndSizeList, buffer, MAX_STRING_LEN+1);
            on_sizelist_modified(hwndSizeList, buffer);
        }
        break;

    default:
        SendMessageW(hwndEditor, WM_COMMAND, wParam, lParam);
        break;
    }
    return 0;
}

__attribute__((used)) static LRESULT OnInitPopupMenu( HWND hWnd, WPARAM wParam )
{
    HMENU hMenu = (HMENU)wParam;
    HWND hwndEditor = GetDlgItem(hWnd, IDC_EDITOR);
    HWND hwndStatus = GetDlgItem(hWnd, IDC_STATUSBAR);
    PARAFORMAT pf;
    int nAlignment = -1;
    int selFrom, selTo;
    GETTEXTLENGTHEX gt;
    LRESULT textLength;
    MENUITEMINFOW mi;

    SendMessageW(hEditorWnd, EM_GETSEL, (WPARAM)&selFrom, (LPARAM)&selTo);
    EnableMenuItem(hMenu, ID_EDIT_COPY, (selFrom == selTo) ? MF_GRAYED : MF_ENABLED);
    EnableMenuItem(hMenu, ID_EDIT_CUT, (selFrom == selTo) ? MF_GRAYED : MF_ENABLED);

    pf.cbSize = sizeof(PARAFORMAT);
    SendMessageW(hwndEditor, EM_GETPARAFORMAT, 0, (LPARAM)&pf);
    CheckMenuItem(hMenu, ID_EDIT_READONLY,
      (GetWindowLongW(hwndEditor, GWL_STYLE) & ES_READONLY) ? MF_CHECKED : MF_UNCHECKED);
    CheckMenuItem(hMenu, ID_EDIT_MODIFIED,
      SendMessageW(hwndEditor, EM_GETMODIFY, 0, 0) ? MF_CHECKED : MF_UNCHECKED);
    if (pf.dwMask & PFM_ALIGNMENT)
        nAlignment = pf.wAlignment;
    CheckMenuItem(hMenu, ID_ALIGN_LEFT, (nAlignment == PFA_LEFT) ?  MF_CHECKED : MF_UNCHECKED);
    CheckMenuItem(hMenu, ID_ALIGN_CENTER, (nAlignment == PFA_CENTER) ?  MF_CHECKED : MF_UNCHECKED);
    CheckMenuItem(hMenu, ID_ALIGN_RIGHT, (nAlignment == PFA_RIGHT) ?  MF_CHECKED : MF_UNCHECKED);
    CheckMenuItem(hMenu, ID_BULLET, ((pf.wNumbering == PFN_BULLET) ?  MF_CHECKED : MF_UNCHECKED));
    EnableMenuItem(hMenu, ID_EDIT_UNDO, SendMessageW(hwndEditor, EM_CANUNDO, 0, 0) ?
            MF_ENABLED : MF_GRAYED);
    EnableMenuItem(hMenu, ID_EDIT_REDO, SendMessageW(hwndEditor, EM_CANREDO, 0, 0) ?
            MF_ENABLED : MF_GRAYED);

    CheckMenuItem(hMenu, ID_TOGGLE_TOOLBAR, is_bar_visible(BANDID_TOOLBAR) ?
            MF_CHECKED : MF_UNCHECKED);

    CheckMenuItem(hMenu, ID_TOGGLE_FORMATBAR, is_bar_visible(BANDID_FORMATBAR) ?
            MF_CHECKED : MF_UNCHECKED);

    CheckMenuItem(hMenu, ID_TOGGLE_STATUSBAR, IsWindowVisible(hwndStatus) ?
            MF_CHECKED : MF_UNCHECKED);

    CheckMenuItem(hMenu, ID_TOGGLE_RULER, is_bar_visible(BANDID_RULER) ? MF_CHECKED : MF_UNCHECKED);

    gt.flags = GTL_NUMCHARS;
    gt.codepage = 1200;
    textLength = SendMessageW(hEditorWnd, EM_GETTEXTLENGTHEX, (WPARAM)&gt, 0);
    EnableMenuItem(hMenu, ID_FIND, textLength ? MF_ENABLED : MF_GRAYED);

    mi.cbSize = sizeof(mi);
    mi.fMask = MIIM_DATA;

    GetMenuItemInfoW(hMenu, ID_FIND_NEXT, FALSE, &mi);

    EnableMenuItem(hMenu, ID_FIND_NEXT, (textLength && mi.dwItemData) ?  MF_ENABLED : MF_GRAYED);

    EnableMenuItem(hMenu, ID_REPLACE, textLength ? MF_ENABLED : MF_GRAYED);

    return 0;
}

__attribute__((used)) static LRESULT OnSize( HWND hWnd, WPARAM wParam, LPARAM lParam )
{
    int nStatusSize = 0;
    RECT rc;
    HWND hwndEditor = preview_isactive() ? GetDlgItem(hWnd, IDC_PREVIEW) : GetDlgItem(hWnd, IDC_EDITOR);
    HWND hwndStatusBar = GetDlgItem(hWnd, IDC_STATUSBAR);
    HWND hwndReBar = GetDlgItem(hWnd, IDC_REBAR);
    HWND hRulerWnd = GetDlgItem(hwndReBar, IDC_RULER);
    int rebarHeight = 0;

    if (hwndStatusBar)
    {
        SendMessageW(hwndStatusBar, WM_SIZE, 0, 0);
        if (IsWindowVisible(hwndStatusBar))
        {
            GetClientRect(hwndStatusBar, &rc);
            nStatusSize = rc.bottom - rc.top;
        } else
        {
            nStatusSize = 0;
        }
    }
    if (hwndReBar)
    {
        rebarHeight = SendMessageW(hwndReBar, RB_GETBARHEIGHT, 0, 0);

        MoveWindow(hwndReBar, 0, 0, LOWORD(lParam), rebarHeight, TRUE);
    }
    if (hwndEditor)
    {
        GetClientRect(hWnd, &rc);
        MoveWindow(hwndEditor, 0, rebarHeight, rc.right, rc.bottom-nStatusSize-rebarHeight, TRUE);
    }

    redraw_ruler(hRulerWnd);

    return DefWindowProcW(hWnd, WM_SIZE, wParam, lParam);
}

