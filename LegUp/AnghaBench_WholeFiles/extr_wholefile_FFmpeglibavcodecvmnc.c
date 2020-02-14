#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int int64_t ;
struct TYPE_14__ {int bpp2; int* curbits; int cur_h; int cur_w; int bigendian; int* curmask; scalar_t__ width; scalar_t__ cur_x; scalar_t__ height; scalar_t__ cur_y; int* screendta; int cur_hx; int cur_hy; int bpp; TYPE_8__* pic; int /*<<< orphan*/  gb; int /*<<< orphan*/  avctx; } ;
typedef  TYPE_1__ VmncContext ;
struct TYPE_17__ {int key_frame; int** data; int* linesize; int /*<<< orphan*/  pict_type; } ;
struct TYPE_16__ {TYPE_1__* priv_data; } ;
struct TYPE_15__ {int* data; int size; } ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int /*<<< orphan*/  EINVAL ; 
 int HT_BKG ; 
 int HT_CLR ; 
 int HT_FG ; 
 int HT_RAW ; 
 int HT_SUB ; 
 int INT_MAX ; 
#define  MAGIC_WMVd 134 
#define  MAGIC_WMVe 133 
#define  MAGIC_WMVf 132 
#define  MAGIC_WMVg 131 
#define  MAGIC_WMVh 130 
#define  MAGIC_WMVi 129 
#define  MAGIC_WMVj 128 
 int av_frame_ref (void*,TYPE_8__*) ; 
 int /*<<< orphan*/  av_freep (int**) ; 
 int /*<<< orphan*/  av_log (TYPE_3__*,int /*<<< orphan*/ ,char*,...) ; 
 int av_reallocp (int**,int) ; 
 int bytestream2_get_be16 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_be32 (int /*<<< orphan*/ *) ; 
 void* bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int const*,int) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int ff_reget_buffer (TYPE_3__*,TYPE_8__*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  paint_raw (int*,int,int,int /*<<< orphan*/ *,int const,int,int) ; 
 int /*<<< orphan*/  paint_rect (int*,int,int,int,int,int,int const,int) ; 
 int vmnc_get_pixel (int /*<<< orphan*/ *,int const,int) ; 

__attribute__((used)) static void load_cursor(VmncContext *c)
{
    int i, j, p;
    const int bpp   = c->bpp2;
    uint8_t *dst8   =             c->curbits;
    uint16_t *dst16 = (uint16_t *)c->curbits;
    uint32_t *dst32 = (uint32_t *)c->curbits;

    for (j = 0; j < c->cur_h; j++) {
        for (i = 0; i < c->cur_w; i++) {
            p = vmnc_get_pixel(&c->gb, bpp, c->bigendian);
            if (bpp == 1)
                *dst8++ = p;
            if (bpp == 2)
                *dst16++ = p;
            if (bpp == 4)
                *dst32++ = p;
        }
    }
    dst8  =            c->curmask;
    dst16 = (uint16_t*)c->curmask;
    dst32 = (uint32_t*)c->curmask;
    for (j = 0; j < c->cur_h; j++) {
        for (i = 0; i < c->cur_w; i++) {
            p = vmnc_get_pixel(&c->gb, bpp, c->bigendian);
            if (bpp == 1)
                *dst8++ = p;
            if (bpp == 2)
                *dst16++ = p;
            if (bpp == 4)
                *dst32++ = p;
        }
    }
}

__attribute__((used)) static void put_cursor(uint8_t *dst, int stride, VmncContext *c, int dx, int dy)
{
    int i, j;
    int w, h, x, y;
    w = c->cur_w;
    if (c->width < c->cur_x + c->cur_w)
        w = c->width - c->cur_x;
    h = c->cur_h;
    if (c->height < c->cur_y + c->cur_h)
        h = c->height - c->cur_y;
    x = c->cur_x;
    y = c->cur_y;
    if (x < 0) {
        w += x;
        x  = 0;
    }
    if (y < 0) {
        h += y;
        y  = 0;
    }

    if ((w < 1) || (h < 1))
        return;
    dst += x * c->bpp2 + y * stride;

    if (c->bpp2 == 1) {
        uint8_t *cd = c->curbits, *msk = c->curmask;
        for (j = 0; j < h; j++) {
            for (i = 0; i < w; i++)
                dst[i] = (dst[i] & cd[i]) ^ msk[i];
            msk += c->cur_w;
            cd  += c->cur_w;
            dst += stride;
        }
    } else if (c->bpp2 == 2) {
        uint16_t *cd = (uint16_t*)c->curbits, *msk = (uint16_t*)c->curmask;
        uint16_t *dst2;
        for (j = 0; j < h; j++) {
            dst2 = (uint16_t*)dst;
            for (i = 0; i < w; i++)
                dst2[i] = (dst2[i] & cd[i]) ^ msk[i];
            msk += c->cur_w;
            cd  += c->cur_w;
            dst += stride;
        }
    } else if (c->bpp2 == 4) {
        uint32_t *cd = (uint32_t*)c->curbits, *msk = (uint32_t*)c->curmask;
        uint32_t *dst2;
        for (j = 0; j < h; j++) {
            dst2 = (uint32_t*)dst;
            for (i = 0; i < w; i++)
                dst2[i] = (dst2[i] & cd[i]) ^ msk[i];
            msk += c->cur_w;
            cd  += c->cur_w;
            dst += stride;
        }
    }
}

__attribute__((used)) static int decode_hextile(VmncContext *c, uint8_t* dst, GetByteContext *gb,
                          int w, int h, int stride)
{
    int i, j, k;
    int bg = 0, fg = 0, rects, color, flags, xy, wh;
    const int bpp = c->bpp2;
    uint8_t *dst2;
    int bw = 16, bh = 16;

    for (j = 0; j < h; j += 16) {
        dst2 = dst;
        bw   = 16;
        if (j + 16 > h)
            bh = h - j;
        for (i = 0; i < w; i += 16, dst2 += 16 * bpp) {
            if (bytestream2_get_bytes_left(gb) <= 0) {
                av_log(c->avctx, AV_LOG_ERROR, "Premature end of data!\n");
                return AVERROR_INVALIDDATA;
            }
            if (i + 16 > w)
                bw = w - i;
            flags = bytestream2_get_byte(gb);
            if (flags & HT_RAW) {
                if (bytestream2_get_bytes_left(gb) < bw * bh * bpp) {
                    av_log(c->avctx, AV_LOG_ERROR, "Premature end of data!\n");
                    return AVERROR_INVALIDDATA;
                }
                paint_raw(dst2, bw, bh, gb, bpp, c->bigendian, stride);
            } else {
                if (flags & HT_BKG)
                    bg = vmnc_get_pixel(gb, bpp, c->bigendian);
                if (flags & HT_FG)
                    fg = vmnc_get_pixel(gb, bpp, c->bigendian);
                rects = 0;
                if (flags & HT_SUB)
                    rects = bytestream2_get_byte(gb);
                color = !!(flags & HT_CLR);

                paint_rect(dst2, 0, 0, bw, bh, bg, bpp, stride);

                if (bytestream2_get_bytes_left(gb) < rects * (color * bpp + 2)) {
                    av_log(c->avctx, AV_LOG_ERROR, "Premature end of data!\n");
                    return AVERROR_INVALIDDATA;
                }
                for (k = 0; k < rects; k++) {
                    int rect_x, rect_y, rect_w, rect_h;
                    if (color)
                        fg = vmnc_get_pixel(gb, bpp, c->bigendian);
                    xy = bytestream2_get_byte(gb);
                    wh = bytestream2_get_byte(gb);

                    rect_x = xy >> 4;
                    rect_y = xy & 0xF;
                    rect_w = (wh >> 4) + 1;
                    rect_h = (wh & 0xF) + 1;

                    if (rect_x + rect_w > w - i || rect_y + rect_h > h - j) {
                        av_log(c->avctx, AV_LOG_ERROR, "Rectangle outside picture\n");
                        return AVERROR_INVALIDDATA;
                    }

                    paint_rect(dst2, rect_x, rect_y,
                               rect_w, rect_h, fg, bpp, stride);
                }
            }
        }
        dst += stride * 16;
    }
    return 0;
}

__attribute__((used)) static void reset_buffers(VmncContext *c)
{
    av_freep(&c->curbits);
    av_freep(&c->curmask);
    av_freep(&c->screendta);
    c->cur_w = c->cur_h = 0;
    c->cur_hx = c->cur_hy = 0;

}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx, void *data, int *got_frame,
                        AVPacket *avpkt)
{
    const uint8_t *buf = avpkt->data;
    int buf_size       = avpkt->size;
    VmncContext * const c = avctx->priv_data;
    GetByteContext *gb = &c->gb;
    uint8_t *outptr;
    int dx, dy, w, h, depth, enc, chunks, res, size_left, ret;

    if ((ret = ff_reget_buffer(avctx, c->pic)) < 0)
        return ret;

    bytestream2_init(gb, buf, buf_size);

    c->pic->key_frame = 0;
    c->pic->pict_type = AV_PICTURE_TYPE_P;

    // restore screen after cursor
    if (c->screendta) {
        int i;
        w = c->cur_w;
        if (c->width < c->cur_x + w)
            w = c->width - c->cur_x;
        h = c->cur_h;
        if (c->height < c->cur_y + h)
            h = c->height - c->cur_y;
        dx = c->cur_x;
        if (dx < 0) {
            w += dx;
            dx = 0;
        }
        dy = c->cur_y;
        if (dy < 0) {
            h += dy;
            dy = 0;
        }
        if ((w > 0) && (h > 0)) {
            outptr = c->pic->data[0] + dx * c->bpp2 + dy * c->pic->linesize[0];
            for (i = 0; i < h; i++) {
                memcpy(outptr, c->screendta + i * c->cur_w * c->bpp2,
                       w * c->bpp2);
                outptr += c->pic->linesize[0];
            }
        }
    }
    bytestream2_skip(gb, 2);
    chunks = bytestream2_get_be16(gb);
    while (chunks--) {
        if (bytestream2_get_bytes_left(gb) < 12) {
            av_log(avctx, AV_LOG_ERROR, "Premature end of data!\n");
            return -1;
        }
        dx  = bytestream2_get_be16(gb);
        dy  = bytestream2_get_be16(gb);
        w   = bytestream2_get_be16(gb);
        h   = bytestream2_get_be16(gb);
        enc = bytestream2_get_be32(gb);
        if ((dx + w > c->width) || (dy + h > c->height)) {
            av_log(avctx, AV_LOG_ERROR,
                    "Incorrect frame size: %ix%i+%ix%i of %ix%i\n",
                    w, h, dx, dy, c->width, c->height);
            return AVERROR_INVALIDDATA;
        }
        outptr = c->pic->data[0] + dx * c->bpp2 + dy * c->pic->linesize[0];
        size_left = bytestream2_get_bytes_left(gb);
        switch (enc) {
        case MAGIC_WMVd: // cursor
            if (w*(int64_t)h*c->bpp2 > INT_MAX/2 - 2) {
                av_log(avctx, AV_LOG_ERROR, "dimensions too large\n");
                return AVERROR_INVALIDDATA;
            }
            if (size_left < 2 + w * h * c->bpp2 * 2) {
                av_log(avctx, AV_LOG_ERROR,
                       "Premature end of data! (need %i got %i)\n",
                       2 + w * h * c->bpp2 * 2, size_left);
                return AVERROR_INVALIDDATA;
            }
            bytestream2_skip(gb, 2);
            c->cur_w  = w;
            c->cur_h  = h;
            c->cur_hx = dx;
            c->cur_hy = dy;
            if ((c->cur_hx > c->cur_w) || (c->cur_hy > c->cur_h)) {
                av_log(avctx, AV_LOG_ERROR,
                       "Cursor hot spot is not in image: "
                       "%ix%i of %ix%i cursor size\n",
                       c->cur_hx, c->cur_hy, c->cur_w, c->cur_h);
                c->cur_hx = c->cur_hy = 0;
            }
            if (c->cur_w * c->cur_h >= INT_MAX / c->bpp2) {
                reset_buffers(c);
                return AVERROR(EINVAL);
            } else {
                int screen_size = c->cur_w * c->cur_h * c->bpp2;
                if ((ret = av_reallocp(&c->curbits, screen_size)) < 0 ||
                    (ret = av_reallocp(&c->curmask, screen_size)) < 0 ||
                    (ret = av_reallocp(&c->screendta, screen_size)) < 0) {
                    reset_buffers(c);
                    return ret;
                }
            }
            load_cursor(c);
            break;
        case MAGIC_WMVe: // unknown
            bytestream2_skip(gb, 2);
            break;
        case MAGIC_WMVf: // update cursor position
            c->cur_x = dx - c->cur_hx;
            c->cur_y = dy - c->cur_hy;
            break;
        case MAGIC_WMVg: // unknown
            bytestream2_skip(gb, 10);
            break;
        case MAGIC_WMVh: // unknown
            bytestream2_skip(gb, 4);
            break;
        case MAGIC_WMVi: // ServerInitialization struct
            c->pic->key_frame = 1;
            c->pic->pict_type = AV_PICTURE_TYPE_I;
            depth = bytestream2_get_byte(gb);
            if (depth != c->bpp) {
                av_log(avctx, AV_LOG_INFO,
                       "Depth mismatch. Container %i bpp, "
                       "Frame data: %i bpp\n",
                       c->bpp, depth);
            }
            bytestream2_skip(gb, 1);
            c->bigendian = bytestream2_get_byte(gb);
            if (c->bigendian & (~1)) {
                av_log(avctx, AV_LOG_INFO,
                       "Invalid header: bigendian flag = %i\n", c->bigendian);
                return AVERROR_INVALIDDATA;
            }
            //skip the rest of pixel format data
            bytestream2_skip(gb, 13);
            break;
        case MAGIC_WMVj: // unknown
            bytestream2_skip(gb, 2);
            break;
        case 0x00000000: // raw rectangle data
            if (size_left < w * h * c->bpp2) {
                av_log(avctx, AV_LOG_ERROR,
                       "Premature end of data! (need %i got %i)\n",
                       w * h * c->bpp2, size_left);
                return AVERROR_INVALIDDATA;
            }
            paint_raw(outptr, w, h, gb, c->bpp2, c->bigendian,
                      c->pic->linesize[0]);
            break;
        case 0x00000005: // HexTile encoded rectangle
            res = decode_hextile(c, outptr, gb, w, h, c->pic->linesize[0]);
            if (res < 0)
                return res;
            break;
        default:
            av_log(avctx, AV_LOG_ERROR, "Unsupported block type 0x%08X\n", enc);
            chunks = 0; // leave chunks decoding loop
        }
    }
    if (c->screendta) {
        int i;
        // save screen data before painting cursor
        w = c->cur_w;
        if (c->width < c->cur_x + w)
            w = c->width - c->cur_x;
        h = c->cur_h;
        if (c->height < c->cur_y + h)
            h = c->height - c->cur_y;
        dx = c->cur_x;
        if (dx < 0) {
            w += dx;
            dx = 0;
        }
        dy = c->cur_y;
        if (dy < 0) {
            h += dy;
            dy = 0;
        }
        if ((w > 0) && (h > 0)) {
            outptr = c->pic->data[0] + dx * c->bpp2 + dy * c->pic->linesize[0];
            for (i = 0; i < h; i++) {
                memcpy(c->screendta + i * c->cur_w * c->bpp2, outptr,
                       w * c->bpp2);
                outptr += c->pic->linesize[0];
            }
            outptr = c->pic->data[0];
            put_cursor(outptr, c->pic->linesize[0], c, c->cur_x, c->cur_y);
        }
    }
    *got_frame = 1;
    if ((ret = av_frame_ref(data, c->pic)) < 0)
        return ret;

    /* always report that the buffer was completely consumed */
    return buf_size;
}

