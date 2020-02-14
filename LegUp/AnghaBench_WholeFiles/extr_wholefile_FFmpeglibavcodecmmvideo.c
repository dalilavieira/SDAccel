#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;
typedef  struct TYPE_20__   TYPE_12__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_25__ {TYPE_2__* priv_data; } ;
struct TYPE_24__ {int size; int /*<<< orphan*/ * data; } ;
struct TYPE_23__ {scalar_t__ buffer; scalar_t__ buffer_start; } ;
struct TYPE_22__ {int* palette; TYPE_12__* frame; TYPE_3__ gb; TYPE_1__* avctx; } ;
struct TYPE_21__ {int height; int width; } ;
struct TYPE_20__ {int** data; int* linesize; } ;
typedef  TYPE_2__ MmContext ;
typedef  TYPE_3__ GetByteContext ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AVPALETTE_SIZE ; 
 int AV_RL16 (int /*<<< orphan*/  const*) ; 
 int MM_PREAMBLE_SIZE ; 
#define  MM_TYPE_INTER 134 
#define  MM_TYPE_INTER_HH 133 
#define  MM_TYPE_INTER_HHV 132 
#define  MM_TYPE_INTRA 131 
#define  MM_TYPE_INTRA_HH 130 
#define  MM_TYPE_INTRA_HHV 129 
#define  MM_TYPE_PALETTE 128 
 int av_frame_ref (void*,TYPE_12__*) ; 
 int bytestream2_get_be24 (TYPE_3__*) ; 
 int bytestream2_get_byte (TYPE_3__*) ; 
 int bytestream2_get_bytes_left (TYPE_3__*) ; 
 int bytestream2_get_le16 (TYPE_3__*) ; 
 int /*<<< orphan*/  bytestream2_init (TYPE_3__*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  bytestream2_skip (TYPE_3__*,int) ; 
 int ff_reget_buffer (TYPE_5__*,TYPE_12__*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int*,int,int) ; 

__attribute__((used)) static void mm_decode_pal(MmContext *s)
{
    int i;

    bytestream2_skip(&s->gb, 4);
    for (i = 0; i < 128; i++) {
        s->palette[i] = 0xFFU << 24 | bytestream2_get_be24(&s->gb);
        s->palette[i+128] = s->palette[i]<<2;
    }
}

__attribute__((used)) static int mm_decode_intra(MmContext * s, int half_horiz, int half_vert)
{
    int x = 0, y = 0;

    while (bytestream2_get_bytes_left(&s->gb) > 0) {
        int run_length, color;

        if (y >= s->avctx->height)
            return 0;

        color = bytestream2_get_byte(&s->gb);
        if (color & 0x80) {
            run_length = 1;
        }else{
            run_length = (color & 0x7f) + 2;
            color = bytestream2_get_byte(&s->gb);
        }

        if (half_horiz)
            run_length *=2;

        if (run_length > s->avctx->width - x)
            return AVERROR_INVALIDDATA;

        if (color) {
            memset(s->frame->data[0] + y*s->frame->linesize[0] + x, color, run_length);
            if (half_vert && y + half_vert < s->avctx->height)
                memset(s->frame->data[0] + (y+1)*s->frame->linesize[0] + x, color, run_length);
        }
        x+= run_length;

        if (x >= s->avctx->width) {
            x=0;
            y += 1 + half_vert;
        }
    }

    return 0;
}

__attribute__((used)) static int mm_decode_inter(MmContext * s, int half_horiz, int half_vert)
{
    int data_off = bytestream2_get_le16(&s->gb);
    int y = 0;
    GetByteContext data_ptr;

    if (bytestream2_get_bytes_left(&s->gb) < data_off)
        return AVERROR_INVALIDDATA;

    bytestream2_init(&data_ptr, s->gb.buffer + data_off, bytestream2_get_bytes_left(&s->gb) - data_off);
    while (s->gb.buffer < data_ptr.buffer_start) {
        int i, j;
        int length = bytestream2_get_byte(&s->gb);
        int x = bytestream2_get_byte(&s->gb) + ((length & 0x80) << 1);
        length &= 0x7F;

        if (length==0) {
            y += x;
            continue;
        }

        if (y + half_vert >= s->avctx->height)
            return 0;

        for(i=0; i<length; i++) {
            int replace_array = bytestream2_get_byte(&s->gb);
            for(j=0; j<8; j++) {
                int replace = (replace_array >> (7-j)) & 1;
                if (x + half_horiz >= s->avctx->width)
                    return AVERROR_INVALIDDATA;
                if (replace) {
                    int color = bytestream2_get_byte(&data_ptr);
                    s->frame->data[0][y*s->frame->linesize[0] + x] = color;
                    if (half_horiz)
                        s->frame->data[0][y*s->frame->linesize[0] + x + 1] = color;
                    if (half_vert) {
                        s->frame->data[0][(y+1)*s->frame->linesize[0] + x] = color;
                        if (half_horiz)
                            s->frame->data[0][(y+1)*s->frame->linesize[0] + x + 1] = color;
                    }
                }
                x += 1 + half_horiz;
            }
        }

        y += 1 + half_vert;
    }

    return 0;
}

__attribute__((used)) static int mm_decode_frame(AVCodecContext *avctx,
                            void *data, int *got_frame,
                            AVPacket *avpkt)
{
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    MmContext *s = avctx->priv_data;
    int type, res;

    if (buf_size < MM_PREAMBLE_SIZE)
        return AVERROR_INVALIDDATA;
    type = AV_RL16(&buf[0]);
    buf += MM_PREAMBLE_SIZE;
    buf_size -= MM_PREAMBLE_SIZE;
    bytestream2_init(&s->gb, buf, buf_size);

    if ((res = ff_reget_buffer(avctx, s->frame)) < 0)
        return res;

    switch(type) {
    case MM_TYPE_PALETTE   : mm_decode_pal(s); return avpkt->size;
    case MM_TYPE_INTRA     : res = mm_decode_intra(s, 0, 0); break;
    case MM_TYPE_INTRA_HH  : res = mm_decode_intra(s, 1, 0); break;
    case MM_TYPE_INTRA_HHV : res = mm_decode_intra(s, 1, 1); break;
    case MM_TYPE_INTER     : res = mm_decode_inter(s, 0, 0); break;
    case MM_TYPE_INTER_HH  : res = mm_decode_inter(s, 1, 0); break;
    case MM_TYPE_INTER_HHV : res = mm_decode_inter(s, 1, 1); break;
    default:
        res = AVERROR_INVALIDDATA;
        break;
    }
    if (res < 0)
        return res;

    memcpy(s->frame->data[1], s->palette, AVPALETTE_SIZE);

    if ((res = av_frame_ref(data, s->frame)) < 0)
        return res;

    *got_frame      = 1;

    return avpkt->size;
}

