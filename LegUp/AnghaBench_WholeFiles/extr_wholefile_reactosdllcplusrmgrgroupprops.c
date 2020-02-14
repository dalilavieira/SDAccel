#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_7__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  szStr ;
typedef  int /*<<< orphan*/  lvi ;
typedef  int /*<<< orphan*/  column ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  USHORT ;
typedef  scalar_t__ ULONG ;
struct TYPE_21__ {int /*<<< orphan*/ * lgrmi3_domainandname; } ;
struct TYPE_20__ {int mask; int iSubItem; int iImage; scalar_t__ state; int /*<<< orphan*/ * pszText; scalar_t__ cx; int /*<<< orphan*/  fmt; } ;
struct TYPE_19__ {int /*<<< orphan*/  szGroupName; } ;
struct TYPE_18__ {int* Value; } ;
struct TYPE_17__ {int usri20_flags; int /*<<< orphan*/  usri20_comment; int /*<<< orphan*/  usri20_full_name; int /*<<< orphan*/ * usri20_name; } ;
struct TYPE_16__ {double right; double left; } ;
typedef  int /*<<< orphan*/  TCHAR ;
typedef  TYPE_1__ RECT ;
typedef  TYPE_2__* PUSER_INFO_20 ;
typedef  TYPE_3__* PSID_IDENTIFIER_AUTHORITY ;
typedef  int /*<<< orphan*/  PSID ;
typedef  TYPE_4__* PGENERAL_GROUP_DATA ;
typedef  scalar_t__ NET_API_STATUS ;
typedef  TYPE_5__ LV_ITEM ;
typedef  TYPE_5__ LV_COLUMN ;
typedef  scalar_t__ LPTSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  TYPE_7__ LOCALGROUP_MEMBERS_INFO_3 ;
typedef  scalar_t__ INT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HIMAGELIST ;
typedef  int /*<<< orphan*/  HICON ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  DebugPrintf (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DestroyIcon (int /*<<< orphan*/ ) ; 
 scalar_t__ ERROR_MEMBER_IN_ALIAS ; 
 scalar_t__ ERROR_MORE_DATA ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FILTER_NORMAL_ACCOUNT ; 
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_3__* GetSidIdentifierAuthority (int /*<<< orphan*/ ) ; 
 scalar_t__* GetSidSubAuthority (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__* GetSidSubAuthorityCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IDC_USER_ADD_MEMBERSHIP_LIST ; 
 int /*<<< orphan*/  IDI_GROUP ; 
 int /*<<< orphan*/  IDI_LOCKED_USER ; 
 int /*<<< orphan*/  IDI_USER ; 
 int /*<<< orphan*/  IDS_DESCRIPTION ; 
 int /*<<< orphan*/  IDS_NAME ; 
 int ILC_COLOR32 ; 
 int ILC_MASK ; 
 int /*<<< orphan*/  IMAGE_ICON ; 
 int /*<<< orphan*/  ImageList_AddIcon (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ImageList_Create (int,int,int,int,int) ; 
 int /*<<< orphan*/  LR_DEFAULTCOLOR ; 
 int /*<<< orphan*/  LVCFMT_LEFT ; 
 int LVCF_FMT ; 
 int LVCF_SUBITEM ; 
 int LVCF_TEXT ; 
 int LVCF_WIDTH ; 
 int LVIF_IMAGE ; 
 int LVIF_STATE ; 
 int LVIF_TEXT ; 
 int /*<<< orphan*/  LVNI_SELECTED ; 
 int /*<<< orphan*/  LVSIL_SMALL ; 
 int /*<<< orphan*/  LVS_EX_FULLROWSELECT ; 
 int /*<<< orphan*/  ListView_GetItemText (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 scalar_t__ ListView_GetNextItem (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ ListView_GetSelectedCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ListView_InsertColumn (int /*<<< orphan*/ ,int,TYPE_5__*) ; 
 scalar_t__ ListView_InsertItem (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  ListView_SetExtendedListViewStyle (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ListView_SetImageList (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ListView_SetItemText (int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LoadImage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LoadString (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  MAKEINTRESOURCE (int /*<<< orphan*/ ) ; 
 int MB_ICONERROR ; 
 int MB_OK ; 
 int /*<<< orphan*/  MessageBox (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 scalar_t__ NERR_Success ; 
 int /*<<< orphan*/  NetApiBufferFree (TYPE_2__*) ; 
 scalar_t__ NetLocalGroupAddMembers (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 scalar_t__ NetUserEnum (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,scalar_t__*,scalar_t__*,scalar_t__*) ; 
 scalar_t__ SID_REVISION ; 
 int /*<<< orphan*/  TEXT (char*) ; 
 int /*<<< orphan*/  TRUE ; 
 int UF_ACCOUNTDISABLE ; 
 int UNLEN ; 
 int /*<<< orphan*/  _TEXT (char*) ; 
 int /*<<< orphan*/  hApplet ; 
 scalar_t__ lstrlen (scalar_t__) ; 
 int /*<<< orphan*/  memset (TYPE_5__*,int,int) ; 
 scalar_t__ wsprintf (scalar_t__,int /*<<< orphan*/ ,scalar_t__,...) ; 

__attribute__((used)) static VOID
GetTextSid(PSID pSid,
           LPTSTR pTextSid)
{
    PSID_IDENTIFIER_AUTHORITY psia;
    DWORD dwSubAuthorities;
    DWORD dwSidRev = SID_REVISION;
    DWORD dwCounter;
    DWORD dwSidSize;

    psia = GetSidIdentifierAuthority(pSid);

    dwSubAuthorities = *GetSidSubAuthorityCount(pSid);

    dwSidSize = wsprintf(pTextSid, TEXT("S-%lu-"), dwSidRev);

    if ((psia->Value[0] != 0) || (psia->Value[1] != 0))
    {
        dwSidSize += wsprintf(pTextSid + lstrlen(pTextSid),
                              TEXT("0x%02hx%02hx%02hx%02hx%02hx%02hx"),
                              (USHORT)psia->Value[0],
                              (USHORT)psia->Value[1],
                              (USHORT)psia->Value[2],
                              (USHORT)psia->Value[3],
                              (USHORT)psia->Value[4],
                              (USHORT)psia->Value[5]);
    }
    else
    {
        dwSidSize += wsprintf(pTextSid + lstrlen(pTextSid),
                              TEXT("%lu"),
                              (ULONG)(psia->Value[5]) +
                              (ULONG)(psia->Value[4] <<  8) +
                              (ULONG)(psia->Value[3] << 16) +
                              (ULONG)(psia->Value[2] << 24));
    }

    for (dwCounter = 0 ; dwCounter < dwSubAuthorities ; dwCounter++)
    {
        dwSidSize += wsprintf(pTextSid + dwSidSize, TEXT("-%lu"),
                              *GetSidSubAuthority(pSid, dwCounter));
    }
}

__attribute__((used)) static VOID
InitGroupMembersList(HWND hwndDlg,
                     PGENERAL_GROUP_DATA pGroupData)
{
    HWND hwndLV;
    LV_COLUMN column;
    RECT rect;
    TCHAR szStr[32];
    HIMAGELIST hImgList;
    HICON hIcon;

    NET_API_STATUS netStatus;
    PUSER_INFO_20 pUserBuffer;
    DWORD entriesread;
    DWORD totalentries;
    DWORD resume_handle = 0;
    DWORD i;
    LV_ITEM lvi;
    INT iItem;

    hwndLV = GetDlgItem(hwndDlg, IDC_USER_ADD_MEMBERSHIP_LIST);
    GetClientRect(hwndLV, &rect);

    hImgList = ImageList_Create(16,16,ILC_COLOR32 | ILC_MASK,5,5);
    hIcon = LoadImage(hApplet,MAKEINTRESOURCE(IDI_GROUP),IMAGE_ICON,16,16,LR_DEFAULTCOLOR);
    ImageList_AddIcon(hImgList,hIcon);
    DestroyIcon(hIcon);
    hIcon = LoadImage(hApplet, MAKEINTRESOURCE(IDI_USER), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
    ImageList_AddIcon(hImgList, hIcon);
    DestroyIcon(hIcon);
    hIcon = LoadImage(hApplet, MAKEINTRESOURCE(IDI_LOCKED_USER), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
    ImageList_AddIcon(hImgList, hIcon);
    DestroyIcon(hIcon);

    (void)ListView_SetImageList(hwndLV, hImgList, LVSIL_SMALL);
    (void)ListView_SetExtendedListViewStyle(hwndLV, LVS_EX_FULLROWSELECT);

    memset(&column, 0x00, sizeof(column));
    column.mask = LVCF_FMT | LVCF_WIDTH | LVCF_SUBITEM | LVCF_TEXT;
    column.fmt = LVCFMT_LEFT;
    column.cx = (INT)((rect.right - rect.left) * 0.40);
    column.iSubItem = 0;
    LoadString(hApplet, IDS_NAME, szStr, sizeof(szStr) / sizeof(szStr[0]));
    column.pszText = szStr;
    (void)ListView_InsertColumn(hwndLV, 0, &column);

    column.cx = (INT)((rect.right - rect.left) * 0.60);
    column.iSubItem = 1;
    LoadString(hApplet, IDS_DESCRIPTION, szStr, sizeof(szStr) / sizeof(szStr[0]));
    column.pszText = szStr;
    (void)ListView_InsertColumn(hwndLV, 1, &column);

    /* TODO: Enumerate global groups and add them to the list! */

    for (;;)
    {
        netStatus = NetUserEnum(NULL, 20, FILTER_NORMAL_ACCOUNT,
                                (LPBYTE*)&pUserBuffer,
                                1024, &entriesread,
                                &totalentries, &resume_handle);
        if (netStatus != NERR_Success && netStatus != ERROR_MORE_DATA)
            break;

        for (i = 0; i < entriesread; i++)
        {
           memset(&lvi, 0x00, sizeof(lvi));
           lvi.mask = LVIF_TEXT | LVIF_STATE | LVIF_IMAGE;
           lvi.pszText = pUserBuffer[i].usri20_name;
           lvi.state = 0;
           lvi.iImage = (pUserBuffer[i].usri20_flags & UF_ACCOUNTDISABLE) ? 2 : 1;
           iItem = ListView_InsertItem(hwndLV, &lvi);

           ListView_SetItemText(hwndLV, iItem, 1,
                                pUserBuffer[i].usri20_full_name);

           ListView_SetItemText(hwndLV, iItem, 2,
                                pUserBuffer[i].usri20_comment);
        }

        NetApiBufferFree(pUserBuffer);

        /* No more data left */
        if (netStatus != ERROR_MORE_DATA)
            break;
    }
}

__attribute__((used)) static BOOL
AddSelectedUsersToGroup(HWND hwndDlg,
                        PGENERAL_GROUP_DATA pGroupData)
{
    HWND hwndLV;
    INT nSelectedItems;
    INT nItem;
    TCHAR szUserName[UNLEN];
    BOOL bResult = FALSE;
    LOCALGROUP_MEMBERS_INFO_3 memberInfo;
    NET_API_STATUS status;

    hwndLV = GetDlgItem(hwndDlg, IDC_USER_ADD_MEMBERSHIP_LIST);

    nSelectedItems = ListView_GetSelectedCount(hwndLV);
    if (nSelectedItems > 0)
    {
        nItem = ListView_GetNextItem(hwndLV, -1, LVNI_SELECTED);
        while (nItem != -1)
        {
            /* Get the new user name */
            ListView_GetItemText(hwndLV,
                                 nItem, 0,
                                 szUserName,
                                 UNLEN);

            DebugPrintf(_TEXT("Selected user: %s"), szUserName);

            memberInfo.lgrmi3_domainandname = szUserName;

            status = NetLocalGroupAddMembers(NULL, pGroupData->szGroupName, 3,
                                             (LPBYTE)&memberInfo, 1);
            if (status != NERR_Success && status != ERROR_MEMBER_IN_ALIAS)
            {
                TCHAR szText[256];
                wsprintf(szText, TEXT("Error: %u"), status);
                MessageBox(NULL, szText, TEXT("NetLocalGroupAddMembers"), MB_ICONERROR | MB_OK);
            }
            else
            {
                bResult = TRUE;
            }

            nItem = ListView_GetNextItem(hwndLV, nItem, LVNI_SELECTED);
        }
    }

    return bResult;
}

