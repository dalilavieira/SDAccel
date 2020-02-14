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
struct TYPE_2__ {int (* __pfn_to_nid ) (unsigned long) ;int (* distance ) (int,int) ;int /*<<< orphan*/  (* update_cpu_topology ) () ;} ;

/* Variables and functions */
 TYPE_1__* mode ; 
 int /*<<< orphan*/  node_possible_map ; 
 int /*<<< orphan*/  node_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (unsigned long) ; 
 int /*<<< orphan*/  stub2 () ; 
 int stub3 (int,int) ; 

__attribute__((used)) static void plain_setup(void)
{
	node_set(0, node_possible_map);
}

int numa_pfn_to_nid(unsigned long pfn)
{
	return mode->__pfn_to_nid ? mode->__pfn_to_nid(pfn) : 0;
}

void numa_update_cpu_topology(void)
{
	if (mode->update_cpu_topology)
		mode->update_cpu_topology();
}

int __node_distance(int a, int b)
{
	return mode->distance ? mode->distance(a, b) : 0;
}

