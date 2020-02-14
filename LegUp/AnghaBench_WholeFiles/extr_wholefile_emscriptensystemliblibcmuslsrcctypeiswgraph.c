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
typedef  int /*<<< orphan*/  wint_t ;
typedef  int /*<<< orphan*/  locale_t ;

/* Variables and functions */
 scalar_t__ iswprint (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iswspace (int /*<<< orphan*/ ) ; 

int iswgraph(wint_t wc)
{
	/* ISO C defines this function as: */
	return !iswspace(wc) && iswprint(wc);
}

int __iswgraph_l(wint_t c, locale_t l)
{
	return iswgraph(c);
}

