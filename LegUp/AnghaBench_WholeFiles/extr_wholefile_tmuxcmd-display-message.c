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
struct winlink {int dummy; } ;
struct window_pane {int dummy; } ;
struct session {int dummy; } ;
struct format_tree {int dummy; } ;
struct TYPE_2__ {struct window_pane* wp; struct winlink* wl; struct session* s; } ;
struct cmdq_item {int /*<<< orphan*/  client; TYPE_1__ target; } ;
struct cmd {struct args* args; } ;
struct client {struct session* session; } ;
struct args {scalar_t__ argc; char** argv; } ;
typedef  enum cmd_retval { ____Placeholder_cmd_retval } cmd_retval ;

/* Variables and functions */
 int CMD_RETURN_ERROR ; 
 int CMD_RETURN_NORMAL ; 
 char* DISPLAY_MESSAGE_TEMPLATE ; 
 int /*<<< orphan*/  FORMAT_NONE ; 
 int FORMAT_VERBOSE ; 
 char* args_get (struct args*,char) ; 
 scalar_t__ args_has (struct args*,char) ; 
 struct client* cmd_find_best_client (struct session*) ; 
 struct client* cmd_find_client (struct cmdq_item*,char*,int) ; 
 int /*<<< orphan*/  cmdq_error (struct cmdq_item*,char*) ; 
 int /*<<< orphan*/  cmdq_print (struct cmdq_item*,char*,char const*,...) ; 
 struct format_tree* format_create (int /*<<< orphan*/ ,struct cmdq_item*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  format_defaults (struct format_tree*,struct client*,struct session*,struct winlink*,struct window_pane*) ; 
 int /*<<< orphan*/  format_each (struct format_tree*,void (*) (char const*,char const*,void*),struct cmdq_item*) ; 
 char* format_expand_time (struct format_tree*,char const*) ; 
 int /*<<< orphan*/  format_free (struct format_tree*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  status_message_set (struct client*,char*,char*) ; 

__attribute__((used)) static void
cmd_display_message_each(const char *key, const char *value, void *arg)
{
	struct cmdq_item	*item = arg;

	cmdq_print(item, "%s=%s", key, value);
}

__attribute__((used)) static enum cmd_retval
cmd_display_message_exec(struct cmd *self, struct cmdq_item *item)
{
	struct args		*args = self->args;
	struct client		*c, *target_c;
	struct session		*s = item->target.s;
	struct winlink		*wl = item->target.wl;
	struct window_pane	*wp = item->target.wp;
	const char		*template;
	char			*msg;
	struct format_tree	*ft;
	int			 flags;

	if (args_has(args, 'F') && args->argc != 0) {
		cmdq_error(item, "only one of -F or argument must be given");
		return (CMD_RETURN_ERROR);
	}

	template = args_get(args, 'F');
	if (args->argc != 0)
		template = args->argv[0];
	if (template == NULL)
		template = DISPLAY_MESSAGE_TEMPLATE;

	/*
	 * -c is intended to be the client where the message should be
	 * displayed if -p is not given. But it makes sense to use it for the
	 * formats too, assuming it matches the session. If it doesn't, use the
	 * best client for the session.
	 */
	c = cmd_find_client(item, args_get(args, 'c'), 1);
	if (c != NULL && c->session == s)
		target_c = c;
	else
		target_c = cmd_find_best_client(s);
	if (args_has(self->args, 'v'))
		flags = FORMAT_VERBOSE;
	else
		flags = 0;
	ft = format_create(item->client, item, FORMAT_NONE, flags);
	format_defaults(ft, target_c, s, wl, wp);

	if (args_has(args, 'a')) {
		if (item != NULL)
			format_each(ft, cmd_display_message_each, item);
		return (CMD_RETURN_NORMAL);
	}

	msg = format_expand_time(ft, template);
	if (args_has(self->args, 'p'))
		cmdq_print(item, "%s", msg);
	else if (c != NULL)
		status_message_set(c, "%s", msg);
	free(msg);

	format_free(ft);

	return (CMD_RETURN_NORMAL);
}

