#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int ptrdiff_t ;
struct TYPE_3__ {char* name; int /*<<< orphan*/  state; } ;
typedef  TYPE_1__ log_var_t ;

/* Variables and functions */
 int /*<<< orphan*/  ATOMIC_ACQUIRE ; 
 int /*<<< orphan*/  ATOMIC_RELAXED ; 
 int JEMALLOC_LOG_VAR_BUFSIZE ; 
 int LOG_ENABLED ; 
 int LOG_INITIALIZED_NOT_ENABLED ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  atomic_load_b (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_store_u (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  log_init_done ; 
 char const* log_var_names ; 
 int strlen (char*) ; 
 scalar_t__ strncmp (char const*,char const*,int) ; 

__attribute__((used)) static const char *
log_var_extract_segment(const char* segment_begin) {
	const char *end;
	for (end = segment_begin; *end != '\0' && *end != '|'; end++) {
	}
	return end;
}

__attribute__((used)) static bool
log_var_matches_segment(const char *segment_begin, const char *segment_end,
    const char *log_var_begin, const char *log_var_end) {
	assert(segment_begin <= segment_end);
	assert(log_var_begin < log_var_end);

	ptrdiff_t segment_len = segment_end - segment_begin;
	ptrdiff_t log_var_len = log_var_end - log_var_begin;
	/* The special '.' segment matches everything. */
	if (segment_len == 1 && *segment_begin == '.') {
		return true;
	}
        if (segment_len == log_var_len) {
		return strncmp(segment_begin, log_var_begin, segment_len) == 0;
	} else if (segment_len < log_var_len) {
		return strncmp(segment_begin, log_var_begin, segment_len) == 0
		    && log_var_begin[segment_len] == '.';
        } else {
		return false;
	}
}

unsigned
log_var_update_state(log_var_t *log_var) {
	const char *log_var_begin = log_var->name;
	const char *log_var_end = log_var->name + strlen(log_var->name);

	/* Pointer to one before the beginning of the current segment. */
	const char *segment_begin = log_var_names;

	/*
	 * If log_init done is false, we haven't parsed the malloc conf yet.  To
	 * avoid log-spew, we default to not displaying anything.
	 */
	if (!atomic_load_b(&log_init_done, ATOMIC_ACQUIRE)) {
		return LOG_INITIALIZED_NOT_ENABLED;
	}

	while (true) {
		const char *segment_end = log_var_extract_segment(
		    segment_begin);
		assert(segment_end < log_var_names + JEMALLOC_LOG_VAR_BUFSIZE);
		if (log_var_matches_segment(segment_begin, segment_end,
		    log_var_begin, log_var_end)) {
			atomic_store_u(&log_var->state, LOG_ENABLED,
			    ATOMIC_RELAXED);
			return LOG_ENABLED;
		}
		if (*segment_end == '\0') {
			/* Hit the end of the segment string with no match. */
			atomic_store_u(&log_var->state,
			    LOG_INITIALIZED_NOT_ENABLED, ATOMIC_RELAXED);
			return LOG_INITIALIZED_NOT_ENABLED;
		}
		/* Otherwise, skip the delimiter and continue. */
		segment_begin = segment_end + 1;
	}
}

