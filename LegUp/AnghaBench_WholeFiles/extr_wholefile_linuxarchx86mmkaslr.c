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
struct kaslr_memory_region {unsigned long size_tb; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_KASAN ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 unsigned long TB_SHIFT ; 
 void* alloc_low_pages (int) ; 
 scalar_t__ kaslr_enabled () ; 

__attribute__((used)) static inline void *alloc_low_page(void)
{
	return alloc_low_pages(1);
}

__attribute__((used)) static inline unsigned long get_padding(struct kaslr_memory_region *region)
{
	return (region->size_tb << TB_SHIFT);
}

__attribute__((used)) static inline bool kaslr_memory_enabled(void)
{
	return kaslr_enabled() && !IS_ENABLED(CONFIG_KASAN);
}

