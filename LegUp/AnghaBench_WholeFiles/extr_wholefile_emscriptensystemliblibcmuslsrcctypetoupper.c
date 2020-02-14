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
 scalar_t__ islower (int) ; 

int toupper(int c)
{
	if (islower(c)) return c & 0x5f;
	return c;
}

int __toupper_l(int c, locale_t l)
{
	return toupper(c);
}

