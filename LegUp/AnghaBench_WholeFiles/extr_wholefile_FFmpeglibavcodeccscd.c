#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct TYPE_16__ {TYPE_1__* priv_data; } ;
struct TYPE_15__ {int** data; int* linesize; int key_frame; int /*<<< orphan*/  pict_type; } ;
struct TYPE_14__ {int* data; int size; } ;
struct TYPE_13__ {int decomp_size; int* decomp_buf; int linelen; int height; TYPE_3__* pic; } ;
typedef  TYPE_1__ CamStudioContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int /*<<< orphan*/  ENOSYS ; 
 int FFALIGN (int,int) ; 
 int av_frame_ref (void*,TYPE_3__*) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  av_lzo1x_decode (int*,int*,int const*,int*) ; 
 int ff_reget_buffer (TYPE_4__*,TYPE_3__*) ; 
 int /*<<< orphan*/  memcpy (int*,int const*,int) ; 

__attribute__((used)) static void copy_frame_default(AVFrame *f, const uint8_t *src,
                               int linelen, int height)
{
    int i, src_stride = FFALIGN(linelen, 4);
    uint8_t *dst = f->data[0];
    dst += (height - 1) * f->linesize[0];
    for (i = height; i; i--) {
        memcpy(dst, src, linelen);
        src += src_stride;
        dst -= f->linesize[0];
    }
}

__attribute__((used)) static void add_frame_default(AVFrame *f, const uint8_t *src,
                              int linelen, int height)
{
    int i, j, src_stride = FFALIGN(linelen, 4);
    uint8_t *dst = f->data[0];
    dst += (height - 1) * f->linesize[0];
    for (i = height; i; i--) {
        for (j = linelen; j; j--)
            *dst++ += *src++;
        src += src_stride - linelen;
        dst -= f->linesize[0] + linelen;
    }
}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx, void *data, int *got_frame,
                        AVPacket *avpkt)
{
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    CamStudioContext *c = avctx->priv_data;
    int ret;

    if (buf_size < 2) {
        av_log(avctx, AV_LOG_ERROR, "coded frame too small\n");
        return AVERROR_INVALIDDATA;
    }

    if ((ret = ff_reget_buffer(avctx, c->pic)) < 0)
        return ret;

    // decompress data
    switch ((buf[0] >> 1) & 7) {
    case 0: { // lzo compression
        int outlen = c->decomp_size, inlen = buf_size - 2;
        if (av_lzo1x_decode(c->decomp_buf, &outlen, &buf[2], &inlen) || outlen) {
            av_log(avctx, AV_LOG_ERROR, "error during lzo decompression\n");
            return AVERROR_INVALIDDATA;
        }
        break;
    }
    case 1: { // zlib compression
#if CONFIG_ZLIB
        unsigned long dlen = c->decomp_size;
        if (uncompress(c->decomp_buf, &dlen, &buf[2], buf_size - 2) != Z_OK) {
            av_log(avctx, AV_LOG_ERROR, "error during zlib decompression\n");
            return AVERROR_INVALIDDATA;
        }
        break;
#else
        av_log(avctx, AV_LOG_ERROR, "compiled without zlib support\n");
        return AVERROR(ENOSYS);
#endif
    }
    default:
        av_log(avctx, AV_LOG_ERROR, "unknown compression\n");
        return AVERROR_INVALIDDATA;
    }

    // flip upside down, add difference frame
    if (buf[0] & 1) { // keyframe
        c->pic->pict_type = AV_PICTURE_TYPE_I;
        c->pic->key_frame = 1;
              copy_frame_default(c->pic, c->decomp_buf,
                                 c->linelen, c->height);
    } else {
        c->pic->pict_type = AV_PICTURE_TYPE_P;
        c->pic->key_frame = 0;
              add_frame_default(c->pic, c->decomp_buf,
                                c->linelen, c->height);
    }

    *got_frame = 1;
    if ((ret = av_frame_ref(data, c->pic)) < 0)
        return ret;

    return buf_size;
}

