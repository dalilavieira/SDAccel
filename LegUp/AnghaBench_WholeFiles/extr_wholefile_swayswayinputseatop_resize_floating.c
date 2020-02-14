#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct wlr_keyboard {int dummy; } ;
struct wlr_input_device {int dummy; } ;
struct sway_seat {int /*<<< orphan*/  wlr_seat; struct sway_cursor* cursor; struct seatop_resize_floating_event* seatop_data; int /*<<< orphan*/ * seatop_impl; } ;
struct sway_cursor {scalar_t__ pressed_button_count; TYPE_1__* cursor; } ;
struct sway_container {double width; double height; int x; int y; int content_x; int content_y; int content_width; int content_height; scalar_t__ view; } ;
struct seatop_resize_floating_event {int edge; double ref_lx; double ref_ly; double ref_width; double ref_height; int ref_con_lx; int ref_con_ly; scalar_t__ preserve_ratio; struct sway_container* con; } ;
typedef  enum wlr_edges { ____Placeholder_wlr_edges } wlr_edges ;
typedef  enum wlr_button_state { ____Placeholder_wlr_button_state } wlr_button_state ;
struct TYPE_2__ {double x; double y; } ;

/* Variables and functions */
 int WLR_EDGE_BOTTOM ; 
 int WLR_EDGE_LEFT ; 
 int WLR_EDGE_NONE ; 
 int WLR_EDGE_RIGHT ; 
 int WLR_EDGE_TOP ; 
 int WLR_MODIFIER_SHIFT ; 
 int /*<<< orphan*/  arrange_container (struct sway_container*) ; 
 struct seatop_resize_floating_event* calloc (int,int) ; 
 int /*<<< orphan*/  container_raise_floating (struct sway_container*) ; 
 int /*<<< orphan*/  cursor_set_image (struct sway_cursor*,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  floating_calculate_constraints (int*,int*,int*,int*) ; 
 double fmax (double,double) ; 
 double fmin (double,double) ; 
 int /*<<< orphan*/  seatop_begin_default (struct sway_seat*) ; 
 int /*<<< orphan*/  seatop_end (struct sway_seat*) ; 
 int /*<<< orphan*/  seatop_impl ; 
 int /*<<< orphan*/  view_get_constraints (scalar_t__,double*,double*,double*,double*) ; 
 int wlr_keyboard_get_modifiers (struct wlr_keyboard*) ; 
 struct wlr_keyboard* wlr_seat_get_keyboard (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wlr_seat_pointer_clear_focus (int /*<<< orphan*/ ) ; 
 char* wlr_xcursor_get_resize_name (int) ; 

__attribute__((used)) static void handle_button(struct sway_seat *seat, uint32_t time_msec,
		struct wlr_input_device *device, uint32_t button,
		enum wlr_button_state state) {
	if (seat->cursor->pressed_button_count == 0) {
		seatop_begin_default(seat);
	}
}

__attribute__((used)) static void handle_motion(struct sway_seat *seat, uint32_t time_msec,
		double dx, double dy) {
	struct seatop_resize_floating_event *e = seat->seatop_data;
	struct sway_container *con = e->con;
	enum wlr_edges edge = e->edge;
	struct sway_cursor *cursor = seat->cursor;

	// The amount the mouse has moved since the start of the resize operation
	// Positive is down/right
	double mouse_move_x = cursor->cursor->x - e->ref_lx;
	double mouse_move_y = cursor->cursor->y - e->ref_ly;

	if (edge == WLR_EDGE_TOP || edge == WLR_EDGE_BOTTOM) {
		mouse_move_x = 0;
	}
	if (edge == WLR_EDGE_LEFT || edge == WLR_EDGE_RIGHT) {
		mouse_move_y = 0;
	}

	double grow_width = edge & WLR_EDGE_LEFT ? -mouse_move_x : mouse_move_x;
	double grow_height = edge & WLR_EDGE_TOP ? -mouse_move_y : mouse_move_y;

	if (e->preserve_ratio) {
		double x_multiplier = grow_width / e->ref_width;
		double y_multiplier = grow_height / e->ref_height;
		double max_multiplier = fmax(x_multiplier, y_multiplier);
		grow_width = e->ref_width * max_multiplier;
		grow_height = e->ref_height * max_multiplier;
	}

	// Determine new width/height, and accommodate for floating min/max values
	double width = e->ref_width + grow_width;
	double height = e->ref_height + grow_height;
	int min_width, max_width, min_height, max_height;
	floating_calculate_constraints(&min_width, &max_width,
			&min_height, &max_height);
	width = fmax(min_width, fmin(width, max_width));
	height = fmax(min_height, fmin(height, max_height));

	// Apply the view's min/max size
	if (con->view) {
		double view_min_width, view_max_width, view_min_height, view_max_height;
		view_get_constraints(con->view, &view_min_width, &view_max_width,
				&view_min_height, &view_max_height);
		width = fmax(view_min_width, fmin(width, view_max_width));
		height = fmax(view_min_height, fmin(height, view_max_height));
	}

	// Recalculate these, in case we hit a min/max limit
	grow_width = width - e->ref_width;
	grow_height = height - e->ref_height;

	// Determine grow x/y values - these are relative to the container's x/y at
	// the start of the resize operation.
	double grow_x = 0, grow_y = 0;
	if (edge & WLR_EDGE_LEFT) {
		grow_x = -grow_width;
	} else if (edge & WLR_EDGE_RIGHT) {
		grow_x = 0;
	} else {
		grow_x = -grow_width / 2;
	}
	if (edge & WLR_EDGE_TOP) {
		grow_y = -grow_height;
	} else if (edge & WLR_EDGE_BOTTOM) {
		grow_y = 0;
	} else {
		grow_y = -grow_height / 2;
	}

	// Determine the amounts we need to bump everything relative to the current
	// size.
	int relative_grow_width = width - con->width;
	int relative_grow_height = height - con->height;
	int relative_grow_x = (e->ref_con_lx + grow_x) - con->x;
	int relative_grow_y = (e->ref_con_ly + grow_y) - con->y;

	// Actually resize stuff
	con->x += relative_grow_x;
	con->y += relative_grow_y;
	con->width += relative_grow_width;
	con->height += relative_grow_height;

	con->content_x += relative_grow_x;
	con->content_y += relative_grow_y;
	con->content_width += relative_grow_width;
	con->content_height += relative_grow_height;

	arrange_container(con);
}

__attribute__((used)) static void handle_unref(struct sway_seat *seat, struct sway_container *con) {
	struct seatop_resize_floating_event *e = seat->seatop_data;
	if (e->con == con) {
		seatop_begin_default(seat);
	}
}

void seatop_begin_resize_floating(struct sway_seat *seat,
		struct sway_container *con, enum wlr_edges edge) {
	seatop_end(seat);

	struct seatop_resize_floating_event *e =
		calloc(1, sizeof(struct seatop_resize_floating_event));
	if (!e) {
		return;
	}
	e->con = con;

	struct wlr_keyboard *keyboard = wlr_seat_get_keyboard(seat->wlr_seat);
	e->preserve_ratio = keyboard &&
		(wlr_keyboard_get_modifiers(keyboard) & WLR_MODIFIER_SHIFT);

	e->edge = edge == WLR_EDGE_NONE ? WLR_EDGE_BOTTOM | WLR_EDGE_RIGHT : edge;
	e->ref_lx = seat->cursor->cursor->x;
	e->ref_ly = seat->cursor->cursor->y;
	e->ref_con_lx = con->x;
	e->ref_con_ly = con->y;
	e->ref_width = con->width;
	e->ref_height = con->height;

	seat->seatop_impl = &seatop_impl;
	seat->seatop_data = e;

	container_raise_floating(con);

	const char *image = edge == WLR_EDGE_NONE ?
		"se-resize" : wlr_xcursor_get_resize_name(edge);
	cursor_set_image(seat->cursor, image, NULL);
	wlr_seat_pointer_clear_focus(seat->wlr_seat);
}

