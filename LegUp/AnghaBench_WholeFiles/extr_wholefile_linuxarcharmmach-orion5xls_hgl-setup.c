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
 int /*<<< orphan*/  REBOOT_HARD ; 
 int /*<<< orphan*/  orion5x_restart (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void mss2_init(void) {}

__attribute__((used)) static void ls_hgl_power_off(void)
{
	orion5x_restart(REBOOT_HARD, NULL);
}

