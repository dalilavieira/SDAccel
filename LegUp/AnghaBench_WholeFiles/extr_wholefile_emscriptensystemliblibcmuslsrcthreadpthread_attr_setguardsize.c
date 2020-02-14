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
struct TYPE_3__ {scalar_t__ _a_guardsize; } ;
typedef  TYPE_1__ pthread_attr_t ;

/* Variables and functions */
 scalar_t__ DEFAULT_GUARD_SIZE ; 
 int EINVAL ; 
 int SIZE_MAX ; 

int pthread_attr_setguardsize(pthread_attr_t *a, size_t size)
{
	if (size > SIZE_MAX/8) return EINVAL;
	a->_a_guardsize = size - DEFAULT_GUARD_SIZE;
	return 0;
}

