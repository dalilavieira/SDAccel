#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int Vertex1; int Vertex2; int Vertex3; } ;
struct TYPE_13__ {int WndWidth; int WndHeight; int /*<<< orphan*/  ForegroundDc; } ;
struct TYPE_12__ {int x; int y; int Red; int Green; int Blue; scalar_t__ Alpha; } ;
struct TYPE_11__ {int member_1; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ TRIVERTEX ;
typedef  TYPE_3__* PPERF_INFO ;
typedef  int /*<<< orphan*/  HDC ;
typedef  TYPE_4__ GRADIENT_TRIANGLE ;
typedef  TYPE_4__* GRADIENT_RECT ;

/* Variables and functions */
 int /*<<< orphan*/  GRADIENT_FILL_RECT_H ; 
 int /*<<< orphan*/  GRADIENT_FILL_RECT_V ; 
 int /*<<< orphan*/  GRADIENT_FILL_TRIANGLE ; 
 int /*<<< orphan*/  GradientFill (int /*<<< orphan*/ ,TYPE_2__*,int,TYPE_4__**,int,int /*<<< orphan*/ ) ; 

void
GradientProc(void *Context, PPERF_INFO PerfInfo, unsigned Reps)
{
  unsigned Rep;
  HDC Dc;
  TRIVERTEX vert[6];
  static GRADIENT_TRIANGLE gcap[4];

  Dc = PerfInfo->ForegroundDc;
  vert[0].x = 0;
  vert[0].y = 0;
  vert[0].Red = 0xff00;
  vert[0].Green = 0;
  vert[0].Blue = 0;
  vert[0].Alpha = 0;
  vert[1].x = PerfInfo->WndWidth;
  vert[1].y = 0;
  vert[1].Red = 0;
  vert[1].Green = 0xff00;
  vert[1].Blue = 0;
  vert[1].Alpha = 0;
  vert[2].x = PerfInfo->WndWidth;
  vert[2].y = PerfInfo->WndHeight;
  vert[2].Red = 0;
  vert[2].Green = 0;
  vert[2].Blue = 0xff00;
  vert[2].Alpha = 0;
  vert[3].x = 0;
  vert[3].y = PerfInfo->WndHeight;
  vert[3].Red = 0;
  vert[3].Green = 0xff00;
  vert[3].Blue = 0;
  vert[3].Alpha = 0;
  vert[4].Red = 0;
  vert[4].Green = 0;
  vert[4].Blue = 0;
  vert[4].Alpha = 0;
  vert[5].Red = 0;
  vert[5].Green = 0;
  vert[5].Blue = 0;
  vert[5].Alpha = 0;

  for (Rep = 0; Rep < Reps; Rep++)
    {
      switch (2 * Rep / Reps)
      {
        case 0:
             vert[4].x = PerfInfo->WndWidth * 2 * Rep / Reps;
             vert[4].y = 0;
             vert[5].x = PerfInfo->WndWidth - vert[4].x;
             vert[5].y = PerfInfo->WndHeight;
             gcap[0].Vertex1 = 5; gcap[0].Vertex2 = 0; gcap[0].Vertex3 = 4;
             gcap[1].Vertex1 = 5; gcap[1].Vertex2 = 4; gcap[1].Vertex3 = 1;
             gcap[2].Vertex1 = 5; gcap[2].Vertex2 = 1; gcap[2].Vertex3 = 2;
             gcap[3].Vertex1 = 5; gcap[3].Vertex2 = 3; gcap[3].Vertex3 = 0;
             break;
        case 1:
             vert[4].x = PerfInfo->WndWidth;
             vert[4].y = PerfInfo->WndHeight * 2 * Rep / Reps - PerfInfo->WndHeight;
             vert[5].x = 0;
             vert[5].y = PerfInfo->WndHeight - vert[4].y;
             gcap[0].Vertex1 = 5; gcap[0].Vertex2 = 1; gcap[0].Vertex3 = 4;
             gcap[1].Vertex1 = 5; gcap[1].Vertex2 = 4; gcap[1].Vertex3 = 2;
             gcap[2].Vertex1 = 5; gcap[2].Vertex2 = 2; gcap[2].Vertex3 = 3;
             gcap[3].Vertex1 = 5; gcap[3].Vertex2 = 0; gcap[3].Vertex3 = 1;
             break;
      }

      GradientFill(Dc, vert, 6, &gcap, 4, GRADIENT_FILL_TRIANGLE);
   }
}

void
GradientHorizontalProc(void *Context, PPERF_INFO PerfInfo, unsigned Reps)
{
  unsigned Rep;
  HDC Dc;
  TRIVERTEX vert[2];
  static GRADIENT_RECT gcap = {0, 1};

  Dc = PerfInfo->ForegroundDc;
  for (Rep = 0; Rep < Reps; Rep++)
    {
      vert[0].x = 0;
      vert[0].y = 0;
      vert[0].Red = 0xff00;
      vert[0].Green = 0xff00 - 0xff00 * Rep / Reps;
      vert[0].Blue = 0xff00 * Rep / Reps;
      vert[0].Alpha = 0;

      vert[1].x = PerfInfo->WndWidth;
      vert[1].y = PerfInfo->WndHeight;
      vert[1].Red = 0xff00 - 0xff00 * Rep / Reps;
      vert[1].Green = 0xff00 * Rep / Reps;
      vert[1].Blue = 0xff00;
      vert[1].Alpha = 0;

      GradientFill(Dc, vert, 2, &gcap, 1, GRADIENT_FILL_RECT_H);
    }
}

void
GradientVerticalProc(void *Context, PPERF_INFO PerfInfo, unsigned Reps)
{
  unsigned Rep;
  HDC Dc;
  TRIVERTEX vert[2];
  static GRADIENT_RECT gcap = {0, 1};

  Dc = PerfInfo->ForegroundDc;
  for (Rep = 0; Rep < Reps; Rep++)
    {
      vert[0].x = 0;
      vert[0].y = 0;
      vert[0].Red = 0xff00 * Rep / Reps;
      vert[0].Green = 0xff00 - 0xff00 * Rep / Reps;
      vert[0].Blue = 0xff00;
      vert[0].Alpha = 0;

      vert[1].x = PerfInfo->WndWidth;
      vert[1].y = PerfInfo->WndHeight;
      vert[1].Red = 0xff00 - 0xff00 * Rep / Reps;
      vert[1].Green = 0xff00;
      vert[1].Blue = 0xff00 * Rep / Reps;
      vert[1].Alpha = 0;

      GradientFill(Dc, vert, 2, &gcap, 1, GRADIENT_FILL_RECT_V);
    }
}

