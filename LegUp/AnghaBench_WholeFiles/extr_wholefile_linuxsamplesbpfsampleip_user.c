#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct perf_event_attr {int freq; int sample_period; int inherit; int /*<<< orphan*/  config; int /*<<< orphan*/  type; } ;
struct ksym {int /*<<< orphan*/  name; } ;
struct ipcount {int count; } ;
typedef  int /*<<< orphan*/  filename ;
typedef  scalar_t__ __u64 ;
typedef  int /*<<< orphan*/  __u32 ;
struct TYPE_3__ {int /*<<< orphan*/  count; scalar_t__ ip; } ;

/* Variables and functions */
 int DEFAULT_FREQ ; 
 int DEFAULT_SECS ; 
 int MAX_IPS ; 
 scalar_t__ PAGE_OFFSET ; 
 int /*<<< orphan*/  PERF_COUNT_SW_CPU_CLOCK ; 
 int /*<<< orphan*/  PERF_EVENT_IOC_ENABLE ; 
 int /*<<< orphan*/  PERF_EVENT_IOC_SET_BPF ; 
 int /*<<< orphan*/  PERF_TYPE_SOFTWARE ; 
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  SIGTERM ; 
 int /*<<< orphan*/  _SC_NPROCESSORS_CONF ; 
 int /*<<< orphan*/  assert (int) ; 
 int atoi (char*) ; 
 char* bpf_log_buf ; 
 scalar_t__ bpf_map_get_next_key (int,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  bpf_map_lookup_elem (int,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  close (int) ; 
 TYPE_1__* counts ; 
 int errno ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (int*) ; 
 int getopt (int,char**,char*) ; 
 scalar_t__ ioctl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ksym* ksym_search (scalar_t__) ; 
 scalar_t__ load_bpf_file (char*) ; 
 scalar_t__ load_kallsyms () ; 
 int* malloc (int) ; 
 int* map_fd ; 
 int nr_cpus ; 
 char* optarg ; 
 int optind ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/ * prog_fd ; 
 int /*<<< orphan*/  qsort (TYPE_1__*,int,int,int (*) (void const*,void const*)) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int)) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char*,char*) ; 
 int sys_perf_event_open (struct perf_event_attr*,int,int,int,int /*<<< orphan*/ ) ; 
 int sysconf (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void usage(void)
{
	printf("USAGE: sampleip [-F freq] [duration]\n");
	printf("       -F freq    # sample frequency (Hertz), default 99\n");
	printf("       duration   # sampling duration (seconds), default 5\n");
}

__attribute__((used)) static int sampling_start(int *pmu_fd, int freq)
{
	int i;

	struct perf_event_attr pe_sample_attr = {
		.type = PERF_TYPE_SOFTWARE,
		.freq = 1,
		.sample_period = freq,
		.config = PERF_COUNT_SW_CPU_CLOCK,
		.inherit = 1,
	};

	for (i = 0; i < nr_cpus; i++) {
		pmu_fd[i] = sys_perf_event_open(&pe_sample_attr, -1 /* pid */, i,
					    -1 /* group_fd */, 0 /* flags */);
		if (pmu_fd[i] < 0) {
			fprintf(stderr, "ERROR: Initializing perf sampling\n");
			return 1;
		}
		assert(ioctl(pmu_fd[i], PERF_EVENT_IOC_SET_BPF,
			     prog_fd[0]) == 0);
		assert(ioctl(pmu_fd[i], PERF_EVENT_IOC_ENABLE, 0) == 0);
	}

	return 0;
}

__attribute__((used)) static void sampling_end(int *pmu_fd)
{
	int i;

	for (i = 0; i < nr_cpus; i++)
		close(pmu_fd[i]);
}

__attribute__((used)) static int count_cmp(const void *p1, const void *p2)
{
	return ((struct ipcount *)p1)->count - ((struct ipcount *)p2)->count;
}

__attribute__((used)) static void print_ip_map(int fd)
{
	struct ksym *sym;
	__u64 key, next_key;
	__u32 value;
	int i, max;

	printf("%-19s %-32s %s\n", "ADDR", "KSYM", "COUNT");

	/* fetch IPs and counts */
	key = 0, i = 0;
	while (bpf_map_get_next_key(fd, &key, &next_key) == 0) {
		bpf_map_lookup_elem(fd, &next_key, &value);
		counts[i].ip = next_key;
		counts[i++].count = value;
		key = next_key;
	}
	max = i;

	/* sort and print */
	qsort(counts, max, sizeof(struct ipcount), count_cmp);
	for (i = 0; i < max; i++) {
		if (counts[i].ip > PAGE_OFFSET) {
			sym = ksym_search(counts[i].ip);
			printf("0x%-17llx %-32s %u\n", counts[i].ip, sym->name,
			       counts[i].count);
		} else {
			printf("0x%-17llx %-32s %u\n", counts[i].ip, "(user)",
			       counts[i].count);
		}
	}

	if (max == MAX_IPS) {
		printf("WARNING: IP hash was full (max %d entries); ", max);
		printf("may have dropped samples\n");
	}
}

__attribute__((used)) static void int_exit(int sig)
{
	printf("\n");
	print_ip_map(map_fd[0]);
	exit(0);
}

int main(int argc, char **argv)
{
	char filename[256];
	int *pmu_fd, opt, freq = DEFAULT_FREQ, secs = DEFAULT_SECS;

	/* process arguments */
	while ((opt = getopt(argc, argv, "F:h")) != -1) {
		switch (opt) {
		case 'F':
			freq = atoi(optarg);
			break;
		case 'h':
		default:
			usage();
			return 0;
		}
	}
	if (argc - optind == 1)
		secs = atoi(argv[optind]);
	if (freq == 0 || secs == 0) {
		usage();
		return 1;
	}

	/* initialize kernel symbol translation */
	if (load_kallsyms()) {
		fprintf(stderr, "ERROR: loading /proc/kallsyms\n");
		return 2;
	}

	/* create perf FDs for each CPU */
	nr_cpus = sysconf(_SC_NPROCESSORS_CONF);
	pmu_fd = malloc(nr_cpus * sizeof(int));
	if (pmu_fd == NULL) {
		fprintf(stderr, "ERROR: malloc of pmu_fd\n");
		return 1;
	}

	/* load BPF program */
	snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);
	if (load_bpf_file(filename)) {
		fprintf(stderr, "ERROR: loading BPF program (errno %d):\n",
			errno);
		if (strcmp(bpf_log_buf, "") == 0)
			fprintf(stderr, "Try: ulimit -l unlimited\n");
		else
			fprintf(stderr, "%s", bpf_log_buf);
		return 1;
	}
	signal(SIGINT, int_exit);
	signal(SIGTERM, int_exit);

	/* do sampling */
	printf("Sampling at %d Hertz for %d seconds. Ctrl-C also ends.\n",
	       freq, secs);
	if (sampling_start(pmu_fd, freq) != 0)
		return 1;
	sleep(secs);
	sampling_end(pmu_fd);
	free(pmu_fd);

	/* output sample counts */
	print_ip_map(map_fd[0]);

	return 0;
}

