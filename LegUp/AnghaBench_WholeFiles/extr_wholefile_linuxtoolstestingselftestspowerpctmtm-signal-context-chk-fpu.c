#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__* fp_regs; } ;
struct TYPE_4__ {TYPE_1__ uc_mcontext; struct TYPE_4__* uc_link; } ;
typedef  TYPE_2__ ucontext_t ;
struct sigaction {void (* sa_sigaction ) (int,int /*<<< orphan*/ *,void*) ;int /*<<< orphan*/  sa_flags; int /*<<< orphan*/  sa_mask; } ;
typedef  int /*<<< orphan*/  siginfo_t ;
typedef  long pid_t ;

/* Variables and functions */
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int MAX_ATTEMPT ; 
 int NV_FPU_REGS ; 
 int /*<<< orphan*/  SA_SIGINFO ; 
 int /*<<< orphan*/  SIGUSR1 ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int TM_CAUSE_FAC_UNAV ; 
 int TM_CAUSE_PERSISTENT ; 
 int TM_CAUSE_SYSCALL ; 
 int __builtin_get_texasru () ; 
 int /*<<< orphan*/  exit (int) ; 
 int fail ; 
 scalar_t__* fps ; 
 long getpid () ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sigemptyset (int /*<<< orphan*/ *) ; 
 int test_harness (int (*) (),char*) ; 
 long tm_signal_self_context_load (long,int /*<<< orphan*/ *,scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static void signal_usr1(int signum, siginfo_t *info, void *uc)
{
	int i;
	ucontext_t *ucp = uc;
	ucontext_t *tm_ucp = ucp->uc_link;

	for (i = 0; i < NV_FPU_REGS && !fail; i++) {
		fail = (ucp->uc_mcontext.fp_regs[i + 14] != fps[i]);
		fail |= (tm_ucp->uc_mcontext.fp_regs[i + 14] != fps[i + NV_FPU_REGS]);
		if (fail)
			printf("Failed on %d FP %g or %g\n", i, ucp->uc_mcontext.fp_regs[i + 14], tm_ucp->uc_mcontext.fp_regs[i + 14]);
	}
}

__attribute__((used)) static int tm_signal_context_chk_fpu()
{
	struct sigaction act;
	int i;
	long rc;
	pid_t pid = getpid();

	SKIP_IF(!have_htm());

	act.sa_sigaction = signal_usr1;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) < 0) {
		perror("sigaction sigusr1");
		exit(1);
	}

	i = 0;
	while (i < MAX_ATTEMPT && !fail) {
		rc = tm_signal_self_context_load(pid, NULL, fps, NULL, NULL);
		FAIL_IF(rc != pid);
		i++;
	}

	return fail;
}

int main(void)
{
	return test_harness(tm_signal_context_chk_fpu, "tm_signal_context_chk_fpu");
}

