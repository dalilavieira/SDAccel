#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int int64_t ;
struct TYPE_25__ {scalar_t__ channel_layout; scalar_t__ format; scalar_t__ sample_rate; int nb_samples; int* linesize; int /*<<< orphan*/ ** extended_data; } ;
struct TYPE_24__ {scalar_t__ in_ch_layout; scalar_t__ in_sample_rate; scalar_t__ in_sample_fmt; scalar_t__ out_ch_layout; scalar_t__ out_sample_rate; scalar_t__ out_sample_fmt; } ;
typedef  TYPE_1__ SwrContext ;
typedef  TYPE_2__ AVFrame ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INPUT_CHANGED ; 
 int AVERROR_OUTPUT_CHANGED ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  EINVAL ; 
 int av_frame_get_buffer (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int av_get_bytes_per_sample (scalar_t__) ; 
 int av_get_channel_layout_nb_channels (scalar_t__) ; 
 int /*<<< orphan*/  av_log (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ av_opt_set_int (TYPE_1__*,char*,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ av_sample_fmt_is_planar (scalar_t__) ; 
 int /*<<< orphan*/  swr_close (TYPE_1__*) ; 
 int swr_convert (TYPE_1__*,int /*<<< orphan*/ **,int,int /*<<< orphan*/  const**,int) ; 
 int swr_get_delay (TYPE_1__*,scalar_t__) ; 
 int swr_init (TYPE_1__*) ; 
 int /*<<< orphan*/  swr_is_initialized (TYPE_1__*) ; 

int swr_config_frame(SwrContext *s, const AVFrame *out, const AVFrame *in)
{
    swr_close(s);

    if (in) {
        if (av_opt_set_int(s, "icl", in->channel_layout, 0) < 0)
            goto fail;
        if (av_opt_set_int(s, "isf", in->format, 0) < 0)
            goto fail;
        if (av_opt_set_int(s, "isr", in->sample_rate, 0) < 0)
            goto fail;
    }

    if (out) {
        if (av_opt_set_int(s, "ocl", out->channel_layout, 0) < 0)
            goto fail;
        if (av_opt_set_int(s, "osf", out->format,  0) < 0)
            goto fail;
        if (av_opt_set_int(s, "osr", out->sample_rate, 0) < 0)
            goto fail;
    }

    return 0;
fail:
    av_log(s, AV_LOG_ERROR, "Failed to set option\n");
    return AVERROR(EINVAL);
}

__attribute__((used)) static int config_changed(SwrContext *s,
                          const AVFrame *out, const AVFrame *in)
{
    int ret = 0;

    if (in) {
        if (s->in_ch_layout   != in->channel_layout ||
            s->in_sample_rate != in->sample_rate ||
            s->in_sample_fmt  != in->format) {
            ret |= AVERROR_INPUT_CHANGED;
        }
    }

    if (out) {
        if (s->out_ch_layout   != out->channel_layout ||
            s->out_sample_rate != out->sample_rate ||
            s->out_sample_fmt  != out->format) {
            ret |= AVERROR_OUTPUT_CHANGED;
        }
    }

    return ret;
}

__attribute__((used)) static inline int convert_frame(SwrContext *s,
                                AVFrame *out, const AVFrame *in)
{
    int ret;
    uint8_t **out_data = NULL;
    const uint8_t **in_data = NULL;
    int out_nb_samples = 0, in_nb_samples = 0;

    if (out) {
        out_data       = out->extended_data;
        out_nb_samples = out->nb_samples;
    }

    if (in) {
        in_data       = (const uint8_t **)in->extended_data;
        in_nb_samples = in->nb_samples;
    }

    ret = swr_convert(s, out_data, out_nb_samples, in_data, in_nb_samples);

    if (ret < 0) {
        if (out)
            out->nb_samples = 0;
        return ret;
    }

    if (out)
        out->nb_samples = ret;

    return 0;
}

__attribute__((used)) static inline int available_samples(AVFrame *out)
{
    int bytes_per_sample = av_get_bytes_per_sample(out->format);
    int samples = out->linesize[0] / bytes_per_sample;

    if (av_sample_fmt_is_planar(out->format)) {
        return samples;
    } else {
        int channels = av_get_channel_layout_nb_channels(out->channel_layout);
        return samples / channels;
    }
}

int swr_convert_frame(SwrContext *s,
                      AVFrame *out, const AVFrame *in)
{
    int ret, setup = 0;

    if (!swr_is_initialized(s)) {
        if ((ret = swr_config_frame(s, out, in)) < 0)
            return ret;
        if ((ret = swr_init(s)) < 0)
            return ret;
        setup = 1;
    } else {
        // return as is or reconfigure for input changes?
        if ((ret = config_changed(s, out, in)))
            return ret;
    }

    if (out) {
        if (!out->linesize[0]) {
            out->nb_samples = swr_get_delay(s, s->out_sample_rate) + 3;
            if (in) {
                out->nb_samples += in->nb_samples*(int64_t)s->out_sample_rate / s->in_sample_rate;
            }
            if ((ret = av_frame_get_buffer(out, 0)) < 0) {
                if (setup)
                    swr_close(s);
                return ret;
            }
        } else {
            if (!out->nb_samples)
                out->nb_samples = available_samples(out);
        }
    }

    return convert_frame(s, out, in);
}

