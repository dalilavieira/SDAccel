#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;
typedef  struct TYPE_17__   TYPE_12__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int ptrdiff_t ;
typedef  int int64_t ;
struct TYPE_22__ {int avail_in; int avail_out; int /*<<< orphan*/ * next_out; scalar_t__ next_in; } ;
struct TYPE_18__ {int bpp; TYPE_12__* prev_frame; TYPE_5__ zstream; int /*<<< orphan*/ * block_data; } ;
typedef  TYPE_1__ WCMVContext ;
struct TYPE_21__ {int width; int height; int /*<<< orphan*/  pix_fmt; TYPE_1__* priv_data; } ;
struct TYPE_20__ {int* linesize; int key_frame; int /*<<< orphan*/  pict_type; int /*<<< orphan*/ ** data; } ;
struct TYPE_19__ {int size; int /*<<< orphan*/ * data; } ;
struct TYPE_17__ {scalar_t__* data; } ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_EXTERNAL ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_GET_BUFFER_FLAG_REF ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int INT_MAX ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  Z_FINISH ; 
 int Z_OK ; 
 int Z_STREAM_END ; 
 int /*<<< orphan*/  Z_SYNC_FLUSH ; 
 int av_frame_copy (TYPE_3__*,TYPE_12__*) ; 
 int av_frame_ref (TYPE_12__*,TYPE_3__*) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_12__*) ; 
 int /*<<< orphan*/  av_image_fill_black (int /*<<< orphan*/ **,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,int) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le16 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le24 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bytestream2_seek (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int bytestream2_tell (int /*<<< orphan*/ *) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int inflate (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int inflateReset (TYPE_5__*) ; 

__attribute__((used)) static int decode_frame(AVCodecContext *avctx,
                        void *data, int *got_frame,
                        AVPacket *avpkt)
{
    WCMVContext *s = avctx->priv_data;
    AVFrame *frame = data;
    int skip, blocks, zret, ret, intra = 0, bpp = s->bpp;
    GetByteContext gb;
    uint8_t *dst;

    ret = inflateReset(&s->zstream);
    if (ret != Z_OK) {
        av_log(avctx, AV_LOG_ERROR, "Inflate reset error: %d\n", ret);
        return AVERROR_EXTERNAL;
    }

    bytestream2_init(&gb, avpkt->data, avpkt->size);
    blocks = bytestream2_get_le16(&gb);
    if (!blocks)
        return avpkt->size;

    if ((ret = ff_get_buffer(avctx, frame, AV_GET_BUFFER_FLAG_REF)) < 0)
        return ret;

    if (blocks > 5) {
        GetByteContext bgb;
        int x = 0, size;

        if (blocks * 8 >= 0xFFFF)
            size = bytestream2_get_le24(&gb);
        else if (blocks * 8 >= 0xFF)
            size = bytestream2_get_le16(&gb);
        else
            size = bytestream2_get_byte(&gb);

        skip = bytestream2_tell(&gb);
        if (size > avpkt->size - skip)
            return AVERROR_INVALIDDATA;

        s->zstream.next_in  = avpkt->data + skip;
        s->zstream.avail_in = size;
        s->zstream.next_out  = s->block_data;
        s->zstream.avail_out = sizeof(s->block_data);

        zret = inflate(&s->zstream, Z_FINISH);
        if (zret != Z_STREAM_END) {
            av_log(avctx, AV_LOG_ERROR,
                   "Inflate failed with return code: %d.\n", zret);
            return AVERROR_INVALIDDATA;
        }

        ret = inflateReset(&s->zstream);
        if (ret != Z_OK) {
            av_log(avctx, AV_LOG_ERROR, "Inflate reset error: %d\n", ret);
            return AVERROR_EXTERNAL;
        }

        bytestream2_skip(&gb, size);
        bytestream2_init(&bgb, s->block_data, blocks * 8);

        for (int i = 0; i < blocks; i++) {
            int w, h;

            bytestream2_skip(&bgb, 4);
            w = bytestream2_get_le16(&bgb);
            h = bytestream2_get_le16(&bgb);
            if (x + bpp * (int64_t)w * h > INT_MAX)
                return AVERROR_INVALIDDATA;
            x += bpp * w * h;
        }

        if (x >= 0xFFFF)
            bytestream2_skip(&gb, 3);
        else if (x >= 0xFF)
            bytestream2_skip(&gb, 2);
        else
            bytestream2_skip(&gb, 1);

        skip = bytestream2_tell(&gb);

        s->zstream.next_in  = avpkt->data + skip;
        s->zstream.avail_in = avpkt->size - skip;

        bytestream2_init(&gb, s->block_data, blocks * 8);
    } else if (blocks) {
        int x = 0;

        bytestream2_seek(&gb, 2, SEEK_SET);

        for (int i = 0; i < blocks; i++) {
            int w, h;

            bytestream2_skip(&gb, 4);
            w = bytestream2_get_le16(&gb);
            h = bytestream2_get_le16(&gb);
            if (x + bpp * (int64_t)w * h > INT_MAX)
                return AVERROR_INVALIDDATA;
            x += bpp * w * h;
        }

        if (x >= 0xFFFF)
            bytestream2_skip(&gb, 3);
        else if (x >= 0xFF)
            bytestream2_skip(&gb, 2);
        else
            bytestream2_skip(&gb, 1);

        skip = bytestream2_tell(&gb);

        s->zstream.next_in  = avpkt->data + skip;
        s->zstream.avail_in = avpkt->size - skip;

        bytestream2_seek(&gb, 2, SEEK_SET);
    }

    if (s->prev_frame->data[0]) {
        ret = av_frame_copy(frame, s->prev_frame);
        if (ret < 0)
            return ret;
    } else {
        ptrdiff_t linesize[4] = { frame->linesize[0], 0, 0, 0 };
        av_image_fill_black(frame->data, linesize, avctx->pix_fmt, 0,
                            avctx->width, avctx->height);
    }

    for (int block = 0; block < blocks; block++) {
        int x, y, w, h;

        x = bytestream2_get_le16(&gb);
        y = bytestream2_get_le16(&gb);
        w = bytestream2_get_le16(&gb);
        h = bytestream2_get_le16(&gb);

        if (blocks == 1 && x == 0 && y == 0 && w == avctx->width && h == avctx->height)
            intra = 1;

        if (x + w > avctx->width || y + h > avctx->height)
            return AVERROR_INVALIDDATA;

        if (w > avctx->width || h > avctx->height)
            return AVERROR_INVALIDDATA;

        dst = frame->data[0] + (avctx->height - y - 1) * frame->linesize[0] + x * bpp;
        for (int i = 0; i < h; i++) {
            s->zstream.next_out  = dst;
            s->zstream.avail_out = w * bpp;

            zret = inflate(&s->zstream, Z_SYNC_FLUSH);
            if (zret != Z_OK && zret != Z_STREAM_END) {
                av_log(avctx, AV_LOG_ERROR,
                       "Inflate failed with return code: %d.\n", zret);
                return AVERROR_INVALIDDATA;
            }

            dst -= frame->linesize[0];
        }
    }

    frame->key_frame = intra;
    frame->pict_type = intra ? AV_PICTURE_TYPE_I : AV_PICTURE_TYPE_P;

    av_frame_unref(s->prev_frame);
    if ((ret = av_frame_ref(s->prev_frame, frame)) < 0)
        return ret;

    *got_frame = 1;

    return avpkt->size;
}

