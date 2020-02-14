#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_8__ ;
typedef  struct TYPE_21__   TYPE_7__ ;
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  pt ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_22__ {int /*<<< orphan*/ * hGreyPen; int /*<<< orphan*/  cyClient; int /*<<< orphan*/  cxClient; int /*<<< orphan*/ * hGreyBrush; } ;
struct TYPE_19__ {size_t member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_18__ {size_t member_0; int /*<<< orphan*/  member_1; } ;
struct TYPE_17__ {size_t member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_16__ {size_t member_0; int /*<<< orphan*/  member_1; } ;
struct TYPE_15__ {size_t member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_21__ {size_t x; int y; TYPE_5__ member_4; TYPE_4__ member_3; TYPE_3__ member_2; TYPE_2__ member_1; TYPE_1__ member_0; } ;
struct TYPE_20__ {int wHour; int wMinute; int wSecond; } ;
typedef  TYPE_6__ SYSTEMTIME ;
typedef  TYPE_7__ POINT ;
typedef  TYPE_8__* PCLOCKDATA ;
typedef  size_t INT ;
typedef  int /*<<< orphan*/ * HPEN ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int /*<<< orphan*/ * HBRUSH ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  BLACK_PEN ; 
 int /*<<< orphan*/  CopyMemory (TYPE_7__**,TYPE_7__**,int) ; 
 int /*<<< orphan*/  Ellipse (int /*<<< orphan*/ ,int,int,int,int) ; 
 int /*<<< orphan*/ * GetCurrentObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * GetStockObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OBJ_PEN ; 
 int /*<<< orphan*/  Polygon (int /*<<< orphan*/ ,TYPE_7__*,int) ; 
 int /*<<< orphan*/ * SelectObject (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 size_t TWOPI ; 
 int /*<<< orphan*/  WHITE_BRUSH ; 
 int cos (size_t) ; 
 int min (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sin (size_t) ; 

__attribute__((used)) static VOID
RotatePoint(POINT pt[], INT iNum, INT iAngle)
{
     INT i;
     POINT ptTemp;

     for (i = 0 ; i < iNum ; i++)
     {
          ptTemp.x = (INT) (pt[i].x * cos (TWOPI * iAngle / 360) +
               pt[i].y * sin (TWOPI * iAngle / 360));

          ptTemp.y = (INT) (pt[i].y * cos (TWOPI * iAngle / 360) -
               pt[i].x * sin (TWOPI * iAngle / 360));

          pt[i] = ptTemp;
     }
}

__attribute__((used)) static INT
DrawClock(HDC hdc, PCLOCKDATA pClockData)
{
     INT iAngle,Radius;
     POINT pt[3];
     HBRUSH hBrushOld;
     HPEN hPenOld = NULL;

     /* Grey brush to fill the dots */
     hBrushOld = SelectObject(hdc, pClockData->hGreyBrush);

     hPenOld = GetCurrentObject(hdc, OBJ_PEN);

     // TODO: Check if this conversion is correct resp. usable
     Radius = min(pClockData->cxClient,pClockData->cyClient) * 2;

     for (iAngle = 0; iAngle < 360; iAngle += 6)
     {
          /* Starting coords */
          pt[0].x = 0;
          pt[0].y = Radius;

          /* Rotate start coords */
          RotatePoint(pt, 1, iAngle);

          /* Determine whether it's a big dot or a little dot
           * i.e. 1-4 or 5, 6-9 or 10, 11-14 or 15 */
          if (iAngle % 5)
          {
                pt[2].x = pt[2].y = 7;
                SelectObject(hdc, pClockData->hGreyPen);
          }
          else
          {
              pt[2].x = pt[2].y = 16;
              SelectObject(hdc, GetStockObject(BLACK_PEN));
          }

          pt[0].x -= pt[2].x / 2;
          pt[0].y -= pt[2].y / 2;

          pt[1].x  = pt[0].x + pt[2].x;
          pt[1].y  = pt[0].y + pt[2].y;

          Ellipse(hdc, pt[0].x, pt[0].y, pt[1].x, pt[1].y);
     }

     SelectObject(hdc, hBrushOld);
     SelectObject(hdc, hPenOld);
     return Radius;
}

__attribute__((used)) static VOID
DrawHands(HDC hdc, SYSTEMTIME * pst, BOOL fChange, INT Radius)
{
     POINT pt[3][5] = { {{0, (INT)-Radius/6}, {(INT)Radius/9, 0}, 
	     {0, (INT)Radius/1.8}, {(INT)-Radius/9, 0}, {0, (INT)-Radius/6}},
     {{0, (INT)-Radius/4.5}, {(INT)Radius/18, 0}, {0, (INT) Radius*0.89}, 
	     {(INT)-Radius/18, 0}, {0, (INT)-Radius/4.5}},
     {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, (INT) Radius*0.89}} };
     INT i, iAngle[3];
     POINT ptTemp[3][5];

     /* Black pen for outline, white brush for fill */
     SelectObject(hdc, GetStockObject(BLACK_PEN));
     SelectObject(hdc, GetStockObject(WHITE_BRUSH));

     iAngle[0] = (pst->wHour * 30) % 360 + pst->wMinute / 2;
     iAngle[1] = pst->wMinute * 6;
     iAngle[2] = pst->wSecond * 6;

     CopyMemory(ptTemp, pt, sizeof(pt));

     for (i = fChange ? 0 : 2; i < 3; i++)
     {
          RotatePoint(ptTemp[i], 5, iAngle[i]);

          Polygon(hdc, ptTemp[i], 5);
     }
}

