#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_56__   TYPE_9__ ;
typedef  struct TYPE_55__   TYPE_8__ ;
typedef  struct TYPE_54__   TYPE_7__ ;
typedef  struct TYPE_53__   TYPE_6__ ;
typedef  struct TYPE_52__   TYPE_5__ ;
typedef  struct TYPE_51__   TYPE_4__ ;
typedef  struct TYPE_50__   TYPE_3__ ;
typedef  struct TYPE_49__   TYPE_31__ ;
typedef  struct TYPE_48__   TYPE_2__ ;
typedef  struct TYPE_47__   TYPE_1__ ;
typedef  struct TYPE_46__   TYPE_18__ ;
typedef  struct TYPE_45__   TYPE_17__ ;
typedef  struct TYPE_44__   TYPE_16__ ;
typedef  struct TYPE_43__   TYPE_15__ ;
typedef  struct TYPE_42__   TYPE_14__ ;
typedef  struct TYPE_41__   TYPE_13__ ;
typedef  struct TYPE_40__   TYPE_12__ ;
typedef  struct TYPE_39__   TYPE_11__ ;
typedef  struct TYPE_38__   TYPE_10__ ;

/* Type definitions */
struct TYPE_55__ {int i_type; int b_keyframe; int i_qpplus1; int /*<<< orphan*/ * opaque; int /*<<< orphan*/  i_dts; int /*<<< orphan*/  i_pts; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_8__ x264_picture_t ;
struct TYPE_56__ {int i_payload; int /*<<< orphan*/  p_payload; } ;
typedef  TYPE_9__ x264_nal_t ;
typedef  int /*<<< orphan*/  va_list ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  int64_t ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
struct TYPE_54__ {float* quant_offsets; int /*<<< orphan*/  (* quant_offsets_free ) (float*) ;} ;
struct TYPE_51__ {int num_payloads; TYPE_31__* payloads; int /*<<< orphan*/  (* sei_free ) (float*) ;} ;
struct TYPE_50__ {int i_plane; int /*<<< orphan*/ * i_stride; int /*<<< orphan*/ * plane; int /*<<< orphan*/  i_csp; } ;
struct TYPE_45__ {int i_type; TYPE_7__ prop; TYPE_4__ extra_sei; int /*<<< orphan*/ * opaque; int /*<<< orphan*/  i_pts; TYPE_3__ img; } ;
struct TYPE_52__ {int i_vbv_buffer_size; int i_vbv_max_bitrate; scalar_t__ i_rc_method; int i_bitrate; scalar_t__ f_rf_constant; scalar_t__ i_qp_constant; scalar_t__ f_rf_constant_max; scalar_t__ i_aq_mode; } ;
struct TYPE_47__ {int i_sar_height; int i_sar_width; } ;
struct TYPE_46__ {scalar_t__ b_tff; int i_frame_packing; TYPE_5__ rc; int /*<<< orphan*/  i_csp; TYPE_1__ vui; scalar_t__ b_interlaced; } ;
struct TYPE_38__ {int sei_size; scalar_t__ avcintra_class; scalar_t__ crf; scalar_t__ cqp; scalar_t__ crf_max; size_t next_reordered_opaque; size_t nb_reordered_opaque; int /*<<< orphan*/ * reordered_opaque; TYPE_17__ pic; int /*<<< orphan*/  enc; TYPE_18__ params; scalar_t__ a53_cc; int /*<<< orphan*/  forced_idr; int /*<<< orphan*/  sei; } ;
typedef  TYPE_10__ X264Context ;
struct TYPE_53__ {float den; float num; } ;
struct TYPE_49__ {size_t payload_size; int payload_type; void* payload; } ;
struct TYPE_48__ {int num; int den; } ;
struct TYPE_44__ {int rc_buffer_size; int rc_max_rate; int bit_rate; int pix_fmt; int /*<<< orphan*/  reordered_opaque; TYPE_10__* priv_data; TYPE_2__ sample_aspect_ratio; } ;
struct TYPE_43__ {scalar_t__ top_field_first; int pict_type; scalar_t__ interlaced_frame; int width; int height; int /*<<< orphan*/  reordered_opaque; int /*<<< orphan*/  pts; int /*<<< orphan*/ * linesize; int /*<<< orphan*/ * data; } ;
struct TYPE_42__ {int size; scalar_t__ data; } ;
struct TYPE_41__ {int flags; int /*<<< orphan*/  dts; int /*<<< orphan*/  pts; int /*<<< orphan*/ * data; } ;
struct TYPE_40__ {int top; int bottom; int left; int right; scalar_t__ self_size; TYPE_6__ qoffset; } ;
struct TYPE_39__ {int type; int flags; } ;
typedef  TYPE_11__ AVStereo3D ;
typedef  TYPE_12__ AVRegionOfInterest ;
typedef  TYPE_13__ AVPacket ;
typedef  TYPE_14__ AVFrameSideData ;
typedef  TYPE_15__ AVFrame ;
typedef  TYPE_16__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EXTERNAL ; 
 int /*<<< orphan*/  AV_FRAME_DATA_REGIONS_OF_INTEREST ; 
 int /*<<< orphan*/  AV_FRAME_DATA_STEREO3D ; 
#define  AV_LOG_DEBUG 168 
#define  AV_LOG_ERROR 167 
#define  AV_LOG_INFO 166 
#define  AV_LOG_WARNING 165 
#define  AV_PICTURE_TYPE_B 164 
#define  AV_PICTURE_TYPE_I 163 
 int AV_PICTURE_TYPE_NONE ; 
#define  AV_PICTURE_TYPE_P 162 
#define  AV_PIX_FMT_BGR0 161 
#define  AV_PIX_FMT_BGR24 160 
#define  AV_PIX_FMT_GRAY10 159 
#define  AV_PIX_FMT_GRAY8 158 
#define  AV_PIX_FMT_NV12 157 
#define  AV_PIX_FMT_NV16 156 
#define  AV_PIX_FMT_NV20 155 
#define  AV_PIX_FMT_RGB24 154 
#define  AV_PIX_FMT_YUV420P 153 
#define  AV_PIX_FMT_YUV420P10 152 
#define  AV_PIX_FMT_YUV420P9 151 
#define  AV_PIX_FMT_YUV422P 150 
#define  AV_PIX_FMT_YUV422P10 149 
#define  AV_PIX_FMT_YUV444P 148 
#define  AV_PIX_FMT_YUV444P10 147 
#define  AV_PIX_FMT_YUV444P9 146 
#define  AV_PIX_FMT_YUVJ420P 145 
#define  AV_PIX_FMT_YUVJ422P 144 
#define  AV_PIX_FMT_YUVJ444P 143 
 int AV_PKT_FLAG_KEY ; 
#define  AV_STEREO3D_CHECKERBOARD 142 
#define  AV_STEREO3D_COLUMNS 141 
 int AV_STEREO3D_FLAG_INVERT ; 
#define  AV_STEREO3D_FRAMESEQUENCE 140 
#define  AV_STEREO3D_LINES 139 
#define  AV_STEREO3D_SIDEBYSIDE 138 
#define  AV_STEREO3D_TOPBOTTOM 137 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FFMIN (int,int) ; 
 int FF_QP2LAMBDA ; 
 int MB_SIZE ; 
 scalar_t__ X264_AQ_NONE ; 
 int /*<<< orphan*/  X264_CSP_HIGH_DEPTH ; 
 int X264_CSP_I420 ; 
 int X264_CSP_I422 ; 
 int X264_CSP_I444 ; 
 int X264_CSP_NV12 ; 
 int X264_CSP_NV16 ; 
#define  X264_LOG_DEBUG 136 
#define  X264_LOG_ERROR 135 
#define  X264_LOG_INFO 134 
#define  X264_LOG_WARNING 133 
 scalar_t__ X264_RC_ABR ; 
 scalar_t__ X264_RC_CQP ; 
 scalar_t__ X264_RC_CRF ; 
 int X264_TYPE_AUTO ; 
#define  X264_TYPE_B 132 
#define  X264_TYPE_BREF 131 
#define  X264_TYPE_I 130 
#define  X264_TYPE_IDR 129 
 int X264_TYPE_KEYFRAME ; 
#define  X264_TYPE_P 128 
 float av_clipf (float,float,float) ; 
 TYPE_14__* av_frame_get_side_data (TYPE_15__ const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_free (float*) ; 
 int /*<<< orphan*/  av_freep (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_log (TYPE_16__*,int const,char*,...) ; 
 TYPE_31__* av_mallocz (int) ; 
 float* av_mallocz_array (int,int) ; 
 int /*<<< orphan*/  av_vlog (void*,int const,char const*,int /*<<< orphan*/ ) ; 
 int ff_alloc_a53_sei (TYPE_15__ const*,int /*<<< orphan*/ ,void**,size_t*) ; 
 int ff_alloc_packet2 (TYPE_16__*,TYPE_13__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_side_data_set_encoder_stats (TYPE_13__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int x264_bit_depth ; 
 scalar_t__ x264_encoder_delayed_frames (int /*<<< orphan*/ ) ; 
 scalar_t__ x264_encoder_encode (int /*<<< orphan*/ ,TYPE_9__**,int*,TYPE_17__*,TYPE_8__*) ; 
 int /*<<< orphan*/  x264_encoder_reconfig (int /*<<< orphan*/ ,TYPE_18__*) ; 
 int /*<<< orphan*/  x264_picture_init (TYPE_17__*) ; 

__attribute__((used)) static void X264_log(void *p, int level, const char *fmt, va_list args)
{
    static const int level_map[] = {
        [X264_LOG_ERROR]   = AV_LOG_ERROR,
        [X264_LOG_WARNING] = AV_LOG_WARNING,
        [X264_LOG_INFO]    = AV_LOG_INFO,
        [X264_LOG_DEBUG]   = AV_LOG_DEBUG
    };

    if (level < 0 || level > X264_LOG_DEBUG)
        return;

    av_vlog(p, level_map[level], fmt, args);
}

__attribute__((used)) static int encode_nals(AVCodecContext *ctx, AVPacket *pkt,
                       const x264_nal_t *nals, int nnal)
{
    X264Context *x4 = ctx->priv_data;
    uint8_t *p;
    int i, size = x4->sei_size, ret;

    if (!nnal)
        return 0;

    for (i = 0; i < nnal; i++)
        size += nals[i].i_payload;

    if ((ret = ff_alloc_packet2(ctx, pkt, size, 0)) < 0)
        return ret;

    p = pkt->data;

    /* Write the SEI as part of the first frame. */
    if (x4->sei_size > 0 && nnal > 0) {
        if (x4->sei_size > size) {
            av_log(ctx, AV_LOG_ERROR, "Error: nal buffer is too small\n");
            return -1;
        }
        memcpy(p, x4->sei, x4->sei_size);
        p += x4->sei_size;
        x4->sei_size = 0;
        av_freep(&x4->sei);
    }

    for (i = 0; i < nnal; i++){
        memcpy(p, nals[i].p_payload, nals[i].i_payload);
        p += nals[i].i_payload;
    }

    return 1;
}

__attribute__((used)) static int avfmt2_num_planes(int avfmt)
{
    switch (avfmt) {
    case AV_PIX_FMT_YUV420P:
    case AV_PIX_FMT_YUVJ420P:
    case AV_PIX_FMT_YUV420P9:
    case AV_PIX_FMT_YUV420P10:
    case AV_PIX_FMT_YUV444P:
        return 3;

    case AV_PIX_FMT_BGR0:
    case AV_PIX_FMT_BGR24:
    case AV_PIX_FMT_RGB24:
    case AV_PIX_FMT_GRAY8:
    case AV_PIX_FMT_GRAY10:
        return 1;

    default:
        return 3;
    }
}

__attribute__((used)) static void reconfig_encoder(AVCodecContext *ctx, const AVFrame *frame)
{
    X264Context *x4 = ctx->priv_data;
    AVFrameSideData *side_data;


  if (x4->avcintra_class < 0) {
    if (x4->params.b_interlaced && x4->params.b_tff != frame->top_field_first) {

        x4->params.b_tff = frame->top_field_first;
        x264_encoder_reconfig(x4->enc, &x4->params);
    }
    if (x4->params.vui.i_sar_height*ctx->sample_aspect_ratio.num != ctx->sample_aspect_ratio.den * x4->params.vui.i_sar_width) {
        x4->params.vui.i_sar_height = ctx->sample_aspect_ratio.den;
        x4->params.vui.i_sar_width  = ctx->sample_aspect_ratio.num;
        x264_encoder_reconfig(x4->enc, &x4->params);
    }

    if (x4->params.rc.i_vbv_buffer_size != ctx->rc_buffer_size / 1000 ||
        x4->params.rc.i_vbv_max_bitrate != ctx->rc_max_rate    / 1000) {
        x4->params.rc.i_vbv_buffer_size = ctx->rc_buffer_size / 1000;
        x4->params.rc.i_vbv_max_bitrate = ctx->rc_max_rate    / 1000;
        x264_encoder_reconfig(x4->enc, &x4->params);
    }

    if (x4->params.rc.i_rc_method == X264_RC_ABR &&
        x4->params.rc.i_bitrate != ctx->bit_rate / 1000) {
        x4->params.rc.i_bitrate = ctx->bit_rate / 1000;
        x264_encoder_reconfig(x4->enc, &x4->params);
    }

    if (x4->crf >= 0 &&
        x4->params.rc.i_rc_method == X264_RC_CRF &&
        x4->params.rc.f_rf_constant != x4->crf) {
        x4->params.rc.f_rf_constant = x4->crf;
        x264_encoder_reconfig(x4->enc, &x4->params);
    }

    if (x4->params.rc.i_rc_method == X264_RC_CQP &&
        x4->cqp >= 0 &&
        x4->params.rc.i_qp_constant != x4->cqp) {
        x4->params.rc.i_qp_constant = x4->cqp;
        x264_encoder_reconfig(x4->enc, &x4->params);
    }

    if (x4->crf_max >= 0 &&
        x4->params.rc.f_rf_constant_max != x4->crf_max) {
        x4->params.rc.f_rf_constant_max = x4->crf_max;
        x264_encoder_reconfig(x4->enc, &x4->params);
    }
  }

    side_data = av_frame_get_side_data(frame, AV_FRAME_DATA_STEREO3D);
    if (side_data) {
        AVStereo3D *stereo = (AVStereo3D *)side_data->data;
        int fpa_type;

        switch (stereo->type) {
        case AV_STEREO3D_CHECKERBOARD:
            fpa_type = 0;
            break;
        case AV_STEREO3D_COLUMNS:
            fpa_type = 1;
            break;
        case AV_STEREO3D_LINES:
            fpa_type = 2;
            break;
        case AV_STEREO3D_SIDEBYSIDE:
            fpa_type = 3;
            break;
        case AV_STEREO3D_TOPBOTTOM:
            fpa_type = 4;
            break;
        case AV_STEREO3D_FRAMESEQUENCE:
            fpa_type = 5;
            break;
#if X264_BUILD >= 145
        case AV_STEREO3D_2D:
            fpa_type = 6;
            break;
#endif
        default:
            fpa_type = -1;
            break;
        }

        /* Inverted mode is not supported by x264 */
        if (stereo->flags & AV_STEREO3D_FLAG_INVERT) {
            av_log(ctx, AV_LOG_WARNING,
                   "Ignoring unsupported inverted stereo value %d\n", fpa_type);
            fpa_type = -1;
        }

        if (fpa_type != x4->params.i_frame_packing) {
            x4->params.i_frame_packing = fpa_type;
            x264_encoder_reconfig(x4->enc, &x4->params);
        }
    }
}

__attribute__((used)) static int X264_frame(AVCodecContext *ctx, AVPacket *pkt, const AVFrame *frame,
                      int *got_packet)
{
    X264Context *x4 = ctx->priv_data;
    x264_nal_t *nal;
    int nnal, i, ret;
    x264_picture_t pic_out = {0};
    int pict_type;
    int64_t *out_opaque;
    AVFrameSideData *sd;

    x264_picture_init( &x4->pic );
    x4->pic.img.i_csp   = x4->params.i_csp;
#if X264_BUILD >= 153
    if (x4->params.i_bitdepth > 8)
#else
    if (x264_bit_depth > 8)
#endif
        x4->pic.img.i_csp |= X264_CSP_HIGH_DEPTH;
    x4->pic.img.i_plane = avfmt2_num_planes(ctx->pix_fmt);

    if (frame) {
        for (i = 0; i < x4->pic.img.i_plane; i++) {
            x4->pic.img.plane[i]    = frame->data[i];
            x4->pic.img.i_stride[i] = frame->linesize[i];
        }

        x4->pic.i_pts  = frame->pts;

        x4->reordered_opaque[x4->next_reordered_opaque] = frame->reordered_opaque;
        x4->pic.opaque = &x4->reordered_opaque[x4->next_reordered_opaque];
        x4->next_reordered_opaque++;
        x4->next_reordered_opaque %= x4->nb_reordered_opaque;

        switch (frame->pict_type) {
        case AV_PICTURE_TYPE_I:
            x4->pic.i_type = x4->forced_idr > 0 ? X264_TYPE_IDR
                                                : X264_TYPE_KEYFRAME;
            break;
        case AV_PICTURE_TYPE_P:
            x4->pic.i_type = X264_TYPE_P;
            break;
        case AV_PICTURE_TYPE_B:
            x4->pic.i_type = X264_TYPE_B;
            break;
        default:
            x4->pic.i_type = X264_TYPE_AUTO;
            break;
        }
        reconfig_encoder(ctx, frame);

        if (x4->a53_cc) {
            void *sei_data;
            size_t sei_size;

            ret = ff_alloc_a53_sei(frame, 0, &sei_data, &sei_size);
            if (ret < 0) {
                av_log(ctx, AV_LOG_ERROR, "Not enough memory for closed captions, skipping\n");
            } else if (sei_data) {
                x4->pic.extra_sei.payloads = av_mallocz(sizeof(x4->pic.extra_sei.payloads[0]));
                if (x4->pic.extra_sei.payloads == NULL) {
                    av_log(ctx, AV_LOG_ERROR, "Not enough memory for closed captions, skipping\n");
                    av_free(sei_data);
                } else {
                    x4->pic.extra_sei.sei_free = av_free;

                    x4->pic.extra_sei.payloads[0].payload_size = sei_size;
                    x4->pic.extra_sei.payloads[0].payload = sei_data;
                    x4->pic.extra_sei.num_payloads = 1;
                    x4->pic.extra_sei.payloads[0].payload_type = 4;
                }
            }
        }

        sd = av_frame_get_side_data(frame, AV_FRAME_DATA_REGIONS_OF_INTEREST);
        if (sd) {
            if (x4->params.rc.i_aq_mode == X264_AQ_NONE) {
                av_log(ctx, AV_LOG_WARNING, "Adaptive quantization must be enabled to use ROI encoding, skipping ROI.\n");
            } else {
                if (frame->interlaced_frame == 0) {
                    int mbx = (frame->width + MB_SIZE - 1) / MB_SIZE;
                    int mby = (frame->height + MB_SIZE - 1) / MB_SIZE;
                    int nb_rois;
                    AVRegionOfInterest* roi;
                    float* qoffsets;
                    qoffsets = av_mallocz_array(mbx * mby, sizeof(*qoffsets));
                    if (!qoffsets)
                        return AVERROR(ENOMEM);

                    nb_rois = sd->size / sizeof(AVRegionOfInterest);
                    roi = (AVRegionOfInterest*)sd->data;
                    for (int count = 0; count < nb_rois; count++) {
                        int starty = FFMIN(mby, roi->top / MB_SIZE);
                        int endy   = FFMIN(mby, (roi->bottom + MB_SIZE - 1)/ MB_SIZE);
                        int startx = FFMIN(mbx, roi->left / MB_SIZE);
                        int endx   = FFMIN(mbx, (roi->right + MB_SIZE - 1)/ MB_SIZE);
                        float qoffset;

                        if (roi->qoffset.den == 0) {
                            av_free(qoffsets);
                            av_log(ctx, AV_LOG_ERROR, "AVRegionOfInterest.qoffset.den should not be zero.\n");
                            return AVERROR(EINVAL);
                        }
                        qoffset = roi->qoffset.num * 1.0f / roi->qoffset.den;
                        qoffset = av_clipf(qoffset, -1.0f, 1.0f);

                        // 25 is a number that I think it is a possible proper scale value.
                        qoffset = qoffset * 25;

                        for (int y = starty; y < endy; y++) {
                            for (int x = startx; x < endx; x++) {
                                qoffsets[x + y*mbx] = qoffset;
                            }
                        }

                        if (roi->self_size == 0) {
                            av_free(qoffsets);
                            av_log(ctx, AV_LOG_ERROR, "AVRegionOfInterest.self_size should be set to sizeof(AVRegionOfInterest).\n");
                            return AVERROR(EINVAL);
                        }
                        roi = (AVRegionOfInterest*)((char*)roi + roi->self_size);
                    }

                    x4->pic.prop.quant_offsets = qoffsets;
                    x4->pic.prop.quant_offsets_free = av_free;
                } else {
                    av_log(ctx, AV_LOG_WARNING, "interlaced_frame not supported for ROI encoding yet, skipping ROI.\n");
                }
            }
        }
    }

    do {
        if (x264_encoder_encode(x4->enc, &nal, &nnal, frame? &x4->pic: NULL, &pic_out) < 0)
            return AVERROR_EXTERNAL;

        ret = encode_nals(ctx, pkt, nal, nnal);
        if (ret < 0)
            return ret;
    } while (!ret && !frame && x264_encoder_delayed_frames(x4->enc));

    pkt->pts = pic_out.i_pts;
    pkt->dts = pic_out.i_dts;

    out_opaque = pic_out.opaque;
    if (out_opaque >= x4->reordered_opaque &&
        out_opaque < &x4->reordered_opaque[x4->nb_reordered_opaque]) {
        ctx->reordered_opaque = *out_opaque;
    } else {
        // Unexpected opaque pointer on picture output
        ctx->reordered_opaque = 0;
    }

    switch (pic_out.i_type) {
    case X264_TYPE_IDR:
    case X264_TYPE_I:
        pict_type = AV_PICTURE_TYPE_I;
        break;
    case X264_TYPE_P:
        pict_type = AV_PICTURE_TYPE_P;
        break;
    case X264_TYPE_B:
    case X264_TYPE_BREF:
        pict_type = AV_PICTURE_TYPE_B;
        break;
    default:
        pict_type = AV_PICTURE_TYPE_NONE;
    }
#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
    ctx->coded_frame->pict_type = pict_type;
FF_ENABLE_DEPRECATION_WARNINGS
#endif

    pkt->flags |= AV_PKT_FLAG_KEY*pic_out.b_keyframe;
    if (ret) {
        ff_side_data_set_encoder_stats(pkt, (pic_out.i_qpplus1 - 1) * FF_QP2LAMBDA, NULL, 0, pict_type);

#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
        ctx->coded_frame->quality = (pic_out.i_qpplus1 - 1) * FF_QP2LAMBDA;
FF_ENABLE_DEPRECATION_WARNINGS
#endif
    }

    *got_packet = ret;
    return 0;
}

__attribute__((used)) static int convert_pix_fmt(enum AVPixelFormat pix_fmt)
{
    switch (pix_fmt) {
    case AV_PIX_FMT_YUV420P:
    case AV_PIX_FMT_YUVJ420P:
    case AV_PIX_FMT_YUV420P9:
    case AV_PIX_FMT_YUV420P10: return X264_CSP_I420;
    case AV_PIX_FMT_YUV422P:
    case AV_PIX_FMT_YUVJ422P:
    case AV_PIX_FMT_YUV422P10: return X264_CSP_I422;
    case AV_PIX_FMT_YUV444P:
    case AV_PIX_FMT_YUVJ444P:
    case AV_PIX_FMT_YUV444P9:
    case AV_PIX_FMT_YUV444P10: return X264_CSP_I444;
#if CONFIG_LIBX264RGB_ENCODER
    case AV_PIX_FMT_BGR0:
        return X264_CSP_BGRA;
    case AV_PIX_FMT_BGR24:
        return X264_CSP_BGR;

    case AV_PIX_FMT_RGB24:
        return X264_CSP_RGB;
#endif
    case AV_PIX_FMT_NV12:      return X264_CSP_NV12;
    case AV_PIX_FMT_NV16:
    case AV_PIX_FMT_NV20:      return X264_CSP_NV16;
#ifdef X264_CSP_NV21
    case AV_PIX_FMT_NV21:      return X264_CSP_NV21;
#endif
#ifdef X264_CSP_I400
    case AV_PIX_FMT_GRAY8:
    case AV_PIX_FMT_GRAY10:    return X264_CSP_I400;
#endif
    };
    return 0;
}

