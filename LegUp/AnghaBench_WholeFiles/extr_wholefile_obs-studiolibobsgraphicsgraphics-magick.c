#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  char wchar_t ;
struct gs_vb_data {size_t num_tex; struct gs_vb_data* tvarray; struct gs_vb_data* array; struct gs_vb_data* colors; struct gs_vb_data* tangents; struct gs_vb_data* normals; struct gs_vb_data* points; } ;
typedef  struct gs_vb_data uint8_t ;
typedef  size_t uint32_t ;
typedef  enum gs_color_format { ____Placeholder_gs_color_format } gs_color_format ;
struct TYPE_16__ {scalar_t__ severity; int /*<<< orphan*/  reason; } ;
struct TYPE_15__ {size_t magick_columns; size_t magick_rows; } ;
struct TYPE_14__ {int /*<<< orphan*/  filename; } ;
typedef  TYPE_1__ ImageInfo ;
typedef  TYPE_2__ Image ;
typedef  TYPE_3__ ExceptionInfo ;

/* Variables and functions */
 TYPE_3__* AcquireExceptionInfo () ; 
 int /*<<< orphan*/  CharPixel ; 
 TYPE_1__* CloneImageInfo (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DestroyExceptionInfo (TYPE_3__*) ; 
 int /*<<< orphan*/  DestroyImage (TYPE_2__*) ; 
 int /*<<< orphan*/  DestroyImageInfo (TYPE_1__*) ; 
 int /*<<< orphan*/  ExportImagePixels (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,size_t,char*,int /*<<< orphan*/ ,struct gs_vb_data*,TYPE_3__*) ; 
#define  GS_A8 146 
#define  GS_BGRA 145 
#define  GS_BGRX 144 
#define  GS_DXT1 143 
#define  GS_DXT3 142 
#define  GS_DXT5 141 
#define  GS_R10G10B10A2 140 
#define  GS_R16 139 
#define  GS_R16F 138 
#define  GS_R32F 137 
#define  GS_R8 136 
#define  GS_R8G8 135 
#define  GS_RG16F 134 
#define  GS_RG32F 133 
#define  GS_RGBA 132 
#define  GS_RGBA16 131 
#define  GS_RGBA16F 130 
#define  GS_RGBA32F 129 
#define  GS_UNKNOWN 128 
 int /*<<< orphan*/  LOG_WARNING ; 
 int /*<<< orphan*/  MagickCoreGenesis (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MagickCoreTerminus () ; 
 int /*<<< orphan*/  MagickTrue ; 
 TYPE_2__* ReadImage (TYPE_1__*,TYPE_3__*) ; 
 scalar_t__ UndefinedException ; 
 int /*<<< orphan*/  bfree (struct gs_vb_data*) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,char const*,int /*<<< orphan*/ ) ; 
 void* bmalloc (size_t) ; 
 scalar_t__ bmemdup (char const*,size_t) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char const*) ; 
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

__attribute__((used)) static inline struct gs_vb_data *gs_vbdata_create(void)
{
	return (struct gs_vb_data*)bzalloc(sizeof(struct gs_vb_data));
}

__attribute__((used)) static inline void gs_vbdata_destroy(struct gs_vb_data *data)
{
	uint32_t i;
	if (!data)
		return;

	bfree(data->points);
	bfree(data->normals);
	bfree(data->tangents);
	bfree(data->colors);
	for (i = 0; i < data->num_tex; i++)
		bfree(data->tvarray[i].array);
	bfree(data->tvarray);
	bfree(data);
}

__attribute__((used)) static inline uint32_t gs_get_format_bpp(enum gs_color_format format)
{
	switch (format) {
	case GS_A8:          return 8;
	case GS_R8:          return 8;
	case GS_RGBA:        return 32;
	case GS_BGRX:        return 32;
	case GS_BGRA:        return 32;
	case GS_R10G10B10A2: return 32;
	case GS_RGBA16:      return 64;
	case GS_R16:         return 16;
	case GS_RGBA16F:     return 64;
	case GS_RGBA32F:     return 128;
	case GS_RG16F:       return 32;
	case GS_RG32F:       return 64;
	case GS_R16F:        return 16;
	case GS_R32F:        return 32;
	case GS_DXT1:        return 4;
	case GS_DXT3:        return 8;
	case GS_DXT5:        return 8;
	case GS_R8G8:        return 16;
	case GS_UNKNOWN:     return 0;
	}

	return 0;
}

__attribute__((used)) static inline bool gs_is_compressed_format(enum gs_color_format format)
{
	return (format == GS_DXT1 || format == GS_DXT3 || format == GS_DXT5);
}

__attribute__((used)) static inline uint32_t gs_get_total_levels(uint32_t width, uint32_t height)
{
	uint32_t size = width > height ? width : height;
	uint32_t num_levels = 0;

	while (size > 1) {
		size /= 2;
		num_levels++;
	}

	return num_levels;
}

void gs_init_image_deps()
{
	MagickCoreGenesis(NULL, MagickTrue);
}

void gs_free_image_deps()
{
	MagickCoreTerminus();
}

uint8_t *gs_create_texture_file_data(const char *file,
		enum gs_color_format *format,
		uint32_t *cx_out, uint32_t *cy_out)
{
	uint8_t       *data = NULL;
	ImageInfo     *info;
	ExceptionInfo *exception;
	Image         *image;

	if (!file || !*file)
		return NULL;

	info      = CloneImageInfo(NULL);
	exception = AcquireExceptionInfo();

	strcpy(info->filename, file);
	image = ReadImage(info, exception);
	if (image) {
		size_t  cx    = image->magick_columns;
		size_t  cy    = image->magick_rows;
		data          = bmalloc(cx * cy * 4);

		ExportImagePixels(image, 0, 0, cx, cy, "BGRA", CharPixel,
				data, exception);
		if (exception->severity != UndefinedException) {
			blog(LOG_WARNING, "magickcore warning/error getting "
			                  "pixels from file '%s': %s", file,
			                  exception->reason);
			bfree(data);
			data = NULL;
		}

		*format = GS_BGRA;
		*cx_out = (uint32_t)cx;
		*cy_out = (uint32_t)cy;
		DestroyImage(image);

	} else if (exception->severity != UndefinedException) {
		blog(LOG_WARNING, "magickcore warning/error reading file "
		                  "'%s': %s", file, exception->reason);
	}

	DestroyImageInfo(info);
	DestroyExceptionInfo(exception);

	return data;
}

