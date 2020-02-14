#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
typedef  enum content { ____Placeholder_content } content ;
typedef  int /*<<< orphan*/  WPARAM ;
typedef  int /*<<< orphan*/  WNDPROC ;
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_22__ {scalar_t__ right; scalar_t__ bottom; scalar_t__ top; scalar_t__ left; } ;
struct TYPE_23__ {int /*<<< orphan*/  OrigWndProc; int /*<<< orphan*/  hWnd; TYPE_3__ size; int /*<<< orphan*/  control; int /*<<< orphan*/  fWindowless; scalar_t__ fActive; scalar_t__ fInPlace; } ;
struct TYPE_21__ {scalar_t__ right; scalar_t__ bottom; scalar_t__ top; scalar_t__ left; } ;
struct TYPE_20__ {scalar_t__ cy; scalar_t__ cx; } ;
typedef  TYPE_1__ SIZEL ;
typedef  TYPE_2__ RECTL ;
typedef  TYPE_3__ RECT ;
typedef  int /*<<< orphan*/  LRESULT ;
typedef  TYPE_3__* LPCRECT ;
typedef  int /*<<< orphan*/ * LPCOLESTR ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  IViewObject ;
typedef  int /*<<< orphan*/  IOleInPlaceObject ;
typedef  TYPE_5__ IOCS ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  CLSID ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  AtlPixelToHiMetric (TYPE_1__*,TYPE_1__*) ; 
 scalar_t__ CLSIDFromProgID (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ CLSIDFromString (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CLSID_WebBrowser ; 
 int /*<<< orphan*/  CallWindowProcW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DVASPECT_CONTENT ; 
 int /*<<< orphan*/  FIXME (char*) ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HIWORD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IID_IOleInPlaceObject ; 
 int /*<<< orphan*/  IID_IViewObject ; 
 int /*<<< orphan*/  IOCS_Detach (TYPE_5__*) ; 
 int /*<<< orphan*/  IOleInPlaceObject_Release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IOleInPlaceObject_SetObjectRects (int /*<<< orphan*/ *,TYPE_3__*,TYPE_3__*) ; 
 int /*<<< orphan*/  IOleObject_QueryInterface (int /*<<< orphan*/ ,int /*<<< orphan*/ *,void**) ; 
 int /*<<< orphan*/  IOleObject_SetExtent (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  IViewObject_Draw (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__*,TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IViewObject_Release (int /*<<< orphan*/ *) ; 
 int IsEmpty ; 
 int IsGUID ; 
 int IsHTML ; 
 int IsURL ; 
 int IsUnknown ; 
 int /*<<< orphan*/  LOWORD (int /*<<< orphan*/ ) ; 
 int MAX_PATH ; 
 scalar_t__ PathIsURLW (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ SUCCEEDED (int /*<<< orphan*/ ) ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  SetRect (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ TRUE ; 
 int URL_APPLY_GUESSFILE ; 
 int URL_APPLY_GUESSSCHEME ; 
 scalar_t__ UrlApplySchemeW (int /*<<< orphan*/ *,char*,int*,int) ; 
 int /*<<< orphan*/  WARN (char*,int /*<<< orphan*/ ) ; 
#define  WM_DESTROY 131 
#define  WM_PAINT 130 
#define  WM_SHOWWINDOW 129 
#define  WM_SIZE 128 
 int /*<<< orphan*/  strncmpiW (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  wine_dbgstr_w (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void IOCS_OnSize( IOCS* This, LPCRECT rect )
{
    SIZEL inPix, inHi;

    This->size = *rect;

    if ( !This->control )
        return;

    inPix.cx = rect->right - rect->left;
    inPix.cy = rect->bottom - rect->top;
    AtlPixelToHiMetric( &inPix, &inHi );
    IOleObject_SetExtent( This->control, DVASPECT_CONTENT, &inHi );

    if ( This->fInPlace )
    {
        IOleInPlaceObject *wl;

        if ( SUCCEEDED( IOleObject_QueryInterface( This->control, &IID_IOleInPlaceObject, (void**)&wl ) ) )
        {
            IOleInPlaceObject_SetObjectRects( wl, rect, rect );
            IOleInPlaceObject_Release( wl );
        }
    }
}

__attribute__((used)) static void IOCS_OnShow( IOCS *This, BOOL fShow )
{
    if (!This->control || This->fActive || !fShow )
        return;

    This->fActive = TRUE;
}

__attribute__((used)) static void IOCS_OnDraw( IOCS *This )
{
    IViewObject *view;

    if ( !This->control || !This->fWindowless )
        return;

    if ( SUCCEEDED( IOleObject_QueryInterface( This->control, &IID_IViewObject, (void**)&view ) ) )
    {
        HDC dc = GetDC( This->hWnd );
        RECTL rect;

        rect.left = This->size.left; rect.top = This->size.top;
        rect.bottom = This->size.bottom; rect.right = This->size.right;

        IViewObject_Draw( view, DVASPECT_CONTENT, ~0, NULL, NULL, 0, dc, &rect, &rect, NULL, 0 );
        IViewObject_Release( view );
        ReleaseDC( This->hWnd, dc );
    }
}

__attribute__((used)) static LRESULT IOCS_OnWndProc( IOCS *This, HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    WNDPROC OrigWndProc = This->OrigWndProc;

    switch( uMsg )
    {
        case WM_DESTROY:
            IOCS_Detach( This );
            break;
        case WM_SIZE:
            {
                RECT r;
                SetRect(&r, 0, 0, LOWORD(lParam), HIWORD(lParam));
                IOCS_OnSize( This, &r );
            }
            break;
        case WM_SHOWWINDOW:
            IOCS_OnShow( This, (BOOL) wParam );
            break;
        case WM_PAINT:
            IOCS_OnDraw( This );
            break;
    }

    return CallWindowProcW( OrigWndProc, hWnd, uMsg, wParam, lParam );
}

__attribute__((used)) static enum content get_content_type(LPCOLESTR name, CLSID *control_id)
{
    static const WCHAR mshtml_prefixW[] = {'m','s','h','t','m','l',':',0};
    WCHAR new_urlW[MAX_PATH];
    DWORD size = MAX_PATH;

    if (!name || !name[0])
    {
        WARN("name %s\n", wine_dbgstr_w(name));
        return IsEmpty;
    }

    if (CLSIDFromString(name, control_id) == S_OK ||
        CLSIDFromProgID(name, control_id) == S_OK)
        return IsGUID;

    if (PathIsURLW (name) ||
        UrlApplySchemeW(name, new_urlW, &size, URL_APPLY_GUESSSCHEME|URL_APPLY_GUESSFILE) == S_OK)
    {
        *control_id = CLSID_WebBrowser;
        return IsURL;
    }

    if (!strncmpiW(name, mshtml_prefixW, 7))
    {
        FIXME("mshtml prefix not implemented\n");
        *control_id = CLSID_WebBrowser;
        return IsHTML;
    }

    return IsUnknown;
}

