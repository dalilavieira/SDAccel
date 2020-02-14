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
typedef  int /*<<< orphan*/  VOID ;
typedef  int UINT_PTR ;
typedef  int UINT ;
struct TYPE_9__ {int mask; char* pszText; int cx; int /*<<< orphan*/  fmt; } ;
struct TYPE_8__ {int mask; char* pszText; int cchTextMax; size_t iItem; scalar_t__ lParam; scalar_t__ iSubItem; } ;
struct TYPE_7__ {int Type; scalar_t__ UserData; scalar_t__ KernelData; scalar_t__ ProcessId; } ;
typedef  char TCHAR ;
typedef  TYPE_1__* PGDI_TABLE_ENTRY ;
typedef  TYPE_2__ LVITEM ;
typedef  TYPE_3__ LVCOLUMN ;
typedef  scalar_t__ LPARAM ;
typedef  int LONG_PTR ;
typedef  size_t INT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  scalar_t__ HANDLE ;

/* Variables and functions */
 int GDI_HANDLE_BASETYPE_MASK ; 
 size_t GDI_HANDLE_COUNT ; 
 scalar_t__ GDI_HANDLE_CREATE (size_t,int) ; 
 int GDI_HANDLE_GET_TYPE (scalar_t__) ; 
#define  GDI_OBJECT_TYPE_BITMAP 146 
#define  GDI_OBJECT_TYPE_BRUSH 145 
#define  GDI_OBJECT_TYPE_COLORSPACE 144 
#define  GDI_OBJECT_TYPE_DC 143 
#define  GDI_OBJECT_TYPE_DCE 142 
#define  GDI_OBJECT_TYPE_DONTCARE 141 
#define  GDI_OBJECT_TYPE_EMF 140 
#define  GDI_OBJECT_TYPE_ENHMETADC 139 
#define  GDI_OBJECT_TYPE_ENHMETAFILE 138 
#define  GDI_OBJECT_TYPE_EXTPEN 137 
#define  GDI_OBJECT_TYPE_FONT 136 
#define  GDI_OBJECT_TYPE_MEMDC 135 
#define  GDI_OBJECT_TYPE_METADC 134 
#define  GDI_OBJECT_TYPE_METAFILE 133 
#define  GDI_OBJECT_TYPE_PALETTE 132 
#define  GDI_OBJECT_TYPE_PEN 131 
#define  GDI_OBJECT_TYPE_PFE 130 
#define  GDI_OBJECT_TYPE_REGION 129 
#define  GDI_OBJECT_TYPE_SILENT 128 
 TYPE_1__* GdiHandleTable ; 
 char* GetTypeName (scalar_t__) ; 
 int /*<<< orphan*/  HandleList_Update (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  LVCFMT_LEFT ; 
 int LVCF_FMT ; 
 int LVCF_TEXT ; 
 int LVCF_WIDTH ; 
 int LVIF_PARAM ; 
 int LVIF_TEXT ; 
 int /*<<< orphan*/  ListView_DeleteAllItems (int /*<<< orphan*/ ) ; 
 size_t ListView_GetItemCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ListView_InsertColumn (int /*<<< orphan*/ ,int,TYPE_3__*) ; 
 int /*<<< orphan*/  ListView_InsertItem (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  ListView_SetItemText (int /*<<< orphan*/ ,size_t,int,char*) ; 
 int /*<<< orphan*/  wsprintf (char*,char*,int) ; 

VOID
HandleList_Create(HWND hListCtrl)
{
	LVCOLUMN column;

	column.mask = LVCF_TEXT|LVCF_FMT|LVCF_WIDTH;
	column.fmt = LVCFMT_LEFT;

	column.pszText = L"Number";
	column.cx = 50;
	(void)ListView_InsertColumn(hListCtrl, 0, &column);

	column.pszText = L"Index";
	column.cx = 45;
	(void)ListView_InsertColumn(hListCtrl, 1, &column);

	column.pszText = L"Handle";
	column.cx = 90;
	(void)ListView_InsertColumn(hListCtrl, 2, &column);

	column.pszText = L"Type";
	column.cx = 80;
	(void)ListView_InsertColumn(hListCtrl, 3, &column);

	column.pszText = L"Process";
	column.cx = 80;
	(void)ListView_InsertColumn(hListCtrl, 4, &column);

	column.pszText = L"KernelData";
	column.cx = 80;
	(void)ListView_InsertColumn(hListCtrl, 5, &column);

	column.pszText = L"UserData";
	column.cx = 80;
	(void)ListView_InsertColumn(hListCtrl, 6, &column);

	column.pszText = L"Type";
	column.cx = 80;
	(void)ListView_InsertColumn(hListCtrl, 7, &column);

	HandleList_Update(hListCtrl, 0);
}

VOID
HandleList_Update(HWND hHandleListCtrl, HANDLE ProcessId)
{
	INT i, index;
	HANDLE handle;
	PGDI_TABLE_ENTRY pEntry;
	LVITEM item;
	TCHAR strText[80];
	TCHAR* str2;

	(void)ListView_DeleteAllItems(hHandleListCtrl);
	item.mask = LVIF_TEXT|LVIF_PARAM;
	item.pszText = strText;
	item.cchTextMax = 80;
	for (i = 0; i<= GDI_HANDLE_COUNT; i++)
	{
		pEntry = &GdiHandleTable[i];
		if ( ((ProcessId != (HANDLE)1) && ((pEntry->Type & GDI_HANDLE_BASETYPE_MASK) != 0)) ||
		     ((ProcessId == (HANDLE)1) && ((pEntry->Type & GDI_HANDLE_BASETYPE_MASK) == 0)) ||
		      (ProcessId == (HANDLE)2) )
		{
			if (ProcessId == (HANDLE)1 || ProcessId == (HANDLE)2 ||
			    ((LONG_PTR)ProcessId & 0xfffc) == ((LONG_PTR)pEntry->ProcessId & 0xfffc))
			{
				handle = GDI_HANDLE_CREATE(i, pEntry->Type);
				index = ListView_GetItemCount(hHandleListCtrl);
				item.iItem = index;
				item.iSubItem = 0;
				item.lParam = (LPARAM)handle;

				wsprintf(strText, L"%d", index);
				(void)ListView_InsertItem(hHandleListCtrl, &item);

				wsprintf(strText, L"%d", i);
				ListView_SetItemText(hHandleListCtrl, index, 1, strText);

				wsprintf(strText, L"%#08Ix", handle);
				ListView_SetItemText(hHandleListCtrl, index, 2, strText);

				str2 = GetTypeName(handle);
				ListView_SetItemText(hHandleListCtrl, index, 3, str2);

				wsprintf(strText, L"%#08Ix", (UINT_PTR)pEntry->ProcessId);
				ListView_SetItemText(hHandleListCtrl, index, 4, strText);

				wsprintf(strText, L"%#08Ix", (UINT_PTR)pEntry->KernelData);
				ListView_SetItemText(hHandleListCtrl, index, 5, strText);

				wsprintf(strText, L"%#08Ix", (UINT_PTR)pEntry->UserData);
				ListView_SetItemText(hHandleListCtrl, index, 6, strText);

				wsprintf(strText, L"%#08x", (UINT)pEntry->Type);
				ListView_SetItemText(hHandleListCtrl, index, 7, strText);
			}
		}
	}
}

TCHAR*
GetTypeName(HANDLE handle)
{
	TCHAR* strText;
	UINT Type = GDI_HANDLE_GET_TYPE(handle);

	switch (Type)
	{
		case GDI_OBJECT_TYPE_DC:
			strText = L"DC";
			break;
		case GDI_OBJECT_TYPE_REGION:
			strText = L"Region";
			break;
		case GDI_OBJECT_TYPE_BITMAP:
			strText = L"Bitmap";
			break;
		case GDI_OBJECT_TYPE_PALETTE:
			strText = L"Palette";
			break;
		case GDI_OBJECT_TYPE_FONT:
			strText = L"Font";
			break;
		case GDI_OBJECT_TYPE_BRUSH:
			strText = L"Brush";
			break;
		case GDI_OBJECT_TYPE_EMF:
			strText = L"EMF";
			break;
		case GDI_OBJECT_TYPE_PEN:
			strText = L"Pen";
			break;
		case GDI_OBJECT_TYPE_EXTPEN:
			strText = L"ExtPen";
			break;
		case GDI_OBJECT_TYPE_COLORSPACE:
			strText = L"ColSpace";
			break;
		case GDI_OBJECT_TYPE_METADC:
			strText = L"MetaDC";
			break;
		case GDI_OBJECT_TYPE_METAFILE:
			strText = L"Metafile";
			break;
		case GDI_OBJECT_TYPE_ENHMETAFILE:
			strText = L"EMF";
			break;
		case GDI_OBJECT_TYPE_ENHMETADC:
			strText = L"EMDC";
			break;
		case GDI_OBJECT_TYPE_MEMDC:
			strText = L"MemDC";
			break;
		case GDI_OBJECT_TYPE_DCE:
			strText = L"DCE";
			break;
		case GDI_OBJECT_TYPE_PFE:
			strText = L"PFE";
			break;
		case GDI_OBJECT_TYPE_DONTCARE:
			strText = L"anything";
			break;
		case GDI_OBJECT_TYPE_SILENT:
		default:
			strText = L"unknown";
			break;
	}
	return strText;
}

