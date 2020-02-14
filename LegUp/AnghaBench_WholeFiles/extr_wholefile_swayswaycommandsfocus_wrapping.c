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
struct TYPE_2__ {scalar_t__ focus_wrapping; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_EQUAL_TO ; 
 scalar_t__ WRAP_FORCE ; 
 scalar_t__ WRAP_NO ; 
 scalar_t__ WRAP_YES ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_1__* config ; 
 scalar_t__ parse_boolean (char*,int) ; 
 scalar_t__ strcasecmp (char*,char*) ; 

struct cmd_results *cmd_focus_wrapping(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "focus_wrapping", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	if (strcasecmp(argv[0], "force") == 0) {
		config->focus_wrapping = WRAP_FORCE;
	} else if (parse_boolean(argv[0], config->focus_wrapping == WRAP_YES)) {
		config->focus_wrapping = WRAP_YES;
	} else {
		config->focus_wrapping = WRAP_NO;
	}

	return cmd_results_new(CMD_SUCCESS, NULL);
}

