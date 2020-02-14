#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_54__   TYPE_5__ ;
typedef  struct TYPE_53__   TYPE_4__ ;
typedef  struct TYPE_52__   TYPE_3__ ;
typedef  struct TYPE_51__   TYPE_2__ ;
typedef  struct TYPE_50__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int VLC_TYPE ;
struct TYPE_54__ {TYPE_2__* priv_data; } ;
struct TYPE_53__ {int key_frame; int height; unsigned int** data; int* linesize; void* decode_error_flags; int /*<<< orphan*/  pict_type; } ;
struct TYPE_52__ {unsigned int* data; scalar_t__ size; } ;
struct TYPE_51__ {TYPE_4__* frame; } ;
struct TYPE_50__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
typedef  TYPE_1__ GetBitContext ;
typedef  TYPE_2__ CpiaContext ;
typedef  TYPE_3__ AVPacket ;
typedef  TYPE_4__ AVFrame ;
typedef  TYPE_5__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AVERROR_PATCHWELCOME ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int AV_RL16 (unsigned int*) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_1__*) ; 
 unsigned int COMPRESSED ; 
 unsigned int DECIMATION_ENAB ; 
 unsigned int EOL ; 
 int FFMAX (int,int) ; 
 void* FF_DECODE_ERROR_INVALID_BITSTREAM ; 
 scalar_t__ FRAME_HEADER_SIZE ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_1__*,int) ; 
 unsigned int MAGIC_0 ; 
 unsigned int MAGIC_1 ; 
 int MIN_CACHE_BITS ; 
 int NEG_USR32 (int,int) ; 
 unsigned int NOT_COMPRESSED ; 
 unsigned int NO_DECIMATION ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_1__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_1__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_1__*,int) ; 
 unsigned int SUBSAMPLE_420 ; 
 unsigned int SUBSAMPLE_422 ; 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_1__*) ; 
 unsigned int YUVORDER_UYVY ; 
 unsigned int YUVORDER_YUYV ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int av_frame_ref (void*,TYPE_4__*) ; 
 int /*<<< orphan*/  av_log (TYPE_5__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  avpriv_report_missing_feature (TYPE_5__*,char*) ; 
 int ff_reget_buffer (TYPE_5__*,TYPE_4__*) ; 
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

__attribute__((used)) static int cpia_decode_frame(AVCodecContext *avctx,
                             void *data, int *got_frame, AVPacket* avpkt)
{
    CpiaContext* const cpia = avctx->priv_data;
    int i,j,ret;

    uint8_t* const header = avpkt->data;
    uint8_t* src;
    int src_size;
    uint16_t linelength;
    uint8_t skip;

    AVFrame *frame = cpia->frame;
    uint8_t *y, *u, *v, *y_end, *u_end, *v_end;

    // Check header
    if ( avpkt->size < FRAME_HEADER_SIZE
      || header[0] != MAGIC_0 || header[1] != MAGIC_1
      || (header[17] != SUBSAMPLE_420 && header[17] != SUBSAMPLE_422)
      || (header[18] != YUVORDER_YUYV && header[18] != YUVORDER_UYVY)
      || (header[28] != NOT_COMPRESSED && header[28] != COMPRESSED)
      || (header[29] != NO_DECIMATION && header[29] != DECIMATION_ENAB)
    ) {
        av_log(avctx, AV_LOG_ERROR, "Invalid header!\n");
        return AVERROR_INVALIDDATA;
    }

    // currently unsupported properties
    if (header[17] == SUBSAMPLE_422) {
        avpriv_report_missing_feature(avctx, "4:2:2 subsampling");
        return AVERROR_PATCHWELCOME;
    }
    if (header[18] == YUVORDER_UYVY) {
        avpriv_report_missing_feature(avctx, "YUV byte order UYVY");
        return AVERROR_PATCHWELCOME;
    }
    if (header[29] == DECIMATION_ENAB) {
        avpriv_report_missing_feature(avctx, "Decimation");
        return AVERROR_PATCHWELCOME;
    }

    src = header + FRAME_HEADER_SIZE;
    src_size = avpkt->size - FRAME_HEADER_SIZE;

    if (header[28] == NOT_COMPRESSED) {
        frame->pict_type = AV_PICTURE_TYPE_I;
        frame->key_frame = 1;
    } else {
        frame->pict_type = AV_PICTURE_TYPE_P;
        frame->key_frame = 0;
    }

    // Get buffer filled with previous frame
    if ((ret = ff_reget_buffer(avctx, frame)) < 0)
        return ret;


    for ( i = 0;
          i < frame->height;
          i++, src += linelength, src_size -= linelength
    ) {
        // Read line length, two byte little endian
        linelength = AV_RL16(src);
        src += 2;

        if (src_size < linelength) {
            frame->decode_error_flags = FF_DECODE_ERROR_INVALID_BITSTREAM;
            av_log(avctx, AV_LOG_WARNING, "Frame ended unexpectedly!\n");
            break;
        }
        if (src[linelength - 1] != EOL) {
            frame->decode_error_flags = FF_DECODE_ERROR_INVALID_BITSTREAM;
            av_log(avctx, AV_LOG_WARNING, "Wrong line length %d or line not terminated properly (found 0x%02x)!\n", linelength, src[linelength - 1]);
            break;
        }

        /* Update the data pointers. Y data is on every line.
         * U and V data on every second line
         */
        y = &frame->data[0][i * frame->linesize[0]];
        u = &frame->data[1][(i >> 1) * frame->linesize[1]];
        v = &frame->data[2][(i >> 1) * frame->linesize[2]];
        y_end = y + frame->linesize[0] - 1;
        u_end = u + frame->linesize[1] - 1;
        v_end = v + frame->linesize[2] - 1;

        if ((i & 1) && header[17] == SUBSAMPLE_420) {
            /* We are on an odd line and 420 subsample is used.
             * On this line only Y values are specified, one per pixel.
             */
            for (j = 0; j < linelength - 1; j++) {
                if (y > y_end) {
                    frame->decode_error_flags = FF_DECODE_ERROR_INVALID_BITSTREAM;
                    av_log(avctx, AV_LOG_WARNING, "Decoded data exceeded linesize!\n");
                    break;
                }
                if ((src[j] & 1) && header[28] == COMPRESSED) {
                    /* It seems that odd lines are always uncompressed, but
                     * we do it according to specification anyways.
                     */
                    skip = src[j] >> 1;
                    y += skip;
                } else {
                    *(y++) = src[j];
                }
            }
        } else if (header[17] == SUBSAMPLE_420) {
            /* We are on an even line and 420 subsample is used.
             * On this line each pair of pixels is described by four bytes.
             */
            for (j = 0; j < linelength - 4; ) {
                if (y + 1 > y_end || u > u_end || v > v_end) {
                    frame->decode_error_flags = FF_DECODE_ERROR_INVALID_BITSTREAM;
                    av_log(avctx, AV_LOG_WARNING, "Decoded data exceeded linesize!\n");
                    break;
                }
                if ((src[j] & 1) && header[28] == COMPRESSED) {
                    // Skip amount of pixels and move forward one byte
                    skip = src[j] >> 1;
                    y += skip;
                    u += skip >> 1;
                    v += skip >> 1;
                    j++;
                } else {
                    // Set image data as specified and move forward 4 bytes
                    *(y++) = src[j];
                    *(u++) = src[j+1];
                    *(y++) = src[j+2];
                    *(v++) = src[j+3];
                    j += 4;
                }
            }
        }
    }

    *got_frame = 1;
    if ((ret = av_frame_ref(data, cpia->frame)) < 0)
        return ret;

    return avpkt->size;
}

