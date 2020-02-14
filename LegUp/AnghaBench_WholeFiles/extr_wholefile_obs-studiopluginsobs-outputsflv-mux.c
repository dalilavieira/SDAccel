#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  video_t ;
typedef  char uint8_t ;
typedef  int uint32_t ;
struct serializer {int dummy; } ;
struct encoder_packet {int timebase_den; int pts; int dts; char* data; size_t size; scalar_t__ type; scalar_t__ keyframe; } ;
struct dstr {char* array; int /*<<< orphan*/  member_0; } ;
struct TYPE_10__ {char* array; size_t num; } ;
struct array_output_data {TYPE_1__ bytes; } ;
typedef  int /*<<< orphan*/  obs_output_t ;
typedef  int /*<<< orphan*/  obs_encoder_t ;
typedef  int /*<<< orphan*/  obs_data_t ;
typedef  int int64_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  audio_t ;
struct TYPE_11__ {char* av_val; int av_len; } ;
typedef  int /*<<< orphan*/  FILE ;
typedef  TYPE_2__ AVal ;

/* Variables and functions */
 int /*<<< orphan*/  AMF_ECMA_ARRAY ; 
 char* AMF_EncodeInt32 (char*,char*,int) ; 
 char* AMF_EncodeNamedBoolean (char*,char*,TYPE_2__*,int) ; 
 char* AMF_EncodeNamedNumber (char*,char*,TYPE_2__*,double) ; 
 char* AMF_EncodeNamedString (char*,char*,TYPE_2__*,TYPE_2__*) ; 
 char* AMF_EncodeString (char*,char*,TYPE_2__*) ; 
 int /*<<< orphan*/  AMF_OBJECT_END ; 
 int /*<<< orphan*/  FLV_INFO_SIZE_OFFSET ; 
 int /*<<< orphan*/  LIBOBS_API_MAJOR_VER ; 
 int /*<<< orphan*/  LIBOBS_API_MINOR_VER ; 
 int /*<<< orphan*/  LIBOBS_API_PATCH_VER ; 
 int MILLISECOND_DEN ; 
 int /*<<< orphan*/  MODULE_NAME ; 
 scalar_t__ OBS_ENCODER_VIDEO ; 
 int RTMP_PACKET_TYPE_AUDIO ; 
 int RTMP_PACKET_TYPE_INFO ; 
 int RTMP_PACKET_TYPE_VIDEO ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  array_output_serializer_init (struct serializer*,struct array_output_data*) ; 
 int audio_output_get_channels (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bfree (char*) ; 
 char* bmemdup (char*,size_t) ; 
 int /*<<< orphan*/  dstr_cat (struct dstr*,char*) ; 
 int /*<<< orphan*/  dstr_catf (struct dstr*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dstr_free (struct dstr*) ; 
 int /*<<< orphan*/  dstr_printf (struct dstr*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fwrite (char*,int,int,int /*<<< orphan*/ *) ; 
 double obs_data_get_double (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  obs_data_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * obs_encoder_audio (int /*<<< orphan*/ *) ; 
 scalar_t__ obs_encoder_get_height (int /*<<< orphan*/ *) ; 
 scalar_t__ obs_encoder_get_sample_rate (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * obs_encoder_get_settings (int /*<<< orphan*/ *) ; 
 scalar_t__ obs_encoder_get_width (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * obs_encoder_video (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * obs_output_get_audio_encoder (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/ * obs_output_get_video_encoder (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  s_w8 (struct serializer*,int) ; 
 int /*<<< orphan*/  s_wb24 (struct serializer*,int) ; 
 int /*<<< orphan*/  s_wb32 (struct serializer*,int) ; 
 int /*<<< orphan*/  s_write (struct serializer*,char*,size_t) ; 
 int serializer_get_pos (struct serializer*) ; 
 scalar_t__ strlen (char const*) ; 
 double video_output_get_frame_rate (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int32_t get_ms_time(struct encoder_packet *packet, int64_t val)
{
	return (int32_t)(val * MILLISECOND_DEN / packet->timebase_den);
}

__attribute__((used)) static inline AVal *flv_str(AVal *out, const char *str)
{
	out->av_val = (char*)str;
	out->av_len = (int)strlen(str);
	return out;
}

__attribute__((used)) static inline void enc_num_val(char **enc, char *end, const char *name,
		double val)
{
	AVal s;
	*enc = AMF_EncodeNamedNumber(*enc, end, flv_str(&s, name), val);
}

__attribute__((used)) static inline void enc_bool_val(char **enc, char *end, const char *name,
		bool val)
{
	AVal s;
	*enc = AMF_EncodeNamedBoolean(*enc, end, flv_str(&s, name), val);
}

__attribute__((used)) static inline void enc_str_val(char **enc, char *end, const char *name,
		const char *val)
{
	AVal s1, s2;
	*enc = AMF_EncodeNamedString(*enc, end,
			flv_str(&s1, name),
			flv_str(&s2, val));
}

__attribute__((used)) static inline void enc_str(char **enc, char *end, const char *str)
{
	AVal s;
	*enc = AMF_EncodeString(*enc, end, flv_str(&s, str));
}

__attribute__((used)) static inline double encoder_bitrate(obs_encoder_t *encoder)
{
	obs_data_t *settings = obs_encoder_get_settings(encoder);
	double bitrate = obs_data_get_double(settings, "bitrate");

	obs_data_release(settings);
	return bitrate;
}

void write_file_info(FILE *file, int64_t duration_ms, int64_t size)
{
	char buf[64];
	char *enc = buf;
	char *end = enc + sizeof(buf);

	fseek(file, FLV_INFO_SIZE_OFFSET, SEEK_SET);

	enc_num_val(&enc, end, "duration", (double)duration_ms / 1000.0);
	enc_num_val(&enc, end, "fileSize", (double)size);

	fwrite(buf, 1, enc - buf, file);
}

__attribute__((used)) static bool build_flv_meta_data(obs_output_t *context,
		uint8_t **output, size_t *size, size_t a_idx)
{
	obs_encoder_t *vencoder = obs_output_get_video_encoder(context);
	obs_encoder_t *aencoder = obs_output_get_audio_encoder(context, a_idx);
	video_t       *video    = obs_encoder_video(vencoder);
	audio_t       *audio    = obs_encoder_audio(aencoder);
	char buf[4096];
	char *enc = buf;
	char *end = enc+sizeof(buf);
	struct dstr encoder_name = {0};

	if (a_idx > 0 && !aencoder)
		return false;

	enc_str(&enc, end, "onMetaData");

	*enc++ = AMF_ECMA_ARRAY;
	enc    = AMF_EncodeInt32(enc, end, a_idx == 0 ? 20 : 15);

	enc_num_val(&enc, end, "duration", 0.0);
	enc_num_val(&enc, end, "fileSize", 0.0);

	if (a_idx == 0) {
		enc_num_val(&enc, end, "width",
				(double)obs_encoder_get_width(vencoder));
		enc_num_val(&enc, end, "height",
				(double)obs_encoder_get_height(vencoder));

		enc_str_val(&enc, end, "videocodecid", "avc1");
		enc_num_val(&enc, end, "videodatarate",
				encoder_bitrate(vencoder));
		enc_num_val(&enc, end, "framerate",
				video_output_get_frame_rate(video));
	}

	enc_str_val(&enc, end, "audiocodecid", "mp4a");
	enc_num_val(&enc, end, "audiodatarate", encoder_bitrate(aencoder));
	enc_num_val(&enc, end, "audiosamplerate",
			(double)obs_encoder_get_sample_rate(aencoder));
	enc_num_val(&enc, end, "audiosamplesize", 16.0);
	enc_num_val(&enc, end, "audiochannels",
			(double)audio_output_get_channels(audio));

	enc_bool_val(&enc, end, "stereo",
			audio_output_get_channels(audio) == 2);
	enc_bool_val(&enc, end, "2.1",
			audio_output_get_channels(audio) == 3);
	enc_bool_val(&enc, end, "3.1",
			audio_output_get_channels(audio) == 4);
	enc_bool_val(&enc, end, "4.0",
			audio_output_get_channels(audio) == 4);
	enc_bool_val(&enc, end, "4.1",
			audio_output_get_channels(audio) == 5);
	enc_bool_val(&enc, end, "5.1",
			audio_output_get_channels(audio) == 6);
	enc_bool_val(&enc, end, "7.1",
			audio_output_get_channels(audio) == 8);

	dstr_printf(&encoder_name, "%s (libobs version ",
			MODULE_NAME);

#ifdef HAVE_OBSCONFIG_H
	dstr_cat(&encoder_name, OBS_VERSION);
#else
	dstr_catf(&encoder_name, "%d.%d.%d",
			LIBOBS_API_MAJOR_VER,
			LIBOBS_API_MINOR_VER,
			LIBOBS_API_PATCH_VER);
#endif

	dstr_cat(&encoder_name, ")");

	enc_str_val(&enc, end, "encoder", encoder_name.array);
	dstr_free(&encoder_name);

	*enc++  = 0;
	*enc++  = 0;
	*enc++  = AMF_OBJECT_END;

	*size   = enc-buf;
	*output = bmemdup(buf, *size);
	return true;
}

bool flv_meta_data(obs_output_t *context, uint8_t **output, size_t *size,
		bool write_header, size_t audio_idx)
{
	struct array_output_data data;
	struct serializer s;
	uint8_t *meta_data = NULL;
	size_t  meta_data_size;
	uint32_t start_pos;

	array_output_serializer_init(&s, &data);

	if (!build_flv_meta_data(context, &meta_data, &meta_data_size,
				audio_idx)) {
		bfree(meta_data);
		return false;
	}

	if (write_header) {
		s_write(&s, "FLV", 3);
		s_w8(&s, 1);
		s_w8(&s, 5);
		s_wb32(&s, 9);
		s_wb32(&s, 0);
	}

	start_pos = serializer_get_pos(&s);

	s_w8(&s, RTMP_PACKET_TYPE_INFO);

	s_wb24(&s, (uint32_t)meta_data_size);
	s_wb32(&s, 0);
	s_wb24(&s, 0);

	s_write(&s, meta_data, meta_data_size);

	s_wb32(&s, (uint32_t)serializer_get_pos(&s) - start_pos - 1);

	*output = data.bytes.array;
	*size   = data.bytes.num;

	bfree(meta_data);
	return true;
}

__attribute__((used)) static void flv_video(struct serializer *s, int32_t dts_offset,
		struct encoder_packet *packet, bool is_header)
{
	int64_t offset  = packet->pts - packet->dts;
	int32_t time_ms = get_ms_time(packet, packet->dts) - dts_offset;

	if (!packet->data || !packet->size)
		return;

	s_w8(s, RTMP_PACKET_TYPE_VIDEO);

#ifdef DEBUG_TIMESTAMPS
	blog(LOG_DEBUG, "Video: %lu", time_ms);

	if (last_time > time_ms)
		blog(LOG_DEBUG, "Non-monotonic");

	last_time = time_ms;
#endif

	s_wb24(s, (uint32_t)packet->size + 5);
	s_wb24(s, time_ms);
	s_w8(s, (time_ms >> 24) & 0x7F);
	s_wb24(s, 0);

	/* these are the 5 extra bytes mentioned above */
	s_w8(s, packet->keyframe ? 0x17 : 0x27);
	s_w8(s, is_header ? 0 : 1);
	s_wb24(s, get_ms_time(packet, offset));
	s_write(s, packet->data, packet->size);

	/* write tag size (starting byte doesn't count) */
	s_wb32(s, (uint32_t)serializer_get_pos(s) - 1);
}

__attribute__((used)) static void flv_audio(struct serializer *s, int32_t dts_offset,
		struct encoder_packet *packet, bool is_header)
{
	int32_t time_ms = get_ms_time(packet, packet->dts) - dts_offset;

	if (!packet->data || !packet->size)
		return;

	s_w8(s, RTMP_PACKET_TYPE_AUDIO);

#ifdef DEBUG_TIMESTAMPS
	blog(LOG_DEBUG, "Audio: %lu", time_ms);

	if (last_time > time_ms)
		blog(LOG_DEBUG, "Non-monotonic");

	last_time = time_ms;
#endif

	s_wb24(s, (uint32_t)packet->size + 2);
	s_wb24(s, time_ms);
	s_w8(s, (time_ms >> 24) & 0x7F);
	s_wb24(s, 0);

	/* these are the two extra bytes mentioned above */
	s_w8(s, 0xaf);
	s_w8(s, is_header ? 0 : 1);
	s_write(s, packet->data, packet->size);

	/* write tag size (starting byte doesn't count) */
	s_wb32(s, (uint32_t)serializer_get_pos(s) - 1);
}

void flv_packet_mux(struct encoder_packet *packet, int32_t dts_offset,
		uint8_t **output, size_t *size, bool is_header)
{
	struct array_output_data data;
	struct serializer s;

	array_output_serializer_init(&s, &data);

	if (packet->type == OBS_ENCODER_VIDEO)
		flv_video(&s, dts_offset, packet, is_header);
	else
		flv_audio(&s, dts_offset, packet, is_header);

	*output = data.bytes.array;
	*size   = data.bytes.num;
}

