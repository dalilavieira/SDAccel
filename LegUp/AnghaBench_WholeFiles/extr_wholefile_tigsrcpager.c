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
struct view_column_data {int /*<<< orphan*/  box; void* text; } ;
struct view {int lines; TYPE_1__* env; int /*<<< orphan*/  ref; struct diff_state* private; struct line const* line; scalar_t__ width; } ;
struct ref_format {int /*<<< orphan*/  end; int /*<<< orphan*/  start; } ;
struct ref {int /*<<< orphan*/  name; struct ref* next; } ;
typedef  struct line {size_t lineno; int wrapped; scalar_t__ type; int /*<<< orphan*/  data; } const line ;
struct diff_state {int combined_diff; int reading_diff_chunk; } ;
struct buffer {char* data; } ;
typedef  enum status_code { ____Placeholder_status_code } status_code ;
typedef  enum request { ____Placeholder_request } request ;
typedef  enum open_flags { ____Placeholder_open_flags } open_flags ;
typedef  enum line_type { ____Placeholder_line_type } line_type ;
struct TYPE_2__ {int /*<<< orphan*/  commit; int /*<<< orphan*/  text; } ;

/* Variables and functions */
 scalar_t__ LINE_COMMIT ; 
 int LINE_DEFAULT ; 
 int LINE_DIFF_ADD ; 
 int LINE_DIFF_ADD2 ; 
 int LINE_DIFF_ADD_FILE ; 
 int LINE_DIFF_CHUNK ; 
 int LINE_DIFF_DEL ; 
 int LINE_DIFF_DEL2 ; 
 int LINE_DIFF_DEL_FILE ; 
 int LINE_DIFF_HEADER ; 
 int LINE_DIFF_START ; 
 int LINE_PP_MERGE ; 
 int LINE_PP_REFS ; 
 int OPEN_PREPARED ; 
 int /*<<< orphan*/  OPEN_SPLIT ; 
 int REQ_ENTER ; 
 int REQ_NONE ; 
 int /*<<< orphan*/  REQ_PROMPT ; 
 int /*<<< orphan*/  REQ_SCROLL_LINE_DOWN ; 
 int SIZEOF_STR ; 
 int STRING_SIZE (char*) ; 
 int /*<<< orphan*/  VIEW_ADD_DESCRIBE_REF ; 
 int /*<<< orphan*/  VIEW_ADD_PAGER_REFS ; 
 int /*<<< orphan*/  VIEW_NO_REF ; 
 int /*<<< orphan*/  VIEW_OPEN_DIFF ; 
 struct line const* add_line_text (struct view*,char const*,int) ; 
 struct line const* add_line_text_at_ (struct view*,int,char const*,size_t,int,int,int) ; 
 int begin_update (struct view*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 void* box_text (struct line const*) ; 
 int error (char*,int /*<<< orphan*/ ) ; 
 int get_line_type (char*) ; 
 struct ref_format* get_ref_format (int /*<<< orphan*/ ,struct ref const*) ; 
 struct ref* get_ref_list (char const*) ; 
 int /*<<< orphan*/  get_view_key (struct view*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  open_diff_view (struct view*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  open_from_stdin (int) ; 
 int /*<<< orphan*/  opt_reference_format ; 
 int /*<<< orphan*/  opt_tab_size ; 
 scalar_t__ opt_wrap_lines ; 
 scalar_t__ refs_contain_tag () ; 
 int /*<<< orphan*/  scroll_view (struct view*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_copy_rev (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_copy_rev_from_commit_line (int /*<<< orphan*/ ,char const*) ; 
 size_t string_expanded_length (char const*,size_t,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  string_format_from (char*,size_t*,char*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_ncopy (int /*<<< orphan*/ ,char const*,size_t) ; 
 size_t strlen (char const*) ; 
 int /*<<< orphan*/  strncmp (char const*,char*,size_t) ; 
 int /*<<< orphan*/  update_view_title (struct view*) ; 
 scalar_t__ view_has_flags (struct view*,int /*<<< orphan*/ ) ; 

bool
pager_get_column_data(struct view *view, const struct line *line, struct view_column_data *column_data)
{
	column_data->text = box_text(line);
	column_data->box = line->data;
	return true;
}

__attribute__((used)) static void
add_pager_refs(struct view *view, const char *commit_id)
{
	char buf[SIZEOF_STR];
	const struct ref *list;
	size_t bufpos = 0;
	const char *sep = "Refs: ";

	list = get_ref_list(commit_id);
	if (!list) {
		if (view_has_flags(view, VIEW_ADD_DESCRIBE_REF) && refs_contain_tag())
			add_line_text(view, sep, LINE_PP_REFS);
		return;
	}

	for (; list; list = list->next) {
		const struct ref *ref = list;
		const struct ref_format *fmt = get_ref_format(opt_reference_format, ref);

		if (!string_format_from(buf, &bufpos, "%s%s%s%s", sep,
					fmt->start, ref->name, fmt->end))
			return;
		sep = ", ";
	}

	if (bufpos == 0)
		return;

	add_line_text(view, buf, LINE_PP_REFS);
}

__attribute__((used)) static struct line *
pager_wrap_line(struct view *view, const char *data, enum line_type type)
{
	size_t first_line = 0;
	bool has_first_line = false;
	size_t datalen = strlen(data);
	size_t lineno = 0;

	while (datalen > 0 || !has_first_line) {
		bool wrapped = !!first_line;
		size_t linelen = string_expanded_length(data, datalen, opt_tab_size, view->width - !!wrapped);
		struct line *line;

		line = add_line_text_at_(view, view->lines, data, linelen, type, 1, wrapped);
		if (!line)
			break;
		if (!has_first_line) {
			first_line = view->lines - 1;
			has_first_line = true;
		}

		if (!wrapped)
			lineno = line->lineno;

		line->wrapped = wrapped;
		line->lineno = lineno;

		datalen -= linelen;
		data += linelen;
	}

	return has_first_line ? &view->line[first_line] : NULL;
}

bool
pager_common_read(struct view *view, const char *data, enum line_type type, struct line **line_ptr)
{
	struct diff_state *state = view->private;
	struct line *line;

	if (!data)
		return true;

	if (type == LINE_DIFF_HEADER) {
		const int len = STRING_SIZE("diff --");

		if (!strncmp(data + len, "combined ", strlen("combined ")) ||
		    !strncmp(data + len, "cc ", strlen("cc ")))
			state->combined_diff = true;
		state->reading_diff_chunk = false;

	} else if (type == LINE_DIFF_CHUNK) {
		state->reading_diff_chunk = true;

	} else if (type == LINE_PP_MERGE) {
		state->combined_diff = true;
	}

	/* ADD2 and DEL2 are only valid in combined diff hunks */
	if (!state->combined_diff && (type == LINE_DIFF_ADD2 || type == LINE_DIFF_DEL2))
		type = LINE_DEFAULT;

	/* DEL_FILE, ADD_FILE and START are only valid outside diff chunks */
	if (state->reading_diff_chunk) {
		if (type == LINE_DIFF_DEL_FILE || type == LINE_DIFF_START)
			type = LINE_DIFF_DEL;
		else if (type == LINE_DIFF_ADD_FILE)
			type = LINE_DIFF_ADD;
	}

	if (opt_wrap_lines) {
		line = pager_wrap_line(view, data, type);
	} else {
		line = add_line_text(view, data, type);
	}

	if (!line)
		return false;

	if (line_ptr)
		*line_ptr = line;

	if (line->type == LINE_COMMIT && view_has_flags(view, VIEW_ADD_PAGER_REFS))
		add_pager_refs(view, data + STRING_SIZE("commit "));

	return true;
}

bool
pager_read(struct view *view, struct buffer *buf, bool force_stop)
{
	if (!buf)
		return true;

	return pager_common_read(view, buf->data, get_line_type(buf->data), NULL);
}

enum request
pager_request(struct view *view, enum request request, struct line *line)
{
	int split = 0;

	if (request != REQ_ENTER)
		return request;

	if (line->type == LINE_COMMIT && view_has_flags(view, VIEW_OPEN_DIFF)) {
		open_diff_view(view, OPEN_SPLIT);
		split = 1;
	}

	/* Always scroll the view even if it was split. That way
	 * you can use Enter to scroll through the log view and
	 * split open each commit diff. */
	scroll_view(view, REQ_SCROLL_LINE_DOWN);

	/* FIXME: A minor workaround. Scrolling the view will call report_clear()
	 * but if we are scrolling a non-current view this won't properly
	 * update the view title. */
	if (split)
		update_view_title(view);

	return REQ_NONE;
}

void
pager_select(struct view *view, struct line *line)
{
	const char *text = box_text(line);

	string_ncopy(view->env->text, text, strlen(text));

	if (line->type == LINE_COMMIT) {
		string_copy_rev_from_commit_line(view->env->commit, text);
		if (!view_has_flags(view, VIEW_NO_REF))
			string_copy_rev(view->ref, view->env->commit);
	}
}

__attribute__((used)) static enum status_code
pager_open(struct view *view, enum open_flags flags)
{
	if (!open_from_stdin(flags) && !view->lines && !(flags & OPEN_PREPARED))
		return error("No pager content, press %s to run command from prompt",
			     get_view_key(view, REQ_PROMPT));

	return begin_update(view, NULL, NULL, flags);
}

