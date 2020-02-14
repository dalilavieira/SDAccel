#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  xcb_xfixes_query_version_cookie_t ;
struct TYPE_14__ {int width; scalar_t__ height; scalar_t__ cursor_serial; int x; int y; int xhot; int yhot; } ;
typedef  TYPE_1__ xcb_xfixes_get_cursor_image_reply_t ;
struct TYPE_15__ {int last_height; scalar_t__ last_width; scalar_t__ last_serial; int x; int x_org; int y; int y_org; int x_render; int y_render; scalar_t__ tex; } ;
typedef  TYPE_2__ xcb_xcursor_t ;
typedef  int /*<<< orphan*/  xcb_connection_t ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  gs_eparam_t ;
typedef  int /*<<< orphan*/  gs_effect_t ;

/* Variables and functions */
 int /*<<< orphan*/  GS_BGRA ; 
 int /*<<< orphan*/  GS_BLEND_INVSRCALPHA ; 
 int /*<<< orphan*/  GS_BLEND_SRCALPHA ; 
 int /*<<< orphan*/  GS_DYNAMIC ; 
 int /*<<< orphan*/  XCB_XFIXES_MAJOR_VERSION ; 
 int /*<<< orphan*/  XCB_XFIXES_MINOR_VERSION ; 
 int /*<<< orphan*/  bfree (TYPE_2__*) ; 
 TYPE_2__* bzalloc (int) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gs_blend_function (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gs_blend_state_pop () ; 
 int /*<<< orphan*/  gs_blend_state_push () ; 
 int /*<<< orphan*/  gs_draw_sprite (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * gs_effect_get_param_by_name (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  gs_effect_set_texture (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  gs_enable_color (int,int,int,int) ; 
 int /*<<< orphan*/ * gs_get_effect () ; 
 int /*<<< orphan*/  gs_matrix_pop () ; 
 int /*<<< orphan*/  gs_matrix_push () ; 
 int /*<<< orphan*/  gs_matrix_translate3f (int,int,float) ; 
 scalar_t__ gs_texture_create (int,scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/  const**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gs_texture_destroy (scalar_t__) ; 
 int /*<<< orphan*/  gs_texture_set_image (scalar_t__,int /*<<< orphan*/  const*,int,int) ; 
 int /*<<< orphan*/ * xcb_xfixes_get_cursor_image_cursor_image (TYPE_1__*) ; 
 int /*<<< orphan*/  xcb_xfixes_query_version_reply (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xcb_xfixes_query_version_unchecked (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xcb_xcursor_create(xcb_xcursor_t *data,
		xcb_xfixes_get_cursor_image_reply_t *xc)
{
	uint32_t *pixels = xcb_xfixes_get_cursor_image_cursor_image(xc);
	if (!pixels)
		return;

	if (data->tex && data->last_height == xc->width &&
			data->last_width == xc->height) {
		gs_texture_set_image(data->tex, (const uint8_t *) pixels,
			xc->width * sizeof(uint32_t), false);
	} else {
		if (data->tex)
			gs_texture_destroy(data->tex);

		data->tex = gs_texture_create(xc->width, xc->height,
			GS_BGRA, 1, (const uint8_t **) &pixels, GS_DYNAMIC);
	}

	data->last_serial = xc->cursor_serial;
	data->last_width  = xc->width;
	data->last_height = xc->height;
}

xcb_xcursor_t *xcb_xcursor_init(xcb_connection_t *xcb)
{
	xcb_xcursor_t *data = bzalloc(sizeof(xcb_xcursor_t));

	xcb_xfixes_query_version_cookie_t xfix_c;

	xfix_c = xcb_xfixes_query_version_unchecked(xcb,
			XCB_XFIXES_MAJOR_VERSION, XCB_XFIXES_MINOR_VERSION);
	free(xcb_xfixes_query_version_reply(xcb, xfix_c, NULL));

	return data;
}

void xcb_xcursor_destroy(xcb_xcursor_t *data)
{
	if (data->tex)
		gs_texture_destroy(data->tex);
	bfree(data);
}

void xcb_xcursor_update(xcb_xcursor_t *data,
		xcb_xfixes_get_cursor_image_reply_t *xc)
{
	if (!data || !xc)
		return;

	if (!data->tex || data->last_serial != xc->cursor_serial)
		xcb_xcursor_create(data, xc);

	data->x        = xc->x - data->x_org;
	data->y        = xc->y - data->y_org;
	data->x_render = data->x - xc->xhot;
	data->y_render = data->y - xc->yhot;
}

void xcb_xcursor_render(xcb_xcursor_t *data)
{
	if (!data->tex)
		return;

	gs_effect_t *effect  = gs_get_effect();
	gs_eparam_t *image = gs_effect_get_param_by_name(effect, "image");
	gs_effect_set_texture(image, data->tex);

	gs_blend_state_push();
	gs_blend_function(GS_BLEND_SRCALPHA, GS_BLEND_INVSRCALPHA);
	gs_enable_color(true, true, true, false);

	gs_matrix_push();
	gs_matrix_translate3f(data->x_render, data->y_render, 0.0f);
	gs_draw_sprite(data->tex, 0, 0, 0);
	gs_matrix_pop();

	gs_enable_color(true, true, true, true);
	gs_blend_state_pop();
}

void xcb_xcursor_offset(xcb_xcursor_t* data, const int x_org, const int y_org)
{
	data->x_org = x_org;
	data->y_org = y_org;
}

