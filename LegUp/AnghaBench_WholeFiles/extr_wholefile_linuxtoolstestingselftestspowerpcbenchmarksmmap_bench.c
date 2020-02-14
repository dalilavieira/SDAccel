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
struct timespec {double tv_sec; int tv_nsec; } ;
struct TYPE_3__ {int /*<<< orphan*/  flag; } ;

/* Variables and functions */
 int CHUNK_COUNT ; 
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int MAP_ANONYMOUS ; 
 char* MAP_FAILED ; 
 int MAP_PRIVATE ; 
 int /*<<< orphan*/  MEMSIZE ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 unsigned long atoi (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  exit (int) ; 
 char getopt_long (int,char**,char*,TYPE_1__*,int*) ; 
 unsigned long iterations ; 
 char* mmap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  munmap (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  optarg ; 
 TYPE_1__* options ; 
 scalar_t__ pg_fault ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int test_harness (int (*) (),char*) ; 
 int /*<<< orphan*/  test_harness_set_timeout (int) ; 

__attribute__((used)) static void usage(void)
{
	printf("mmap_bench <--pgfault> <--iterations count>\n");
}

int test_mmap(void)
{
	struct timespec ts_start, ts_end;
	unsigned long i = iterations;

	clock_gettime(CLOCK_MONOTONIC, &ts_start);

	while (i--) {
		char *c = mmap(NULL, MEMSIZE, PROT_READ|PROT_WRITE,
			       MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
		FAIL_IF(c == MAP_FAILED);
		if (pg_fault) {
			int count;
			for (count = 0; count < CHUNK_COUNT; count++)
				c[count << 16] = 'c';
		}
		munmap(c, MEMSIZE);
	}

	clock_gettime(CLOCK_MONOTONIC, &ts_end);

	printf("time = %.6f\n", ts_end.tv_sec - ts_start.tv_sec + (ts_end.tv_nsec - ts_start.tv_nsec) / 1e9);

	return 0;
}

int main(int argc, char *argv[])
{
	signed char c;
	while (1) {
		int option_index = 0;

		c = getopt_long(argc, argv, "", options, &option_index);

		if (c == -1)
			break;

		switch (c) {
		case 0:
			if (options[option_index].flag != 0)
				break;

			usage();
			exit(1);
			break;
		case 'i':
			iterations = atoi(optarg);
			break;
		default:
			usage();
			exit(1);
		}
	}

	test_harness_set_timeout(300);
	return test_harness(test_mmap, "mmap_bench");
}

