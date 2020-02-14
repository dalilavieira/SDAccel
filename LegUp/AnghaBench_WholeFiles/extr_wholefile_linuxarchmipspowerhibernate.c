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
 int /*<<< orphan*/  local_flush_tlb_all () ; 
 int restore_image () ; 

int swsusp_arch_resume(void)
{
	/* Avoid TLB mismatch during and after kernel resume */
	local_flush_tlb_all();
	return restore_image();
}

