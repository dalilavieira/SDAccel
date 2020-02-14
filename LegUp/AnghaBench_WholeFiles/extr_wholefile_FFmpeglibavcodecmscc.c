#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  unsigned int uint32_t ;
struct TYPE_18__ {int avail_in; int /*<<< orphan*/  total_out; int /*<<< orphan*/  avail_out; int /*<<< orphan*/  next_out; int /*<<< orphan*/ * next_in; } ;
struct TYPE_17__ {int bits_per_coded_sample; unsigned int width; scalar_t__ codec_id; scalar_t__ pix_fmt; int height; TYPE_1__* priv_data; } ;
struct TYPE_16__ {int palette_has_changed; int* linesize; int key_frame; int /*<<< orphan*/  pict_type; scalar_t__* data; } ;
struct TYPE_15__ {int size; int /*<<< orphan*/ * data; } ;
struct TYPE_14__ {unsigned int bpp; int* pal; int* uncomp_buf; int /*<<< orphan*/  uncomp_size; TYPE_6__ zstream; int /*<<< orphan*/  decomp_buf; int /*<<< orphan*/  decomp_size; } ;
typedef  int /*<<< orphan*/  PutByteContext ;
typedef  TYPE_1__ MSCCContext ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AVERROR_UNKNOWN ; 
 int AVPALETTE_SIZE ; 
 scalar_t__ AV_CODEC_ID_MSCC ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 scalar_t__ AV_PIX_FMT_PAL8 ; 
 int /*<<< orphan*/  AV_PKT_DATA_PALETTE ; 
 int AV_RL32 (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  Z_FINISH ; 
 int Z_OK ; 
 int Z_STREAM_END ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/ * av_packet_get_side_data (TYPE_2__*,int /*<<< orphan*/ ,int*) ; 
 unsigned int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 scalar_t__ bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_le16 (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_le24 (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_le32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bytestream2_init_writer (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bytestream2_put_byte (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  bytestream2_put_le16 (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  bytestream2_put_le24 (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  bytestream2_put_le32 (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  bytestream2_seek_p (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int inflate (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int inflateReset (TYPE_6__*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int*,int) ; 

__attribute__((used)) static int rle_uncompress(AVCodecContext *avctx, GetByteContext *gb, PutByteContext *pb)
{
    MSCCContext *s = avctx->priv_data;
    unsigned x = 0, y = 0;

    while (bytestream2_get_bytes_left(gb) > 0) {
        uint32_t fill;
        int j;
        unsigned run = bytestream2_get_byte(gb);

        if (run) {
            switch (avctx->bits_per_coded_sample) {
            case 8:
                fill = bytestream2_get_byte(gb);
                break;
            case 16:
                fill = bytestream2_get_le16(gb);
                break;
            case 24:
                fill = bytestream2_get_le24(gb);
                break;
            case 32:
                fill = bytestream2_get_le32(gb);
                break;
            }

            for (j = 0; j < run; j++) {
                switch (avctx->bits_per_coded_sample) {
                case 8:
                    bytestream2_put_byte(pb, fill);
                    break;
                case 16:
                    bytestream2_put_le16(pb, fill);
                    break;
                case 24:
                    bytestream2_put_le24(pb, fill);
                    break;
                case 32:
                    bytestream2_put_le32(pb, fill);
                    break;
                }
            }
            x += run;
        } else {
            unsigned copy = bytestream2_get_byte(gb);

            if (copy == 0) {
                x = 0;
                y++;
                bytestream2_seek_p(pb, y * avctx->width * s->bpp, SEEK_SET);
            } else if (copy == 1) {
                return 0;
            } else if (copy == 2) {

                x += bytestream2_get_byte(gb);
                y += bytestream2_get_byte(gb);

                bytestream2_seek_p(pb, y * avctx->width * s->bpp + x * s->bpp, SEEK_SET);
            } else {
                for (j = 0; j < copy; j++) {
                    switch (avctx->bits_per_coded_sample) {
                    case 8:
                        bytestream2_put_byte(pb, bytestream2_get_byte(gb));
                        break;
                    case 16:
                        bytestream2_put_le16(pb, bytestream2_get_le16(gb));
                        break;
                    case 24:
                        bytestream2_put_le24(pb, bytestream2_get_le24(gb));
                        break;
                    case 32:
                        bytestream2_put_le32(pb, bytestream2_get_le32(gb));
                        break;
                    }
                }

                if (s->bpp == 1 && (copy & 1))
                    bytestream2_skip(gb, 1);
                x += copy;
            }
        }
    }

    return AVERROR_INVALIDDATA;
}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx,
                        void *data, int *got_frame,
                        AVPacket *avpkt)
{
    MSCCContext *s = avctx->priv_data;
    AVFrame *frame = data;
    uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    GetByteContext gb;
    PutByteContext pb;
    int ret, j;

    if (avpkt->size < 3)
        return buf_size;

    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
        return ret;

    if (avctx->codec_id == AV_CODEC_ID_MSCC) {
        avpkt->data[2] ^= avpkt->data[0];
        buf += 2;
        buf_size -= 2;
    }

    if (avctx->pix_fmt == AV_PIX_FMT_PAL8) {
        int size;
        const uint8_t *pal = av_packet_get_side_data(avpkt, AV_PKT_DATA_PALETTE, &size);

        if (pal && size == AVPALETTE_SIZE) {
            frame->palette_has_changed = 1;
            for (j = 0; j < 256; j++)
                s->pal[j] = 0xFF000000 | AV_RL32(pal + j * 4);
        } else if (pal) {
            av_log(avctx, AV_LOG_ERROR, "Palette size %d is wrong\n", size);
        }
        memcpy(frame->data[1], s->pal, AVPALETTE_SIZE);
    }

    ret = inflateReset(&s->zstream);
    if (ret != Z_OK) {
        av_log(avctx, AV_LOG_ERROR, "Inflate reset error: %d\n", ret);
        return AVERROR_UNKNOWN;
    }
    s->zstream.next_in   = buf;
    s->zstream.avail_in  = buf_size;
    s->zstream.next_out  = s->decomp_buf;
    s->zstream.avail_out = s->decomp_size;
    ret = inflate(&s->zstream, Z_FINISH);
    if (ret != Z_STREAM_END) {
        av_log(avctx, AV_LOG_ERROR, "Inflate error: %d\n", ret);
        return AVERROR_UNKNOWN;
    }

    bytestream2_init(&gb, s->decomp_buf, s->zstream.total_out);
    bytestream2_init_writer(&pb, s->uncomp_buf, s->uncomp_size);

    ret = rle_uncompress(avctx, &gb, &pb);
    if (ret)
        return ret;

    for (j = 0; j < avctx->height; j++) {
        memcpy(frame->data[0] + (avctx->height - j - 1) * frame->linesize[0],
               s->uncomp_buf + s->bpp * j * avctx->width, s->bpp * avctx->width);
    }

    frame->key_frame = 1;
    frame->pict_type = AV_PICTURE_TYPE_I;

    *got_frame = 1;

    return avpkt->size;
}

