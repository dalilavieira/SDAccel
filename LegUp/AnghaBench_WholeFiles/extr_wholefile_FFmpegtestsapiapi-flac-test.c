#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_3__ ;
typedef  struct TYPE_32__   TYPE_2__ ;
typedef  struct TYPE_31__   TYPE_1__ ;

/* Type definitions */
struct TYPE_31__ {scalar_t__ sample_fmt; int sample_rate; scalar_t__ channel_layout; int frame_size; int channels; void* request_channel_layout; void* request_sample_fmt; } ;
typedef  TYPE_1__ uint8_t ;
typedef  int uint64_t ;
typedef  int uint16_t ;
typedef  void* int64_t ;
struct TYPE_33__ {int nb_samples; scalar_t__ format; scalar_t__ channel_layout; int* linesize; int channels; scalar_t__* data; } ;
struct TYPE_32__ {int size; int /*<<< orphan*/ * data; } ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_1__ AVCodecContext ;
typedef  int /*<<< orphan*/  AVCodec ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_UNKNOWN ; 
 int AV_CH_LAYOUT_5POINT1_BACK ; 
 int AV_CH_LAYOUT_STEREO ; 
 int AV_CH_LAYOUT_STEREO_DOWNMIX ; 
 int AV_CH_LAYOUT_SURROUND ; 
 int /*<<< orphan*/  AV_CODEC_ID_FLAC ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 void* AV_SAMPLE_FMT_S16 ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FF_ARRAY_ELEMS (int*) ; 
 int NAME_BUFF_SIZE ; 
 int NUMBER_OF_AUDIO_FRAMES ; 
 TYPE_3__* av_frame_alloc () ; 
 int /*<<< orphan*/  av_frame_free (TYPE_3__**) ; 
 scalar_t__ av_frame_get_buffer (TYPE_3__*,int) ; 
 int /*<<< orphan*/  av_freep (TYPE_1__**) ; 
 int /*<<< orphan*/  av_get_channel_layout_string (char*,int,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  av_init_packet (TYPE_2__*) ; 
 int /*<<< orphan*/  av_log (TYPE_1__*,int /*<<< orphan*/ ,char*,...) ; 
 TYPE_1__* av_malloc (int) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_2__*) ; 
 TYPE_1__* avcodec_alloc_context3 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avcodec_close (TYPE_1__*) ; 
 int avcodec_decode_audio4 (TYPE_1__*,TYPE_3__*,int*,TYPE_2__*) ; 
 int avcodec_encode_audio2 (TYPE_1__*,TYPE_2__*,TYPE_3__*,int*) ; 
 int /*<<< orphan*/ * avcodec_find_decoder (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * avcodec_find_encoder (int /*<<< orphan*/ ) ; 
 int avcodec_open2 (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ memcmp (TYPE_1__*,TYPE_1__*,int) ; 
 int /*<<< orphan*/  memcpy (TYPE_1__*,scalar_t__,int) ; 

__attribute__((used)) static int generate_raw_frame(uint16_t *frame_data, int i, int sample_rate,
                              int channels, int frame_size)
{
    int j, k;

    for (j = 0; j < frame_size; j++) {
        frame_data[channels * j] = 10000 * ((j / 10 * i) % 2);
        for (k = 1; k < channels; k++)
            frame_data[channels * j + k] = frame_data[channels * j] * (k + 1);
    }
    return 0;
}

__attribute__((used)) static int init_encoder(AVCodec *enc, AVCodecContext **enc_ctx,
                        int64_t ch_layout, int sample_rate)
{
    AVCodecContext *ctx;
    int result;
    char name_buff[NAME_BUFF_SIZE];

    av_get_channel_layout_string(name_buff, NAME_BUFF_SIZE, 0, ch_layout);
    av_log(NULL, AV_LOG_INFO, "channel layout: %s, sample rate: %i\n", name_buff, sample_rate);

    ctx = avcodec_alloc_context3(enc);
    if (!ctx) {
        av_log(NULL, AV_LOG_ERROR, "Can't allocate encoder context\n");
        return AVERROR(ENOMEM);
    }

    ctx->sample_fmt = AV_SAMPLE_FMT_S16;
    ctx->sample_rate = sample_rate;
    ctx->channel_layout = ch_layout;

    result = avcodec_open2(ctx, enc, NULL);
    if (result < 0) {
        av_log(ctx, AV_LOG_ERROR, "Can't open encoder\n");
        return result;
    }

    *enc_ctx = ctx;
    return 0;
}

__attribute__((used)) static int init_decoder(AVCodec *dec, AVCodecContext **dec_ctx,
                        int64_t ch_layout)
{
    AVCodecContext *ctx;
    int result;

    ctx = avcodec_alloc_context3(dec);
    if (!ctx) {
        av_log(NULL, AV_LOG_ERROR , "Can't allocate decoder context\n");
        return AVERROR(ENOMEM);
    }

    ctx->request_sample_fmt = AV_SAMPLE_FMT_S16;
    /* XXX: FLAC ignores it for some reason */
    ctx->request_channel_layout = ch_layout;
    ctx->channel_layout = ch_layout;

    result = avcodec_open2(ctx, dec, NULL);
    if (result < 0) {
        av_log(ctx, AV_LOG_ERROR, "Can't open decoder\n");
        return result;
    }

    *dec_ctx = ctx;
    return 0;
}

__attribute__((used)) static int run_test(AVCodec *enc, AVCodec *dec, AVCodecContext *enc_ctx,
                    AVCodecContext *dec_ctx)
{
    AVPacket enc_pkt;
    AVFrame *in_frame, *out_frame;
    uint8_t *raw_in = NULL, *raw_out = NULL;
    int in_offset = 0, out_offset = 0;
    int result = 0;
    int got_output = 0;
    int i = 0;
    int in_frame_bytes, out_frame_bytes;

    in_frame = av_frame_alloc();
    if (!in_frame) {
        av_log(NULL, AV_LOG_ERROR, "Can't allocate input frame\n");
        return AVERROR(ENOMEM);
    }

    in_frame->nb_samples = enc_ctx->frame_size;
    in_frame->format = enc_ctx->sample_fmt;
    in_frame->channel_layout = enc_ctx->channel_layout;
    if (av_frame_get_buffer(in_frame, 32) != 0) {
        av_log(NULL, AV_LOG_ERROR, "Can't allocate a buffer for input frame\n");
        return AVERROR(ENOMEM);
    }

    out_frame = av_frame_alloc();
    if (!out_frame) {
        av_log(NULL, AV_LOG_ERROR, "Can't allocate output frame\n");
        return AVERROR(ENOMEM);
    }

    raw_in = av_malloc(in_frame->linesize[0] * NUMBER_OF_AUDIO_FRAMES);
    if (!raw_in) {
        av_log(NULL, AV_LOG_ERROR, "Can't allocate memory for raw_in\n");
        return AVERROR(ENOMEM);
    }

    raw_out = av_malloc(in_frame->linesize[0] * NUMBER_OF_AUDIO_FRAMES);
    if (!raw_out) {
        av_log(NULL, AV_LOG_ERROR, "Can't allocate memory for raw_out\n");
        return AVERROR(ENOMEM);
    }

    for (i = 0; i < NUMBER_OF_AUDIO_FRAMES; i++) {
        av_init_packet(&enc_pkt);
        enc_pkt.data = NULL;
        enc_pkt.size = 0;

        generate_raw_frame((uint16_t*)(in_frame->data[0]), i, enc_ctx->sample_rate,
                           enc_ctx->channels, enc_ctx->frame_size);
        in_frame_bytes = in_frame->nb_samples * in_frame->channels * sizeof(uint16_t);
        if (in_frame_bytes > in_frame->linesize[0]) {
            av_log(NULL, AV_LOG_ERROR, "Incorrect value of input frame linesize\n");
            return 1;
        }
        memcpy(raw_in + in_offset, in_frame->data[0], in_frame_bytes);
        in_offset += in_frame_bytes;
        result = avcodec_encode_audio2(enc_ctx, &enc_pkt, in_frame, &got_output);
        if (result < 0) {
            av_log(NULL, AV_LOG_ERROR, "Error encoding audio frame\n");
            return result;
        }

        /* if we get an encoded packet, feed it straight to the decoder */
        if (got_output) {
            result = avcodec_decode_audio4(dec_ctx, out_frame, &got_output, &enc_pkt);
            if (result < 0) {
                av_log(NULL, AV_LOG_ERROR, "Error decoding audio packet\n");
                return result;
            }

            if (got_output) {
                if (result != enc_pkt.size) {
                    av_log(NULL, AV_LOG_INFO, "Decoder consumed only part of a packet, it is allowed to do so -- need to update this test\n");
                    return AVERROR_UNKNOWN;
                }

                if (in_frame->nb_samples != out_frame->nb_samples) {
                    av_log(NULL, AV_LOG_ERROR, "Error frames before and after decoding has different number of samples\n");
                    return AVERROR_UNKNOWN;
                }

                if (in_frame->channel_layout != out_frame->channel_layout) {
                    av_log(NULL, AV_LOG_ERROR, "Error frames before and after decoding has different channel layout\n");
                    return AVERROR_UNKNOWN;
                }

                if (in_frame->format != out_frame->format) {
                    av_log(NULL, AV_LOG_ERROR, "Error frames before and after decoding has different sample format\n");
                    return AVERROR_UNKNOWN;
                }
                out_frame_bytes = out_frame->nb_samples * out_frame->channels * sizeof(uint16_t);
                if (out_frame_bytes > out_frame->linesize[0]) {
                    av_log(NULL, AV_LOG_ERROR, "Incorrect value of output frame linesize\n");
                    return 1;
                }
                memcpy(raw_out + out_offset, out_frame->data[0], out_frame_bytes);
                out_offset += out_frame_bytes;
            }
        }
        av_packet_unref(&enc_pkt);
    }

    if (memcmp(raw_in, raw_out, out_frame_bytes * NUMBER_OF_AUDIO_FRAMES) != 0) {
        av_log(NULL, AV_LOG_ERROR, "Output differs\n");
        return 1;
    }

    av_log(NULL, AV_LOG_INFO, "OK\n");

    av_freep(&raw_in);
    av_freep(&raw_out);
    av_frame_free(&in_frame);
    av_frame_free(&out_frame);
    return 0;
}

__attribute__((used)) static int close_encoder(AVCodecContext **enc_ctx)
{
    avcodec_close(*enc_ctx);
    av_freep(enc_ctx);
    return 0;
}

__attribute__((used)) static int close_decoder(AVCodecContext **dec_ctx)
{
    avcodec_close(*dec_ctx);
    av_freep(dec_ctx);
    return 0;
}

int main(void)
{
    AVCodec *enc = NULL, *dec = NULL;
    AVCodecContext *enc_ctx = NULL, *dec_ctx = NULL;
    uint64_t channel_layouts[] = {AV_CH_LAYOUT_STEREO, AV_CH_LAYOUT_5POINT1_BACK, AV_CH_LAYOUT_SURROUND, AV_CH_LAYOUT_STEREO_DOWNMIX};
    int sample_rates[] = {8000, 44100, 48000, 192000};
    int cl, sr;

    enc = avcodec_find_encoder(AV_CODEC_ID_FLAC);
    if (!enc) {
        av_log(NULL, AV_LOG_ERROR, "Can't find encoder\n");
        return 1;
    }

    dec = avcodec_find_decoder(AV_CODEC_ID_FLAC);
    if (!dec) {
        av_log(NULL, AV_LOG_ERROR, "Can't find decoder\n");
        return 1;
    }

    for (cl = 0; cl < FF_ARRAY_ELEMS(channel_layouts); cl++) {
        for (sr = 0; sr < FF_ARRAY_ELEMS(sample_rates); sr++) {
            if (init_encoder(enc, &enc_ctx, channel_layouts[cl], sample_rates[sr]) != 0)
                return 1;
            if (init_decoder(dec, &dec_ctx, channel_layouts[cl]) != 0)
                return 1;
            if (run_test(enc, dec, enc_ctx, dec_ctx) != 0)
                return 1;
            close_encoder(&enc_ctx);
            close_decoder(&dec_ctx);
        }
    }

    return 0;
}

