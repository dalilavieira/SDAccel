#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct wlr_surface {int dummy; } ;
struct wlr_box {int /*<<< orphan*/  height; int /*<<< orphan*/  width; scalar_t__ y; scalar_t__ x; } ;
struct TYPE_9__ {scalar_t__ y; scalar_t__ x; } ;
struct sway_view {TYPE_5__* surface; TYPE_3__ geometry; struct sway_container* container; } ;
struct sway_output {int /*<<< orphan*/  wlr_output; } ;
struct TYPE_8__ {scalar_t__ content_y; scalar_t__ content_x; } ;
struct sway_container {TYPE_2__ current; } ;
struct TYPE_12__ {TYPE_1__* outputs; int /*<<< orphan*/  output_layout; } ;
struct TYPE_10__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct TYPE_11__ {TYPE_4__ current; } ;
struct TYPE_7__ {int length; struct sway_output** items; } ;

/* Variables and functions */
 int /*<<< orphan*/  output_damage_box (struct sway_output*,struct wlr_box*) ; 
 int /*<<< orphan*/  output_damage_surface (struct sway_output*,scalar_t__,scalar_t__,struct wlr_surface*,int) ; 
 int /*<<< orphan*/  output_damage_whole_container (struct sway_output*,struct sway_container*) ; 
 TYPE_6__* root ; 
 struct wlr_box* wlr_output_layout_get_box (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void desktop_damage_surface(struct wlr_surface *surface, double lx, double ly,
		bool whole) {
	for (int i = 0; i < root->outputs->length; ++i) {
		struct sway_output *output = root->outputs->items[i];
		struct wlr_box *output_box = wlr_output_layout_get_box(
			root->output_layout, output->wlr_output);
		output_damage_surface(output, lx - output_box->x,
			ly - output_box->y, surface, whole);
	}
}

void desktop_damage_whole_container(struct sway_container *con) {
	for (int i = 0; i < root->outputs->length; ++i) {
		struct sway_output *output = root->outputs->items[i];
		output_damage_whole_container(output, con);
	}
}

void desktop_damage_box(struct wlr_box *box) {
	for (int i = 0; i < root->outputs->length; ++i) {
		struct sway_output *output = root->outputs->items[i];
		output_damage_box(output, box);
	}
}

void desktop_damage_view(struct sway_view *view) {
	desktop_damage_whole_container(view->container);
	struct wlr_box box = {
		.x = view->container->current.content_x - view->geometry.x,
		.y = view->container->current.content_y - view->geometry.y,
		.width = view->surface->current.width,
		.height = view->surface->current.height,
	};
	desktop_damage_box(&box);
}

