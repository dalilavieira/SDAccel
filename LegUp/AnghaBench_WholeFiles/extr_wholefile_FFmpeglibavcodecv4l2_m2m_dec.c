#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_8__ ;
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sub ;
struct TYPE_23__ {scalar_t__ height; scalar_t__ width; } ;
struct TYPE_21__ {int /*<<< orphan*/  pixelformat; } ;
struct TYPE_22__ {TYPE_1__ pix_mp; } ;
struct v4l2_selection {int /*<<< orphan*/  type; TYPE_3__ r; TYPE_2__ fmt; } ;
struct v4l2_event_subscription {int /*<<< orphan*/  type; TYPE_3__ r; TYPE_2__ fmt; } ;
struct TYPE_24__ {TYPE_5__* context; } ;
typedef  TYPE_4__ V4L2m2mPriv ;
struct TYPE_26__ {scalar_t__ height; scalar_t__ width; int /*<<< orphan*/  buffers; int /*<<< orphan*/  av_pix_fmt; struct v4l2_selection format; int /*<<< orphan*/  type; scalar_t__ streamon; } ;
struct TYPE_25__ {scalar_t__ draining; TYPE_6__ output; TYPE_6__ capture; TYPE_8__* avctx; int /*<<< orphan*/  fd; } ;
typedef  TYPE_5__ V4L2m2mContext ;
typedef  TYPE_6__ V4L2Context ;
struct TYPE_28__ {scalar_t__ coded_height; scalar_t__ coded_width; scalar_t__ priv_data; int /*<<< orphan*/  pix_fmt; } ;
struct TYPE_27__ {scalar_t__ size; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_7__ AVPacket ;
typedef  int /*<<< orphan*/  AVFrame ;
typedef  TYPE_8__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int /*<<< orphan*/  AV_CODEC_ID_RAWVIDEO ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  V4L2_BUF_TYPE_VIDEO_CAPTURE ; 
 int /*<<< orphan*/  V4L2_EVENT_SOURCE_CHANGE ; 
 int /*<<< orphan*/  VIDIOC_G_FMT ; 
 int /*<<< orphan*/  VIDIOC_G_SELECTION ; 
 int /*<<< orphan*/  VIDIOC_STREAMON ; 
 int /*<<< orphan*/  VIDIOC_SUBSCRIBE_EVENT ; 
 int /*<<< orphan*/  VIDIOC_S_SELECTION ; 
 int /*<<< orphan*/  av_log (TYPE_8__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_7__*) ; 
 int ff_decode_get_packet (TYPE_8__*,TYPE_7__*) ; 
 int ff_v4l2_context_dequeue_frame (TYPE_6__* const,int /*<<< orphan*/ *) ; 
 int ff_v4l2_context_enqueue_packet (TYPE_6__* const,TYPE_7__*) ; 
 int ff_v4l2_context_init (TYPE_6__* const) ; 
 int ff_v4l2_context_set_status (TYPE_6__* const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_v4l2_format_v4l2_to_avfmt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ioctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct v4l2_selection*) ; 
 int /*<<< orphan*/  memset (struct v4l2_selection*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int v4l2_try_start(AVCodecContext *avctx)
{
    V4L2m2mContext *s = ((V4L2m2mPriv*)avctx->priv_data)->context;
    V4L2Context *const capture = &s->capture;
    V4L2Context *const output = &s->output;
    struct v4l2_selection selection;
    int ret;

    /* 1. start the output process */
    if (!output->streamon) {
        ret = ff_v4l2_context_set_status(output, VIDIOC_STREAMON);
        if (ret < 0) {
            av_log(avctx, AV_LOG_DEBUG, "VIDIOC_STREAMON on output context\n");
            return ret;
        }
    }

    if (capture->streamon)
        return 0;

    /* 2. get the capture format */
    capture->format.type = capture->type;
    ret = ioctl(s->fd, VIDIOC_G_FMT, &capture->format);
    if (ret) {
        av_log(avctx, AV_LOG_WARNING, "VIDIOC_G_FMT ioctl\n");
        return ret;
    }

    /* 2.1 update the AVCodecContext */
    avctx->pix_fmt = ff_v4l2_format_v4l2_to_avfmt(capture->format.fmt.pix_mp.pixelformat, AV_CODEC_ID_RAWVIDEO);
    capture->av_pix_fmt = avctx->pix_fmt;

    /* 3. set the crop parameters */
    selection.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    selection.r.height = avctx->coded_height;
    selection.r.width = avctx->coded_width;
    ret = ioctl(s->fd, VIDIOC_S_SELECTION, &selection);
    if (!ret) {
        ret = ioctl(s->fd, VIDIOC_G_SELECTION, &selection);
        if (ret) {
            av_log(avctx, AV_LOG_WARNING, "VIDIOC_G_SELECTION ioctl\n");
        } else {
            av_log(avctx, AV_LOG_DEBUG, "crop output %dx%d\n", selection.r.width, selection.r.height);
            /* update the size of the resulting frame */
            capture->height = selection.r.height;
            capture->width  = selection.r.width;
        }
    }

    /* 4. init the capture context now that we have the capture format */
    if (!capture->buffers) {
        ret = ff_v4l2_context_init(capture);
        if (ret) {
            av_log(avctx, AV_LOG_DEBUG, "can't request output buffers\n");
            return ret;
        }
    }

    /* 5. start the capture process */
    ret = ff_v4l2_context_set_status(capture, VIDIOC_STREAMON);
    if (ret) {
        av_log(avctx, AV_LOG_DEBUG, "VIDIOC_STREAMON, on capture context\n");
        return ret;
    }

    return 0;
}

__attribute__((used)) static int v4l2_prepare_decoder(V4L2m2mContext *s)
{
    struct v4l2_event_subscription sub;
    V4L2Context *output = &s->output;
    int ret;

    /**
     * requirements
     */
    memset(&sub, 0, sizeof(sub));
    sub.type = V4L2_EVENT_SOURCE_CHANGE;
    ret = ioctl(s->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    if ( ret < 0) {
        if (output->height == 0 || output->width == 0) {
            av_log(s->avctx, AV_LOG_ERROR,
                "the v4l2 driver does not support VIDIOC_SUBSCRIBE_EVENT\n"
                "you must provide codec_height and codec_width on input\n");
            return ret;
        }
    }

    return 0;
}

__attribute__((used)) static int v4l2_receive_frame(AVCodecContext *avctx, AVFrame *frame)
{
    V4L2m2mContext *s = ((V4L2m2mPriv*)avctx->priv_data)->context;
    V4L2Context *const capture = &s->capture;
    V4L2Context *const output = &s->output;
    AVPacket avpkt = {0};
    int ret;

    ret = ff_decode_get_packet(avctx, &avpkt);
    if (ret < 0 && ret != AVERROR_EOF)
        return ret;

    if (s->draining)
        goto dequeue;

    ret = ff_v4l2_context_enqueue_packet(output, &avpkt);
    if (ret < 0) {
        if (ret != AVERROR(ENOMEM))
           return ret;
        /* no input buffers available, continue dequeing */
    }

    if (avpkt.size) {
        ret = v4l2_try_start(avctx);
        if (ret) {
            av_packet_unref(&avpkt);
            return 0;
        }
    }

dequeue:
    av_packet_unref(&avpkt);
    return ff_v4l2_context_dequeue_frame(capture, frame);
}

