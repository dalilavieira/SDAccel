#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* gdImagePtr ;
struct TYPE_5__ {int sy; int** tpixels; int sx; unsigned char** pixels; scalar_t__ trueColor; } ;

/* Variables and functions */

void gdImageFlipVertical(gdImagePtr im)
{
	register int x, y;

	if (im->trueColor) {
		for (y = 0; y < im->sy / 2; y++) {
			int *row_dst = im->tpixels[y];
			int *row_src = im->tpixels[im->sy - 1 - y];
			for (x = 0; x < im->sx; x++) {
				register int p;
				p = row_dst[x];
				row_dst[x] = im->tpixels[im->sy - 1 - y][x];
				row_src[x] = p;
			}
		}
	} else {
		unsigned char p;
		for (y = 0; y < im->sy / 2; y++) {
			for (x = 0; x < im->sx; x++) {
				p = im->pixels[y][x];
				im->pixels[y][x] =	im->pixels[im->sy - 1 - y][x];
				im->pixels[im->sy - 1 - y][x] = p;
			}
		}
	}
	return;
}

void gdImageFlipHorizontal(gdImagePtr im)
{

	int x, y;

	if (im->trueColor) {
   		int *px1, *px2, tmp;

		for (y = 0; y < im->sy; y++) {
			px1 = im->tpixels[y];
			px2 = im->tpixels[y] + im->sx - 1;
			for (x = 0; x < (im->sx >> 1); x++) {
				tmp = *px1;
				*px1 = *px2;
				*px2 = tmp;
				px1++;
				px2--;
			}
		}
	} else {
		unsigned char *px1, *px2, tmp;

		for (y = 0; y < im->sy; y++) {
			px1 = im->pixels[y];
			px2 = im->pixels[y] + im->sx - 1;
			for (x = 0; x < (im->sx >> 1); x++) {
				tmp = *px1;
				*px1 = *px2;
				*px2 = tmp;
				px1++;
				px2--;
			}
		}
	}
}

void gdImageFlipBoth(gdImagePtr im)
{
	gdImageFlipVertical(im);
	gdImageFlipHorizontal(im);
}

