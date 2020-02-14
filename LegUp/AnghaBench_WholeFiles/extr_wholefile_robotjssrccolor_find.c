#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {scalar_t__ y; scalar_t__ x; } ;
struct TYPE_15__ {scalar_t__ height; scalar_t__ width; } ;
struct TYPE_16__ {TYPE_3__ origin; TYPE_1__ size; } ;
typedef  TYPE_2__ MMRect ;
typedef  int /*<<< orphan*/  MMRGBHex ;
typedef  int /*<<< orphan*/  MMPointArrayRef ;
typedef  TYPE_3__ MMPoint ;
typedef  int /*<<< orphan*/  MMBitmapRef ;

/* Variables and functions */
 int /*<<< orphan*/  ITER_NEXT_POINT (TYPE_3__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  MMBitmapRectInBounds (int /*<<< orphan*/ ,TYPE_2__) ; 
 int /*<<< orphan*/  MMPointArrayAppendPoint (int /*<<< orphan*/ ,TYPE_3__) ; 
 TYPE_3__ MMPointZero ; 
 int /*<<< orphan*/  MMRGBHexAtPoint (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 scalar_t__ MMRGBHexSimilarToColor (int /*<<< orphan*/ ,int /*<<< orphan*/ ,float) ; 
 int /*<<< orphan*/  createMMPointArray (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int findColorInRectAt(MMBitmapRef image, MMRGBHex color, MMPoint *point,
                             MMRect rect, float tolerance, MMPoint startPoint)
{
	MMPoint scan = startPoint;
	if (!MMBitmapRectInBounds(image, rect)) return -1;

	for (; scan.y < rect.size.height; ++scan.y) {
		for (; scan.x < rect.size.width; ++scan.x) {
			MMRGBHex found = MMRGBHexAtPoint(image, scan.x, scan.y);
			if (MMRGBHexSimilarToColor(color, found, tolerance)) {
				if (point != NULL) *point = scan;
				return 0;
			}
		}
		scan.x = rect.origin.x;
	}

	return -1;
}

int findColorInRect(MMBitmapRef image, MMRGBHex color,
                    MMPoint *point, MMRect rect, float tolerance)
{
	return findColorInRectAt(image, color, point, rect, tolerance, rect.origin);
}

MMPointArrayRef findAllColorInRect(MMBitmapRef image, MMRGBHex color,
                                   MMRect rect, float tolerance)
{
	MMPointArrayRef pointArray = createMMPointArray(0);
	MMPoint point = MMPointZero;

	while (findColorInRectAt(image, color, &point, rect, tolerance, point) == 0) {
		MMPointArrayAppendPoint(pointArray, point);
		ITER_NEXT_POINT(point, rect.size.width, rect.origin.x);
	}

	return pointArray;
}

size_t countOfColorsInRect(MMBitmapRef image, MMRGBHex color, MMRect rect,
                           float tolerance)
{
	size_t count = 0;
	MMPoint point = MMPointZero;

	while (findColorInRectAt(image, color, &point, rect, tolerance, point) == 0) {
		ITER_NEXT_POINT(point, rect.size.width, rect.origin.x);
		++count;
	}

	return count;
}

