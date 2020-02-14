#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct swaynag_button {int x; int y; int width; int height; int /*<<< orphan*/  text; } ;
struct TYPE_8__ {int x; int y; int width; int height; scalar_t__ visible; struct swaynag_button button_down; struct swaynag_button button_up; void* visible_lines; int /*<<< orphan*/  offset; void* total_lines; int /*<<< orphan*/  message; } ;
struct swaynag {int scale; scalar_t__ height; scalar_t__ width; int /*<<< orphan*/  display; int /*<<< orphan*/  surface; TYPE_6__* current_buffer; int /*<<< orphan*/  buffers; int /*<<< orphan*/  shm; int /*<<< orphan*/  layer_surface; int /*<<< orphan*/  run_display; TYPE_3__* type; TYPE_2__ details; TYPE_1__* buttons; int /*<<< orphan*/  message; } ;
typedef  int gint ;
typedef  int /*<<< orphan*/  cairo_t ;
typedef  int /*<<< orphan*/  cairo_surface_t ;
struct TYPE_11__ {int /*<<< orphan*/  buffer; int /*<<< orphan*/ * cairo; } ;
struct TYPE_10__ {int start_index; } ;
struct TYPE_9__ {int message_padding; int button_border_thickness; int button_padding; int details_border_thickness; int button_margin_right; int button_gap; int button_gap_close; int bar_border_thickness; int /*<<< orphan*/  border_bottom; int /*<<< orphan*/  background; int /*<<< orphan*/  font; int /*<<< orphan*/  text; int /*<<< orphan*/  button_background; int /*<<< orphan*/  border; } ;
struct TYPE_7__ {int length; struct swaynag_button** items; } ;
typedef  TYPE_4__ PangoLayoutLine ;
typedef  int /*<<< orphan*/  PangoLayout ;

/* Variables and functions */
 int /*<<< orphan*/  CAIRO_CONTENT_COLOR_ALPHA ; 
 int /*<<< orphan*/  CAIRO_OPERATOR_CLEAR ; 
 int /*<<< orphan*/  CAIRO_OPERATOR_SOURCE ; 
 int /*<<< orphan*/  PANGO_ELLIPSIZE_END ; 
 int PANGO_SCALE ; 
 int /*<<< orphan*/  PANGO_WRAP_WORD_CHAR ; 
 scalar_t__ SWAYNAG_MAX_HEIGHT ; 
 int /*<<< orphan*/  SWAY_DEBUG ; 
 int /*<<< orphan*/ * cairo_create (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cairo_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cairo_fill (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cairo_move_to (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  cairo_paint (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * cairo_recording_surface_create (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cairo_rectangle (int /*<<< orphan*/ *,int,int,int,int) ; 
 int /*<<< orphan*/  cairo_restore (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cairo_save (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cairo_set_operator (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cairo_set_source_surface (int /*<<< orphan*/ *,int /*<<< orphan*/ *,double,double) ; 
 int /*<<< orphan*/  cairo_set_source_u32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cairo_surface_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_object_unref (int /*<<< orphan*/ *) ; 
 TYPE_6__* get_next_buffer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/ * get_pango_layout (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int) ; 
 int /*<<< orphan*/  get_text_size (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*,int*,int /*<<< orphan*/ *,int,int,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pango_cairo_show_layout (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pango_cairo_update_layout (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* pango_layout_get_line_count (int /*<<< orphan*/ *) ; 
 TYPE_4__* pango_layout_get_line_readonly (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pango_layout_get_pixel_size (int /*<<< orphan*/ *,int*,int*) ; 
 char* pango_layout_get_text (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pango_layout_set_ellipsize (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pango_layout_set_height (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pango_layout_set_single_paragraph_mode (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pango_layout_set_text (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  pango_layout_set_width (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pango_layout_set_wrap (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pango_printf (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__,int,char*,int /*<<< orphan*/ ) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  wl_display_roundtrip (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_surface_attach (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_surface_commit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_surface_damage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  wl_surface_set_buffer_scale (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  zwlr_layer_surface_v1_set_exclusive_zone (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  zwlr_layer_surface_v1_set_size (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static uint32_t render_message(cairo_t *cairo, struct swaynag *swaynag) {
	int text_width, text_height;
	get_text_size(cairo, swaynag->type->font, &text_width, &text_height, NULL,
			swaynag->scale, true, "%s", swaynag->message);

	int padding = swaynag->type->message_padding * swaynag->scale;

	uint32_t ideal_height = text_height + padding * 2;
	uint32_t ideal_surface_height = ideal_height / swaynag->scale;
	if (swaynag->height < ideal_surface_height) {
		return ideal_surface_height;
	}

	cairo_set_source_u32(cairo, swaynag->type->text);
	cairo_move_to(cairo, padding, (int)(ideal_height - text_height) / 2);
	pango_printf(cairo, swaynag->type->font, swaynag->scale, false,
			"%s", swaynag->message);

	return ideal_surface_height;
}

__attribute__((used)) static void render_details_scroll_button(cairo_t *cairo,
		struct swaynag *swaynag, struct swaynag_button *button) {
	int text_width, text_height;
	get_text_size(cairo, swaynag->type->font, &text_width, &text_height, NULL,
			swaynag->scale, true, "%s", button->text);

	int border = swaynag->type->button_border_thickness * swaynag->scale;
	int padding = swaynag->type->button_padding * swaynag->scale;

	cairo_set_source_u32(cairo, swaynag->type->border);
	cairo_rectangle(cairo, button->x, button->y,
			button->width, button->height);
	cairo_fill(cairo);

	cairo_set_source_u32(cairo, swaynag->type->button_background);
	cairo_rectangle(cairo, button->x + border, button->y + border,
			button->width - (border * 2), button->height - (border * 2));
	cairo_fill(cairo);

	cairo_set_source_u32(cairo, swaynag->type->text);
	cairo_move_to(cairo, button->x + border + padding,
			button->y + border + (button->height - text_height) / 2);
	pango_printf(cairo, swaynag->type->font, swaynag->scale, true,
			"%s", button->text);
}

__attribute__((used)) static int get_detailed_scroll_button_width(cairo_t *cairo,
		struct swaynag *swaynag) {
	int up_width, down_width, temp_height;
	get_text_size(cairo, swaynag->type->font, &up_width, &temp_height, NULL,
			swaynag->scale, true,
			"%s", swaynag->details.button_up.text);
	get_text_size(cairo, swaynag->type->font, &down_width, &temp_height, NULL,
			swaynag->scale, true,
			"%s", swaynag->details.button_down.text);

	int text_width =  up_width > down_width ? up_width : down_width;
	int border = swaynag->type->button_border_thickness * swaynag->scale;
	int padding = swaynag->type->button_padding * swaynag->scale;

	return text_width + border * 2 + padding * 2;
}

__attribute__((used)) static uint32_t render_detailed(cairo_t *cairo, struct swaynag *swaynag,
		uint32_t y) {
	uint32_t width = swaynag->width * swaynag->scale;

	int border = swaynag->type->details_border_thickness * swaynag->scale;
	int padding = swaynag->type->message_padding * swaynag->scale;
	int decor = padding + border;

	swaynag->details.x = decor;
	swaynag->details.y = y * swaynag->scale + decor;
	swaynag->details.width = width - decor * 2;

	PangoLayout *layout = get_pango_layout(cairo, swaynag->type->font,
			swaynag->details.message, swaynag->scale, false);
	pango_layout_set_width(layout,
			(swaynag->details.width - padding * 2) * PANGO_SCALE);
	pango_layout_set_wrap(layout, PANGO_WRAP_WORD_CHAR);
	pango_layout_set_single_paragraph_mode(layout, false);
	pango_cairo_update_layout(cairo, layout);
	swaynag->details.total_lines = pango_layout_get_line_count(layout);

	PangoLayoutLine *line;
	line = pango_layout_get_line_readonly(layout, swaynag->details.offset);
	gint offset = line->start_index;
	const char *text = pango_layout_get_text(layout);
	pango_layout_set_text(layout, text + offset, strlen(text) - offset);

	int text_width, text_height;
	pango_cairo_update_layout(cairo, layout);
	pango_layout_get_pixel_size(layout, &text_width, &text_height);

	bool show_buttons = swaynag->details.offset > 0;
	int button_width = get_detailed_scroll_button_width(cairo, swaynag);
	if (show_buttons) {
		swaynag->details.width -= button_width;
		pango_layout_set_width(layout,
				(swaynag->details.width - padding * 2) * PANGO_SCALE);
	}

	uint32_t ideal_height;
	do {
		ideal_height = swaynag->details.y + text_height + decor + padding * 2;
		if (ideal_height > SWAYNAG_MAX_HEIGHT) {
			ideal_height = SWAYNAG_MAX_HEIGHT;

			if (!show_buttons) {
				show_buttons = true;
				swaynag->details.width -= button_width;
				pango_layout_set_width(layout,
						(swaynag->details.width - padding * 2) * PANGO_SCALE);
			}
		}

		swaynag->details.height = ideal_height - swaynag->details.y - decor;
		pango_layout_set_height(layout,
				(swaynag->details.height - padding * 2) * PANGO_SCALE);
		pango_layout_set_ellipsize(layout, PANGO_ELLIPSIZE_END);
		pango_cairo_update_layout(cairo, layout);
		pango_layout_get_pixel_size(layout, &text_width, &text_height);
	} while (text_height != (swaynag->details.height - padding * 2));

	swaynag->details.visible_lines = pango_layout_get_line_count(layout);

	if (show_buttons) {
		swaynag->details.button_up.x =
			swaynag->details.x + swaynag->details.width;
		swaynag->details.button_up.y = swaynag->details.y;
		swaynag->details.button_up.width = button_width;
		swaynag->details.button_up.height = swaynag->details.height / 2;
		render_details_scroll_button(cairo, swaynag,
				&swaynag->details.button_up);

		swaynag->details.button_down.x =
			swaynag->details.x + swaynag->details.width;
		swaynag->details.button_down.y =
			swaynag->details.button_up.y + swaynag->details.button_up.height;
		swaynag->details.button_down.width = button_width;
		swaynag->details.button_down.height = swaynag->details.height / 2;
		render_details_scroll_button(cairo, swaynag,
				&swaynag->details.button_down);
	}

	cairo_set_source_u32(cairo, swaynag->type->border);
	cairo_rectangle(cairo, swaynag->details.x, swaynag->details.y,
			swaynag->details.width, swaynag->details.height);
	cairo_fill(cairo);

	cairo_move_to(cairo, swaynag->details.x + padding,
			swaynag->details.y + padding);
	cairo_set_source_u32(cairo, swaynag->type->text);
	pango_cairo_show_layout(cairo, layout);
	g_object_unref(layout);

	return ideal_height / swaynag->scale;
}

__attribute__((used)) static uint32_t render_button(cairo_t *cairo, struct swaynag *swaynag,
		int button_index, int *x) {
	struct swaynag_button *button = swaynag->buttons->items[button_index];

	int text_width, text_height;
	get_text_size(cairo, swaynag->type->font, &text_width, &text_height, NULL,
			swaynag->scale, true, "%s", button->text);

	int border = swaynag->type->button_border_thickness * swaynag->scale;
	int padding = swaynag->type->button_padding * swaynag->scale;

	uint32_t ideal_height = text_height + padding * 2 + border * 2;
	uint32_t ideal_surface_height = ideal_height / swaynag->scale;
	if (swaynag->height < ideal_surface_height) {
		return ideal_surface_height;
	}

	button->x = *x - border - text_width - padding * 2 + 1;
	button->y = (int)(ideal_height - text_height) / 2 - padding + 1;
	button->width = text_width + padding * 2;
	button->height = text_height + padding * 2;

	cairo_set_source_u32(cairo, swaynag->type->border);
	cairo_rectangle(cairo, button->x - border, button->y - border,
			button->width + border * 2, button->height + border * 2);
	cairo_fill(cairo);

	cairo_set_source_u32(cairo, swaynag->type->button_background);
	cairo_rectangle(cairo, button->x, button->y,
			button->width, button->height);
	cairo_fill(cairo);

	cairo_set_source_u32(cairo, swaynag->type->text);
	cairo_move_to(cairo, button->x + padding, button->y + padding);
	pango_printf(cairo, swaynag->type->font, swaynag->scale, true,
			"%s", button->text);

	*x = button->x - border;

	return ideal_surface_height;
}

__attribute__((used)) static uint32_t render_to_cairo(cairo_t *cairo, struct swaynag *swaynag) {
	uint32_t max_height = 0;

	cairo_set_operator(cairo, CAIRO_OPERATOR_SOURCE);
	cairo_set_source_u32(cairo, swaynag->type->background);
	cairo_paint(cairo);

	uint32_t h = render_message(cairo, swaynag);
	max_height = h > max_height ? h : max_height;

	int x = swaynag->width - swaynag->type->button_margin_right;
	x *= swaynag->scale;
	for (int i = 0; i < swaynag->buttons->length; i++) {
		h = render_button(cairo, swaynag, i, &x);
		max_height = h > max_height ? h : max_height;
		x -= swaynag->type->button_gap * swaynag->scale;
		if (i == 0) {
			x -= swaynag->type->button_gap_close * swaynag->scale;
		}
	}

	if (swaynag->details.visible) {
		h = render_detailed(cairo, swaynag, max_height);
		max_height = h > max_height ? h : max_height;
	}

	int border = swaynag->type->bar_border_thickness * swaynag->scale;
	if (max_height > swaynag->height) {
		max_height += border;
	}
	cairo_set_source_u32(cairo, swaynag->type->border_bottom);
	cairo_rectangle(cairo, 0,
			swaynag->height * swaynag->scale - border,
			swaynag->width * swaynag->scale,
			border);
	cairo_fill(cairo);

	return max_height;
}

void render_frame(struct swaynag *swaynag) {
	if (!swaynag->run_display) {
		return;
	}

	cairo_surface_t *recorder = cairo_recording_surface_create(
			CAIRO_CONTENT_COLOR_ALPHA, NULL);
	cairo_t *cairo = cairo_create(recorder);
	cairo_save(cairo);
	cairo_set_operator(cairo, CAIRO_OPERATOR_CLEAR);
	cairo_paint(cairo);
	cairo_restore(cairo);
	uint32_t height = render_to_cairo(cairo, swaynag);
	if (height != swaynag->height) {
		zwlr_layer_surface_v1_set_size(swaynag->layer_surface, 0, height);
		zwlr_layer_surface_v1_set_exclusive_zone(swaynag->layer_surface,
				height);
		wl_surface_commit(swaynag->surface);
		wl_display_roundtrip(swaynag->display);
	} else {
		swaynag->current_buffer = get_next_buffer(swaynag->shm,
				swaynag->buffers,
				swaynag->width * swaynag->scale,
				swaynag->height * swaynag->scale);
		if (!swaynag->current_buffer) {
			sway_log(SWAY_DEBUG, "Failed to get buffer. Skipping frame.");
			goto cleanup;
		}

		cairo_t *shm = swaynag->current_buffer->cairo;
		cairo_save(shm);
		cairo_set_operator(shm, CAIRO_OPERATOR_CLEAR);
		cairo_paint(shm);
		cairo_restore(shm);
		cairo_set_source_surface(shm, recorder, 0.0, 0.0);
		cairo_paint(shm);

		wl_surface_set_buffer_scale(swaynag->surface, swaynag->scale);
		wl_surface_attach(swaynag->surface,
				swaynag->current_buffer->buffer, 0, 0);
		wl_surface_damage(swaynag->surface, 0, 0,
				swaynag->width, swaynag->height);
		wl_surface_commit(swaynag->surface);
		wl_display_roundtrip(swaynag->display);
	}

cleanup:
	cairo_surface_destroy(recorder);
	cairo_destroy(cairo);
}

