#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_71__   TYPE_7__ ;
typedef  struct TYPE_70__   TYPE_6__ ;
typedef  struct TYPE_69__   TYPE_5__ ;
typedef  struct TYPE_68__   TYPE_4__ ;
typedef  struct TYPE_67__   TYPE_42__ ;
typedef  struct TYPE_66__   TYPE_3__ ;
typedef  struct TYPE_65__   TYPE_2__ ;
typedef  struct TYPE_64__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint8_t ;
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  opus_int16 ;
typedef  int /*<<< orphan*/  name ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int VLC_TYPE ;
struct TYPE_71__ {unsigned int* extradata; int channels; scalar_t__ channel_layout; scalar_t__ sample_fmt; TYPE_3__* priv_data; scalar_t__ cutoff; int /*<<< orphan*/  bit_rate; scalar_t__ global_quality; int /*<<< orphan*/  sample_rate; int /*<<< orphan*/  initial_padding; } ;
struct TYPE_70__ {unsigned int** data; int nb_samples; } ;
struct TYPE_69__ {int duration; int /*<<< orphan*/  pts; int /*<<< orphan*/  size; int /*<<< orphan*/  data; } ;
struct TYPE_68__ {int index; unsigned int size_in_bits_plus8; unsigned int* buffer; int size_in_bits; unsigned int const* buffer_end; } ;
struct TYPE_67__ {int /*<<< orphan*/  frame_count; int /*<<< orphan*/  frame_alloc; int /*<<< orphan*/  remaining_samples; } ;
struct TYPE_64__ {int packet_size; } ;
struct TYPE_66__ {unsigned int* encoder_channel_map; unsigned int* samples; int stream_count; TYPE_1__ opts; TYPE_42__ afq; int /*<<< orphan*/  enc; } ;
struct TYPE_65__ {int vbr; int /*<<< orphan*/  max_bandwidth; int /*<<< orphan*/  packet_loss; int /*<<< orphan*/  complexity; } ;
typedef  int /*<<< orphan*/  OpusMSEncoder ;
typedef  TYPE_2__ LibopusEncOpts ;
typedef  TYPE_3__ LibopusEncContext ;
typedef  TYPE_4__ GetBitContext ;
typedef  TYPE_5__ AVPacket ;
typedef  TYPE_6__ AVFrame ;
typedef  TYPE_7__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  AV_PKT_DATA_SKIP_SAMPLES ; 
 scalar_t__ AV_SAMPLE_FMT_FLT ; 
 int /*<<< orphan*/  AV_WL32 (unsigned int*,int) ; 
 int /*<<< orphan*/  CLOSE_READER (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FFMAX (int,int) ; 
 int FF_ARRAY_ELEMS (scalar_t__*) ; 
 int GET_CACHE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  LAST_SKIP_BITS (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 int MIN_CACHE_BITS ; 
 int NEG_USR32 (int,int) ; 
 int /*<<< orphan*/  OPEN_READER (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  OPEN_READER_NOSIZE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int OPUS_OK ; 
 int /*<<< orphan*/  OPUS_SET_BITRATE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OPUS_SET_COMPLEXITY (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OPUS_SET_MAX_BANDWIDTH (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OPUS_SET_PACKET_LOSS_PERC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OPUS_SET_VBR (int) ; 
 int /*<<< orphan*/  OPUS_SET_VBR_CONSTRAINT (int) ; 
 int SHOW_SBITS (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 unsigned int SHOW_UBITS (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 int SHOW_UBITS_LE (int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 unsigned int UINT64_C (int) ; 
 int /*<<< orphan*/  UPDATE_CACHE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  UPDATE_CACHE_LE (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 scalar_t__ av_clip (int,int,unsigned int) ; 
 int /*<<< orphan*/  av_free (TYPE_5__*) ; 
 int av_get_bytes_per_sample (scalar_t__) ; 
 int /*<<< orphan*/  av_get_channel_layout_string (char*,int,int,scalar_t__) ; 
 int /*<<< orphan*/  av_log (TYPE_7__*,int /*<<< orphan*/ ,char*,...) ; 
 unsigned int* av_packet_new_side_data (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_5__*) ; 
 int /*<<< orphan*/  av_shrink_packet (TYPE_5__*,int) ; 
 int /*<<< orphan*/  bytestream_put_buffer (unsigned int**,...) ; 
 int /*<<< orphan*/  bytestream_put_byte (unsigned int**,int) ; 
 int /*<<< orphan*/  bytestream_put_le16 (unsigned int**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bytestream_put_le32 (unsigned int**,int /*<<< orphan*/ ) ; 
 int ff_af_queue_add (TYPE_42__*,TYPE_6__ const*) ; 
 int /*<<< orphan*/  ff_af_queue_remove (TYPE_42__*,int const,int /*<<< orphan*/ *,int*) ; 
 int ff_alloc_packet2 (TYPE_7__*,TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int ff_opus_error_to_averror (int) ; 
 unsigned int** ff_vorbis_channel_layout_offsets ; 
 scalar_t__* ff_vorbis_channel_layouts ; 
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned int const*,int const) ; 
 int /*<<< orphan*/  memset (unsigned int*,int /*<<< orphan*/ ,int const) ; 
 int opus_multistream_encode (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int const,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int opus_multistream_encode_float (int /*<<< orphan*/ ,float*,int const,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int opus_multistream_encoder_ctl (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int opus_strerror (int) ; 
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

__attribute__((used)) static void libopus_write_header(AVCodecContext *avctx, int stream_count,
                                 int coupled_stream_count,
                                 int mapping_family,
                                 const uint8_t *channel_mapping)
{
    uint8_t *p   = avctx->extradata;
    int channels = avctx->channels;

    bytestream_put_buffer(&p, "OpusHead", 8);
    bytestream_put_byte(&p, 1); /* Version */
    bytestream_put_byte(&p, channels);
    bytestream_put_le16(&p, avctx->initial_padding); /* Lookahead samples at 48kHz */
    bytestream_put_le32(&p, avctx->sample_rate); /* Original sample rate */
    bytestream_put_le16(&p, 0); /* Gain of 0dB is recommended. */

    /* Channel mapping */
    bytestream_put_byte(&p, mapping_family);
    if (mapping_family != 0) {
        bytestream_put_byte(&p, stream_count);
        bytestream_put_byte(&p, coupled_stream_count);
        bytestream_put_buffer(&p, channel_mapping, channels);
    }
}

__attribute__((used)) static int libopus_configure_encoder(AVCodecContext *avctx, OpusMSEncoder *enc,
                                     LibopusEncOpts *opts)
{
    int ret;

    if (avctx->global_quality) {
        av_log(avctx, AV_LOG_ERROR,
               "Quality-based encoding not supported, "
               "please specify a bitrate and VBR setting.\n");
        return AVERROR(EINVAL);
    }

    ret = opus_multistream_encoder_ctl(enc, OPUS_SET_BITRATE(avctx->bit_rate));
    if (ret != OPUS_OK) {
        av_log(avctx, AV_LOG_ERROR,
               "Failed to set bitrate: %s\n", opus_strerror(ret));
        return ret;
    }

    ret = opus_multistream_encoder_ctl(enc,
                                       OPUS_SET_COMPLEXITY(opts->complexity));
    if (ret != OPUS_OK)
        av_log(avctx, AV_LOG_WARNING,
               "Unable to set complexity: %s\n", opus_strerror(ret));

    ret = opus_multistream_encoder_ctl(enc, OPUS_SET_VBR(!!opts->vbr));
    if (ret != OPUS_OK)
        av_log(avctx, AV_LOG_WARNING,
               "Unable to set VBR: %s\n", opus_strerror(ret));

    ret = opus_multistream_encoder_ctl(enc,
                                       OPUS_SET_VBR_CONSTRAINT(opts->vbr == 2));
    if (ret != OPUS_OK)
        av_log(avctx, AV_LOG_WARNING,
               "Unable to set constrained VBR: %s\n", opus_strerror(ret));

    ret = opus_multistream_encoder_ctl(enc,
                                       OPUS_SET_PACKET_LOSS_PERC(opts->packet_loss));
    if (ret != OPUS_OK)
        av_log(avctx, AV_LOG_WARNING,
               "Unable to set expected packet loss percentage: %s\n",
               opus_strerror(ret));

    if (avctx->cutoff) {
        ret = opus_multistream_encoder_ctl(enc,
                                           OPUS_SET_MAX_BANDWIDTH(opts->max_bandwidth));
        if (ret != OPUS_OK)
            av_log(avctx, AV_LOG_WARNING,
                   "Unable to set maximum bandwidth: %s\n", opus_strerror(ret));
    }

#ifdef OPUS_SET_PHASE_INVERSION_DISABLED_REQUEST
    ret = opus_multistream_encoder_ctl(enc,
                                       OPUS_SET_PHASE_INVERSION_DISABLED(!opts->apply_phase_inv));
    if (ret != OPUS_OK)
        av_log(avctx, AV_LOG_WARNING,
               "Unable to set phase inversion: %s\n",
               opus_strerror(ret));
#endif
    return OPUS_OK;
}

__attribute__((used)) static int libopus_check_max_channels(AVCodecContext *avctx,
                                      int max_channels) {
    if (avctx->channels > max_channels) {
        av_log(avctx, AV_LOG_ERROR, "Opus mapping family undefined for %d channels.\n",
               avctx->channels);
        return AVERROR(EINVAL);
    }

    return 0;
}

__attribute__((used)) static int libopus_check_vorbis_layout(AVCodecContext *avctx, int mapping_family) {
    av_assert2(avctx->channels < FF_ARRAY_ELEMS(ff_vorbis_channel_layouts));

    if (!avctx->channel_layout) {
        av_log(avctx, AV_LOG_WARNING,
               "No channel layout specified. Opus encoder will use Vorbis "
               "channel layout for %d channels.\n", avctx->channels);
    } else if (avctx->channel_layout != ff_vorbis_channel_layouts[avctx->channels - 1]) {
        char name[32];
        av_get_channel_layout_string(name, sizeof(name), avctx->channels,
                                     avctx->channel_layout);
        av_log(avctx, AV_LOG_ERROR,
               "Invalid channel layout %s for specified mapping family %d.\n",
               name, mapping_family);

        return AVERROR(EINVAL);
    }

    return 0;
}

__attribute__((used)) static int libopus_validate_layout_and_get_channel_map(
        AVCodecContext *avctx,
        int mapping_family,
        const uint8_t ** channel_map_result)
{
    const uint8_t * channel_map = NULL;
    int ret;

    switch (mapping_family) {
    case -1:
        ret = libopus_check_max_channels(avctx, 8);
        if (ret == 0) {
            ret = libopus_check_vorbis_layout(avctx, mapping_family);
            /* Channels do not need to be reordered. */
        }

        break;
    case 0:
        ret = libopus_check_max_channels(avctx, 2);
        if (ret == 0) {
            ret = libopus_check_vorbis_layout(avctx, mapping_family);
        }
        break;
    case 1:
        /* Opus expects channels to be in Vorbis order. */
        ret = libopus_check_max_channels(avctx, 8);
        if (ret == 0) {
            ret = libopus_check_vorbis_layout(avctx, mapping_family);
            channel_map = ff_vorbis_channel_layout_offsets[avctx->channels - 1];
        }
        break;
    case 255:
        ret = libopus_check_max_channels(avctx, 254);
        break;
    default:
        av_log(avctx, AV_LOG_WARNING,
               "Unknown channel mapping family %d. Output channel layout may be invalid.\n",
               mapping_family);
        ret = 0;
    }

    *channel_map_result = channel_map;
    return ret;
}

__attribute__((used)) static void libopus_copy_samples_with_channel_map(
    uint8_t *dst, const uint8_t *src, const uint8_t *channel_map,
    int nb_channels, int nb_samples, int bytes_per_sample) {
    int sample, channel;
    for (sample = 0; sample < nb_samples; ++sample) {
        for (channel = 0; channel < nb_channels; ++channel) {
            const size_t src_pos = bytes_per_sample * (nb_channels * sample + channel);
            const size_t dst_pos = bytes_per_sample * (nb_channels * sample + channel_map[channel]);

            memcpy(&dst[dst_pos], &src[src_pos], bytes_per_sample);
        }
    }
}

__attribute__((used)) static int libopus_encode(AVCodecContext *avctx, AVPacket *avpkt,
                          const AVFrame *frame, int *got_packet_ptr)
{
    LibopusEncContext *opus = avctx->priv_data;
    const int bytes_per_sample = av_get_bytes_per_sample(avctx->sample_fmt);
    const int sample_size      = avctx->channels * bytes_per_sample;
    uint8_t *audio;
    int ret;
    int discard_padding;

    if (frame) {
        ret = ff_af_queue_add(&opus->afq, frame);
        if (ret < 0)
            return ret;
        if (opus->encoder_channel_map != NULL) {
            audio = opus->samples;
            libopus_copy_samples_with_channel_map(
                audio, frame->data[0], opus->encoder_channel_map,
                avctx->channels, frame->nb_samples, bytes_per_sample);
        } else if (frame->nb_samples < opus->opts.packet_size) {
            audio = opus->samples;
            memcpy(audio, frame->data[0], frame->nb_samples * sample_size);
        } else
            audio = frame->data[0];
    } else {
        if (!opus->afq.remaining_samples || (!opus->afq.frame_alloc && !opus->afq.frame_count))
            return 0;
        audio = opus->samples;
        memset(audio, 0, opus->opts.packet_size * sample_size);
    }

    /* Maximum packet size taken from opusenc in opus-tools. 120ms packets
     * consist of 6 frames in one packet. The maximum frame size is 1275
     * bytes along with the largest possible packet header of 7 bytes. */
    if ((ret = ff_alloc_packet2(avctx, avpkt, (1275 * 6 + 7) * opus->stream_count, 0)) < 0)
        return ret;

    if (avctx->sample_fmt == AV_SAMPLE_FMT_FLT)
        ret = opus_multistream_encode_float(opus->enc, (float *)audio,
                                            opus->opts.packet_size,
                                            avpkt->data, avpkt->size);
    else
        ret = opus_multistream_encode(opus->enc, (opus_int16 *)audio,
                                      opus->opts.packet_size,
                                      avpkt->data, avpkt->size);

    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR,
               "Error encoding frame: %s\n", opus_strerror(ret));
        return ff_opus_error_to_averror(ret);
    }

    av_shrink_packet(avpkt, ret);

    ff_af_queue_remove(&opus->afq, opus->opts.packet_size,
                       &avpkt->pts, &avpkt->duration);

    discard_padding = opus->opts.packet_size - avpkt->duration;
    // Check if subtraction resulted in an overflow
    if ((discard_padding < opus->opts.packet_size) != (avpkt->duration > 0)) {
        av_packet_unref(avpkt);
        av_free(avpkt);
        return AVERROR(EINVAL);
    }
    if (discard_padding > 0) {
        uint8_t* side_data = av_packet_new_side_data(avpkt,
                                                     AV_PKT_DATA_SKIP_SAMPLES,
                                                     10);
        if(!side_data) {
            av_packet_unref(avpkt);
            av_free(avpkt);
            return AVERROR(ENOMEM);
        }
        AV_WL32(side_data + 4, discard_padding);
    }

    *got_packet_ptr = 1;

    return 0;
}

