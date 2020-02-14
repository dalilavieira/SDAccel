#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_2__ ;
typedef  struct TYPE_33__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct TYPE_36__ {scalar_t__ pix_fmt; int width; int height; } ;
struct TYPE_35__ {int** data; int palette_has_changed; int key_frame; int /*<<< orphan*/  pict_type; int /*<<< orphan*/ * linesize; } ;
struct TYPE_34__ {int size; int /*<<< orphan*/  data; } ;
struct TYPE_33__ {char* buffer; } ;
typedef  TYPE_1__ GetByteContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AVERROR_PATCHWELCOME ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_TRACE ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 void* AV_PIX_FMT_ARGB ; 
 scalar_t__ AV_PIX_FMT_PAL8 ; 
 void* AV_PIX_FMT_RGB24 ; 
 void* AV_PIX_FMT_RGB555 ; 
 unsigned int AV_RB16 (char const*) ; 
#define  CLIP 133 
#define  DIRECTBITSRECT 132 
#define  DIRECTBITSRGN 131 
 int EOP ; 
#define  LONGCOMMENT 130 
#define  PACKBITSRECT 129 
#define  PACKBITSRGN 128 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  avpriv_report_missing_feature (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  avpriv_request_sample (TYPE_4__*,char*,...) ; 
 int bytestream2_get_be16 (TYPE_1__*) ; 
 int bytestream2_get_be32 (TYPE_1__*) ; 
 int bytestream2_get_byte (TYPE_1__*) ; 
 int bytestream2_get_bytes_left (TYPE_1__*) ; 
 int /*<<< orphan*/  bytestream2_init (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bytestream2_skip (TYPE_1__*,int) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__* const,int /*<<< orphan*/ ) ; 
 int ff_set_dimensions (TYPE_4__*,int,int) ; 

__attribute__((used)) static int parse_palette(AVCodecContext *avctx, GetByteContext *gbc,
                         uint32_t *pal, int colors, int pixmap)
{
    int i;

    for (i = 0; i <= colors; i++) {
        uint8_t r, g, b;
        unsigned int idx = bytestream2_get_be16(gbc); /* color index */
        if (idx > 255 && !pixmap) {
            av_log(avctx, AV_LOG_WARNING,
                   "Palette index out of range: %u\n", idx);
            bytestream2_skip(gbc, 6);
            continue;
        }
        if (avctx->pix_fmt != AV_PIX_FMT_PAL8)
            return AVERROR_INVALIDDATA;
        r = bytestream2_get_byte(gbc);
        bytestream2_skip(gbc, 1);
        g = bytestream2_get_byte(gbc);
        bytestream2_skip(gbc, 1);
        b = bytestream2_get_byte(gbc);
        bytestream2_skip(gbc, 1);
        pal[pixmap ? i : idx] = (0xFFU << 24) | (r << 16) | (g << 8) | b;
    }
    return 0;
}

__attribute__((used)) static int decode_rle_bpp2(AVCodecContext *avctx, AVFrame *p, GetByteContext *gbc)
{
    int offset = avctx->width;
    uint8_t *outdata = p->data[0];
    int i, j;

    for (i = 0; i < avctx->height; i++) {
        int size, left, code, pix;
        uint8_t *out = outdata;
        int pos = 0;

        /* size of packed line */
        if (offset / 4 > 200)
            size = left = bytestream2_get_be16(gbc);
        else
            size = left = bytestream2_get_byte(gbc);
        if (bytestream2_get_bytes_left(gbc) < size)
            return AVERROR_INVALIDDATA;

        /* decode line */
        while (left > 0) {
            code = bytestream2_get_byte(gbc);
            if (code & 0x80 ) { /* run */
                pix = bytestream2_get_byte(gbc);
                for (j = 0; j < 257 - code; j++) {
                    if (pos < offset)
                        out[pos++] = (pix & 0xC0) >> 6;
                    if (pos < offset)
                        out[pos++] = (pix & 0x30) >> 4;
                    if (pos < offset)
                        out[pos++] = (pix & 0x0C) >> 2;
                    if (pos < offset)
                        out[pos++] = (pix & 0x03);
                }
                left  -= 2;
            } else { /* copy */
                for (j = 0; j < code + 1; j++) {
                    pix = bytestream2_get_byte(gbc);
                    if (pos < offset)
                        out[pos++] = (pix & 0xC0) >> 6;
                    if (pos < offset)
                        out[pos++] = (pix & 0x30) >> 4;
                    if (pos < offset)
                        out[pos++] = (pix & 0x0C) >> 2;
                    if (pos < offset)
                        out[pos++] = (pix & 0x03);
                }
                left  -= 1 + (code + 1);
            }
        }
        outdata += p->linesize[0];
    }
    return 0;
}

__attribute__((used)) static int decode_rle_bpp4(AVCodecContext *avctx, AVFrame *p, GetByteContext *gbc)
{
    int offset = avctx->width;
    uint8_t *outdata = p->data[0];
    int i, j;

    for (i = 0; i < avctx->height; i++) {
        int size, left, code, pix;
        uint8_t *out = outdata;
        int pos = 0;

        /* size of packed line */
        size = left = bytestream2_get_be16(gbc);
        if (bytestream2_get_bytes_left(gbc) < size)
            return AVERROR_INVALIDDATA;

        /* decode line */
        while (left > 0) {
            code = bytestream2_get_byte(gbc);
            if (code & 0x80 ) { /* run */
                pix = bytestream2_get_byte(gbc);
                for (j = 0; j < 257 - code; j++) {
                    if (pos < offset)
                        out[pos++] = (pix & 0xF0) >> 4;
                    if (pos < offset)
                        out[pos++] = pix & 0xF;
                }
                left  -= 2;
            } else { /* copy */
                for (j = 0; j < code + 1; j++) {
                    pix = bytestream2_get_byte(gbc);
                    if (pos < offset)
                        out[pos++] = (pix & 0xF0) >> 4;
                    if (pos < offset)
                        out[pos++] = pix & 0xF;
                }
                left  -= 1 + (code + 1);
            }
        }
        outdata += p->linesize[0];
    }
    return 0;
}

__attribute__((used)) static int decode_rle16(AVCodecContext *avctx, AVFrame *p, GetByteContext *gbc)
{
    int offset = avctx->width;
    uint8_t *outdata = p->data[0];
    int i, j;

    for (i = 0; i < avctx->height; i++) {
        int size, left, code, pix;
        uint16_t *out = (uint16_t *)outdata;
        int pos = 0;

        /* size of packed line */
        size = left = bytestream2_get_be16(gbc);
        if (bytestream2_get_bytes_left(gbc) < size)
            return AVERROR_INVALIDDATA;

        /* decode line */
        while (left > 0) {
            code = bytestream2_get_byte(gbc);
            if (code & 0x80 ) { /* run */
                pix = bytestream2_get_be16(gbc);
                for (j = 0; j < 257 - code; j++) {
                    if (pos < offset) {
                        out[pos++] = pix;
                    }
                }
                left  -= 3;
            } else { /* copy */
                for (j = 0; j < code + 1; j++) {
                    if (pos < offset) {
                        out[pos++] = bytestream2_get_be16(gbc);
                    } else {
                        bytestream2_skip(gbc, 2);
                    }
                }
                left  -= 1 + (code + 1) * 2;
            }
        }
        outdata += p->linesize[0];
    }
    return 0;
}

__attribute__((used)) static int decode_rle(AVCodecContext *avctx, AVFrame *p, GetByteContext *gbc,
                      int step)
{
    int i, j;
    int offset = avctx->width * step;
    uint8_t *outdata = p->data[0];

    for (i = 0; i < avctx->height; i++) {
        int size, left, code, pix;
        uint8_t *out = outdata;
        int pos = 0;

        /* size of packed line */
        size = left = bytestream2_get_be16(gbc);
        if (bytestream2_get_bytes_left(gbc) < size)
            return AVERROR_INVALIDDATA;

        /* decode line */
        while (left > 0) {
            code = bytestream2_get_byte(gbc);
            if (code & 0x80 ) { /* run */
                pix = bytestream2_get_byte(gbc);
                for (j = 0; j < 257 - code; j++) {
                    if (pos < offset)
                        out[pos] = pix;
                    pos += step;
                    if (pos >= offset && step > 1) {
                        pos -= offset;
                        pos++;
                    }
                }
                left  -= 2;
            } else { /* copy */
                for (j = 0; j < code + 1; j++) {
                    pix = bytestream2_get_byte(gbc);
                    if (pos < offset)
                        out[pos] = pix;
                    pos += step;
                    if (pos >= offset && step > 1) {
                        pos -= offset;
                        pos++;
                    }
                }
                left  -= 2 + code;
            }
        }
        outdata += p->linesize[0];
    }
    return 0;
}

__attribute__((used)) static int check_header(const char *buf, int buf_size)
{
    unsigned w, h, v0, v1;

    if (buf_size < 40)
        return 0;

    w = AV_RB16(buf+6);
    h = AV_RB16(buf+8);
    v0 = AV_RB16(buf+10);
    v1 = AV_RB16(buf+12);

    if (!w || !h)
        return 0;

    if (v0 == 0x1101)
        return 1;
    if (v0 == 0x0011 && v1 == 0x02FF)
        return 2;
    return 0;
}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx,
                        void *data, int *got_frame,
                        AVPacket *avpkt)
{
    AVFrame * const p      = data;
    GetByteContext gbc;
    int colors;
    int w, h, ret;
    int ver;

    bytestream2_init(&gbc, avpkt->data, avpkt->size);
    if (   bytestream2_get_bytes_left(&gbc) >= 552
           &&  check_header(gbc.buffer + 512, bytestream2_get_bytes_left(&gbc) - 512)
       )
        bytestream2_skip(&gbc, 512);

    ver = check_header(gbc.buffer, bytestream2_get_bytes_left(&gbc));

    /* smallest PICT header */
    if (bytestream2_get_bytes_left(&gbc) < 40) {
        av_log(avctx, AV_LOG_ERROR, "Frame is too small %d\n",
               bytestream2_get_bytes_left(&gbc));
        return AVERROR_INVALIDDATA;
    }

    bytestream2_skip(&gbc, 6);
    h = bytestream2_get_be16(&gbc);
    w = bytestream2_get_be16(&gbc);

    ret = ff_set_dimensions(avctx, w, h);
    if (ret < 0)
        return ret;

    /* version 1 is identified by 0x1101
     * it uses byte-aligned opcodes rather than word-aligned */
    if (ver == 1) {
        avpriv_request_sample(avctx, "QuickDraw version 1");
        return AVERROR_PATCHWELCOME;
    } else if (ver != 2) {
        avpriv_request_sample(avctx, "QuickDraw version unknown (%X)", bytestream2_get_be32(&gbc));
        return AVERROR_PATCHWELCOME;
    }

    bytestream2_skip(&gbc, 4+26);

    while (bytestream2_get_bytes_left(&gbc) >= 4) {
        int bppcnt, bpp;
        int rowbytes, pack_type;
        int flags;
        int opcode = bytestream2_get_be16(&gbc);

        switch(opcode) {
        case CLIP:
            bytestream2_skip(&gbc, 10);
            break;
        case PACKBITSRECT:
        case PACKBITSRGN:
            av_log(avctx, AV_LOG_DEBUG, "Parsing Packbit opcode\n");

            flags = bytestream2_get_be16(&gbc) & 0xC000;
            bytestream2_skip(&gbc, 28);
            bppcnt = bytestream2_get_be16(&gbc); /* cmpCount */
            bpp    = bytestream2_get_be16(&gbc); /* cmpSize */

            av_log(avctx, AV_LOG_DEBUG, "bppcount %d bpp %d\n", bppcnt, bpp);
            if (bppcnt == 1 && bpp == 8) {
                avctx->pix_fmt = AV_PIX_FMT_PAL8;
            } else if (bppcnt == 1 && (bpp == 4 || bpp == 2)) {
                avctx->pix_fmt = AV_PIX_FMT_PAL8;
            } else if (bppcnt == 3 && bpp == 5) {
                avctx->pix_fmt = AV_PIX_FMT_RGB555;
            } else {
                av_log(avctx, AV_LOG_ERROR,
                       "Invalid pixel format (bppcnt %d bpp %d) in Packbit\n",
                       bppcnt, bpp);
                return AVERROR_INVALIDDATA;
            }

            /* jump to palette */
            bytestream2_skip(&gbc, 18);
            colors = bytestream2_get_be16(&gbc);

            if (colors < 0 || colors > 256) {
                av_log(avctx, AV_LOG_ERROR,
                       "Error color count - %i(0x%X)\n", colors, colors);
                return AVERROR_INVALIDDATA;
            }
            if (bytestream2_get_bytes_left(&gbc) < (colors + 1) * 8) {
                av_log(avctx, AV_LOG_ERROR, "Palette is too small %d\n",
                       bytestream2_get_bytes_left(&gbc));
                return AVERROR_INVALIDDATA;
            }
            if ((ret = ff_get_buffer(avctx, p, 0)) < 0)
                return ret;

            ret = parse_palette(avctx, &gbc, (uint32_t *)p->data[1], colors, flags & 0x8000);
            if (ret < 0)
                return ret;
            p->palette_has_changed = 1;

            /* jump to image data */
            bytestream2_skip(&gbc, 18);

            if (opcode == PACKBITSRGN) {
                bytestream2_skip(&gbc, 2 + 8); /* size + rect */
                avpriv_report_missing_feature(avctx, "Packbit mask region");
            }

            if (avctx->pix_fmt == AV_PIX_FMT_RGB555)
                ret = decode_rle16(avctx, p, &gbc);
            else if (bpp == 2)
                ret = decode_rle_bpp2(avctx, p, &gbc);
            else if (bpp == 4)
                ret = decode_rle_bpp4(avctx, p, &gbc);
            else
                ret = decode_rle(avctx, p, &gbc, bppcnt);
            if (ret < 0)
                return ret;
            *got_frame = 1;
            break;
        case DIRECTBITSRECT:
        case DIRECTBITSRGN:
            av_log(avctx, AV_LOG_DEBUG, "Parsing Directbit opcode\n");

            bytestream2_skip(&gbc, 4);
            rowbytes = bytestream2_get_be16(&gbc) & 0x3FFF;
            if (rowbytes <= 250) {
                avpriv_report_missing_feature(avctx, "Short rowbytes");
                return AVERROR_PATCHWELCOME;
            }

            bytestream2_skip(&gbc, 4);
            h = bytestream2_get_be16(&gbc);
            w = bytestream2_get_be16(&gbc);
            bytestream2_skip(&gbc, 2);

            ret = ff_set_dimensions(avctx, w, h);
            if (ret < 0)
                return ret;

            pack_type = bytestream2_get_be16(&gbc);

            bytestream2_skip(&gbc, 16);
            bppcnt = bytestream2_get_be16(&gbc); /* cmpCount */
            bpp    = bytestream2_get_be16(&gbc); /* cmpSize */

            av_log(avctx, AV_LOG_DEBUG, "bppcount %d bpp %d\n", bppcnt, bpp);
            if (bppcnt == 3 && bpp == 8) {
                avctx->pix_fmt = AV_PIX_FMT_RGB24;
            } else if (bppcnt == 3 && bpp == 5 || bppcnt == 2 && bpp == 8) {
                avctx->pix_fmt = AV_PIX_FMT_RGB555;
            } else if (bppcnt == 4 && bpp == 8) {
                avctx->pix_fmt = AV_PIX_FMT_ARGB;
            } else {
                av_log(avctx, AV_LOG_ERROR,
                       "Invalid pixel format (bppcnt %d bpp %d) in Directbit\n",
                       bppcnt, bpp);
                return AVERROR_INVALIDDATA;
            }

            /* set packing when default is selected */
            if (pack_type == 0)
                pack_type = bppcnt;

            if (pack_type != 3 && pack_type != 4) {
                avpriv_request_sample(avctx, "Pack type %d", pack_type);
                return AVERROR_PATCHWELCOME;
            }
            if ((ret = ff_get_buffer(avctx, p, 0)) < 0)
                return ret;

            /* jump to data */
            bytestream2_skip(&gbc, 30);

            if (opcode == DIRECTBITSRGN) {
                bytestream2_skip(&gbc, 2 + 8); /* size + rect */
                avpriv_report_missing_feature(avctx, "DirectBit mask region");
            }

            if (avctx->pix_fmt == AV_PIX_FMT_RGB555)
                ret = decode_rle16(avctx, p, &gbc);
            else
                ret = decode_rle(avctx, p, &gbc, bppcnt);
            if (ret < 0)
                return ret;
            *got_frame = 1;
            break;
        case LONGCOMMENT:
            bytestream2_get_be16(&gbc);
            bytestream2_skip(&gbc, bytestream2_get_be16(&gbc));
            break;
        default:
            av_log(avctx, AV_LOG_TRACE, "Unknown 0x%04X opcode\n", opcode);
            break;
        }
        /* exit the loop when a known pixel block has been found */
        if (*got_frame) {
            int eop, trail;

            /* re-align to a word */
            bytestream2_skip(&gbc, bytestream2_get_bytes_left(&gbc) % 2);

            eop = bytestream2_get_be16(&gbc);
            trail = bytestream2_get_bytes_left(&gbc);
            if (eop != EOP)
                av_log(avctx, AV_LOG_WARNING,
                       "Missing end of picture opcode (found 0x%04X)\n", eop);
            if (trail)
                av_log(avctx, AV_LOG_WARNING, "Got %d trailing bytes\n", trail);
            break;
        }
    }

    if (*got_frame) {
        p->pict_type = AV_PICTURE_TYPE_I;
        p->key_frame = 1;

        return avpkt->size;
    } else {
        av_log(avctx, AV_LOG_ERROR, "Frame contained no usable data\n");

        return AVERROR_INVALIDDATA;
    }
}

