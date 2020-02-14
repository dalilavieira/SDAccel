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
typedef  int u_int32_t ;

/* Variables and functions */
 int RandomULong () ; 

u_int32_t
random(void)
{
	/* Zero all but bottom 31 bits, also works for 64-bit longs */
	u_int32_t mask = (u_int32_t)-1 >> ((sizeof(u_int32_t) * 8) - 31);
	return (mask & RandomULong());
}

