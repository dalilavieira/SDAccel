#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_57__   TYPE_9__ ;
typedef  struct TYPE_56__   TYPE_8__ ;
typedef  struct TYPE_55__   TYPE_7__ ;
typedef  struct TYPE_54__   TYPE_6__ ;
typedef  struct TYPE_53__   TYPE_5__ ;
typedef  struct TYPE_52__   TYPE_4__ ;
typedef  struct TYPE_51__   TYPE_3__ ;
typedef  struct TYPE_50__   TYPE_2__ ;
typedef  struct TYPE_49__   TYPE_1__ ;
typedef  struct TYPE_48__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int64_t ;
typedef  int int32_t ;
struct TYPE_57__ {int channels; int nb_samples; int /*<<< orphan*/ ** data; int /*<<< orphan*/  format; } ;
struct TYPE_56__ {int size; int /*<<< orphan*/  duration; int /*<<< orphan*/  pts; int /*<<< orphan*/ * data; } ;
struct TYPE_55__ {int hd; int sync_idx; int block_size; int /*<<< orphan*/  afq; TYPE_6__* channels; } ;
struct TYPE_50__ {int /*<<< orphan*/  outer_filter_signal; int /*<<< orphan*/ * inner_filter_signal; } ;
struct TYPE_54__ {int codeword_history; int* dither; int dither_parity; TYPE_1__* quantize; TYPE_3__* prediction; TYPE_4__* invert_quantize; TYPE_2__ qmf; } ;
struct TYPE_53__ {int* quantize_intervals; int* quantize_dither_factors; int* invert_quantize_dither_factors; int* quantize_factor_select_offset; int factor_max; int prediction_order; int /*<<< orphan*/  tables_size; } ;
struct TYPE_52__ {int quantization_factor; int reconstructed_difference; int factor_select; } ;
struct TYPE_51__ {int predicted_sample; int previous_reconstructed_sample; int* reconstructed_differences; int pos; int* s_weight; int* d_weight; int predicted_difference; int* prev_sign; } ;
struct TYPE_49__ {scalar_t__ error; int quantized_sample; int quantized_sample_parity_change; } ;
struct TYPE_48__ {TYPE_7__* priv_data; } ;
typedef  TYPE_1__ Quantize ;
typedef  TYPE_2__ QMFAnalysis ;
typedef  TYPE_3__ Prediction ;
typedef  TYPE_4__ InvertQuantize ;
typedef  TYPE_5__ ConstTables ;
typedef  TYPE_6__ Channel ;
typedef  TYPE_7__ AptXContext ;
typedef  TYPE_8__ AVPacket ;
typedef  TYPE_9__ AVFrame ;
typedef  TYPE_10__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int AV_RB16 (int /*<<< orphan*/  const*) ; 
 int AV_RB24 (int /*<<< orphan*/  const*) ; 
 scalar_t__ AV_RN32A (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AV_SAMPLE_FMT_S32P ; 
 int /*<<< orphan*/  AV_WB16 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  AV_WB24 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  AV_WN32A (int /*<<< orphan*/ *,int) ; 
 void* FFABS (int) ; 
 int FFDIFFSIGN (int,int) ; 
 int FFMIN (int,int) ; 
 int FF_SIGNBIT (int) ; 
 size_t LEFT ; 
 int MUL64 (int,int) ; 
 int /*<<< orphan*/  MULH (int,int) ; 
 int NB_CHANNELS ; 
 int NB_SUBBANDS ; 
 size_t RIGHT ; 
 int aptx_bin_search (int,int,int const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  aptx_qmf_inner_coeffs ; 
 int /*<<< orphan*/  aptx_qmf_outer_coeffs ; 
 int /*<<< orphan*/  aptx_qmf_polyphase_analysis (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int*,int*,int*) ; 
 int /*<<< orphan*/  aptx_qmf_polyphase_synthesis (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int*) ; 
 int /*<<< orphan*/  aptx_update_codeword_history (TYPE_6__*) ; 
 int av_clip (int,int,int) ; 
 void* av_clip_intp2 (int,int) ; 
 int /*<<< orphan*/  av_log (TYPE_10__*,int /*<<< orphan*/ ,char*) ; 
 int ff_af_queue_add (int /*<<< orphan*/ *,TYPE_9__ const*) ; 
 int /*<<< orphan*/  ff_af_queue_remove (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ff_alloc_packet2 (TYPE_10__*,TYPE_8__*,int,int /*<<< orphan*/ ) ; 
 int ff_get_buffer (TYPE_10__*,TYPE_9__*,int /*<<< orphan*/ ) ; 
 int* quantization_factors ; 
 int rshift32 (int,int) ; 
 int rshift32_clip24 (int /*<<< orphan*/ ,int) ; 
 int rshift64 (int,int) ; 
 int rshift64_clip24 (int,int) ; 
 void* sign_extend (int,int) ; 
 TYPE_5__** tables ; 

__attribute__((used)) static inline int8_t ff_u8_to_s8(uint8_t a)
{
    union {
        uint8_t u8;
        int8_t  s8;
    } b;
    b.u8 = a;
    return b.s8;
}

__attribute__((used)) static void aptx_generate_dither(Channel *channel)
{
    int subband;
    int64_t m;
    int32_t d;

    aptx_update_codeword_history(channel);

    m = (int64_t)5184443 * (channel->codeword_history >> 7);
    d = (m << 2) + (m >> 22);
    for (subband = 0; subband < NB_SUBBANDS; subband++)
        channel->dither[subband] = d << (23 - 5*subband);
    channel->dither_parity = (d >> 25) & 1;
}

__attribute__((used)) static void aptx_qmf_tree_analysis(QMFAnalysis *qmf,
                                   int32_t samples[4],
                                   int32_t subband_samples[4])
{
    int32_t intermediate_samples[4];
    int i;

    /* Split 4 input samples into 2 intermediate subbands downsampled to 2 samples */
    for (i = 0; i < 2; i++)
        aptx_qmf_polyphase_analysis(qmf->outer_filter_signal,
                                    aptx_qmf_outer_coeffs, 23,
                                    &samples[2*i],
                                    &intermediate_samples[0+i],
                                    &intermediate_samples[2+i]);

    /* Split 2 intermediate subband samples into 4 final subbands downsampled to 1 sample */
    for (i = 0; i < 2; i++)
        aptx_qmf_polyphase_analysis(qmf->inner_filter_signal[i],
                                    aptx_qmf_inner_coeffs, 23,
                                    &intermediate_samples[2*i],
                                    &subband_samples[2*i+0],
                                    &subband_samples[2*i+1]);
}

__attribute__((used)) static void aptx_qmf_tree_synthesis(QMFAnalysis *qmf,
                                    int32_t subband_samples[4],
                                    int32_t samples[4])
{
    int32_t intermediate_samples[4];
    int i;

    /* Join 4 subbands into 2 intermediate subbands upsampled to 2 samples. */
    for (i = 0; i < 2; i++)
        aptx_qmf_polyphase_synthesis(qmf->inner_filter_signal[i],
                                     aptx_qmf_inner_coeffs, 22,
                                     subband_samples[2*i+0],
                                     subband_samples[2*i+1],
                                     &intermediate_samples[2*i]);

    /* Join 2 samples from intermediate subbands upsampled to 4 samples. */
    for (i = 0; i < 2; i++)
        aptx_qmf_polyphase_synthesis(qmf->outer_filter_signal,
                                     aptx_qmf_outer_coeffs, 21,
                                     intermediate_samples[0+i],
                                     intermediate_samples[2+i],
                                     &samples[2*i]);
}

__attribute__((used)) static void aptx_quantize_difference(Quantize *quantize,
                                     int32_t sample_difference,
                                     int32_t dither,
                                     int32_t quantization_factor,
                                     ConstTables *tables)
{
    const int32_t *intervals = tables->quantize_intervals;
    int32_t quantized_sample, dithered_sample, parity_change;
    int32_t d, mean, interval, inv, sample_difference_abs;
    int64_t error;

    sample_difference_abs = FFABS(sample_difference);
    sample_difference_abs = FFMIN(sample_difference_abs, (1 << 23) - 1);

    quantized_sample = aptx_bin_search(sample_difference_abs >> 4,
                                       quantization_factor,
                                       intervals, tables->tables_size);

    d = rshift32_clip24(MULH(dither, dither), 7) - (1 << 23);
    d = rshift64(MUL64(d, tables->quantize_dither_factors[quantized_sample]), 23);

    intervals += quantized_sample;
    mean = (intervals[1] + intervals[0]) / 2;
    interval = (intervals[1] - intervals[0]) * (-(sample_difference < 0) | 1);

    dithered_sample = rshift64_clip24(MUL64(dither, interval) + ((int64_t)av_clip_intp2(mean + d, 23) << 32), 32);
    error = ((int64_t)sample_difference_abs << 20) - MUL64(dithered_sample, quantization_factor);
    quantize->error = FFABS(rshift64(error, 23));

    parity_change = quantized_sample;
    if (error < 0)
        quantized_sample--;
    else
        parity_change--;

    inv = -(sample_difference < 0);
    quantize->quantized_sample               = quantized_sample ^ inv;
    quantize->quantized_sample_parity_change = parity_change    ^ inv;
}

__attribute__((used)) static void aptx_encode_channel(Channel *channel, int32_t samples[4], int hd)
{
    int32_t subband_samples[4];
    int subband;
    aptx_qmf_tree_analysis(&channel->qmf, samples, subband_samples);
    aptx_generate_dither(channel);
    for (subband = 0; subband < NB_SUBBANDS; subband++) {
        int32_t diff = av_clip_intp2(subband_samples[subband] - channel->prediction[subband].predicted_sample, 23);
        aptx_quantize_difference(&channel->quantize[subband], diff,
                                 channel->dither[subband],
                                 channel->invert_quantize[subband].quantization_factor,
                                 &tables[hd][subband]);
    }
}

__attribute__((used)) static void aptx_decode_channel(Channel *channel, int32_t samples[4])
{
    int32_t subband_samples[4];
    int subband;
    for (subband = 0; subband < NB_SUBBANDS; subband++)
        subband_samples[subband] = channel->prediction[subband].previous_reconstructed_sample;
    aptx_qmf_tree_synthesis(&channel->qmf, subband_samples, samples);
}

__attribute__((used)) static void aptx_invert_quantization(InvertQuantize *invert_quantize,
                                     int32_t quantized_sample, int32_t dither,
                                     ConstTables *tables)
{
    int32_t qr, idx, shift, factor_select;

    idx = (quantized_sample ^ -(quantized_sample < 0)) + 1;
    qr = tables->quantize_intervals[idx] / 2;
    if (quantized_sample < 0)
        qr = -qr;

    qr = rshift64_clip24(((int64_t)qr<<32) + MUL64(dither, tables->invert_quantize_dither_factors[idx]), 32);
    invert_quantize->reconstructed_difference = MUL64(invert_quantize->quantization_factor, qr) >> 19;

    /* update factor_select */
    factor_select = 32620 * invert_quantize->factor_select;
    factor_select = rshift32(factor_select + (tables->quantize_factor_select_offset[idx] << 15), 15);
    invert_quantize->factor_select = av_clip(factor_select, 0, tables->factor_max);

    /* update quantization factor */
    idx = (invert_quantize->factor_select & 0xFF) >> 3;
    shift = (tables->factor_max - invert_quantize->factor_select) >> 8;
    invert_quantize->quantization_factor = (quantization_factors[idx] << 11) >> shift;
}

__attribute__((used)) static int32_t *aptx_reconstructed_differences_update(Prediction *prediction,
                                                      int32_t reconstructed_difference,
                                                      int order)
{
    int32_t *rd1 = prediction->reconstructed_differences, *rd2 = rd1 + order;
    int p = prediction->pos;

    rd1[p] = rd2[p];
    prediction->pos = p = (p + 1) % order;
    rd2[p] = reconstructed_difference;
    return &rd2[p];
}

__attribute__((used)) static void aptx_prediction_filtering(Prediction *prediction,
                                      int32_t reconstructed_difference,
                                      int order)
{
    int32_t reconstructed_sample, predictor, srd0;
    int32_t *reconstructed_differences;
    int64_t predicted_difference = 0;
    int i;

    reconstructed_sample = av_clip_intp2(reconstructed_difference + prediction->predicted_sample, 23);
    predictor = av_clip_intp2((MUL64(prediction->s_weight[0], prediction->previous_reconstructed_sample)
                             + MUL64(prediction->s_weight[1], reconstructed_sample)) >> 22, 23);
    prediction->previous_reconstructed_sample = reconstructed_sample;

    reconstructed_differences = aptx_reconstructed_differences_update(prediction, reconstructed_difference, order);
    srd0 = FFDIFFSIGN(reconstructed_difference, 0) << 23;
    for (i = 0; i < order; i++) {
        int32_t srd = FF_SIGNBIT(reconstructed_differences[-i-1]) | 1;
        prediction->d_weight[i] -= rshift32(prediction->d_weight[i] - srd*srd0, 8);
        predicted_difference += MUL64(reconstructed_differences[-i], prediction->d_weight[i]);
    }

    prediction->predicted_difference = av_clip_intp2(predicted_difference >> 22, 23);
    prediction->predicted_sample = av_clip_intp2(predictor + prediction->predicted_difference, 23);
}

__attribute__((used)) static void aptx_process_subband(InvertQuantize *invert_quantize,
                                 Prediction *prediction,
                                 int32_t quantized_sample, int32_t dither,
                                 ConstTables *tables)
{
    int32_t sign, same_sign[2], weight[2], sw1, range;

    aptx_invert_quantization(invert_quantize, quantized_sample, dither, tables);

    sign = FFDIFFSIGN(invert_quantize->reconstructed_difference,
                      -prediction->predicted_difference);
    same_sign[0] = sign * prediction->prev_sign[0];
    same_sign[1] = sign * prediction->prev_sign[1];
    prediction->prev_sign[0] = prediction->prev_sign[1];
    prediction->prev_sign[1] = sign | 1;

    range = 0x100000;
    sw1 = rshift32(-same_sign[1] * prediction->s_weight[1], 1);
    sw1 = (av_clip(sw1, -range, range) & ~0xF) << 4;

    range = 0x300000;
    weight[0] = 254 * prediction->s_weight[0] + 0x800000*same_sign[0] + sw1;
    prediction->s_weight[0] = av_clip(rshift32(weight[0], 8), -range, range);

    range = 0x3C0000 - prediction->s_weight[0];
    weight[1] = 255 * prediction->s_weight[1] + 0xC00000*same_sign[1];
    prediction->s_weight[1] = av_clip(rshift32(weight[1], 8), -range, range);

    aptx_prediction_filtering(prediction,
                              invert_quantize->reconstructed_difference,
                              tables->prediction_order);
}

__attribute__((used)) static void aptx_invert_quantize_and_prediction(Channel *channel, int hd)
{
    int subband;
    for (subband = 0; subband < NB_SUBBANDS; subband++)
        aptx_process_subband(&channel->invert_quantize[subband],
                             &channel->prediction[subband],
                             channel->quantize[subband].quantized_sample,
                             channel->dither[subband],
                             &tables[hd][subband]);
}

__attribute__((used)) static int32_t aptx_quantized_parity(Channel *channel)
{
    int32_t parity = channel->dither_parity;
    int subband;

    for (subband = 0; subband < NB_SUBBANDS; subband++)
        parity ^= channel->quantize[subband].quantized_sample;

    return parity & 1;
}

__attribute__((used)) static int aptx_check_parity(Channel channels[NB_CHANNELS], int32_t *idx)
{
    int32_t parity = aptx_quantized_parity(&channels[LEFT])
                   ^ aptx_quantized_parity(&channels[RIGHT]);

    int eighth = *idx == 7;
    *idx = (*idx + 1) & 7;

    return parity ^ eighth;
}

__attribute__((used)) static void aptx_insert_sync(Channel channels[NB_CHANNELS], int32_t *idx)
{
    if (aptx_check_parity(channels, idx)) {
        int i;
        Channel *c;
        static const int map[] = { 1, 2, 0, 3 };
        Quantize *min = &channels[NB_CHANNELS-1].quantize[map[0]];
        for (c = &channels[NB_CHANNELS-1]; c >= channels; c--)
            for (i = 0; i < NB_SUBBANDS; i++)
                if (c->quantize[map[i]].error < min->error)
                    min = &c->quantize[map[i]];

        /* Forcing the desired parity is done by offsetting by 1 the quantized
         * sample from the subband featuring the smallest quantization error. */
        min->quantized_sample = min->quantized_sample_parity_change;
    }
}

__attribute__((used)) static uint16_t aptx_pack_codeword(Channel *channel)
{
    int32_t parity = aptx_quantized_parity(channel);
    return (((channel->quantize[3].quantized_sample & 0x06) | parity) << 13)
         | (((channel->quantize[2].quantized_sample & 0x03)         ) << 11)
         | (((channel->quantize[1].quantized_sample & 0x0F)         ) <<  7)
         | (((channel->quantize[0].quantized_sample & 0x7F)         ) <<  0);
}

__attribute__((used)) static uint32_t aptxhd_pack_codeword(Channel *channel)
{
    int32_t parity = aptx_quantized_parity(channel);
    return (((channel->quantize[3].quantized_sample & 0x01E) | parity) << 19)
         | (((channel->quantize[2].quantized_sample & 0x00F)         ) << 15)
         | (((channel->quantize[1].quantized_sample & 0x03F)         ) <<  9)
         | (((channel->quantize[0].quantized_sample & 0x1FF)         ) <<  0);
}

__attribute__((used)) static void aptx_unpack_codeword(Channel *channel, uint16_t codeword)
{
    channel->quantize[0].quantized_sample = sign_extend(codeword >>  0, 7);
    channel->quantize[1].quantized_sample = sign_extend(codeword >>  7, 4);
    channel->quantize[2].quantized_sample = sign_extend(codeword >> 11, 2);
    channel->quantize[3].quantized_sample = sign_extend(codeword >> 13, 3);
    channel->quantize[3].quantized_sample = (channel->quantize[3].quantized_sample & ~1)
                                          | aptx_quantized_parity(channel);
}

__attribute__((used)) static void aptxhd_unpack_codeword(Channel *channel, uint32_t codeword)
{
    channel->quantize[0].quantized_sample = sign_extend(codeword >>  0, 9);
    channel->quantize[1].quantized_sample = sign_extend(codeword >>  9, 6);
    channel->quantize[2].quantized_sample = sign_extend(codeword >> 15, 4);
    channel->quantize[3].quantized_sample = sign_extend(codeword >> 19, 5);
    channel->quantize[3].quantized_sample = (channel->quantize[3].quantized_sample & ~1)
                                          | aptx_quantized_parity(channel);
}

__attribute__((used)) static void aptx_encode_samples(AptXContext *ctx,
                                int32_t samples[NB_CHANNELS][4],
                                uint8_t *output)
{
    int channel;
    for (channel = 0; channel < NB_CHANNELS; channel++)
        aptx_encode_channel(&ctx->channels[channel], samples[channel], ctx->hd);

    aptx_insert_sync(ctx->channels, &ctx->sync_idx);

    for (channel = 0; channel < NB_CHANNELS; channel++) {
        aptx_invert_quantize_and_prediction(&ctx->channels[channel], ctx->hd);
        if (ctx->hd)
            AV_WB24(output + 3*channel,
                    aptxhd_pack_codeword(&ctx->channels[channel]));
        else
            AV_WB16(output + 2*channel,
                    aptx_pack_codeword(&ctx->channels[channel]));
    }
}

__attribute__((used)) static int aptx_decode_samples(AptXContext *ctx,
                                const uint8_t *input,
                                int32_t samples[NB_CHANNELS][4])
{
    int channel, ret;

    for (channel = 0; channel < NB_CHANNELS; channel++) {
        aptx_generate_dither(&ctx->channels[channel]);

        if (ctx->hd)
            aptxhd_unpack_codeword(&ctx->channels[channel],
                                   AV_RB24(input + 3*channel));
        else
            aptx_unpack_codeword(&ctx->channels[channel],
                                 AV_RB16(input + 2*channel));
        aptx_invert_quantize_and_prediction(&ctx->channels[channel], ctx->hd);
    }

    ret = aptx_check_parity(ctx->channels, &ctx->sync_idx);

    for (channel = 0; channel < NB_CHANNELS; channel++)
        aptx_decode_channel(&ctx->channels[channel], samples[channel]);

    return ret;
}

__attribute__((used)) static int aptx_decode_frame(AVCodecContext *avctx, void *data,
                             int *got_frame_ptr, AVPacket *avpkt)
{
    AptXContext *s = avctx->priv_data;
    AVFrame *frame = data;
    int pos, opos, channel, sample, ret;

    if (avpkt->size < s->block_size) {
        av_log(avctx, AV_LOG_ERROR, "Packet is too small\n");
        return AVERROR_INVALIDDATA;
    }

    /* get output buffer */
    frame->channels = NB_CHANNELS;
    frame->format = AV_SAMPLE_FMT_S32P;
    frame->nb_samples = 4 * avpkt->size / s->block_size;
    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
        return ret;

    for (pos = 0, opos = 0; opos < frame->nb_samples; pos += s->block_size, opos += 4) {
        int32_t samples[NB_CHANNELS][4];

        if (aptx_decode_samples(s, &avpkt->data[pos], samples)) {
            av_log(avctx, AV_LOG_ERROR, "Synchronization error\n");
            return AVERROR_INVALIDDATA;
        }

        for (channel = 0; channel < NB_CHANNELS; channel++)
            for (sample = 0; sample < 4; sample++)
                AV_WN32A(&frame->data[channel][4*(opos+sample)],
                         samples[channel][sample] << 8);
    }

    *got_frame_ptr = 1;
    return s->block_size * frame->nb_samples / 4;
}

__attribute__((used)) static int aptx_encode_frame(AVCodecContext *avctx, AVPacket *avpkt,
                             const AVFrame *frame, int *got_packet_ptr)
{
    AptXContext *s = avctx->priv_data;
    int pos, ipos, channel, sample, output_size, ret;

    if ((ret = ff_af_queue_add(&s->afq, frame)) < 0)
        return ret;

    output_size = s->block_size * frame->nb_samples/4;
    if ((ret = ff_alloc_packet2(avctx, avpkt, output_size, 0)) < 0)
        return ret;

    for (pos = 0, ipos = 0; pos < output_size; pos += s->block_size, ipos += 4) {
        int32_t samples[NB_CHANNELS][4];

        for (channel = 0; channel < NB_CHANNELS; channel++)
            for (sample = 0; sample < 4; sample++)
                samples[channel][sample] = (int32_t)AV_RN32A(&frame->data[channel][4*(ipos+sample)]) >> 8;

        aptx_encode_samples(s, samples, avpkt->data + pos);
    }

    ff_af_queue_remove(&s->afq, frame->nb_samples, &avpkt->pts, &avpkt->duration);
    *got_packet_ptr = 1;
    return 0;
}

