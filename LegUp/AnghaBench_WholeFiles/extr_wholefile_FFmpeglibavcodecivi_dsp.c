#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_49__   TYPE_4__ ;
typedef  struct TYPE_48__   TYPE_3__ ;
typedef  struct TYPE_47__   TYPE_2__ ;
typedef  struct TYPE_46__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  size_t ptrdiff_t ;
typedef  int /*<<< orphan*/  out ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int int16_t ;
typedef  int VLC_TYPE ;
struct TYPE_49__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
struct TYPE_48__ {scalar_t__ pic_width; scalar_t__ pic_height; scalar_t__ chroma_width; scalar_t__ chroma_height; scalar_t__ tile_width; scalar_t__ tile_height; scalar_t__ luma_bands; scalar_t__ chroma_bands; } ;
struct TYPE_47__ {int height; int width; TYPE_1__* bands; } ;
struct TYPE_46__ {size_t pitch; short* buf; } ;
typedef  TYPE_2__ IVIPlaneDesc ;
typedef  TYPE_3__ IVIPicConfig ;
typedef  TYPE_4__ GetBitContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int FFMAX (int,int) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  INV_HAAR4 (int const,int const,int const,int const,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  INV_HAAR8 (int const,int const,int const,int const,int const,int const,int const,int const,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  IVI_INV_SLANT4 (int const,int const,int const,int const,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  IVI_INV_SLANT8 (int const,int const,int const,int const,int const,int const,int const,int const,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
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
 unsigned int av_clip_uint8 (int) ; 
 int /*<<< orphan*/  av_log (void*,int /*<<< orphan*/ ,char*,int,int,char const*) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
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

__attribute__((used)) static inline int ivi_pic_config_cmp(IVIPicConfig *str1, IVIPicConfig *str2)
{
    return str1->pic_width    != str2->pic_width    || str1->pic_height    != str2->pic_height    ||
           str1->chroma_width != str2->chroma_width || str1->chroma_height != str2->chroma_height ||
           str1->tile_width   != str2->tile_width   || str1->tile_height   != str2->tile_height   ||
           str1->luma_bands   != str2->luma_bands   || str1->chroma_bands  != str2->chroma_bands;
}

__attribute__((used)) static inline int ivi_scale_mv(int mv, int mv_scale)
{
    return (mv + (mv > 0) + (mv_scale - 1)) >> mv_scale;
}

void ff_ivi_recompose53(const IVIPlaneDesc *plane, uint8_t *dst,
                        const ptrdiff_t dst_pitch)
{
    int             x, y, indx;
    int32_t         p0, p1, p2, p3, tmp0, tmp1, tmp2;
    int32_t         b0_1, b0_2, b1_1, b1_2, b1_3, b2_1, b2_2, b2_3, b2_4, b2_5, b2_6;
    int32_t         b3_1, b3_2, b3_3, b3_4, b3_5, b3_6, b3_7, b3_8, b3_9;
    ptrdiff_t       pitch, back_pitch;
    const short     *b0_ptr, *b1_ptr, *b2_ptr, *b3_ptr;
    const int       num_bands = 4;

    /* all bands should have the same pitch */
    pitch = plane->bands[0].pitch;

    /* pixels at the position "y-1" will be set to pixels at the "y" for the 1st iteration */
    back_pitch = 0;

    /* get pointers to the wavelet bands */
    b0_ptr = plane->bands[0].buf;
    b1_ptr = plane->bands[1].buf;
    b2_ptr = plane->bands[2].buf;
    b3_ptr = plane->bands[3].buf;

    for (y = 0; y < plane->height; y += 2) {

        if (y+2 >= plane->height)
            pitch= 0;
        /* load storage variables with values */
        if (num_bands > 0) {
            b0_1 = b0_ptr[0];
            b0_2 = b0_ptr[pitch];
        }

        if (num_bands > 1) {
            b1_1 = b1_ptr[back_pitch];
            b1_2 = b1_ptr[0];
            b1_3 = b1_1 - b1_2*6 + b1_ptr[pitch];
        }

        if (num_bands > 2) {
            b2_2 = b2_ptr[0];     // b2[x,  y  ]
            b2_3 = b2_2;          // b2[x+1,y  ] = b2[x,y]
            b2_5 = b2_ptr[pitch]; // b2[x  ,y+1]
            b2_6 = b2_5;          // b2[x+1,y+1] = b2[x,y+1]
        }

        if (num_bands > 3) {
            b3_2 = b3_ptr[back_pitch]; // b3[x  ,y-1]
            b3_3 = b3_2;               // b3[x+1,y-1] = b3[x  ,y-1]
            b3_5 = b3_ptr[0];          // b3[x  ,y  ]
            b3_6 = b3_5;               // b3[x+1,y  ] = b3[x  ,y  ]
            b3_8 = b3_2 - b3_5*6 + b3_ptr[pitch];
            b3_9 = b3_8;
        }

        for (x = 0, indx = 0; x < plane->width; x+=2, indx++) {
            if (x+2 >= plane->width) {
                b0_ptr --;
                b1_ptr --;
                b2_ptr --;
                b3_ptr --;
            }

            /* some values calculated in the previous iterations can */
            /* be reused in the next ones, so do appropriate copying */
            b2_1 = b2_2; // b2[x-1,y  ] = b2[x,  y  ]
            b2_2 = b2_3; // b2[x  ,y  ] = b2[x+1,y  ]
            b2_4 = b2_5; // b2[x-1,y+1] = b2[x  ,y+1]
            b2_5 = b2_6; // b2[x  ,y+1] = b2[x+1,y+1]
            b3_1 = b3_2; // b3[x-1,y-1] = b3[x  ,y-1]
            b3_2 = b3_3; // b3[x  ,y-1] = b3[x+1,y-1]
            b3_4 = b3_5; // b3[x-1,y  ] = b3[x  ,y  ]
            b3_5 = b3_6; // b3[x  ,y  ] = b3[x+1,y  ]
            b3_7 = b3_8; // vert_HPF(x-1)
            b3_8 = b3_9; // vert_HPF(x  )

            p0 = p1 = p2 = p3 = 0;

            /* process the LL-band by applying LPF both vertically and horizontally */
            if (num_bands > 0) {
                tmp0 = b0_1;
                tmp2 = b0_2;
                b0_1 = b0_ptr[indx+1];
                b0_2 = b0_ptr[pitch+indx+1];
                tmp1 = tmp0 + b0_1;

                p0 =  tmp0 * 16;
                p1 =  tmp1 * 8;
                p2 = (tmp0 + tmp2) * 8;
                p3 = (tmp1 + tmp2 + b0_2) * 4;
            }

            /* process the HL-band by applying HPF vertically and LPF horizontally */
            if (num_bands > 1) {
                tmp0 = b1_2;
                tmp1 = b1_1;
                b1_2 = b1_ptr[indx+1];
                b1_1 = b1_ptr[back_pitch+indx+1];

                tmp2 = tmp1 - tmp0*6 + b1_3;
                b1_3 = b1_1 - b1_2*6 + b1_ptr[pitch+indx+1];

                p0 += (tmp0 + tmp1) * 8;
                p1 += (tmp0 + tmp1 + b1_1 + b1_2) * 4;
                p2 +=  tmp2 * 4;
                p3 += (tmp2 + b1_3) * 2;
            }

            /* process the LH-band by applying LPF vertically and HPF horizontally */
            if (num_bands > 2) {
                b2_3 = b2_ptr[indx+1];
                b2_6 = b2_ptr[pitch+indx+1];

                tmp0 = b2_1 + b2_2;
                tmp1 = b2_1 - b2_2*6 + b2_3;

                p0 += tmp0 * 8;
                p1 += tmp1 * 4;
                p2 += (tmp0 + b2_4 + b2_5) * 4;
                p3 += (tmp1 + b2_4 - b2_5*6 + b2_6) * 2;
            }

            /* process the HH-band by applying HPF both vertically and horizontally */
            if (num_bands > 3) {
                b3_6 = b3_ptr[indx+1];            // b3[x+1,y  ]
                b3_3 = b3_ptr[back_pitch+indx+1]; // b3[x+1,y-1]

                tmp0 = b3_1 + b3_4;
                tmp1 = b3_2 + b3_5;
                tmp2 = b3_3 + b3_6;

                b3_9 = b3_3 - b3_6*6 + b3_ptr[pitch+indx+1];

                p0 += (tmp0 + tmp1) * 4;
                p1 += (tmp0 - tmp1*6 + tmp2) * 2;
                p2 += (b3_7 + b3_8) * 2;
                p3 +=  b3_7 - b3_8*6 + b3_9;
            }

            /* output four pixels */
            dst[x]             = av_clip_uint8((p0 >> 6) + 128);
            dst[x+1]           = av_clip_uint8((p1 >> 6) + 128);
            dst[dst_pitch+x]   = av_clip_uint8((p2 >> 6) + 128);
            dst[dst_pitch+x+1] = av_clip_uint8((p3 >> 6) + 128);
        }// for x

        dst += dst_pitch << 1;

        back_pitch = -pitch;

        b0_ptr += pitch + 1;
        b1_ptr += pitch + 1;
        b2_ptr += pitch + 1;
        b3_ptr += pitch + 1;
    }
}

void ff_ivi_recompose_haar(const IVIPlaneDesc *plane, uint8_t *dst,
                           const ptrdiff_t dst_pitch)
{
    int             x, y, indx, b0, b1, b2, b3, p0, p1, p2, p3;
    const short     *b0_ptr, *b1_ptr, *b2_ptr, *b3_ptr;
    ptrdiff_t       pitch;

    /* all bands should have the same pitch */
    pitch = plane->bands[0].pitch;

    /* get pointers to the wavelet bands */
    b0_ptr = plane->bands[0].buf;
    b1_ptr = plane->bands[1].buf;
    b2_ptr = plane->bands[2].buf;
    b3_ptr = plane->bands[3].buf;

    for (y = 0; y < plane->height; y += 2) {
        for (x = 0, indx = 0; x < plane->width; x += 2, indx++) {
            /* load coefficients */
            b0 = b0_ptr[indx]; //should be: b0 = (num_bands > 0) ? b0_ptr[indx] : 0;
            b1 = b1_ptr[indx]; //should be: b1 = (num_bands > 1) ? b1_ptr[indx] : 0;
            b2 = b2_ptr[indx]; //should be: b2 = (num_bands > 2) ? b2_ptr[indx] : 0;
            b3 = b3_ptr[indx]; //should be: b3 = (num_bands > 3) ? b3_ptr[indx] : 0;

            /* haar wavelet recomposition */
            p0 = (b0 + b1 + b2 + b3 + 2) >> 2;
            p1 = (b0 + b1 - b2 - b3 + 2) >> 2;
            p2 = (b0 - b1 + b2 - b3 + 2) >> 2;
            p3 = (b0 - b1 - b2 + b3 + 2) >> 2;

            /* bias, convert and output four pixels */
            dst[x]                 = av_clip_uint8(p0 + 128);
            dst[x + 1]             = av_clip_uint8(p1 + 128);
            dst[dst_pitch + x]     = av_clip_uint8(p2 + 128);
            dst[dst_pitch + x + 1] = av_clip_uint8(p3 + 128);
        }// for x

        dst += dst_pitch << 1;

        b0_ptr += pitch;
        b1_ptr += pitch;
        b2_ptr += pitch;
        b3_ptr += pitch;
    }// for y
}

void ff_ivi_inverse_haar_8x8(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                             const uint8_t *flags)
{
    int     i, shift, sp1, sp2, sp3, sp4;
    const int32_t *src;
    int32_t *dst;
    int     tmp[64];
    int     t0, t1, t2, t3, t4, t5, t6, t7, t8;

    /* apply the InvHaar8 to all columns */
#define COMPENSATE(x) (x)
    src = in;
    dst = tmp;
    for (i = 0; i < 8; i++) {
        if (flags[i]) {
            /* pre-scaling */
            shift = !(i & 4);
            sp1 = src[ 0] * (1 << shift);
            sp2 = src[ 8] * (1 << shift);
            sp3 = src[16] * (1 << shift);
            sp4 = src[24] * (1 << shift);
            INV_HAAR8(    sp1,     sp2,     sp3,     sp4,
                      src[32], src[40], src[48], src[56],
                      dst[ 0], dst[ 8], dst[16], dst[24],
                      dst[32], dst[40], dst[48], dst[56],
                      t0, t1, t2, t3, t4, t5, t6, t7, t8);
        } else
            dst[ 0] = dst[ 8] = dst[16] = dst[24] =
            dst[32] = dst[40] = dst[48] = dst[56] = 0;

        src++;
        dst++;
    }
#undef  COMPENSATE

    /* apply the InvHaar8 to all rows */
#define COMPENSATE(x) (x)
    src = tmp;
    for (i = 0; i < 8; i++) {
        if (   !src[0] && !src[1] && !src[2] && !src[3]
            && !src[4] && !src[5] && !src[6] && !src[7]) {
            memset(out, 0, 8 * sizeof(out[0]));
        } else {
            INV_HAAR8(src[0], src[1], src[2], src[3],
                      src[4], src[5], src[6], src[7],
                      out[0], out[1], out[2], out[3],
                      out[4], out[5], out[6], out[7],
                      t0, t1, t2, t3, t4, t5, t6, t7, t8);
        }
        src += 8;
        out += pitch;
    }
#undef  COMPENSATE
}

void ff_ivi_row_haar8(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                      const uint8_t *flags)
{
    int     i;
    int     t0, t1, t2, t3, t4, t5, t6, t7, t8;

    /* apply the InvHaar8 to all rows */
#define COMPENSATE(x) (x)
    for (i = 0; i < 8; i++) {
        if (   !in[0] && !in[1] && !in[2] && !in[3]
            && !in[4] && !in[5] && !in[6] && !in[7]) {
            memset(out, 0, 8 * sizeof(out[0]));
        } else {
            INV_HAAR8(in[0],  in[1],  in[2],  in[3],
                      in[4],  in[5],  in[6],  in[7],
                      out[0], out[1], out[2], out[3],
                      out[4], out[5], out[6], out[7],
                      t0, t1, t2, t3, t4, t5, t6, t7, t8);
        }
        in  += 8;
        out += pitch;
    }
#undef  COMPENSATE
}

void ff_ivi_col_haar8(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                      const uint8_t *flags)
{
    int     i;
    int     t0, t1, t2, t3, t4, t5, t6, t7, t8;

    /* apply the InvHaar8 to all columns */
#define COMPENSATE(x) (x)
    for (i = 0; i < 8; i++) {
        if (flags[i]) {
            INV_HAAR8(in[ 0], in[ 8], in[16], in[24],
                      in[32], in[40], in[48], in[56],
                      out[0 * pitch], out[1 * pitch],
                      out[2 * pitch], out[3 * pitch],
                      out[4 * pitch], out[5 * pitch],
                      out[6 * pitch], out[7 * pitch],
                      t0, t1, t2, t3, t4, t5, t6, t7, t8);
        } else
            out[0 * pitch] = out[1 * pitch] =
            out[2 * pitch] = out[3 * pitch] =
            out[4 * pitch] = out[5 * pitch] =
            out[6 * pitch] = out[7 * pitch] = 0;

        in++;
        out++;
    }
#undef  COMPENSATE
}

void ff_ivi_inverse_haar_4x4(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                             const uint8_t *flags)
{
    int     i, shift, sp1, sp2;
    const int32_t *src;
    int32_t *dst;
    int     tmp[16];
    int     t0, t1, t2, t3, t4;

    /* apply the InvHaar4 to all columns */
#define COMPENSATE(x) (x)
    src = in;
    dst = tmp;
    for (i = 0; i < 4; i++) {
        if (flags[i]) {
            /* pre-scaling */
            shift = !(i & 2);
            sp1 = src[0] * (1 << shift);
            sp2 = src[4] * (1 << shift);
            INV_HAAR4(   sp1,    sp2, src[8], src[12],
                      dst[0], dst[4], dst[8], dst[12],
                      t0, t1, t2, t3, t4);
        } else
            dst[0] = dst[4] = dst[8] = dst[12] = 0;

        src++;
        dst++;
    }
#undef  COMPENSATE

    /* apply the InvHaar8 to all rows */
#define COMPENSATE(x) (x)
    src = tmp;
    for (i = 0; i < 4; i++) {
        if (!src[0] && !src[1] && !src[2] && !src[3]) {
            memset(out, 0, 4 * sizeof(out[0]));
        } else {
            INV_HAAR4(src[0], src[1], src[2], src[3],
                      out[0], out[1], out[2], out[3],
                      t0, t1, t2, t3, t4);
        }
        src += 4;
        out += pitch;
    }
#undef  COMPENSATE
}

void ff_ivi_row_haar4(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                      const uint8_t *flags)
{
    int     i;
    int     t0, t1, t2, t3, t4;

    /* apply the InvHaar4 to all rows */
#define COMPENSATE(x) (x)
    for (i = 0; i < 4; i++) {
        if (!in[0] && !in[1] && !in[2] && !in[3]) {
            memset(out, 0, 4 * sizeof(out[0]));
        } else {
            INV_HAAR4(in[0], in[1], in[2], in[3],
                      out[0], out[1], out[2], out[3],
                      t0, t1, t2, t3, t4);
        }
        in  += 4;
        out += pitch;
    }
#undef  COMPENSATE
}

void ff_ivi_col_haar4(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                      const uint8_t *flags)
{
    int     i;
    int     t0, t1, t2, t3, t4;

    /* apply the InvHaar8 to all columns */
#define COMPENSATE(x) (x)
    for (i = 0; i < 4; i++) {
        if (flags[i]) {
            INV_HAAR4(in[0], in[4], in[8], in[12],
                      out[0 * pitch], out[1 * pitch],
                      out[2 * pitch], out[3 * pitch],
                      t0, t1, t2, t3, t4);
        } else
            out[0 * pitch] = out[1 * pitch] =
            out[2 * pitch] = out[3 * pitch] = 0;

        in++;
        out++;
    }
#undef  COMPENSATE
}

void ff_ivi_dc_haar_2d(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                       int blk_size)
{
    int     x, y;
    int16_t dc_coeff;

    dc_coeff = (*in + 0) >> 3;

    for (y = 0; y < blk_size; out += pitch, y++) {
        for (x = 0; x < blk_size; x++)
            out[x] = dc_coeff;
    }
}

void ff_ivi_inverse_slant_8x8(const int32_t *in, int16_t *out, ptrdiff_t pitch, const uint8_t *flags)
{
    int     i;
    const int32_t *src;
    int32_t *dst;
    int     tmp[64];
    int     t0, t1, t2, t3, t4, t5, t6, t7, t8;

#define COMPENSATE(x) (x)
    src = in;
    dst = tmp;
    for (i = 0; i < 8; i++) {
        if (flags[i]) {
            IVI_INV_SLANT8(src[0], src[8], src[16], src[24], src[32], src[40], src[48], src[56],
                           dst[0], dst[8], dst[16], dst[24], dst[32], dst[40], dst[48], dst[56],
                           t0, t1, t2, t3, t4, t5, t6, t7, t8);
        } else
            dst[0] = dst[8] = dst[16] = dst[24] = dst[32] = dst[40] = dst[48] = dst[56] = 0;

        src++;
        dst++;
    }
#undef COMPENSATE

#define COMPENSATE(x) (((x) + 1)>>1)
    src = tmp;
    for (i = 0; i < 8; i++) {
        if (!src[0] && !src[1] && !src[2] && !src[3] && !src[4] && !src[5] && !src[6] && !src[7]) {
            memset(out, 0, 8*sizeof(out[0]));
        } else {
            IVI_INV_SLANT8(src[0], src[1], src[2], src[3], src[4], src[5], src[6], src[7],
                           out[0], out[1], out[2], out[3], out[4], out[5], out[6], out[7],
                           t0, t1, t2, t3, t4, t5, t6, t7, t8);
        }
        src += 8;
        out += pitch;
    }
#undef COMPENSATE
}

void ff_ivi_inverse_slant_4x4(const int32_t *in, int16_t *out, ptrdiff_t pitch, const uint8_t *flags)
{
    int     i;
    const int32_t *src;
    int32_t *dst;
    int     tmp[16];
    int     t0, t1, t2, t3, t4;

#define COMPENSATE(x) (x)
    src = in;
    dst = tmp;
    for (i = 0; i < 4; i++) {
        if (flags[i]) {
            IVI_INV_SLANT4(src[0], src[4], src[8], src[12],
                           dst[0], dst[4], dst[8], dst[12],
                           t0, t1, t2, t3, t4);
        } else
            dst[0] = dst[4] = dst[8] = dst[12] = 0;

        src++;
        dst++;
    }
#undef COMPENSATE

#define COMPENSATE(x) (((x) + 1)>>1)
    src = tmp;
    for (i = 0; i < 4; i++) {
        if (!src[0] && !src[1] && !src[2] && !src[3]) {
            out[0] = out[1] = out[2] = out[3] = 0;
        } else {
            IVI_INV_SLANT4(src[0], src[1], src[2], src[3],
                           out[0], out[1], out[2], out[3],
                           t0, t1, t2, t3, t4);
        }
        src += 4;
        out += pitch;
    }
#undef COMPENSATE
}

void ff_ivi_dc_slant_2d(const int32_t *in, int16_t *out, ptrdiff_t pitch, int blk_size)
{
    int     x, y;
    int16_t dc_coeff;

    dc_coeff = (*in + 1) >> 1;

    for (y = 0; y < blk_size; out += pitch, y++) {
        for (x = 0; x < blk_size; x++)
            out[x] = dc_coeff;
    }
}

void ff_ivi_row_slant8(const int32_t *in, int16_t *out, ptrdiff_t pitch, const uint8_t *flags)
{
    int     i;
    int     t0, t1, t2, t3, t4, t5, t6, t7, t8;

#define COMPENSATE(x) (((x) + 1)>>1)
    for (i = 0; i < 8; i++) {
        if (!in[0] && !in[1] && !in[2] && !in[3] && !in[4] && !in[5] && !in[6] && !in[7]) {
            memset(out, 0, 8*sizeof(out[0]));
        } else {
            IVI_INV_SLANT8( in[0],  in[1],  in[2],  in[3],  in[4],  in[5],  in[6],  in[7],
                           out[0], out[1], out[2], out[3], out[4], out[5], out[6], out[7],
                           t0, t1, t2, t3, t4, t5, t6, t7, t8);
        }
        in += 8;
        out += pitch;
    }
#undef COMPENSATE
}

void ff_ivi_dc_row_slant(const int32_t *in, int16_t *out, ptrdiff_t pitch, int blk_size)
{
    int     x, y;
    int16_t dc_coeff;

    dc_coeff = (*in + 1) >> 1;

    for (x = 0; x < blk_size; x++)
        out[x] = dc_coeff;

    out += pitch;

    for (y = 1; y < blk_size; out += pitch, y++) {
        for (x = 0; x < blk_size; x++)
            out[x] = 0;
    }
}

void ff_ivi_col_slant8(const int32_t *in, int16_t *out, ptrdiff_t pitch, const uint8_t *flags)
{
    int     i, row2, row4, row8;
    int     t0, t1, t2, t3, t4, t5, t6, t7, t8;

    row2 = pitch << 1;
    row4 = pitch << 2;
    row8 = pitch << 3;

#define COMPENSATE(x) (((x) + 1)>>1)
    for (i = 0; i < 8; i++) {
        if (flags[i]) {
            IVI_INV_SLANT8(in[0], in[8], in[16], in[24], in[32], in[40], in[48], in[56],
                           out[0], out[pitch], out[row2], out[row2 + pitch], out[row4],
                           out[row4 + pitch],  out[row4 + row2], out[row8 - pitch],
                           t0, t1, t2, t3, t4, t5, t6, t7, t8);
        } else {
            out[0] = out[pitch] = out[row2] = out[row2 + pitch] = out[row4] =
            out[row4 + pitch] =  out[row4 + row2] = out[row8 - pitch] = 0;
        }

        in++;
        out++;
    }
#undef COMPENSATE
}

void ff_ivi_dc_col_slant(const int32_t *in, int16_t *out, ptrdiff_t pitch, int blk_size)
{
    int     x, y;
    int16_t dc_coeff;

    dc_coeff = (*in + 1) >> 1;

    for (y = 0; y < blk_size; out += pitch, y++) {
        out[0] = dc_coeff;
        for (x = 1; x < blk_size; x++)
            out[x] = 0;
    }
}

void ff_ivi_row_slant4(const int32_t *in, int16_t *out, ptrdiff_t pitch, const uint8_t *flags)
{
    int     i;
    int     t0, t1, t2, t3, t4;

#define COMPENSATE(x) (((x) + 1)>>1)
    for (i = 0; i < 4; i++) {
        if (!in[0] && !in[1] && !in[2] && !in[3]) {
            memset(out, 0, 4*sizeof(out[0]));
        } else {
            IVI_INV_SLANT4( in[0],  in[1],  in[2],  in[3],
                           out[0], out[1], out[2], out[3],
                           t0, t1, t2, t3, t4);
        }
        in  += 4;
        out += pitch;
    }
#undef COMPENSATE
}

void ff_ivi_col_slant4(const int32_t *in, int16_t *out, ptrdiff_t pitch, const uint8_t *flags)
{
    int     i, row2;
    int     t0, t1, t2, t3, t4;

    row2 = pitch << 1;

#define COMPENSATE(x) (((x) + 1)>>1)
    for (i = 0; i < 4; i++) {
        if (flags[i]) {
            IVI_INV_SLANT4(in[0], in[4], in[8], in[12],
                           out[0], out[pitch], out[row2], out[row2 + pitch],
                           t0, t1, t2, t3, t4);
        } else {
            out[0] = out[pitch] = out[row2] = out[row2 + pitch] = 0;
        }

        in++;
        out++;
    }
#undef COMPENSATE
}

void ff_ivi_put_pixels_8x8(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                           const uint8_t *flags)
{
    int     x, y;

    for (y = 0; y < 8; out += pitch, in += 8, y++)
        for (x = 0; x < 8; x++)
            out[x] = in[x];
}

void ff_ivi_put_dc_pixel_8x8(const int32_t *in, int16_t *out, ptrdiff_t pitch,
                             int blk_size)
{
    int     y;

    out[0] = in[0];
    memset(out + 1, 0, 7*sizeof(out[0]));
    out += pitch;

    for (y = 1; y < 8; out += pitch, y++)
        memset(out, 0, 8*sizeof(out[0]));
}

