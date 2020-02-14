#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tm ;
struct timeval {int dummy; } ;
typedef  int /*<<< orphan*/  fd_set ;
typedef  scalar_t__ WPARAM ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_15__ {scalar_t__ left; scalar_t__ top; scalar_t__ right; scalar_t__ bottom; } ;
struct TYPE_14__ {int right; int left; int bottom; int top; } ;
struct TYPE_11__ {int left; int top; int right; int bottom; } ;
struct TYPE_13__ {TYPE_1__ rcPaint; int /*<<< orphan*/  hdc; } ;
struct TYPE_12__ {scalar_t__ x; scalar_t__ y; } ;
typedef  char TCHAR ;
typedef  TYPE_1__ RECT ;
typedef  TYPE_2__ POINT ;
typedef  TYPE_3__ PAINTSTRUCT ;
typedef  int /*<<< orphan*/  LRESULT ;
typedef  TYPE_4__* LPRECT ;
typedef  scalar_t__ LPARAM ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HRGN ;
typedef  int /*<<< orphan*/  HBRUSH ;

/* Variables and functions */
 int /*<<< orphan*/  BeginPaint (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  CreateRectRgn (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CreateSolidBrush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DefWindowProc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EndPaint (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  FD_SET (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FillRect (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GWL_STYLE ; 
 short GetKeyState (int /*<<< orphan*/ ) ; 
 int GetWindowLongPtr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ HIWORD (scalar_t__) ; 
 int /*<<< orphan*/  InvalidateRgn (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IsRectEmpty (TYPE_1__*) ; 
 scalar_t__ LOWORD (scalar_t__) ; 
 int /*<<< orphan*/  MB_OK ; 
 int /*<<< orphan*/  MessageBox (int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PostQuitMessage (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RGB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int SB_BOTTOM ; 
 int /*<<< orphan*/  SB_HORZ ; 
 int SB_LINELEFT ; 
 int SB_LINERIGHT ; 
 int SB_PAGELEFT ; 
 int SB_PAGERIGHT ; 
 int SB_THUMBPOSITION ; 
 int SB_TOP ; 
 int /*<<< orphan*/  SB_VERT ; 
 scalar_t__ SIZE_MAXIMIZED ; 
 scalar_t__ SIZE_MINIMIZED ; 
 scalar_t__ SIZE_RESTORED ; 
 int /*<<< orphan*/  SW_ERASE ; 
 scalar_t__ ScreenToClient (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  ScrollWindowEx (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetCursor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetScrollPos (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  SetScrollRange (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  SetWindowLongPtr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 void* UI_MAX (int,int) ; 
 int UI_MIN (int,int) ; 
 int /*<<< orphan*/  VK_CAPITAL ; 
 int /*<<< orphan*/  VK_NUMLOCK ; 
 int /*<<< orphan*/  VK_SCROLL ; 
 int WS_HSCROLL ; 
 int WS_VSCROLL ; 
 int /*<<< orphan*/  ZeroMemory (struct timeval*,int) ; 
 int /*<<< orphan*/  g_Wnd ; 
 int g_block ; 
 int /*<<< orphan*/  g_cursor ; 
 int g_height ; 
 scalar_t__ g_mousex ; 
 scalar_t__ g_mousey ; 
 scalar_t__ g_tcp_sck ; 
 int g_width ; 
 int g_wnd_cheight ; 
 TYPE_5__ g_wnd_clip ; 
 int g_wnd_cwidth ; 
 int g_xoff ; 
 int g_xscroll ; 
 int g_yoff ; 
 int g_yscroll ; 
 int lstrlen (char*) ; 
 int select (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct timeval*) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  ui_invalidate (int,int,int,int) ; 
 int /*<<< orphan*/  ui_key_down (int,int) ; 
 int /*<<< orphan*/  ui_key_up (int,int) ; 
 int /*<<< orphan*/  ui_mouse_button (int,scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  ui_mouse_move (scalar_t__,scalar_t__) ; 
 scalar_t__ ui_read_wire () ; 
 int /*<<< orphan*/  ui_set_modifier_state (int) ; 

__attribute__((used)) static void
str_to_uni(TCHAR * sizex, char * size1)
{
  int len;
  int i;

  len = strlen(size1);
  for (i = 0; i < len; i++)
  {
    sizex[i] = size1[i];
  }
  sizex[len] = 0;
}

__attribute__((used)) static void
uni_to_str(char * sizex, TCHAR * size1)
{
  int len;
  int i;

  len = lstrlen(size1);
  for (i = 0; i < len; i++)
  {
    sizex[i] = (char)size1[i];
  }
  sizex[len] = 0;
}

__attribute__((used)) static int
check_sck(void)
{
  fd_set rfds;
  struct timeval tm;
  int count;
  int rv;

  rv = 0;
  if (g_block == 0)
  {
    g_block = 1;
    /* see if there really is data */
    FD_ZERO(&rfds);
    FD_SET((unsigned int)g_tcp_sck, &rfds);
    ZeroMemory(&tm, sizeof(tm));
    count = select(g_tcp_sck + 1, &rfds, 0, 0, &tm);
    if (count > 0)
    {
      if (ui_read_wire())
      {
        rv = 1;
      }
      else
      {
        PostQuitMessage(0);
      }
    }
    g_block = 0;
  }
  return rv;
}

void
mi_error(char * msg)
{
#ifdef WITH_DEBUG
  printf(msg);
#else /* WITH_DEBUG */
  TCHAR lmsg[512];
  TCHAR ltitle[512];

  str_to_uni(lmsg, msg);
  str_to_uni(ltitle, "Error");
  MessageBox(g_Wnd, lmsg, ltitle, MB_OK);
#endif /* WITH_DEBUG */
}

__attribute__((used)) static int
get_scan_code_from_ascii(int code)
{
  int rv;

  rv = 0;
  switch (code & 0xff)
  {
    case 0x30: rv = 0x0b; break; // 0
    case 0x31: rv = 0x02; break; // 1
    case 0x32: rv = 0x03; break; // 2
    case 0x33: rv = 0x04; break; // 3
    case 0x34: rv = 0x05; break; // 4
    case 0x35: rv = 0x06; break; // 5
    case 0x36: rv = 0x07; break; // 6
    case 0x37: rv = 0x08; break; // 7
    case 0x38: rv = 0x09; break; // 8
    case 0x39: rv = 0x0a; break; // 9

    case 0xbd: rv = 0x0c; break; // -
    case 0xbb: rv = 0x0d; break; // =
    case 0x08: rv = 0x0e; break; // backspace
    case 0x09: rv = 0x0f; break; // tab
    case 0xdb: rv = 0x1b; break; // ]
    case 0xdd: rv = 0x1a; break; // [
    case 0x14: rv = 0x3a; break; // capslock
    case 0xba: rv = 0x27; break; // ;
    case 0xde: rv = 0x28; break; // '
    case 0x10: rv = 0x2a; break; // shift
    case 0xbc: rv = 0x33; break; // ,
    case 0xbe: rv = 0x34; break; // .
    case 0xbf: rv = 0x35; break; // /
    case 0x0d: rv = 0x1c; break; // enter
    case 0x27: rv = 0x4d; break; // arrow right
    case 0x25: rv = 0x4b; break; // arrow left
    case 0x26: rv = 0x48; break; // arrow up
    case 0x28: rv = 0x50; break; // arrow down
    case 0x20: rv = 0x39; break; // space
    case 0xdc: rv = 0x2b; break; // backslash
    case 0xc0: rv = 0x29; break; // `
    case 0x11: rv = 0x1d; break; // ctl

    case 0x41: rv = 0x1e; break; // a
    case 0x42: rv = 0x30; break; // b
    case 0x43: rv = 0x2e; break; // c
    case 0x44: rv = 0x20; break; // d
    case 0x45: rv = 0x12; break; // e
    case 0x46: rv = 0x21; break; // f
    case 0x47: rv = 0x22; break; // g
    case 0x48: rv = 0x23; break; // h
    case 0x49: rv = 0x17; break; // i
    case 0x4a: rv = 0x24; break; // j
    case 0x4b: rv = 0x25; break; // k
    case 0x4c: rv = 0x26; break; // l
    case 0x4d: rv = 0x32; break; // m
    case 0x4e: rv = 0x31; break; // n
    case 0x4f: rv = 0x18; break; // o
    case 0x50: rv = 0x19; break; // p
    case 0x51: rv = 0x10; break; // q
    case 0x52: rv = 0x13; break; // r
    case 0x53: rv = 0x1f; break; // s
    case 0x54: rv = 0x14; break; // t
    case 0x55: rv = 0x16; break; // u
    case 0x56: rv = 0x2f; break; // v
    case 0x57: rv = 0x11; break; // w
    case 0x58: rv = 0x2d; break; // x
    case 0x59: rv = 0x15; break; // y
    case 0x5a: rv = 0x2c; break; // z
  }
  return rv;
}

__attribute__((used)) static void
mi_scroll(int dx, int dy)
{
  HRGN rgn;

  rgn = CreateRectRgn(0, 0, 0, 0);
  ScrollWindowEx(g_Wnd, dx, dy, 0, 0, rgn, 0, SW_ERASE);
  InvalidateRgn(g_Wnd, rgn, 0);
  DeleteObject(rgn);
}

int
mi_read_keyboard_state(void)
{
  short keydata;
  int code;

  code = 0;
  keydata = GetKeyState(VK_SCROLL);
  if (keydata & 0x0001)
  {
    code |= 1;
  }
  keydata = GetKeyState(VK_NUMLOCK);
  if (keydata & 0x0001)
  {
    code |= 2;
  }
  keydata = GetKeyState(VK_CAPITAL);
  if (keydata & 0x0001)
  {
    code |= 4;
  }
  return code;
}

__attribute__((used)) static void
mi_check_modifier(void)
{
  int code;

  code = mi_read_keyboard_state();
  ui_set_modifier_state(code);
}

__attribute__((used)) static LRESULT
handle_WM_SETCURSOR(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if (g_mousex >= g_wnd_clip.left &&
      g_mousey >= g_wnd_clip.top &&
      g_mousex < g_wnd_clip.right &&
      g_mousey < g_wnd_clip.bottom)
  {
    SetCursor(g_cursor);
  }
  /* need default behavoir here */
  return DefWindowProc(hWnd, message, wParam, lParam);
}

__attribute__((used)) static LRESULT
handle_WM_NCHITTEST(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  POINT pt;

  pt.x = LOWORD(lParam);
  pt.y = HIWORD(lParam);
  if (ScreenToClient(g_Wnd, &pt))
  {
    g_mousex = pt.x;
    g_mousey = pt.y;
  }
  return DefWindowProc(hWnd, message, wParam, lParam);
}

__attribute__((used)) static LRESULT
handle_WM_MOUSEMOVE(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  g_mousex = LOWORD(lParam);
  g_mousey = HIWORD(lParam);
  ui_mouse_move(g_mousex + g_xscroll, g_mousey + g_yscroll);
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_LBUTTONDOWN(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  g_mousex = LOWORD(lParam);
  g_mousey = HIWORD(lParam);
  ui_mouse_button(1, g_mousex + g_xscroll, g_mousey + g_yscroll, 1);
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_LBUTTONUP(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  g_mousex = LOWORD(lParam);
  g_mousey = HIWORD(lParam);
  ui_mouse_button(1, g_mousex + g_xscroll, g_mousey + g_yscroll, 0);
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_RBUTTONDOWN(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  g_mousex = LOWORD(lParam);
  g_mousey = HIWORD(lParam);
  ui_mouse_button(2, g_mousex + g_xscroll, g_mousey + g_yscroll, 1);
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_RBUTTONUP(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  g_mousex = LOWORD(lParam);
  g_mousey = HIWORD(lParam);
  ui_mouse_button(2, g_mousex + g_xscroll, g_mousey + g_yscroll, 0);
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_MBUTTONDOWN(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  g_mousex = LOWORD(lParam);
  g_mousey = HIWORD(lParam);
  ui_mouse_button(3, g_mousex + g_xscroll, g_mousey + g_yscroll, 1);
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_MBUTTONUP(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  g_mousex = LOWORD(lParam);
  g_mousey = HIWORD(lParam);
  ui_mouse_button(3, g_mousex + g_xscroll, g_mousey + g_yscroll, 0);
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_MOUSEWHEEL(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int delta;

  delta = ((signed short)HIWORD(wParam)); /* GET_WHEEL_DELTA_WPARAM(wParam); */
  if (delta > 0)
  {
    ui_mouse_button(4, 0, 0, 1);
    ui_mouse_button(4, 0, 0, 0);
  }
  else
  {
    ui_mouse_button(5, 0, 0, 1);
    ui_mouse_button(5, 0, 0, 0);
  }
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_KEY(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int scancode;
  int ext;
  int down;

  ext = HIWORD(lParam);
  scancode = ext;
  down = !(ext & 0x8000);
  scancode &= 0xff;
  if (scancode == 0)
  {
    scancode = get_scan_code_from_ascii(wParam);
  }
  ext &= 0x0100;
  if (scancode == 0x0045) /* num lock */
  {
    ext &= ~0x0100;
  }
  if (down)
  {
    ui_key_down(scancode, ext);
  }
  else
  {
    ui_key_up(scancode, ext);
  }
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_PAINT(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  PAINTSTRUCT ps;
  RECT rect;
  HBRUSH brush;

  BeginPaint(hWnd, &ps);
  /* paint the area outside the rdp screen with one colour */
  rect = ps.rcPaint;
  rect.left = UI_MAX(rect.left, g_width);
  if (!IsRectEmpty(&rect))
  {
    brush = CreateSolidBrush(RGB(0, 0, 255));
    FillRect(ps.hdc, &rect, brush);
    DeleteObject(brush);
  }
  rect = ps.rcPaint;
  rect.top = UI_MAX(rect.top, g_height);
  if (!IsRectEmpty(&rect))
  {
    brush = CreateSolidBrush(RGB(0, 0, 255));
    FillRect(ps.hdc, &rect, brush);
    DeleteObject(brush);
  }
  rect = ps.rcPaint;
  EndPaint(hWnd, &ps);
  ui_invalidate(rect.left + g_xscroll,
                rect.top + g_yscroll,
                (rect.right - rect.left) + 1,
                (rect.bottom - rect.top) + 1);
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_SIZE(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int oldxscroll;
  int oldyscroll;

  if (wParam == SIZE_MINIMIZED)
  {
    return DefWindowProc(hWnd, message, wParam, lParam);
  }
  g_wnd_cwidth = LOWORD(lParam); /* client width / height */
  g_wnd_cheight = HIWORD(lParam);
  g_wnd_clip.left = 0;
  g_wnd_clip.top = 0;
  g_wnd_clip.right = g_wnd_clip.left + g_wnd_cwidth;
  g_wnd_clip.bottom = g_wnd_clip.top + g_wnd_cheight;
  if (g_wnd_cwidth < g_width || g_wnd_cheight < g_height)
  {
    SetScrollRange(g_Wnd, SB_HORZ, 0, g_width - g_wnd_cwidth, 1);
    SetScrollRange(g_Wnd, SB_VERT, 0, g_height - g_wnd_cheight, 1);
  }
  oldxscroll = g_xscroll;
  oldyscroll = g_yscroll;
  if (g_wnd_cwidth >= g_width)
  {
    g_xscroll = 0;
  }
  else
  {
    g_xscroll = UI_MIN(g_xscroll, g_width - g_wnd_cwidth);
  }
  if (g_wnd_cheight >= g_height)
  {
    g_yscroll = 0;
  }
  else
  {
    g_yscroll = UI_MIN(g_yscroll, g_height - g_wnd_cheight);
  }
  mi_scroll(oldxscroll - g_xscroll, oldyscroll - g_yscroll);
  if (wParam == SIZE_RESTORED || wParam == SIZE_MAXIMIZED)
  {
    /* check the caps, num, and scroll lock here */
    mi_check_modifier();
  }
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_SIZING(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  LPRECT prect;
  int width;
  int height;
  int style;

  prect = (LPRECT) lParam; /* total window rect */
  width = (prect->right - prect->left) - (g_xoff * 2);
  height = (prect->bottom - prect->top) - (g_yoff + g_xoff);
  if (height < g_height || width < g_width)
  {
    style = GetWindowLongPtr(g_Wnd, GWL_STYLE);
    if (!(style & WS_HSCROLL))
    {
      style |= WS_HSCROLL | WS_VSCROLL;
      SetWindowLongPtr(g_Wnd, GWL_STYLE, style);
      g_xscroll = 0;
      g_yscroll = 0;
      SetScrollPos(g_Wnd, SB_HORZ, g_xscroll, 1);
      SetScrollPos(g_Wnd, SB_VERT, g_yscroll, 1);
    }
  }
  else if (height >= g_height && width >= g_width)
  {
    style = GetWindowLongPtr(g_Wnd, GWL_STYLE);
    if (style & WS_HSCROLL)
    {
      style &= ~WS_HSCROLL;
      style &= ~WS_VSCROLL;
      SetWindowLongPtr(g_Wnd, GWL_STYLE, style);
      g_xscroll = 0;
      g_yscroll = 0;
    }
  }
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_HSCROLL(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int code;
  int oldxscroll;

  code = (int) LOWORD(wParam); /* scroll bar value */
  if (code == SB_LINELEFT)
  {
    oldxscroll = g_xscroll;
    g_xscroll--;
    g_xscroll = UI_MAX(g_xscroll, 0);
    SetScrollPos(g_Wnd, SB_HORZ, g_xscroll, 1);
    mi_scroll(oldxscroll - g_xscroll, 0);
  }
  else if (code == SB_LINERIGHT)
  {
    oldxscroll = g_xscroll;
    g_xscroll++;
    g_xscroll = UI_MIN(g_xscroll, g_width - g_wnd_cwidth);
    SetScrollPos(g_Wnd, SB_HORZ, g_xscroll, 1);
    mi_scroll(oldxscroll - g_xscroll, 0);
  }
  else if (code == SB_PAGELEFT)
  {
    oldxscroll = g_xscroll;
    g_xscroll -= g_wnd_cwidth / 2;
    g_xscroll = UI_MAX(g_xscroll, 0);
    SetScrollPos(g_Wnd, SB_HORZ, g_xscroll, 1);
    mi_scroll(oldxscroll - g_xscroll, 0);
  }
  else if (code == SB_PAGERIGHT)
  {
    oldxscroll = g_xscroll;
    g_xscroll += g_wnd_cwidth / 2;
    g_xscroll = UI_MIN(g_xscroll, g_width - g_wnd_cwidth);
    SetScrollPos(g_Wnd, SB_HORZ, g_xscroll, 1);
    mi_scroll(oldxscroll - g_xscroll, 0);
  }
  else if (code == SB_BOTTOM)
  {
    oldxscroll = g_xscroll;
    g_xscroll = g_width - g_wnd_cwidth;
    SetScrollPos(g_Wnd, SB_HORZ, g_xscroll, 1);
    mi_scroll(oldxscroll - g_xscroll, 0);
  }
  else if (code == SB_TOP)
  {
    oldxscroll = g_xscroll;
    g_xscroll = 0;
    SetScrollPos(g_Wnd, SB_HORZ, g_xscroll, 1);
    mi_scroll(oldxscroll - g_xscroll, 0);
  }
  else if (code == SB_THUMBPOSITION)
  {
    oldxscroll = g_xscroll;
    g_xscroll = (signed short) HIWORD(wParam);
    SetScrollPos(g_Wnd, SB_HORZ, g_xscroll, 1);
    mi_scroll(oldxscroll - g_xscroll, 0);
  }
  return 0;
}

__attribute__((used)) static LRESULT
handle_WM_VSCROLL(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int code;
  int oldyscroll;

  code = (int) LOWORD(wParam); /* scroll bar value */
  if (code == SB_LINELEFT)
  {
    oldyscroll = g_yscroll;
    g_yscroll--;
    g_yscroll = UI_MAX(g_yscroll, 0);
    SetScrollPos(g_Wnd, SB_VERT, g_yscroll, 1);
    mi_scroll(0, oldyscroll - g_yscroll);
  }
  else if (code == SB_LINERIGHT)
  {
    oldyscroll = g_yscroll;
    g_yscroll++;
    g_yscroll = UI_MIN(g_yscroll, g_height - g_wnd_cheight);
    SetScrollPos(g_Wnd, SB_VERT, g_yscroll, 1);
    mi_scroll(0, oldyscroll - g_yscroll);
  }
  else if (code == SB_PAGELEFT)
  {
    oldyscroll = g_yscroll;
    g_yscroll -= g_wnd_cheight / 2;
    g_yscroll = UI_MAX(g_yscroll, 0);
    SetScrollPos(g_Wnd, SB_VERT, g_yscroll, 1);
    mi_scroll(0, oldyscroll - g_yscroll);
  }
  else if (code == SB_PAGERIGHT)
  {
    oldyscroll = g_yscroll;
    g_yscroll += g_wnd_cheight / 2;
    g_yscroll = UI_MIN(g_yscroll, g_height - g_wnd_cheight);
    SetScrollPos(g_Wnd, SB_VERT, g_yscroll, 1);
    mi_scroll(0, oldyscroll - g_yscroll);
  }
  else if (code == SB_BOTTOM)
  {
    oldyscroll = g_yscroll;
    g_yscroll = g_height - g_wnd_cheight;
    SetScrollPos(g_Wnd, SB_VERT, g_yscroll, 1);
    mi_scroll(0, oldyscroll - g_yscroll);
  }
  else if (code == SB_TOP)
  {
    oldyscroll = g_yscroll;
    g_yscroll = 0;
    SetScrollPos(g_Wnd, SB_VERT, g_yscroll, 1);
    mi_scroll(0, oldyscroll - g_yscroll);
  }
  else if (code == SB_THUMBPOSITION)
  {
    oldyscroll = g_yscroll;
    g_yscroll = (signed short) HIWORD(wParam);
    SetScrollPos(g_Wnd, SB_VERT, g_yscroll, 1);
    mi_scroll(0, oldyscroll - g_yscroll);
  }
  return 0;
}

