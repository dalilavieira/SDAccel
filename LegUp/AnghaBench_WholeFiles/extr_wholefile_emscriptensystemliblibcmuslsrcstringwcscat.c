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
typedef  int /*<<< orphan*/  wchar_t ;

/* Variables and functions */
 int /*<<< orphan*/  wcscpy (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int wcslen (int /*<<< orphan*/ *) ; 

wchar_t *wcscat(wchar_t *restrict dest, const wchar_t *restrict src)
{
	wcscpy(dest + wcslen(dest), src);
	return dest;
}

