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
 unsigned int ARRAY_SIZE (char const**) ; 
 int EINVAL ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  gprs ; 
 int offsetof (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char const** s390_dwarf_regs ; 
 scalar_t__ strncmp (char const*,char*,int) ; 
 unsigned long strtoul (char const*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  user_pt_regs ; 

const char *get_arch_regstr(unsigned int n)
{
	return (n >= ARRAY_SIZE(s390_dwarf_regs)) ? NULL : s390_dwarf_regs[n];
}

int regs_query_register_offset(const char *name)
{
	unsigned long gpr;

	if (!name || strncmp(name, "%r", 2))
		return -EINVAL;

	errno = 0;
	gpr = strtoul(name + 2, NULL, 10);
	if (errno || gpr >= 16)
		return -EINVAL;

	return offsetof(user_pt_regs, gprs) + 8 * gpr;
}

