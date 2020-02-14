#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint64_t ;
struct TYPE_27__ {size_t nb_samples; int channels; scalar_t__ pts; size_t* linesize; size_t* extended_data; size_t* data; int /*<<< orphan*/  sample_rate; int /*<<< orphan*/  format; } ;
struct TYPE_26__ {TYPE_3__* frame; } ;
struct TYPE_25__ {size_t queued; size_t total_samples_head; size_t total_samples_tail; size_t tail; int allocated; int samples_skipped; int /*<<< orphan*/  total_frames_tail; int /*<<< orphan*/  total_frames_head; TYPE_2__* queue; TYPE_2__ first_bucket; } ;
typedef  int /*<<< orphan*/  FFFrameQueueGlobal ;
typedef  TYPE_1__ FFFrameQueue ;
typedef  TYPE_2__ FFFrameBucket ;
typedef  int /*<<< orphan*/  AVRational ;
typedef  TYPE_3__ AVFrame ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ AV_NOPTS_VALUE ; 
 int AV_NUM_DATA_POINTERS ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  av_assert1 (int) ; 
 int /*<<< orphan*/  av_frame_free (TYPE_3__**) ; 
 int /*<<< orphan*/  av_freep (TYPE_2__**) ; 
 size_t av_get_bytes_per_sample (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_make_q (int,int /*<<< orphan*/ ) ; 
 TYPE_2__* av_realloc_array (TYPE_2__*,size_t,int) ; 
 scalar_t__ av_rescale_q (size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int av_sample_fmt_is_planar (int /*<<< orphan*/ ) ; 
 TYPE_3__* ff_framequeue_take (TYPE_1__*) ; 
 int /*<<< orphan*/  memmove (TYPE_2__*,TYPE_2__*,int) ; 

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

__attribute__((used)) static inline FFFrameBucket *bucket(FFFrameQueue *fq, size_t idx)
{
    return &fq->queue[(fq->tail + idx) & (fq->allocated - 1)];
}

void ff_framequeue_global_init(FFFrameQueueGlobal *fqg)
{
}

__attribute__((used)) static void check_consistency(FFFrameQueue *fq)
{
#if defined(ASSERT_LEVEL) && ASSERT_LEVEL >= 2
    uint64_t nb_samples = 0;
    size_t i;

    av_assert0(fq->queued == fq->total_frames_head - fq->total_frames_tail);
    for (i = 0; i < fq->queued; i++)
        nb_samples += bucket(fq, i)->frame->nb_samples;
    av_assert0(nb_samples == fq->total_samples_head - fq->total_samples_tail);
#endif
}

void ff_framequeue_init(FFFrameQueue *fq, FFFrameQueueGlobal *fqg)
{
    fq->queue = &fq->first_bucket;
    fq->allocated = 1;
}

void ff_framequeue_free(FFFrameQueue *fq)
{
    while (fq->queued) {
        AVFrame *frame = ff_framequeue_take(fq);
        av_frame_free(&frame);
    }
    if (fq->queue != &fq->first_bucket)
        av_freep(&fq->queue);
}

int ff_framequeue_add(FFFrameQueue *fq, AVFrame *frame)
{
    FFFrameBucket *b;

    check_consistency(fq);
    if (fq->queued == fq->allocated) {
        if (fq->allocated == 1) {
            size_t na = 8;
            FFFrameBucket *nq = av_realloc_array(NULL, na, sizeof(*nq));
            if (!nq)
                return AVERROR(ENOMEM);
            nq[0] = fq->queue[0];
            fq->queue = nq;
            fq->allocated = na;
        } else {
            size_t na = fq->allocated << 1;
            FFFrameBucket *nq = av_realloc_array(fq->queue, na, sizeof(*nq));
            if (!nq)
                return AVERROR(ENOMEM);
            if (fq->tail + fq->queued > fq->allocated)
                memmove(nq + fq->allocated, nq,
                        (fq->tail + fq->queued - fq->allocated) * sizeof(*nq));
            fq->queue = nq;
            fq->allocated = na;
        }
    }
    b = bucket(fq, fq->queued);
    b->frame = frame;
    fq->queued++;
    fq->total_frames_head++;
    fq->total_samples_head += frame->nb_samples;
    check_consistency(fq);
    return 0;
}

AVFrame *ff_framequeue_take(FFFrameQueue *fq)
{
    FFFrameBucket *b;

    check_consistency(fq);
    av_assert1(fq->queued);
    b = bucket(fq, 0);
    fq->queued--;
    fq->tail++;
    fq->tail &= fq->allocated - 1;
    fq->total_frames_tail++;
    fq->total_samples_tail += b->frame->nb_samples;
    fq->samples_skipped = 0;
    check_consistency(fq);
    return b->frame;
}

AVFrame *ff_framequeue_peek(FFFrameQueue *fq, size_t idx)
{
    FFFrameBucket *b;

    check_consistency(fq);
    av_assert1(idx < fq->queued);
    b = bucket(fq, idx);
    check_consistency(fq);
    return b->frame;
}

void ff_framequeue_skip_samples(FFFrameQueue *fq, size_t samples, AVRational time_base)
{
    FFFrameBucket *b;
    size_t bytes;
    int planar, planes, i;

    check_consistency(fq);
    av_assert1(fq->queued);
    b = bucket(fq, 0);
    av_assert1(samples < b->frame->nb_samples);
    planar = av_sample_fmt_is_planar(b->frame->format);
    planes = planar ? b->frame->channels : 1;
    bytes = samples * av_get_bytes_per_sample(b->frame->format);
    if (!planar)
        bytes *= b->frame->channels;
    if (b->frame->pts != AV_NOPTS_VALUE)
        b->frame->pts += av_rescale_q(samples, av_make_q(1, b->frame->sample_rate), time_base);
    b->frame->nb_samples -= samples;
    b->frame->linesize[0] -= bytes;
    for (i = 0; i < planes; i++)
        b->frame->extended_data[i] += bytes;
    for (i = 0; i < planes && i < AV_NUM_DATA_POINTERS; i++)
        b->frame->data[i] = b->frame->extended_data[i];
    fq->total_samples_tail += samples;
    fq->samples_skipped = 1;
    ff_framequeue_update_peeked(fq, 0);
}

