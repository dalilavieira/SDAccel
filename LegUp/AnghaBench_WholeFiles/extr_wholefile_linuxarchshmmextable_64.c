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
struct pt_regs {int /*<<< orphan*/  pc; } ;
struct exception_table_entry {unsigned long insn; int /*<<< orphan*/  fixup; } ;

/* Variables and functions */
 struct exception_table_entry const __copy_user_fixup_ex ; 
 struct exception_table_entry const* bsearch (unsigned long*,struct exception_table_entry const*,size_t const,int,int (*) (void const*,void const*)) ; 
 int /*<<< orphan*/  copy_user_memcpy ; 
 int /*<<< orphan*/  copy_user_memcpy_end ; 
 struct exception_table_entry* search_exception_tables (int /*<<< orphan*/ ) ; 

__attribute__((used)) static const struct exception_table_entry *check_exception_ranges(unsigned long addr)
{
	if ((addr >= (unsigned long)&copy_user_memcpy) &&
	    (addr <= (unsigned long)&copy_user_memcpy_end))
		return &__copy_user_fixup_ex;

	return NULL;
}

__attribute__((used)) static int cmp_ex_search(const void *key, const void *elt)
{
	const struct exception_table_entry *_elt = elt;
	unsigned long _key = *(unsigned long *)key;

	/* avoid overflow */
	if (_key > _elt->insn)
		return 1;
	if (_key < _elt->insn)
		return -1;
	return 0;
}

const struct exception_table_entry *
search_extable(const struct exception_table_entry *base,
		 const size_t num,
		 unsigned long value)
{
	const struct exception_table_entry *mid;

	mid = check_exception_ranges(value);
	if (mid)
		return mid;

	return bsearch(&value, base, num,
		       sizeof(struct exception_table_entry), cmp_ex_search);
}

int fixup_exception(struct pt_regs *regs)
{
	const struct exception_table_entry *fixup;

	fixup = search_exception_tables(regs->pc);
	if (fixup) {
		regs->pc = fixup->fixup;
		return 1;
	}

	return 0;
}

