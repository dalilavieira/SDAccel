#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct sway_variable {struct sway_variable* value; struct sway_variable* name; } ;
struct cmd_results {int dummy; } ;
struct TYPE_5__ {TYPE_1__* symbols; } ;
struct TYPE_4__ {int length; struct sway_variable** items; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_FAILURE ; 
 int /*<<< orphan*/  CMD_INVALID ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_AT_LEAST ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*,...) ; 
 TYPE_3__* config ; 
 int /*<<< orphan*/  free (struct sway_variable*) ; 
 struct sway_variable* join_args (char**,int) ; 
 int /*<<< orphan*/  list_add (TYPE_1__*,struct sway_variable*) ; 
 int /*<<< orphan*/  list_qsort (TYPE_1__*,int (*) (void const*,void const*)) ; 
 struct sway_variable* malloc (int) ; 
 scalar_t__ strcmp (struct sway_variable*,char*) ; 
 struct sway_variable* strdup (char*) ; 
 int strlen (struct sway_variable*) ; 

__attribute__((used)) static int compare_set_qsort(const void *_l, const void *_r) {
	struct sway_variable const *l = *(void **)_l;
	struct sway_variable const *r = *(void **)_r;
	return strlen(r->name) - strlen(l->name);
}

void free_sway_variable(struct sway_variable *var) {
	if (!var) {
		return;
	}
	free(var->name);
	free(var->value);
	free(var);
}

struct cmd_results *cmd_set(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "set", EXPECTED_AT_LEAST, 2))) {
		return error;
	}

	if (argv[0][0] != '$') {
		return cmd_results_new(CMD_INVALID, "variable '%s' must start with $", argv[0]);
	}

	struct sway_variable *var = NULL;
	// Find old variable if it exists
	int i;
	for (i = 0; i < config->symbols->length; ++i) {
		var = config->symbols->items[i];
		if (strcmp(var->name, argv[0]) == 0) {
			break;
		}
		var = NULL;
	}
	if (var) {
		free(var->value);
	} else {
		var = malloc(sizeof(struct sway_variable));
		if (!var) {
			return cmd_results_new(CMD_FAILURE, "Unable to allocate variable");
		}
		var->name = strdup(argv[0]);
		list_add(config->symbols, var);
		list_qsort(config->symbols, compare_set_qsort);
	}
	var->value = join_args(argv + 1, argc - 1);
	return cmd_results_new(CMD_SUCCESS, NULL);
}

