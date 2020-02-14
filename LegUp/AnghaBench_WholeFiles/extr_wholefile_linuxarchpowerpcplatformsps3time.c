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
typedef  int /*<<< orphan*/  u64 ;

/* Variables and functions */

__attribute__((used)) static inline void ps3_smp_cleanup_cpu(int cpu) { }

__attribute__((used)) static inline void ps3_spu_set_platform (void) {}

__attribute__((used)) static inline int ps3_repository_write_highmem_region_count(
	unsigned int region_count) {return 0;}

__attribute__((used)) static inline int ps3_repository_write_highmem_base(unsigned int region_index,
	u64 highmem_base) {return 0;}

__attribute__((used)) static inline int ps3_repository_write_highmem_size(unsigned int region_index,
	u64 highmem_size) {return 0;}

__attribute__((used)) static inline int ps3_repository_write_highmem_info(unsigned int region_index,
	u64 highmem_base, u64 highmem_size) {return 0;}

__attribute__((used)) static inline int ps3_repository_delete_highmem_info(unsigned int region_index)
	{return 0;}

