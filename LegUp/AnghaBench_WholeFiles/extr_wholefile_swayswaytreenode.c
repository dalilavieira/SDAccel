#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct wlr_box {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  destroy; } ;
struct sway_node {int type; int dirty; struct sway_container* sway_container; struct sway_workspace* sway_workspace; struct sway_output* sway_output; TYPE_1__ events; void* sway_root; int /*<<< orphan*/  id; } ;
struct sway_workspace {char* name; int layout; int /*<<< orphan*/ * tiling; struct sway_output* output; struct sway_node node; } ;
struct sway_output {struct sway_node node; TYPE_2__* wlr_output; } ;
struct sway_container {char* title; int layout; scalar_t__ fullscreen_mode; int /*<<< orphan*/ * children; struct sway_workspace* workspace; TYPE_3__* parent; scalar_t__ view; } ;
typedef  int /*<<< orphan*/  list_t ;
typedef  enum sway_node_type { ____Placeholder_sway_node_type } sway_node_type ;
typedef  enum sway_container_layout { ____Placeholder_sway_container_layout } sway_container_layout ;
struct TYPE_11__ {struct sway_node node; } ;
struct TYPE_10__ {int /*<<< orphan*/  dirty_nodes; } ;
struct TYPE_9__ {struct sway_node node; } ;
struct TYPE_8__ {char* name; } ;

/* Variables and functions */
 scalar_t__ FULLSCREEN_GLOBAL ; 
 int L_NONE ; 
#define  N_CONTAINER 131 
#define  N_OUTPUT 130 
#define  N_ROOT 129 
#define  N_WORKSPACE 128 
 int /*<<< orphan*/  container_get_box (struct sway_container*,struct wlr_box*) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ ,struct sway_node*) ; 
 int /*<<< orphan*/  output_get_box (struct sway_output*,struct wlr_box*) ; 
 TYPE_5__* root ; 
 int /*<<< orphan*/  root_get_box (TYPE_5__*,struct wlr_box*) ; 
 TYPE_4__ server ; 
 int /*<<< orphan*/  wl_signal_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  workspace_get_box (struct sway_workspace*,struct wlr_box*) ; 

void node_init(struct sway_node *node, enum sway_node_type type, void *thing) {
	static size_t next_id = 1;
	node->id = next_id++;
	node->type = type;
	node->sway_root = thing;
	wl_signal_init(&node->events.destroy);
}

const char *node_type_to_str(enum sway_node_type type) {
	switch (type) {
	case N_ROOT:
		return "N_ROOT";
	case N_OUTPUT:
		return "N_OUTPUT";
	case N_WORKSPACE:
		return "N_WORKSPACE";
	case N_CONTAINER:
		return "N_CONTAINER";
	}
	return "";
}

void node_set_dirty(struct sway_node *node) {
	if (node->dirty) {
		return;
	}
	node->dirty = true;
	list_add(server.dirty_nodes, node);
}

bool node_is_view(struct sway_node *node) {
	return node->type == N_CONTAINER && node->sway_container->view;
}

char *node_get_name(struct sway_node *node) {
	switch (node->type) {
	case N_ROOT:
		return "root";
	case N_OUTPUT:
		return node->sway_output->wlr_output->name;
	case N_WORKSPACE:
		return node->sway_workspace->name;
	case N_CONTAINER:
		return node->sway_container->title;
	}
	return NULL;
}

void node_get_box(struct sway_node *node, struct wlr_box *box) {
	switch (node->type) {
	case N_ROOT:
		root_get_box(root, box);
		break;
	case N_OUTPUT:
		output_get_box(node->sway_output, box);
		break;
	case N_WORKSPACE:
		workspace_get_box(node->sway_workspace, box);
		break;
	case N_CONTAINER:
		container_get_box(node->sway_container, box);
		break;
	}
}

struct sway_output *node_get_output(struct sway_node *node) {
	switch (node->type) {
	case N_CONTAINER: {
		struct sway_workspace *ws = node->sway_container->workspace;
		return ws ? ws->output : NULL;
    }
	case N_WORKSPACE:
		return node->sway_workspace->output;
	case N_OUTPUT:
		return node->sway_output;
	case N_ROOT:
		return NULL;
	}
	return NULL;
}

enum sway_container_layout node_get_layout(struct sway_node *node) {
	switch (node->type) {
	case N_CONTAINER:
		return node->sway_container->layout;
	case N_WORKSPACE:
		return node->sway_workspace->layout;
	case N_OUTPUT:
	case N_ROOT:
		return L_NONE;
	}
	return L_NONE;
}

struct sway_node *node_get_parent(struct sway_node *node) {
	switch (node->type) {
	case N_CONTAINER: {
			struct sway_container *con = node->sway_container;
			if (con->parent) {
				return &con->parent->node;
			}
			if (con->workspace) {
				return &con->workspace->node;
			}
		}
		return NULL;
	case N_WORKSPACE: {
			struct sway_workspace *ws = node->sway_workspace;
			if (ws->output) {
				return &ws->output->node;
			}
		}
		return NULL;
	case N_OUTPUT:
		return &root->node;
	case N_ROOT:
		return NULL;
	}
	return NULL;
}

list_t *node_get_children(struct sway_node *node) {
	switch (node->type) {
	case N_CONTAINER:
		return node->sway_container->children;
	case N_WORKSPACE:
		return node->sway_workspace->tiling;
	case N_OUTPUT:
	case N_ROOT:
		return NULL;
	}
	return NULL;
}

bool node_has_ancestor(struct sway_node *node, struct sway_node *ancestor) {
	if (ancestor->type == N_ROOT && node->type == N_CONTAINER &&
			node->sway_container->fullscreen_mode == FULLSCREEN_GLOBAL) {
		return true;
	}
	struct sway_node *parent = node_get_parent(node);
	while (parent) {
		if (parent == ancestor) {
			return true;
		}
		if (ancestor->type == N_ROOT && parent->type == N_CONTAINER &&
				parent->sway_container->fullscreen_mode == FULLSCREEN_GLOBAL) {
			return true;
		}
		parent = node_get_parent(parent);
	}
	return false;
}

