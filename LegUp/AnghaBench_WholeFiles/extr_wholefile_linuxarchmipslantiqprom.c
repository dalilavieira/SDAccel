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
struct TYPE_2__ {char const* sys_type; int type; } ;

/* Variables and functions */
 TYPE_1__ soc_info ; 

const char *get_system_type(void)
{
	return soc_info.sys_type;
}

int ltq_soc_type(void)
{
	return soc_info.type;
}

