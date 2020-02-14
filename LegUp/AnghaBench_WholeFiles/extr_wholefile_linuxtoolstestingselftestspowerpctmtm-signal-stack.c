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
 int /*<<< orphan*/  SIGSEGV ; 
 scalar_t__ SIG_ERR ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int TM_CAUSE_FAC_UNAV ; 
 int TM_CAUSE_PERSISTENT ; 
 int TM_CAUSE_SYSCALL ; 
 int __builtin_get_texasru () ; 
 int /*<<< orphan*/  exit (int) ; 
 int fork () ; 
 int /*<<< orphan*/  printf (char*) ; 
 scalar_t__ signal (int /*<<< orphan*/ ,void (*) (int)) ; 
 int test_harness (int (*) (),char*) ; 
 int /*<<< orphan*/  wait (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool have_htm(void)
{
#ifdef PPC_FEATURE2_HTM
	return have_hwcap2(PPC_FEATURE2_HTM);
#else
	printf("PPC_FEATURE2_HTM not defined, can't check AT_HWCAP2\n");
	return false;
#endif
}

__attribute__((used)) static inline bool have_htm_nosc(void)
{
#ifdef PPC_FEATURE2_HTM_NOSC
	return have_hwcap2(PPC_FEATURE2_HTM_NOSC);
#else
	printf("PPC_FEATURE2_HTM_NOSC not defined, can't check AT_HWCAP2\n");
	return false;
#endif
}

__attribute__((used)) static inline long failure_code(void)
{
	return __builtin_get_texasru() >> 24;
}

__attribute__((used)) static inline bool failure_is_persistent(void)
{
	return (failure_code() & TM_CAUSE_PERSISTENT) == TM_CAUSE_PERSISTENT;
}

__attribute__((used)) static inline bool failure_is_syscall(void)
{
	return (failure_code() & TM_CAUSE_SYSCALL) == TM_CAUSE_SYSCALL;
}

__attribute__((used)) static inline bool failure_is_unavailable(void)
{
	return (failure_code() & TM_CAUSE_FAC_UNAV) == TM_CAUSE_FAC_UNAV;
}

__attribute__((used)) static inline bool failure_is_nesting(void)
{
	return (__builtin_get_texasru() & 0x400000);
}

__attribute__((used)) static inline int tcheck(void)
{
	long cr;
	asm volatile ("tcheck 0" : "=r"(cr) : : "cr0");
	return (cr >> 28) & 4;
}

__attribute__((used)) static inline bool tcheck_doomed(void)
{
	return tcheck() & 8;
}

__attribute__((used)) static inline bool tcheck_active(void)
{
	return tcheck() & 4;
}

__attribute__((used)) static inline bool tcheck_suspended(void)
{
	return tcheck() & 2;
}

__attribute__((used)) static inline bool tcheck_transactional(void)
{
	return tcheck() & 6;
}

void signal_segv(int signum)
{
	/* This should never actually run since stack is foobar */
	exit(1);
}

int tm_signal_stack()
{
	int pid;

	SKIP_IF(!have_htm());

	pid = fork();
	if (pid < 0)
		exit(1);

	if (pid) { /* Parent */
		/*
		 * It's likely the whole machine will crash here so if
		 * the child ever exits, we are good.
		 */
		wait(NULL);
		return 0;
	}

	/*
	 * The flow here is:
	 * 1) register a signal handler (so signal delievery occurs)
	 * 2) make stack pointer (r1) = NULL
	 * 3) start transaction
	 * 4) cause segv
	 */
	if (signal(SIGSEGV, signal_segv) == SIG_ERR)
		exit(1);
	asm volatile("li 1, 0 ;"		/* stack ptr == NULL */
		     "1:"
		     "tbegin.;"
		     "beq 1b ;"			/* retry forever */
		     "tsuspend.;"
		     "ld 2, 0(1) ;"		/* trigger segv" */
		     : : : "memory");

	/* This should never get here due to above segv */
	return 1;
}

int main(void)
{
	return test_harness(tm_signal_stack, "tm_signal_stack");
}

