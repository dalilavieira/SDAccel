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
struct TYPE_5__ {int add_style; } ;
struct listbox_test {TYPE_1__ prop; } ;
struct listbox_stat {scalar_t__ selcount; scalar_t__ caret; scalar_t__ anchor; scalar_t__ selected; } ;
typedef  int /*<<< orphan*/  buf ;
typedef  int WPARAM ;
typedef  int WORD ;
typedef  int /*<<< orphan*/  WCHAR ;
struct TYPE_7__ {scalar_t__ top; scalar_t__ left; } ;
struct TYPE_6__ {int tmHeight; } ;
typedef  TYPE_2__ TEXTMETRICA ;
typedef  TYPE_3__ RECT ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  LPCREATESTRUCTA ;
typedef  int LPARAM ;
typedef  int INT_PTR ;
typedef  int INT ;
typedef  int /*<<< orphan*/ * HWND ;
typedef  int /*<<< orphan*/ * HMENU ;
typedef  scalar_t__ HFONT ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  CHAR ;
typedef  int BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 void* CreateWindowA (char*,char*,int,int,int,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DCX_CACHE ; 
 int /*<<< orphan*/  DestroyWindow (int /*<<< orphan*/ *) ; 
 int FALSE ; 
 scalar_t__ GetCurrentObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetDCEx (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  GetTextMetricsA (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 int /*<<< orphan*/ * HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ ID_TEST_LABEL ; 
 scalar_t__ ID_TEST_LISTBOX ; 
 int KEYEVENTF_EXTENDEDKEY ; 
 int LBS_OWNERDRAWVARIABLE ; 
 int LBS_SORT ; 
 int LBS_STANDARD ; 
 int /*<<< orphan*/  LB_ADDSTRING ; 
 int /*<<< orphan*/  LB_DELETESTRING ; 
 int LB_ERR ; 
 int /*<<< orphan*/  LB_GETANCHORINDEX ; 
 int /*<<< orphan*/  LB_GETCARETINDEX ; 
 int /*<<< orphan*/  LB_GETCOUNT ; 
 int /*<<< orphan*/  LB_GETCURSEL ; 
 int /*<<< orphan*/  LB_GETITEMHEIGHT ; 
 int /*<<< orphan*/  LB_GETITEMRECT ; 
 int /*<<< orphan*/  LB_GETSELCOUNT ; 
 int /*<<< orphan*/  LB_GETTEXT ; 
 int /*<<< orphan*/  LB_GETTEXTLEN ; 
 int /*<<< orphan*/  LB_SELITEMRANGE ; 
 int MAKELPARAM (int,int) ; 
 int MK_LBUTTON ; 
 int /*<<< orphan*/  MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  OBJ_FONT ; 
 int /*<<< orphan*/  REDRAW ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ SendMessageA (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int) ; 
 int SendMessageW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int) ; 
 int TRUE ; 
 int VK_DOWN ; 
 int /*<<< orphan*/  WAIT ; 
 int /*<<< orphan*/  WM_KEYDOWN ; 
 int /*<<< orphan*/  WM_KEYUP ; 
 int /*<<< orphan*/  WM_LBUTTONDOWN ; 
 int /*<<< orphan*/  WM_LBUTTONUP ; 
 int /*<<< orphan*/  WM_SETFONT ; 
 int WS_BORDER ; 
 int WS_CHILD ; 
 int WS_TABSTOP ; 
 int WS_VISIBLE ; 
 int WS_VSCROLL ; 
 int /*<<< orphan*/  WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  click ; 
 void* g_label ; 
 void* g_listBox ; 
 int /*<<< orphan*/  init ; 
 int /*<<< orphan*/  listbox_ok (struct listbox_test const,int /*<<< orphan*/ ,struct listbox_stat) ; 
 int lstrcmpW (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ok (int,char*,...) ; 
 int /*<<< orphan*/  sel ; 
 int /*<<< orphan*/  step ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__* strings ; 
 int /*<<< orphan*/  trace (char*,int,int) ; 

__attribute__((used)) static int strcmp_aw(LPCWSTR strw, const char *stra)
{
    WCHAR buf[1024];

    if (!stra) return 1;
    MultiByteToWideChar(CP_ACP, 0, stra, -1, buf, sizeof(buf)/sizeof(WCHAR));
    return lstrcmpW(strw, buf);
}

__attribute__((used)) static HWND
create_listbox (DWORD add_style, HWND parent)
{
  HWND handle;
  INT_PTR ctl_id=0;
  if (parent)
    ctl_id=1;
  handle=CreateWindowA("LISTBOX", "TestList",
                            (LBS_STANDARD & ~LBS_SORT) | add_style,
                            0, 0, 100, 100,
                            parent, (HMENU)ctl_id, NULL, 0);

  assert (handle);
  SendMessageA(handle, LB_ADDSTRING, 0, (LPARAM) strings[0]);
  SendMessageA(handle, LB_ADDSTRING, 0, (LPARAM) strings[1]);
  SendMessageA(handle, LB_ADDSTRING, 0, (LPARAM) strings[2]);
  SendMessageA(handle, LB_ADDSTRING, 0, (LPARAM) strings[3]);

#ifdef VISIBLE
  ShowWindow (handle, SW_SHOW);
#endif
  REDRAW;

  return handle;
}

__attribute__((used)) static void
listbox_query (HWND handle, struct listbox_stat *results)
{
  results->selected = SendMessageA(handle, LB_GETCURSEL, 0, 0);
  results->anchor   = SendMessageA(handle, LB_GETANCHORINDEX, 0, 0);
  results->caret    = SendMessageA(handle, LB_GETCARETINDEX, 0, 0);
  results->selcount = SendMessageA(handle, LB_GETSELCOUNT, 0, 0);
}

__attribute__((used)) static void
buttonpress (HWND handle, WORD x, WORD y)
{
  LPARAM lp=x+(y<<16);

  WAIT;
  SendMessageA(handle, WM_LBUTTONDOWN, MK_LBUTTON, lp);
  SendMessageA(handle, WM_LBUTTONUP, 0, lp);
  REDRAW;
}

__attribute__((used)) static void
keypress (HWND handle, WPARAM keycode, BYTE scancode, BOOL extended)
{
  LPARAM lp=1+(scancode<<16)+(extended?KEYEVENTF_EXTENDEDKEY:0);

  WAIT;
  SendMessageA(handle, WM_KEYDOWN, keycode, lp);
  SendMessageA(handle, WM_KEYUP  , keycode, lp | 0xc000000);
  REDRAW;
}

__attribute__((used)) static void
check (const struct listbox_test test)
{
  struct listbox_stat answer;
  HWND hLB=create_listbox (test.prop.add_style, 0);
  RECT second_item;
  int i;
  int res;

  listbox_query (hLB, &answer);
  listbox_ok (test, init, answer);

  SendMessageA(hLB, LB_GETITEMRECT, 1, (LPARAM) &second_item);
  buttonpress(hLB, (WORD)second_item.left, (WORD)second_item.top);

  listbox_query (hLB, &answer);
  listbox_ok (test, click, answer);

  keypress (hLB, VK_DOWN, 0x50, TRUE);

  listbox_query (hLB, &answer);
  listbox_ok (test, step, answer);

  DestroyWindow (hLB);
  hLB=create_listbox (test.prop.add_style, 0);

  SendMessageA(hLB, LB_SELITEMRANGE, TRUE, MAKELPARAM(1, 2));
  listbox_query (hLB, &answer);
  listbox_ok (test, sel, answer);

  for (i=0;i<4;i++) {
	DWORD size = SendMessageA(hLB, LB_GETTEXTLEN, i, 0);
	CHAR *txt;
	WCHAR *txtw;
	int resA, resW;

	txt = HeapAlloc (GetProcessHeap(), HEAP_ZERO_MEMORY, size+1);
	resA=SendMessageA(hLB, LB_GETTEXT, i, (LPARAM)txt);
        ok(!strcmp (txt, strings[i]), "returned string for item %d does not match %s vs %s\n", i, txt, strings[i]);

	txtw = HeapAlloc (GetProcessHeap(), HEAP_ZERO_MEMORY, 2*size+2);
	resW=SendMessageW(hLB, LB_GETTEXT, i, (LPARAM)txtw);
	if (resA != resW) {
            trace("SendMessageW(LB_GETTEXT) not supported on this platform (resA=%d resW=%d), skipping...\n",
                resA, resW);
	} else {
	    WideCharToMultiByte( CP_ACP, 0, txtw, -1, txt, size, NULL, NULL );
            ok(!strcmp (txt, strings[i]), "returned string for item %d does not match %s vs %s\n", i, txt, strings[i]);
	}

	HeapFree (GetProcessHeap(), 0, txtw);
	HeapFree (GetProcessHeap(), 0, txt);
  }
  
  /* Confirm the count of items, and that an invalid delete does not remove anything */
  res = SendMessageA(hLB, LB_GETCOUNT, 0, 0);
  ok((res==4), "Expected 4 items, got %d\n", res);
  res = SendMessageA(hLB, LB_DELETESTRING, -1, 0);
  ok((res==LB_ERR), "Expected LB_ERR items, got %d\n", res);
  res = SendMessageA(hLB, LB_DELETESTRING, 4, 0);
  ok((res==LB_ERR), "Expected LB_ERR items, got %d\n", res);
  res = SendMessageA(hLB, LB_GETCOUNT, 0, 0);
  ok((res==4), "Expected 4 items, got %d\n", res);

  WAIT;
  DestroyWindow (hLB);
}

__attribute__((used)) static void check_item_height(void)
{
    HWND hLB;
    HDC hdc;
    HFONT font;
    TEXTMETRICA tm;
    INT itemHeight;

    hLB = create_listbox (0, 0);
    ok ((hdc = GetDCEx( hLB, 0, DCX_CACHE )) != 0, "Can't get hdc\n");
    ok ((font = GetCurrentObject(hdc, OBJ_FONT)) != 0, "Can't get the current font\n");
    ok (GetTextMetricsA( hdc, &tm ), "Can't read font metrics\n");
    ReleaseDC( hLB, hdc);

    ok (SendMessageA(hLB, WM_SETFONT, (WPARAM)font, 0) == 0, "Can't set font\n");

    itemHeight = SendMessageA(hLB, LB_GETITEMHEIGHT, 0, 0);
    ok (itemHeight == tm.tmHeight, "Item height wrong, got %d, expecting %d\n", itemHeight, tm.tmHeight);

    DestroyWindow (hLB);

    hLB = CreateWindowA("LISTBOX", "TestList", LBS_OWNERDRAWVARIABLE,
                         0, 0, 100, 100, NULL, NULL, NULL, 0);
    itemHeight = SendMessageA(hLB, LB_GETITEMHEIGHT, 0, 0);
    ok(itemHeight == tm.tmHeight, "itemHeight %d\n", itemHeight);
    itemHeight = SendMessageA(hLB, LB_GETITEMHEIGHT, 5, 0);
    ok(itemHeight == tm.tmHeight, "itemHeight %d\n", itemHeight);
    itemHeight = SendMessageA(hLB, LB_GETITEMHEIGHT, -5, 0);
    ok(itemHeight == tm.tmHeight, "itemHeight %d\n", itemHeight);
    DestroyWindow (hLB);
}

__attribute__((used)) static BOOL on_listbox_container_create (HWND hwnd, LPCREATESTRUCTA lpcs)
{
    g_label = CreateWindowA(
        "Static",
        "Contents of static control before DlgDirList.",
        WS_CHILD | WS_VISIBLE,
        10, 10, 512, 32,
        hwnd, (HMENU)ID_TEST_LABEL, NULL, 0);
    if (!g_label) return FALSE;
    g_listBox = CreateWindowA(
        "ListBox",
        "DlgDirList test",
        WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | WS_VSCROLL,
        10, 60, 256, 256,
        hwnd, (HMENU)ID_TEST_LISTBOX, NULL, 0);
    if (!g_listBox) return FALSE;

    return TRUE;
}

