#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_76__   TYPE_6__ ;
typedef  struct TYPE_75__   TYPE_5__ ;
typedef  struct TYPE_74__   TYPE_56__ ;
typedef  struct TYPE_73__   TYPE_4__ ;
typedef  struct TYPE_72__   TYPE_3__ ;
typedef  struct TYPE_71__   TYPE_2__ ;
typedef  struct TYPE_70__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
struct TYPE_70__ {int frame_size; unsigned int* buffer1; int buffer1_size; unsigned int* buffer2; int size; unsigned int* buf; int buffer2_size; int palettes_count; unsigned int* palettes; int cur_palette; TYPE_56__* last_frame; TYPE_6__* avctx; } ;
typedef  TYPE_1__ XanContext ;
typedef  int VLC_TYPE ;
struct TYPE_76__ {int width; int height; TYPE_1__* priv_data; } ;
struct TYPE_75__ {unsigned int** data; int* linesize; } ;
struct TYPE_74__ {unsigned int** data; } ;
struct TYPE_73__ {unsigned int* data; int size; } ;
struct TYPE_72__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
struct TYPE_71__ {unsigned int* buffer; } ;
typedef  TYPE_2__ GetByteContext ;
typedef  TYPE_3__ GetBitContext ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVFrame ;
typedef  TYPE_6__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int AVPALETTE_COUNT ; 
 int AVPALETTE_SIZE ; 
 int /*<<< orphan*/  AV_GET_BUFFER_FLAG_REF ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int AV_RL16 (unsigned int*) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FFABS (int) ; 
 int FFMAX (int,int) ; 
 int FFMIN (int,int) ; 
 int FFMIN3 (int,int,int) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 int MIN_CACHE_BITS ; 
 int NEG_USR32 (int,int) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int PALETTES_MAX ; 
 int PALETTE_COUNT ; 
 int PALETTE_SIZE ; 
#define  PALT_TAG 130 
#define  SHOT_TAG 129 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_3__*) ; 
#define  VGA__TAG 128 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int av_frame_ref (TYPE_56__*,TYPE_5__*) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_56__*) ; 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  av_memcpy_backptr (unsigned int*,int,int) ; 
 unsigned int* av_realloc_array (unsigned int*,int,int) ; 
 int /*<<< orphan*/  avpriv_request_sample (TYPE_6__*,char*) ; 
 unsigned int bytestream2_get_be16 (TYPE_2__*) ; 
 int bytestream2_get_be24 (TYPE_2__*) ; 
 int bytestream2_get_be32 (TYPE_2__*) ; 
 int /*<<< orphan*/  bytestream2_get_buffer (TYPE_2__*,unsigned int*,int) ; 
 unsigned int bytestream2_get_byte (TYPE_2__*) ; 
 int bytestream2_get_bytes_left (TYPE_2__*) ; 
 size_t bytestream2_get_byteu (TYPE_2__*) ; 
 void* bytestream2_get_le32 (TYPE_2__*) ; 
 int /*<<< orphan*/  bytestream2_init (TYPE_2__*,unsigned int const*,int) ; 
 int bytestream2_peek_byte (TYPE_2__*) ; 
 int /*<<< orphan*/  bytestream2_skip (TYPE_2__*,int) ; 
 int ff_get_buffer (TYPE_6__*,TYPE_5__*,int /*<<< orphan*/ ) ; 
 int* gamma_lookup ; 
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned int const*,int) ; 
 int /*<<< orphan*/  re ; 
 int sign_extend (unsigned int,int) ; 
 int zero_extend (int,int) ; 

__attribute__((used)) static inline int8_t ff_u8_to_s8(uint8_t a)
{
    union {
        uint8_t u8;
        int8_t  s8;
    } b;
    b.u8 = a;
    return b.s8;
}

__attribute__((used)) static inline int get_bits_count(const GetBitContext *s)
{
#if CACHED_BITSTREAM_READER
    return s->index - s->bits_left;
#else
    return s->index;
#endif
}

__attribute__((used)) static inline void skip_bits_long(GetBitContext *s, int n)
{
#if CACHED_BITSTREAM_READER
    skip_bits(s, n);
#else
#if UNCHECKED_BITSTREAM_READER
    s->index += n;
#else
    s->index += av_clip(n, -s->index, s->size_in_bits_plus8 - s->index);
#endif
#endif
}

__attribute__((used)) static inline int get_xbits(GetBitContext *s, int n)
{
#if CACHED_BITSTREAM_READER
    int32_t cache = show_bits(s, 32);
    int sign = ~cache >> 31;
    skip_remaining(s, n);

    return ((((uint32_t)(sign ^ cache)) >> (32 - n)) ^ sign) - sign;
#else
    register int sign;
    register int32_t cache;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    cache = GET_CACHE(re, s);
    sign  = ~cache >> 31;
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    return (NEG_USR32(sign ^ cache, n) ^ sign) - sign;
#endif
}

__attribute__((used)) static inline int get_xbits_le(GetBitContext *s, int n)
{
    register int sign;
    register int32_t cache;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE_LE(re, s);
    cache = GET_CACHE(re, s);
    sign  = sign_extend(~cache, n) >> 31;
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    return (zero_extend(sign ^ cache, n) ^ sign) - sign;
}

__attribute__((used)) static inline int get_sbits(GetBitContext *s, int n)
{
    register int tmp;
#if CACHED_BITSTREAM_READER
    av_assert2(n>0 && n<=25);
    tmp = sign_extend(get_bits(s, n), n);
#else
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_SBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
#endif
    return tmp;
}

__attribute__((used)) static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
#if CACHED_BITSTREAM_READER

    av_assert2(n>0 && n<=32);
    if (n > s->bits_left) {
#ifdef BITSTREAM_READER_LE
        refill_32(s, 1);
#else
        refill_32(s, 0);
#endif
        if (s->bits_left < 32)
            s->bits_left = n;
    }

#ifdef BITSTREAM_READER_LE
    tmp = get_val(s, n, 1);
#else
    tmp = get_val(s, n, 0);
#endif
#else
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
#endif
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}

__attribute__((used)) static inline unsigned int get_bits_le(GetBitContext *s, int n)
{
#if CACHED_BITSTREAM_READER
    av_assert2(n>0 && n<=32);
    if (n > s->bits_left) {
        refill_32(s, 1);
        if (s->bits_left < 32)
            s->bits_left = n;
    }

    return get_val(s, n, 1);
#else
    register int tmp;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE_LE(re, s);
    tmp = SHOW_UBITS_LE(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    return tmp;
#endif
}

__attribute__((used)) static inline unsigned int show_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
#if CACHED_BITSTREAM_READER
    if (n > s->bits_left)
#ifdef BITSTREAM_READER_LE
        refill_32(s, 1);
#else
        refill_32(s, 0);
#endif

    tmp = show_val(s, n);
#else
    OPEN_READER_NOSIZE(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
#endif
    return tmp;
}

__attribute__((used)) static inline void skip_bits(GetBitContext *s, int n)
{
#if CACHED_BITSTREAM_READER
    if (n < s->bits_left)
        skip_remaining(s, n);
    else {
        n -= s->bits_left;
        s->cache = 0;
        s->bits_left = 0;

        if (n >= 64) {
            unsigned skip = (n / 8) * 8;

            n -= skip;
            s->index += skip;
        }
#ifdef BITSTREAM_READER_LE
        refill_64(s, 1);
#else
        refill_64(s, 0);
#endif
        if (n)
            skip_remaining(s, n);
    }
#else
    OPEN_READER(re, s);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
#endif
}

__attribute__((used)) static inline unsigned int get_bits1(GetBitContext *s)
{
#if CACHED_BITSTREAM_READER
    if (!s->bits_left)
#ifdef BITSTREAM_READER_LE
        refill_64(s, 1);
#else
        refill_64(s, 0);
#endif

#ifdef BITSTREAM_READER_LE
    return get_val(s, 1, 1);
#else
    return get_val(s, 1, 0);
#endif
#else
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index >> 3];
#ifdef BITSTREAM_READER_LE
    result >>= index & 7;
    result  &= 1;
#else
    result <<= index & 7;
    result >>= 8 - 1;
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
#endif
        index++;
    s->index = index;

    return result;
#endif
}

__attribute__((used)) static inline unsigned int show_bits1(GetBitContext *s)
{
    return show_bits(s, 1);
}

__attribute__((used)) static inline void skip_bits1(GetBitContext *s)
{
    skip_bits(s, 1);
}

__attribute__((used)) static inline unsigned int get_bits_long(GetBitContext *s, int n)
{
    av_assert2(n>=0 && n<=32);
    if (!n) {
        return 0;
#if CACHED_BITSTREAM_READER
    }
    return get_bits(s, n);
#else
    } else if (n <= MIN_CACHE_BITS) {
        return get_bits(s, n);
    } else {
#ifdef BITSTREAM_READER_LE
        unsigned ret = get_bits(s, 16);
        return ret | (get_bits(s, n - 16) << 16);
#else
        unsigned ret = get_bits(s, 16) << (n - 16);
        return ret | get_bits(s, n - 16);
#endif
    }
#endif
}

__attribute__((used)) static inline uint64_t get_bits64(GetBitContext *s, int n)
{
    if (n <= 32) {
        return get_bits_long(s, n);
    } else {
#ifdef BITSTREAM_READER_LE
        uint64_t ret = get_bits_long(s, 32);
        return ret | (uint64_t) get_bits_long(s, n - 32) << 32;
#else
        uint64_t ret = (uint64_t) get_bits_long(s, n - 32) << 32;
        return ret | get_bits_long(s, 32);
#endif
    }
}

__attribute__((used)) static inline int get_sbits_long(GetBitContext *s, int n)
{
    // sign_extend(x, 0) is undefined
    if (!n)
        return 0;

    return sign_extend(get_bits_long(s, n), n);
}

__attribute__((used)) static inline unsigned int show_bits_long(GetBitContext *s, int n)
{
    if (n <= MIN_CACHE_BITS) {
        return show_bits(s, n);
    } else {
        GetBitContext gb = *s;
        return get_bits_long(&gb, n);
    }
}

__attribute__((used)) static inline int check_marker(void *logctx, GetBitContext *s, const char *msg)
{
    int bit = get_bits1(s);
    if (!bit)
        av_log(logctx, AV_LOG_INFO, "Marker bit missing at %d of %d %s\n",
               get_bits_count(s) - 1, s->size_in_bits, msg);

    return bit;
}

__attribute__((used)) static inline int init_get_bits_xe(GetBitContext *s, const uint8_t *buffer,
                                   int bit_size, int is_le)
{
    int buffer_size;
    int ret = 0;

    if (bit_size >= INT_MAX - FFMAX(7, AV_INPUT_BUFFER_PADDING_SIZE*8) || bit_size < 0 || !buffer) {
        bit_size    = 0;
        buffer      = NULL;
        ret         = AVERROR_INVALIDDATA;
    }

    buffer_size = (bit_size + 7) >> 3;

    s->buffer             = buffer;
    s->size_in_bits       = bit_size;
    s->size_in_bits_plus8 = bit_size + 8;
    s->buffer_end         = buffer + buffer_size;
    s->index              = 0;

#if CACHED_BITSTREAM_READER
    s->cache              = 0;
    s->bits_left          = 0;
    refill_64(s, is_le);
#endif

    return ret;
}

__attribute__((used)) static inline int init_get_bits(GetBitContext *s, const uint8_t *buffer,
                                int bit_size)
{
#ifdef BITSTREAM_READER_LE
    return init_get_bits_xe(s, buffer, bit_size, 1);
#else
    return init_get_bits_xe(s, buffer, bit_size, 0);
#endif
}

__attribute__((used)) static inline int init_get_bits8(GetBitContext *s, const uint8_t *buffer,
                                 int byte_size)
{
    if (byte_size > INT_MAX / 8 || byte_size < 0)
        byte_size = -1;
    return init_get_bits(s, buffer, byte_size * 8);
}

__attribute__((used)) static inline int init_get_bits8_le(GetBitContext *s, const uint8_t *buffer,
                                    int byte_size)
{
    if (byte_size > INT_MAX / 8 || byte_size < 0)
        byte_size = -1;
    return init_get_bits_xe(s, buffer, byte_size * 8, 1);
}

__attribute__((used)) static inline const uint8_t *align_get_bits(GetBitContext *s)
{
    int n = -get_bits_count(s) & 7;
    if (n)
        skip_bits(s, n);
    return s->buffer + (s->index >> 3);
}

__attribute__((used)) static inline int set_idx(GetBitContext *s, int code, int *n, int *nb_bits,
                          VLC_TYPE (*table)[2])
{
    unsigned idx;

    *nb_bits = -*n;
    idx = show_bits(s, *nb_bits) + code;
    *n = table[idx][1];

    return table[idx][0];
}

__attribute__((used)) static inline int decode012(GetBitContext *gb)
{
    int n;
    n = get_bits1(gb);
    if (n == 0)
        return 0;
    else
        return get_bits1(gb) + 1;
}

__attribute__((used)) static inline int decode210(GetBitContext *gb)
{
    if (get_bits1(gb))
        return 0;
    else
        return 2 - get_bits1(gb);
}

__attribute__((used)) static inline int get_bits_left(GetBitContext *gb)
{
    return gb->size_in_bits - get_bits_count(gb);
}

__attribute__((used)) static inline int skip_1stop_8data_bits(GetBitContext *gb)
{
    if (get_bits_left(gb) <= 0)
        return AVERROR_INVALIDDATA;

    while (get_bits1(gb)) {
        skip_bits(gb, 8);
        if (get_bits_left(gb) <= 0)
            return AVERROR_INVALIDDATA;
    }

    return 0;
}

__attribute__((used)) static int xan_huffman_decode(uint8_t *dest, int dest_len,
                              const uint8_t *src, int src_len)
{
    uint8_t byte = *src++;
    uint8_t ival = byte + 0x16;
    const uint8_t * ptr = src + byte*2;
    int ptr_len = src_len - 1 - byte*2;
    uint8_t val = ival;
    uint8_t *dest_end = dest + dest_len;
    uint8_t *dest_start = dest;
    int ret;
    GetBitContext gb;

    if ((ret = init_get_bits8(&gb, ptr, ptr_len)) < 0)
        return ret;

    while (val != 0x16) {
        unsigned idx;
        if (get_bits_left(&gb) < 1)
            return AVERROR_INVALIDDATA;
        idx = val - 0x17 + get_bits1(&gb) * byte;
        if (idx >= 2 * byte)
            return AVERROR_INVALIDDATA;
        val = src[idx];

        if (val < 0x16) {
            if (dest >= dest_end)
                return dest_len;
            *dest++ = val;
            val = ival;
        }
    }

    return dest - dest_start;
}

__attribute__((used)) static void xan_unpack(uint8_t *dest, int dest_len,
                       const uint8_t *src, int src_len)
{
    uint8_t opcode;
    int size;
    uint8_t *dest_org = dest;
    uint8_t *dest_end = dest + dest_len;
    GetByteContext ctx;

    bytestream2_init(&ctx, src, src_len);
    while (dest < dest_end && bytestream2_get_bytes_left(&ctx)) {
        opcode = bytestream2_get_byte(&ctx);

        if (opcode < 0xe0) {
            int size2, back;
            if ((opcode & 0x80) == 0) {
                size = opcode & 3;

                back  = ((opcode & 0x60) << 3) + bytestream2_get_byte(&ctx) + 1;
                size2 = ((opcode & 0x1c) >> 2) + 3;
            } else if ((opcode & 0x40) == 0) {
                size = bytestream2_peek_byte(&ctx) >> 6;

                back  = (bytestream2_get_be16(&ctx) & 0x3fff) + 1;
                size2 = (opcode & 0x3f) + 4;
            } else {
                size = opcode & 3;

                back  = ((opcode & 0x10) << 12) + bytestream2_get_be16(&ctx) + 1;
                size2 = ((opcode & 0x0c) <<  6) + bytestream2_get_byte(&ctx) + 5;
            }

            if (dest_end - dest < size + size2 ||
                dest + size - dest_org < back ||
                bytestream2_get_bytes_left(&ctx) < size)
                return;
            bytestream2_get_buffer(&ctx, dest, size);
            dest += size;
            av_memcpy_backptr(dest, back, size2);
            dest += size2;
        } else {
            int finish = opcode >= 0xfc;
            size = finish ? opcode & 3 : ((opcode & 0x1f) << 2) + 4;

            if (dest_end - dest < size || bytestream2_get_bytes_left(&ctx) < size)
                return;
            bytestream2_get_buffer(&ctx, dest, size);
            dest += size;
            if (finish)
                return;
        }
    }
}

__attribute__((used)) static inline void xan_wc3_output_pixel_run(XanContext *s, AVFrame *frame,
    const uint8_t *pixel_buffer, int x, int y, int pixel_count)
{
    int stride;
    int line_inc;
    int index;
    int current_x;
    int width = s->avctx->width;
    uint8_t *palette_plane;

    palette_plane = frame->data[0];
    stride = frame->linesize[0];
    line_inc = stride - width;
    index = y * stride + x;
    current_x = x;
    while (pixel_count && index < s->frame_size) {
        int count = FFMIN(pixel_count, width - current_x);
        memcpy(palette_plane + index, pixel_buffer, count);
        pixel_count  -= count;
        index        += count;
        pixel_buffer += count;
        current_x    += count;

        if (current_x >= width) {
            index += line_inc;
            current_x = 0;
        }
    }
}

__attribute__((used)) static inline void xan_wc3_copy_pixel_run(XanContext *s, AVFrame *frame,
                                          int x, int y,
                                          int pixel_count, int motion_x,
                                          int motion_y)
{
    int stride;
    int line_inc;
    int curframe_index, prevframe_index;
    int curframe_x, prevframe_x;
    int width = s->avctx->width;
    uint8_t *palette_plane, *prev_palette_plane;

    if (y + motion_y < 0 || y + motion_y >= s->avctx->height ||
        x + motion_x < 0 || x + motion_x >= s->avctx->width)
        return;

    palette_plane = frame->data[0];
    prev_palette_plane = s->last_frame->data[0];
    if (!prev_palette_plane)
        prev_palette_plane = palette_plane;
    stride = frame->linesize[0];
    line_inc = stride - width;
    curframe_index = y * stride + x;
    curframe_x = x;
    prevframe_index = (y + motion_y) * stride + x + motion_x;
    prevframe_x = x + motion_x;

    if (prev_palette_plane == palette_plane && FFABS(motion_x + width*motion_y) < pixel_count) {
         avpriv_request_sample(s->avctx, "Overlapping copy");
         return ;
    }

    while (pixel_count &&
           curframe_index  < s->frame_size &&
           prevframe_index < s->frame_size) {
        int count = FFMIN3(pixel_count, width - curframe_x,
                           width - prevframe_x);

        memcpy(palette_plane + curframe_index,
               prev_palette_plane + prevframe_index, count);
        pixel_count     -= count;
        curframe_index  += count;
        prevframe_index += count;
        curframe_x      += count;
        prevframe_x     += count;

        if (curframe_x >= width) {
            curframe_index += line_inc;
            curframe_x = 0;
        }

        if (prevframe_x >= width) {
            prevframe_index += line_inc;
            prevframe_x = 0;
        }
    }
}

__attribute__((used)) static int xan_wc3_decode_frame(XanContext *s, AVFrame *frame)
{

    int width  = s->avctx->width;
    int height = s->avctx->height;
    int total_pixels = width * height;
    uint8_t opcode;
    uint8_t flag = 0;
    int size = 0;
    int motion_x, motion_y;
    int x, y, ret;

    uint8_t *opcode_buffer = s->buffer1;
    uint8_t *opcode_buffer_end = s->buffer1 + s->buffer1_size;
    int opcode_buffer_size = s->buffer1_size;
    const uint8_t *imagedata_buffer = s->buffer2;

    /* pointers to segments inside the compressed chunk */
    const uint8_t *huffman_segment;
    GetByteContext       size_segment;
    GetByteContext       vector_segment;
    const uint8_t *imagedata_segment;
    int huffman_offset, size_offset, vector_offset, imagedata_offset,
        imagedata_size;

    if (s->size < 8)
        return AVERROR_INVALIDDATA;

    huffman_offset    = AV_RL16(&s->buf[0]);
    size_offset       = AV_RL16(&s->buf[2]);
    vector_offset     = AV_RL16(&s->buf[4]);
    imagedata_offset  = AV_RL16(&s->buf[6]);

    if (huffman_offset   >= s->size ||
        size_offset      >= s->size ||
        vector_offset    >= s->size ||
        imagedata_offset >= s->size)
        return AVERROR_INVALIDDATA;

    huffman_segment   = s->buf + huffman_offset;
    bytestream2_init(&size_segment,   s->buf + size_offset,   s->size - size_offset);
    bytestream2_init(&vector_segment, s->buf + vector_offset, s->size - vector_offset);
    imagedata_segment = s->buf + imagedata_offset;

    if ((ret = xan_huffman_decode(opcode_buffer, opcode_buffer_size,
                                  huffman_segment, s->size - huffman_offset)) < 0)
        return AVERROR_INVALIDDATA;
    opcode_buffer_end = opcode_buffer + ret;

    if (imagedata_segment[0] == 2) {
        xan_unpack(s->buffer2, s->buffer2_size,
                   &imagedata_segment[1], s->size - imagedata_offset - 1);
        imagedata_size = s->buffer2_size;
    } else {
        imagedata_size = s->size - imagedata_offset - 1;
        imagedata_buffer = &imagedata_segment[1];
    }

    /* use the decoded data segments to build the frame */
    x = y = 0;
    while (total_pixels && opcode_buffer < opcode_buffer_end) {

        opcode = *opcode_buffer++;
        size = 0;

        switch (opcode) {

        case 0:
            flag ^= 1;
            continue;

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            size = opcode;
            break;

        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            size += (opcode - 10);
            break;

        case 9:
        case 19:
            if (bytestream2_get_bytes_left(&size_segment) < 1) {
                av_log(s->avctx, AV_LOG_ERROR, "size_segment overread\n");
                return AVERROR_INVALIDDATA;
            }
            size = bytestream2_get_byte(&size_segment);
            break;

        case 10:
        case 20:
            if (bytestream2_get_bytes_left(&size_segment) < 2) {
                av_log(s->avctx, AV_LOG_ERROR, "size_segment overread\n");
                return AVERROR_INVALIDDATA;
            }
            size = bytestream2_get_be16(&size_segment);
            break;

        case 11:
        case 21:
            if (bytestream2_get_bytes_left(&size_segment) < 3) {
                av_log(s->avctx, AV_LOG_ERROR, "size_segment overread\n");
                return AVERROR_INVALIDDATA;
            }
            size = bytestream2_get_be24(&size_segment);
            break;
        }

        if (size > total_pixels)
            break;

        if (opcode < 12) {
            flag ^= 1;
            if (flag) {
                /* run of (size) pixels is unchanged from last frame */
                xan_wc3_copy_pixel_run(s, frame, x, y, size, 0, 0);
            } else {
                /* output a run of pixels from imagedata_buffer */
                if (imagedata_size < size)
                    break;
                xan_wc3_output_pixel_run(s, frame, imagedata_buffer, x, y, size);
                imagedata_buffer += size;
                imagedata_size -= size;
            }
        } else {
            uint8_t vector;
            if (bytestream2_get_bytes_left(&vector_segment) <= 0) {
                av_log(s->avctx, AV_LOG_ERROR, "vector_segment overread\n");
                return AVERROR_INVALIDDATA;
            }
            /* run-based motion compensation from last frame */
            vector = bytestream2_get_byte(&vector_segment);
            motion_x = sign_extend(vector >> 4,  4);
            motion_y = sign_extend(vector & 0xF, 4);

            /* copy a run of pixels from the previous frame */
            xan_wc3_copy_pixel_run(s, frame, x, y, size, motion_x, motion_y);

            flag = 0;
        }

        /* coordinate accounting */
        total_pixels -= size;
        y += (x + size) / width;
        x  = (x + size) % width;
    }
    return 0;
}

__attribute__((used)) static int xan_decode_frame(AVCodecContext *avctx,
                            void *data, int *got_frame,
                            AVPacket *avpkt)
{
    AVFrame *frame = data;
    const uint8_t *buf = avpkt->data;
    int ret, buf_size = avpkt->size;
    XanContext *s = avctx->priv_data;
    GetByteContext ctx;
    int tag = 0;

    bytestream2_init(&ctx, buf, buf_size);
    while (bytestream2_get_bytes_left(&ctx) > 8 && tag != VGA__TAG) {
        unsigned *tmpptr;
        uint32_t new_pal;
        int size;
        int i;
        tag  = bytestream2_get_le32(&ctx);
        size = bytestream2_get_be32(&ctx);
        if (size < 0) {
            av_log(avctx, AV_LOG_ERROR, "Invalid tag size %d\n", size);
            return AVERROR_INVALIDDATA;
        }
        size = FFMIN(size, bytestream2_get_bytes_left(&ctx));
        switch (tag) {
        case PALT_TAG:
            if (size < PALETTE_SIZE)
                return AVERROR_INVALIDDATA;
            if (s->palettes_count >= PALETTES_MAX)
                return AVERROR_INVALIDDATA;
            tmpptr = av_realloc_array(s->palettes,
                                      s->palettes_count + 1, AVPALETTE_SIZE);
            if (!tmpptr)
                return AVERROR(ENOMEM);
            s->palettes = tmpptr;
            tmpptr += s->palettes_count * AVPALETTE_COUNT;
            for (i = 0; i < PALETTE_COUNT; i++) {
#if RUNTIME_GAMMA
                int r = gamma_corr(bytestream2_get_byteu(&ctx));
                int g = gamma_corr(bytestream2_get_byteu(&ctx));
                int b = gamma_corr(bytestream2_get_byteu(&ctx));
#else
                int r = gamma_lookup[bytestream2_get_byteu(&ctx)];
                int g = gamma_lookup[bytestream2_get_byteu(&ctx)];
                int b = gamma_lookup[bytestream2_get_byteu(&ctx)];
#endif
                *tmpptr++ = (0xFFU << 24) | (r << 16) | (g << 8) | b;
            }
            s->palettes_count++;
            break;
        case SHOT_TAG:
            if (size < 4)
                return AVERROR_INVALIDDATA;
            new_pal = bytestream2_get_le32(&ctx);
            if (new_pal < s->palettes_count) {
                s->cur_palette = new_pal;
            } else
                av_log(avctx, AV_LOG_ERROR, "Invalid palette selected\n");
            break;
        case VGA__TAG:
            break;
        default:
            bytestream2_skip(&ctx, size);
            break;
        }
    }
    buf_size = bytestream2_get_bytes_left(&ctx);

    if (s->palettes_count <= 0) {
        av_log(s->avctx, AV_LOG_ERROR, "No palette found\n");
        return AVERROR_INVALIDDATA;
    }

    if ((ret = ff_get_buffer(avctx, frame, AV_GET_BUFFER_FLAG_REF)) < 0)
        return ret;

    if (!s->frame_size)
        s->frame_size = frame->linesize[0] * s->avctx->height;

    memcpy(frame->data[1],
           s->palettes + s->cur_palette * AVPALETTE_COUNT, AVPALETTE_SIZE);

    s->buf = ctx.buffer;
    s->size = buf_size;

    if (xan_wc3_decode_frame(s, frame) < 0)
        return AVERROR_INVALIDDATA;

    av_frame_unref(s->last_frame);
    if ((ret = av_frame_ref(s->last_frame, frame)) < 0)
        return ret;

    *got_frame = 1;

    /* always report that the buffer was completely consumed */
    return buf_size;
}

