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
struct TYPE_3__ {int /*<<< orphan*/  __attr; } ;
typedef  TYPE_1__ pthread_barrierattr_t ;

/* Variables and functions */
 int /*<<< orphan*/  INT_MIN ; 

int pthread_barrierattr_setpshared(pthread_barrierattr_t *a, int pshared)
{
	a->__attr = pshared ? INT_MIN : 0;
	return 0;
}

