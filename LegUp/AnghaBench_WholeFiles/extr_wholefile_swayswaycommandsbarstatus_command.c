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
struct TYPE_4__ {TYPE_1__* current_bar; int /*<<< orphan*/  validating; scalar_t__ active; } ;
struct TYPE_3__ {char* status_command; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_FAILURE ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_AT_LEAST ; 
 int /*<<< orphan*/  SWAY_DEBUG ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*) ; 
 TYPE_2__* config ; 
 int /*<<< orphan*/  free (char*) ; 
 char* join_args (char**,int) ; 
 int /*<<< orphan*/  load_swaybar (TYPE_1__*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*,char*) ; 

struct cmd_results *bar_cmd_status_command(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "status_command", EXPECTED_AT_LEAST, 1))) {
		return error;
	}
	if (!config->current_bar) {
		return cmd_results_new(CMD_FAILURE, "No bar defined.");
	}
	free(config->current_bar->status_command);
	config->current_bar->status_command = NULL;

	char *new_command = join_args(argv, argc);
	if (strcmp(new_command, "-") != 0) {
		config->current_bar->status_command = new_command;
		sway_log(SWAY_DEBUG, "Feeding bar with status command: %s",
				config->current_bar->status_command);
	} else {
		free(new_command);
	}

	if (config->active && !config->validating) {
		load_swaybar(config->current_bar);
	}

	return cmd_results_new(CMD_SUCCESS, NULL);
}

