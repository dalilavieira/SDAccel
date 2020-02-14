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
typedef  int /*<<< orphan*/  mbstate_t ;

/* Variables and functions */
 size_t mbrtowc (int /*<<< orphan*/ ,char const*,size_t,int /*<<< orphan*/ *) ; 

size_t mbrlen(const char *restrict s, size_t n, mbstate_t *restrict st)
{
	static unsigned internal;
	return mbrtowc(0, s, n, st ? st : (mbstate_t *)&internal);
}

