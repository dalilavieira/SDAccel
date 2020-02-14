#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct cmd_results {int dummy; } ;
struct bar_binding {scalar_t__ button; scalar_t__ release; int /*<<< orphan*/  command; } ;
struct TYPE_9__ {int length; struct bar_binding** items; } ;
typedef  TYPE_2__ list_t ;
struct TYPE_10__ {TYPE_1__* current_bar; } ;
struct TYPE_8__ {TYPE_2__* bindings; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_FAILURE ; 
 int /*<<< orphan*/  CMD_INVALID ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_AT_LEAST ; 
 int /*<<< orphan*/  SWAY_DEBUG ; 
 struct bar_binding* calloc (int,int) ; 
 struct cmd_results* checkarg (int,char const*,int /*<<< orphan*/ ,int) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*,...) ; 
 TYPE_5__* config ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  free_bar_binding (struct bar_binding*) ; 
 scalar_t__ get_mouse_bindcode (char*,char**) ; 
 scalar_t__ get_mouse_bindsym (char*,char**) ; 
 char* get_mouse_button_name (scalar_t__) ; 
 int /*<<< orphan*/  join_args (char**,int) ; 
 int /*<<< orphan*/  list_add (TYPE_2__*,struct bar_binding*) ; 
 int /*<<< orphan*/  list_del (TYPE_2__*,int) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,scalar_t__,char const*,char*) ; 

__attribute__((used)) static struct cmd_results *binding_add(struct bar_binding *binding,
		list_t *mode_bindings) {
	const char *name = get_mouse_button_name(binding->button);
	bool overwritten = false;
	for (int i = 0; i < mode_bindings->length; i++) {
		struct bar_binding *other = mode_bindings->items[i];
		if (other->button == binding->button &&
				other->release == binding->release) {
			overwritten = true;
			mode_bindings->items[i] = binding;
			free_bar_binding(other);
			sway_log(SWAY_DEBUG, "[bar %s] Updated binding for %u (%s)%s",
					config->current_bar->id, binding->button, name,
					binding->release ? " - release" : "");
			break;
		}
	}
	if (!overwritten) {
		list_add(mode_bindings, binding);
		sway_log(SWAY_DEBUG, "[bar %s] Added binding for %u (%s)%s",
				config->current_bar->id, binding->button, name,
				binding->release ? " - release" : "");
	}
	return cmd_results_new(CMD_SUCCESS, NULL);
}

__attribute__((used)) static struct cmd_results *binding_remove(struct bar_binding *binding,
		list_t *mode_bindings) {
	const char *name = get_mouse_button_name(binding->button);
	for (int i = 0; i < mode_bindings->length; i++) {
		struct bar_binding *other = mode_bindings->items[i];
		if (other->button == binding->button &&
				other->release == binding->release) {
			sway_log(SWAY_DEBUG, "[bar %s] Unbound binding for %u (%s)%s",
					config->current_bar->id, binding->button, name,
					binding->release ? " - release" : "");
			free_bar_binding(other);
			free_bar_binding(binding);
			list_del(mode_bindings, i);
			return cmd_results_new(CMD_SUCCESS, NULL);
		}
	}

	struct cmd_results *error = cmd_results_new(CMD_FAILURE, "Could not "
			"find binding for [bar %s]" " Button %u (%s)%s",
			config->current_bar->id, binding->button, name,
			binding->release ? " - release" : "");
	free_bar_binding(binding);
	return error;
}

__attribute__((used)) static struct cmd_results *bar_cmd_bind(int argc, char **argv, bool code,
		bool unbind) {
	int minargs = 2;
	const char *command;
	if (unbind) {
		minargs--;
		command = code ? "bar unbindcode" : "bar unbindsym";
	} else {
		command = code ? "bar bindcode" : "bar bindsym";
	}

	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, command, EXPECTED_AT_LEAST, minargs))) {
		return error;
	}
	if (!config->current_bar) {
		return cmd_results_new(CMD_FAILURE, "No bar defined.");
	}

	struct bar_binding *binding = calloc(1, sizeof(struct bar_binding));
	if (!binding) {
		return cmd_results_new(CMD_FAILURE, "Unable to allocate bar binding");
	}

	binding->release = false;
	if (strcmp("--release", argv[0]) == 0) {
		binding->release = true;
		argv++;
		argc--;
	}

	char *message = NULL;
	if (code) {
		binding->button = get_mouse_bindcode(argv[0], &message);
	} else {
		binding->button = get_mouse_bindsym(argv[0], &message);
	}
	if (message) {
		free_bar_binding(binding);
		error = cmd_results_new(CMD_INVALID, message);
		free(message);
		return error;
	} else if (!binding->button) {
		free_bar_binding(binding);
		return cmd_results_new(CMD_INVALID, "Unknown button %s", argv[0]);
	}
	list_t *bindings = config->current_bar->bindings;
	if (unbind) {
		return binding_remove(binding, bindings);
	}

	binding->command = join_args(argv + 1, argc - 1);
	return binding_add(binding, bindings);
}

struct cmd_results *bar_cmd_bindcode(int argc, char **argv) {
	return bar_cmd_bind(argc, argv, true, false);
}

struct cmd_results *bar_cmd_bindsym(int argc, char **argv) {
	return bar_cmd_bind(argc, argv, false, false);
}

struct cmd_results *bar_cmd_unbindcode(int argc, char **argv) {
	return bar_cmd_bind(argc, argv, true, true);
}

struct cmd_results *bar_cmd_unbindsym(int argc, char **argv) {
	return bar_cmd_bind(argc, argv, false, true);
}

