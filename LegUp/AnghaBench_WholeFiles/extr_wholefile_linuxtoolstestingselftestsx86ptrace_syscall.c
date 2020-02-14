#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct user_regs_struct {scalar_t__ user_syscall_nr; int user_arg0; int user_arg1; int user_arg2; int user_arg3; int user_arg4; int user_arg5; scalar_t__ user_ax; scalar_t__ user_ip; } ;
struct syscall_args32 {unsigned long arg5; int nr; int arg0; int arg1; int arg2; int arg3; int arg4; } ;
struct sigaction {void (* sa_sigaction ) (int,TYPE_1__*,void*) ;int sa_flags; int /*<<< orphan*/  sa_mask; int /*<<< orphan*/  sa_handler; } ;
struct TYPE_7__ {scalar_t__ si_pid; scalar_t__ si_code; } ;
typedef  TYPE_1__ siginfo_t ;
typedef  int /*<<< orphan*/  sa ;
typedef  scalar_t__ pid_t ;

/* Variables and functions */
 scalar_t__ CLD_TRAPPED ; 
 int /*<<< orphan*/  PTRACE_CONT ; 
 int /*<<< orphan*/  PTRACE_GETREGS ; 
 int /*<<< orphan*/  PTRACE_SETREGS ; 
 int /*<<< orphan*/  PTRACE_SYSCALL ; 
 int /*<<< orphan*/  PTRACE_SYSEMU ; 
 int /*<<< orphan*/  PTRACE_TRACEME ; 
 int /*<<< orphan*/  P_PID ; 
 int SA_RESTART ; 
 int SA_SIGINFO ; 
 void* SIGKILL ; 
 int /*<<< orphan*/  SIGSTOP ; 
 void* SIGUSR1 ; 
 int /*<<< orphan*/  SIG_DFL ; 
 scalar_t__ SIG_IGN ; 
 scalar_t__ SYS_getpid ; 
 scalar_t__ SYS_gettid ; 
 scalar_t__ SYS_pause ; 
 int /*<<< orphan*/  SYS_tgkill ; 
 int WEXITED ; 
 scalar_t__ WEXITSTATUS (int) ; 
 int /*<<< orphan*/  WIFEXITED (int) ; 
 int /*<<< orphan*/  WIFSTOPPED (int) ; 
 int WSTOPPED ; 
 int /*<<< orphan*/  _exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  err (int,char*) ; 
 int /*<<< orphan*/  errx (int,char*,...) ; 
 scalar_t__ fork () ; 
 void* getpid () ; 
 int /*<<< orphan*/  kill (scalar_t__,void*) ; 
 int /*<<< orphan*/  memset (struct sigaction*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nerrs ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ ptrace (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,struct user_regs_struct*) ; 
 scalar_t__ sigaction (int,struct sigaction*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sigemptyset (int /*<<< orphan*/ *) ; 
 scalar_t__ syscall (scalar_t__,...) ; 
 scalar_t__ waitid (int /*<<< orphan*/ ,scalar_t__,TYPE_1__*,int) ; 
 scalar_t__ waitpid (scalar_t__,int*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void do_full_int80(struct syscall_args32 *args)
{
#ifdef __x86_64__
	register unsigned long bp asm("bp") = args->arg5;
	asm volatile ("int $0x80"
		      : "+a" (args->nr),
			"+b" (args->arg0), "+c" (args->arg1), "+d" (args->arg2),
			"+S" (args->arg3), "+D" (args->arg4), "+r" (bp)
			: : "r8", "r9", "r10", "r11");
	args->arg5 = bp;
#else
	sys32_helper(args, int80_and_ret);
#endif
}

__attribute__((used)) static siginfo_t wait_trap(pid_t chld)
{
	siginfo_t si;
	if (waitid(P_PID, chld, &si, WEXITED|WSTOPPED) != 0)
		err(1, "waitid");
	if (si.si_pid != chld)
		errx(1, "got unexpected pid in event\n");
	if (si.si_code != CLD_TRAPPED)
		errx(1, "got unexpected event type %d\n", si.si_code);
	return si;
}

__attribute__((used)) static void sethandler(int sig, void (*handler)(int, siginfo_t *, void *),
		       int flags)
{
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | flags;
	sigemptyset(&sa.sa_mask);
	if (sigaction(sig, &sa, 0))
		err(1, "sigaction");
}

__attribute__((used)) static void setsigign(int sig, int flags)
{
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = (void *)SIG_IGN;
	sa.sa_flags = flags;
	sigemptyset(&sa.sa_mask);
	if (sigaction(sig, &sa, 0))
		err(1, "sigaction");
}

__attribute__((used)) static void clearhandler(int sig)
{
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	if (sigaction(sig, &sa, 0))
		err(1, "sigaction");
}

__attribute__((used)) static void empty_handler(int sig, siginfo_t *si, void *ctx_void)
{
}

__attribute__((used)) static void test_sys32_regs(void (*do_syscall)(struct syscall_args32 *))
{
	struct syscall_args32 args = {
		.nr = 224,	/* gettid */
		.arg0 = 10, .arg1 = 11, .arg2 = 12,
		.arg3 = 13, .arg4 = 14, .arg5 = 15,
	};

	do_syscall(&args);

	if (args.nr != getpid() ||
	    args.arg0 != 10 || args.arg1 != 11 || args.arg2 != 12 ||
	    args.arg3 != 13 || args.arg4 != 14 || args.arg5 != 15) {
		printf("[FAIL]\tgetpid() failed to preserve regs\n");
		nerrs++;
	} else {
		printf("[OK]\tgetpid() preserves regs\n");
	}

	sethandler(SIGUSR1, empty_handler, 0);

	args.nr = 37;	/* kill */
	args.arg0 = getpid();
	args.arg1 = SIGUSR1;
	do_syscall(&args);
	if (args.nr != 0 ||
	    args.arg0 != getpid() || args.arg1 != SIGUSR1 || args.arg2 != 12 ||
	    args.arg3 != 13 || args.arg4 != 14 || args.arg5 != 15) {
		printf("[FAIL]\tkill(getpid(), SIGUSR1) failed to preserve regs\n");
		nerrs++;
	} else {
		printf("[OK]\tkill(getpid(), SIGUSR1) preserves regs\n");
	}
	clearhandler(SIGUSR1);
}

__attribute__((used)) static void test_ptrace_syscall_restart(void)
{
	printf("[RUN]\tptrace-induced syscall restart\n");
	pid_t chld = fork();
	if (chld < 0)
		err(1, "fork");

	if (chld == 0) {
		if (ptrace(PTRACE_TRACEME, 0, 0, 0) != 0)
			err(1, "PTRACE_TRACEME");

		pid_t pid = getpid(), tid = syscall(SYS_gettid);

		printf("\tChild will make one syscall\n");
		syscall(SYS_tgkill, pid, tid, SIGSTOP);

		syscall(SYS_gettid, 10, 11, 12, 13, 14, 15);
		_exit(0);
	}

	int status;

	/* Wait for SIGSTOP. */
	if (waitpid(chld, &status, 0) != chld || !WIFSTOPPED(status))
		err(1, "waitpid");

	struct user_regs_struct regs;

	printf("[RUN]\tSYSEMU\n");
	if (ptrace(PTRACE_SYSEMU, chld, 0, 0) != 0)
		err(1, "PTRACE_SYSEMU");
	wait_trap(chld);

	if (ptrace(PTRACE_GETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_GETREGS");

	if (regs.user_syscall_nr != SYS_gettid ||
	    regs.user_arg0 != 10 || regs.user_arg1 != 11 ||
	    regs.user_arg2 != 12 || regs.user_arg3 != 13 ||
	    regs.user_arg4 != 14 || regs.user_arg5 != 15) {
		printf("[FAIL]\tInitial args are wrong (nr=%lu, args=%lu %lu %lu %lu %lu %lu)\n", (unsigned long)regs.user_syscall_nr, (unsigned long)regs.user_arg0, (unsigned long)regs.user_arg1, (unsigned long)regs.user_arg2, (unsigned long)regs.user_arg3, (unsigned long)regs.user_arg4, (unsigned long)regs.user_arg5);
		nerrs++;
	} else {
		printf("[OK]\tInitial nr and args are correct\n");
	}

	printf("[RUN]\tRestart the syscall (ip = 0x%lx)\n",
	       (unsigned long)regs.user_ip);

	/*
	 * This does exactly what it appears to do if syscall is int80 or
	 * SYSCALL64.  For SYSCALL32 or SYSENTER, though, this is highly
	 * magical.  It needs to work so that ptrace and syscall restart
	 * work as expected.
	 */
	regs.user_ax = regs.user_syscall_nr;
	regs.user_ip -= 2;
	if (ptrace(PTRACE_SETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_SETREGS");

	if (ptrace(PTRACE_SYSEMU, chld, 0, 0) != 0)
		err(1, "PTRACE_SYSEMU");
	wait_trap(chld);

	if (ptrace(PTRACE_GETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_GETREGS");

	if (regs.user_syscall_nr != SYS_gettid ||
	    regs.user_arg0 != 10 || regs.user_arg1 != 11 ||
	    regs.user_arg2 != 12 || regs.user_arg3 != 13 ||
	    regs.user_arg4 != 14 || regs.user_arg5 != 15) {
		printf("[FAIL]\tRestart nr or args are wrong (nr=%lu, args=%lu %lu %lu %lu %lu %lu)\n", (unsigned long)regs.user_syscall_nr, (unsigned long)regs.user_arg0, (unsigned long)regs.user_arg1, (unsigned long)regs.user_arg2, (unsigned long)regs.user_arg3, (unsigned long)regs.user_arg4, (unsigned long)regs.user_arg5);
		nerrs++;
	} else {
		printf("[OK]\tRestarted nr and args are correct\n");
	}

	printf("[RUN]\tChange nr and args and restart the syscall (ip = 0x%lx)\n",
	       (unsigned long)regs.user_ip);

	regs.user_ax = SYS_getpid;
	regs.user_arg0 = 20;
	regs.user_arg1 = 21;
	regs.user_arg2 = 22;
	regs.user_arg3 = 23;
	regs.user_arg4 = 24;
	regs.user_arg5 = 25;
	regs.user_ip -= 2;

	if (ptrace(PTRACE_SETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_SETREGS");

	if (ptrace(PTRACE_SYSEMU, chld, 0, 0) != 0)
		err(1, "PTRACE_SYSEMU");
	wait_trap(chld);

	if (ptrace(PTRACE_GETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_GETREGS");

	if (regs.user_syscall_nr != SYS_getpid ||
	    regs.user_arg0 != 20 || regs.user_arg1 != 21 || regs.user_arg2 != 22 ||
	    regs.user_arg3 != 23 || regs.user_arg4 != 24 || regs.user_arg5 != 25) {
		printf("[FAIL]\tRestart nr or args are wrong (nr=%lu, args=%lu %lu %lu %lu %lu %lu)\n", (unsigned long)regs.user_syscall_nr, (unsigned long)regs.user_arg0, (unsigned long)regs.user_arg1, (unsigned long)regs.user_arg2, (unsigned long)regs.user_arg3, (unsigned long)regs.user_arg4, (unsigned long)regs.user_arg5);
		nerrs++;
	} else {
		printf("[OK]\tReplacement nr and args are correct\n");
	}

	if (ptrace(PTRACE_CONT, chld, 0, 0) != 0)
		err(1, "PTRACE_CONT");
	if (waitpid(chld, &status, 0) != chld)
		err(1, "waitpid");
	if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
		printf("[FAIL]\tChild failed\n");
		nerrs++;
	} else {
		printf("[OK]\tChild exited cleanly\n");
	}
}

__attribute__((used)) static void test_restart_under_ptrace(void)
{
	printf("[RUN]\tkernel syscall restart under ptrace\n");
	pid_t chld = fork();
	if (chld < 0)
		err(1, "fork");

	if (chld == 0) {
		if (ptrace(PTRACE_TRACEME, 0, 0, 0) != 0)
			err(1, "PTRACE_TRACEME");

		pid_t pid = getpid(), tid = syscall(SYS_gettid);

		printf("\tChild will take a nap until signaled\n");
		setsigign(SIGUSR1, SA_RESTART);
		syscall(SYS_tgkill, pid, tid, SIGSTOP);

		syscall(SYS_pause, 0, 0, 0, 0, 0, 0);
		_exit(0);
	}

	int status;

	/* Wait for SIGSTOP. */
	if (waitpid(chld, &status, 0) != chld || !WIFSTOPPED(status))
		err(1, "waitpid");

	struct user_regs_struct regs;

	printf("[RUN]\tSYSCALL\n");
	if (ptrace(PTRACE_SYSCALL, chld, 0, 0) != 0)
		err(1, "PTRACE_SYSCALL");
	wait_trap(chld);

	/* We should be stopped at pause(2) entry. */

	if (ptrace(PTRACE_GETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_GETREGS");

	if (regs.user_syscall_nr != SYS_pause ||
	    regs.user_arg0 != 0 || regs.user_arg1 != 0 ||
	    regs.user_arg2 != 0 || regs.user_arg3 != 0 ||
	    regs.user_arg4 != 0 || regs.user_arg5 != 0) {
		printf("[FAIL]\tInitial args are wrong (nr=%lu, args=%lu %lu %lu %lu %lu %lu)\n", (unsigned long)regs.user_syscall_nr, (unsigned long)regs.user_arg0, (unsigned long)regs.user_arg1, (unsigned long)regs.user_arg2, (unsigned long)regs.user_arg3, (unsigned long)regs.user_arg4, (unsigned long)regs.user_arg5);
		nerrs++;
	} else {
		printf("[OK]\tInitial nr and args are correct\n");
	}

	/* Interrupt it. */
	kill(chld, SIGUSR1);

	/* Advance.  We should be stopped at exit. */
	printf("[RUN]\tSYSCALL\n");
	if (ptrace(PTRACE_SYSCALL, chld, 0, 0) != 0)
		err(1, "PTRACE_SYSCALL");
	wait_trap(chld);

	if (ptrace(PTRACE_GETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_GETREGS");

	if (regs.user_syscall_nr != SYS_pause ||
	    regs.user_arg0 != 0 || regs.user_arg1 != 0 ||
	    regs.user_arg2 != 0 || regs.user_arg3 != 0 ||
	    regs.user_arg4 != 0 || regs.user_arg5 != 0) {
		printf("[FAIL]\tArgs after SIGUSR1 are wrong (nr=%lu, args=%lu %lu %lu %lu %lu %lu)\n", (unsigned long)regs.user_syscall_nr, (unsigned long)regs.user_arg0, (unsigned long)regs.user_arg1, (unsigned long)regs.user_arg2, (unsigned long)regs.user_arg3, (unsigned long)regs.user_arg4, (unsigned long)regs.user_arg5);
		nerrs++;
	} else {
		printf("[OK]\tArgs after SIGUSR1 are correct (ax = %ld)\n",
		       (long)regs.user_ax);
	}

	/* Poke the regs back in.  This must not break anything. */
	if (ptrace(PTRACE_SETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_SETREGS");

	/* Catch the (ignored) SIGUSR1. */
	if (ptrace(PTRACE_CONT, chld, 0, 0) != 0)
		err(1, "PTRACE_CONT");
	if (waitpid(chld, &status, 0) != chld)
		err(1, "waitpid");
	if (!WIFSTOPPED(status)) {
		printf("[FAIL]\tChild was stopped for SIGUSR1 (status = 0x%x)\n", status);
		nerrs++;
	} else {
		printf("[OK]\tChild got SIGUSR1\n");
	}

	/* The next event should be pause(2) again. */
	printf("[RUN]\tStep again\n");
	if (ptrace(PTRACE_SYSCALL, chld, 0, 0) != 0)
		err(1, "PTRACE_SYSCALL");
	wait_trap(chld);

	/* We should be stopped at pause(2) entry. */

	if (ptrace(PTRACE_GETREGS, chld, 0, &regs) != 0)
		err(1, "PTRACE_GETREGS");

	if (regs.user_syscall_nr != SYS_pause ||
	    regs.user_arg0 != 0 || regs.user_arg1 != 0 ||
	    regs.user_arg2 != 0 || regs.user_arg3 != 0 ||
	    regs.user_arg4 != 0 || regs.user_arg5 != 0) {
		printf("[FAIL]\tpause did not restart (nr=%lu, args=%lu %lu %lu %lu %lu %lu)\n", (unsigned long)regs.user_syscall_nr, (unsigned long)regs.user_arg0, (unsigned long)regs.user_arg1, (unsigned long)regs.user_arg2, (unsigned long)regs.user_arg3, (unsigned long)regs.user_arg4, (unsigned long)regs.user_arg5);
		nerrs++;
	} else {
		printf("[OK]\tpause(2) restarted correctly\n");
	}

	/* Kill it. */
	kill(chld, SIGKILL);
	if (waitpid(chld, &status, 0) != chld)
		err(1, "waitpid");
}

int main()
{
	printf("[RUN]\tCheck int80 return regs\n");
	test_sys32_regs(do_full_int80);

#if defined(__i386__) && (!defined(__GLIBC__) || __GLIBC__ > 2 || __GLIBC_MINOR__ >= 16)
	vsyscall32 = (void *)getauxval(AT_SYSINFO);
	printf("[RUN]\tCheck AT_SYSINFO return regs\n");
	test_sys32_regs(do_full_vsyscall32);
#endif

	test_ptrace_syscall_restart();

	test_restart_under_ptrace();

	return 0;
}

