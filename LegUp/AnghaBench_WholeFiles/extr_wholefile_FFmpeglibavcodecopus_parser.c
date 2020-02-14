#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_58__   TYPE_5__ ;
typedef  struct TYPE_57__   TYPE_4__ ;
typedef  struct TYPE_56__   TYPE_3__ ;
typedef  struct TYPE_55__   TYPE_35__ ;
typedef  struct TYPE_54__   TYPE_33__ ;
typedef  struct TYPE_53__   TYPE_2__ ;
typedef  struct TYPE_52__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int VLC_TYPE ;
struct TYPE_58__ {scalar_t__ extradata; } ;
struct TYPE_57__ {int duration; TYPE_2__* priv_data; } ;
struct TYPE_56__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
struct TYPE_55__ {int nb_streams; int /*<<< orphan*/  channel_maps; } ;
struct TYPE_54__ {int frame_count; int frame_duration; } ;
struct TYPE_52__ {int frame_start_found; int state; } ;
struct TYPE_53__ {int ts_framing; int extradata_parsed; TYPE_1__ pc; TYPE_33__ pkt; TYPE_35__ ctx; } ;
typedef  TYPE_1__ ParseContext ;
typedef  TYPE_2__ OpusParseContext ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_3__ GetBitContext ;
typedef  TYPE_4__ AVCodecParserContext ;
typedef  TYPE_5__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int AV_RB16 (unsigned int const*) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int END_NOT_FOUND ; 
 int FFMAX (int,int) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 int MIN_CACHE_BITS ; 
 int NEG_USR32 (int,int) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int OPUS_TS_HEADER ; 
 int OPUS_TS_MASK ; 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int /*<<< orphan*/  av_freep (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_log (TYPE_5__*,int /*<<< orphan*/ ,char*,...) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,unsigned int const*,int) ; 
 int bytestream2_peek_byte (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int bytestream2_tell (int /*<<< orphan*/ *) ; 
 scalar_t__ ff_combine_frame (TYPE_1__*,int,unsigned int const**,int*) ; 
 int ff_opus_parse_extradata (TYPE_5__*,TYPE_35__*) ; 
 int ff_opus_parse_packet (TYPE_33__*,unsigned int const*,int,int) ; 
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

__attribute__((used)) static const uint8_t *parse_opus_ts_header(const uint8_t *start, int *payload_len, int buf_len)
{
    const uint8_t *buf = start + 1;
    int start_trim_flag, end_trim_flag, control_extension_flag, control_extension_length;
    uint8_t flags;
    uint64_t payload_len_tmp;

    GetByteContext gb;
    bytestream2_init(&gb, buf, buf_len);

    flags = bytestream2_get_byte(&gb);
    start_trim_flag        = (flags >> 4) & 1;
    end_trim_flag          = (flags >> 3) & 1;
    control_extension_flag = (flags >> 2) & 1;

    payload_len_tmp = *payload_len = 0;
    while (bytestream2_peek_byte(&gb) == 0xff)
        payload_len_tmp += bytestream2_get_byte(&gb);

    payload_len_tmp += bytestream2_get_byte(&gb);

    if (start_trim_flag)
        bytestream2_skip(&gb, 2);
    if (end_trim_flag)
        bytestream2_skip(&gb, 2);
    if (control_extension_flag) {
        control_extension_length = bytestream2_get_byte(&gb);
        bytestream2_skip(&gb, control_extension_length);
    }

    if (bytestream2_tell(&gb) + payload_len_tmp > buf_len)
        return NULL;

    *payload_len = payload_len_tmp;

    return buf + bytestream2_tell(&gb);
}

__attribute__((used)) static int opus_find_frame_end(AVCodecParserContext *ctx, AVCodecContext *avctx,
                               const uint8_t *buf, int buf_size, int *header_len)
{
    OpusParseContext *s = ctx->priv_data;
    ParseContext *pc    = &s->pc;
    int ret, start_found, i = 0, payload_len = 0;
    const uint8_t *payload;
    uint32_t state;
    uint16_t hdr;
    *header_len = 0;

    if (!buf_size)
        return 0;

    start_found = pc->frame_start_found;
    state = pc->state;
    payload = buf;

    /* Check if we're using Opus in MPEG-TS framing */
    if (!s->ts_framing && buf_size > 2) {
        hdr = AV_RB16(buf);
        if ((hdr & OPUS_TS_MASK) == OPUS_TS_HEADER)
            s->ts_framing = 1;
    }

    if (s->ts_framing && !start_found) {
        for (i = 0; i < buf_size-2; i++) {
            state = (state << 8) | payload[i];
            if ((state & OPUS_TS_MASK) == OPUS_TS_HEADER) {
                payload = parse_opus_ts_header(payload, &payload_len, buf_size - i);
                if (!payload) {
                    av_log(avctx, AV_LOG_ERROR, "Error parsing Ogg TS header.\n");
                    return AVERROR_INVALIDDATA;
                }
                *header_len = payload - buf;
                start_found = 1;
                break;
            }
        }
    }

    if (!s->ts_framing)
        payload_len = buf_size;

    if (avctx->extradata && !s->extradata_parsed) {
        ret = ff_opus_parse_extradata(avctx, &s->ctx);
        if (ret < 0) {
            av_log(avctx, AV_LOG_ERROR, "Error parsing Ogg extradata.\n");
            return AVERROR_INVALIDDATA;
        }
        av_freep(&s->ctx.channel_maps);
        s->extradata_parsed = 1;
    }

    if (payload_len <= buf_size && (!s->ts_framing || start_found)) {
        ret = ff_opus_parse_packet(&s->pkt, payload, payload_len, s->ctx.nb_streams > 1);
        if (ret < 0) {
            av_log(avctx, AV_LOG_ERROR, "Error parsing Opus packet header.\n");
            pc->frame_start_found = 0;
            return AVERROR_INVALIDDATA;
        }

        ctx->duration = s->pkt.frame_count * s->pkt.frame_duration;
    }

    if (s->ts_framing) {
        if (start_found) {
            if (payload_len + *header_len <= buf_size) {
                pc->frame_start_found = 0;
                pc->state             = -1;
                return payload_len + *header_len;
            }
        }

        pc->frame_start_found = start_found;
        pc->state = state;
        return END_NOT_FOUND;
    }

    return buf_size;
}

__attribute__((used)) static int opus_parse(AVCodecParserContext *ctx, AVCodecContext *avctx,
                       const uint8_t **poutbuf, int *poutbuf_size,
                       const uint8_t *buf, int buf_size)
{
    OpusParseContext *s = ctx->priv_data;
    ParseContext *pc    = &s->pc;
    int next, header_len;

    next = opus_find_frame_end(ctx, avctx, buf, buf_size, &header_len);

    if (s->ts_framing && next != AVERROR_INVALIDDATA &&
        ff_combine_frame(pc, next, &buf, &buf_size) < 0) {
        *poutbuf      = NULL;
        *poutbuf_size = 0;
        return buf_size;
    }

    if (next == AVERROR_INVALIDDATA){
        *poutbuf      = NULL;
        *poutbuf_size = 0;
        return buf_size;
    }

    *poutbuf      = buf + header_len;
    *poutbuf_size = buf_size - header_len;
    return next;
}

