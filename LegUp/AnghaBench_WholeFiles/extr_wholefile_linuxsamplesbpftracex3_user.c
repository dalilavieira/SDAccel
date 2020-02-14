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
typedef  int /*<<< orphan*/  values ;
struct rlimit {int member_0; int /*<<< orphan*/  member_1; } ;
typedef  int /*<<< orphan*/  filename ;
typedef  int __u64 ;
typedef  int __u32 ;

/* Variables and functions */
 int /*<<< orphan*/  BPF_ANY ; 
 int /*<<< orphan*/  RLIMIT_MEMLOCK ; 
 int /*<<< orphan*/  RLIM_INFINITY ; 
 int SLOTS ; 
 char* bpf_log_buf ; 
 int /*<<< orphan*/  bpf_map_lookup_elem (int,int*,long*) ; 
 int /*<<< orphan*/  bpf_map_update_elem (int,int*,int*,int /*<<< orphan*/ ) ; 
 unsigned int bpf_num_possible_cpus () ; 
 char** color ; 
 int full_range ; 
 scalar_t__ load_bpf_file (char*) ; 
 int* map_fd ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 char* nocolor ; 
 int num_colors ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ setrlimit (int /*<<< orphan*/ ,struct rlimit*) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 char** sym ; 
 int text_only ; 

__attribute__((used)) static void clear_stats(int fd)
{
	unsigned int nr_cpus = bpf_num_possible_cpus();
	__u64 values[nr_cpus];
	__u32 key;

	memset(values, 0, sizeof(values));
	for (key = 0; key < SLOTS; key++)
		bpf_map_update_elem(fd, &key, values, BPF_ANY);
}

__attribute__((used)) static void print_banner(void)
{
	if (full_range)
		printf("|1ns     |10ns     |100ns    |1us      |10us     |100us"
		       "    |1ms      |10ms     |100ms    |1s       |10s\n");
	else
		printf("|1us      |10us     |100us    |1ms      |10ms     "
		       "|100ms    |1s       |10s\n");
}

__attribute__((used)) static void print_hist(int fd)
{
	unsigned int nr_cpus = bpf_num_possible_cpus();
	__u64 total_events = 0;
	long values[nr_cpus];
	__u64 max_cnt = 0;
	__u64 cnt[SLOTS];
	__u64 value;
	__u32 key;
	int i;

	for (key = 0; key < SLOTS; key++) {
		bpf_map_lookup_elem(fd, &key, values);
		value = 0;
		for (i = 0; i < nr_cpus; i++)
			value += values[i];
		cnt[key] = value;
		total_events += value;
		if (value > max_cnt)
			max_cnt = value;
	}
	clear_stats(fd);
	for (key = full_range ? 0 : 29; key < SLOTS; key++) {
		int c = num_colors * cnt[key] / (max_cnt + 1);

		if (text_only)
			printf("%s", sym[c]);
		else
			printf("%s %s", color[c], nocolor);
	}
	printf(" # %lld\n", total_events);
}

int main(int ac, char **argv)
{
	struct rlimit r = {1024*1024, RLIM_INFINITY};
	char filename[256];
	int i;

	snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);

	if (setrlimit(RLIMIT_MEMLOCK, &r)) {
		perror("setrlimit(RLIMIT_MEMLOCK)");
		return 1;
	}

	if (load_bpf_file(filename)) {
		printf("%s", bpf_log_buf);
		return 1;
	}

	for (i = 1; i < ac; i++) {
		if (strcmp(argv[i], "-a") == 0) {
			full_range = true;
		} else if (strcmp(argv[i], "-t") == 0) {
			text_only = true;
		} else if (strcmp(argv[i], "-h") == 0) {
			printf("Usage:\n"
			       "  -a display wider latency range\n"
			       "  -t text only\n");
			return 1;
		}
	}

	printf("  heatmap of IO latency\n");
	if (text_only)
		printf("  %s", sym[num_colors - 1]);
	else
		printf("  %s %s", color[num_colors - 1], nocolor);
	printf(" - many events with this latency\n");

	if (text_only)
		printf("  %s", sym[0]);
	else
		printf("  %s %s", color[0], nocolor);
	printf(" - few events\n");

	for (i = 0; ; i++) {
		if (i % 20 == 0)
			print_banner();
		print_hist(map_fd[1]);
		sleep(2);
	}

	return 0;
}

