#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_64__   TYPE_9__ ;
typedef  struct TYPE_63__   TYPE_8__ ;
typedef  struct TYPE_62__   TYPE_7__ ;
typedef  struct TYPE_61__   TYPE_6__ ;
typedef  struct TYPE_60__   TYPE_5__ ;
typedef  struct TYPE_59__   TYPE_4__ ;
typedef  struct TYPE_58__   TYPE_3__ ;
typedef  struct TYPE_57__   TYPE_2__ ;
typedef  struct TYPE_56__   TYPE_1__ ;
typedef  struct TYPE_55__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  si ;
typedef  int /*<<< orphan*/  sbi ;
typedef  enum SCROLL_HITTEST { ____Placeholder_SCROLL_HITTEST } SCROLL_HITTEST ;
typedef  int WPARAM ;
typedef  int UINT ;
struct TYPE_57__ {int top; int left; } ;
struct TYPE_56__ {int top; int left; } ;
struct TYPE_58__ {int dwStyle; TYPE_2__ rcWindow; TYPE_1__ rcClient; } ;
struct TYPE_64__ {scalar_t__ hWnd; TYPE_3__ wi; int /*<<< orphan*/  hDC; int /*<<< orphan*/  scrolltheme; } ;
struct TYPE_63__ {scalar_t__ x; scalar_t__ y; } ;
struct TYPE_62__ {int SCROLL_TrackingPos; int SCROLL_MovingThumb; int SCROLL_trackHitTest; int SCROLL_TrackingBar; int SCROLL_TrackingVal; scalar_t__ SCROLL_TrackingWin; void* SCROLL_trackVertical; } ;
struct TYPE_61__ {int left; int top; int right; int bottom; } ;
struct TYPE_60__ {scalar_t__ dxyLineButton; scalar_t__ xyThumbTop; scalar_t__ xyThumbBottom; int* rgstate; int cbSize; TYPE_6__ rcScrollBar; } ;
struct TYPE_59__ {int cbSize; int nMin; int nPage; int nMax; void* fMask; } ;
struct TYPE_55__ {int const message; scalar_t__ wParam; int /*<<< orphan*/  lParam; } ;
typedef  TYPE_4__ SCROLLINFO ;
typedef  TYPE_5__ SCROLLBARINFO ;
typedef  TYPE_6__ RECT ;
typedef  TYPE_7__* PWND_DATA ;
typedef  TYPE_8__ POINT ;
typedef  TYPE_9__* PDRAW_CONTEXT ;
typedef  TYPE_10__ MSG ;
typedef  TYPE_6__* LPRECT ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int INT ;
typedef  scalar_t__ HWND ;
typedef  TYPE_9__ DRAW_CONTEXT ;
typedef  void* BOOL ;

/* Variables and functions */
 int ABS_DOWNNORMAL ; 
 int ABS_LEFTNORMAL ; 
 int ABS_RIGHTNORMAL ; 
 int ABS_UPNORMAL ; 
 scalar_t__ BUTTON_DISABLED ; 
 scalar_t__ BUTTON_HOT ; 
 int BUTTON_NORMAL ; 
 scalar_t__ BUTTON_PRESSED ; 
 scalar_t__ CallMsgFilterW (TYPE_10__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ClientToScreen (scalar_t__,TYPE_8__*) ; 
 int /*<<< orphan*/  DispatchMessageW (TYPE_10__*) ; 
 int /*<<< orphan*/  DrawThemeBackground (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,TYPE_6__*,int /*<<< orphan*/ *) ; 
 void* FALSE ; 
 int GET_X_LPARAM (int /*<<< orphan*/ ) ; 
 int GET_Y_LPARAM (int /*<<< orphan*/ ) ; 
 scalar_t__ GetCapture () ; 
 scalar_t__ GetFocus () ; 
 int /*<<< orphan*/  GetMessageW (TYPE_10__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ GetParent (scalar_t__) ; 
 int /*<<< orphan*/  GetScrollBarInfo (scalar_t__,int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  GetScrollInfo (scalar_t__,int,TYPE_4__*) ; 
 int GetSystemMetrics (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowRect (scalar_t__,TYPE_6__*) ; 
 int HTHSCROLL ; 
 int HTVSCROLL ; 
 int /*<<< orphan*/  HideCaret (scalar_t__) ; 
 scalar_t__ IsRectEmpty (TYPE_6__*) ; 
 int /*<<< orphan*/  IsWindow (scalar_t__) ; 
 int /*<<< orphan*/  KillSystemTimer (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  MAKEWPARAM (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MSGF_SCROLLBAR ; 
 int MulDiv (int,int,int) ; 
 int /*<<< orphan*/  OBJID_HSCROLL ; 
 int /*<<< orphan*/  OBJID_VSCROLL ; 
 int /*<<< orphan*/  OffsetRect (TYPE_6__*,int,int) ; 
 void* PtInRect (TYPE_6__*,TYPE_8__) ; 
 int /*<<< orphan*/  ReleaseCapture () ; 
 int SBP_ARROWBTN ; 
 int SBP_GRIPPERHORZ ; 
 int SBP_GRIPPERVERT ; 
 int SBP_LOWERTRACKHORZ ; 
 int SBP_LOWERTRACKVERT ; 
 int SBP_THUMBBTNHORZ ; 
 int SBP_THUMBBTNVERT ; 
 int SBP_UPPERTRACKHORZ ; 
 int SBP_UPPERTRACKVERT ; 
 int SB_CTL ; 
 int /*<<< orphan*/  SB_ENDSCROLL ; 
#define  SB_HORZ 139 
 int /*<<< orphan*/  SB_LINEDOWN ; 
 int /*<<< orphan*/  SB_LINEUP ; 
 int /*<<< orphan*/  SB_PAGEDOWN ; 
 int /*<<< orphan*/  SB_PAGEUP ; 
 int /*<<< orphan*/  SB_THUMBPOSITION ; 
 int /*<<< orphan*/  SB_THUMBTRACK ; 
#define  SB_VERT 138 
 int SCROLL_ARROW_THUMB_OVERLAP ; 
#define  SCROLL_BOTTOM_ARROW 137 
#define  SCROLL_BOTTOM_RECT 136 
 int /*<<< orphan*/  SCROLL_FIRST_DELAY ; 
 int SCROLL_MIN_THUMB ; 
#define  SCROLL_NOWHERE 135 
 int /*<<< orphan*/  SCROLL_REPEAT_DELAY ; 
#define  SCROLL_THUMB 134 
 scalar_t__ SCROLL_TIMER ; 
#define  SCROLL_TOP_ARROW 133 
#define  SCROLL_TOP_RECT 132 
 int SC_HSCROLL ; 
 void* SIF_ALL ; 
 int /*<<< orphan*/  SM_CXVSCROLL ; 
 int STATE_SYSTEM_UNAVAILABLE ; 
 int /*<<< orphan*/  SendMessageW (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetCapture (scalar_t__) ; 
 int /*<<< orphan*/  SetSystemTimer (scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ShowCaret (scalar_t__) ; 
 void* TRUE ; 
 int /*<<< orphan*/  ThemeCleanupDrawContext (TYPE_9__*) ; 
 TYPE_7__* ThemeGetWndData (scalar_t__) ; 
 int /*<<< orphan*/  ThemeInitDrawContext (TYPE_9__*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TranslateMessage (TYPE_10__*) ; 
 int /*<<< orphan*/  WM_HSCROLL ; 
#define  WM_LBUTTONDOWN 131 
#define  WM_LBUTTONUP 130 
#define  WM_MOUSEMOVE 129 
#define  WM_SYSTIMER 128 
 int /*<<< orphan*/  WM_VSCROLL ; 
 int WS_HSCROLL ; 
 int WS_VSCROLL ; 
 int /*<<< orphan*/  assert (void*) ; 
 int max (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void ScreenToWindow( HWND hWnd, POINT* pt)
{
    RECT rcWnd;
    GetWindowRect(hWnd, &rcWnd);
    pt->x -= rcWnd.left;
    pt->y -= rcWnd.top;
}

__attribute__((used)) static BOOL SCROLL_IsVertical(HWND hwnd, INT nBar)
{
    switch(nBar)
    {
    case SB_HORZ:
        return FALSE;
    case SB_VERT:
        return TRUE;
    default:
        assert(FALSE);
        return FALSE;
    }
}

__attribute__((used)) static LONG SCROLL_getObjectId(INT nBar)
{
    switch(nBar)
    {
    case SB_HORZ:
        return OBJID_HSCROLL;
    case SB_VERT:
        return OBJID_VSCROLL;
    default:
        assert(FALSE);
        return 0;
    }
}

__attribute__((used)) static BOOL SCROLL_PtInRectEx( LPRECT lpRect, POINT pt, BOOL vertical )
{
    RECT rect = *lpRect;
    int scrollbarWidth;

    /* Pad hit rect to allow mouse to be dragged outside of scrollbar and
     * still be considered in the scrollbar. */
    if (vertical)
    {
        scrollbarWidth = lpRect->right - lpRect->left;
        rect.left -= scrollbarWidth*8;
        rect.right += scrollbarWidth*8;
        rect.top -= scrollbarWidth*2;
        rect.bottom += scrollbarWidth*2;
    }
    else
    {
        scrollbarWidth = lpRect->bottom - lpRect->top;
        rect.left -= scrollbarWidth*2;
        rect.right += scrollbarWidth*2;
        rect.top -= scrollbarWidth*8;
        rect.bottom += scrollbarWidth*8;
    }
    return PtInRect( &rect, pt );
}

__attribute__((used)) static enum SCROLL_HITTEST SCROLL_HitTest( HWND hwnd, SCROLLBARINFO* psbi, BOOL vertical,
                                           POINT pt, BOOL bDragging )
{
    if ( (bDragging && !SCROLL_PtInRectEx( &psbi->rcScrollBar, pt, vertical )) ||
	     (!PtInRect( &psbi->rcScrollBar, pt )) ) 
    {
         return SCROLL_NOWHERE;
    }

    if (vertical)
    {
        if (pt.y < psbi->rcScrollBar.top + psbi->dxyLineButton) 
            return SCROLL_TOP_ARROW;
        if (pt.y >= psbi->rcScrollBar.bottom - psbi->dxyLineButton) 
            return SCROLL_BOTTOM_ARROW;
        if (!psbi->xyThumbTop) 
            return SCROLL_TOP_RECT;
        pt.y -= psbi->rcScrollBar.top;
        if (pt.y < psbi->xyThumbTop) 
            return SCROLL_TOP_RECT;
        if (pt.y >= psbi->xyThumbBottom) 
            return SCROLL_BOTTOM_RECT;
    }
    else  /* horizontal */
    {
        if (pt.x < psbi->rcScrollBar.left + psbi->dxyLineButton)
            return SCROLL_TOP_ARROW;
        if (pt.x >= psbi->rcScrollBar.right - psbi->dxyLineButton) 
            return SCROLL_BOTTOM_ARROW;
        if (!psbi->xyThumbTop) 
            return SCROLL_TOP_RECT;
        pt.x -= psbi->rcScrollBar.left;
        if (pt.x < psbi->xyThumbTop) 
            return SCROLL_TOP_RECT;
        if (pt.x >= psbi->xyThumbBottom) 
            return SCROLL_BOTTOM_RECT;
    }
    return SCROLL_THUMB;
}

__attribute__((used)) static void SCROLL_ThemeDrawPart(PDRAW_CONTEXT pcontext, int iPartId,int iStateId,  SCROLLBARINFO* psbi, int htCurrent, int htDown, int htHot, RECT* r)
{
    if (r->right <= r->left || r->bottom <= r->top)
        return;

    if(psbi->rgstate[htCurrent] & STATE_SYSTEM_UNAVAILABLE)
        iStateId += BUTTON_DISABLED - BUTTON_NORMAL;
    else if (htHot == htCurrent)
        iStateId += BUTTON_HOT - BUTTON_NORMAL;
    else if (htDown == htCurrent)
        iStateId += BUTTON_PRESSED - BUTTON_NORMAL;

    DrawThemeBackground(pcontext->scrolltheme, pcontext->hDC, iPartId, iStateId, r, NULL);
}

__attribute__((used)) static void SCROLL_DrawArrows( PDRAW_CONTEXT pcontext, SCROLLBARINFO* psbi, 
                               BOOL vertical, int htDown, int htHot )
{
    RECT r;
    int iStateId;

    r = psbi->rcScrollBar;
    if( vertical )
    {
        r.bottom = r.top + psbi->dxyLineButton;
        iStateId = ABS_UPNORMAL;
    }
    else
    {
        r.right = r.left + psbi->dxyLineButton;
        iStateId = ABS_LEFTNORMAL;
    }
    
    SCROLL_ThemeDrawPart(pcontext, SBP_ARROWBTN, iStateId, psbi, SCROLL_TOP_ARROW, htDown, htHot, &r);
    
    r = psbi->rcScrollBar;
    if( vertical )
    {
        r.top = r.bottom - psbi->dxyLineButton;
        iStateId = ABS_DOWNNORMAL;
    }
    else
    {
        iStateId = ABS_RIGHTNORMAL;
        r.left = r.right - psbi->dxyLineButton;
    }

    SCROLL_ThemeDrawPart(pcontext, SBP_ARROWBTN, iStateId, psbi, SCROLL_BOTTOM_ARROW, htDown, htHot, &r);
}

__attribute__((used)) static void SCROLL_DrawInterior( PDRAW_CONTEXT pcontext, SCROLLBARINFO* psbi,
                                  INT thumbPos, BOOL vertical,
                                  int htDown, int htHot )
{
    RECT r, rcPart;

    /* thumbPos is relative to the edge of the scrollbar */

    r = psbi->rcScrollBar;
    if (vertical)
    {
        if (thumbPos)
            thumbPos += pcontext->wi.rcClient.top - pcontext->wi.rcWindow.top;
        r.top    += psbi->dxyLineButton;
        r.bottom -= (psbi->dxyLineButton);
    }
    else
    {
        if (thumbPos)
            thumbPos += pcontext->wi.rcClient.left - pcontext->wi.rcWindow.left;
        r.left  += psbi->dxyLineButton;
        r.right -= psbi->dxyLineButton;
    }

    if (r.right <= r.left || r.bottom <= r.top)
        return;

    /* Draw the scroll rectangles and thumb */

    if (!thumbPos)  /* No thumb to draw */
    {
        rcPart = r;
        SCROLL_ThemeDrawPart(pcontext, vertical ? SBP_UPPERTRACKVERT: SBP_UPPERTRACKHORZ , BUTTON_NORMAL, psbi, SCROLL_THUMB, 0, 0, &rcPart);
        return;
    }

    /* Some themes have different bitmaps for the upper and lower tracks  
       It seems that windows use the bitmap for the lower track in the upper track */
    if (vertical)
    { 
        rcPart = r;
        rcPart.bottom = thumbPos;
        SCROLL_ThemeDrawPart(pcontext, SBP_LOWERTRACKVERT, BUTTON_NORMAL, psbi, SCROLL_TOP_RECT, htDown, htHot, &rcPart);
        r.top = rcPart.bottom;

        rcPart = r;
        rcPart.top += psbi->xyThumbBottom - psbi->xyThumbTop;
        SCROLL_ThemeDrawPart(pcontext, SBP_UPPERTRACKVERT, BUTTON_NORMAL, psbi, SCROLL_BOTTOM_RECT, htDown, htHot, &rcPart); 
        r.bottom = rcPart.top;

        SCROLL_ThemeDrawPart(pcontext, SBP_THUMBBTNVERT, BUTTON_NORMAL, psbi, SCROLL_THUMB, htDown, htHot, &r); 
        SCROLL_ThemeDrawPart(pcontext, SBP_GRIPPERVERT, BUTTON_NORMAL, psbi, SCROLL_THUMB, htDown, htHot, &r); 
    }
    else  /* horizontal */
    {
        rcPart = r;
        rcPart.right = thumbPos;
        SCROLL_ThemeDrawPart(pcontext, SBP_LOWERTRACKHORZ, BUTTON_NORMAL, psbi, SCROLL_TOP_RECT, htDown, htHot, &rcPart);
        r.left = rcPart.right;

        rcPart = r;
        rcPart.left += psbi->xyThumbBottom - psbi->xyThumbTop;
        SCROLL_ThemeDrawPart(pcontext, SBP_UPPERTRACKHORZ, BUTTON_NORMAL, psbi, SCROLL_BOTTOM_RECT, htDown, htHot, &rcPart);
        r.right = rcPart.left;

        SCROLL_ThemeDrawPart(pcontext, SBP_THUMBBTNHORZ, BUTTON_NORMAL, psbi, SCROLL_THUMB, htDown, htHot, &r);
        SCROLL_ThemeDrawPart(pcontext, SBP_GRIPPERHORZ, BUTTON_NORMAL, psbi, SCROLL_THUMB, htDown, htHot, &r);
    }
}

__attribute__((used)) static void SCROLL_DrawMovingThumb(PWND_DATA pwndData, PDRAW_CONTEXT pcontext, SCROLLBARINFO* psbi,  BOOL vertical)
{
  INT pos = pwndData->SCROLL_TrackingPos;
  INT max_size;

  if( vertical )
      max_size = psbi->rcScrollBar.bottom - psbi->rcScrollBar.top;
  else
      max_size = psbi->rcScrollBar.right - psbi->rcScrollBar.left;

  max_size -= psbi->xyThumbBottom - psbi->xyThumbTop + psbi->dxyLineButton;

  if( pos < (psbi->dxyLineButton) )
    pos = (psbi->dxyLineButton);
  else if( pos > max_size )
    pos = max_size;

  SCROLL_DrawInterior(pcontext, psbi, pos, vertical, SCROLL_THUMB, 0);  

  pwndData->SCROLL_MovingThumb = !pwndData->SCROLL_MovingThumb;
}

void 
ThemeDrawScrollBar(PDRAW_CONTEXT pcontext, INT nBar, POINT* pt)
{
    SCROLLINFO si;
    SCROLLBARINFO sbi;
    BOOL vertical;
    enum SCROLL_HITTEST htHot = SCROLL_NOWHERE;
    PWND_DATA pwndData;

    if (((nBar == SB_VERT) && !(pcontext->wi.dwStyle & WS_VSCROLL)) ||
        ((nBar == SB_HORZ) && !(pcontext->wi.dwStyle & WS_HSCROLL))) return;

    if (!(pwndData = ThemeGetWndData(pcontext->hWnd)))
        return;

    if (pwndData->SCROLL_TrackingWin)
        return;

    /* Retrieve scrollbar info */
    sbi.cbSize = sizeof(sbi);
    si.cbSize = sizeof(si);
    si.fMask = SIF_ALL ;
    GetScrollInfo(pcontext->hWnd, nBar, &si);
    GetScrollBarInfo(pcontext->hWnd, SCROLL_getObjectId(nBar), &sbi);
    vertical = SCROLL_IsVertical(pcontext->hWnd, nBar);
    if(sbi.rgstate[SCROLL_TOP_ARROW] & STATE_SYSTEM_UNAVAILABLE  && 
       sbi.rgstate[SCROLL_BOTTOM_ARROW] & STATE_SYSTEM_UNAVAILABLE  )
    {
        sbi.xyThumbTop = 0;
    }

    /* The scrollbar rect is in screen coordinates */
    OffsetRect(&sbi.rcScrollBar, -pcontext->wi.rcWindow.left, -pcontext->wi.rcWindow.top);

    if(pt)
    {
        ScreenToWindow(pcontext->hWnd, pt);
        htHot = SCROLL_HitTest(pcontext->hWnd, &sbi, vertical, *pt, FALSE);
    }

    /* do not draw if the scrollbar rectangle is empty */
    if(IsRectEmpty(&sbi.rcScrollBar)) return;

    /* Draw the scrollbar */
    SCROLL_DrawArrows( pcontext, &sbi, vertical, 0, htHot );
	SCROLL_DrawInterior( pcontext, &sbi, sbi.xyThumbTop, vertical, 0, htHot );
}

__attribute__((used)) static POINT SCROLL_ClipPos( LPRECT lpRect, POINT pt )
{
    if( pt.x < lpRect->left )
	    pt.x = lpRect->left;
    else
        if( pt.x > lpRect->right )
	pt.x = lpRect->right;

    if( pt.y < lpRect->top )
	    pt.y = lpRect->top;
    else
    if( pt.y > lpRect->bottom )
	    pt.y = lpRect->bottom;

    return pt;
}

__attribute__((used)) static UINT SCROLL_GetThumbVal( SCROLLINFO *psi, RECT *rect,
                                  BOOL vertical, INT pos )
{
    INT thumbSize;
    INT pixels = vertical ? rect->bottom-rect->top : rect->right-rect->left;
    INT range;

    if ((pixels -= 2*(GetSystemMetrics(SM_CXVSCROLL) - SCROLL_ARROW_THUMB_OVERLAP)) <= 0)
        return psi->nMin;

    if (psi->nPage)
    {
        thumbSize = MulDiv(pixels,psi->nPage,(psi->nMax-psi->nMin+1));
        if (thumbSize < SCROLL_MIN_THUMB) thumbSize = SCROLL_MIN_THUMB;
    }
    else thumbSize = GetSystemMetrics(SM_CXVSCROLL);

    if ((pixels -= thumbSize) <= 0) return psi->nMin;

    pos = max( 0, pos - (GetSystemMetrics(SM_CXVSCROLL) - SCROLL_ARROW_THUMB_OVERLAP) );
    if (pos > pixels) pos = pixels;

    if (!psi->nPage)
        range = psi->nMax - psi->nMin;
    else
        range = psi->nMax - psi->nMin - psi->nPage + 1;

    return psi->nMin + MulDiv(pos, range, pixels);
}

__attribute__((used)) static void 
SCROLL_HandleScrollEvent(PWND_DATA pwndData, HWND hwnd, INT nBar, UINT msg, POINT pt)
{
      /* Previous mouse position for timer events */
    static POINT prevPt;
      /* Thumb position when tracking started. */
    static UINT trackThumbPos;
      /* Position in the scroll-bar of the last button-down event. */
    static INT lastClickPos;
      /* Position in the scroll-bar of the last mouse event. */
    static INT lastMousePos;

    enum SCROLL_HITTEST hittest;
    HWND hwndOwner, hwndCtl;
    BOOL vertical;
    SCROLLINFO si;
    SCROLLBARINFO sbi;
    DRAW_CONTEXT context;

    si.cbSize = sizeof(si);
    sbi.cbSize = sizeof(sbi);
    si.fMask = SIF_ALL;
    GetScrollInfo(hwnd, nBar, &si);
    GetScrollBarInfo(hwnd, SCROLL_getObjectId(nBar), &sbi);
    vertical = SCROLL_IsVertical(hwnd, nBar);
    if(sbi.rgstate[SCROLL_TOP_ARROW] & STATE_SYSTEM_UNAVAILABLE  && 
       sbi.rgstate[SCROLL_BOTTOM_ARROW] & STATE_SYSTEM_UNAVAILABLE  )
    {
        return;
    }

    if ((pwndData->SCROLL_trackHitTest == SCROLL_NOWHERE) && (msg != WM_LBUTTONDOWN))
		  return;
    
    ThemeInitDrawContext(&context, hwnd, 0);

    /* The scrollbar rect is in screen coordinates */
    OffsetRect(&sbi.rcScrollBar, -context.wi.rcWindow.left, -context.wi.rcWindow.top);

    hwndOwner = (nBar == SB_CTL) ? GetParent(hwnd) : hwnd;
    hwndCtl   = (nBar == SB_CTL) ? hwnd : 0;

    switch(msg)
    {
      case WM_LBUTTONDOWN:  /* Initialise mouse tracking */
          HideCaret(hwnd);  /* hide caret while holding down LBUTTON */
          pwndData->SCROLL_trackVertical = vertical;
          pwndData->SCROLL_trackHitTest  = hittest = SCROLL_HitTest( hwnd, &sbi, vertical, pt, FALSE );
          lastClickPos  = vertical ? (pt.y - sbi.rcScrollBar.top) : (pt.x - sbi.rcScrollBar.left);
          lastMousePos  = lastClickPos;
          trackThumbPos = sbi.xyThumbTop;
          prevPt = pt;
          SetCapture( hwnd );
          break;

      case WM_MOUSEMOVE:
          hittest = SCROLL_HitTest( hwnd, &sbi, vertical, pt, TRUE );
          prevPt = pt;
          break;

      case WM_LBUTTONUP:
          hittest = SCROLL_NOWHERE;
          ReleaseCapture();
          /* if scrollbar has focus, show back caret */
          if (hwnd==GetFocus()) 
              ShowCaret(hwnd);
          break;

      case WM_SYSTIMER:
          pt = prevPt;
          hittest = SCROLL_HitTest( hwnd, &sbi, vertical, pt, FALSE );
          break;

      default:
          return;  /* Should never happen */
    }

    //TRACE("Event: hwnd=%p bar=%d msg=%s pt=%d,%d hit=%d\n",
    //      hwnd, nBar, SPY_GetMsgName(msg,hwnd), pt.x, pt.y, hittest );

    switch(pwndData->SCROLL_trackHitTest)
    {
    case SCROLL_NOWHERE:  /* No tracking in progress */
        break;

    case SCROLL_TOP_ARROW:
        if (hittest == pwndData->SCROLL_trackHitTest)
        {
            SCROLL_DrawArrows( &context, &sbi, vertical, pwndData->SCROLL_trackHitTest, 0 );
            if ((msg == WM_LBUTTONDOWN) || (msg == WM_SYSTIMER))
            {
                SendMessageW( hwndOwner, vertical ? WM_VSCROLL : WM_HSCROLL,
                                SB_LINEUP, (LPARAM)hwndCtl );
	        }

        SetSystemTimer( hwnd, SCROLL_TIMER, (msg == WM_LBUTTONDOWN) ?
                            SCROLL_FIRST_DELAY : SCROLL_REPEAT_DELAY, NULL );
        }
        else
        {
            SCROLL_DrawArrows( &context, &sbi, vertical, 0, 0 );
            KillSystemTimer( hwnd, SCROLL_TIMER );
        }

        break;

    case SCROLL_TOP_RECT:
        SCROLL_DrawInterior( &context, &sbi, sbi.xyThumbTop, vertical, pwndData->SCROLL_trackHitTest, 0);
        if (hittest == pwndData->SCROLL_trackHitTest)
        {
            if ((msg == WM_LBUTTONDOWN) || (msg == WM_SYSTIMER))
            {
                SendMessageW( hwndOwner, vertical ? WM_VSCROLL : WM_HSCROLL,
                                SB_PAGEUP, (LPARAM)hwndCtl );
            }
            SetSystemTimer( hwnd, SCROLL_TIMER, (msg == WM_LBUTTONDOWN) ?
                              SCROLL_FIRST_DELAY : SCROLL_REPEAT_DELAY, NULL );
        }
        else KillSystemTimer( hwnd, SCROLL_TIMER );
        break;

    case SCROLL_THUMB:
        if (msg == WM_LBUTTONDOWN)
        {
            pwndData->SCROLL_TrackingWin = hwnd;
            pwndData->SCROLL_TrackingBar = nBar;
            pwndData->SCROLL_TrackingPos = trackThumbPos + lastMousePos - lastClickPos;
            pwndData->SCROLL_TrackingVal = SCROLL_GetThumbVal( &si, &sbi.rcScrollBar, 
                                                     vertical, pwndData->SCROLL_TrackingPos );
	        if (!pwndData->SCROLL_MovingThumb)
		        SCROLL_DrawMovingThumb(pwndData, &context, &sbi, vertical);
        }
        else if (msg == WM_LBUTTONUP)
        {
	        if (pwndData->SCROLL_MovingThumb)
		        SCROLL_DrawMovingThumb(pwndData, &context, &sbi, vertical);

            SCROLL_DrawInterior(  &context, &sbi, sbi.xyThumbTop, vertical, 0, pwndData->SCROLL_trackHitTest );
        }
        else  /* WM_MOUSEMOVE */
        {
            INT pos;

            if (!SCROLL_PtInRectEx( &sbi.rcScrollBar, pt, vertical )) 
                pos = lastClickPos;
            else
            {
                pt = SCROLL_ClipPos( &sbi.rcScrollBar, pt );
                pos = vertical ? (pt.y - sbi.rcScrollBar.top) : (pt.x - sbi.rcScrollBar.left);
            }
            if ( (pos != lastMousePos) || (!pwndData->SCROLL_MovingThumb) )
            {
                if (pwndData->SCROLL_MovingThumb)
                    SCROLL_DrawMovingThumb(pwndData, &context, &sbi, vertical);
                lastMousePos = pos;
                pwndData->SCROLL_TrackingPos = trackThumbPos + pos - lastClickPos;
                pwndData->SCROLL_TrackingVal = SCROLL_GetThumbVal( &si, &sbi.rcScrollBar,
                                                         vertical,
                                                         pwndData->SCROLL_TrackingPos );
                SendMessageW( hwndOwner, vertical ? WM_VSCROLL : WM_HSCROLL,
                                MAKEWPARAM( SB_THUMBTRACK, pwndData->SCROLL_TrackingVal),
                                (LPARAM)hwndCtl );
                if (!pwndData->SCROLL_MovingThumb)
                    SCROLL_DrawMovingThumb(pwndData, &context, &sbi, vertical);
            }
        }
        break;

    case SCROLL_BOTTOM_RECT:
        if (hittest == pwndData->SCROLL_trackHitTest)
        {
            SCROLL_DrawInterior(  &context, &sbi, sbi.xyThumbTop, vertical, pwndData->SCROLL_trackHitTest, 0 );
            if ((msg == WM_LBUTTONDOWN) || (msg == WM_SYSTIMER))
            {
                SendMessageW( hwndOwner, vertical ? WM_VSCROLL : WM_HSCROLL,
                                SB_PAGEDOWN, (LPARAM)hwndCtl );
            }
            SetSystemTimer( hwnd, SCROLL_TIMER, (msg == WM_LBUTTONDOWN) ?
                              SCROLL_FIRST_DELAY : SCROLL_REPEAT_DELAY, NULL );
        }
        else
        {
            SCROLL_DrawInterior(  &context, &sbi, sbi.xyThumbTop, vertical, 0, 0 );
            KillSystemTimer( hwnd, SCROLL_TIMER );
        }
        break;

    case SCROLL_BOTTOM_ARROW:
        if (hittest == pwndData->SCROLL_trackHitTest)
        {
            SCROLL_DrawArrows(  &context, &sbi, vertical, pwndData->SCROLL_trackHitTest, 0 );
            if ((msg == WM_LBUTTONDOWN) || (msg == WM_SYSTIMER))
            {
                SendMessageW( hwndOwner, vertical ? WM_VSCROLL : WM_HSCROLL,
                                SB_LINEDOWN, (LPARAM)hwndCtl );
	        }

        SetSystemTimer( hwnd, SCROLL_TIMER, (msg == WM_LBUTTONDOWN) ?
                            SCROLL_FIRST_DELAY : SCROLL_REPEAT_DELAY, NULL );
        }
        else
        {
            SCROLL_DrawArrows(  &context, &sbi, vertical, 0, 0 );
            KillSystemTimer( hwnd, SCROLL_TIMER );
        }
        break;
    }

    if (msg == WM_LBUTTONDOWN)
    {

        if (hittest == SCROLL_THUMB)
        {
            UINT val = SCROLL_GetThumbVal( &si, &sbi.rcScrollBar, vertical,
                                 trackThumbPos + lastMousePos - lastClickPos );
            SendMessageW( hwndOwner, vertical ? WM_VSCROLL : WM_HSCROLL,
                            MAKEWPARAM( SB_THUMBTRACK, val ), (LPARAM)hwndCtl );
        }
    }

    if (msg == WM_LBUTTONUP)
    {
        hittest = pwndData->SCROLL_trackHitTest;
        pwndData->SCROLL_trackHitTest = SCROLL_NOWHERE;  /* Terminate tracking */

        if (hittest == SCROLL_THUMB)
        {
            UINT val = SCROLL_GetThumbVal( &si, &sbi.rcScrollBar, vertical,
                                 trackThumbPos + lastMousePos - lastClickPos );
            SendMessageW( hwndOwner, vertical ? WM_VSCROLL : WM_HSCROLL,
                            MAKEWPARAM( SB_THUMBPOSITION, val ), (LPARAM)hwndCtl );
        }
        /* SB_ENDSCROLL doesn't report thumb position */
        SendMessageW( hwndOwner, vertical ? WM_VSCROLL : WM_HSCROLL,
                          SB_ENDSCROLL, (LPARAM)hwndCtl );

        /* Terminate tracking */
        pwndData->SCROLL_TrackingWin = 0;
    }

    ThemeCleanupDrawContext(&context);
}

__attribute__((used)) static void 
SCROLL_TrackScrollBar( HWND hwnd, INT scrollbar, POINT pt )
{
    MSG msg;
    PWND_DATA pwndData = ThemeGetWndData(hwnd);
    if(!pwndData)
        return;

    ScreenToWindow(hwnd, &pt);

    SCROLL_HandleScrollEvent(pwndData, hwnd, scrollbar, WM_LBUTTONDOWN, pt );

    do
    {
        if (!GetMessageW( &msg, 0, 0, 0 )) break;
        if (CallMsgFilterW( &msg, MSGF_SCROLLBAR )) continue;
        if (msg.message == WM_LBUTTONUP ||
            msg.message == WM_MOUSEMOVE ||
            (msg.message == WM_SYSTIMER && msg.wParam == SCROLL_TIMER))
        {
            pt.x = GET_X_LPARAM(msg.lParam);
            pt.y = GET_Y_LPARAM(msg.lParam);
            ClientToScreen(hwnd, &pt);
            ScreenToWindow(hwnd, &pt);
            SCROLL_HandleScrollEvent(pwndData, hwnd, scrollbar, msg.message, pt );
        }
        else
        {
            TranslateMessage( &msg );
            DispatchMessageW( &msg );
        }
        if (!IsWindow( hwnd ))
        {
            ReleaseCapture();
            break;
        }
    } while (msg.message != WM_LBUTTONUP && GetCapture() == hwnd);
}

void NC_TrackScrollBar( HWND hwnd, WPARAM wParam, POINT pt )
{
    INT scrollbar;
    
    if ((wParam & 0xfff0) == SC_HSCROLL)
    {
        if ((wParam & 0x0f) != HTHSCROLL) return;
        scrollbar = SB_HORZ;
    }
    else  /* SC_VSCROLL */
    {
        if ((wParam & 0x0f) != HTVSCROLL) return;
        scrollbar = SB_VERT;
    }
    SCROLL_TrackScrollBar( hwnd, scrollbar, pt );
}

