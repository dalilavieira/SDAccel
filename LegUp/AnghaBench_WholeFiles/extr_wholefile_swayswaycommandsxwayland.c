#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct cmd_results {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_EQUAL_TO ; 
 int /*<<< orphan*/  SWAY_INFO ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*) ; 

struct cmd_results *cmd_xwayland(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "xwayland", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

#ifdef HAVE_XWAYLAND
	config->xwayland = parse_boolean(argv[0], config->xwayland);
#else
	sway_log(SWAY_INFO, "Ignoring `xwayland` command, "
		"sway hasn't been built with Xwayland support");
#endif

	return cmd_results_new(CMD_SUCCESS, NULL);
}

