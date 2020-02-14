#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_4__ {int size; int flags; int /*<<< orphan*/ * data; int /*<<< orphan*/  buf; } ;
typedef  TYPE_1__ AVPacket ;
typedef  int /*<<< orphan*/  AVFrame ;
typedef  int /*<<< orphan*/  AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AV_BUFFER_FLAG_READONLY ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int AV_PKT_FLAG_KEY ; 
 int AV_PKT_FLAG_TRUSTED ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  EPERM ; 
 int /*<<< orphan*/  av_buffer_create (int /*<<< orphan*/ *,int,void (*) (void*,int /*<<< orphan*/ *),int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * av_frame_clone (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  av_frame_free (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  av_frame_move_ref (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_frame_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_freep (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/ * av_mallocz (int) ; 
 int ff_attach_decode_data (int /*<<< orphan*/ *) ; 
 int ff_decode_frame_props (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void wrapped_avframe_release_buffer(void *unused, uint8_t *data)
{
    AVFrame *frame = (AVFrame *)data;

    av_frame_free(&frame);
}

__attribute__((used)) static int wrapped_avframe_encode(AVCodecContext *avctx, AVPacket *pkt,
                     const AVFrame *frame, int *got_packet)
{
    AVFrame *wrapped = av_frame_clone(frame);
    uint8_t *data;
    int size = sizeof(*wrapped) + AV_INPUT_BUFFER_PADDING_SIZE;

    if (!wrapped)
        return AVERROR(ENOMEM);

    data = av_mallocz(size);
    if (!data) {
        av_frame_free(&wrapped);
        return AVERROR(ENOMEM);
    }

    pkt->buf = av_buffer_create(data, size,
                                wrapped_avframe_release_buffer, NULL,
                                AV_BUFFER_FLAG_READONLY);
    if (!pkt->buf) {
        av_frame_free(&wrapped);
        av_freep(&data);
        return AVERROR(ENOMEM);
    }

    av_frame_move_ref((AVFrame*)data, wrapped);
    av_frame_free(&wrapped);

    pkt->data = data;
    pkt->size = sizeof(*wrapped);

    pkt->flags |= AV_PKT_FLAG_KEY;
    *got_packet = 1;
    return 0;
}

__attribute__((used)) static int wrapped_avframe_decode(AVCodecContext *avctx, void *data,
                                  int *got_frame, AVPacket *pkt)
{
    AVFrame *in, *out;
    int err;

    if (!(pkt->flags & AV_PKT_FLAG_TRUSTED)) {
        // This decoder is not usable with untrusted input.
        return AVERROR(EPERM);
    }

    if (pkt->size < sizeof(AVFrame))
        return AVERROR(EINVAL);

    in  = (AVFrame*)pkt->data;
    out = data;

    err = ff_decode_frame_props(avctx, out);
    if (err < 0)
        return err;

    av_frame_move_ref(out, in);

    err = ff_attach_decode_data(out);
    if (err < 0) {
        av_frame_unref(out);
        return err;
    }

    *got_frame = 1;
    return 0;
}

