#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int WORD ;
typedef  int /*<<< orphan*/  UINT ;
typedef  int /*<<< orphan*/  SIZE ;
typedef  int /*<<< orphan*/  POINT ;
typedef  int /*<<< orphan*/  PHYSDEV ;
typedef  int INT ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  COLORREF ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CLR_INVALID ; 
 int FALSE ; 
 int /*<<< orphan*/  GDI_ERROR ; 
 int HIWORD (int /*<<< orphan*/ ) ; 
 int LOWORD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  META_EXCLUDECLIPRECT ; 
 int /*<<< orphan*/  META_INTERSECTCLIPRECT ; 
 int /*<<< orphan*/  META_OFFSETCLIPRGN ; 
 int /*<<< orphan*/  META_OFFSETVIEWPORTORG ; 
 int /*<<< orphan*/  META_OFFSETWINDOWORG ; 
 int /*<<< orphan*/  META_RESTOREDC ; 
 int /*<<< orphan*/  META_SAVEDC ; 
 int /*<<< orphan*/  META_SCALEVIEWPORTEXT ; 
 int /*<<< orphan*/  META_SCALEWINDOWEXT ; 
 int /*<<< orphan*/  META_SETBKCOLOR ; 
 int /*<<< orphan*/  META_SETBKMODE ; 
 int /*<<< orphan*/  META_SETMAPMODE ; 
 int /*<<< orphan*/  META_SETMAPPERFLAGS ; 
 int /*<<< orphan*/  META_SETPOLYFILLMODE ; 
 int /*<<< orphan*/  META_SETRELABS ; 
 int /*<<< orphan*/  META_SETROP2 ; 
 int /*<<< orphan*/  META_SETSTRETCHBLTMODE ; 
 int /*<<< orphan*/  META_SETTEXTALIGN ; 
 int /*<<< orphan*/  META_SETTEXTCHAREXTRA ; 
 int /*<<< orphan*/  META_SETTEXTCOLOR ; 
 int /*<<< orphan*/  META_SETTEXTJUSTIFICATION ; 
 int /*<<< orphan*/  META_SETVIEWPORTEXT ; 
 int /*<<< orphan*/  META_SETVIEWPORTORG ; 
 int /*<<< orphan*/  META_SETWINDOWEXT ; 
 int /*<<< orphan*/  META_SETWINDOWORG ; 
 int MFDRV_MetaParam0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int MFDRV_MetaParam1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int MFDRV_MetaParam2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int MFDRV_MetaParam4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int) ; 

INT MFDRV_SaveDC( PHYSDEV dev )
{
    return MFDRV_MetaParam0( dev, META_SAVEDC );
}

BOOL MFDRV_RestoreDC( PHYSDEV dev, INT level )
{
    return MFDRV_MetaParam1( dev, META_RESTOREDC, level );
}

UINT MFDRV_SetTextAlign( PHYSDEV dev, UINT align )
{
    return MFDRV_MetaParam2( dev, META_SETTEXTALIGN, HIWORD(align), LOWORD(align)) ? align : GDI_ERROR;
}

INT MFDRV_SetBkMode( PHYSDEV dev, INT mode )
{
    return MFDRV_MetaParam1( dev, META_SETBKMODE, (WORD)mode) ? mode : 0;
}

COLORREF MFDRV_SetBkColor( PHYSDEV dev, COLORREF color )
{
    return MFDRV_MetaParam2(dev, META_SETBKCOLOR, HIWORD(color), LOWORD(color)) ? color : CLR_INVALID;
}

COLORREF MFDRV_SetTextColor( PHYSDEV dev, COLORREF color )
{
    return MFDRV_MetaParam2(dev, META_SETTEXTCOLOR, HIWORD(color), LOWORD(color)) ? color : CLR_INVALID;
}

INT MFDRV_SetROP2( PHYSDEV dev, INT rop )
{
    return MFDRV_MetaParam1( dev, META_SETROP2, (WORD)rop) ? rop : 0;
}

INT MFDRV_SetRelAbs( PHYSDEV dev, INT mode )
{
    return MFDRV_MetaParam1( dev, META_SETRELABS, (WORD)mode) ? mode : 0;
}

INT MFDRV_SetPolyFillMode( PHYSDEV dev, INT mode )
{
    return MFDRV_MetaParam1( dev, META_SETPOLYFILLMODE, (WORD)mode) ? mode : 0;
}

INT MFDRV_SetStretchBltMode( PHYSDEV dev, INT mode )
{
    return MFDRV_MetaParam1( dev, META_SETSTRETCHBLTMODE, (WORD)mode) ? mode : 0;
}

INT MFDRV_IntersectClipRect( PHYSDEV dev, INT left, INT top, INT right, INT bottom )
{
    return MFDRV_MetaParam4( dev, META_INTERSECTCLIPRECT, left, top, right, bottom );
}

INT MFDRV_ExcludeClipRect( PHYSDEV dev, INT left, INT top, INT right, INT bottom )
{
    return MFDRV_MetaParam4( dev, META_EXCLUDECLIPRECT, left, top, right, bottom );
}

INT MFDRV_OffsetClipRgn( PHYSDEV dev, INT x, INT y )
{
    return MFDRV_MetaParam2( dev, META_OFFSETCLIPRGN, x, y );
}

INT MFDRV_SetMapMode( PHYSDEV dev, INT mode )
{
    return MFDRV_MetaParam1( dev, META_SETMAPMODE, mode );
}

BOOL MFDRV_SetViewportExtEx( PHYSDEV dev, INT x, INT y, SIZE *size )
{
    return MFDRV_MetaParam2( dev, META_SETVIEWPORTEXT, x, y );
}

BOOL MFDRV_SetViewportOrgEx( PHYSDEV dev, INT x, INT y, POINT *pt )
{
    return MFDRV_MetaParam2( dev, META_SETVIEWPORTORG, x, y );
}

BOOL MFDRV_SetWindowExtEx( PHYSDEV dev, INT x, INT y, SIZE *size )
{
    return MFDRV_MetaParam2( dev, META_SETWINDOWEXT, x, y );
}

BOOL MFDRV_SetWindowOrgEx( PHYSDEV dev, INT x, INT y, POINT *pt )
{
    return MFDRV_MetaParam2( dev, META_SETWINDOWORG, x, y );
}

BOOL MFDRV_OffsetViewportOrgEx( PHYSDEV dev, INT x, INT y, POINT *pt )
{
    return MFDRV_MetaParam2( dev, META_OFFSETVIEWPORTORG, x, y );
}

BOOL MFDRV_OffsetWindowOrgEx( PHYSDEV dev, INT x, INT y, POINT *pt )
{
    return MFDRV_MetaParam2( dev, META_OFFSETWINDOWORG, x, y );
}

BOOL MFDRV_ScaleViewportExtEx( PHYSDEV dev, INT xNum, INT xDenom, INT yNum, INT yDenom, SIZE *size )
{
    return MFDRV_MetaParam4( dev, META_SCALEVIEWPORTEXT, xNum, xDenom, yNum, yDenom );
}

BOOL MFDRV_ScaleWindowExtEx( PHYSDEV dev, INT xNum, INT xDenom, INT yNum, INT yDenom, SIZE *size )
{
    return MFDRV_MetaParam4( dev, META_SCALEWINDOWEXT, xNum, xDenom, yNum, yDenom );
}

BOOL MFDRV_SetTextJustification( PHYSDEV dev, INT extra, INT breaks )
{
    return MFDRV_MetaParam2( dev, META_SETTEXTJUSTIFICATION, extra, breaks );
}

INT MFDRV_SetTextCharacterExtra( PHYSDEV dev, INT extra )
{
    return MFDRV_MetaParam1( dev, META_SETTEXTCHAREXTRA, extra ) ? extra : 0x80000000;
}

DWORD MFDRV_SetMapperFlags( PHYSDEV dev, DWORD flags )
{
    return MFDRV_MetaParam2( dev, META_SETMAPPERFLAGS, HIWORD(flags), LOWORD(flags) ) ? flags : GDI_ERROR;
}

BOOL MFDRV_AbortPath( PHYSDEV dev )
{
    return FALSE;
}

BOOL MFDRV_BeginPath( PHYSDEV dev )
{
    return FALSE;
}

BOOL MFDRV_CloseFigure( PHYSDEV dev )
{
    return FALSE;
}

BOOL MFDRV_EndPath( PHYSDEV dev )
{
    return FALSE;
}

BOOL MFDRV_FillPath( PHYSDEV dev )
{
    return FALSE;
}

BOOL MFDRV_FlattenPath( PHYSDEV dev )
{
    return FALSE;
}

BOOL MFDRV_SelectClipPath( PHYSDEV dev, INT iMode )
{
    return FALSE;
}

BOOL MFDRV_StrokeAndFillPath( PHYSDEV dev )
{
    return FALSE;
}

BOOL MFDRV_StrokePath( PHYSDEV dev )
{
    return FALSE;
}

BOOL MFDRV_WidenPath( PHYSDEV dev )
{
    return FALSE;
}

COLORREF MFDRV_SetDCBrushColor( PHYSDEV dev, COLORREF color )
{
    return CLR_INVALID;
}

COLORREF MFDRV_SetDCPenColor( PHYSDEV dev, COLORREF color )
{
    return CLR_INVALID;
}

