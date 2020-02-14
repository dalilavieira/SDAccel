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
 unsigned long PFN_DOWN (int /*<<< orphan*/ ) ; 
 unsigned long PFN_UP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __nosave_begin ; 
 int /*<<< orphan*/  __nosave_end ; 
 int /*<<< orphan*/  __pa (int /*<<< orphan*/ *) ; 
 scalar_t__ cpu_has_dsp ; 
 int /*<<< orphan*/  current ; 
 scalar_t__ is_fpu_owner () ; 
 int /*<<< orphan*/  read_c0_status () ; 
 int /*<<< orphan*/  restore_dsp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  restore_fp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  save_dsp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  save_fp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  saved_status ; 
 int /*<<< orphan*/  write_c0_status (int /*<<< orphan*/ ) ; 

void save_processor_state(void)
{
	saved_status = read_c0_status();

	if (is_fpu_owner())
		save_fp(current);
	if (cpu_has_dsp)
		save_dsp(current);
}

void restore_processor_state(void)
{
	write_c0_status(saved_status);

	if (is_fpu_owner())
		restore_fp(current);
	if (cpu_has_dsp)
		restore_dsp(current);
}

int pfn_is_nosave(unsigned long pfn)
{
	unsigned long nosave_begin_pfn = PFN_DOWN(__pa(&__nosave_begin));
	unsigned long nosave_end_pfn = PFN_UP(__pa(&__nosave_end));

	return	(pfn >= nosave_begin_pfn) && (pfn < nosave_end_pfn);
}

