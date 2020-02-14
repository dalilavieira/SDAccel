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
 long InterlockedDecrement (long volatile*) ; 
 long InterlockedIncrement (long volatile*) ; 

long ff_atomic_inc_long(volatile long *val)
{
	return InterlockedIncrement(val);
}

long ff_atomic_dec_long(volatile long *val)
{
	return InterlockedDecrement(val);
}

