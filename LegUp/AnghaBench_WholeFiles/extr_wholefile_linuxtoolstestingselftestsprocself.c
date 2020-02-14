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
struct dirent {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int pid_t ;
typedef  int /*<<< orphan*/  buf2 ;
typedef  int /*<<< orphan*/  buf1 ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_getpid ; 
 int /*<<< orphan*/  SYS_gettid ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ errno ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 size_t readlink (char*,char*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 size_t strlen (char*) ; 
 unsigned long long strtoull (char const*,char**,int) ; 
 int syscall (int /*<<< orphan*/ ) ; 

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

int main(void)
{
	char buf1[64], buf2[64];
	pid_t pid;
	ssize_t rv;

	pid = sys_getpid();
	snprintf(buf1, sizeof(buf1), "%u", pid);

	rv = readlink("/proc/self", buf2, sizeof(buf2));
	assert(rv == strlen(buf1));
	buf2[rv] = '\0';
	assert(streq(buf1, buf2));

	return 0;
}

