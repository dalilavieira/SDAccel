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
typedef  int /*<<< orphan*/  fenv_t ;

/* Variables and functions */
 int FE_TONEAREST ; 

int feclearexcept(int mask)
{
	return 0;
}

int feraiseexcept(int mask)
{
	return 0;
}

int fetestexcept(int mask)
{
	return 0;
}

int fegetround(void)
{
	return FE_TONEAREST;
}

int __fesetround(int r)
{
	return 0;
}

int fegetenv(fenv_t *envp)
{
	return 0;
}

int fesetenv(const fenv_t *envp)
{
	return 0;
}

