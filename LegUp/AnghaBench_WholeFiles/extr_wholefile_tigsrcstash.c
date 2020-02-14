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
struct view {int /*<<< orphan*/  argv; TYPE_1__* env; int /*<<< orphan*/  ref; int /*<<< orphan*/  watch; struct main_state* private; } ;
struct main_state {int with_graph; } ;
struct line {scalar_t__ lineno; } ;
typedef  enum status_code { ____Placeholder_status_code } status_code ;
typedef  enum request { ____Placeholder_request } request ;
typedef  enum open_flags { ____Placeholder_open_flags } open_flags ;
struct TYPE_2__ {int /*<<< orphan*/  stash; } ;

/* Variables and functions */
 char* DIFF_ARGS ; 
 int OPEN_DEFAULT ; 
 int OPEN_PREPARED ; 
 int OPEN_RELOAD ; 
 int OPEN_SPLIT ; 
#define  REQ_ENTER 130 
 int REQ_NONE ; 
#define  REQ_VIEW_DIFF 129 
 int /*<<< orphan*/  WATCH_STASH ; 
 int /*<<< orphan*/  argv_format (TYPE_1__*,int /*<<< orphan*/ *,char const**,int,int) ; 
 int begin_update (struct view*,int /*<<< orphan*/ *,char const**,int) ; 
 char* diff_context_arg () ; 
 struct view diff_view ; 
 struct view** display ; 
#define  encoding_arg 128 
 char* ignore_space_arg () ; 
 int main_request (struct view*,int,struct line*) ; 
 int /*<<< orphan*/  main_select (struct view*,struct line*) ; 
 int /*<<< orphan*/  maximize_view (struct view*,int) ; 
 int /*<<< orphan*/  open_view (struct view*,struct view*,int) ; 
 int /*<<< orphan*/  report (char*) ; 
 char* show_notes_arg () ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_copy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_format (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 scalar_t__ view_is_displayed (struct view*) ; 
 int /*<<< orphan*/  watch_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static enum status_code
stash_open(struct view *view, enum open_flags flags)
{
	static const char *stash_argv[] = { "git", "stash", "list",
		encoding_arg, "--no-color", "--pretty=raw", NULL };
	struct main_state *state = view->private;

	state->with_graph = false;
	watch_register(&view->watch, WATCH_STASH);
	return begin_update(view, NULL, stash_argv, flags | OPEN_RELOAD);
}

__attribute__((used)) static void
stash_select(struct view *view, struct line *line)
{
	main_select(view, line);
	string_format(view->env->stash, "stash@{%d}", line->lineno - 1);
	string_copy(view->ref, view->env->stash);
}

enum request
stash_request(struct view *view, enum request request, struct line *line)
{
	enum open_flags flags = (view_is_displayed(view) && request != REQ_VIEW_DIFF)
				? OPEN_SPLIT : OPEN_DEFAULT;
	struct view *diff = &diff_view;

	switch (request) {
	case REQ_VIEW_DIFF:
	case REQ_ENTER:
		if (view_is_displayed(view) && display[0] != view)
			maximize_view(view, true);

		if (!view_is_displayed(diff) ||
		    strcmp(view->env->stash, diff->ref)) {
			const char *diff_argv[] = {
				"git", "stash", "show", encoding_arg, "--pretty=fuller",
					"--root", "--patch-with-stat",
					show_notes_arg(), diff_context_arg(),
					ignore_space_arg(), DIFF_ARGS,
					"--no-color", "%(stash)", NULL
			};

			if (!argv_format(diff_view.env, &diff_view.argv, diff_argv, false, false))
				report("Failed to format argument");
			else
				open_view(view, &diff_view, flags | OPEN_PREPARED);
		}
		return REQ_NONE;

	default:
		return main_request(view, request, line);
	}
}

