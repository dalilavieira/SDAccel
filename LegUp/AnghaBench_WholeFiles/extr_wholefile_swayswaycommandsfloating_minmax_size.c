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
struct cmd_results {int dummy; } ;
struct TYPE_2__ {int floating_minimum_width; int floating_minimum_height; int floating_maximum_width; int floating_maximum_height; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_INVALID ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_EQUAL_TO ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*,...) ; 
 TYPE_1__* config ; 
 char* max_usage ; 
 char* min_usage ; 
 scalar_t__ strcmp (char*,char*) ; 
 scalar_t__ strtol (char*,char**,int) ; 

__attribute__((used)) static struct cmd_results *handle_command(int argc, char **argv, char *cmd_name,
		const char *usage, int *config_width, int *config_height) {
	struct cmd_results *error;
	if ((error = checkarg(argc, cmd_name, EXPECTED_EQUAL_TO, 3))) {
		return error;
	}

	char *err;
	int width = (int)strtol(argv[0], &err, 10);
	if (*err) {
		return cmd_results_new(CMD_INVALID, cmd_name, usage);
	}

	if (strcmp(argv[1], "x") != 0) {
		return cmd_results_new(CMD_INVALID, cmd_name, usage);
	}

	int height = (int)strtol(argv[2], &err, 10);
	if (*err) {
		return cmd_results_new(CMD_INVALID, cmd_name, usage);
	}

	*config_width = width;
	*config_height = height;

	return cmd_results_new(CMD_SUCCESS, NULL);
}

struct cmd_results *cmd_floating_minimum_size(int argc, char **argv) {
	return handle_command(argc, argv, "floating_minimum_size", min_usage,
			&config->floating_minimum_width, &config->floating_minimum_height);
}

struct cmd_results *cmd_floating_maximum_size(int argc, char **argv) {
	return handle_command(argc, argv, "floating_maximum_size", max_usage,
			&config->floating_maximum_width, &config->floating_maximum_height);
}

