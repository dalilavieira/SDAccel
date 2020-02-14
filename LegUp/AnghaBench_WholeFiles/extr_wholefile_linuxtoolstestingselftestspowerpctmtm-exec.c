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
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int TM_CAUSE_FAC_UNAV ; 
 int TM_CAUSE_PERSISTENT ; 
 int TM_CAUSE_SYSCALL ; 
 int __builtin_get_texasru () ; 
 int /*<<< orphan*/  execl (char*,char*,char*,int /*<<< orphan*/ *) ; 
 char* path ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int test_harness (int (*) (),char*) ; 

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

__attribute__((used)) static int test_exec(void)
{
	SKIP_IF(!have_htm());

	asm __volatile__(
		"tbegin.;"
		"blt    1f; "
		"tsuspend.;"
		"1: ;"
		: : : "memory");

	execl(path, "tm-exec", "--child", NULL);

	/* Shouldn't get here */
	perror("execl() failed");
	return 1;
}

__attribute__((used)) static int after_exec(void)
{
	asm __volatile__(
		"tbegin.;"
		"blt    1f;"
		"tsuspend.;"
		"1: ;"
		: : : "memory");

	FAIL_IF(failure_is_nesting());
	return 0;
}

int main(int argc, char *argv[])
{
	path = argv[0];

	if (argc > 1 && strcmp(argv[1], "--child") == 0)
		return after_exec();

	return test_harness(test_exec, "tm_exec");
}

