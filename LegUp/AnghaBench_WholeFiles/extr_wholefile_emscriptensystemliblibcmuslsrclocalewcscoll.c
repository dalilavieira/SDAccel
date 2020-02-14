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
typedef  int /*<<< orphan*/  locale_t ;

/* Variables and functions */
 int /*<<< orphan*/  CURRENT_LOCALE ; 
 int wcscmp (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

int __wcscoll_l(const wchar_t *l, const wchar_t *r, locale_t locale)
{
	return wcscmp(l, r);
}

int wcscoll(const wchar_t *l, const wchar_t *r)
{
	return __wcscoll_l(l, r, CURRENT_LOCALE);
}

