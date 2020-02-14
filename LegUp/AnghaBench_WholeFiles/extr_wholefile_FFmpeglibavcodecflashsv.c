#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_70__   TYPE_4__ ;
typedef  struct TYPE_69__   TYPE_48__ ;
typedef  struct TYPE_68__   TYPE_3__ ;
typedef  struct TYPE_67__   TYPE_38__ ;
typedef  struct TYPE_66__   TYPE_2__ ;
typedef  struct TYPE_65__   TYPE_1__ ;
typedef  struct TYPE_64__   TYPE_17__ ;

/* Type definitions */
struct TYPE_65__ {unsigned int* next_in; int avail_in; unsigned int* next_out; int avail_out; int /*<<< orphan*/ * opaque; int /*<<< orphan*/ * zfree; int /*<<< orphan*/ * zalloc; } ;
typedef  TYPE_1__ z_stream ;
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_64__ {unsigned int* next_in; int avail_in; unsigned int* next_out; int avail_out; } ;
struct FlashSVContext {unsigned int* tmpblock; int block_size; unsigned int* deflate_block; int deflate_block_size; unsigned int zlibprime_curr; unsigned int zlibprime_prev; int is_keyframe; unsigned int* keyframedata; unsigned int diff_start; unsigned int color_depth; int diff_height; int image_height; int block_width; int block_height; unsigned int image_width; int ver; unsigned int* keyframe; TYPE_38__* frame; TYPE_48__* blocks; int /*<<< orphan*/ * pal; TYPE_17__ zstream; int /*<<< orphan*/  avctx; } ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int VLC_TYPE ;
struct TYPE_70__ {int width; int height; struct FlashSVContext* priv_data; } ;
struct TYPE_69__ {unsigned int* pos; int size; } ;
struct TYPE_68__ {unsigned int* data; int size; int flags; } ;
struct TYPE_67__ {unsigned int** data; int* linesize; } ;
struct TYPE_66__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
typedef  TYPE_2__ GetBitContext ;
typedef  struct FlashSVContext FlashSVContext ;
typedef  TYPE_3__ AVPacket ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int AVERROR_PATCHWELCOME ; 
 int AVERROR_UNKNOWN ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int AV_PKT_FLAG_KEY ; 
 int AV_RB16 (unsigned int const*) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FFMAX (int,int) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_2__*,int) ; 
 int MIN_CACHE_BITS ; 
 int NEG_USR32 (int,int) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_2__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_2__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_2__*,int) ; 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int Z_DATA_ERROR ; 
 int /*<<< orphan*/  Z_FINISH ; 
 void* Z_NULL ; 
 int Z_OK ; 
 int Z_STREAM_END ; 
 int /*<<< orphan*/  Z_SYNC_FLUSH ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int av_frame_ref (void*,TYPE_38__*) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_38__*) ; 
 int /*<<< orphan*/  av_freep (TYPE_48__**) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,...) ; 
 unsigned int* av_malloc (int) ; 
 TYPE_48__* av_mallocz (int) ; 
 int av_reallocp (unsigned int**,int) ; 
 int /*<<< orphan*/  avpriv_request_sample (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  bytestream_put_le24 (unsigned int**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  deflate (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int deflateBound (TYPE_1__*,int) ; 
 int /*<<< orphan*/  deflateEnd (TYPE_1__*) ; 
 int deflateInit (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_dlog (TYPE_4__*,char*,int,int,int,int,int,int,int,int) ; 
 int ff_reget_buffer (TYPE_4__*,TYPE_38__*) ; 
 int ff_set_dimensions (TYPE_4__*,int,int) ; 
 int inflate (TYPE_17__*,int /*<<< orphan*/ ) ; 
 int inflateReset (TYPE_17__*) ; 
 int /*<<< orphan*/  inflateSync (TYPE_17__*) ; 
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned int*,int) ; 
 int /*<<< orphan*/  re ; 
 int sign_extend (int,int) ; 
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

__attribute__((used)) static int decode_hybrid(const uint8_t *sptr, const uint8_t *sptr_end, uint8_t *dptr, int dx, int dy,
                         int h, int w, int stride, const uint32_t *pal)
{
    int x, y;
    const uint8_t *orig_src = sptr;

    for (y = dx + h; y > dx; y--) {
        uint8_t *dst = dptr + (y * stride) + dy * 3;
        for (x = 0; x < w; x++) {
            if (sptr >= sptr_end)
                return AVERROR_INVALIDDATA;
            if (*sptr & 0x80) {
                /* 15-bit color */
                unsigned c = AV_RB16(sptr) & ~0x8000;
                unsigned b =  c        & 0x1F;
                unsigned g = (c >>  5) & 0x1F;
                unsigned r =  c >> 10;
                /* 000aaabb -> aaabbaaa  */
                *dst++ = (b << 3) | (b >> 2);
                *dst++ = (g << 3) | (g >> 2);
                *dst++ = (r << 3) | (r >> 2);
                sptr += 2;
            } else {
                /* palette index */
                uint32_t c = pal[*sptr++];
                bytestream_put_le24(&dst, c);
            }
        }
    }
    return sptr - orig_src;
}

__attribute__((used)) static int flashsv2_prime(FlashSVContext *s, uint8_t *src, int size)
{
    z_stream zs;
    int zret; // Zlib return code

    if (!src)
        return AVERROR_INVALIDDATA;

    zs.zalloc = NULL;
    zs.zfree  = NULL;
    zs.opaque = NULL;

    s->zstream.next_in   = src;
    s->zstream.avail_in  = size;
    s->zstream.next_out  = s->tmpblock;
    s->zstream.avail_out = s->block_size * 3;
    inflate(&s->zstream, Z_SYNC_FLUSH);

    if (deflateInit(&zs, 0) != Z_OK)
        return -1;
    zs.next_in   = s->tmpblock;
    zs.avail_in  = s->block_size * 3 - s->zstream.avail_out;
    zs.next_out  = s->deflate_block;
    zs.avail_out = s->deflate_block_size;
    deflate(&zs, Z_SYNC_FLUSH);
    deflateEnd(&zs);

    if ((zret = inflateReset(&s->zstream)) != Z_OK) {
        av_log(s->avctx, AV_LOG_ERROR, "Inflate reset error: %d\n", zret);
        return AVERROR_UNKNOWN;
    }

    s->zstream.next_in   = s->deflate_block;
    s->zstream.avail_in  = s->deflate_block_size - zs.avail_out;
    s->zstream.next_out  = s->tmpblock;
    s->zstream.avail_out = s->block_size * 3;
    inflate(&s->zstream, Z_SYNC_FLUSH);

    return 0;
}

__attribute__((used)) static int flashsv_decode_block(AVCodecContext *avctx, AVPacket *avpkt,
                                GetBitContext *gb, int block_size,
                                int width, int height, int x_pos, int y_pos,
                                int blk_idx)
{
    struct FlashSVContext *s = avctx->priv_data;
    uint8_t *line = s->tmpblock;
    int k;
    int ret = inflateReset(&s->zstream);
    if (ret != Z_OK) {
        av_log(avctx, AV_LOG_ERROR, "Inflate reset error: %d\n", ret);
        return AVERROR_UNKNOWN;
    }
    if (s->zlibprime_curr || s->zlibprime_prev) {
        ret = flashsv2_prime(s,
                             s->blocks[blk_idx].pos,
                             s->blocks[blk_idx].size);
        if (ret < 0)
            return ret;
    }
    s->zstream.next_in   = avpkt->data + get_bits_count(gb) / 8;
    s->zstream.avail_in  = block_size;
    s->zstream.next_out  = s->tmpblock;
    s->zstream.avail_out = s->block_size * 3;
    ret = inflate(&s->zstream, Z_FINISH);
    if (ret == Z_DATA_ERROR) {
        av_log(avctx, AV_LOG_ERROR, "Zlib resync occurred\n");
        inflateSync(&s->zstream);
        ret = inflate(&s->zstream, Z_FINISH);
    }

    if (ret != Z_OK && ret != Z_STREAM_END) {
        //return -1;
    }

    if (s->is_keyframe) {
        s->blocks[blk_idx].pos  = s->keyframedata + (get_bits_count(gb) / 8);
        s->blocks[blk_idx].size = block_size;
    }

    y_pos += s->diff_start;

    if (!s->color_depth) {
        /* Flash Screen Video stores the image upside down, so copy
         * lines to destination in reverse order. */
        for (k = 1; k <= s->diff_height; k++) {
            memcpy(s->frame->data[0] + x_pos * 3 +
                   (s->image_height - y_pos - k) * s->frame->linesize[0],
                   line, width * 3);
            /* advance source pointer to next line */
            line += width * 3;
        }
    } else {
        /* hybrid 15-bit/palette mode */
        ret = decode_hybrid(s->tmpblock, s->zstream.next_out,
                      s->frame->data[0],
                      s->image_height - (y_pos + 1 + s->diff_height),
                      x_pos, s->diff_height, width,
                      s->frame->linesize[0], s->pal);
        if (ret < 0) {
            av_log(avctx, AV_LOG_ERROR, "decode_hybrid failed\n");
            return ret;
        }
    }
    skip_bits_long(gb, 8 * block_size); /* skip the consumed bits */
    return 0;
}

__attribute__((used)) static int calc_deflate_block_size(int tmpblock_size)
{
    z_stream zstream;
    int size;

    zstream.zalloc = Z_NULL;
    zstream.zfree  = Z_NULL;
    zstream.opaque = Z_NULL;
    if (deflateInit(&zstream, 0) != Z_OK)
        return -1;
    size = deflateBound(&zstream, tmpblock_size);
    deflateEnd(&zstream);

    return size;
}

__attribute__((used)) static int flashsv_decode_frame(AVCodecContext *avctx, void *data,
                                int *got_frame, AVPacket *avpkt)
{
    int buf_size = avpkt->size;
    FlashSVContext *s = avctx->priv_data;
    int h_blocks, v_blocks, h_part, v_part, i, j, ret;
    GetBitContext gb;
    int last_blockwidth = s->block_width;
    int last_blockheight= s->block_height;

    /* no supplementary picture */
    if (buf_size == 0)
        return 0;
    if (buf_size < 4)
        return -1;

    if ((ret = init_get_bits8(&gb, avpkt->data, buf_size)) < 0)
        return ret;

    /* start to parse the bitstream */
    s->block_width  = 16 * (get_bits(&gb, 4) + 1);
    s->image_width  = get_bits(&gb, 12);
    s->block_height = 16 * (get_bits(&gb, 4) + 1);
    s->image_height = get_bits(&gb, 12);

    if (   last_blockwidth != s->block_width
        || last_blockheight!= s->block_height)
        av_freep(&s->blocks);

    if (s->ver == 2) {
        skip_bits(&gb, 6);
        if (get_bits1(&gb)) {
            avpriv_request_sample(avctx, "iframe");
            return AVERROR_PATCHWELCOME;
        }
        if (get_bits1(&gb)) {
            avpriv_request_sample(avctx, "Custom palette");
            return AVERROR_PATCHWELCOME;
        }
    }

    /* calculate number of blocks and size of border (partial) blocks */
    h_blocks = s->image_width  / s->block_width;
    h_part   = s->image_width  % s->block_width;
    v_blocks = s->image_height / s->block_height;
    v_part   = s->image_height % s->block_height;

    /* the block size could change between frames, make sure the buffer
     * is large enough, if not, get a larger one */
    if (s->block_size < s->block_width * s->block_height) {
        int tmpblock_size = 3 * s->block_width * s->block_height, err;

        if ((err = av_reallocp(&s->tmpblock, tmpblock_size)) < 0) {
            s->block_size = 0;
            av_log(avctx, AV_LOG_ERROR,
                   "Cannot allocate decompression buffer.\n");
            return err;
        }
        if (s->ver == 2) {
            s->deflate_block_size = calc_deflate_block_size(tmpblock_size);
            if (s->deflate_block_size <= 0) {
                av_log(avctx, AV_LOG_ERROR,
                       "Cannot determine deflate buffer size.\n");
                return -1;
            }
            if ((err = av_reallocp(&s->deflate_block, s->deflate_block_size)) < 0) {
                s->block_size = 0;
                av_log(avctx, AV_LOG_ERROR, "Cannot allocate deflate buffer.\n");
                return err;
            }
        }
    }
    s->block_size = s->block_width * s->block_height;

    /* initialize the image size once */
    if (avctx->width == 0 && avctx->height == 0) {
        if ((ret = ff_set_dimensions(avctx, s->image_width, s->image_height)) < 0)
            return ret;
    }

    /* check for changes of image width and image height */
    if (avctx->width != s->image_width || avctx->height != s->image_height) {
        av_log(avctx, AV_LOG_ERROR,
               "Frame width or height differs from first frame!\n");
        av_log(avctx, AV_LOG_ERROR, "fh = %d, fv %d  vs  ch = %d, cv = %d\n",
               avctx->height, avctx->width, s->image_height, s->image_width);
        return AVERROR_INVALIDDATA;
    }

    /* we care for keyframes only in Screen Video v2 */
    s->is_keyframe = (avpkt->flags & AV_PKT_FLAG_KEY) && (s->ver == 2);
    if (s->is_keyframe) {
        int err;
        if ((err = av_reallocp(&s->keyframedata, avpkt->size)) < 0)
            return err;
        memcpy(s->keyframedata, avpkt->data, avpkt->size);
    }
    if(s->ver == 2 && !s->blocks)
        s->blocks = av_mallocz((v_blocks + !!v_part) * (h_blocks + !!h_part) *
                               sizeof(s->blocks[0]));

    ff_dlog(avctx, "image: %dx%d block: %dx%d num: %dx%d part: %dx%d\n",
            s->image_width, s->image_height, s->block_width, s->block_height,
            h_blocks, v_blocks, h_part, v_part);

    if ((ret = ff_reget_buffer(avctx, s->frame)) < 0)
        return ret;

    /* loop over all block columns */
    for (j = 0; j < v_blocks + (v_part ? 1 : 0); j++) {

        int y_pos  = j * s->block_height; // vertical position in frame
        int cur_blk_height = (j < v_blocks) ? s->block_height : v_part;

        /* loop over all block rows */
        for (i = 0; i < h_blocks + (h_part ? 1 : 0); i++) {
            int x_pos = i * s->block_width; // horizontal position in frame
            int cur_blk_width = (i < h_blocks) ? s->block_width : h_part;
            int has_diff = 0;

            /* get the size of the compressed zlib chunk */
            int size = get_bits(&gb, 16);

            s->color_depth    = 0;
            s->zlibprime_curr = 0;
            s->zlibprime_prev = 0;
            s->diff_start     = 0;
            s->diff_height    = cur_blk_height;

            if (8 * size > get_bits_left(&gb)) {
                av_frame_unref(s->frame);
                return AVERROR_INVALIDDATA;
            }

            if (s->ver == 2 && size) {
                skip_bits(&gb, 3);
                s->color_depth    = get_bits(&gb, 2);
                has_diff          = get_bits1(&gb);
                s->zlibprime_curr = get_bits1(&gb);
                s->zlibprime_prev = get_bits1(&gb);

                if (s->color_depth != 0 && s->color_depth != 2) {
                    av_log(avctx, AV_LOG_ERROR,
                           "%dx%d invalid color depth %d\n",
                           i, j, s->color_depth);
                    return AVERROR_INVALIDDATA;
                }

                if (has_diff) {
                    if (size < 3) {
                        av_log(avctx, AV_LOG_ERROR, "size too small for diff\n");
                        return AVERROR_INVALIDDATA;
                    }
                    if (!s->keyframe) {
                        av_log(avctx, AV_LOG_ERROR,
                               "Inter frame without keyframe\n");
                        return AVERROR_INVALIDDATA;
                    }
                    s->diff_start  = get_bits(&gb, 8);
                    s->diff_height = get_bits(&gb, 8);
                    if (s->diff_start + s->diff_height > cur_blk_height) {
                        av_log(avctx, AV_LOG_ERROR,
                               "Block parameters invalid: %d + %d > %d\n",
                               s->diff_start, s->diff_height, cur_blk_height);
                        return AVERROR_INVALIDDATA;
                    }
                    av_log(avctx, AV_LOG_DEBUG,
                           "%dx%d diff start %d height %d\n",
                           i, j, s->diff_start, s->diff_height);
                    size -= 2;
                }

                if (s->zlibprime_prev)
                    av_log(avctx, AV_LOG_DEBUG, "%dx%d zlibprime_prev\n", i, j);

                if (s->zlibprime_curr) {
                    int col = get_bits(&gb, 8);
                    int row = get_bits(&gb, 8);
                    av_log(avctx, AV_LOG_DEBUG, "%dx%d zlibprime_curr %dx%d\n",
                           i, j, col, row);
                    if (size < 3) {
                        av_log(avctx, AV_LOG_ERROR, "size too small for zlibprime_curr\n");
                        return AVERROR_INVALIDDATA;
                    }
                    size -= 2;
                    avpriv_request_sample(avctx, "zlibprime_curr");
                    return AVERROR_PATCHWELCOME;
                }
                if (!s->blocks && (s->zlibprime_curr || s->zlibprime_prev)) {
                    av_log(avctx, AV_LOG_ERROR,
                           "no data available for zlib priming\n");
                    return AVERROR_INVALIDDATA;
                }
                size--; // account for flags byte
            }

            if (has_diff) {
                int k;
                int off = (s->image_height - y_pos - 1) * s->frame->linesize[0];

                for (k = 0; k < cur_blk_height; k++) {
                    int x = off - k * s->frame->linesize[0] + x_pos * 3;
                    memcpy(s->frame->data[0] + x, s->keyframe + x,
                           cur_blk_width * 3);
                }
            }

            /* skip unchanged blocks, which have size 0 */
            if (size) {
                if (flashsv_decode_block(avctx, avpkt, &gb, size,
                                         cur_blk_width, cur_blk_height,
                                         x_pos, y_pos,
                                         i + j * (h_blocks + !!h_part)))
                    av_log(avctx, AV_LOG_ERROR,
                           "error in decompression of block %dx%d\n", i, j);
            }
        }
    }
    if (s->is_keyframe && s->ver == 2) {
        if (!s->keyframe) {
            s->keyframe = av_malloc(s->frame->linesize[0] * avctx->height);
            if (!s->keyframe) {
                av_log(avctx, AV_LOG_ERROR, "Cannot allocate image data\n");
                return AVERROR(ENOMEM);
            }
        }
        memcpy(s->keyframe, s->frame->data[0],
               s->frame->linesize[0] * avctx->height);
    }

    if ((ret = av_frame_ref(data, s->frame)) < 0)
        return ret;

    *got_frame = 1;

    if ((get_bits_count(&gb) / 8) != buf_size)
        av_log(avctx, AV_LOG_ERROR, "buffer not fully consumed (%d != %d)\n",
               buf_size, (get_bits_count(&gb) / 8));

    /* report that the buffer was completely consumed */
    return buf_size;
}

