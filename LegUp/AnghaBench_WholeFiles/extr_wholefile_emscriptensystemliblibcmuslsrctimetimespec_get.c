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
struct timespec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_REALTIME ; 
 int TIME_UTC ; 
 int __clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 

int timespec_get(struct timespec * ts, int base)
{
	if (base != TIME_UTC) return 0;
	int ret = __clock_gettime(CLOCK_REALTIME, ts);
	return ret < 0 ? 0 : base;
}

