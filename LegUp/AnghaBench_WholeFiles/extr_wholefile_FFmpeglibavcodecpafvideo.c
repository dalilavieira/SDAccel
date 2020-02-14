#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_9__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int ptrdiff_t ;
typedef  void* int8_t ;
struct TYPE_16__ {int** data; int key_frame; int palette_has_changed; int /*<<< orphan*/ * linesize; int /*<<< orphan*/  pict_type; } ;
struct TYPE_15__ {TYPE_1__* priv_data; } ;
struct TYPE_14__ {int size; int* data; } ;
struct TYPE_13__ {int** frame; int width; int frame_size; size_t current_frame; int video_size; int height; TYPE_9__* pic; int /*<<< orphan*/  gb; } ;
typedef  TYPE_1__ PAFVideoDecContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AVPALETTE_SIZE ; 
 int /*<<< orphan*/  AV_COPY128U (int*,int const*) ; 
 int /*<<< orphan*/  AV_COPY16U (int*,int const*) ; 
 int /*<<< orphan*/  AV_COPY32U (int*,int const*) ; 
 int /*<<< orphan*/  AV_COPY64U (int*,int const*) ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int /*<<< orphan*/  FFABS (void*) ; 
 int /*<<< orphan*/  av_assert0 (int /*<<< orphan*/ ) ; 
 int av_frame_ref (void*,TYPE_9__*) ; 
 int /*<<< orphan*/  av_image_copy_plane (int*,int /*<<< orphan*/ ,int*,int,int,int) ; 
 int /*<<< orphan*/  avpriv_request_sample (TYPE_3__*,char*) ; 
 int** block_sequences ; 
 int bytestream2_get_be16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_get_buffer (int /*<<< orphan*/ *,int*,int) ; 
 int /*<<< orphan*/  bytestream2_get_bufferu (int /*<<< orphan*/ *,int*,int) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 void* bytestream2_get_byteu (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int*,int) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bytestream2_skipu (int /*<<< orphan*/ *,int) ; 
 int bytestream2_tell (int /*<<< orphan*/ *) ; 
 int ff_reget_buffer (TYPE_3__*,TYPE_9__*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,void*,int) ; 

__attribute__((used)) static inline void copy_block2(uint8_t *dst, const uint8_t *src, ptrdiff_t dstStride, ptrdiff_t srcStride, int h)
{
    int i;
    for (i = 0; i < h; i++) {
        AV_COPY16U(dst, src);
        dst += dstStride;
        src += srcStride;
    }
}

__attribute__((used)) static inline void copy_block4(uint8_t *dst, const uint8_t *src, ptrdiff_t dstStride, ptrdiff_t srcStride, int h)
{
    int i;
    for (i = 0; i < h; i++) {
        AV_COPY32U(dst, src);
        dst += dstStride;
        src += srcStride;
    }
}

__attribute__((used)) static inline void copy_block8(uint8_t *dst, const uint8_t *src, ptrdiff_t dstStride, ptrdiff_t srcStride, int h)
{
    int i;
    for (i = 0; i < h; i++) {
        AV_COPY64U(dst, src);
        dst += dstStride;
        src += srcStride;
    }
}

__attribute__((used)) static inline void copy_block9(uint8_t *dst, const uint8_t *src, ptrdiff_t dstStride, ptrdiff_t srcStride, int h)
{
    int i;
    for (i = 0; i < h; i++) {
        AV_COPY64U(dst, src);
        dst[8] = src[8];
        dst   += dstStride;
        src   += srcStride;
    }
}

__attribute__((used)) static inline void copy_block16(uint8_t *dst, const uint8_t *src, ptrdiff_t dstStride, ptrdiff_t srcStride, int h)
{
    int i;
    for (i = 0; i < h; i++) {
        AV_COPY128U(dst, src);
        dst += dstStride;
        src += srcStride;
    }
}

__attribute__((used)) static inline void copy_block17(uint8_t *dst, const uint8_t *src, ptrdiff_t dstStride, ptrdiff_t srcStride, int h)
{
    int i;
    for (i = 0; i < h; i++) {
        AV_COPY128U(dst, src);
        dst[16] = src[16];
        dst    += dstStride;
        src    += srcStride;
    }
}

__attribute__((used)) static void read4x4block(PAFVideoDecContext *c, uint8_t *dst, int width)
{
    int i;

    for (i = 0; i < 4; i++) {
        bytestream2_get_buffer(&c->gb, dst, 4);
        dst += width;
    }
}

__attribute__((used)) static void copy_color_mask(uint8_t *dst, int width, uint8_t mask, uint8_t color)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (mask & (1 << 7 - i))
            dst[i] = color;
        if (mask & (1 << 3 - i))
            dst[width + i] = color;
    }
}

__attribute__((used)) static void copy_src_mask(uint8_t *dst, int width, uint8_t mask, const uint8_t *src)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (mask & (1 << 7 - i))
            dst[i] = src[i];
        if (mask & (1 << 3 - i))
            dst[width + i] = src[width + i];
    }
}

__attribute__((used)) static void set_src_position(PAFVideoDecContext *c,
                             const uint8_t **p,
                             const uint8_t **pend)
{
    int val  = bytestream2_get_be16(&c->gb);
    int page = val >> 14;
    int x    = (val & 0x7F);
    int y    = ((val >> 7) & 0x7F);

    *p    = c->frame[page] + x * 2 + y * 2 * c->width;
    *pend = c->frame[page] + c->frame_size;
}

__attribute__((used)) static int decode_0(PAFVideoDecContext *c, uint8_t *pkt, uint8_t code)
{
    uint32_t opcode_size, offset;
    uint8_t *dst, *dend, mask = 0, color = 0;
    const uint8_t *src, *send, *opcodes;
    int i, j, op = 0;

    i = bytestream2_get_byte(&c->gb);
    if (i) {
        if (code & 0x10) {
            int align;

            align = bytestream2_tell(&c->gb) & 3;
            if (align)
                bytestream2_skip(&c->gb, 4 - align);
        }
        do {
            int page, val, x, y;
            val    = bytestream2_get_be16(&c->gb);
            page   = val >> 14;
            x      = (val & 0x7F) * 2;
            y      = ((val >> 7) & 0x7F) * 2;
            dst    = c->frame[page] + x + y * c->width;
            dend   = c->frame[page] + c->frame_size;
            offset = (x & 0x7F) * 2;
            j      = bytestream2_get_le16(&c->gb) + offset;
            if (bytestream2_get_bytes_left(&c->gb) < (j - offset) * 16)
                return AVERROR_INVALIDDATA;
            do {
                offset++;
                if (dst + 3 * c->width + 4 > dend)
                    return AVERROR_INVALIDDATA;
                read4x4block(c, dst, c->width);
                if ((offset & 0x3F) == 0)
                    dst += c->width * 3;
                dst += 4;
            } while (offset < j);
        } while (--i);
    }

    dst  = c->frame[c->current_frame];
    dend = c->frame[c->current_frame] + c->frame_size;
    do {
        set_src_position(c, &src, &send);
        if ((src + 3 * c->width + 4 > send) ||
            (dst + 3 * c->width + 4 > dend) ||
            bytestream2_get_bytes_left(&c->gb) < 4)
            return AVERROR_INVALIDDATA;
        copy_block4(dst, src, c->width, c->width, 4);
        i++;
        if ((i & 0x3F) == 0)
            dst += c->width * 3;
        dst += 4;
    } while (i < c->video_size / 16);

    opcode_size = bytestream2_get_le16(&c->gb);
    bytestream2_skip(&c->gb, 2);

    if (bytestream2_get_bytes_left(&c->gb) < opcode_size)
        return AVERROR_INVALIDDATA;

    opcodes = pkt + bytestream2_tell(&c->gb);
    bytestream2_skipu(&c->gb, opcode_size);

    dst = c->frame[c->current_frame];

    for (i = 0; i < c->height; i += 4, dst += c->width * 3)
        for (j = 0; j < c->width; j += 4, dst += 4) {
            int opcode, k = 0;
            if (op > opcode_size)
                return AVERROR_INVALIDDATA;
            if (j & 4) {
                opcode = opcodes[op] & 15;
                op++;
            } else {
                opcode = opcodes[op] >> 4;
            }

            while (block_sequences[opcode][k]) {
                offset = c->width * 2;
                code   = block_sequences[opcode][k++];

                switch (code) {
                case 2:
                    offset = 0;
                case 3:
                    color = bytestream2_get_byte(&c->gb);
                case 4:
                    mask = bytestream2_get_byte(&c->gb);
                    copy_color_mask(dst + offset, c->width, mask, color);
                    break;
                case 5:
                    offset = 0;
                case 6:
                    set_src_position(c, &src, &send);
                case 7:
                    if (src + offset + c->width + 4 > send)
                        return AVERROR_INVALIDDATA;
                    mask = bytestream2_get_byte(&c->gb);
                    copy_src_mask(dst + offset, c->width, mask, src + offset);
                    break;
                }
            }
        }

    return 0;
}

__attribute__((used)) static int paf_video_decode(AVCodecContext *avctx, void *data,
                            int *got_frame, AVPacket *pkt)
{
    PAFVideoDecContext *c = avctx->priv_data;
    uint8_t code, *dst, *end;
    int i, frame, ret;

    if (pkt->size < 2)
        return AVERROR_INVALIDDATA;

    bytestream2_init(&c->gb, pkt->data, pkt->size);

    code = bytestream2_get_byte(&c->gb);
    if ((code & 0xF) > 4 || (code & 0xF) == 3) {
        avpriv_request_sample(avctx, "unknown/invalid code");
        return AVERROR_INVALIDDATA;
    }

    if ((ret = ff_reget_buffer(avctx, c->pic)) < 0)
        return ret;

    if (code & 0x20) {  // frame is keyframe
        for (i = 0; i < 4; i++)
            memset(c->frame[i], 0, c->frame_size);

        memset(c->pic->data[1], 0, AVPALETTE_SIZE);
        c->current_frame  = 0;
        c->pic->key_frame = 1;
        c->pic->pict_type = AV_PICTURE_TYPE_I;
    } else {
        c->pic->key_frame = 0;
        c->pic->pict_type = AV_PICTURE_TYPE_P;
    }

    if (code & 0x40) {  // palette update
        uint32_t *out = (uint32_t *)c->pic->data[1];
        int index, count;

        index = bytestream2_get_byte(&c->gb);
        count = bytestream2_get_byte(&c->gb) + 1;

        if (index + count > 256)
            return AVERROR_INVALIDDATA;
        if (bytestream2_get_bytes_left(&c->gb) < 3 * count)
            return AVERROR_INVALIDDATA;

        out += index;
        for (i = 0; i < count; i++) {
            unsigned r, g, b;

            r = bytestream2_get_byteu(&c->gb);
            r = r << 2 | r >> 4;
            g = bytestream2_get_byteu(&c->gb);
            g = g << 2 | g >> 4;
            b = bytestream2_get_byteu(&c->gb);
            b = b << 2 | b >> 4;
            *out++ = (0xFFU << 24) | (r << 16) | (g << 8) | b;
        }
        c->pic->palette_has_changed = 1;
    }

    switch (code & 0x0F) {
    case 0:
        /* Block-based motion compensation using 4x4 blocks with either
         * horizontal or vertical vectors; might incorporate VQ as well. */
        if ((ret = decode_0(c, pkt->data, code)) < 0)
            return ret;
        break;
    case 1:
        /* Uncompressed data. This mode specifies that (width * height) bytes
         * should be copied directly from the encoded buffer into the output. */
        dst = c->frame[c->current_frame];
        // possibly chunk length data
        bytestream2_skip(&c->gb, 2);
        if (bytestream2_get_bytes_left(&c->gb) < c->video_size)
            return AVERROR_INVALIDDATA;
        bytestream2_get_bufferu(&c->gb, dst, c->video_size);
        break;
    case 2:
        /* Copy reference frame: Consume the next byte in the stream as the
         * reference frame (which should be 0, 1, 2, or 3, and should not be
         * the same as the current frame number). */
        frame = bytestream2_get_byte(&c->gb);
        if (frame > 3)
            return AVERROR_INVALIDDATA;
        if (frame != c->current_frame)
            memcpy(c->frame[c->current_frame], c->frame[frame], c->frame_size);
        break;
    case 4:
        /* Run length encoding.*/
        dst = c->frame[c->current_frame];
        end = dst + c->video_size;

        bytestream2_skip(&c->gb, 2);

        while (dst < end) {
            int8_t code;
            int count;

            if (bytestream2_get_bytes_left(&c->gb) < 2)
                return AVERROR_INVALIDDATA;

            code  = bytestream2_get_byteu(&c->gb);
            count = FFABS(code) + 1;

            if (dst + count > end)
                return AVERROR_INVALIDDATA;
            if (code < 0)
                memset(dst, bytestream2_get_byteu(&c->gb), count);
            else
                bytestream2_get_buffer(&c->gb, dst, count);
            dst += count;
        }
        break;
    default:
        av_assert0(0);
    }

    av_image_copy_plane(c->pic->data[0], c->pic->linesize[0],
                        c->frame[c->current_frame], c->width,
                        c->width, c->height);

    c->current_frame = (c->current_frame + 1) & 3;
    if ((ret = av_frame_ref(data, c->pic)) < 0)
        return ret;

    *got_frame = 1;

    return pkt->size;
}

