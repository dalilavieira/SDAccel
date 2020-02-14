#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_8__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {unsigned long* __bits; } ;
struct TYPE_11__ {TYPE_2__ uc_sigmask; int /*<<< orphan*/  uc_mcontext; } ;
typedef  TYPE_1__ ucontext_t ;
typedef  int /*<<< orphan*/  syscall_arg_t ;
struct sigaction {int sa_flags; void (* sa_sigaction ) (int,int /*<<< orphan*/ *,void*) ;int /*<<< orphan*/  sa_mask; } ;
typedef  TYPE_2__ sigset_t ;
typedef  int /*<<< orphan*/  siginfo_t ;
typedef  TYPE_3__* pthread_t ;
struct TYPE_14__ {int /*<<< orphan*/  main_thread; } ;
struct TYPE_13__ {int canceldisable; scalar_t__ cancel; int /*<<< orphan*/  tid; int /*<<< orphan*/  pid; scalar_t__ cancelasync; } ;

/* Variables and functions */
 size_t CANCEL_REG_IP ; 
 long EINTR ; 
 int /*<<< orphan*/  PTHREAD_CANCELED ; 
 int SA_RESTART ; 
 int SA_SIGINFO ; 
 int SIGCANCEL ; 
 int /*<<< orphan*/  SIG_SETMASK ; 
 int /*<<< orphan*/  SYS_close ; 
 int /*<<< orphan*/  SYS_tgkill ; 
 int /*<<< orphan*/  __libc_sigaction (int,struct sigaction*,int /*<<< orphan*/ ) ; 
 TYPE_3__* __pthread_self () ; 
 long __syscall (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,...) ; 
 long __syscall_cp_asm (scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  a_store (scalar_t__*,int) ; 
 TYPE_8__ libc ; 
 int /*<<< orphan*/  pthread_exit (int /*<<< orphan*/ ) ; 
 int pthread_kill (TYPE_3__*,int) ; 
 TYPE_3__* pthread_self () ; 
 int /*<<< orphan*/  pthread_sigmask (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sigfillset (int /*<<< orphan*/ *) ; 

void __cancel()
{
	pthread_t self = __pthread_self();
	self->canceldisable = 1;
	self->cancelasync = 0;
	pthread_exit(PTHREAD_CANCELED);
}

long (__syscall_cp)(syscall_arg_t nr,
                    syscall_arg_t u, syscall_arg_t v, syscall_arg_t w,
                    syscall_arg_t x, syscall_arg_t y, syscall_arg_t z)
{
	pthread_t self;
	long r;

	if (!libc.main_thread || (self = __pthread_self())->canceldisable)
		return __syscall(nr, u, v, w, x, y, z);

	r = __syscall_cp_asm(&self->cancel, nr, u, v, w, x, y, z);
	if (r==-EINTR && nr!=SYS_close && self->cancel && !self->canceldisable)
		__cancel();
	return r;
}

__attribute__((used)) static void _sigaddset(sigset_t *set, int sig)
{
	unsigned s = sig-1;
	set->__bits[s/8/sizeof *set->__bits] |= 1UL<<(s&8*sizeof *set->__bits-1);
}

__attribute__((used)) static void cancel_handler(int sig, siginfo_t *si, void *ctx)
{
	pthread_t self = __pthread_self();
	ucontext_t *uc = ctx;
	const char *ip = ((char **)&uc->uc_mcontext)[CANCEL_REG_IP];
	extern const char __cp_begin[1], __cp_end[1];

	if (!self->cancel || self->canceldisable) return;

	_sigaddset(&uc->uc_sigmask, SIGCANCEL);

	if (self->cancelasync || ip >= __cp_begin && ip < __cp_end) {
		self->canceldisable = 1;
		pthread_sigmask(SIG_SETMASK, &uc->uc_sigmask, 0);
		__cancel();
	}

	__syscall(SYS_tgkill, self->pid, self->tid, SIGCANCEL);
}

void __testcancel()
{
	pthread_t self = pthread_self();
	if (self->cancel && !self->canceldisable)
		__cancel();
}

__attribute__((used)) static void init_cancellation()
{
	struct sigaction sa = {
		.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = cancel_handler
	};
	sigfillset(&sa.sa_mask);
	__libc_sigaction(SIGCANCEL, &sa, 0);
}

int pthread_cancel(pthread_t t)
{
	static int init;
	if (!init) {
		init_cancellation();
		init = 1;
	}
	a_store(&t->cancel, 1);
	return pthread_kill(t, SIGCANCEL);
}

