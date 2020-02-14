#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_18__ {size_t num; struct cached_cursor* array; } ;
struct TYPE_17__ {long x; long y; } ;
struct cursor_data {scalar_t__ last_cx; scalar_t__ last_cy; long x_hotspot; long y_hotspot; int visible; scalar_t__ current_cursor; TYPE_6__ cached_textures; int /*<<< orphan*/ * texture; TYPE_4__ cursor_pos; } ;
struct cached_cursor {scalar_t__ cx; scalar_t__ cy; int /*<<< orphan*/ * texture; } ;
typedef  int /*<<< orphan*/  gs_texture_t ;
typedef  int /*<<< orphan*/  ci ;
struct TYPE_16__ {int bmHeight; int bmWidth; int bmBitsPixel; long bmWidthBytes; } ;
struct TYPE_15__ {int cbSize; scalar_t__ hCursor; int flags; int /*<<< orphan*/  ptScreenPos; int /*<<< orphan*/  member_0; } ;
struct TYPE_14__ {long xHotspot; long yHotspot; int /*<<< orphan*/  hbmMask; int /*<<< orphan*/  hbmColor; } ;
typedef  TYPE_1__ ICONINFO ;
typedef  int /*<<< orphan*/  HICON ;
typedef  int /*<<< orphan*/  HBITMAP ;
typedef  TYPE_2__ CURSORINFO ;
typedef  TYPE_3__ BITMAP ;

/* Variables and functions */
 int CURSOR_SHOWING ; 
 int /*<<< orphan*/  CopyIcon (scalar_t__) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DestroyIcon (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GS_BGRA ; 
 int /*<<< orphan*/  GS_BLEND_INVSRCALPHA ; 
 int /*<<< orphan*/  GS_BLEND_SRCALPHA ; 
 int /*<<< orphan*/  GS_DYNAMIC ; 
 int /*<<< orphan*/  GetBitmapBits (int /*<<< orphan*/ ,unsigned int,int*) ; 
 int /*<<< orphan*/  GetCursorInfo (TYPE_2__*) ; 
 int /*<<< orphan*/  GetIconInfo (int /*<<< orphan*/ ,TYPE_1__*) ; 
 scalar_t__ GetObject (int /*<<< orphan*/ ,int,TYPE_3__*) ; 
 int /*<<< orphan*/  bfree (int*) ; 
 int* bmalloc (unsigned int) ; 
 int* bzalloc (long) ; 
 int /*<<< orphan*/  da_free (TYPE_6__) ; 
 int /*<<< orphan*/  da_push_back (TYPE_6__,struct cached_cursor*) ; 
 int /*<<< orphan*/  gs_blend_function (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gs_blend_state_pop () ; 
 int /*<<< orphan*/  gs_blend_state_push () ; 
 int /*<<< orphan*/  gs_enable_color (int,int,int,int) ; 
 int /*<<< orphan*/  gs_matrix_pop () ; 
 int /*<<< orphan*/  gs_matrix_push () ; 
 int /*<<< orphan*/  gs_matrix_scale3f (float,float,float) ; 
 int /*<<< orphan*/ * gs_texture_create (scalar_t__,scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gs_texture_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gs_texture_set_image (int /*<<< orphan*/ *,int*,scalar_t__,int) ; 
 int /*<<< orphan*/  memcpy (TYPE_4__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (struct cursor_data*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  obs_source_draw (int /*<<< orphan*/ *,long,long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static uint8_t *get_bitmap_data(HBITMAP hbmp, BITMAP *bmp)
{
	if (GetObject(hbmp, sizeof(*bmp), bmp) != 0) {
		uint8_t *output;
		unsigned int size =
			(bmp->bmHeight * bmp->bmWidth * bmp->bmBitsPixel) / 8;

		output = bmalloc(size);
		GetBitmapBits(hbmp, size, output);
		return output;
	}

	return NULL;
}

__attribute__((used)) static inline uint8_t bit_to_alpha(uint8_t *data, long pixel, bool invert)
{
	uint8_t pix_byte = data[pixel / 8];
	bool alpha = (pix_byte >> (7 - pixel % 8) & 1) != 0;

	if (invert) {
		return alpha ? 0xFF : 0;
	} else {
		return alpha ? 0 : 0xFF;
	}
}

__attribute__((used)) static inline bool bitmap_has_alpha(uint8_t *data, long num_pixels)
{
	for (long i = 0; i < num_pixels; i++) {
		if (data[i * 4 + 3] != 0) {
			return true;
		}
	}

	return false;
}

__attribute__((used)) static inline void apply_mask(uint8_t *color, uint8_t *mask, long num_pixels)
{
	for (long i = 0; i < num_pixels; i++)
		color[i * 4 + 3] = bit_to_alpha(mask, i, false);
}

__attribute__((used)) static inline uint8_t *copy_from_color(ICONINFO *ii, uint32_t *width,
		uint32_t *height)
{
	BITMAP bmp_color;
	BITMAP bmp_mask;
	uint8_t *color;
	uint8_t *mask;

	color = get_bitmap_data(ii->hbmColor, &bmp_color);
	if (!color) {
		return NULL;
	}

	if (bmp_color.bmBitsPixel < 32) {
		bfree(color);
		return NULL;
	}

	mask = get_bitmap_data(ii->hbmMask, &bmp_mask);
	if (mask) {
		long pixels = bmp_color.bmHeight * bmp_color.bmWidth;

		if (!bitmap_has_alpha(color, pixels))
			apply_mask(color, mask, pixels);

		bfree(mask);
	}

	*width = bmp_color.bmWidth;
	*height = bmp_color.bmHeight;
	return color;
}

__attribute__((used)) static inline uint8_t *copy_from_mask(ICONINFO *ii, uint32_t *width,
		uint32_t *height)
{
	uint8_t *output;
	uint8_t *mask;
	long pixels;
	long bottom;
	BITMAP bmp;

	mask = get_bitmap_data(ii->hbmMask, &bmp);
	if (!mask) {
		return NULL;
	}

	bmp.bmHeight /= 2;

	pixels = bmp.bmHeight * bmp.bmWidth;
	output = bzalloc(pixels * 4);

	bottom = bmp.bmWidthBytes * bmp.bmHeight;

	for (long i = 0; i < pixels; i++) {
		uint8_t alpha = bit_to_alpha(mask, i, false);
		uint8_t color = bit_to_alpha(mask + bottom, i, true);

		if (!alpha) {
			output[i * 4 + 3] = color;
		} else {
			*(uint32_t*)&output[i * 4] = !!color ?
				0xFFFFFFFF : 0xFF000000;
		}
	}

	bfree(mask);

	*width = bmp.bmWidth;
	*height = bmp.bmHeight;
	return output;
}

__attribute__((used)) static inline uint8_t *cursor_capture_icon_bitmap(ICONINFO *ii,
		uint32_t *width, uint32_t *height)
{
	uint8_t *output;

	output = copy_from_color(ii, width, height);
	if (!output)
		output = copy_from_mask(ii, width, height);

	return output;
}

__attribute__((used)) static gs_texture_t *get_cached_texture(struct cursor_data *data,
		uint32_t cx, uint32_t cy)
{
	struct cached_cursor cc;

	for (size_t i = 0; i < data->cached_textures.num; i++) {
		struct cached_cursor *pcc = &data->cached_textures.array[i];

		if (pcc->cx == cx && pcc->cy == cy)
			return pcc->texture;
	}

	cc.texture = gs_texture_create(cx, cy, GS_BGRA, 1, NULL, GS_DYNAMIC);
	cc.cx = cx;
	cc.cy = cy;
	da_push_back(data->cached_textures, &cc);
	return cc.texture;
}

__attribute__((used)) static inline bool cursor_capture_icon(struct cursor_data *data, HICON icon)
{
	uint8_t *bitmap;
	uint32_t height;
	uint32_t width;
	ICONINFO ii;

	if (!icon) {
		return false;
	}
	if (!GetIconInfo(icon, &ii)) {
		return false;
	}

	bitmap = cursor_capture_icon_bitmap(&ii, &width, &height);
	if (bitmap) {
		if (data->last_cx != width || data->last_cy != height) {
			data->texture = get_cached_texture(data, width, height);
			data->last_cx = width;
			data->last_cy = height;
		}
		gs_texture_set_image(data->texture, bitmap, width * 4, false);
		bfree(bitmap);

		data->x_hotspot = ii.xHotspot;
		data->y_hotspot = ii.yHotspot;
	}

	DeleteObject(ii.hbmColor);
	DeleteObject(ii.hbmMask);
	return !!data->texture;
}

void cursor_capture(struct cursor_data *data)
{
	CURSORINFO ci = {0};
	HICON icon;

	ci.cbSize = sizeof(ci);

	if (!GetCursorInfo(&ci)) {
		data->visible = false;
		return;
	}

	memcpy(&data->cursor_pos, &ci.ptScreenPos, sizeof(data->cursor_pos));

	if (data->current_cursor == ci.hCursor) {
		return;
	}

	icon = CopyIcon(ci.hCursor);
	data->visible = cursor_capture_icon(data, icon);
	data->current_cursor = ci.hCursor;
	if ((ci.flags & CURSOR_SHOWING) == 0)
		data->visible = false;
	DestroyIcon(icon);
}

void cursor_draw(struct cursor_data *data, long x_offset, long y_offset,
		float x_scale, float y_scale, long width, long height)
{
	long x = data->cursor_pos.x + x_offset;
	long y = data->cursor_pos.y + y_offset;
	long x_draw = x - data->x_hotspot;
	long y_draw = y - data->y_hotspot;

	if (x < 0 || x > width || y < 0 || y > height)
		return;

	if (data->visible && !!data->texture) {
		gs_blend_state_push();
		gs_blend_function(GS_BLEND_SRCALPHA, GS_BLEND_INVSRCALPHA);
		gs_enable_color(true, true, true, false);

		gs_matrix_push();
		gs_matrix_scale3f(x_scale, y_scale, 1.0f);
		obs_source_draw(data->texture, x_draw, y_draw, 0, 0, false);
		gs_matrix_pop();

		gs_enable_color(true, true, true, true);
		gs_blend_state_pop();
	}
}

void cursor_data_free(struct cursor_data *data)
{
	for (size_t i = 0; i < data->cached_textures.num; i++) {
		struct cached_cursor *pcc = &data->cached_textures.array[i];
		gs_texture_destroy(pcc->texture);
	}
	da_free(data->cached_textures);
	memset(data, 0, sizeof(*data));
}

