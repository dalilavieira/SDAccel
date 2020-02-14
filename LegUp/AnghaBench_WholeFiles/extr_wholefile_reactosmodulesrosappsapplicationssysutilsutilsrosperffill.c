#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int WndWidth; int WndHeight; int /*<<< orphan*/  ForegroundDc; int /*<<< orphan*/  BackgroundDc; } ;
typedef  TYPE_1__* PPERF_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  PATCOPY ; 
 int /*<<< orphan*/  PatBlt (int /*<<< orphan*/ ,int,int,int,int,int /*<<< orphan*/ ) ; 

void
FillProc(void *Context, PPERF_INFO PerfInfo, unsigned Reps)
{
  unsigned Rep;

  for (Rep = 0; Rep < Reps; Rep++)
    {
      PatBlt((Rep & 0x100) ? PerfInfo->BackgroundDc : PerfInfo->ForegroundDc, 0, 0,
             PerfInfo->WndWidth, PerfInfo->WndHeight, PATCOPY);
    }
}

void
FillSmallProc(void *Context, PPERF_INFO PerfInfo, unsigned Reps)
{
#define SMALL_SIZE 16
  unsigned Rep;
  int x, y;

  x = 0;
  y = 0;

  for (Rep = 0; Rep < Reps; Rep++)
    {
      PatBlt((Rep & 0x10000) ? PerfInfo->BackgroundDc : PerfInfo->ForegroundDc, x, y,
             SMALL_SIZE, SMALL_SIZE, PATCOPY);
      x += SMALL_SIZE + 1;
      if (PerfInfo->WndWidth < x + SMALL_SIZE)
        {
          x = 0;
          y += SMALL_SIZE + 1;
          if (PerfInfo->WndHeight < y + SMALL_SIZE)
            {
              y = 0;
            }
        }
    }
}

