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
typedef  int /*<<< orphan*/  u_int ;
struct window_pane {int /*<<< orphan*/  id; } ;
struct session {int /*<<< orphan*/  options; } ;
struct cmdq_item {int /*<<< orphan*/  flags; } ;
struct cmd_list {int dummy; } ;
struct cmd {struct args* args; } ;
struct client {void (* identify_callback ) (struct client*,struct window_pane*) ;char* identify_callback_data; struct cmdq_item* identify_callback_item; struct session* session; } ;
struct args {scalar_t__ argc; char** argv; } ;
typedef  enum cmd_retval { ____Placeholder_cmd_retval } cmd_retval ;

/* Variables and functions */
 int /*<<< orphan*/  CMDQ_WAITING ; 
 int CMD_RETURN_ERROR ; 
 int CMD_RETURN_NORMAL ; 
 int CMD_RETURN_WAIT ; 
 int /*<<< orphan*/  UINT_MAX ; 
 int /*<<< orphan*/  args_get (struct args*,char) ; 
 scalar_t__ args_has (struct args*,char) ; 
 int /*<<< orphan*/  args_strtonum (struct args*,char,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char**) ; 
static  void cmd_display_panes_callback (struct client*,struct window_pane*) ; 
 struct client* cmd_find_client (struct cmdq_item*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cmd_list_free (struct cmd_list*) ; 
 struct cmd_list* cmd_string_parse (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char**) ; 
 char* cmd_template_replace (char*,char*,int) ; 
 int /*<<< orphan*/  cmdq_append (struct client*,struct cmdq_item*) ; 
 int /*<<< orphan*/  cmdq_error (struct cmdq_item*,char*,char*) ; 
 struct cmdq_item* cmdq_get_callback (int (*) (struct cmdq_item*,void*),char*) ; 
 struct cmdq_item* cmdq_get_command (struct cmd_list*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cmdq_insert_after (struct cmdq_item*,struct cmdq_item*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  options_get_number (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  server_client_set_identify (struct client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xasprintf (char**,char*,int /*<<< orphan*/ ) ; 
 void* xstrdup (char*) ; 

__attribute__((used)) static enum cmd_retval
cmd_display_panes_exec(struct cmd *self, struct cmdq_item *item)
{
	struct args	*args = self->args;
	struct client	*c;
	struct session	*s;
	u_int		 delay;
	char		*cause;

	if ((c = cmd_find_client(item, args_get(args, 't'), 0)) == NULL)
		return (CMD_RETURN_ERROR);
	s = c->session;

	if (c->identify_callback != NULL)
		return (CMD_RETURN_NORMAL);

	c->identify_callback = cmd_display_panes_callback;
	if (args->argc != 0)
		c->identify_callback_data = xstrdup(args->argv[0]);
	else
		c->identify_callback_data = xstrdup("select-pane -t '%%'");
	if (args_has(args, 'b'))
		c->identify_callback_item = NULL;
	else
		c->identify_callback_item = item;

	if (args_has(args, 'd')) {
		delay = args_strtonum(args, 'd', 0, UINT_MAX, &cause);
		if (cause != NULL) {
			cmdq_error(item, "delay %s", cause);
			free(cause);
			return (CMD_RETURN_ERROR);
		}
	} else
		delay = options_get_number(s->options, "display-panes-time");
	server_client_set_identify(c, delay);

	if (args_has(args, 'b'))
		return (CMD_RETURN_NORMAL);
	return (CMD_RETURN_WAIT);
}

__attribute__((used)) static enum cmd_retval
cmd_display_panes_error(struct cmdq_item *item, void *data)
{
	char	*error = data;

	cmdq_error(item, "%s", error);
	free(error);

	return (CMD_RETURN_NORMAL);
}

__attribute__((used)) static void
cmd_display_panes_callback(struct client *c, struct window_pane *wp)
{
	struct cmd_list		*cmdlist;
	struct cmdq_item	*new_item;
	char			*cmd, *expanded, *cause;

	if (wp == NULL)
		goto out;

	xasprintf(&expanded, "%%%u", wp->id);
	cmd = cmd_template_replace(c->identify_callback_data, expanded, 1);

	cmdlist = cmd_string_parse(cmd, NULL, 0, &cause);
	if (cmdlist == NULL && cause != NULL)
		new_item = cmdq_get_callback(cmd_display_panes_error, cause);
	else if (cmdlist == NULL)
		new_item = NULL;
	else {
		new_item = cmdq_get_command(cmdlist, NULL, NULL, 0);
		cmd_list_free(cmdlist);
	}

	if (new_item != NULL) {
		if (c->identify_callback_item != NULL)
			cmdq_insert_after(c->identify_callback_item, new_item);
		else
			cmdq_append(c, new_item);
	}

	free(cmd);
	free(expanded);

out:
	if (c->identify_callback_item != NULL) {
		c->identify_callback_item->flags &= ~CMDQ_WAITING;
		c->identify_callback_item = NULL;
	}

	free(c->identify_callback_data);
	c->identify_callback_data = NULL;

	c->identify_callback = NULL;
}

