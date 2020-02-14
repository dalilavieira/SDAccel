#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_7__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct sway_container {int dummy; } ;
struct cmd_results {int dummy; } ;
struct bar_config {int /*<<< orphan*/  id; } ;
struct TYPE_9__ {int length; int /*<<< orphan*/ * items; } ;
typedef  TYPE_2__ list_t ;
struct TYPE_11__ {int /*<<< orphan*/  current_config_path; TYPE_1__* bars; } ;
struct TYPE_10__ {int /*<<< orphan*/  wl_event_loop; } ;
struct TYPE_8__ {int length; struct bar_config** items; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_FAILURE ; 
 int /*<<< orphan*/  CMD_SUCCESS ; 
 int /*<<< orphan*/  EXPECTED_EQUAL_TO ; 
 int /*<<< orphan*/  SWAY_ERROR ; 
 int /*<<< orphan*/  arrange_root () ; 
 struct cmd_results* checkarg (int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*) ; 
 TYPE_7__* config ; 
 int /*<<< orphan*/  config_update_font_height (int) ; 
 int /*<<< orphan*/  container_update_marks_textures (struct sway_container*) ; 
 int /*<<< orphan*/  container_update_title_textures (struct sway_container*) ; 
 TYPE_2__* create_list () ; 
 int /*<<< orphan*/  ipc_event_barconfig_update (struct bar_config*) ; 
 int /*<<< orphan*/  ipc_event_workspace (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  list_add (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_free_items_and_destroy (TYPE_2__*) ; 
 int /*<<< orphan*/  load_main_config (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  load_swaybars () ; 
 int /*<<< orphan*/  root_for_each_container (void (*) (struct sway_container*,void*),int /*<<< orphan*/ *) ; 
 TYPE_3__ server ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strdup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  wl_event_loop_add_idle (int /*<<< orphan*/ ,void (*) (void*),int /*<<< orphan*/ *) ; 

__attribute__((used)) static void rebuild_textures_iterator(struct sway_container *con, void *data) {
	container_update_marks_textures(con);
	container_update_title_textures(con);
}

__attribute__((used)) static void do_reload(void *data) {
	// store bar ids to check against new bars for barconfig_update events
	list_t *bar_ids = create_list();
	for (int i = 0; i < config->bars->length; ++i) {
		struct bar_config *bar = config->bars->items[i];
		list_add(bar_ids, strdup(bar->id));
	}

	if (!load_main_config(config->current_config_path, true, false)) {
		sway_log(SWAY_ERROR, "Error(s) reloading config");
		list_free_items_and_destroy(bar_ids);
		return;
	}

	ipc_event_workspace(NULL, NULL, "reload");

	load_swaybars();

	for (int i = 0; i < config->bars->length; ++i) {
		struct bar_config *bar = config->bars->items[i];
		for (int j = 0; j < bar_ids->length; ++j) {
			if (strcmp(bar->id, bar_ids->items[j]) == 0) {
				ipc_event_barconfig_update(bar);
				break;
			}
		}
	}
	list_free_items_and_destroy(bar_ids);

	config_update_font_height(true);
	root_for_each_container(rebuild_textures_iterator, NULL);

	arrange_root();
}

struct cmd_results *cmd_reload(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "reload", EXPECTED_EQUAL_TO, 0))) {
		return error;
	}

	if (!load_main_config(config->current_config_path, true, true)) {
		return cmd_results_new(CMD_FAILURE, "Error(s) reloading config.");
	}

	// The reload command frees a lot of stuff, so to avoid use-after-frees
	// we schedule the reload to happen using an idle event.
	wl_event_loop_add_idle(server.wl_event_loop, do_reload, NULL);

	return cmd_results_new(CMD_SUCCESS, NULL);
}

