#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
struct wlr_output {int dummy; } ;
struct sway_node {scalar_t__ type; struct sway_container* sway_container; } ;
struct sway_workspace {int layout; struct sway_output* output; struct sway_node node; TYPE_2__* tiling; TYPE_1__* fullscreen; } ;
struct sway_seat {int dummy; } ;
struct sway_output {int lx; int width; int ly; int height; int /*<<< orphan*/  node; int /*<<< orphan*/  wlr_output; } ;
struct sway_container {scalar_t__ fullscreen_mode; int x; int width; int y; int height; struct sway_node node; TYPE_4__* workspace; struct sway_container* parent; } ;
struct cmd_results {int dummy; } ;
struct TYPE_18__ {int length; struct sway_container** items; } ;
typedef  TYPE_7__ list_t ;
typedef  enum wlr_direction { ____Placeholder_wlr_direction } wlr_direction ;
typedef  enum sway_container_layout { ____Placeholder_sway_container_layout } sway_container_layout ;
struct TYPE_19__ {TYPE_5__* outputs; int /*<<< orphan*/  output_layout; } ;
struct TYPE_17__ {struct sway_seat* seat; struct sway_workspace* workspace; struct sway_container* container; struct sway_node* node; } ;
struct TYPE_16__ {int /*<<< orphan*/  length; } ;
struct TYPE_15__ {TYPE_3__* floating; struct sway_output* output; } ;
struct TYPE_14__ {int length; struct sway_container** items; } ;
struct TYPE_13__ {scalar_t__ length; struct sway_container** items; } ;
struct TYPE_12__ {int /*<<< orphan*/  node; } ;
struct TYPE_11__ {scalar_t__ focus_wrapping; TYPE_6__ handler_context; int /*<<< orphan*/  active; scalar_t__ reading; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_DEFER ; 
 int /*<<< orphan*/  CMD_FAILURE ; 
 int /*<<< orphan*/  CMD_INVALID ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 double DBL_MAX ; 
 scalar_t__ FULLSCREEN_GLOBAL ; 
 scalar_t__ FULLSCREEN_WORKSPACE ; 
 int L_HORIZ ; 
 int L_STACKED ; 
 int L_TABBED ; 
 int L_VERT ; 
 scalar_t__ N_CONTAINER ; 
 scalar_t__ N_WORKSPACE ; 
#define  WLR_DIRECTION_DOWN 131 
#define  WLR_DIRECTION_LEFT 130 
#define  WLR_DIRECTION_RIGHT 129 
#define  WLR_DIRECTION_UP 128 
 scalar_t__ WRAP_FORCE ; 
 scalar_t__ WRAP_NO ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*,...) ; 
 TYPE_10__* config ; 
 TYPE_7__* container_get_siblings (struct sway_container*) ; 
 scalar_t__ container_is_floating (struct sway_container*) ; 
 scalar_t__ container_is_floating_or_child (struct sway_container*) ; 
 scalar_t__ container_is_scratchpad_hidden (struct sway_container*) ; 
 int container_parent_layout (struct sway_container*) ; 
 int /*<<< orphan*/  container_raise_floating (struct sway_container*) ; 
 int container_sibling_index (struct sway_container*) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* join_args (char**,int) ; 
 struct sway_node* node_get_parent (struct sway_node*) ; 
 int /*<<< orphan*/  opposite_direction (int) ; 
 struct sway_output* output_by_name_or_id (char*) ; 
 struct sway_output* output_from_wlr_output (struct wlr_output*) ; 
 struct sway_workspace* output_get_active_workspace (struct sway_output*) ; 
 struct sway_output* output_get_in_direction (struct sway_output*,int) ; 
 TYPE_8__* root ; 
 int /*<<< orphan*/  root_scratchpad_show (struct sway_container*) ; 
 int /*<<< orphan*/  seat_consider_warp_to_focus (struct sway_seat*) ; 
 struct sway_node* seat_get_active_tiling_child (struct sway_seat*,struct sway_node*) ; 
 struct sway_node* seat_get_focus_inactive (struct sway_seat*,int /*<<< orphan*/ *) ; 
 struct sway_container* seat_get_focus_inactive_floating (struct sway_seat*,struct sway_workspace*) ; 
 struct sway_container* seat_get_focus_inactive_tiling (struct sway_seat*,struct sway_workspace*) ; 
 struct sway_container* seat_get_focus_inactive_view (struct sway_seat*,struct sway_node*) ; 
 struct sway_workspace* seat_get_focused_workspace (struct sway_seat*) ; 
 int /*<<< orphan*/  seat_set_focus (struct sway_seat*,struct sway_node*) ; 
 int /*<<< orphan*/  seat_set_focus_container (struct sway_seat*,struct sway_container*) ; 
 scalar_t__ strcasecmp (char const*,char*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  sway_assert (struct sway_workspace*,char*) ; 
 struct wlr_output* wlr_output_layout_farthest_output (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static bool parse_direction(const char *name,
		enum wlr_direction *out) {
	if (strcasecmp(name, "left") == 0) {
		*out = WLR_DIRECTION_LEFT;
	} else if (strcasecmp(name, "right") == 0) {
		*out = WLR_DIRECTION_RIGHT;
	} else if (strcasecmp(name, "up") == 0) {
		*out = WLR_DIRECTION_UP;
	} else if (strcasecmp(name, "down") == 0) {
		*out = WLR_DIRECTION_DOWN;
	} else {
		return false;
	}

	return true;
}

__attribute__((used)) static struct sway_node *get_node_in_output_direction(
		struct sway_output *output, enum wlr_direction dir) {
	struct sway_seat *seat = config->handler_context.seat;
	struct sway_workspace *ws = output_get_active_workspace(output);
	if (!sway_assert(ws, "Expected output to have a workspace")) {
		return NULL;
	}
	if (ws->fullscreen) {
		return seat_get_focus_inactive(seat, &ws->fullscreen->node);
	}
	struct sway_container *container = NULL;

	if (ws->tiling->length > 0) {
		switch (dir) {
		case WLR_DIRECTION_LEFT:
			if (ws->layout == L_HORIZ || ws->layout == L_TABBED) {
				// get most right child of new output
				container = ws->tiling->items[ws->tiling->length-1];
			} else {
				container = seat_get_focus_inactive_tiling(seat, ws);
			}
			break;
		case WLR_DIRECTION_RIGHT:
			if (ws->layout == L_HORIZ || ws->layout == L_TABBED) {
				// get most left child of new output
				container = ws->tiling->items[0];
			} else {
				container = seat_get_focus_inactive_tiling(seat, ws);
			}
			break;
		case WLR_DIRECTION_UP:
			if (ws->layout == L_VERT || ws->layout == L_STACKED) {
				// get most bottom child of new output
				container = ws->tiling->items[ws->tiling->length-1];
			} else {
				container = seat_get_focus_inactive_tiling(seat, ws);
			}
			break;
		case WLR_DIRECTION_DOWN:
			if (ws->layout == L_VERT || ws->layout == L_STACKED) {
				// get most top child of new output
				container = ws->tiling->items[0];
			} else {
				container = seat_get_focus_inactive_tiling(seat, ws);
			}
			break;
		}
	}

	if (container) {
		container = seat_get_focus_inactive_view(seat, &container->node);
		return &container->node;
	}

	return &ws->node;
}

__attribute__((used)) static struct sway_node *node_get_in_direction_tiling(
		struct sway_container *container, struct sway_seat *seat,
		enum wlr_direction dir) {
	struct sway_container *wrap_candidate = NULL;
	struct sway_container *current = container;
	while (current) {
		if (current->fullscreen_mode == FULLSCREEN_WORKSPACE) {
			// Fullscreen container with a direction - go straight to outputs
			struct sway_output *output = current->workspace->output;
			struct sway_output *new_output =
				output_get_in_direction(output, dir);
			if (!new_output) {
				return NULL;
			}
			return get_node_in_output_direction(new_output, dir);
		}
		if (current->fullscreen_mode == FULLSCREEN_GLOBAL) {
			return NULL;
		}

		bool can_move = false;
		int desired;
		int idx = container_sibling_index(current);
		enum sway_container_layout parent_layout =
			container_parent_layout(current);
		list_t *siblings = container_get_siblings(current);

		if (dir == WLR_DIRECTION_LEFT || dir == WLR_DIRECTION_RIGHT) {
			if (parent_layout == L_HORIZ || parent_layout == L_TABBED) {
				can_move = true;
				desired = idx + (dir == WLR_DIRECTION_LEFT ? -1 : 1);
			}
		} else {
			if (parent_layout == L_VERT || parent_layout == L_STACKED) {
				can_move = true;
				desired = idx + (dir == WLR_DIRECTION_UP ? -1 : 1);
			}
		}

		if (can_move) {
			if (desired < 0 || desired >= siblings->length) {
				int len = siblings->length;
				if (config->focus_wrapping != WRAP_NO && !wrap_candidate
						&& len > 1) {
					if (desired < 0) {
						wrap_candidate = siblings->items[len-1];
					} else {
						wrap_candidate = siblings->items[0];
					}
					if (config->focus_wrapping == WRAP_FORCE) {
						struct sway_container *c = seat_get_focus_inactive_view(
								seat, &wrap_candidate->node);
						return &c->node;
					}
				}
			} else {
				struct sway_container *desired_con = siblings->items[desired];
				struct sway_container *c = seat_get_focus_inactive_view(
						seat, &desired_con->node);
				return &c->node;
			}
		}

		current = current->parent;
	}

	// Check a different output
	struct sway_output *output = container->workspace->output;
	struct sway_output *new_output = output_get_in_direction(output, dir);
	if (new_output) {
		return get_node_in_output_direction(new_output, dir);
	}

	// If there is a wrap candidate, return its focus inactive view
	if (wrap_candidate) {
		struct sway_container *wrap_inactive = seat_get_focus_inactive_view(
				seat, &wrap_candidate->node);
		return &wrap_inactive->node;
	}

	return NULL;
}

__attribute__((used)) static struct sway_node *node_get_in_direction_floating(
		struct sway_container *con, struct sway_seat *seat,
		enum wlr_direction dir) {
	double ref_lx = con->x + con->width / 2;
	double ref_ly = con->y + con->height / 2;
	double closest_distance = DBL_MAX;
	struct sway_container *closest_con = NULL;

	if (!con->workspace) {
		return NULL;
	}

	for (int i = 0; i < con->workspace->floating->length; i++) {
		struct sway_container *floater = con->workspace->floating->items[i];
		if (floater == con) {
			continue;
		}
		float distance = dir == WLR_DIRECTION_LEFT || dir == WLR_DIRECTION_RIGHT
			? (floater->x + floater->width / 2) - ref_lx
			: (floater->y + floater->height / 2) - ref_ly;
		if (dir == WLR_DIRECTION_LEFT || dir == WLR_DIRECTION_UP) {
			distance = -distance;
		}
		if (distance < 0) {
			continue;
		}
		if (distance < closest_distance) {
			closest_distance = distance;
			closest_con = floater;
		}
	}

	return closest_con ? &closest_con->node : NULL;
}

__attribute__((used)) static struct cmd_results *focus_mode(struct sway_workspace *ws,
		struct sway_seat *seat, bool floating) {
	struct sway_container *new_focus = NULL;
	if (floating) {
		new_focus = seat_get_focus_inactive_floating(seat, ws);
	} else {
		new_focus = seat_get_focus_inactive_tiling(seat, ws);
	}
	if (new_focus) {
		seat_set_focus_container(seat, new_focus);
		seat_consider_warp_to_focus(seat);
	} else {
		return cmd_results_new(CMD_FAILURE,
				"Failed to find a %s container in workspace",
				floating ? "floating" : "tiling");
	}
	return cmd_results_new(CMD_SUCCESS, NULL);
}

__attribute__((used)) static struct cmd_results *focus_output(struct sway_seat *seat,
		int argc, char **argv) {
	if (!argc) {
		return cmd_results_new(CMD_INVALID,
			"Expected 'focus output <direction|name>'");
	}
	char *identifier = join_args(argv, argc);
	struct sway_output *output = output_by_name_or_id(identifier);

	if (!output) {
		enum wlr_direction direction;
		if (!parse_direction(identifier, &direction)) {
			free(identifier);
			return cmd_results_new(CMD_INVALID,
				"There is no output with that name");
		}
		struct sway_workspace *ws = seat_get_focused_workspace(seat);
		if (!ws) {
			free(identifier);
			return cmd_results_new(CMD_FAILURE,
				"No focused workspace to base directions off of");
		}
		output = output_get_in_direction(ws->output, direction);

		if (!output) {
			int center_lx = ws->output->lx + ws->output->width / 2;
			int center_ly = ws->output->ly + ws->output->height / 2;
			struct wlr_output *target = wlr_output_layout_farthest_output(
					root->output_layout, opposite_direction(direction),
					ws->output->wlr_output, center_lx, center_ly);
			if (target) {
				output = output_from_wlr_output(target);
			}
		}
	}

	free(identifier);
	if (output) {
		seat_set_focus(seat, seat_get_focus_inactive(seat, &output->node));
		seat_consider_warp_to_focus(seat);
	}

	return cmd_results_new(CMD_SUCCESS, NULL);
}

__attribute__((used)) static struct cmd_results *focus_parent(void) {
	struct sway_seat *seat = config->handler_context.seat;
	struct sway_container *con = config->handler_context.container;
	if (!con || con->fullscreen_mode) {
		return cmd_results_new(CMD_SUCCESS, NULL);
	}
	struct sway_node *parent = node_get_parent(&con->node);
	if (parent) {
		seat_set_focus(seat, parent);
		seat_consider_warp_to_focus(seat);
	}
	return cmd_results_new(CMD_SUCCESS, NULL);
}

__attribute__((used)) static struct cmd_results *focus_child(void) {
	struct sway_seat *seat = config->handler_context.seat;
	struct sway_node *node = config->handler_context.node;
	struct sway_node *focus = seat_get_active_tiling_child(seat, node);
	if (focus) {
		seat_set_focus(seat, focus);
		seat_consider_warp_to_focus(seat);
	}
	return cmd_results_new(CMD_SUCCESS, NULL);
}

struct cmd_results *cmd_focus(int argc, char **argv) {
	if (config->reading || !config->active) {
		return cmd_results_new(CMD_DEFER, NULL);
	}
	if (!root->outputs->length) {
		return cmd_results_new(CMD_INVALID,
				"Can't run this command while there's no outputs connected.");
	}
	struct sway_node *node = config->handler_context.node;
	struct sway_container *container = config->handler_context.container;
	struct sway_workspace *workspace = config->handler_context.workspace;
	struct sway_seat *seat = config->handler_context.seat;
	if (node->type < N_WORKSPACE) {
		return cmd_results_new(CMD_FAILURE,
			"Command 'focus' cannot be used above the workspace level");
	}

	if (argc == 0 && container) {
		if (container_is_scratchpad_hidden(container)) {
			root_scratchpad_show(container);
		}
		seat_set_focus_container(seat, container);
		seat_consider_warp_to_focus(seat);
		container_raise_floating(container);
		return cmd_results_new(CMD_SUCCESS, NULL);
	}

	if (strcmp(argv[0], "floating") == 0) {
		return focus_mode(workspace, seat, true);
	} else if (strcmp(argv[0], "tiling") == 0) {
		return focus_mode(workspace, seat, false);
	} else if (strcmp(argv[0], "mode_toggle") == 0) {
		bool floating = container && container_is_floating_or_child(container);
		return focus_mode(workspace, seat, !floating);
	}

	if (strcmp(argv[0], "output") == 0) {
		argc--; argv++;
		return focus_output(seat, argc, argv);
	}

	if (strcasecmp(argv[0], "parent") == 0) {
		return focus_parent();
	}
	if (strcasecmp(argv[0], "child") == 0) {
		return focus_child();
	}

	enum wlr_direction direction = 0;
	if (!parse_direction(argv[0], &direction)) {
		return cmd_results_new(CMD_INVALID,
			"Expected 'focus <direction|parent|child|mode_toggle|floating|tiling>' "
			"or 'focus output <direction|name>'");
	}

	if (node->type == N_WORKSPACE) {
		// Jump to the next output
		struct sway_output *new_output =
			output_get_in_direction(workspace->output, direction);
		if (!new_output) {
			return cmd_results_new(CMD_SUCCESS, NULL);
		}

		struct sway_node *node =
			get_node_in_output_direction(new_output, direction);
		seat_set_focus(seat, node);
		seat_consider_warp_to_focus(seat);
		return cmd_results_new(CMD_SUCCESS, NULL);
	}

	struct sway_node *next_focus = NULL;
	if (container_is_floating(container)) {
		next_focus = node_get_in_direction_floating(container, seat, direction);
	} else {
		next_focus = node_get_in_direction_tiling(container, seat, direction);
	}
	if (next_focus) {
		seat_set_focus(seat, next_focus);
		seat_consider_warp_to_focus(seat);

		if (next_focus->type == N_CONTAINER) {
			container_raise_floating(next_focus->sway_container);
		}
	}

	return cmd_results_new(CMD_SUCCESS, NULL);
}

