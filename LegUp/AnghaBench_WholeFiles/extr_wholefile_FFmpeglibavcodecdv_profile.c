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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
typedef  int /*<<< orphan*/  AVRational ;
typedef  int /*<<< orphan*/  AVDVProfile ;
typedef  int /*<<< orphan*/  AVCodecContext ;

/* Variables and functions */

const AVDVProfile* ff_dv_frame_profile(AVCodecContext* codec, const AVDVProfile *sys,
                                       const uint8_t *frame, unsigned buf_size)
{
#if CONFIG_DVPROFILE
    int i, dsf, stype;

    if(buf_size < DV_PROFILE_BYTES)
        return NULL;

    dsf   = (frame[3] & 0x80) >> 7;
    stype = frame[80 * 5 + 48 + 3] & 0x1f;

    /* 576i50 25Mbps 4:1:1 is a special case */
    if ((dsf == 1 && stype == 0 && frame[4] & 0x07 /* the APT field */) ||
        (stype == 31 && codec && codec->codec_tag==AV_RL32("SL25") && codec->coded_width==720 && codec->coded_height==576))
        return &dv_profiles[2];

    if(   stype == 0
       && codec
       && (codec->codec_tag==AV_RL32("dvsd") || codec->codec_tag==AV_RL32("CDVC"))
       && codec->coded_width ==720
       && codec->coded_height==576)
        return &dv_profiles[1];

    for (i = 0; i < FF_ARRAY_ELEMS(dv_profiles); i++)
        if (dsf == dv_profiles[i].dsf && stype == dv_profiles[i].video_stype)
            return &dv_profiles[i];

    /* check if old sys matches and assumes corrupted input */
    if (sys && buf_size == sys->frame_size)
        return sys;

    /* hack for trac issue #217, dv files created with QuickTime 3 */
    if ((frame[3] & 0x7f) == 0x3f && frame[80 * 5 + 48 + 3] == 0xff)
        return &dv_profiles[dsf];
#endif

    return NULL;
}

const AVDVProfile *av_dv_frame_profile(const AVDVProfile *sys,
                                       const uint8_t *frame, unsigned buf_size)
{
    return ff_dv_frame_profile(NULL, sys, frame, buf_size);
}

const AVDVProfile *av_dv_codec_profile(int width, int height,
                                       enum AVPixelFormat pix_fmt)
{
#if CONFIG_DVPROFILE
    return av_dv_codec_profile2(width, height, pix_fmt, (AVRational){0, 0});
#endif

    return NULL;
}

const AVDVProfile *av_dv_codec_profile2(int width, int height,
                                       enum AVPixelFormat pix_fmt,
                                       AVRational frame_rate)
{
    const AVDVProfile *p = NULL;
#if CONFIG_DVPROFILE
    int i;
    /* frame rate is necessary to select between 720p50 and 720p60 profiles */
    int invalid_framerate = frame_rate.num == 0 || frame_rate.den == 0;

    for (i = 0; i < FF_ARRAY_ELEMS(dv_profiles); i++)
        if (height  == dv_profiles[i].height  &&
            pix_fmt == dv_profiles[i].pix_fmt &&
            width   == dv_profiles[i].width)
        {
            if( invalid_framerate || av_div_q(dv_profiles[i].time_base, frame_rate).num == 1 )
                return &dv_profiles[i];

            if(!p)
                p = &dv_profiles[i];
        }
#endif

    return p;
}

