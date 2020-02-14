#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct wlr_output {int /*<<< orphan*/  transform; } ;
struct sway_output {struct wlr_output* wlr_output; } ;
struct output_config {char* name; int transform; } ;
struct cmd_results {int dummy; } ;
typedef  enum wl_output_transform { ____Placeholder_wl_output_transform } wl_output_transform ;
struct TYPE_4__ {int argc; char** argv; } ;
struct TYPE_5__ {TYPE_1__ leftovers; struct output_config* output_config; } ;
struct TYPE_6__ {TYPE_2__ handler_context; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_FAILURE ; 
 int /*<<< orphan*/  CMD_INVALID ; 
 int WL_OUTPUT_TRANSFORM_180 ; 
 int WL_OUTPUT_TRANSFORM_270 ; 
 int WL_OUTPUT_TRANSFORM_90 ; 
 int WL_OUTPUT_TRANSFORM_FLIPPED ; 
 int WL_OUTPUT_TRANSFORM_FLIPPED_180 ; 
 int WL_OUTPUT_TRANSFORM_FLIPPED_270 ; 
 int WL_OUTPUT_TRANSFORM_FLIPPED_90 ; 
 int WL_OUTPUT_TRANSFORM_NORMAL ; 
 struct cmd_results* cmd_results_new (int /*<<< orphan*/ ,char*,...) ; 
 TYPE_3__* config ; 
 struct sway_output* output_by_name_or_id (char*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  sway_assert (int /*<<< orphan*/ ,char*) ; 
 int wlr_output_transform_compose (int /*<<< orphan*/ ,int) ; 
 int wlr_output_transform_invert (int) ; 

struct cmd_results *output_cmd_transform(int argc, char **argv) {
	if (!config->handler_context.output_config) {
		return cmd_results_new(CMD_FAILURE, "Missing output config");
	}
	if (!argc) {
		return cmd_results_new(CMD_INVALID, "Missing transform argument.");
	}
	enum wl_output_transform transform;
	if (strcmp(*argv, "normal") == 0 ||
			strcmp(*argv, "0") == 0) {
		transform = WL_OUTPUT_TRANSFORM_NORMAL;
	} else if (strcmp(*argv, "90") == 0) {
		transform = WL_OUTPUT_TRANSFORM_90;
	} else if (strcmp(*argv, "180") == 0) {
		transform = WL_OUTPUT_TRANSFORM_180;
	} else if (strcmp(*argv, "270") == 0) {
		transform = WL_OUTPUT_TRANSFORM_270;
	} else if (strcmp(*argv, "flipped") == 0) {
		transform = WL_OUTPUT_TRANSFORM_FLIPPED;
	} else if (strcmp(*argv, "flipped-90") == 0) {
		transform = WL_OUTPUT_TRANSFORM_FLIPPED_90;
	} else if (strcmp(*argv, "flipped-180") == 0) {
		transform = WL_OUTPUT_TRANSFORM_FLIPPED_180;
	} else if (strcmp(*argv, "flipped-270") == 0) {
		transform = WL_OUTPUT_TRANSFORM_FLIPPED_270;
	} else {
		return cmd_results_new(CMD_INVALID, "Invalid output transform.");
	}
	struct output_config *output = config->handler_context.output_config;
	config->handler_context.leftovers.argc = argc - 1;
	config->handler_context.leftovers.argv = argv + 1;
	if (argc > 1 &&
			(strcmp(argv[1], "clockwise") == 0 || strcmp(argv[1], "anticlockwise") == 0)) {
		if (!sway_assert(output->name != NULL, "Output config name not set")) {
			return NULL;
		}
		if (strcmp(output->name, "*") == 0) {
			return cmd_results_new(CMD_INVALID,
				"Cannot apply relative transform to all outputs.");
		}
		struct sway_output *s_output = output_by_name_or_id(output->name);
		if (s_output == NULL) {
			return cmd_results_new(CMD_INVALID,
				"Cannot apply relative transform to unknown output %s", output->name);
		}
		if (strcmp(argv[1], "anticlockwise") == 0) {
			transform = wlr_output_transform_invert(transform);
		}
		struct wlr_output *w_output = s_output->wlr_output;
		transform = wlr_output_transform_compose(w_output->transform, transform);
		config->handler_context.leftovers.argv += 1;
		config->handler_context.leftovers.argc -= 1;
	}
	output->transform = transform;
	return NULL;
}

