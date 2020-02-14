#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int _a_detach; } ;
typedef  TYPE_1__ pthread_attr_t ;

/* Variables and functions */
 int EINVAL ; 

int pthread_attr_setdetachstate(pthread_attr_t *a, int state)
{
	if (state > 1U) return EINVAL;
	a->_a_detach = state;
	return 0;
}

