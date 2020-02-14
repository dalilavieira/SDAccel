#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_42__   TYPE_9__ ;
typedef  struct TYPE_41__   TYPE_8__ ;
typedef  struct TYPE_40__   TYPE_7__ ;
typedef  struct TYPE_39__   TYPE_6__ ;
typedef  struct TYPE_38__   TYPE_5__ ;
typedef  struct TYPE_37__   TYPE_4__ ;
typedef  struct TYPE_36__   TYPE_3__ ;
typedef  struct TYPE_35__   TYPE_2__ ;
typedef  struct TYPE_34__   TYPE_1__ ;
typedef  struct TYPE_33__   TYPE_13__ ;
typedef  struct TYPE_32__   TYPE_12__ ;
typedef  struct TYPE_31__   TYPE_11__ ;
typedef  struct TYPE_30__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  xvid_plg_destroy_t ;
struct TYPE_36__ {int quant; int kblks; int mblks; int ublks; int length; int hlength; } ;
struct TYPE_40__ {int quant; int vop_flags; int motion_flags; int type; TYPE_3__ stats; int /*<<< orphan*/  vol_flags; TYPE_2__* zone; } ;
typedef  TYPE_7__ xvid_plg_data_t ;
struct TYPE_41__ {scalar_t__ param; } ;
typedef  TYPE_8__ xvid_plg_create_t ;
struct TYPE_42__ {scalar_t__ type; int quant; unsigned int hlength; void* version; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_9__ xvid_enc_stats_t ;
struct TYPE_38__ {int /*<<< orphan*/ * stride; int /*<<< orphan*/ * plane; int /*<<< orphan*/  csp; } ;
struct TYPE_30__ {int* bitstream; unsigned int length; int par_width; int par_height; int quant; int out_flags; int /*<<< orphan*/  quant_inter_matrix; int /*<<< orphan*/  quant_intra_matrix; int /*<<< orphan*/  par; scalar_t__ type; int /*<<< orphan*/  motion; int /*<<< orphan*/  vol_flags; int /*<<< orphan*/  vop_flags; TYPE_5__ input; void* version; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_10__ xvid_enc_frame_t ;
struct xvid_ff_pass1 {TYPE_1__* context; } ;
struct xvid_context {char* twopassbuffer; char* old_twopassbuffer; scalar_t__ quicktime_format; int /*<<< orphan*/  encoder_handle; int /*<<< orphan*/  inter_matrix; int /*<<< orphan*/  intra_matrix; scalar_t__ qscale; int /*<<< orphan*/  me_flags; int /*<<< orphan*/  vol_flags; int /*<<< orphan*/  vop_flags; } ;
typedef  int int64_t ;
struct TYPE_39__ {int num; int den; } ;
struct TYPE_37__ {int den; int num; } ;
struct TYPE_35__ {scalar_t__ mode; } ;
struct TYPE_34__ {char* twopassbuffer; } ;
struct TYPE_33__ {int extradata_size; int width; int height; scalar_t__ pix_fmt; scalar_t__* stats_out; TYPE_6__ sample_aspect_ratio; struct xvid_context* priv_data; TYPE_4__ time_base; int /*<<< orphan*/  extradata; } ;
struct TYPE_32__ {int pict_type; int quality; int /*<<< orphan*/ * linesize; int /*<<< orphan*/ * data; } ;
struct TYPE_31__ {int* data; unsigned int size; int /*<<< orphan*/  flags; } ;
typedef  TYPE_11__ AVPacket ;
typedef  TYPE_12__ AVFrame ;
typedef  TYPE_13__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EXTERNAL ; 
 scalar_t__ AV_INPUT_BUFFER_MIN_SIZE ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int AV_PICTURE_TYPE_B ; 
 int AV_PICTURE_TYPE_I ; 
 int AV_PICTURE_TYPE_P ; 
 int AV_PICTURE_TYPE_S ; 
 scalar_t__ AV_PIX_FMT_YUV420P ; 
 int /*<<< orphan*/  AV_PKT_FLAG_KEY ; 
 int /*<<< orphan*/  BUFFER_CAT (char*) ; 
 int /*<<< orphan*/  BUFFER_REMAINING (char*) ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FF_QP2LAMBDA ; 
 int MAX_MB_BYTES ; 
 int /*<<< orphan*/  XVID_CSP_PLANAR ; 
 int /*<<< orphan*/  XVID_ENC_ENCODE ; 
 int XVID_ERR_FAIL ; 
 int XVID_KEYFRAME ; 
 int XVID_ME_ADVANCEDDIAMOND16 ; 
 int XVID_ME_BFRAME_EARLYSTOP ; 
 int XVID_ME_CHROMA_BVOP ; 
 int XVID_ME_CHROMA_PVOP ; 
 int XVID_ME_EXTSEARCH16 ; 
 int XVID_ME_FASTREFINE16 ; 
 int XVID_ME_FAST_MODEINTERPOLATE ; 
 int XVID_ME_SKIP_DELTASEARCH ; 
 int /*<<< orphan*/  XVID_PAR_EXT ; 
#define  XVID_PLG_AFTER 133 
#define  XVID_PLG_BEFORE 132 
#define  XVID_PLG_CREATE 131 
#define  XVID_PLG_DESTROY 130 
#define  XVID_PLG_FRAME 129 
#define  XVID_PLG_INFO 128 
 scalar_t__ XVID_TYPE_AUTO ; 
 scalar_t__ XVID_TYPE_BVOP ; 
 scalar_t__ XVID_TYPE_IVOP ; 
 scalar_t__ XVID_TYPE_PVOP ; 
 scalar_t__ XVID_TYPE_SVOP ; 
 void* XVID_VERSION ; 
 int XVID_VERSION_MAJOR (void*) ; 
 int XVID_VERSION_MINOR (void*) ; 
 int XVID_VERSION_PATCH (void*) ; 
 int /*<<< orphan*/  XVID_VOL_GMC ; 
 int XVID_VOP_FAST_MODEDECISION_RD ; 
 int XVID_VOP_HQACPRED ; 
 int XVID_VOP_INTER4V ; 
 int XVID_VOP_MODEDECISION_RD ; 
 int XVID_VOP_TRELLISQUANT ; 
 scalar_t__ XVID_ZONE_QUANT ; 
 int av_gcd (int,int) ; 
 int /*<<< orphan*/  av_log (TYPE_13__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  av_malloc (int) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_11__*) ; 
 int /*<<< orphan*/  av_reduce (int*,int*,int,int,int) ; 
 int ff_alloc_packet2 (TYPE_13__*,TYPE_11__*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_side_data_set_encoder_stats (TYPE_11__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  memmove (int*,int*,unsigned int) ; 
 double roundf (float) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,...) ; 
 int xvid_encore (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_10__*,TYPE_9__*) ; 

__attribute__((used)) static int xvid_ff_2pass_create(xvid_plg_create_t *param, void **handle)
{
    struct xvid_ff_pass1 *x = (struct xvid_ff_pass1 *) param->param;
    char *log = x->context->twopassbuffer;

    /* Do a quick bounds check */
    if (!log)
        return XVID_ERR_FAIL;

    /* We use snprintf() */
    /* This is because we can safely prevent a buffer overflow */
    log[0] = 0;
    snprintf(log, BUFFER_REMAINING(log),
             "# ffmpeg 2-pass log file, using xvid codec\n");
    snprintf(BUFFER_CAT(log), BUFFER_REMAINING(log),
             "# Do not modify. libxvidcore version: %d.%d.%d\n\n",
             XVID_VERSION_MAJOR(XVID_VERSION),
             XVID_VERSION_MINOR(XVID_VERSION),
             XVID_VERSION_PATCH(XVID_VERSION));

    *handle = x->context;
    return 0;
}

__attribute__((used)) static int xvid_ff_2pass_destroy(struct xvid_context *ref,
                                 xvid_plg_destroy_t *param)
{
    /* Currently cannot think of anything to do on destruction */
    /* Still, the framework should be here for reference/use */
    if (ref->twopassbuffer)
        ref->twopassbuffer[0] = 0;
    return 0;
}

__attribute__((used)) static int xvid_ff_2pass_before(struct xvid_context *ref,
                                xvid_plg_data_t *param)
{
    int motion_remove;
    int motion_replacements;
    int vop_remove;

    /* Nothing to do here, result is changed too much */
    if (param->zone && param->zone->mode == XVID_ZONE_QUANT)
        return 0;

    /* We can implement a 'turbo' first pass mode here */
    param->quant = 2;

    /* Init values */
    motion_remove       = ~XVID_ME_CHROMA_PVOP &
                          ~XVID_ME_CHROMA_BVOP &
                          ~XVID_ME_EXTSEARCH16 &
                          ~XVID_ME_ADVANCEDDIAMOND16;
    motion_replacements = XVID_ME_FAST_MODEINTERPOLATE |
                          XVID_ME_SKIP_DELTASEARCH     |
                          XVID_ME_FASTREFINE16         |
                          XVID_ME_BFRAME_EARLYSTOP;
    vop_remove          = ~XVID_VOP_MODEDECISION_RD      &
                          ~XVID_VOP_FAST_MODEDECISION_RD &
                          ~XVID_VOP_TRELLISQUANT         &
                          ~XVID_VOP_INTER4V              &
                          ~XVID_VOP_HQACPRED;

    param->vol_flags    &= ~XVID_VOL_GMC;
    param->vop_flags    &= vop_remove;
    param->motion_flags &= motion_remove;
    param->motion_flags |= motion_replacements;

    return 0;
}

__attribute__((used)) static int xvid_ff_2pass_after(struct xvid_context *ref,
                               xvid_plg_data_t *param)
{
    char *log = ref->twopassbuffer;
    const char *frame_types = " ipbs";
    char frame_type;

    /* Quick bounds check */
    if (!log)
        return XVID_ERR_FAIL;

    /* Convert the type given to us into a character */
    if (param->type < 5 && param->type > 0)
        frame_type = frame_types[param->type];
    else
        return XVID_ERR_FAIL;

    snprintf(BUFFER_CAT(log), BUFFER_REMAINING(log),
             "%c %d %d %d %d %d %d\n",
             frame_type, param->stats.quant, param->stats.kblks,
             param->stats.mblks, param->stats.ublks,
             param->stats.length, param->stats.hlength);

    return 0;
}

__attribute__((used)) static int xvid_ff_2pass(void *ref, int cmd, void *p1, void *p2)
{
    switch (cmd) {
    case XVID_PLG_INFO:
    case XVID_PLG_FRAME:
        return 0;
    case XVID_PLG_BEFORE:
        return xvid_ff_2pass_before(ref, p1);
    case XVID_PLG_CREATE:
        return xvid_ff_2pass_create(p1, p2);
    case XVID_PLG_AFTER:
        return xvid_ff_2pass_after(ref, p1);
    case XVID_PLG_DESTROY:
        return xvid_ff_2pass_destroy(ref, p1);
    default:
        return XVID_ERR_FAIL;
    }
}

__attribute__((used)) static int xvid_strip_vol_header(AVCodecContext *avctx, AVPacket *pkt,
                                 unsigned int header_len,
                                 unsigned int frame_len)
{
    int vo_len = 0, i;

    for (i = 0; i < header_len - 3; i++) {
        if (pkt->data[i]     == 0x00 &&
            pkt->data[i + 1] == 0x00 &&
            pkt->data[i + 2] == 0x01 &&
            pkt->data[i + 3] == 0xB6) {
            vo_len = i;
            break;
        }
    }

    if (vo_len > 0) {
        /* We need to store the header, so extract it */
        if (!avctx->extradata) {
            avctx->extradata = av_malloc(vo_len);
            if (!avctx->extradata)
                return AVERROR(ENOMEM);
            memcpy(avctx->extradata, pkt->data, vo_len);
            avctx->extradata_size = vo_len;
        }
        /* Less dangerous now, memmove properly copies the two
         * chunks of overlapping data */
        memmove(pkt->data, &pkt->data[vo_len], frame_len - vo_len);
        pkt->size = frame_len - vo_len;
    }
    return 0;
}

__attribute__((used)) static void xvid_correct_framerate(AVCodecContext *avctx)
{
    int frate, fbase;
    int est_frate, est_fbase;
    int gcd;
    float est_fps, fps;

    frate = avctx->time_base.den;
    fbase = avctx->time_base.num;

    gcd = av_gcd(frate, fbase);
    if (gcd > 1) {
        frate /= gcd;
        fbase /= gcd;
    }

    if (frate <= 65000 && fbase <= 65000) {
        avctx->time_base.den = frate;
        avctx->time_base.num = fbase;
        return;
    }

    fps     = (float) frate / (float) fbase;
    est_fps = roundf(fps * 1000.0) / 1000.0;

    est_frate = (int) est_fps;
    if (est_fps > (int) est_fps) {
        est_frate = (est_frate + 1) * 1000;
        est_fbase = (int) roundf((float) est_frate / est_fps);
    } else
        est_fbase = 1;

    gcd = av_gcd(est_frate, est_fbase);
    if (gcd > 1) {
        est_frate /= gcd;
        est_fbase /= gcd;
    }

    if (fbase > est_fbase) {
        avctx->time_base.den = est_frate;
        avctx->time_base.num = est_fbase;
        av_log(avctx, AV_LOG_DEBUG,
               "Xvid: framerate re-estimated: %.2f, %.3f%% correction\n",
               est_fps, (((est_fps - fps) / fps) * 100.0));
    } else {
        avctx->time_base.den = frate;
        avctx->time_base.num = fbase;
    }
}

__attribute__((used)) static int xvid_encode_frame(AVCodecContext *avctx, AVPacket *pkt,
                             const AVFrame *picture, int *got_packet)
{
    int xerr, i, ret, user_packet = !!pkt->data;
    struct xvid_context *x = avctx->priv_data;
    int mb_width  = (avctx->width  + 15) / 16;
    int mb_height = (avctx->height + 15) / 16;
    char *tmp;

    xvid_enc_frame_t xvid_enc_frame = { 0 };
    xvid_enc_stats_t xvid_enc_stats = { 0 };

    if ((ret = ff_alloc_packet2(avctx, pkt, mb_width*(int64_t)mb_height*MAX_MB_BYTES + AV_INPUT_BUFFER_MIN_SIZE, 0)) < 0)
        return ret;

    /* Start setting up the frame */
    xvid_enc_frame.version = XVID_VERSION;
    xvid_enc_stats.version = XVID_VERSION;

    /* Let Xvid know where to put the frame. */
    xvid_enc_frame.bitstream = pkt->data;
    xvid_enc_frame.length    = pkt->size;

    /* Initialize input image fields */
    if (avctx->pix_fmt != AV_PIX_FMT_YUV420P) {
        av_log(avctx, AV_LOG_ERROR,
               "Xvid: Color spaces other than 420P not supported\n");
        return AVERROR(EINVAL);
    }

    xvid_enc_frame.input.csp = XVID_CSP_PLANAR; /* YUV420P */

    for (i = 0; i < 4; i++) {
        xvid_enc_frame.input.plane[i]  = picture->data[i];
        xvid_enc_frame.input.stride[i] = picture->linesize[i];
    }

    /* Encoder Flags */
    xvid_enc_frame.vop_flags = x->vop_flags;
    xvid_enc_frame.vol_flags = x->vol_flags;
    xvid_enc_frame.motion    = x->me_flags;
    xvid_enc_frame.type      =
        picture->pict_type == AV_PICTURE_TYPE_I ? XVID_TYPE_IVOP :
        picture->pict_type == AV_PICTURE_TYPE_P ? XVID_TYPE_PVOP :
        picture->pict_type == AV_PICTURE_TYPE_B ? XVID_TYPE_BVOP :
                                                  XVID_TYPE_AUTO;

    /* Pixel aspect ratio setting */
    if (avctx->sample_aspect_ratio.num < 0 || avctx->sample_aspect_ratio.num > 255 ||
        avctx->sample_aspect_ratio.den < 0 || avctx->sample_aspect_ratio.den > 255) {
        av_log(avctx, AV_LOG_WARNING,
               "Invalid pixel aspect ratio %i/%i, limit is 255/255 reducing\n",
               avctx->sample_aspect_ratio.num, avctx->sample_aspect_ratio.den);
        av_reduce(&avctx->sample_aspect_ratio.num, &avctx->sample_aspect_ratio.den,
                   avctx->sample_aspect_ratio.num,  avctx->sample_aspect_ratio.den, 255);
    }
    xvid_enc_frame.par        = XVID_PAR_EXT;
    xvid_enc_frame.par_width  = avctx->sample_aspect_ratio.num;
    xvid_enc_frame.par_height = avctx->sample_aspect_ratio.den;

    /* Quant Setting */
    if (x->qscale)
        xvid_enc_frame.quant = picture->quality / FF_QP2LAMBDA;
    else
        xvid_enc_frame.quant = 0;

    /* Matrices */
    xvid_enc_frame.quant_intra_matrix = x->intra_matrix;
    xvid_enc_frame.quant_inter_matrix = x->inter_matrix;

    /* Encode */
    xerr = xvid_encore(x->encoder_handle, XVID_ENC_ENCODE,
                       &xvid_enc_frame, &xvid_enc_stats);

    /* Two-pass log buffer swapping */
    avctx->stats_out = NULL;
    if (x->twopassbuffer) {
        tmp                  = x->old_twopassbuffer;
        x->old_twopassbuffer = x->twopassbuffer;
        x->twopassbuffer     = tmp;
        x->twopassbuffer[0]  = 0;
        if (x->old_twopassbuffer[0] != 0) {
            avctx->stats_out = x->old_twopassbuffer;
        }
    }

    if (xerr > 0) {
        int pict_type;

        *got_packet = 1;

        if (xvid_enc_stats.type == XVID_TYPE_PVOP)
            pict_type = AV_PICTURE_TYPE_P;
        else if (xvid_enc_stats.type == XVID_TYPE_BVOP)
            pict_type = AV_PICTURE_TYPE_B;
        else if (xvid_enc_stats.type == XVID_TYPE_SVOP)
            pict_type = AV_PICTURE_TYPE_S;
        else
            pict_type = AV_PICTURE_TYPE_I;

#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
        avctx->coded_frame->pict_type = pict_type;
        avctx->coded_frame->quality = xvid_enc_stats.quant * FF_QP2LAMBDA;
FF_ENABLE_DEPRECATION_WARNINGS
#endif

        ff_side_data_set_encoder_stats(pkt, xvid_enc_stats.quant * FF_QP2LAMBDA, NULL, 0, pict_type);

        if (xvid_enc_frame.out_flags & XVID_KEYFRAME) {
#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
            avctx->coded_frame->key_frame = 1;
FF_ENABLE_DEPRECATION_WARNINGS
#endif
            pkt->flags  |= AV_PKT_FLAG_KEY;
            if (x->quicktime_format)
                return xvid_strip_vol_header(avctx, pkt,
                                             xvid_enc_stats.hlength, xerr);
        } else {
#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
            avctx->coded_frame->key_frame = 0;
FF_ENABLE_DEPRECATION_WARNINGS
#endif
        }

        pkt->size = xerr;

        return 0;
    } else {
        if (!user_packet)
            av_packet_unref(pkt);
        if (!xerr)
            return 0;
        av_log(avctx, AV_LOG_ERROR,
               "Xvid: Encoding Error Occurred: %i\n", xerr);
        return AVERROR_EXTERNAL;
    }
}

