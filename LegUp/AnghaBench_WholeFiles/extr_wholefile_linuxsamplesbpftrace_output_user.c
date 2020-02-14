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
struct timespec {unsigned long long tv_sec; long long tv_nsec; } ;
struct perf_event_attr {int /*<<< orphan*/  config; int /*<<< orphan*/  type; int /*<<< orphan*/  sample_type; } ;
typedef  int /*<<< orphan*/  filename ;
typedef  long long __u64 ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  BPF_ANY ; 
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 int LIBBPF_PERF_EVENT_CONT ; 
 int LIBBPF_PERF_EVENT_DONE ; 
 int LIBBPF_PERF_EVENT_ERROR ; 
 long long MAX_CNT ; 
 int /*<<< orphan*/  PERF_COUNT_SW_BPF_OUTPUT ; 
 int /*<<< orphan*/  PERF_EVENT_IOC_ENABLE ; 
 int /*<<< orphan*/  PERF_SAMPLE_RAW ; 
 int /*<<< orphan*/  PERF_TYPE_SOFTWARE ; 
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  assert (int) ; 
 char* bpf_log_buf ; 
 scalar_t__ bpf_map_update_elem (int /*<<< orphan*/ ,int*,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  ioctl (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kill (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ load_bpf_file (char*) ; 
 int /*<<< orphan*/ * map_fd ; 
 scalar_t__ perf_event_mmap (scalar_t__) ; 
 int perf_event_poller (scalar_t__,int (*) (void*,int)) ; 
 scalar_t__ pmu_fd ; 
 int /*<<< orphan*/ * popen (char*,char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 
 long long start_time ; 
 scalar_t__ sys_perf_event_open (struct perf_event_attr*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __u64 time_get_ns(void)
{
	struct timespec ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000000ull + ts.tv_nsec;
}

__attribute__((used)) static int print_bpf_output(void *data, int size)
{
	static __u64 cnt;
	struct {
		__u64 pid;
		__u64 cookie;
	} *e = data;

	if (e->cookie != 0x12345678) {
		printf("BUG pid %llx cookie %llx sized %d\n",
		       e->pid, e->cookie, size);
		return LIBBPF_PERF_EVENT_ERROR;
	}

	cnt++;

	if (cnt == MAX_CNT) {
		printf("recv %lld events per sec\n",
		       MAX_CNT * 1000000000ll / (time_get_ns() - start_time));
		return LIBBPF_PERF_EVENT_DONE;
	}

	return LIBBPF_PERF_EVENT_CONT;
}

__attribute__((used)) static void test_bpf_perf_event(void)
{
	struct perf_event_attr attr = {
		.sample_type = PERF_SAMPLE_RAW,
		.type = PERF_TYPE_SOFTWARE,
		.config = PERF_COUNT_SW_BPF_OUTPUT,
	};
	int key = 0;

	pmu_fd = sys_perf_event_open(&attr, -1/*pid*/, 0/*cpu*/, -1/*group_fd*/, 0);

	assert(pmu_fd >= 0);
	assert(bpf_map_update_elem(map_fd[0], &key, &pmu_fd, BPF_ANY) == 0);
	ioctl(pmu_fd, PERF_EVENT_IOC_ENABLE, 0);
}

int main(int argc, char **argv)
{
	char filename[256];
	FILE *f;
	int ret;

	snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);

	if (load_bpf_file(filename)) {
		printf("%s", bpf_log_buf);
		return 1;
	}

	test_bpf_perf_event();

	if (perf_event_mmap(pmu_fd) < 0)
		return 1;

	f = popen("taskset 1 dd if=/dev/zero of=/dev/null", "r");
	(void) f;

	start_time = time_get_ns();
	ret = perf_event_poller(pmu_fd, print_bpf_output);
	kill(0, SIGINT);
	return ret;
}

