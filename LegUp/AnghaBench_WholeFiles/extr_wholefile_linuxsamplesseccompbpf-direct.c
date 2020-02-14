#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int* gregs; } ;
struct TYPE_6__ {TYPE_1__ uc_mcontext; } ;
typedef  TYPE_2__ ucontext_t ;
struct sock_fprog {unsigned short len; struct sock_filter* filter; } ;
struct sock_filter {int dummy; } ;
struct sigaction {void (* sa_sigaction ) (int,TYPE_3__*,void*) ;int /*<<< orphan*/  sa_flags; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  sigset_t ;
struct TYPE_7__ {scalar_t__ si_code; } ;
typedef  TYPE_3__ siginfo_t ;
typedef  int /*<<< orphan*/  filter ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  act ;

/* Variables and functions */
 scalar_t__ BPF_ABS ; 
 scalar_t__ BPF_JEQ ; 
 scalar_t__ BPF_JMP ; 
 struct sock_filter BPF_JUMP (scalar_t__,int,int,int) ; 
 scalar_t__ BPF_K ; 
 scalar_t__ BPF_LD ; 
 scalar_t__ BPF_RET ; 
 struct sock_filter BPF_STMT (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ BPF_W ; 
 int /*<<< orphan*/  PR_SET_NO_NEW_PRIVS ; 
 int /*<<< orphan*/  PR_SET_SECCOMP ; 
 size_t REG_ARG0 ; 
 size_t REG_ARG1 ; 
 size_t REG_ARG2 ; 
 size_t REG_RESULT ; 
 size_t REG_SYSCALL ; 
 int /*<<< orphan*/  SA_SIGINFO ; 
 int /*<<< orphan*/  SECCOMP_MODE_FILTER ; 
 int /*<<< orphan*/  SECCOMP_RET_ALLOW ; 
 int /*<<< orphan*/  SECCOMP_RET_KILL ; 
 int /*<<< orphan*/  SECCOMP_RET_TRAP ; 
 int /*<<< orphan*/  SIGSYS ; 
 int /*<<< orphan*/  SIG_UNBLOCK ; 
 int STDERR_FILENO ; 
 int STDIN_FILENO ; 
 int STDOUT_FILENO ; 
 scalar_t__ SYS_SECCOMP ; 
 int __NR_exit ; 
 int __NR_exit_group ; 
 int __NR_read ; 
 int __NR_rt_sigreturn ; 
 int __NR_write ; 
 int /*<<< orphan*/  memset (struct sigaction*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  payload (char*) ; 
 int /*<<< orphan*/  perror (char*) ; 
 scalar_t__ prctl (int /*<<< orphan*/ ,int,struct sock_fprog*,...) ; 
 scalar_t__ sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sigaddset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sigemptyset (int /*<<< orphan*/ *) ; 
 scalar_t__ sigprocmask (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int syscall (int,int,char*,...) ; 
 int /*<<< orphan*/  syscall_arg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  syscall_nr ; 
 int write (int,char*,size_t) ; 

__attribute__((used)) static void emulator(int nr, siginfo_t *info, void *void_context)
{
	ucontext_t *ctx = (ucontext_t *)(void_context);
	int syscall;
	char *buf;
	ssize_t bytes;
	size_t len;
	if (info->si_code != SYS_SECCOMP)
		return;
	if (!ctx)
		return;
	syscall = ctx->uc_mcontext.gregs[REG_SYSCALL];
	buf = (char *) ctx->uc_mcontext.gregs[REG_ARG1];
	len = (size_t) ctx->uc_mcontext.gregs[REG_ARG2];

	if (syscall != __NR_write)
		return;
	if (ctx->uc_mcontext.gregs[REG_ARG0] != STDERR_FILENO)
		return;
	/* Redirect stderr messages to stdout. Doesn't handle EINTR, etc */
	ctx->uc_mcontext.gregs[REG_RESULT] = -1;
	if (write(STDOUT_FILENO, "[ERR] ", 6) > 0) {
		bytes = write(STDOUT_FILENO, buf, len);
		ctx->uc_mcontext.gregs[REG_RESULT] = bytes;
	}
	return;
}

__attribute__((used)) static int install_emulator(void)
{
	struct sigaction act;
	sigset_t mask;
	memset(&act, 0, sizeof(act));
	sigemptyset(&mask);
	sigaddset(&mask, SIGSYS);

	act.sa_sigaction = &emulator;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGSYS, &act, NULL) < 0) {
		perror("sigaction");
		return -1;
	}
	if (sigprocmask(SIG_UNBLOCK, &mask, NULL)) {
		perror("sigprocmask");
		return -1;
	}
	return 0;
}

__attribute__((used)) static int install_filter(void)
{
	struct sock_filter filter[] = {
		/* Grab the system call number */
		BPF_STMT(BPF_LD+BPF_W+BPF_ABS, syscall_nr),
		/* Jump table for the allowed syscalls */
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_rt_sigreturn, 0, 1),
		BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
#ifdef __NR_sigreturn
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_sigreturn, 0, 1),
		BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
#endif
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_exit_group, 0, 1),
		BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_exit, 0, 1),
		BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_read, 1, 0),
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, __NR_write, 3, 2),

		/* Check that read is only using stdin. */
		BPF_STMT(BPF_LD+BPF_W+BPF_ABS, syscall_arg(0)),
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, STDIN_FILENO, 4, 0),
		BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_KILL),

		/* Check that write is only using stdout */
		BPF_STMT(BPF_LD+BPF_W+BPF_ABS, syscall_arg(0)),
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, STDOUT_FILENO, 1, 0),
		/* Trap attempts to write to stderr */
		BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, STDERR_FILENO, 1, 2),

		BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW),
		BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_TRAP),
		BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_KILL),
	};
	struct sock_fprog prog = {
		.len = (unsigned short)(sizeof(filter)/sizeof(filter[0])),
		.filter = filter,
	};

	if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
		perror("prctl(NO_NEW_PRIVS)");
		return 1;
	}


	if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog)) {
		perror("prctl");
		return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	char buf[4096];
	ssize_t bytes = 0;
	if (install_emulator())
		return 1;
	if (install_filter())
		return 1;
	syscall(__NR_write, STDOUT_FILENO,
		payload("OHAI! WHAT IS YOUR NAME? "));
	bytes = syscall(__NR_read, STDIN_FILENO, buf, sizeof(buf));
	syscall(__NR_write, STDOUT_FILENO, payload("HELLO, "));
	syscall(__NR_write, STDOUT_FILENO, buf, bytes);
	syscall(__NR_write, STDERR_FILENO,
		payload("Error message going to STDERR\n"));
	return 0;
}

