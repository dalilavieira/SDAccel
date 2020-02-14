#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_89__   TYPE_7__ ;
typedef  struct TYPE_88__   TYPE_6__ ;
typedef  struct TYPE_87__   TYPE_5__ ;
typedef  struct TYPE_86__   TYPE_4__ ;
typedef  struct TYPE_85__   TYPE_3__ ;
typedef  struct TYPE_84__   TYPE_2__ ;
typedef  struct TYPE_83__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  size_t ptrdiff_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int VLC_TYPE ;
struct TYPE_89__ {int (* get_model_sym ) (TYPE_7__*,TYPE_4__*) ;int (* get_number ) (TYPE_7__*,int) ;} ;
struct TYPE_88__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
struct TYPE_87__ {unsigned int* last_rgb_pic; unsigned int* rgb_pic; int rgb_stride; unsigned int* pal_pic; int pal_stride; unsigned int* last_pal_pic; scalar_t__ mvX; scalar_t__ mvY; int* pal; unsigned int* mask; size_t mask_stride; int /*<<< orphan*/  keyframe; TYPE_1__* avctx; } ;
struct TYPE_86__ {int* weights; size_t num_syms; int* cum_prob; int* idx2sym; scalar_t__ thr_weight; int threshold; } ;
struct TYPE_85__ {int cache_size; int* cache; TYPE_4__** sec_models; TYPE_4__ full_model; TYPE_4__ cache_model; int /*<<< orphan*/  special_initial_cache; } ;
struct TYPE_84__ {TYPE_5__* c; TYPE_4__ split_mode; TYPE_3__ intra_pix_ctx; TYPE_3__ inter_pix_ctx; TYPE_4__ inter_region; TYPE_4__ intra_region; TYPE_4__ pivot; TYPE_4__ edge_mode; } ;
struct TYPE_83__ {scalar_t__ width; scalar_t__ height; int err_recognition; } ;
typedef  TYPE_2__ SliceContext ;
typedef  TYPE_3__ PixContext ;
typedef  TYPE_4__ Model ;
typedef  TYPE_5__ MSS12Context ;
typedef  TYPE_6__ GetBitContext ;
typedef  TYPE_7__ ArithCoder ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AV_EF_EXPLODE ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  AV_WB24 (unsigned int*,int const) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int FFMAX (int,int) ; 
 int FFMIN (int,int) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_6__*,int) ; 
 size_t LEFT ; 
 int MIN_CACHE_BITS ; 
 int NEG_USR32 (int,int) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_6__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_6__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_6__*,int) ; 
#define  SPLIT_HOR 130 
#define  SPLIT_NONE 129 
#define  SPLIT_VERT 128 
 scalar_t__ THRESH_ADAPTIVE ; 
 size_t TOP ; 
 size_t TOP_LEFT ; 
 size_t TOP_RIGHT ; 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int /*<<< orphan*/  av_log (void*,int /*<<< orphan*/ ,char*,int,int,char const*) ; 
 int decode_pixel (TYPE_7__*,TYPE_3__*,unsigned int*,int,int) ; 
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned int*,int) ; 
 int /*<<< orphan*/  memmove (unsigned int*,unsigned int*,int) ; 
 int /*<<< orphan*/  memset (unsigned int*,int,int) ; 
 int /*<<< orphan*/  re ; 
 int sign_extend (int,int) ; 
 int stub1 (TYPE_7__*,TYPE_4__*) ; 
 int stub2 (TYPE_7__*,TYPE_4__*) ; 
 int stub3 (TYPE_7__*,TYPE_4__*) ; 
 int stub4 (TYPE_7__*,int) ; 
 int stub5 (TYPE_7__*,TYPE_4__*) ; 
 int stub6 (TYPE_7__*,TYPE_4__*) ; 
 int stub7 (TYPE_7__*,TYPE_4__*) ; 
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

__attribute__((used)) static int model_calc_threshold(Model *m)
{
    int thr;

    thr = 2 * m->weights[m->num_syms] - 1;
    thr = ((thr >> 1) + 4 * m->cum_prob[0]) / thr;

    return FFMIN(thr, 0x3FFF);
}

__attribute__((used)) static void model_reset(Model *m)
{
    int i;

    for (i = 0; i <= m->num_syms; i++) {
        m->weights[i]  = 1;
        m->cum_prob[i] = m->num_syms - i;
    }
    m->weights[0] = 0;
    for (i = 0; i < m->num_syms; i++)
        m->idx2sym[i + 1] = i;
}

__attribute__((used)) static void model_rescale_weights(Model *m)
{
    int i;
    int cum_prob;

    if (m->thr_weight == THRESH_ADAPTIVE)
        m->threshold = model_calc_threshold(m);
    while (m->cum_prob[0] > m->threshold) {
        cum_prob = 0;
        for (i = m->num_syms; i >= 0; i--) {
            m->cum_prob[i] = cum_prob;
            m->weights[i]  = (m->weights[i] + 1) >> 1;
            cum_prob      += m->weights[i];
        }
    }
}

void ff_mss12_model_update(Model *m, int val)
{
    int i;

    if (m->weights[val] == m->weights[val - 1]) {
        for (i = val; m->weights[i - 1] == m->weights[val]; i--);
        if (i != val) {
            int sym1, sym2;

            sym1 = m->idx2sym[val];
            sym2 = m->idx2sym[i];

            m->idx2sym[val]  = sym2;
            m->idx2sym[i]    = sym1;

            val = i;
        }
    }
    m->weights[val]++;
    for (i = val - 1; i >= 0; i--)
        m->cum_prob[i]++;
    model_rescale_weights(m);
}

__attribute__((used)) static void pixctx_reset(PixContext *ctx)
{
    int i, j;

    if (!ctx->special_initial_cache)
        for (i = 0; i < ctx->cache_size; i++)
            ctx->cache[i] = i;
    else {
        ctx->cache[0] = 1;
        ctx->cache[1] = 2;
        ctx->cache[2] = 4;
    }

    model_reset(&ctx->cache_model);
    model_reset(&ctx->full_model);

    for (i = 0; i < 15; i++)
        for (j = 0; j < 4; j++)
            model_reset(&ctx->sec_models[i][j]);
}

__attribute__((used)) static int decode_pixel_in_context(ArithCoder *acoder, PixContext *pctx,
                                   uint8_t *src, ptrdiff_t stride, int x, int y,
                                   int has_right)
{
    uint8_t neighbours[4];
    uint8_t ref_pix[4];
    int nlen;
    int layer = 0, sub;
    int pix;
    int i, j;

    if (!y) {
        memset(neighbours, src[-1], 4);
    } else {
        neighbours[TOP] = src[-stride];
        if (!x) {
            neighbours[TOP_LEFT] = neighbours[LEFT] = neighbours[TOP];
        } else {
            neighbours[TOP_LEFT] = src[-stride - 1];
            neighbours[    LEFT] = src[-1];
        }
        if (has_right)
            neighbours[TOP_RIGHT] = src[-stride + 1];
        else
            neighbours[TOP_RIGHT] = neighbours[TOP];
    }

    sub = 0;
    if (x >= 2 && src[-2] == neighbours[LEFT])
        sub  = 1;
    if (y >= 2 && src[-2 * stride] == neighbours[TOP])
        sub |= 2;

    nlen = 1;
    ref_pix[0] = neighbours[0];
    for (i = 1; i < 4; i++) {
        for (j = 0; j < nlen; j++)
            if (ref_pix[j] == neighbours[i])
                break;
        if (j == nlen)
            ref_pix[nlen++] = neighbours[i];
    }

    switch (nlen) {
    case 1:
        layer = 0;
        break;
    case 2:
        if (neighbours[TOP] == neighbours[TOP_LEFT]) {
            if (neighbours[TOP_RIGHT] == neighbours[TOP_LEFT])
                layer = 1;
            else if (neighbours[LEFT] == neighbours[TOP_LEFT])
                layer = 2;
            else
                layer = 3;
        } else if (neighbours[TOP_RIGHT] == neighbours[TOP_LEFT]) {
            if (neighbours[LEFT] == neighbours[TOP_LEFT])
                layer = 4;
            else
                layer = 5;
        } else if (neighbours[LEFT] == neighbours[TOP_LEFT]) {
            layer = 6;
        } else {
            layer = 7;
        }
        break;
    case 3:
        if (neighbours[TOP] == neighbours[TOP_LEFT])
            layer = 8;
        else if (neighbours[TOP_RIGHT] == neighbours[TOP_LEFT])
            layer = 9;
        else if (neighbours[LEFT] == neighbours[TOP_LEFT])
            layer = 10;
        else if (neighbours[TOP_RIGHT] == neighbours[TOP])
            layer = 11;
        else if (neighbours[TOP] == neighbours[LEFT])
            layer = 12;
        else
            layer = 13;
        break;
    case 4:
        layer = 14;
        break;
    }

    pix = acoder->get_model_sym(acoder,
                                &pctx->sec_models[layer][sub]);
    if (pix < nlen)
        return ref_pix[pix];
    else
        return decode_pixel(acoder, pctx, ref_pix, nlen, 1);
}

__attribute__((used)) static int decode_region(ArithCoder *acoder, uint8_t *dst, uint8_t *rgb_pic,
                         int x, int y, int width, int height, ptrdiff_t stride,
                         ptrdiff_t rgb_stride, PixContext *pctx,
                         const uint32_t *pal)
{
    int i, j, p;
    uint8_t *rgb_dst = rgb_pic + x * 3 + y * rgb_stride;

    dst += x + y * stride;

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            if (!i && !j)
                p = decode_pixel(acoder, pctx, NULL, 0, 0);
            else
                p = decode_pixel_in_context(acoder, pctx, dst + i, stride,
                                            i, j, width - i - 1);
            dst[i] = p;

            if (rgb_pic)
                AV_WB24(rgb_dst + i * 3, pal[p]);
        }
        dst     += stride;
        rgb_dst += rgb_stride;
    }

    return 0;
}

__attribute__((used)) static void copy_rectangles(MSS12Context const *c,
                            int x, int y, int width, int height)
{
    int j;

    if (c->last_rgb_pic)
        for (j = y; j < y + height; j++) {
            memcpy(c->rgb_pic      + j * c->rgb_stride + x * 3,
                   c->last_rgb_pic + j * c->rgb_stride + x * 3,
                   width * 3);
            memcpy(c->pal_pic      + j * c->pal_stride + x,
                   c->last_pal_pic + j * c->pal_stride + x,
                   width);
        }
}

__attribute__((used)) static int motion_compensation(MSS12Context const *c,
                               int x, int y, int width, int height)
{
    if (x + c->mvX < 0 || x + c->mvX + width  > c->avctx->width  ||
        y + c->mvY < 0 || y + c->mvY + height > c->avctx->height ||
        !c->rgb_pic)
        return -1;
    else {
        uint8_t *dst     = c->pal_pic + x     + y * c->pal_stride;
        uint8_t *rgb_dst = c->rgb_pic + x * 3 + y * c->rgb_stride;
        uint8_t *src;
        uint8_t *rgb_src;
        int j;
        x += c->mvX;
        y += c->mvY;
        if (c->last_rgb_pic) {
            src     = c->last_pal_pic + x +     y * c->pal_stride;
            rgb_src = c->last_rgb_pic + x * 3 + y * c->rgb_stride;
        } else {
            src     = c->pal_pic + x     + y * c->pal_stride;
            rgb_src = c->rgb_pic + x * 3 + y * c->rgb_stride;
        }
        for (j = 0; j < height; j++) {
            memmove(dst, src, width);
            memmove(rgb_dst, rgb_src, width * 3);
            dst     += c->pal_stride;
            src     += c->pal_stride;
            rgb_dst += c->rgb_stride;
            rgb_src += c->rgb_stride;
        }
    }
    return 0;
}

__attribute__((used)) static int decode_region_masked(MSS12Context const *c, ArithCoder *acoder,
                                uint8_t *dst, ptrdiff_t stride, uint8_t *mask,
                                ptrdiff_t mask_stride, int x, int y,
                                int width, int height,
                                PixContext *pctx)
{
    int i, j, p;
    uint8_t *rgb_dst = c->rgb_pic + x * 3 + y * c->rgb_stride;

    dst  += x + y * stride;
    mask += x + y * mask_stride;

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            if (c->avctx->err_recognition & AV_EF_EXPLODE &&
                ( c->rgb_pic && mask[i] != 0x01 && mask[i] != 0x02 && mask[i] != 0x04 ||
                 !c->rgb_pic && mask[i] != 0x80 && mask[i] != 0xFF))
                return -1;

            if (mask[i] == 0x02) {
                copy_rectangles(c, x + i, y + j, 1, 1);
            } else if (mask[i] == 0x04) {
                if (motion_compensation(c, x + i, y + j, 1, 1))
                    return -1;
            } else if (mask[i] != 0x80) {
                if (!i && !j)
                    p = decode_pixel(acoder, pctx, NULL, 0, 0);
                else
                    p = decode_pixel_in_context(acoder, pctx, dst + i, stride,
                                                i, j, width - i - 1);
                dst[i] = p;
                if (c->rgb_pic)
                    AV_WB24(rgb_dst + i * 3, c->pal[p]);
            }
        }
        dst     += stride;
        mask    += mask_stride;
        rgb_dst += c->rgb_stride;
    }

    return 0;
}

void ff_mss12_slicecontext_reset(SliceContext *sc)
{
    model_reset(&sc->intra_region);
    model_reset(&sc->inter_region);
    model_reset(&sc->split_mode);
    model_reset(&sc->edge_mode);
    model_reset(&sc->pivot);
    pixctx_reset(&sc->intra_pix_ctx);
    pixctx_reset(&sc->inter_pix_ctx);
}

__attribute__((used)) static int decode_pivot(SliceContext *sc, ArithCoder *acoder, int base)
{
    int val, inv;

    inv = acoder->get_model_sym(acoder, &sc->edge_mode);
    val = acoder->get_model_sym(acoder, &sc->pivot) + 1;

    if (val > 2) {
        if ((base + 1) / 2 - 2 <= 0)
            return -1;

        val = acoder->get_number(acoder, (base + 1) / 2 - 2) + 3;
    }

    if ((unsigned)val >= base)
        return -1;

    return inv ? base - val : val;
}

__attribute__((used)) static int decode_region_intra(SliceContext *sc, ArithCoder *acoder,
                               int x, int y, int width, int height)
{
    MSS12Context const *c = sc->c;
    int mode;

    mode = acoder->get_model_sym(acoder, &sc->intra_region);

    if (!mode) {
        int i, j, pix, rgb_pix;
        ptrdiff_t stride     = c->pal_stride;
        ptrdiff_t rgb_stride = c->rgb_stride;
        uint8_t *dst     = c->pal_pic + x     + y * stride;
        uint8_t *rgb_dst = c->rgb_pic + x * 3 + y * rgb_stride;

        pix     = decode_pixel(acoder, &sc->intra_pix_ctx, NULL, 0, 0);
        rgb_pix = c->pal[pix];
        for (i = 0; i < height; i++, dst += stride, rgb_dst += rgb_stride) {
            memset(dst, pix, width);
            if (c->rgb_pic)
                for (j = 0; j < width * 3; j += 3)
                    AV_WB24(rgb_dst + j, rgb_pix);
        }
    } else {
        return decode_region(acoder, c->pal_pic, c->rgb_pic,
                             x, y, width, height, c->pal_stride, c->rgb_stride,
                             &sc->intra_pix_ctx, &c->pal[0]);
    }

    return 0;
}

__attribute__((used)) static int decode_region_inter(SliceContext *sc, ArithCoder *acoder,
                               int x, int y, int width, int height)
{
    MSS12Context const *c = sc->c;
    int mode;

    mode = acoder->get_model_sym(acoder, &sc->inter_region);

    if (!mode) {
        mode = decode_pixel(acoder, &sc->inter_pix_ctx, NULL, 0, 0);

        if (c->avctx->err_recognition & AV_EF_EXPLODE &&
            ( c->rgb_pic && mode != 0x01 && mode != 0x02 && mode != 0x04 ||
             !c->rgb_pic && mode != 0x80 && mode != 0xFF))
            return -1;

        if (mode == 0x02)
            copy_rectangles(c, x, y, width, height);
        else if (mode == 0x04)
            return motion_compensation(c, x, y, width, height);
        else if (mode != 0x80)
            return decode_region_intra(sc, acoder, x, y, width, height);
    } else {
        if (decode_region(acoder, c->mask, NULL,
                          x, y, width, height, c->mask_stride, 0,
                          &sc->inter_pix_ctx, &c->pal[0]) < 0)
            return -1;
        return decode_region_masked(c, acoder, c->pal_pic,
                                    c->pal_stride, c->mask,
                                    c->mask_stride,
                                    x, y, width, height,
                                    &sc->intra_pix_ctx);
    }

    return 0;
}

int ff_mss12_decode_rect(SliceContext *sc, ArithCoder *acoder,
                         int x, int y, int width, int height)
{
    int mode, pivot;

    mode = acoder->get_model_sym(acoder, &sc->split_mode);

    switch (mode) {
    case SPLIT_VERT:
        if ((pivot = decode_pivot(sc, acoder, height)) < 1)
            return -1;
        if (ff_mss12_decode_rect(sc, acoder, x, y, width, pivot))
            return -1;
        if (ff_mss12_decode_rect(sc, acoder, x, y + pivot, width, height - pivot))
            return -1;
        break;
    case SPLIT_HOR:
        if ((pivot = decode_pivot(sc, acoder, width)) < 1)
            return -1;
        if (ff_mss12_decode_rect(sc, acoder, x, y, pivot, height))
            return -1;
        if (ff_mss12_decode_rect(sc, acoder, x + pivot, y, width - pivot, height))
            return -1;
        break;
    case SPLIT_NONE:
        if (sc->c->keyframe)
            return decode_region_intra(sc, acoder, x, y, width, height);
        else
            return decode_region_inter(sc, acoder, x, y, width, height);
    default:
        return -1;
    }

    return 0;
}

