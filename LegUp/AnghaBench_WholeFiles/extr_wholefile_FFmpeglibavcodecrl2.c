#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct TYPE_15__ {TYPE_2__* priv_data; } ;
struct TYPE_14__ {int** data; int* linesize; } ;
struct TYPE_13__ {int* data; int size; } ;
struct TYPE_12__ {int* back_frame; int video_base; int const* palette; TYPE_1__* avctx; } ;
struct TYPE_11__ {int width; int height; } ;
typedef  TYPE_2__ Rl2Context ;
typedef  TYPE_3__ AVPacket ;
typedef  TYPE_4__ AVFrame ;
typedef  TYPE_5__ AVCodecContext ;

/* Variables and functions */
 int AVPALETTE_SIZE ; 
 int ff_get_buffer (TYPE_5__*,TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int const*,int) ; 

__attribute__((used)) static void rl2_rle_decode(Rl2Context *s, const uint8_t *in, int size,
                               uint8_t *out, int stride, int video_base)
{
    int base_x = video_base % s->avctx->width;
    int base_y = video_base / s->avctx->width;
    int stride_adj = stride - s->avctx->width;
    int i;
    const uint8_t *back_frame = s->back_frame;
    const uint8_t *in_end     = in + size;
    const uint8_t *out_end    = out + stride * s->avctx->height;
    uint8_t *line_end;

    /** copy start of the background frame */
    for (i = 0; i <= base_y; i++) {
        if (s->back_frame)
            memcpy(out, back_frame, s->avctx->width);
        out        += stride;
        back_frame += s->avctx->width;
    }
    back_frame += base_x - s->avctx->width;
    line_end    = out - stride_adj;
    out        += base_x - stride;

    /** decode the variable part of the frame */
    while (in < in_end) {
        uint8_t val = *in++;
        int len     = 1;
        if (val >= 0x80) {
            if (in >= in_end)
                break;
            len = *in++;
            if (!len)
                break;
        }

        if (len >= out_end - out)
            break;

        if (s->back_frame)
            val |= 0x80;
        else
            val &= ~0x80;

        while (len--) {
            *out++ = (val == 0x80) ? *back_frame : val;
            back_frame++;
            if (out == line_end) {
                 out      += stride_adj;
                 line_end += stride;
                 if (len >= out_end - out)
                     break;
            }
        }
    }

    /** copy the rest from the background frame */
    if (s->back_frame) {
        while (out < out_end) {
            memcpy(out, back_frame, line_end - out);
            back_frame += line_end - out;
            out         = line_end + stride_adj;
            line_end   += stride;
        }
    }
}

__attribute__((used)) static int rl2_decode_frame(AVCodecContext *avctx,
                            void *data, int *got_frame,
                            AVPacket *avpkt)
{
    AVFrame *frame     = data;
    const uint8_t *buf = avpkt->data;
    int ret, buf_size  = avpkt->size;
    Rl2Context *s = avctx->priv_data;

    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
        return ret;

    /** run length decode */
    rl2_rle_decode(s, buf, buf_size, frame->data[0], frame->linesize[0],
                   s->video_base);

    /** make the palette available on the way out */
    memcpy(frame->data[1], s->palette, AVPALETTE_SIZE);

    *got_frame = 1;

    /** report that the buffer was completely consumed */
    return buf_size;
}

