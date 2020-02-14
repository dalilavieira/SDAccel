#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
struct TYPE_15__ {scalar_t__ channel_layouts; scalar_t__ sample_rates; scalar_t__ formats; } ;
struct TYPE_14__ {TYPE_3__* priv; int /*<<< orphan*/  outputs; int /*<<< orphan*/  output_pads; int /*<<< orphan*/  nb_outputs; int /*<<< orphan*/  inputs; int /*<<< orphan*/  input_pads; int /*<<< orphan*/  nb_inputs; } ;
struct TYPE_13__ {size_t queued; scalar_t__ total_samples_tail; scalar_t__ total_samples_head; } ;
typedef  TYPE_1__ FFFrameQueue ;
typedef  int /*<<< orphan*/  AVFilterPad ;
typedef  TYPE_2__ AVFilterContext ;
typedef  TYPE_3__ AFormatContext ;

/* Variables and functions */
 int /*<<< orphan*/  AVFilterLink ; 
 int /*<<< orphan*/  AVMEDIA_TYPE_AUDIO ; 
 int FFMAX (int,int /*<<< orphan*/ ) ; 
#define  FF_QSCALE_TYPE_H264 131 
#define  FF_QSCALE_TYPE_MPEG1 130 
#define  FF_QSCALE_TYPE_MPEG2 129 
#define  FF_QSCALE_TYPE_VP56 128 
 int /*<<< orphan*/  dstpad ; 
 scalar_t__ ff_all_channel_counts () ; 
 scalar_t__ ff_all_formats (int /*<<< orphan*/ ) ; 
 scalar_t__ ff_all_samplerates () ; 
 int ff_insert_pad (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ff_set_common_channel_layouts (TYPE_2__*,scalar_t__) ; 
 int ff_set_common_formats (TYPE_2__*,scalar_t__) ; 
 int ff_set_common_samplerates (TYPE_2__*,scalar_t__) ; 
 int /*<<< orphan*/  offsetof (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  srcpad ; 
 int strtol (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline size_t ff_framequeue_queued_frames(const FFFrameQueue *fq)
{
    return fq->queued;
}

__attribute__((used)) static inline uint64_t ff_framequeue_queued_samples(const FFFrameQueue *fq)
{
    return fq->total_samples_head - fq->total_samples_tail;
}

__attribute__((used)) static inline void ff_framequeue_update_peeked(FFFrameQueue *fq, size_t idx)
{
}

__attribute__((used)) static inline int ff_insert_inpad(AVFilterContext *f, unsigned index,
                                   AVFilterPad *p)
{
    return ff_insert_pad(index, &f->nb_inputs, offsetof(AVFilterLink, dstpad),
                  &f->input_pads, &f->inputs, p);
}

__attribute__((used)) static inline int ff_insert_outpad(AVFilterContext *f, unsigned index,
                                    AVFilterPad *p)
{
    return ff_insert_pad(index, &f->nb_outputs, offsetof(AVFilterLink, srcpad),
                  &f->output_pads, &f->outputs, p);
}

__attribute__((used)) static inline int ff_norm_qscale(int qscale, int type)
{
    switch (type) {
    case FF_QSCALE_TYPE_MPEG1: return qscale;
    case FF_QSCALE_TYPE_MPEG2: return qscale >> 1;
    case FF_QSCALE_TYPE_H264:  return qscale >> 2;
    case FF_QSCALE_TYPE_VP56:  return (63 - qscale + 2) >> 2;
    }
    return qscale;
}

__attribute__((used)) static int get_sample_rate(const char *samplerate)
{
    int ret = strtol(samplerate, NULL, 0);
    return FFMAX(ret, 0);
}

__attribute__((used)) static int query_formats(AVFilterContext *ctx)
{
    AFormatContext *s = ctx->priv;
    int ret;

    ret = ff_set_common_formats(ctx, s->formats ? s->formats :
                                            ff_all_formats(AVMEDIA_TYPE_AUDIO));
    if (ret < 0)
        return ret;
    ret = ff_set_common_samplerates(ctx, s->sample_rates ? s->sample_rates :
                                                     ff_all_samplerates());
    if (ret < 0)
        return ret;
    return ff_set_common_channel_layouts(ctx, s->channel_layouts ? s->channel_layouts :
                                                            ff_all_channel_counts());
}

