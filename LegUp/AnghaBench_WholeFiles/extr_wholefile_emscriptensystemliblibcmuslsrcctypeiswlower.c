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
typedef  scalar_t__ wint_t ;
typedef  int /*<<< orphan*/  locale_t ;

/* Variables and functions */
 scalar_t__ towupper (scalar_t__) ; 

int iswlower(wint_t wc)
{
	return towupper(wc) != wc;
}

int __iswlower_l(wint_t c, locale_t l)
{
	return iswlower(c);
}

