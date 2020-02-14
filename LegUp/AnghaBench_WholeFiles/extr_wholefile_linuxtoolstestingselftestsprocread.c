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
struct dirent {int d_type; char* d_name; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  pid_t ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
#define  DT_DIR 130 
#define  DT_LNK 129 
#define  DT_REG 128 
 int O_DIRECTORY ; 
 int O_NONBLOCK ; 
 int O_RDONLY ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  SYS_getpid ; 
 int /*<<< orphan*/  SYS_gettid ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  closedir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dirfd (int /*<<< orphan*/ *) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/ * fdopendir (int) ; 
 int openat (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/ * opendir (char*) ; 
 int read (int,char*,int) ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 int readlinkat (int /*<<< orphan*/ ,char const*,char*,int) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 unsigned long long strtoull (char const*,char**,int) ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ) ; 
 int write (int,char const*,size_t) ; 

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

__attribute__((used)) static void f_reg(DIR *d, const char *filename)
{
	char buf[4096];
	int fd;
	ssize_t rv;

	/* read from /proc/kmsg can block */
	fd = openat(dirfd(d), filename, O_RDONLY|O_NONBLOCK);
	if (fd == -1)
		return;
	rv = read(fd, buf, sizeof(buf));
	assert((0 <= rv && rv <= sizeof(buf)) || rv == -1);
	close(fd);
}

__attribute__((used)) static void f_reg_write(DIR *d, const char *filename, const char *buf, size_t len)
{
	int fd;
	ssize_t rv;

	fd = openat(dirfd(d), filename, O_WRONLY);
	if (fd == -1)
		return;
	rv = write(fd, buf, len);
	assert((0 <= rv && rv <= len) || rv == -1);
	close(fd);
}

__attribute__((used)) static void f_lnk(DIR *d, const char *filename)
{
	char buf[4096];
	ssize_t rv;

	rv = readlinkat(dirfd(d), filename, buf, sizeof(buf));
	assert((0 <= rv && rv <= sizeof(buf)) || rv == -1);
}

__attribute__((used)) static void f(DIR *d, unsigned int level)
{
	struct dirent *de;

	de = xreaddir(d);
	assert(de->d_type == DT_DIR);
	assert(streq(de->d_name, "."));

	de = xreaddir(d);
	assert(de->d_type == DT_DIR);
	assert(streq(de->d_name, ".."));

	while ((de = xreaddir(d))) {
		assert(!streq(de->d_name, "."));
		assert(!streq(de->d_name, ".."));

		switch (de->d_type) {
			DIR *dd;
			int fd;

		case DT_REG:
			if (level == 0 && streq(de->d_name, "sysrq-trigger")) {
				f_reg_write(d, de->d_name, "h", 1);
			} else if (level == 1 && streq(de->d_name, "clear_refs")) {
				f_reg_write(d, de->d_name, "1", 1);
			} else if (level == 3 && streq(de->d_name, "clear_refs")) {
				f_reg_write(d, de->d_name, "1", 1);
			} else {
				f_reg(d, de->d_name);
			}
			break;
		case DT_DIR:
			fd = openat(dirfd(d), de->d_name, O_DIRECTORY|O_RDONLY);
			if (fd == -1)
				continue;
			dd = fdopendir(fd);
			if (!dd)
				continue;
			f(dd, level + 1);
			closedir(dd);
			break;
		case DT_LNK:
			f_lnk(d, de->d_name);
			break;
		default:
			assert(0);
		}
	}
}

int main(void)
{
	DIR *d;

	d = opendir("/proc");
	if (!d)
		return 2;
	f(d, 0);
	return 0;
}

