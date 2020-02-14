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
typedef  scalar_t__ time_t ;
struct watch_handler {scalar_t__ last_modified; int triggers; int (* check ) (struct watch_handler*,int,int) ;} ;
struct watch {int triggers; int changed; int state; struct watch* next; } ;
struct stat {scalar_t__ st_mtime; } ;
struct ref {int /*<<< orphan*/  name; } ;
struct index_diff {scalar_t__ untracked; scalar_t__ unstaged; scalar_t__ staged; } ;
typedef  int /*<<< orphan*/  path ;
typedef  enum watch_trigger { ____Placeholder_watch_trigger } watch_trigger ;
typedef  enum watch_event { ____Placeholder_watch_event } watch_event ;
struct TYPE_2__ {scalar_t__* git_dir; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct watch_handler*) ; 
 int /*<<< orphan*/  FORMAT_BUFFER (char*,int,char const*,int,int) ; 
 scalar_t__ REFRESH_MODE_AFTER_COMMAND ; 
 scalar_t__ REFRESH_MODE_MANUAL ; 
 int SIZEOF_STR ; 
 int WATCH_EVENT_AFTER_COMMAND ; 
 int WATCH_EVENT_LOAD ; 
 int WATCH_EVENT_PERIODIC ; 
 int WATCH_EVENT_SWITCH_VIEW ; 
 int WATCH_HEAD ; 
 int WATCH_INDEX ; 
 int WATCH_INDEX_STAGED ; 
 int WATCH_INDEX_STAGED_NO ; 
 int WATCH_INDEX_STAGED_YES ; 
 int WATCH_INDEX_UNSTAGED ; 
 int WATCH_INDEX_UNSTAGED_NO ; 
 int WATCH_INDEX_UNSTAGED_YES ; 
 int WATCH_INDEX_UNTRACKED ; 
 int WATCH_INDEX_UNTRACKED_NO ; 
 int WATCH_INDEX_UNTRACKED_YES ; 
 int WATCH_NONE ; 
 int WATCH_STASH ; 
 struct ref* get_ref_head () ; 
 int /*<<< orphan*/  index_diff (struct index_diff*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  load_refs (int) ; 
 scalar_t__ lstat (char*,struct stat*) ; 
 int /*<<< orphan*/  memset (struct watch*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ opt_refresh_mode ; 
 int /*<<< orphan*/  opt_show_untracked ; 
 TYPE_1__ repo ; 
 int stub1 (struct watch_handler*,int,int) ; 
 void* time (int /*<<< orphan*/ *) ; 
 struct watch_handler* watch_handlers ; 
 int watch_trigger_unmask (int,int) ; 
 void watch_unregister (struct watch*) ; 
 struct watch* watches ; 

void
watch_register(struct watch *watch, enum watch_trigger triggers)
{
	watch_unregister(watch);

	watch->next = watches;
	watches = watch;

	watch->triggers = triggers;
	watch->changed = WATCH_NONE;
	watch->state = WATCH_NONE;
}

void
watch_unregister(struct watch *watch)
{
	struct watch *pos, *prev = NULL;

	for (pos = watches; pos; prev = pos, pos = pos->next) {
		if (watch != pos)
			continue;
		if (!prev)
			watches = watch->next;
		else
			prev->next = watch->next;
		break;
	}

	memset(watch, 0, sizeof(*watch));
}

__attribute__((used)) static bool
check_file_mtime(time_t *last_modified, const char *path_fmt, ...)
{
	char path[SIZEOF_STR];
	struct stat stat;
	int retval;

	FORMAT_BUFFER(path, sizeof(path), path_fmt, retval, false);

	if (retval < 0 ||
	    lstat(path, &stat) < 0 ||
	    stat.st_mtime <= *last_modified)
		return false;

	*last_modified = stat.st_mtime;
	return true;
}

__attribute__((used)) static enum watch_trigger
watch_head_handler(struct watch_handler *handler, enum watch_event event, enum watch_trigger check)
{
	const struct ref *head;

	if (check_file_mtime(&handler->last_modified, "%s/HEAD", repo.git_dir))
		return WATCH_HEAD;

	// FIXME: check branch
	if ((head = get_ref_head()) &&
	    check_file_mtime(&handler->last_modified, "%s/refs/heads/%s", repo.git_dir, head->name))
		return WATCH_HEAD;

	return WATCH_NONE;
}

__attribute__((used)) static enum watch_trigger
watch_stash_handler(struct watch_handler *handler, enum watch_event event, enum watch_trigger check)
{
	if (check_file_mtime(&handler->last_modified, "%s/refs/stash", repo.git_dir))
		return WATCH_STASH;

	return WATCH_NONE;
}

__attribute__((used)) static enum watch_trigger
watch_index_handler(struct watch_handler *handler, enum watch_event event, enum watch_trigger check)
{
	enum watch_trigger changed = WATCH_NONE;
	struct index_diff diff;

	if (event == WATCH_EVENT_AFTER_COMMAND)
		return check_file_mtime(&handler->last_modified, "%s/index", repo.git_dir)
			? check : WATCH_NONE;

	if (!check_file_mtime(&handler->last_modified, "%s/index", repo.git_dir) ||
	    event == WATCH_EVENT_SWITCH_VIEW ||
	    !index_diff(&diff, opt_show_untracked, false))
		return WATCH_NONE;

	if (check & WATCH_INDEX_STAGED) {
		if (diff.staged)
			changed |= WATCH_INDEX_STAGED_YES;
		else
			changed |= WATCH_INDEX_STAGED_NO;
	}

	if (check & WATCH_INDEX_UNSTAGED) {
		if (diff.unstaged)
			changed |= WATCH_INDEX_UNSTAGED_YES;
		else
			changed |= WATCH_INDEX_UNSTAGED_NO;
	}

	if (check & WATCH_INDEX_UNTRACKED) {
		if (diff.untracked)
			changed |= WATCH_INDEX_UNTRACKED_YES;
		else
			changed |= WATCH_INDEX_UNTRACKED_NO;
	}

	if (changed)
		handler->last_modified = time(NULL);

	return changed;
}

__attribute__((used)) static enum watch_trigger
watch_refs_handler(struct watch_handler *handler, enum watch_event event,
		   enum watch_trigger check)
{
	if (event == WATCH_EVENT_AFTER_COMMAND)
		load_refs(true);

	return WATCH_NONE;
}

__attribute__((used)) static bool
watch_no_refresh(enum watch_event event)
{
	return opt_refresh_mode == REFRESH_MODE_MANUAL ||
	       (opt_refresh_mode == REFRESH_MODE_AFTER_COMMAND &&
		event != WATCH_EVENT_AFTER_COMMAND);
}

__attribute__((used)) static void
watch_apply_changes(struct watch *source, enum watch_event event,
		    enum watch_trigger changed)
{
	struct watch *watch;

	if (watch_no_refresh(event))
		return;

	for (watch = watches; watch; watch = watch->next) {
		enum watch_trigger triggers = changed & watch->triggers;

		if (source == watch) {
			source->state |= triggers;
			continue;
		}

		if (event == WATCH_EVENT_AFTER_COMMAND) {
			watch->state = WATCH_NONE;
			triggers = watch->triggers;
		}

		watch->changed |= triggers;
	}
}

void
watch_apply(struct watch *source, enum watch_trigger changed)
{
	watch_apply_changes(source, WATCH_EVENT_LOAD, changed);
}

__attribute__((used)) static enum watch_trigger
watch_update_event(enum watch_event event, enum watch_trigger trigger,
		   enum watch_trigger changed)
{
	time_t timestamp = 0;
	int i;

	if (watch_no_refresh(event))
		return WATCH_NONE;

	if (event == WATCH_EVENT_AFTER_COMMAND)
		timestamp = time(NULL);

	for (i = 0; i < ARRAY_SIZE(watch_handlers); i++) {
		struct watch_handler *handler = &watch_handlers[i];

		if (event == WATCH_EVENT_AFTER_COMMAND) {
			changed = handler->triggers;
			handler->last_modified = timestamp;
			continue;
		}

		if (*repo.git_dir &&
		    (trigger & handler->triggers) &&
		    (changed | handler->triggers) != changed)
			changed |= handler->check(handler, event, trigger);
	}

	if (changed)
		watch_apply_changes(NULL, event, changed);

	return changed;
}

__attribute__((used)) static inline enum watch_trigger
watch_unchanged_triggers(struct watch *watch)
{
	return watch_trigger_unmask(watch->triggers, watch->changed);
}

enum watch_trigger
watch_update_single(struct watch *watch, enum watch_event event)
{
	enum watch_trigger trigger = watch_unchanged_triggers(watch);

	return watch_update_event(event, trigger, watch->changed);
}

enum watch_trigger
watch_update(enum watch_event event)
{
	enum watch_trigger trigger = WATCH_NONE;
	struct watch *watch;

	/* Collect triggers to check. Skkipping watches that are already
	 * marked dirty to avoid unnecessary checks. */
	for (watch = watches; watch; watch = watch->next)
		trigger |= watch_unchanged_triggers(watch);

	return watch_update_event(event, trigger, WATCH_NONE);
}

int
watch_periodic(int interval)
{
	static time_t last_update;
	int delay = -1;

	if (watches && interval > 0) {
		time_t now = time(NULL);

		if (!last_update)
			last_update = now;
		if (last_update + interval <= now) {
			watch_update(WATCH_EVENT_PERIODIC);
			last_update = now;
		}

		delay = (now - last_update + interval) * 1000;
	}

	return delay;
}

bool
watch_dirty(struct watch *watch)
{
	enum watch_trigger old_index = watch->state & WATCH_INDEX;
	enum watch_trigger new_index = watch->changed & WATCH_INDEX;
	enum watch_trigger index = watch_trigger_unmask(new_index, old_index);
	enum watch_trigger other = watch_trigger_unmask(watch->changed, WATCH_INDEX);
	bool dirty = !!(index | other);

	watch->changed = WATCH_NONE;
	return dirty;
}

