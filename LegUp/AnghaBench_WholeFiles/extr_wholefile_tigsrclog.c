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
struct view {struct log_state* private; int /*<<< orphan*/  ref; TYPE_1__* env; } ;
struct log_state {int last_lineno; scalar_t__ last_type; int graph_indent; int commit_title_read; int after_commit_header; int reading_diff_stat; } ;
struct line {int lineno; scalar_t__ type; int graph_indent; } ;
struct buffer {char* data; } ;
typedef  enum status_code { ____Placeholder_status_code } status_code ;
typedef  enum request { ____Placeholder_request } request ;
typedef  enum open_flags { ____Placeholder_open_flags } open_flags ;
typedef  enum line_type { ____Placeholder_line_type } line_type ;
struct TYPE_4__ {int /*<<< orphan*/  vid; } ;
struct TYPE_3__ {int /*<<< orphan*/  commit; } ;

/* Variables and functions */
 scalar_t__ LINE_COMMIT ; 
 int /*<<< orphan*/  OPEN_SPLIT ; 
#define  REQ_ENTER 129 
 int REQ_NONE ; 
#define  REQ_REFRESH 128 
 int /*<<< orphan*/  VIEW_NO_REF ; 
 int abs (int) ; 
 int begin_update (struct view*,int /*<<< orphan*/ *,char const**,int) ; 
 char* box_text (struct line*) ; 
 char* commit_order_arg () ; 
 struct line* diff_common_add_diff_stat (struct view*,char*,int) ; 
 TYPE_2__** display ; 
 char* encoding_arg ; 
 struct line* find_prev_line_by_type (struct view*,struct line*,scalar_t__) ; 
 int get_graph_indent (char const*) ; 
 int get_line_type (char*) ; 
 int /*<<< orphan*/  load_refs (int) ; 
 int /*<<< orphan*/  open_diff_view (struct view*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pager_common_read (struct view*,char*,int,struct line**) ; 
 int /*<<< orphan*/  refresh_view (struct view*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_copy_rev (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_copy_rev_from_commit_line (int /*<<< orphan*/ ,char const*) ; 
 size_t strlen (char*) ; 
 char* strstr (char*,char*) ; 
 int /*<<< orphan*/  view_has_flags (struct view*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
log_copy_rev(struct view *view, struct line *line)
{
	const char *text = box_text(line);
	size_t offset = get_graph_indent(text);

	string_copy_rev_from_commit_line(view->ref, text + offset);
}

__attribute__((used)) static void
log_select(struct view *view, struct line *line)
{
	struct log_state *state = view->private;
	int last_lineno = state->last_lineno;

	if (!last_lineno || abs(last_lineno - line->lineno) > 1
	    || (state->last_type == LINE_COMMIT && last_lineno > line->lineno)) {
		struct line *commit_line = find_prev_line_by_type(view, line, LINE_COMMIT);

		if (commit_line)
			log_copy_rev(view, commit_line);
	}

	if (line->type == LINE_COMMIT && !view_has_flags(view, VIEW_NO_REF))
		log_copy_rev(view, line);
	string_copy_rev(view->env->commit, view->ref);
	state->last_lineno = line->lineno;
	state->last_type = line->type;
}

__attribute__((used)) static enum status_code
log_open(struct view *view, enum open_flags flags)
{
	const char *log_argv[] = {
		"git", "log", encoding_arg, commit_order_arg(), "--cc",
			"--stat", "%(logargs)", "%(cmdlineargs)", "%(revargs)",
			"--no-color", "--", "%(fileargs)", NULL
	};

	return begin_update(view, NULL, log_argv, flags);
}

__attribute__((used)) static enum request
log_request(struct view *view, enum request request, struct line *line)
{
	switch (request) {
	case REQ_REFRESH:
		load_refs(true);
		refresh_view(view);
		return REQ_NONE;

	case REQ_ENTER:
		if (!display[1] || strcmp(display[1]->vid, view->ref))
			open_diff_view(view, OPEN_SPLIT);
		return REQ_NONE;

	default:
		return request;
	}
}

__attribute__((used)) static bool
log_read(struct view *view, struct buffer *buf, bool force_stop)
{
	struct line *line = NULL;
	enum line_type type;
	struct log_state *state = view->private;
	size_t len;
	char *commit;
	char *data;

	if (!buf)
		return true;

	data = buf->data;
	commit = strstr(data, "commit ");
	if (commit && get_graph_indent(data) == commit - data)
		state->graph_indent = commit - data;

	type = get_line_type(data + state->graph_indent);
	len = strlen(data + state->graph_indent);

	if (type == LINE_COMMIT)
		state->commit_title_read = true;
	else if (state->commit_title_read && len < 1) {
		state->commit_title_read = false;
		state->after_commit_header = true;
	} else if (state->after_commit_header && len < 1) {
		state->after_commit_header = false;
		state->reading_diff_stat = true;
	} else if (state->reading_diff_stat) {
		line = diff_common_add_diff_stat(view, data, state->graph_indent);
		if (line) {
			if (state->graph_indent)
				line->graph_indent = 1;
			return true;
		}
		state->reading_diff_stat = false;
	}

	if (!pager_common_read(view, data, type, &line))
		return false;
	if (line && state->graph_indent)
		line->graph_indent = 1;
	return true;
}

