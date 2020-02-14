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
 int /*<<< orphan*/  trace_page_ref_freeze (struct page*,int,int) ; 
 int /*<<< orphan*/  trace_page_ref_mod (struct page*,int) ; 
 int /*<<< orphan*/  trace_page_ref_mod_and_return (struct page*,int,int) ; 
 int /*<<< orphan*/  trace_page_ref_mod_and_test (struct page*,int,int) ; 
 int /*<<< orphan*/  trace_page_ref_mod_unless (struct page*,int,int) ; 
 int /*<<< orphan*/  trace_page_ref_set (struct page*,int) ; 
 int /*<<< orphan*/  trace_page_ref_unfreeze (struct page*,int) ; 

void __page_ref_set(struct page *page, int v)
{
	trace_page_ref_set(page, v);
}

void __page_ref_mod(struct page *page, int v)
{
	trace_page_ref_mod(page, v);
}

void __page_ref_mod_and_test(struct page *page, int v, int ret)
{
	trace_page_ref_mod_and_test(page, v, ret);
}

void __page_ref_mod_and_return(struct page *page, int v, int ret)
{
	trace_page_ref_mod_and_return(page, v, ret);
}

void __page_ref_mod_unless(struct page *page, int v, int u)
{
	trace_page_ref_mod_unless(page, v, u);
}

void __page_ref_freeze(struct page *page, int v, int ret)
{
	trace_page_ref_freeze(page, v, ret);
}

void __page_ref_unfreeze(struct page *page, int v)
{
	trace_page_ref_unfreeze(page, v);
}

