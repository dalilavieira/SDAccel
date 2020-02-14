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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int) ; 
 int /*<<< orphan*/  CONFIG_HARDEN_BRANCH_PREDICTOR ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_v7_check_auxcr_set (int*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  spectre_warned ; 
 int* this_cpu_ptr (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void cpu_v7_spectre_init(void)
{
}

__attribute__((used)) static bool check_spectre_auxcr(bool *warned, u32 bit)
{
	return IS_ENABLED(CONFIG_HARDEN_BRANCH_PREDICTOR) &&
		cpu_v7_check_auxcr_set(warned, bit,
				       "Spectre v2: firmware did not set auxiliary control register IBE bit, system vulnerable\n");
}

void cpu_v7_ca8_ibe(void)
{
	if (check_spectre_auxcr(this_cpu_ptr(&spectre_warned), BIT(6)))
		cpu_v7_spectre_init();
}

void cpu_v7_ca15_ibe(void)
{
	if (check_spectre_auxcr(this_cpu_ptr(&spectre_warned), BIT(0)))
		cpu_v7_spectre_init();
}

void cpu_v7_bugs_init(void)
{
	cpu_v7_spectre_init();
}

