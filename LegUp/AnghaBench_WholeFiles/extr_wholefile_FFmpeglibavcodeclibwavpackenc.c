#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int int32_t ;
struct TYPE_14__ {scalar_t__ frame_size; TYPE_1__* priv_data; } ;
struct TYPE_13__ {scalar_t__ nb_samples; scalar_t__* data; } ;
struct TYPE_12__ {int size; scalar_t__ data; int /*<<< orphan*/  duration; int /*<<< orphan*/  pts; } ;
struct TYPE_11__ {int got_output; int user_size; TYPE_2__* pkt; int /*<<< orphan*/  afq; int /*<<< orphan*/  wv; } ;
typedef  TYPE_1__ LibWavpackContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_UNKNOWN ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int WavpackFlushSamples (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WavpackGetErrorMessage (int /*<<< orphan*/ ) ; 
 int WavpackPackSamples (int /*<<< orphan*/ ,int*,scalar_t__) ; 
 int av_grow_packet (TYPE_2__*,int) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,...) ; 
 int ff_af_queue_add (int /*<<< orphan*/ *,TYPE_3__ const*) ; 
 int /*<<< orphan*/  ff_af_queue_remove (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,void*,int) ; 

__attribute__((used)) static int wavpack_encode_frame(AVCodecContext *avctx, AVPacket *pkt,
                                const AVFrame *frame, int *got_output)
{
    LibWavpackContext *s = avctx->priv_data;
    int ret;

    s->got_output = 0;
    s->pkt        = pkt;
    s->user_size  = pkt->size;

    if (frame) {
        ret = ff_af_queue_add(&s->afq, frame);
        if (ret < 0)
            return ret;

        ret = WavpackPackSamples(s->wv, (int32_t*)frame->data[0], frame->nb_samples);
        if (!ret) {
            av_log(avctx, AV_LOG_ERROR, "Error encoding a frame: %s\n",
                   WavpackGetErrorMessage(s->wv));
            return AVERROR_UNKNOWN;
        }
    }

    if (!s->got_output &&
        (!frame || frame->nb_samples < avctx->frame_size)) {
        ret = WavpackFlushSamples(s->wv);
        if (!ret) {
            av_log(avctx, AV_LOG_ERROR, "Error flushing the encoder: %s\n",
                   WavpackGetErrorMessage(s->wv));
            return AVERROR_UNKNOWN;
        }
    }

    if (s->got_output) {
        ff_af_queue_remove(&s->afq, avctx->frame_size, &pkt->pts, &pkt->duration);
        *got_output = 1;
    }

    return 0;
}

__attribute__((used)) static int encode_callback(void *id, void *data, int32_t count)
{
    AVCodecContext *avctx = id;
    LibWavpackContext *s  = avctx->priv_data;
    int ret, offset = s->pkt->size;

    if (s->user_size) {
        if (s->user_size - count < s->pkt->size) {
            av_log(avctx, AV_LOG_ERROR, "Provided packet too small.\n");
            return 0;
        }
        s->pkt->size += count;
    } else {
        ret = av_grow_packet(s->pkt, count);
        if (ret < 0) {
            av_log(avctx, AV_LOG_ERROR, "Error allocating output packet.\n");
            return 0;
        }
    }

    memcpy(s->pkt->data + offset, data, count);

    s->got_output = 1;

    return 1;
}

