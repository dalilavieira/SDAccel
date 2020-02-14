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
struct timespec {unsigned long long tv_sec; int tv_nsec; } ;
struct rlimit {int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
typedef  int pid_t ;
typedef  int /*<<< orphan*/  filename ;
typedef  int /*<<< orphan*/  cpuset ;
typedef  int /*<<< orphan*/  cpu_set_t ;
typedef  int /*<<< orphan*/  buf ;
typedef  int __u64 ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 int /*<<< orphan*/  CPU_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CPU_ZERO (int /*<<< orphan*/ *) ; 
 int MAX_CNT ; 
 int O_RDONLY ; 
 int O_TRUNC ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  RLIMIT_MEMLOCK ; 
 int /*<<< orphan*/  RLIM_INFINITY ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ atoi (char*) ; 
 char* bpf_log_buf ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  errno ; 
 int* event_fd ; 
 int /*<<< orphan*/  exit (int) ; 
 int fork () ; 
 scalar_t__ load_bpf_file (char*) ; 
 int open (char*,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int* prog_fd ; 
 scalar_t__ read (int,char*,int) ; 
 int /*<<< orphan*/  sched_setaffinity (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setrlimit (int /*<<< orphan*/ ,struct rlimit*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 
 char* strerror (int /*<<< orphan*/ ) ; 
 int waitpid (int,int*,int /*<<< orphan*/ ) ; 
 scalar_t__ write (int,char*,int) ; 

__attribute__((used)) static __u64 time_get_ns(void)
{
	struct timespec ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000000ull + ts.tv_nsec;
}

__attribute__((used)) static void test_task_rename(int cpu)
{
	__u64 start_time;
	char buf[] = "test\n";
	int i, fd;

	fd = open("/proc/self/comm", O_WRONLY|O_TRUNC);
	if (fd < 0) {
		printf("couldn't open /proc\n");
		exit(1);
	}
	start_time = time_get_ns();
	for (i = 0; i < MAX_CNT; i++) {
		if (write(fd, buf, sizeof(buf)) < 0) {
			printf("task rename failed: %s\n", strerror(errno));
			close(fd);
			return;
		}
	}
	printf("task_rename:%d: %lld events per sec\n",
	       cpu, MAX_CNT * 1000000000ll / (time_get_ns() - start_time));
	close(fd);
}

__attribute__((used)) static void test_urandom_read(int cpu)
{
	__u64 start_time;
	char buf[4];
	int i, fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0) {
		printf("couldn't open /dev/urandom\n");
		exit(1);
	}
	start_time = time_get_ns();
	for (i = 0; i < MAX_CNT; i++) {
		if (read(fd, buf, sizeof(buf)) < 0) {
			printf("failed to read from /dev/urandom: %s\n", strerror(errno));
			close(fd);
			return;
		}
	}
	printf("urandom_read:%d: %lld events per sec\n",
	       cpu, MAX_CNT * 1000000000ll / (time_get_ns() - start_time));
	close(fd);
}

__attribute__((used)) static void loop(int cpu, int flags)
{
	cpu_set_t cpuset;

	CPU_ZERO(&cpuset);
	CPU_SET(cpu, &cpuset);
	sched_setaffinity(0, sizeof(cpuset), &cpuset);

	if (flags & 1)
		test_task_rename(cpu);
	if (flags & 2)
		test_urandom_read(cpu);
}

__attribute__((used)) static void run_perf_test(int tasks, int flags)
{
	pid_t pid[tasks];
	int i;

	for (i = 0; i < tasks; i++) {
		pid[i] = fork();
		if (pid[i] == 0) {
			loop(i, flags);
			exit(0);
		} else if (pid[i] == -1) {
			printf("couldn't spawn #%d process\n", i);
			exit(1);
		}
	}
	for (i = 0; i < tasks; i++) {
		int status;

		assert(waitpid(pid[i], &status, 0) == pid[i]);
		assert(status == 0);
	}
}

__attribute__((used)) static void unload_progs(void)
{
	close(prog_fd[0]);
	close(prog_fd[1]);
	close(event_fd[0]);
	close(event_fd[1]);
}

int main(int argc, char **argv)
{
	struct rlimit r = {RLIM_INFINITY, RLIM_INFINITY};
	char filename[256];
	int num_cpu = 8;
	int test_flags = ~0;

	setrlimit(RLIMIT_MEMLOCK, &r);

	if (argc > 1)
		test_flags = atoi(argv[1]) ? : test_flags;
	if (argc > 2)
		num_cpu = atoi(argv[2]) ? : num_cpu;

	if (test_flags & 0x3) {
		printf("BASE\n");
		run_perf_test(num_cpu, test_flags);
	}

	if (test_flags & 0xC) {
		snprintf(filename, sizeof(filename),
			 "%s_kprobe_kern.o", argv[0]);
		if (load_bpf_file(filename)) {
			printf("%s", bpf_log_buf);
			return 1;
		}
		printf("w/KPROBE\n");
		run_perf_test(num_cpu, test_flags >> 2);
		unload_progs();
	}

	if (test_flags & 0x30) {
		snprintf(filename, sizeof(filename),
			 "%s_tp_kern.o", argv[0]);
		if (load_bpf_file(filename)) {
			printf("%s", bpf_log_buf);
			return 1;
		}
		printf("w/TRACEPOINT\n");
		run_perf_test(num_cpu, test_flags >> 4);
		unload_progs();
	}

	if (test_flags & 0xC0) {
		snprintf(filename, sizeof(filename),
			 "%s_raw_tp_kern.o", argv[0]);
		if (load_bpf_file(filename)) {
			printf("%s", bpf_log_buf);
			return 1;
		}
		printf("w/RAW_TRACEPOINT\n");
		run_perf_test(num_cpu, test_flags >> 6);
		unload_progs();
	}

	return 0;
}

