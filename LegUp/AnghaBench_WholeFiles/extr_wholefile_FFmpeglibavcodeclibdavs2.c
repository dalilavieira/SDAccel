#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_31__   TYPE_6__ ;
typedef  struct TYPE_30__   TYPE_5__ ;
typedef  struct TYPE_29__   TYPE_4__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_23__ ;
typedef  struct TYPE_25__   TYPE_1__ ;
typedef  struct TYPE_24__   TYPE_14__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_25__ {int output_bit_depth; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  frame_rate; } ;
typedef  TYPE_1__ davs2_seq_info_t ;
struct TYPE_27__ {int bytes_per_sample; int type; int* widths; int* lines; int* strides; int /*<<< orphan*/  pts; scalar_t__* planes; } ;
typedef  TYPE_2__ davs2_picture_t ;
struct TYPE_31__ {TYPE_3__* priv_data; int /*<<< orphan*/  pix_fmt; int /*<<< orphan*/  framerate; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct TYPE_30__ {int* linesize; int /*<<< orphan*/  format; int /*<<< orphan*/  pts; int /*<<< orphan*/  height; int /*<<< orphan*/  width; scalar_t__* data; TYPE_23__** buf; int /*<<< orphan*/  pict_type; } ;
struct TYPE_29__ {int size; int /*<<< orphan*/  dts; int /*<<< orphan*/  pts; int /*<<< orphan*/ * data; } ;
struct TYPE_24__ {int len; int /*<<< orphan*/  dts; int /*<<< orphan*/  pts; int /*<<< orphan*/ * data; } ;
struct TYPE_28__ {TYPE_2__ out_frame; int /*<<< orphan*/  decoder; TYPE_1__ headerset; TYPE_14__ packet; } ;
struct TYPE_26__ {scalar_t__ data; } ;
typedef  TYPE_3__ DAVS2Context ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVFrame ;
typedef  TYPE_6__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EXTERNAL ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_B ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_S ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV420P ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV420P10 ; 
 int DAVS2_DEFAULT ; 
 int DAVS2_ERROR ; 
 int DAVS2_GOT_FRAME ; 
 int DAVS2_GOT_HEADER ; 
#define  DAVS2_PIC_B 133 
#define  DAVS2_PIC_F 132 
#define  DAVS2_PIC_G 131 
#define  DAVS2_PIC_I 130 
#define  DAVS2_PIC_P 129 
#define  DAVS2_PIC_S 128 
 int /*<<< orphan*/  ENOMEM ; 
 TYPE_23__* av_buffer_alloc (int) ; 
 int /*<<< orphan*/  av_d2q (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*) ; 
 int davs2_decoder_flush (int /*<<< orphan*/ ,TYPE_1__*,TYPE_2__*) ; 
 int /*<<< orphan*/  davs2_decoder_frame_unref (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int davs2_decoder_recv_frame (int /*<<< orphan*/ ,TYPE_1__*,TYPE_2__*) ; 
 int davs2_decoder_send_packet (int /*<<< orphan*/ ,TYPE_14__*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,scalar_t__,int) ; 

__attribute__((used)) static int davs2_dump_frames(AVCodecContext *avctx, davs2_picture_t *pic, int *got_frame,
                             davs2_seq_info_t *headerset, int ret_type, AVFrame *frame)
{
    DAVS2Context *cad    = avctx->priv_data;
    int bytes_per_sample = pic->bytes_per_sample;
    int plane = 0;
    int line  = 0;

    if (!headerset) {
        *got_frame = 0;
        return 0;
    }

    if (!pic || ret_type == DAVS2_GOT_HEADER) {
        avctx->width     = headerset->width;
        avctx->height    = headerset->height;
        avctx->pix_fmt   = headerset->output_bit_depth == 10 ?
                           AV_PIX_FMT_YUV420P10 : AV_PIX_FMT_YUV420P;

        avctx->framerate = av_d2q(headerset->frame_rate,4096);
        *got_frame = 0;
        return 0;
    }

    switch (pic->type) {
    case DAVS2_PIC_I:
    case DAVS2_PIC_G:
        frame->pict_type = AV_PICTURE_TYPE_I;
        break;
    case DAVS2_PIC_P:
    case DAVS2_PIC_S:
        frame->pict_type = AV_PICTURE_TYPE_P;
        break;
    case DAVS2_PIC_B:
        frame->pict_type = AV_PICTURE_TYPE_B;
        break;
    case DAVS2_PIC_F:
        frame->pict_type = AV_PICTURE_TYPE_S;
        break;
    default:
        av_log(avctx, AV_LOG_ERROR, "Decoder error: unknown frame type\n");
        return AVERROR_EXTERNAL;
    }

    for (plane = 0; plane < 3; ++plane) {
        int size_line = pic->widths[plane] * bytes_per_sample;
        frame->buf[plane]  = av_buffer_alloc(size_line * pic->lines[plane]);

        if (!frame->buf[plane]){
            av_log(avctx, AV_LOG_ERROR, "Decoder error: allocation failure, can't dump frames.\n");
            return AVERROR(ENOMEM);
        }

        frame->data[plane]     = frame->buf[plane]->data;
        frame->linesize[plane] = size_line;

        for (line = 0; line < pic->lines[plane]; ++line)
            memcpy(frame->data[plane] + line * size_line,
                   pic->planes[plane] + line * pic->strides[plane],
                   pic->widths[plane] * bytes_per_sample);
    }

    frame->width     = cad->headerset.width;
    frame->height    = cad->headerset.height;
    frame->pts       = cad->out_frame.pts;
    frame->format    = avctx->pix_fmt;

    *got_frame = 1;
    return 0;
}

__attribute__((used)) static void davs2_flush(AVCodecContext *avctx)
{
    DAVS2Context *cad      = avctx->priv_data;
    int           ret      = DAVS2_GOT_FRAME;

    while (ret == DAVS2_GOT_FRAME) {
        ret = davs2_decoder_flush(cad->decoder, &cad->headerset, &cad->out_frame);
        davs2_decoder_frame_unref(cad->decoder, &cad->out_frame);
    }

    if (ret == DAVS2_ERROR) {
        av_log(avctx, AV_LOG_WARNING, "Decoder flushing failed.\n");
    }
}

__attribute__((used)) static int send_delayed_frame(AVCodecContext *avctx, AVFrame *frame, int *got_frame)
{
    DAVS2Context *cad      = avctx->priv_data;
    int           ret      = DAVS2_DEFAULT;

    ret = davs2_decoder_flush(cad->decoder, &cad->headerset, &cad->out_frame);
    if (ret == DAVS2_ERROR) {
        av_log(avctx, AV_LOG_ERROR, "Decoder error: can't flush delayed frame\n");
        return AVERROR_EXTERNAL;
    }
    if (ret == DAVS2_GOT_FRAME) {
        ret = davs2_dump_frames(avctx, &cad->out_frame, got_frame, &cad->headerset, ret, frame);
        davs2_decoder_frame_unref(cad->decoder, &cad->out_frame);
    }
    return ret;
}

__attribute__((used)) static int davs2_decode_frame(AVCodecContext *avctx, void *data,
                              int *got_frame, AVPacket *avpkt)
{
    DAVS2Context *cad      = avctx->priv_data;
    int           buf_size = avpkt->size;
    uint8_t      *buf_ptr  = avpkt->data;
    AVFrame      *frame    = data;
    int           ret      = DAVS2_DEFAULT;

    /* end of stream, output what is still in the buffers */
    if (!buf_size) {
        return send_delayed_frame(avctx, frame, got_frame);
    }

    cad->packet.data = buf_ptr;
    cad->packet.len  = buf_size;
    cad->packet.pts  = avpkt->pts;
    cad->packet.dts  = avpkt->dts;

    ret = davs2_decoder_send_packet(cad->decoder, &cad->packet);


    if (ret == DAVS2_ERROR) {
        av_log(avctx, AV_LOG_ERROR, "Decoder error: can't read packet\n");
        return AVERROR_EXTERNAL;
    }

    ret = davs2_decoder_recv_frame(cad->decoder, &cad->headerset, &cad->out_frame);

    if (ret != DAVS2_DEFAULT) {
        ret = davs2_dump_frames(avctx, &cad->out_frame, got_frame, &cad->headerset, ret, frame);
        davs2_decoder_frame_unref(cad->decoder, &cad->out_frame);
    }

    return ret == 0 ? buf_size : ret;
}

