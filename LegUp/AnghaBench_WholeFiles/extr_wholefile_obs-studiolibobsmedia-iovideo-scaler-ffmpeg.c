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
typedef  char wchar_t ;
struct video_scaler {int /*<<< orphan*/  swscale; int /*<<< orphan*/  src_height; } ;
typedef  struct video_scaler video_scaler_t ;
struct video_scale_info {int format; int colorspace; int range; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
typedef  enum video_scale_type { ____Placeholder_video_scale_type } video_scale_type ;
typedef  enum video_range_type { ____Placeholder_video_range_type } video_range_type ;
typedef  enum video_format { ____Placeholder_video_format } video_format ;
typedef  enum video_colorspace { ____Placeholder_video_colorspace } video_colorspace ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;

/* Variables and functions */
 int AV_PIX_FMT_BGRA ; 
 int AV_PIX_FMT_GRAY8 ; 
 int AV_PIX_FMT_NONE ; 
 int AV_PIX_FMT_NV12 ; 
 int AV_PIX_FMT_RGBA ; 
 int AV_PIX_FMT_UYVY422 ; 
 int AV_PIX_FMT_YUV420P ; 
 int AV_PIX_FMT_YUV444P ; 
 int AV_PIX_FMT_YUYV422 ; 
 int /*<<< orphan*/  FIXED_1_0 ; 
 int /*<<< orphan*/  LOG_DEBUG ; 
 int /*<<< orphan*/  LOG_ERROR ; 
 int SWS_AREA ; 
 int SWS_BICUBIC ; 
 int SWS_BILINEAR ; 
 int /*<<< orphan*/  SWS_CS_ITU601 ; 
 int /*<<< orphan*/  SWS_CS_ITU709 ; 
 int SWS_FAST_BILINEAR ; 
 int SWS_POINT ; 
#define  VIDEO_CS_601 149 
#define  VIDEO_CS_709 148 
#define  VIDEO_CS_DEFAULT 147 
#define  VIDEO_FORMAT_BGRA 146 
#define  VIDEO_FORMAT_BGRX 145 
#define  VIDEO_FORMAT_I420 144 
#define  VIDEO_FORMAT_I444 143 
#define  VIDEO_FORMAT_NONE 142 
#define  VIDEO_FORMAT_NV12 141 
#define  VIDEO_FORMAT_RGBA 140 
#define  VIDEO_FORMAT_UYVY 139 
#define  VIDEO_FORMAT_Y800 138 
#define  VIDEO_FORMAT_YUY2 137 
#define  VIDEO_FORMAT_YVYU 136 
#define  VIDEO_RANGE_DEFAULT 135 
#define  VIDEO_RANGE_FULL 134 
#define  VIDEO_RANGE_PARTIAL 133 
 int VIDEO_SCALER_BAD_CONVERSION ; 
 int VIDEO_SCALER_FAILED ; 
 int VIDEO_SCALER_SUCCESS ; 
#define  VIDEO_SCALE_BICUBIC 132 
#define  VIDEO_SCALE_BILINEAR 131 
#define  VIDEO_SCALE_DEFAULT 130 
#define  VIDEO_SCALE_FAST_BILINEAR 129 
#define  VIDEO_SCALE_POINT 128 
 int /*<<< orphan*/  bfree (struct video_scaler*) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*) ; 
 void* bmalloc (size_t) ; 
 scalar_t__ bmemdup (char const*,size_t) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,size_t) ; 
 size_t strlen (char const*) ; 
 int /*<<< orphan*/  sws_freeContext (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sws_getCachedContext (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int const* sws_getCoefficients (int /*<<< orphan*/ ) ; 
 int sws_setColorspaceDetails (int /*<<< orphan*/ ,int const*,int,int const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void video_scaler_destroy (struct video_scaler*) ; 
 size_t wcslen (char const*) ; 

__attribute__((used)) static inline void *bzalloc(size_t size)
{
	void *mem = bmalloc(size);
	if (mem)
		memset(mem, 0, size);
	return mem;
}

__attribute__((used)) static inline char *bstrdup_n(const char *str, size_t n)
{
	char *dup;
	if (!str)
		return NULL;

	dup = (char*)bmemdup(str, n+1);
	dup[n] = 0;

	return dup;
}

__attribute__((used)) static inline wchar_t *bwstrdup_n(const wchar_t *str, size_t n)
{
	wchar_t *dup;
	if (!str)
		return NULL;

	dup = (wchar_t*)bmemdup(str, (n+1) * sizeof(wchar_t));
	dup[n] = 0;

	return dup;
}

__attribute__((used)) static inline char *bstrdup(const char *str)
{
	if (!str)
		return NULL;

	return bstrdup_n(str, strlen(str));
}

__attribute__((used)) static inline wchar_t *bwstrdup(const wchar_t *str)
{
	if (!str)
		return NULL;

	return bwstrdup_n(str, wcslen(str));
}

__attribute__((used)) static inline bool format_is_yuv(enum video_format format)
{
	switch (format) {
	case VIDEO_FORMAT_I420:
	case VIDEO_FORMAT_NV12:
	case VIDEO_FORMAT_YVYU:
	case VIDEO_FORMAT_YUY2:
	case VIDEO_FORMAT_UYVY:
	case VIDEO_FORMAT_I444:
		return true;
	case VIDEO_FORMAT_NONE:
	case VIDEO_FORMAT_RGBA:
	case VIDEO_FORMAT_BGRA:
	case VIDEO_FORMAT_BGRX:
	case VIDEO_FORMAT_Y800:
		return false;
	}

	return false;
}

__attribute__((used)) static inline const char *get_video_format_name(enum video_format format)
{
	switch (format) {
	case VIDEO_FORMAT_I420: return "I420";
	case VIDEO_FORMAT_NV12: return "NV12";
	case VIDEO_FORMAT_YVYU: return "YVYU";
	case VIDEO_FORMAT_YUY2: return "YUY2";
	case VIDEO_FORMAT_UYVY: return "UYVY";
	case VIDEO_FORMAT_RGBA: return "RGBA";
	case VIDEO_FORMAT_BGRA: return "BGRA";
	case VIDEO_FORMAT_BGRX: return "BGRX";
	case VIDEO_FORMAT_I444: return "I444";
	case VIDEO_FORMAT_Y800: return "Y800";
	case VIDEO_FORMAT_NONE:;
	}

	return "None";
}

__attribute__((used)) static inline const char *get_video_colorspace_name(enum video_colorspace cs)
{
	switch (cs) {
	case VIDEO_CS_709: return "709";
	case VIDEO_CS_601:
	case VIDEO_CS_DEFAULT:;
	}

	return "601";
}

__attribute__((used)) static inline enum video_range_type resolve_video_range(
		enum video_format format, enum video_range_type range)
{
	if (range == VIDEO_RANGE_DEFAULT) {
		range = format_is_yuv(format)
			? VIDEO_RANGE_PARTIAL
			: VIDEO_RANGE_FULL;
	}

	return range;
}

__attribute__((used)) static inline const char *get_video_range_name(enum video_format format,
		enum video_range_type range)
{
	range = resolve_video_range(format, range);
	return range == VIDEO_RANGE_FULL ? "Full" : "Partial";
}

__attribute__((used)) static inline enum AVPixelFormat get_ffmpeg_video_format(
		enum video_format format)
{
	switch (format) {
	case VIDEO_FORMAT_NONE: return AV_PIX_FMT_NONE;
	case VIDEO_FORMAT_I420: return AV_PIX_FMT_YUV420P;
	case VIDEO_FORMAT_NV12: return AV_PIX_FMT_NV12;
	case VIDEO_FORMAT_YVYU: return AV_PIX_FMT_NONE;
	case VIDEO_FORMAT_YUY2: return AV_PIX_FMT_YUYV422;
	case VIDEO_FORMAT_UYVY: return AV_PIX_FMT_UYVY422;
	case VIDEO_FORMAT_RGBA: return AV_PIX_FMT_RGBA;
	case VIDEO_FORMAT_BGRA: return AV_PIX_FMT_BGRA;
	case VIDEO_FORMAT_BGRX: return AV_PIX_FMT_BGRA;
	case VIDEO_FORMAT_Y800: return AV_PIX_FMT_GRAY8;
	case VIDEO_FORMAT_I444: return AV_PIX_FMT_YUV444P;
	}

	return AV_PIX_FMT_NONE;
}

__attribute__((used)) static inline int get_ffmpeg_scale_type(enum video_scale_type type)
{
	switch (type) {
	case VIDEO_SCALE_DEFAULT:       return SWS_FAST_BILINEAR;
	case VIDEO_SCALE_POINT:         return SWS_POINT;
	case VIDEO_SCALE_FAST_BILINEAR: return SWS_FAST_BILINEAR;
	case VIDEO_SCALE_BILINEAR:      return SWS_BILINEAR | SWS_AREA;
	case VIDEO_SCALE_BICUBIC:       return SWS_BICUBIC;
	}

	return SWS_POINT;
}

__attribute__((used)) static inline const int *get_ffmpeg_coeffs(enum video_colorspace cs)
{
	switch (cs) {
	case VIDEO_CS_DEFAULT: return sws_getCoefficients(SWS_CS_ITU601);
	case VIDEO_CS_601:     return sws_getCoefficients(SWS_CS_ITU601);
	case VIDEO_CS_709:     return sws_getCoefficients(SWS_CS_ITU709);
	}

	return sws_getCoefficients(SWS_CS_ITU601);
}

__attribute__((used)) static inline int get_ffmpeg_range_type(enum video_range_type type)
{
	switch (type) {
	case VIDEO_RANGE_DEFAULT: return 0;
	case VIDEO_RANGE_PARTIAL: return 0;
	case VIDEO_RANGE_FULL:    return 1;
	}

	return 0;
}

int video_scaler_create(video_scaler_t **scaler_out,
		const struct video_scale_info *dst,
		const struct video_scale_info *src,
		enum video_scale_type type)
{
	enum AVPixelFormat format_src = get_ffmpeg_video_format(src->format);
	enum AVPixelFormat format_dst = get_ffmpeg_video_format(dst->format);
	int                scale_type = get_ffmpeg_scale_type(type);
	const int          *coeff_src = get_ffmpeg_coeffs(src->colorspace);
	const int          *coeff_dst = get_ffmpeg_coeffs(dst->colorspace);
	int                range_src  = get_ffmpeg_range_type(src->range);
	int                range_dst  = get_ffmpeg_range_type(dst->range);
	struct video_scaler *scaler;
	int ret;

	if (!scaler_out)
		return VIDEO_SCALER_FAILED;

	if (format_src == AV_PIX_FMT_NONE ||
	    format_dst == AV_PIX_FMT_NONE)
		return VIDEO_SCALER_BAD_CONVERSION;

	scaler = bzalloc(sizeof(struct video_scaler));
	scaler->src_height = src->height;

	scaler->swscale = sws_getCachedContext(NULL,
			src->width, src->height, format_src,
			dst->width, dst->height, format_dst,
			scale_type, NULL, NULL, NULL);
	if (!scaler->swscale) {
		blog(LOG_ERROR, "video_scaler_create: Could not create "
		                "swscale");
		goto fail;
	}

	ret = sws_setColorspaceDetails(scaler->swscale,
			coeff_src, range_src,
			coeff_dst, range_dst,
			0, FIXED_1_0, FIXED_1_0);
	if (ret < 0) {
		blog(LOG_DEBUG, "video_scaler_create: "
		                "sws_setColorspaceDetails failed, ignoring");
	}

	*scaler_out = scaler;
	return VIDEO_SCALER_SUCCESS;

fail:
	video_scaler_destroy(scaler);
	return VIDEO_SCALER_FAILED;
}

void video_scaler_destroy(video_scaler_t *scaler)
{
	if (scaler) {
		sws_freeContext(scaler->swscale);
		bfree(scaler);
	}
}

