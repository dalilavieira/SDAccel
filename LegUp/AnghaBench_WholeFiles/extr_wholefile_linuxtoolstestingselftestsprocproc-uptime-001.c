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
typedef  int uint64_t ;
struct dirent {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  pid_t ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  SYS_getpid ; 
 int /*<<< orphan*/  SYS_gettid ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int pread (int,char*,int,int /*<<< orphan*/ ) ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 unsigned long long strtoull (char const*,char**,int) ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static void proc_uptime(int fd, uint64_t *uptime, uint64_t *idle)
{
	uint64_t val1, val2;
	char buf[64], *p;
	ssize_t rv;

	/* save "p < end" checks */
	memset(buf, 0, sizeof(buf));
	rv = pread(fd, buf, sizeof(buf), 0);
	assert(0 <= rv && rv <= sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';

	p = buf;

	val1 = xstrtoull(p, &p);
	assert(p[0] == '.');
	assert('0' <= p[1] && p[1] <= '9');
	assert('0' <= p[2] && p[2] <= '9');
	assert(p[3] == ' ');

	val2 = (p[1] - '0') * 10 + p[2] - '0';
	*uptime = val1 * 100 + val2;

	p += 4;

	val1 = xstrtoull(p, &p);
	assert(p[0] == '.');
	assert('0' <= p[1] && p[1] <= '9');
	assert('0' <= p[2] && p[2] <= '9');
	assert(p[3] == '\n');

	val2 = (p[1] - '0') * 10 + p[2] - '0';
	*idle = val1 * 100 + val2;

	assert(p + 4 == buf + rv);
}

int main(void)
{
	uint64_t start, u0, u1, i0, i1;
	int fd;

	fd = open("/proc/uptime", O_RDONLY);
	assert(fd >= 0);

	proc_uptime(fd, &u0, &i0);
	start = u0;
	do {
		proc_uptime(fd, &u1, &i1);
		assert(u1 >= u0);
		assert(i1 >= i0);
		u0 = u1;
		i0 = i1;
	} while (u1 - start < 100);

	return 0;
}

