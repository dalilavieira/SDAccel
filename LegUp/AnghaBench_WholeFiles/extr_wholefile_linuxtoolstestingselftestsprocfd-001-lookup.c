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
struct stat {int /*<<< orphan*/  st_mode; } ;
struct dirent {scalar_t__ d_type; char* d_name; } ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  pid_t ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int /*<<< orphan*/  CLONE_FILES ; 
 scalar_t__ DT_DIR ; 
 scalar_t__ DT_LNK ; 
 scalar_t__ ENOENT ; 
 int INT_MAX ; 
 int INT_MIN ; 
 int O_DIRECTORY ; 
 int O_PATH ; 
 int /*<<< orphan*/  SYS_getpid ; 
 int /*<<< orphan*/  SYS_gettid ; 
 int S_ISLNK (int /*<<< orphan*/ ) ; 
 int UINT_MAX ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  close (unsigned int) ; 
 int /*<<< orphan*/  closedir (int /*<<< orphan*/ *) ; 
 unsigned int dirfd (int /*<<< orphan*/ *) ; 
 unsigned int dup2 (unsigned int,unsigned int) ; 
 scalar_t__ errno ; 
 scalar_t__ lstat (char const*,struct stat*) ; 
 int /*<<< orphan*/  memset (struct stat*,int /*<<< orphan*/ ,int) ; 
 unsigned int open (char*,int) ; 
 int /*<<< orphan*/ * opendir (char*) ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,unsigned int,...) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 unsigned long long strtoull (char const*,char**,int) ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ) ; 
 int unshare (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline pid_t sys_getpid(void)
{
	return syscall(SYS_getpid);
}

__attribute__((used)) static inline pid_t sys_gettid(void)
{
	return syscall(SYS_gettid);
}

__attribute__((used)) static inline bool streq(const char *s1, const char *s2)
{
	return strcmp(s1, s2) == 0;
}

__attribute__((used)) static unsigned long long xstrtoull(const char *p, char **end)
{
	if (*p == '0') {
		*end = (char *)p + 1;
		return 0;
	} else if ('1' <= *p && *p <= '9') {
		unsigned long long val;

		errno = 0;
		val = strtoull(p, end, 10);
		assert(errno == 0);
		return val;
	} else
		assert(0);
}

__attribute__((used)) static struct dirent *xreaddir(DIR *d)
{
	struct dirent *de;

	errno = 0;
	de = readdir(d);
	assert(de || errno == 0);
	return de;
}

__attribute__((used)) static void test_lookup_pass(const char *pathname)
{
	struct stat st;
	ssize_t rv;

	memset(&st, 0, sizeof(struct stat));
	rv = lstat(pathname, &st);
	assert(rv == 0);
	assert(S_ISLNK(st.st_mode));
}

__attribute__((used)) static void test_lookup_fail(const char *pathname)
{
	struct stat st;
	ssize_t rv;

	rv = lstat(pathname, &st);
	assert(rv == -1 && errno == ENOENT);
}

__attribute__((used)) static void test_lookup(unsigned int fd)
{
	char buf[64];
	unsigned int c;
	unsigned int u;
	int i;

	snprintf(buf, sizeof(buf), "/proc/self/fd/%u", fd);
	test_lookup_pass(buf);

	/* leading junk */
	for (c = 1; c <= 255; c++) {
		if (c == '/')
			continue;
		snprintf(buf, sizeof(buf), "/proc/self/fd/%c%u", c, fd);
		test_lookup_fail(buf);
	}

	/* trailing junk */
	for (c = 1; c <= 255; c++) {
		if (c == '/')
			continue;
		snprintf(buf, sizeof(buf), "/proc/self/fd/%u%c", fd, c);
		test_lookup_fail(buf);
	}

	for (i = INT_MIN; i < INT_MIN + 1024; i++) {
		snprintf(buf, sizeof(buf), "/proc/self/fd/%d", i);
		test_lookup_fail(buf);
	}
	for (i = -1024; i < 0; i++) {
		snprintf(buf, sizeof(buf), "/proc/self/fd/%d", i);
		test_lookup_fail(buf);
	}
	for (u = INT_MAX - 1024; u <= (unsigned int)INT_MAX + 1024; u++) {
		snprintf(buf, sizeof(buf), "/proc/self/fd/%u", u);
		test_lookup_fail(buf);
	}
	for (u = UINT_MAX - 1024; u != 0; u++) {
		snprintf(buf, sizeof(buf), "/proc/self/fd/%u", u);
		test_lookup_fail(buf);
	}


}

int main(void)
{
	struct dirent *de;
	unsigned int fd, target_fd;

	if (unshare(CLONE_FILES) == -1)
		return 1;

	/* Wipe fdtable. */
	do {
		DIR *d;

		d = opendir("/proc/self/fd");
		if (!d)
			return 1;

		de = xreaddir(d);
		assert(de->d_type == DT_DIR);
		assert(streq(de->d_name, "."));

		de = xreaddir(d);
		assert(de->d_type == DT_DIR);
		assert(streq(de->d_name, ".."));
next:
		de = xreaddir(d);
		if (de) {
			unsigned long long fd_ull;
			unsigned int fd;
			char *end;

			assert(de->d_type == DT_LNK);

			fd_ull = xstrtoull(de->d_name, &end);
			assert(*end == '\0');
			assert(fd_ull == (unsigned int)fd_ull);

			fd = fd_ull;
			if (fd == dirfd(d))
				goto next;
			close(fd);
		}

		closedir(d);
	} while (de);

	/* Now fdtable is clean. */

	fd = open("/", O_PATH|O_DIRECTORY);
	assert(fd == 0);
	test_lookup(fd);
	close(fd);

	/* Clean again! */

	fd = open("/", O_PATH|O_DIRECTORY);
	assert(fd == 0);
	/* Default RLIMIT_NOFILE-1 */
	target_fd = 1023;
	while (target_fd > 0) {
		if (dup2(fd, target_fd) == target_fd)
			break;
		target_fd /= 2;
	}
	assert(target_fd > 0);
	close(fd);
	test_lookup(target_fd);
	close(target_fd);

	return 0;
}

