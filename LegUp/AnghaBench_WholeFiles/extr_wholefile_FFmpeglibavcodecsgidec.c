#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char uint8_t ;
typedef  unsigned short uint16_t ;
struct TYPE_18__ {int /*<<< orphan*/  pix_fmt; TYPE_1__* priv_data; } ;
struct TYPE_17__ {int key_frame; unsigned char** data; int* linesize; int /*<<< orphan*/  pict_type; } ;
struct TYPE_16__ {int size; int /*<<< orphan*/  data; } ;
struct TYPE_15__ {int height; int depth; int width; int linesize; int bytes_per_channel; int /*<<< orphan*/  g; TYPE_4__* avctx; } ;
typedef  TYPE_1__ SgiState ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PIX_FMT_GRAY16BE ; 
 int /*<<< orphan*/  AV_PIX_FMT_GRAY8 ; 
 int /*<<< orphan*/  AV_PIX_FMT_RGB24 ; 
 int /*<<< orphan*/  AV_PIX_FMT_RGB48BE ; 
 int /*<<< orphan*/  AV_PIX_FMT_RGBA ; 
 int /*<<< orphan*/  AV_PIX_FMT_RGBA64BE ; 
 int /*<<< orphan*/  AV_WN16A (unsigned short*,unsigned short) ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int SGI_GRAYSCALE ; 
 unsigned int SGI_HEADER_SIZE ; 
 void* SGI_MAGIC ; 
 int SGI_RGB ; 
 int SGI_RGBA ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,...) ; 
 void* bytestream2_get_be16u (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_be32 (int /*<<< orphan*/ *) ; 
 unsigned char bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 void* bytestream2_get_byteu (int /*<<< orphan*/ *) ; 
 unsigned short bytestream2_get_ne16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_get_ne16u (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bytestream2_seek (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int ff_set_dimensions (TYPE_4__*,int,int) ; 

__attribute__((used)) static int expand_rle_row8(SgiState *s, uint8_t *out_buf,
                           int len, int pixelstride)
{
    unsigned char pixel, count;
    unsigned char *orig = out_buf;
    uint8_t *out_end = out_buf + len;

    while (out_buf < out_end) {
        if (bytestream2_get_bytes_left(&s->g) < 1)
            return AVERROR_INVALIDDATA;
        pixel = bytestream2_get_byteu(&s->g);
        if (!(count = (pixel & 0x7f))) {
            break;
        }

        /* Check for buffer overflow. */
        if (out_end - out_buf <= pixelstride * (count - 1)) {
            av_log(s->avctx, AV_LOG_ERROR, "Invalid pixel count.\n");
            return AVERROR_INVALIDDATA;
        }

        if (pixel & 0x80) {
            while (count--) {
                *out_buf = bytestream2_get_byte(&s->g);
                out_buf += pixelstride;
            }
        } else {
            pixel = bytestream2_get_byte(&s->g);

            while (count--) {
                *out_buf = pixel;
                out_buf += pixelstride;
            }
        }
    }
    return (out_buf - orig) / pixelstride;
}

__attribute__((used)) static int expand_rle_row16(SgiState *s, uint16_t *out_buf,
                            int len, int pixelstride)
{
    unsigned short pixel;
    unsigned char count;
    unsigned short *orig = out_buf;
    uint16_t *out_end = out_buf + len;

    while (out_buf < out_end) {
        if (bytestream2_get_bytes_left(&s->g) < 2)
            return AVERROR_INVALIDDATA;
        pixel = bytestream2_get_be16u(&s->g);
        if (!(count = (pixel & 0x7f)))
            break;

        /* Check for buffer overflow. */
        if (out_end - out_buf <= pixelstride * (count - 1)) {
            av_log(s->avctx, AV_LOG_ERROR, "Invalid pixel count.\n");
            return AVERROR_INVALIDDATA;
        }

        if (pixel & 0x80) {
            while (count--) {
                pixel = bytestream2_get_ne16(&s->g);
                AV_WN16A(out_buf, pixel);
                out_buf += pixelstride;
            }
        } else {
            pixel = bytestream2_get_ne16(&s->g);

            while (count--) {
                AV_WN16A(out_buf, pixel);
                out_buf += pixelstride;
            }
        }
    }
    return (out_buf - orig) / pixelstride;
}

__attribute__((used)) static int read_rle_sgi(uint8_t *out_buf, SgiState *s)
{
    uint8_t *dest_row;
    unsigned int len = s->height * s->depth * 4;
    GetByteContext g_table = s->g;
    unsigned int y, z;
    unsigned int start_offset;
    int linesize, ret;

    /* size of  RLE offset and length tables */
    if (len * 2 > bytestream2_get_bytes_left(&s->g)) {
        return AVERROR_INVALIDDATA;
    }

    for (z = 0; z < s->depth; z++) {
        dest_row = out_buf;
        for (y = 0; y < s->height; y++) {
            linesize = s->width * s->depth;
            dest_row -= s->linesize;
            start_offset = bytestream2_get_be32(&g_table);
            bytestream2_seek(&s->g, start_offset, SEEK_SET);
            if (s->bytes_per_channel == 1)
                ret = expand_rle_row8(s, dest_row + z, linesize, s->depth);
            else
                ret = expand_rle_row16(s, (uint16_t *)dest_row + z, linesize, s->depth);
            if (ret != s->width)
                return AVERROR_INVALIDDATA;
        }
    }
    return 0;
}

__attribute__((used)) static int read_uncompressed_sgi(unsigned char *out_buf, SgiState *s)
{
    int x, y, z;
    unsigned int offset = s->height * s->width * s->bytes_per_channel;
    GetByteContext gp[4];
    uint8_t *out_end;

    /* Test buffer size. */
    if (offset * s->depth > bytestream2_get_bytes_left(&s->g))
        return AVERROR_INVALIDDATA;

    /* Create a reader for each plane */
    for (z = 0; z < s->depth; z++) {
        gp[z] = s->g;
        bytestream2_skip(&gp[z], z * offset);
    }

    for (y = s->height - 1; y >= 0; y--) {
        out_end = out_buf + (y * s->linesize);
        if (s->bytes_per_channel == 1) {
            for (x = s->width; x > 0; x--)
                for (z = 0; z < s->depth; z++)
                    *out_end++ = bytestream2_get_byteu(&gp[z]);
        } else {
            uint16_t *out16 = (uint16_t *)out_end;
            for (x = s->width; x > 0; x--)
                for (z = 0; z < s->depth; z++)
                    *out16++ = bytestream2_get_ne16u(&gp[z]);
        }
    }
    return 0;
}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx,
                        void *data, int *got_frame,
                        AVPacket *avpkt)
{
    SgiState *s = avctx->priv_data;
    AVFrame *p = data;
    unsigned int dimension, rle;
    int ret = 0;
    uint8_t *out_buf, *out_end;

    bytestream2_init(&s->g, avpkt->data, avpkt->size);
    if (bytestream2_get_bytes_left(&s->g) < SGI_HEADER_SIZE) {
        av_log(avctx, AV_LOG_ERROR, "buf_size too small (%d)\n", avpkt->size);
        return AVERROR_INVALIDDATA;
    }

    /* Test for SGI magic. */
    if (bytestream2_get_be16u(&s->g) != SGI_MAGIC) {
        av_log(avctx, AV_LOG_ERROR, "bad magic number\n");
        return AVERROR_INVALIDDATA;
    }

    rle                  = bytestream2_get_byteu(&s->g);
    s->bytes_per_channel = bytestream2_get_byteu(&s->g);
    dimension            = bytestream2_get_be16u(&s->g);
    s->width             = bytestream2_get_be16u(&s->g);
    s->height            = bytestream2_get_be16u(&s->g);
    s->depth             = bytestream2_get_be16u(&s->g);

    if (s->bytes_per_channel != 1 && s->bytes_per_channel != 2) {
        av_log(avctx, AV_LOG_ERROR, "wrong channel number\n");
        return AVERROR_INVALIDDATA;
    }

    /* Check for supported image dimensions. */
    if (dimension != 2 && dimension != 3) {
        av_log(avctx, AV_LOG_ERROR, "wrong dimension number\n");
        return AVERROR_INVALIDDATA;
    }

    if (s->depth == SGI_GRAYSCALE) {
        avctx->pix_fmt = s->bytes_per_channel == 2 ? AV_PIX_FMT_GRAY16BE : AV_PIX_FMT_GRAY8;
    } else if (s->depth == SGI_RGB) {
        avctx->pix_fmt = s->bytes_per_channel == 2 ? AV_PIX_FMT_RGB48BE : AV_PIX_FMT_RGB24;
    } else if (s->depth == SGI_RGBA) {
        avctx->pix_fmt = s->bytes_per_channel == 2 ? AV_PIX_FMT_RGBA64BE : AV_PIX_FMT_RGBA;
    } else {
        av_log(avctx, AV_LOG_ERROR, "wrong picture format\n");
        return AVERROR_INVALIDDATA;
    }

    ret = ff_set_dimensions(avctx, s->width, s->height);
    if (ret < 0)
        return ret;

    if ((ret = ff_get_buffer(avctx, p, 0)) < 0)
        return ret;

    p->pict_type = AV_PICTURE_TYPE_I;
    p->key_frame = 1;
    out_buf = p->data[0];

    out_end = out_buf + p->linesize[0] * s->height;

    s->linesize = p->linesize[0];

    /* Skip header. */
    bytestream2_seek(&s->g, SGI_HEADER_SIZE, SEEK_SET);
    if (rle) {
        ret = read_rle_sgi(out_end, s);
    } else {
        ret = read_uncompressed_sgi(out_buf, s);
    }
    if (ret)
        return ret;

    *got_frame = 1;
    return avpkt->size;
}

