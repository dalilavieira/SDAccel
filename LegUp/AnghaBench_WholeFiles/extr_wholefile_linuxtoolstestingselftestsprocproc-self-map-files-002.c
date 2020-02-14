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
typedef  int /*<<< orphan*/  name ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 scalar_t__ ENOENT ; 
 scalar_t__ EPERM ; 
 void* MAP_FAILED ; 
 int MAP_FILE ; 
 int MAP_FIXED ; 
 int MAP_PRIVATE ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  PROT_NONE ; 
 int /*<<< orphan*/  _SC_PAGESIZE ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 void* mmap (void*,unsigned int const,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int readlink (char*,char*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char const*,unsigned long,unsigned long) ; 
 unsigned int sysconf (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pass(const char *fmt, unsigned long a, unsigned long b)
{
	char name[64];
	char buf[64];

	snprintf(name, sizeof(name), fmt, a, b);
	if (readlink(name, buf, sizeof(buf)) == -1)
		exit(1);
}

__attribute__((used)) static void fail(const char *fmt, unsigned long a, unsigned long b)
{
	char name[64];
	char buf[64];

	snprintf(name, sizeof(name), fmt, a, b);
	if (readlink(name, buf, sizeof(buf)) == -1 && errno == ENOENT)
		return;
	exit(1);
}

int main(void)
{
	const unsigned int PAGE_SIZE = sysconf(_SC_PAGESIZE);
#ifdef __arm__
	unsigned long va = 2 * PAGE_SIZE;
#else
	unsigned long va = 0;
#endif
	void *p;
	int fd;
	unsigned long a, b;

	fd = open("/dev/zero", O_RDONLY);
	if (fd == -1)
		return 1;

	p = mmap((void *)va, PAGE_SIZE, PROT_NONE, MAP_PRIVATE|MAP_FILE|MAP_FIXED, fd, 0);
	if (p == MAP_FAILED) {
		if (errno == EPERM)
			return 2;
		return 1;
	}

	a = (unsigned long)p;
	b = (unsigned long)p + PAGE_SIZE;

	pass("/proc/self/map_files/%lx-%lx", a, b);
	fail("/proc/self/map_files/ %lx-%lx", a, b);
	fail("/proc/self/map_files/%lx -%lx", a, b);
	fail("/proc/self/map_files/%lx- %lx", a, b);
	fail("/proc/self/map_files/%lx-%lx ", a, b);
	fail("/proc/self/map_files/0%lx-%lx", a, b);
	fail("/proc/self/map_files/%lx-0%lx", a, b);
	if (sizeof(long) == 4) {
		fail("/proc/self/map_files/100000000%lx-%lx", a, b);
		fail("/proc/self/map_files/%lx-100000000%lx", a, b);
	} else if (sizeof(long) == 8) {
		fail("/proc/self/map_files/10000000000000000%lx-%lx", a, b);
		fail("/proc/self/map_files/%lx-10000000000000000%lx", a, b);
	} else
		return 1;

	return 0;
}

