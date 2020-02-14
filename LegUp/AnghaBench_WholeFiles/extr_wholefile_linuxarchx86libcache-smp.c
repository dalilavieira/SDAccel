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
 int on_each_cpu (void (*) (void*),int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  smp_call_function_single (int,void (*) (void*),int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  wbinvd () ; 

__attribute__((used)) static void __wbinvd(void *dummy)
{
	wbinvd();
}

void wbinvd_on_cpu(int cpu)
{
	smp_call_function_single(cpu, __wbinvd, NULL, 1);
}

int wbinvd_on_all_cpus(void)
{
	return on_each_cpu(__wbinvd, NULL, 1);
}

