#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_9__ ;
typedef  struct TYPE_34__   TYPE_8__ ;
typedef  struct TYPE_33__   TYPE_7__ ;
typedef  struct TYPE_32__   TYPE_6__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_4__ ;
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  intbuf ;
struct TYPE_29__ {int* bitmap; } ;
typedef  TYPE_3__ XFaceContext ;
struct TYPE_35__ {int width; scalar_t__ height; TYPE_3__* priv_data; } ;
struct TYPE_34__ {int** data; int /*<<< orphan*/ * linesize; } ;
struct TYPE_33__ {int* data; int /*<<< orphan*/  flags; } ;
struct TYPE_32__ {scalar_t__ nb_words; int /*<<< orphan*/  member_0; } ;
struct TYPE_31__ {int offset; int /*<<< orphan*/  range; } ;
struct TYPE_28__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_27__ {TYPE_2__ member_0; } ;
struct TYPE_30__ {int prob_ranges_idx; TYPE_5__* prob_ranges; int /*<<< orphan*/  member_1; TYPE_1__ member_0; } ;
typedef  TYPE_4__ ProbRangesQueue ;
typedef  TYPE_5__ ProbRange ;
typedef  TYPE_6__ BigInt ;
typedef  TYPE_7__ AVPacket ;
typedef  TYPE_8__ AVFrame ;
typedef  TYPE_9__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PKT_FLAG_KEY ; 
 int /*<<< orphan*/  EINVAL ; 
 size_t XFACE_COLOR_BLACK ; 
 size_t XFACE_COLOR_GREY ; 
 size_t XFACE_COLOR_WHITE ; 
 int XFACE_FIRST_PRINT ; 
 scalar_t__ XFACE_HEIGHT ; 
 int XFACE_MAX_DIGITS ; 
 scalar_t__ XFACE_MAX_WORDS ; 
 int XFACE_PIXELS ; 
 int /*<<< orphan*/  XFACE_PRINTS ; 
 int XFACE_WIDTH ; 
 int /*<<< orphan*/  av_assert0 (int) ; 
 int /*<<< orphan*/  av_log (TYPE_9__*,int /*<<< orphan*/ ,char*,int,scalar_t__,int,scalar_t__) ; 
 int ff_alloc_packet2 (TYPE_9__*,TYPE_7__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_big_add (TYPE_6__*,int) ; 
 int /*<<< orphan*/  ff_big_div (TYPE_6__*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  ff_big_mul (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_xface_generate_face (int*,int*) ; 
 TYPE_5__* ff_xface_probranges_2x2 ; 
 TYPE_5__** ff_xface_probranges_per_level ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 

__attribute__((used)) static int all_same(char *bitmap, int w, int h)
{
    char val, *row;
    int x;

    val = *bitmap;
    while (h--) {
        row = bitmap;
        x = w;
        while (x--)
            if (*(row++) != val)
                return 0;
        bitmap += XFACE_WIDTH;
    }
    return 1;
}

__attribute__((used)) static int all_black(char *bitmap, int w, int h)
{
    if (w > 3) {
        w /= 2;
        h /= 2;
        return (all_black(bitmap, w, h) && all_black(bitmap + w, w, h) &&
                all_black(bitmap + XFACE_WIDTH * h, w, h) &&
                all_black(bitmap + XFACE_WIDTH * h + w, w, h));
    } else {
        /* at least one pixel in the 2x2 grid is non-zero */
        return *bitmap || *(bitmap + 1) ||
               *(bitmap + XFACE_WIDTH) || *(bitmap + XFACE_WIDTH + 1);
    }
}

__attribute__((used)) static int all_white(char *bitmap, int w, int h)
{
    return *bitmap == 0 && all_same(bitmap, w, h);
}

__attribute__((used)) static inline int pq_push(ProbRangesQueue *pq, const ProbRange *p)
{
    if (pq->prob_ranges_idx >= XFACE_PIXELS * 2 - 1)
        return -1;
    pq->prob_ranges[pq->prob_ranges_idx++] = *p;
    return 0;
}

__attribute__((used)) static void push_greys(ProbRangesQueue *pq, char *bitmap, int w, int h)
{
    if (w > 3) {
        w /= 2;
        h /= 2;
        push_greys(pq, bitmap,                       w, h);
        push_greys(pq, bitmap + w,                   w, h);
        push_greys(pq, bitmap + XFACE_WIDTH * h,     w, h);
        push_greys(pq, bitmap + XFACE_WIDTH * h + w, w, h);
    } else {
        const ProbRange *p = ff_xface_probranges_2x2 +
                 *bitmap +
            2 * *(bitmap + 1) +
            4 * *(bitmap + XFACE_WIDTH) +
            8 * *(bitmap + XFACE_WIDTH + 1);
        pq_push(pq, p);
    }
}

__attribute__((used)) static void encode_block(char *bitmap, int w, int h, int level, ProbRangesQueue *pq)
{
    if (all_white(bitmap, w, h)) {
        pq_push(pq, &ff_xface_probranges_per_level[level][XFACE_COLOR_WHITE]);
    } else if (all_black(bitmap, w, h)) {
        pq_push(pq, &ff_xface_probranges_per_level[level][XFACE_COLOR_BLACK]);
        push_greys(pq, bitmap, w, h);
    } else {
        pq_push(pq, &ff_xface_probranges_per_level[level][XFACE_COLOR_GREY]);
        w /= 2;
        h /= 2;
        level++;
        encode_block(bitmap,                       w, h, level, pq);
        encode_block(bitmap + w,                   w, h, level, pq);
        encode_block(bitmap + h * XFACE_WIDTH,     w, h, level, pq);
        encode_block(bitmap + w + h * XFACE_WIDTH, w, h, level, pq);
    }
}

__attribute__((used)) static void push_integer(BigInt *b, const ProbRange *prange)
{
    uint8_t r;

    ff_big_div(b, prange->range, &r);
    ff_big_mul(b, 0);
    ff_big_add(b, r + prange->offset);
}

__attribute__((used)) static int xface_encode_frame(AVCodecContext *avctx, AVPacket *pkt,
                              const AVFrame *frame, int *got_packet)
{
    XFaceContext *xface = avctx->priv_data;
    ProbRangesQueue pq = {{{ 0 }}, 0};
    uint8_t bitmap_copy[XFACE_PIXELS];
    BigInt b = {0};
    int i, j, k, ret = 0;
    const uint8_t *buf;
    uint8_t *p;
    char intbuf[XFACE_MAX_DIGITS];

    if (avctx->width || avctx->height) {
        if (avctx->width != XFACE_WIDTH || avctx->height != XFACE_HEIGHT) {
            av_log(avctx, AV_LOG_ERROR,
                   "Size value %dx%d not supported, only accepts a size of %dx%d\n",
                   avctx->width, avctx->height, XFACE_WIDTH, XFACE_HEIGHT);
            return AVERROR(EINVAL);
        }
    }
    avctx->width  = XFACE_WIDTH;
    avctx->height = XFACE_HEIGHT;

    /* convert image from MONOWHITE to 1=black 0=white bitmap */
    buf = frame->data[0];
    i = j = 0;
    do {
        for (k = 0; k < 8; k++)
            xface->bitmap[i++] = (buf[j]>>(7-k))&1;
        if (++j == XFACE_WIDTH/8) {
            buf += frame->linesize[0];
            j = 0;
        }
    } while (i < XFACE_PIXELS);

    /* create a copy of bitmap */
    memcpy(bitmap_copy, xface->bitmap, XFACE_PIXELS);
    ff_xface_generate_face(xface->bitmap, bitmap_copy);

    encode_block(xface->bitmap,                         16, 16, 0, &pq);
    encode_block(xface->bitmap + 16,                    16, 16, 0, &pq);
    encode_block(xface->bitmap + 32,                    16, 16, 0, &pq);
    encode_block(xface->bitmap + XFACE_WIDTH * 16,      16, 16, 0, &pq);
    encode_block(xface->bitmap + XFACE_WIDTH * 16 + 16, 16, 16, 0, &pq);
    encode_block(xface->bitmap + XFACE_WIDTH * 16 + 32, 16, 16, 0, &pq);
    encode_block(xface->bitmap + XFACE_WIDTH * 32,      16, 16, 0, &pq);
    encode_block(xface->bitmap + XFACE_WIDTH * 32 + 16, 16, 16, 0, &pq);
    encode_block(xface->bitmap + XFACE_WIDTH * 32 + 32, 16, 16, 0, &pq);

    while (pq.prob_ranges_idx > 0)
        push_integer(&b, &pq.prob_ranges[--pq.prob_ranges_idx]);

    /* write the inverted big integer in b to intbuf */
    i = 0;
    av_assert0(b.nb_words < XFACE_MAX_WORDS);
    while (b.nb_words) {
        uint8_t r;
        ff_big_div(&b, XFACE_PRINTS, &r);
        av_assert0(i < sizeof(intbuf));
        intbuf[i++] = r + XFACE_FIRST_PRINT;
    }

    if ((ret = ff_alloc_packet2(avctx, pkt, i+2, 0)) < 0)
        return ret;

    /* revert the number, and close the buffer */
    p = pkt->data;
    while (--i >= 0)
        *(p++) = intbuf[i];
    *(p++) = '\n';
    *(p++) = 0;

    pkt->flags |= AV_PKT_FLAG_KEY;
    *got_packet = 1;

    return 0;
}

