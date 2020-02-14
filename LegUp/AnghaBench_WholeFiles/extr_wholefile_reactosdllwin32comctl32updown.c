#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_3__ ;
typedef  struct TYPE_32__   TYPE_2__ ;
typedef  struct TYPE_31__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  txt ;
typedef  int WPARAM ;
typedef  scalar_t__ WCHAR ;
struct TYPE_32__ {scalar_t__ BuddyType; int MaxVal; int MinVal; int CurVal; int dwStyle; int Flags; int Base; int /*<<< orphan*/  Self; TYPE_1__* AccelVect; scalar_t__ AccelCount; int /*<<< orphan*/  Buddy; } ;
typedef  TYPE_2__ UPDOWN_INFO ;
struct TYPE_33__ {int left; int right; int bottom; int top; } ;
struct TYPE_31__ {int nInc; } ;
typedef  TYPE_3__ RECT ;
typedef  int /*<<< orphan*/  POINT ;
typedef  int /*<<< orphan*/  PAINTSTRUCT ;
typedef  int LRESULT ;
typedef  int INT ;
typedef  scalar_t__ HTHEME ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int BOOL ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 int /*<<< orphan*/  AUTOPRESS_DELAY ; 
 int BF_BOTTOM ; 
 int BF_LEFT ; 
 int BF_RIGHT ; 
 int BF_TOP ; 
 scalar_t__ BUDDY_TYPE_EDIT ; 
 scalar_t__ BUDDY_TYPE_LISTBOX ; 
 int /*<<< orphan*/  BeginPaint (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int DEFAULT_BUDDYBORDER ; 
 int DEFAULT_BUDDYBORDER_THEMED ; 
 int DEFAULT_BUDDYSPACER ; 
 int DEFAULT_BUDDYSPACER_THEMED ; 
 int DFCS_HOT ; 
 int DFCS_INACTIVE ; 
 int DFCS_PUSHED ; 
 int DFCS_SCROLLDOWN ; 
 int DFCS_SCROLLLEFT ; 
 int DFCS_SCROLLRIGHT ; 
 int DFCS_SCROLLUP ; 
 int /*<<< orphan*/  DFC_SCROLL ; 
 int DNS_DISABLED ; 
 int DNS_HOT ; 
 int DNS_NORMAL ; 
 int DNS_PRESSED ; 
 int /*<<< orphan*/  DrawEdge (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DrawFrameControl (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DrawThemeBackground (scalar_t__,int /*<<< orphan*/ ,int,int,TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EDGE_SUNKEN ; 
 int /*<<< orphan*/  EndPaint (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int FALSE ; 
 int FLAG_ARROW ; 
 int FLAG_BUDDYINT ; 
 int FLAG_DECR ; 
 int FLAG_INCR ; 
 int FLAG_MOUSEIN ; 
 int FLAG_PRESSED ; 
 int GET_WHEEL_DELTA_WPARAM (int) ; 
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int GetLocaleInfoW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,int) ; 
 int /*<<< orphan*/  GetWindowRect (int /*<<< orphan*/ ,TYPE_3__*) ; 
 scalar_t__ GetWindowTextW (int /*<<< orphan*/ ,scalar_t__*,int) ; 
 scalar_t__ GetWindowTheme (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InflateRect (TYPE_3__*,int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  InvalidateRect (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 scalar_t__ IsThemeBackgroundPartiallyTransparent (scalar_t__,int,int) ; 
 scalar_t__ IsWindow (int /*<<< orphan*/ ) ; 
 scalar_t__ LB_ERR ; 
 int /*<<< orphan*/  LB_GETCARETINDEX ; 
 int /*<<< orphan*/  LB_SETCURSEL ; 
 int /*<<< orphan*/  LOCALE_STHOUSAND ; 
 int /*<<< orphan*/  LOCALE_USER_DEFAULT ; 
 int MK_CONTROL ; 
 int MK_SHIFT ; 
 int /*<<< orphan*/  MapWindowPoints (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 scalar_t__ PtInRect (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int SPNP_DOWN ; 
 int SPNP_DOWNHORZ ; 
 int SPNP_UP ; 
 int SPNP_UPHORZ ; 
 scalar_t__ SendMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetTimer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int SetWindowTextW (int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  TIMER_AUTOPRESS ; 
 int /*<<< orphan*/  TRACE (char*,int,...) ; 
 int TRUE ; 
 int UDS_ALIGNLEFT ; 
 int UDS_ALIGNRIGHT ; 
 int UDS_HORZ ; 
 int UDS_HOTTRACK ; 
 int UDS_NOTHOUSANDS ; 
 int UDS_WRAP ; 
 int /*<<< orphan*/  UPDOWN_DoAction (TYPE_2__*,int,int) ; 
 int VK_DOWN ; 
 int VK_UP ; 
 int WHEEL_DELTA ; 
 int WS_DISABLED ; 
 int abs (int) ; 
 scalar_t__ lstrcmpiW (scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__*,int) ; 
 int strtolW (scalar_t__*,scalar_t__**,int) ; 
 int wsprintfW (scalar_t__*,scalar_t__ const*,int) ; 

__attribute__((used)) static inline BOOL UPDOWN_IsBuddyEdit(const UPDOWN_INFO *infoPtr)
{
    return infoPtr->BuddyType == BUDDY_TYPE_EDIT;
}

__attribute__((used)) static inline BOOL UPDOWN_IsBuddyListbox(const UPDOWN_INFO *infoPtr)
{
    return infoPtr->BuddyType == BUDDY_TYPE_LISTBOX;
}

__attribute__((used)) static BOOL UPDOWN_InBounds(const UPDOWN_INFO *infoPtr, int val)
{
    if(infoPtr->MaxVal > infoPtr->MinVal)
        return (infoPtr->MinVal <= val) && (val <= infoPtr->MaxVal);
    else
        return (infoPtr->MaxVal <= val) && (val <= infoPtr->MinVal);
}

__attribute__((used)) static BOOL UPDOWN_OffsetVal(UPDOWN_INFO *infoPtr, int delta)
{
    /* check if we can do the modification first */
    if(!UPDOWN_InBounds (infoPtr, infoPtr->CurVal+delta)) {
        if (infoPtr->dwStyle & UDS_WRAP) {
            delta += (delta < 0 ? -1 : 1) *
		     (infoPtr->MaxVal < infoPtr->MinVal ? -1 : 1) *
		     (infoPtr->MinVal - infoPtr->MaxVal) +
		     (delta < 0 ? 1 : -1);
        } else if ((infoPtr->MaxVal > infoPtr->MinVal && infoPtr->CurVal+delta > infoPtr->MaxVal)
                || (infoPtr->MaxVal < infoPtr->MinVal && infoPtr->CurVal+delta < infoPtr->MaxVal)) {
            delta = infoPtr->MaxVal - infoPtr->CurVal;
        } else {
            delta = infoPtr->MinVal - infoPtr->CurVal;
        }
    }

    infoPtr->CurVal += delta;
    return delta != 0;
}

__attribute__((used)) static BOOL UPDOWN_HasBuddyBorder(const UPDOWN_INFO *infoPtr)
{
    return  ( ((infoPtr->dwStyle & (UDS_ALIGNLEFT | UDS_ALIGNRIGHT)) != 0) &&
	      UPDOWN_IsBuddyEdit(infoPtr) );
}

__attribute__((used)) static void UPDOWN_GetArrowRect (const UPDOWN_INFO* infoPtr, RECT *rect, int arrow)
{
    HTHEME theme = GetWindowTheme (infoPtr->Self);
    const int border = theme ? DEFAULT_BUDDYBORDER_THEMED : DEFAULT_BUDDYBORDER;
    const int spacer = theme ? DEFAULT_BUDDYSPACER_THEMED : DEFAULT_BUDDYSPACER;
    GetClientRect (infoPtr->Self, rect);

    /*
     * Make sure we calculate the rectangle to fit even if we draw the
     * border.
     */
    if (UPDOWN_HasBuddyBorder(infoPtr)) {
        if (infoPtr->dwStyle & UDS_ALIGNLEFT)
            rect->left += border;
        else
            rect->right -= border;

        InflateRect(rect, 0, -border);
    }

    /* now figure out if we need a space away from the buddy */
    if (IsWindow(infoPtr->Buddy) ) {
	if (infoPtr->dwStyle & UDS_ALIGNLEFT) rect->right -= spacer;
	else if (infoPtr->dwStyle & UDS_ALIGNRIGHT) rect->left += spacer;
    }

    /*
     * We're calculating the midpoint to figure-out where the
     * separation between the buttons will lay. We make sure that we
     * round the uneven numbers by adding 1.
     */
    if (infoPtr->dwStyle & UDS_HORZ) {
        int len = rect->right - rect->left + 1; /* compute the width */
        if (arrow & FLAG_INCR)
            rect->left = rect->left + len/2;
        if (arrow & FLAG_DECR)
            rect->right =  rect->left + len/2 - (theme ? 0 : 1);
    } else {
        int len = rect->bottom - rect->top + 1; /* compute the height */
        if (arrow & FLAG_INCR)
            rect->bottom =  rect->top + len/2 - (theme ? 0 : 1);
        if (arrow & FLAG_DECR)
            rect->top =  rect->top + len/2;
    }
}

__attribute__((used)) static INT UPDOWN_GetArrowFromPoint (const UPDOWN_INFO *infoPtr, RECT *rect, POINT pt)
{
    UPDOWN_GetArrowRect (infoPtr, rect, FLAG_INCR);
    if(PtInRect(rect, pt)) return FLAG_INCR;

    UPDOWN_GetArrowRect (infoPtr, rect, FLAG_DECR);
    if(PtInRect(rect, pt)) return FLAG_DECR;

    return 0;
}

__attribute__((used)) static WCHAR UPDOWN_GetThousandSep(void)
{
    WCHAR sep[2];

    if(GetLocaleInfoW(LOCALE_USER_DEFAULT, LOCALE_STHOUSAND, sep, 2) != 1)
        sep[0] = ',';

    return sep[0];
}

__attribute__((used)) static BOOL UPDOWN_GetBuddyInt (UPDOWN_INFO *infoPtr)
{
    WCHAR txt[20], sep, *src, *dst;
    int newVal;

    if (!((infoPtr->Flags & FLAG_BUDDYINT) && IsWindow(infoPtr->Buddy)))
        return FALSE;

    /*if the buddy is a list window, we must set curr index */
    if (UPDOWN_IsBuddyListbox(infoPtr)) {
        newVal = SendMessageW(infoPtr->Buddy, LB_GETCARETINDEX, 0, 0);
        if(newVal < 0) return FALSE;
    } else {
        /* we have a regular window, so will get the text */
        /* note that a zero-length string is a legitimate value for 'txt',
         * and ought to result in a successful conversion to '0'. */
        if (GetWindowTextW(infoPtr->Buddy, txt, ARRAY_SIZE(txt)) < 0)
            return FALSE;

        sep = UPDOWN_GetThousandSep();

        /* now get rid of the separators */
        for(src = dst = txt; *src; src++)
            if(*src != sep) *dst++ = *src;
        *dst = 0;

        /* try to convert the number and validate it */
        newVal = strtolW(txt, &src, infoPtr->Base);
        if(*src || !UPDOWN_InBounds (infoPtr, newVal)) return FALSE;
    }

    TRACE("new value(%d) from buddy (old=%d)\n", newVal, infoPtr->CurVal);
    infoPtr->CurVal = newVal;
    return TRUE;
}

__attribute__((used)) static BOOL UPDOWN_SetBuddyInt (const UPDOWN_INFO *infoPtr)
{
    static const WCHAR fmt_hex[] = { '0', 'x', '%', '0', '4', 'X', 0 };
    static const WCHAR fmt_dec_oct[] = { '%', 'd', '\0' };
    const WCHAR *fmt;
    WCHAR txt[20], txt_old[20] = { 0 };
    int len;

    if (!((infoPtr->Flags & FLAG_BUDDYINT) && IsWindow(infoPtr->Buddy)))
        return FALSE;

    TRACE("set new value(%d) to buddy.\n", infoPtr->CurVal);

    /*if the buddy is a list window, we must set curr index */
    if (UPDOWN_IsBuddyListbox(infoPtr)) {
        return SendMessageW(infoPtr->Buddy, LB_SETCURSEL, infoPtr->CurVal, 0) != LB_ERR;
    }

    /* Regular window, so set caption to the number */
    fmt = (infoPtr->Base == 16) ? fmt_hex : fmt_dec_oct;
    len = wsprintfW(txt, fmt, infoPtr->CurVal);


    /* Do thousands separation if necessary */
    if ((infoPtr->Base == 10) && !(infoPtr->dwStyle & UDS_NOTHOUSANDS) && (len > 3)) {
        WCHAR tmp[ARRAY_SIZE(txt)], *src = tmp, *dst = txt;
        WCHAR sep = UPDOWN_GetThousandSep();
	int start = len % 3;

	memcpy(tmp, txt, sizeof(txt));
	if (start == 0) start = 3;
	dst += start;
	src += start;
        for (len=0; *src; len++) {
	    if (len % 3 == 0) *dst++ = sep;
	    *dst++ = *src++;
        }
        *dst = 0;
    }

    /* if nothing changed exit earlier */
    GetWindowTextW(infoPtr->Buddy, txt_old, ARRAY_SIZE(txt_old));
    if (lstrcmpiW(txt_old, txt) == 0) return FALSE;

    return SetWindowTextW(infoPtr->Buddy, txt);
}

__attribute__((used)) static BOOL UPDOWN_DrawBuddyBackground (const UPDOWN_INFO *infoPtr, HDC hdc)
{
    RECT br, r;
    HTHEME buddyTheme = GetWindowTheme (infoPtr->Buddy);
    if (!buddyTheme) return FALSE;

    GetWindowRect (infoPtr->Buddy, &br);
    MapWindowPoints (NULL, infoPtr->Self, (POINT*)&br, 2);
    GetClientRect (infoPtr->Self, &r);

    if (infoPtr->dwStyle & UDS_ALIGNLEFT)
        br.left = r.left;
    else if (infoPtr->dwStyle & UDS_ALIGNRIGHT)
        br.right = r.right;
    /* FIXME: take disabled etc. into account */
    DrawThemeBackground (buddyTheme, hdc, 0, 0, &br, NULL);
    return TRUE;
}

__attribute__((used)) static LRESULT UPDOWN_Draw (const UPDOWN_INFO *infoPtr, HDC hdc)
{
    BOOL uPressed, uHot, dPressed, dHot;
    RECT rect;
    HTHEME theme = GetWindowTheme (infoPtr->Self);
    int uPart = 0, uState = 0, dPart = 0, dState = 0;
    BOOL needBuddyBg = FALSE;

    uPressed = (infoPtr->Flags & FLAG_PRESSED) && (infoPtr->Flags & FLAG_INCR);
    uHot = (infoPtr->Flags & FLAG_INCR) && (infoPtr->Flags & FLAG_MOUSEIN);
    dPressed = (infoPtr->Flags & FLAG_PRESSED) && (infoPtr->Flags & FLAG_DECR);
    dHot = (infoPtr->Flags & FLAG_DECR) && (infoPtr->Flags & FLAG_MOUSEIN);
    if (theme) {
        uPart = (infoPtr->dwStyle & UDS_HORZ) ? SPNP_UPHORZ : SPNP_UP;
        uState = (infoPtr->dwStyle & WS_DISABLED) ? DNS_DISABLED 
            : (uPressed ? DNS_PRESSED : (uHot ? DNS_HOT : DNS_NORMAL));
        dPart = (infoPtr->dwStyle & UDS_HORZ) ? SPNP_DOWNHORZ : SPNP_DOWN;
        dState = (infoPtr->dwStyle & WS_DISABLED) ? DNS_DISABLED 
            : (dPressed ? DNS_PRESSED : (dHot ? DNS_HOT : DNS_NORMAL));
        needBuddyBg = IsWindow (infoPtr->Buddy)
            && (IsThemeBackgroundPartiallyTransparent (theme, uPart, uState)
              || IsThemeBackgroundPartiallyTransparent (theme, dPart, dState));
    }

    /* Draw the common border between ourselves and our buddy */
    if (UPDOWN_HasBuddyBorder(infoPtr) || needBuddyBg) {
        if (!theme || !UPDOWN_DrawBuddyBackground (infoPtr, hdc)) {
            GetClientRect(infoPtr->Self, &rect);
	    DrawEdge(hdc, &rect, EDGE_SUNKEN,
		     BF_BOTTOM | BF_TOP |
		     (infoPtr->dwStyle & UDS_ALIGNLEFT ? BF_LEFT : BF_RIGHT));
        }
    }

    /* Draw the incr button */
    UPDOWN_GetArrowRect (infoPtr, &rect, FLAG_INCR);
    if (theme) {
        DrawThemeBackground(theme, hdc, uPart, uState, &rect, NULL);
    } else {
        DrawFrameControl(hdc, &rect, DFC_SCROLL,
            (infoPtr->dwStyle & UDS_HORZ ? DFCS_SCROLLRIGHT : DFCS_SCROLLUP) |
            ((infoPtr->dwStyle & UDS_HOTTRACK) && uHot ? DFCS_HOT : 0) |
            (uPressed ? DFCS_PUSHED : 0) |
            (infoPtr->dwStyle & WS_DISABLED ? DFCS_INACTIVE : 0) );
    }

    /* Draw the decr button */
    UPDOWN_GetArrowRect(infoPtr, &rect, FLAG_DECR);
    if (theme) {
        DrawThemeBackground(theme, hdc, dPart, dState, &rect, NULL);
    } else {
        DrawFrameControl(hdc, &rect, DFC_SCROLL,
            (infoPtr->dwStyle & UDS_HORZ ? DFCS_SCROLLLEFT : DFCS_SCROLLDOWN) |
            ((infoPtr->dwStyle & UDS_HOTTRACK) && dHot ? DFCS_HOT : 0) |
            (dPressed ? DFCS_PUSHED : 0) |
            (infoPtr->dwStyle & WS_DISABLED ? DFCS_INACTIVE : 0) );
    }

    return 0;
}

__attribute__((used)) static LRESULT UPDOWN_Paint (const UPDOWN_INFO *infoPtr, HDC hdc)
{
    PAINTSTRUCT ps;
    if (hdc) return UPDOWN_Draw (infoPtr, hdc);
    hdc = BeginPaint (infoPtr->Self, &ps);
    UPDOWN_Draw (infoPtr, hdc);
    EndPaint (infoPtr->Self, &ps);
    return 0;
}

__attribute__((used)) static LRESULT UPDOWN_KeyPressed(UPDOWN_INFO *infoPtr, int key)
{
    int arrow, accel;

    if (key == VK_UP) arrow = FLAG_INCR;
    else if (key == VK_DOWN) arrow = FLAG_DECR;
    else return 1;

    UPDOWN_GetBuddyInt (infoPtr);
    infoPtr->Flags &= ~FLAG_ARROW;
    infoPtr->Flags |= FLAG_PRESSED | arrow;
    InvalidateRect (infoPtr->Self, NULL, FALSE);
    SetTimer(infoPtr->Self, TIMER_AUTOPRESS, AUTOPRESS_DELAY, 0);
    accel = (infoPtr->AccelCount && infoPtr->AccelVect) ? infoPtr->AccelVect[0].nInc : 1;
    UPDOWN_DoAction (infoPtr, accel, arrow);
    return 0;
}

__attribute__((used)) static int UPDOWN_GetPos(UPDOWN_INFO *infoPtr, BOOL *err)
{
    BOOL succ = UPDOWN_GetBuddyInt(infoPtr);
    int val = infoPtr->CurVal;

    if(!UPDOWN_InBounds(infoPtr, val)) {
        if((infoPtr->MinVal < infoPtr->MaxVal && val < infoPtr->MinVal)
                || (infoPtr->MinVal > infoPtr->MaxVal && val > infoPtr->MinVal))
            val = infoPtr->MinVal;
        else
            val = infoPtr->MaxVal;

        succ = FALSE;
    }

    if(err) *err = !succ;
    return val;
}

__attribute__((used)) static int UPDOWN_SetPos(UPDOWN_INFO *infoPtr, int pos)
{
    int ret = infoPtr->CurVal;

    if(!UPDOWN_InBounds(infoPtr, pos)) {
        if((infoPtr->MinVal < infoPtr->MaxVal && pos < infoPtr->MinVal)
                || (infoPtr->MinVal > infoPtr->MaxVal && pos > infoPtr->MinVal))
            pos = infoPtr->MinVal;
        else
            pos = infoPtr->MaxVal;
    }

    infoPtr->CurVal = pos;
    UPDOWN_SetBuddyInt(infoPtr);

    if(!UPDOWN_InBounds(infoPtr, ret)) {
        if((infoPtr->MinVal < infoPtr->MaxVal && ret < infoPtr->MinVal)
                || (infoPtr->MinVal > infoPtr->MaxVal && ret > infoPtr->MinVal))
            ret = infoPtr->MinVal;
        else
            ret = infoPtr->MaxVal;
    }
    return ret;
}

__attribute__((used)) static LRESULT UPDOWN_SetRange(UPDOWN_INFO *infoPtr, INT Max, INT Min)
{
    infoPtr->MaxVal = Max;
    infoPtr->MinVal = Min;

    TRACE("UpDown Ctrl new range(%d to %d), hwnd=%p\n",
           infoPtr->MinVal, infoPtr->MaxVal, infoPtr->Self);

    return 0;
}

__attribute__((used)) static LRESULT UPDOWN_MouseWheel(UPDOWN_INFO *infoPtr, WPARAM wParam)
{
    int iWheelDelta = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA;

    if (wParam & (MK_SHIFT | MK_CONTROL))
        return 0;

    if (iWheelDelta != 0)
    {
        UPDOWN_GetBuddyInt(infoPtr);
        UPDOWN_DoAction(infoPtr, abs(iWheelDelta), iWheelDelta > 0 ? FLAG_INCR : FLAG_DECR);
    }

    return 1;
}

