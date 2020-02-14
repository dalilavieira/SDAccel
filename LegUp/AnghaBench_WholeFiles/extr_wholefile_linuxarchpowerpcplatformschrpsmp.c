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
 scalar_t__ KERNELBASE ; 
 int /*<<< orphan*/  mpic_setup_this_cpu () ; 

__attribute__((used)) static int smp_chrp_kick_cpu(int nr)
{
	*(unsigned long *)KERNELBASE = nr;
	asm volatile("dcbf 0,%0"::"r"(KERNELBASE):"memory");

	return 0;
}

__attribute__((used)) static void smp_chrp_setup_cpu(int cpu_nr)
{
	mpic_setup_this_cpu();
}

