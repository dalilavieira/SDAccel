#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct cmd_results {int dummy; } ;
struct bar_config {char* hidden_state; char const* id; } ;
struct TYPE_4__ {TYPE_1__* bars; struct bar_config* current_bar; scalar_t__ reading; } ;
struct TYPE_3__ {int length; struct bar_config** items; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_INVALID ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_AT_LEAST ; 
 int /*<<< orphan*/  EXPECTED_AT_MOST ; 
 int /*<<< orphan*/  SWAY_DEBUG ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*,...) ; 
 TYPE_2__* config ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  ipc_event_barconfig_update (struct bar_config*) ; 
 scalar_t__ strcasecmp (char*,char const*) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 void* strdup (char*) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*,char const*,char const*) ; 

__attribute__((used)) static struct cmd_results *bar_set_hidden_state(struct bar_config *bar,
		const char *hidden_state) {
	char *old_state = bar->hidden_state;
	if (strcasecmp("toggle", hidden_state) == 0 && !config->reading) {
		if (strcasecmp("hide", bar->hidden_state) == 0) {
			bar->hidden_state = strdup("show");
		} else if (strcasecmp("show", bar->hidden_state) == 0) {
			bar->hidden_state = strdup("hide");
		}
	} else if (strcasecmp("hide", hidden_state) == 0) {
		bar->hidden_state = strdup("hide");
	} else if (strcasecmp("show", hidden_state) == 0) {
		bar->hidden_state = strdup("show");
	} else {
		return cmd_results_new(CMD_INVALID, "Invalid value %s",	hidden_state);
	}
	if (strcmp(old_state, bar->hidden_state) != 0) {
		if (!config->reading) {
			ipc_event_barconfig_update(bar);
		}
		sway_log(SWAY_DEBUG, "Setting hidden_state: '%s' for bar: %s",
				bar->hidden_state, bar->id);
	}
	// free old mode
	free(old_state);
	return NULL;
}

struct cmd_results *bar_cmd_hidden_state(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "hidden_state", EXPECTED_AT_LEAST, 1))) {
		return error;
	}
	if ((error = checkarg(argc, "hidden_state", EXPECTED_AT_MOST, 2))) {
		return error;
	}
	if (config->reading && argc > 1) {
		return cmd_results_new(CMD_INVALID,
				"Unexpected value %s in config mode", argv[1]);
	}

	const char *state = argv[0];
	if (config->reading) {
		error = bar_set_hidden_state(config->current_bar, state);
	} else {
		const char *id = argc == 2 ? argv[1] : NULL;
		for (int i = 0; i < config->bars->length; ++i) {
			struct bar_config *bar = config->bars->items[i];
			if (id) {
				if (strcmp(id, bar->id) == 0) {
					error = bar_set_hidden_state(bar, state);
					break;
				}
			} else if ((error = bar_set_hidden_state(bar, state))) {
				break;
			}
		}
	}
	return error ? error : cmd_results_new(CMD_SUCCESS, NULL);
}

