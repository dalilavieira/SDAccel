#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ int64_t ;
typedef  enum AVMediaType { ____Placeholder_AVMediaType } AVMediaType ;
typedef  enum AVCodecID { ____Placeholder_AVCodecID } AVCodecID ;
struct TYPE_11__ {int pt; scalar_t__ codec_id; scalar_t__ codec_type; scalar_t__ audio_channels; scalar_t__ clock_rate; char const* enc_name; } ;
struct TYPE_10__ {scalar_t__ codec_type; scalar_t__ codec_id; int channels; int sample_rate; } ;
struct TYPE_9__ {scalar_t__ priv_data; TYPE_1__* oformat; } ;
struct TYPE_8__ {scalar_t__ priv_class; } ;
typedef  TYPE_1__ AVOutputFormat ;
typedef  TYPE_2__ AVFormatContext ;
typedef  TYPE_3__ AVCodecParameters ;

/* Variables and functions */
 scalar_t__ AVMEDIA_TYPE_AUDIO ; 
 scalar_t__ AV_CODEC_ID_ADPCM_G722 ; 
 scalar_t__ AV_CODEC_ID_H263 ; 
 scalar_t__ AV_CODEC_ID_NONE ; 
 int RTP_PT_PRIVATE ; 
 int /*<<< orphan*/  av_opt_flag_is_set (scalar_t__,char*,char*) ; 
 scalar_t__ av_opt_get_int (scalar_t__,char*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  av_strcasecmp (char const*,char const*) ; 
 TYPE_4__* rtp_payload_types ; 

int ff_rtp_get_codec_info(AVCodecParameters *par, int payload_type)
{
    int i = 0;

    for (i = 0; rtp_payload_types[i].pt >= 0; i++)
        if (rtp_payload_types[i].pt == payload_type) {
            if (rtp_payload_types[i].codec_id != AV_CODEC_ID_NONE) {
                par->codec_type = rtp_payload_types[i].codec_type;
                par->codec_id = rtp_payload_types[i].codec_id;
                if (rtp_payload_types[i].audio_channels > 0)
                    par->channels = rtp_payload_types[i].audio_channels;
                if (rtp_payload_types[i].clock_rate > 0)
                    par->sample_rate = rtp_payload_types[i].clock_rate;
                return 0;
            }
        }
    return -1;
}

int ff_rtp_get_payload_type(AVFormatContext *fmt,
                            AVCodecParameters *par, int idx)
{
    int i;
    const AVOutputFormat *ofmt = fmt ? fmt->oformat : NULL;

    /* Was the payload type already specified for the RTP muxer? */
    if (ofmt && ofmt->priv_class && fmt->priv_data) {
        int64_t payload_type;
        if (av_opt_get_int(fmt->priv_data, "payload_type", 0, &payload_type) >= 0 &&
            payload_type >= 0)
            return (int)payload_type;
    }

    /* static payload type */
    for (i = 0; rtp_payload_types[i].pt >= 0; ++i)
        if (rtp_payload_types[i].codec_id == par->codec_id) {
            if (par->codec_id == AV_CODEC_ID_H263 && (!fmt || !fmt->oformat ||
                !fmt->oformat->priv_class || !fmt->priv_data ||
                !av_opt_flag_is_set(fmt->priv_data, "rtpflags", "rfc2190")))
                continue;
            /* G722 has 8000 as nominal rate even if the sample rate is 16000,
             * see section 4.5.2 in RFC 3551. */
            if (par->codec_id == AV_CODEC_ID_ADPCM_G722 &&
                par->sample_rate == 16000 && par->channels == 1)
                return rtp_payload_types[i].pt;
            if (par->codec_type == AVMEDIA_TYPE_AUDIO &&
                ((rtp_payload_types[i].clock_rate > 0 &&
                  par->sample_rate != rtp_payload_types[i].clock_rate) ||
                 (rtp_payload_types[i].audio_channels > 0 &&
                  par->channels != rtp_payload_types[i].audio_channels)))
                continue;
            return rtp_payload_types[i].pt;
        }

    if (idx < 0)
        idx = par->codec_type == AVMEDIA_TYPE_AUDIO;

    /* dynamic payload type */
    return RTP_PT_PRIVATE + idx;
}

const char *ff_rtp_enc_name(int payload_type)
{
    int i;

    for (i = 0; rtp_payload_types[i].pt >= 0; i++)
        if (rtp_payload_types[i].pt == payload_type)
            return rtp_payload_types[i].enc_name;

    return "";
}

enum AVCodecID ff_rtp_codec_id(const char *buf, enum AVMediaType codec_type)
{
    int i;

    for (i = 0; rtp_payload_types[i].pt >= 0; i++)
        if (!av_strcasecmp(buf, rtp_payload_types[i].enc_name) && (codec_type == rtp_payload_types[i].codec_type))
            return rtp_payload_types[i].codec_id;

    return AV_CODEC_ID_NONE;
}

