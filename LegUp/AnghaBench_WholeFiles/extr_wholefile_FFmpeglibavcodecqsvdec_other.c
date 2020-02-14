#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_9__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  pkt ;
typedef  int /*<<< orphan*/  input_ref ;
struct TYPE_21__ {scalar_t__ reinit_flag; } ;
struct TYPE_20__ {TYPE_1__* priv_data; } ;
struct TYPE_19__ {int size; int data; int /*<<< orphan*/  member_0; } ;
struct TYPE_18__ {TYPE_9__ qsv; TYPE_2__ input_ref; int /*<<< orphan*/  packet_fifo; } ;
typedef  TYPE_1__ QSVOtherContext ;
typedef  TYPE_2__ AVPacket ;
typedef  int /*<<< orphan*/  AVFrame ;
typedef  TYPE_3__ AVCodecContext ;

/* Variables and functions */
 int /*<<< orphan*/  av_fifo_generic_read (int /*<<< orphan*/ ,TYPE_2__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_fifo_generic_write (int /*<<< orphan*/ ,TYPE_2__*,int,int /*<<< orphan*/ *) ; 
 int av_fifo_realloc2 (int /*<<< orphan*/ ,int) ; 
 int av_fifo_size (int /*<<< orphan*/ ) ; 
 int av_fifo_space (int /*<<< orphan*/ ) ; 
 int av_packet_ref (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_2__*) ; 
 int /*<<< orphan*/  ff_qsv_decode_flush (TYPE_3__*,TYPE_9__*) ; 
 int ff_qsv_process_data (TYPE_3__*,TYPE_9__*,int /*<<< orphan*/ *,int*,TYPE_2__*) ; 

__attribute__((used)) static void qsv_clear_buffers(QSVOtherContext *s)
{
    AVPacket pkt;
    while (av_fifo_size(s->packet_fifo) >= sizeof(pkt)) {
        av_fifo_generic_read(s->packet_fifo, &pkt, sizeof(pkt), NULL);
        av_packet_unref(&pkt);
    }

    av_packet_unref(&s->input_ref);
}

__attribute__((used)) static int qsv_decode_frame(AVCodecContext *avctx, void *data,
                            int *got_frame, AVPacket *avpkt)
{
    QSVOtherContext *s = avctx->priv_data;
    AVFrame *frame    = data;
    int ret;

    /* buffer the input packet */
    if (avpkt->size) {
        AVPacket input_ref = { 0 };

        if (av_fifo_space(s->packet_fifo) < sizeof(input_ref)) {
            ret = av_fifo_realloc2(s->packet_fifo,
                                   av_fifo_size(s->packet_fifo) + sizeof(input_ref));
            if (ret < 0)
                return ret;
        }

        ret = av_packet_ref(&input_ref, avpkt);
        if (ret < 0)
            return ret;
        av_fifo_generic_write(s->packet_fifo, &input_ref, sizeof(input_ref), NULL);
    }

    /* process buffered data */
    while (!*got_frame) {
        if (s->input_ref.size <= 0) {
            /* no more data */
            if (av_fifo_size(s->packet_fifo) < sizeof(AVPacket))
                return avpkt->size ? avpkt->size : ff_qsv_process_data(avctx, &s->qsv, frame, got_frame, avpkt);
            /* in progress of reinit, no read from fifo and keep the buffer_pkt */
            if (!s->qsv.reinit_flag) {
                av_packet_unref(&s->input_ref);
                av_fifo_generic_read(s->packet_fifo, &s->input_ref, sizeof(s->input_ref), NULL);
            }
        }

        ret = ff_qsv_process_data(avctx, &s->qsv, frame, got_frame, &s->input_ref);
        if (ret < 0) {
            /* Drop input packet when failed to decode the packet. Otherwise,
               the decoder will keep decoding the failure packet. */
            av_packet_unref(&s->input_ref);

            return ret;
        }
        if (s->qsv.reinit_flag)
            continue;

        s->input_ref.size -= ret;
        s->input_ref.data += ret;
    }

    return avpkt->size;
}

__attribute__((used)) static void qsv_decode_flush(AVCodecContext *avctx)
{
    QSVOtherContext *s = avctx->priv_data;

    qsv_clear_buffers(s);
    ff_qsv_decode_flush(avctx, &s->qsv);
}

