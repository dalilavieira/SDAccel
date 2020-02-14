#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_19__ {int left; int right; int top; int bottom; } ;
struct TYPE_18__ {void* m_bitmapOldGrid; void* m_bitmapOldPlot; void* m_bitmapGrid; void* m_bitmapPlot; void* m_brushBack; void** m_penPlot; double* m_dPreviousPosition; int m_nYDecimals; double m_dLowerLimit; double m_dUpperLimit; double m_dRange; int m_nShiftPixels; int m_nHalfShiftPixels; int m_nPlotShiftPixels; double m_dVerticalFactor; int m_nPlotHeight; int m_nClientWidth; int m_nClientHeight; int m_nPlotWidth; double* m_dCurrentPosition; TYPE_2__ m_rectPlot; TYPE_2__ m_rectClient; void* m_hWnd; int /*<<< orphan*/ * m_dcPlot; int /*<<< orphan*/ * m_dcGrid; void* m_hParentWnd; void* m_crBackColor; void* m_crGridColor; void** m_crPlotColor; int /*<<< orphan*/  m_strYUnitsString; int /*<<< orphan*/  m_strXUnitsString; } ;
typedef  TYPE_1__ TGraphCtrl ;
typedef  TYPE_2__ RECT ;
typedef  void* HWND ;
typedef  void* HPEN ;
typedef  int /*<<< orphan*/ * HDC ;
typedef  void* HBITMAP ;
typedef  void* COLORREF ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  BitBlt (int /*<<< orphan*/ *,int,int,int,int,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 void* CreateCompatibleBitmap (int /*<<< orphan*/ *,int,int) ; 
 void* CreateCompatibleDC (int /*<<< orphan*/ *) ; 
 void* CreatePen (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 void* CreateSolidBrush (void*) ; 
 int /*<<< orphan*/  DeleteDC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DeleteObject (void*) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  FillRect (int /*<<< orphan*/ *,TYPE_2__*,void*) ; 
 int /*<<< orphan*/  GetClientRect (void*,TYPE_2__*) ; 
 int /*<<< orphan*/ * GetDC (void*) ; 
 void GraphCtrl_DrawPoint (TYPE_1__*) ; 
 void GraphCtrl_InvalidateCtrl (TYPE_1__*,scalar_t__) ; 
 void GraphCtrl_Resize (TYPE_1__*) ; 
 int /*<<< orphan*/  InvalidateRect (void*,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LineTo (int /*<<< orphan*/ *,int,int) ; 
 int MAX_PLOTS ; 
 int /*<<< orphan*/  MoveToEx (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PS_SOLID ; 
 void* RGB (int,int,int) ; 
 int /*<<< orphan*/  ReleaseDC (void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SRCCOPY ; 
 int /*<<< orphan*/  SRCPAINT ; 
 scalar_t__ SelectObject (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  SetBkColor (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  TRUE ; 
 int abs (int) ; 
 int /*<<< orphan*/  fabs (double) ; 
 scalar_t__ log10 (int /*<<< orphan*/ ) ; 
 int max (int,int) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void GraphCtrl_Init(TGraphCtrl* this)
{
    int i;

    this->m_hWnd = 0;
    this->m_hParentWnd = 0;
    this->m_dcGrid = 0;
    this->m_dcPlot = 0;
    this->m_bitmapOldGrid = 0;
    this->m_bitmapOldPlot = 0;
    this->m_bitmapGrid = 0;
    this->m_bitmapPlot = 0;
    this->m_brushBack = 0;

    this->m_penPlot[0] = 0;
    this->m_penPlot[1] = 0;
    this->m_penPlot[2] = 0;
    this->m_penPlot[3] = 0;

    /* since plotting is based on a LineTo for each new point
     * we need a starting point (i.e. a "previous" point)
     * use 0.0 as the default first point.
     * these are public member variables, and can be changed outside
     * (after construction).  Therefore m_perviousPosition could be set to
     * a more appropriate value prior to the first call to SetPosition.
     */
    this->m_dPreviousPosition[0] = 0.0;
    this->m_dPreviousPosition[1] = 0.0;
    this->m_dPreviousPosition[2] = 0.0;
    this->m_dPreviousPosition[3] = 0.0;

    /*  public variable for the number of decimal places on the y axis */
    this->m_nYDecimals = 3;

    /*  set some initial values for the scaling until "SetRange" is called.
     *  these are protected variables and must be set with SetRange
     *  in order to ensure that m_dRange is updated accordingly
     */
    /*   m_dLowerLimit = -10.0; */
    /*   m_dUpperLimit =  10.0; */
    this->m_dLowerLimit = 0.0;
    this->m_dUpperLimit = 100.0;
    this->m_dRange      =  this->m_dUpperLimit - this->m_dLowerLimit;   /*  protected member variable */

    /*  m_nShiftPixels determines how much the plot shifts (in terms of pixels)  */
    /*  with the addition of a new data point */
    this->m_nShiftPixels     = 4;
    this->m_nHalfShiftPixels = this->m_nShiftPixels/2;                     /*  protected */
    this->m_nPlotShiftPixels = this->m_nShiftPixels + this->m_nHalfShiftPixels;  /*  protected */

    /*  background, grid and data colors */
    /*  these are public variables and can be set directly */
    this->m_crBackColor = RGB(  0,   0,   0);  /*  see also SetBackgroundColor */
    this->m_crGridColor = RGB(  0, 128, 64);  /*  see also SetGridColor */
    this->m_crPlotColor[0] = RGB(255, 255, 255);  /*  see also SetPlotColor */
    this->m_crPlotColor[1] = RGB(100, 255, 255);  /*  see also SetPlotColor */
    this->m_crPlotColor[2] = RGB(255, 100, 255);  /*  see also SetPlotColor */
    this->m_crPlotColor[3] = RGB(255, 255, 100);  /*  see also SetPlotColor */

    /*  protected variables */
    for (i = 0; i < MAX_PLOTS; i++)
    {
        this->m_penPlot[i] = CreatePen(PS_SOLID, 0, this->m_crPlotColor[i]);
    }
    this->m_brushBack = CreateSolidBrush(this->m_crBackColor);

    /*  public member variables, can be set directly  */
    strcpy(this->m_strXUnitsString, "Samples");  /*  can also be set with SetXUnits */
    strcpy(this->m_strYUnitsString, "Y units");  /*  can also be set with SetYUnits */

    /*  protected bitmaps to restore the memory DC's */
    this->m_bitmapOldGrid = NULL;
    this->m_bitmapOldPlot = NULL;
}

void GraphCtrl_Dispose(TGraphCtrl* this)
{
    int plot;

    for (plot = 0; plot < MAX_PLOTS; plot++)
        DeleteObject(this->m_penPlot[plot]);

    /*  just to be picky restore the bitmaps for the two memory dc's */
    /*  (these dc's are being destroyed so there shouldn't be any leaks) */

    if (this->m_bitmapOldGrid != NULL) SelectObject(this->m_dcGrid, this->m_bitmapOldGrid);
    if (this->m_bitmapOldPlot != NULL) SelectObject(this->m_dcPlot, this->m_bitmapOldPlot);
    if (this->m_bitmapGrid    != NULL) DeleteObject(this->m_bitmapGrid);
    if (this->m_bitmapPlot    != NULL) DeleteObject(this->m_bitmapPlot);
    if (this->m_dcGrid        != NULL) DeleteDC(this->m_dcGrid);
    if (this->m_dcPlot        != NULL) DeleteDC(this->m_dcPlot);
    if (this->m_brushBack     != NULL) DeleteObject(this->m_brushBack);
}

void GraphCtrl_Create(TGraphCtrl* this, HWND hWnd, HWND hParentWnd, UINT nID)
{
    GraphCtrl_Init(this);
    this->m_hParentWnd = hParentWnd;
    this->m_hWnd = hWnd;

    GraphCtrl_Resize(this);

    return;
}

void GraphCtrl_SetRange(TGraphCtrl* this, double dLower, double dUpper, int nDecimalPlaces)
{
    /* ASSERT(dUpper > dLower); */
    this->m_dLowerLimit     = dLower;
    this->m_dUpperLimit     = dUpper;
    this->m_nYDecimals      = nDecimalPlaces;
    this->m_dRange          = this->m_dUpperLimit - this->m_dLowerLimit;
    this->m_dVerticalFactor = (double)this->m_nPlotHeight / this->m_dRange;
    /*  clear out the existing garbage, re-start with a clean plot */
    GraphCtrl_InvalidateCtrl(this, FALSE);
}

void GraphCtrl_SetGridColor(TGraphCtrl* this, COLORREF color)
{
    this->m_crGridColor = color;
    /*  clear out the existing garbage, re-start with a clean plot */
    GraphCtrl_InvalidateCtrl(this, FALSE);
}

void GraphCtrl_SetPlotColor(TGraphCtrl* this, int plot, COLORREF color)
{
    this->m_crPlotColor[plot] = color;
    DeleteObject(this->m_penPlot[plot]);
    this->m_penPlot[plot] = CreatePen(PS_SOLID, 0, this->m_crPlotColor[plot]);
    /*  clear out the existing garbage, re-start with a clean plot */
    GraphCtrl_InvalidateCtrl(this, FALSE);
}

void GraphCtrl_SetBackgroundColor(TGraphCtrl* this, COLORREF color)
{
    this->m_crBackColor = color;
    DeleteObject(this->m_brushBack);
    this->m_brushBack = CreateSolidBrush(this->m_crBackColor);
    /*  clear out the existing garbage, re-start with a clean plot */
    GraphCtrl_InvalidateCtrl(this, FALSE);
}

void GraphCtrl_InvalidateCtrl(TGraphCtrl* this, BOOL bResize)
{
    /*  There is a lot of drawing going on here - particularly in terms of  */
    /*  drawing the grid.  Don't panic, this is all being drawn (only once) */
    /*  to a bitmap.  The result is then BitBlt'd to the control whenever needed. */
    int i;
    int nCharacters;
    //int nTopGridPix, nMidGridPix, nBottomGridPix;

    HPEN oldPen;
    HPEN solidPen = CreatePen(PS_SOLID, 0, this->m_crGridColor);
    /* HFONT axisFont, yUnitFont, oldFont; */
    /* char strTemp[50]; */

    /*  in case we haven't established the memory dc's */
    /* CClientDC dc(this); */
    HDC dc = GetDC(this->m_hParentWnd);

    /*  if we don't have one yet, set up a memory dc for the grid */
    if (this->m_dcGrid == NULL)
    {
        this->m_dcGrid = CreateCompatibleDC(dc);
        this->m_bitmapGrid = CreateCompatibleBitmap(dc, this->m_nClientWidth, this->m_nClientHeight);
        this->m_bitmapOldGrid = (HBITMAP)SelectObject(this->m_dcGrid, this->m_bitmapGrid);
    }
    else if(bResize)
    {
        // the size of the drawing area has changed
        // so create a new bitmap of the appropriate size
        if(this->m_bitmapGrid != NULL)
        {
            this->m_bitmapGrid = (HBITMAP)SelectObject(this->m_dcGrid, this->m_bitmapOldGrid);
            DeleteObject(this->m_bitmapGrid);
            this->m_bitmapGrid = CreateCompatibleBitmap(dc, this->m_nClientWidth, this->m_nClientHeight);
            SelectObject(this->m_dcGrid, this->m_bitmapGrid);
        }
    }

    SetBkColor(this->m_dcGrid, this->m_crBackColor);

    /*  fill the grid background */
    FillRect(this->m_dcGrid, &this->m_rectClient, this->m_brushBack);

    /*  draw the plot rectangle: */
    /*  determine how wide the y axis scaling values are */
    nCharacters = abs((int)log10(fabs(this->m_dUpperLimit)));
    nCharacters = max(nCharacters, abs((int)log10(fabs(this->m_dLowerLimit))));

    /*  add the units digit, decimal point and a minus sign, and an extra space */
    /*  as well as the number of decimal places to display */
    nCharacters = nCharacters + 4 + this->m_nYDecimals;

    /*  adjust the plot rectangle dimensions */
    /*  assume 6 pixels per character (this may need to be adjusted) */
    /*   m_rectPlot.left = m_rectClient.left + 6*(nCharacters); */
    this->m_rectPlot.left = this->m_rectClient.left;
    this->m_nPlotWidth    = this->m_rectPlot.right - this->m_rectPlot.left;/* m_rectPlot.Width(); */

    /*  draw the plot rectangle */
    oldPen = (HPEN)SelectObject(this->m_dcGrid, solidPen);
    MoveToEx(this->m_dcGrid, this->m_rectPlot.left, this->m_rectPlot.top, NULL);
    LineTo(this->m_dcGrid, this->m_rectPlot.right+1, this->m_rectPlot.top);
    LineTo(this->m_dcGrid, this->m_rectPlot.right+1, this->m_rectPlot.bottom+1);
    LineTo(this->m_dcGrid, this->m_rectPlot.left, this->m_rectPlot.bottom+1);
    /*   LineTo(m_dcGrid, m_rectPlot.left, m_rectPlot.top); */

    /*  draw the horizontal axis */
    for (i = this->m_rectPlot.top; i < this->m_rectPlot.bottom; i += 12)
    {
        MoveToEx(this->m_dcGrid, this->m_rectPlot.left, this->m_rectPlot.top + i, NULL);
        LineTo(this->m_dcGrid, this->m_rectPlot.right, this->m_rectPlot.top + i);
    }

    /*  draw the vertical axis */
    for (i = this->m_rectPlot.left; i < this->m_rectPlot.right; i += 12)
    {
        MoveToEx(this->m_dcGrid, this->m_rectPlot.left + i, this->m_rectPlot.bottom, NULL);
        LineTo(this->m_dcGrid, this->m_rectPlot.left + i, this->m_rectPlot.top);
    }

    SelectObject(this->m_dcGrid, oldPen);
    DeleteObject(solidPen);

#if 0
    /*  create some fonts (horizontal and vertical) */
    /*  use a height of 14 pixels and 300 weight  */
    /*  (these may need to be adjusted depending on the display) */
    axisFont = CreateFont (14, 0, 0, 0, 300,
                           FALSE, FALSE, 0, ANSI_CHARSET,
                           OUT_DEFAULT_PRECIS,
                           CLIP_DEFAULT_PRECIS,
                           DEFAULT_QUALITY,
                           DEFAULT_PITCH|FF_SWISS, "Arial");
    yUnitFont = CreateFont (14, 0, 900, 0, 300,
                            FALSE, FALSE, 0, ANSI_CHARSET,
                            OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS,
                            DEFAULT_QUALITY,
                            DEFAULT_PITCH|FF_SWISS, "Arial");

    /*  grab the horizontal font */
    oldFont = (HFONT)SelectObject(m_dcGrid, axisFont);

    /*  y max */
    SetTextColor(m_dcGrid, m_crGridColor);
    SetTextAlign(m_dcGrid, TA_RIGHT|TA_TOP);
    sprintf(strTemp, "%.*lf", m_nYDecimals, m_dUpperLimit);
    TextOut(m_dcGrid, m_rectPlot.left-4, m_rectPlot.top, strTemp, wcslen(strTemp));

    /*  y min */
    SetTextAlign(m_dcGrid, TA_RIGHT|TA_BASELINE);
    sprintf(strTemp, "%.*lf", m_nYDecimals, m_dLowerLimit);
    TextOut(m_dcGrid, m_rectPlot.left-4, m_rectPlot.bottom, strTemp, wcslen(strTemp));

    /*  x min */
    SetTextAlign(m_dcGrid, TA_LEFT|TA_TOP);
    TextOut(m_dcGrid, m_rectPlot.left, m_rectPlot.bottom+4, "0", 1);

    /*  x max */
    SetTextAlign(m_dcGrid, TA_RIGHT|TA_TOP);
    sprintf(strTemp, "%d", m_nPlotWidth/m_nShiftPixels);
    TextOut(m_dcGrid, m_rectPlot.right, m_rectPlot.bottom+4, strTemp, wcslen(strTemp));

    /*  x units */
    SetTextAlign(m_dcGrid, TA_CENTER|TA_TOP);
    TextOut(m_dcGrid, (m_rectPlot.left+m_rectPlot.right)/2,
            m_rectPlot.bottom+4, m_strXUnitsString, wcslen(m_strXUnitsString));

    /*  restore the font */
    SelectObject(m_dcGrid, oldFont);

    /*  y units */
    oldFont = (HFONT)SelectObject(m_dcGrid, yUnitFont);
    SetTextAlign(m_dcGrid, TA_CENTER|TA_BASELINE);
    TextOut(m_dcGrid, (m_rectClient.left+m_rectPlot.left)/2,
            (m_rectPlot.bottom+m_rectPlot.top)/2, m_strYUnitsString, wcslen(m_strYUnitsString));
    SelectObject(m_dcGrid, oldFont);
#endif
    /*  at this point we are done filling the grid bitmap,  */
    /*  no more drawing to this bitmap is needed until the settings are changed */

    /*  if we don't have one yet, set up a memory dc for the plot */
    if (this->m_dcPlot == NULL)
    {
        this->m_dcPlot = CreateCompatibleDC(dc);
        this->m_bitmapPlot = CreateCompatibleBitmap(dc, this->m_nClientWidth, this->m_nClientHeight);
        this->m_bitmapOldPlot = (HBITMAP)SelectObject(this->m_dcPlot, this->m_bitmapPlot);
    }
    else if(bResize)
    {
        // the size of the drawing area has changed
        // so create a new bitmap of the appropriate size
        if(this->m_bitmapPlot != NULL)
        {
            this->m_bitmapPlot = (HBITMAP)SelectObject(this->m_dcPlot, this->m_bitmapOldPlot);
            DeleteObject(this->m_bitmapPlot);
            this->m_bitmapPlot = CreateCompatibleBitmap(dc, this->m_nClientWidth, this->m_nClientHeight);
            SelectObject(this->m_dcPlot, this->m_bitmapPlot);
        }
    }

    /*  make sure the plot bitmap is cleared */
    SetBkColor(this->m_dcPlot, this->m_crBackColor);
    FillRect(this->m_dcPlot, &this->m_rectClient, this->m_brushBack);

    /*  finally, force the plot area to redraw */
    InvalidateRect(this->m_hParentWnd, &this->m_rectClient, TRUE);
    ReleaseDC(this->m_hParentWnd, dc);
}

double GraphCtrl_AppendPoint(TGraphCtrl* this,
                             double dNewPoint0, double dNewPoint1,
                             double dNewPoint2, double dNewPoint3)
{
    /*  append a data point to the plot & return the previous point */
    double dPrevious;

    dPrevious = this->m_dCurrentPosition[0];
    this->m_dCurrentPosition[0] = dNewPoint0;
    this->m_dCurrentPosition[1] = dNewPoint1;
    this->m_dCurrentPosition[2] = dNewPoint2;
    this->m_dCurrentPosition[3] = dNewPoint3;
    GraphCtrl_DrawPoint(this);
    /* Invalidate(); */
    return dPrevious;
}

void GraphCtrl_Paint(TGraphCtrl* this, HWND hWnd, HDC dc)
{
    HDC memDC;
    HBITMAP memBitmap;
    HBITMAP oldBitmap; /*  bitmap originally found in CMemDC */

/*   RECT rcClient; */
/*   GetClientRect(hWnd, &rcClient); */
/*   FillSolidRect(dc, &rcClient, RGB(255, 0, 255)); */
/*   m_nClientWidth = rcClient.right - rcClient.left; */
/*   m_nClientHeight = rcClient.bottom - rcClient.top; */

    /*  no real plotting work is performed here,  */
    /*  just putting the existing bitmaps on the client */

    /*  to avoid flicker, establish a memory dc, draw to it */
    /*  and then BitBlt it to the client */
    memDC = CreateCompatibleDC(dc);
    memBitmap = (HBITMAP)CreateCompatibleBitmap(dc, this->m_nClientWidth, this->m_nClientHeight);
    oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);

    if (memDC != NULL)
    {
        /*  first drop the grid on the memory dc */
        BitBlt(memDC, 0, 0, this->m_nClientWidth, this->m_nClientHeight, this->m_dcGrid, 0, 0, SRCCOPY);
        /*  now add the plot on top as a "pattern" via SRCPAINT. */
        /*  works well with dark background and a light plot */
        BitBlt(memDC, 0, 0, this->m_nClientWidth, this->m_nClientHeight, this->m_dcPlot, 0, 0, SRCPAINT);  /* SRCPAINT */
        /*  finally send the result to the display */
        BitBlt(dc, 0, 0, this->m_nClientWidth, this->m_nClientHeight, memDC, 0, 0, SRCCOPY);
    }
    SelectObject(memDC, oldBitmap);
    DeleteObject(memBitmap);
    DeleteDC(memDC);
}

void GraphCtrl_DrawPoint(TGraphCtrl* this)
{
    /*  this does the work of "scrolling" the plot to the left
     *  and appending a new data point all of the plotting is
     *  directed to the memory based bitmap associated with m_dcPlot
     *  the will subsequently be BitBlt'd to the client in Paint
     */
    int currX, prevX, currY, prevY;
    HPEN oldPen;
    RECT rectCleanUp;
    int i;

    if (this->m_dcPlot != NULL)
    {
        /*  shift the plot by BitBlt'ing it to itself
         *  note: the m_dcPlot covers the entire client
         *        but we only shift bitmap that is the size
         *        of the plot rectangle
         *  grab the right side of the plot (excluding m_nShiftPixels on the left)
         *  move this grabbed bitmap to the left by m_nShiftPixels
         */
        BitBlt(this->m_dcPlot, this->m_rectPlot.left, this->m_rectPlot.top+1,
               this->m_nPlotWidth, this->m_nPlotHeight, this->m_dcPlot,
               this->m_rectPlot.left+this->m_nShiftPixels, this->m_rectPlot.top+1,
               SRCCOPY);

        /*  establish a rectangle over the right side of plot */
        /*  which now needs to be cleaned up prior to adding the new point */
        rectCleanUp = this->m_rectPlot;
        rectCleanUp.left  = rectCleanUp.right - this->m_nShiftPixels;

        /*  fill the cleanup area with the background */
        FillRect(this->m_dcPlot, &rectCleanUp, this->m_brushBack);

        /*  draw the next line segment */
        for (i = 0; i < MAX_PLOTS; i++)
        {
            /*  grab the plotting pen */
            oldPen = (HPEN)SelectObject(this->m_dcPlot, this->m_penPlot[i]);

            /*  move to the previous point */
            prevX = this->m_rectPlot.right-this->m_nPlotShiftPixels;
            prevY = this->m_rectPlot.bottom -
                (long)((this->m_dPreviousPosition[i] - this->m_dLowerLimit) * this->m_dVerticalFactor);
            MoveToEx(this->m_dcPlot, prevX, prevY, NULL);

            /*  draw to the current point */
            currX = this->m_rectPlot.right-this->m_nHalfShiftPixels;
            currY = this->m_rectPlot.bottom -
                (long)((this->m_dCurrentPosition[i] - this->m_dLowerLimit) * this->m_dVerticalFactor);
            LineTo(this->m_dcPlot, currX, currY);

            /*  Restore the pen  */
            SelectObject(this->m_dcPlot, oldPen);

            /*  if the data leaks over the upper or lower plot boundaries
             *  fill the upper and lower leakage with the background
             *  this will facilitate clipping on an as needed basis
             *  as opposed to always calling IntersectClipRect
             */
            if ((prevY <= this->m_rectPlot.top) || (currY <= this->m_rectPlot.top))
            {
                RECT rc;
                rc.bottom = this->m_rectPlot.top+1;
                rc.left = prevX;
                rc.right = currX+1;
                rc.top = this->m_rectClient.top;
                FillRect(this->m_dcPlot, &rc, this->m_brushBack);
            }
            if ((prevY >= this->m_rectPlot.bottom) || (currY >= this->m_rectPlot.bottom))
            {
                RECT rc;
                rc.bottom = this->m_rectClient.bottom+1;
                rc.left = prevX;
                rc.right = currX+1;
                rc.top = this->m_rectPlot.bottom+1;
                /* RECT rc(prevX, m_rectPlot.bottom+1, currX+1, m_rectClient.bottom+1); */
                FillRect(this->m_dcPlot, &rc, this->m_brushBack);
            }

            /*  store the current point for connection to the next point */
            this->m_dPreviousPosition[i] = this->m_dCurrentPosition[i];
        }
    }
}

void GraphCtrl_Resize(TGraphCtrl* this)
{
    /*  NOTE: Resize automatically gets called during the setup of the control */
    GetClientRect(this->m_hWnd, &this->m_rectClient);

    /*  set some member variables to avoid multiple function calls */
    this->m_nClientHeight = this->m_rectClient.bottom - this->m_rectClient.top;/* m_rectClient.Height(); */
    this->m_nClientWidth  = this->m_rectClient.right - this->m_rectClient.left;/* m_rectClient.Width(); */

    /*  the "left" coordinate and "width" will be modified in  */
    /*  InvalidateCtrl to be based on the width of the y axis scaling */
#if 0
    this->m_rectPlot.left   = 20;
    this->m_rectPlot.top    = 10;
    this->m_rectPlot.right  = this->m_rectClient.right-10;
    this->m_rectPlot.bottom = this->m_rectClient.bottom-25;
#else
    this->m_rectPlot.left   = 0;
    this->m_rectPlot.top    = -1;
    this->m_rectPlot.right  = this->m_rectClient.right-0;
    this->m_rectPlot.bottom = this->m_rectClient.bottom-0;
#endif

    /*  set some member variables to avoid multiple function calls */
    this->m_nPlotHeight = this->m_rectPlot.bottom - this->m_rectPlot.top;/* m_rectPlot.Height(); */
    this->m_nPlotWidth  = this->m_rectPlot.right - this->m_rectPlot.left;/* m_rectPlot.Width(); */

    /*  set the scaling factor for now, this can be adjusted  */
    /*  in the SetRange functions */
    this->m_dVerticalFactor = (double)this->m_nPlotHeight / this->m_dRange;
}

