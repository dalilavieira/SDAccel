#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_6__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;
typedef  struct TYPE_18__   TYPE_11__ ;

/* Type definitions */
struct TYPE_18__ {scalar_t__ data; int flags; int /*<<< orphan*/  pts; } ;
struct ff_packet {TYPE_11__ base; int /*<<< orphan*/ * clock; int /*<<< orphan*/  member_0; } ;
struct ff_frame {double pts; int /*<<< orphan*/  clock; TYPE_3__* frame; } ;
struct TYPE_19__ {scalar_t__ data; } ;
struct TYPE_20__ {TYPE_1__ base; } ;
struct TYPE_23__ {TYPE_2__ flush_packet; } ;
struct ff_decoder {int finished; int /*<<< orphan*/ * clock; TYPE_4__* codec; TYPE_6__ packet_queue; scalar_t__ eof; scalar_t__ abort; int /*<<< orphan*/  frame_queue; int /*<<< orphan*/  callbacks; } ;
typedef  scalar_t__ int64_t ;
struct TYPE_22__ {scalar_t__ width; scalar_t__ height; scalar_t__ pix_fmt; } ;
struct TYPE_21__ {scalar_t__ width; scalar_t__ height; scalar_t__ format; } ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 scalar_t__ AV_NOPTS_VALUE ; 
 int AV_PKT_FLAG_KEY ; 
 int FF_PACKET_EMPTY ; 
 int FF_PACKET_FAIL ; 
 TYPE_3__* av_frame_alloc () ; 
 TYPE_3__* av_frame_clone (TYPE_3__*) ; 
 int /*<<< orphan*/  av_frame_free (TYPE_3__**) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_3__*) ; 
 int /*<<< orphan*/  av_free_packet (TYPE_11__*) ; 
 int /*<<< orphan*/  avcodec_decode_video2 (TYPE_4__*,TYPE_3__*,int*,TYPE_11__*) ; 
 int /*<<< orphan*/  avcodec_flush_buffers (TYPE_4__*) ; 
 int /*<<< orphan*/  ff_callbacks_frame_initialize (struct ff_frame*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_circular_queue_advance_write (int /*<<< orphan*/ *,struct ff_frame*) ; 
 struct ff_frame* ff_circular_queue_peek_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ff_circular_queue_wait_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ff_clock_move (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  ff_clock_release (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  ff_clock_retain (int /*<<< orphan*/ *) ; 
 scalar_t__ ff_clock_start_time (int /*<<< orphan*/ *) ; 
 double ff_decoder_get_best_effort_pts (struct ff_decoder*,TYPE_3__*) ; 
 int /*<<< orphan*/  ff_decoder_set_frame_drop_state (struct ff_decoder*,scalar_t__,int /*<<< orphan*/ ) ; 
 int packet_queue_get (TYPE_6__*,struct ff_packet*,int) ; 

__attribute__((used)) static bool queue_frame(struct ff_decoder *decoder, AVFrame *frame,
		double best_effort_pts)
{
	struct ff_frame *queue_frame;
	bool call_initialize;

	ff_circular_queue_wait_write(&decoder->frame_queue);

	if (decoder->abort) {
		return false;
	}

	queue_frame = ff_circular_queue_peek_write(&decoder->frame_queue);

	// Check if we need to communicate a different format has been received
	// to any callbacks
	AVCodecContext *codec = decoder->codec;
	call_initialize = (queue_frame->frame == NULL
			|| queue_frame->frame->width != codec->width
			|| queue_frame->frame->height != codec->height
			|| queue_frame->frame->format != codec->pix_fmt);

	if (queue_frame->frame != NULL) {
		// This shouldn't happen any more, the frames are freed in
		// ff_decoder_refresh.
		av_frame_free(&queue_frame->frame);
	}

	queue_frame->frame = av_frame_clone(frame);
	queue_frame->clock = ff_clock_retain(decoder->clock);

	if (call_initialize)
		ff_callbacks_frame_initialize(queue_frame, decoder->callbacks);

	queue_frame->pts = best_effort_pts;

	ff_circular_queue_advance_write(&decoder->frame_queue, queue_frame);

	return true;
}

void *ff_video_decoder_thread(void *opaque_video_decoder)
{
	struct ff_decoder *decoder = (struct ff_decoder*)opaque_video_decoder;

	struct ff_packet packet = {0};
	int complete;
	AVFrame *frame = av_frame_alloc();
	int ret;
	bool key_frame;

	while (!decoder->abort) {
		if (decoder->eof)
			ret = packet_queue_get(&decoder->packet_queue, &packet, 0);
		else
			ret = packet_queue_get(&decoder->packet_queue, &packet, 1);

		if (ret == FF_PACKET_EMPTY || ret == FF_PACKET_FAIL) {
			// should we just use abort here?
			break;
		}

		if (packet.base.data == decoder->packet_queue.flush_packet.base.data) {
			avcodec_flush_buffers(decoder->codec);
			continue;
		}

		// We received a reset packet with a new clock
		if (packet.clock != NULL) {
			if (decoder->clock != NULL)
				ff_clock_release(&decoder->clock);
			decoder->clock = ff_clock_move(&packet.clock);
			av_free_packet(&packet.base);
			continue;
		}

		int64_t start_time = ff_clock_start_time(decoder->clock);
		key_frame = packet.base.flags & AV_PKT_FLAG_KEY;

		// We can only make decisions on keyframes for
		// hw decoders (maybe just OSX?)
		// For now, always make drop decisions on keyframes
		bool frame_drop_check = key_frame;
		// Must have a proper packet pts to drop frames here
		frame_drop_check &= start_time != AV_NOPTS_VALUE;

		if (frame_drop_check)
			ff_decoder_set_frame_drop_state(decoder,
					start_time, packet.base.pts);

		avcodec_decode_video2(decoder->codec, frame,
				&complete, &packet.base);

		// Did we get an entire video frame?  This doesn't guarantee
		// there is a picture to show for some codecs, but we still want
		// to adjust our various internal clocks for the next frame
		if (complete) {
			// If we don't have a good PTS, try to guess based
			// on last received PTS provided plus prediction
			// This function returns a pts scaled to stream
			// time base
			double best_effort_pts =
				ff_decoder_get_best_effort_pts(decoder, frame);

			queue_frame(decoder, frame, best_effort_pts);
			av_frame_unref(frame);
		}

		av_free_packet(&packet.base);
	}

	if (decoder->clock != NULL)
		ff_clock_release(&decoder->clock);

	av_frame_free(&frame);

	decoder->finished = true;

	return NULL;
}

