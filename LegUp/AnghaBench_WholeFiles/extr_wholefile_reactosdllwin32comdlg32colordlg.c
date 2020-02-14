#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_5__ ;
typedef  struct TYPE_46__   TYPE_4__ ;
typedef  struct TYPE_45__   TYPE_3__ ;
typedef  struct TYPE_44__   TYPE_2__ ;
typedef  struct TYPE_43__   TYPE_1__ ;

/* Type definitions */
typedef  int WPARAM ;
typedef  int WORD ;
typedef  int /*<<< orphan*/  WNDPROC ;
typedef  int UINT ;
struct TYPE_44__ {int right; int left; int bottom; int top; } ;
struct TYPE_43__ {int left; int right; int top; int bottom; } ;
struct TYPE_47__ {scalar_t__ hwndFocus; scalar_t__ hwndSelf; int l; int h; int s; int updating; int nextuserdef; int capturedGraph; TYPE_4__* lpcc; TYPE_2__ fullsize; void* msetrgb; scalar_t__ hdcMem; scalar_t__ hbmMem; TYPE_1__ oldcross; TYPE_2__ old3angle; TYPE_2__ focusRect; } ;
struct TYPE_46__ {void* rgbResult; void** lpCustColors; int Flags; int lStructSize; scalar_t__ hwndOwner; scalar_t__ lpfnHook; } ;
struct TYPE_45__ {int x; int y; } ;
typedef  TYPE_2__ RECT ;
typedef  TYPE_3__ POINT ;
typedef  int /*<<< orphan*/  PAINTSTRUCT ;
typedef  int LRESULT ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  long LPARAM ;
typedef  scalar_t__ HWND ;
typedef  scalar_t__ HPEN ;
typedef  scalar_t__ HDC ;
typedef  int /*<<< orphan*/  HCURSOR ;
typedef  scalar_t__ HBRUSH ;
typedef  void* COLORREF ;
typedef  TYPE_4__ CHOOSECOLORW ;
typedef  TYPE_5__ CCPRIV ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (char*) ; 
 int /*<<< orphan*/  BDR_SUNKEN ; 
 int /*<<< orphan*/  BDR_SUNKENOUTER ; 
 int /*<<< orphan*/  BF_RECT ; 
 int /*<<< orphan*/  BLACK_BRUSH ; 
 int /*<<< orphan*/  BeginPaint (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BitBlt (scalar_t__,int,int,int,int,scalar_t__,int,int,int /*<<< orphan*/ ) ; 
 int CC_ENABLEHOOK ; 
 int CC_FULLOPEN ; 
 int CC_PREVENTFULLOPEN ; 
 int CC_SHOWHELP ; 
 int /*<<< orphan*/  COLOROKSTRINGA ; 
 int /*<<< orphan*/  COLOR_BTNFACE ; 
 int /*<<< orphan*/  CONV_LPARAMTOPOINT (long,TYPE_3__*) ; 
 int CallWindowProcA (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int,long) ; 
 int /*<<< orphan*/  ClientToScreen (scalar_t__,TYPE_3__*) ; 
 scalar_t__ CreateCompatibleBitmap (scalar_t__,long,long) ; 
 scalar_t__ CreateCompatibleDC (scalar_t__) ; 
 scalar_t__ CreatePen (int /*<<< orphan*/ ,int,void*) ; 
 int /*<<< orphan*/  CreateRectRgnIndirect (TYPE_2__*) ; 
 scalar_t__ CreateSolidBrush (void*) ; 
 int DISTANCE ; 
 int /*<<< orphan*/  DeleteObject (scalar_t__) ; 
 int /*<<< orphan*/  DrawEdge (scalar_t__,TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DrawFocusRect (scalar_t__,TYPE_2__*) ; 
 int EM_GETSEL ; 
 int EM_LIMITTEXT ; 
 int EM_SETSEL ; 
 int EN_UPDATE ; 
 int /*<<< orphan*/  EnableWindow (scalar_t__,int) ; 
 int /*<<< orphan*/  EndDialog (scalar_t__,int) ; 
 int /*<<< orphan*/  EndPaint (scalar_t__,int /*<<< orphan*/ *) ; 
 int FALSE ; 
 int /*<<< orphan*/  FillRect (scalar_t__,TYPE_2__*,scalar_t__) ; 
 int /*<<< orphan*/  GCLP_HBRBACKGROUND ; 
 int GetBValue (void*) ; 
 scalar_t__ GetClassLongPtrW (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetClientRect (scalar_t__,TYPE_2__*) ; 
 scalar_t__ GetDC (scalar_t__) ; 
 int GetDialogBaseUnits () ; 
 scalar_t__ GetDlgItem (scalar_t__,int const) ; 
 int GetGValue (void*) ; 
 void* GetNearestColor (scalar_t__,void*) ; 
 int GetRValue (void*) ; 
 scalar_t__ GetStockObject (int /*<<< orphan*/ ) ; 
 scalar_t__ GetSysColorBrush (int /*<<< orphan*/ ) ; 
 int GetSystemMetrics (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowRect (scalar_t__,TYPE_2__*) ; 
 int /*<<< orphan*/  GetWindowTextA (scalar_t__,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HELPMSGSTRINGA ; 
#define  IDCANCEL 139 
#define  IDC_COLOR_ADD 138 
 int IDC_COLOR_BL ; 
#define  IDC_COLOR_DEFINE 137 
#define  IDC_COLOR_EDIT_B 136 
#define  IDC_COLOR_EDIT_G 135 
#define  IDC_COLOR_EDIT_H 134 
#define  IDC_COLOR_EDIT_L 133 
#define  IDC_COLOR_EDIT_R 132 
#define  IDC_COLOR_EDIT_S 131 
 int const IDC_COLOR_GRAPH ; 
 int IDC_COLOR_HL ; 
 int const IDC_COLOR_LUMBAR ; 
 int const IDC_COLOR_PREDEF ; 
#define  IDC_COLOR_RES 130 
 int const IDC_COLOR_RESULT ; 
 int const IDC_COLOR_USRDEF ; 
 scalar_t__ IDC_WAIT ; 
#define  IDOK 129 
 scalar_t__ IsWindowVisible (scalar_t__) ; 
 int LOWORD (int) ; 
 int /*<<< orphan*/  LineTo (scalar_t__,int,int) ; 
 int /*<<< orphan*/  LoadCursorW (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 long MAXHORI ; 
 long MAXVERT ; 
 int /*<<< orphan*/  MoveToEx (scalar_t__,int,int,TYPE_3__*) ; 
 int /*<<< orphan*/  PS_SOLID ; 
 int /*<<< orphan*/  Polygon (scalar_t__,TYPE_3__*,int) ; 
 int /*<<< orphan*/  PostMessageA (scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ PtInRect (TYPE_2__*,TYPE_3__) ; 
 void* RGB (int,int,int) ; 
 void* RegisterWindowMessageA (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseCapture () ; 
 int /*<<< orphan*/  ReleaseDC (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  SETRGBSTRINGA ; 
 int /*<<< orphan*/  SM_CXDLGFRAME ; 
 int /*<<< orphan*/  SRCCOPY ; 
 int SWP_NOMOVE ; 
 int SWP_NOZORDER ; 
 int /*<<< orphan*/  SW_HIDE ; 
 int /*<<< orphan*/  SW_SHOW ; 
 int /*<<< orphan*/  ScreenToClient (scalar_t__,TYPE_3__*) ; 
 int /*<<< orphan*/  SelectClipRgn (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ SelectObject (scalar_t__,scalar_t__) ; 
 long SendMessageA (scalar_t__,int,int,long) ; 
 int /*<<< orphan*/  SetCapture (scalar_t__) ; 
 int /*<<< orphan*/  SetCursor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetDlgItemInt (scalar_t__,int,int,int) ; 
 int /*<<< orphan*/  SetFocus (scalar_t__) ; 
 int /*<<< orphan*/  SetPropW (scalar_t__,int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  SetWindowPos (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  SetWindowTextA (scalar_t__,char*) ; 
 int /*<<< orphan*/  ShowWindow (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,int,...) ; 
 int TRUE ; 
 int /*<<< orphan*/  UpdateWindow (scalar_t__) ; 
 int /*<<< orphan*/  WARN (char*) ; 
 int /*<<< orphan*/  WM_COMMAND ; 
 int /*<<< orphan*/  WM_INITDIALOG ; 
 int XSTEPS ; 
 int YSTEPS ; 
 int atoi (char*) ; 
 TYPE_5__* heap_alloc_zero (int) ; 
 void* max (int,int) ; 
 int min (int,int) ; 
 void*** predefcolors ; 
 int psh15 ; 
#define  pshHelp 128 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  szColourDialogProp ; 

__attribute__((used)) static int hsl_to_x(int hue, int sat, int lum)
{
 int res = 0, maxrgb;

 /* l below 120 */
 maxrgb = (256 * min(120,lum)) / 120;  /* 0 .. 256 */
 if (hue < 80)
  res = 0;
 else
  if (hue < 120)
  {
   res = (hue - 80) * maxrgb;           /* 0...10240 */
   res /= 40;                        /* 0...256 */
  }
  else
   if (hue < 200)
    res = maxrgb;
   else
    {
     res= (240 - hue) * maxrgb;
     res /= 40;
    }
 res = res - maxrgb / 2;                 /* -128...128 */

 /* saturation */
 res = maxrgb / 2 + (sat * res) / 240;    /* 0..256 */

 /* lum above 120 */
 if (lum > 120 && res < 256)
  res += ((lum - 120) * (256 - res)) / 120;

 return min(res, 255);
}

__attribute__((used)) static COLORREF CC_HSLtoRGB(int hue, int sat, int lum)
{
 int h, r, g, b;

 /* r */
 h = hue > 80 ? hue-80 : hue+160;
 r = hsl_to_x(h, sat, lum);
 /* g */
 h = hue > 160 ? hue-160 : hue+80;
 g = hsl_to_x(h, sat, lum);
 /* b */
 b = hsl_to_x(hue, sat, lum);

 return RGB(r, g, b);
}

__attribute__((used)) static int CC_RGBtoHSL(char c, COLORREF rgb)
{
 WORD maxi, mini, mmsum, mmdif, result = 0;
 int iresult = 0, r, g, b;

 r = GetRValue(rgb);
 g = GetGValue(rgb);
 b = GetBValue(rgb);

 maxi = max(r, b);
 maxi = max(maxi, g);
 mini = min(r, b);
 mini = min(mini, g);

 mmsum = maxi + mini;
 mmdif = maxi - mini;

 switch(c)
 {
  /* lum */
  case 'L': mmsum *= 120;              /* 0...61200=(255+255)*120 */
	   result = mmsum / 255;        /* 0...240 */
	   break;
  /* saturation */
  case 'S': if (!mmsum)
	    result = 0;
	   else
	    if (!mini || maxi == 255)
	     result = 240;
	   else
	   {
	    result = mmdif * 240;       /* 0...61200=255*240 */
	    result /= (mmsum > 255 ? 510 - mmsum : mmsum); /* 0..255 */
	   }
	   break;
  /* hue */
  case 'H': if (!mmdif)
	    result = 160;
	   else
	   {
	    if (maxi == r)
	    {
	     iresult = 40 * (g - b);       /* -10200 ... 10200 */
	     iresult /= (int) mmdif;    /* -40 .. 40 */
	     if (iresult < 0)
	      iresult += 240;          /* 0..40 and 200..240 */
	    }
	    else
	     if (maxi == g)
	     {
	      iresult = 40 * (b - r);
	      iresult /= (int) mmdif;
	      iresult += 80;           /* 40 .. 120 */
	     }
	     else
	      if (maxi == b)
	      {
	       iresult = 40 * (r - g);
	       iresult /= (int) mmdif;
	       iresult += 160;         /* 120 .. 200 */
	      }
	    result = iresult;
	   }
	   break;
 }
 return result;    /* is this integer arithmetic precise enough ? */
}

__attribute__((used)) static void CC_DrawCurrentFocusRect( const CCPRIV *lpp )
{
  if (lpp->hwndFocus)
  {
    HDC hdc = GetDC(lpp->hwndFocus);
    DrawFocusRect(hdc, &lpp->focusRect);
    ReleaseDC(lpp->hwndFocus, hdc);
  }
}

__attribute__((used)) static void CC_DrawFocusRect(CCPRIV *lpp, HWND hwnd, int x, int y, int rows, int cols)
{
  RECT rect;
  int dx, dy;
  HDC hdc;

  CC_DrawCurrentFocusRect(lpp); /* remove current focus rect */
  /* calculate new rect */
  GetClientRect(hwnd, &rect);
  dx = (rect.right - rect.left) / cols;
  dy = (rect.bottom - rect.top) / rows;
  rect.left += (x * dx) - 2;
  rect.top += (y * dy) - 2;
  rect.right = rect.left + dx;
  rect.bottom = rect.top + dy;
  /* draw it */
  hdc = GetDC(hwnd);
  DrawFocusRect(hdc, &rect);
  lpp->focusRect = rect;
  lpp->hwndFocus = hwnd;
  ReleaseDC(hwnd, hdc);
}

__attribute__((used)) static BOOL CC_MouseCheckPredefColorArray(CCPRIV *lpp, int rows, int cols, LPARAM lParam)
{
 HWND hwnd;
 POINT point;
 RECT rect;
 int dx, dy, x, y;

 CONV_LPARAMTOPOINT(lParam, &point);
 ClientToScreen(lpp->hwndSelf, &point);
 hwnd = GetDlgItem(lpp->hwndSelf, IDC_COLOR_PREDEF);
 GetWindowRect(hwnd, &rect);
 if (PtInRect(&rect, point))
 {
  dx = (rect.right - rect.left) / cols;
  dy = (rect.bottom - rect.top) / rows;
  ScreenToClient(hwnd, &point);

  if (point.x % dx < ( dx - DISTANCE) && point.y % dy < ( dy - DISTANCE))
  {
   x = point.x / dx;
   y = point.y / dy;
   lpp->lpcc->rgbResult = predefcolors[y][x];
   CC_DrawFocusRect(lpp, hwnd, x, y, rows, cols);
   return TRUE;
  }
 }
 return FALSE;
}

__attribute__((used)) static BOOL CC_MouseCheckUserColorArray(CCPRIV *lpp, int rows, int cols, LPARAM lParam)
{
 HWND hwnd;
 POINT point;
 RECT rect;
 int dx, dy, x, y;
 COLORREF *crarr = lpp->lpcc->lpCustColors;

 CONV_LPARAMTOPOINT(lParam, &point);
 ClientToScreen(lpp->hwndSelf, &point);
 hwnd = GetDlgItem(lpp->hwndSelf, IDC_COLOR_USRDEF);
 GetWindowRect(hwnd, &rect);
 if (PtInRect(&rect, point))
 {
  dx = (rect.right - rect.left) / cols;
  dy = (rect.bottom - rect.top) / rows;
  ScreenToClient(hwnd, &point);

  if (point.x % dx < (dx - DISTANCE) && point.y % dy < (dy - DISTANCE))
  {
   x = point.x / dx;
   y = point.y / dy;
   lpp->lpcc->rgbResult = crarr[x + (cols * y) ];
   CC_DrawFocusRect(lpp, hwnd, x, y, rows, cols);
   return TRUE;
  }
 }
 return FALSE;
}

__attribute__((used)) static BOOL CC_MouseCheckColorGraph( HWND hDlg, int dlgitem, int *hori, int *vert, LPARAM lParam )
{
 HWND hwnd;
 POINT point;
 RECT rect;
 long x,y;

 CONV_LPARAMTOPOINT(lParam, &point);
 ClientToScreen(hDlg, &point);
 hwnd = GetDlgItem( hDlg, dlgitem );
 GetWindowRect(hwnd, &rect);

 if (!PtInRect(&rect, point))
  return FALSE;

 GetClientRect(hwnd, &rect);
 ScreenToClient(hwnd, &point);

 x = (long) point.x * MAXHORI;
 x /= rect.right;
 y = (long) (rect.bottom - point.y) * MAXVERT;
 y /= rect.bottom;

 if (x < 0) x = 0;
 if (y < 0) y = 0;
 if (x > MAXHORI) x = MAXHORI;
 if (y > MAXVERT) y = MAXVERT;

 if (hori)
  *hori = x;
 if (vert)
  *vert = y;

 return TRUE;
}

__attribute__((used)) static BOOL CC_MouseCheckResultWindow( HWND hDlg, LPARAM lParam )
{
 HWND hwnd;
 POINT point;
 RECT rect;

 CONV_LPARAMTOPOINT(lParam, &point);
 ClientToScreen(hDlg, &point);
 hwnd = GetDlgItem(hDlg, IDC_COLOR_RESULT);
 GetWindowRect(hwnd, &rect);
 if (PtInRect(&rect, point))
 {
  PostMessageA(hDlg, WM_COMMAND, IDC_COLOR_RES, 0);
  return TRUE;
 }
 return FALSE;
}

__attribute__((used)) static int CC_CheckDigitsInEdit( HWND hwnd, int maxval )
{
 int i, k, m, result, value;
 long editpos;
 char buffer[30];

 GetWindowTextA(hwnd, buffer, ARRAY_SIZE(buffer));
 m = strlen(buffer);
 result = 0;

 for (i = 0 ; i < m ; i++)
  if (buffer[i] < '0' || buffer[i] > '9')
  {
   for (k = i + 1; k <= m; k++)  /* delete bad character */
   {
    buffer[i] = buffer[k];
    m--;
   }
   buffer[m] = 0;
   result = 1;
  }

 value = atoi(buffer);
 if (value > maxval)       /* build a new string */
 {
  sprintf(buffer, "%d", maxval);
  result = 2;
 }
 if (result)
 {
  editpos = SendMessageA(hwnd, EM_GETSEL, 0, 0);
  SetWindowTextA(hwnd, buffer );
  SendMessageA(hwnd, EM_SETSEL, 0, editpos);
 }
 return value;
}

__attribute__((used)) static void CC_PaintSelectedColor(const CCPRIV *infoPtr)
{
 if (IsWindowVisible( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_GRAPH) ))   /* if full size */
 {
  RECT rect;
  HDC  hdc;
  HBRUSH hBrush;
  HWND hwnd = GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_RESULT);

  hdc = GetDC(hwnd);
  GetClientRect(hwnd, &rect) ;
  hBrush = CreateSolidBrush(infoPtr->lpcc->rgbResult);
  if (hBrush)
  {
   FillRect(hdc, &rect, hBrush);
   DrawEdge(hdc, &rect, BDR_SUNKENOUTER, BF_RECT);
   DeleteObject(hBrush);
  }
  ReleaseDC(hwnd, hdc);
 }
}

__attribute__((used)) static void CC_PaintTriangle(CCPRIV *infoPtr)
{
 HDC hDC;
 long temp;
 int w = LOWORD(GetDialogBaseUnits()) / 2;
 POINT points[3];
 int height;
 int oben;
 RECT rect;
 HBRUSH hbr;
 HWND hwnd = GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_LUMBAR);

 if (IsWindowVisible( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_GRAPH)))   /* if full size */
 {
   GetClientRect(hwnd, &rect);
   height = rect.bottom;
   hDC = GetDC(infoPtr->hwndSelf);
   points[0].y = rect.top;
   points[0].x = rect.right;                  /*  |  /|  */
   ClientToScreen(hwnd, points);              /*  | / |  */
   ScreenToClient(infoPtr->hwndSelf, points); /*  |<  |  */
   oben = points[0].y;                        /*  | \ |  */
                                              /*  |  \|  */
   temp = (long)height * (long)infoPtr->l;
   points[0].x += 1;
   points[0].y = oben + height - temp / (long)MAXVERT;
   points[1].y = points[0].y + w;
   points[2].y = points[0].y - w;
   points[2].x = points[1].x = points[0].x + w;

   hbr = (HBRUSH)GetClassLongPtrW( hwnd, GCLP_HBRBACKGROUND);
   if (!hbr) hbr = GetSysColorBrush(COLOR_BTNFACE);
   FillRect(hDC, &infoPtr->old3angle, hbr);
   infoPtr->old3angle.left  = points[0].x;
   infoPtr->old3angle.right = points[1].x + 1;
   infoPtr->old3angle.top   = points[2].y - 1;
   infoPtr->old3angle.bottom= points[1].y + 1;

   hbr = SelectObject(hDC, GetStockObject(BLACK_BRUSH));
   Polygon(hDC, points, 3);
   SelectObject(hDC, hbr);

   ReleaseDC(infoPtr->hwndSelf, hDC);
 }
}

__attribute__((used)) static void CC_PaintCross(CCPRIV *infoPtr)
{
 HWND hwnd = GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_GRAPH);

 if (IsWindowVisible(hwnd))   /* if full size */
 {
   HDC hDC;
   int w = GetDialogBaseUnits() - 1;
   int wc = GetDialogBaseUnits() * 3 / 4;
   RECT rect;
   POINT point, p;
   HPEN hPen;
   int x, y;

   x = infoPtr->h;
   y = infoPtr->s;

   GetClientRect(hwnd, &rect);
   hDC = GetDC(hwnd);
   SelectClipRgn( hDC, CreateRectRgnIndirect(&rect));

   point.x = ((long)rect.right * (long)x) / (long)MAXHORI;
   point.y = rect.bottom - ((long)rect.bottom * (long)y) / (long)MAXVERT;
   if ( infoPtr->oldcross.left != infoPtr->oldcross.right )
     BitBlt(hDC, infoPtr->oldcross.left, infoPtr->oldcross.top,
              infoPtr->oldcross.right - infoPtr->oldcross.left,
              infoPtr->oldcross.bottom - infoPtr->oldcross.top,
              infoPtr->hdcMem, infoPtr->oldcross.left, infoPtr->oldcross.top, SRCCOPY);
   infoPtr->oldcross.left   = point.x - w - 1;
   infoPtr->oldcross.right  = point.x + w + 1;
   infoPtr->oldcross.top    = point.y - w - 1;
   infoPtr->oldcross.bottom = point.y + w + 1;

   hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0)); /* -black- color */
   hPen = SelectObject(hDC, hPen);
   MoveToEx(hDC, point.x - w, point.y, &p);
   LineTo(hDC, point.x - wc, point.y);
   MoveToEx(hDC, point.x + wc, point.y, &p);
   LineTo(hDC, point.x + w, point.y);
   MoveToEx(hDC, point.x, point.y - w, &p);
   LineTo(hDC, point.x, point.y - wc);
   MoveToEx(hDC, point.x, point.y + wc, &p);
   LineTo(hDC, point.x, point.y + w);
   DeleteObject( SelectObject(hDC, hPen));

   ReleaseDC(hwnd, hDC);
 }
}

__attribute__((used)) static void CC_PrepareColorGraph(CCPRIV *infoPtr)
{
 int sdif, hdif, xdif, ydif, hue, sat;
 HWND hwnd = GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_GRAPH);
 HBRUSH hbrush;
 HDC hdc ;
 RECT rect, client;
 HCURSOR hcursor = SetCursor( LoadCursorW(0, (LPCWSTR)IDC_WAIT) );

 GetClientRect(hwnd, &client);
 hdc = GetDC(hwnd);
 infoPtr->hdcMem = CreateCompatibleDC(hdc);
 infoPtr->hbmMem = CreateCompatibleBitmap(hdc, client.right, client.bottom);
 SelectObject(infoPtr->hdcMem, infoPtr->hbmMem);

 xdif = client.right / XSTEPS;
 ydif = client.bottom / YSTEPS+1;
 hdif = 239 / XSTEPS;
 sdif = 240 / YSTEPS;
 for (rect.left = hue = 0; hue < 239 + hdif; hue += hdif)
 {
  rect.right = rect.left + xdif;
  rect.bottom = client.bottom;
  for(sat = 0; sat < 240 + sdif; sat += sdif)
  {
   rect.top = rect.bottom - ydif;
   hbrush = CreateSolidBrush(CC_HSLtoRGB(hue, sat, 120));
   FillRect(infoPtr->hdcMem, &rect, hbrush);
   DeleteObject(hbrush);
   rect.bottom = rect.top;
  }
  rect.left = rect.right;
 }
 ReleaseDC(hwnd, hdc);
 SetCursor(hcursor);
}

__attribute__((used)) static void CC_PaintColorGraph(CCPRIV *infoPtr)
{
 HWND hwnd = GetDlgItem( infoPtr->hwndSelf, IDC_COLOR_GRAPH );
 HDC  hDC;
 RECT rect;

 if (IsWindowVisible(hwnd))   /* if full size */
 {
  if (!infoPtr->hdcMem)
   CC_PrepareColorGraph(infoPtr);   /* should not be necessary */

  hDC = GetDC(hwnd);
  GetClientRect(hwnd, &rect);
  if (infoPtr->hdcMem)
      BitBlt(hDC, 0, 0, rect.right, rect.bottom, infoPtr->hdcMem, 0, 0, SRCCOPY);
  else
      WARN("choose color: hdcMem is not defined\n");
  ReleaseDC(hwnd, hDC);
 }
}

__attribute__((used)) static void CC_PaintLumBar(const CCPRIV *infoPtr)
{
 HWND hwnd = GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_LUMBAR);
 RECT rect, client;
 int lum, ldif, ydif;
 HBRUSH hbrush;
 HDC hDC;

 if (IsWindowVisible(hwnd))
 {
  hDC = GetDC(hwnd);
  GetClientRect(hwnd, &client);
  rect = client;

  ldif = 240 / YSTEPS;
  ydif = client.bottom / YSTEPS+1;
  for (lum = 0; lum < 240 + ldif; lum += ldif)
  {
   rect.top = max(0, rect.bottom - ydif);
   hbrush = CreateSolidBrush(CC_HSLtoRGB(infoPtr->h, infoPtr->s, lum));
   FillRect(hDC, &rect, hbrush);
   DeleteObject(hbrush);
   rect.bottom = rect.top;
  }
  GetClientRect(hwnd, &rect);
  DrawEdge(hDC, &rect, BDR_SUNKENOUTER, BF_RECT);
  ReleaseDC(hwnd, hDC);
 }
}

__attribute__((used)) static void CC_EditSetRGB( CCPRIV *infoPtr )
{
 if (IsWindowVisible( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_GRAPH) ))   /* if full size */
 {
   COLORREF cr = infoPtr->lpcc->rgbResult;
   int r = GetRValue(cr);
   int g = GetGValue(cr);
   int b = GetBValue(cr);

   infoPtr->updating = TRUE;
   SetDlgItemInt(infoPtr->hwndSelf, IDC_COLOR_EDIT_R, r, TRUE);
   SetDlgItemInt(infoPtr->hwndSelf, IDC_COLOR_EDIT_G, g, TRUE);
   SetDlgItemInt(infoPtr->hwndSelf, IDC_COLOR_EDIT_B, b, TRUE);
   infoPtr->updating = FALSE;
 }
}

__attribute__((used)) static void CC_EditSetHSL( CCPRIV *infoPtr )
{
 if (IsWindowVisible( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_GRAPH) ))   /* if full size */
 {
   infoPtr->updating = TRUE;
   SetDlgItemInt(infoPtr->hwndSelf, IDC_COLOR_EDIT_H, infoPtr->h, TRUE);
   SetDlgItemInt(infoPtr->hwndSelf, IDC_COLOR_EDIT_S, infoPtr->s, TRUE);
   SetDlgItemInt(infoPtr->hwndSelf, IDC_COLOR_EDIT_L, infoPtr->l, TRUE);
   infoPtr->updating = FALSE;
 }
 CC_PaintLumBar(infoPtr);
}

__attribute__((used)) static void CC_SwitchToFullSize( CCPRIV *infoPtr, const RECT *lprect )
{
 int i;

 EnableWindow( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_DEFINE), FALSE);
 CC_PrepareColorGraph(infoPtr);
 for (i = IDC_COLOR_EDIT_H; i <= IDC_COLOR_EDIT_B; i++)
   ShowWindow( GetDlgItem(infoPtr->hwndSelf, i), SW_SHOW);
 for (i = IDC_COLOR_HL; i <= IDC_COLOR_BL; i++)
   ShowWindow( GetDlgItem(infoPtr->hwndSelf, i), SW_SHOW);
 ShowWindow( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_RES), SW_SHOW);
 ShowWindow( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_ADD), SW_SHOW);
 ShowWindow( GetDlgItem(infoPtr->hwndSelf, 1090), SW_SHOW);

 if (lprect)
  SetWindowPos(infoPtr->hwndSelf, 0, 0, 0, lprect->right-lprect->left,
   lprect->bottom-lprect->top, SWP_NOMOVE|SWP_NOZORDER);

 ShowWindow( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_LUMBAR), SW_SHOW);
 ShowWindow( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_RESULT), SW_SHOW);

 CC_EditSetRGB(infoPtr);
 CC_EditSetHSL(infoPtr);
 ShowWindow( GetDlgItem( infoPtr->hwndSelf, IDC_COLOR_GRAPH), SW_SHOW);
 UpdateWindow( GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_GRAPH) );
}

__attribute__((used)) static void CC_PaintPredefColorArray(const CCPRIV *infoPtr, int rows, int cols)
{
 HWND hwnd = GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_PREDEF);
 RECT rect, blockrect;
 HDC  hdc;
 HBRUSH hBrush;
 int dx, dy, i, j, k;

 GetClientRect(hwnd, &rect);
 dx = rect.right / cols;
 dy = rect.bottom / rows;
 k = rect.left;

 hdc = GetDC(hwnd);
 GetClientRect(hwnd, &rect);
 hBrush = (HBRUSH)GetClassLongPtrW( hwnd, GCLP_HBRBACKGROUND);
 if (!hBrush) hBrush = GetSysColorBrush(COLOR_BTNFACE);
 FillRect(hdc, &rect, hBrush);
 for ( j = 0; j < rows; j++ )
 {
  for ( i = 0; i < cols; i++ )
  {
   hBrush = CreateSolidBrush(predefcolors[j][i]);
   if (hBrush)
   {
    blockrect.left = rect.left;
    blockrect.top = rect.top;
    blockrect.right = rect.left + dx - DISTANCE;
    blockrect.bottom = rect.top + dy - DISTANCE;
    FillRect(hdc, &blockrect, hBrush);
    DrawEdge(hdc, &blockrect, BDR_SUNKEN, BF_RECT);
    DeleteObject(hBrush);
   }
   rect.left += dx;
  }
  rect.top += dy;
  rect.left = k;
 }
 ReleaseDC(hwnd, hdc);
 if (infoPtr->hwndFocus == hwnd)
   CC_DrawCurrentFocusRect(infoPtr);
}

__attribute__((used)) static void CC_PaintUserColorArray(const CCPRIV *infoPtr, int rows, int cols)
{
 HWND hwnd = GetDlgItem(infoPtr->hwndSelf, IDC_COLOR_USRDEF);
 RECT rect, blockrect;
 HDC  hdc;
 HBRUSH hBrush;
 int dx, dy, i, j, k;

 GetClientRect(hwnd, &rect);

 dx = rect.right / cols;
 dy = rect.bottom / rows;
 k = rect.left;

 hdc = GetDC(hwnd);
 if (hdc)
 {
  hBrush = (HBRUSH)GetClassLongPtrW( hwnd, GCLP_HBRBACKGROUND);
  if (!hBrush) hBrush = GetSysColorBrush(COLOR_BTNFACE);
  FillRect( hdc, &rect, hBrush );
  for (j = 0; j < rows; j++)
  {
   for (i = 0; i < cols; i++)
   {
    hBrush = CreateSolidBrush(infoPtr->lpcc->lpCustColors[i+j*cols]);
    if (hBrush)
    {
     blockrect.left = rect.left;
     blockrect.top = rect.top;
     blockrect.right = rect.left + dx - DISTANCE;
     blockrect.bottom = rect.top + dy - DISTANCE;
     FillRect(hdc, &blockrect, hBrush);
     DrawEdge(hdc, &blockrect, BDR_SUNKEN, BF_RECT);
     DeleteObject(hBrush);
    }
    rect.left += dx;
   }
   rect.top += dy;
   rect.left = k;
  }
  ReleaseDC(hwnd, hdc);
 }
 if (infoPtr->hwndFocus == hwnd)
   CC_DrawCurrentFocusRect(infoPtr);
}

__attribute__((used)) static BOOL CC_HookCallChk( const CHOOSECOLORW *lpcc )
{
 if (lpcc)
  if(lpcc->Flags & CC_ENABLEHOOK)
   if (lpcc->lpfnHook)
    return TRUE;
 return FALSE;
}

__attribute__((used)) static LRESULT CC_WMInitDialog( HWND hDlg, WPARAM wParam, LPARAM lParam )
{
   CHOOSECOLORW *cc = (CHOOSECOLORW*)lParam;
   int i, res;
   int r, g, b;
   HWND hwnd;
   RECT rect;
   POINT point;
   CCPRIV *lpp;

   TRACE("WM_INITDIALOG lParam=%08lX\n", lParam);

   if (cc->lStructSize != sizeof(CHOOSECOLORW))
   {
       EndDialog(hDlg, 0);
       return FALSE;
   }

   lpp = heap_alloc_zero(sizeof(*lpp));
   lpp->lpcc = cc;
   lpp->hwndSelf = hDlg;

   SetPropW( hDlg, szColourDialogProp, lpp );

   if (!(lpp->lpcc->Flags & CC_SHOWHELP))
      ShowWindow(GetDlgItem(hDlg, pshHelp), SW_HIDE);
   lpp->msetrgb = RegisterWindowMessageA(SETRGBSTRINGA);

#if 0
   cpos = MAKELONG(5,7); /* init */
   if (lpp->lpcc->Flags & CC_RGBINIT)
   {
     for (i = 0; i < 6; i++)
       for (j = 0; j < 8; j++)
        if (predefcolors[i][j] == lpp->lpcc->rgbResult)
        {
          cpos = MAKELONG(i,j);
          goto found;
        }
   }
   found:
   /* FIXME: Draw_a_focus_rect & set_init_values */
#endif

   GetWindowRect(hDlg, &lpp->fullsize);
   if (lpp->lpcc->Flags & CC_FULLOPEN || lpp->lpcc->Flags & CC_PREVENTFULLOPEN)
   {
      hwnd = GetDlgItem(hDlg, IDC_COLOR_DEFINE);
      EnableWindow(hwnd, FALSE);
   }
   if (!(lpp->lpcc->Flags & CC_FULLOPEN ) || lpp->lpcc->Flags & CC_PREVENTFULLOPEN)
   {
      rect = lpp->fullsize;
      res = rect.bottom - rect.top;
      hwnd = GetDlgItem(hDlg, IDC_COLOR_GRAPH); /* cut at left border */
      point.x = point.y = 0;
      ClientToScreen(hwnd, &point);
      ScreenToClient(hDlg,&point);
      GetClientRect(hDlg, &rect);
      point.x += GetSystemMetrics(SM_CXDLGFRAME);
      SetWindowPos(hDlg, 0, 0, 0, point.x, res, SWP_NOMOVE|SWP_NOZORDER);

      for (i = IDC_COLOR_EDIT_H; i <= IDC_COLOR_EDIT_B; i++)
         ShowWindow( GetDlgItem(hDlg, i), SW_HIDE);
      for (i = IDC_COLOR_HL; i <= IDC_COLOR_BL; i++)
         ShowWindow( GetDlgItem(hDlg, i), SW_HIDE);
      ShowWindow( GetDlgItem(hDlg, IDC_COLOR_RES), SW_HIDE);
      ShowWindow( GetDlgItem(hDlg, IDC_COLOR_ADD), SW_HIDE);
      ShowWindow( GetDlgItem(hDlg, IDC_COLOR_GRAPH), SW_HIDE);
      ShowWindow( GetDlgItem(hDlg, IDC_COLOR_RESULT), SW_HIDE);
      ShowWindow( GetDlgItem(hDlg, 1090 ), SW_HIDE);
   }
   else
      CC_SwitchToFullSize(lpp, NULL);
   res = TRUE;
   for (i = IDC_COLOR_EDIT_H; i <= IDC_COLOR_EDIT_B; i++)
     SendMessageA( GetDlgItem(hDlg, i), EM_LIMITTEXT, 3, 0);  /* max 3 digits:  xyz  */
   if (CC_HookCallChk(lpp->lpcc))
   {
          res = CallWindowProcA( (WNDPROC)lpp->lpcc->lpfnHook, hDlg, WM_INITDIALOG, wParam, lParam);
   }

   /* Set the initial values of the color chooser dialog */
   r = GetRValue(lpp->lpcc->rgbResult);
   g = GetGValue(lpp->lpcc->rgbResult);
   b = GetBValue(lpp->lpcc->rgbResult);

   CC_PaintSelectedColor(lpp);
   lpp->h = CC_RGBtoHSL('H', lpp->lpcc->rgbResult);
   lpp->s = CC_RGBtoHSL('S', lpp->lpcc->rgbResult);
   lpp->l = CC_RGBtoHSL('L', lpp->lpcc->rgbResult);

   /* Doing it the long way because CC_EditSetRGB/HSL doesn't seem to work */
   SetDlgItemInt(hDlg, IDC_COLOR_EDIT_H, lpp->h, TRUE);
   SetDlgItemInt(hDlg, IDC_COLOR_EDIT_S, lpp->s, TRUE);
   SetDlgItemInt(hDlg, IDC_COLOR_EDIT_L, lpp->l, TRUE);
   SetDlgItemInt(hDlg, IDC_COLOR_EDIT_R, r, TRUE);
   SetDlgItemInt(hDlg, IDC_COLOR_EDIT_G, g, TRUE);
   SetDlgItemInt(hDlg, IDC_COLOR_EDIT_B, b, TRUE);

   CC_PaintCross(lpp);
   CC_PaintTriangle(lpp);

   return res;
}

__attribute__((used)) static LRESULT CC_WMCommand(CCPRIV *lpp, WPARAM wParam, LPARAM lParam, WORD notifyCode, HWND hwndCtl)
{
    int  r, g, b, i, xx;
    UINT cokmsg;
    HDC hdc;
    COLORREF *cr;

    TRACE("CC_WMCommand wParam=%lx lParam=%lx\n", wParam, lParam);
    switch (LOWORD(wParam))
    {
        case IDC_COLOR_EDIT_R:  /* edit notify RGB */
        case IDC_COLOR_EDIT_G:
        case IDC_COLOR_EDIT_B:
	       if (notifyCode == EN_UPDATE && !lpp->updating)
			 {
			   i = CC_CheckDigitsInEdit(hwndCtl, 255);
			   r = GetRValue(lpp->lpcc->rgbResult);
			   g = GetGValue(lpp->lpcc->rgbResult);
			   b= GetBValue(lpp->lpcc->rgbResult);
			   xx = 0;
			   switch (LOWORD(wParam))
			   {
			    case IDC_COLOR_EDIT_R: if ((xx = (i != r))) r = i; break;
			    case IDC_COLOR_EDIT_G: if ((xx = (i != g))) g = i; break;
			    case IDC_COLOR_EDIT_B: if ((xx = (i != b))) b = i; break;
			   }
			   if (xx) /* something has changed */
			   {
			    lpp->lpcc->rgbResult = RGB(r, g, b);
			    CC_PaintSelectedColor(lpp);
			    lpp->h = CC_RGBtoHSL('H', lpp->lpcc->rgbResult);
			    lpp->s = CC_RGBtoHSL('S', lpp->lpcc->rgbResult);
			    lpp->l = CC_RGBtoHSL('L', lpp->lpcc->rgbResult);
			    CC_EditSetHSL(lpp);
			    CC_PaintCross(lpp);
			    CC_PaintTriangle(lpp);
			   }
			 }
		 break;

        case IDC_COLOR_EDIT_H:  /* edit notify HSL */
        case IDC_COLOR_EDIT_S:
        case IDC_COLOR_EDIT_L:
	       if (notifyCode == EN_UPDATE && !lpp->updating)
			 {
			   i = CC_CheckDigitsInEdit(hwndCtl , LOWORD(wParam) == IDC_COLOR_EDIT_H ? 239 : 240);
			   xx = 0;
			   switch (LOWORD(wParam))
			   {
			    case IDC_COLOR_EDIT_H: if ((xx = ( i != lpp->h))) lpp->h = i; break;
			    case IDC_COLOR_EDIT_S: if ((xx = ( i != lpp->s))) lpp->s = i; break;
			    case IDC_COLOR_EDIT_L: if ((xx = ( i != lpp->l))) lpp->l = i; break;
			   }
			   if (xx) /* something has changed */
			   {
			    lpp->lpcc->rgbResult = CC_HSLtoRGB(lpp->h, lpp->s, lpp->l);
			    CC_PaintSelectedColor(lpp);
			    CC_EditSetRGB(lpp);
			    CC_PaintCross(lpp);
			    CC_PaintTriangle(lpp);
			   }
			 }
	       break;

        case IDC_COLOR_DEFINE:
               CC_SwitchToFullSize(lpp, &lpp->fullsize);
	       SetFocus( GetDlgItem(lpp->hwndSelf, IDC_COLOR_EDIT_H));
	       break;

        case IDC_COLOR_ADD:    /* add colors ... column by column */
               cr = lpp->lpcc->lpCustColors;
               cr[(lpp->nextuserdef % 2) * 8 + lpp->nextuserdef / 2] = lpp->lpcc->rgbResult;
               if (++lpp->nextuserdef == 16)
		   lpp->nextuserdef = 0;
	       CC_PaintUserColorArray(lpp, 2, 8);
	       break;

        case IDC_COLOR_RES:              /* resulting color */
	       hdc = GetDC(lpp->hwndSelf);
	       lpp->lpcc->rgbResult = GetNearestColor(hdc, lpp->lpcc->rgbResult);
	       ReleaseDC(lpp->hwndSelf, hdc);
	       CC_EditSetRGB(lpp);
	       CC_PaintSelectedColor(lpp);
	       lpp->h = CC_RGBtoHSL('H', lpp->lpcc->rgbResult);
	       lpp->s = CC_RGBtoHSL('S', lpp->lpcc->rgbResult);
	       lpp->l = CC_RGBtoHSL('L', lpp->lpcc->rgbResult);
	       CC_EditSetHSL(lpp);
	       CC_PaintCross(lpp);
	       CC_PaintTriangle(lpp);
	       break;

	  case pshHelp:           /* Help! */ /* The Beatles, 1965  ;-) */
	       i = RegisterWindowMessageA(HELPMSGSTRINGA);
                   if (lpp->lpcc->hwndOwner)
		       SendMessageA(lpp->lpcc->hwndOwner, i, 0, (LPARAM)lpp->lpcc);
                   if ( CC_HookCallChk(lpp->lpcc))
		       CallWindowProcA( (WNDPROC) lpp->lpcc->lpfnHook, lpp->hwndSelf,
		          WM_COMMAND, psh15, (LPARAM)lpp->lpcc);
	       break;

          case IDOK :
		cokmsg = RegisterWindowMessageA(COLOROKSTRINGA);
		    if (lpp->lpcc->hwndOwner)
			if (SendMessageA(lpp->lpcc->hwndOwner, cokmsg, 0, (LPARAM)lpp->lpcc))
			break;    /* do NOT close */
		EndDialog(lpp->hwndSelf, 1) ;
		return TRUE ;

	  case IDCANCEL :
		EndDialog(lpp->hwndSelf, 0) ;
		return TRUE ;

       }
       return FALSE;
}

__attribute__((used)) static LRESULT CC_WMPaint( CCPRIV *lpp )
{
    PAINTSTRUCT ps;

    BeginPaint(lpp->hwndSelf, &ps);
    /* we have to paint dialog children except text and buttons */
    CC_PaintPredefColorArray(lpp, 6, 8);
    CC_PaintUserColorArray(lpp, 2, 8);
    CC_PaintLumBar(lpp);
    CC_PaintTriangle(lpp);
    CC_PaintSelectedColor(lpp);
    CC_PaintColorGraph(lpp);
    CC_PaintCross(lpp);
    EndPaint(lpp->hwndSelf, &ps);

    return TRUE;
}

__attribute__((used)) static LRESULT CC_WMLButtonUp( CCPRIV *infoPtr )
{
   if (infoPtr->capturedGraph)
   {
       infoPtr->capturedGraph = 0;
       ReleaseCapture();
       CC_PaintCross(infoPtr);
       return 1;
   }
   return 0;
}

__attribute__((used)) static LRESULT CC_WMMouseMove( CCPRIV *infoPtr, LPARAM lParam )
{
   if (infoPtr->capturedGraph)
   {
      int *ptrh = NULL, *ptrs = &infoPtr->l;
      if (infoPtr->capturedGraph == IDC_COLOR_GRAPH)
      {
          ptrh = &infoPtr->h;
          ptrs = &infoPtr->s;
      }
      if (CC_MouseCheckColorGraph( infoPtr->hwndSelf, infoPtr->capturedGraph, ptrh, ptrs, lParam))
      {
          infoPtr->lpcc->rgbResult = CC_HSLtoRGB(infoPtr->h, infoPtr->s, infoPtr->l);
          CC_EditSetRGB(infoPtr);
          CC_EditSetHSL(infoPtr);
          CC_PaintCross(infoPtr);
          CC_PaintTriangle(infoPtr);
          CC_PaintSelectedColor(infoPtr);
      }
      else
      {
          ReleaseCapture();
          infoPtr->capturedGraph = 0;
      }
      return 1;
   }
   return 0;
}

__attribute__((used)) static LRESULT CC_WMLButtonDown( CCPRIV *infoPtr, LPARAM lParam )
{
   int i = 0;

   if (CC_MouseCheckPredefColorArray(infoPtr, 6, 8, lParam))
      i = 1;
   else
      if (CC_MouseCheckUserColorArray(infoPtr, 2, 8, lParam))
         i = 1;
      else
	 if (CC_MouseCheckColorGraph(infoPtr->hwndSelf, IDC_COLOR_GRAPH, &infoPtr->h, &infoPtr->s, lParam))
         {
	    i = 2;
            infoPtr->capturedGraph = IDC_COLOR_GRAPH;
         }
	 else
	    if (CC_MouseCheckColorGraph(infoPtr->hwndSelf, IDC_COLOR_LUMBAR, NULL, &infoPtr->l, lParam))
            {
	       i = 2;
               infoPtr->capturedGraph = IDC_COLOR_LUMBAR;
            }
   if ( i == 2 )
   {
      SetCapture(infoPtr->hwndSelf);
      infoPtr->lpcc->rgbResult = CC_HSLtoRGB(infoPtr->h, infoPtr->s, infoPtr->l);
   }
   if ( i == 1 )
   {
      infoPtr->h = CC_RGBtoHSL('H', infoPtr->lpcc->rgbResult);
      infoPtr->s = CC_RGBtoHSL('S', infoPtr->lpcc->rgbResult);
      infoPtr->l = CC_RGBtoHSL('L', infoPtr->lpcc->rgbResult);
   }
   if (i)
   {
      CC_EditSetRGB(infoPtr);
      CC_EditSetHSL(infoPtr);
      CC_PaintCross(infoPtr);
      CC_PaintTriangle(infoPtr);
      CC_PaintSelectedColor(infoPtr);
      return TRUE;
   }
   return FALSE;
}

