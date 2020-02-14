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
struct sway_workspace {TYPE_1__* floating; } ;
struct sway_seat {int dummy; } ;
struct sway_container {int scratchpad; struct sway_container* parent; struct sway_workspace* workspace; int /*<<< orphan*/  title; } ;
struct cmd_results {int dummy; } ;
struct TYPE_10__ {struct sway_container* container; scalar_t__ using_criteria; } ;
struct TYPE_12__ {TYPE_4__ handler_context; } ;
struct TYPE_11__ {TYPE_3__* scratchpad; TYPE_2__* outputs; } ;
struct TYPE_9__ {int length; struct sway_container** items; } ;
struct TYPE_8__ {int /*<<< orphan*/  length; } ;
struct TYPE_7__ {int length; struct sway_container** items; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_INVALID ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_EQUAL_TO ; 
 int /*<<< orphan*/  SWAY_DEBUG ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*) ; 
 TYPE_6__* config ; 
 scalar_t__ container_is_floating_or_child (struct sway_container*) ; 
 struct sway_seat* input_manager_current_seat () ; 
 int /*<<< orphan*/  ipc_event_window (struct sway_container*,char*) ; 
 TYPE_5__* root ; 
 int /*<<< orphan*/  root_scratchpad_hide (struct sway_container*) ; 
 int /*<<< orphan*/  root_scratchpad_show (struct sway_container*) ; 
 struct sway_container* seat_get_focused_container (struct sway_seat*) ; 
 struct sway_workspace* seat_get_focused_workspace (struct sway_seat*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  sway_assert (int,char*) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*,...) ; 

__attribute__((used)) static void scratchpad_toggle_auto(void) {
	struct sway_seat *seat = input_manager_current_seat();
	struct sway_container *focus = seat_get_focused_container(seat);
	struct sway_workspace *ws = seat_get_focused_workspace(seat);
	if (!ws) {
		sway_log(SWAY_DEBUG,
				"No focused workspace to toggle scratchpad windows on");
		return;
	}

	// If the focus is in a floating split container,
	// operate on the split container instead of the child.
	if (focus && container_is_floating_or_child(focus)) {
		while (focus->parent) {
			focus = focus->parent;
		}
	}

	// Check if the currently focused window is a scratchpad window and should
	// be hidden again.
	if (focus && focus->scratchpad) {
		sway_log(SWAY_DEBUG, "Focus is a scratchpad window - hiding %s",
				focus->title);
		root_scratchpad_hide(focus);
		return;
	}

	// Check if there is an unfocused scratchpad window on the current workspace
	// and focus it.
	for (int i = 0; i < ws->floating->length; ++i) {
		struct sway_container *floater = ws->floating->items[i];
		if (floater->scratchpad && focus != floater) {
			sway_log(SWAY_DEBUG,
					"Focusing other scratchpad window (%s) in this workspace",
					floater->title);
			root_scratchpad_show(floater);
			return;
		}
	}

	// Check if there is a visible scratchpad window on another workspace.
	// In this case we move it to the current workspace.
	for (int i = 0; i < root->scratchpad->length; ++i) {
		struct sway_container *con = root->scratchpad->items[i];
		if (con->parent) {
			sway_log(SWAY_DEBUG,
					"Moving a visible scratchpad window (%s) to this workspace",
					con->title);
			root_scratchpad_show(con);
			ipc_event_window(con, "move");
			return;
		}
	}

	// Take the container at the bottom of the scratchpad list
	if (!sway_assert(root->scratchpad->length, "Scratchpad is empty")) {
		return;
	}
	struct sway_container *con = root->scratchpad->items[0];
	sway_log(SWAY_DEBUG, "Showing %s from list", con->title);
	root_scratchpad_show(con);
	ipc_event_window(con, "move");
}

__attribute__((used)) static void scratchpad_toggle_container(struct sway_container *con) {
	if (!sway_assert(con->scratchpad, "Container isn't in the scratchpad")) {
		return;
	}

	struct sway_seat *seat = input_manager_current_seat();
	struct sway_workspace *ws = seat_get_focused_workspace(seat);
	// Check if it matches a currently visible scratchpad window and hide it.
	if (con->workspace && ws == con->workspace) {
		root_scratchpad_hide(con);
		return;
	}

	root_scratchpad_show(con);
	ipc_event_window(con, "move");
}

struct cmd_results *cmd_scratchpad(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "scratchpad", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}
	if (strcmp(argv[0], "show") != 0) {
		return cmd_results_new(CMD_INVALID, "Expected 'scratchpad show'");
	}
	if (!root->outputs->length) {
		return cmd_results_new(CMD_INVALID,
				"Can't run this command while there's no outputs connected.");
	}
	if (!root->scratchpad->length) {
		return cmd_results_new(CMD_INVALID, "Scratchpad is empty");
	}

	if (config->handler_context.using_criteria) {
		struct sway_container *con = config->handler_context.container;

		// If the container is in a floating split container,
		// operate on the split container instead of the child.
		if (container_is_floating_or_child(con)) {
			while (con->parent) {
				con = con->parent;
			}
		}

		// If using criteria, this command is executed for every container which
		// matches the criteria. If this container isn't in the scratchpad,
		// we'll just silently return a success.
		if (!con->scratchpad) {
			return cmd_results_new(CMD_SUCCESS, NULL);
		}
		scratchpad_toggle_container(con);
	} else {
		scratchpad_toggle_auto();
	}

	return cmd_results_new(CMD_SUCCESS, NULL);
}

