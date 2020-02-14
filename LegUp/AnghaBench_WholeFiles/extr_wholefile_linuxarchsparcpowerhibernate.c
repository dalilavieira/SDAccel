#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mm_struct {int /*<<< orphan*/  context; } ;
struct TYPE_2__ {struct mm_struct* active_mm; } ;

/* Variables and functions */
 int /*<<< orphan*/  CTX_HWBITS (int /*<<< orphan*/ ) ; 
 unsigned long PFN_DOWN (unsigned long) ; 
 int /*<<< orphan*/  __nosave_begin ; 
 int /*<<< orphan*/  __nosave_end ; 
 TYPE_1__* current ; 
 int /*<<< orphan*/  save_and_clear_fpu () ; 
 int /*<<< orphan*/  tsb_context_switch_ctx (struct mm_struct*,int /*<<< orphan*/ ) ; 

int pfn_is_nosave(unsigned long pfn)
{
	unsigned long nosave_begin_pfn = PFN_DOWN((unsigned long)&__nosave_begin);
	unsigned long nosave_end_pfn = PFN_DOWN((unsigned long)&__nosave_end);

	return (pfn >= nosave_begin_pfn) && (pfn < nosave_end_pfn);
}

void save_processor_state(void)
{
	save_and_clear_fpu();
}

void restore_processor_state(void)
{
	struct mm_struct *mm = current->active_mm;

	tsb_context_switch_ctx(mm, CTX_HWBITS(mm->context));
}

