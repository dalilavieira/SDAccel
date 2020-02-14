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

/* Variables and functions */
 int ITERATIONS ; 
 int LARGE_ITERATIONS ; 
 unsigned long LARGE_MAX_OFFSET ; 
 unsigned long LARGE_SIZE ; 
 unsigned long LARGE_SIZE_START ; 
 unsigned long MAX_OFFSET_DIFF_S1_S2 ; 
 unsigned long SIZE ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  exit (int) ; 
 char* memalign (int,unsigned long) ; 
 int memcmp (char*,char*,unsigned long) ; 
 int /*<<< orphan*/  memcpy (char*,char*,unsigned long) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int random () ; 
 int /*<<< orphan*/  srandom (int /*<<< orphan*/ ) ; 
 int test_harness (int (*) (),char*) ; 
 int /*<<< orphan*/  test_harness_set_timeout (int) ; 
 int test_memcmp (char*,char*,unsigned long) ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ ) ; 
 scalar_t__ vmx_count ; 

int enter_vmx_ops(void)
{
	vmx_count++;
	return 1;
}

void exit_vmx_ops(void)
{
	vmx_count--;
}

__attribute__((used)) static void test_one(char *s1, char *s2, unsigned long max_offset,
		unsigned long size_start, unsigned long max_size)
{
	unsigned long offset, size;

	for (offset = 0; offset < max_offset; offset++) {
		for (size = size_start; size < (max_size - offset); size++) {
			int x, y;
			unsigned long i;

			y = memcmp(s1+offset, s2+offset, size);
			x = test_memcmp(s1+offset, s2+offset, size);

			if (((x ^ y) < 0) &&	/* Trick to compare sign */
				((x | y) != 0)) { /* check for zero */
				printf("memcmp returned %d, should have returned %d (offset %ld size %ld)\n", x, y, offset, size);

				for (i = offset; i < offset+size; i++)
					printf("%02x ", s1[i]);
				printf("\n");

				for (i = offset; i < offset+size; i++)
					printf("%02x ", s2[i]);
				printf("\n");
				abort();
			}

			if (vmx_count != 0) {
				printf("vmx enter/exit not paired.(offset:%ld size:%ld s1:%p s2:%p vc:%d\n",
					offset, size, s1, s2, vmx_count);
				printf("\n");
				abort();
			}
		}
	}
}

__attribute__((used)) static int testcase(bool islarge)
{
	char *s1;
	char *s2;
	unsigned long i;

	unsigned long comp_size = (islarge ? LARGE_SIZE : SIZE);
	unsigned long alloc_size = comp_size + MAX_OFFSET_DIFF_S1_S2;
	int iterations = islarge ? LARGE_ITERATIONS : ITERATIONS;

	s1 = memalign(128, alloc_size);
	if (!s1) {
		perror("memalign");
		exit(1);
	}

	s2 = memalign(128, alloc_size);
	if (!s2) {
		perror("memalign");
		exit(1);
	}

	srandom(time(0));

	for (i = 0; i < iterations; i++) {
		unsigned long j;
		unsigned long change;
		char *rand_s1 = s1;
		char *rand_s2 = s2;

		for (j = 0; j < alloc_size; j++)
			s1[j] = random();

		rand_s1 += random() % MAX_OFFSET_DIFF_S1_S2;
		rand_s2 += random() % MAX_OFFSET_DIFF_S1_S2;
		memcpy(rand_s2, rand_s1, comp_size);

		/* change one byte */
		change = random() % comp_size;
		rand_s2[change] = random() & 0xff;

		if (islarge)
			test_one(rand_s1, rand_s2, LARGE_MAX_OFFSET,
					LARGE_SIZE_START, comp_size);
		else
			test_one(rand_s1, rand_s2, SIZE, 0, comp_size);
	}

	srandom(time(0));

	for (i = 0; i < iterations; i++) {
		unsigned long j;
		unsigned long change;
		char *rand_s1 = s1;
		char *rand_s2 = s2;

		for (j = 0; j < alloc_size; j++)
			s1[j] = random();

		rand_s1 += random() % MAX_OFFSET_DIFF_S1_S2;
		rand_s2 += random() % MAX_OFFSET_DIFF_S1_S2;
		memcpy(rand_s2, rand_s1, comp_size);

		/* change multiple bytes, 1/8 of total */
		for (j = 0; j < comp_size / 8; j++) {
			change = random() % comp_size;
			s2[change] = random() & 0xff;
		}

		if (islarge)
			test_one(rand_s1, rand_s2, LARGE_MAX_OFFSET,
					LARGE_SIZE_START, comp_size);
		else
			test_one(rand_s1, rand_s2, SIZE, 0, comp_size);
	}

	return 0;
}

__attribute__((used)) static int testcases(void)
{
	testcase(0);
	testcase(1);
	return 0;
}

int main(void)
{
	test_harness_set_timeout(300);
	return test_harness(testcases, "memcmp");
}

