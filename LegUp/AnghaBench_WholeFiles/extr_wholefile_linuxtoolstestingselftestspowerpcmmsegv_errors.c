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
struct TYPE_5__ {struct pt_regs* regs; } ;
struct TYPE_6__ {TYPE_1__ uc_mcontext; } ;
typedef  TYPE_2__ ucontext_t ;
struct sigaction {void (* sa_sigaction ) (int,TYPE_3__*,void*) ;int /*<<< orphan*/  sa_flags; } ;
struct pt_regs {int nip; } ;
struct TYPE_7__ {scalar_t__ si_code; } ;
typedef  TYPE_3__ siginfo_t ;

/* Variables and functions */
 int /*<<< orphan*/  FAIL_IF (int) ; 
 int MAP_ANONYMOUS ; 
 char* MAP_FAILED ; 
 int MAP_PRIVATE ; 
 int /*<<< orphan*/  SA_SIGINFO ; 
 scalar_t__ SEGV_ACCERR ; 
 int /*<<< orphan*/  SIGSEGV ; 
 int faulted ; 
 int /*<<< orphan*/  getpagesize () ; 
 int /*<<< orphan*/  mb () ; 
 char* mmap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ si_code ; 
 scalar_t__ sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ *) ; 
 int test_harness (int (*) (),char*) ; 

__attribute__((used)) static void segv_handler(int n, siginfo_t *info, void *ctxt_v)
{
	ucontext_t *ctxt = (ucontext_t *)ctxt_v;
	struct pt_regs *regs = ctxt->uc_mcontext.regs;

	faulted = true;
	si_code = info->si_code;
	regs->nip += 4;
}

int test_segv_errors(void)
{
	struct sigaction act = {
		.sa_sigaction = segv_handler,
		.sa_flags = SA_SIGINFO,
	};
	char c, *p = NULL;

	p = mmap(NULL, getpagesize(), 0, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	FAIL_IF(p == MAP_FAILED);

	FAIL_IF(sigaction(SIGSEGV, &act, NULL) != 0);

	faulted = false;
	si_code = 0;

	/*
	 * We just need a compiler barrier, but mb() works and has the nice
	 * property of being easy to spot in the disassembly.
	 */
	mb();
	c = *p;
	mb();

	FAIL_IF(!faulted);
	FAIL_IF(si_code != SEGV_ACCERR);

	faulted = false;
	si_code = 0;

	mb();
	*p = c;
	mb();

	FAIL_IF(!faulted);
	FAIL_IF(si_code != SEGV_ACCERR);

	return 0;
}

int main(void)
{
	return test_harness(test_segv_errors, "segv_errors");
}

