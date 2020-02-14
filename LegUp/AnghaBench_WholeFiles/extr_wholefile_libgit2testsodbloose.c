#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct stat {int st_mode; } ;
struct TYPE_21__ {char* dir; scalar_t__ dlen; char* id; int /*<<< orphan*/  type; int /*<<< orphan*/  data; int /*<<< orphan*/  blen; int /*<<< orphan*/  bytes; int /*<<< orphan*/  file; } ;
typedef  TYPE_2__ object_data ;
typedef  int mode_t ;
typedef  int /*<<< orphan*/  git_repository ;
struct TYPE_22__ {scalar_t__ type; scalar_t__ len; char* data; } ;
typedef  TYPE_3__ git_rawobj ;
typedef  int /*<<< orphan*/  git_oid ;
typedef  int /*<<< orphan*/  git_odb_stream ;
struct TYPE_20__ {scalar_t__ size; scalar_t__ type; } ;
struct TYPE_23__ {char* buffer; TYPE_1__ cached; } ;
typedef  TYPE_4__ git_odb_object ;
typedef  int /*<<< orphan*/  git_odb_backend ;
typedef  int /*<<< orphan*/  git_odb ;
typedef  int git_object_t ;

/* Variables and functions */
 size_t ARRAY_SIZE (size_t*) ; 
 scalar_t__ EEXIST ; 
 int GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_OBJECT_BLOB ; 
 int GIT_OBJECT_DIR_MODE ; 
 int GIT_OBJECT_FILE_MODE ; 
 int /*<<< orphan*/  GIT_OPT_ENABLE_FSYNC_GITDIR ; 
 int S_IREAD ; 
 int S_IWRITE ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int) ; 
 int /*<<< orphan*/  cl_assert_equal_sz (scalar_t__,size_t) ; 
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_git_pass (int) ; 
 int /*<<< orphan*/  cl_must_pass (scalar_t__) ; 
 int /*<<< orphan*/  cl_repo_set_bool (int /*<<< orphan*/ *,char*,int) ; 
 TYPE_2__ commit ; 
 scalar_t__ errno ; 
 int git_libgit2_opts (int /*<<< orphan*/ ,int) ; 
 int git_object_string2type (int /*<<< orphan*/ ) ; 
 int git_odb_add_backend (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int git_odb_backend_loose (int /*<<< orphan*/ **,char*,int,int,int,int) ; 
 int git_odb_exists (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int git_odb_exists_prefix (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_odb_free (int /*<<< orphan*/ *) ; 
 int git_odb_new (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  git_odb_object_free (TYPE_4__*) ; 
 int git_odb_open (int /*<<< orphan*/ **,char*) ; 
 int git_odb_open_rstream (int /*<<< orphan*/ **,scalar_t__*,scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int git_odb_read (TYPE_4__**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int git_odb_read_header (size_t*,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_odb_stream_free (int /*<<< orphan*/ *) ; 
 int git_odb_stream_read (int /*<<< orphan*/ *,char*,size_t) ; 
 int git_odb_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ) ; 
 int git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int git_oid_fromstrp (int /*<<< orphan*/ *,char*) ; 
 int git_oid_streq (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ *) ; 
 int git_repository_init (int /*<<< orphan*/ **,char*,int) ; 
 int git_repository_odb__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int git_repository_open (int /*<<< orphan*/ **,char*) ; 
 scalar_t__ memcmp (char*,int /*<<< orphan*/ ,scalar_t__) ; 
 TYPE_2__ one ; 
 int /*<<< orphan*/  p_close (int) ; 
 int p_creat (int /*<<< orphan*/ ,int) ; 
 size_t p_fsync__cnt ; 
 scalar_t__ p_mkdir (char*,int) ; 
 int p_stat (char*,struct stat*) ; 
 int p_umask (int) ; 
 scalar_t__ p_write (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__ some ; 
 TYPE_2__ tag ; 
 TYPE_2__ tree ; 
 TYPE_2__ two ; 
 TYPE_2__ zero ; 

__attribute__((used)) static void write_object_files(object_data *d)
{
	int fd;

	if (p_mkdir(d->dir, GIT_OBJECT_DIR_MODE) < 0)
		cl_assert(errno == EEXIST);

	cl_assert((fd = p_creat(d->file, S_IREAD | S_IWRITE)) >= 0);
	cl_must_pass(p_write(fd, d->bytes, d->blen));

	p_close(fd);
}

__attribute__((used)) static void cmp_objects(git_rawobj *o, object_data *d)
{
	cl_assert(o->type == git_object_string2type(d->type));
	cl_assert(o->len == d->dlen);

	if (o->len > 0)
		cl_assert(memcmp(o->data, d->data, o->len) == 0);
}

__attribute__((used)) static void test_read_object(object_data *data)
{
    git_oid id;
    git_odb_object *obj;
	git_odb *odb;
	git_rawobj tmp;

    write_object_files(data);

    cl_git_pass(git_odb_open(&odb, "test-objects"));
    cl_git_pass(git_oid_fromstr(&id, data->id));
    cl_git_pass(git_odb_read(&obj, odb, &id));

	tmp.data = obj->buffer;
	tmp.len = obj->cached.size;
	tmp.type = obj->cached.type;

    cmp_objects(&tmp, data);

    git_odb_object_free(obj);
	git_odb_free(odb);
}

__attribute__((used)) static void test_read_header(object_data *data)
{
	git_oid id;
	git_odb *odb;
	size_t len;
	git_object_t type;

	write_object_files(data);

	cl_git_pass(git_odb_open(&odb, "test-objects"));
	cl_git_pass(git_oid_fromstr(&id, data->id));
	cl_git_pass(git_odb_read_header(&len, &type, odb, &id));

	cl_assert_equal_sz(data->dlen, len);
	cl_assert_equal_i(git_object_string2type(data->type), type);

	git_odb_free(odb);
}

__attribute__((used)) static void test_readstream_object(object_data *data, size_t blocksize)
{
	git_oid id;
	git_odb *odb;
	git_odb_stream *stream;
	git_rawobj tmp;
	char buf[2048], *ptr = buf;
	size_t remain;
	int ret;

	write_object_files(data);

	cl_git_pass(git_odb_open(&odb, "test-objects"));
	cl_git_pass(git_oid_fromstr(&id, data->id));
	cl_git_pass(git_odb_open_rstream(&stream, &tmp.len, &tmp.type, odb, &id));

	remain = tmp.len;

	while (remain) {
		cl_assert((ret = git_odb_stream_read(stream, ptr, blocksize)) >= 0);
		if (ret == 0)
			break;

		cl_assert(remain >= (size_t)ret);
		remain -= ret;
		ptr += ret;
	}

	cl_assert(remain == 0);

	tmp.data = buf;

	cmp_objects(&tmp, data);

	git_odb_stream_free(stream);
	git_odb_free(odb);
}

void test_odb_loose__initialize(void)
{
	p_fsync__cnt = 0;
	cl_must_pass(p_mkdir("test-objects", GIT_OBJECT_DIR_MODE));
}

void test_odb_loose__cleanup(void)
{
	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_FSYNC_GITDIR, 0));
	cl_fixture_cleanup("test-objects");
}

void test_odb_loose__exists(void)
{
	git_oid id, id2;
	git_odb *odb;

	write_object_files(&one);
	cl_git_pass(git_odb_open(&odb, "test-objects"));

	cl_git_pass(git_oid_fromstr(&id, one.id));
	cl_assert(git_odb_exists(odb, &id));

	cl_git_pass(git_oid_fromstrp(&id, "8b137891"));
	cl_git_pass(git_odb_exists_prefix(&id2, odb, &id, 8));
	cl_assert_equal_i(0, git_oid_streq(&id2, one.id));

	/* Test for a missing object */
	cl_git_pass(git_oid_fromstr(&id, "8b137891791fe96927ad78e64b0aad7bded08baa"));
	cl_assert(!git_odb_exists(odb, &id));

	cl_git_pass(git_oid_fromstrp(&id, "8b13789a"));
	cl_assert_equal_i(GIT_ENOTFOUND, git_odb_exists_prefix(&id2, odb, &id, 8));

	git_odb_free(odb);
}

void test_odb_loose__simple_reads(void)
{
	test_read_object(&commit);
	test_read_object(&tree);
	test_read_object(&tag);
	test_read_object(&zero);
	test_read_object(&one);
	test_read_object(&two);
	test_read_object(&some);
}

void test_odb_loose__streaming_reads(void)
{
	size_t blocksizes[] = { 1, 2, 4, 16, 99, 1024, 123456789 };
	size_t i;

	for (i = 0; i < ARRAY_SIZE(blocksizes); i++) {
		test_readstream_object(&commit, blocksizes[i]);
		test_readstream_object(&tree, blocksizes[i]);
		test_readstream_object(&tag, blocksizes[i]);
		test_readstream_object(&zero, blocksizes[i]);
		test_readstream_object(&one, blocksizes[i]);
		test_readstream_object(&two, blocksizes[i]);
		test_readstream_object(&some, blocksizes[i]);
	}
}

void test_odb_loose__read_header(void)
{
	test_read_header(&commit);
	test_read_header(&tree);
	test_read_header(&tag);
	test_read_header(&zero);
	test_read_header(&one);
	test_read_header(&two);
	test_read_header(&some);
}

void test_write_object_permission(
	mode_t dir_mode, mode_t file_mode,
	mode_t expected_dir_mode, mode_t expected_file_mode)
{
	git_odb *odb;
	git_odb_backend *backend;
	git_oid oid;
	struct stat statbuf;
	mode_t mask, os_mask;

	/* Windows does not return group/user bits from stat,
	* files are never executable.
	*/
#ifdef GIT_WIN32
	os_mask = 0600;
#else
	os_mask = 0777;
#endif

	mask = p_umask(0);
	p_umask(mask);

	cl_git_pass(git_odb_new(&odb));
	cl_git_pass(git_odb_backend_loose(&backend, "test-objects", -1, 0, dir_mode, file_mode));
	cl_git_pass(git_odb_add_backend(odb, backend, 1));
	cl_git_pass(git_odb_write(&oid, odb, "Test data\n", 10, GIT_OBJECT_BLOB));

	cl_git_pass(p_stat("test-objects/67", &statbuf));
	cl_assert_equal_i(statbuf.st_mode & os_mask, (expected_dir_mode & ~mask) & os_mask);

	cl_git_pass(p_stat("test-objects/67/b808feb36201507a77f85e6d898f0a2836e4a5", &statbuf));
	cl_assert_equal_i(statbuf.st_mode & os_mask, (expected_file_mode & ~mask) & os_mask);

	git_odb_free(odb);
}

void test_odb_loose__permissions_standard(void)
{
	test_write_object_permission(0, 0, GIT_OBJECT_DIR_MODE, GIT_OBJECT_FILE_MODE);
}

void test_odb_loose_permissions_readonly(void)
{
	test_write_object_permission(0777, 0444, 0777, 0444);
}

void test_odb_loose__permissions_readwrite(void)
{
	test_write_object_permission(0777, 0666, 0777, 0666);
}

__attribute__((used)) static void write_object_to_loose_odb(int fsync)
{
	git_odb *odb;
	git_odb_backend *backend;
	git_oid oid;

	cl_git_pass(git_odb_new(&odb));
	cl_git_pass(git_odb_backend_loose(&backend, "test-objects", -1, fsync, 0777, 0666));
	cl_git_pass(git_odb_add_backend(odb, backend, 1));
	cl_git_pass(git_odb_write(&oid, odb, "Test data\n", 10, GIT_OBJECT_BLOB));
	git_odb_free(odb);
}

void test_odb_loose__does_not_fsync_by_default(void)
{
	write_object_to_loose_odb(0);
	cl_assert_equal_sz(0, p_fsync__cnt);
}

void test_odb_loose__fsync_obeys_odb_option(void)
{
	write_object_to_loose_odb(1);
	cl_assert(p_fsync__cnt > 0);
}

void test_odb_loose__fsync_obeys_global_setting(void)
{
	cl_git_pass(git_libgit2_opts(GIT_OPT_ENABLE_FSYNC_GITDIR, 1));
	write_object_to_loose_odb(0);
	cl_assert(p_fsync__cnt > 0);
}

void test_odb_loose__fsync_obeys_repo_setting(void)
{
	git_repository *repo;
	git_odb *odb;
	git_oid oid;

	cl_git_pass(git_repository_init(&repo, "test-objects", 1));
	cl_git_pass(git_repository_odb__weakptr(&odb, repo));
	cl_git_pass(git_odb_write(&oid, odb, "No fsync here\n", 14, GIT_OBJECT_BLOB));
	cl_assert(p_fsync__cnt == 0);
	git_repository_free(repo);

	cl_git_pass(git_repository_open(&repo, "test-objects"));
	cl_repo_set_bool(repo, "core.fsyncObjectFiles", true);
	cl_git_pass(git_repository_odb__weakptr(&odb, repo));
	cl_git_pass(git_odb_write(&oid, odb, "Now fsync\n", 10, GIT_OBJECT_BLOB));
	cl_assert(p_fsync__cnt > 0);
	git_repository_free(repo);
}

