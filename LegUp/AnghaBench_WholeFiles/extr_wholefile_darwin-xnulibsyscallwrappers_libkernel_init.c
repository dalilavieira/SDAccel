#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct ProgramVars {int dummy; } ;
typedef  TYPE_1__* _libkernel_functions_t ;
struct TYPE_4__ {scalar_t__ dlsym; } ;

/* Variables and functions */
 scalar_t__ _dlsym ; 
 TYPE_1__* _libkernel_functions ; 
 int /*<<< orphan*/  mach_init () ; 

void
__libkernel_init(_libkernel_functions_t fns,
		const char *envp[] __attribute__((unused)),
		const char *apple[] __attribute__((unused)),
		const struct ProgramVars *vars __attribute__((unused)))
{
	_libkernel_functions = fns;
	if (fns->dlsym) {
		_dlsym = fns->dlsym;
	}
	mach_init();
}

