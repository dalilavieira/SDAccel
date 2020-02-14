#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct obs_source_frame2 {int format; int flip; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  color_range_max; int /*<<< orphan*/  color_range_min; int /*<<< orphan*/  color_matrix; int /*<<< orphan*/  range; int /*<<< orphan*/ * linesize; int /*<<< orphan*/ * data; } ;
struct obs_source_audio {int format; int speakers; int /*<<< orphan*/  frames; int /*<<< orphan*/  samples_per_sec; int /*<<< orphan*/ * data; } ;
struct ffmpeg_decode {size_t packet_size; TYPE_2__* frame; TYPE_2__* decoder; TYPE_7__* codec; scalar_t__ packet_buffer; } ;
typedef  enum video_format { ____Placeholder_video_format } video_format ;
typedef  enum speaker_layout { ____Placeholder_speaker_layout } speaker_layout ;
typedef  enum audio_format { ____Placeholder_audio_format } audio_format ;
typedef  enum AVCodecID { ____Placeholder_AVCodecID } AVCodecID ;
struct TYPE_16__ {int capabilities; scalar_t__ id; } ;
struct TYPE_15__ {int format; scalar_t__ color_range; long long pkt_pts; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/ * linesize; int /*<<< orphan*/ * data; int /*<<< orphan*/  nb_samples; scalar_t__ channels; int /*<<< orphan*/  sample_rate; int /*<<< orphan*/  flags; } ;
struct TYPE_14__ {int size; long long pts; int /*<<< orphan*/  flags; scalar_t__ data; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ AVPacket ;

/* Variables and functions */
 int AUDIO_FORMAT_16BIT ; 
 int AUDIO_FORMAT_16BIT_PLANAR ; 
 int AUDIO_FORMAT_32BIT ; 
 int AUDIO_FORMAT_32BIT_PLANAR ; 
 int AUDIO_FORMAT_FLOAT ; 
 int AUDIO_FORMAT_FLOAT_PLANAR ; 
 int AUDIO_FORMAT_U8BIT ; 
 int AUDIO_FORMAT_U8BIT_PLANAR ; 
 int AUDIO_FORMAT_UNKNOWN ; 
 scalar_t__ AVCOL_RANGE_JPEG ; 
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 scalar_t__ AV_CODEC_ID_H264 ; 
#define  AV_PIX_FMT_BGR0 143 
#define  AV_PIX_FMT_BGRA 142 
#define  AV_PIX_FMT_NONE 141 
#define  AV_PIX_FMT_NV12 140 
#define  AV_PIX_FMT_RGBA 139 
#define  AV_PIX_FMT_UYVY422 138 
#define  AV_PIX_FMT_YUV420P 137 
#define  AV_PIX_FMT_YUYV422 136 
 int /*<<< orphan*/  AV_PKT_FLAG_KEY ; 
#define  AV_SAMPLE_FMT_FLT 135 
#define  AV_SAMPLE_FMT_FLTP 134 
#define  AV_SAMPLE_FMT_S16 133 
#define  AV_SAMPLE_FMT_S16P 132 
#define  AV_SAMPLE_FMT_S32 131 
#define  AV_SAMPLE_FMT_S32P 130 
#define  AV_SAMPLE_FMT_U8 129 
#define  AV_SAMPLE_FMT_U8P 128 
 int CODEC_CAP_TRUNC ; 
 int /*<<< orphan*/  CODEC_FLAG_TRUNC ; 
 int /*<<< orphan*/  EAGAIN ; 
 size_t INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  LOG_ERROR ; 
 size_t MAX_AV_PLANES ; 
 int SPEAKERS_2POINT1 ; 
 int SPEAKERS_4POINT0 ; 
 int SPEAKERS_4POINT1 ; 
 int SPEAKERS_5POINT1 ; 
 int SPEAKERS_7POINT1 ; 
 int SPEAKERS_MONO ; 
 int SPEAKERS_STEREO ; 
 int SPEAKERS_UNKNOWN ; 
 int /*<<< orphan*/  VIDEO_CS_601 ; 
 int VIDEO_FORMAT_BGRA ; 
 int VIDEO_FORMAT_BGRX ; 
 int VIDEO_FORMAT_I420 ; 
 int VIDEO_FORMAT_NONE ; 
 int VIDEO_FORMAT_NV12 ; 
 int VIDEO_FORMAT_RGBA ; 
 int VIDEO_FORMAT_UYVY ; 
 int VIDEO_FORMAT_YUY2 ; 
 int /*<<< orphan*/  VIDEO_RANGE_DEFAULT ; 
 int /*<<< orphan*/  VIDEO_RANGE_FULL ; 
 void* av_frame_alloc () ; 
 int /*<<< orphan*/  av_free (TYPE_2__*) ; 
 int /*<<< orphan*/  av_init_packet (TYPE_1__*) ; 
 TYPE_2__* avcodec_alloc_context3 (TYPE_7__*) ; 
 int /*<<< orphan*/  avcodec_close (TYPE_2__*) ; 
 TYPE_7__* avcodec_find_decoder (int) ; 
 int avcodec_open2 (TYPE_2__*,TYPE_7__*,int /*<<< orphan*/ *) ; 
 int avcodec_receive_frame (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  avcodec_register_all () ; 
 int avcodec_send_packet (TYPE_2__*,TYPE_1__*) ; 
 int /*<<< orphan*/  bfree (scalar_t__) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ brealloc (scalar_t__,size_t) ; 
 void ffmpeg_decode_free (struct ffmpeg_decode*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int*,size_t) ; 
 int /*<<< orphan*/  memset (struct ffmpeg_decode*,int /*<<< orphan*/ ,size_t) ; 
 scalar_t__ obs_avc_keyframe (int*,size_t) ; 
 int video_format_get_parameters (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool ffmpeg_decode_valid(struct ffmpeg_decode *decode)
{
	return decode->decoder != NULL;
}

int ffmpeg_decode_init(struct ffmpeg_decode *decode, enum AVCodecID id)
{
	int ret;

	avcodec_register_all();
	memset(decode, 0, sizeof(*decode));

	decode->codec = avcodec_find_decoder(id);
	if (!decode->codec)
		return -1;

	decode->decoder = avcodec_alloc_context3(decode->codec);

	ret = avcodec_open2(decode->decoder, decode->codec, NULL);
	if (ret < 0) {
		ffmpeg_decode_free(decode);
		return ret;
	}

	if (decode->codec->capabilities & CODEC_CAP_TRUNC)
		decode->decoder->flags |= CODEC_FLAG_TRUNC;

	return 0;
}

void ffmpeg_decode_free(struct ffmpeg_decode *decode)
{
	if (decode->decoder) {
		avcodec_close(decode->decoder);
		av_free(decode->decoder);
	}

	if (decode->frame)
		av_free(decode->frame);

	if (decode->packet_buffer)
		bfree(decode->packet_buffer);

	memset(decode, 0, sizeof(*decode));
}

__attribute__((used)) static inline enum video_format convert_pixel_format(int f)
{
	switch (f) {
	case AV_PIX_FMT_NONE:    return VIDEO_FORMAT_NONE;
	case AV_PIX_FMT_YUV420P: return VIDEO_FORMAT_I420;
	case AV_PIX_FMT_NV12:    return VIDEO_FORMAT_NV12;
	case AV_PIX_FMT_YUYV422: return VIDEO_FORMAT_YUY2;
	case AV_PIX_FMT_UYVY422: return VIDEO_FORMAT_UYVY;
	case AV_PIX_FMT_RGBA:    return VIDEO_FORMAT_RGBA;
	case AV_PIX_FMT_BGRA:    return VIDEO_FORMAT_BGRA;
	case AV_PIX_FMT_BGR0:    return VIDEO_FORMAT_BGRX;
	default:;
	}

	return VIDEO_FORMAT_NONE;
}

__attribute__((used)) static inline enum audio_format convert_sample_format(int f)
{
	switch (f) {
	case AV_SAMPLE_FMT_U8:   return AUDIO_FORMAT_U8BIT;
	case AV_SAMPLE_FMT_S16:  return AUDIO_FORMAT_16BIT;
	case AV_SAMPLE_FMT_S32:  return AUDIO_FORMAT_32BIT;
	case AV_SAMPLE_FMT_FLT:  return AUDIO_FORMAT_FLOAT;
	case AV_SAMPLE_FMT_U8P:  return AUDIO_FORMAT_U8BIT_PLANAR;
	case AV_SAMPLE_FMT_S16P: return AUDIO_FORMAT_16BIT_PLANAR;
	case AV_SAMPLE_FMT_S32P: return AUDIO_FORMAT_32BIT_PLANAR;
	case AV_SAMPLE_FMT_FLTP: return AUDIO_FORMAT_FLOAT_PLANAR;
	default:;
	}

	return AUDIO_FORMAT_UNKNOWN;
}

__attribute__((used)) static inline enum speaker_layout convert_speaker_layout(uint8_t channels)
{
	switch (channels) {
	case 0:     return SPEAKERS_UNKNOWN;
	case 1:     return SPEAKERS_MONO;
	case 2:     return SPEAKERS_STEREO;
	case 3:     return SPEAKERS_2POINT1;
	case 4:     return SPEAKERS_4POINT0;
	case 5:     return SPEAKERS_4POINT1;
	case 6:     return SPEAKERS_5POINT1;
	case 8:     return SPEAKERS_7POINT1;
	default:    return SPEAKERS_UNKNOWN;
	}
}

__attribute__((used)) static inline void copy_data(struct ffmpeg_decode *decode, uint8_t *data,
		size_t size)
{
	size_t new_size = size + INPUT_BUFFER_PADDING_SIZE;

	if (decode->packet_size < new_size) {
		decode->packet_buffer = brealloc(decode->packet_buffer,
				new_size);
		decode->packet_size   = new_size;
	}

	memset(decode->packet_buffer + size, 0, INPUT_BUFFER_PADDING_SIZE);
	memcpy(decode->packet_buffer, data, size);
}

bool ffmpeg_decode_audio(struct ffmpeg_decode *decode,
		uint8_t *data, size_t size,
		struct obs_source_audio *audio,
		bool *got_output)
{
	AVPacket packet = {0};
	int got_frame = false;
	int ret = 0;

	*got_output = false;

	copy_data(decode, data, size);

	av_init_packet(&packet);
	packet.data = decode->packet_buffer;
	packet.size = (int)size;

	if (!decode->frame) {
		decode->frame = av_frame_alloc();
		if (!decode->frame)
			return false;
	}

	if (data && size)
		ret = avcodec_send_packet(decode->decoder, &packet);
	if (ret == 0)
		ret = avcodec_receive_frame(decode->decoder, decode->frame);

	got_frame = (ret == 0);

	if (ret == AVERROR_EOF || ret == AVERROR(EAGAIN))
		ret = 0;

	if (ret < 0)
		return false;
	else if (!got_frame)
		return true;

	for (size_t i = 0; i < MAX_AV_PLANES; i++)
		audio->data[i] = decode->frame->data[i];

	audio->samples_per_sec = decode->frame->sample_rate;
	audio->format          = convert_sample_format(decode->frame->format);
	audio->speakers        =
		convert_speaker_layout((uint8_t)decode->decoder->channels);

	audio->frames = decode->frame->nb_samples;

	if (audio->format == AUDIO_FORMAT_UNKNOWN)
		return false;

	*got_output = true;
	return true;
}

bool ffmpeg_decode_video(struct ffmpeg_decode *decode,
		uint8_t *data, size_t size, long long *ts,
		struct obs_source_frame2 *frame,
		bool *got_output)
{
	AVPacket packet = {0};
	int got_frame = false;
	enum video_format new_format;
	int ret;

	*got_output = false;

	copy_data(decode, data, size);

	av_init_packet(&packet);
	packet.data     = decode->packet_buffer;
	packet.size     = (int)size;
	packet.pts      = *ts;

	if (decode->codec->id == AV_CODEC_ID_H264 &&
			obs_avc_keyframe(data, size))
		packet.flags |= AV_PKT_FLAG_KEY;

	if (!decode->frame) {
		decode->frame = av_frame_alloc();
		if (!decode->frame)
			return false;
	}

	ret = avcodec_send_packet(decode->decoder, &packet);
	if (ret == 0)
		ret = avcodec_receive_frame(decode->decoder, decode->frame);

	got_frame = (ret == 0);

	if (ret == AVERROR_EOF || ret == AVERROR(EAGAIN))
		ret = 0;

	if (ret < 0)
		return false;
	else if (!got_frame)
		return true;

	for (size_t i = 0; i < MAX_AV_PLANES; i++) {
		frame->data[i]     = decode->frame->data[i];
		frame->linesize[i] = decode->frame->linesize[i];
	}

	new_format = convert_pixel_format(decode->frame->format);
	if (new_format != frame->format) {
		bool success;

		frame->format = new_format;
		frame->range = decode->frame->color_range == AVCOL_RANGE_JPEG
			? VIDEO_RANGE_FULL
			: VIDEO_RANGE_DEFAULT;

		success = video_format_get_parameters(VIDEO_CS_601,
				frame->range, frame->color_matrix,
				frame->color_range_min, frame->color_range_max);
		if (!success) {
			blog(LOG_ERROR, "Failed to get video format "
			                "parameters for video format %u",
			                VIDEO_CS_601);
			return false;
		}
	}

	*ts = decode->frame->pkt_pts;

	frame->width  = decode->frame->width;
	frame->height = decode->frame->height;
	frame->flip   = false;

	if (frame->format == VIDEO_FORMAT_NONE)
		return false;

	*got_output = true;
	return true;
}

