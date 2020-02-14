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
struct perf_event_attr {int size; int disabled; int bp_type; int bp_addr; int bp_len; int exclude_user; void* type; } ;
typedef  int /*<<< orphan*/  pid_t ;
typedef  int /*<<< orphan*/  attr ;
typedef  int __u64 ;

/* Variables and functions */
 int DAWR_LENGTH_MAX ; 
 int HW_BREAKPOINT_R ; 
 int HW_BREAKPOINT_W ; 
 int MAX_LOOPS ; 
 int /*<<< orphan*/  PERF_EVENT_IOC_DISABLE ; 
 int /*<<< orphan*/  PERF_EVENT_IOC_ENABLE ; 
 void* PERF_TYPE_BREAKPOINT ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  __NR_perf_event_open ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  ioctl (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct perf_event_attr*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,unsigned long,unsigned long long,unsigned long long,int,int,int) ; 
 int rand () ; 
 size_t read (int,unsigned long long*,int) ; 
 int /*<<< orphan*/  srand (int /*<<< orphan*/ ) ; 
 int syscall (int /*<<< orphan*/ ,struct perf_event_attr*,int /*<<< orphan*/ ,int,int,unsigned long) ; 
 int test_harness (int (*) (),char*) ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int sys_perf_event_open(struct perf_event_attr *attr, pid_t pid,
				      int cpu, int group_fd,
				      unsigned long flags)
{
	attr->size = sizeof(*attr);
	return syscall(__NR_perf_event_open, attr, pid, cpu, group_fd, flags);
}

__attribute__((used)) static inline bool breakpoint_test(int len)
{
	struct perf_event_attr attr;
	int fd;

	/* setup counters */
	memset(&attr, 0, sizeof(attr));
	attr.disabled = 1;
	attr.type = PERF_TYPE_BREAKPOINT;
	attr.bp_type = HW_BREAKPOINT_R;
	/* bp_addr can point anywhere but needs to be aligned */
	attr.bp_addr = (__u64)(&attr) & 0xfffffffffffff800;
	attr.bp_len = len;
	fd = sys_perf_event_open(&attr, 0, -1, -1, 0);
	if (fd < 0)
		return false;
	close(fd);
	return true;
}

__attribute__((used)) static inline bool perf_breakpoint_supported(void)
{
	return breakpoint_test(4);
}

__attribute__((used)) static inline bool dawr_supported(void)
{
	return breakpoint_test(DAWR_LENGTH_MAX);
}

__attribute__((used)) static int runtestsingle(int readwriteflag, int exclude_user, int arraytest)
{
	int i,j;
	struct perf_event_attr attr;
	size_t res;
	unsigned long long breaks, needed;
	int readint;
	int readintarraybig[2*DAWR_LENGTH_MAX/sizeof(int)];
	int *readintalign;
	volatile int *ptr;
	int break_fd;
	int loop_num = MAX_LOOPS - (rand() % 100); /* provide some variability */
	volatile int *k;

	/* align to 0x400 boundary as required by DAWR */
	readintalign = (int *)(((unsigned long)readintarraybig + 0x7ff) &
			       0xfffffffffffff800);

	ptr = &readint;
	if (arraytest)
		ptr = &readintalign[0];

	/* setup counters */
	memset(&attr, 0, sizeof(attr));
	attr.disabled = 1;
	attr.type = PERF_TYPE_BREAKPOINT;
	attr.bp_type = readwriteflag;
	attr.bp_addr = (__u64)ptr;
	attr.bp_len = sizeof(int);
	if (arraytest)
		attr.bp_len = DAWR_LENGTH_MAX;
	attr.exclude_user = exclude_user;
	break_fd = sys_perf_event_open(&attr, 0, -1, -1, 0);
	if (break_fd < 0) {
		perror("sys_perf_event_open");
		exit(1);
	}

	/* start counters */
	ioctl(break_fd, PERF_EVENT_IOC_ENABLE);

	/* Test a bunch of reads and writes */
	k = &readint;
	for (i = 0; i < loop_num; i++) {
		if (arraytest)
			k = &(readintalign[i % (DAWR_LENGTH_MAX/sizeof(int))]);

		j = *k;
		*k = j;
	}

	/* stop counters */
	ioctl(break_fd, PERF_EVENT_IOC_DISABLE);

	/* read and check counters */
	res = read(break_fd, &breaks, sizeof(unsigned long long));
	assert(res == sizeof(unsigned long long));
	/* we read and write each loop, so subtract the ones we are counting */
	needed = 0;
	if (readwriteflag & HW_BREAKPOINT_R)
		needed += loop_num;
	if (readwriteflag & HW_BREAKPOINT_W)
		needed += loop_num;
	needed = needed * (1 - exclude_user);
	printf("TESTED: addr:0x%lx brks:% 8lld loops:% 8i rw:%i !user:%i array:%i\n",
	       (unsigned long int)ptr, breaks, loop_num, readwriteflag, exclude_user, arraytest);
	if (breaks != needed) {
		printf("FAILED: 0x%lx brks:%lld needed:%lli %i %i %i\n\n",
		       (unsigned long int)ptr, breaks, needed, loop_num, readwriteflag, exclude_user);
		return 1;
	}
	close(break_fd);

	return 0;
}

__attribute__((used)) static int runtest(void)
{
	int rwflag;
	int exclude_user;
	int ret;

	/*
	 * perf defines rwflag as two bits read and write and at least
	 * one must be set.  So range 1-3.
	 */
	for (rwflag = 1 ; rwflag < 4; rwflag++) {
		for (exclude_user = 0 ; exclude_user < 2; exclude_user++) {
			ret = runtestsingle(rwflag, exclude_user, 0);
			if (ret)
				return ret;

			/* if we have the dawr, we can do an array test */
			if (!dawr_supported())
				continue;
			ret = runtestsingle(rwflag, exclude_user, 1);
			if (ret)
				return ret;
		}
	}
	return 0;
}

__attribute__((used)) static int perf_hwbreak(void)
{
	srand ( time(NULL) );

	SKIP_IF(!perf_breakpoint_supported());

	return runtest();
}

int main(int argc, char *argv[], char **envp)
{
	return test_harness(perf_hwbreak, "perf_hwbreak");
}

