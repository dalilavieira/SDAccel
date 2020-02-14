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
 unsigned int ARRAY_SIZE (char const**) ; 
 char const** xen_hypercall_names ; 

__attribute__((used)) static const char *xen_hypercall_name(unsigned op)
{
	if (op < ARRAY_SIZE(xen_hypercall_names) && xen_hypercall_names[op] != NULL)
		return xen_hypercall_names[op];

	return "";
}

