#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_8__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vimmenu_T ;
typedef  int /*<<< orphan*/  guicolor_T ;
typedef  scalar_t__ char_u ;
typedef  char UINT ;
struct TYPE_21__ {int char_width; int char_height; int col; int row; int in_focus; int border_width; scalar_t__ starting; scalar_t__ menu_is_active; } ;
struct TYPE_20__ {scalar_t__ vim_code1; scalar_t__ vim_code0; char key_sym; } ;
struct TYPE_19__ {int flags; int /*<<< orphan*/  cy; int /*<<< orphan*/  cx; } ;
struct TYPE_18__ {scalar_t__ message; char wParam; int /*<<< orphan*/  lParam; int /*<<< orphan*/  hwnd; } ;
struct TYPE_17__ {int left; int top; int right; int bottom; } ;
typedef  int /*<<< orphan*/  TIMERPROC ;
typedef  TYPE_1__ RECT ;
typedef  TYPE_2__ MSG ;
typedef  TYPE_3__* LPWINDOWPOS ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HFONT ;
typedef  int /*<<< orphan*/  HBRUSH ;
typedef  scalar_t__ GuiFont ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int CSI ; 
 int Columns ; 
 int /*<<< orphan*/  CreateSolidBrush (int /*<<< orphan*/ ) ; 
 scalar_t__ Ctrl_AT ; 
 scalar_t__ Ctrl_C ; 
 scalar_t__ Ctrl_HAT ; 
 scalar_t__ Ctrl__ ; 
 int /*<<< orphan*/  DeleteBrush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DrawMenuBar (int /*<<< orphan*/ *) ; 
 int FAIL ; 
 void* FALSE ; 
 void* FILL_X (int) ; 
 void* FILL_Y (int) ; 
 int /*<<< orphan*/  FillRect (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FrameRect (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int GetKeyState (char) ; 
 int GetMenuItemCount (int /*<<< orphan*/ ) ; 
 int GetSystemMetrics (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowRect (int /*<<< orphan*/ *,TYPE_1__*) ; 
 scalar_t__ IS_SPECIAL (int) ; 
 int /*<<< orphan*/  InvertRect (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  IsIconic (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IsZoomed (int /*<<< orphan*/ *) ; 
 scalar_t__ KS_MODIFIER ; 
 int K_CSI ; 
 scalar_t__ K_SECOND (int) ; 
 scalar_t__ K_THIRD (int) ; 
 int /*<<< orphan*/  KillTimer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  MB_OK ; 
 int MOD_MASK_ALT ; 
 int MOD_MASK_CTRL ; 
 int MOD_MASK_SHIFT ; 
 char MapVirtualKey (char,int) ; 
 int /*<<< orphan*/  MessageBeep (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MyTranslateMessage (TYPE_2__*) ; 
 scalar_t__ NUL ; 
 int OK ; 
 int /*<<< orphan*/  PM_NOREMOVE ; 
 int /*<<< orphan*/  PM_REMOVE ; 
 int /*<<< orphan*/  PostMessage (int /*<<< orphan*/ ,scalar_t__,char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RESIZE_VERT ; 
 int Rows ; 
 int /*<<< orphan*/  SM_CYCAPTION ; 
 int /*<<< orphan*/  SM_CYFRAME ; 
 int /*<<< orphan*/  SM_CYMENU ; 
 int SWP_NOSIZE ; 
 int /*<<< orphan*/  SW_MINIMIZE ; 
 int /*<<< orphan*/  SetActiveWindow (int /*<<< orphan*/ *) ; 
 scalar_t__ SetTimer (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ShowWindow (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int TOLOWER_ASC (int) ; 
 int TO_SPECIAL (int,scalar_t__) ; 
 void* TRUE ; 
 scalar_t__ VIM_ISDIGIT (int) ; 
 char VK_CANCEL ; 
 char VK_CONTROL ; 
 char VK_MENU ; 
 char VK_SHIFT ; 
 char VK_SPACE ; 
 scalar_t__ WM_KEYDOWN ; 
 scalar_t__ WM_SYSKEYDOWN ; 
 int /*<<< orphan*/  WM_TIMER ; 
 scalar_t__ _OnTimer ; 
 int /*<<< orphan*/  add_to_input_buf (scalar_t__*,int) ; 
 void* allow_scrollbar ; 
 long blink_offtime ; 
 long blink_ontime ; 
 long blink_waittime ; 
 int char_to_string (int,scalar_t__*,int,void*) ; 
 int /*<<< orphan*/  clear_rect (TYPE_1__*) ; 
 scalar_t__ dead_key ; 
 void* got_int ; 
 TYPE_8__ gui ; 
 int /*<<< orphan*/  gui_mch_menu_grey (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gui_mch_start_blink () ; 
 int /*<<< orphan*/  gui_mch_stop_blink () ; 
 int /*<<< orphan*/  gui_mswin_get_valid_dimensions (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gui_set_shellsize (void*,void*,int /*<<< orphan*/ ) ; 
 scalar_t__ input_available () ; 
 int /*<<< orphan*/  pDispatchMessage (TYPE_2__*) ; 
 int /*<<< orphan*/  pGetMessage (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ pPeekMessage (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ s_busy_processing ; 
 int s_button_pending ; 
 int /*<<< orphan*/  s_getting_focus ; 
 int /*<<< orphan*/  s_hdc ; 
 int /*<<< orphan*/ * s_hwnd ; 
 int /*<<< orphan*/  s_menuBar ; 
 void* s_need_activate ; 
 void* s_timed_out ; 
 scalar_t__ s_wait_timer ; 
 int simplify_key (int,int*) ; 
 TYPE_4__* special_keys ; 
 int /*<<< orphan*/  trash_input_buf () ; 
 int /*<<< orphan*/  vim_is_input_buf_full () ; 

void
gui_mch_set_blinking(long wait, long on, long off)
{
    blink_waittime = wait;
    blink_ontime = on;
    blink_offtime = off;
}

void
gui_mch_free_font(GuiFont font)
{
    if (font)
	DeleteObject((HFONT)font);
}

__attribute__((used)) static int
hex_digit(int c)
{
    if (VIM_ISDIGIT(c))
	return c - '0';
    c = TOLOWER_ASC(c);
    if (c >= 'a' && c <= 'f')
	return c - 'a' + 10;
    return -1000;
}

int
gui_mch_haskey(char_u *name)
{
    int i;

    for (i = 0; special_keys[i].vim_code1 != NUL; i++)
	if (name[0] == special_keys[i].vim_code0 &&
					 name[1] == special_keys[i].vim_code1)
	    return OK;
    return FAIL;
}

void
gui_mch_beep(void)
{
    MessageBeep(MB_OK);
}

void
gui_mch_invert_rectangle(
    int	    r,
    int	    c,
    int	    nr,
    int	    nc)
{
    RECT    rc;

    /*
     * Note: InvertRect() excludes right and bottom of rectangle.
     */
    rc.left = FILL_X(c);
    rc.top = FILL_Y(r);
    rc.right = rc.left + nc * gui.char_width;
    rc.bottom = rc.top + nr * gui.char_height;
    InvertRect(s_hdc, &rc);
}

void
gui_mch_iconify(void)
{
    ShowWindow(s_hwnd, SW_MINIMIZE);
}

void
gui_mch_draw_hollow_cursor(guicolor_T color)
{
    HBRUSH  hbr;
    RECT    rc;

    /*
     * Note: FrameRect() excludes right and bottom of rectangle.
     */
    rc.left = FILL_X(gui.col);
    rc.top = FILL_Y(gui.row);
    rc.right = rc.left + gui.char_width;
#ifdef FEAT_MBYTE
    if (mb_lefthalve(gui.row, gui.col))
	rc.right += gui.char_width;
#endif
    rc.bottom = rc.top + gui.char_height;
    hbr = CreateSolidBrush(color);
    FrameRect(s_hdc, &rc, hbr);
    DeleteBrush(hbr);
}

void
gui_mch_draw_part_cursor(
    int		w,
    int		h,
    guicolor_T	color)
{
    HBRUSH	hbr;
    RECT	rc;

    /*
     * Note: FillRect() excludes right and bottom of rectangle.
     */
    rc.left =
#ifdef FEAT_RIGHTLEFT
		/* vertical line should be on the right of current point */
		CURSOR_BAR_RIGHT ? FILL_X(gui.col + 1) - w :
#endif
		    FILL_X(gui.col);
    rc.top = FILL_Y(gui.row) + gui.char_height - h;
    rc.right = rc.left + w;
    rc.bottom = rc.top + h;
    hbr = CreateSolidBrush(color);
    FillRect(s_hdc, &rc, hbr);
    DeleteBrush(hbr);
}

__attribute__((used)) static void
process_message(void)
{
    MSG		msg;
    UINT	vk = 0;		/* Virtual key */
    char_u	string[40];
    int		i;
    int		modifiers = 0;
    int		key;
#ifdef FEAT_MENU
    static char_u k10[] = {K_SPECIAL, 'k', ';', 0};
#endif

    pGetMessage(&msg, NULL, 0, 0);

#ifdef FEAT_OLE
    /* Look after OLE Automation commands */
    if (msg.message == WM_OLE)
    {
	char_u *str = (char_u *)msg.lParam;
	if (str == NULL || *str == NUL)
	{
	    /* Message can't be ours, forward it.  Fixes problem with Ultramon
	     * 3.0.4 */
	    pDispatchMessage(&msg);
	}
	else
	{
	    add_to_input_buf(str, (int)STRLEN(str));
	    vim_free(str);  /* was allocated in CVim::SendKeys() */
	}
	return;
    }
#endif

#ifdef FEAT_NETBEANS_INTG
    if (msg.message == WM_NETBEANS)
    {
	netbeans_read();
	return;
    }
#endif

#ifdef FEAT_SNIFF
    if (sniff_request_waiting && want_sniff_request)
    {
	static char_u bytes[3] = {CSI, (char_u)KS_EXTRA, (char_u)KE_SNIFF};
	add_to_input_buf(bytes, 3); /* K_SNIFF */
	sniff_request_waiting = 0;
	want_sniff_request = 0;
	/* request is handled in normal.c */
    }
    if (msg.message == WM_USER)
    {
	MyTranslateMessage(&msg);
	pDispatchMessage(&msg);
	return;
    }
#endif

#ifdef MSWIN_FIND_REPLACE
    /* Don't process messages used by the dialog */
    if (s_findrep_hwnd != NULL && pIsDialogMessage(s_findrep_hwnd, &msg))
    {
	HandleMouseHide(msg.message, msg.lParam);
	return;
    }
#endif

    /*
     * Check if it's a special key that we recognise.  If not, call
     * TranslateMessage().
     */
    if (msg.message == WM_KEYDOWN || msg.message == WM_SYSKEYDOWN)
    {
	vk = (int) msg.wParam;
	/* handle key after dead key, but ignore shift, alt and control */
	if (dead_key && vk != VK_SHIFT && vk != VK_MENU && vk != VK_CONTROL)
	{
	    dead_key = 0;
	    /* handle non-alphabetic keys (ones that hopefully cannot generate
	     * umlaut-characters), unless when control is down */
	    if (vk < 'A' || vk > 'Z' || (GetKeyState(VK_CONTROL) & 0x8000))
	    {
		MSG dm;

		dm.message = msg.message;
		dm.hwnd = msg.hwnd;
		dm.wParam = VK_SPACE;
		MyTranslateMessage(&dm);	/* generate dead character */
		if (vk != VK_SPACE) /* and send current character once more */
		    PostMessage(msg.hwnd, msg.message, msg.wParam, msg.lParam);
		return;
	    }
	}

	/* Check for CTRL-BREAK */
	if (vk == VK_CANCEL)
	{
	    trash_input_buf();
	    got_int = TRUE;
	    string[0] = Ctrl_C;
	    add_to_input_buf(string, 1);
	}

	for (i = 0; special_keys[i].key_sym != 0; i++)
	{
	    /* ignore VK_SPACE when ALT key pressed: system menu */
	    if (special_keys[i].key_sym == vk
		    && (vk != VK_SPACE || !(GetKeyState(VK_MENU) & 0x8000)))
	    {
#ifdef FEAT_MENU
		/* Check for <F10>: Windows selects the menu.  When <F10> is
		 * mapped we want to use the mapping instead. */
		if (vk == VK_F10
			&& gui.menu_is_active
			&& check_map(k10, State, FALSE, TRUE, FALSE,
							  NULL, NULL) == NULL)
		    break;
#endif
		if (GetKeyState(VK_SHIFT) & 0x8000)
		    modifiers |= MOD_MASK_SHIFT;
		/*
		 * Don't use caps-lock as shift, because these are special keys
		 * being considered here, and we only want letters to get
		 * shifted -- webb
		 */
		/*
		if (GetKeyState(VK_CAPITAL) & 0x0001)
		    modifiers ^= MOD_MASK_SHIFT;
		*/
		if (GetKeyState(VK_CONTROL) & 0x8000)
		    modifiers |= MOD_MASK_CTRL;
		if (GetKeyState(VK_MENU) & 0x8000)
		    modifiers |= MOD_MASK_ALT;

		if (special_keys[i].vim_code1 == NUL)
		    key = special_keys[i].vim_code0;
		else
		    key = TO_SPECIAL(special_keys[i].vim_code0,
						   special_keys[i].vim_code1);
		key = simplify_key(key, &modifiers);
		if (key == CSI)
		    key = K_CSI;

		if (modifiers)
		{
		    string[0] = CSI;
		    string[1] = KS_MODIFIER;
		    string[2] = modifiers;
		    add_to_input_buf(string, 3);
		}

		if (IS_SPECIAL(key))
		{
		    string[0] = CSI;
		    string[1] = K_SECOND(key);
		    string[2] = K_THIRD(key);
		    add_to_input_buf(string, 3);
		}
		else
		{
		    int	len;

		    /* Handle "key" as a Unicode character. */
		    len = char_to_string(key, string, 40, FALSE);
		    add_to_input_buf(string, len);
		}
		break;
	    }
	}
	if (special_keys[i].key_sym == 0)
	{
	    /* Some keys need C-S- where they should only need C-.
	     * Ignore 0xff, Windows XP sends it when NUMLOCK has changed since
	     * system startup (Helmut Stiegler, 2003 Oct 3). */
	    if (vk != 0xff
		    && (GetKeyState(VK_CONTROL) & 0x8000)
		    && !(GetKeyState(VK_SHIFT) & 0x8000)
		    && !(GetKeyState(VK_MENU) & 0x8000))
	    {
		/* CTRL-6 is '^'; Japanese keyboard maps '^' to vk == 0xDE */
		if (vk == '6' || MapVirtualKey(vk, 2) == (UINT)'^')
		{
		    string[0] = Ctrl_HAT;
		    add_to_input_buf(string, 1);
		}
		/* vk == 0xBD AZERTY for CTRL-'-', but CTRL-[ for * QWERTY! */
		else if (vk == 0xBD)	/* QWERTY for CTRL-'-' */
		{
		    string[0] = Ctrl__;
		    add_to_input_buf(string, 1);
		}
		/* CTRL-2 is '@'; Japanese keyboard maps '@' to vk == 0xC0 */
		else if (vk == '2' || MapVirtualKey(vk, 2) == (UINT)'@')
		{
		    string[0] = Ctrl_AT;
		    add_to_input_buf(string, 1);
		}
		else
		    MyTranslateMessage(&msg);
	    }
	    else
		MyTranslateMessage(&msg);
	}
    }
#ifdef FEAT_MBYTE_IME
    else if (msg.message == WM_IME_NOTIFY)
	_OnImeNotify(msg.hwnd, (DWORD)msg.wParam, (DWORD)msg.lParam);
    else if (msg.message == WM_KEYUP && im_get_status())
	/* added for non-MS IME (Yasuhiro Matsumoto) */
	MyTranslateMessage(&msg);
#endif
#if !defined(FEAT_MBYTE_IME) && defined(GLOBAL_IME)
/* GIME_TEST */
    else if (msg.message == WM_IME_STARTCOMPOSITION)
    {
	POINT point;

	global_ime_set_font(&norm_logfont);
	point.x = FILL_X(gui.col);
	point.y = FILL_Y(gui.row);
	MapWindowPoints(s_textArea, s_hwnd, &point, 1);
	global_ime_set_position(&point);
    }
#endif

#ifdef FEAT_MENU
    /* Check for <F10>: Default effect is to select the menu.  When <F10> is
     * mapped we need to stop it here to avoid strange effects (e.g., for the
     * key-up event) */
    if (vk != VK_F10 || check_map(k10, State, FALSE, TRUE, FALSE,
							  NULL, NULL) == NULL)
#endif
	pDispatchMessage(&msg);
}

void
gui_mch_update(void)
{
    MSG	    msg;

    if (!s_busy_processing)
	while (pPeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)
						  && !vim_is_input_buf_full())
	    process_message();
}

int
gui_mch_wait_for_chars(int wtime)
{
    MSG		msg;
    int		focus;

    s_timed_out = FALSE;

    if (wtime > 0)
    {
	/* Don't do anything while processing a (scroll) message. */
	if (s_busy_processing)
	    return FAIL;
	s_wait_timer = (UINT)SetTimer(NULL, 0, (UINT)wtime,
							 (TIMERPROC)_OnTimer);
    }

    allow_scrollbar = TRUE;

    focus = gui.in_focus;
    while (!s_timed_out)
    {
	/* Stop or start blinking when focus changes */
	if (gui.in_focus != focus)
	{
	    if (gui.in_focus)
		gui_mch_start_blink();
	    else
		gui_mch_stop_blink();
	    focus = gui.in_focus;
	}

	if (s_need_activate)
	{
#ifdef WIN32
	    (void)SetForegroundWindow(s_hwnd);
#else
	    (void)SetActiveWindow(s_hwnd);
#endif
	    s_need_activate = FALSE;
	}

#ifdef FEAT_NETBEANS_INTG
	/* Process the queued netbeans messages. */
	netbeans_parse_messages();
#endif

	/*
	 * Don't use gui_mch_update() because then we will spin-lock until a
	 * char arrives, instead we use GetMessage() to hang until an
	 * event arrives.  No need to check for input_buf_full because we are
	 * returning as soon as it contains a single char -- webb
	 */
	process_message();

	if (input_available())
	{
	    if (s_wait_timer != 0 && !s_timed_out)
	    {
		KillTimer(NULL, s_wait_timer);

		/* Eat spurious WM_TIMER messages */
		while (pPeekMessage(&msg, s_hwnd, WM_TIMER, WM_TIMER, PM_REMOVE))
		    ;
		s_wait_timer = 0;
	    }
	    allow_scrollbar = FALSE;

	    /* Clear pending mouse button, the release event may have been
	     * taken by the dialog window.  But don't do this when getting
	     * focus, we need the mouse-up event then. */
	    if (!s_getting_focus)
		s_button_pending = -1;

	    return OK;
	}
    }
    allow_scrollbar = FALSE;
    return FAIL;
}

void
gui_mch_clear_block(
    int		row1,
    int		col1,
    int		row2,
    int		col2)
{
    RECT	rc;

    /*
     * Clear one extra pixel at the far right, for when bold characters have
     * spilled over to the window border.
     * Note: FillRect() excludes right and bottom of rectangle.
     */
    rc.left = FILL_X(col1);
    rc.top = FILL_Y(row1);
    rc.right = FILL_X(col2 + 1) + (col2 == Columns - 1);
    rc.bottom = FILL_Y(row2 + 1);
    clear_rect(&rc);
}

void
gui_mch_clear_all(void)
{
    RECT    rc;

    rc.left = 0;
    rc.top = 0;
    rc.right = Columns * gui.char_width + 2 * gui.border_width;
    rc.bottom = Rows * gui.char_height + 2 * gui.border_width;
    clear_rect(&rc);
}

void
gui_mch_enable_menu(int flag)
{
#ifdef FEAT_MENU
    SetMenu(s_hwnd, flag ? s_menuBar : NULL);
#endif
}

void
gui_mch_set_menu_pos(
    int	    x,
    int	    y,
    int	    w,
    int	    h)
{
    /* It will be in the right place anyway */
}

void
gui_mch_menu_hidden(
    vimmenu_T	*menu,
    int		hidden)
{
    /*
     * This doesn't do what we want.  Hmm, just grey the menu items for now.
     */
    /*
    if (hidden)
	EnableMenuItem(s_menuBar, menu->id, MF_BYCOMMAND | MF_DISABLED);
    else
	EnableMenuItem(s_menuBar, menu->id, MF_BYCOMMAND | MF_ENABLED);
    */
    gui_mch_menu_grey(menu, hidden);
}

void
gui_mch_draw_menubar(void)
{
    DrawMenuBar(s_hwnd);
}

__attribute__((used)) static int
gui_mswin_get_menu_height(
    int	    fix_window)	    /* If TRUE, resize window if menu height changed */
{
    static int	old_menu_height = -1;

    int	    num;
    int	    menu_height;

    if (gui.menu_is_active)
	num = GetMenuItemCount(s_menuBar);
    else
	num = 0;

    if (num == 0)
	menu_height = 0;
    else if (gui.starting)
	menu_height = GetSystemMetrics(SM_CYMENU);
    else
    {
	RECT r1, r2;
	int frameht = GetSystemMetrics(SM_CYFRAME);
	int capht = GetSystemMetrics(SM_CYCAPTION);

	/*	get window rect of s_hwnd
		 * get client rect of s_hwnd
		 * get cap height
		 * subtract from window rect, the sum of client height,
		 * (if not maximized)frame thickness, and caption height.
	 */
	GetWindowRect(s_hwnd, &r1);
	GetClientRect(s_hwnd, &r2);
	menu_height = r1.bottom - r1.top - (r2.bottom-r2.top +
			       2 * frameht * (!IsZoomed(s_hwnd)) + capht);
    }

    if (fix_window && menu_height != old_menu_height)
    {
	old_menu_height = menu_height;
	gui_set_shellsize(FALSE, FALSE, RESIZE_VERT);
    }

    return menu_height;
}

__attribute__((used)) static BOOL
_OnWindowPosChanging(
    HWND hwnd,
    LPWINDOWPOS lpwpos)
{

    if (!IsIconic(hwnd) && !(lpwpos->flags & SWP_NOSIZE))
    {
	gui_mswin_get_valid_dimensions(lpwpos->cx, lpwpos->cy,
				     &lpwpos->cx, &lpwpos->cy);
    }
    return 0;
}

