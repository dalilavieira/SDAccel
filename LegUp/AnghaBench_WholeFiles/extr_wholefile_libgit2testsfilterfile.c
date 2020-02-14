#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int /*<<< orphan*/  (* free ) (TYPE_3__*) ;} ;
struct TYPE_10__ {int /*<<< orphan*/  ptr; } ;
struct TYPE_9__ {int (* member_0 ) (int /*<<< orphan*/ *,char const*,size_t) ;int (* member_1 ) (int /*<<< orphan*/ *) ;void (* member_2 ) (int /*<<< orphan*/ *) ;} ;
struct buf_writestream {TYPE_3__ base; TYPE_2__ buf; TYPE_1__ member_0; } ;
typedef  int /*<<< orphan*/  git_writestream ;
typedef  int /*<<< orphan*/  git_reference ;
typedef  int /*<<< orphan*/  git_object ;
typedef  int /*<<< orphan*/  git_filter_list ;
typedef  int /*<<< orphan*/  git_filter ;
typedef  int /*<<< orphan*/  git_commit ;
typedef  TYPE_2__ git_buf ;

/* Variables and functions */
 TYPE_2__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_FILTER_CRLF ; 
 int /*<<< orphan*/  GIT_FILTER_TO_ODB ; 
 int /*<<< orphan*/  GIT_OBJECT_COMMIT ; 
 int /*<<< orphan*/  GIT_RESET_HARD ; 
 int /*<<< orphan*/  GIT_UNUSED (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_mkfile (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  cl_repo_set_bool (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_2__*) ; 
 int git_buf_put (TYPE_2__*,char const*,size_t) ; 
 int /*<<< orphan*/  git_commit_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_filter_list_apply_to_file (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_filter_list_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_filter_list_new (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_filter_list_push (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_filter_list_stream_file (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,TYPE_3__*) ; 
 int /*<<< orphan*/ * git_filter_lookup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_reference_peel (int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_head (int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reset (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*) ; 

void test_filter_file__initialize(void)
{
	git_reference *head_ref;
	git_commit *head;

	g_repo = cl_git_sandbox_init("crlf");

	cl_git_mkfile("crlf/.gitattributes",
		"*.txt text\n*.bin binary\n*.crlf text eol=crlf\n*.lf text eol=lf\n");

	cl_repo_set_bool(g_repo, "core.autocrlf", true);

	cl_git_pass(git_repository_head(&head_ref, g_repo));
	cl_git_pass(git_reference_peel((git_object **)&head, head_ref, GIT_OBJECT_COMMIT));
	cl_git_pass(git_reset(g_repo, (git_object *)head, GIT_RESET_HARD, NULL));

	git_commit_free(head);
	git_reference_free(head_ref);
}

void test_filter_file__cleanup(void)
{
	cl_git_sandbox_cleanup();
}

void test_filter_file__apply(void)
{
	git_filter_list *fl;
	git_filter *crlf;
	git_buf buf = GIT_BUF_INIT;

	cl_git_pass(git_filter_list_new(
		&fl, g_repo, GIT_FILTER_TO_ODB, 0));

	crlf = git_filter_lookup(GIT_FILTER_CRLF);
	cl_assert(crlf != NULL);

	cl_git_pass(git_filter_list_push(fl, crlf, NULL));

	cl_git_pass(git_filter_list_apply_to_file(&buf, fl, g_repo, "all-crlf"));
	cl_assert_equal_s("crlf\ncrlf\ncrlf\ncrlf\n", buf.ptr);

	git_buf_dispose(&buf);
	git_filter_list_free(fl);
}

int buf_writestream_write(git_writestream *s, const char *buf, size_t len)
{
	struct buf_writestream *stream = (struct buf_writestream *)s;
	return git_buf_put(&stream->buf, buf, len);
}

int buf_writestream_close(git_writestream *s)
{
	GIT_UNUSED(s);
	return 0;
}

void buf_writestream_free(git_writestream *s)
{
	struct buf_writestream *stream = (struct buf_writestream *)s;
	git_buf_dispose(&stream->buf);
}

void test_filter_file__apply_stream(void)
{
	git_filter_list *fl;
	git_filter *crlf;
	struct buf_writestream write_target = { {
		buf_writestream_write,
		buf_writestream_close,
		buf_writestream_free } };

	cl_git_pass(git_filter_list_new(
		&fl, g_repo, GIT_FILTER_TO_ODB, 0));

	crlf = git_filter_lookup(GIT_FILTER_CRLF);
	cl_assert(crlf != NULL);

	cl_git_pass(git_filter_list_push(fl, crlf, NULL));

	cl_git_pass(git_filter_list_stream_file(fl, g_repo, "all-crlf", &write_target.base));
	cl_assert_equal_s("crlf\ncrlf\ncrlf\ncrlf\n", write_target.buf.ptr);

	git_filter_list_free(fl);
	write_target.base.free(&write_target.base);
}

