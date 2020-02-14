#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint8_t ;
typedef  size_t uint16_t ;
struct TYPE_12__ {size_t* table; } ;
struct TYPE_11__ {int (* process ) (int /*<<< orphan*/ *,TYPE_3__*,int,int) ;int /*<<< orphan*/ * dst; TYPE_2__* src; TYPE_4__* instance; } ;
struct TYPE_10__ {int width; TYPE_1__* plane; } ;
struct TYPE_9__ {size_t** line; int sliceY; } ;
typedef  TYPE_2__ SwsSlice ;
typedef  TYPE_3__ SwsFilterDescriptor ;
typedef  int /*<<< orphan*/  SwsContext ;
typedef  TYPE_4__ GammaContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 size_t AV_RL16 (size_t*) ; 
 int /*<<< orphan*/  AV_WB16 (size_t*,int) ; 
 int /*<<< orphan*/  AV_WL16 (size_t*,size_t) ; 
 int /*<<< orphan*/  ENOMEM ; 
 TYPE_4__* av_malloc (int) ; 

__attribute__((used)) static inline void fillPlane16(uint8_t *plane, int stride, int width, int height, int y,
                               int alpha, int bits, const int big_endian)
{
    int i, j;
    uint8_t *ptr = plane + stride * y;
    int v = alpha ? 0xFFFF>>(16-bits) : (1<<(bits-1));
    for (i = 0; i < height; i++) {
#define FILL(wfunc) \
        for (j = 0; j < width; j++) {\
            wfunc(ptr+2*j, v);\
        }
        if (big_endian) {
            FILL(AV_WB16);
        } else {
            FILL(AV_WL16);
        }
        ptr += stride;
    }
}

__attribute__((used)) static int gamma_convert(SwsContext *c, SwsFilterDescriptor *desc, int sliceY, int sliceH)
{
    GammaContext *instance = desc->instance;
    uint16_t *table = instance->table;
    int srcW = desc->src->width;

    int i;
    for (i = 0; i < sliceH; ++i) {
        uint8_t ** src = desc->src->plane[0].line;
        int src_pos = sliceY+i - desc->src->plane[0].sliceY;

        uint16_t *src1 = (uint16_t*)*(src+src_pos);
        int j;
        for (j = 0; j < srcW; ++j) {
            uint16_t r = AV_RL16(src1 + j*4 + 0);
            uint16_t g = AV_RL16(src1 + j*4 + 1);
            uint16_t b = AV_RL16(src1 + j*4 + 2);

            AV_WL16(src1 + j*4 + 0, table[r]);
            AV_WL16(src1 + j*4 + 1, table[g]);
            AV_WL16(src1 + j*4 + 2, table[b]);
        }

    }
    return sliceH;
}

int ff_init_gamma_convert(SwsFilterDescriptor *desc, SwsSlice * src, uint16_t *table)
{
    GammaContext *li = av_malloc(sizeof(GammaContext));
    if (!li)
        return AVERROR(ENOMEM);
    li->table = table;

    desc->instance = li;
    desc->src = src;
    desc->dst = NULL;
    desc->process = &gamma_convert;

    return 0;
}

