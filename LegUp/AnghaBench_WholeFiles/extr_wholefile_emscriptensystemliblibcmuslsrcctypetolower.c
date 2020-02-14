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
typedef  int /*<<< orphan*/  locale_t ;

/* Variables and functions */
 scalar_t__ isupper (int) ; 

int tolower(int c)
{
	if (isupper(c)) return c | 32;
	return c;
}

int __tolower_l(int c, locale_t l)
{
	return tolower(c);
}

