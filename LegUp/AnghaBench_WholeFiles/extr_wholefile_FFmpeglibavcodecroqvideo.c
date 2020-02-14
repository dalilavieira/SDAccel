#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {unsigned char* y; unsigned char u; unsigned char v; } ;
typedef  TYPE_3__ roq_cell ;
struct TYPE_15__ {int width; int height; TYPE_1__* last_frame; TYPE_2__* current_frame; int /*<<< orphan*/  avctx; } ;
struct TYPE_13__ {int* linesize; unsigned char** data; } ;
struct TYPE_12__ {unsigned char** data; int* linesize; } ;
typedef  TYPE_4__ RoqContext ;

/* Variables and functions */
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,int) ; 

__attribute__((used)) static inline void block_copy(unsigned char *out, unsigned char *in,
                              int outstride, int instride, int sz)
{
    int rows = sz;
    while(rows--) {
        memcpy(out, in, sz);
        out += outstride;
        in += instride;
    }
}

void ff_apply_vector_2x2(RoqContext *ri, int x, int y, roq_cell *cell)
{
    unsigned char *bptr;
    int boffs,stride;

    stride = ri->current_frame->linesize[0];
    boffs = y*stride + x;

    bptr = ri->current_frame->data[0] + boffs;
    bptr[0       ] = cell->y[0];
    bptr[1       ] = cell->y[1];
    bptr[stride  ] = cell->y[2];
    bptr[stride+1] = cell->y[3];

    stride = ri->current_frame->linesize[1];
    boffs = y*stride + x;

    bptr = ri->current_frame->data[1] + boffs;
    bptr[0       ] =
    bptr[1       ] =
    bptr[stride  ] =
    bptr[stride+1] = cell->u;

    bptr = ri->current_frame->data[2] + boffs;
    bptr[0       ] =
    bptr[1       ] =
    bptr[stride  ] =
    bptr[stride+1] = cell->v;
}

void ff_apply_vector_4x4(RoqContext *ri, int x, int y, roq_cell *cell)
{
    unsigned char *bptr;
    int boffs,stride;

    stride = ri->current_frame->linesize[0];
    boffs = y*stride + x;

    bptr = ri->current_frame->data[0] + boffs;
    bptr[         0] = bptr[         1] = bptr[stride    ] = bptr[stride  +1] = cell->y[0];
    bptr[         2] = bptr[         3] = bptr[stride  +2] = bptr[stride  +3] = cell->y[1];
    bptr[stride*2  ] = bptr[stride*2+1] = bptr[stride*3  ] = bptr[stride*3+1] = cell->y[2];
    bptr[stride*2+2] = bptr[stride*2+3] = bptr[stride*3+2] = bptr[stride*3+3] = cell->y[3];

    stride = ri->current_frame->linesize[1];
    boffs = y*stride + x;

    bptr = ri->current_frame->data[1] + boffs;
    bptr[         0] = bptr[         1] = bptr[stride    ] = bptr[stride  +1] =
    bptr[         2] = bptr[         3] = bptr[stride  +2] = bptr[stride  +3] =
    bptr[stride*2  ] = bptr[stride*2+1] = bptr[stride*3  ] = bptr[stride*3+1] =
    bptr[stride*2+2] = bptr[stride*2+3] = bptr[stride*3+2] = bptr[stride*3+3] = cell->u;

    bptr = ri->current_frame->data[2] + boffs;
    bptr[         0] = bptr[         1] = bptr[stride    ] = bptr[stride  +1] =
    bptr[         2] = bptr[         3] = bptr[stride  +2] = bptr[stride  +3] =
    bptr[stride*2  ] = bptr[stride*2+1] = bptr[stride*3  ] = bptr[stride*3+1] =
    bptr[stride*2+2] = bptr[stride*2+3] = bptr[stride*3+2] = bptr[stride*3+3] = cell->v;
}

__attribute__((used)) static inline void apply_motion_generic(RoqContext *ri, int x, int y, int deltax,
                                        int deltay, int sz)
{
    int mx, my, cp;

    mx = x + deltax;
    my = y + deltay;

    /* check MV against frame boundaries */
    if ((mx < 0) || (mx > ri->width - sz) ||
        (my < 0) || (my > ri->height - sz)) {
        av_log(ri->avctx, AV_LOG_ERROR, "motion vector out of bounds: MV = (%d, %d), boundaries = (0, 0, %d, %d)\n",
            mx, my, ri->width, ri->height);
        return;
    }

    if (!ri->last_frame->data[0]) {
        av_log(ri->avctx, AV_LOG_ERROR, "Invalid decode type. Invalid header?\n");
        return;
    }

    for(cp = 0; cp < 3; cp++) {
        int outstride = ri->current_frame->linesize[cp];
        int instride  = ri->last_frame   ->linesize[cp];
        block_copy(ri->current_frame->data[cp] + y*outstride + x,
                   ri->last_frame->data[cp] + my*instride + mx,
                   outstride, instride, sz);
    }
}

void ff_apply_motion_4x4(RoqContext *ri, int x, int y,
                             int deltax, int deltay)
{
    apply_motion_generic(ri, x, y, deltax, deltay, 4);
}

void ff_apply_motion_8x8(RoqContext *ri, int x, int y,
                             int deltax, int deltay)
{
    apply_motion_generic(ri, x, y, deltax, deltay, 8);
}

