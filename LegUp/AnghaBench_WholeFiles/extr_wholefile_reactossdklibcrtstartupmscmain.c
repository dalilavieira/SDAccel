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
 int /*<<< orphan*/  _RTC_Initialize () ; 
 int initialized ; 

void _pei386_runtime_relocator(void)
{
}

int __mingw_init_ehandler(void)
{
    /* Nothing to do */
    return 1;
}

void
__main(void)
{
    if (!initialized)
    {
        initialized = 1;

        _RTC_Initialize();
    }
}

