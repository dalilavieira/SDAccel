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
typedef  int u32 ;
typedef  int phys_addr_t ;

/* Variables and functions */

__attribute__((used)) static inline int shmobile_suspend_init(void) { return 0; }

__attribute__((used)) static inline void shmobile_smp_apmu_suspend_init(void) { }

__attribute__((used)) static inline u32 phys_to_sbar(phys_addr_t addr)
{
	return (addr >> 8) & 0xfffffc00;
}

