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
 int /*<<< orphan*/  FE_INEXACT ; 
 long double LLONG_MAX ; 
 long double LLONG_MIN ; 
 int /*<<< orphan*/  feclearexcept (int /*<<< orphan*/ ) ; 
 int fetestexcept (int /*<<< orphan*/ ) ; 
 long double rintl (long double) ; 

long long llrintl(long double x)
{
	#pragma STDC FENV_ACCESS ON
	int e;

	e = fetestexcept(FE_INEXACT);
	x = rintl(x);
	if (!e && (x > LLONG_MAX || x < LLONG_MIN))
		feclearexcept(FE_INEXACT);
	/* conversion */
	return x;
}

