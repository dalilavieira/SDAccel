#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_7__ ;
typedef  struct TYPE_27__   TYPE_6__ ;
typedef  struct TYPE_26__   TYPE_5__ ;
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;
typedef  struct TYPE_21__   TYPE_10__ ;

/* Type definitions */
struct TYPE_23__ {int i_pts; int i_type; int i_qpplus1; } ;
typedef  TYPE_2__ xavs_picture_t ;
struct TYPE_24__ {scalar_t__ i_payload; } ;
typedef  TYPE_3__ xavs_nal_t ;
typedef  int /*<<< orphan*/  va_list ;
typedef  int uint8_t ;
struct TYPE_22__ {int i_plane; int /*<<< orphan*/ * i_stride; int /*<<< orphan*/ * plane; int /*<<< orphan*/  i_csp; } ;
struct TYPE_21__ {int i_pts; int /*<<< orphan*/  i_type; TYPE_1__ img; } ;
struct TYPE_25__ {int sei_size; int* pts_buffer; int out_frame_count; scalar_t__ end_of_stream; TYPE_10__ pic; int /*<<< orphan*/  enc; int /*<<< orphan*/  sei; } ;
typedef  TYPE_4__ XavsContext ;
struct TYPE_28__ {int frame_number; int max_b_frames; scalar_t__ has_b_frames; TYPE_4__* priv_data; } ;
struct TYPE_27__ {int pts; int /*<<< orphan*/ * linesize; int /*<<< orphan*/ * data; } ;
struct TYPE_26__ {int* data; int size; int dts; int pts; int /*<<< orphan*/  flags; } ;
typedef  TYPE_5__ AVPacket ;
typedef  TYPE_6__ AVFrame ;
typedef  TYPE_7__ AVCodecContext ;

/* Variables and functions */
 int AV_INPUT_BUFFER_MIN_SIZE ; 
#define  AV_LOG_DEBUG 140 
#define  AV_LOG_ERROR 139 
#define  AV_LOG_INFO 138 
#define  AV_LOG_WARNING 137 
 int AV_PICTURE_TYPE_B ; 
 int AV_PICTURE_TYPE_I ; 
 int AV_PICTURE_TYPE_NONE ; 
 int AV_PICTURE_TYPE_P ; 
 int /*<<< orphan*/  AV_PKT_FLAG_KEY ; 
 scalar_t__ END_OF_STREAM ; 
 int FF_QP2LAMBDA ; 
 int /*<<< orphan*/  XAVS_CSP_I420 ; 
#define  XAVS_LOG_DEBUG 136 
#define  XAVS_LOG_ERROR 135 
#define  XAVS_LOG_INFO 134 
#define  XAVS_LOG_WARNING 133 
 int /*<<< orphan*/  XAVS_TYPE_AUTO ; 
#define  XAVS_TYPE_B 132 
#define  XAVS_TYPE_BREF 131 
#define  XAVS_TYPE_I 130 
#define  XAVS_TYPE_IDR 129 
#define  XAVS_TYPE_P 128 
 int /*<<< orphan*/  av_vlog (void*,int const,char const*,int /*<<< orphan*/ ) ; 
 int ff_alloc_packet2 (TYPE_7__*,TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_side_data_set_encoder_stats (TYPE_5__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ xavs_encoder_encode (int /*<<< orphan*/ ,TYPE_3__**,int*,TYPE_10__*,TYPE_2__*) ; 
 int xavs_nal_encode (int*,int*,int,TYPE_3__*) ; 

__attribute__((used)) static void XAVS_log(void *p, int level, const char *fmt, va_list args)
{
    static const int level_map[] = {
        [XAVS_LOG_ERROR]   = AV_LOG_ERROR,
        [XAVS_LOG_WARNING] = AV_LOG_WARNING,
        [XAVS_LOG_INFO]    = AV_LOG_INFO,
        [XAVS_LOG_DEBUG]   = AV_LOG_DEBUG
    };

    if (level < 0 || level > XAVS_LOG_DEBUG)
        return;

    av_vlog(p, level_map[level], fmt, args);
}

__attribute__((used)) static int encode_nals(AVCodecContext *ctx, AVPacket *pkt,
                       xavs_nal_t *nals, int nnal)
{
    XavsContext *x4 = ctx->priv_data;
    uint8_t *p;
    int i, s, ret, size = x4->sei_size + AV_INPUT_BUFFER_MIN_SIZE;

    if (!nnal)
        return 0;

    for (i = 0; i < nnal; i++)
        size += nals[i].i_payload;

    if ((ret = ff_alloc_packet2(ctx, pkt, size, 0)) < 0)
        return ret;
    p = pkt->data;

    /* Write the SEI as part of the first frame. */
    if (x4->sei_size > 0 && nnal > 0) {
        memcpy(p, x4->sei, x4->sei_size);
        p += x4->sei_size;
        x4->sei_size = 0;
    }

    for (i = 0; i < nnal; i++) {
        s = xavs_nal_encode(p, &size, 1, nals + i);
        if (s < 0)
            return -1;
        p += s;
    }
    pkt->size = p - pkt->data;

    return 1;
}

__attribute__((used)) static int XAVS_frame(AVCodecContext *avctx, AVPacket *pkt,
                      const AVFrame *frame, int *got_packet)
{
    XavsContext *x4 = avctx->priv_data;
    xavs_nal_t *nal;
    int nnal, i, ret;
    xavs_picture_t pic_out;
    int pict_type;

    x4->pic.img.i_csp   = XAVS_CSP_I420;
    x4->pic.img.i_plane = 3;

    if (frame) {
       for (i = 0; i < 3; i++) {
            x4->pic.img.plane[i] = frame->data[i];
            x4->pic.img.i_stride[i] = frame->linesize[i];
       }

        x4->pic.i_pts  = frame->pts;
        x4->pic.i_type = XAVS_TYPE_AUTO;
        x4->pts_buffer[avctx->frame_number % (avctx->max_b_frames+1)] = frame->pts;
    }

    if (xavs_encoder_encode(x4->enc, &nal, &nnal,
                            frame? &x4->pic: NULL, &pic_out) < 0)
    return -1;

    ret = encode_nals(avctx, pkt, nal, nnal);

    if (ret < 0)
        return -1;

    if (!ret) {
        if (!frame && !(x4->end_of_stream)) {
            if ((ret = ff_alloc_packet2(avctx, pkt, 4, 0)) < 0)
                return ret;

            pkt->data[0] = 0x0;
            pkt->data[1] = 0x0;
            pkt->data[2] = 0x01;
            pkt->data[3] = 0xb1;
            pkt->dts = 2*x4->pts_buffer[(x4->out_frame_count-1)%(avctx->max_b_frames+1)] -
                         x4->pts_buffer[(x4->out_frame_count-2)%(avctx->max_b_frames+1)];
            x4->end_of_stream = END_OF_STREAM;
            *got_packet = 1;
        }
        return 0;
    }

#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
    avctx->coded_frame->pts = pic_out.i_pts;
FF_ENABLE_DEPRECATION_WARNINGS
#endif
    pkt->pts = pic_out.i_pts;
    if (avctx->has_b_frames) {
        if (!x4->out_frame_count)
            pkt->dts = pkt->pts - (x4->pts_buffer[1] - x4->pts_buffer[0]);
        else
            pkt->dts = x4->pts_buffer[(x4->out_frame_count-1)%(avctx->max_b_frames+1)];
    } else
        pkt->dts = pkt->pts;

    switch (pic_out.i_type) {
    case XAVS_TYPE_IDR:
    case XAVS_TYPE_I:
        pict_type = AV_PICTURE_TYPE_I;
        break;
    case XAVS_TYPE_P:
        pict_type = AV_PICTURE_TYPE_P;
        break;
    case XAVS_TYPE_B:
    case XAVS_TYPE_BREF:
        pict_type = AV_PICTURE_TYPE_B;
        break;
    default:
        pict_type = AV_PICTURE_TYPE_NONE;
    }
#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
    avctx->coded_frame->pict_type = pict_type;
FF_ENABLE_DEPRECATION_WARNINGS
#endif

    /* There is no IDR frame in AVS JiZhun */
    /* Sequence header is used as a flag */
    if (pic_out.i_type == XAVS_TYPE_I) {
#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
        avctx->coded_frame->key_frame = 1;
FF_ENABLE_DEPRECATION_WARNINGS
#endif
        pkt->flags |= AV_PKT_FLAG_KEY;
    }

#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
    avctx->coded_frame->quality = (pic_out.i_qpplus1 - 1) * FF_QP2LAMBDA;
FF_ENABLE_DEPRECATION_WARNINGS
#endif

    ff_side_data_set_encoder_stats(pkt, (pic_out.i_qpplus1 - 1) * FF_QP2LAMBDA, NULL, 0, pict_type);

    x4->out_frame_count++;
    *got_packet = ret;
    return 0;
}

