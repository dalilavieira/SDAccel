#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int numcomps; int /*<<< orphan*/  color_space; TYPE_1__* comps; } ;
typedef  TYPE_2__ opj_image_t ;
struct TYPE_7__ {int prec; int w; int h; int* data; int dx; int dy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLRSPC_GRAY ; 
 int /*<<< orphan*/  CLRSPC_SRGB ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,int) ; 
 int /*<<< orphan*/  free (int*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void sycc_to_rgb(int offset, int upb, int y, int cb, int cr,
	int *out_r, int *out_g, int *out_b)
{
	int r, g, b;

	cb -= offset; cr -= offset;
	r = y + (int)(1.402 * (float)cr);
	if(r < 0) r = 0; else if(r > upb) r = upb; *out_r = r;

	g = y - (int)(0.344 * (float)cb + 0.714 * (float)cr);
	if(g < 0) g = 0; else if(g > upb) g = upb; *out_g = g;

	b = y + (int)(1.772 * (float)cb);
	if(b < 0) b = 0; else if(b > upb) b = upb; *out_b = b;
}

__attribute__((used)) static void sycc444_to_rgb(opj_image_t *img)
{
	int *d0, *d1, *d2, *r, *g, *b;
	const int *y, *cb, *cr;
	int maxw, maxh, max, i, offset, upb;

	i = img->comps[0].prec;
	offset = 1<<(i - 1); upb = (1<<i)-1;

	maxw = img->comps[0].w; maxh = img->comps[0].h;
	max = maxw * maxh;

	y = img->comps[0].data;
	cb = img->comps[1].data;
	cr = img->comps[2].data;

	d0 = r = (int*)malloc(sizeof(int) * max);
	d1 = g = (int*)malloc(sizeof(int) * max);
	d2 = b = (int*)malloc(sizeof(int) * max);

	for(i = 0; i < max; ++i)
   {
	sycc_to_rgb(offset, upb, *y, *cb, *cr, r, g, b);	

	++y; ++cb; ++cr; ++r; ++g; ++b;
   }	
	free(img->comps[0].data); img->comps[0].data = d0;
	free(img->comps[1].data); img->comps[1].data = d1;
	free(img->comps[2].data); img->comps[2].data = d2;

}

__attribute__((used)) static void sycc422_to_rgb(opj_image_t *img)
{	
	int *d0, *d1, *d2, *r, *g, *b;
	const int *y, *cb, *cr;
	int maxw, maxh, max, offset, upb;
	int i, j;

	i = img->comps[0].prec;
	offset = 1<<(i - 1); upb = (1<<i)-1;

	maxw = img->comps[0].w; maxh = img->comps[0].h;
	max = maxw * maxh;

	y = img->comps[0].data;
	cb = img->comps[1].data;
	cr = img->comps[2].data;

	d0 = r = (int*)malloc(sizeof(int) * max);
	d1 = g = (int*)malloc(sizeof(int) * max);
	d2 = b = (int*)malloc(sizeof(int) * max);

	for(i=0; i < maxh; ++i)
   {
	for(j=0; j < maxw; j += 2)
  {
	sycc_to_rgb(offset, upb, *y, *cb, *cr, r, g, b);

	++y; ++r; ++g; ++b;

	sycc_to_rgb(offset, upb, *y, *cb, *cr, r, g, b);

	++y; ++r; ++g; ++b; ++cb; ++cr;
  }
   }
	free(img->comps[0].data); img->comps[0].data = d0;
	free(img->comps[1].data); img->comps[1].data = d1;
	free(img->comps[2].data); img->comps[2].data = d2;

	img->comps[1].w = maxw; img->comps[1].h = maxh;
	img->comps[2].w = maxw; img->comps[2].h = maxh;
	img->comps[1].dx = img->comps[0].dx;
	img->comps[2].dx = img->comps[0].dx;
	img->comps[1].dy = img->comps[0].dy;
	img->comps[2].dy = img->comps[0].dy;

}

__attribute__((used)) static void sycc420_to_rgb(opj_image_t *img)
{
	int *d0, *d1, *d2, *r, *g, *b, *nr, *ng, *nb;
	const int *y, *cb, *cr, *ny;
	int maxw, maxh, max, offset, upb;
	int i, j;

	i = img->comps[0].prec;
	offset = 1<<(i - 1); upb = (1<<i)-1;

	maxw = img->comps[0].w; maxh = img->comps[0].h;
	max = maxw * maxh;

	y = img->comps[0].data;
	cb = img->comps[1].data;
	cr = img->comps[2].data;

	d0 = r = (int*)malloc(sizeof(int) * max);
	d1 = g = (int*)malloc(sizeof(int) * max);
	d2 = b = (int*)malloc(sizeof(int) * max);

	for(i=0; i < maxh; i += 2)
   {
	ny = y + maxw;
	nr = r + maxw; ng = g + maxw; nb = b + maxw;

	for(j=0; j < maxw;  j += 2)
  {
	sycc_to_rgb(offset, upb, *y, *cb, *cr, r, g, b);

	++y; ++r; ++g; ++b;

	sycc_to_rgb(offset, upb, *y, *cb, *cr, r, g, b);

	++y; ++r; ++g; ++b;

	sycc_to_rgb(offset, upb, *ny, *cb, *cr, nr, ng, nb);

	++ny; ++nr; ++ng; ++nb;

	sycc_to_rgb(offset, upb, *ny, *cb, *cr, nr, ng, nb);

	++ny; ++nr; ++ng; ++nb; ++cb; ++cr;
  }
	y += maxw; r += maxw; g += maxw; b += maxw;
   }
	free(img->comps[0].data); img->comps[0].data = d0;
	free(img->comps[1].data); img->comps[1].data = d1;
	free(img->comps[2].data); img->comps[2].data = d2;

	img->comps[1].w = maxw; img->comps[1].h = maxh;
	img->comps[2].w = maxw; img->comps[2].h = maxh;
	img->comps[1].dx = img->comps[0].dx;
	img->comps[2].dx = img->comps[0].dx;
	img->comps[1].dy = img->comps[0].dy;
	img->comps[2].dy = img->comps[0].dy;

}

void color_sycc_to_rgb(opj_image_t *img)
{
	if(img->numcomps < 3) 
   {
	img->color_space = CLRSPC_GRAY;
	return;
   }

	if((img->comps[0].dx == 1)
	&& (img->comps[1].dx == 2)
	&& (img->comps[2].dx == 2)
	&& (img->comps[0].dy == 1)
	&& (img->comps[1].dy == 2)
	&& (img->comps[2].dy == 2))/* horizontal and vertical sub-sample */
  {
	sycc420_to_rgb(img);
  }
	else
	if((img->comps[0].dx == 1)
	&& (img->comps[1].dx == 2)
	&& (img->comps[2].dx == 2)
	&& (img->comps[0].dy == 1)
	&& (img->comps[1].dy == 1)
	&& (img->comps[2].dy == 1))/* horizontal sub-sample only */
  {
	sycc422_to_rgb(img);
  }
	else
	if((img->comps[0].dx == 1)
	&& (img->comps[1].dx == 1)
	&& (img->comps[2].dx == 1)
	&& (img->comps[0].dy == 1)
	&& (img->comps[1].dy == 1)
	&& (img->comps[2].dy == 1))/* no sub-sample */
  {
	sycc444_to_rgb(img);
  }
	else
  {
	fprintf(stderr,"%s:%d:color_sycc_to_rgb\n\tCAN NOT CONVERT\n",
	 __FILE__,__LINE__);
	return;
  }
	img->color_space = CLRSPC_SRGB;

}

