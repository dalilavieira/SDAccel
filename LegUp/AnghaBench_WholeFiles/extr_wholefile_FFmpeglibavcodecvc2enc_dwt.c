#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int ptrdiff_t ;
typedef  int dwtcoef ;
struct TYPE_7__ {int* buffer; } ;
typedef  TYPE_1__ VC2TransformContext ;

/* Variables and functions */
 int /*<<< orphan*/  deinterleave (int*,int,int,int,int*) ; 
 int /*<<< orphan*/  dwt_haar (TYPE_1__*,int*,int,int,int,int) ; 

__attribute__((used)) static void vc2_subband_dwt_97(VC2TransformContext *t, dwtcoef *data,
                               ptrdiff_t stride, int width, int height)
{
    int x, y;
    dwtcoef *datal = data, *synth = t->buffer, *synthl = synth;
    const ptrdiff_t synth_width  = width  << 1;
    const ptrdiff_t synth_height = height << 1;

    /*
     * Shift in one bit that is used for additional precision and copy
     * the data to the buffer.
     */
    for (y = 0; y < synth_height; y++) {
        for (x = 0; x < synth_width; x++)
            synthl[x] = datal[x] << 1;
        synthl += synth_width;
        datal += stride;
    }

    /* Horizontal synthesis. */
    synthl = synth;
    for (y = 0; y < synth_height; y++) {
        /* Lifting stage 2. */
        synthl[1] -= (8*synthl[0] + 9*synthl[2] - synthl[4] + 8) >> 4;
        for (x = 1; x < width - 2; x++)
            synthl[2*x + 1] -= (9*synthl[2*x] + 9*synthl[2*x + 2] - synthl[2*x + 4] -
                                synthl[2 * x - 2] + 8) >> 4;
        synthl[synth_width - 1] -= (17*synthl[synth_width - 2] -
                                    synthl[synth_width - 4] + 8) >> 4;
        synthl[synth_width - 3] -= (8*synthl[synth_width - 2] +
                                    9*synthl[synth_width - 4] -
                                    synthl[synth_width - 6] + 8) >> 4;
        /* Lifting stage 1. */
        synthl[0] += (synthl[1] + synthl[1] + 2) >> 2;
        for (x = 1; x < width - 1; x++)
            synthl[2*x] += (synthl[2*x - 1] + synthl[2*x + 1] + 2) >> 2;

        synthl[synth_width - 2] += (synthl[synth_width - 3] +
                                    synthl[synth_width - 1] + 2) >> 2;
        synthl += synth_width;
    }

    /* Vertical synthesis: Lifting stage 2. */
    synthl = synth + synth_width;
    for (x = 0; x < synth_width; x++)
        synthl[x] -= (8*synthl[x - synth_width] + 9*synthl[x + synth_width] -
                      synthl[x + 3 * synth_width] + 8) >> 4;

    synthl = synth + (synth_width << 1);
    for (y = 1; y < height - 2; y++) {
        for (x = 0; x < synth_width; x++)
            synthl[x + synth_width] -= (9*synthl[x] +
                                        9*synthl[x + 2 * synth_width] -
                                        synthl[x - 2 * synth_width] -
                                        synthl[x + 4 * synth_width] + 8) >> 4;
        synthl += synth_width << 1;
    }

    synthl = synth + (synth_height - 1) * synth_width;
    for (x = 0; x < synth_width; x++) {
        synthl[x] -= (17*synthl[x - synth_width] -
                      synthl[x - 3*synth_width] + 8) >> 4;
                      synthl[x - 2*synth_width] -= (9*synthl[x - 3*synth_width] +
                      8*synthl[x - 1*synth_width] - synthl[x - 5*synth_width] + 8) >> 4;
    }

    /* Vertical synthesis: Lifting stage 1. */
    synthl = synth;
    for (x = 0; x < synth_width; x++)
        synthl[x] += (synthl[x + synth_width] + synthl[x + synth_width] + 2) >> 2;

    synthl = synth + (synth_width << 1);
    for (y = 1; y < height - 1; y++) {
        for (x = 0; x < synth_width; x++)
            synthl[x] += (synthl[x - synth_width] + synthl[x + synth_width] + 2) >> 2;
        synthl += synth_width << 1;
    }

    synthl = synth + (synth_height - 2) * synth_width;
    for (x = 0; x < synth_width; x++)
        synthl[x] += (synthl[x - synth_width] + synthl[x + synth_width] + 2) >> 2;

    deinterleave(data, stride, width, height, synth);
}

__attribute__((used)) static void vc2_subband_dwt_53(VC2TransformContext *t, dwtcoef *data,
                               ptrdiff_t stride, int width, int height)
{
    int x, y;
    dwtcoef *synth = t->buffer, *synthl = synth, *datal = data;
    const ptrdiff_t synth_width  = width  << 1;
    const ptrdiff_t synth_height = height << 1;

    /*
     * Shift in one bit that is used for additional precision and copy
     * the data to the buffer.
     */
    for (y = 0; y < synth_height; y++) {
        for (x = 0; x < synth_width; x++)
            synthl[x] = datal[x] << 1;
        synthl += synth_width;
        datal  += stride;
    }

    /* Horizontal synthesis. */
    synthl = synth;
    for (y = 0; y < synth_height; y++) {
        /* Lifting stage 2. */
        for (x = 0; x < width - 1; x++)
            synthl[2 * x + 1] -= (synthl[2 * x] + synthl[2 * x + 2] + 1) >> 1;

        synthl[synth_width - 1] -= (2*synthl[synth_width - 2] + 1) >> 1;

        /* Lifting stage 1. */
        synthl[0] += (2*synthl[1] + 2) >> 2;
        for (x = 1; x < width - 1; x++)
            synthl[2 * x] += (synthl[2 * x - 1] + synthl[2 * x + 1] + 2) >> 2;

        synthl[synth_width - 2] += (synthl[synth_width - 3] + synthl[synth_width - 1] + 2) >> 2;

        synthl += synth_width;
    }

    /* Vertical synthesis: Lifting stage 2. */
    synthl = synth + synth_width;
    for (x = 0; x < synth_width; x++)
        synthl[x] -= (synthl[x - synth_width] + synthl[x + synth_width] + 1) >> 1;

    synthl = synth + (synth_width << 1);
    for (y = 1; y < height - 1; y++) {
        for (x = 0; x < synth_width; x++)
            synthl[x + synth_width] -= (synthl[x] + synthl[x + synth_width * 2] + 1) >> 1;
        synthl += (synth_width << 1);
    }

    synthl = synth + (synth_height - 1) * synth_width;
    for (x = 0; x < synth_width; x++)
        synthl[x] -= (2*synthl[x - synth_width] + 1) >> 1;

    /* Vertical synthesis: Lifting stage 1. */
    synthl = synth;
    for (x = 0; x < synth_width; x++)
        synthl[x] += (2*synthl[synth_width + x] + 2) >> 2;

    synthl = synth + (synth_width << 1);
    for (y = 1; y < height - 1; y++) {
        for (x = 0; x < synth_width; x++)
            synthl[x] += (synthl[x + synth_width] + synthl[x - synth_width] + 2) >> 2;
        synthl += (synth_width << 1);
    }

    synthl = synth + (synth_height - 2)*synth_width;
    for (x = 0; x < synth_width; x++)
        synthl[x] += (synthl[x - synth_width] + synthl[x + synth_width] + 2) >> 2;


    deinterleave(data, stride, width, height, synth);
}

__attribute__((used)) static void vc2_subband_dwt_haar(VC2TransformContext *t, dwtcoef *data,
                                 ptrdiff_t stride, int width, int height)
{
    dwt_haar(t, data, stride, width, height, 0);
}

__attribute__((used)) static void vc2_subband_dwt_haar_shift(VC2TransformContext *t, dwtcoef *data,
                                       ptrdiff_t stride, int width, int height)
{
    dwt_haar(t, data, stride, width, height, 1);
}

