#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct input_config_mapped_from_region {int dummy; } ;
struct input_config {TYPE_2__* mapped_from_region; } ;
struct cmd_results {int dummy; } ;
struct TYPE_5__ {struct input_config* input_config; } ;
struct TYPE_7__ {TYPE_1__ handler_context; } ;
struct TYPE_6__ {double x1; double y1; double x2; double y2; int /*<<< orphan*/  mm; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_FAILURE ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_EQUAL_TO ; 
 TYPE_2__* calloc (int,int) ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*) ; 
 TYPE_3__* config ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 double strtod (char const*,char**) ; 

__attribute__((used)) static bool parse_coords(const char *str, double *x, double *y, bool *mm) {
	*mm = false;

	char *end;
	*x = strtod(str, &end);
	if (end[0] != 'x') {
		return false;
	}
	++end;

	*y = strtod(end, &end);
	if (end[0] == 'm') {
		// Expect mm
		if (end[1] != 'm') {
			return false;
		}
		*mm = true;
		end = &end[2];
	}
	if (end[0] != '\0') {
		return false;
	}

	return true;
}

struct cmd_results *input_cmd_map_from_region(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "map_from_region", EXPECTED_EQUAL_TO, 2))) {
		return error;
	}
	struct input_config *ic = config->handler_context.input_config;
	if (!ic) {
		return cmd_results_new(CMD_FAILURE, "No input device defined");
	}

	ic->mapped_from_region =
		calloc(1, sizeof(struct input_config_mapped_from_region));

	bool mm1, mm2;
	if (!parse_coords(argv[0], &ic->mapped_from_region->x1,
			&ic->mapped_from_region->y1, &mm1)) {
		free(ic->mapped_from_region);
		ic->mapped_from_region = NULL;
		return cmd_results_new(CMD_FAILURE, "Invalid top-left coordinates");
	}
	if (!parse_coords(argv[1], &ic->mapped_from_region->x2,
			&ic->mapped_from_region->y2, &mm2)) {
		free(ic->mapped_from_region);
		ic->mapped_from_region = NULL;
		return cmd_results_new(CMD_FAILURE, "Invalid bottom-right coordinates");
	}
	if (ic->mapped_from_region->x1 > ic->mapped_from_region->x2 ||
			ic->mapped_from_region->y1 > ic->mapped_from_region->y2) {
		free(ic->mapped_from_region);
		ic->mapped_from_region = NULL;
		return cmd_results_new(CMD_FAILURE, "Invalid rectangle");
	}
	if (mm1 != mm2) {
		free(ic->mapped_from_region);
		ic->mapped_from_region = NULL;
		return cmd_results_new(CMD_FAILURE,
			"Both coordinates must be in the same unit");
	}
	ic->mapped_from_region->mm = mm1;

	return cmd_results_new(CMD_SUCCESS, NULL);
}

