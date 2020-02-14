#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  buf ;
struct TYPE_3__ {unsigned int x; unsigned int y; int w; int h; unsigned int r; unsigned int g; unsigned int b; } ;
typedef  TYPE_1__ VObj ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int DEFAULT_HEIGHT ; 
 int DEFAULT_NB_PICT ; 
 int DEFAULT_WIDTH ; 
 int FIX (double) ; 
 int FRAC_BITS ; 
 int FRAC_ONE ; 
 int NB_OBJS ; 
 int NOISE_W ; 
 int NOISE_X ; 
 int NOISE_Y ; 
 int ONE_HALF ; 
 int SCALEBITS ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  err_if (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,int,int,int) ; 
 int /*<<< orphan*/  free (unsigned char*) ; 
 int /*<<< orphan*/  freopen (char*,char*,int /*<<< orphan*/ *) ; 
 int fwrite (unsigned char*,int,int,int /*<<< orphan*/ *) ; 
 int height ; 
 unsigned char* malloc (int) ; 
 TYPE_1__* objs ; 
 int /*<<< orphan*/  printf (char*,char const*,int,int) ; 
 unsigned char* rgb_tab ; 
 unsigned int seed ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,int) ; 
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

__attribute__((used)) static unsigned int myrnd(unsigned int *seed_ptr, int n)
{
    unsigned int seed, val;

    seed = *seed_ptr;
    seed = (seed * 314159) + 1;
    if (n == 256) {
        val = seed >> 24;
    } else {
        val = seed % n;
    }
    *seed_ptr = seed;
    return val;
}

__attribute__((used)) static int int_cos(int a)
{
    int v, neg;
    a = a & (FRAC_ONE - 1);
    if (a >= (FRAC_ONE / 2))
        a = FRAC_ONE - a;
    neg = 0;
    if (a > (FRAC_ONE / 4)) {
        neg = -1;
        a   = (FRAC_ONE / 2) - a;
    }
    v = FRAC_ONE - ((a * a) >> 4);
    v = (v ^ neg) - neg;
    return v;
}

__attribute__((used)) static void gen_image(int num, int w, int h)
{
    int r, g, b, x, y, i, dx, dy, x1, y1;
    unsigned int seed1;

    if (num == 0) {
        for (i = 0; i < NB_OBJS; i++) {
            objs[i].x = myrnd(&seed, w);
            objs[i].y = myrnd(&seed, h);
            objs[i].w = myrnd(&seed, w / 4) + 10;
            objs[i].h = myrnd(&seed, h / 4) + 10;
            objs[i].r = myrnd(&seed, 256);
            objs[i].g = myrnd(&seed, 256);
            objs[i].b = myrnd(&seed, 256);
        }
    }

    /* first a moving background with gradients */
    /* test motion estimation */
    dx = int_cos(num * FRAC_ONE / 50) * 35;
    dy = int_cos(num * FRAC_ONE / 50 + FRAC_ONE / 10) * 30;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            x1 = (x << FRAC_BITS) + dx;
            y1 = (y << FRAC_BITS) + dy;
            r  =       ((y1  * 7) >> FRAC_BITS) & 0xff;
            g  = (((x1 + y1) * 9) >> FRAC_BITS) & 0xff;
            b  =  ((x1       * 5) >> FRAC_BITS) & 0xff;
            put_pixel(x, y, r, g, b);
        }
    }

    /* then some noise with very high intensity to test saturation */
    seed1 = num;
    for (y = 0; y < NOISE_W; y++) {
        for (x = 0; x < NOISE_W; x++) {
            r = myrnd(&seed1, 256);
            g = myrnd(&seed1, 256);
            b = myrnd(&seed1, 256);
            put_pixel(x + NOISE_X, y + NOISE_Y, r, g, b);
        }
    }

    /* then moving objects */
    for (i = 0; i < NB_OBJS; i++) {
        VObj *p = &objs[i];
        seed1 = i;
        for (y = 0; y < p->h; y++) {
            for (x = 0; x < p->w; x++) {
                r = p->r;
                g = p->g;
                b = p->b;
                /* add a per object noise */
                r += myrnd(&seed1, 50);
                g += myrnd(&seed1, 50);
                b += myrnd(&seed1, 50);
                put_pixel(x + p->x, y + p->y, r, g, b);
            }
        }
        p->x += myrnd(&seed, 21) - 10;
        p->y += myrnd(&seed, 21) - 10;
    }
}

void print_help(const char* name)
{
    printf("usage: %s file|dir [w=%i] [h=%i]\n"
            "generate a test video stream\n",
            name, DEFAULT_WIDTH, DEFAULT_HEIGHT);
    exit(1);
}

int main(int argc, char **argv)
{
    int w, h, i;
    char buf[1024];
    int isdir = 0;

    if (argc < 2 || argc > 4) {
        print_help(argv[0]);
    }

    if (!freopen(argv[1], "wb", stdout))
        isdir = 1;

    w = DEFAULT_WIDTH;
    if(argc > 2) {
        w = atoi(argv[2]);
        if (w < 1) print_help(argv[0]);
    }
    h = DEFAULT_HEIGHT;
    if(argc > 3) {
        h = atoi(argv[3]);
        if (h < 1) print_help(argv[0]);
    }

    rgb_tab = malloc(w * h * 3);
    wrap    = w * 3;
    width   = w;
    height  = h;

    for (i = 0; i < DEFAULT_NB_PICT; i++) {
        gen_image(i, w, h);
        if (isdir) {
            snprintf(buf, sizeof(buf), "%s%02d.pgm", argv[1], i);
            pgmyuv_save(buf, w, h, rgb_tab);
        } else {
            pgmyuv_save(NULL, w, h, rgb_tab);
        }
    }

    free(rgb_tab);
    return 0;
}

