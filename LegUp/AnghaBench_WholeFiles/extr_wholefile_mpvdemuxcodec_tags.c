#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  void* uint64_t ;
typedef  int uint32_t ;
struct mp_chmap {scalar_t__ num; } ;
struct mp_codec_params {int codec_tag; int extradata_size; unsigned char* extradata; char const* codec; int type; int bits_per_coded_sample; struct mp_chmap channels; } ;
struct AVCodecTag {int dummy; } ;
typedef  int /*<<< orphan*/  codec ;

/* Variables and functions */
 int AV_CODEC_ID_NONE ; 
 void* AV_RL32 (unsigned char*) ; 
#define  STREAM_AUDIO 129 
#define  STREAM_VIDEO 128 
 int av_codec_get_id (struct AVCodecTag const**,int) ; 
 struct AVCodecTag* avformat_get_riff_audio_tags () ; 
 struct AVCodecTag* avformat_get_riff_video_tags () ; 
 scalar_t__ guid_ext_base ; 
 scalar_t__ memcmp (unsigned char*,scalar_t__,int) ; 
 char const*** mimetype_to_codec ; 
 int /*<<< orphan*/  mp_chmap_from_waveext (struct mp_chmap*,void*) ; 
 char const* mp_codec_from_av_codec_id (int) ; 
 void mp_set_pcm_codec (struct mp_codec_params*,int,int,int,int) ; 
 int /*<<< orphan*/  mp_snprintf_cat (char*,int,char*,...) ; 
 scalar_t__ strcasecmp (char const*,char const*) ; 
 char const* talloc_strdup (struct mp_codec_params*,char*) ; 

__attribute__((used)) static const char *lookup_tag(int type, uint32_t tag)
{
    const struct AVCodecTag *av_tags[3] = {0};
    switch (type) {
    case STREAM_VIDEO: {
        av_tags[0] = avformat_get_riff_video_tags();
#if HAVE_QT_TAGS
        av_tags[1] = avformat_get_mov_video_tags();
#endif
        break;
    }
    case STREAM_AUDIO: {
        av_tags[0] = avformat_get_riff_audio_tags();
#if HAVE_QT_TAGS
        av_tags[1] = avformat_get_mov_audio_tags();
#endif
        break;
    }
    }

    int id = av_codec_get_id(av_tags, tag);
    return id == AV_CODEC_ID_NONE ? NULL : mp_codec_from_av_codec_id(id);
}

__attribute__((used)) static void map_audio_pcm_tag(struct mp_codec_params *c)
{
    // MS PCM, Extended
    if (c->codec_tag == 0xfffe && c->extradata_size >= 22) {
        // WAVEFORMATEXTENSIBLE.dwChannelMask
        uint64_t chmask = AV_RL32(c->extradata + 2);
        struct mp_chmap chmap;
        mp_chmap_from_waveext(&chmap, chmask);
        if (c->channels.num == chmap.num)
            c->channels = chmap;

        // WAVEFORMATEXTENSIBLE.SubFormat
        unsigned char *subformat = c->extradata + 6;
        if (memcmp(subformat + 4, guid_ext_base + 4, 12) == 0) {
            c->codec_tag = AV_RL32(subformat);
            c->codec = lookup_tag(c->type, c->codec_tag);
        }

        // Compressed formats might use this.
        c->extradata += 22;
        c->extradata_size += 22;
    }

    int bits = c->bits_per_coded_sample;
    int bytes = (bits + 7) / 8;
    switch (c->codec_tag) {
    case 0x0:       // Microsoft PCM
    case 0x1:
        if (bytes >= 1 && bytes <= 4)
            mp_set_pcm_codec(c, bytes > 1, false, bytes * 8, false);
        break;
    case 0x3:       // IEEE float
        mp_set_pcm_codec(c, true, true, bits == 64 ? 64 : 32, false);
        break;
    }
}

void mp_set_codec_from_tag(struct mp_codec_params *c)
{
    c->codec = lookup_tag(c->type, c->codec_tag);

    if (c->type == STREAM_AUDIO && c->bits_per_coded_sample)
        map_audio_pcm_tag(c);
}

void mp_set_pcm_codec(struct mp_codec_params *c, bool sign, bool is_float,
                      int bits, bool is_be)
{
    // This uses libavcodec pcm codec names, e.g. "pcm_u16le".
    char codec[64] = "pcm_";
    if (is_float) {
        mp_snprintf_cat(codec, sizeof(codec), "f");
    } else {
        mp_snprintf_cat(codec, sizeof(codec), sign ? "s" : "u");
    }
    mp_snprintf_cat(codec, sizeof(codec), "%d", bits);
    if (bits != 8)
        mp_snprintf_cat(codec, sizeof(codec), is_be ? "be" : "le");
    c->codec = talloc_strdup(c, codec);
}

const char *mp_map_mimetype_to_video_codec(const char *mimetype)
{
    if (mimetype) {
        for (int n = 0; mimetype_to_codec[n][0]; n++) {
            if (strcasecmp(mimetype_to_codec[n][0], mimetype) == 0)
                return mimetype_to_codec[n][1];
        }
    }
    return NULL;
}

