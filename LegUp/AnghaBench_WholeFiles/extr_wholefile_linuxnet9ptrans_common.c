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
struct page {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  put_page (struct page*) ; 

void p9_release_pages(struct page **pages, int nr_pages)
{
	int i;

	for (i = 0; i < nr_pages; i++)
		if (pages[i])
			put_page(pages[i]);
}

