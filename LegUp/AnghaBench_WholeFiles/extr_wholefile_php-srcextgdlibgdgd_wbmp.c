#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/ * gdImagePtr ;
struct TYPE_22__ {int /*<<< orphan*/  (* gd_free ) (TYPE_1__*) ;} ;
typedef  TYPE_1__ gdIOCtx ;
struct TYPE_23__ {scalar_t__* bitmap; int width; int height; } ;
typedef  TYPE_2__ Wbmp ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ WBMP_BLACK ; 
 scalar_t__ WBMP_WHITE ; 
static  int _gdImageWBMPCtx (int /*<<< orphan*/ *,int,TYPE_1__*) ; 
 TYPE_2__* createwbmp (int,int,scalar_t__) ; 
 int /*<<< orphan*/  freewbmp (TYPE_2__*) ; 
 void* gdDPExtractData (TYPE_1__*,int*) ; 
 int gdGetC (TYPE_1__*) ; 
 int gdImageColorAllocate (int /*<<< orphan*/ *,int,int,int) ; 
 int /*<<< orphan*/ * gdImageCreate (int,int) ; 
 int gdImageGetPixel (int /*<<< orphan*/ *,int,int) ; 
 int gdImageSX (int /*<<< orphan*/ *) ; 
 int gdImageSY (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gdImageSetPixel (int /*<<< orphan*/ *,int,int,int) ; 
 TYPE_1__* gdNewDynamicCtx (int,int /*<<< orphan*/ *) ; 
 TYPE_1__* gdNewDynamicCtxEx (int,void*,int /*<<< orphan*/ ) ; 
 TYPE_1__* gdNewFileCtx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gdPutC (int,TYPE_1__*) ; 
 int /*<<< orphan*/  gd_error (char*) ; 
 scalar_t__ readwbmp (int (*) (void*),TYPE_1__*,TYPE_2__**) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub3 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__*) ; 
 scalar_t__ writewbmp (TYPE_2__*,void (*) (int,void*),TYPE_1__*) ; 

void gd_putout (int i, void *out)
{
	gdPutC(i, (gdIOCtx *) out);
}

int gd_getin (void *in)
{
	return (gdGetC((gdIOCtx *) in));
}

void gdImageWBMPCtx (gdImagePtr image, int fg, gdIOCtx * out)
{
	_gdImageWBMPCtx(image, fg, out);
}

__attribute__((used)) static int _gdImageWBMPCtx(gdImagePtr image, int fg, gdIOCtx *out)
{
	int x, y, pos;
	Wbmp *wbmp;

	/* create the WBMP */
	if ((wbmp = createwbmp (gdImageSX (image), gdImageSY (image), WBMP_WHITE)) == NULL) {
		gd_error("Could not create WBMP");
		return 1;
	}

	/* fill up the WBMP structure */
	pos = 0;
	for (y = 0; y < gdImageSY(image); y++) {
		for (x = 0; x < gdImageSX(image); x++) {
			if (gdImageGetPixel (image, x, y) == fg) {
				wbmp->bitmap[pos] = WBMP_BLACK;
			}
			pos++;
		}
	}

	/* write the WBMP to a gd file descriptor */
	if (writewbmp (wbmp, &gd_putout, out)) {
		freewbmp(wbmp);
		gd_error("Could not save WBMP");
		return 1;
	}

	/* des submitted this bugfix: gdFree the memory. */
	freewbmp(wbmp);

	return 0;
}

gdImagePtr gdImageCreateFromWBMPCtx (gdIOCtx * infile)
{
	/* FILE *wbmp_file; */
	Wbmp *wbmp;
	gdImagePtr im = NULL;
	int black, white;
	int col, row, pos;

	if (readwbmp (&gd_getin, infile, &wbmp)) {
		return NULL;
	}

	if (!(im = gdImageCreate (wbmp->width, wbmp->height))) {
		freewbmp (wbmp);
		return NULL;
	}

	/* create the background color */
	white = gdImageColorAllocate(im, 255, 255, 255);
	/* create foreground color */
	black = gdImageColorAllocate(im, 0, 0, 0);

	/* fill in image (in a wbmp 1 = white/ 0 = black) */
	pos = 0;
	for (row = 0; row < wbmp->height; row++) {
		for (col = 0; col < wbmp->width; col++) {
			if (wbmp->bitmap[pos++] == WBMP_WHITE) {
				gdImageSetPixel(im, col, row, white);
			} else {
				gdImageSetPixel(im, col, row, black);
			}
		}
	}

	freewbmp(wbmp);

	return im;
}

gdImagePtr gdImageCreateFromWBMP (FILE * inFile)
{
	gdImagePtr im;
	gdIOCtx *in = gdNewFileCtx(inFile);
	im = gdImageCreateFromWBMPCtx(in);
	in->gd_free(in);

	return im;
}

gdImagePtr gdImageCreateFromWBMPPtr (int size, void *data)
{
	gdImagePtr im;
	gdIOCtx *in = gdNewDynamicCtxEx(size, data, 0);
	im = gdImageCreateFromWBMPCtx(in);
	in->gd_free(in);
	return im;
}

void gdImageWBMP (gdImagePtr im, int fg, FILE * outFile)
{
	gdIOCtx *out = gdNewFileCtx(outFile);
	gdImageWBMPCtx(im, fg, out);
	out->gd_free(out);
}

void * gdImageWBMPPtr (gdImagePtr im, int *size, int fg)
{
	void *rv;
	gdIOCtx *out = gdNewDynamicCtx(2048, NULL);
	if (!_gdImageWBMPCtx(im, fg, out)) {
		rv = gdDPExtractData(out, size);
	} else {
		rv = NULL;
	}
	out->gd_free(out);

	return rv;
}

