#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int WPARAM ;
typedef  int /*<<< orphan*/  ULONG_PTR ;
typedef  scalar_t__ UINT ;
struct TYPE_5__ {int /*<<< orphan*/  hbrGray; } ;
struct TYPE_4__ {short x; short y; } ;
typedef  TYPE_1__ POINT ;
typedef  scalar_t__ LRESULT ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int /*<<< orphan*/  HBRUSH ;
typedef  scalar_t__ COLORREF ;

/* Variables and functions */
 int /*<<< orphan*/  COLOR_3DFACE ; 
 int /*<<< orphan*/  COLOR_3DHILIGHT ; 
 int /*<<< orphan*/  COLOR_SCROLLBAR ; 
 int /*<<< orphan*/  COLOR_WINDOW ; 
 int /*<<< orphan*/  COLOR_WINDOWTEXT ; 
 scalar_t__ CTLCOLOR_EDIT ; 
 scalar_t__ CTLCOLOR_LISTBOX ; 
 scalar_t__ CTLCOLOR_SCROLLBAR ; 
 int /*<<< orphan*/  DefWndTrackScrollBar (int /*<<< orphan*/ ,int,TYPE_1__) ; 
 int /*<<< orphan*/  DoAppSwitch (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FIXME (char*,int) ; 
 int /*<<< orphan*/  FNID_DEFWINDOWPROC ; 
 scalar_t__ GetSysColor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetSysColorBrush (int /*<<< orphan*/ ) ; 
 scalar_t__ HIWORD (int /*<<< orphan*/ ) ; 
 scalar_t__ ISITHOOKED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IsWindowEnabled (int /*<<< orphan*/ ) ; 
 scalar_t__ LOWORD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NtUserMessageCall (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  SC_CLOSE 142 
#define  SC_HOTKEY 141 
#define  SC_HSCROLL 140 
#define  SC_KEYMENU 139 
#define  SC_MAXIMIZE 138 
#define  SC_MINIMIZE 137 
#define  SC_MOUSEMENU 136 
#define  SC_MOVE 135 
#define  SC_NEXTWINDOW 134 
#define  SC_PREVWINDOW 133 
#define  SC_RESTORE 132 
#define  SC_SCREENSAVE 131 
#define  SC_SIZE 130 
#define  SC_TASKLIST 129 
#define  SC_VSCROLL 128 
 int /*<<< orphan*/  SW_SHOWNORMAL ; 
 int /*<<< orphan*/  SetBkColor (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  SetTextColor (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  UnrealizeObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WH_CBT ; 
 int /*<<< orphan*/  WM_SYSCOMMAND ; 
 int /*<<< orphan*/  WinExec (char*,int /*<<< orphan*/ ) ; 
 TYPE_2__* gpsi ; 

LRESULT
DefWndHandleSysCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
  POINT Pt;
  LRESULT lResult;

  if (!IsWindowEnabled( hWnd )) return 0;

  switch (wParam & 0xfff0)
    {
      case SC_MOVE:
      case SC_SIZE:
//      case SC_DEFAULT:
      case SC_MOUSEMENU:
      case SC_KEYMENU:
      case SC_SCREENSAVE:
      case SC_MINIMIZE:
      case SC_MAXIMIZE:
      case SC_RESTORE:
      case SC_CLOSE:
      case SC_HOTKEY:
        NtUserMessageCall( hWnd, WM_SYSCOMMAND, wParam, lParam, (ULONG_PTR)&lResult, FNID_DEFWINDOWPROC, FALSE);
        return 0;

      default:
        break;
    }

  if (ISITHOOKED(WH_CBT))
  {
     NtUserMessageCall( hWnd, WM_SYSCOMMAND, wParam, lParam, (ULONG_PTR)&lResult, FNID_DEFWINDOWPROC, FALSE);
     if (lResult) return 0;
  }

  switch (wParam & 0xfff0)
    {

      case SC_VSCROLL:
      case SC_HSCROLL:
        {
          Pt.x = (short)LOWORD(lParam);
          Pt.y = (short)HIWORD(lParam);
          DefWndTrackScrollBar(hWnd, wParam, Pt);
        }
	break;

      case SC_TASKLIST:
        WinExec( "taskman.exe", SW_SHOWNORMAL );
        break;


      case SC_NEXTWINDOW:
      case SC_PREVWINDOW:
        DoAppSwitch( wParam, lParam);
        break;

      default:
        FIXME("Unimplemented DefWndHandleSysCommand wParam 0x%x\n",wParam);
        break;
    }

  return(0);
}

HBRUSH
DefWndControlColor(HDC hDC, UINT ctlType)
{
  if (ctlType == CTLCOLOR_SCROLLBAR)
  {
      HBRUSH hb = GetSysColorBrush(COLOR_SCROLLBAR);
      COLORREF bk = GetSysColor(COLOR_3DHILIGHT);
      SetTextColor(hDC, GetSysColor(COLOR_3DFACE));
      SetBkColor(hDC, bk);

      /* if COLOR_WINDOW happens to be the same as COLOR_3DHILIGHT
       * we better use 0x55aa bitmap brush to make scrollbar's background
       * look different from the window background.
       */
      if ( bk == GetSysColor(COLOR_WINDOW))
          return gpsi->hbrGray;

      UnrealizeObject( hb );
      return hb;
  }

  SetTextColor(hDC, GetSysColor(COLOR_WINDOWTEXT));

  if ((ctlType == CTLCOLOR_EDIT) || (ctlType == CTLCOLOR_LISTBOX))
  {
      SetBkColor(hDC, GetSysColor(COLOR_WINDOW));
  }
  else
  {
      SetBkColor(hDC, GetSysColor(COLOR_3DFACE));
      return GetSysColorBrush(COLOR_3DFACE);
  }

  return GetSysColorBrush(COLOR_WINDOW);
}

