#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  scalar_t__ int64_t ;
struct TYPE_21__ {char* bitmap; } ;
typedef  TYPE_1__ XFaceContext ;
struct TYPE_26__ {TYPE_1__* priv_data; } ;
struct TYPE_25__ {char** data; int /*<<< orphan*/ * linesize; } ;
struct TYPE_24__ {int size; scalar_t__* data; } ;
struct TYPE_23__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_22__ {scalar_t__ offset; scalar_t__ range; } ;
typedef  TYPE_2__ ProbRange ;
typedef  TYPE_3__ BigInt ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVFrame ;
typedef  TYPE_6__ AVCodecContext ;

/* Variables and functions */
 int /*<<< orphan*/  AV_LOG_WARNING ; 
#define  XFACE_COLOR_BLACK 129 
#define  XFACE_COLOR_WHITE 128 
 scalar_t__ XFACE_FIRST_PRINT ; 
 scalar_t__ XFACE_LAST_PRINT ; 
 int XFACE_MAX_DIGITS ; 
 int XFACE_PIXELS ; 
 scalar_t__ XFACE_PRINTS ; 
 int XFACE_WIDTH ; 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  ff_big_add (TYPE_3__*,scalar_t__) ; 
 int /*<<< orphan*/  ff_big_div (TYPE_3__*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  ff_big_mul (TYPE_3__*,scalar_t__) ; 
 int ff_get_buffer (TYPE_6__*,TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_xface_generate_face (char*,char*) ; 
 TYPE_2__* ff_xface_probranges_2x2 ; 
 TYPE_2__** ff_xface_probranges_per_level ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int pop_integer(BigInt *b, const ProbRange *pranges)
{
    uint8_t r;
    int i;

    /* extract the last byte into r, and shift right b by 8 bits */
    ff_big_div(b, 0, &r);

    i = 0;
    while (r < pranges->offset || r >= pranges->range + pranges->offset) {
        pranges++;
        i++;
    }
    ff_big_mul(b, pranges->range);
    ff_big_add(b, r - pranges->offset);
    return i;
}

__attribute__((used)) static void pop_greys(BigInt *b, char *bitmap, int w, int h)
{
    if (w > 3) {
        w /= 2;
        h /= 2;
        pop_greys(b, bitmap,                       w, h);
        pop_greys(b, bitmap + w,                   w, h);
        pop_greys(b, bitmap + XFACE_WIDTH * h,     w, h);
        pop_greys(b, bitmap + XFACE_WIDTH * h + w, w, h);
    } else {
        w = pop_integer(b, ff_xface_probranges_2x2);
        if (w & 1) bitmap[0]               = 1;
        if (w & 2) bitmap[1]               = 1;
        if (w & 4) bitmap[XFACE_WIDTH]     = 1;
        if (w & 8) bitmap[XFACE_WIDTH + 1] = 1;
    }
}

__attribute__((used)) static void decode_block(BigInt *b, char *bitmap, int w, int h, int level)
{
    switch (pop_integer(b, &ff_xface_probranges_per_level[level][0])) {
    case XFACE_COLOR_WHITE:
        return;
    case XFACE_COLOR_BLACK:
        pop_greys(b, bitmap, w, h);
        return;
    default:
        w /= 2;
        h /= 2;
        level++;
        decode_block(b, bitmap,                       w, h, level);
        decode_block(b, bitmap + w,                   w, h, level);
        decode_block(b, bitmap + h * XFACE_WIDTH,     w, h, level);
        decode_block(b, bitmap + w + h * XFACE_WIDTH, w, h, level);
        return;
    }
}

__attribute__((used)) static int xface_decode_frame(AVCodecContext *avctx,
                              void *data, int *got_frame,
                              AVPacket *avpkt)
{
    XFaceContext *xface = avctx->priv_data;
    int ret, i, j, k;
    uint8_t byte;
    BigInt b = {0};
    char *buf;
    int64_t c;
    AVFrame *frame = data;

    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
        return ret;

    for (i = 0, k = 0; i < avpkt->size && avpkt->data[i]; i++) {
        c = avpkt->data[i];

        /* ignore invalid digits */
        if (c < XFACE_FIRST_PRINT || c > XFACE_LAST_PRINT)
            continue;

        if (++k > XFACE_MAX_DIGITS) {
            av_log(avctx, AV_LOG_WARNING,
                   "Buffer is longer than expected, truncating at byte %d\n", i);
            break;
        }
        ff_big_mul(&b, XFACE_PRINTS);
        ff_big_add(&b, c - XFACE_FIRST_PRINT);
    }

    /* decode image and put it in bitmap */
    memset(xface->bitmap, 0, XFACE_PIXELS);
    buf = xface->bitmap;
    decode_block(&b, buf,                         16, 16, 0);
    decode_block(&b, buf + 16,                    16, 16, 0);
    decode_block(&b, buf + 32,                    16, 16, 0);
    decode_block(&b, buf + XFACE_WIDTH * 16,      16, 16, 0);
    decode_block(&b, buf + XFACE_WIDTH * 16 + 16, 16, 16, 0);
    decode_block(&b, buf + XFACE_WIDTH * 16 + 32, 16, 16, 0);
    decode_block(&b, buf + XFACE_WIDTH * 32     , 16, 16, 0);
    decode_block(&b, buf + XFACE_WIDTH * 32 + 16, 16, 16, 0);
    decode_block(&b, buf + XFACE_WIDTH * 32 + 32, 16, 16, 0);

    ff_xface_generate_face(xface->bitmap, xface->bitmap);

    /* convert image from 1=black 0=white bitmap to MONOWHITE */
    buf = frame->data[0];
    for (i = 0, j = 0, k = 0, byte = 0; i < XFACE_PIXELS; i++) {
        byte += xface->bitmap[i];
        if (k == 7) {
            buf[j++] = byte;
            byte = k = 0;
        } else {
            k++;
            byte <<= 1;
        }
        if (j == XFACE_WIDTH/8) {
            j = 0;
            buf += frame->linesize[0];
        }
    }

    *got_frame = 1;

    return avpkt->size;
}

