#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;
typedef  struct TYPE_21__   TYPE_12__ ;

/* Type definitions */
struct TYPE_21__ {int size; int /*<<< orphan*/ * data; int /*<<< orphan*/  pts; } ;
struct ff_packet {TYPE_12__ base; int /*<<< orphan*/  member_0; int /*<<< orphan*/ * clock; } ;
struct ff_frame {double pts; int /*<<< orphan*/  clock; TYPE_3__* frame; } ;
struct TYPE_22__ {int /*<<< orphan*/ * data; } ;
struct TYPE_23__ {TYPE_1__ base; } ;
struct TYPE_26__ {TYPE_2__ flush_packet; } ;
struct ff_decoder {int finished; int /*<<< orphan*/ * clock; scalar_t__ abort; int /*<<< orphan*/  frame_queue; int /*<<< orphan*/  callbacks; TYPE_4__* codec; TYPE_6__ packet_queue; scalar_t__ eof; } ;
typedef  scalar_t__ int64_t ;
struct TYPE_25__ {scalar_t__ channels; scalar_t__ sample_rate; scalar_t__ sample_fmt; } ;
struct TYPE_24__ {scalar_t__ nb_samples; scalar_t__ format; scalar_t__ channels; scalar_t__ sample_rate; } ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 scalar_t__ AV_NOPTS_VALUE ; 
 int FF_PACKET_EMPTY ; 
 int FF_PACKET_FAIL ; 
 TYPE_3__* av_frame_alloc () ; 
 TYPE_3__* av_frame_clone (TYPE_3__*) ; 
 int /*<<< orphan*/  av_frame_free (TYPE_3__**) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_3__*) ; 
 int /*<<< orphan*/  av_free_packet (TYPE_12__*) ; 
 int av_get_bytes_per_sample (scalar_t__) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_12__*) ; 
 int /*<<< orphan*/  av_shrink_packet (TYPE_12__*,int) ; 
 int avcodec_decode_audio4 (TYPE_4__*,TYPE_3__*,int*,TYPE_12__*) ; 
 int /*<<< orphan*/  avcodec_flush_buffers (TYPE_4__*) ; 
 int /*<<< orphan*/  ff_callbacks_frame_initialize (struct ff_frame*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ff_circular_queue_advance_write (int /*<<< orphan*/ *,struct ff_frame*) ; 
 struct ff_frame* ff_circular_queue_peek_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ff_circular_queue_wait_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ff_clock_release (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  ff_clock_retain (int /*<<< orphan*/ *) ; 
 scalar_t__ ff_clock_start_time (int /*<<< orphan*/ *) ; 
 double ff_decoder_get_best_effort_pts (struct ff_decoder*,TYPE_3__*) ; 
 scalar_t__ ff_decoder_set_frame_drop_state (struct ff_decoder*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memmove (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int packet_queue_get (TYPE_6__*,struct ff_packet*,int) ; 

__attribute__((used)) static inline void shrink_packet(struct ff_packet *packet, int packet_length)
{
	if (packet_length <= packet->base.size) {
		int remaining = packet->base.size - packet_length;

		memmove(packet->base.data, &packet->base.data[packet_length],
				remaining);
		av_shrink_packet(&packet->base, remaining);
	}
}

__attribute__((used)) static bool handle_reset_packet(struct ff_decoder *decoder,
		struct ff_packet *packet)
{
	if (decoder->clock != NULL)
		ff_clock_release(&decoder->clock);
	decoder->clock = packet->clock;
	av_free_packet(&packet->base);

	return true;
}

__attribute__((used)) static void drop_late_packets(struct ff_decoder *decoder,
		struct ff_packet *packet)
{
	int64_t start_time = ff_clock_start_time(decoder->clock);
	if (start_time != AV_NOPTS_VALUE) {
		if (ff_decoder_set_frame_drop_state(decoder, start_time,
				packet->base.pts))
			shrink_packet(packet, packet->base.size);
	}
}

__attribute__((used)) static int decode_frame(struct ff_decoder *decoder,
	struct ff_packet *packet, AVFrame *frame, bool *frame_complete)
{
	int packet_length;
	int ret;

	while (true) {
		if (decoder->eof)
			ret = packet_queue_get(&decoder->packet_queue, packet, 0);
		else
			ret = packet_queue_get(&decoder->packet_queue, packet, 1);

		if (ret == FF_PACKET_EMPTY) {
			return 0;
		} else if (ret == FF_PACKET_FAIL) {
			return -1;
		}

		if (packet->base.data ==
				decoder->packet_queue.flush_packet.base.data) {
			avcodec_flush_buffers(decoder->codec);
			continue;
		}

		// Packet has a new clock (reset packet)
		if (packet->clock != NULL)
			if (!handle_reset_packet(decoder, packet))
				return -1;

		while (packet->base.size > 0) {
			int complete;

			drop_late_packets(decoder, packet);

			packet_length = avcodec_decode_audio4(decoder->codec,
				frame, &complete,
				&packet->base);

			if (packet_length < 0)
				break;

			shrink_packet(packet, packet_length);

			if (complete == 0 || frame->nb_samples <= 0)
				continue;

			*frame_complete = complete != 0;

			return frame->nb_samples *
				av_get_bytes_per_sample(frame->format);
		}

		if (packet->base.data != NULL)
			av_packet_unref(&packet->base);
	}
}

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

	AVCodecContext *codec = decoder->codec;
	call_initialize = (queue_frame->frame == NULL
			|| queue_frame->frame->channels != codec->channels
			|| queue_frame->frame->sample_rate != codec->sample_rate
			|| queue_frame->frame->format != codec->sample_fmt);

	if (queue_frame->frame != NULL) {
		//FIXME: this shouldn't happen any more!
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

void *ff_audio_decoder_thread(void *opaque_audio_decoder)
{
	struct ff_decoder *decoder = opaque_audio_decoder;

	struct ff_packet packet = {0};
	bool frame_complete;
	AVFrame *frame = av_frame_alloc();
	int ret;

	while (!decoder->abort) {
		ret = decode_frame(decoder, &packet, frame, &frame_complete);
		if (ret == 0) {
			break;
		} else if (ret < 0) {
			av_free_packet(&packet.base);
			continue;
		}

		// Did we get a audio frame?
		if (frame_complete) {
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

