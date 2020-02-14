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

/* Variables and functions */
 void* alloc_low_pages (int) ; 
 scalar_t__ sev_enabled ; 
 scalar_t__ sme_me_mask ; 

__attribute__((used)) static inline void *alloc_low_page(void)
{
	return alloc_low_pages(1);
}

bool sev_active(void)
{
	return sme_me_mask && sev_enabled;
}

