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
typedef  int /*<<< orphan*/  hdr ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_odb_stream ;
typedef  int /*<<< orphan*/  git_odb_object ;
typedef  int /*<<< orphan*/  git_object_t ;
typedef  int /*<<< orphan*/  git_hash_ctx ;
struct TYPE_5__ {int /*<<< orphan*/  size; int /*<<< orphan*/  ptr; } ;
typedef  TYPE_1__ git_buf ;

/* Variables and functions */
 TYPE_1__ GIT_BUF_INIT ; 
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int /*<<< orphan*/  LARGEFILE_SIZE ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_oid (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  cl_git_sandbox_init (char*) ; 
 int /*<<< orphan*/  cl_is_env_set (char*) ; 
 int /*<<< orphan*/  cl_skip () ; 
 int /*<<< orphan*/  git_buf_dispose (TYPE_1__*) ; 
 int /*<<< orphan*/  git_buf_puts (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  git_hash_ctx_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_hash_ctx_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_hash_final (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_hash_update (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  git_odb__format_object_header (size_t*,char*,int,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_open_rstream (int /*<<< orphan*/ **,size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_open_wstream (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_read (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_read_header (size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_stream_finalize_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_stream_free (int /*<<< orphan*/ *) ; 
 int git_odb_stream_read (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  git_odb_stream_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_odb_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_repository_odb (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  odb ; 
 int /*<<< orphan*/  repo ; 

void test_odb_largefiles__initialize(void)
{
	repo = cl_git_sandbox_init("testrepo.git");
	cl_git_pass(git_repository_odb(&odb, repo));
}

void test_odb_largefiles__cleanup(void)
{
	git_odb_free(odb);
	cl_git_sandbox_cleanup();
}

__attribute__((used)) static void writefile(git_oid *oid)
{
	static git_odb_stream *stream;
	git_buf buf = GIT_BUF_INIT;
	size_t i;

	for (i = 0; i < 3041; i++)
		cl_git_pass(git_buf_puts(&buf, "Hello, world.\n"));

	cl_git_pass(git_odb_open_wstream(&stream, odb, LARGEFILE_SIZE, GIT_OBJECT_BLOB));
	for (i = 0; i < 126103; i++)
		cl_git_pass(git_odb_stream_write(stream, buf.ptr, buf.size));

	cl_git_pass(git_odb_stream_finalize_write(oid, stream));

	git_odb_stream_free(stream);
	git_buf_dispose(&buf);
}

void test_odb_largefiles__write_from_memory(void)
{
	git_oid expected, oid;
	git_buf buf = GIT_BUF_INIT;
	size_t i;

#ifndef GIT_ARCH_64
	cl_skip();
#endif

	if (!cl_is_env_set("GITTEST_INVASIVE_FS_SIZE") ||
		!cl_is_env_set("GITTEST_INVASIVE_MEMORY") ||
		!cl_is_env_set("GITTEST_SLOW"))
		cl_skip();

	for (i = 0; i < (3041*126103); i++)
		cl_git_pass(git_buf_puts(&buf, "Hello, world.\n"));

	git_oid_fromstr(&expected, "3fb56989cca483b21ba7cb0a6edb229d10e1c26c");
	cl_git_pass(git_odb_write(&oid, odb, buf.ptr, buf.size, GIT_OBJECT_BLOB));

	cl_assert_equal_oid(&expected, &oid);
}

void test_odb_largefiles__streamwrite(void)
{
	git_oid expected, oid;

#ifndef GIT_ARCH_64
	cl_skip();
#endif

	if (!cl_is_env_set("GITTEST_INVASIVE_FS_SIZE") ||
		!cl_is_env_set("GITTEST_SLOW"))
		cl_skip();

	git_oid_fromstr(&expected, "3fb56989cca483b21ba7cb0a6edb229d10e1c26c");
	writefile(&oid);

	cl_assert_equal_oid(&expected, &oid);
}

void test_odb_largefiles__streamread(void)
{
	git_oid oid, read_oid;
	git_odb_stream *stream;
	char buf[10240];
	char hdr[64];
	size_t len, hdr_len, total = 0;
	git_hash_ctx hash;
	git_object_t type;
	int ret;

#ifndef GIT_ARCH_64
	cl_skip();
#endif

	if (!cl_is_env_set("GITTEST_INVASIVE_FS_SIZE") ||
		!cl_is_env_set("GITTEST_SLOW"))
		cl_skip();

	writefile(&oid);

	cl_git_pass(git_odb_open_rstream(&stream, &len, &type, odb, &oid));

	cl_assert_equal_sz(LARGEFILE_SIZE, len);
	cl_assert_equal_i(GIT_OBJECT_BLOB, type);

	cl_git_pass(git_hash_ctx_init(&hash));
	cl_git_pass(git_odb__format_object_header(&hdr_len, hdr, sizeof(hdr), len, type));

	cl_git_pass(git_hash_update(&hash, hdr, hdr_len));

	while ((ret = git_odb_stream_read(stream, buf, 10240)) > 0) {
		cl_git_pass(git_hash_update(&hash, buf, ret));
		total += ret;
	}

	cl_assert_equal_sz(LARGEFILE_SIZE, total);

	git_hash_final(&read_oid, &hash);

	cl_assert_equal_oid(&oid, &read_oid);

	git_hash_ctx_cleanup(&hash);
	git_odb_stream_free(stream);
}

void test_odb_largefiles__read_into_memory(void)
{
	git_oid oid;
	git_odb_object *obj;

#ifndef GIT_ARCH_64
	cl_skip();
#endif

	if (!cl_is_env_set("GITTEST_INVASIVE_FS_SIZE") ||
		!cl_is_env_set("GITTEST_INVASIVE_MEMORY") ||
		!cl_is_env_set("GITTEST_SLOW"))
		cl_skip();

	writefile(&oid);
	cl_git_pass(git_odb_read(&obj, odb, &oid));

	git_odb_object_free(obj);
}

void test_odb_largefiles__read_into_memory_rejected_on_32bit(void)
{
	git_oid oid;
	git_odb_object *obj = NULL;

#ifdef GIT_ARCH_64
	cl_skip();
#endif

	if (!cl_is_env_set("GITTEST_INVASIVE_FS_SIZE") ||
		!cl_is_env_set("GITTEST_INVASIVE_MEMORY") ||
		!cl_is_env_set("GITTEST_SLOW"))
		cl_skip();

	writefile(&oid);
	cl_git_fail(git_odb_read(&obj, odb, &oid));

	git_odb_object_free(obj);
}

void test_odb_largefiles__read_header(void)
{
	git_oid oid;
	size_t len;
	git_object_t type;

#ifndef GIT_ARCH_64
	cl_skip();
#endif

	if (!cl_is_env_set("GITTEST_INVASIVE_FS_SIZE") ||
		!cl_is_env_set("GITTEST_SLOW"))
		cl_skip();

	writefile(&oid);
	cl_git_pass(git_odb_read_header(&len, &type, odb, &oid));

	cl_assert_equal_sz(LARGEFILE_SIZE, len);
	cl_assert_equal_i(GIT_OBJECT_BLOB, type);
}

