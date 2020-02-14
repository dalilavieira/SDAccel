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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int FIX (double) ; 
 int ONE_HALF ; 
 int SCALEBITS ; 
 int /*<<< orphan*/  err_if (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,int,int,int) ; 
 int /*<<< orphan*/  free (unsigned char*) ; 
 int fwrite (unsigned char*,int,int,int /*<<< orphan*/ *) ; 
 int height ; 
 unsigned char* malloc (int) ; 
 unsigned char* rgb_tab ; 
 int /*<<< orphan*/ * stdout ; 
 int width ; 
 int wrap ; 

__attribute__((used)) static void rgb24_to_yuv420p(unsigned char *lum, unsigned char *cb,
                             unsigned char *cr, const unsigned char *src,
                             int width, int height)
{
    int wrap, wrap3, x, y;
    int r, g, b, r1, g1, b1;
    const unsigned char *p;

    wrap  = width;
    wrap3 = width * 3;
    p     = src;
    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 2) {
            r       = p[0];
            g       = p[1];
            b       = p[2];
            r1      = r;
            g1      = g;
            b1      = b;
            lum[0]  = (FIX(0.29900) * r + FIX(0.58700) * g +
                       FIX(0.11400) * b + ONE_HALF) >> SCALEBITS;
            r       = p[3];
            g       = p[4];
            b       = p[5];
            r1     += r;
            g1     += g;
            b1     += b;
            lum[1]  = (FIX(0.29900) * r + FIX(0.58700) * g +
                       FIX(0.11400) * b + ONE_HALF) >> SCALEBITS;
            p      += wrap3;
            lum    += wrap;

            r       = p[0];
            g       = p[1];
            b       = p[2];
            r1     += r;
            g1     += g;
            b1     += b;
            lum[0]  = (FIX(0.29900) * r + FIX(0.58700) * g +
                       FIX(0.11400) * b + ONE_HALF) >> SCALEBITS;
            r       = p[3];
            g       = p[4];
            b       = p[5];
            r1     += r;
            g1     += g;
            b1     += b;
            lum[1]  = (FIX(0.29900) * r + FIX(0.58700) * g +
                       FIX(0.11400) * b + ONE_HALF) >> SCALEBITS;

            cb[0]   = ((- FIX(0.16874) * r1 - FIX(0.33126) * g1 +
                       FIX(0.50000) * b1 + 4 * ONE_HALF - 1) >> (SCALEBITS + 2)) + 128;
            cr[0]   = ((FIX(0.50000) * r1 - FIX(0.41869) * g1 -
                       FIX(0.08131) * b1 + 4 * ONE_HALF - 1) >> (SCALEBITS + 2)) + 128;

            cb++;
            cr++;
            p   += -wrap3 + 2 * 3;
            lum += -wrap  + 2;
        }
        p   += wrap3;
        lum += wrap;
    }
}

__attribute__((used)) static void pgmyuv_save(const char *filename, int w, int h,
                        const unsigned char *rgb_tab)
{
    FILE *f;
    int i, h2, w2;
    unsigned char *cb, *cr;
    unsigned char *lum_tab, *cb_tab, *cr_tab;

    lum_tab = malloc(w * h);
    cb_tab  = malloc(w * h / 4);
    cr_tab  = malloc(w * h / 4);

    rgb24_to_yuv420p(lum_tab, cb_tab, cr_tab, rgb_tab, w, h);

    if (filename) {
        f = fopen(filename, "wb");
        fprintf(f, "P5\n%d %d\n%d\n", w, h * 3 / 2, 255);
    } else {
        f = stdout;
    }

    err_if(fwrite(lum_tab, 1, w * h, f) != w * h);
    h2 = h / 2;
    w2 = w / 2;
    cb = cb_tab;
    cr = cr_tab;

    if (filename) {
        for (i = 0; i < h2; i++) {
            err_if(fwrite(cb, 1, w2, f) != w2);
            err_if(fwrite(cr, 1, w2, f) != w2);
            cb += w2;
            cr += w2;
        }
        fclose(f);
    } else {
        for (i = 0; i < h2; i++) {
            err_if(fwrite(cb, 1, w2, f) != w2);
            cb += w2;
        }
        for (i = 0; i < h2; i++) {
            err_if(fwrite(cr, 1, w2, f) != w2);
            cr += w2;
        }
    }

    free(lum_tab);
    free(cb_tab);
    free(cr_tab);
}

__attribute__((used)) static void put_pixel(int x, int y, int r, int g, int b)
{
    unsigned char *p;

    if (x < 0 || x >= width ||
        y < 0 || y >= height)
        return;

    p    = rgb_tab + y * wrap + x * 3;
    p[0] = r;
    p[1] = g;
    p[2] = b;
}

