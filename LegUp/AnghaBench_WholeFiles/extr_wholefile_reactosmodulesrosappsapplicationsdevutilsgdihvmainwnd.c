#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WPARAM ;
struct TYPE_11__ {int code; } ;
struct TYPE_10__ {int uNewState; int uOldState; int /*<<< orphan*/  iItem; } ;
struct TYPE_9__ {int /*<<< orphan*/  lParam; int /*<<< orphan*/  iItem; int /*<<< orphan*/  mask; } ;
struct TYPE_8__ {int bottom; int right; } ;
typedef  TYPE_1__ RECT ;
typedef  TYPE_2__ LV_ITEM ;
typedef  int /*<<< orphan*/  LRESULT ;
typedef  TYPE_3__* LPNMLISTVIEW ;
typedef  TYPE_4__* LPNMHDR ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HandleList_Update (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IDC_HANDLELIST ; 
 int /*<<< orphan*/  IDC_PROCESSLIST ; 
 int /*<<< orphan*/  IDC_REFRESHHANDLE ; 
 int /*<<< orphan*/  IDC_REFRESHPROCESS ; 
 int /*<<< orphan*/  LVIF_PARAM ; 
 int LVIS_SELECTED ; 
#define  LVN_ITEMCHANGED 128 
 int /*<<< orphan*/  ListView_GetItem (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  MoveWindow (int /*<<< orphan*/ ,int,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int g_Separator ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static LRESULT
MainWindow_OnSize(HWND hMainWnd)
{
	HWND hProcessListctrl, hHandleListCtrl, hProcessRefresh, hHandleRefresh;
	RECT rect;

	hProcessListctrl = GetDlgItem(hMainWnd, IDC_PROCESSLIST);
	hHandleListCtrl = GetDlgItem(hMainWnd, IDC_HANDLELIST);
	hProcessRefresh = GetDlgItem(hMainWnd, IDC_REFRESHPROCESS);
	hHandleRefresh = GetDlgItem(hMainWnd, IDC_REFRESHHANDLE);

	GetClientRect(hMainWnd, &rect);

//g_Separator = (rect.right / 2);
	MoveWindow(hProcessListctrl, 5, 5, g_Separator - 5, rect.bottom - 40, TRUE);
	MoveWindow(hHandleListCtrl, g_Separator + 5, 5, rect.right - g_Separator - 5, rect.bottom - 40, TRUE);
	MoveWindow(hProcessRefresh, g_Separator - 90, rect.bottom - 30, 90, 25, TRUE);
	MoveWindow(hHandleRefresh, rect.right - 90, rect.bottom - 30, 90, 25, TRUE);

	return 0;
}

__attribute__((used)) static LRESULT
MainWnd_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	LPNMHDR pnmh = (LPNMHDR)lParam;

	switch(pnmh->code)
	{
		case LVN_ITEMCHANGED:
		{
			LPNMLISTVIEW pnmlv = (LPNMLISTVIEW)pnmh;
			if ((wParam == IDC_PROCESSLIST)
				&& (pnmlv->uNewState & LVIS_SELECTED)
				&& !(pnmlv->uOldState & LVIS_SELECTED))
			{
				LV_ITEM item;
				memset(&item, 0, sizeof(LV_ITEM));
				item.mask = LVIF_PARAM;
				item.iItem = pnmlv->iItem;
				(void)ListView_GetItem(GetDlgItem(hWnd, IDC_PROCESSLIST), &item);
				HandleList_Update(GetDlgItem(hWnd, IDC_HANDLELIST), (HANDLE)item.lParam);
				return TRUE;
			}
			break;
		}
	}

	return 0;
}

