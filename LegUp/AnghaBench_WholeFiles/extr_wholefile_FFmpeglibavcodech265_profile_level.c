#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_52__   TYPE_4__ ;
typedef  struct TYPE_51__   TYPE_2__ ;
typedef  struct TYPE_50__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int64_t ;
typedef  int int32_t ;
typedef  int VLC_TYPE ;
struct TYPE_52__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
struct TYPE_51__ {int level_idc; size_t profile_idc; int max_14bit; int max_12bit; int max_10bit; int max_8bit; int max_422chroma; int max_420chroma; int max_monochrome; int intra; int one_picture_only; int lower_bit_rate; int max_luma_ps; int max_slice_segments_per_picture; int max_tile_rows; int max_tile_cols; int max_br_high; int max_br_main; scalar_t__ cpb_nal_factor; scalar_t__ high_throughput; } ;
struct TYPE_50__ {size_t general_profile_idc; int general_max_14bit_constraint_flag; int general_max_12bit_constraint_flag; int general_max_10bit_constraint_flag; int general_max_8bit_constraint_flag; int general_max_422chroma_constraint_flag; int general_max_420chroma_constraint_flag; int general_max_monochrome_constraint_flag; int general_intra_constraint_flag; int general_one_picture_only_constraint_flag; int general_lower_bit_rate_constraint_flag; scalar_t__ general_tier_flag; int /*<<< orphan*/ * general_profile_compatibility_flag; scalar_t__ general_profile_space; } ;
typedef  TYPE_1__ H265RawProfileTierLevel ;
typedef  TYPE_2__ H265ProfileDescriptor ;
typedef  TYPE_2__ H265LevelDescriptor ;
typedef  TYPE_4__ GetBitContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  EAGAIN ; 
 int FFMAX (int,int) ; 
 int FF_ARRAY_ELEMS (TYPE_2__ const*) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 int MIN_CACHE_BITS ; 
 int NEG_USR32 (int,int) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int /*<<< orphan*/  av_log (void*,int /*<<< orphan*/ ,char*,int,int,...) ; 
 TYPE_2__ const* h265_levels ; 
 TYPE_2__ const* h265_profiles ; 
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

__attribute__((used)) static inline int get_nalsize(int nal_length_size, const uint8_t *buf,
                              int buf_size, int *buf_index, void *logctx)
{
    int i, nalsize = 0;

    if (*buf_index >= buf_size - nal_length_size) {
        // the end of the buffer is reached, refill it
        return AVERROR(EAGAIN);
    }

    for (i = 0; i < nal_length_size; i++)
        nalsize = ((unsigned)nalsize << 8) | buf[(*buf_index)++];
    if (nalsize <= 0 || nalsize > buf_size - *buf_index) {
        av_log(logctx, AV_LOG_ERROR,
               "Invalid NAL unit size (%d > %d).\n", nalsize, buf_size - *buf_index);
        return AVERROR_INVALIDDATA;
    }
    return nalsize;
}

const H265LevelDescriptor *ff_h265_get_level(int level_idc)
{
    int i;

    for (i = 0; i < FF_ARRAY_ELEMS(h265_levels); i++) {
        if (h265_levels[i].level_idc == level_idc)
            return &h265_levels[i];
    }

    return NULL;
}

const H265ProfileDescriptor *ff_h265_get_profile(const H265RawProfileTierLevel *ptl)
{
    int i;

    if (ptl->general_profile_space)
        return NULL;

    for (i = 0; i < FF_ARRAY_ELEMS(h265_profiles); i++) {
        const H265ProfileDescriptor *profile = &h265_profiles[i];

        if (ptl->general_profile_idc &&
            ptl->general_profile_idc != profile->profile_idc)
            continue;
        if (!ptl->general_profile_compatibility_flag[profile->profile_idc])
            continue;

#define check_flag(name) \
        if (profile->name < 2) { \
            if (profile->name != ptl->general_ ## name ## _constraint_flag) \
                continue; \
        }
        check_flag(max_14bit);
        check_flag(max_12bit);
        check_flag(max_10bit);
        check_flag(max_8bit);
        check_flag(max_422chroma);
        check_flag(max_420chroma);
        check_flag(max_monochrome);
        check_flag(intra);
        check_flag(one_picture_only);
        check_flag(lower_bit_rate);
#undef check_flag

        return profile;
    }

    return NULL;
}

const H265LevelDescriptor *ff_h265_guess_level(const H265RawProfileTierLevel *ptl,
                                               int64_t bitrate,
                                               int width, int height,
                                               int slice_segments,
                                               int tile_rows, int tile_cols,
                                               int max_dec_pic_buffering)
{
    const H265ProfileDescriptor *profile;
    int pic_size, lbr_flag, hbr_factor;
    int i;

    if (ptl)
        profile = ff_h265_get_profile(ptl);
    else
        profile = NULL;
    if (!profile) {
        // Default to using multiplication factors for Main profile.
        profile = &h265_profiles[3];
    }

    pic_size = width * height;

    if (ptl)
        lbr_flag = ptl->general_lower_bit_rate_constraint_flag;
    else
        lbr_flag = profile->lower_bit_rate > 0;
    if (profile->profile_idc == 1 || profile->profile_idc == 2) {
        hbr_factor = 1;
    } else if (profile->high_throughput) {
        if (profile->intra)
            hbr_factor = 24 - 12 * lbr_flag;
        else
            hbr_factor = 6;
    } else {
        hbr_factor = 2 - lbr_flag;
    }

    for (i = 0; i < FF_ARRAY_ELEMS(h265_levels); i++) {
        const H265LevelDescriptor *level = &h265_levels[i];
        int max_br, max_dpb_size;

        if (pic_size > level->max_luma_ps)
            continue;
        if (width  * width  > 8 * level->max_luma_ps)
            continue;
        if (height * height > 8 * level->max_luma_ps)
            continue;

        if (slice_segments > level->max_slice_segments_per_picture)
            continue;
        if (tile_rows > level->max_tile_rows)
            continue;
        if (tile_cols > level->max_tile_cols)
            continue;

        if (ptl && ptl->general_tier_flag)
            max_br = level->max_br_high;
        else
            max_br = level->max_br_main;
        if (!max_br)
            continue;
        if (bitrate > (int64_t)profile->cpb_nal_factor * hbr_factor * max_br)
            continue;

        if (pic_size < (level->max_luma_ps >> 2))
            max_dpb_size = 16;
        else if (pic_size < (level->max_luma_ps >> 1))
            max_dpb_size = 14;
        else if (pic_size < (3 * level->max_luma_ps >> 2))
            max_dpb_size = 9;
        else
            max_dpb_size = 7;
        if (max_dec_pic_buffering > max_dpb_size)
            continue;

        return level;
    }

    return NULL;
}

