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
 int EINTR ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int mtdtest_relax(void)
{
	cond_resched();
	if (signal_pending(current)) {
		pr_info("aborting test due to pending signal!\n");
		return -EINTR;
	}

	return 0;
}

__attribute__((used)) static int nand_ecc_test_run(const size_t size)
{
	return 0;
}

