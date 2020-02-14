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
 int CLONE_SIGHAND ; 
 int CLONE_THREAD ; 
 int CLONE_VM ; 
 int MAP_ANONYMOUS ; 
 void* MAP_FAILED ; 
 int MAP_PRIVATE ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 int /*<<< orphan*/  SYS_getpid ; 
 int /*<<< orphan*/  SYS_gettid ; 
 int /*<<< orphan*/  _SC_PAGESIZE ; 
 int /*<<< orphan*/  assert (int) ; 
 int clone (int (*) (void*),void*,int,void*) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 void* mmap (int /*<<< orphan*/ *,int,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pause () ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 size_t readlink (char*,char*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int,int) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 size_t strlen (char*) ; 
 unsigned long long strtoull (char const*,char**,int) ; 
 int syscall (int /*<<< orphan*/ ) ; 
 int sysconf (int /*<<< orphan*/ ) ; 

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

int f(void *arg)
{
	char buf1[64], buf2[64];
	pid_t pid, tid;
	ssize_t rv;

	pid = sys_getpid();
	tid = sys_gettid();
	snprintf(buf1, sizeof(buf1), "%u/task/%u", pid, tid);

	rv = readlink("/proc/thread-self", buf2, sizeof(buf2));
	assert(rv == strlen(buf1));
	buf2[rv] = '\0';
	assert(streq(buf1, buf2));

	if (arg)
		exit(0);
	return 0;
}

int main(void)
{
	const int PAGE_SIZE = sysconf(_SC_PAGESIZE);
	pid_t pid;
	void *stack;

	/* main thread */
	f((void *)0);

	stack = mmap(NULL, 2 * PAGE_SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	assert(stack != MAP_FAILED);
	/* side thread */
	pid = clone(f, stack + PAGE_SIZE, CLONE_THREAD|CLONE_SIGHAND|CLONE_VM, (void *)1);
	assert(pid > 0);
	pause();

	return 0;
}

