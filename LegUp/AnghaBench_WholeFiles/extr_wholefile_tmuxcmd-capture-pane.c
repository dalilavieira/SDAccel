#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u_int ;
struct TYPE_4__ {struct grid* grid; } ;
struct window_pane {TYPE_2__ base; struct grid* saved_grid; } ;
struct grid_line {int flags; } ;
struct grid_cell {int dummy; } ;
struct grid {size_t hsize; int sy; } ;
struct evbuffer {int dummy; } ;
struct TYPE_3__ {struct window_pane* wp; } ;
struct cmdq_item {struct client* client; TYPE_1__ target; } ;
struct cmd {int /*<<< orphan*/ * entry; struct args* args; } ;
struct client {int flags; int /*<<< orphan*/  stdout_data; int /*<<< orphan*/ * session; } ;
struct args {int dummy; } ;
typedef  enum cmd_retval { ____Placeholder_cmd_retval } cmd_retval ;

/* Variables and functions */
 int CLIENT_CONTROL ; 
 int CMD_RETURN_ERROR ; 
 int CMD_RETURN_NORMAL ; 
 char* EVBUFFER_DATA (struct evbuffer*) ; 
 size_t EVBUFFER_LENGTH (struct evbuffer*) ; 
 int GRID_LINE_WRAPPED ; 
 int /*<<< orphan*/  INT_MIN ; 
 int /*<<< orphan*/  SHRT_MAX ; 
 char* args_get (struct args*,char) ; 
 int args_has (struct args*,char) ; 
 int args_strtonum (struct args*,char,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char**) ; 
 int /*<<< orphan*/  cmd_clear_history_entry ; 
 int /*<<< orphan*/  cmdq_error (struct cmdq_item*,char*,...) ; 
 int /*<<< orphan*/  evbuffer_add (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  grid_clear_history (struct grid*) ; 
 struct grid_line* grid_peek_line (struct grid*,size_t) ; 
 char* grid_string_cells (struct grid*,int /*<<< orphan*/ ,size_t,size_t,struct grid_cell**,int,int,int) ; 
 struct evbuffer* input_pending (struct window_pane*) ; 
 int /*<<< orphan*/  memcpy (char*,char*,size_t) ; 
 scalar_t__ paste_set (char*,size_t,char const*,char**) ; 
 size_t screen_size_x (TYPE_2__*) ; 
 int /*<<< orphan*/  server_client_push_stdout (struct client*) ; 
 scalar_t__ strcmp (char const*,char*) ; 
 size_t strlen (char*) ; 
 int /*<<< orphan*/  window_pane_reset_mode_all (struct window_pane*) ; 
 char* xrealloc (char*,size_t) ; 
 int /*<<< orphan*/  xsnprintf (char*,int,char*,char) ; 
 char* xstrdup (char*) ; 

__attribute__((used)) static char *
cmd_capture_pane_append(char *buf, size_t *len, char *line, size_t linelen)
{
	buf = xrealloc(buf, *len + linelen + 1);
	memcpy(buf + *len, line, linelen);
	*len += linelen;
	return (buf);
}

__attribute__((used)) static char *
cmd_capture_pane_pending(struct args *args, struct window_pane *wp,
    size_t *len)
{
	struct evbuffer	*pending;
	char		*buf, *line, tmp[5];
	size_t		 linelen;
	u_int		 i;

	pending = input_pending(wp);
	if (pending == NULL)
		return (xstrdup(""));

	line = EVBUFFER_DATA(pending);
	linelen = EVBUFFER_LENGTH(pending);

	buf = xstrdup("");
	if (args_has(args, 'C')) {
		for (i = 0; i < linelen; i++) {
			if (line[i] >= ' ' && line[i] != '\\') {
				tmp[0] = line[i];
				tmp[1] = '\0';
			} else
				xsnprintf(tmp, sizeof tmp, "\\%03hho", line[i]);
			buf = cmd_capture_pane_append(buf, len, tmp,
			    strlen(tmp));
		}
	} else
		buf = cmd_capture_pane_append(buf, len, line, linelen);
	return (buf);
}

__attribute__((used)) static char *
cmd_capture_pane_history(struct args *args, struct cmdq_item *item,
    struct window_pane *wp, size_t *len)
{
	struct grid		*gd;
	const struct grid_line	*gl;
	struct grid_cell	*gc = NULL;
	int			 n, with_codes, escape_c0, join_lines;
	u_int			 i, sx, top, bottom, tmp;
	char			*cause, *buf, *line;
	const char		*Sflag, *Eflag;
	size_t			 linelen;

	sx = screen_size_x(&wp->base);
	if (args_has(args, 'a')) {
		gd = wp->saved_grid;
		if (gd == NULL) {
			if (!args_has(args, 'q')) {
				cmdq_error(item, "no alternate screen");
				return (NULL);
			}
			return (xstrdup(""));
		}
	} else
		gd = wp->base.grid;

	Sflag = args_get(args, 'S');
	if (Sflag != NULL && strcmp(Sflag, "-") == 0)
		top = 0;
	else {
		n = args_strtonum(args, 'S', INT_MIN, SHRT_MAX, &cause);
		if (cause != NULL) {
			top = gd->hsize;
			free(cause);
		} else if (n < 0 && (u_int) -n > gd->hsize)
			top = 0;
		else
			top = gd->hsize + n;
		if (top > gd->hsize + gd->sy - 1)
			top = gd->hsize + gd->sy - 1;
	}

	Eflag = args_get(args, 'E');
	if (Eflag != NULL && strcmp(Eflag, "-") == 0)
		bottom = gd->hsize + gd->sy - 1;
	else {
		n = args_strtonum(args, 'E', INT_MIN, SHRT_MAX, &cause);
		if (cause != NULL) {
			bottom = gd->hsize + gd->sy - 1;
			free(cause);
		} else if (n < 0 && (u_int) -n > gd->hsize)
			bottom = 0;
		else
			bottom = gd->hsize + n;
		if (bottom > gd->hsize + gd->sy - 1)
			bottom = gd->hsize + gd->sy - 1;
	}

	if (bottom < top) {
		tmp = bottom;
		bottom = top;
		top = tmp;
	}

	with_codes = args_has(args, 'e');
	escape_c0 = args_has(args, 'C');
	join_lines = args_has(args, 'J');

	buf = NULL;
	for (i = top; i <= bottom; i++) {
		line = grid_string_cells(gd, 0, i, sx, &gc, with_codes,
		    escape_c0, !join_lines);
		linelen = strlen(line);

		buf = cmd_capture_pane_append(buf, len, line, linelen);

		gl = grid_peek_line(gd, i);
		if (!join_lines || !(gl->flags & GRID_LINE_WRAPPED))
			buf[(*len)++] = '\n';

		free(line);
	}
	return (buf);
}

__attribute__((used)) static enum cmd_retval
cmd_capture_pane_exec(struct cmd *self, struct cmdq_item *item)
{
	struct args		*args = self->args;
	struct client		*c;
	struct window_pane	*wp = item->target.wp;
	char			*buf, *cause;
	const char		*bufname;
	size_t			 len;

	if (self->entry == &cmd_clear_history_entry) {
		window_pane_reset_mode_all(wp);
		grid_clear_history(wp->base.grid);
		return (CMD_RETURN_NORMAL);
	}

	len = 0;
	if (args_has(args, 'P'))
		buf = cmd_capture_pane_pending(args, wp, &len);
	else
		buf = cmd_capture_pane_history(args, item, wp, &len);
	if (buf == NULL)
		return (CMD_RETURN_ERROR);

	if (args_has(args, 'p')) {
		c = item->client;
		if (c == NULL ||
		    (c->session != NULL && !(c->flags & CLIENT_CONTROL))) {
			cmdq_error(item, "can't write to stdout");
			free(buf);
			return (CMD_RETURN_ERROR);
		}
		evbuffer_add(c->stdout_data, buf, len);
		free(buf);
		if (args_has(args, 'P') && len > 0)
		    evbuffer_add(c->stdout_data, "\n", 1);
		server_client_push_stdout(c);
	} else {
		bufname = NULL;
		if (args_has(args, 'b'))
			bufname = args_get(args, 'b');

		if (paste_set(buf, len, bufname, &cause) != 0) {
			cmdq_error(item, "%s", cause);
			free(cause);
			free(buf);
			return (CMD_RETURN_ERROR);
		}
	}

	return (CMD_RETURN_NORMAL);
}

