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
struct sleep_save {int /*<<< orphan*/  reg; int /*<<< orphan*/  val; } ;

/* Variables and functions */
 int /*<<< orphan*/  S3C_PMDBG (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readl_relaxed (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void s3c_pm_do_save(struct sleep_save *ptr, int count)
{
	for (; count > 0; count--, ptr++) {
		ptr->val = readl_relaxed(ptr->reg);
		S3C_PMDBG("saved %p value %08lx\n", ptr->reg, ptr->val);
	}
}

void s3c_pm_do_restore(const struct sleep_save *ptr, int count)
{
	for (; count > 0; count--, ptr++) {
		pr_debug("restore %p (restore %08lx, was %08x)\n",
				ptr->reg, ptr->val, readl_relaxed(ptr->reg));

		writel_relaxed(ptr->val, ptr->reg);
	}
}

void s3c_pm_do_restore_core(const struct sleep_save *ptr, int count)
{
	for (; count > 0; count--, ptr++)
		writel_relaxed(ptr->val, ptr->reg);
}

