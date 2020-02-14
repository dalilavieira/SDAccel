#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  git_buf ;
struct TYPE_5__ {void* (* gmalloc ) (size_t,char const*,int) ;void* (* grealloc ) (void*,size_t,char const*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_OPT_SET_ALLOCATOR ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 
 int git_buf_grow (int /*<<< orphan*/ *,int) ; 
 int git_buf_grow_by (int /*<<< orphan*/ *,int) ; 
 int git_buf_oom (int /*<<< orphan*/ *) ; 
 int git_libgit2_opts (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  git_stdalloc_init_allocator (TYPE_1__*) ; 
 TYPE_1__ oom_alloc ; 
 TYPE_1__ std_alloc ; 
 void* stub1 (size_t,char const*,int) ; 
 void* stub2 (void*,size_t,char const*,int) ; 

__attribute__((used)) static void *oom_malloc(size_t n, const char *file, int line)
{
	/* Reject any allocation of more than 100 bytes */
	return (n > 100) ? NULL : std_alloc.gmalloc(n, file, line);
}

__attribute__((used)) static void *oom_realloc(void *p, size_t n, const char *file, int line)
{
	/* Reject any allocation of more than 100 bytes */
	return (n > 100) ? NULL : std_alloc.grealloc(p, n, file, line);
}

void test_buf_oom__initialize(void)
{
	git_stdalloc_init_allocator(&std_alloc);
	git_stdalloc_init_allocator(&oom_alloc);

	oom_alloc.gmalloc = oom_malloc;
	oom_alloc.grealloc = oom_realloc;

	cl_git_pass(git_libgit2_opts(GIT_OPT_SET_ALLOCATOR, &oom_alloc));
}

void test_buf_oom__cleanup(void)
{
	cl_git_pass(git_libgit2_opts(GIT_OPT_SET_ALLOCATOR, NULL));
}

void test_buf_oom__grow(void)
{
	git_buf buf = GIT_BUF_INIT;

	cl_git_pass(git_buf_grow(&buf, 42));
	cl_assert(!git_buf_oom(&buf));

	cl_assert(git_buf_grow(&buf, 101) == -1);
	cl_assert(git_buf_oom(&buf));

	git_buf_dispose(&buf);
}

void test_buf_oom__grow_by(void)
{
	git_buf buf = GIT_BUF_INIT;

	cl_git_pass(git_buf_grow_by(&buf, 42));
	cl_assert(!git_buf_oom(&buf));

	cl_assert(git_buf_grow_by(&buf, 101) == -1);
	cl_assert(git_buf_oom(&buf));
}

