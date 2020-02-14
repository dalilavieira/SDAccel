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
struct syscalls_exit_open_args {int dummy; } ;
struct syscalls_enter_open_args {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  count (void*) ; 
 int /*<<< orphan*/  enter_open_map ; 
 int /*<<< orphan*/  exit_open_map ; 

int trace_enter_open(struct syscalls_enter_open_args *ctx)
{
	count((void *)&enter_open_map);
	return 0;
}

int trace_enter_exit(struct syscalls_exit_open_args *ctx)
{
	count((void *)&exit_open_map);
	return 0;
}

