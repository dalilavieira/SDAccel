#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;
typedef  struct TYPE_19__   TYPE_14__ ;

/* Type definitions */
typedef  int uint16_t ;
struct TYPE_23__ {TYPE_14__* prev_frame; int /*<<< orphan*/  gb; } ;
struct TYPE_22__ {int height; int width; TYPE_4__* priv_data; } ;
struct TYPE_21__ {int* linesize; int key_frame; int /*<<< orphan*/  pict_type; int /*<<< orphan*/ ** data; } ;
struct TYPE_20__ {int size; int /*<<< orphan*/  data; } ;
struct TYPE_19__ {scalar_t__* data; } ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_1__ AVPacket ;
typedef  TYPE_2__ AVFrame ;
typedef  TYPE_3__ AVCodecContext ;
typedef  TYPE_4__ ARBCContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_GET_BUFFER_FLAG_REF ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int /*<<< orphan*/  AV_WB24 (int /*<<< orphan*/ *,int) ; 
 int FFMIN (int const,int) ; 
 int av_frame_copy (TYPE_2__*,TYPE_14__*) ; 
 int av_frame_ref (TYPE_14__*,TYPE_2__*) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_14__*) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int ff_get_buffer (TYPE_3__*,TYPE_2__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int fill_tile4(AVCodecContext *avctx, int color, AVFrame *frame)
{
    ARBCContext *s = avctx->priv_data;
    GetByteContext *gb = &s->gb;
    int nb_tiles = bytestream2_get_le16(gb);
    int h = avctx->height - 1;
    int pixels_overwritten = 0;

    if ((avctx->width / 4 + 1) * (avctx->height / 4 + 1) < nb_tiles)
        return 0;

    for (int i = 0; i < nb_tiles; i++) {
        int y = bytestream2_get_byte(gb);
        int x = bytestream2_get_byte(gb);
        uint16_t mask = bytestream2_get_le16(gb);
        int start_y = y * 4, start_x = x * 4;
        int end_y = start_y + 4, end_x = start_x + 4;

        for (int j = start_y; j < end_y; j++) {
            for (int k = start_x; k < end_x; k++) {
                if (mask & 0x8000) {
                    if (j >= avctx->height || k >= avctx->width) {
                        mask = mask << 1;
                        continue;
                    }
                    AV_WB24(&frame->data[0][frame->linesize[0] * (h - j) + 3 * k], color);
                    pixels_overwritten ++;
                }
                mask = mask << 1;
            }
        }
    }
    return pixels_overwritten;
}

__attribute__((used)) static int fill_tileX(AVCodecContext *avctx, int tile_width, int tile_height,
                       int color, AVFrame *frame)
{
    ARBCContext *s = avctx->priv_data;
    GetByteContext *gb = &s->gb;
    const int step_h = tile_height / 4;
    const int step_w = tile_width / 4;
    int nb_tiles = bytestream2_get_le16(gb);
    int h = avctx->height - 1;
    int pixels_overwritten = 0;

    if ((avctx->width / tile_width + 1) * (avctx->height / tile_height + 1) < nb_tiles)
        return 0;

    for (int i = 0; i < nb_tiles; i++) {
        int y = bytestream2_get_byte(gb);
        int x = bytestream2_get_byte(gb);
        uint16_t mask = bytestream2_get_le16(gb);
        int start_y = y * tile_height, start_x = x * tile_width;
        int end_y = start_y + tile_height, end_x = start_x + tile_width;

        for (int j = start_y; j < end_y; j += step_h) {
            for (int k = start_x; k < end_x; k += step_w) {
                if (mask & 0x8000U) {
                    for (int m = 0; m < step_h; m++) {
                        for (int n = 0; n < step_w; n++) {
                            if (j + m >= avctx->height || k + n >= avctx->width)
                                continue;
                            AV_WB24(&frame->data[0][frame->linesize[0] * (h - (j + m)) + 3 * (k + n)], color);
                        }
                    }
                    pixels_overwritten += FFMIN(step_h, avctx->height - j) * FFMIN(step_w, avctx->width - k);
                }
                mask = mask << 1;
            }
        }
    }
    return pixels_overwritten;
}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx, void *data,
                        int *got_frame, AVPacket *avpkt)
{
    ARBCContext *s = avctx->priv_data;
    AVFrame *frame = data;
    int ret, nb_segments;
    int prev_pixels = avctx->width * avctx->height;

    if (avpkt->size < 10)
        return AVERROR_INVALIDDATA;

    bytestream2_init(&s->gb, avpkt->data, avpkt->size);
    bytestream2_skip(&s->gb, 8);
    nb_segments = bytestream2_get_le16(&s->gb);
    if (nb_segments == 0)
        return avpkt->size;

    if (7 * nb_segments > bytestream2_get_bytes_left(&s->gb))
        return AVERROR_INVALIDDATA;

    if ((ret = ff_get_buffer(avctx, frame, AV_GET_BUFFER_FLAG_REF)) < 0)
        return ret;

    if (s->prev_frame->data[0]) {
        ret = av_frame_copy(frame, s->prev_frame);
        if (ret < 0)
            return ret;
    }

    for (int i = 0; i < nb_segments; i++) {
        int resolution_flag;
        int fill;

        if (bytestream2_get_bytes_left(&s->gb) <= 0)
            return AVERROR_INVALIDDATA;

        fill = bytestream2_get_byte(&s->gb) << 16;
        bytestream2_skip(&s->gb, 1);
        fill |= bytestream2_get_byte(&s->gb) << 8;
        bytestream2_skip(&s->gb, 1);
        fill |= bytestream2_get_byte(&s->gb) << 0;
        bytestream2_skip(&s->gb, 1);
        resolution_flag = bytestream2_get_byte(&s->gb);

        if (resolution_flag & 0x10)
            prev_pixels -= fill_tileX(avctx, 1024, 1024, fill, frame);
        if (resolution_flag & 0x08)
            prev_pixels -= fill_tileX(avctx, 256, 256, fill, frame);
        if (resolution_flag & 0x04)
            prev_pixels -= fill_tileX(avctx, 64, 64, fill, frame);
        if (resolution_flag & 0x02)
            prev_pixels -= fill_tileX(avctx, 16, 16, fill, frame);
        if (resolution_flag & 0x01)
            prev_pixels -= fill_tile4(avctx, fill, frame);
    }

    av_frame_unref(s->prev_frame);
    if ((ret = av_frame_ref(s->prev_frame, frame)) < 0)
        return ret;

    frame->pict_type = prev_pixels <= 0 ? AV_PICTURE_TYPE_I : AV_PICTURE_TYPE_P;
    frame->key_frame = prev_pixels <= 0;
    *got_frame = 1;

    return avpkt->size;
}

__attribute__((used)) static void decode_flush(AVCodecContext *avctx)
{
    ARBCContext *s = avctx->priv_data;

    av_frame_unref(s->prev_frame);
}

