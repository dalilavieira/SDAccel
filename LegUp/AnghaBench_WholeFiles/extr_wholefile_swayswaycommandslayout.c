#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct sway_workspace {int layout; int prev_split_layout; } ;
struct sway_container {int layout; int prev_split_layout; struct sway_container* parent; } ;
struct cmd_results {int dummy; } ;
typedef  enum sway_container_layout { ____Placeholder_sway_container_layout } sway_container_layout ;
struct TYPE_6__ {struct sway_workspace* workspace; struct sway_container* container; } ;
struct TYPE_8__ {TYPE_2__ handler_context; } ;
struct TYPE_7__ {scalar_t__ fullscreen_global; TYPE_1__* outputs; } ;
struct TYPE_5__ {int /*<<< orphan*/  length; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_FAILURE ; 
 int /*<<< orphan*/  CMD_INVALID ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_AT_LEAST ; 
 int L_HORIZ ; 
 int L_NONE ; 
 int L_STACKED ; 
 int L_TABBED ; 
 int L_VERT ; 
 int /*<<< orphan*/  arrange_root () ; 
 int /*<<< orphan*/  arrange_workspace (struct sway_workspace*) ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*) ; 
 TYPE_4__* config ; 
 scalar_t__ container_is_floating (struct sway_container*) ; 
 int /*<<< orphan*/  container_update_representation (struct sway_container*) ; 
 char* expected_syntax ; 
 TYPE_3__* root ; 
 scalar_t__ strcasecmp (char*,char*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  workspace_update_representation (struct sway_workspace*) ; 

__attribute__((used)) static enum sway_container_layout parse_layout_string(char *s) {
	if (strcasecmp(s, "splith") == 0) {
		return L_HORIZ;
	} else if (strcasecmp(s, "splitv") == 0) {
		return L_VERT;
	} else if (strcasecmp(s, "tabbed") == 0) {
		return L_TABBED;
	} else if (strcasecmp(s, "stacking") == 0) {
		return L_STACKED;
	}
	return L_NONE;
}

__attribute__((used)) static enum sway_container_layout get_layout_toggle(int argc, char **argv,
		enum sway_container_layout layout,
		enum sway_container_layout prev_split_layout) {
	// "layout toggle"
	if (argc == 1) {
		return layout == L_HORIZ ? L_VERT : L_HORIZ;
	}

	if (argc == 2) {
		// "layout toggle split" (same as "layout toggle")
		if (strcasecmp(argv[1], "split") == 0) {
			return layout == L_HORIZ ? L_VERT : L_HORIZ;
		}
		// "layout toggle all"
		if (strcasecmp(argv[1], "all") == 0) {
			return layout == L_HORIZ ? L_VERT :
				layout == L_VERT ? L_STACKED :
				layout == L_STACKED ? L_TABBED : L_HORIZ;
		}
		return L_NONE;
	}

	enum sway_container_layout parsed;
	int curr = 1;
	for (; curr < argc; curr++) {
		parsed = parse_layout_string(argv[curr]);
		if (parsed == layout || (strcmp(argv[curr], "split") == 0 &&
				 (layout == L_VERT || layout == L_HORIZ))) {
			break;
		}
	}
	for (int i = curr + 1; i != curr; ++i) {
		// cycle round to find next valid layout
		if (i >= argc) {
			i = 1;
		}
		parsed = parse_layout_string(argv[i]);
		if (parsed != L_NONE) {
			return parsed;
		}
		if (strcmp(argv[i], "split") == 0) {
			return layout == L_HORIZ ? L_VERT :
				layout == L_VERT ? L_HORIZ : prev_split_layout;
		}
		// invalid layout strings are silently ignored
	}
	return L_NONE;
}

__attribute__((used)) static enum sway_container_layout get_layout(int argc, char **argv,
		enum sway_container_layout layout,
		enum sway_container_layout prev_split_layout) {
	// Check if assigned directly
	enum sway_container_layout parsed = parse_layout_string(argv[0]);
	if (parsed != L_NONE) {
		return parsed;
	}

	if (strcasecmp(argv[0], "default") == 0) {
		return prev_split_layout;
	}

	if (strcasecmp(argv[0], "toggle") == 0) {
		return get_layout_toggle(argc, argv, layout, prev_split_layout);
	}

	return L_NONE;
}

struct cmd_results *cmd_layout(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "layout", EXPECTED_AT_LEAST, 1))) {
		return error;
	}
	if (!root->outputs->length) {
		return cmd_results_new(CMD_INVALID,
				"Can't run this command while there's no outputs connected.");
	}
	struct sway_container *container = config->handler_context.container;
	struct sway_workspace *workspace = config->handler_context.workspace;

	if (container && container_is_floating(container)) {
		return cmd_results_new(CMD_FAILURE,
				"Unable to change layout of floating windows");
	}

	// Operate on parent container, like i3.
	if (container) {
		container = container->parent;
	}

	// We could be working with a container OR a workspace. These are different
	// structures, so we set up pointers to they layouts so we can refer them in
	// an abstract way.
	enum sway_container_layout new_layout = L_NONE;
	enum sway_container_layout old_layout = L_NONE;
	if (container) {
		old_layout = container->layout;
		new_layout = get_layout(argc, argv,
				container->layout, container->prev_split_layout);
	} else {
		old_layout = workspace->layout;
		new_layout = get_layout(argc, argv,
				workspace->layout, workspace->prev_split_layout);
	}
	if (new_layout == L_NONE) {
		return cmd_results_new(CMD_INVALID, expected_syntax);
	}
	if (new_layout != old_layout) {
		if (container) {
			if (old_layout != L_TABBED && old_layout != L_STACKED) {
				container->prev_split_layout = old_layout;
			}
			container->layout = new_layout;
			container_update_representation(container);
		} else {
			if (old_layout != L_TABBED && old_layout != L_STACKED) {
				workspace->prev_split_layout = old_layout;
			}
			workspace->layout = new_layout;
			workspace_update_representation(workspace);
		}
		if (root->fullscreen_global) {
			arrange_root();
		} else {
			arrange_workspace(workspace);
		}
	}

	return cmd_results_new(CMD_SUCCESS, NULL);
}

