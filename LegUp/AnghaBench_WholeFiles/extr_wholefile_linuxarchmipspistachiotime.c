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
 unsigned int gic_get_c0_compare_int () ; 
 int gic_get_c0_fdc_int () ; 
 int gic_get_c0_perfcount_int () ; 

unsigned int get_c0_compare_int(void)
{
	return gic_get_c0_compare_int();
}

int get_c0_perfcount_int(void)
{
	return gic_get_c0_perfcount_int();
}

int get_c0_fdc_int(void)
{
	return gic_get_c0_fdc_int();
}

