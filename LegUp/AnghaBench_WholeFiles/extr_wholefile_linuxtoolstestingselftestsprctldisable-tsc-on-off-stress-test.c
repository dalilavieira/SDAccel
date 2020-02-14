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
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  PR_SET_TSC ; 
 int /*<<< orphan*/  PR_TSC_ENABLE ; 
 int /*<<< orphan*/  PR_TSC_SIGSEGV ; 
 int /*<<< orphan*/  SIGSEGV ; 
 int /*<<< orphan*/  alarm (int) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 scalar_t__ fork () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  perror (char*) ; 
 scalar_t__ prctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int should_segv ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int)) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  wait (int /*<<< orphan*/ *) ; 

__attribute__((used)) static uint64_t rdtsc(void)
{
uint32_t lo, hi;
/* We cannot use "=A", since this would use %rax on x86_64 */
__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
return (uint64_t)hi << 32 | lo;
}

__attribute__((used)) static void sigsegv_cb(int sig)
{
	if (!should_segv)
	{
		fprintf(stderr, "FATAL ERROR, rdtsc() failed while enabled\n");
		exit(0);
	}
	if (prctl(PR_SET_TSC, PR_TSC_ENABLE) < 0)
	{
		perror("prctl");
		exit(0);
	}
	should_segv = 0;

	rdtsc();
}

__attribute__((used)) static void task(void)
{
	signal(SIGSEGV, sigsegv_cb);
	alarm(10);
	for(;;)
	{
		rdtsc();
		if (should_segv)
		{
			fprintf(stderr, "FATAL ERROR, rdtsc() succeeded while disabled\n");
			exit(0);
		}
		if (prctl(PR_SET_TSC, PR_TSC_SIGSEGV) < 0)
		{
			perror("prctl");
			exit(0);
		}
		should_segv = 1;
	}
}

int main(void)
{
	int n_tasks = 100, i;

	fprintf(stderr, "[No further output means we're allright]\n");

	for (i=0; i<n_tasks; i++)
		if (fork() == 0)
			task();

	for (i=0; i<n_tasks; i++)
		wait(NULL);

	exit(0);
}

