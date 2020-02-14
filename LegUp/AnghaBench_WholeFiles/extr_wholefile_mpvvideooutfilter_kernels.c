#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
struct filter_window {double (* weight ) (struct filter_window*,double) ;double blur; double taper; double radius; scalar_t__ name; } ;
struct filter_kernel {int clamp; scalar_t__ size; double filter_scale; double radius_cutoff; scalar_t__ value_cutoff; struct filter_window f; scalar_t__ polar; struct filter_window w; } ;
struct TYPE_19__ {double radius; double* params; } ;
typedef  TYPE_1__ params ;

/* Variables and functions */
 double M_PI ; 
 int POW3 (double) ; 
 int /*<<< orphan*/  assert (int) ; 
 double cos (double) ; 
 double exp (double) ; 
 int fabs (double) ; 
 double fmax (double,int) ; 
 double j1 (double) ; 
 struct filter_kernel* mp_filter_kernels ; 
 struct filter_window* mp_filter_windows ; 
 double sin (double) ; 
 double sqrt (double) ; 
 scalar_t__ strcmp (scalar_t__,char const*) ; 
 double stub1 (struct filter_window*,double) ; 

const struct filter_window *mp_find_filter_window(const char *name)
{
    if (!name)
        return NULL;
    for (const struct filter_window *w = mp_filter_windows; w->name; w++) {
        if (strcmp(w->name, name) == 0)
            return w;
    }
    return NULL;
}

const struct filter_kernel *mp_find_filter_kernel(const char *name)
{
    if (!name)
        return NULL;
    for (const struct filter_kernel *k = mp_filter_kernels; k->f.name; k++) {
        if (strcmp(k->f.name, name) == 0)
            return k;
    }
    return NULL;
}

__attribute__((used)) static double sample_window(struct filter_window *kernel, double x)
{
    if (!kernel->weight)
        return 1.0;

    // All windows are symmetric, this makes life easier
    x = fabs(x);

    // Stretch and taper the window size as needed
    x = kernel->blur > 0.0 ? x / kernel->blur : x;
    x = x <= kernel->taper ? 0.0 : (x - kernel->taper) / (1 - kernel->taper);

    if (x < kernel->radius)
        return kernel->weight(kernel, x);
    return 0.0;
}

__attribute__((used)) static double sample_filter(struct filter_kernel *filter, double x)
{
    // The window is always stretched to the entire kernel
    double w = sample_window(&filter->w, x / filter->f.radius * filter->w.radius);
    double k = w * sample_window(&filter->f, x);
    return k < 0 ? (1 - filter->clamp) * k : k;
}

__attribute__((used)) static void mp_compute_weights(struct filter_kernel *filter, double f,
                               float *out_w)
{
    assert(filter->size > 0);
    double sum = 0;
    for (int n = 0; n < filter->size; n++) {
        double x = f - (n - filter->size / 2 + 1);
        double w = sample_filter(filter, x / filter->filter_scale);
        out_w[n] = w;
        sum += w;
    }
    // Normalize to preserve energy
    for (int n = 0; n < filter->size; n++)
        out_w[n] /= sum;
}

void mp_compute_lut(struct filter_kernel *filter, int count, int stride,
                    float *out_array)
{
    if (filter->polar) {
        filter->radius_cutoff = 0.0;
        // Compute a 1D array indexed by radius
        for (int x = 0; x < count; x++) {
            double r = x * filter->f.radius / (count - 1);
            out_array[x] = sample_filter(filter, r);

            if (fabs(out_array[x]) > filter->value_cutoff)
                filter->radius_cutoff = r;
        }
    } else {
        // Compute a 2D array indexed by subpixel position
        for (int n = 0; n < count; n++) {
            mp_compute_weights(filter, n / (double)(count - 1),
                               out_array + stride * n);
        }
    }
}

__attribute__((used)) static double box(params *p, double x)
{
    // This is mathematically 1.0 everywhere, the clipping is done implicitly
    // based on the radius.
    return 1.0;
}

__attribute__((used)) static double triangle(params *p, double x)
{
    return fmax(0.0, 1.0 - fabs(x / p->radius));
}

__attribute__((used)) static double hanning(params *p, double x)
{
    return 0.5 + 0.5 * cos(M_PI * x);
}

__attribute__((used)) static double hamming(params *p, double x)
{
    return 0.54 + 0.46 * cos(M_PI * x);
}

__attribute__((used)) static double quadric(params *p, double x)
{
    if (x <  0.75) {
        return 0.75 - x * x;
    } else if (x <  1.5) {
        double t = x - 1.5;
        return 0.5 * t * t;
    }
    return 0.0;
}

__attribute__((used)) static double bicubic(params *p, double x)
{
    return (1.0/6.0) * (      POW3(x + 2)
                        - 4 * POW3(x + 1)
                        + 6 * POW3(x)
                        - 4 * POW3(x - 1));
}

__attribute__((used)) static double bessel_i0(double x)
{
    double s = 1.0;
    double y = x * x / 4.0;
    double t = y;
    int i = 2;
    while (t > 1e-12) {
        s += t;
        t *= y / (i * i);
        i += 1;
    }
    return s;
}

__attribute__((used)) static double kaiser(params *p, double x)
{
    if (x > 1)
        return 0;
    double i0a = 1.0 / bessel_i0(p->params[1]);
    return bessel_i0(p->params[0] * sqrt(1.0 - x * x)) * i0a;
}

__attribute__((used)) static double blackman(params *p, double x)
{
    double a = p->params[0];
    double a0 = (1-a)/2.0, a1 = 1/2.0, a2 = a/2.0;
    double pix = M_PI * x;
    return a0 + a1*cos(pix) + a2*cos(2 * pix);
}

__attribute__((used)) static double welch(params *p, double x)
{
    return 1.0 - x*x;
}

__attribute__((used)) static double cubic_bc(params *p, double x)
{
    double b = p->params[0],
           c = p->params[1];
    double p0 = (6.0 - 2.0 * b) / 6.0,
           p2 = (-18.0 + 12.0 * b + 6.0 * c) / 6.0,
           p3 = (12.0 - 9.0 * b - 6.0 * c) / 6.0,
           q0 = (8.0 * b + 24.0 * c) / 6.0,
           q1 = (-12.0 * b - 48.0 * c) / 6.0,
           q2 = (6.0 * b + 30.0 * c) / 6.0,
           q3 = (-b - 6.0 * c) / 6.0;

    if (x < 1.0) {
        return p0 + x * x * (p2 + x * p3);
    } else if (x < 2.0) {
        return q0 + x * (q1 + x * (q2 + x * q3));
    }
    return 0.0;
}

__attribute__((used)) static double spline16(params *p, double x)
{
    if (x < 1.0) {
        return ((x - 9.0/5.0 ) * x - 1.0/5.0 ) * x + 1.0;
    } else {
        return ((-1.0/3.0 * (x-1) + 4.0/5.0) * (x-1) - 7.0/15.0 ) * (x-1);
    }
}

__attribute__((used)) static double spline36(params *p, double x)
{
    if (x < 1.0) {
        return ((13.0/11.0 * x - 453.0/209.0) * x - 3.0/209.0) * x + 1.0;
    } else if (x < 2.0) {
        return ((-6.0/11.0 * (x-1) + 270.0/209.0) * (x-1) - 156.0/ 209.0) * (x-1);
    } else {
        return ((1.0/11.0 * (x-2) - 45.0/209.0) * (x-2) +  26.0/209.0) * (x-2);
    }
}

__attribute__((used)) static double spline64(params *p, double x)
{
    if (x < 1.0) {
        return ((49.0/41.0 * x - 6387.0/2911.0) * x - 3.0/2911.0) * x + 1.0;
    } else if (x < 2.0) {
        return ((-24.0/41.0 * (x-1) + 4032.0/2911.0) * (x-1) - 2328.0/2911.0) * (x-1);
    } else if (x < 3.0) {
        return ((6.0/41.0 * (x-2) - 1008.0/2911.0) * (x-2) + 582.0/2911.0) * (x-2);
    } else {
        return ((-1.0/41.0 * (x-3) + 168.0/2911.0) * (x-3) - 97.0/2911.0) * (x-3);
    }
}

__attribute__((used)) static double gaussian(params *p, double x)
{
    return exp(-2.0 * x * x / p->params[0]);
}

__attribute__((used)) static double sinc(params *p, double x)
{
    if (fabs(x) < 1e-8)
        return 1.0;
    x *= M_PI;
    return sin(x) / x;
}

__attribute__((used)) static double jinc(params *p, double x)
{
    if (fabs(x) < 1e-8)
        return 1.0;
    x *= M_PI;
    return 2.0 * j1(x) / x;
}

__attribute__((used)) static double sphinx(params *p, double x)
{
    if (fabs(x) < 1e-8)
        return 1.0;
    x *= M_PI;
    return 3.0 * (sin(x) - x * cos(x)) / (x * x * x);
}

