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
typedef  scalar_t__ wchar_t ;

/* Variables and functions */
 int towlower (scalar_t__ const) ; 

int wcsncasecmp(const wchar_t *l, const wchar_t *r, size_t n)
{
	if (!n--) return 0;
	for (; *l && *r && n && (*l == *r || towlower(*l) == towlower(*r)); l++, r++, n--);
	return towlower(*l) - towlower(*r);
}

