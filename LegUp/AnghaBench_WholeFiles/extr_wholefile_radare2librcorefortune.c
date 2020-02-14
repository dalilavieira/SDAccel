#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  config; } ;
typedef  TYPE_1__ RCore ;

/* Variables and functions */
 int /*<<< orphan*/  R2_FORTUNES ; 
 int R_ARRAY_SIZE (char**) ; 
 int /*<<< orphan*/  R_JOIN_3_PATHS (char*,int /*<<< orphan*/ ,char*) ; 
 char** fortunes ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ r_config_get (int /*<<< orphan*/ ,char*) ; 
 char* r_file_slurp_random_line_count (char*,int*) ; 
 char* r_str_newf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  r_sys_prefix (int /*<<< orphan*/ *) ; 
 scalar_t__ strstr (char const*,char*) ; 

__attribute__((used)) static char *getFortuneFile(RCore *core, const char *type) {
	return r_str_newf (R_JOIN_3_PATHS ("%s", R2_FORTUNES, "fortunes.%s"),
		r_sys_prefix (NULL), type);
}

__attribute__((used)) static char *getrandomline(RCore *core) {
	int i, lines = 0;
	const char *types = (char *)r_config_get (core->config, "cfg.fortunes.type");
	char *line = NULL, *templine;
	for (i = 0; i < R_ARRAY_SIZE (fortunes); i++) {
		if (strstr (types, fortunes[i])) {
			char *file = getFortuneFile(core, fortunes[i]);
			templine = r_file_slurp_random_line_count (file, &lines);
			if (templine && *templine) {
				free (line);
				line = templine;
			}
			free (file);
		}
	}
	return line;
}

