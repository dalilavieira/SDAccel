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
 int /*<<< orphan*/  iommu_restore () ; 
 int /*<<< orphan*/  iommu_save () ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  touch_softlockup_watchdog () ; 

void do_after_copyback(void)
{
	iommu_restore();
	touch_softlockup_watchdog();
	mb();
}

void _iommu_save(void)
{
	iommu_save();
}

