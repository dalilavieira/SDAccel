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
 int MODE_PIN1 ; 
 int MODE_PIN2 ; 

__attribute__((used)) static int se7206_mode_pins(void)
{
	return MODE_PIN1 | MODE_PIN2;
}

