#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct view_column_data {char* text; char* file_name; scalar_t__* line_number; struct view_column* section; } ;
struct TYPE_6__ {scalar_t__ display; } ;
struct TYPE_7__ {TYPE_2__ file_name; } ;
struct view_column {TYPE_3__ opt; int /*<<< orphan*/  type; } ;
struct view {scalar_t__* ref; scalar_t__ lines; struct grep_state* private; TYPE_1__* env; int /*<<< orphan*/  pos; struct view* prev; struct view* parent; } ;
struct line {scalar_t__ type; struct grep_line* data; } ;
struct grep_state {int no_file_group; char* last_file; } ;
struct grep_line {char* file; char* text; scalar_t__ lineno; } ;
struct buffer {char* data; } ;
typedef  enum status_code { ____Placeholder_status_code } status_code ;
typedef  enum request { ____Placeholder_request } request ;
typedef  enum open_flags { ____Placeholder_open_flags } open_flags ;
struct TYPE_8__ {char const* cdup; } ;
struct TYPE_5__ {scalar_t__ goto_lineno; scalar_t__* ref; int /*<<< orphan*/ * blob; scalar_t__ lineno; scalar_t__* file; } ;

/* Variables and functions */
 int ERROR_OUT_OF_MEMORY ; 
 scalar_t__ FILENAME_ALWAYS ; 
 scalar_t__ FILENAME_NO ; 
 scalar_t__ LINE_DEFAULT ; 
 scalar_t__ LINE_DELIMITER ; 
 int /*<<< orphan*/  LINE_FILE ; 
 int OPEN_DEFAULT ; 
 int OPEN_RELOAD ; 
 int OPEN_SPLIT ; 
#define  REQ_EDIT 131 
#define  REQ_ENTER 130 
 int REQ_NONE ; 
#define  REQ_REFRESH 129 
#define  REQ_VIEW_BLAME 128 
 int SIZEOF_ARG ; 
 int /*<<< orphan*/  VIEW_COLUMN_FILE_NAME ; 
 int /*<<< orphan*/  VIEW_COLUMN_TEXT ; 
 struct line* add_line_alloc (struct view*,struct grep_line**,scalar_t__,size_t,int) ; 
 int /*<<< orphan*/ * add_line_nodata (struct view*,scalar_t__) ; 
 int /*<<< orphan*/  add_line_text (struct view*,char const*,int /*<<< orphan*/ ) ; 
 int argv_append_array (char const***,char const**) ; 
 int /*<<< orphan*/  argv_free (char const**) ; 
 int /*<<< orphan*/  argv_from_string_no_quotes (char const**,int*,char*) ; 
 scalar_t__ atoi (char*) ; 
 int begin_update (struct view*,int /*<<< orphan*/ *,char const**,int) ; 
 struct view blob_view ; 
 char* box_text (struct line const*) ; 
 int /*<<< orphan*/  clear_position (int /*<<< orphan*/ *) ; 
 char* get_path (char*) ; 
 struct view_column* get_view_column (struct view*,int /*<<< orphan*/ ) ; 
 char const** grep_args ; 
 char const** grep_argv ; 
 struct view grep_view ; 
 char* io_memchr (struct buffer*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ is_initial_view (struct view*) ; 
 int /*<<< orphan*/  open_argv (struct view*,struct view*,char const**,char const*,int) ; 
 int /*<<< orphan*/  open_editor (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  open_view (struct view*,struct view*,int) ; 
 char** opt_cmdline_args ; 
 char* read_prompt (char*) ; 
 int /*<<< orphan*/  refresh_view (struct view*) ; 
 TYPE_4__ repo ; 
 int /*<<< orphan*/  report (char*) ; 
 int /*<<< orphan*/  report_clear () ; 
 int /*<<< orphan*/  select_view_line (struct view*,scalar_t__) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/  string_ncopy (scalar_t__*,char*,size_t) ; 
 size_t strlen (char*) ; 
 int /*<<< orphan*/  strncpy (char*,char*,size_t) ; 
 int /*<<< orphan*/  update_view_title (struct view*) ; 
 int /*<<< orphan*/  view_column_info_update (struct view*,struct line*) ; 
 int /*<<< orphan*/  view_is_displayed (struct view*) ; 

__attribute__((used)) static struct grep_line *
grep_get_line(const struct line *line)
{
	static struct grep_line grep_line;

	if (line->type == LINE_DEFAULT)
		return line->data;

	grep_line.file = line->type == LINE_DELIMITER ? "" : get_path(box_text(line));
	return &grep_line;
}

__attribute__((used)) static bool
grep_get_column_data(struct view *view, const struct line *line, struct view_column_data *column_data)
{
	struct grep_line *grep = grep_get_line(line);

	if (line->type == LINE_DELIMITER) {
		static struct view_column separator_column;

		separator_column.type = VIEW_COLUMN_TEXT;
		column_data->section = &separator_column;
		column_data->text = "--";
		return true;
	}

	if (*grep->file && !*grep->text) {
		static struct view_column file_name_column;

		file_name_column.type = VIEW_COLUMN_FILE_NAME;
		file_name_column.opt.file_name.display = FILENAME_ALWAYS;

		column_data->section = &file_name_column;
	}

	column_data->line_number = &grep->lineno;
	column_data->file_name = grep->file;
	column_data->text = grep->text;
	return true;
}

__attribute__((used)) static void
grep_select(struct view *view, struct line *line)
{
	struct grep_line *grep = grep_get_line(line);

	if (!*grep->file)
		return;
	view->env->ref[0] = 0;
	string_ncopy(view->env->file, grep->file, strlen(grep->file));
	string_ncopy(view->ref, grep->file, strlen(grep->file));
	view->env->lineno = grep->lineno + 1;
}

__attribute__((used)) static bool
grep_prompt(void)
{
	const char *argv[SIZEOF_ARG];
	int argc = 0;
	char *grep = read_prompt("grep: ");

	report_clear();

	if (!grep || !*grep || !argv_from_string_no_quotes(argv, &argc, grep))
		return false;
	if (grep_argv)
		argv_free(grep_argv);
	return argv_append_array(&grep_argv, argv);
}

void
open_grep_view(struct view *prev)
{
	struct view *view = &grep_view;
	bool in_grep_view = prev == view;

	if ((!prev && is_initial_view(view)) || (view->lines && !in_grep_view)) {
		open_view(prev, view, OPEN_DEFAULT);
	} else {
		if (grep_prompt()) {
			clear_position(&view->pos);
			open_view(prev, view, OPEN_RELOAD);
		}
	}
}

__attribute__((used)) static enum status_code
grep_open(struct view *view, enum open_flags flags)
{
	struct grep_state *state = view->private;
	const char **argv = NULL;

	if (is_initial_view(view)) {
		grep_argv = opt_cmdline_args;
		opt_cmdline_args = NULL;
	}

	if (!argv_append_array(&argv, grep_args) ||
	    !argv_append_array(&argv, grep_argv))
		return ERROR_OUT_OF_MEMORY;

	{
		struct view_column *column = get_view_column(view, VIEW_COLUMN_FILE_NAME);

		state->no_file_group = !column || column->opt.file_name.display != FILENAME_NO;
	}

	return begin_update(view, NULL, argv, flags);
}

__attribute__((used)) static enum request
grep_request(struct view *view, enum request request, struct line *line)
{
	struct grep_state *state = view->private;
	struct grep_line *grep = grep_get_line(line);
	struct view *file_view = &blob_view;

	switch (request) {
	case REQ_REFRESH:
		refresh_view(view);
		return REQ_NONE;

	case REQ_ENTER:
		if (!*grep->file)
			return REQ_NONE;
		if (file_view->parent == view && file_view->prev == view &&
		    state->last_file == grep->file && view_is_displayed(file_view)) {
			if (*grep->text) {
				select_view_line(file_view, grep->lineno);
				update_view_title(file_view);
			}

		} else {
			const char *file_argv[] = { repo.cdup, grep->file, NULL };

			clear_position(&file_view->pos);
			view->env->goto_lineno = grep->lineno;
			view->env->blob[0] = 0;
			open_argv(view, file_view, file_argv, repo.cdup, OPEN_SPLIT | OPEN_RELOAD);
		}
		state->last_file = grep->file;
		return REQ_NONE;

	case REQ_EDIT:
		if (!*grep->file)
			return request;
		open_editor(grep->file, grep->lineno + 1);
		return REQ_NONE;

	case REQ_VIEW_BLAME:
		view->env->ref[0] = 0;
		view->env->goto_lineno = grep->lineno;
		return request;

	default:
		return request;
	}
}

__attribute__((used)) static bool
grep_read(struct view *view, struct buffer *buf, bool force_stop)
{
	struct grep_state *state = view->private;
	struct grep_line *grep;
	char *lineno, *text;
	struct line *line;
	const char *file;
	size_t textlen;

	if (!buf) {
		state->last_file = NULL;
		if (!view->lines) {
			view->ref[0] = 0;
			report("No matches found");
		}
		return true;
	}

	if (!strcmp(buf->data, "--"))
		return add_line_nodata(view, LINE_DELIMITER) != NULL;

	lineno = io_memchr(buf, buf->data, 0);
	text = io_memchr(buf, lineno, 0);

	/*
	 * No data indicates binary file matches, e.g.:
	 *	> git grep vertical- -- test
	 *	test/graph/20-tig-all-long-test:● │ Add "auto" vertical-split
	 *	Binary file test/graph/20-tig-all-long-test.in matches
	 */
	if (!lineno || !text)
		return true;

	textlen = strlen(text);

	file = get_path(buf->data);
	if (!file)
		return false;

	if (!state->no_file_group && file != state->last_file &&
	    !add_line_text(view, file, LINE_FILE))
		return false;

	line = add_line_alloc(view, &grep, LINE_DEFAULT, textlen, false);
	if (!line)
		return false;

	grep->file = file;
	grep->lineno = atoi(lineno);
	if (grep->lineno > 0)
		grep->lineno -= 1;
	strncpy(grep->text, text, textlen + 1);
	view_column_info_update(view, line);

	state->last_file = file;

	return true;
}

