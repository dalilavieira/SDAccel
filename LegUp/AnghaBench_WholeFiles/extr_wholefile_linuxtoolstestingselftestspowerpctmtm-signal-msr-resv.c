#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* uc_regs; } ;
struct TYPE_6__ {TYPE_2__ uc_mcontext; struct TYPE_6__* uc_link; } ;
typedef  TYPE_3__ ucontext_t ;
struct sigaction {void (* sa_sigaction ) (int,int /*<<< orphan*/ *,void*) ;int /*<<< orphan*/  sa_flags; int /*<<< orphan*/  sa_mask; } ;
typedef  int /*<<< orphan*/  siginfo_t ;
struct TYPE_4__ {unsigned long long* gregs; } ;

/* Variables and functions */
 size_t PT_MSR ; 
 int /*<<< orphan*/  SA_SIGINFO ; 
 int SIGSEGV ; 
 int /*<<< orphan*/  SIGUSR1 ; 
 scalar_t__ SIG_ERR ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int TM_CAUSE_FAC_UNAV ; 
 int TM_CAUSE_PERSISTENT ; 
 int TM_CAUSE_SYSCALL ; 
 int __builtin_get_texasru () ; 
 int /*<<< orphan*/  _exit (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  raise (int /*<<< orphan*/ ) ; 
 int segv_expected ; 
 scalar_t__ sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sigemptyset (int /*<<< orphan*/ *) ; 
 scalar_t__ signal (int,void (*) (int)) ; 
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

void signal_segv(int signum)
{
	if (segv_expected && (signum == SIGSEGV))
		_exit(0);
	_exit(1);
}

void signal_usr1(int signum, siginfo_t *info, void *uc)
{
	ucontext_t *ucp = uc;

	/* Link tm checkpointed context to normal context */
	ucp->uc_link = ucp;
	/* Set all TM bits so that the context is now invalid */
#ifdef __powerpc64__
	ucp->uc_mcontext.gp_regs[PT_MSR] |= (7ULL << 32);
#else
	ucp->uc_mcontext.uc_regs->gregs[PT_MSR] |= (7ULL);
#endif
	/* Should segv on return becuase of invalid context */
	segv_expected = 1;
}

int tm_signal_msr_resv()
{
	struct sigaction act;

	SKIP_IF(!have_htm());

	act.sa_sigaction = signal_usr1;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) < 0) {
		perror("sigaction sigusr1");
		exit(1);
	}
	if (signal(SIGSEGV, signal_segv) == SIG_ERR)
		exit(1);

	raise(SIGUSR1);

	/* We shouldn't get here as we exit in the segv handler */
	return 1;
}

int main(void)
{
	return test_harness(tm_signal_msr_resv, "tm_signal_msr_resv");
}

