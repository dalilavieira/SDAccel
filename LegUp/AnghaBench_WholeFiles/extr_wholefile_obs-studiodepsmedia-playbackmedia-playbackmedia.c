#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_53__   TYPE_7__ ;
typedef  struct TYPE_52__   TYPE_6__ ;
typedef  struct TYPE_51__   TYPE_5__ ;
typedef  struct TYPE_50__   TYPE_4__ ;
typedef  struct TYPE_49__   TYPE_3__ ;
typedef  struct TYPE_48__   TYPE_35__ ;
typedef  struct TYPE_47__   TYPE_2__ ;
typedef  struct TYPE_46__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ uint64_t ;
struct obs_source_frame {int* data; int* linesize; int format; int full_range; int height; int flip; int /*<<< orphan*/  width; void* timestamp; int /*<<< orphan*/  color_range_max; int /*<<< orphan*/  color_range_min; int /*<<< orphan*/  color_matrix; } ;
struct obs_source_audio {int* data; int samples_per_sec; int speakers; int format; void* timestamp; int /*<<< orphan*/  frames; int /*<<< orphan*/  member_0; } ;
struct mp_media_info {int force_range; int speed; scalar_t__ is_local_file; int /*<<< orphan*/  buffering; int /*<<< orphan*/  (* v_preload_cb ) (int /*<<< orphan*/ ,struct obs_source_frame*) ;int /*<<< orphan*/  (* stop_cb ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* a_cb ) (int /*<<< orphan*/ ,struct obs_source_audio*) ;int /*<<< orphan*/  (* v_cb ) (int /*<<< orphan*/ ,struct obs_source_frame*) ;int /*<<< orphan*/  opaque; int /*<<< orphan*/  hardware_decoding; scalar_t__ format; scalar_t__ path; } ;
struct mp_decode {int frame_ready; scalar_t__ frame_pts; scalar_t__ next_pts; int got_first_keyframe; TYPE_7__* frame; TYPE_2__* decoder; int /*<<< orphan*/  eof; TYPE_1__* stream; } ;
struct TYPE_50__ {int scale_format; int* scale_pic; scalar_t__* scale_linesizes; int eof; scalar_t__ next_pts_ns; int speed; void* base_ts; void* start_ts; void* play_sys_ts; int force_range; int cur_space; int cur_range; scalar_t__ next_ns; int stopping; int active; int looping; scalar_t__ interrupt_poll_ts; int kill; int reset; int thread_valid; int /*<<< orphan*/  mutex; int /*<<< orphan*/  sem; scalar_t__* format_name; scalar_t__* path; scalar_t__ swscale; TYPE_35__* fmt; struct mp_decode a; struct mp_decode v; int /*<<< orphan*/  thread; scalar_t__ is_local_file; int /*<<< orphan*/  buffering; int /*<<< orphan*/  (* v_preload_cb ) (int /*<<< orphan*/ ,struct obs_source_frame*) ;int /*<<< orphan*/  (* stop_cb ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* a_cb ) (int /*<<< orphan*/ ,struct obs_source_audio*) ;int /*<<< orphan*/  (* v_cb ) (int /*<<< orphan*/ ,struct obs_source_frame*) ;int /*<<< orphan*/  opaque; int /*<<< orphan*/  hw; void* has_audio; void* has_video; struct obs_source_frame obsframe; } ;
typedef  TYPE_4__ mp_media_t ;
typedef  scalar_t__ int64_t ;
typedef  enum video_range_type { ____Placeholder_video_range_type } video_range_type ;
typedef  enum video_format { ____Placeholder_video_format } video_format ;
typedef  enum video_colorspace { ____Placeholder_video_colorspace } video_colorspace ;
typedef  enum speaker_layout { ____Placeholder_speaker_layout } speaker_layout ;
typedef  enum audio_format { ____Placeholder_audio_format } audio_format ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
typedef  enum AVColorSpace { ____Placeholder_AVColorSpace } AVColorSpace ;
typedef  enum AVColorRange { ____Placeholder_AVColorRange } AVColorRange ;
struct TYPE_53__ {int format; int* data; int sample_rate; int channels; scalar_t__* linesize; int height; int colorspace; int color_range; int /*<<< orphan*/  key_frame; int /*<<< orphan*/  width; int /*<<< orphan*/  nb_samples; } ;
struct TYPE_52__ {scalar_t__ stream_index; scalar_t__ size; } ;
struct TYPE_51__ {int /*<<< orphan*/  time_base; } ;
struct TYPE_49__ {int (* callback ) (void*) ;TYPE_4__* opaque; } ;
struct TYPE_48__ {scalar_t__ duration; scalar_t__ start_time; TYPE_3__ interrupt_callback; TYPE_5__** streams; } ;
struct TYPE_47__ {int colorspace; int color_range; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  pix_fmt; } ;
struct TYPE_46__ {scalar_t__ index; } ;
typedef  TYPE_5__ AVStream ;
typedef  TYPE_6__ AVPacket ;
typedef  int /*<<< orphan*/  AVInputFormat ;
typedef  TYPE_7__ AVFrame ;
typedef  int /*<<< orphan*/  AVDictionary ;

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
 int AVCOL_RANGE_JPEG ; 
#define  AVCOL_SPC_BT709 176 
#define  AVCOL_SPC_FCC 175 
#define  AVCOL_SPC_SMPTE170M 174 
#define  AVCOL_SPC_SMPTE240M 173 
 int AVERROR_EOF ; 
 int /*<<< orphan*/  AVMEDIA_TYPE_AUDIO ; 
 int /*<<< orphan*/  AVMEDIA_TYPE_VIDEO ; 
 int AVSEEK_FLAG_BACKWARD ; 
 int AVSEEK_FLAG_FRAME ; 
 scalar_t__ AV_NOPTS_VALUE ; 
#define  AV_PIX_FMT_BGR0 172 
#define  AV_PIX_FMT_BGRA 171 
#define  AV_PIX_FMT_NONE 170 
#define  AV_PIX_FMT_NV12 169 
#define  AV_PIX_FMT_NV21 168 
#define  AV_PIX_FMT_RGBA 167 
#define  AV_PIX_FMT_UYVY422 166 
#define  AV_PIX_FMT_UYYVYY411 165 
#define  AV_PIX_FMT_YUV410P 164 
#define  AV_PIX_FMT_YUV411P 163 
#define  AV_PIX_FMT_YUV420P 162 
#define  AV_PIX_FMT_YUV420P10BE 161 
#define  AV_PIX_FMT_YUV420P10LE 160 
#define  AV_PIX_FMT_YUV420P12BE 159 
#define  AV_PIX_FMT_YUV420P12LE 158 
#define  AV_PIX_FMT_YUV420P14BE 157 
#define  AV_PIX_FMT_YUV420P14LE 156 
#define  AV_PIX_FMT_YUV420P16BE 155 
#define  AV_PIX_FMT_YUV420P16LE 154 
#define  AV_PIX_FMT_YUV420P9BE 153 
#define  AV_PIX_FMT_YUV420P9LE 152 
#define  AV_PIX_FMT_YUV422P 151 
#define  AV_PIX_FMT_YUV422P10BE 150 
#define  AV_PIX_FMT_YUV422P10LE 149 
#define  AV_PIX_FMT_YUV422P12BE 148 
#define  AV_PIX_FMT_YUV422P12LE 147 
#define  AV_PIX_FMT_YUV422P14BE 146 
#define  AV_PIX_FMT_YUV422P14LE 145 
#define  AV_PIX_FMT_YUV422P16BE 144 
#define  AV_PIX_FMT_YUV422P16LE 143 
#define  AV_PIX_FMT_YUV422P9BE 142 
#define  AV_PIX_FMT_YUV422P9LE 141 
#define  AV_PIX_FMT_YUV444P 140 
#define  AV_PIX_FMT_YUVJ420P 139 
#define  AV_PIX_FMT_YUVJ422P 138 
#define  AV_PIX_FMT_YUYV422 137 
#define  AV_PIX_FMT_YVYU422 136 
#define  AV_SAMPLE_FMT_FLT 135 
#define  AV_SAMPLE_FMT_FLTP 134 
#define  AV_SAMPLE_FMT_S16 133 
#define  AV_SAMPLE_FMT_S16P 132 
#define  AV_SAMPLE_FMT_S32 131 
#define  AV_SAMPLE_FMT_S32P 130 
#define  AV_SAMPLE_FMT_U8 129 
#define  AV_SAMPLE_FMT_U8P 128 
 int /*<<< orphan*/  AV_TIME_BASE_Q ; 
 int /*<<< orphan*/  FIXED_1_0 ; 
 int /*<<< orphan*/  LOG_INFO ; 
 int /*<<< orphan*/  LOG_WARNING ; 
 size_t MAX_AV_PLANES ; 
 int SPEAKERS_2POINT1 ; 
 int SPEAKERS_4POINT0 ; 
 int SPEAKERS_4POINT1 ; 
 int SPEAKERS_5POINT1 ; 
 int SPEAKERS_7POINT1 ; 
 int SPEAKERS_MONO ; 
 int SPEAKERS_STEREO ; 
 int SPEAKERS_UNKNOWN ; 
 int SWS_CS_FCC ; 
 int SWS_CS_ITU601 ; 
 int SWS_CS_ITU709 ; 
 int SWS_CS_SMPTE170M ; 
 int SWS_CS_SMPTE240M ; 
 int /*<<< orphan*/  SWS_FAST_BILINEAR ; 
 int VIDEO_CS_709 ; 
 int VIDEO_CS_DEFAULT ; 
 int VIDEO_FORMAT_BGRA ; 
 int VIDEO_FORMAT_BGRX ; 
 int VIDEO_FORMAT_I420 ; 
 int VIDEO_FORMAT_I444 ; 
 int VIDEO_FORMAT_NONE ; 
 int VIDEO_FORMAT_NV12 ; 
 int VIDEO_FORMAT_RGBA ; 
 int VIDEO_FORMAT_UYVY ; 
 int VIDEO_FORMAT_YUY2 ; 
 int VIDEO_RANGE_DEFAULT ; 
 int VIDEO_RANGE_FULL ; 
 void* abs (scalar_t__) ; 
 int /*<<< orphan*/  av_dict_free (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  av_dict_set_int (int /*<<< orphan*/ **,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_err2str (int) ; 
 int /*<<< orphan*/ * av_find_input_format (scalar_t__*) ; 
 int /*<<< orphan*/  av_freep (int*) ; 
 int av_image_alloc (int*,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  av_init_packet (TYPE_6__*) ; 
 int /*<<< orphan*/  av_packet_ref (TYPE_6__*,TYPE_6__*) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_6__*) ; 
 int av_read_frame (TYPE_35__*,TYPE_6__*) ; 
 int /*<<< orphan*/  av_register_all () ; 
 scalar_t__ av_rescale_q (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int av_seek_frame (TYPE_35__*,int /*<<< orphan*/ ,scalar_t__,int) ; 
 int /*<<< orphan*/  avcodec_register_all () ; 
 int /*<<< orphan*/  avdevice_register_all () ; 
 TYPE_35__* avformat_alloc_context () ; 
 int /*<<< orphan*/  avformat_close_input (TYPE_35__**) ; 
 scalar_t__ avformat_find_stream_info (TYPE_35__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avformat_network_init () ; 
 int avformat_open_input (TYPE_35__**,scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 
 void* base_sys_ts ; 
 int /*<<< orphan*/  bfree (scalar_t__*) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__* bstrdup (scalar_t__) ; 
 int /*<<< orphan*/  memset (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mp_decode_flush (struct mp_decode*) ; 
 int /*<<< orphan*/  mp_decode_free (struct mp_decode*) ; 
 void* mp_decode_init (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ mp_decode_next (struct mp_decode*) ; 
 int /*<<< orphan*/  mp_decode_push_packet (struct mp_decode*,TYPE_6__*) ; 
 void mp_media_free (TYPE_4__*) ; 
 void mp_media_stop (TYPE_4__*) ; 
 scalar_t__ os_gettime_ns () ; 
 int /*<<< orphan*/  os_sem_destroy (int /*<<< orphan*/ ) ; 
 scalar_t__ os_sem_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_sem_post (int /*<<< orphan*/ ) ; 
 scalar_t__ os_sem_wait (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_set_thread_name (char*) ; 
 int /*<<< orphan*/  os_sleepto_ns (scalar_t__) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),TYPE_4__*) ; 
 int /*<<< orphan*/  pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_init_value (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,struct obs_source_audio*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,struct obs_source_frame*) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,struct obs_source_frame*) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sws_freeContext (scalar_t__) ; 
 scalar_t__ sws_getCachedContext (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int* sws_getCoefficients (int) ; 
 int sws_scale (scalar_t__,int const* const*,scalar_t__*,int /*<<< orphan*/ ,int,int*,scalar_t__*) ; 
 int /*<<< orphan*/  sws_setColorspaceDetails (scalar_t__,int const*,int,int const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int video_format_get_parameters (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static enum AVPixelFormat closest_format(enum AVPixelFormat fmt)
{
	switch (fmt) {
	case AV_PIX_FMT_YUYV422:
		return AV_PIX_FMT_YUYV422;
	case AV_PIX_FMT_YUV444P:
		return AV_PIX_FMT_YUV444P;

	case AV_PIX_FMT_YUV422P:
	case AV_PIX_FMT_YUVJ422P:
	case AV_PIX_FMT_UYVY422:
	case AV_PIX_FMT_YUV422P16LE:
	case AV_PIX_FMT_YUV422P16BE:
	case AV_PIX_FMT_YUV422P10BE:
	case AV_PIX_FMT_YUV422P10LE:
	case AV_PIX_FMT_YUV422P9BE:
	case AV_PIX_FMT_YUV422P9LE:
	case AV_PIX_FMT_YVYU422:
	case AV_PIX_FMT_YUV422P12BE:
	case AV_PIX_FMT_YUV422P12LE:
	case AV_PIX_FMT_YUV422P14BE:
	case AV_PIX_FMT_YUV422P14LE:
		return AV_PIX_FMT_UYVY422;

	case AV_PIX_FMT_NV12:
	case AV_PIX_FMT_NV21:
		return AV_PIX_FMT_NV12;

	case AV_PIX_FMT_YUV420P:
	case AV_PIX_FMT_YUVJ420P:
	case AV_PIX_FMT_YUV411P:
	case AV_PIX_FMT_UYYVYY411:
	case AV_PIX_FMT_YUV410P:
	case AV_PIX_FMT_YUV420P16LE:
	case AV_PIX_FMT_YUV420P16BE:
	case AV_PIX_FMT_YUV420P9BE:
	case AV_PIX_FMT_YUV420P9LE:
	case AV_PIX_FMT_YUV420P10BE:
	case AV_PIX_FMT_YUV420P10LE:
	case AV_PIX_FMT_YUV420P12BE:
	case AV_PIX_FMT_YUV420P12LE:
	case AV_PIX_FMT_YUV420P14BE:
	case AV_PIX_FMT_YUV420P14LE:
		return AV_PIX_FMT_YUV420P;

	case AV_PIX_FMT_RGBA:
	case AV_PIX_FMT_BGRA:
	case AV_PIX_FMT_BGR0:
		return fmt;

	default:
		break;
	}

	return AV_PIX_FMT_BGRA;
}

__attribute__((used)) static inline enum video_format convert_pixel_format(int f)
{
	switch (f) {
	case AV_PIX_FMT_NONE:    return VIDEO_FORMAT_NONE;
	case AV_PIX_FMT_YUV420P: return VIDEO_FORMAT_I420;
	case AV_PIX_FMT_NV12:    return VIDEO_FORMAT_NV12;
	case AV_PIX_FMT_YUYV422: return VIDEO_FORMAT_YUY2;
	case AV_PIX_FMT_YUV444P: return VIDEO_FORMAT_I444;
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

__attribute__((used)) static inline enum video_colorspace convert_color_space(enum AVColorSpace s)
{
	return s == AVCOL_SPC_BT709 ? VIDEO_CS_709 : VIDEO_CS_DEFAULT;
}

__attribute__((used)) static inline enum video_range_type convert_color_range(enum AVColorRange r)
{
	return r == AVCOL_RANGE_JPEG ? VIDEO_RANGE_FULL : VIDEO_RANGE_DEFAULT;
}

__attribute__((used)) static inline struct mp_decode *get_packet_decoder(mp_media_t *media,
		AVPacket *pkt)
{
	if (media->has_audio && pkt->stream_index == media->a.stream->index)
		return &media->a;
	if (media->has_video && pkt->stream_index == media->v.stream->index)
		return &media->v;

	return NULL;
}

__attribute__((used)) static int mp_media_next_packet(mp_media_t *media)
{
	AVPacket new_pkt;
	AVPacket pkt;
	av_init_packet(&pkt);
	new_pkt = pkt;

	int ret = av_read_frame(media->fmt, &pkt);
	if (ret < 0) {
		if (ret != AVERROR_EOF)
			blog(LOG_WARNING, "MP: av_read_frame failed: %s (%d)",
					av_err2str(ret), ret);
		return ret;
	}

	struct mp_decode *d = get_packet_decoder(media, &pkt);
	if (d && pkt.size) {
		av_packet_ref(&new_pkt, &pkt);
		mp_decode_push_packet(d, &new_pkt);
	}

	av_packet_unref(&pkt);
	return ret;
}

__attribute__((used)) static inline bool mp_media_ready_to_start(mp_media_t *m)
{
	if (m->has_audio && !m->a.eof && !m->a.frame_ready)
		return false;
	if (m->has_video && !m->v.eof && !m->v.frame_ready)
		return false;
	return true;
}

__attribute__((used)) static inline bool mp_decode_frame(struct mp_decode *d)
{
	return d->frame_ready || mp_decode_next(d);
}

__attribute__((used)) static inline int get_sws_colorspace(enum AVColorSpace cs)
{
	switch (cs) {
	case AVCOL_SPC_BT709:
		return SWS_CS_ITU709;
	case AVCOL_SPC_FCC:
		return SWS_CS_FCC;
	case AVCOL_SPC_SMPTE170M:
		return SWS_CS_SMPTE170M;
	case AVCOL_SPC_SMPTE240M:
		return SWS_CS_SMPTE240M;
	default:
		break;
	}

	return SWS_CS_ITU601;
}

__attribute__((used)) static inline int get_sws_range(enum AVColorRange r)
{
	return r == AVCOL_RANGE_JPEG ? 1 : 0;
}

__attribute__((used)) static bool mp_media_init_scaling(mp_media_t *m)
{
	int space = get_sws_colorspace(m->v.decoder->colorspace);
	int range = get_sws_range(m->v.decoder->color_range);
	const int *coeff = sws_getCoefficients(space);

	m->swscale = sws_getCachedContext(NULL,
			m->v.decoder->width, m->v.decoder->height,
			m->v.decoder->pix_fmt,
			m->v.decoder->width, m->v.decoder->height,
			m->scale_format,
			SWS_FAST_BILINEAR, NULL, NULL, NULL);
	if (!m->swscale) {
		blog(LOG_WARNING, "MP: Failed to initialize scaler");
		return false;
	}

	sws_setColorspaceDetails(m->swscale, coeff, range, coeff, range, 0,
			FIXED_1_0, FIXED_1_0);

	int ret = av_image_alloc(m->scale_pic, m->scale_linesizes,
			m->v.decoder->width, m->v.decoder->height,
			m->scale_format, 1);
	if (ret < 0) {
		blog(LOG_WARNING, "MP: Failed to create scale pic data");
		return false;
	}

	return true;
}

__attribute__((used)) static bool mp_media_prepare_frames(mp_media_t *m)
{
	while (!mp_media_ready_to_start(m)) {
		if (!m->eof) {
			int ret = mp_media_next_packet(m);
			if (ret == AVERROR_EOF)
				m->eof = true;
			else if (ret < 0)
				return false;
		}

		if (m->has_video && !mp_decode_frame(&m->v))
			return false;
		if (m->has_audio && !mp_decode_frame(&m->a))
			return false;
	}

	if (m->has_video && m->v.frame_ready && !m->swscale) {
		m->scale_format = closest_format(m->v.frame->format);
		if (m->scale_format != m->v.frame->format) {
			if (!mp_media_init_scaling(m)) {
				return false;
			}
		}
	}

	return true;
}

__attribute__((used)) static inline int64_t mp_media_get_next_min_pts(mp_media_t *m)
{
	int64_t min_next_ns = 0x7FFFFFFFFFFFFFFFLL;

	if (m->has_video && m->v.frame_ready) {
		if (m->v.frame_pts < min_next_ns)
			min_next_ns = m->v.frame_pts;
	}
	if (m->has_audio && m->a.frame_ready) {
		if (m->a.frame_pts < min_next_ns)
			min_next_ns = m->a.frame_pts;
	}

	return min_next_ns;
}

__attribute__((used)) static inline int64_t mp_media_get_base_pts(mp_media_t *m)
{
	int64_t base_ts = 0;

	if (m->has_video && m->v.next_pts > base_ts)
		base_ts = m->v.next_pts;
	if (m->has_audio && m->a.next_pts > base_ts)
		base_ts = m->a.next_pts;

	return base_ts;
}

__attribute__((used)) static inline bool mp_media_can_play_frame(mp_media_t *m,
		struct mp_decode *d)
{
	return d->frame_ready && d->frame_pts <= m->next_pts_ns;
}

__attribute__((used)) static void mp_media_next_audio(mp_media_t *m)
{
	struct mp_decode *d = &m->a;
	struct obs_source_audio audio = {0};
	AVFrame *f = d->frame;

	if (!mp_media_can_play_frame(m, d))
		return;

	d->frame_ready = false;
	if (!m->a_cb)
		return;

	for (size_t i = 0; i < MAX_AV_PLANES; i++)
		audio.data[i] = f->data[i];

	audio.samples_per_sec = f->sample_rate * m->speed / 100;
	audio.speakers = convert_speaker_layout(f->channels);
	audio.format = convert_sample_format(f->format);
	audio.frames = f->nb_samples;
	audio.timestamp = m->base_ts + d->frame_pts - m->start_ts +
		m->play_sys_ts - base_sys_ts;

	if (audio.format == AUDIO_FORMAT_UNKNOWN)
		return;

	m->a_cb(m->opaque, &audio);
}

__attribute__((used)) static void mp_media_next_video(mp_media_t *m, bool preload)
{
	struct mp_decode *d = &m->v;
	struct obs_source_frame *frame = &m->obsframe;
	enum video_format new_format;
	enum video_colorspace new_space;
	enum video_range_type new_range;
	AVFrame *f = d->frame;

	if (!preload) {
		if (!mp_media_can_play_frame(m, d))
			return;

		d->frame_ready = false;

		if (!m->v_cb)
			return;
	} else if (!d->frame_ready) {
		return;
	}

	bool flip = false;
	if (m->swscale) {
		int ret = sws_scale(m->swscale,
				(const uint8_t *const *)f->data, f->linesize,
				0, f->height,
				m->scale_pic, m->scale_linesizes);
		if (ret < 0)
			return;

		flip = m->scale_linesizes[0] < 0 && m->scale_linesizes[1] == 0;
		for (size_t i = 0; i < 4; i++) {
			frame->data[i] = m->scale_pic[i];
			frame->linesize[i] = abs(m->scale_linesizes[i]);
		}

	} else {
		flip = f->linesize[0] < 0 && f->linesize[1] == 0;

		for (size_t i = 0; i < MAX_AV_PLANES; i++) {
			frame->data[i] = f->data[i];
			frame->linesize[i] = abs(f->linesize[i]);
		}
	}

	if (flip)
		frame->data[0] -= frame->linesize[0] * (f->height - 1);

	new_format = convert_pixel_format(m->scale_format);
	new_space  = convert_color_space(f->colorspace);
	new_range  = m->force_range == VIDEO_RANGE_DEFAULT
		? convert_color_range(f->color_range)
		: m->force_range;

	if (new_format != frame->format ||
	    new_space  != m->cur_space  ||
	    new_range  != m->cur_range) {
		bool success;

		frame->format = new_format;
		frame->full_range = new_range == VIDEO_RANGE_FULL;

		success = video_format_get_parameters(
				new_space,
				new_range,
				frame->color_matrix,
				frame->color_range_min,
				frame->color_range_max);

		frame->format = new_format;
		m->cur_space = new_space;
		m->cur_range = new_range;

		if (!success) {
			frame->format = VIDEO_FORMAT_NONE;
			return;
		}
	}

	if (frame->format == VIDEO_FORMAT_NONE)
		return;

	frame->timestamp = m->base_ts + d->frame_pts - m->start_ts +
		m->play_sys_ts - base_sys_ts;
	frame->width = f->width;
	frame->height = f->height;
	frame->flip = flip;

	if (!m->is_local_file && !d->got_first_keyframe) {
		if (!f->key_frame)
			return;

		d->got_first_keyframe = true;
	}

	if (preload)
		m->v_preload_cb(m->opaque, frame);
	else
		m->v_cb(m->opaque, frame);
}

__attribute__((used)) static void mp_media_calc_next_ns(mp_media_t *m)
{
	int64_t min_next_ns = mp_media_get_next_min_pts(m);

	int64_t delta = min_next_ns - m->next_pts_ns;
#ifdef _DEBUG
	assert(delta >= 0);
#endif
	if (delta < 0)
		delta = 0;
	if (delta > 3000000000)
		delta = 0;

	m->next_ns += delta;
	m->next_pts_ns = min_next_ns;
}

__attribute__((used)) static bool mp_media_reset(mp_media_t *m)
{
	AVStream *stream = m->fmt->streams[0];
	int64_t seek_pos;
	int seek_flags;
	bool stopping;
	bool active;

	if (m->fmt->duration == AV_NOPTS_VALUE) {
		seek_pos = 0;
		seek_flags = AVSEEK_FLAG_FRAME;
	} else {
		seek_pos = m->fmt->start_time;
		seek_flags = AVSEEK_FLAG_BACKWARD;
	}

	int64_t seek_target = seek_flags == AVSEEK_FLAG_BACKWARD
		? av_rescale_q(seek_pos, AV_TIME_BASE_Q, stream->time_base)
		: seek_pos;

	if (m->is_local_file) {
		int ret = av_seek_frame(m->fmt, 0, seek_target, seek_flags);
		if (ret < 0) {
			blog(LOG_WARNING, "MP: Failed to seek: %s",
					av_err2str(ret));
		}
	}

	if (m->has_video && m->is_local_file)
		mp_decode_flush(&m->v);
	if (m->has_audio && m->is_local_file)
		mp_decode_flush(&m->a);

	int64_t next_ts = mp_media_get_base_pts(m);
	int64_t offset = next_ts - m->next_pts_ns;

	m->eof = false;
	m->base_ts += next_ts;

	pthread_mutex_lock(&m->mutex);
	stopping = m->stopping;
	active = m->active;
	m->stopping = false;
	pthread_mutex_unlock(&m->mutex);

	if (!mp_media_prepare_frames(m))
		return false;

	if (active) {
		if (!m->play_sys_ts)
			m->play_sys_ts = (int64_t)os_gettime_ns();
		m->start_ts = m->next_pts_ns = mp_media_get_next_min_pts(m);
		if (m->next_ns)
			m->next_ns += offset;
	} else {
		m->start_ts = m->next_pts_ns = mp_media_get_next_min_pts(m);
		m->play_sys_ts = (int64_t)os_gettime_ns();
		m->next_ns = 0;
	}

	if (!active && m->is_local_file && m->v_preload_cb)
		mp_media_next_video(m, true);
	if (stopping && m->stop_cb)
		m->stop_cb(m->opaque);
	return true;
}

__attribute__((used)) static inline bool mp_media_sleepto(mp_media_t *m)
{
	bool timeout = false;

	if (!m->next_ns) {
		m->next_ns = os_gettime_ns();
	} else {
		uint64_t t = os_gettime_ns();
		const uint64_t timeout_ns = 200000000;

		if (m->next_ns > t && (m->next_ns - t) > timeout_ns) {
			os_sleepto_ns(t + timeout_ns);
			timeout = true;
		} else {
			os_sleepto_ns(m->next_ns);
		}
	}

	return timeout;
}

__attribute__((used)) static inline bool mp_media_eof(mp_media_t *m)
{
	bool v_ended = !m->has_video || !m->v.frame_ready;
	bool a_ended = !m->has_audio || !m->a.frame_ready;
	bool eof = v_ended && a_ended;

	if (eof) {
		bool looping;

		pthread_mutex_lock(&m->mutex);
		looping = m->looping;
		if (!looping) {
			m->active = false;
			m->stopping = true;
		}
		pthread_mutex_unlock(&m->mutex);

		mp_media_reset(m);
	}

	return eof;
}

__attribute__((used)) static int interrupt_callback(void *data)
{
	mp_media_t *m = data;
	bool stop = false;
	uint64_t ts = os_gettime_ns();

	if ((ts - m->interrupt_poll_ts) > 20000000) {
		pthread_mutex_lock(&m->mutex);
		stop = m->kill || m->stopping;
		pthread_mutex_unlock(&m->mutex);

		m->interrupt_poll_ts = ts;
	}

	return stop;
}

__attribute__((used)) static bool init_avformat(mp_media_t *m)
{
	AVInputFormat *format = NULL;

	if (m->format_name && *m->format_name) {
		format = av_find_input_format(m->format_name);
		if (!format)
			blog(LOG_INFO, "MP: Unable to find input format for "
					"'%s'", m->path);
	}

	AVDictionary *opts = NULL;
	if (m->buffering && !m->is_local_file)
		av_dict_set_int(&opts, "buffer_size", m->buffering, 0);

	m->fmt = avformat_alloc_context();
	m->fmt->interrupt_callback.callback = interrupt_callback;
	m->fmt->interrupt_callback.opaque = m;

	int ret = avformat_open_input(&m->fmt, m->path, format,
			opts ? &opts : NULL);
	av_dict_free(&opts);

	if (ret < 0) {
		blog(LOG_WARNING, "MP: Failed to open media: '%s'", m->path);
		return false;
	}

	if (avformat_find_stream_info(m->fmt, NULL) < 0) {
		blog(LOG_WARNING, "MP: Failed to find stream info for '%s'",
				m->path);
		return false;
	}

	m->has_video = mp_decode_init(m, AVMEDIA_TYPE_VIDEO, m->hw);
	m->has_audio = mp_decode_init(m, AVMEDIA_TYPE_AUDIO, m->hw);

	if (!m->has_video && !m->has_audio) {
		blog(LOG_WARNING, "MP: Could not initialize audio or video: "
				"'%s'", m->path);
		return false;
	}

	return true;
}

__attribute__((used)) static inline bool mp_media_thread(mp_media_t *m)
{
	os_set_thread_name("mp_media_thread");

	if (!init_avformat(m)) {
		return false;
	}
	if (!mp_media_reset(m)) {
		return false;
	}

	for (;;) {
		bool reset, kill, is_active;
		bool timeout = false;

		pthread_mutex_lock(&m->mutex);
		is_active = m->active;
		pthread_mutex_unlock(&m->mutex);

		if (!is_active) {
			if (os_sem_wait(m->sem) < 0)
				return false;
		} else {
			timeout = mp_media_sleepto(m);
		}

		pthread_mutex_lock(&m->mutex);

		reset = m->reset;
		kill = m->kill;
		m->reset = false;
		m->kill = false;

		pthread_mutex_unlock(&m->mutex);

		if (kill) {
			break;
		}
		if (reset) {
			mp_media_reset(m);
			continue;
		}

		/* frames are ready */
		if (is_active && !timeout) {
			if (m->has_video)
				mp_media_next_video(m, false);
			if (m->has_audio)
				mp_media_next_audio(m);

			if (!mp_media_prepare_frames(m))
				return false;
			if (mp_media_eof(m))
				continue;

			mp_media_calc_next_ns(m);
		}
	}

	return true;
}

__attribute__((used)) static void *mp_media_thread_start(void *opaque)
{
	mp_media_t *m = opaque;

	if (!mp_media_thread(m)) {
		if (m->stop_cb) {
			m->stop_cb(m->opaque);
		}
	}

	return NULL;
}

__attribute__((used)) static inline bool mp_media_init_internal(mp_media_t *m,
		const struct mp_media_info *info)
{
	if (pthread_mutex_init(&m->mutex, NULL) != 0) {
		blog(LOG_WARNING, "MP: Failed to init mutex");
		return false;
	}
	if (os_sem_init(&m->sem, 0) != 0) {
		blog(LOG_WARNING, "MP: Failed to init semaphore");
		return false;
	}

	m->path = info->path ? bstrdup(info->path) : NULL;
	m->format_name = info->format ? bstrdup(info->format) : NULL;
	m->hw = info->hardware_decoding;

	if (pthread_create(&m->thread, NULL, mp_media_thread_start, m) != 0) {
		blog(LOG_WARNING, "MP: Could not create media thread");
		return false;
	}

	m->thread_valid = true;
	return true;
}

bool mp_media_init(mp_media_t *media, const struct mp_media_info *info)
{
	memset(media, 0, sizeof(*media));
	pthread_mutex_init_value(&media->mutex);
	media->opaque = info->opaque;
	media->v_cb = info->v_cb;
	media->a_cb = info->a_cb;
	media->stop_cb = info->stop_cb;
	media->v_preload_cb = info->v_preload_cb;
	media->force_range = info->force_range;
	media->buffering = info->buffering;
	media->speed = info->speed;
	media->is_local_file = info->is_local_file;

	if (!info->is_local_file || media->speed < 1 || media->speed > 200)
		media->speed = 100;

	static bool initialized = false;
	if (!initialized) {
		av_register_all();
		avdevice_register_all();
		avcodec_register_all();
		avformat_network_init();
		initialized = true;
	}

	if (!base_sys_ts)
		base_sys_ts = (int64_t)os_gettime_ns();

	if (!mp_media_init_internal(media, info)) {
		mp_media_free(media);
		return false;
	}

	return true;
}

__attribute__((used)) static void mp_kill_thread(mp_media_t *m)
{
	if (m->thread_valid) {
		pthread_mutex_lock(&m->mutex);
		m->kill = true;
		pthread_mutex_unlock(&m->mutex);
		os_sem_post(m->sem);

		pthread_join(m->thread, NULL);
	}
}

void mp_media_free(mp_media_t *media)
{
	if (!media)
		return;

	mp_media_stop(media);
	mp_kill_thread(media);
	mp_decode_free(&media->v);
	mp_decode_free(&media->a);
	avformat_close_input(&media->fmt);
	pthread_mutex_destroy(&media->mutex);
	os_sem_destroy(media->sem);
	sws_freeContext(media->swscale);
	av_freep(&media->scale_pic[0]);
	bfree(media->path);
	bfree(media->format_name);
	memset(media, 0, sizeof(*media));
	pthread_mutex_init_value(&media->mutex);
}

void mp_media_play(mp_media_t *m, bool loop)
{
	pthread_mutex_lock(&m->mutex);

	if (m->active)
		m->reset = true;

	m->looping = loop;
	m->active = true;

	pthread_mutex_unlock(&m->mutex);

	os_sem_post(m->sem);
}

void mp_media_stop(mp_media_t *m)
{
	pthread_mutex_lock(&m->mutex);
	if (m->active) {
		m->reset = true;
		m->active = false;
		m->stopping = true;
		os_sem_post(m->sem);
	}
	pthread_mutex_unlock(&m->mutex);
}

