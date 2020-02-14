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
typedef  int /*<<< orphan*/  initcall_t ;

/* Variables and functions */
 int /*<<< orphan*/  initcall_calltime ; 
 int /*<<< orphan*/  initcall_debug ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/  trace_initcall_finish_cb (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  trace_initcall_start_cb (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void setup_nr_cpu_ids(void) { }

__attribute__((used)) static inline void smp_prepare_cpus(unsigned int maxcpus) { }

__attribute__((used)) static inline void initcall_debug_enable(void)
{
}

__attribute__((used)) static inline void do_trace_initcall_start(initcall_t fn)
{
	if (!initcall_debug)
		return;
	trace_initcall_start_cb(&initcall_calltime, fn);
}

__attribute__((used)) static inline void do_trace_initcall_finish(initcall_t fn, int ret)
{
	if (!initcall_debug)
		return;
	trace_initcall_finish_cb(&initcall_calltime, fn, ret);
}

__attribute__((used)) static inline void mark_readonly(void)
{
	pr_warn("This architecture does not have kernel memory protection.\n");
}

