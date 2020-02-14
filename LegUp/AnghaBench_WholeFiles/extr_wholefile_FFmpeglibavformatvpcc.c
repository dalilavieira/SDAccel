#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int int64_t ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
typedef  enum AVColorRange { ____Placeholder_AVColorRange } AVColorRange ;
typedef  enum AVChromaLocation { ____Placeholder_AVChromaLocation } AVChromaLocation ;
struct TYPE_14__ {int profile; int level; int bitdepth; int chroma_subsampling; int full_range_flag; } ;
typedef  TYPE_2__ VPCC ;
struct TYPE_17__ {int width; int height; int profile; int level; int format; int chroma_location; int color_range; int color_primaries; int color_trc; int color_space; } ;
struct TYPE_16__ {TYPE_1__* comp; } ;
struct TYPE_15__ {int den; int num; } ;
struct TYPE_13__ {int depth; } ;
typedef  TYPE_3__ AVRational ;
typedef  TYPE_4__ AVPixFmtDescriptor ;
typedef  int /*<<< orphan*/  AVIOContext ;
typedef  int /*<<< orphan*/  AVFormatContext ;
typedef  TYPE_5__ AVCodecParameters ;

/* Variables and functions */
 int AVCHROMA_LOC_LEFT ; 
 int AVCOL_RANGE_JPEG ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int FF_LEVEL_UNKNOWN ; 
 int FF_PROFILE_UNKNOWN ; 
 int FF_PROFILE_VP9_0 ; 
 int FF_PROFILE_VP9_1 ; 
 int FF_PROFILE_VP9_2 ; 
 int FF_PROFILE_VP9_3 ; 
 int VPX_SUBSAMPLING_420_COLLOCATED_WITH_LUMA ; 
 int VPX_SUBSAMPLING_420_VERTICAL ; 
 int VPX_SUBSAMPLING_422 ; 
 int VPX_SUBSAMPLING_444 ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int) ; 
 TYPE_4__* av_pix_fmt_desc_get (int) ; 
 scalar_t__ av_pix_fmt_get_chroma_sub_sample (int,int*,int*) ; 
 int /*<<< orphan*/  avio_w8 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  avio_wb16 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int get_vpx_chroma_subsampling(AVFormatContext *s,
                                      enum AVPixelFormat pixel_format,
                                      enum AVChromaLocation chroma_location)
{
    int chroma_w, chroma_h;
    if (av_pix_fmt_get_chroma_sub_sample(pixel_format, &chroma_w, &chroma_h) == 0) {
        if (chroma_w == 1 && chroma_h == 1) {
            return (chroma_location == AVCHROMA_LOC_LEFT)
                       ? VPX_SUBSAMPLING_420_VERTICAL
                       : VPX_SUBSAMPLING_420_COLLOCATED_WITH_LUMA;
        } else if (chroma_w == 1 && chroma_h == 0) {
            return VPX_SUBSAMPLING_422;
        } else if (chroma_w == 0 && chroma_h == 0) {
            return VPX_SUBSAMPLING_444;
        }
    }
    av_log(s, AV_LOG_ERROR, "Unsupported pixel format (%d)\n", pixel_format);
    return -1;
}

__attribute__((used)) static int get_bit_depth(AVFormatContext *s, enum AVPixelFormat pixel_format)
{
    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(pixel_format);
    if (desc == NULL) {
        av_log(s, AV_LOG_ERROR, "Unsupported pixel format (%d)\n",
               pixel_format);
        return -1;
    }
    return desc->comp[0].depth;
}

__attribute__((used)) static int get_vpx_video_full_range_flag(enum AVColorRange color_range)
{
    return color_range == AVCOL_RANGE_JPEG;
}

__attribute__((used)) static int get_vp9_level(AVCodecParameters *par, AVRational *frame_rate) {
    int picture_size = par->width * par->height;
    int64_t sample_rate;

    // All decisions will be based on picture_size, if frame rate is missing/invalid
    if (!frame_rate || !frame_rate->den)
        sample_rate = 0;
    else
        sample_rate = ((int64_t)picture_size * frame_rate->num) / frame_rate->den;

    if (picture_size <= 0) {
        return 0;
    } else if (sample_rate <= 829440     && picture_size <= 36864) {
        return 10;
    } else if (sample_rate <= 2764800    && picture_size <= 73728) {
        return 11;
    } else if (sample_rate <= 4608000    && picture_size <= 122880) {
        return 20;
    } else if (sample_rate <= 9216000    && picture_size <= 245760) {
        return 21;
    } else if (sample_rate <= 20736000   && picture_size <= 552960) {
        return 30;
    } else if (sample_rate <= 36864000   && picture_size <= 983040) {
        return 31;
    } else if (sample_rate <= 83558400   && picture_size <= 2228224) {
        return 40;
    } else if (sample_rate <= 160432128  && picture_size <= 2228224) {
        return 41;
    } else if (sample_rate <= 311951360  && picture_size <= 8912896) {
        return 50;
    } else if (sample_rate <= 588251136  && picture_size <= 8912896) {
        return 51;
    } else if (sample_rate <= 1176502272 && picture_size <= 8912896) {
        return 52;
    } else if (sample_rate <= 1176502272 && picture_size <= 35651584) {
        return 60;
    } else if (sample_rate <= 2353004544 && picture_size <= 35651584) {
        return 61;
    } else if (sample_rate <= 4706009088 && picture_size <= 35651584) {
        return 62;
    } else {
        return 0;
    }
}

int ff_isom_get_vpcc_features(AVFormatContext *s, AVCodecParameters *par,
                              AVRational *frame_rate, VPCC *vpcc)
{
    int profile = par->profile;
    int level = par->level == FF_LEVEL_UNKNOWN ?
        get_vp9_level(par, frame_rate) : par->level;
    int bit_depth = get_bit_depth(s, par->format);
    int vpx_chroma_subsampling =
        get_vpx_chroma_subsampling(s, par->format, par->chroma_location);
    int vpx_video_full_range_flag =
        get_vpx_video_full_range_flag(par->color_range);

    if (bit_depth < 0 || vpx_chroma_subsampling < 0)
        return AVERROR_INVALIDDATA;

    if (profile == FF_PROFILE_UNKNOWN) {
        if (vpx_chroma_subsampling == VPX_SUBSAMPLING_420_VERTICAL ||
            vpx_chroma_subsampling == VPX_SUBSAMPLING_420_COLLOCATED_WITH_LUMA) {
            profile = (bit_depth == 8) ? FF_PROFILE_VP9_0 : FF_PROFILE_VP9_2;
        } else {
            profile = (bit_depth == 8) ? FF_PROFILE_VP9_1 : FF_PROFILE_VP9_3;
        }
    }

    vpcc->profile            = profile;
    vpcc->level              = level;
    vpcc->bitdepth           = bit_depth;
    vpcc->chroma_subsampling = vpx_chroma_subsampling;
    vpcc->full_range_flag    = vpx_video_full_range_flag;

    return 0;
}

int ff_isom_write_vpcc(AVFormatContext *s, AVIOContext *pb,
                       AVCodecParameters *par)
{
    VPCC vpcc;
    int ret;

    ret = ff_isom_get_vpcc_features(s, par, NULL, &vpcc);
    if (ret < 0)
        return ret;

    avio_w8(pb, vpcc.profile);
    avio_w8(pb, vpcc.level);
    avio_w8(pb, (vpcc.bitdepth << 4) | (vpcc.chroma_subsampling << 1) | vpcc.full_range_flag);
    avio_w8(pb, par->color_primaries);
    avio_w8(pb, par->color_trc);
    avio_w8(pb, par->color_space);

    // vp9 does not have codec initialization data.
    avio_wb16(pb, 0);
    return 0;
}

