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
typedef  size_t uint32_t ;
struct gs_vb_data {size_t num_tex; int format; int zsformat; size_t cx; size_t cy; int rendered; int /*<<< orphan*/ * target; int /*<<< orphan*/  prev_zs; int /*<<< orphan*/  prev_target; int /*<<< orphan*/ * zs; struct gs_vb_data* tvarray; struct gs_vb_data* array; struct gs_vb_data* colors; struct gs_vb_data* tangents; struct gs_vb_data* normals; struct gs_vb_data* points; } ;
struct gs_texture_render {size_t num_tex; int format; int zsformat; size_t cx; size_t cy; int rendered; int /*<<< orphan*/ * target; int /*<<< orphan*/  prev_zs; int /*<<< orphan*/  prev_target; int /*<<< orphan*/ * zs; struct gs_texture_render* tvarray; struct gs_texture_render* array; struct gs_texture_render* colors; struct gs_texture_render* tangents; struct gs_texture_render* normals; struct gs_texture_render* points; } ;
typedef  int /*<<< orphan*/  gs_texture_t ;
typedef  struct gs_vb_data gs_texrender_t ;
typedef  enum gs_zstencil_format { ____Placeholder_gs_zstencil_format } gs_zstencil_format ;
typedef  enum gs_color_format { ____Placeholder_gs_color_format } gs_color_format ;

/* Variables and functions */
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
 int /*<<< orphan*/  GS_RENDER_TARGET ; 
#define  GS_RG16F 134 
#define  GS_RG32F 133 
#define  GS_RGBA 132 
#define  GS_RGBA16 131 
#define  GS_RGBA16F 130 
#define  GS_RGBA32F 129 
#define  GS_UNKNOWN 128 
 scalar_t__ GS_ZS_NONE ; 
 int /*<<< orphan*/  bfree (struct gs_vb_data*) ; 
 void* bmalloc (size_t) ; 
 scalar_t__ bmemdup (char const*,size_t) ; 
 int /*<<< orphan*/  gs_matrix_pop () ; 
 int /*<<< orphan*/  gs_projection_pop () ; 
 int /*<<< orphan*/  gs_set_render_target (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * gs_texture_create (size_t,size_t,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gs_texture_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gs_viewport_pop () ; 
 int /*<<< orphan*/ * gs_zstencil_create (size_t,size_t,scalar_t__) ; 
 int /*<<< orphan*/  gs_zstencil_destroy (int /*<<< orphan*/ *) ; 
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

gs_texrender_t *gs_texrender_create(enum gs_color_format format,
		enum gs_zstencil_format zsformat)
{
	struct gs_texture_render *texrender;
	texrender = bzalloc(sizeof(struct gs_texture_render));
	texrender->format   = format;
	texrender->zsformat = zsformat;

	return texrender;
}

void gs_texrender_destroy(gs_texrender_t *texrender)
{
	if (texrender) {
		gs_texture_destroy(texrender->target);
		gs_zstencil_destroy(texrender->zs);
		bfree(texrender);
	}
}

__attribute__((used)) static bool texrender_resetbuffer(gs_texrender_t *texrender, uint32_t cx,
		uint32_t cy)
{
	if (!texrender)
		return false;

	gs_texture_destroy(texrender->target);
	gs_zstencil_destroy(texrender->zs);

	texrender->target = NULL;
	texrender->zs     = NULL;
	texrender->cx     = cx;
	texrender->cy     = cy;

	texrender->target = gs_texture_create(cx, cy, texrender->format,
			1, NULL, GS_RENDER_TARGET);
	if (!texrender->target)
		return false;

	if (texrender->zsformat != GS_ZS_NONE) {
		texrender->zs = gs_zstencil_create(cx, cy, texrender->zsformat);
		if (!texrender->zs) {
			gs_texture_destroy(texrender->target);
			texrender->target = NULL;

			return false;
		}
	}

	return true;
}

void gs_texrender_end(gs_texrender_t *texrender)
{
	if (!texrender)
		return;

	gs_set_render_target(texrender->prev_target, texrender->prev_zs);

	gs_matrix_pop();
	gs_projection_pop();
	gs_viewport_pop();

	texrender->rendered = true;
}

void gs_texrender_reset(gs_texrender_t *texrender)
{
	if (texrender)
		texrender->rendered = false;
}

gs_texture_t *gs_texrender_get_texture(const gs_texrender_t *texrender)
{
	return texrender ? texrender->target : NULL;
}

