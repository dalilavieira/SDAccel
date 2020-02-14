#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;
typedef  struct TYPE_17__   TYPE_13__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  void* uint16_t ;
typedef  int int8_t ;
typedef  int int64_t ;
struct TYPE_20__ {int height; int bits_per_coded_sample; scalar_t__ discard_damaged_percentage; TYPE_1__* priv_data; } ;
struct TYPE_19__ {int size; int /*<<< orphan*/  data; } ;
struct TYPE_18__ {int const* pal; TYPE_13__* frame; TYPE_3__* avctx; int /*<<< orphan*/  g; } ;
struct TYPE_17__ {int* linesize; int** data; int palette_has_changed; } ;
typedef  TYPE_1__ QtrleContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AVPALETTE_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PKT_DATA_PALETTE ; 
 int /*<<< orphan*/  AV_WN16 (int*,void*) ; 
 int /*<<< orphan*/  AV_WN32 (int*,unsigned int) ; 
 int /*<<< orphan*/  AV_WN32A (int*,unsigned int) ; 
 int /*<<< orphan*/  AV_WN64 (int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CHECK_PIXEL_PTR (int) ; 
 int av_frame_ref (void*,TYPE_13__*) ; 
 int /*<<< orphan*/  av_log (TYPE_3__*,int /*<<< orphan*/ ,char*,int) ; 
 int* av_packet_get_side_data (TYPE_2__*,int /*<<< orphan*/ ,int*) ; 
 void* bytestream2_get_be16 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_be32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_get_buffer (int /*<<< orphan*/ *,int*,int) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 void* bytestream2_get_ne16 (int /*<<< orphan*/ *) ; 
 unsigned int bytestream2_get_ne32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_get_ne64 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int bytestream2_peek_byte (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int ff_reget_buffer (TYPE_3__*,TYPE_13__*) ; 
 int /*<<< orphan*/  memcpy (int const*,...) ; 

__attribute__((used)) static void qtrle_decode_1bpp(QtrleContext *s, int row_ptr, int lines_to_change)
{
    int rle_code;
    int pixel_ptr;
    int row_inc = s->frame->linesize[0];
    uint8_t pi0, pi1;  /* 2 8-pixel values */
    uint8_t *rgb = s->frame->data[0];
    int pixel_limit = s->frame->linesize[0] * s->avctx->height;
    int skip;
    /* skip & 0x80 appears to mean 'start a new line', which can be interpreted
     * as 'go to next line' during the decoding of a frame but is 'go to first
     * line' at the beginning. Since we always interpret it as 'go to next line'
     * in the decoding loop (which makes code simpler/faster), the first line
     * would not be counted, so we count one more.
     * See: https://trac.ffmpeg.org/ticket/226
     * In the following decoding loop, row_ptr will be the position of the
     * current row. */

    row_ptr  -= row_inc;
    pixel_ptr = row_ptr;
    lines_to_change++;
    while (lines_to_change) {
        skip     =              bytestream2_get_byte(&s->g);
        rle_code = (int8_t)bytestream2_get_byte(&s->g);
        if (rle_code == 0)
            break;
        if(skip & 0x80) {
            lines_to_change--;
            row_ptr += row_inc;
            pixel_ptr = row_ptr + 2 * 8 * (skip & 0x7f);
        } else
            pixel_ptr += 2 * 8 * skip;
        CHECK_PIXEL_PTR(0);  /* make sure pixel_ptr is positive */

        if(rle_code == -1)
            continue;

        if (rle_code < 0) {
            /* decode the run length code */
            rle_code = -rle_code;
            /* get the next 2 bytes from the stream, treat them as groups
             * of 8 pixels, and output them rle_code times */

            pi0 = bytestream2_get_byte(&s->g);
            pi1 = bytestream2_get_byte(&s->g);
            CHECK_PIXEL_PTR(rle_code * 2 * 8);

            while (rle_code--) {
                rgb[pixel_ptr++] = (pi0 >> 7) & 0x01;
                rgb[pixel_ptr++] = (pi0 >> 6) & 0x01;
                rgb[pixel_ptr++] = (pi0 >> 5) & 0x01;
                rgb[pixel_ptr++] = (pi0 >> 4) & 0x01;
                rgb[pixel_ptr++] = (pi0 >> 3) & 0x01;
                rgb[pixel_ptr++] = (pi0 >> 2) & 0x01;
                rgb[pixel_ptr++] = (pi0 >> 1) & 0x01;
                rgb[pixel_ptr++] =  pi0       & 0x01;
                rgb[pixel_ptr++] = (pi1 >> 7) & 0x01;
                rgb[pixel_ptr++] = (pi1 >> 6) & 0x01;
                rgb[pixel_ptr++] = (pi1 >> 5) & 0x01;
                rgb[pixel_ptr++] = (pi1 >> 4) & 0x01;
                rgb[pixel_ptr++] = (pi1 >> 3) & 0x01;
                rgb[pixel_ptr++] = (pi1 >> 2) & 0x01;
                rgb[pixel_ptr++] = (pi1 >> 1) & 0x01;
                rgb[pixel_ptr++] =  pi1       & 0x01;
            }
        } else {
            /* copy the same pixel directly to output 2 times */
            rle_code *= 2;
            CHECK_PIXEL_PTR(rle_code * 8);

            while (rle_code--) {
                int x = bytestream2_get_byte(&s->g);
                rgb[pixel_ptr++] = (x >> 7) & 0x01;
                rgb[pixel_ptr++] = (x >> 6) & 0x01;
                rgb[pixel_ptr++] = (x >> 5) & 0x01;
                rgb[pixel_ptr++] = (x >> 4) & 0x01;
                rgb[pixel_ptr++] = (x >> 3) & 0x01;
                rgb[pixel_ptr++] = (x >> 2) & 0x01;
                rgb[pixel_ptr++] = (x >> 1) & 0x01;
                rgb[pixel_ptr++] =  x       & 0x01;
            }
        }
    }
}

__attribute__((used)) static inline void qtrle_decode_2n4bpp(QtrleContext *s, int row_ptr,
                                       int lines_to_change, int bpp)
{
    int rle_code, i;
    int pixel_ptr;
    int row_inc = s->frame->linesize[0];
    uint8_t pi[16];  /* 16 palette indices */
    uint8_t *rgb = s->frame->data[0];
    int pixel_limit = s->frame->linesize[0] * s->avctx->height;
    int num_pixels = (bpp == 4) ? 8 : 16;

    while (lines_to_change--) {
        pixel_ptr = row_ptr + (num_pixels * (bytestream2_get_byte(&s->g) - 1));
        CHECK_PIXEL_PTR(0);

        while ((rle_code = (int8_t)bytestream2_get_byte(&s->g)) != -1) {
            if (bytestream2_get_bytes_left(&s->g) < 1)
                return;
            if (rle_code == 0) {
                /* there's another skip code in the stream */
                pixel_ptr += (num_pixels * (bytestream2_get_byte(&s->g) - 1));
                CHECK_PIXEL_PTR(0);  /* make sure pixel_ptr is positive */
            } else if (rle_code < 0) {
                /* decode the run length code */
                rle_code = -rle_code;
                /* get the next 4 bytes from the stream, treat them as palette
                 * indexes, and output them rle_code times */
                for (i = num_pixels-1; i >= 0; i--) {
                    pi[num_pixels-1-i] = (bytestream2_peek_byte(&s->g) >> ((i*bpp) & 0x07)) & ((1<<bpp)-1);
                    bytestream2_skip(&s->g, ((i & ((num_pixels>>2)-1)) == 0));
                }
                CHECK_PIXEL_PTR(rle_code * num_pixels);
                while (rle_code--) {
                    memcpy(&rgb[pixel_ptr], &pi, num_pixels);
                    pixel_ptr += num_pixels;
                }
            } else {
                /* copy the same pixel directly to output 4 times */
                rle_code *= 4;
                CHECK_PIXEL_PTR(rle_code*(num_pixels>>2));
                while (rle_code--) {
                    if(bpp == 4) {
                        int x = bytestream2_get_byte(&s->g);
                        rgb[pixel_ptr++] = (x >> 4) & 0x0f;
                        rgb[pixel_ptr++] =  x       & 0x0f;
                    } else {
                        int x = bytestream2_get_byte(&s->g);
                        rgb[pixel_ptr++] = (x >> 6) & 0x03;
                        rgb[pixel_ptr++] = (x >> 4) & 0x03;
                        rgb[pixel_ptr++] = (x >> 2) & 0x03;
                        rgb[pixel_ptr++] =  x       & 0x03;
                    }
                }
            }
        }
        row_ptr += row_inc;
    }
}

__attribute__((used)) static void qtrle_decode_8bpp(QtrleContext *s, int row_ptr, int lines_to_change)
{
    int rle_code;
    int pixel_ptr;
    int row_inc = s->frame->linesize[0];
    uint8_t pi1, pi2, pi3, pi4;  /* 4 palette indexes */
    uint8_t *rgb = s->frame->data[0];
    int pixel_limit = s->frame->linesize[0] * s->avctx->height;

    while (lines_to_change--) {
        pixel_ptr = row_ptr + (4 * (bytestream2_get_byte(&s->g) - 1));
        CHECK_PIXEL_PTR(0);

        while ((rle_code = (int8_t)bytestream2_get_byte(&s->g)) != -1) {
            if (bytestream2_get_bytes_left(&s->g) < 1)
                return;
            if (rle_code == 0) {
                /* there's another skip code in the stream */
                pixel_ptr += (4 * (bytestream2_get_byte(&s->g) - 1));
                CHECK_PIXEL_PTR(0);  /* make sure pixel_ptr is positive */
            } else if (rle_code < 0) {
                /* decode the run length code */
                rle_code = -rle_code;
                /* get the next 4 bytes from the stream, treat them as palette
                 * indexes, and output them rle_code times */
                pi1 = bytestream2_get_byte(&s->g);
                pi2 = bytestream2_get_byte(&s->g);
                pi3 = bytestream2_get_byte(&s->g);
                pi4 = bytestream2_get_byte(&s->g);

                CHECK_PIXEL_PTR(rle_code * 4);

                while (rle_code--) {
                    rgb[pixel_ptr++] = pi1;
                    rgb[pixel_ptr++] = pi2;
                    rgb[pixel_ptr++] = pi3;
                    rgb[pixel_ptr++] = pi4;
                }
            } else {
                /* copy the same pixel directly to output 4 times */
                rle_code *= 4;
                CHECK_PIXEL_PTR(rle_code);

                bytestream2_get_buffer(&s->g, &rgb[pixel_ptr], rle_code);
                pixel_ptr += rle_code;
            }
        }
        row_ptr += row_inc;
    }
}

__attribute__((used)) static void qtrle_decode_16bpp(QtrleContext *s, int row_ptr, int lines_to_change)
{
    int rle_code;
    int pixel_ptr;
    int row_inc = s->frame->linesize[0];
    uint16_t rgb16;
    uint8_t *rgb = s->frame->data[0];
    int pixel_limit = s->frame->linesize[0] * s->avctx->height;

    while (lines_to_change--) {
        pixel_ptr = row_ptr + (bytestream2_get_byte(&s->g) - 1) * 2;
        CHECK_PIXEL_PTR(0);

        while ((rle_code = (int8_t)bytestream2_get_byte(&s->g)) != -1) {
            if (bytestream2_get_bytes_left(&s->g) < 1)
                return;
            if (rle_code == 0) {
                /* there's another skip code in the stream */
                pixel_ptr += (bytestream2_get_byte(&s->g) - 1) * 2;
                CHECK_PIXEL_PTR(0);  /* make sure pixel_ptr is positive */
            } else if (rle_code < 0) {
                /* decode the run length code */
                rle_code = -rle_code;
                rgb16 = bytestream2_get_be16(&s->g);

                CHECK_PIXEL_PTR(rle_code * 2);

                while (rle_code--) {
                    *(uint16_t *)(&rgb[pixel_ptr]) = rgb16;
                    pixel_ptr += 2;
                }
            } else {
                CHECK_PIXEL_PTR(rle_code * 2);

                /* copy pixels directly to output */
                while (rle_code--) {
                    rgb16 = bytestream2_get_be16(&s->g);
                    *(uint16_t *)(&rgb[pixel_ptr]) = rgb16;
                    pixel_ptr += 2;
                }
            }
        }
        row_ptr += row_inc;
    }
}

__attribute__((used)) static void qtrle_decode_24bpp(QtrleContext *s, int row_ptr, int lines_to_change)
{
    int rle_code, rle_code_half;
    int pixel_ptr;
    int row_inc = s->frame->linesize[0];
    uint8_t b;
    uint16_t rg;
    uint8_t *rgb = s->frame->data[0];
    int pixel_limit = s->frame->linesize[0] * s->avctx->height;

    while (lines_to_change--) {
        pixel_ptr = row_ptr + (bytestream2_get_byte(&s->g) - 1) * 3;
        CHECK_PIXEL_PTR(0);

        while ((rle_code = (int8_t)bytestream2_get_byte(&s->g)) != -1) {
            if (bytestream2_get_bytes_left(&s->g) < 1)
                return;
            if (rle_code == 0) {
                /* there's another skip code in the stream */
                pixel_ptr += (bytestream2_get_byte(&s->g) - 1) * 3;
                CHECK_PIXEL_PTR(0);  /* make sure pixel_ptr is positive */
            } else if (rle_code < 0) {
                /* decode the run length code */
                rle_code = -rle_code;
                rg = bytestream2_get_ne16(&s->g);
                b = bytestream2_get_byte(&s->g);

                CHECK_PIXEL_PTR(rle_code * 3);

                while (rle_code--) {
                    AV_WN16(rgb + pixel_ptr, rg);
                    rgb[pixel_ptr + 2] = b;
                    pixel_ptr += 3;
                }
            } else {
                CHECK_PIXEL_PTR(rle_code * 3);

                rle_code_half = rle_code / 2;

                while (rle_code_half--) { /* copy 2 raw rgb value at the same time */
                    AV_WN32(rgb + pixel_ptr, bytestream2_get_ne32(&s->g)); /* rgbr */
                    AV_WN16(rgb + pixel_ptr + 4, bytestream2_get_ne16(&s->g)); /* rgbr */
                    pixel_ptr += 6;
                }

                if (rle_code % 2 != 0){ /* not even raw value */
                    AV_WN16(rgb + pixel_ptr, bytestream2_get_ne16(&s->g));
                    rgb[pixel_ptr + 2] = bytestream2_get_byte(&s->g);
                    pixel_ptr += 3;
                }
            }
        }
        row_ptr += row_inc;
    }
}

__attribute__((used)) static void qtrle_decode_32bpp(QtrleContext *s, int row_ptr, int lines_to_change)
{
    int rle_code, rle_code_half;
    int pixel_ptr;
    int row_inc = s->frame->linesize[0];
    unsigned int argb;
    uint8_t *rgb = s->frame->data[0];
    int pixel_limit = s->frame->linesize[0] * s->avctx->height;

    while (lines_to_change--) {
        pixel_ptr = row_ptr + (bytestream2_get_byte(&s->g) - 1) * 4;
        CHECK_PIXEL_PTR(0);

        while ((rle_code = (int8_t)bytestream2_get_byte(&s->g)) != -1) {
            if (bytestream2_get_bytes_left(&s->g) < 1)
                return;
            if (rle_code == 0) {
                /* there's another skip code in the stream */
                pixel_ptr += (bytestream2_get_byte(&s->g) - 1) * 4;
                CHECK_PIXEL_PTR(0);  /* make sure pixel_ptr is positive */
            } else if (rle_code < 0) {
                /* decode the run length code */
                rle_code = -rle_code;
                argb = bytestream2_get_ne32(&s->g);

                CHECK_PIXEL_PTR(rle_code * 4);

                while (rle_code--) {
                    AV_WN32A(rgb + pixel_ptr, argb);
                    pixel_ptr += 4;
                }
            } else {
                CHECK_PIXEL_PTR(rle_code * 4);

                /* copy pixels directly to output */
                rle_code_half = rle_code / 2;
                while (rle_code_half--) { /* copy 2 argb raw value at the same time */
                    AV_WN64(rgb + pixel_ptr, bytestream2_get_ne64(&s->g));
                    pixel_ptr += 8;
                }

                if (rle_code % 2 != 0){ /* not even raw value */
                    AV_WN32A(rgb + pixel_ptr, bytestream2_get_ne32(&s->g));
                    pixel_ptr += 4;
                }
            }
        }
        row_ptr += row_inc;
    }
}

__attribute__((used)) static int qtrle_decode_frame(AVCodecContext *avctx,
                              void *data, int *got_frame,
                              AVPacket *avpkt)
{
    QtrleContext *s = avctx->priv_data;
    int header, start_line;
    int height, row_ptr;
    int has_palette = 0;
    int ret, size;

    bytestream2_init(&s->g, avpkt->data, avpkt->size);

    /* check if this frame is even supposed to change */
    if (avpkt->size < 8)
        return avpkt->size;

    /* start after the chunk size */
    size = bytestream2_get_be32(&s->g) & 0x3FFFFFFF;
    if (size - avpkt->size >  size * (int64_t)avctx->discard_damaged_percentage / 100)
        return AVERROR_INVALIDDATA;


    /* fetch the header */
    header = bytestream2_get_be16(&s->g);

    /* if a header is present, fetch additional decoding parameters */
    if (header & 0x0008) {
        if (avpkt->size < 14)
            return avpkt->size;
        start_line = bytestream2_get_be16(&s->g);
        bytestream2_skip(&s->g, 2);
        height     = bytestream2_get_be16(&s->g);
        bytestream2_skip(&s->g, 2);
        if (height > s->avctx->height - start_line)
            return avpkt->size;
    } else {
        start_line = 0;
        height     = s->avctx->height;
    }
    if ((ret = ff_reget_buffer(avctx, s->frame)) < 0)
        return ret;

    row_ptr = s->frame->linesize[0] * start_line;

    switch (avctx->bits_per_coded_sample) {
    case 1:
    case 33:
        qtrle_decode_1bpp(s, row_ptr, height);
        has_palette = 1;
        break;

    case 2:
    case 34:
        qtrle_decode_2n4bpp(s, row_ptr, height, 2);
        has_palette = 1;
        break;

    case 4:
    case 36:
        qtrle_decode_2n4bpp(s, row_ptr, height, 4);
        has_palette = 1;
        break;

    case 8:
    case 40:
        qtrle_decode_8bpp(s, row_ptr, height);
        has_palette = 1;
        break;

    case 16:
        qtrle_decode_16bpp(s, row_ptr, height);
        break;

    case 24:
        qtrle_decode_24bpp(s, row_ptr, height);
        break;

    case 32:
        qtrle_decode_32bpp(s, row_ptr, height);
        break;

    default:
        av_log (s->avctx, AV_LOG_ERROR, "Unsupported colorspace: %d bits/sample?\n",
            avctx->bits_per_coded_sample);
        break;
    }

    if(has_palette) {
        int size;
        const uint8_t *pal = av_packet_get_side_data(avpkt, AV_PKT_DATA_PALETTE, &size);

        if (pal && size == AVPALETTE_SIZE) {
            s->frame->palette_has_changed = 1;
            memcpy(s->pal, pal, AVPALETTE_SIZE);
        } else if (pal) {
            av_log(avctx, AV_LOG_ERROR, "Palette size %d is wrong\n", size);
        }

        /* make the palette available on the way out */
        memcpy(s->frame->data[1], s->pal, AVPALETTE_SIZE);
    }

    if ((ret = av_frame_ref(data, s->frame)) < 0)
        return ret;
    *got_frame      = 1;

    /* always report that the buffer was completely consumed */
    return avpkt->size;
}

