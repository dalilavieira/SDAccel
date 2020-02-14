#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct wlr_input_device {int dummy; } ;
struct sway_seat {struct seatop_down_event* seatop_data; int /*<<< orphan*/ * seatop_impl; TYPE_3__* cursor; int /*<<< orphan*/  wlr_seat; } ;
struct sway_container {TYPE_1__* view; } ;
struct seatop_down_event {double ref_lx; double ref_ly; double ref_con_lx; double ref_con_ly; struct sway_container* con; } ;
typedef  enum wlr_button_state { ____Placeholder_wlr_button_state } wlr_button_state ;
struct TYPE_6__ {scalar_t__ pressed_button_count; TYPE_2__* cursor; } ;
struct TYPE_5__ {double x; double y; } ;
struct TYPE_4__ {int /*<<< orphan*/  surface; } ;

/* Variables and functions */
 struct seatop_down_event* calloc (int,int) ; 
 int /*<<< orphan*/  container_raise_floating (struct sway_container*) ; 
 scalar_t__ seat_is_input_allowed (struct sway_seat*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seat_pointer_notify_button (struct sway_seat*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  seatop_begin_default (struct sway_seat*) ; 
 int /*<<< orphan*/  seatop_end (struct sway_seat*) ; 
 int /*<<< orphan*/  seatop_impl ; 
 int /*<<< orphan*/  wlr_seat_pointer_notify_motion (int /*<<< orphan*/ ,int /*<<< orphan*/ ,double,double) ; 

__attribute__((used)) static void handle_button(struct sway_seat *seat, uint32_t time_msec,
		struct wlr_input_device *device, uint32_t button,
		enum wlr_button_state state) {
	seat_pointer_notify_button(seat, time_msec, button, state);

	if (seat->cursor->pressed_button_count == 0) {
		seatop_begin_default(seat);
	}
}

__attribute__((used)) static void handle_motion(struct sway_seat *seat, uint32_t time_msec,
		double dx, double dy) {
	struct seatop_down_event *e = seat->seatop_data;
	struct sway_container *con = e->con;
	if (seat_is_input_allowed(seat, con->view->surface)) {
		double moved_x = seat->cursor->cursor->x - e->ref_lx;
		double moved_y = seat->cursor->cursor->y - e->ref_ly;
		double sx = e->ref_con_lx + moved_x;
		double sy = e->ref_con_ly + moved_y;
		wlr_seat_pointer_notify_motion(seat->wlr_seat, time_msec, sx, sy);
	}
}

__attribute__((used)) static void handle_unref(struct sway_seat *seat, struct sway_container *con) {
	struct seatop_down_event *e = seat->seatop_data;
	if (e->con == con) {
		seatop_begin_default(seat);
	}
}

void seatop_begin_down(struct sway_seat *seat, struct sway_container *con,
		uint32_t time_msec, int sx, int sy) {
	seatop_end(seat);

	struct seatop_down_event *e =
		calloc(1, sizeof(struct seatop_down_event));
	if (!e) {
		return;
	}
	e->con = con;
	e->ref_lx = seat->cursor->cursor->x;
	e->ref_ly = seat->cursor->cursor->y;
	e->ref_con_lx = sx;
	e->ref_con_ly = sy;

	seat->seatop_impl = &seatop_impl;
	seat->seatop_data = e;

	container_raise_floating(con);
}

