#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_6__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  szTemp ;
typedef  int WPARAM ;
typedef  int /*<<< orphan*/  WCHAR ;
struct TYPE_10__ {int size; int /*<<< orphan*/  dwIdsName; } ;
struct TYPE_9__ {int* ColumnSizeArray; int* ColumnOrderArray; scalar_t__* Columns; } ;
struct TYPE_8__ {int mask; int cchTextMax; int cxy; int /*<<< orphan*/ * pszText; } ;
struct TYPE_7__ {int mask; int fmt; int cx; int iSubItem; scalar_t__ pszText; } ;
typedef  TYPE_1__ LVCOLUMN ;
typedef  int LRESULT ;
typedef  scalar_t__ LPWSTR ;
typedef  int /*<<< orphan*/ * LPCWSTR ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  TYPE_2__ HDITEM ;

/* Variables and functions */
 unsigned int COLUMN_NMAX ; 
 TYPE_6__* ColumnPresets ; 
 int /*<<< orphan*/  ColumnsDialogWndProc ; 
 scalar_t__ DialogBoxW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ FALSE ; 
 int HDI_TEXT ; 
 int HDI_WIDTH ; 
 int /*<<< orphan*/  HDM_GETITEM ; 
 int /*<<< orphan*/  HDM_GETITEMCOUNT ; 
 int /*<<< orphan*/  HDM_GETORDERARRAY ; 
 int /*<<< orphan*/  HDM_SETORDERARRAY ; 
 int Header_GetItemCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IDD_COLUMNS_DIALOG ; 
 scalar_t__ IDOK ; 
static  int InsertColumn (int,int /*<<< orphan*/ *,int,int,int) ; 
 int LVCFMT_LEFT ; 
 int LVCF_FMT ; 
 int LVCF_SUBITEM ; 
 int LVCF_TEXT ; 
 int LVCF_WIDTH ; 
 int /*<<< orphan*/  ListView_DeleteColumn (int /*<<< orphan*/ ,int) ; 
 int ListView_InsertColumn (int /*<<< orphan*/ ,int,TYPE_1__*) ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  MAKEINTRESOURCEW (int /*<<< orphan*/ ) ; 
 int SendMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ TRUE ; 
 TYPE_4__ TaskManagerSettings ; 
 int /*<<< orphan*/  UpdateColumnDataHints () ; 
 scalar_t__ _wcsicmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hInst ; 
 int /*<<< orphan*/  hMainWnd ; 
 int /*<<< orphan*/  hProcessPageHeaderCtrl ; 
 int /*<<< orphan*/  hProcessPageListCtrl ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 

void AddColumns(void)
{
    LRESULT       size;
    WCHAR         szTemp[256];
    unsigned int  n;

    for (n=0; n<COLUMN_NMAX; n++) {
        if (TaskManagerSettings.Columns[n]) {
            LoadStringW(hInst, ColumnPresets[n].dwIdsName, szTemp, sizeof(szTemp)/sizeof(WCHAR));
            InsertColumn(n, szTemp, LVCFMT_LEFT, TaskManagerSettings.ColumnSizeArray[n], -1);
        }
    }

    size = SendMessageW(hProcessPageHeaderCtrl, HDM_GETITEMCOUNT, 0, 0);
    SendMessageW(hProcessPageHeaderCtrl, HDM_SETORDERARRAY, (WPARAM) size, (LPARAM) &TaskManagerSettings.ColumnOrderArray);

    UpdateColumnDataHints();
}

__attribute__((used)) static int InsertColumn(int nCol, LPCWSTR lpszColumnHeading, int nFormat, int nWidth, int nSubItem)
{
    LVCOLUMN  column;

    column.mask = LVCF_TEXT|LVCF_FMT;
    column.pszText = (LPWSTR)lpszColumnHeading;
    column.fmt = nFormat;

    if (nWidth != -1)
    {
        column.mask |= LVCF_WIDTH;
        column.cx = nWidth;
    }

    if (nSubItem != -1)
    {
        column.mask |= LVCF_SUBITEM;
        column.iSubItem = nSubItem;
    }

    return ListView_InsertColumn(hProcessPageListCtrl, nCol, &column);
}

void SaveColumnSettings(void)
{
    HDITEM        hditem;
    int           i, n;
    WCHAR         text[260];
    WCHAR         szTemp[256];
    LRESULT       size;

    /* Reset column data */
    for (i=0; i<COLUMN_NMAX; i++) {
        TaskManagerSettings.ColumnOrderArray[i] = i;
        TaskManagerSettings.Columns[i] = FALSE;
        TaskManagerSettings.ColumnSizeArray[i] = ColumnPresets[i].size;
    }

    /* Get header order */
    size = SendMessageW(hProcessPageHeaderCtrl, HDM_GETITEMCOUNT, 0, 0);
    SendMessageW(hProcessPageHeaderCtrl, HDM_GETORDERARRAY, (WPARAM) size, (LPARAM) &TaskManagerSettings.ColumnOrderArray);

    /* Get visible columns */
    for (i = 0; i < SendMessageW(hProcessPageHeaderCtrl, HDM_GETITEMCOUNT, 0, 0); i++) {
        memset(&hditem, 0, sizeof(HDITEM));

        hditem.mask = HDI_TEXT|HDI_WIDTH;
        hditem.pszText = text;
        hditem.cchTextMax = 260;

        SendMessageW(hProcessPageHeaderCtrl, HDM_GETITEM, i, (LPARAM) &hditem);

        for (n = 0; n < COLUMN_NMAX; n++) {
            LoadStringW(hInst, ColumnPresets[n].dwIdsName, szTemp, sizeof(szTemp)/sizeof(WCHAR));
            if (_wcsicmp(text, szTemp) == 0)
            {
                TaskManagerSettings.Columns[n] = TRUE;
                TaskManagerSettings.ColumnSizeArray[n] = hditem.cxy;
            }
        }
    }
}

void ProcessPage_OnViewSelectColumns(void)
{
    int  i;

    if (DialogBoxW(hInst, MAKEINTRESOURCEW(IDD_COLUMNS_DIALOG), hMainWnd, ColumnsDialogWndProc) == IDOK)
    {
        for (i=Header_GetItemCount(hProcessPageHeaderCtrl)-1; i>=0; i--)
        {
            (void)ListView_DeleteColumn(hProcessPageListCtrl, i);
        }

        for (i=0; i<COLUMN_NMAX; i++) {
            TaskManagerSettings.ColumnOrderArray[i] = i;
            TaskManagerSettings.ColumnSizeArray[i] = ColumnPresets[i].size;
        }

        AddColumns();
    }
}

