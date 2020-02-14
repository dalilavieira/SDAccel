#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_7__ ;
typedef  struct TYPE_29__   TYPE_6__ ;
typedef  struct TYPE_28__   TYPE_5__ ;
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  int (* avfilter_action_func ) (TYPE_4__*,void*,int,int) ;
struct TYPE_28__ {int (* func ) (TYPE_4__*,void*,int,int) ;int* rets; int /*<<< orphan*/  thread; void* arg; TYPE_4__* ctx; } ;
typedef  TYPE_5__ ThreadContext ;
struct TYPE_30__ {int nb_threads; TYPE_3__* internal; scalar_t__ thread_type; } ;
struct TYPE_29__ {size_t queued; scalar_t__ total_samples_tail; scalar_t__ total_samples_head; } ;
struct TYPE_27__ {TYPE_2__* graph; int /*<<< orphan*/  outputs; int /*<<< orphan*/  output_pads; int /*<<< orphan*/  nb_outputs; int /*<<< orphan*/  inputs; int /*<<< orphan*/  input_pads; int /*<<< orphan*/  nb_inputs; } ;
struct TYPE_26__ {int (* thread_execute ) (TYPE_4__*,int (*) (TYPE_4__*,void*,int,int),void*,int*,int) ;TYPE_5__* thread; } ;
struct TYPE_25__ {TYPE_1__* internal; } ;
struct TYPE_24__ {TYPE_5__* thread; } ;
typedef  TYPE_6__ FFFrameQueue ;
typedef  int /*<<< orphan*/  AVFilterPad ;
typedef  TYPE_7__ AVFilterGraph ;
typedef  TYPE_4__ AVFilterContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AVFilterLink ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FFMAX (int,int) ; 
#define  FF_QSCALE_TYPE_H264 131 
#define  FF_QSCALE_TYPE_MPEG1 130 
#define  FF_QSCALE_TYPE_MPEG2 129 
#define  FF_QSCALE_TYPE_VP56 128 
 int /*<<< orphan*/  av_freep (TYPE_5__**) ; 
 TYPE_5__* av_mallocz (int) ; 
 int avpriv_slicethread_create (int /*<<< orphan*/ *,TYPE_5__*,void (*) (void*,int,int,int,int),int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  avpriv_slicethread_execute (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avpriv_slicethread_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dstpad ; 
 int ff_insert_pad (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  offsetof (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  srcpad ; 
 int stub1 (TYPE_4__*,void*,int,int) ; 

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

__attribute__((used)) static void worker_func(void *priv, int jobnr, int threadnr, int nb_jobs, int nb_threads)
{
    ThreadContext *c = priv;
    int ret = c->func(c->ctx, c->arg, jobnr, nb_jobs);
    if (c->rets)
        c->rets[jobnr] = ret;
}

__attribute__((used)) static void slice_thread_uninit(ThreadContext *c)
{
    avpriv_slicethread_free(&c->thread);
}

__attribute__((used)) static int thread_execute(AVFilterContext *ctx, avfilter_action_func *func,
                          void *arg, int *ret, int nb_jobs)
{
    ThreadContext *c = ctx->graph->internal->thread;

    if (nb_jobs <= 0)
        return 0;
    c->ctx         = ctx;
    c->arg         = arg;
    c->func        = func;
    c->rets        = ret;

    avpriv_slicethread_execute(c->thread, nb_jobs, 0);
    return 0;
}

__attribute__((used)) static int thread_init_internal(ThreadContext *c, int nb_threads)
{
    nb_threads = avpriv_slicethread_create(&c->thread, c, worker_func, NULL, nb_threads);
    if (nb_threads <= 1)
        avpriv_slicethread_free(&c->thread);
    return FFMAX(nb_threads, 1);
}

int ff_graph_thread_init(AVFilterGraph *graph)
{
    int ret;

    if (graph->nb_threads == 1) {
        graph->thread_type = 0;
        return 0;
    }

    graph->internal->thread = av_mallocz(sizeof(ThreadContext));
    if (!graph->internal->thread)
        return AVERROR(ENOMEM);

    ret = thread_init_internal(graph->internal->thread, graph->nb_threads);
    if (ret <= 1) {
        av_freep(&graph->internal->thread);
        graph->thread_type = 0;
        graph->nb_threads  = 1;
        return (ret < 0) ? ret : 0;
    }
    graph->nb_threads = ret;

    graph->internal->thread_execute = thread_execute;

    return 0;
}

void ff_graph_thread_free(AVFilterGraph *graph)
{
    if (graph->internal->thread)
        slice_thread_uninit(graph->internal->thread);
    av_freep(&graph->internal->thread);
}

