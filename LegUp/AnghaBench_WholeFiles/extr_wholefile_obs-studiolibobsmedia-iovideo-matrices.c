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
typedef  enum video_range_type { ____Placeholder_video_range_type } video_range_type ;
typedef  enum video_format { ____Placeholder_video_format } video_format ;
typedef  enum video_colorspace { ____Placeholder_video_colorspace } video_colorspace ;

/* Variables and functions */
#define  VIDEO_CS_601 141 
#define  VIDEO_CS_709 140 
#define  VIDEO_CS_DEFAULT 139 
#define  VIDEO_FORMAT_BGRA 138 
#define  VIDEO_FORMAT_BGRX 137 
#define  VIDEO_FORMAT_I420 136 
#define  VIDEO_FORMAT_I444 135 
#define  VIDEO_FORMAT_NONE 134 
#define  VIDEO_FORMAT_NV12 133 
#define  VIDEO_FORMAT_RGBA 132 
#define  VIDEO_FORMAT_UYVY 131 
#define  VIDEO_FORMAT_Y800 130 
#define  VIDEO_FORMAT_YUY2 129 
#define  VIDEO_FORMAT_YVYU 128 
 int VIDEO_RANGE_DEFAULT ; 
 int VIDEO_RANGE_FULL ; 
 int VIDEO_RANGE_PARTIAL ; 
 void* bmalloc (size_t) ; 
 scalar_t__ bmemdup (char const*,size_t) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,size_t) ; 
 size_t strlen (char const*) ; 
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

