#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_65__   TYPE_9__ ;
typedef  struct TYPE_64__   TYPE_8__ ;
typedef  struct TYPE_63__   TYPE_7__ ;
typedef  struct TYPE_62__   TYPE_6__ ;
typedef  struct TYPE_61__   TYPE_5__ ;
typedef  struct TYPE_60__   TYPE_4__ ;
typedef  struct TYPE_59__   TYPE_3__ ;
typedef  struct TYPE_58__   TYPE_2__ ;
typedef  struct TYPE_57__   TYPE_1__ ;
typedef  struct TYPE_56__   TYPE_19__ ;
typedef  struct TYPE_55__   TYPE_16__ ;
typedef  struct TYPE_54__   TYPE_15__ ;
typedef  struct TYPE_53__   TYPE_14__ ;
typedef  struct TYPE_52__   TYPE_12__ ;
typedef  struct TYPE_51__   TYPE_11__ ;
typedef  struct TYPE_50__   TYPE_10__ ;

/* Type definitions */
typedef  int WORD ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_61__ {int dwFlags; char* pszCaption; int /*<<< orphan*/  hwndParent; int /*<<< orphan*/  hInstance; int /*<<< orphan*/  (* pfnCallback ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
struct TYPE_65__ {int width; int height; int nPages; int hasHelp; int hasApply; int hasFinish; int isModeless; int usePropPage; scalar_t__ active_page; scalar_t__ hImageList; int activeValid; int useCallback; TYPE_6__* proppage; TYPE_5__ ppshheader; scalar_t__ unicode; scalar_t__ result; } ;
struct TYPE_64__ {int left; int top; int right; int bottom; } ;
struct TYPE_63__ {scalar_t__ pszText; int /*<<< orphan*/  mask; int /*<<< orphan*/  iImage; int /*<<< orphan*/  cchTextMax; } ;
struct TYPE_62__ {int isDirty; int useCallback; int hasHelp; int hasIcon; int const* pszText; scalar_t__ hwndPage; scalar_t__ hpage; } ;
struct TYPE_60__ {scalar_t__ hIcon; int /*<<< orphan*/  pszIcon; } ;
struct TYPE_59__ {scalar_t__ pszTemplate; TYPE_19__* pResource; } ;
struct TYPE_58__ {scalar_t__ nStartPage; } ;
struct TYPE_57__ {scalar_t__ pszTemplate; } ;
struct TYPE_56__ {int /*<<< orphan*/  style; } ;
struct TYPE_55__ {TYPE_1__ u; } ;
struct TYPE_54__ {int dwFlags; char const* pszTitle; TYPE_4__ u2; int /*<<< orphan*/  hInstance; TYPE_3__ u; scalar_t__ pfnCallback; } ;
struct TYPE_53__ {int dwFlags; char const* pszCaption; scalar_t__ nPages; TYPE_2__ u2; scalar_t__ pfnCallback; int /*<<< orphan*/  hInstance; int /*<<< orphan*/  hwndParent; int /*<<< orphan*/  dwSize; } ;
struct TYPE_52__ {int signature; int /*<<< orphan*/  style; } ;
struct TYPE_51__ {int x; int y; } ;
struct TYPE_50__ {int x; int y; } ;
typedef  TYPE_7__ TCITEMW ;
typedef  TYPE_8__ RECT ;
typedef  TYPE_9__ PropSheetInfo ;
typedef  int /*<<< orphan*/  PROPSHEETHEADERW ;
typedef  int /*<<< orphan*/  PROPSHEETHEADERA ;
typedef  TYPE_10__ POINT ;
typedef  TYPE_11__ PADDING_INFO ;
typedef  TYPE_12__ MyDLGTEMPLATEEX ;
typedef  int LRESULT ;
typedef  scalar_t__ LPWSTR ;
typedef  scalar_t__ LPVOID ;
typedef  int /*<<< orphan*/  LPSTR ;
typedef  TYPE_10__* LPPOINT ;
typedef  TYPE_14__* LPCVOID ;
typedef  int /*<<< orphan*/  LPCSTR ;
typedef  TYPE_15__* LPCPROPSHEETPAGEW ;
typedef  TYPE_16__* LPCPROPSHEETPAGEA ;
typedef  TYPE_14__* LPCPROPSHEETHEADERW ;
typedef  TYPE_14__* LPCPROPSHEETHEADERA ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int LONG ;
typedef  int INT_PTR ;
typedef  int INT ;
typedef  int /*<<< orphan*/ * HWND ;
typedef  int /*<<< orphan*/  HRSRC ;
typedef  scalar_t__ HPROPSHEETPAGE ;
typedef  scalar_t__ HICON ;
typedef  void* HGLOBAL ;
typedef  int /*<<< orphan*/  DWORD_PTR ;
typedef  int DWORD ;
typedef  TYPE_19__ DLGTEMPLATE ;
typedef  char CHAR ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (char*) ; 
 int /*<<< orphan*/  AdjustWindowRect (TYPE_8__*,int,int) ; 
 void* Alloc (int) ; 
 int /*<<< orphan*/  COMCTL32_hModule ; 
 int /*<<< orphan*/  CP_ACP ; 
 scalar_t__ CreateDialogIndirectParamA (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ CreateDialogIndirectParamW (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DM_SETDEFID ; 
 int /*<<< orphan*/  DS_CONTEXTHELP ; 
 int /*<<< orphan*/  ERR (char*) ; 
 int /*<<< orphan*/  EnableWindow (int /*<<< orphan*/ *,int) ; 
 int FALSE ; 
 int /*<<< orphan*/  FIXME (char*,char*) ; 
 int /*<<< orphan*/  FindResourceA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FindResourceW (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  Free (scalar_t__) ; 
 int /*<<< orphan*/  GWL_STYLE ; 
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ *,TYPE_8__*) ; 
 int /*<<< orphan*/ * GetDlgItem (int /*<<< orphan*/ *,int) ; 
 int GetSystemMetrics (int /*<<< orphan*/ ) ; 
 int GetWindowLongW (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowRect (int /*<<< orphan*/ *,TYPE_8__*) ; 
 int IDCANCEL ; 
 int IDC_APPLY_BUTTON ; 
 int IDC_BACK_BUTTON ; 
 int IDC_FINISH_BUTTON ; 
 int IDC_NEXT_BUTTON ; 
 int IDC_SUNKEN_LINE ; 
 int IDC_SUNKEN_LINEHEADER ; 
 int IDC_TABCONTROL ; 
 int IDD_PROPSHEET ; 
 int IDD_WIZARD ; 
 int IDHELP ; 
 int IDOK ; 
 int /*<<< orphan*/  ILC_COLOR ; 
 int /*<<< orphan*/  IMAGE_ICON ; 
 int INTRNL_ANY_WIZARD ; 
 scalar_t__ IS_INTRESOURCE (char const*) ; 
 int /*<<< orphan*/  ImageList_AddIcon (scalar_t__,scalar_t__) ; 
 scalar_t__ ImageList_Create (int,int,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  LR_DEFAULTCOLOR ; 
 scalar_t__ LoadImageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 void* LoadResource (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 TYPE_19__* LockResource (void*) ; 
 int /*<<< orphan*/  MAKEINTRESOURCEA (int) ; 
 scalar_t__ MAKEINTRESOURCEW (int) ; 
 int /*<<< orphan*/  MAX_TABTEXT_LENGTH ; 
 int /*<<< orphan*/  MapDialogRect (int /*<<< orphan*/ *,TYPE_8__*) ; 
 int /*<<< orphan*/  MapWindowPoints (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_10__*,int) ; 
 void* MulDiv (int,int,int) ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,char*,int) ; 
 int /*<<< orphan*/  PROPSHEET_DialogProc ; 
static  TYPE_11__ PROPSHEET_GetPaddingInfo (int /*<<< orphan*/ *) ; 
static  TYPE_11__ PROPSHEET_GetPaddingInfoWizard (int /*<<< orphan*/ *,TYPE_9__ const*) ; 
 int /*<<< orphan*/  PSCB_PRECREATE ; 
 int PSH_HASHELP ; 
 int PSH_HEADER ; 
 int PSH_MODELESS ; 
 int PSH_NOAPPLYNOW ; 
 int PSH_NOCONTEXTHELP ; 
 int PSH_PROPSHEETPAGE ; 
 int /*<<< orphan*/  PSH_RTLREADING ; 
 int /*<<< orphan*/  PSH_STRETCHWATERMARK ; 
 int PSH_USECALLBACK ; 
 int /*<<< orphan*/  PSH_USEPAGELANG ; 
 int PSH_USEPSTARTPAGE ; 
 int PSH_WIZARD ; 
 int PSH_WIZARD97_NEW ; 
 int PSH_WIZARD97_OLD ; 
 int PSH_WIZARDCONTEXTHELP ; 
 int PSH_WIZARDHASFINISH ; 
 int PSH_WIZARD_LITE ; 
 int PSP_DLGINDIRECT ; 
 int PSP_HASHELP ; 
 int PSP_HIDEHEADER ; 
 int PSP_INTERNAL_UNICODE ; 
 int PSP_USECALLBACK ; 
 int PSP_USEHEADERSUBTITLE ; 
 int PSP_USEHEADERTITLE ; 
 int PSP_USEHICON ; 
 int PSP_USEICONID ; 
 int PSP_USETITLE ; 
 scalar_t__ RT_DIALOG ; 
 int /*<<< orphan*/  SM_CXSMICON ; 
 int /*<<< orphan*/  SM_CYSMICON ; 
 int SWP_NOACTIVATE ; 
 int SWP_NOMOVE ; 
 int SWP_NOSIZE ; 
 int SWP_NOZORDER ; 
 int /*<<< orphan*/  SW_HIDE ; 
 int /*<<< orphan*/  SendMessageW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetRect (TYPE_8__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  SetWindowPos (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int,int,int) ; 
 int /*<<< orphan*/  ShowWindow (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int SizeofResource (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TCIF_IMAGE ; 
 int /*<<< orphan*/  TCIF_TEXT ; 
 int /*<<< orphan*/  TCM_ADJUSTRECT ; 
 int /*<<< orphan*/  TCM_INSERTITEMW ; 
 int /*<<< orphan*/  TCM_SETIMAGELIST ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int TRUE ; 
 scalar_t__ WIZARD_HEADER_HEIGHT ; 
 int WIZARD_PADDING ; 
 int /*<<< orphan*/  WM_SETREDRAW ; 
 int WS_CHILD ; 
 int /*<<< orphan*/  add_flag (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debugstr_a (char const*) ; 
 int /*<<< orphan*/  debugstr_w (int const*) ; 
 int /*<<< orphan*/  lstrlenW (int const*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,TYPE_14__*,int) ; 
 int min (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strcpyW (char*,char const*) ; 
 int strlenW (char const*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wine_dbgstr_rect (TYPE_8__*) ; 

__attribute__((used)) static WCHAR *heap_strdupW(const WCHAR *str)
{
    int len = strlenW(str) + 1;
    WCHAR *ret = Alloc(len * sizeof(WCHAR));
    strcpyW(ret, str);
    return ret;
}

__attribute__((used)) static WCHAR *heap_strdupAtoW(const char *str)
{
    WCHAR *ret;
    INT len;

    len = MultiByteToWideChar(CP_ACP, 0, str, -1, 0, 0);
    ret = Alloc(len * sizeof(WCHAR));
    MultiByteToWideChar(CP_ACP, 0, str, -1, ret, len);

    return ret;
}

__attribute__((used)) static VOID PROPSHEET_UnImplementedFlags(DWORD dwFlags)
{
    CHAR string[256];

    string[0] = '\0';

  /*
   * unhandled header flags:
   *  PSH_RTLREADING         0x00000800
   *  PSH_STRETCHWATERMARK   0x00040000
   *  PSH_USEPAGELANG        0x00200000
   */

    add_flag(PSH_RTLREADING);
    add_flag(PSH_STRETCHWATERMARK);
    add_flag(PSH_USEPAGELANG);
    if (string[0] != '\0')
	FIXME("%s\n", string);
}

__attribute__((used)) static void PROPSHEET_GetPageRect(const PropSheetInfo * psInfo, HWND hwndDlg,
                                  RECT *rc, LPCPROPSHEETPAGEW ppshpage)
{
    if (psInfo->ppshheader.dwFlags & INTRNL_ANY_WIZARD) {     
        HWND hwndChild;
        RECT r;

        if (((psInfo->ppshheader.dwFlags & (PSH_WIZARD97_NEW | PSH_WIZARD97_OLD)) &&
             (psInfo->ppshheader.dwFlags & PSH_HEADER) &&
             !(ppshpage->dwFlags & PSP_HIDEHEADER)) ||
            (psInfo->ppshheader.dwFlags & PSH_WIZARD))
        {
            rc->left = rc->top = WIZARD_PADDING;
        }
        else
        {
            rc->left = rc->top = 0;
        }
        rc->right = psInfo->width - rc->left;
        rc->bottom = psInfo->height - rc->top;
        MapDialogRect(hwndDlg, rc);

        if ((psInfo->ppshheader.dwFlags & (PSH_WIZARD97_NEW | PSH_WIZARD97_OLD)) &&
            (psInfo->ppshheader.dwFlags & PSH_HEADER) &&
            !(ppshpage->dwFlags & PSP_HIDEHEADER))
        {
            hwndChild = GetDlgItem(hwndDlg, IDC_SUNKEN_LINEHEADER);
            GetClientRect(hwndChild, &r);
            MapWindowPoints(hwndChild, hwndDlg, (LPPOINT) &r, 2);
            rc->top += r.bottom + 1;
        }
    } else {
        HWND hwndTabCtrl = GetDlgItem(hwndDlg, IDC_TABCONTROL);
        GetClientRect(hwndTabCtrl, rc);
        SendMessageW(hwndTabCtrl, TCM_ADJUSTRECT, FALSE, (LPARAM)rc);
        MapWindowPoints(hwndTabCtrl, hwndDlg, (LPPOINT)rc, 2);
    }
}

__attribute__((used)) static INT PROPSHEET_FindPageByResId(const PropSheetInfo * psInfo, LRESULT resId)
{
   INT i;

   for (i = 0; i < psInfo->nPages; i++)
   {
      LPCPROPSHEETPAGEA lppsp = (LPCPROPSHEETPAGEA)psInfo->proppage[i].hpage;

      /* Fixme: if resource ID is a string shall we use strcmp ??? */
      if (lppsp->u.pszTemplate == (LPVOID)resId)
         break;
   }

   return i;
}

__attribute__((used)) static void PROPSHEET_CollectSheetInfoCommon(PropSheetInfo * psInfo, DWORD dwFlags)
{
  PROPSHEET_UnImplementedFlags(dwFlags);

  psInfo->hasHelp = dwFlags & PSH_HASHELP;
  psInfo->hasApply = !(dwFlags & PSH_NOAPPLYNOW);
  psInfo->hasFinish = dwFlags & PSH_WIZARDHASFINISH;
  psInfo->isModeless = dwFlags & PSH_MODELESS;
  psInfo->usePropPage = dwFlags & PSH_PROPSHEETPAGE;
  if (psInfo->active_page < 0 || psInfo->active_page >= psInfo->nPages)
     psInfo->active_page = 0;

  psInfo->result = 0;
  psInfo->hImageList = 0;
  psInfo->activeValid = FALSE;
}

__attribute__((used)) static void PROPSHEET_CollectSheetInfoA(LPCPROPSHEETHEADERA lppsh,
                                       PropSheetInfo * psInfo)
{
  DWORD dwSize = min(lppsh->dwSize,sizeof(PROPSHEETHEADERA));
  DWORD dwFlags = lppsh->dwFlags;

  psInfo->useCallback = (dwFlags & PSH_USECALLBACK )&& (lppsh->pfnCallback);

  memcpy(&psInfo->ppshheader,lppsh,dwSize);
  TRACE("\n** PROPSHEETHEADER **\ndwSize\t\t%d\ndwFlags\t\t%08x\nhwndParent\t%p\nhInstance\t%p\npszCaption\t'%s'\nnPages\t\t%d\npfnCallback\t%p\n",
	lppsh->dwSize, lppsh->dwFlags, lppsh->hwndParent, lppsh->hInstance,
	debugstr_a(lppsh->pszCaption), lppsh->nPages, lppsh->pfnCallback);

  if (lppsh->dwFlags & INTRNL_ANY_WIZARD)
     psInfo->ppshheader.pszCaption = NULL;
  else
  {
     if (!IS_INTRESOURCE(lppsh->pszCaption))
     {
        int len = MultiByteToWideChar(CP_ACP, 0, lppsh->pszCaption, -1, NULL, 0);
        WCHAR *caption = Alloc( len*sizeof (WCHAR) );

        MultiByteToWideChar(CP_ACP, 0, lppsh->pszCaption, -1, caption, len);
        psInfo->ppshheader.pszCaption = caption;
     }
  }
  psInfo->nPages = lppsh->nPages;

  if (dwFlags & PSH_USEPSTARTPAGE)
  {
    TRACE("PSH_USEPSTARTPAGE is on\n");
    psInfo->active_page = 0;
  }
  else
    psInfo->active_page = lppsh->u2.nStartPage;

  PROPSHEET_CollectSheetInfoCommon(psInfo, dwFlags);
}

__attribute__((used)) static void PROPSHEET_CollectSheetInfoW(LPCPROPSHEETHEADERW lppsh,
                                       PropSheetInfo * psInfo)
{
  DWORD dwSize = min(lppsh->dwSize,sizeof(PROPSHEETHEADERW));
  DWORD dwFlags = lppsh->dwFlags;

  psInfo->useCallback = (dwFlags & PSH_USECALLBACK) && (lppsh->pfnCallback);

  memcpy(&psInfo->ppshheader,lppsh,dwSize);
  TRACE("\n** PROPSHEETHEADER **\ndwSize\t\t%d\ndwFlags\t\t%08x\nhwndParent\t%p\nhInstance\t%p\npszCaption\t%s\nnPages\t\t%d\npfnCallback\t%p\n",
      lppsh->dwSize, lppsh->dwFlags, lppsh->hwndParent, lppsh->hInstance, debugstr_w(lppsh->pszCaption), lppsh->nPages, lppsh->pfnCallback);

  if (lppsh->dwFlags & INTRNL_ANY_WIZARD)
     psInfo->ppshheader.pszCaption = NULL;
  else
  {
     if (!IS_INTRESOURCE(lppsh->pszCaption))
       psInfo->ppshheader.pszCaption = heap_strdupW( lppsh->pszCaption );
  }
  psInfo->nPages = lppsh->nPages;

  if (dwFlags & PSH_USEPSTARTPAGE)
  {
    TRACE("PSH_USEPSTARTPAGE is on\n");
    psInfo->active_page = 0;
  }
  else
    psInfo->active_page = lppsh->u2.nStartPage;

  PROPSHEET_CollectSheetInfoCommon(psInfo, dwFlags);
}

__attribute__((used)) static BOOL PROPSHEET_CollectPageInfo(LPCPROPSHEETPAGEW lppsp,
                               PropSheetInfo * psInfo,
                               int index, BOOL resize)
{
  const DLGTEMPLATE* pTemplate;
  const WORD*  p;
  DWORD dwFlags;
  int width, height;

  if (!lppsp)
    return FALSE;

  TRACE("\n");
  psInfo->proppage[index].hpage = (HPROPSHEETPAGE)lppsp;
  psInfo->proppage[index].hwndPage = 0;
  psInfo->proppage[index].isDirty = FALSE;

  /*
   * Process property page flags.
   */
  dwFlags = lppsp->dwFlags;
  psInfo->proppage[index].useCallback = (dwFlags & PSP_USECALLBACK) && (lppsp->pfnCallback);
  psInfo->proppage[index].hasHelp = dwFlags & PSP_HASHELP;
  psInfo->proppage[index].hasIcon = dwFlags & (PSP_USEHICON | PSP_USEICONID);

  /* as soon as we have a page with the help flag, set the sheet flag on */
  if (psInfo->proppage[index].hasHelp)
    psInfo->hasHelp = TRUE;

  /*
   * Process page template.
   */
  if (dwFlags & PSP_DLGINDIRECT)
    pTemplate = lppsp->u.pResource;
  else if(dwFlags & PSP_INTERNAL_UNICODE )
  {
    HRSRC hResource = FindResourceW(lppsp->hInstance,
                                    lppsp->u.pszTemplate,
                                    (LPWSTR)RT_DIALOG);
    HGLOBAL hTemplate = LoadResource(lppsp->hInstance,
                                     hResource);
    pTemplate = LockResource(hTemplate);
  }
  else
  {
    HRSRC hResource = FindResourceA(lppsp->hInstance,
                                    (LPCSTR)lppsp->u.pszTemplate,
                                    (LPSTR)RT_DIALOG);
    HGLOBAL hTemplate = LoadResource(lppsp->hInstance,
                                     hResource);
    pTemplate = LockResource(hTemplate);
  }

  /*
   * Extract the size of the page and the caption.
   */
  if (!pTemplate)
      return FALSE;

  p = (const WORD *)pTemplate;

  if (((const MyDLGTEMPLATEEX*)pTemplate)->signature == 0xFFFF)
  {
    /* DLGTEMPLATEEX (not defined in any std. header file) */

    p++;       /* dlgVer    */
    p++;       /* signature */
    p += 2;    /* help ID   */
    p += 2;    /* ext style */
    p += 2;    /* style     */
  }
  else
  {
    /* DLGTEMPLATE */

    p += 2;    /* style     */
    p += 2;    /* ext style */
  }

  p++;    /* nb items */
  p++;    /*   x      */
  p++;    /*   y      */
  width  = (WORD)*p; p++;
  height = (WORD)*p; p++;

  if (lppsp->dwFlags & (PSP_USEHEADERTITLE | PSP_USEHEADERSUBTITLE))
    psInfo->ppshheader.dwFlags |= PSH_HEADER;

  /* Special calculation for interior wizard pages so the largest page is
   * calculated correctly. We need to add all the padding and space occupied
   * by the header so the width and height sums up to the whole wizard client
   * area. */
  if ((psInfo->ppshheader.dwFlags & (PSH_WIZARD97_OLD | PSH_WIZARD97_NEW)) &&
      (psInfo->ppshheader.dwFlags & PSH_HEADER) &&
      !(dwFlags & PSP_HIDEHEADER))
  {
      height += 2 * WIZARD_PADDING + WIZARD_HEADER_HEIGHT;
      width += 2 * WIZARD_PADDING;
  }
  if (psInfo->ppshheader.dwFlags & PSH_WIZARD)
  {
      height += 2 * WIZARD_PADDING;
      width += 2 * WIZARD_PADDING;
  }

  /* remember the largest width and height */
  if (resize)
  {
      if (width > psInfo->width)
        psInfo->width = width;

      if (height > psInfo->height)
        psInfo->height = height;
  }

  /* menu */
  switch ((WORD)*p)
  {
    case 0x0000:
      p++;
      break;
    case 0xffff:
      p += 2;
      break;
    default:
      p += lstrlenW( p ) + 1;
      break;
  }

  /* class */
  switch ((WORD)*p)
  {
    case 0x0000:
      p++;
      break;
    case 0xffff:
      p += 2;
      break;
    default:
      p += lstrlenW( p ) + 1;
      break;
  }

  /* Extract the caption */
  psInfo->proppage[index].pszText = p;
  TRACE("Tab %d %s\n",index,debugstr_w( p ));

  if (dwFlags & PSP_USETITLE)
  {
    WCHAR szTitle[256];
    const WCHAR *pTitle;
    static const WCHAR pszNull[] = { '(','n','u','l','l',')',0 };

    if (IS_INTRESOURCE( lppsp->pszTitle ))
    {
      if (LoadStringW( lppsp->hInstance, (DWORD_PTR)lppsp->pszTitle, szTitle, ARRAY_SIZE(szTitle)))
        pTitle = szTitle;
      else if (*p)
        pTitle = p;
      else
        pTitle = pszNull;
    }
    else
      pTitle = lppsp->pszTitle;

    psInfo->proppage[index].pszText = heap_strdupW( pTitle );
  }

  /*
   * Build the image list for icons
   */
  if ((dwFlags & PSP_USEHICON) || (dwFlags & PSP_USEICONID))
  {
    HICON hIcon;
    int icon_cx = GetSystemMetrics(SM_CXSMICON);
    int icon_cy = GetSystemMetrics(SM_CYSMICON);

    if (dwFlags & PSP_USEICONID)
      hIcon = LoadImageW(lppsp->hInstance, lppsp->u2.pszIcon, IMAGE_ICON,
                         icon_cx, icon_cy, LR_DEFAULTCOLOR);
    else
      hIcon = lppsp->u2.hIcon;

    if ( hIcon )
    {
      if (psInfo->hImageList == 0 )
	psInfo->hImageList = ImageList_Create(icon_cx, icon_cy, ILC_COLOR, 1, 1);

      ImageList_AddIcon(psInfo->hImageList, hIcon);
    }

  }

  return TRUE;
}

__attribute__((used)) static INT_PTR PROPSHEET_CreateDialog(PropSheetInfo* psInfo)
{
  LRESULT ret;
  LPCVOID template;
  LPVOID temp = 0;
  HRSRC hRes;
  DWORD resSize;
  WORD resID = IDD_PROPSHEET;

  TRACE("(%p)\n", psInfo);
  if (psInfo->ppshheader.dwFlags & INTRNL_ANY_WIZARD)
    resID = IDD_WIZARD;

  if( psInfo->unicode )
  {
    if(!(hRes = FindResourceW(COMCTL32_hModule,
                            MAKEINTRESOURCEW(resID),
                            (LPWSTR)RT_DIALOG)))
      return -1;
  }
  else
  {
    if(!(hRes = FindResourceA(COMCTL32_hModule,
                            MAKEINTRESOURCEA(resID),
                            (LPSTR)RT_DIALOG)))
      return -1;
  }

  if(!(template = LoadResource(COMCTL32_hModule, hRes)))
    return -1;

  /*
   * Make a copy of the dialog template.
   */
  resSize = SizeofResource(COMCTL32_hModule, hRes);

  temp = Alloc(2 * resSize);

  if (!temp)
    return -1;

  memcpy(temp, template, resSize);

  if (psInfo->ppshheader.dwFlags & PSH_NOCONTEXTHELP)
  {
    if (((MyDLGTEMPLATEEX*)temp)->signature == 0xFFFF)
      ((MyDLGTEMPLATEEX*)temp)->style &= ~DS_CONTEXTHELP;
    else
      ((DLGTEMPLATE*)temp)->style &= ~DS_CONTEXTHELP;
  }
  if ((psInfo->ppshheader.dwFlags & INTRNL_ANY_WIZARD) &&
      (psInfo->ppshheader.dwFlags & PSH_WIZARDCONTEXTHELP))
  {
    if (((MyDLGTEMPLATEEX*)temp)->signature == 0xFFFF)
      ((MyDLGTEMPLATEEX*)temp)->style |= DS_CONTEXTHELP;
    else
      ((DLGTEMPLATE*)temp)->style |= DS_CONTEXTHELP;
  }

  if (psInfo->useCallback)
    (*(psInfo->ppshheader.pfnCallback))(0, PSCB_PRECREATE, (LPARAM)temp);

  /* NOTE: MSDN states "Returns a positive value if successful, or -1
   * otherwise for modal property sheets.", but this is wrong. The
   * actual return value is either TRUE (success), FALSE (cancel) or
   * -1 (error). */
  if( psInfo->unicode )
  {
    ret = (INT_PTR)CreateDialogIndirectParamW(psInfo->ppshheader.hInstance,
                                          temp, psInfo->ppshheader.hwndParent,
                                          PROPSHEET_DialogProc, (LPARAM)psInfo);
    if ( !ret ) ret = -1;
  }
  else
  {
    ret = (INT_PTR)CreateDialogIndirectParamA(psInfo->ppshheader.hInstance,
                                          temp, psInfo->ppshheader.hwndParent,
                                          PROPSHEET_DialogProc, (LPARAM)psInfo);
    if ( !ret ) ret = -1;
  }

  Free(temp);

  return ret;
}

__attribute__((used)) static BOOL PROPSHEET_SizeMismatch(HWND hwndDlg, const PropSheetInfo* psInfo)
{
  HWND hwndTabCtrl = GetDlgItem(hwndDlg, IDC_TABCONTROL);
  RECT rcOrigTab, rcPage;

  /*
   * Original tab size.
   */
  GetClientRect(hwndTabCtrl, &rcOrigTab);
  TRACE("orig tab %s\n", wine_dbgstr_rect(&rcOrigTab));

  /*
   * Biggest page size.
   */
  SetRect(&rcPage, 0, 0, psInfo->width, psInfo->height);
  MapDialogRect(hwndDlg, &rcPage);
  TRACE("biggest page %s\n", wine_dbgstr_rect(&rcPage));

  if ( (rcPage.right - rcPage.left) != (rcOrigTab.right - rcOrigTab.left) )
    return TRUE;
  if ( (rcPage.bottom - rcPage.top) != (rcOrigTab.bottom - rcOrigTab.top) )
    return TRUE;

  return FALSE;
}

__attribute__((used)) static BOOL PROPSHEET_AdjustSize(HWND hwndDlg, PropSheetInfo* psInfo)
{
  HWND hwndTabCtrl = GetDlgItem(hwndDlg, IDC_TABCONTROL);
  HWND hwndButton = GetDlgItem(hwndDlg, IDOK);
  RECT rc,tabRect;
  int buttonHeight;
  PADDING_INFO padding = PROPSHEET_GetPaddingInfo(hwndDlg);
  RECT units;
  LONG style;

  /* Get the height of buttons */
  GetClientRect(hwndButton, &rc);
  buttonHeight = rc.bottom;

  /*
   * Biggest page size.
   */
  SetRect(&rc, 0, 0, psInfo->width, psInfo->height);
  MapDialogRect(hwndDlg, &rc);

  /* retrieve the dialog units */
  units.left = units.right = 4;
  units.top = units.bottom = 8;
  MapDialogRect(hwndDlg, &units);

  /*
   * Resize the tab control.
   */
  GetClientRect(hwndTabCtrl,&tabRect);

  SendMessageW(hwndTabCtrl, TCM_ADJUSTRECT, FALSE, (LPARAM)&tabRect);

  if ((rc.bottom - rc.top) < (tabRect.bottom - tabRect.top))
  {
      rc.bottom = rc.top + tabRect.bottom - tabRect.top;
      psInfo->height = MulDiv((rc.bottom - rc.top),8,units.top);
  }

  if ((rc.right - rc.left) < (tabRect.right - tabRect.left))
  {
      rc.right = rc.left + tabRect.right - tabRect.left;
      psInfo->width  = MulDiv((rc.right - rc.left),4,units.left);
  }

  SendMessageW(hwndTabCtrl, TCM_ADJUSTRECT, TRUE, (LPARAM)&rc);

  rc.right -= rc.left;
  rc.bottom -= rc.top;
  TRACE("setting tab %p, rc (0,0)-(%d,%d)\n",
        hwndTabCtrl, rc.right, rc.bottom);
  SetWindowPos(hwndTabCtrl, 0, 0, 0, rc.right, rc.bottom,
               SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

  GetClientRect(hwndTabCtrl, &rc);

  TRACE("tab client rc %s\n", wine_dbgstr_rect(&rc));

  rc.right += (padding.x * 2);
  rc.bottom += buttonHeight + (3 * padding.y);

  style = GetWindowLongW(hwndDlg, GWL_STYLE);
  if (!(style & WS_CHILD))
    AdjustWindowRect(&rc, style, FALSE);

  rc.right -= rc.left;
  rc.bottom -= rc.top;

  /*
   * Resize the property sheet.
   */
  TRACE("setting dialog %p, rc (0,0)-(%d,%d)\n",
        hwndDlg, rc.right, rc.bottom);
  SetWindowPos(hwndDlg, 0, 0, 0, rc.right, rc.bottom,
               SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
  return TRUE;
}

__attribute__((used)) static BOOL PROPSHEET_AdjustSizeWizard(HWND hwndDlg, const PropSheetInfo* psInfo)
{
  HWND hwndLine = GetDlgItem(hwndDlg, IDC_SUNKEN_LINE);
  RECT rc, lineRect, dialogRect;

  /* Biggest page size */
  SetRect(&rc, 0, 0, psInfo->width, psInfo->height);
  MapDialogRect(hwndDlg, &rc);

  TRACE("Biggest page %s\n", wine_dbgstr_rect(&rc));

  /* Add space for the buttons row */
  GetWindowRect(hwndLine, &lineRect);
  MapWindowPoints(NULL, hwndDlg, (LPPOINT)&lineRect, 2);
  GetClientRect(hwndDlg, &dialogRect);
  rc.bottom += dialogRect.bottom - lineRect.top - 1;

  /* Convert the client coordinates to window coordinates */
  AdjustWindowRect(&rc, GetWindowLongW(hwndDlg, GWL_STYLE), FALSE);

  /* Resize the property sheet */
  TRACE("setting dialog %p, rc (0,0)-(%d,%d)\n",
        hwndDlg, rc.right, rc.bottom);
  SetWindowPos(hwndDlg, 0, 0, 0, rc.right - rc.left, rc.bottom - rc.top,
               SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

  return TRUE;
}

__attribute__((used)) static BOOL PROPSHEET_AdjustButtons(HWND hwndParent, const PropSheetInfo* psInfo)
{
  HWND hwndButton = GetDlgItem(hwndParent, IDOK);
  RECT rcSheet;
  int x, y;
  int num_buttons = 2;
  int buttonWidth, buttonHeight;
  PADDING_INFO padding = PROPSHEET_GetPaddingInfo(hwndParent);

  if (psInfo->hasApply)
    num_buttons++;

  if (psInfo->hasHelp)
    num_buttons++;

  /*
   * Obtain the size of the buttons.
   */
  GetClientRect(hwndButton, &rcSheet);
  buttonWidth = rcSheet.right;
  buttonHeight = rcSheet.bottom;

  /*
   * Get the size of the property sheet.
   */
  GetClientRect(hwndParent, &rcSheet);

  /*
   * All buttons will be at this y coordinate.
   */
  y = rcSheet.bottom - (padding.y + buttonHeight);

  /*
   * Position OK button and make it default.
   */
  hwndButton = GetDlgItem(hwndParent, IDOK);

  x = rcSheet.right - ((padding.x + buttonWidth) * num_buttons);

  SetWindowPos(hwndButton, 0, x, y, 0, 0,
               SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

  SendMessageW(hwndParent, DM_SETDEFID, IDOK, 0);


  /*
   * Position Cancel button.
   */
  hwndButton = GetDlgItem(hwndParent, IDCANCEL);

  x += padding.x + buttonWidth;

  SetWindowPos(hwndButton, 0, x, y, 0, 0,
               SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

  /*
   * Position Apply button.
   */
  hwndButton = GetDlgItem(hwndParent, IDC_APPLY_BUTTON);

  if(psInfo->hasApply)
    x += padding.x + buttonWidth;
  else
    ShowWindow(hwndButton, SW_HIDE);

  SetWindowPos(hwndButton, 0, x, y, 0, 0,
              SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
  EnableWindow(hwndButton, FALSE);

  /*
   * Position Help button.
   */
  hwndButton = GetDlgItem(hwndParent, IDHELP);

  x += padding.x + buttonWidth;
  SetWindowPos(hwndButton, 0, x, y, 0, 0,
              SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

  if(!psInfo->hasHelp)
    ShowWindow(hwndButton, SW_HIDE);

  return TRUE;
}

__attribute__((used)) static BOOL PROPSHEET_AdjustButtonsWizard(HWND hwndParent,
                                          const PropSheetInfo* psInfo)
{
  HWND hwndButton = GetDlgItem(hwndParent, IDCANCEL);
  HWND hwndLine = GetDlgItem(hwndParent, IDC_SUNKEN_LINE);
  HWND hwndLineHeader = GetDlgItem(hwndParent, IDC_SUNKEN_LINEHEADER);
  RECT rcSheet;
  int x, y;
  int num_buttons = 3;
  int buttonWidth, buttonHeight, lineHeight, lineWidth;
  PADDING_INFO padding = PROPSHEET_GetPaddingInfoWizard(hwndParent, psInfo);

  if (psInfo->hasHelp)
    num_buttons++;
  if (psInfo->hasFinish)
    num_buttons++;

  /*
   * Obtain the size of the buttons.
   */
  GetClientRect(hwndButton, &rcSheet);
  buttonWidth = rcSheet.right;
  buttonHeight = rcSheet.bottom;

  GetClientRect(hwndLine, &rcSheet);
  lineHeight = rcSheet.bottom;

  /*
   * Get the size of the property sheet.
   */
  GetClientRect(hwndParent, &rcSheet);

  /*
   * All buttons will be at this y coordinate.
   */
  y = rcSheet.bottom - (padding.y + buttonHeight);
  
  /*
   * Position the Back button.
   */
  hwndButton = GetDlgItem(hwndParent, IDC_BACK_BUTTON);

  x = rcSheet.right - ((padding.x + buttonWidth) * (num_buttons - 1)) - buttonWidth;

  SetWindowPos(hwndButton, 0, x, y, 0, 0,
               SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

  /*
   * Position the Next button.
   */
  hwndButton = GetDlgItem(hwndParent, IDC_NEXT_BUTTON);
  
  x += buttonWidth;
  
  SetWindowPos(hwndButton, 0, x, y, 0, 0,
               SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

  /*
   * Position the Finish button.
   */
  hwndButton = GetDlgItem(hwndParent, IDC_FINISH_BUTTON);
  
  if (psInfo->hasFinish)
    x += padding.x + buttonWidth;

  SetWindowPos(hwndButton, 0, x, y, 0, 0,
               SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

  if (!psInfo->hasFinish)
    ShowWindow(hwndButton, SW_HIDE);

  /*
   * Position the Cancel button.
   */
  hwndButton = GetDlgItem(hwndParent, IDCANCEL);

  x += padding.x + buttonWidth;

  SetWindowPos(hwndButton, 0, x, y, 0, 0,
               SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

  /*
   * Position Help button.
   */
  hwndButton = GetDlgItem(hwndParent, IDHELP);

  if (psInfo->hasHelp)
  {
    x += padding.x + buttonWidth;

    SetWindowPos(hwndButton, 0, x, y, 0, 0,
                 SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
  }
  else
    ShowWindow(hwndButton, SW_HIDE);

  if (psInfo->ppshheader.dwFlags &
      (PSH_WIZARD97_OLD | PSH_WIZARD97_NEW | PSH_WIZARD_LITE)) 
      padding.x = 0;

  /*
   * Position and resize the sunken line.
   */
  x = padding.x;
  y = rcSheet.bottom - ((padding.y * 2) + buttonHeight + lineHeight);

  lineWidth = rcSheet.right - (padding.x * 2);
  SetWindowPos(hwndLine, 0, x, y, lineWidth, 2,
               SWP_NOZORDER | SWP_NOACTIVATE);

  /*
   * Position and resize the header sunken line.
   */
  
  SetWindowPos(hwndLineHeader, 0, 0, 0, rcSheet.right, 2,
	       SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
  if (!(psInfo->ppshheader.dwFlags & (PSH_WIZARD97_OLD | PSH_WIZARD97_NEW)))
      ShowWindow(hwndLineHeader, SW_HIDE);

  return TRUE;
}

__attribute__((used)) static PADDING_INFO PROPSHEET_GetPaddingInfo(HWND hwndDlg)
{
  HWND hwndTab = GetDlgItem(hwndDlg, IDC_TABCONTROL);
  RECT rcTab;
  PADDING_INFO padding;

  GetWindowRect(hwndTab, &rcTab);
  MapWindowPoints( 0, hwndDlg, (POINT *)&rcTab, 2 );

  padding.x = rcTab.left;
  padding.y = rcTab.top;

  return padding;
}

__attribute__((used)) static PADDING_INFO PROPSHEET_GetPaddingInfoWizard(HWND hwndDlg, const PropSheetInfo*
 psInfo)
{
  PADDING_INFO padding;
  RECT rc;
  HWND hwndControl;
  INT idButton;
  POINT ptButton, ptLine;

  TRACE("\n");
  if (psInfo->hasHelp)
  {
	idButton = IDHELP;
  }
  else
  {
    if (psInfo->ppshheader.dwFlags & INTRNL_ANY_WIZARD)
    {
	idButton = IDC_NEXT_BUTTON;
    }
    else
    {
	/* hopefully this is ok */
	idButton = IDCANCEL;
    }
  }

  hwndControl = GetDlgItem(hwndDlg, idButton);
  GetWindowRect(hwndControl, &rc);
  MapWindowPoints( 0, hwndDlg, (POINT *)&rc, 2 );
  ptButton.x = rc.left;
  ptButton.y = rc.top;

  /* Line */
  hwndControl = GetDlgItem(hwndDlg, IDC_SUNKEN_LINE);
  GetWindowRect(hwndControl, &rc);
  MapWindowPoints( 0, hwndDlg, (POINT *)&rc, 2 );
  ptLine.x = rc.left;
  ptLine.y = rc.bottom;

  padding.y = ptButton.y - ptLine.y;

  if (padding.y < 0)
	  ERR("padding negative ! Please report this !\n");

  /* this is most probably not correct, but the best we have now */
  padding.x = padding.y;
  return padding;
}

__attribute__((used)) static BOOL PROPSHEET_CreateTabControl(HWND hwndParent,
                                       const PropSheetInfo * psInfo)
{
  HWND hwndTabCtrl = GetDlgItem(hwndParent, IDC_TABCONTROL);
  TCITEMW item;
  int i, nTabs;
  int iImage = 0;

  TRACE("\n");
  item.mask = TCIF_TEXT;
  item.cchTextMax = MAX_TABTEXT_LENGTH;

  nTabs = psInfo->nPages;

  /*
   * Set the image list for icons.
   */
  if (psInfo->hImageList)
  {
    SendMessageW(hwndTabCtrl, TCM_SETIMAGELIST, 0, (LPARAM)psInfo->hImageList);
  }

  SendMessageW(hwndTabCtrl, WM_SETREDRAW, 0, 0);
  for (i = 0; i < nTabs; i++)
  {
    if ( psInfo->proppage[i].hasIcon )
    {
      item.mask |= TCIF_IMAGE;
      item.iImage = iImage++;
    }
    else
    {
      item.mask &= ~TCIF_IMAGE;
    }

    item.pszText = (LPWSTR) psInfo->proppage[i].pszText;
    SendMessageW(hwndTabCtrl, TCM_INSERTITEMW, i, (LPARAM)&item);
  }
  SendMessageW(hwndTabCtrl, WM_SETREDRAW, 1, 0);

  return TRUE;
}

