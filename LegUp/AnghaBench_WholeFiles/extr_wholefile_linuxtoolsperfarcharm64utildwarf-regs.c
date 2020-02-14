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
struct pt_regs_dwarfnum {char const* name; unsigned int dwarfnum; } ;

/* Variables and functions */
 int DWARFNUM2OFFSET (unsigned int) ; 
 int EINVAL ; 
 struct pt_regs_dwarfnum* regdwarfnum_table ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 

const char *get_arch_regstr(unsigned int n)
{
	const struct pt_regs_dwarfnum *roff;
	for (roff = regdwarfnum_table; roff->name != NULL; roff++)
		if (roff->dwarfnum == n)
			return roff->name;
	return NULL;
}

int regs_query_register_offset(const char *name)
{
	const struct pt_regs_dwarfnum *roff;

	for (roff = regdwarfnum_table; roff->name != NULL; roff++)
		if (!strcmp(roff->name, name))
			return DWARFNUM2OFFSET(roff->dwarfnum);
	return -EINVAL;
}

