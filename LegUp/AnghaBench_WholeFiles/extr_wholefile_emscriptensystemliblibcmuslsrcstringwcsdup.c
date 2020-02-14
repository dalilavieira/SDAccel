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
 int /*<<< orphan*/ * malloc (size_t) ; 
 size_t wcslen (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * wmemcpy (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,size_t) ; 

wchar_t *wcsdup(const wchar_t *s)
{
	size_t l = wcslen(s);
	wchar_t *d = malloc((l+1)*sizeof(wchar_t));
	if (!d) return NULL;
	return wmemcpy(d, s, l+1);
}

