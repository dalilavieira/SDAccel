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
struct TYPE_4__ {TYPE_2__* uc_regs; } ;
struct TYPE_6__ {TYPE_1__ uc_mcontext; } ;
typedef  TYPE_3__ ucontext_t ;
struct sigaction {void (* sa_sigaction ) (int,int /*<<< orphan*/ *,void*) ;int /*<<< orphan*/  sa_flags; } ;
typedef  int /*<<< orphan*/  signal_action ;
typedef  int /*<<< orphan*/  siginfo_t ;
struct TYPE_5__ {scalar_t__* gregs; } ;

/* Variables and functions */
 int /*<<< orphan*/  PPC_FEATURE2_ARCH_3_00 ; 
 size_t PT_NIP ; 
 int /*<<< orphan*/  SA_SIGINFO ; 
 int /*<<< orphan*/  SIGBUS ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  _exit (int) ; 
 scalar_t__ cacheline_buf ; 
 int /*<<< orphan*/  copy_first (scalar_t__) ; 
 unsigned int expected_instruction ; 
 int /*<<< orphan*/  have_hwcap2 (int /*<<< orphan*/ ) ; 
 unsigned int instruction_mask ; 
 int /*<<< orphan*/  memset (struct sigaction*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ *) ; 
 int test_harness (int (*) (),char*) ; 

void signal_action_handler(int signal_num, siginfo_t *info, void *ptr)
{
	ucontext_t *ctx = ptr;
#ifdef __powerpc64__
	unsigned int *pc = (unsigned int *)ctx->uc_mcontext.gp_regs[PT_NIP];
#else
	unsigned int *pc = (unsigned int *)ctx->uc_mcontext.uc_regs->gregs[PT_NIP];
#endif

	/*
	 * Check that the signal was on the correct instruction, using a
	 * mask because the compiler assigns the register at RB.
	 */
	if ((*pc & instruction_mask) == expected_instruction)
		_exit(0); /* We hit the right instruction */

	_exit(1);
}

void setup_signal_handler(void)
{
	struct sigaction signal_action;

	memset(&signal_action, 0, sizeof(signal_action));
	signal_action.sa_sigaction = signal_action_handler;
	signal_action.sa_flags = SA_SIGINFO;
	sigaction(SIGBUS, &signal_action, NULL);
}

int test_copy_first_unaligned(void)
{
	/* Only run this test on a P9 or later */
	SKIP_IF(!have_hwcap2(PPC_FEATURE2_ARCH_3_00));

	/* Register our signal handler with SIGBUS */
	setup_signal_handler();

	/* +1 makes buf unaligned */
	copy_first(cacheline_buf+1);

	/* We should not get here */
	return 1;
}

int main(int argc, char *argv[])
{
	return test_harness(test_copy_first_unaligned, "test_copy_first_unaligned");
}

