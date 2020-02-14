#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {uintptr_t MC_PC; } ;
struct TYPE_12__ {unsigned long* __bits; } ;
struct TYPE_11__ {TYPE_1__ uc_mcontext; TYPE_3__ uc_sigmask; } ;
typedef  TYPE_2__ ucontext_t ;
typedef  int /*<<< orphan*/  syscall_arg_t ;
struct sigaction {int sa_flags; void (* sa_sigaction ) (int,int /*<<< orphan*/ *,void*) ;int /*<<< orphan*/  sa_mask; } ;
typedef  TYPE_3__ sigset_t ;
typedef  int /*<<< orphan*/  siginfo_t ;
typedef  TYPE_4__* pthread_t ;
struct TYPE_13__ {scalar_t__ canceldisable; scalar_t__ cancelasync; scalar_t__ cancel; int /*<<< orphan*/  tid; } ;

/* Variables and functions */
 long ECANCELED ; 
 long EINTR ; 
 int /*<<< orphan*/  PTHREAD_CANCELED ; 
 int PTHREAD_CANCEL_DISABLE ; 
 scalar_t__ PTHREAD_CANCEL_ENABLE ; 
 int SA_RESTART ; 
 int SA_SIGINFO ; 
 int SIGCANCEL ; 
 int /*<<< orphan*/  SYS_close ; 
 int /*<<< orphan*/  SYS_tkill ; 
 int _NSIG ; 
 scalar_t__ __cp_begin ; 
 scalar_t__ __cp_cancel ; 
 scalar_t__ __cp_end ; 
 int /*<<< orphan*/  __libc_sigaction (int,struct sigaction*,int /*<<< orphan*/ ) ; 
 TYPE_4__* __pthread_self () ; 
 long __syscall (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,...) ; 
 long __syscall_cp_asm (scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  a_barrier () ; 
 int /*<<< orphan*/  a_store (scalar_t__*,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  pthread_exit (int /*<<< orphan*/ ) ; 
 int pthread_kill (TYPE_4__*,int) ; 
 TYPE_4__* pthread_self () ; 

long __cancel()
{
	pthread_t self = __pthread_self();
	if (self->canceldisable == PTHREAD_CANCEL_ENABLE || self->cancelasync)
		pthread_exit(PTHREAD_CANCELED);
	self->canceldisable = PTHREAD_CANCEL_DISABLE;
	return -ECANCELED;
}

long __syscall_cp_c(syscall_arg_t nr,
                    syscall_arg_t u, syscall_arg_t v, syscall_arg_t w,
                    syscall_arg_t x, syscall_arg_t y, syscall_arg_t z)
{
	pthread_t self;
	long r;
	int st;

	if ((st=(self=__pthread_self())->canceldisable)
	    && (st==PTHREAD_CANCEL_DISABLE || nr==SYS_close))
		return __syscall(nr, u, v, w, x, y, z);

	r = __syscall_cp_asm(&self->cancel, nr, u, v, w, x, y, z);
	if (r==-EINTR && nr!=SYS_close && self->cancel &&
	    self->canceldisable != PTHREAD_CANCEL_DISABLE)
		r = __cancel();
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
	uintptr_t pc = uc->uc_mcontext.MC_PC;

	a_barrier();
	if (!self->cancel || self->canceldisable == PTHREAD_CANCEL_DISABLE) return;

	_sigaddset(&uc->uc_sigmask, SIGCANCEL);

	if (self->cancelasync || pc >= (uintptr_t)__cp_begin && pc < (uintptr_t)__cp_end) {
		uc->uc_mcontext.MC_PC = (uintptr_t)__cp_cancel;
		return;
	}

	__syscall(SYS_tkill, self->tid, SIGCANCEL);
}

void __testcancel()
{
	pthread_t self = __pthread_self();
	if (self->cancel && !self->canceldisable)
		__cancel();
}

__attribute__((used)) static void init_cancellation()
{
	struct sigaction sa = {
		.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = cancel_handler
	};
	memset(&sa.sa_mask, -1, _NSIG/8);
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
	if (t == pthread_self() && !t->cancelasync) return 0;
	return pthread_kill(t, SIGCANCEL);
}

