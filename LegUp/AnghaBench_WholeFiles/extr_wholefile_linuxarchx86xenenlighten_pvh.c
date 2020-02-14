#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_2__ {int /*<<< orphan*/  rsdp_paddr; } ;

/* Variables and functions */
 TYPE_1__ pvh_start_info ; 

__attribute__((used)) static u64 pvh_get_root_pointer(void)
{
	return pvh_start_info.rsdp_paddr;
}

