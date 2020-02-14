#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_68__   TYPE_6__ ;
typedef  struct TYPE_67__   TYPE_5__ ;
typedef  struct TYPE_66__   TYPE_4__ ;
typedef  struct TYPE_65__   TYPE_3__ ;
typedef  struct TYPE_64__   TYPE_2__ ;
typedef  struct TYPE_63__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int VLC_TYPE ;
struct TYPE_68__ {int err_recognition; TYPE_1__* priv_data; } ;
struct TYPE_67__ {scalar_t__* linesize; int key_frame; scalar_t__* data; int /*<<< orphan*/  pict_type; } ;
struct TYPE_66__ {unsigned int* data; int size; } ;
struct TYPE_65__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
struct TYPE_64__ {int width; int height; int got_picture; TYPE_5__* picture_ptr; TYPE_3__ gb; int /*<<< orphan*/  first_picture; int /*<<< orphan*/  interlaced; TYPE_6__* avctx; } ;
struct TYPE_63__ {unsigned int mb_width; unsigned int mb_height; unsigned int bitmask_size; unsigned int* mxm_bitmask; unsigned int* completion_bitmask; int got_mxm_bitmask; int has_complete_frame; int got_sof_data; int picture_index; TYPE_5__** picture; TYPE_2__ jpg; } ;
typedef  TYPE_1__ MXpegDecodeContext ;
typedef  TYPE_2__ MJpegDecodeContext ;
typedef  TYPE_3__ GetBitContext ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVFrame ;
typedef  TYPE_6__ AVCodecContext ;

/* Variables and functions */
 int APP0 ; 
 int APP15 ; 
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int AV_EF_EXPLODE ; 
 int /*<<< orphan*/  AV_GET_BUFFER_FLAG_REF ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int AV_RB16 (unsigned int const*) ; 
 void* AV_RL16 (unsigned int const*) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_3__*) ; 
#define  COM 134 
#define  DHT 133 
#define  DQT 132 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
#define  EOI 131 
 int FFMAX (int,int) ; 
 int FFMIN (int,int) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 int MAX_COMPONENTS ; 
 int MIN_CACHE_BITS ; 
 int NEG_USR32 (int,int) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_3__*,int) ; 
#define  SOF0 130 
#define  SOI 129 
#define  SOS 128 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int av_frame_ref (void*,TYPE_5__*) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_5__*) ; 
 int /*<<< orphan*/  av_freep (unsigned int**) ; 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*,...) ; 
 unsigned int* av_malloc (unsigned int) ; 
 unsigned int* av_mallocz (unsigned int) ; 
 int ff_get_buffer (TYPE_6__*,TYPE_5__*,int /*<<< orphan*/ ) ; 
 int ff_mjpeg_decode_dht (TYPE_2__*) ; 
 int ff_mjpeg_decode_dqt (TYPE_2__*) ; 
 int ff_mjpeg_decode_sof (TYPE_2__*) ; 
 int ff_mjpeg_decode_sos (TYPE_2__*,unsigned int*,unsigned int,TYPE_5__*) ; 
 int ff_mjpeg_find_marker (TYPE_2__*,unsigned int const**,unsigned int const*,unsigned int const**,int*) ; 
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned int const*,unsigned int) ; 
 int /*<<< orphan*/  re ; 
 int sign_extend (int,int) ; 
 int /*<<< orphan*/  strncmp (unsigned int const*,char*,int) ; 
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

__attribute__((used)) static int mxpeg_decode_app(MXpegDecodeContext *s,
                            const uint8_t *buf_ptr, int buf_size)
{
    int len;
    if (buf_size < 2)
        return 0;
    len = AV_RB16(buf_ptr);
    skip_bits(&s->jpg.gb, 8*FFMIN(len,buf_size));

    return 0;
}

__attribute__((used)) static int mxpeg_decode_mxm(MXpegDecodeContext *s,
                            const uint8_t *buf_ptr, int buf_size)
{
    unsigned bitmask_size, mb_count;
    int i;

    s->mb_width  = AV_RL16(buf_ptr+4);
    s->mb_height = AV_RL16(buf_ptr+6);
    mb_count = s->mb_width * s->mb_height;

    bitmask_size = (mb_count + 7) >> 3;
    if (bitmask_size > buf_size - 12) {
        av_log(s->jpg.avctx, AV_LOG_ERROR,
               "MXM bitmask is not complete\n");
        return AVERROR(EINVAL);
    }

    if (s->bitmask_size != bitmask_size) {
        s->bitmask_size = 0;
        av_freep(&s->mxm_bitmask);
        s->mxm_bitmask = av_malloc(bitmask_size);
        if (!s->mxm_bitmask) {
            av_log(s->jpg.avctx, AV_LOG_ERROR,
                   "MXM bitmask memory allocation error\n");
            return AVERROR(ENOMEM);
        }

        av_freep(&s->completion_bitmask);
        s->completion_bitmask = av_mallocz(bitmask_size);
        if (!s->completion_bitmask) {
            av_log(s->jpg.avctx, AV_LOG_ERROR,
                   "Completion bitmask memory allocation error\n");
            return AVERROR(ENOMEM);
        }

        s->bitmask_size = bitmask_size;
    }

    memcpy(s->mxm_bitmask, buf_ptr + 12, bitmask_size);
    s->got_mxm_bitmask = 1;

    if (!s->has_complete_frame) {
        uint8_t completion_check = 0xFF;
        for (i = 0; i < bitmask_size; ++i) {
            s->completion_bitmask[i] |= s->mxm_bitmask[i];
            completion_check &= s->completion_bitmask[i];
        }
        s->has_complete_frame = !(completion_check ^ 0xFF);
    }

    return 0;
}

__attribute__((used)) static int mxpeg_decode_com(MXpegDecodeContext *s,
                            const uint8_t *buf_ptr, int buf_size)
{
    int len, ret = 0;
    if (buf_size < 2)
        return 0;
    len = AV_RB16(buf_ptr);
    if (len > 14 && len <= buf_size && !strncmp(buf_ptr + 2, "MXM", 3)) {
        ret = mxpeg_decode_mxm(s, buf_ptr + 2, len - 2);
    }
    skip_bits(&s->jpg.gb, 8*FFMIN(len,buf_size));

    return ret;
}

__attribute__((used)) static int mxpeg_check_dimensions(MXpegDecodeContext *s, MJpegDecodeContext *jpg,
                                  AVFrame *reference_ptr)
{
    if ((jpg->width + 0x0F)>>4 != s->mb_width ||
        (jpg->height + 0x0F)>>4 != s->mb_height) {
        av_log(jpg->avctx, AV_LOG_ERROR,
               "Picture dimensions stored in SOF and MXM mismatch\n");
        return AVERROR(EINVAL);
    }

    if (reference_ptr->data[0]) {
        int i;
        for (i = 0; i < MAX_COMPONENTS; ++i) {
            if ( (!reference_ptr->data[i] ^ !jpg->picture_ptr->data[i]) ||
                 reference_ptr->linesize[i] != jpg->picture_ptr->linesize[i]) {
                av_log(jpg->avctx, AV_LOG_ERROR,
                       "Dimensions of current and reference picture mismatch\n");
                return AVERROR(EINVAL);
            }
        }
    }

    return 0;
}

__attribute__((used)) static int mxpeg_decode_frame(AVCodecContext *avctx,
                          void *data, int *got_frame,
                          AVPacket *avpkt)
{
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    MXpegDecodeContext *s = avctx->priv_data;
    MJpegDecodeContext *jpg = &s->jpg;
    const uint8_t *buf_end, *buf_ptr;
    const uint8_t *unescaped_buf_ptr;
    int unescaped_buf_size;
    int start_code;
    int ret;

    buf_ptr = buf;
    buf_end = buf + buf_size;
    jpg->got_picture = 0;
    s->got_mxm_bitmask = 0;
    while (buf_ptr < buf_end) {
        start_code = ff_mjpeg_find_marker(jpg, &buf_ptr, buf_end,
                                          &unescaped_buf_ptr, &unescaped_buf_size);
        if (start_code < 0)
            goto the_end;
        {
            init_get_bits(&jpg->gb, unescaped_buf_ptr, unescaped_buf_size*8);

            if (start_code >= APP0 && start_code <= APP15) {
                mxpeg_decode_app(s, unescaped_buf_ptr, unescaped_buf_size);
            }

            switch (start_code) {
            case SOI:
                if (jpg->got_picture) //emulating EOI
                    goto the_end;
                break;
            case EOI:
                goto the_end;
            case DQT:
                ret = ff_mjpeg_decode_dqt(jpg);
                if (ret < 0) {
                    av_log(avctx, AV_LOG_ERROR,
                           "quantization table decode error\n");
                    return ret;
                }
                break;
            case DHT:
                ret = ff_mjpeg_decode_dht(jpg);
                if (ret < 0) {
                    av_log(avctx, AV_LOG_ERROR,
                           "huffman table decode error\n");
                    return ret;
                }
                break;
            case COM:
                ret = mxpeg_decode_com(s, unescaped_buf_ptr,
                                       unescaped_buf_size);
                if (ret < 0)
                    return ret;
                break;
            case SOF0:
                s->got_sof_data = 0;
                ret = ff_mjpeg_decode_sof(jpg);
                if (ret < 0) {
                    av_log(avctx, AV_LOG_ERROR,
                           "SOF data decode error\n");
                    return ret;
                }
                if (jpg->interlaced) {
                    av_log(avctx, AV_LOG_ERROR,
                           "Interlaced mode not supported in MxPEG\n");
                    return AVERROR(EINVAL);
                }
                s->got_sof_data = 1;
                break;
            case SOS:
                if (!s->got_sof_data) {
                    av_log(avctx, AV_LOG_WARNING,
                           "Can not process SOS without SOF data, skipping\n");
                    break;
                }
                if (!jpg->got_picture) {
                    if (jpg->first_picture) {
                        av_log(avctx, AV_LOG_WARNING,
                               "First picture has no SOF, skipping\n");
                        break;
                    }
                    if (!s->got_mxm_bitmask){
                        av_log(avctx, AV_LOG_WARNING,
                               "Non-key frame has no MXM, skipping\n");
                        break;
                    }
                    /* use stored SOF data to allocate current picture */
                    av_frame_unref(jpg->picture_ptr);
                    if ((ret = ff_get_buffer(avctx, jpg->picture_ptr,
                                             AV_GET_BUFFER_FLAG_REF)) < 0)
                        return ret;
                    jpg->picture_ptr->pict_type = AV_PICTURE_TYPE_P;
                    jpg->picture_ptr->key_frame = 0;
                    jpg->got_picture = 1;
                } else {
                    jpg->picture_ptr->pict_type = AV_PICTURE_TYPE_I;
                    jpg->picture_ptr->key_frame = 1;
                }

                if (s->got_mxm_bitmask) {
                    AVFrame *reference_ptr = s->picture[s->picture_index ^ 1];
                    if (mxpeg_check_dimensions(s, jpg, reference_ptr) < 0)
                        break;

                    /* allocate dummy reference picture if needed */
                    if (!reference_ptr->data[0] &&
                        (ret = ff_get_buffer(avctx, reference_ptr,
                                             AV_GET_BUFFER_FLAG_REF)) < 0)
                        return ret;

                    ret = ff_mjpeg_decode_sos(jpg, s->mxm_bitmask, s->bitmask_size, reference_ptr);
                    if (ret < 0 && (avctx->err_recognition & AV_EF_EXPLODE))
                        return ret;
                } else {
                    ret = ff_mjpeg_decode_sos(jpg, NULL, 0, NULL);
                    if (ret < 0 && (avctx->err_recognition & AV_EF_EXPLODE))
                        return ret;
                }

                break;
            }

            buf_ptr += (get_bits_count(&jpg->gb)+7) >> 3;
        }

    }

the_end:
    if (jpg->got_picture) {
        int ret = av_frame_ref(data, jpg->picture_ptr);
        if (ret < 0)
            return ret;
        *got_frame = 1;

        s->picture_index ^= 1;
        jpg->picture_ptr = s->picture[s->picture_index];

        if (!s->has_complete_frame) {
            if (!s->got_mxm_bitmask)
                s->has_complete_frame = 1;
            else
                *got_frame = 0;
        }
    }

    return buf_ptr - buf;
}

