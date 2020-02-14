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
struct wlr_input_device {int dummy; } ;
struct sway_seat {int /*<<< orphan*/  wlr_seat; TYPE_1__* cursor; struct seatop_move_floating_event* seatop_data; int /*<<< orphan*/ * seatop_impl; } ;
struct sway_container {int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct seatop_move_floating_event {struct sway_container* con; } ;
typedef  enum wlr_button_state { ____Placeholder_wlr_button_state } wlr_button_state ;
struct TYPE_2__ {scalar_t__ pressed_button_count; } ;

/* Variables and functions */
 struct seatop_move_floating_event* calloc (int,int) ; 
 int /*<<< orphan*/  container_floating_move_to (struct sway_container*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  container_floating_translate (struct sway_container*,double,double) ; 
 int /*<<< orphan*/  container_raise_floating (struct sway_container*) ; 
 int /*<<< orphan*/  cursor_set_image (TYPE_1__*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  desktop_damage_whole_container (struct sway_container*) ; 
 int /*<<< orphan*/  seatop_begin_default (struct sway_seat*) ; 
 int /*<<< orphan*/  seatop_end (struct sway_seat*) ; 
 int /*<<< orphan*/  seatop_impl ; 
 int /*<<< orphan*/  wlr_seat_pointer_clear_focus (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void handle_button(struct sway_seat *seat, uint32_t time_msec,
		struct wlr_input_device *device, uint32_t button,
		enum wlr_button_state state) {
	if (seat->cursor->pressed_button_count == 0) {
		struct seatop_move_floating_event *e = seat->seatop_data;

		// We "move" the container to its own location
		// so it discovers its output again.
		container_floating_move_to(e->con, e->con->x, e->con->y);

		seatop_begin_default(seat);
	}
}

__attribute__((used)) static void handle_motion(struct sway_seat *seat, uint32_t time_msec,
		double dx, double dy) {
	struct seatop_move_floating_event *e = seat->seatop_data;
	desktop_damage_whole_container(e->con);
	container_floating_translate(e->con, dx, dy);
	desktop_damage_whole_container(e->con);
}

__attribute__((used)) static void handle_unref(struct sway_seat *seat, struct sway_container *con) {
	struct seatop_move_floating_event *e = seat->seatop_data;
	if (e->con == con) {
		seatop_begin_default(seat);
	}
}

void seatop_begin_move_floating(struct sway_seat *seat,
		struct sway_container *con) {
	seatop_end(seat);

	struct seatop_move_floating_event *e =
		calloc(1, sizeof(struct seatop_move_floating_event));
	if (!e) {
		return;
	}
	e->con = con;

	seat->seatop_impl = &seatop_impl;
	seat->seatop_data = e;

	container_raise_floating(con);

	cursor_set_image(seat->cursor, "grab", NULL);
	wlr_seat_pointer_clear_focus(seat->wlr_seat);
}

