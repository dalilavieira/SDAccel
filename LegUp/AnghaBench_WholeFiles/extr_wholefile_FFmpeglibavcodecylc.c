#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_69__   TYPE_9__ ;
typedef  struct TYPE_68__   TYPE_8__ ;
typedef  struct TYPE_67__   TYPE_7__ ;
typedef  struct TYPE_66__   TYPE_6__ ;
typedef  struct TYPE_65__   TYPE_5__ ;
typedef  struct TYPE_64__   TYPE_4__ ;
typedef  struct TYPE_63__   TYPE_3__ ;
typedef  struct TYPE_62__   TYPE_2__ ;
typedef  struct TYPE_61__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  unsigned long long uint32_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  unsigned long long int16_t ;
struct TYPE_61__ {int /*<<< orphan*/  (* bswap_buf ) (unsigned long long*,unsigned long long*,int) ;} ;
struct TYPE_62__ {unsigned int* table_bits; unsigned long long* table; unsigned int* bitstream_bits; TYPE_3__* vlc; TYPE_1__ bdsp; int /*<<< orphan*/  bitstream_bits_size; int /*<<< orphan*/  table_bits_size; } ;
typedef  TYPE_2__ YLCContext ;
typedef  int VLC_TYPE ;
struct TYPE_63__ {int /*<<< orphan*/  bits; int /*<<< orphan*/  table; } ;
typedef  TYPE_3__ VLC ;
struct TYPE_64__ {void* f; } ;
typedef  TYPE_4__ ThreadFrame ;
struct TYPE_69__ {int height; int width; TYPE_2__* priv_data; } ;
struct TYPE_68__ {unsigned int** data; int* linesize; int key_frame; int /*<<< orphan*/  pict_type; } ;
struct TYPE_67__ {unsigned int* data; int size; } ;
struct TYPE_66__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
struct TYPE_65__ {int sym; int l; int r; unsigned long long count; int n0; } ;
typedef  TYPE_5__ Node ;
typedef  TYPE_6__ GetBitContext ;
typedef  TYPE_7__ AVPacket ;
typedef  TYPE_8__ AVFrame ;
typedef  TYPE_9__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int AV_RL32 (unsigned int const*) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  ENOMEM ; 
 unsigned long long FFMAX (int,int) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_6__*,int) ; 
 int MIN_CACHE_BITS ; 
 int MKTAG (char,char,char,int /*<<< orphan*/ ) ; 
 int NEG_USR32 (int,int) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_6__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_6__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_6__*,int) ; 
 unsigned int UINT32_MAX ; 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int /*<<< orphan*/  av_fast_malloc (unsigned int**,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  av_log (TYPE_9__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  ff_free_vlc (TYPE_3__*) ; 
 int ff_init_vlc_sparse (TYPE_3__*,int,int,unsigned long long*,int,int,unsigned long long*,int,int,unsigned int*,int,int,int /*<<< orphan*/ ) ; 
 int ff_thread_get_buffer (TYPE_9__*,TYPE_4__*,int /*<<< orphan*/ ) ; 
 int get_vlc2 (TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned int*,int) ; 
 int /*<<< orphan*/  memset (unsigned int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  re ; 
 int sign_extend (int,int) ; 
 int /*<<< orphan*/  stub1 (unsigned long long*,unsigned long long*,int) ; 
 int /*<<< orphan*/  stub2 (unsigned long long*,unsigned long long*,int) ; 
 unsigned int* table_u ; 
 unsigned int* table_v ; 
 unsigned int* table_y1 ; 
 unsigned int* table_y2 ; 
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

__attribute__((used)) static inline int get_unary(GetBitContext *gb, int stop, int len)
{
    int i;

    for(i = 0; i < len && get_bits1(gb) != stop; i++);
    return i;
}

__attribute__((used)) static inline int get_unary_0_33(GetBitContext *gb)
{
    return get_unary(gb, 0, 33);
}

__attribute__((used)) static inline int get_unary_0_9(GetBitContext *gb)
{
    return get_unary(gb, 0, 9);
}

__attribute__((used)) static void get_tree_codes(uint32_t *bits, int16_t *lens, uint8_t *xlat,
                           Node *nodes, int node,
                           uint32_t pfx, int pl, int *pos)
{
    int s;

    s = nodes[node].sym;
    if (s != -1) {
        bits[*pos] = (~pfx) & ((1ULL << FFMAX(pl, 1)) - 1);
        lens[*pos] = FFMAX(pl, 1);
        xlat[*pos] = s + (pl == 0);
        (*pos)++;
    } else {
        pfx <<= 1;
        pl++;
        get_tree_codes(bits, lens, xlat, nodes, nodes[node].l, pfx, pl,
                       pos);
        pfx |= 1;
        get_tree_codes(bits, lens, xlat, nodes, nodes[node].r, pfx, pl,
                       pos);
    }
}

__attribute__((used)) static int build_vlc(AVCodecContext *avctx, VLC *vlc, const uint32_t *table)
{
    Node nodes[512];
    uint32_t bits[256];
    int16_t lens[256];
    uint8_t xlat[256];
    int cur_node, i, j, pos = 0;

    ff_free_vlc(vlc);

    for (i = 0; i < 256; i++) {
        nodes[i].count = table[i];
        nodes[i].sym   = i;
        nodes[i].n0    = -2;
        nodes[i].l     = i;
        nodes[i].r     = i;
    }

    cur_node = 256;
    j = 0;
    do {
        for (i = 0; ; i++) {
            int new_node = j;
            int first_node = cur_node;
            int second_node = cur_node;
            unsigned nd, st;

            nodes[cur_node].count = -1;

            do {
                int val = nodes[new_node].count;
                if (val && (val < nodes[first_node].count)) {
                    if (val >= nodes[second_node].count) {
                        first_node = new_node;
                    } else {
                        first_node = second_node;
                        second_node = new_node;
                    }
                }
                new_node += 1;
            } while (new_node != cur_node);

            if (first_node == cur_node)
                break;

            nd = nodes[second_node].count;
            st = nodes[first_node].count;
            nodes[second_node].count = 0;
            nodes[first_node].count  = 0;
            if (nd >= UINT32_MAX - st) {
                av_log(avctx, AV_LOG_ERROR, "count overflow\n");
                return AVERROR_INVALIDDATA;
            }
            nodes[cur_node].count = nd + st;
            nodes[cur_node].sym = -1;
            nodes[cur_node].n0 = cur_node;
            nodes[cur_node].l = first_node;
            nodes[cur_node].r = second_node;
            cur_node++;
        }
        j++;
    } while (cur_node - 256 == j);

    get_tree_codes(bits, lens, xlat, nodes, cur_node - 1, 0, 0, &pos);

    return ff_init_vlc_sparse(vlc, 10, pos, lens, 2, 2, bits, 4, 4, xlat, 1, 1, 0);
}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx,
                        void *data, int *got_frame,
                        AVPacket *avpkt)
{
    int TL[4] = { 128, 128, 128, 128 };
    int L[4]  = { 128, 128, 128, 128 };
    YLCContext *s = avctx->priv_data;
    ThreadFrame frame = { .f = data };
    const uint8_t *buf = avpkt->data;
    int ret, x, y, toffset, boffset;
    AVFrame * const p = data;
    GetBitContext gb;
    uint8_t *dst;

    if (avpkt->size <= 16)
        return AVERROR_INVALIDDATA;

    if (AV_RL32(buf) != MKTAG('Y', 'L', 'C', '0') ||
        AV_RL32(buf + 4) != 0)
        return AVERROR_INVALIDDATA;

    toffset = AV_RL32(buf + 8);
    if (toffset < 16 || toffset >= avpkt->size)
        return AVERROR_INVALIDDATA;

    boffset = AV_RL32(buf + 12);
    if (toffset >= boffset || boffset >= avpkt->size)
        return AVERROR_INVALIDDATA;

    if ((ret = ff_thread_get_buffer(avctx, &frame, 0)) < 0)
        return ret;

    av_fast_malloc(&s->table_bits, &s->table_bits_size,
                   boffset - toffset + AV_INPUT_BUFFER_PADDING_SIZE);
    if (!s->table_bits)
        return AVERROR(ENOMEM);

    memcpy(s->table_bits, avpkt->data + toffset, boffset - toffset);
    memset(s->table_bits + boffset - toffset, 0, AV_INPUT_BUFFER_PADDING_SIZE);
    s->bdsp.bswap_buf((uint32_t *) s->table_bits,
                      (uint32_t *) s->table_bits,
                      (boffset - toffset + 3) >> 2);
    if ((ret = init_get_bits8(&gb, s->table_bits, boffset - toffset)) < 0)
        return ret;

    for (x = 0; x < 1024; x++) {
        unsigned len = get_unary(&gb, 1, 31);
        uint32_t val = ((1U << len) - 1) + get_bits_long(&gb, len);

        s->table[x] = val;
    }

    ret = build_vlc(avctx, &s->vlc[0], &s->table[0  ]);
    if (ret < 0)
        return ret;
    ret = build_vlc(avctx, &s->vlc[1], &s->table[256]);
    if (ret < 0)
        return ret;
    ret = build_vlc(avctx, &s->vlc[2], &s->table[512]);
    if (ret < 0)
        return ret;
    ret = build_vlc(avctx, &s->vlc[3], &s->table[768]);
    if (ret < 0)
        return ret;

    av_fast_malloc(&s->bitstream_bits, &s->bitstream_bits_size,
                   avpkt->size - boffset + AV_INPUT_BUFFER_PADDING_SIZE);
    if (!s->bitstream_bits)
        return AVERROR(ENOMEM);

    memcpy(s->bitstream_bits, avpkt->data + boffset, avpkt->size - boffset);
    memset(s->bitstream_bits + avpkt->size - boffset, 0, AV_INPUT_BUFFER_PADDING_SIZE);
    s->bdsp.bswap_buf((uint32_t *) s->bitstream_bits,
                      (uint32_t *) s->bitstream_bits,
                      (avpkt->size - boffset) >> 2);
    if ((ret = init_get_bits8(&gb, s->bitstream_bits, avpkt->size - boffset)) < 0)
        return ret;

    dst = p->data[0];
    for (y = 0; y < avctx->height; y++) {
        memset(dst, 0, avctx->width * 2);
        dst += p->linesize[0];
    }

    dst = p->data[0];
    for (y = 0; y < avctx->height; y++) {
        for (x = 0; x < avctx->width * 2 && y < avctx->height;) {
            if (get_bits_left(&gb) <= 0)
                return AVERROR_INVALIDDATA;

            if (get_bits1(&gb)) {
                int val = get_vlc2(&gb, s->vlc[0].table, s->vlc[0].bits, 3);
                if (val < 0) {
                    return AVERROR_INVALIDDATA;
                } else if (val < 0xE1) {
                    dst[x    ] = table_y1[val];
                    dst[x + 1] = table_u[val];
                    dst[x + 2] = table_y2[val];
                    dst[x + 3] = table_v[val];
                    x += 4;
                } else {
                    int incr = (val - 0xDF) * 4;
                    if (x + incr >= avctx->width * 2) {
                        int iy = ((x + incr) / (avctx->width * 2));
                        x  = (x + incr) % (avctx->width * 2);
                        y += iy;
                        dst += iy * p->linesize[0];
                    } else {
                        x += incr;
                    }
                }
            } else {
                int y1, y2, u, v;

                y1 = get_vlc2(&gb, s->vlc[1].table, s->vlc[1].bits, 3);
                u  = get_vlc2(&gb, s->vlc[2].table, s->vlc[2].bits, 3);
                y2 = get_vlc2(&gb, s->vlc[1].table, s->vlc[1].bits, 3);
                v  = get_vlc2(&gb, s->vlc[3].table, s->vlc[3].bits, 3);
                if (y1 < 0 || y2 < 0 || u < 0 || v < 0)
                    return AVERROR_INVALIDDATA;
                dst[x    ] = y1;
                dst[x + 1] = u;
                dst[x + 2] = y1 + y2;
                dst[x + 3] = v;
                x += 4;
            }
        }
        dst += p->linesize[0];
    }

    dst = p->data[0];
    for (x = 0; x < avctx->width * 2; x += 4) {
        dst[x    ] =        dst[x    ] + L[0];
        dst[x + 2] = L[0] = dst[x + 2] + L[0];
        L[1] = dst[x + 1] + L[1];
        dst[x + 1] = L[1];
        L[2] = dst[x + 3] + L[2];
        dst[x + 3] = L[2];
    }
    dst += p->linesize[0];

    for (y = 1; y < avctx->height; y++) {
        x = 0;
        dst[x    ] =        dst[x    ] + L[0] + dst[x + 0 - p->linesize[0]] - TL[0];
        dst[x + 2] = L[0] = dst[x + 2] + L[0] + dst[x + 2 - p->linesize[0]] - TL[0];
        TL[0] = dst[x + 2 - p->linesize[0]];
        L[1] = dst[x + 1] + L[1] + dst[x + 1 - p->linesize[0]] - TL[1];
        dst[x + 1] = L[1];
        TL[1] = dst[x + 1 - p->linesize[0]];
        L[2] = dst[x + 3] + L[2] + dst[x + 3 - p->linesize[0]] - TL[2];
        dst[x + 3] = L[2];
        TL[2] = dst[x + 3 - p->linesize[0]];
        for (x = 4; x < avctx->width * 2; x += 4) {
            dst[x    ] =        dst[x    ] + L[0] + dst[x + 0 - p->linesize[0]] - TL[0];
            dst[x + 2] = L[0] = dst[x + 2] + L[0] + dst[x + 2 - p->linesize[0]] - TL[0];
            TL[0] = dst[x + 2 - p->linesize[0]];
            L[1] = dst[x + 1] + L[1] + dst[x + 1 - p->linesize[0]] - TL[1];
            dst[x + 1] = L[1];
            TL[1] = dst[x + 1 - p->linesize[0]];
            L[2] = dst[x + 3] + L[2] + dst[x + 3 - p->linesize[0]] - TL[2];
            dst[x + 3] = L[2];
            TL[2] = dst[x + 3 - p->linesize[0]];
        }
        dst += p->linesize[0];
    }

    p->pict_type = AV_PICTURE_TYPE_I;
    p->key_frame = 1;
    *got_frame   = 1;

    return avpkt->size;
}

