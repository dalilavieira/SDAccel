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
struct rlimit {scalar_t__ rlim_max; } ;

/* Variables and functions */
 scalar_t__ INT_MAX ; 
 int /*<<< orphan*/  RLIMIT_NOFILE ; 
 int /*<<< orphan*/  getrlimit (int /*<<< orphan*/ ,struct rlimit*) ; 

int getdtablesize(void)
{
	struct rlimit rl;
	getrlimit(RLIMIT_NOFILE, &rl);
	return rl.rlim_max < INT_MAX ? rl.rlim_max : INT_MAX;
}

