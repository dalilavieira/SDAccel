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
typedef  int /*<<< orphan*/  git_trace_level_t ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_TRACE_INFO ; 
 int /*<<< orphan*/  GIT_TRACE_NONE ; 
 int /*<<< orphan*/  GIT_UNUSED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_global_trace_disable () ; 
 int /*<<< orphan*/  cl_global_trace_register () ; 
 int /*<<< orphan*/  cl_skip () ; 
 int /*<<< orphan*/  git_trace_set (int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ ,char const*)) ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int written ; 

__attribute__((used)) static void trace_callback(git_trace_level_t level, const char *message)
{
	GIT_UNUSED(level);

	cl_assert(strcmp(message, "Hello world!") == 0);

	written = 1;
}

void test_trace_trace__initialize(void)
{
	/* If global tracing is enabled, disable for the duration of this test. */
	cl_global_trace_disable();

	git_trace_set(GIT_TRACE_INFO, trace_callback);
	written = 0;
}

void test_trace_trace__cleanup(void)
{
	git_trace_set(GIT_TRACE_NONE, NULL);

	/* If global tracing was enabled, restart it. */
	cl_global_trace_register();
}

void test_trace_trace__sets(void)
{
#ifdef GIT_TRACE
	cl_assert(git_trace_level() == GIT_TRACE_INFO);
#else
	cl_skip();
#endif
}

void test_trace_trace__can_reset(void)
{
#ifdef GIT_TRACE
	cl_assert(git_trace_level() == GIT_TRACE_INFO);
	cl_git_pass(git_trace_set(GIT_TRACE_ERROR, trace_callback));

	cl_assert(written == 0);
	git_trace(GIT_TRACE_INFO, "Hello %s!", "world");
	cl_assert(written == 0);

	git_trace(GIT_TRACE_ERROR, "Hello %s!", "world");
	cl_assert(written == 1);
#else
	cl_skip();
#endif
}

void test_trace_trace__can_unset(void)
{
#ifdef GIT_TRACE
	cl_assert(git_trace_level() == GIT_TRACE_INFO);
	cl_git_pass(git_trace_set(GIT_TRACE_NONE, NULL));

	cl_assert(git_trace_level() == GIT_TRACE_NONE);

	cl_assert(written == 0);
	git_trace(GIT_TRACE_FATAL, "Hello %s!", "world");
	cl_assert(written == 0);
#else
	cl_skip();
#endif
}

void test_trace_trace__skips_higher_level(void)
{
#ifdef GIT_TRACE
	cl_assert(written == 0);
	git_trace(GIT_TRACE_DEBUG, "Hello %s!", "world");
	cl_assert(written == 0);
#else
	cl_skip();
#endif
}

void test_trace_trace__writes(void)
{
#ifdef GIT_TRACE
	cl_assert(written == 0);
	git_trace(GIT_TRACE_INFO, "Hello %s!", "world");
	cl_assert(written == 1);
#else
	cl_skip();
#endif
}

void test_trace_trace__writes_lower_level(void)
{
#ifdef GIT_TRACE
	cl_assert(written == 0);
	git_trace(GIT_TRACE_ERROR, "Hello %s!", "world");
	cl_assert(written == 1);
#else
	cl_skip();
#endif
}

