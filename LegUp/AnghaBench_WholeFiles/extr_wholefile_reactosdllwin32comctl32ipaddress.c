#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_46__   TYPE_7__ ;
typedef  struct TYPE_45__   TYPE_6__ ;
typedef  struct TYPE_44__   TYPE_5__ ;
typedef  struct TYPE_43__   TYPE_4__ ;
typedef  struct TYPE_42__   TYPE_3__ ;
typedef  struct TYPE_41__   TYPE_2__ ;
typedef  struct TYPE_40__   TYPE_1__ ;
typedef  struct TYPE_39__   TYPE_10__ ;

/* Type definitions */
typedef  int WPARAM ;
typedef  int WORD ;
typedef  scalar_t__ WNDPROC ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_46__ {scalar_t__ hwndParent; } ;
struct TYPE_45__ {scalar_t__ Self; scalar_t__ Notify; int Enabled; TYPE_5__* Part; } ;
struct TYPE_44__ {scalar_t__ EditHwnd; int LowerLimit; int UpperLimit; scalar_t__ OrigProc; } ;
struct TYPE_43__ {int /*<<< orphan*/  lfFaceName; } ;
struct TYPE_40__ {scalar_t__ hwndFrom; int idFrom; int /*<<< orphan*/  code; } ;
struct TYPE_42__ {int iField; int iValue; TYPE_1__ hdr; } ;
struct TYPE_41__ {int left; int right; scalar_t__ top; scalar_t__ bottom; } ;
struct TYPE_39__ {scalar_t__ clrGrayText; scalar_t__ clr3dFace; scalar_t__ clrWindowText; scalar_t__ clrWindow; } ;
typedef  TYPE_2__ RECT ;
typedef  int /*<<< orphan*/  POINT ;
typedef  int /*<<< orphan*/  PAINTSTRUCT ;
typedef  TYPE_3__ NMIPADDRESS ;
typedef  int LRESULT ;
typedef  int* LPDWORD ;
typedef  int LPARAM ;
typedef  TYPE_4__ LOGFONTW ;
typedef  TYPE_5__ IPPART_INFO ;
typedef  TYPE_6__ IPADDRESS_INFO ;
typedef  int INT ;
typedef  scalar_t__ HWND ;
typedef  scalar_t__ HTHEME ;
typedef  int /*<<< orphan*/  HMENU ;
typedef  int /*<<< orphan*/  HINSTANCE ;
typedef  scalar_t__ HFONT ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int /*<<< orphan*/  HBRUSH ;
typedef  scalar_t__ DWORD_PTR ;
typedef  int DWORD ;
typedef  TYPE_7__ CREATESTRUCTA ;
typedef  scalar_t__ COLORREF ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ANSI_VAR_FONT ; 
 int BF_ADJUST ; 
 int BF_RECT ; 
 int /*<<< orphan*/  BeginPaint (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CloseThemeData (scalar_t__) ; 
 scalar_t__ CreateFontIndirectW (TYPE_4__*) ; 
 scalar_t__ CreateWindowW (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,scalar_t__,int,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int DT_BOTTOM ; 
 int DT_CENTER ; 
 int DT_SINGLELINE ; 
 int /*<<< orphan*/  DrawEdge (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DrawTextW (int /*<<< orphan*/ ,char const*,int,TYPE_2__*,int) ; 
 int /*<<< orphan*/  DrawThemeBackground (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DrawThemeParentBackground (scalar_t__,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  DrawThemeText (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char const*,int,int,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  EDGE_SUNKEN ; 
 int /*<<< orphan*/  EM_SETSEL ; 
 int /*<<< orphan*/  EN_CHANGE ; 
 int /*<<< orphan*/  EP_EDITTEXT ; 
 int /*<<< orphan*/  ERR (char*,scalar_t__) ; 
 int ES_CENTER ; 
 int ES_READONLY ; 
 int ETS_DISABLED ; 
 int ETS_FOCUSED ; 
 int ETS_NORMAL ; 
 int ETS_READONLY ; 
 int /*<<< orphan*/  EnableWindow (scalar_t__,int) ; 
 int /*<<< orphan*/  EndPaint (scalar_t__,int /*<<< orphan*/ *) ; 
 int FALSE ; 
 int /*<<< orphan*/  FillRect (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GWLP_HINSTANCE ; 
 int /*<<< orphan*/  GWLP_ID ; 
 int /*<<< orphan*/  GWLP_WNDPROC ; 
 int /*<<< orphan*/  GWL_STYLE ; 
 int /*<<< orphan*/  GetClientRect (scalar_t__,TYPE_2__*) ; 
 scalar_t__ GetFocus () ; 
 int /*<<< orphan*/  GetObjectW (scalar_t__,int,TYPE_4__*) ; 
 scalar_t__ GetStockObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetThemeColor (scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,scalar_t__*) ; 
 int GetWindowLongPtrW (scalar_t__,int /*<<< orphan*/ ) ; 
 int GetWindowLongW (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowRect (scalar_t__,TYPE_2__*) ; 
 int GetWindowTextLengthW (scalar_t__) ; 
 scalar_t__ GetWindowTextW (scalar_t__,char*,int) ; 
 scalar_t__ IPADDRESS_SubclassProc ; 
 int /*<<< orphan*/  IPN_FIELDCHANGED ; 
 int /*<<< orphan*/  IP_SUBCLASS_PROP ; 
 int /*<<< orphan*/  InvalidateRgn (scalar_t__,int /*<<< orphan*/ *,int) ; 
 scalar_t__ IsThemeBackgroundPartiallyTransparent (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int MAKEWPARAM (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MapWindowPoints (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,int) ; 
 scalar_t__ OpenThemeData (scalar_t__,int /*<<< orphan*/ ) ; 
 int POS_DEFAULT ; 
 int POS_RIGHT ; 
 int POS_SELALL ; 
 int /*<<< orphan*/  SPI_GETICONTITLELOGFONT ; 
 int SendMessageW (scalar_t__,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  SetBkColor (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  SetFocus (scalar_t__) ; 
 int /*<<< orphan*/  SetPropW (scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  SetTextColor (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ SetWindowLongPtrW (scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  SetWindowLongW (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int SetWindowTextW (scalar_t__,char const*) ; 
 int /*<<< orphan*/  SystemParametersInfoW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TMT_FILLCOLOR ; 
 int /*<<< orphan*/  TMT_TEXTCOLOR ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int TRUE ; 
 int /*<<< orphan*/  WC_EDITW ; 
 int /*<<< orphan*/  WM_COMMAND ; 
 int /*<<< orphan*/  WM_NOTIFY ; 
 int /*<<< orphan*/  WM_SETFONT ; 
 int WS_BORDER ; 
 int WS_CHILD ; 
 int WS_VISIBLE ; 
 int atoiW (char*) ; 
 scalar_t__ atolW (char*) ; 
 TYPE_10__ comctl32_color ; 
 int /*<<< orphan*/  debugstr_w (char*) ; 
 TYPE_6__* heap_alloc_zero (int) ; 
 int /*<<< orphan*/  heap_free (TYPE_6__*) ; 
 int /*<<< orphan*/  strcatW (char*,char const*) ; 
 int /*<<< orphan*/  strcpyW (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wsprintfW (char*,char const*,int) ; 

__attribute__((used)) static void IPADDRESS_UpdateText (const IPADDRESS_INFO *infoPtr)
{
    static const WCHAR zero[] = {'0', 0};
    static const WCHAR dot[]  = {'.', 0};
    WCHAR field[4];
    WCHAR ip[16];
    INT i;

    ip[0] = 0;

    for (i = 0; i < 4; i++) {
        if (GetWindowTextW (infoPtr->Part[i].EditHwnd, field, 4))
            strcatW(ip, field);
        else
            /* empty edit treated as zero */
            strcatW(ip, zero);
        if (i != 3)
            strcatW(ip, dot);
    }

    SetWindowTextW(infoPtr->Self, ip);
}

__attribute__((used)) static LRESULT IPADDRESS_Notify (const IPADDRESS_INFO *infoPtr, UINT command)
{
    HWND hwnd = infoPtr->Self;

    TRACE("(command=%x)\n", command);

    return SendMessageW (infoPtr->Notify, WM_COMMAND,
             MAKEWPARAM (GetWindowLongPtrW (hwnd, GWLP_ID), command), (LPARAM)hwnd);
}

__attribute__((used)) static INT IPADDRESS_IPNotify (const IPADDRESS_INFO *infoPtr, INT field, INT value)
{
    NMIPADDRESS nmip;

    TRACE("(field=%x, value=%d)\n", field, value);

    nmip.hdr.hwndFrom = infoPtr->Self;
    nmip.hdr.idFrom   = GetWindowLongPtrW (infoPtr->Self, GWLP_ID);
    nmip.hdr.code     = IPN_FIELDCHANGED;

    nmip.iField = field;
    nmip.iValue = value;

    SendMessageW (infoPtr->Notify, WM_NOTIFY, nmip.hdr.idFrom, (LPARAM)&nmip);

    TRACE("<-- %d\n", nmip.iValue);

    return nmip.iValue;
}

__attribute__((used)) static int IPADDRESS_GetPartIndex(const IPADDRESS_INFO *infoPtr, HWND hwnd)
{
    int i;

    TRACE("(hwnd=%p)\n", hwnd);

    for (i = 0; i < 4; i++)
        if (infoPtr->Part[i].EditHwnd == hwnd) return i;

    ERR("We subclassed the wrong window! (hwnd=%p)\n", hwnd);
    return -1;
}

__attribute__((used)) static LRESULT IPADDRESS_Draw (const IPADDRESS_INFO *infoPtr, HDC hdc)
{
    static const WCHAR dotW[] = { '.', 0 };
    RECT rect, rcPart;
    COLORREF bgCol, fgCol;
    HTHEME theme;
    int i, state = ETS_NORMAL;

    TRACE("\n");

    GetClientRect (infoPtr->Self, &rect);

    theme = OpenThemeData(infoPtr->Self, WC_EDITW);

    if (theme) {
        DWORD dwStyle = GetWindowLongW (infoPtr->Self, GWL_STYLE);

        if (!infoPtr->Enabled)
            state = ETS_DISABLED;
        else if (dwStyle & ES_READONLY)
            state = ETS_READONLY;
        else if (GetFocus() == infoPtr->Self)
            state = ETS_FOCUSED;

        GetThemeColor(theme, EP_EDITTEXT, state, TMT_FILLCOLOR, &bgCol);
        GetThemeColor(theme, EP_EDITTEXT, state, TMT_TEXTCOLOR, &fgCol);

        if (IsThemeBackgroundPartiallyTransparent (theme, EP_EDITTEXT, state))
            DrawThemeParentBackground(infoPtr->Self, hdc, &rect);
        DrawThemeBackground (theme, hdc, EP_EDITTEXT, state, &rect, 0);
    } else {
        if (infoPtr->Enabled) {
            bgCol = comctl32_color.clrWindow;
            fgCol = comctl32_color.clrWindowText;
        } else {
            bgCol = comctl32_color.clr3dFace;
            fgCol = comctl32_color.clrGrayText;
        }

        FillRect (hdc, &rect, (HBRUSH)(DWORD_PTR)(bgCol+1));
        DrawEdge (hdc, &rect, EDGE_SUNKEN, BF_RECT | BF_ADJUST);
    }
    
    SetBkColor  (hdc, bgCol);
    SetTextColor(hdc, fgCol);

    for (i = 0; i < 3; i++) {
        GetWindowRect (infoPtr->Part[i].EditHwnd, &rcPart);
        MapWindowPoints( 0, infoPtr->Self, (POINT *)&rcPart, 2 );
        rect.left = rcPart.right;
        GetWindowRect (infoPtr->Part[i+1].EditHwnd, &rcPart);
        MapWindowPoints( 0, infoPtr->Self, (POINT *)&rcPart, 2 );
        rect.right = rcPart.left;

        if (theme)
            DrawThemeText(theme, hdc, EP_EDITTEXT, state, dotW, 1, DT_SINGLELINE | DT_CENTER | DT_BOTTOM, 0, &rect);
        else
            DrawTextW(hdc, dotW, 1, &rect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
    }

    if (theme)
        CloseThemeData(theme);

    return 0;
}

__attribute__((used)) static LRESULT IPADDRESS_Create (HWND hwnd, const CREATESTRUCTA *lpCreate)
{
    IPADDRESS_INFO *infoPtr;
    RECT rcClient, edit;
    int i, fieldsize;
    HFONT hFont, hSysFont;
    LOGFONTW logFont, logSysFont;

    TRACE("\n");

    SetWindowLongW (hwnd, GWL_STYLE,
		    GetWindowLongW(hwnd, GWL_STYLE) & ~WS_BORDER);

    infoPtr = heap_alloc_zero (sizeof(*infoPtr));
    if (!infoPtr) return -1;
    SetWindowLongPtrW (hwnd, 0, (DWORD_PTR)infoPtr);

    GetClientRect (hwnd, &rcClient);

    fieldsize = (rcClient.right - rcClient.left) / 4;

    edit.top    = rcClient.top + 2;
    edit.bottom = rcClient.bottom - 2;

    infoPtr->Self = hwnd;
    infoPtr->Enabled = TRUE;
    infoPtr->Notify = lpCreate->hwndParent;

    hSysFont = GetStockObject(ANSI_VAR_FONT);
    GetObjectW(hSysFont, sizeof(LOGFONTW), &logSysFont);
    SystemParametersInfoW(SPI_GETICONTITLELOGFONT, 0, &logFont, 0);
    strcpyW(logFont.lfFaceName, logSysFont.lfFaceName);
    hFont = CreateFontIndirectW(&logFont);

    for (i = 0; i < 4; i++) {
	IPPART_INFO* part = &infoPtr->Part[i];

	part->LowerLimit = 0;
	part->UpperLimit = 255;
        edit.left = rcClient.left + i*fieldsize + 6;
        edit.right = rcClient.left + (i+1)*fieldsize - 2;
        part->EditHwnd =
		CreateWindowW (WC_EDITW, NULL, WS_CHILD | WS_VISIBLE | ES_CENTER,
                               edit.left, edit.top, edit.right - edit.left,
			       edit.bottom - edit.top, hwnd, (HMENU) 1,
			       (HINSTANCE)GetWindowLongPtrW(hwnd, GWLP_HINSTANCE), NULL);
        SendMessageW(part->EditHwnd, WM_SETFONT, (WPARAM) hFont, FALSE);
	SetPropW(part->EditHwnd, IP_SUBCLASS_PROP, hwnd);
        part->OrigProc = (WNDPROC)
		SetWindowLongPtrW (part->EditHwnd, GWLP_WNDPROC,
				(DWORD_PTR)IPADDRESS_SubclassProc);
        EnableWindow(part->EditHwnd, infoPtr->Enabled);
    }

    IPADDRESS_UpdateText (infoPtr);

    return 0;
}

__attribute__((used)) static LRESULT IPADDRESS_Destroy (IPADDRESS_INFO *infoPtr)
{
    int i;

    TRACE("\n");

    for (i = 0; i < 4; i++) {
	IPPART_INFO* part = &infoPtr->Part[i];
        SetWindowLongPtrW (part->EditHwnd, GWLP_WNDPROC, (DWORD_PTR)part->OrigProc);
    }

    SetWindowLongPtrW (infoPtr->Self, 0, 0);
    heap_free (infoPtr);
    return 0;
}

__attribute__((used)) static LRESULT IPADDRESS_Enable (IPADDRESS_INFO *infoPtr, BOOL enabled)
{
    int i;

    infoPtr->Enabled = enabled;

    for (i = 0; i < 4; i++)
        EnableWindow(infoPtr->Part[i].EditHwnd, enabled);

    InvalidateRgn(infoPtr->Self, NULL, FALSE);
    return 0;
}

__attribute__((used)) static LRESULT IPADDRESS_Paint (const IPADDRESS_INFO *infoPtr, HDC hdc)
{
    PAINTSTRUCT ps;

    TRACE("\n");

    if (hdc) return IPADDRESS_Draw (infoPtr, hdc);

    hdc = BeginPaint (infoPtr->Self, &ps);
    IPADDRESS_Draw (infoPtr, hdc);
    EndPaint (infoPtr->Self, &ps);
    return 0;
}

__attribute__((used)) static BOOL IPADDRESS_IsBlank (const IPADDRESS_INFO *infoPtr)
{
    int i;

    TRACE("\n");

    for (i = 0; i < 4; i++)
        if (GetWindowTextLengthW (infoPtr->Part[i].EditHwnd)) return FALSE;

    return TRUE;
}

__attribute__((used)) static int IPADDRESS_GetAddress (const IPADDRESS_INFO *infoPtr, LPDWORD ip_address)
{
    WCHAR field[5];
    int i, invalid = 0;
    DWORD ip_addr = 0;

    TRACE("\n");

    for (i = 0; i < 4; i++) {
        ip_addr *= 256;
        if (GetWindowTextW (infoPtr->Part[i].EditHwnd, field, 4))
  	    ip_addr += atolW(field);
	else
	    invalid++;
    }
    *ip_address = ip_addr;

    return 4 - invalid;
}

__attribute__((used)) static BOOL IPADDRESS_SetRange (IPADDRESS_INFO *infoPtr, int index, WORD range)
{
    TRACE("\n");

    if ( (index < 0) || (index > 3) ) return FALSE;

    infoPtr->Part[index].LowerLimit = range & 0xFF;
    infoPtr->Part[index].UpperLimit = (range >> 8)  & 0xFF;

    return TRUE;
}

__attribute__((used)) static void IPADDRESS_ClearAddress (const IPADDRESS_INFO *infoPtr)
{
    static const WCHAR nil[] = { 0 };
    int i;

    TRACE("\n");

    for (i = 0; i < 4; i++)
        SetWindowTextW (infoPtr->Part[i].EditHwnd, nil);
}

__attribute__((used)) static LRESULT IPADDRESS_SetAddress (const IPADDRESS_INFO *infoPtr, DWORD ip_address)
{
    WCHAR buf[20];
    static const WCHAR fmt[] = { '%', 'd', 0 };
    int i;

    TRACE("\n");

    for (i = 3; i >= 0; i--) {
	const IPPART_INFO* part = &infoPtr->Part[i];
        int value = ip_address & 0xff;
	if ( (value >= part->LowerLimit) && (value <= part->UpperLimit) ) {
	    wsprintfW (buf, fmt, value);
	    SetWindowTextW (part->EditHwnd, buf);
	    IPADDRESS_Notify (infoPtr, EN_CHANGE);
        }
        ip_address >>= 8;
    }

    return TRUE;
}

__attribute__((used)) static void IPADDRESS_SetFocusToField (const IPADDRESS_INFO *infoPtr, INT index)
{
    TRACE("(index=%d)\n", index);

    if (index > 3 || index < 0) index=0;

    SetFocus (infoPtr->Part[index].EditHwnd);
}

__attribute__((used)) static BOOL IPADDRESS_ConstrainField (const IPADDRESS_INFO *infoPtr, int currentfield)
{
    static const WCHAR fmt[] = { '%', 'd', 0 };
    const IPPART_INFO *part;
    int curValue, newValue;
    WCHAR field[10];

    TRACE("(currentfield=%d)\n", currentfield);

    if (currentfield < 0 || currentfield > 3) return FALSE;

    part = &infoPtr->Part[currentfield];
    if (!GetWindowTextW (part->EditHwnd, field, 4)) return FALSE;

    curValue = atoiW(field);
    TRACE("  curValue=%d\n", curValue);

    newValue = IPADDRESS_IPNotify(infoPtr, currentfield, curValue);
    TRACE("  newValue=%d\n", newValue);

    if (newValue < part->LowerLimit) newValue = part->LowerLimit;
    if (newValue > part->UpperLimit) newValue = part->UpperLimit;

    if (newValue == curValue) return FALSE;

    wsprintfW (field, fmt, newValue);
    TRACE("  field=%s\n", debugstr_w(field));
    return SetWindowTextW (part->EditHwnd, field);
}

__attribute__((used)) static BOOL IPADDRESS_GotoNextField (const IPADDRESS_INFO *infoPtr, int cur, int sel)
{
    TRACE("\n");

    if(cur >= -1 && cur < 4) {
	IPADDRESS_ConstrainField(infoPtr, cur);

	if(cur < 3) {
	    const IPPART_INFO *next = &infoPtr->Part[cur + 1];
	    int start = 0, end = 0;
            SetFocus (next->EditHwnd);
	    if (sel != POS_DEFAULT) {
		if (sel == POS_RIGHT)
		    start = end = GetWindowTextLengthW(next->EditHwnd);
		else if (sel == POS_SELALL)
		    end = -1;
	        SendMessageW(next->EditHwnd, EM_SETSEL, start, end);
	    }
	    return TRUE;
	}

    }
    return FALSE;
}

