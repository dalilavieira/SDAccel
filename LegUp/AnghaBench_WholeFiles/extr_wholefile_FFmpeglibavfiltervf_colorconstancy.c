#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  double uint8_t ;
typedef  scalar_t__ uint64_t ;
typedef  int const int64_t ;
struct TYPE_18__ {int*** data; int* meta_data; TYPE_4__* in; } ;
typedef  TYPE_1__ ThreadData ;
struct TYPE_22__ {TYPE_3__* priv; int /*<<< orphan*/  outputs; int /*<<< orphan*/  output_pads; int /*<<< orphan*/  nb_outputs; int /*<<< orphan*/  inputs; int /*<<< orphan*/  input_pads; int /*<<< orphan*/  nb_inputs; } ;
struct TYPE_21__ {int* linesize; double** data; } ;
struct TYPE_20__ {int filtersize; int difford; double sigma; int** gauss; int* planeheight; int* planewidth; } ;
struct TYPE_19__ {size_t queued; scalar_t__ total_samples_tail; scalar_t__ total_samples_head; } ;
typedef  TYPE_2__ FFFrameQueue ;
typedef  TYPE_3__ ColorConstancyContext ;
typedef  TYPE_4__ AVFrame ;
typedef  int /*<<< orphan*/  AVFilterPad ;
typedef  TYPE_5__ AVFilterContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AVFilterLink ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_TRACE ; 
 int const DIR_X ; 
 int /*<<< orphan*/  ENOMEM ; 
#define  FF_QSCALE_TYPE_H264 131 
#define  FF_QSCALE_TYPE_MPEG1 130 
#define  FF_QSCALE_TYPE_MPEG2 129 
#define  FF_QSCALE_TYPE_VP56 128 
 scalar_t__ GAUSS (double const*,int,int,int const,int const,int const,double const) ; 
 size_t GINDX (int const,int) ; 
 size_t INDEX_DIR ; 
 size_t INDEX_DST ; 
 size_t INDEX_DX ; 
 size_t INDEX_DXY ; 
 size_t INDEX_DY ; 
 size_t INDEX_NORM ; 
 size_t INDEX_ORD ; 
 size_t INDEX_SRC ; 
 size_t INDX2D (int,int,int const) ; 
 int M_PI ; 
 int NUM_PLANES ; 
 int /*<<< orphan*/  av_freep (int**) ; 
 int /*<<< orphan*/  av_log (TYPE_5__*,int /*<<< orphan*/ ,char*,...) ; 
 void* av_mallocz_array (int,int) ; 
 int /*<<< orphan*/  dstpad ; 
 double exp (int) ; 
 int ff_insert_pad (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  offsetof (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pow (double const,int) ; 
 double sqrt (int) ; 
 int /*<<< orphan*/  srcpad ; 

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

__attribute__((used)) static int set_gauss(AVFilterContext *ctx)
{
    ColorConstancyContext *s = ctx->priv;
    int filtersize = s->filtersize;
    int difford    = s->difford;
    double sigma   = s->sigma;
    double sum1, sum2;
    int i;

    for (i = 0; i <= difford; ++i) {
        s->gauss[i] = av_mallocz_array(filtersize, sizeof(*s->gauss[i]));
        if (!s->gauss[i]) {
            for (; i >= 0; --i) {
                av_freep(&s->gauss[i]);
            }
            av_log(ctx, AV_LOG_ERROR, "Out of memory while allocating gauss buffers.\n");
            return AVERROR(ENOMEM);
        }
    }

    // Order 0
    av_log(ctx, AV_LOG_TRACE, "Setting 0-d gauss with filtersize = %d.\n", filtersize);
    sum1 = 0.0;
    if (!sigma) {
        s->gauss[0][0] = 1; // Copying data to double instead of convolution
    } else {
        for (i = 0; i < filtersize; ++i) {
            s->gauss[0][i] = exp(- pow(GINDX(filtersize, i), 2.) / (2 * sigma * sigma)) / ( sqrt(2 * M_PI) * sigma );
            sum1 += s->gauss[0][i];
        }
        for (i = 0; i < filtersize; ++i) {
            s->gauss[0][i] /= sum1;
        }
    }
    // Order 1
    if (difford > 0) {
        av_log(ctx, AV_LOG_TRACE, "Setting 1-d gauss with filtersize = %d.\n", filtersize);
        sum1 = 0.0;
        for (i = 0; i < filtersize; ++i) {
            s->gauss[1][i] = - (GINDX(filtersize, i) / pow(sigma, 2)) * s->gauss[0][i];
            sum1 += s->gauss[1][i] * GINDX(filtersize, i);
        }

        for (i = 0; i < filtersize; ++i) {
            s->gauss[1][i] /= sum1;
        }

        // Order 2
        if (difford > 1) {
            av_log(ctx, AV_LOG_TRACE, "Setting 2-d gauss with filtersize = %d.\n", filtersize);
            sum1 = 0.0;
            for (i = 0; i < filtersize; ++i) {
                s->gauss[2][i] = ( pow(GINDX(filtersize, i), 2) / pow(sigma, 4) - 1/pow(sigma, 2) )
                                 * s->gauss[0][i];
                sum1 += s->gauss[2][i];
            }

            sum2 = 0.0;
            for (i = 0; i < filtersize; ++i) {
                s->gauss[2][i] -= sum1 / (filtersize);
                sum2 += (0.5 * GINDX(filtersize, i) * GINDX(filtersize, i) * s->gauss[2][i]);
            }
            for (i = 0; i < filtersize ; ++i) {
                s->gauss[2][i] /= sum2;
            }
        }
    }
    return 0;
}

__attribute__((used)) static void cleanup_derivative_buffers(ThreadData *td, int nb_buff, int nb_planes)
{
    int b, p;

    for (b = 0; b < nb_buff; ++b) {
        for (p = 0; p < NUM_PLANES; ++p) {
            av_freep(&td->data[b][p]);
        }
    }
    // Final buffer may not be fully allocated at fail cases
    for (p = 0; p < nb_planes; ++p) {
        av_freep(&td->data[b][p]);
    }
}

__attribute__((used)) static int setup_derivative_buffers(AVFilterContext* ctx, ThreadData *td)
{
    ColorConstancyContext *s = ctx->priv;
    int nb_buff = s->difford + 1;
    int b, p;

    av_log(ctx, AV_LOG_TRACE, "Allocating %d buffer(s) for grey edge.\n", nb_buff);
    for (b = 0; b <= nb_buff; ++b) { // We need difford + 1 buffers
        for (p = 0; p < NUM_PLANES; ++p) {
            td->data[b][p] = av_mallocz_array(s->planeheight[p] * s->planewidth[p], sizeof(*td->data[b][p]));
            if (!td->data[b][p]) {
                cleanup_derivative_buffers(td, b + 1, p);
                av_log(ctx, AV_LOG_ERROR, "Out of memory while allocating derivatives buffers.\n");
                return AVERROR(ENOMEM);
            }
        }
    }
    return 0;
}

__attribute__((used)) static int slice_get_derivative(AVFilterContext* ctx, void* arg, int jobnr, int nb_jobs)
{
    ColorConstancyContext *s = ctx->priv;
    ThreadData *td = arg;
    AVFrame *in = td->in;
    const int ord = td->meta_data[INDEX_ORD];
    const int dir = td->meta_data[INDEX_DIR];
    const int src_index  = td->meta_data[INDEX_SRC];
    const int dst_index  = td->meta_data[INDEX_DST];
    const int filtersize = s->filtersize;
    const double *gauss  = s->gauss[ord];
    int plane;

    for (plane = 0; plane < NUM_PLANES; ++plane) {
        const int height      = s->planeheight[plane];
        const int width       = s->planewidth[plane];
        const int in_linesize = in->linesize[plane];
        double *dst = td->data[dst_index][plane];
        int slice_start, slice_end;
        int r, c, g;

        if (dir == DIR_X) {
            /** Applying gauss horizontally along each row */
            const uint8_t *src = in->data[plane];
            slice_start = (height * jobnr      ) / nb_jobs;
            slice_end   = (height * (jobnr + 1)) / nb_jobs;

            for (r = slice_start; r < slice_end; ++r) {
                for (c = 0; c < width; ++c) {
                    dst[INDX2D(r, c, width)] = 0;
                    for (g = 0; g < filtersize; ++g) {
                        dst[INDX2D(r, c, width)] += GAUSS(src, r,                        c + GINDX(filtersize, g),
                                                          in_linesize, height, width, gauss[GINDX(filtersize, g)]);
                    }
                }
            }
        } else {
            /** Applying gauss vertically along each column */
            const double *src = td->data[src_index][plane];
            slice_start = (width * jobnr      ) / nb_jobs;
            slice_end   = (width * (jobnr + 1)) / nb_jobs;

            for (c = slice_start; c < slice_end; ++c) {
                for (r = 0; r < height; ++r) {
                    dst[INDX2D(r, c, width)] = 0;
                    for (g = 0; g < filtersize; ++g) {
                        dst[INDX2D(r, c, width)] += GAUSS(src, r + GINDX(filtersize, g), c,
                                                          width, height, width, gauss[GINDX(filtersize, g)]);
                    }
                }
            }
        }

    }
    return 0;
}

__attribute__((used)) static int slice_normalize(AVFilterContext* ctx, void* arg, int jobnr, int nb_jobs)
{
    ColorConstancyContext *s = ctx->priv;
    ThreadData *td = arg;
    const int difford = s->difford;
    int plane;

    for (plane = 0; plane < NUM_PLANES; ++plane) {
        const int height = s->planeheight[plane];
        const int width  = s->planewidth[plane];
        const int64_t numpixels = width * (int64_t)height;
        const int slice_start   = (numpixels * jobnr    ) / nb_jobs;
        const int slice_end     = (numpixels * (jobnr+1)) / nb_jobs;
        const double *dx = td->data[INDEX_DX][plane];
        const double *dy = td->data[INDEX_DY][plane];
        double *norm = td->data[INDEX_NORM][plane];
        int i;

        if (difford == 1) {
            for (i = slice_start; i < slice_end; ++i) {
                norm[i] = sqrt( pow(dx[i], 2) + pow(dy[i], 2));
            }
        } else {
            const double *dxy = td->data[INDEX_DXY][plane];
            for (i = slice_start; i < slice_end; ++i) {
                norm[i] = sqrt( pow(dx[i], 2) + 4 * pow(dxy[i], 2) + pow(dy[i], 2) );
            }
        }
    }

    return 0;
}

