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
struct timespec {int tv_sec; int tv_nsec; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 unsigned long ITERATIONS ; 
 int ITERATIONS_BENCH ; 
 unsigned long SIZE ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  exit (int) ; 
 char* memalign (int,unsigned long) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int random () ; 
 int /*<<< orphan*/  srandom (int) ; 
 int strlen (char*) ; 
 int test_harness (int (*) (),char*) ; 
 int test_strlen (char*) ; 

__attribute__((used)) static void test_one(char *s)
{
	unsigned long offset;

	for (offset = 0; offset < SIZE; offset++) {
		int x, y;
		unsigned long i;

		y = strlen(s + offset);
		x = test_strlen(s + offset);

		if (x != y) {
			printf("strlen() returned %d, should have returned %d (%p offset %ld)\n", x, y, s, offset);

			for (i = offset; i < SIZE; i++)
				printf("%02x ", s[i]);
			printf("\n");
		}
	}
}

__attribute__((used)) static void bench_test(char *s)
{
	struct timespec ts_start, ts_end;
	int i;

	clock_gettime(CLOCK_MONOTONIC, &ts_start);

	for (i = 0; i < ITERATIONS_BENCH; i++)
		test_strlen(s);

	clock_gettime(CLOCK_MONOTONIC, &ts_end);

	printf("len %3.3d : time = %.6f\n", test_strlen(s), ts_end.tv_sec - ts_start.tv_sec + (ts_end.tv_nsec - ts_start.tv_nsec) / 1e9);
}

__attribute__((used)) static int testcase(void)
{
	char *s;
	unsigned long i;

	s = memalign(128, SIZE);
	if (!s) {
		perror("memalign");
		exit(1);
	}

	srandom(1);

	memset(s, 0, SIZE);
	for (i = 0; i < SIZE; i++) {
		char c;

		do {
			c = random() & 0x7f;
		} while (!c);
		s[i] = c;
		test_one(s);
	}

	for (i = 0; i < ITERATIONS; i++) {
		unsigned long j;

		for (j = 0; j < SIZE; j++) {
			char c;

			do {
				c = random() & 0x7f;
			} while (!c);
			s[j] = c;
		}
		for (j = 0; j < sizeof(long); j++) {
			s[SIZE - 1 - j] = 0;
			test_one(s);
		}
	}

	for (i = 0; i < SIZE; i++) {
		char c;

		do {
			c = random() & 0x7f;
		} while (!c);
		s[i] = c;
	}

	bench_test(s);

	s[16] = 0;
	bench_test(s);

	s[8] = 0;
	bench_test(s);

	s[4] = 0;
	bench_test(s);

	s[3] = 0;
	bench_test(s);

	s[2] = 0;
	bench_test(s);

	s[1] = 0;
	bench_test(s);

	return 0;
}

int main(void)
{
	return test_harness(testcase, "strlen");
}

