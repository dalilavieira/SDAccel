#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct vo_frame {int num_frames; struct mp_image** frames; scalar_t__ repeat; scalar_t__ redraw; } ;
struct vo {int /*<<< orphan*/  osd; int /*<<< orphan*/  params; struct priv* priv; int /*<<< orphan*/  log; int /*<<< orphan*/  encode_lavc_ctx; } ;
struct priv {int shutdown; struct encoder_context* enc; } ;
struct mp_osd_res {int dummy; } ;
struct TYPE_16__ {int /*<<< orphan*/  levels; int /*<<< orphan*/  space; } ;
struct mp_image_params {int imgfmt; int w; int h; TYPE_1__ color; int /*<<< orphan*/  p_h; int /*<<< orphan*/  p_w; } ;
struct mp_image {double pts; struct mp_image_params params; } ;
struct encoder_context {TYPE_3__* options; TYPE_6__* encoder; struct encode_lavc_context* encode_lavc_ctx; } ;
struct encode_lavc_context {double discontinuity_pts_offset; double next_in_pts; int /*<<< orphan*/  lock; } ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
struct TYPE_19__ {int num; int den; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_21__ {int width; int height; int pix_fmt; int /*<<< orphan*/  global_quality; TYPE_4__ time_base; TYPE_2__* codec; int /*<<< orphan*/  color_range; int /*<<< orphan*/  colorspace; TYPE_4__ sample_aspect_ratio; } ;
struct TYPE_20__ {int /*<<< orphan*/  quality; scalar_t__ pict_type; int /*<<< orphan*/  pts; } ;
struct TYPE_18__ {int /*<<< orphan*/  rawts; } ;
struct TYPE_17__ {int* pix_fmts; TYPE_4__* supported_framerates; } ;
typedef  TYPE_4__ AVRational ;
typedef  TYPE_5__ AVFrame ;
typedef  TYPE_6__ AVCodecContext ;

/* Variables and functions */
 int AV_PIX_FMT_NONE ; 
 int /*<<< orphan*/  MP_ERR (struct vo*,char*) ; 
 int /*<<< orphan*/  MP_FATAL (struct vo*,char*,int /*<<< orphan*/ ) ; 
 double MP_NOPTS_VALUE ; 
 int /*<<< orphan*/  MP_WARN (struct vo*,char*,double) ; 
 int /*<<< orphan*/  OSD_DRAW_SUB_ONLY ; 
 int /*<<< orphan*/  STREAM_VIDEO ; 
 int /*<<< orphan*/  VO_EVENT_INITIAL_UNBLOCK ; 
 int VO_NOTIMPL ; 
 int /*<<< orphan*/  abort () ; 
 size_t av_find_nearest_q_idx (TYPE_4__,TYPE_4__ const*) ; 
 int /*<<< orphan*/  av_frame_free (TYPE_5__**) ; 
 TYPE_4__ av_inv_q (TYPE_4__) ; 
 double av_q2d (TYPE_4__) ; 
 scalar_t__ avcodec_is_open (TYPE_6__*) ; 
 struct encoder_context* encoder_context_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  encoder_encode (struct encoder_context*,TYPE_5__*) ; 
 scalar_t__ encoder_get_offset (struct encoder_context*) ; 
 int /*<<< orphan*/  encoder_init_codec_and_muxer (struct encoder_context*,void (*) (void*),struct vo*) ; 
 int fabs (double) ; 
 int imgfmt2pixfmt (int) ; 
 int /*<<< orphan*/  mp_csp_levels_to_avcol_range (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_csp_to_avcol_spc (int /*<<< orphan*/ ) ; 
 TYPE_5__* mp_image_to_av_frame (struct mp_image*) ; 
 int /*<<< orphan*/  mp_imgfmt_to_name (int) ; 
 int /*<<< orphan*/  osd_draw_on_image (int /*<<< orphan*/ ,struct mp_osd_res,double,int /*<<< orphan*/ ,struct mp_image*) ; 
 struct mp_osd_res osd_res_from_image_params (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rint (double) ; 
 int /*<<< orphan*/  talloc_steal (struct priv*,struct encoder_context*) ; 
 int /*<<< orphan*/  vo_event (struct vo*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int preinit(struct vo *vo)
{
    struct priv *vc = vo->priv;
    vc->enc = encoder_context_alloc(vo->encode_lavc_ctx, STREAM_VIDEO, vo->log);
    if (!vc->enc)
        return -1;
    talloc_steal(vc, vc->enc);
    return 0;
}

__attribute__((used)) static void uninit(struct vo *vo)
{
    struct priv *vc = vo->priv;
    struct encoder_context *enc = vc->enc;

    if (!vc->shutdown)
        encoder_encode(enc, NULL); // finish encoding
}

__attribute__((used)) static void on_ready(void *ptr)
{
    struct vo *vo = ptr;

    vo_event(vo, VO_EVENT_INITIAL_UNBLOCK);
}

__attribute__((used)) static int reconfig2(struct vo *vo, struct mp_image *img)
{
    struct priv *vc = vo->priv;
    AVCodecContext *encoder = vc->enc->encoder;

    struct mp_image_params *params = &img->params;
    enum AVPixelFormat pix_fmt = imgfmt2pixfmt(params->imgfmt);
    AVRational aspect = {params->p_w, params->p_h};
    int width = params->w;
    int height = params->h;

    if (vc->shutdown)
        return -1;

    if (avcodec_is_open(encoder)) {
        if (width == encoder->width && height == encoder->height &&
            pix_fmt == encoder->pix_fmt)
        {
            // consider these changes not critical
            MP_ERR(vo, "Ignoring mid-stream parameter changes!\n");
            return 0;
        }

        /* FIXME Is it possible with raw video? */
        MP_ERR(vo, "resolution changes not supported.\n");
        goto error;
    }

    // When we get here, this must be the first call to reconfigure(). Thus, we
    // can rely on no existing data in vc having been allocated yet.
    // Reason:
    // - Second calls after reconfigure() already failed once fail (due to the
    //   vc->shutdown check above).
    // - Second calls after reconfigure() already succeeded once return early
    //   (due to the avcodec_is_open() check above).

    if (pix_fmt == AV_PIX_FMT_NONE) {
        MP_FATAL(vo, "Format %s not supported by lavc.\n",
                 mp_imgfmt_to_name(params->imgfmt));
        goto error;
    }

    encoder->sample_aspect_ratio = aspect;
    encoder->width = width;
    encoder->height = height;
    encoder->pix_fmt = pix_fmt;
    encoder->colorspace = mp_csp_to_avcol_spc(params->color.space);
    encoder->color_range = mp_csp_levels_to_avcol_range(params->color.levels);

    AVRational tb;

    // we want to handle:
    //      1/25
    //   1001/24000
    //   1001/30000
    // for this we would need 120000fps...
    // however, mpeg-4 only allows 16bit values
    // so let's take 1001/30000 out
    tb.num = 24000;
    tb.den = 1;

    const AVRational *rates = encoder->codec->supported_framerates;
    if (rates && rates[0].den)
        tb = rates[av_find_nearest_q_idx(tb, rates)];

    encoder->time_base = av_inv_q(tb);

    if (!encoder_init_codec_and_muxer(vc->enc, on_ready, vo))
        goto error;

    return 0;

error:
    vc->shutdown = true;
    return -1;
}

__attribute__((used)) static int query_format(struct vo *vo, int format)
{
    struct priv *vc = vo->priv;

    enum AVPixelFormat pix_fmt = imgfmt2pixfmt(format);
    const enum AVPixelFormat *p = vc->enc->encoder->codec->pix_fmts;

    if (!p)
        return 1;

    while (*p != AV_PIX_FMT_NONE) {
        if (*p == pix_fmt)
            return 1;
        p++;
    }

    return 0;
}

__attribute__((used)) static void draw_frame(struct vo *vo, struct vo_frame *voframe)
{
    struct priv *vc = vo->priv;
    struct encoder_context *enc = vc->enc;
    struct encode_lavc_context *ectx = enc->encode_lavc_ctx;
    AVCodecContext *avc = enc->encoder;

    if (voframe->redraw || voframe->repeat || voframe->num_frames < 1)
        return;

    struct mp_image *mpi = voframe->frames[0];

    struct mp_osd_res dim = osd_res_from_image_params(vo->params);
    osd_draw_on_image(vo->osd, dim, mpi->pts, OSD_DRAW_SUB_ONLY, mpi);

    if (vc->shutdown)
        return;

    // Lock for shared timestamp fields.
    pthread_mutex_lock(&ectx->lock);

    double pts = mpi->pts;
    double outpts = pts;
    if (!enc->options->rawts) {
        // fix the discontinuity pts offset
        if (ectx->discontinuity_pts_offset == MP_NOPTS_VALUE) {
            ectx->discontinuity_pts_offset = ectx->next_in_pts - pts;
        } else if (fabs(pts + ectx->discontinuity_pts_offset -
                        ectx->next_in_pts) > 30)
        {
            MP_WARN(vo, "detected an unexpected discontinuity (pts jumped by "
                    "%f seconds)\n",
                    pts + ectx->discontinuity_pts_offset - ectx->next_in_pts);
            ectx->discontinuity_pts_offset = ectx->next_in_pts - pts;
        }

        outpts = pts + ectx->discontinuity_pts_offset;
    }

    outpts += encoder_get_offset(enc);

    if (!enc->options->rawts) {
        // calculate expected pts of next video frame
        double timeunit = av_q2d(avc->time_base);
        double expected_next_pts = pts + timeunit;
        // set next allowed output pts value
        double nextpts = expected_next_pts + ectx->discontinuity_pts_offset;
        if (nextpts > ectx->next_in_pts)
            ectx->next_in_pts = nextpts;
    }

    pthread_mutex_unlock(&ectx->lock);

    AVFrame *frame = mp_image_to_av_frame(mpi);
    if (!frame)
        abort();

    frame->pts = rint(outpts * av_q2d(av_inv_q(avc->time_base)));
    frame->pict_type = 0; // keep this at unknown/undefined
    frame->quality = avc->global_quality;
    encoder_encode(enc, frame);
    av_frame_free(&frame);
}

__attribute__((used)) static void flip_page(struct vo *vo)
{
}

__attribute__((used)) static int control(struct vo *vo, uint32_t request, void *data)
{
    return VO_NOTIMPL;
}

